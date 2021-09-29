class CBBallSettings: public CObject
{
private:


	
public:
	int m_sim_speed;
	void ClearSettings();
	
	int m_scouts_on;
	int m_current_stage;
	CString m_player_gm[33];
		
	double m_scoring_factor;
	int m_injury_prompt;
	int m_salary_matching;
	int m_free_agency_on;
	bool m_loadbmp;

	int m_number_transactions;
		double m_cap;
		int m_ast_gm;
		int m_check3pt;
		int m_check3ft;
		int m_currentYear;
		int m_checkCareer;
		int m_computerTrades;
		int m_financial_on;
		int m_deadline_on;
		int m_save_box[33];
		int m_save_pbp[33];
		int m_get_offers[33];
		int m_show_box[33];
		int m_scouts[33];
		int m_coaches[33];
		int m_injury;
		int m_numberteams;
		int m_expanding;
	int m_all_star;
	int m_rookie_star;
	int m_3contest;
	int m_dunkcontest;
	
	int m_all_star_index;//team player was on during allstar stuff
	int m_rookie_star_index;
	int m_3contest_index;
	int m_dunkcontest_index;
	


		

		CString m_path;
		CString m_league_name;
		CString m_full_path_name;		

		CString m_control[33];
		CString m_leagueTeamNames[33];

		CString m_playoffFormat;
		CString m_rd1Format;	
		CString m_rd2Format;	
		CString m_rd3Format;	
		CString m_rd4Format;	
		CString m_conferenceName1;	
		CString m_conferenceName2;	
		CString m_divisionName1;	
		CString m_divisionName2;	
		CString m_divisionName3;	
		CString m_divisionName4;	





CBBallSettings()
{
	m_loadbmp = false;
	m_number_transactions = 0;
	m_sim_speed = 0;
	m_scoring_factor = 0;
	m_injury_prompt = 0;
	m_free_agency_on = 0;
	m_salary_matching = 0;
		m_cap = 3550;
		m_current_stage = 0;
		m_check3pt = 0;
		m_check3ft = 0;
		m_ast_gm = 0;
		m_scouts_on = 1;
		m_currentYear = 0;
		m_checkCareer = 0;
		m_computerTrades = 0;
		m_financial_on = 1;
		m_deadline_on = 0;
		m_injury = 0;
		m_numberteams = 0;
		m_expanding = 0;
		for(int i=0; i<=32; i++)
		{
			m_control[i] = "";
			m_leagueTeamNames[i] = "";
			m_player_gm[i] = "";
			m_save_box[i] = 0;
			m_save_pbp[i] = 0;
			m_show_box[i] = 0;
			m_get_offers[i] = 0;
			m_scouts[i] = 0;
			m_coaches[i] = 0;
		}
		m_path = "";
		m_league_name = "";
		m_full_path_name = "";
		m_playoffFormat = "";
		m_rd1Format = "";
		m_rd2Format = "";
		m_rd3Format = "";
		m_rd4Format = "";
		m_conferenceName1 = "";
		m_conferenceName2 = "";
		m_divisionName1 = "";
		m_divisionName2 = "";
		m_divisionName3	= "";
		m_divisionName4	= "";
	 m_all_star = 0;
	 m_rookie_star=0;
	 m_3contest=0;
	 m_dunkcontest=0;
	
	 m_all_star_index=0;//team player was on during allstar stuff
	 m_rookie_star_index=0;
	 m_3contest_index=0;
	 m_dunkcontest_index = 0;
	



}






~CBBallSettings()
{
	
}	
	

	const CBBallSettings& operator=( const CBBallSettings& a )
    {
		m_expanding = a.m_expanding;
		m_number_transactions = a.m_number_transactions;
		m_loadbmp = a.m_loadbmp;		
		m_sim_speed = a.m_sim_speed;
		m_salary_matching = a.m_salary_matching;
		m_scoring_factor = a.m_scoring_factor;
		m_injury_prompt = a.m_injury_prompt;
		m_free_agency_on = a.m_free_agency_on;
		m_ast_gm = a.m_ast_gm;
		m_financial_on = a.m_financial_on;
		m_deadline_on = a.m_deadline_on;
		m_cap = a.m_cap;
		m_current_stage = a.m_current_stage;
		m_scouts_on = a.m_scouts_on;
		m_check3pt = a.m_check3pt;
		m_check3ft = a.m_check3ft;
		m_currentYear = a.m_currentYear;
		m_checkCareer = a.m_checkCareer;
		m_computerTrades = a.m_computerTrades;
		m_injury = a.m_injury;
		m_numberteams = a.m_numberteams;
		
		for(int i=0; i<=32; i++)
		{
			m_control[i] = a.m_control[i];
			m_player_gm[i] = a.m_player_gm[i];
			m_save_box[i] = a.m_save_box[i];
			m_save_pbp[i] = a.m_save_pbp[i];
			m_get_offers[i] = a.m_get_offers[i];
			m_show_box[i] = a.m_show_box[i];
			m_scouts[i] = a.m_scouts[i];
			m_coaches[i] = a.m_coaches[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_leagueTeamNames[i] = a.m_leagueTeamNames[i];
			m_player_gm[i] = a.m_player_gm[i];
		}
		m_path = a.m_path;
		m_league_name = a.m_league_name;
		m_full_path_name = a.m_full_path_name;
		m_playoffFormat = a.m_playoffFormat;
		m_rd1Format = a.m_rd1Format;
		m_rd2Format = a.m_rd2Format;
		m_rd3Format = a.m_rd3Format;
		m_rd4Format = a.m_rd4Format;
		m_conferenceName1 = a.m_conferenceName1;
		m_conferenceName2 = a.m_conferenceName2;
		m_divisionName1 = a.m_divisionName1;
		m_divisionName2 = a.m_divisionName2;
		m_divisionName3	= a.m_divisionName3;
		m_divisionName4	= a.m_divisionName4;

	 m_all_star = a.m_all_star;
	 m_rookie_star = a.m_rookie_star;
	 m_3contest = a.m_3contest;
	 m_dunkcontest= a.m_dunkcontest;
	
	 m_all_star_index= a.m_all_star_index;//team player was on during allstar stuff
	 m_rookie_star_index=a.m_rookie_star_index;
	 m_3contest_index=a.m_3contest_index;
	 m_dunkcontest_index = a.m_dunkcontest_index;




		return *this;
	}

	CBBallSettings( const CBBallSettings& a ) 
	{ 
	 m_all_star = a.m_all_star;
	 m_rookie_star = a.m_rookie_star;
	 m_3contest = a.m_3contest;
	 m_dunkcontest= a.m_dunkcontest;
	
	 m_all_star_index= a.m_all_star_index;//team player was on during allstar stuff
	 m_rookie_star_index=a.m_rookie_star_index;
	 m_3contest_index=a.m_3contest_index;
	 m_dunkcontest_index = a.m_dunkcontest_index;

		m_expanding = a.m_expanding;
		m_number_transactions = a.m_number_transactions;
		m_loadbmp = a.m_loadbmp;
		m_sim_speed = a.m_sim_speed;
		m_salary_matching = a.m_salary_matching;
		m_scoring_factor = a.m_scoring_factor;
		m_injury_prompt = a.m_injury_prompt;
		m_free_agency_on = a.m_free_agency_on;
		m_ast_gm = a.m_ast_gm;
		m_financial_on = a.m_financial_on;
		m_deadline_on = a.m_deadline_on;
		m_cap = a.m_cap;
		m_check3pt = a.m_check3pt;
		m_current_stage = a.m_current_stage;
		m_scouts_on = a.m_scouts_on;
		m_check3ft = a.m_check3ft;
		m_currentYear = a.m_currentYear;
		m_checkCareer = a.m_checkCareer;
		m_computerTrades = a.m_computerTrades;
		m_injury = a.m_injury;
		m_numberteams = a.m_numberteams;
		m_path = a.m_path;
		m_league_name = a.m_league_name;
		m_full_path_name = a.m_full_path_name;
		m_playoffFormat = a.m_playoffFormat;
		m_rd1Format = a.m_rd1Format;
		m_rd2Format = a.m_rd2Format;
		m_rd3Format = a.m_rd3Format;
		m_rd4Format = a.m_rd4Format;
		m_conferenceName1 = a.m_conferenceName1;
		m_conferenceName2 = a.m_conferenceName2;
		m_divisionName1 = a.m_divisionName1;
		m_divisionName2 = a.m_divisionName2;
		m_divisionName3	= a.m_divisionName3;
		m_divisionName4	= a.m_divisionName4;
		
		for(int i=0; i<=32; i++)
		{
			m_control[i] = a.m_control[i];
			m_player_gm[i] = a.m_player_gm[i];
			m_save_box[i] = a.m_save_box[i];
			m_save_pbp[i] = a.m_save_pbp[i];
			m_get_offers[i] = a.m_get_offers[i];
			m_show_box[i] = a.m_show_box[i];
			m_scouts[i] = a.m_scouts[i];
			m_coaches[i] = a.m_coaches[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_leagueTeamNames[i] = a.m_leagueTeamNames[i];
		}


	}

	void CBBallSettings::SetLeagueNames(CString path, CString name)
	{
		m_path = path;
		m_league_name = name;
		m_full_path_name = m_path + m_league_name;
	}


};