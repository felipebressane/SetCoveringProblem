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
//  File:    scp.struct.support.h                                        
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
//  Structure: st_coveringResultSupport
//-----------------------------------------------------------------
//  Description: structure used to sort the SubSets with more 
//               Elements
//-----------------------------------------------------------------
//  Members: SubSet         - subSet that cover a group of Elements
//           iTotalElements - Total of elements covered by subset
//           OriginalPositions  - Original Positions in the 
//                                CoveringResult
///////////////////////////////////////////////////////////////////
struct st_coveringResultSupport {
	int SubSet;
	int iTotalElementsCovered;
	std::vector<int> OriginalPositions;
};


///////////////////////////////////////////////////////////////////
//  Structure: st_coverageCostSupport
//-----------------------------------------------------------------
//  Description: structure is used to sort Coverage Cost
//-----------------------------------------------------------------
//  Members: SubSet       - subSet that cover a group of Elements
//           coverageCost - Coverage Cost of a specific SubSet
///////////////////////////////////////////////////////////////////
struct st_coverageCostSupport {
	int SubSet;
	float coverageCost;
};

/*
///////////////////////////////////////////////////////////////////
//  Structure: st_coveringCheckElements
//-----------------------------------------------------------------
//  Description: structure is used to check covering Elements
//-----------------------------------------------------------------
//  Members: Element              - Element
//           numOfSets            - number of Sets for a Element
//           isAllSubSetChecked   - if all SubSets were checked
//           SubSets              - SubSets that covering the Element
//           isSubSetChecked      - if the SubSet was checked for a Element
///////////////////////////////////////////////////////////////////
struct st_coveringCheckElements {
	int Element;
	int numOfSets;
	int isAllSubSetChecked;
	std::vector<int> SubSets;
	std::vector<int> isSubSetChecked;
};
*/
