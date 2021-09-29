#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef HireStaff_h
#include "HireStaff.h"
#define HireStaff_h
#endif 


#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

//#ifndef GamePlan_h
//#include "GamePlan.h"
//#define GamePlan_h
//#endif 




#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 

#ifndef BBallSettings_h
#include "BBallSettings.h"
#define BBallSettings_h
#endif

#ifndef BBallSchedule_h
#include "BBallSchedule.h"
#define BBallSchedule_h
#endif

#ifndef Own_h
#include "Own.h"
#define Own_h
#endif



class CAverage: public CObject
{
private:

	

	
public:
	void CalculateCareerAwards(CString file_name);
	void CalculateCareerStats(CString file_name);

	//void GetPositionValues(int *value, CStaff coach, int team_index);
	void SortTeamRosters(CPlayer *actual, bool ok_erase);
	void SortTeamRoster(int team, int s1, int s2, CPlayer *actual, bool ok_erase);

	
	void VerifyRosters(int t, bool &valid_rosters, bool &release_player, bool &dont_sign);
	void UpdateStaffStats(int *tempRosterValues, CRecord *record);
	void ComputerNegotiatesContracts();
	void ComputerSetsRotation();
	void ComputerRotationForTrades(CPlayer* actual, double* trade_values, int slots, int team1, int team2);
	void ComputerSortsRosterAfterTrades(CPlayer *actual, int slots);

	void SetStartSeasonAttributes(bool age);
	bool FileExists(CString file_name);

	
//	void CreateReport(CStaff m_scout, CPlayer &m_player);
	void UpdateStandings(int t1, int sc1, int t2, int sc2);
	void ConvertDataNewFormat();


	void CalculateCurrentPayroll(bool off_season);
	void ExpandRosters();
	void GenerateRandomProjections();
	void CalculateBetter(bool started);
	void GenerateRandomContracts(BOOL skip_ages, BOOL skip_contracts, BOOL skip_pot);
	
	void ReSortFranchiseData();

	int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}


	
	//int Random(int n);

	double Random(double n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return number;
	}


//	CGamePlan m_game_plan;

//	CFuture* m_future;
	
	CPlayer* m_actual;	
	CTeamFinancial* m_finance;
	CStaff* m_scout;
	CStaff* m_coach;
	CStaff* m_gm;
	CHireStaff* m_owner;
	CRecord* m_standings;
	COwn* m_own;
	CString m_string[101];
	int m_count[6];
	double m_avg_min_on_roster;
	double m_avg_min_for_adj;
	double m_avg_g[6];
	double m_avg_min[6];
	double m_avg_fgm[6];
	double m_avg_fga[6];
	double m_avg_fga_t[6];
	double m_avg_fgp[6];
	double m_avg_fgp_t[6];
	double m_avg_ftm[6];
	double m_avg_fta[6];
	double m_avg_ftp[6];
	double m_avg_tgm[6];
	double m_avg_tga[6];
	double m_avg_tgp[6];
	double m_avg_orb[6];
	double m_avg_drb[6];
	double m_avg_ast[6];
	double m_avg_stl[6];
	double m_avg_to[6];
	double m_avg_blk[6];
	double m_avg_pf[6];
	double m_avg_tru[6];
	double m_avg_tru_on_roster;
	double m_team_avg_tru[33];
	int m_team_hi_g[33];
	double m_avg_trade_tru[6];
	double m_avg_career_tru[6];

	int m_hi_min[6];
	int m_hi_g[6];
	int m_hi_fgm[6];
	int m_hi_fga[6];
	int m_hi_fgp[6];
	int m_hi_ftm[6];
	int m_hi_fta[6];
	int m_hi_ftp[6];
	int m_hi_tgm[6];
	int m_hi_tga[6];
	int m_hi_tgp[6];
	int m_hi_orb[6];
	int m_hi_drb[6];
	int m_hi_ast[6];
	int m_hi_stl[6];
	int m_hi_to[6];
	int m_hi_blk[6];
	int m_hi_pf[6];

	int r_min[6];
	int r_g[6];
	int r_fgm[6];
	int r_fga[6];
	int r_fgp[6];
	int r_ftm[6];
	int r_fta[6];
	int r_ftp[6];
	int r_tgm[6];
	int r_tga[6];
	int r_tgp[6];
	int r_orb[6];
	int r_drb[6];
	int r_ast[6];
	int r_stl[6];
	int r_to[6];
	int r_blk[6];
	int r_pf[6];

	int t_g[6];
	int t_min[6];
	int t_fgm[6];
	int t_fga[6];
	int t_fgp[6];
	int t_ftm[6];
	int t_fta[6];
	int t_ftp[6];
	int t_tgm[6];
	int t_tga[6];
	int t_tgp[6];
	int t_orb[6];
	int t_drb[6];
	int t_ast[6];
	int t_stl[6];
	int t_to[6];
	int t_blk[6];
	int t_pf[6];
	double t_tru[6];
	double t_trade_tru[6];
	double t_career_tru[6];

	CString m_trans_str[2001];

	CBBallSchedule m_sched;
	CBBallSettings m_settings;


