///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: fcostHeuristics
//
// Description: Construtive Heuristic Cost function
//
// Parameters:  nElements     - number of Elements
//              nSubSets      - number of SubSets
//              psubSets      - pointer to the class subSet
//              pelements     - pointer to the class element
//
// Output:      NA
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

void fcostHeuristics( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pcoveringResult )
{
	
    int  *elementsUsed = new int[nElements];   // Elements covered by SubSets
    int  *subSetsUsed  = new int[nSubSets];    // SubSets that are covering Elements
    int  iTotalWeight  = 0;                    // Total Weight
    int  iSubSetSelected = 0;                  // SubSet selected
    int  iWeightSelected = 0;                  // Weight of the SubSet selected
    int  inumElementsCovered = 0;              // Number of Elements covered by a SubSet
    int  *pielementsCoveredSubSet;             // Elements Covered by a SubSet
    int  iTotalSubSetsUsed = 0;                // Total SubSet used in this soluction
    bool subSetIncluded = true;                // To check if the SubSet was included in total				      
    int  iElementsAlreadyCovered = 0;          // Elements yet covered					      
    int  inumOfCovering = 0;                   // Number of covering					      
					      

    // 1 - Initialising with 0 (not used):
    //     vector elementsUsed 
    //     vector subSetsUsed 
    for(int i=0; i<nElements; i++) elementsUsed[i]=0;
    for(int i=0; i<nSubSets; i++)  subSetsUsed[i]=0;


    // 2 - Reading all used SubSets
    for(int i=0; i<nSubSets; i++)
    {

       // Get the number of current SubSet
       iSubSetSelected = psubSets[i].fgetNumSubSet();	

       // Get the cost of current SubSet
       iWeightSelected = psubSets[i].fgetWeight();	

       // Get number of Elements covered by current SubSet
       inumElementsCovered = psubSets[i].fgetnumOfElements();

       // Get all Elements that can be covering by current SubSet
       pielementsCoveredSubSet = new int[inumElementsCovered];
       pielementsCoveredSubSet = psubSets[i].fgetElements();

       subSetIncluded=false;

       // Reading all Elements this SubSet
       for(int j=0;j<inumElementsCovered;j++)
       {

            if( elementsUsed[ (pielementsCoveredSubSet[j]-1) ] == 0 )
	    {

                inumOfCovering++; 

                iElementsAlreadyCovered++;

                subSetIncluded = true;

	        elementsUsed[ (pielementsCoveredSubSet[j]-1) ] = 1;
                pcoveringResult[0].fsetElement( pielementsCoveredSubSet[j] );
                pcoveringResult[0].fsetSubSet(iSubSetSelected);
                pcoveringResult[0].fsetWeight(iWeightSelected);
		
	    }

       }

       delete(pielementsCoveredSubSet);

       if(subSetIncluded)
       {
           // Sum iWeightSelected to iTotalWeight
           iTotalWeight = iTotalWeight + iWeightSelected;

           // Sum iWeightSelected to iTotalWeight
           iTotalSubSetsUsed++; 
       }

       if(iElementsAlreadyCovered==nElements)
          break;

    }

    pcoveringResult[0].fsetNumOfCovering(inumOfCovering);
    pcoveringResult[0].fsetTotalWeight(iTotalWeight);
    pcoveringResult[0].fsetTotalSubSetsUsed(iTotalSubSetsUsed);

}	

