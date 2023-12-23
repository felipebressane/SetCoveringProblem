///////////////////////////////////////////////////////////////////
//  Institution: Universidade Federal do Rio de Janeiro (UNIRIO)  
//=================================================================
//  Course:  Master's degree
//-----------------------------------------------------------------
//  Matter:  Heuristica Inteligente                               
//-----------------------------------------------------------------
//  Teacher: Adriana Alvim 
//-----------------------------------------------------------------
//  Subject: Set Covering Problem                                 
//-----------------------------------------------------------------
//  Author:  Felipe Bressane                                      
//=================================================================
//  File:    scp.cpp                                        
//=================================================================
//  History
//-----------------------------------------------------------------
//  Version | When      | Comment                 
//-----------------------------------------------------------------
//   1.0    | 31/10/23  | Creation
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

#include "/mestrado/projetos/scp/include/scp.includes.h"


int main( int argc, char * argv[]) {
        FILE           *fpInstanceFile;                     // Pointer to instance file
        char           szDirectoryInstanceFiles[50]="\0";   // Directory with instance files. It must be pass in the environment variable <INPUT_DATA_DIR>
	char           szDirectoryReport[50]="\0";          // Directory to receive files reports
        char           szInputDataFile[100]="\0";           // Fullname input data file. It´s result of inputdir directory plus filename parameter 
        char           szDataFile[100]="\0";                // Data file
	int            nElements;                           // Number of elements
        int            nSubSets;                            // Number of subsets
        int            iCurrentSubSet=1;                    // Current Subset						   
        int            iCurrentElement=1;                   // Current Element
	int            iSubSetWeight;                       // Subset Weight
	int            iTotalSubSets=0;                     // Total SubSets for a specific Element
        int            iCurrentPositionSubSet=0;            // Current Position SubSet readen for a specific Element
        int            iSubSet=0;                           // SubSet of iCurrentPositionSubSet  
	char           szFactorExecutions[50]="\0";         // Factor of executions
	int            iFactorExecutions=0;		    // Factor used to multiply number of SubSets and the result'll be number of executions
	int            iNumberMaxExecution=0;  		    // Max number of executions
	char           szDeadline[50]="\0";		    // Deadline to be used in Tabu list
	int            iDeadline=0;		            // Deadline to be used in Tabu list
	int            iHeuristicType=0;                    // Type of heuristics to be executed
	int            iPrintScreen=0;                      // To print informations in screen
	char           szPrintScreen[3]="\0";               // To print informations in screen
	subSet         *subSets;		            // Objects with subSets and caracteristics 	
        element        *elements;                           // Objects with Elements and caracteristics
	coveringResult *coveringResults;                    // The results of covering
	coveringResult *finalSolution;                      // The final results of a specific step



	if( argc != 3 )
	{
	     std::cout << "Incorrect parameters" << "\n\n";
	     std::cout << "The sintaxe is: scp <NAME FILE> <HEURISTIC TYPE>" << "\n\n";
	     std::cout << "HEURISTIC TYPE:  1 - Construtive Heuristic Randomic" << "\n";
	     std::cout << "                 2 - Construtive Heuristic Cost" << "\n";
	     std::cout << "                 3 - Construtive Heuristic Cost Coverage" << "\n\n";
	     std::cout << "                 4 - Construtive Heuristic Randomic (Initial Solution)      -> Local Search Interative Improvement" << "\n";
	     std::cout << "                 5 - Construtive Heuristic Randomic (Initial Solution)      -> Grasp" << "\n";
	     std::cout << "                 6 - Construtive Heuristic Randomic (Initial Solution)      -> Tabu Search" << "\n\n";
	     std::cout << "                 7 - Construtive Heuristic Cost (Initial Solution)          -> Local Search Interative Improvement" << "\n";
	     std::cout << "                 8 - Construtive Heuristic Cost (Initial Solution)          -> Grasp" << "\n";
	     std::cout << "                 9 - Construtive Heuristic Cost (Initial Solution)          -> Tabu Search" << "\n\n";
	     std::cout << "                10 - Construtive Heuristic Cost Coverage (Initial Solution) -> Local Search Interative Improvement" << "\n";
	     std::cout << "                11 - Construtive Heuristic Cost Coverage (Initial Solution) -> Grasp" << "\n";
	     std::cout << "                12 - Construtive Heuristic Cost Coverage (Initial Solution) -> Tabu Search" << "\n\n";
	     exit(1);
	}


	iHeuristicType=atoi(argv[2]);

        if(getenv("INPUT_DATA_DIR")==NULL)
	{
	     std::cout << "The variable <INPUT_DATA_DIR> doesn't exist" << "\n";
	     exit(1);
	}
	else
	     strcpy(szDirectoryInstanceFiles,getenv("INPUT_DATA_DIR"));

	sprintf(szInputDataFile,"%s/%s",szDirectoryInstanceFiles,argv[1]);
        

        if(getenv("REPORT_DIR")==NULL)
	{
	     std::cout << "The variable <REPORT_DIR> doesn't exist" << "\n";
	     exit(1);
	}
	else
	     strcpy(szDirectoryReport,getenv("REPORT_DIR"));


	if( (fpInstanceFile=fopen(szInputDataFile,"r"))==NULL )
	{
 	     std::cout << "File open error " << szInputDataFile << "\n";
	     exit(1);
	}
	
        if(getenv("FACTOR_EXECUTIONS")==NULL)
	{
	     std::cout << "The variable <FACTOR_EXECUTIONS> doesn't exist" << "\n";
	     exit(1);
	}
	else
	     strcpy(szFactorExecutions,getenv("FACTOR_EXECUTIONS"));

	iFactorExecutions = atoi(szFactorExecutions);

        if(getenv("DEADLINE")==NULL)
	{
	     std::cout << "The variable <DEADLINE> doesn't exist" << "\n";
	     exit(1);
	}
	else
	     strcpy(szDeadline,getenv("DEADLINE"));

	iDeadline = atoi(szDeadline);

        if(getenv("PRINTSCREEN")==NULL)
	{
	     std::cout << "The variable <PRINTSCREEN> doesn't exist" << "\n";
	     exit(1);
	}
	else
	     strcpy(szPrintScreen,getenv("PRINTSCREEN"));

	iPrintScreen = atoi(szPrintScreen);


        // Data file
	strcpy(szDataFile,argv[1]);

        ////////////////////////////////////////////////////////////////////////////
	// Step 1 -> In the first line is got the number of ELEMENTS and SUBSETS
	////////////////////////////////////////////////////////////////////////////
	fscanf(fpInstanceFile,"%d %d",&nElements,&nSubSets);
	if(iPrintScreen==1)
	{
           std::cout << "\n";
           std::cout << "***********************************************************************\n";
	   std::cout << "Number of Elements -> " << nElements << "\n";
	   std::cout << "Number of SubSets -> " << nSubSets << "\n";
	}


        ////////////////////////////////////////////////////////////////////////////
	// Step 2 -> Allocate memory to:
	//           - SubSets with number of SubsSets (pnSubSets)
	//           - Elements with number of Elements (pnElements)
	//           - coveringResults with one instance that´ll register the results
	////////////////////////////////////////////////////////////////////////////
	subSets  = new subSet[ nSubSets ];
	elements = new element[ nElements ];
	coveringResults = new coveringResult[ 1 ];
	finalSolution   = new coveringResult[ 1 ];


        ////////////////////////////////////////////////////////////////////////////
	// Step 3 -> Update subSets and elements with informations from data files
	////////////////////////////////////////////////////////////////////////////
        fgetElementsSubSets(fpInstanceFile, nElements, nSubSets, subSets, elements );


        ////////////////////////////////////////////////////////////////
	// Step 4 -> Printing all SubSets and Elements
        ////////////////////////////////////////////////////////////////
	if(iPrintScreen==1)
           fprintElementsSubSets( nElements, nSubSets, subSets,  elements );


        ////////////////////////////////////////////////////////////////
	// Step 5 -> Using Construtive Heuristic Randomic
        ////////////////////////////////////////////////////////////////
	if( iHeuristicType==1 || iHeuristicType==4 || iHeuristicType==5 || iHeuristicType==6 )
	{
	   char szHeuristic[70]="\0";

	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Randomic)",iHeuristicType);

	   ReportScp ReportScpA(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpA, false );

           frandomizedHeuristics( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpA, true );

           ReportScpA.setNumSubSetsUsed( coveringResults[0].fgetTotalSubSetsUsed() );

 	   ReportScpA.setTotalWeight( coveringResults[0].fgetTotalWeight() ); 

 	   ReportScpA.setFactorExecutions(0); 

 	   ReportScpA.setDeadLine(0); 

	   ReportScpA.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Randomic)", coveringResults );


	   ///////////////////
	   // Post Processing
	   ///////////////////
	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Randomic) - Post Processing",iHeuristicType);

           ReportScp ReportScpB(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpB, false );

           finalSolution = fpostProcessing( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpB, true );

           ReportScpB.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScpB.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScpB.setFactorExecutions(0); 

 	   ReportScpB.setDeadLine(0); 

	   ReportScpB.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Randomic) - Post Processing", finalSolution );

	   coveringResults = finalSolution;

	}

        ////////////////////////////////////////////////////////////////
	// Step 5 -> Using Construtive Heuristic Solution (Cost)
        ////////////////////////////////////////////////////////////////
	if( iHeuristicType==2 || iHeuristicType==7 || iHeuristicType==8  || iHeuristicType==9)
	{
	   char szHeuristic[90]="\0";

	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Cost)",iHeuristicType);

	   ReportScp ReportScpA(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpA, false );

           fcostHeuristics( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpA, true );

           ReportScpA.setNumSubSetsUsed( coveringResults[0].fgetTotalSubSetsUsed() );

 	   ReportScpA.setTotalWeight( coveringResults[0].fgetTotalWeight() ); 

 	   ReportScpA.setFactorExecutions(0); 

 	   ReportScpA.setDeadLine(0); 

	   ReportScpA.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Cost)", coveringResults );


	   ///////////////////
	   // Post Processing
	   ///////////////////
	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Cost) - Post Processing",iHeuristicType);

           ReportScp ReportScpB(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpB, false );

           finalSolution = fpostProcessing( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpB, true );

           ReportScpB.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScpB.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScpB.setFactorExecutions(0); 

 	   ReportScpB.setDeadLine(0); 

	   ReportScpB.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Cost) - Post Processing", finalSolution );

	   coveringResults = finalSolution;

	}



        /////////////////////////////////////////////////////////////////
	// Step 5 -> Using Construtive Heuristic Solution (Coverage Cost)
        /////////////////////////////////////////////////////////////////
	if( iHeuristicType==3 || iHeuristicType==10  || iHeuristicType==11 || iHeuristicType==12)
	{
	   char szHeuristic[90]="\0";

	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Coverage Cost)",iHeuristicType);

	   ReportScp ReportScpA(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpA, false );

           fcostCoverageHeuristics( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpA, true );

           ReportScpA.setNumSubSetsUsed( coveringResults[0].fgetTotalSubSetsUsed() );

 	   ReportScpA.setTotalWeight( coveringResults[0].fgetTotalWeight() ); 

 	   ReportScpA.setFactorExecutions(0); 

 	   ReportScpA.setDeadLine(0); 

	   ReportScpA.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Coverage Cost)", coveringResults );


	   ///////////////////
	   // Post Processing
	   ///////////////////
	   sprintf(szHeuristic,"%02d - Construtive Heuristic Solution (Coverage Cost) - Post Processing",iHeuristicType);

           ReportScp ReportScpB(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScpB, false );

           finalSolution = fpostProcessing( nElements, nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScpB, true );

           ReportScpB.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScpB.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScpB.setFactorExecutions(0); 

 	   ReportScpB.setDeadLine(0); 

	   ReportScpB.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Construtive Heuristic Solution (Coverage Cost) - Post Processing", finalSolution );

	   coveringResults = finalSolution;
	}



        ////////////////////////////////////////////////////////////////
	// Step 6 -> Using Local Search with Iterative Improvement
        ////////////////////////////////////////////////////////////////
	if( iHeuristicType==4 || iHeuristicType==7 || iHeuristicType==10)
	{

	   char szHeuristic[70]="\0";

	   sprintf(szHeuristic,"%02d - Local Search Solution with Iterative Improvement",iHeuristicType);

	   ReportScp ReportScp(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScp, false );

           finalSolution = flocalSearchIterativeImprovement( nElements,  nSubSets, subSets,  elements, coveringResults );

           fsetInfoReports( &ReportScp, true );

           ReportScp.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScp.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScp.setFactorExecutions(0); 

 	   ReportScp.setDeadLine(0); 

	   ReportScp.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Local Search Solution with Iterative Improvement", finalSolution );

        }


        ////////////////////////////////////////////////////////////////
	// Step 7 -> Using Grasp
        ////////////////////////////////////////////////////////////////
	if( iHeuristicType==5 || iHeuristicType==8 || iHeuristicType==11)
	{

	   char szHeuristic[70]="\0";

	   sprintf(szHeuristic,"%02d - Grasp Solution",iHeuristicType);

	   ReportScp ReportScp(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScp, false );
           
	   iNumberMaxExecution=iFactorExecutions * nSubSets;

           finalSolution = fgrasp( nElements, nSubSets, subSets,  elements, coveringResults, iNumberMaxExecution );

           fsetInfoReports( &ReportScp, true );

           ReportScp.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScp.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScp.setFactorExecutions(iFactorExecutions); 

 	   ReportScp.setDeadLine(0); 

	   ReportScp.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Grasp Solution", finalSolution );

	}

        ////////////////////////////////////////////////////////////////
	// Step 8 -> Using Tabu Search
        ////////////////////////////////////////////////////////////////
	if( iHeuristicType==6 || iHeuristicType==9 || iHeuristicType==12 )
	{

	   char szHeuristic[70]="\0";

	   sprintf(szHeuristic,"%02d - Tabu Search Solution",iHeuristicType);

	   ReportScp ReportScp(szDirectoryReport,szHeuristic,szDataFile,nElements,nSubSets);

           fsetInfoReports( &ReportScp, false );

	   iNumberMaxExecution=iFactorExecutions * nSubSets;

	   double result = (double)(iNumberMaxExecution * iDeadline)/100;

	   int iNewDeadline = int(result + 0.5);

	   if(iNewDeadline==0) iNewDeadline=1;

           finalSolution = ftabuSearch( nElements, nSubSets, subSets,  elements, coveringResults, iNumberMaxExecution, iNewDeadline );

           fsetInfoReports( &ReportScp, true );

           ReportScp.setNumSubSetsUsed( finalSolution[0].fgetTotalSubSetsUsed() );

 	   ReportScp.setTotalWeight( finalSolution[0].fgetTotalWeight() ); 

 	   ReportScp.setFactorExecutions(iFactorExecutions); 

 	   ReportScp.setDeadLine(iDeadline); 

	   ReportScp.printReport();

	   if(iPrintScreen==1)
              fprintSolution( "Tabu Search Solution", finalSolution );

	}


        exit(0);

}