void SetHighs(bool calculate)
{
		for(int i=0; i<=5; i++)
		{
		m_count[i] = 0;
		m_avg_g[i] = 0;
		m_avg_min[i] = 0;
		m_avg_min_on_roster = 0;
		m_avg_tru_on_roster = 0;

	    m_avg_fgm[i] = 0;
	    m_avg_fga[i] = 0;
	    m_avg_fga_t[i] = 0;
	    m_avg_fgp[i] = 0;
	    m_avg_fgp_t[i] = 0;
	    m_avg_ftm[i] = 0;
	    m_avg_fta[i] = 0;
	    m_avg_ftp[i] = 0;
	    m_avg_tgm[i] = 0;
	    m_avg_tga[i] = 0;
	    m_avg_tgp[i] = 0;
	    m_avg_orb[i] = 0;
	    m_avg_drb[i] = 0;
	    m_avg_ast[i] = 0;
	    m_avg_stl[i] = 0;
	    m_avg_to[i] = 0;
	    m_avg_blk[i] = 0;
	    m_avg_pf[i] = 0;
		m_avg_tru[i] = 0;
		m_avg_trade_tru[i] = 0;
		m_avg_career_tru[i] = 0;

		if(calculate == true)
		{
	    m_hi_fga[i] = 0;
	    m_hi_fta[i] = 0;
	    m_hi_fta[i] = 0;
	    m_hi_fta[i] = 0;
	    m_hi_drb[i] = 0;
	    m_hi_ast[i] = 0;
	    m_hi_stl[i] = 0;
	    m_hi_to[i] = 0;
	    m_hi_blk[i] = 0;
		}

		m_hi_min[i] = 0;
		m_hi_g[i] = 0;
	    m_hi_fgm[i] = 0;
	    m_hi_fgp[i] = 0;
	    m_hi_ftm[i] = 0;
	    m_hi_ftp[i] = 0;
	    m_hi_tgm[i] = 0;
	    m_hi_tgp[i] = 0;
	    m_hi_pf[i] = 0;

		t_g[i] = 0;
		t_min[i] = 0;
	    t_fgm[i] = 0;
	    t_fga[i] = 0;
	    t_fgp[i] = 0;
	    t_ftm[i] = 0;
	    t_fta[i] = 0;
	    t_ftp[i] = 0;
	    t_tgm[i] = 0;
	    t_tga[i] = 0;
	    t_tgp[i] = 0;
	    t_orb[i] = 0;
	    t_drb[i] = 0;
	    t_ast[i] = 0;
	    t_stl[i] = 0;
	    t_to[i] = 0;
	    t_blk[i] = 0;
	    t_pf[i] = 0;
		t_tru[i] = 0;
		t_trade_tru[i] = 0;
		t_career_tru[i] = 0;
		r_g[i] = 0;
		r_min[i] = 0;
	    r_fgm[i] = 0;
	    r_fga[i] = 0;
	    r_fgp[i] = 0;
	    r_ftm[i] = 0;
	    r_fta[i] = 0;
	    r_ftp[i] = 0;
	    r_tgm[i] = 0;
	    r_tga[i] = 0;
	    r_tgp[i] = 0;
	    r_orb[i] = 0;
	    r_drb[i] = 0;
	    r_ast[i] = 0;
	    r_stl[i] = 0;
	    r_to[i] = 0;
	    r_blk[i] = 0;
	    r_pf[i] = 0;

		}		

for(int i=0; i<=32; i++) 
{
		m_team_avg_tru[i] = 0;
		m_team_hi_g[i] = 0;
}
		
int counter = 1;
int ti = 1;
double tr = 0, mp = 0;
int hi_g = 0;
int min_on_roster = 0;
int g_on_roster = 0;
double tru_on_roster = 0;
double tru_min_on_roster = 0;
int min_adj = 0;
int g_adj = 0;
double total_team_avg_tru = 0;

for(int i=1; i<=960; i++) 
{
	
		CPlayer m_player = m_actual[i];

		if(i <= 960)
		{
			if(counter <= 12)
			{
				min_on_roster = min_on_roster + m_player.m_min;
				g_on_roster = g_on_roster + m_player.m_games;
				if(counter <= 8)
				{
					tru_on_roster = tru_on_roster + m_player.GetTrueRatingSimple();
					tru_min_on_roster = tru_min_on_roster + m_player.m_min;
				}

			}
			tr = tr + m_player.GetTrueRatingSimple();
			mp = mp + (double) m_player.GetMin();		
			if(m_player.GetGames() > hi_g) hi_g = m_player.GetGames();
			counter = counter + 1;
			if(counter > 30)
			{
				m_team_hi_g[ti] = hi_g;
				m_team_avg_tru[ti] = tr / mp * 48; 
				total_team_avg_tru = total_team_avg_tru + m_team_avg_tru[ti];
				counter = 1;
				tr = 0;
				mp = 0;
				ti = ti + 1;
				hi_g = 0;
			}
		}


	if(m_player.GetName() != "" && m_player.GetMin() > (m_player.GetGames()*2))
		{
	

//		if(m_player.GetName() == "" || m_player.GetMin() <= 0) continue;


		for(int t=0; t<=1; t++)//1st time all positions 2nd time specific position
		{
		int po = 0;
		CString pos = m_player.GetPos();
		if(t == 1) 
			po = 0;
		else
		{
			if(pos == "PG") po = 1;
			else if(pos == "SG") po = 2;
			else if(pos == "SF") po = 3;
			else if(pos == "PF") po = 4;
			else if(pos == " C") po = 5;
		}

		m_count[po] = m_count[po] + 1; //count elegible players
		double min = double(m_player.GetMin());
		double pen =
			1 + ((min / double(m_player.GetGames()) - 24) / 2 / 48);
		if(pen > 1) pen = 1;

		if(min > m_hi_min[po]) m_hi_min[po] = int(min);
		
		double  f = ((double(m_player.GetFga()) - double(m_player.GetTfga()))/min*480) * pen;
		int n = int(f) + 1;
		if(calculate == true && n > m_hi_fga[po]) m_hi_fga[po] = n;


		f = (double(m_player.GetFta())/min*480) * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_fta[po]) m_hi_fta[po] = n;

		f = double(m_player.GetTfga())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_tga[po]) m_hi_tga[po] = n;


		f = (  double(m_player.GetFgm()) - double(m_player.GetTfgm()) )
		   / (  double(m_player.GetFga()) - double(m_player.GetTfga()) );
		n = int(f*100);
		if(n > m_hi_fgp[po]) m_hi_fgp[po] = n;

		f =   double(m_player.GetTfgm()) /  double(m_player.GetTfga());
		n = int(f*100);
		if(n > m_hi_tgp[po]) m_hi_tgp[po] = n;

		f =   double(m_player.GetFtm()) /  double(m_player.GetFta());
		n = int(f*100);
		if(n > m_hi_ftp[po]) m_hi_ftp[po] = n;

		f = double(m_player.GetOreb())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_orb[po]) m_hi_orb[po] = n;

		f = (double(m_player.GetReb()) - double(m_player.GetOreb()))/min*480 * pen;
		n = int(f) + 1;
 		if(calculate == true && n > m_hi_drb[po]) m_hi_drb[po] = n;

		f = double(m_player.GetAst())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_ast[po]) m_hi_ast[po] = n;

		f = double(m_player.GetStl())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_stl[po]) m_hi_stl[po] = n;

		f = double(m_player.GetTo())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_to[po]) m_hi_to[po] = n;

		f = double(m_player.GetBlk())/min*480 * pen;
		n = int(f) + 1;
		if(calculate == true && n > m_hi_blk[po]) m_hi_blk[po] = n;
		
		f = double(m_player.GetPf())/min*480 * pen;
		n = int(f) + 1;
		if(n > m_hi_pf[po]) m_hi_pf[po] = n;


		
		if(m_player.GetGames() > m_hi_g[po]) m_hi_g[po] = m_player.GetGames();
		t_g[po] = t_g[po] + m_player.GetGames();
		t_min[po] = t_min[po] + m_player.GetMin();
		t_fgm[po] = t_fgm[po] + (m_player.GetFgm() - m_player.GetTfgm());
		t_fga[po] = t_fga[po] + (m_player.GetFga() - m_player.GetTfga());
		t_ftm[po] = t_ftm[po] + m_player.GetFtm();
		t_fta[po] = t_fta[po] + m_player.GetFta();
		t_tgm[po] = t_tgm[po] + m_player.GetTfgm();
		t_tga[po] = t_tga[po] + m_player.GetTfga();
		t_orb[po] = t_orb[po] + m_player.GetOreb();
		t_drb[po] = t_drb[po] + (m_player.GetReb() - m_player.GetOreb());
		t_ast[po] = t_ast[po] + m_player.GetAst();
		t_stl[po] = t_stl[po] + m_player.GetStl();
		t_to[po] = t_to[po] + m_player.GetTo();
		t_blk[po] = t_blk[po] + m_player.GetBlk();
		t_pf[po] = t_pf[po] + m_player.GetPf();

		m_player.SetTrueRatingSimple(2);//actual
		t_tru[po] = t_tru[po] + m_player.GetTrueRatingSimple();
		t_trade_tru[po] = t_trade_tru[po] + m_player.GetTradeTrueRating(FALSE);
		t_career_tru[po] = t_career_tru[po] + m_player.GetTradeTrueRating(TRUE);
		}

		}
}		


