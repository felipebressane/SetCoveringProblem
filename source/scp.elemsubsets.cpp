///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: fgetElementsSubSets
//
// Description: This function reads all SUBSETS and ELEMENTS from data files and puts these informations in respective
//              classes psubSets and pelements.
//
// Parameters:  fpInstanceFil - pointer to the data file
//              nElements     - number of Elements
//              nSubSets      - number of SubSets
//              psubSets      - pointer to the class subSet
//              pelements     - pointer to the class element
//
// Output:      NA
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"


void fgetElementsSubSets(FILE *fpInstanceFile, int nElements, int nSubSets, subSet *psubSets,  element *pelements )
{
        int     iCurrentSubSet=1;                    // Current Subset						   
        int     iCurrentElement=1;                   // Current Element
	int     iSubSetWeight;                       // Subset Weight
	int     iTotalSubSets=0;                     // Total SubSets for a specific Element
        int     iCurrentPositionSubSet=0;            // Current Position SubSet readen for a specific Element
        int     iSubSet=0;                           // SubSet of iCurrentPositionSubSet  
	int    *iTempNumOfElementsInSubSet;          // Register temporary number of elements by subsets

	iTempNumOfElementsInSubSet = new int[nSubSets];
	for(int i=0; i<nSubSets; i++) iTempNumOfElementsInSubSet[i]=0;
      	
        ////////////////////////////////////////////////////////////////////////////
        // Step 3.1 -> In the second line is got the subsets weight´s
        ////////////////////////////////////////////////////////////////////////////
	fscanf(fpInstanceFile,"%d ",&iSubSetWeight);
        while( iCurrentSubSet <= nSubSets )
	{
	   psubSets[(iCurrentSubSet-1)].fsetNumSubSet(iCurrentSubSet);
	   psubSets[(iCurrentSubSet-1)].fsetWeight(iSubSetWeight);

	   fscanf(fpInstanceFile,"%d",&iSubSetWeight);
	   iCurrentSubSet++;
	}

        ////////////////////////////////////////////////////////////////////////////
	// Step 3.2 -> Read SubSets for all Elements for each one:
	//          - this process first gets the total of SubSets for a specific
	//            Element. 
	//          - then reads all SubSets of this Element.
	//          - It´s done for all Elements.
	////////////////////////////////////////////////////////////////////////////

	// The first TotalSubSets was readen at the last read of Loop above
	iTotalSubSets=iSubSetWeight;

        while( iCurrentElement <= nElements  ) // First Loop reads the element
	{

	   pelements[(iCurrentElement-1)].fsetElement(iCurrentElement);
	   pelements[(iCurrentElement-1)].fsetNumOfSets(iTotalSubSets);
	   pelements[(iCurrentElement-1)].fsetisAllSubSetChecked(0);

           iCurrentPositionSubSet=1;
	   fscanf(fpInstanceFile,"%d",&iSubSet);
	   while(iCurrentPositionSubSet<=iTotalSubSets)
           {
	      // Put SubSet to the new Element
   	      pelements[(iCurrentElement-1)].fsetSubSet(iSubSet);

	      // Put 0 to the isSubSetChecked
   	      pelements[(iCurrentElement-1)].fsetisSubSetChecked(0);

	      // Put 0 to the iQtdChecked
   	      pelements[(iCurrentElement-1)].fsetQtdChecked(0);

	      // Put in the SubSet this New Element
	      psubSets[(iSubSet-1)].fsetElements(iCurrentElement);

	      // Sum the number of Elements by SubSet
	      iTempNumOfElementsInSubSet[iSubSet-1]=(iTempNumOfElementsInSubSet[iSubSet-1] + 1);

	      fscanf(fpInstanceFile,"%d",&iSubSet);
              iCurrentPositionSubSet++;
           }
	   iTotalSubSets=iSubSet;
           iCurrentElement++;
	}

	// Set number elements for each SubSet with the method fsetNumOfElements of the class subSets.
	for(int i=0; i<nSubSets; i++) {
	       	psubSets[i].fsetNumOfElements(iTempNumOfElementsInSubSet[i]);
	       	psubSets[i].fsetCoverageCost( static_cast<float>(psubSets[i].fgetWeight())/iTempNumOfElementsInSubSet[i] );
	}

}

