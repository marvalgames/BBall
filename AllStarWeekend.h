

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

class CAllStarWeekend: public CObject
{

private:


public:
	void ReadUserSelections(int *m_index, CString user_file_name);
	void SimThreePointContestRoundThree();
	void SimThreePointContestRoundTwo();
	void SimThreePointContestRoundOne();

	
	void SimSlamDunkContestRoundTwo();
	void SimSlamDunkContestRoundOne();

	void SelectDunkContestants();
	void SelectThreePointContestants();
	void SelectRookieTeams();
	CPlayer* m_actual;//1-60 is all star team 61-70 three players 71-80 dunkers
	void SelectAllStarTeams();
	CAverage avg;
	int m_scores[31];
	CAllStarWeekend();
	~CAllStarWeekend();

};