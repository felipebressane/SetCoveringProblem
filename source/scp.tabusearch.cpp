///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: ftabuSearch
//
// Description: Tabu Search function
//
// Parameters:  nElements           - number of Elements
//              nSubSets            - number of SubSets
//              psubSets            - pointer to the class subSet
//              pelements           - pointer to the class element
//              pinitialSolution    - initial solution
//              iNumberMaxExecution - Max number of executions
//              iDeadline           - Dealine used in the tabu list
//
// Output:      coveringResult      - Solution SCP with Tabu Search
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

coveringResult *ftabuSearch( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pinitialSolution, int iNumberMaxExecution, int iDeadline )
{
    struct st_coveringResultSupport pst_coveringResultSupport[nSubSets];   // Support structure with SubSet and number of covering
    int inumExecution  = 0;                                                // Interection number
    int *listTabu      = new int[nSubSets];                                // Tabu list
    int *listMoviment  = new int[nSubSets];                                // Moviment list with moviments of an interaction
    int iNumSubSetUsed              = 0;                                   // Total SubsSets used in initial solution
    coveringResult *currentSolution = new coveringResult[1];               // Current solution
    coveringResult *bestSolution    = new coveringResult[1];               // Best solution
    coveringResult *newSolution     = new coveringResult[1];               // New solution
    int iMaxSubSet                  = 0;									   



    currentSolution[0] = pinitialSolution[0];                              // Initializing current solution with initial solution 
    bestSolution[0]    = pinitialSolution[0];                              // Initializing best solution with initial solution
    for(int i=0;i<nSubSets;i++) listTabu[i]=0;                             // Initializing Tabu list with 0

    
    fgerResultSupport( nSubSets, psubSets, pinitialSolution, pst_coveringResultSupport ); 

    iNumSubSetUsed = pinitialSolution[0].fgetTotalSubSetsUsed();

    for(int i=0; i<iNumSubSetUsed; i++ )
	 if(pst_coveringResultSupport[i].SubSet > iMaxSubSet) iMaxSubSet = pst_coveringResultSupport[i].SubSet;


    while(inumExecution < iNumberMaxExecution)
    {


      for(int i=0;i<nSubSets;i++) listMoviment[i]=0;                       // Cleanning vector listMoviment before an interaction 

      newSolution = fgerNewCurrentSolutionTabu( nElements, nSubSets, psubSets,  pelements, currentSolution, listTabu, listMoviment, iMaxSubSet );

      if( fCalcCust(newSolution) < fCalcCust(bestSolution) )
           bestSolution[0] = newSolution[0];
      else
      {    
           inumExecution++;
           if( fCalcCust(newSolution) >= fCalcCust(currentSolution) )
               fupdateListTabu( nSubSets, listTabu, listMoviment, iDeadline );
      }

      currentSolution[0] = bestSolution[0];

      fupdateDeadlineLT( nSubSets, listTabu );

    }


    return(bestSolution);

}


