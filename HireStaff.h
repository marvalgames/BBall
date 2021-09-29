#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

//#ifndef Display_h
//#include "Display.h"
//#define Display_h
//#endif 


class CHireStaff: public CStaff
{

	
public:
	void CheckOffers(int off, int owner_index, int choice, CPlayer &player);
	void SetTopFreeAgentExtension(CPlayer actual, CStaff gm);
	void SetOwnerSalaryCap(int owner_salary_cap);
	int m_offers_this_round;
	double Random(double n);
	//int Random(int n);
	bool AllowHiring(CString file_name);
	void DisallowStaffHiring(CString file_name);

	int MinimumSalary(CPlayer contract);
	void AdjustContractOfferToMinimum(CPlayer contract, int n);
	void SetLeagueSalaryCap(int m_cap);
	bool OverCap(bool exception);
	bool AffordContract(CPlayer contract, CStaff gm, bool &exception);
	bool ContractUnderOwnerSalaryCap(CPlayer contract);
	void CurrentPayroll(CPlayer contracts[1441], int index, bool signing_ok);
	int CurrentYearPayroll(CPlayer contracts[], int index);
	void SetTopFreeAgentContract(CPlayer free_agent, CStaff gm, int n, int stage);
	void SetTopFreeAgent(CPlayer *free_agents, CStaff scout, CStaff coach, CStaff gm, int owner_index, int stage);
	int m_loss;
	int m_win;
	void SetScoutFiringLine(CStaff m_scout);
	void SetCoachFiringLine(CStaff m_coach);
	void SetGmFiringLine(CStaff m_gm);
	int ScoutStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record);
	int CoachStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record);
	int GmStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record);
	void SetRosterValue(CPlayer* m_actual, int index);
	void SetPositionValues(CPlayer* m_actual, int index, CStaff coach);
	void SetPositionValuesSortedList(CPlayer* m_actual, CStaff coach, int team_index);

	bool FireScout(CStaff m_scout);
	bool FireCoach(CStaff m_coach);
	bool FireGM(CStaff m_gm);

	bool RetireScout(CStaff m_scout);
	bool RetireCoach(CStaff m_coach);
	bool RetireGM(CStaff m_gm);

	bool ResignScout(CStaff m_scout, double win_pct);
	bool ResignCoach(CStaff m_coach, double win_pct);
	bool ResignGM(CStaff m_gm, double win_pct);

	void SetTopCoach(CStaff m_coach[101], int owner);
	void SetTopScout(CStaff m_scout[101], int owner);
	void SetTopGM(CStaff m_gm[101], int owner);
