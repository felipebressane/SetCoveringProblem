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
//  File:    scp.class.subset.h                                        
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
//  Class: subset
//-----------------------------------------------------------------
//  Description: Class with informations about a specific subset.
//-----------------------------------------------------------------
//  Members: numSubSet      - subset number
//           weight         - weght of a subset
//           numOfElements  - number of Elements covered by subset
//           elements       - elements covered by subset
//-----------------------------------------------------------------
//  Methods: fsetNumSubSet     - set informartion about SubSet Number
//           fsetWeight        - set information about Subset weight
//           fsetElements      - set all Elements covered by a SubSet
//           fsetNumOfElements - set numbers of Elements covered by 
//                               a SubSet
//           fgetNumSubSet     - get informartion about SubSet Number
//           fgetWeight        - get information about Subset weight
//           fgetElements      - get all Elements covered by a SubSet
//           fgetNumOfElements - get numbers of Elements covered by 
//                               a SubSet
///////////////////////////////////////////////////////////////////

class subSet {
public:

	// Methods Set
	void fsetNumSubSet( int newSubSet )
	{
            numSubSet=newSubSet;
	}

	void fsetWeight( int newWeight )
	{
            weight=newWeight;
	}

	void fsetElements( int newElement )
	{
	    
	    elements.push_back(newElement);
	}

	void fsetNumOfElements( int newNumOfElements )
	{
            numOfElements=newNumOfElements;
	}

	void fsetCoverageCost( float newCostCoverage )
	{
            costCoverage=newCostCoverage;
	}


	// Methods Get
        int fgetNumSubSet()
        {
	    return(numSubSet);
        }

        int fgetWeight() 
        {
	    return(weight);
        }

	int fgetnumOfElements()
	{
            return(numOfElements);
	}

	float fgetCoverageCost()
	{
            return(costCoverage);
	}

	int *fgetElements()
	{
	    
            int *pElements = new int[numOfElements];

	    for(int i=0;i<numOfElements;i++)
		  pElements[i]=elements[i];
          
	    return(pElements);
	   
	}

private: 
        int    numSubSet;
        int    weight;
	int    numOfElements;
	float  costCoverage;
	std::vector<int> elements;
};

