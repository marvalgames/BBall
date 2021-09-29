#include "stdafx.h"
#include "bball.h"
#include "Bballsettings.h"


void CBBallSettings::ClearSettings()
{
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
		m_deadline_on = 1;
		m_injury = 0;
		m_numberteams = 0;
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
}
