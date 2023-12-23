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
//  File:    scp.class.result.h                                        
//=================================================================
//  History
//-----------------------------------------------------------------
//  Version | When      | Comment                 
//-----------------------------------------------------------------
//   1.0    | 31/10/23  | Creation
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
#include <vector>

///////////////////////////////////////////////////////////////////
//  Class: coveringResult
//-----------------------------------------------------------------
//  Description: Class with results of heuristics 
//-----------------------------------------------------------------
//  Members: inumOfCovering - number of covering
//           subSets        - subSets that cover a group of Elements
//           elements       - elements covered by subset
//           weight         - weight of a subset
//           iTotalWeight   - sum of all the Weights of a Covering
//           iTotalSubSetsUsed - Total of SubSets used
//-----------------------------------------------------------------
//  Methods: fsetnumOfCovering - set the number of Covering
//           fsetSubSet        - set SubSet that is covering a respective Element
//           fsetElement       - set Element that is been covered by a SubSet
//           fsetWeight        - set Weight of the current SubSet
//           fsetTotalWeight   - set Total Weight of the solution
//           fsetTotalSubSetsUsed   - set total of SubSets used
//
//           fgetnumOfCovering - get the number of Covering
//           fgetSubSets       - get SubSets that are covering Elements
//           fgetElements      - get Elements that are covered by SubSets
//           fgetWeights       - get Weight of the current SubSet
//           fgetTotalWeight   - get Total Weight of the solution
//           fgetTotalSubSetsUsed   - get total of SubSets used
///////////////////////////////////////////////////////////////////

class coveringResult {
public:

	// Methods Set
	void fsetNumOfCovering( int inewNumOfCovering )
	{
	   inumOfCovering = inewNumOfCovering;
	}

	void fsetSubSet( int newSubSet )
	{
	   subSets.push_back(newSubSet);
	}

	void fsetElement( int newElement )
	{
	   elements.push_back(newElement);
	}

	void fsetWeight( int newWeight )
	{
	   weight.push_back(newWeight);
	}

	void fsetTotalWeight( int iNewTotalWeight )
	{
	   iTotalWeight = iNewTotalWeight;
	}

        void fsetTotalSubSetsUsed( int iNewTotalSubSetsUsed )
	{
	   iTotalSubSetsUsed = iNewTotalSubSetsUsed;
	}

	void fupdSubSet( int newSubSet, int pos )
	{
	   subSets[pos] = newSubSet;
	}

	void fupdWeight( int newWeight, int pos )
	{
	   weight[pos] = newWeight;
	}

	// Methods Get
	int fgetNumOfCovering()
	{
	   return(inumOfCovering);
	}

	int* fgetSubSets()
	{
          int *psubSets = new int[inumOfCovering];

	  for(int i=0;i<inumOfCovering;i++)
		  psubSets[i]=subSets[i];
          
	  return(psubSets);
	}

	int* fgetElements()
	{
          int *pElements = new int[inumOfCovering];

	  for(int i=0;i<inumOfCovering;i++)
		  pElements[i]=elements[i];
          
	  return(pElements);
	}

	int* fgetWeight()
	{
          int *pWeight = new int[inumOfCovering];

	  for(int i=0;i<inumOfCovering;i++)
		  pWeight[i]=weight[i];
          
	  return(pWeight);
	}

	int fgetTotalWeight()
	{
	   return(iTotalWeight);
	}

        int fgetTotalSubSetsUsed()
	{
	   return(iTotalSubSetsUsed);
	}

private:
	int inumOfCovering;
	int iTotalWeight;
	int iTotalSubSetsUsed;
	std::vector<int> subSets;
	std::vector<int> elements;
	std::vector<int> weight;
};

