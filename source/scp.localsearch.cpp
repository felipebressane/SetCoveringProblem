///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: flocalSearchIterativeImprovement
//
// Description: Local Search Iterative Improvement
//
// Parameters:  nElements           - number of Elements
//              nSubSets            - number of SubSets
//              psubSets            - pointer to the class subSet
//              pelements           - pointer to the class element
//              pinitialSolution    - initial solution
//
// Output:      coveringResult      - Solution SCP with Local Search Iterative Improvement
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

coveringResult *flocalSearchIterativeImprovement( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pinitialSolution )
{
    struct st_coveringResultSupport st_coveringResultSupport[nSubSets];    // Support structure with SubSet and number of covering
    int inumExecution  = 0;                                                // Interection number
    int improvement    = 1;                          			   // Control improvement
    coveringResult *currentSolution = new coveringResult[1];               // Current solution
    coveringResult *newSolution     = new coveringResult[1];               // New solution
    int hasSolution    = 1;                                                // This flag indicates if still has solution	
    int iTotalSolution = 0;
    int iNextSolution  = 0;    

    // Get total of SubSet used in Initial Solution
    iTotalSolution = pinitialSolution[0].fgetTotalSubSetsUsed();	   

    // Initializing current solution with initial solutio
    currentSolution = pinitialSolution;                                   
									    

    while(improvement == 1)
    {

       improvement = 0;

       // Load structure support with SubSets and total covering by SubSet
       fgerResultSupport( nSubSets, psubSets, currentSolution, st_coveringResultSupport ); 

       while( hasSolution != 0 && improvement == 0 )
       {

           newSolution = fgerNewCurrentSolution( nElements, nSubSets, psubSets,  pelements, currentSolution, &hasSolution, &iNextSolution, iTotalSolution, st_coveringResultSupport );

           if( fCalcCust(newSolution) < fCalcCust(currentSolution) )
           { 
                 currentSolution[0] = newSolution[0];
		 improvement = 1;
           }

       } 
       
    }

    return(currentSolution);
}