//calculate team avg true
		m_team_avg_tru[0] = total_team_avg_tru / (double)m_settings.m_numberteams;


//averages

	m_avg_min_on_roster = (double)min_on_roster / (double)g_on_roster;
	m_avg_tru_on_roster = tru_on_roster / (double) tru_min_on_roster * 48;




for(int po=0; po<=5; po++)
{


	 //m_hi_fga[po] = 320;
	 //m_hi_fta[po] =  160;
	 //m_hi_tga[po] = 160;
	 //m_hi_orb[po] = 120;
	 //m_hi_drb[po] = 180;
	 //m_hi_ast[po] =  240;
	 //m_hi_stl[po] = 60;
	 //m_hi_to[po] = 90;
	 //m_hi_blk[po] = 120;


	if(m_count[po] == 0) m_count[po] = 1;
	m_avg_g[po] = double(t_g[po]) / m_count[po];
	m_avg_min[po] = double(t_min[po]) / t_g[po];
	m_avg_fgm[po] = double(t_fgm[po])/t_min[po]*48;
	m_avg_fga[po] = double(t_fga[po])/t_min[po]*48;
	m_avg_fga_t[po] = (double(t_fga[po]) + double(t_tga[po])) / t_min[po]*48;
	m_avg_fgp[po] = double(t_fgm[po])/t_fga[po]*100;


	m_avg_ftm[po] = double(t_ftm[po])/t_min[po]*48;
	m_avg_fta[po] = double(t_fta[po])/t_min[po]*48;
	m_avg_ftp[po] = double(t_ftm[po])/t_fta[po]*100;


	m_avg_tgm[po] = double(t_tgm[po])/t_min[po]*48;
	m_avg_tga[po] = double(t_tga[po])/t_min[po]*48;
	m_avg_tgp[po] = double(t_tgm[po])/t_tga[po]*100;

	m_avg_fgp_t[po] = ((double)t_fgm[po] + (double)t_tgm[po]) / ((double)t_fga[po] + (double)t_tga[po]) * 100;


	m_avg_orb[po] = double(t_orb[po])/t_min[po]*48;
	m_avg_drb[po] = double(t_drb[po])/t_min[po]*48;
	m_avg_ast[po] = double(t_ast[po])/t_min[po]*48;
	m_avg_stl[po] = double(t_stl[po])/t_min[po]*48;
	m_avg_to [po] = double(t_to[po])/t_min[po]*48;
	m_avg_blk[po] = double(t_blk[po])/t_min[po]*48;
	m_avg_pf[po] = double(t_pf[po])/t_min[po]*48;
	m_avg_tru[po] = double(t_tru[po])/t_min[po]*48;
	m_avg_trade_tru[po] = double(t_trade_tru[po])/m_count[po];
	m_avg_career_tru[po] = double(t_career_tru[po])/m_count[po];
	
	r_fga[po] = int(m_avg_fga[po]/ m_hi_fga[0] * 1000)+1;
	r_fta[po] = int(m_avg_fta[po]/ m_hi_fta[0] * 1000)+1;
	r_tga[po] = int(m_avg_tga[po]/ m_hi_tga[0] * 1000)+1;

	r_orb[po] = int(m_avg_orb[po]/ m_hi_orb[0] * 1000)+1;
	r_drb[po] = int(m_avg_drb[po]/ m_hi_drb[0] * 1000)+1;
	r_ast[po] = int(m_avg_ast[po]/ m_hi_ast[0] * 1000)+1;
	r_stl[po] = int(m_avg_stl[po]/ m_hi_stl[0] * 1000)+1;
	r_to[po] = 100 - int(m_avg_to[po]/ m_hi_to[0] * 1000)+1;
	r_blk[po] = int(m_avg_blk[po]/ m_hi_blk[0]* 1000)+1;

}

}



