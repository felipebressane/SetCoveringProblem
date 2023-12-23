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
//  File:    scp.class.element.h                                        
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
//  Class: element                                                
//-----------------------------------------------------------------
//  Description: Class with informations about a specific element.
//-----------------------------------------------------------------
//  Members:  element   - element number
//            numOfSets - number of sets that cover a element
//            *subSets  - all sets that cover a element
//-----------------------------------------------------------------
//  Methods:  fsetElement   - set number of Element
//            fsetNumOfSets - set quantity of Sets to a Element
//            fsetSubSet    - set all SubSets to a Element
//            fgetElement   - get a Element number
//            fgetElement   - get quantity of Sets to a Element
//            fgetSubSets   - get all SubSets to a Element
///////////////////////////////////////////////////////////////////

class element {
public:

	// Methods Set
	void fsetElement( int newElement )
	{
          element=newElement;
	}

	void fsetNumOfSets( int newNumOfSets )
	{
          numOfSets=newNumOfSets;
	}

	void fsetisAllSubSetChecked( int newisAllSubSetChecked )
	{
          isAllSubSetChecked=newisAllSubSetChecked;
	}

	void fsetSubSet( int newSubSet )
	{
	   subSets.push_back(newSubSet);
	}

	void fsetisSubSetChecked( int newisSubSetChecked )
	{
	   isSubSetChecked.push_back(newisSubSetChecked);
	}

	void fupdisSubSetChecked( int newisSubSetChecked, int pos )
	{
	   isSubSetChecked.at(pos) = newisSubSetChecked;
	}

	void fsetQtdChecked( int newiQtdChecked )
	{
           iQtdChecked=newiQtdChecked;
	}

	// Methods Get
	int fgetElement()
	{
          return(element);
	}

	int fgetNumOfSets()
	{
          return(numOfSets);
	}

	int fgetisAllSubSetChecked()
	{
          return(isAllSubSetChecked);
	}

	int* fgetSubSets()
	{
          int *psubSets = new int[numOfSets];

	  for(int i=0;i<numOfSets;i++)
		  psubSets[i]=subSets[i];
          
	  return(psubSets);
	}

	int* fgetisSubSetChecked()
	{
          int *pisSubSetChecked = new int[numOfSets];

	  for(int i=0;i<numOfSets;i++)
		  pisSubSetChecked[i]=isSubSetChecked[i];
          
	  return(pisSubSetChecked);
	}

	int fgetQtdChecked()
	{
          return(iQtdChecked);
	}

private:
        int element;
        int numOfSets;
	int iQtdChecked;
	int isAllSubSetChecked;
	std::vector<int> subSets;
	std::vector<int> isSubSetChecked;
};
