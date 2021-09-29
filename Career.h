
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 


class CCareer: public CObject
{

private:




		int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}

	

	//int Random(int n);
	double Random(double n);
	CString lname[3001];
	CString fname[3001];
	double SetImprovementVariable(int yrs_to_prime, double adj,  double pot, int intangible);
	int PrimeAge[1441];
	int Pot1[1441];
	int Pot2[1441];
	int Effort[1441];
//	double GetRookieTrue(int g, double min, double fgm, double fga, double tgm, double tga, double ftm, double fta, 
//							  double orb, double drb, double ast, double stl, double to, double blk, double pf);

public:
	int m_numberteams;

	void ReadCareerStats(CPlayer *m_stats, CString pFileName, int slot, int &round, int &pos, int &overall, int &yrs_pro);
	CAverage avg;
	BOOL m_checkCareer;
	CString CreateName();
	CStaff m_coach[33];
	int m_currentYear;
	CString m_leagueTeamNames[33];
	void CreateRandomStaffProfiles();
	void SetStatsArray();
	void ReadNames();
	double avg_tru;
	CPlayer* m_actual;
	int m_hiG;
	CString m_path;
	CString m_leagueName;

	void CreateEmptyFile();
	int GetCurrentID();	
	void WriteCurrentID(int id);
	void SetupID();//write player id once to .dta file at beginning of season
	void WriteCareerStats();
	void AdjustScoring();

	CCareer();
	~CCareer();
};