CAverage()
{
	


	
	m_finance = new CTeamFinancial[201];
//	m_future = new CFuture[101];
    m_actual = new CPlayer[1601];
	m_scout = new CStaff[101];
	m_coach = new CStaff[101];
	m_gm = new CStaff[101];
	m_owner = new CHireStaff[101];
	m_standings = new CRecord[33];
	m_own = new COwn[33];
	m_avg_min_on_roster = 0;
	m_avg_min_for_adj = 0;
	m_avg_tru_on_roster = 0;
		for(int i=0; i<=5; i++)
		{
		m_count[i] = 0;
		m_avg_g[i] = 0;
		m_avg_min[i] = 0;
	    m_avg_fgm[i] = 0;
	    m_avg_fga[i] = 0;
	    m_avg_fga_t[i] = 0;
	    m_avg_fgp[i] = 0;
	    m_avg_fgp_t[i] = 0;
	    m_avg_ftm[i] = 0;
	    m_avg_fta[i] = 0;
	    m_avg_ftp[i] = 0;
	    m_avg_tgm[i] = 0;
	    m_avg_tga[i] = 0;
	    m_avg_tgp[i] = 0;
	    m_avg_orb[i] = 0;
	    m_avg_drb[i] = 0;
	    m_avg_ast[i] = 0;
	    m_avg_stl[i] = 0;
	    m_avg_to[i] = 0;
	    m_avg_blk[i] = 0;
	    m_avg_pf[i] = 0;
		m_avg_tru[i] = 0;
		m_avg_career_tru[i] = 0;
		m_avg_trade_tru[i] = 0;

		m_hi_min[i] = 0;
		m_hi_g[i] = 0;
	    m_hi_fgm[i] = 0;
	    m_hi_fga[i] = 0;
	    m_hi_fgp[i] = 0;
	    m_hi_ftm[i] = 0;
	    m_hi_fta[i] = 0;
	    m_hi_ftp[i] = 0;
	    m_hi_tgm[i] = 0;
	    m_hi_tga[i] = 0;
	    m_hi_tgp[i] = 0;
	    m_hi_orb[i] = 0;
	    m_hi_drb[i] = 0;
	    m_hi_ast[i] = 0;
	    m_hi_stl[i] = 0;
	    m_hi_to[i] = 0;
	    m_hi_blk[i] = 0;
	    m_hi_pf[i] = 0;

		t_g[i] = 0;
		t_min[i] = 0;
	    t_fgm[i] = 0;
	    t_fga[i] = 0;
	    t_fgp[i] = 0;
	    t_ftm[i] = 0;
	    t_fta[i] = 0;
	    t_ftp[i] = 0;
	    t_tgm[i] = 0;
	    t_tga[i] = 0;
	    t_tgp[i] = 0;
	    t_orb[i] = 0;
	    t_drb[i] = 0;
	    t_ast[i] = 0;
	    t_stl[i] = 0;
	    t_to[i] = 0;
	    t_blk[i] = 0;
	    t_pf[i] = 0;
		t_tru[i] = 0;
		t_trade_tru[i] = 0;
		t_career_tru[i] = 0;

		r_g[i] = 0;
		r_min[i] = 0;
	    r_fgm[i] = 0;
	    r_fga[i] = 0;
	    r_fgp[i] = 0;
	    r_ftm[i] = 0;
	    r_fta[i] = 0;
	    r_ftp[i] = 0;
	    r_tgm[i] = 0;
	    r_tga[i] = 0;
	    r_tgp[i] = 0;
	    r_orb[i] = 0;
	    r_drb[i] = 0;
	    r_ast[i] = 0;
	    r_stl[i] = 0;
	    r_to[i] = 0;
	    r_blk[i] = 0;
	    r_pf[i] = 0;

		}

for(int i=0; i<=32; i++) 
{
		m_team_avg_tru[i] = 0;
		m_team_hi_g[i] = 0;

}

for(int i=1; i<=2000; i++) 
{
	m_trans_str[i] = "";

}

}






	~CAverage()
	{
	   delete [] m_finance;
//	   delete [] m_future;
	   delete [] m_actual;
	   delete [] m_scout;
	   delete [] m_coach;
	   delete [] m_gm;
	   delete [] m_owner;
	   delete [] m_standings;
	   delete [] m_own;
				
	}	
	
	const CAverage& operator=( const CAverage& a )
    {

		//m_trans_str = a.m_trans_str;
		m_avg_min_on_roster = a.m_avg_min_on_roster;
		m_avg_min_for_adj = a.m_avg_min_for_adj;
		m_avg_tru_on_roster = a.m_avg_tru_on_roster;
		for(int i=0; i<=5; i++)
		{

		m_count[i] = a.m_count[i];
		m_avg_g[i] = a.m_avg_g[i];
		m_avg_min[i] = a.m_avg_min[i];
	    m_avg_fgm[i] = a.m_avg_fgm[i];
	    m_avg_fga[i] = a.m_avg_fga[i];
	    m_avg_fga_t[i] = a.m_avg_fga_t[i];
	    m_avg_fgp[i] = a.m_avg_fgp[i];
	    m_avg_fgp_t[i] = a.m_avg_fgp_t[i];
	    m_avg_ftm[i] = a.m_avg_ftm[i];
	    m_avg_fta[i] = a.m_avg_fta[i];
	    m_avg_ftp[i] = a.m_avg_ftp[i];
	    m_avg_tgm[i] = a.m_avg_tgm[i];
	    m_avg_tga[i] = a.m_avg_tga[i];
	    m_avg_tgp[i] = a.m_avg_tgp[i];
	    m_avg_orb[i] = a.m_avg_orb[i];
	    m_avg_drb[i] = a.m_avg_drb[i];
	    m_avg_ast[i] = a.m_avg_ast[i];
	    m_avg_stl[i] = a.m_avg_stl[i];
	    m_avg_to[i] = a.m_avg_to[i];
	    m_avg_blk[i] = a.m_avg_blk[i];
	    m_avg_pf[i] = a.m_avg_pf[i];
		m_avg_tru[i] = a.m_avg_tru[i];
		m_avg_trade_tru[i] = a.m_avg_trade_tru[i];
		m_avg_career_tru[i] = a.m_avg_career_tru[i];

		m_hi_min[i] = a.m_hi_min[i];
		m_hi_g[i] = a.m_hi_g[i];
	    m_hi_fgm[i] = a.m_hi_fgm[i];
	    m_hi_fga[i] = a.m_hi_fga[i];
	    m_hi_fgp[i] = a.m_hi_fgp[i];
	    m_hi_ftm[i] = a.m_hi_ftm[i];
	    m_hi_fta[i] = a.m_hi_fta[i];
	    m_hi_ftp[i] = a.m_hi_ftp[i];
	    m_hi_tgm[i] = a.m_hi_tgm[i];
	    m_hi_tga[i] = a.m_hi_tga[i];
	    m_hi_tgp[i] = a.m_hi_tgp[i];
	    m_hi_orb[i] = a.m_hi_orb[i];
	    m_hi_drb[i] = a.m_hi_drb[i];
	    m_hi_ast[i] = a.m_hi_ast[i];
	    m_hi_stl[i] = a.m_hi_stl[i];
	    m_hi_to[i] = a.m_hi_to[i];
	    m_hi_blk[i] = a.m_hi_blk[i];
	    m_hi_pf[i] = a.m_hi_pf[i];

		t_min[i] = a.t_min[i];
		t_g[i] = a.t_g[i];
	    t_fgm[i] = a.t_fgm[i];
	    t_fga[i] = a.t_fga[i];
	    t_fgp[i] = a.t_fgp[i];
	    t_ftm[i] = a.t_ftm[i];
	    t_fta[i] = a.t_fta[i];
	    t_ftp[i] = a.t_ftp[i];
	    t_tgm[i] = a.t_tgm[i];
	    t_tga[i] = a.t_tga[i];
	    t_tgp[i] = a.t_tgp[i];
	    t_orb[i] = a.t_orb[i];
	    t_drb[i] = a.t_drb[i];
	    t_ast[i] = a.t_ast[i];
	    t_stl[i] = a.t_stl[i];
	    t_to[i] = a.t_to[i];
	    t_blk[i] = a.t_blk[i];
	    t_pf[i] = a.t_pf[i];


		t_tru[i] = a.t_tru[i];
		t_career_tru[i] = a.t_career_tru[i];
		t_trade_tru[i] = a.t_trade_tru[i];

		r_min[i] = a.r_min[i];
		r_g[i] = a.r_g[i];
	    r_fgm[i] = a.r_fgm[i];
	    r_fga[i] = a.r_fga[i];
	    r_fgp[i] = a.r_fgp[i];
	    r_ftm[i] = a.r_ftm[i];
	    r_fta[i] = a.r_fta[i];
	    r_ftp[i] = a.r_ftp[i];
	    r_tgm[i] = a.r_tgm[i];
	    r_tga[i] = a.r_tga[i];
	    r_tgp[i] = a.r_tgp[i];
	    r_orb[i] = a.r_orb[i];
	    r_drb[i] = a.r_drb[i];
	    r_ast[i] = a.r_ast[i];
	    r_stl[i] = a.r_stl[i];
	    r_to[i] = a.r_to[i];
	    r_blk[i] = a.r_blk[i];
	    r_pf[i] = a.r_pf[i];


		}	

		for(int i=0; i<=32; i++) 
		{
			m_team_avg_tru[i] = a.m_team_avg_tru[i];
			m_team_hi_g[i] = a.m_team_hi_g[i];
		}

		for(int i=0; i<=1600; i++)
		{
			m_actual[i] = a.m_actual[i];
		}

	

		for(int i=0; i<=200; i++)
		{
			m_finance[i] = a.m_finance[i];
		}

		for(int i=0; i<=100; i++)
		{
//			m_future[i] = a.m_future[i];
			m_scout[i] = a.m_scout[i];
			m_coach[i] = a.m_coach[i];
			m_gm[i] = a.m_gm[i];
			m_owner[i] = a.m_owner[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_standings[i] = a.m_standings[i];
			m_own[i] = a.m_own[i];
		}





		m_sched = a.m_sched;
		m_settings = a.m_settings;

	for(int i=1; i<=2000; i++) 
	{
		m_trans_str[i] = a.m_trans_str[i];

	}

		

	return *this;
	}	
  
};