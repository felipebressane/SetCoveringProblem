///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: fgrasp
//
// Description: Local Search function
//
// Parameters:  nElements       - number of Elements
//              nSubSets        - number of SubSets
//              psubSets        - pointer to the class subSet
//              pelements       - pointer to the class element
//              pcoveringResult - covering result
//              iNumberMaxExecution - Max number of executions
//
// Output:      NA
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"

coveringResult *fgrasp( int nElements, int nSubSets, subSet *psubSets,  element *pelements, coveringResult *pinitialSolution, int iNumberMaxExecution )
{
    struct st_coveringResultSupport st_coveringResultSupport[nSubSets];    // Support structure with SubSet and number of covering
    int inumExecution               = 0;
    coveringResult *currentSolution = new coveringResult[1];               // Current solution
    coveringResult *bestSolution    = new coveringResult[1];               // Best solution
    coveringResult *newSolution     = new coveringResult[1];               // New solution
    int posRandomic                 = 0;
    int iMaxSubSet                  = 0;
    int iNumSubSetUsed              = 0;
    int iSubSetSelected             = 0;
    int irandomNumber               = 0;


    iNumSubSetUsed = pinitialSolution[0].fgetTotalSubSetsUsed();

    // Load structure support with SubSets and total covering by SubSet
    fgerResultSupport( nSubSets, psubSets, pinitialSolution, st_coveringResultSupport ); 

    // Getting iMaxSubSet to generate random number
    for(int i=0; i<iNumSubSetUsed; i++ )
	 if(st_coveringResultSupport[i].SubSet > iMaxSubSet) iMaxSubSet = st_coveringResultSupport[i].SubSet;

    // Initializing current solution and best solution with initial solution
    currentSolution[0] = pinitialSolution[0];    
    bestSolution[0]    = pinitialSolution[0];    

    while(inumExecution < iNumberMaxExecution)
    {
         // Load structure support with SubSets and total covering by SubSet
         fgerResultSupport( nSubSets, psubSets, currentSolution, st_coveringResultSupport ); 

	 // Get random number to a SubSet
         for(int i=0;i<10;i++)
         {
              irandomNumber = fgerRandomic( iMaxSubSet ); 
	      iSubSetSelected=st_coveringResultSupport[irandomNumber].SubSet;
	      if(iSubSetSelected!=0)
	      {
	         posRandomic = irandomNumber;
	         break;
	      }
         }

         newSolution=fgerNewCurrentSolutionGrasp(nElements, nSubSets, psubSets,  pelements, currentSolution, posRandomic, st_coveringResultSupport);

         if( fCalcCust(newSolution) < fCalcCust(bestSolution) )
              bestSolution[0] = newSolution[0];
    
         currentSolution[0] = bestSolution[0];

         inumExecution++;
    }

    return(bestSolution);
       
}

