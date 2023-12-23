#include <iomanip>
#include <random>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sys/times.h>
#include <time.h>
#include <stdlib.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include "/mestrado/projetos/scp/include/scp.class.element.h"
#include "/mestrado/projetos/scp/include/scp.class.subset.h"
#include "/mestrado/projetos/scp/include/scp.class.result.h"
#include "/mestrado/projetos/scp/include/scp.class.report.h"
#include "/mestrado/projetos/scp/include/scp.struct.support.h"

void fgetElementsSubSets(FILE *, int , int , subSet *,  element *);
void fprintElementsSubSets(int, int, subSet *,  element *);
void frandomizedHeuristics(int, int, subSet *,  element *, coveringResult *);
void fcostHeuristics(int, int, subSet *,  element *, coveringResult *);
void fcostCoverageHeuristics(int, int, subSet *,  element *, coveringResult *);
void fprintSolution(const std::string& Heuristics, coveringResult *);
int  compareStructsDesc(const void *, const void *);
int  compareCoverageCostAsc(const void *, const void *);
int  fgerResultSupport( int, subSet *, coveringResult *, struct st_coveringResultSupport * );
int  fgerRandomic( int );
int  fCalcCust( coveringResult * );
void fupdateListTabu( int, int *, int *, int );
void fupdateDeadlineLT( int, int * );
void fsetInfoReports( ReportScp *, bool  );

coveringResult *flocalSearchIterativeImprovement( int, int, subSet *, element *, coveringResult * );
coveringResult *fgrasp( int, int, subSet *, element *, coveringResult *, int );
coveringResult *ftabuSearch( int, int, subSet *, element *, coveringResult *, int, int );
coveringResult *fgerNewCurrentSolution( int, int, subSet *,  element *, coveringResult *, int *, int *, int, st_coveringResultSupport * );
coveringResult *fgerNewCurrentSolutionGrasp( int, int, subSet *,  element *, coveringResult *, int , st_coveringResultSupport * );
coveringResult *fgerNewCurrentSolutionTabu( int, int, subSet *,  element *, coveringResult *, int *, int *, int );
coveringResult *fpostProcessing( int, int, subSet *,  element *, coveringResult * );
