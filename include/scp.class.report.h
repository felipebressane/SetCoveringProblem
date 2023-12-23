
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
//  File:    scp.class.report.h                                        
//=================================================================
//  History
//-----------------------------------------------------------------
//  Version | When      | Comment                 
//-----------------------------------------------------------------
//   1.0    | 31/10/23  | Creation
///////////////////////////////////////////////////////////////////
#include <vector>
int  fgerRandomic( int );



class ReportScp {
	public:

          ///////////////////////////////////////////////////////////////////////////////////////////
          // Método: Constructor
          ///////////////////////////////////////////////////////////////////////////////////////////
          ReportScp( char *pszReportPath, char *pszNewHeuristicName, char *pszNewFileRead, int iNewNumOfElements, int iNewNumOfSubSets ) {
	     strcpy(szReportPath,pszReportPath);
             strcpy( szHeuristicName,pszNewHeuristicName );
             strcpy( szFileRead,pszNewFileRead );
             iNumOfElements = iNewNumOfElements;
             iNumOfSubSets = iNewNumOfSubSets;
	  }

	  void setNumSubSetsUsed( int iNewNumSubSetsUsed ) {
             iNumSubSetsUsed = iNewNumSubSetsUsed;
	  }

	  void setTotalWeight( int iNewTotalWeight ) {
             iTotalWeight = iNewTotalWeight;
	  }

	  void setFactorExecutions( int iNewFactorExecutions ) {
             iFactorExecutions = iNewFactorExecutions;
	  }

	  void setDeadLine( int iNewDeadLine ) {
             iDeadLine = iNewDeadLine;
	  }

	  void setStartUserCPUTime(clock_t newStartUserCPUTime) {
             startUserCPUTime = newStartUserCPUTime;
          }

	  void setEndUserCPUTime(clock_t newEndUserCPUTime) {
             endUserCPUTime = newEndUserCPUTime;
          }

	  void setUserCPUDuration(clock_t newUserCPUDuration) {
             userCPUDuration = newUserCPUDuration;
          }

	  void setStartSystemCPUTime(clock_t newStartSystemCPUTime) {
             startSystemCPUTime = newStartSystemCPUTime;
          }

	  void setEndSystemCPUTime(clock_t newEndSystemCPUTime) {
             endSystemCPUTime = newEndSystemCPUTime;
          }

	  void setSystemDuration(clock_t newSystemDuration) {
             systemDuration = newSystemDuration;
          }

	  void setStartRealTime(clock_t newStartRealTime) {
             startRealTime = newStartRealTime;
          }

	  void setEndRealTime(clock_t newEndRealTime) {
             endRealTime = newEndRealTime;
          }

	  void setRealTimeDuration(clock_t newRealTimeDuration) {
             realTimeDuration = newRealTimeDuration;
          }


          ///////////////////////////////////////////////////////////////////////////////////////////
          // Método: Grupo de métodos get
          //
          // Parâmetros: Número da linha do relatório
	  //
	  // Retorno: Campo a ser lido
          //
          // Objetivo: Ler valores campos da estrutura de relatórios
          //
          // Autores: Charles, Zara e Bressane
          //
          // Data: 26/06/23
          ///////////////////////////////////////////////////////////////////////////////////////////

	  int getNumSubSetsUsed() {
             return(iNumSubSetsUsed);
	  }

	  int getTotalWeight() {
             return(iTotalWeight);
	  }

	  clock_t getStartUserCPUTime() {
             return(startUserCPUTime);
          }

	  clock_t getEndUserCPUTime() {
             return(endUserCPUTime);
          }

	  clock_t getStartSystemCPUTime() {
             return(startSystemCPUTime);
          }

	  clock_t getEndSystemCPUTime() {
             return(endSystemCPUTime);
          }

	  clock_t getStartRealTime() {
             return(startRealTime);
          }

	  clock_t getEndRealTime() {
             return(endRealTime);
          }

          ///////////////////////////////////////////////////////////////////////////////////////////
          // Método: printReport
          //
          // Parâmetros: NA
	  //
	  // Retorno: NA
          //
          // Objetivo: Imprimir informações dos processos executados, tanto na tela, como também em
	  //           arquivo.
          //
          // Autores: Charles, Zara e Bressane
          //
          // Data: 26/06/23
          ///////////////////////////////////////////////////////////////////////////////////////////
	  void printReport() {
	     FILE    *fpReport;
             struct  tm *ptime;
             time_t  stTempoProcesso;
             int     iData;
             int     iHora;
	     char    szReportFile[500]="\0";
	     int     iSeq=0;

             stTempoProcesso = time( NULL );
             ptime           = localtime(&stTempoProcesso);

             iData=(ptime->tm_year+1900)*10000+(ptime->tm_mon+1)*100+ptime->tm_mday;
             iHora=ptime->tm_hour*10000+ptime->tm_min*100+ptime->tm_sec;

             iSeq = fgerRandomic(100000000); 

	     sprintf(szReportFile,"%s/scp.process.report.%d.%06d.%09d.csv",szReportPath,iData,iHora,iSeq);

	     if( (fpReport=fopen(szReportFile,"w"))==NULL )
	     {
	        printf("Erro na abertura do arquivo %s\n",szReportFile);
	        exit(1);
	     }

	     fprintf(fpReport,"Heuristic;File Read;Number of Elements;Number of SubSets;Number of SubSets Used;Factor Executions;Deadline;Total Weight;User CPU Time;System CPU Time;CPU Time\n");

	     fprintf(fpReport,"%s;%s;%d;%d;%d;%d;%d;%d;%ld;%ld;%ld\n",szHeuristicName,
 			                                             szFileRead,
						 	             iNumOfElements,
                                                                     iNumOfSubSets,
   							             iNumSubSetsUsed,
								     iFactorExecutions,
								     iDeadLine,
								     iTotalWeight,
								     userCPUDuration,
								     systemDuration,
								     realTimeDuration);

	     fclose(fpReport);

          }


	private:
	  char    szReportPath[200]   ="\0";
          char    szHeuristicName[70] ="\0";
          char    szFileRead[50]      ="\0";
	  int     iNumOfElements      = 0;
	  int     iNumOfSubSets       = 0;
	  int     iNumSubSetsUsed     = 0;
	  int     iFactorExecutions   = 0;
	  int     iDeadLine           = 0;
	  int     iTotalWeight        = 0;

          clock_t startUserCPUTime;
          clock_t endUserCPUTime;
          clock_t userCPUDuration;

          clock_t startSystemCPUTime;
          clock_t endSystemCPUTime;
          clock_t systemDuration;

          clock_t startRealTime;
          clock_t endRealTime;
          clock_t realTimeDuration;
          
};
