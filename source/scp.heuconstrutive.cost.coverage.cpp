///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: fcostCoverageHeuristics
//
// Description: Construtive Heuristic Cost Coverage function
//
// Parameters:  nElements     - number of Elements
//              nSubSets      - number of SubSets
//              psubSets      - pointer to the class subSet
//              pelements     - pointer to the class element
//
// Output:      NA
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

void fcostCoverageHeuristics( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pcoveringResult )
{
	
    int  *elementsUsed = new int[nElements];                 // Elements covered by SubSets
    int  *subSetsUsed  = new int[nSubSets];                  // SubSets that are covering Elements
    int  iTotalWeight  = 0;                                  // Total Weight
    int  iSubSetSelected = 0;                                // SubSet selected
    int  iWeightSelected = 0;                                // Weight of the SubSet selected
    int  inumElementsCovered = 0;                            // Number of Elements covered by a SubSet
    int  *pielementsCoveredSubSet;                           // Elements Covered by a SubSet
    int  iTotalSubSetsUsed = 0;                              // Total SubSet used in this soluction
    bool subSetIncluded = true;                              // To check if the SubSet was included in total				      
    int  iElementsAlreadyCovered = 0;                        // Elements yet covered					      
    int  inumOfCovering = 0;                                 // Number of covering					     
    struct st_coverageCostSupport st_coverageCost[nSubSets]; // Struct support with coverage cost of the SubSets
					      

    // 1 - Initialising with 0 (not used):
    //     vector elementsUsed 
    //     vector subSetsUsed 
    for(int i=0; i<nElements; i++) elementsUsed[i]=0;
    for(int i=0; i<nSubSets; i++)  subSetsUsed[i]=0;

    for(int i=0; i<nSubSets; i++)  {
         st_coverageCost[i].SubSet=psubSets[i].fgetNumSubSet();
         st_coverageCost[i].coverageCost=psubSets[i].fgetCoverageCost();
    }

    // Order pst_coveringResultSupport by iTotalElementsCovered desc

//    size_t arraySize = sizeof(st_coverageCost)/sizeof(st_coverageCost[0]);
    size_t arraySize = nSubSets;

    qsort(st_coverageCost, arraySize, sizeof(struct st_coverageCostSupport), compareCoverageCostAsc);



    // 2 - Reading all used SubSets
    for(int i=0; i<nSubSets; i++)
    {

//       (st_coverageCost[i]-1)

       // Get the number of current SubSet
       iSubSetSelected = psubSets[(st_coverageCost[i].SubSet-1)].fgetNumSubSet();	

       // Get the cost of current SubSet
       iWeightSelected = psubSets[(st_coverageCost[i].SubSet-1)].fgetWeight();	

       // Get number of Elements covered by current SubSet
       inumElementsCovered = psubSets[(st_coverageCost[i].SubSet-1)].fgetnumOfElements();

       // Get all Elements that can be covering by current SubSet
       pielementsCoveredSubSet = new int[inumElementsCovered];
       pielementsCoveredSubSet = psubSets[(st_coverageCost[i].SubSet-1)].fgetElements();

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