//	void WriteCareerStaff(CString pFileName, CStaff m_scout[101], CStaff m_coach[101], CStaff m_gm[101]);


	int m_x[1441];
	int m_current_payroll[7];
	int m_temp_payroll[7];


	int m_rosterValue;
	int m_owner_patience;
	int m_topCoach;
	int m_topScout;
	int m_topGM;
	bool m_hireCoach;
	bool m_hireScout;
	bool m_hireGM;
	bool m_hiredCoachOnce;
	bool m_hiredGmOnce;
	bool m_hiredScoutOnce;
	int	m_firingLineScout;
	int	m_firingLineCoach;
	int	m_firingLineGM;
	int	m_record;
	int	m_scoutStatus;
	int	m_coachStatus;
	int	m_gmStatus;
	double m_position_values[6];
	int m_released_salaries[7];

	bool m_madeScoutOffer;	
	bool m_madeCoachOffer;	
	bool m_madeGmOffer;	

	int m_top_free_agent[16];
	int m_top_free_agent_total_salary[16];
	int m_top_free_agent_years[16];
	int m_top_free_agent_salaries[16][7];
	int m_signed_players;

	int m_risk;
	int m_player_spending;
	int m_over_cap;
	int m_team_index;
	int m_minimum[12];
		
	bool m_mid_exception_used;
	int m_mid_exception_offered;
	bool m_million_exception_used;
	int m_million_exception_offered;
	
	int m_salary_cap;
	long m_owner_salary_cap;
	
	CHireStaff()
	{
		m_offers_this_round = 0;

		
		
		m_firingLineScout = 0;
		m_firingLineCoach = 0;
		m_firingLineGM = 0;
		m_record = 0;

		m_rosterValue = 0;
		m_owner_patience = 0;
		m_topCoach = -1;
		m_topScout = -1;
		m_topGM = -1;
		m_hireCoach = false;
		m_hireScout = false;
		m_hireGM = false;
		m_hiredCoachOnce = false;
		m_hiredGmOnce = false;
		m_hiredScoutOnce = false;

		m_scoutStatus = 0;
		m_coachStatus = 0;
		m_gmStatus = 0;
		m_madeScoutOffer = 0;	
		m_madeCoachOffer = 0;	
		m_madeGmOffer = 0;	
		m_win = 0;
		m_loss = 0;

		for(int i=0; i<=5; i++)
		{
			m_position_values[i] = 0;
		}

		for(int i=0; i<=6; i++)
		{
			m_current_payroll[i] = 0;
			m_temp_payroll[i] = 0;
		}

		for(int i=0; i<=6; i++)
		{
			m_released_salaries[i] = 0;
		}

		for(int i=0; i<=1440; i++)
		{
			m_x[i] = 0;
		}

		for(int i=0; i<=15; i++)
		{
			m_top_free_agent[i] = -1;
			m_top_free_agent_total_salary[i] = 0;
			m_top_free_agent_years[i] = 0;
		}

		for(int i=0; i<=15; i++)
		{
			for(int j=0; j<=6; j++)
			{
				m_top_free_agent_salaries[i][j] = 0;//yr by yr amts
			}
		}

		m_signed_players = 0;
		
		m_salary_cap = 0;
		m_owner_salary_cap = 0;
		m_risk = 3;
		m_player_spending = 3;
		m_over_cap = 0;
		m_team_index = 0;

			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;


		m_mid_exception_used = false;
		m_mid_exception_offered = -1;
		m_million_exception_used = false;
		m_million_exception_offered = -1;

	}
	~CHireStaff()
	{
		
	
	}

	//copy constructor
	CHireStaff( const CHireStaff& a ) 
	{ 
		
		m_offers_this_round = a.m_offers_this_round;
		m_firingLineScout = a.m_firingLineScout;
		m_firingLineCoach = a.m_firingLineCoach;
		m_firingLineGM = a.m_firingLineGM;
		m_record = a.m_record;
		m_rosterValue = a.m_rosterValue;
		m_owner_patience = a.m_owner_patience;
		m_topCoach = a.m_topCoach;
		m_topScout = a.m_topScout;
		m_topGM = a.m_topGM;
		m_hireCoach = a.m_hireCoach;
		m_hireScout = a.m_hireScout;
		m_hireGM = a.m_hireGM;
		m_hiredCoachOnce = a.m_hiredCoachOnce;
		m_hiredGmOnce = a.m_hiredGmOnce;
		m_hiredScoutOnce = a.m_hiredScoutOnce;
		m_scoutStatus = a.m_scoutStatus;
		m_coachStatus = a.m_coachStatus;
		m_gmStatus = a.m_gmStatus;
		m_madeScoutOffer = a.m_madeScoutOffer;	
		m_madeCoachOffer = a.m_madeCoachOffer;	
		m_madeGmOffer = a.m_madeGmOffer;	
		m_win = a.m_win;
		m_loss = a.m_loss;
		for(int i=0; i<=5; i++)
		{
			m_position_values[i] = a.m_position_values[i];
		}
		for(int i=0; i<=6; i++)
		{
			m_current_payroll[i] = a.m_current_payroll[i];
			m_temp_payroll[i] = a.m_temp_payroll[i];
			m_released_salaries[i] = a.m_released_salaries[i];

		}

		for(int i=0; i<=1440; i++)
		{
			m_x[i] = a.m_x[i];
		}





		for(int i=0; i<=15; i++)
		{
			m_top_free_agent[i] = a.m_top_free_agent[i];
			m_top_free_agent_total_salary[i] = a.m_top_free_agent_total_salary[i];
			m_top_free_agent_years[i] = a.m_top_free_agent_years[i];
		}

		for(int i=0; i<=15; i++)
		{
			for(int j=0; j<=6; j++)
			{
				m_top_free_agent_salaries[i][j] = a.m_top_free_agent_salaries[i][j];
			}
		}




		m_signed_players = a.m_signed_players;
		
		m_risk = a.m_risk;
		m_player_spending = a.m_player_spending;
		m_over_cap = a.m_over_cap;
		m_team_index = a.m_team_index;
		for(int i=0; i<=11; i++)
		{
			m_minimum[i] = a.m_minimum[i];
		}

		m_mid_exception_used = a.m_mid_exception_used;
		m_mid_exception_offered = a.m_mid_exception_offered;
		m_million_exception_used = a.m_million_exception_used;
		m_million_exception_offered = a.m_million_exception_offered;

		m_salary_cap = a.m_salary_cap;
		m_owner_salary_cap = a.m_owner_salary_cap;

	}

	const CHireStaff& operator=( const CHireStaff& a )
    {

		m_offers_this_round = a.m_offers_this_round;
		m_firingLineScout = a.m_firingLineScout;
		m_firingLineCoach = a.m_firingLineCoach;
		m_firingLineGM = a.m_firingLineGM;
		m_record = a.m_record;
		m_rosterValue = a.m_rosterValue;
		m_owner_patience = a.m_owner_patience;
		m_topCoach = a.m_topCoach;
		m_topScout = a.m_topScout;
		m_topGM = a.m_topGM;
		m_hireCoach = a.m_hireCoach;
		m_hireScout = a.m_hireScout;
		m_hireGM = a.m_hireGM;
		m_hiredCoachOnce = a.m_hiredCoachOnce;
		m_hiredGmOnce = a.m_hiredGmOnce;
		m_hiredScoutOnce = a.m_hiredScoutOnce;
		m_scoutStatus = a.m_scoutStatus;
		m_coachStatus = a.m_coachStatus;
		m_gmStatus = a.m_gmStatus;
		m_madeScoutOffer = a.m_madeScoutOffer;	
		m_madeCoachOffer = a.m_madeCoachOffer;	
		m_madeGmOffer = a.m_madeGmOffer;	
		m_win = a.m_win;
		m_loss = a.m_loss;
		for(int i=0; i<=5; i++)
		{
			m_position_values[i] = a.m_position_values[i];
		}
		for(int i=0; i<=6; i++)
		{
			m_current_payroll[i] = a.m_current_payroll[i];
			m_temp_payroll[i] = a.m_temp_payroll[i];
			m_released_salaries[i] = a.m_released_salaries[i];
		}

		for(int i=0; i<=1440; i++)
		{
			m_x[i] = a.m_x[i];
		}

		for(int i=0; i<=15; i++)
		{
			m_top_free_agent[i] = a.m_top_free_agent[i];
			m_top_free_agent_total_salary[i] = a.m_top_free_agent_total_salary[i];
			m_top_free_agent_years[i] = a.m_top_free_agent_years[i];
		}

		for(int i=0; i<=15; i++)
		{
			for(int j=0; j<=6; j++)
			{
				m_top_free_agent_salaries[i][j] = a.m_top_free_agent_salaries[i][j];
			}
		}



		m_signed_players = a.m_signed_players;

		m_risk = a.m_risk;
		m_player_spending = a.m_player_spending;
		m_over_cap = a.m_over_cap;
		m_team_index = a.m_team_index;
		for(int i=0; i<=11; i++)
		{
			m_minimum[i] = a.m_minimum[i];
		}
		m_mid_exception_used = a.m_mid_exception_used;
		m_mid_exception_offered = a.m_mid_exception_offered;
		m_million_exception_used = a.m_million_exception_used;
		m_million_exception_offered = a.m_million_exception_offered;

		m_salary_cap = a.m_salary_cap;
		m_owner_salary_cap = a.m_owner_salary_cap;

		return *this;
	}
	
private:
	bool PossiblyUseMidLevelException(int n, double trade_value, double accept_factor, int security);
	bool PossiblyUseMillionException(int n);

};