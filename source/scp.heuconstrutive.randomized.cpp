///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: frandomizedHeuristics
//
// Description: Construtive Heuristic Randomic function
//
// Parameters:  nElements     - number of Elements
//              nSubSets      - number of SubSets
//              psubSets      - pointer to the class subSet
//              pelements     - pointer to the class element
//
// Output:      NA
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

void frandomizedHeuristics( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pcoveringResult )
{
    int *positionRandomic = new int[nElements];   // Vector with randomic position that will be treated 
    int *pElementsCovered = new int[nElements];   // Vector with elements covered
    int *SubSetsUsed = new int[nSubSets];         // SubSets that are covering Elements
    int random_number = 0;                        // Random number 
    int var_aux = 0;                              // Auxiliary var used to permute positions
    int elementNotCovered = 0;                    // Variable that receives Elements not covered
    int iTotalSubSets = 0;                        // Total SubSets
    int iFirstPositionSubSetSelected = 0;         
    int iSubSetSelected = 0;
    int iWeightSelected = 0;
    int iTotalWeight = 0;
    int iTotalCovered = 0;
    int iTotalSubSetsUsed = 0;


    // 1 - Initialising:
    //     vector positionRandomic 
    //     vector SubSetsUsed with 0 (not used)
    //     vector pElementsCovered with 0 (not used)
    for(int i=0; i<nElements; i++) positionRandomic[i]=i;
    for(int i=0; i<nElements; i++) pElementsCovered[i]=0;
    for(int i=0; i<nSubSets; i++)  SubSetsUsed[i]=0;


    // 2 - Exchanging positions of Elements, the result is a positionRandomic
    for(int i=0; i<nElements; i++)
    {

       // Put the current position in temporary var
       var_aux = positionRandomic[i];

       // Generate random numbers
       random_number = fgerRandomic(nElements);
       
       // Move the random position to current posiition
       positionRandomic[i] = positionRandomic[random_number];

       // And move temporary var value to the random position
       positionRandomic[random_number] = var_aux;

    }


    // 3 - Reading all Elements with positionRandomic
    for(int i=0; i<nElements; i++)
    {

        // 3.1 Get the Element not covered with positionRandomic in pelements    
	elementNotCovered = pelements[ positionRandomic[i] ].fgetElement();

	// 3.2 Checking if this Element is already covered
	if(pElementsCovered[(elementNotCovered-1)]==0) {

	   pElementsCovered[(elementNotCovered-1)]=1;

           // 3.2 Get the Total SubSets for this Element
           iTotalSubSets     = pelements[ positionRandomic[i] ].fgetNumOfSets();

           // 3.3 Get the SubSets of this Element
	   int *piSubSet = new int[iTotalSubSets];
	   piSubSet = pelements[ positionRandomic[i] ].fgetSubSets();

           // 3.4 Exchanging positions of SubSets
	   //   3.4.1 Define variable to Randomic Position of SubSets
	   int *positionRandomicSubSet = new int[iTotalSubSets];

           //   3.4.2 Define a distribution

           //   3.4.3 Initialising the vector positionRandomicSubSet with SubSets of the Element
           for(int j=0; j<iTotalSubSets; j++)  positionRandomicSubSet[j]=piSubSet[j]; 

           //   3.4.4 Exchanging vector positionRandomicSubSet
           for(int j=0; j<iTotalSubSets; j++)
	   {
               // Put the current position in temporary var
               var_aux = positionRandomicSubSet[j];

               // Generate random numbers
               random_number = fgerRandomic(iTotalSubSets);
       
               // Move the random position to current posiition
               positionRandomicSubSet[j] = positionRandomicSubSet[random_number];

               // And move temporary var value to the random position
               positionRandomicSubSet[random_number] = var_aux;
	   }

           // 3.5 Get the first SubSet position from positionRandomicSubSet
           iFirstPositionSubSetSelected = positionRandomicSubSet[0];
	
	   // 3.6 Get the SubSet with iFirstPositionSubSetSelected
           iSubSetSelected = psubSets[(iFirstPositionSubSetSelected-1)].fgetNumSubSet();	

	   // 3.7 Get the Weight of SubSet selected
           iWeightSelected = psubSets[(iFirstPositionSubSetSelected-1)].fgetWeight();	

	   // 3.8 Verify if the SubSet is covering some Element
	   if (SubSetsUsed[(iSubSetSelected-1)]==0)
	   {
              iTotalWeight = iTotalWeight + iWeightSelected;
	      SubSetsUsed[(iSubSetSelected-1)]=1;
	   }

	   // 3.9 Count the total covered
           iTotalCovered++;

	   // 3.10 Register the solutions
           pcoveringResult[0].fsetElement(elementNotCovered);
           pcoveringResult[0].fsetSubSet(iSubSetSelected);
           pcoveringResult[0].fsetWeight(iWeightSelected);

           // 3.11 Verifing all Elements covered by this SubSet
	   // 3.11.1 Getting total Elements covered by this SubSet
	   int iNumOfElements = psubSets[(iSubSetSelected-1)].fgetnumOfElements();

	   int *pElementsCoveredSubSet = new int[iNumOfElements];

	   // 3.11.2 Getting all Elements covered by this SubSet
           pElementsCoveredSubSet = psubSets[(iSubSetSelected-1)].fgetElements();

	   for (int j=0;j<iNumOfElements;j++)
           {
	   // 3.11.3 If the Element is not covered, put the Element in this solution
              if(  pElementsCovered[ (pElementsCoveredSubSet[j]-1) ] == 0 )		   
	      {
	         pElementsCovered[ (pElementsCoveredSubSet[j]-1) ]=1;

                 iTotalCovered++;
                 pcoveringResult[0].fsetElement( pElementsCoveredSubSet[j] );
                 pcoveringResult[0].fsetSubSet(iSubSetSelected);
                 pcoveringResult[0].fsetWeight(iWeightSelected);
	      }
	   }

           free(positionRandomicSubSet);
	   free(piSubSet);
	   free(pElementsCoveredSubSet);

        }

    }

    for(int i=0; i<nSubSets; i++) {
	 if(SubSetsUsed[i]==1)
	    iTotalSubSetsUsed++;
    }
    pcoveringResult[0].fsetNumOfCovering(iTotalCovered);
    pcoveringResult[0].fsetTotalWeight(iTotalWeight);
    pcoveringResult[0].fsetTotalSubSetsUsed(iTotalSubSetsUsed);

}	

