#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"



#ifndef HireStaff_h
#include "HireStaff.h"
#define HireStaff_h
#endif 

//#include "Constants.h"






bool CHireStaff::FireScout(CStaff m_scout)
{
	bool m_fire = false;
    int fire = m_firingLineScout + 6 - m_owner_patience*2; 
	if(fire < 0) fire = 0;
    if(m_scout.m_points <= fire) m_fire = true;
	m_hireScout = m_fire;
	return m_fire;
}
bool CHireStaff::FireCoach(CStaff m_coach)
{
	bool m_fire = false;
    int fire = m_firingLineCoach + 6 - m_owner_patience*2; 
	if(fire < 0) fire = 0;
    if(m_coach.m_points <= fire) m_fire = true;
	m_hireCoach = m_fire;
	return m_fire;
}
bool CHireStaff::FireGM(CStaff m_gm)
{
	bool m_fire = false;
    int fire = m_firingLineGM + 6 - m_owner_patience*2; 
	if(fire < 0) fire = 0;
    if(m_gm.m_points <= fire) m_fire = true;

	m_hireGM = m_fire;
	return m_fire;
}

bool CHireStaff::RetireScout(CStaff m_scout)
{
	bool m_retire = false;
    int retire = m_scout.m_age; 
	int factor = (74 - retire) * 2;

	if(factor < 2)
		factor = 2;
	else
		factor = factor * factor;

	int n = IntRandom(factor);
	if(n == 1) m_retire = true;
	return m_retire;
}

bool CHireStaff::RetireCoach(CStaff m_coach)
{
	bool m_retire = false;
    int retire = m_coach.m_age; 
	int factor = (72 - retire) * 2;

	if(factor < 2)
		factor = 2;
	else
		factor = factor * factor;

	int n = IntRandom(factor);
	if(n == 1) m_retire = true;
	return m_retire;
}

bool CHireStaff::RetireGM(CStaff m_gm)
{
	bool m_retire = false;
    int retire = m_gm.m_age; 
	int factor = (73 - retire) * 2;

	if(factor < 2)
		factor = 2;
	else
		factor = factor * factor;

	int n = IntRandom(factor);
	if(n == 1) m_retire = true;
	return m_retire;
}

bool CHireStaff::ResignScout(CStaff m_scout, double win_pct)
{
	bool m_resign = false;

    int win = m_win; 
	int loss = m_loss;
	int games = win + loss;
	if(games == 0) games = 1;
	double pct = double(win) / double(games);
	double loyalty = (2 + double(m_scout.m_loyalty))/10;
	double score = (pct + win_pct + loyalty) / 3;
	int total = m_scout.m_pot1Rating + m_scout.m_pot2Rating + m_scout.m_effortRating + m_scout.m_scoringRating + m_scout.m_shootingRating + m_scout.m_reboundingRating + m_scout.m_passingRating + m_scout.m_defenseRating;
	double value = double(total)/56;

	double diff = (value - score)/3;
	if(diff <= 0) diff = 0;
	double n = Random(1);
	if(n <= diff) m_resign = true;
    
	return m_resign;
}
bool CHireStaff::ResignCoach(CStaff m_coach, double win_pct)
{
	bool m_resign = false;

    int win = m_win; 
	int loss = m_loss;
	int games = win + loss;
	if(games == 0) games = 1;
	double pct = double(win) / double(games);
	double loyalty = (2 + double(m_coach.m_loyalty))/10;
	double score = (pct + win_pct + loyalty) / 3;
	int c1 = m_coach.m_pot1Rating + m_coach.m_pot2Rating + m_coach.m_effortRating + m_coach.m_scoringRating + m_coach.m_shootingRating + m_coach.m_reboundingRating + m_coach.m_passingRating + m_coach.m_defenseRating;
	int c2 = m_coach.m_coachScoring + m_coach.m_coachShooting + m_coach.m_coachRebounding + m_coach.m_coachPassing + m_coach.m_coachDefense + m_coach.m_coachPot1 + m_coach.m_coachPot2 + m_coach.m_coachEffort;
	int c3 = m_coach.m_coachO + m_coach.m_coachP + m_coach.m_coachI + m_coach.m_coachF + m_coach.m_coachOD + m_coach.m_coachPD + m_coach.m_coachID + m_coach.m_coachFD;
	int total = c1 + c2 + c3;
	double value = double(total)/136;
//	if(value > score) m_resign = true;
	double diff = (value - score)/3;
	if(diff <= 0) diff = 0;
	double n = Random(1);
	if(n <= diff) m_resign = true;
    
    
	return m_resign;
}
bool CHireStaff::ResignGM(CStaff m_gm, double win_pct)
{
	bool m_resign = false;

    int win = m_win; 
	int loss = m_loss;
	int games = win + loss;
	if(games == 0) games = 1;
	double pct = double(win) / double(games);
	double loyalty = (2 + double(m_gm.m_loyalty))/10;
	double score = (pct + win_pct + loyalty) / 3;
	int total = m_gm.m_pot1Rating + m_gm.m_pot2Rating + m_gm.m_effortRating + m_gm.m_scoringRating + m_gm.m_shootingRating + m_gm.m_reboundingRating + m_gm.m_passingRating + m_gm.m_defenseRating;
	double value = double(total)/56;
//	if(value > score) m_resign = true;
	double diff = (value - score)/3;
	if(diff <= 0) diff = 0;
	double n = Random(1);
	if(n <= diff) m_resign = true;
    
    
	return m_resign;
}

void CHireStaff::SetTopScout(CStaff m_scout[101], int owner)
{
	
	int hiRating = 0;
	int hiIndex = -1;
	for(int i=0; i<=99; i++)
	{
		int rating = (m_scout[i].m_pot1Rating + m_scout[i].m_pot2Rating + m_scout[i].m_effortRating) * 2 + m_scout[i].m_scoringRating + m_scout[i].m_shootingRating + m_scout[i].m_reboundingRating + m_scout[i].m_passingRating + m_scout[i].m_defenseRating;
		int currentTeam = m_scout[i].m_currentScout;
		int originalTeam = m_scout[i].m_originalScout;
		if(rating > hiRating && currentTeam == -1 && originalTeam != owner && m_scout[i].m_status != "retires" && m_scout[i].m_status != "active")
		{
			hiRating = rating;
			hiIndex = i;
		}
	}
	m_topScout = hiIndex;
}


void CHireStaff::SetTopCoach(CStaff m_coach[101], int owner)
{
	int hiRating = 0;
	int hiIndex = -1;
	for(int i=0; i<=99; i++)
	{
		int rating1 = (m_coach[i].m_pot1Rating + m_coach[i].m_pot2Rating + m_coach[i].m_effortRating + m_coach[i].m_scoringRating + m_coach[i].m_shootingRating + m_coach[i].m_reboundingRating + m_coach[i].m_passingRating + m_coach[i].m_defenseRating)*1;
		int rating2 = (m_coach[i].m_coachPot1 + m_coach[i].m_coachPot2 + m_coach[i].m_coachEffort + m_coach[i].m_coachScoring + m_coach[i].m_coachShooting + m_coach[i].m_coachRebounding + m_coach[i].m_coachPassing + m_coach[i].m_coachDefense)*3;
		int rating3 = (m_coach[i].m_coachO + m_coach[i].m_coachP + m_coach[i].m_coachI + m_coach[i].m_coachF + m_coach[i].m_coachOD + m_coach[i].m_coachPD + m_coach[i].m_coachID + m_coach[i].m_coachFD)*3;
		int rating = rating1 + rating2 + rating3;
		int currentTeam = m_coach[i].m_currentCoach;
		int originalTeam = m_coach[i].m_originalCoach;
		if(rating > hiRating && currentTeam == -1 && originalTeam != owner && m_coach[i].m_status != "retires" && m_coach[i].m_status != "active")
		{
			hiRating = rating;
			hiIndex = i;
		}
	}
	m_topCoach = hiIndex;
}

void CHireStaff::SetTopGM(CStaff m_gm[101], int owner)
{
	int hiRating = 0;
	int hiIndex = -1;;
	for(int i=0; i<=99; i++)
	{
		int rating = (m_gm[i].m_pot1Rating + m_gm[i].m_pot2Rating + m_gm[i].m_effortRating + m_gm[i].m_scoringRating + m_gm[i].m_shootingRating + m_gm[i].m_reboundingRating + m_gm[i].m_passingRating + m_gm[i].m_defenseRating)*1;
		int currentTeam = m_gm[i].m_currentGM;
		int originalTeam = m_gm[i].m_originalGM;
		if(rating > hiRating && currentTeam == -1 && originalTeam != owner && m_gm[i].m_status != "retires" && m_gm[i].m_status != "active")
		{
			hiRating = rating;
			hiIndex = i;
		}
	}
	m_topGM = hiIndex;
}





void CHireStaff::SetRosterValue(CPlayer *m_actual, int index)
{
	double rating = 0;
	for(int i=index; i<=index+11; i++)
	{
		double r = m_actual[i].GetTradeValue();
		if(r < 0) r = 0;
		rating = rating + r;
	}
	m_rosterValue = int(rating);
}

int CHireStaff::ScoutStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record)
{
		int add_roster = 0;
		if(old_roster_value <= current_roster_value)
			add_roster = 1;
		else if(old_roster_value > current_roster_value)
			add_roster = -1;
		
		int current_w = record.m_leagueRecord/100;
		int current_l = record.m_leagueRecord - current_w*100;
		int current_games = current_w + current_l;
		if(current_games == 0){ current_w = 1; current_l = 1; }
		double current_pct = double(current_w) / (double(current_w) + double(current_l));
		int prev_w = career_win;
		int prev_l = career_loss;
		int prev_games = prev_w + prev_l;
		if(prev_games == 0){ prev_w = 1; prev_l = 1; }
		double old_pct = double(prev_w) / (double(prev_w) + double(prev_l));

		int add_pct = 0;
		if(old_pct < current_pct)
			add_pct = 1;
		else if(old_pct > current_pct)
			add_pct = -1;
		add_pct = add_pct + int(current_pct * 10) - 5;
		
		m_scoutStatus = status + record.m_points*1 + add_roster*3 + add_pct*2;
		if(m_scoutStatus < 0) m_scoutStatus = 0;
		return m_scoutStatus;
}

int CHireStaff::CoachStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record)
{
		int add_roster = 0;
		if(old_roster_value < current_roster_value)
			add_roster = 1;
		else if(old_roster_value > current_roster_value)
			add_roster = -1;
		
		int current_w = record.m_leagueRecord/100;
		int current_l = record.m_leagueRecord - current_w*100;
		int current_games = current_w + current_l;
		if(current_games == 0){ current_w = 1; current_l = 1; }
		double current_pct = double(current_w) / (double(current_w) + double(current_l));
		int prev_w = career_win;
		int prev_l = career_loss;
		int prev_games = prev_w + prev_l;
		if(prev_games == 0){ prev_w = 1; prev_l = 1; }
		double old_pct = double(prev_w) / (double(prev_w) + double(prev_l));

		int add_pct = 0;
		if(old_pct < current_pct)
			add_pct = 1;
		else if(old_pct > current_pct)
			add_pct = -1;
		add_pct = add_pct + int(current_pct * 10) - 5;
		
		
		m_coachStatus = status + record.m_points*3 + add_roster*1 + add_pct*2;
		if(m_coachStatus < 0) m_coachStatus = 0;
		return m_coachStatus;
}

int CHireStaff::GmStatus(int status, int old_roster_value, int current_roster_value, int career_win, int career_loss, CRecord record)
{
		int add_roster = 0;
		if(old_roster_value < current_roster_value)
			add_roster = 1;
		else if(old_roster_value > current_roster_value)
			add_roster = -1;
		
		int current_w = record.m_leagueRecord/100;
		int current_l = record.m_leagueRecord - current_w*100;
		int current_games = current_w + current_l;
		if(current_games == 0){ current_w = 1; current_l = 1; }
		double current_pct = double(current_w) / (double(current_w) + double(current_l));
		int prev_w = career_win;
		int prev_l = career_loss;
		int prev_games = prev_w + prev_l;
		if(prev_games == 0){ prev_w = 1; prev_l = 1; }
		double old_pct = double(prev_w) / (double(prev_w) + double(prev_l));

		int add_pct = 0;
		if(old_pct < current_pct)
			add_pct = 1;
		else if(old_pct > current_pct)
			add_pct = -1;
		add_pct = add_pct + int(current_pct * 10) - 5;
		
		m_gmStatus = status + record.m_points*2 + add_roster*2 + add_pct*2;
		if(m_gmStatus < 0) m_gmStatus = 0;
		return m_gmStatus;
}


void CHireStaff::SetScoutFiringLine(CStaff m_scout)
{
    int line = m_scout.m_points / 2;
	if(line <= 8) line = 8;
    m_firingLineScout = line;
}

void CHireStaff::SetCoachFiringLine(CStaff m_coach)
{
    int line = m_coach.m_points / 2;
	if(line <= 8) line = 8;
    m_firingLineCoach = line;
}

void CHireStaff::SetGmFiringLine(CStaff m_gm)
{
    int line = m_gm.m_points / 2;
	if(line <= 8) line = 8;
    m_firingLineGM = line;
}

void CHireStaff::SetPositionValues(CPlayer* m_actual, int index, CStaff coach)
{
	double rating = 0;
	double value[6] = {0,0,0,0,0,0};
	for(int i=index; i<=index+19; i++)
	{
		CPlayer m_player = m_actual[i];
		if(m_player.m_is_free_agent == true || m_player.m_name == "") continue;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), coach.m_scoring, coach.m_shooting, coach.m_rebounding, coach.m_passing, coach.m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(coach.m_pot1, coach.m_pot2, coach.m_effort);


		double r = m_player.GetTradeTrueRating(TRUE);
		CString pos = m_player.GetPos();
		if(r < 0) r = 0;
		if(pos == "PG") value[1] = value[1] + r;
		else if(pos == "SG") value[2] = value[2] + r;
		else if(pos == "SF") value[3] = value[3] + r;
		else if(pos == "PF") value[4] = value[4] + r;
		else if(pos == " C") value[5] = value[5] + r;
	}


	for(int i=1; i<=5; i++)
	{
		m_position_values[i] = value[i];
	}
}


void CHireStaff::SetPositionValuesSortedList(CPlayer* m_actual, CStaff coach, int team_index)
{
	double rating = 0;
	double value[6] = {0,0,0,0,0,0};
	for(int i=1; i<=1440; i++)
	{
		CPlayer m_player = m_actual[i];
		if(m_player.m_is_free_agent == true || m_player.m_name == "" || m_player.m_current_team != team_index) continue;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), coach.m_scoring, coach.m_shooting, coach.m_rebounding, coach.m_passing, coach.m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(coach.m_pot1, coach.m_pot2, coach.m_effort);


		double r = m_player.GetTradeTrueRating(TRUE);
		CString pos = m_player.GetPos();
		if(r < 0) r = 0;
		if(pos == "PG") value[1] = value[1] + r;
		else if(pos == "SG") value[2] = value[2] + r;
		else if(pos == "SF") value[3] = value[3] + r;
		else if(pos == "PF") value[4] = value[4] + r;
		else if(pos == " C") value[5] = value[5] + r;
	}


	for(int i=1; i<=5; i++)
	{
		m_position_values[i] = value[i];
	}
}



void CHireStaff::SetTopFreeAgent(CPlayer* actual, CStaff scout, CStaff coach, CStaff gm, int owner_index, int stage)
{

	m_offers_this_round = 0;
	double hi_diff = -65535;//set high and try to beat
	int hi_free_agent = -1;
	int hi_free_agent_total_salary = 0;
	int hi_free_agent_years = 0;
	int hi_free_agent_salaries[] = {0,0,0,0,0,0,0};

		for(int i=0; i<=15; i++)
		{
			m_top_free_agent[i] = 0;
			m_top_free_agent_total_salary[i] = 0;
			m_top_free_agent_years[i] = 0;
		}

		for(int i=0; i<=15; i++)
		{
			for(int j=0; j<=6; j++)
			{
				m_top_free_agent_salaries[i][j] = 0;
			}
		}



	do
	{


	for(int x=0; x<=6; x++)
	{
		hi_free_agent_salaries[x] = 0;
	}


	hi_diff = -65535;//set high and try to beat
	hi_free_agent = -1;
	hi_free_agent_total_salary = 0;
	hi_free_agent_years = 0;
	int off = m_offers_this_round + 1;
	
	for(int i=0; i<=1440; i++)
	{
		m_x[i] = 0;
		
		bool offered_already = false;
		for(int x=1; x<=m_offers_this_round; x++)
		{
			if(m_top_free_agent[x] == i)
				offered_already = true;
		}	
		if(offered_already == true) continue;
		

		CPlayer m_player = actual[i];
		CString pos = m_player.GetPos();
		if(m_player.GetName() == "" || m_player.m_is_free_agent == false || m_player.m_signed == true || m_player.m_retired == true) continue;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), scout.m_scoring, scout.m_shooting, scout.m_rebounding, scout.m_passing, scout.m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(scout.m_pot1, scout.m_pot2, scout.m_effort);
		
		double diff = 0;
		int po = 1;//PG
		if(pos == "SG") po = 2;
		else if(pos == "SF") po = 3;
		else if(pos == "PF") po = 4;
		else if(pos == " C") po = 5;

		diff = m_player.GetTradeTrueRating(TRUE) - m_position_values[po];


		SetTopFreeAgentContract(m_player, gm, i, stage);//check
	

		bool qualify = true;


 		//double number = (double) m_player.m_seeking[owner_index] * (1 - m_player.m_accept_factor);
		//double number_1 = 640 * (1 - m_player.m_accept_factor);
 		double number = 0;
		double number_1 = 0;
		if(m_top_free_agent_salaries[off][1]  < number || m_top_free_agent_salaries[off][1]  < number_1) qualify = false;




			int proj_payroll = m_temp_payroll[1] + m_top_free_agent_salaries[off][1];


			if(proj_payroll * 10 < m_owner_salary_cap && proj_payroll > m_salary_cap &&
				m_player.m_bird_player == true &&
				m_temp_payroll[1] * 10 < (m_owner_salary_cap-MINEX)
				&& m_player.m_previous_team == owner_index				
				)
			{			
				
				//double sal = (double)m_owner_cap/10. - (double)m_temp_payroll[1];
				diff = diff + m_player.GetTradeTrueRating(TRUE);
			}



		if(diff > hi_diff && qualify == true)
		{


			hi_diff = diff;
			hi_free_agent = i;
			for(int j=0; j<=6; j++)
			{
				hi_free_agent_salaries[j] = m_top_free_agent_salaries[off][j];
			}
			hi_free_agent_total_salary = m_top_free_agent_total_salary[off];
			hi_free_agent_years = m_top_free_agent_years[off];
		}

	}




	
	bool qualify = true;
	double number = 32;
	if(hi_free_agent >= 0)
 		number = (double) actual[hi_free_agent].m_seeking[owner_index] * (1 - actual[hi_free_agent].m_accept_factor);

	//if(hi_free_agent_salaries[1]  < number)
	//{
	//	qualify = false;
	//}





	if(m_signed_players > 14 || qualify == false)
	{
		hi_free_agent = -1;
	}


	
	//int better = 0;
	//for(int pl=0; pl<=1440; pl++)
	//{
	//	CPlayer m_p = actual[pl];
	//	if(m_p.GetName() == "" || m_p.m_is_free_agent == false || m_p.m_signed == true || m_p.m_retired == true || hi_free_agent < 0 || m_p.m_rookie == true) continue;
	//	double rat = m_p.GetTradeTrueRating(TRUE);
	//	actual[hi_free_agent].SetAdjTrueRatingSimple(actual[hi_free_agent].GetFgm(), actual[hi_free_agent].GetFga(), actual[hi_free_agent].GetTfgm(), actual[hi_free_agent].GetTfga(), actual[hi_free_agent].GetFtm(),  actual[hi_free_agent].GetFta(), actual[hi_free_agent].GetOreb(),  actual[hi_free_agent].GetReb(), actual[hi_free_agent].GetAst(), actual[hi_free_agent].GetStl(), actual[hi_free_agent].GetTo(), actual[hi_free_agent].GetBlk(), scout.m_scoring, scout.m_shooting, scout.m_rebounding, scout.m_passing, scout.m_defense);
	//	actual[hi_free_agent].SetTradeTrueRating(0);
	//	actual[hi_free_agent].SetAdjTradeValue(scout.m_pot1, scout.m_pot2, scout.m_effort);
	//	double be = actual[hi_free_agent].GetTradeTrueRating(TRUE);
 	//	double num = (double) actual[pl].m_seeking[owner_index] * (1 - (actual[hi_free_agent].m_accept_factor+.1));
	//	if(num < 0) num = 0;
	

	//	if(be < rat && ((m_salary_cap - m_current_payroll[0]) > num  
	//		|| m_p.m_previous_team == owner_index) && better < 16)
	//		better = better + 1;
	//}

	//if(better > stage*3 && IntRandom(better) > stage)
	//	hi_free_agent = -1;


	for(int j=0; j<=6; j++)
	{
		m_top_free_agent_salaries[off][j] = hi_free_agent_salaries[j];
	}

	m_top_free_agent_total_salary[off] = hi_free_agent_total_salary;
	m_top_free_agent_years[off]  = hi_free_agent_years;


	if(hi_free_agent >= 0)
	{
		m_offers_this_round = m_offers_this_round + 1;		
		for(int i=0; i<=6; i++)
		{
			m_temp_payroll[i] = m_temp_payroll[i] + m_top_free_agent_salaries[off][i];
		}		
		m_top_free_agent[off] = hi_free_agent;	

		if(m_x[hi_free_agent] == 1)
			m_mid_exception_offered = actual[hi_free_agent].m_id;
		else if(m_x[hi_free_agent] == 2)
			m_million_exception_offered = actual[hi_free_agent].m_id;

		
	}



	}
	while (hi_free_agent != -1 && ((m_signed_players + m_offers_this_round) <= 14));

	
}

void CHireStaff::SetTopFreeAgentContract(CPlayer actual, CStaff gm, int n, int stage)//salary if signed
{
	bool min = false;

	bool lower = false;




	
		int off = m_offers_this_round + 1;

		for(int i=0; i<=6; i++)
		{
			m_top_free_agent_salaries[off][i] = 0;
		}
			
		CPlayer m_player = actual;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), gm.m_scoring, gm.m_shooting, gm.m_rebounding, gm.m_passing, gm.m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(gm.m_pot1, gm.m_pot2, gm.m_effort);
		double trade_value = m_player.GetTradeTrueRating(FALSE);
		int yrs_service = m_player.m_yrs_of_service;

		double money = trade_value * 100;
		if(money < 32) money = 32;
		bool max_raise = false;
		money = money * (.9 + (double)IntRandom(20)/100);
		if(money > MAX10 && yrs_service >= 10)
		{
			max_raise = true;
			money = MAX10;
		}
		else if(money > MAX7 && yrs_service >= 7) 
		{
			max_raise = true;
			money = MAX7;
		}
		else if(money > MAX0) 
		{
			max_raise = true;
			money = MAX0;
		}

		






		int total_salary = 0;
		
		int contract_max =  6;
			//write some code based on age to set years wanted
		int age = m_player.GetAge();
		int f = 0;
		if(stage <=3 ) f = 4 - stage;//make longer offers in earlier years to get more chance of signing
		if(age > 28) contract_max = 35 - age + stage;

			if(contract_max > 6) contract_max = 6;
			else if(contract_max < 1) contract_max = 1;
			int contract_years = IntRandom(contract_max);
			if(contract_years == 1 && IntRandom(4) == 1) contract_years = 2;//1 year contracts have rare chance (1 in 4) to be 2


			int proj_payroll = m_temp_payroll[1] + (int)money;


			if(proj_payroll * 10 > m_owner_salary_cap && m_temp_payroll[1] < (m_salary_cap-100))
			{			
				lower = true;
				money = (double)m_owner_salary_cap/10. - (double)m_temp_payroll[1];
			}
			if(proj_payroll > m_salary_cap && m_temp_payroll[1] < (m_salary_cap-100) && actual.m_bird_player == false)
			{
				lower = true;
				money = (double)m_salary_cap - (double)m_temp_payroll[1];
			}

			if(lower == true)
			{
				int f = int(money / 100);
				if(f > 5) f = 5; 
				else if(f > 1) f = 1; 
				contract_years = IntRandom(f);
			}


			
			int current_money = (int)money;
			int current_yr_salary = current_money;
			m_top_free_agent_salaries[off][1] = current_money;
			total_salary = total_salary + current_money;

			if(contract_years != 1)//end of contract
			{
			
					int raise = IntRandom(contract_years*3);
					if(max_raise == true) raise = 15;//insure player offered max raise
					double d_raise = (double) raise;
					if(d_raise > 12.5) d_raise = 12.5;
					if(actual.m_bird_player == false && d_raise > 10) d_raise = 10;
					double inc = (double)current_money * (d_raise/100.);
				
				
				for(int j=2; j<=contract_years; j++)
				{

			

					double money = double(current_money) + inc;
					current_money = (int)money;
					m_top_free_agent_salaries[off][j] = current_money;
					total_salary = total_salary + current_money;
				}
			
			}
				
			m_top_free_agent_total_salary[off] = total_salary;
			m_top_free_agent_years[off] = contract_years;

			if(yrs_service > 10) yrs_service = 10;		
			if(current_yr_salary < m_minimum[yrs_service]) min = true;




		bool exception = false;
//same	
		bool afford = AffordContract(m_player, gm, exception);//can fit salary without going over cap?
//same?	
		bool over = OverCap(exception);//currently over cap?

		bool owner_afford = ContractUnderOwnerSalaryCap(m_player);//can fit salary without going over cap?





		if(over == true || afford == false || owner_afford == false || min == true)//over cap
		{
			AdjustContractOfferToMinimum(m_player, n);
		}


			
}

void CHireStaff::CurrentPayroll(CPlayer contracts[], int index, bool signing_ok)
{

	int total[7] = {0,0,0,0,0,0,0};
	for(int i=index; i<=index+29; i++)
	{
		if(contracts[i].m_name == "") continue;
		if(contracts[i].m_retired == true && signing_ok == true) continue;


		for(int y=0; y<=5; y++)
		{
			int yr = contracts[i].m_current_contract_yr + y;
			if(yr <= 6)
				total[y] = total[y] + contracts[i].m_contract_salaries[yr];
		}
	}
		for(int y=0; y<=5; y++)
		{
			m_current_payroll[y] = total[y];
		}


		int te = 1 + (index-1) / 30;
	for(int i=1; i<=480; i++)
	{
		int tp = contracts[960+i].m_team_paying; 
		if(tp != te) continue;
		for(int y=0; y<=5; y++)
		{
			int yr = contracts[960+i].m_current_contract_yr + y;
			if(yr <= 6)
			{
				int money =  contracts[960+i].m_contract_salaries[yr];
				m_current_payroll[y] = m_current_payroll[y] + (long)money;
				m_released_salaries[y] = m_released_salaries[y] + money; 
			}
		}
	}



}

int CHireStaff::CurrentYearPayroll(CPlayer contracts[], int index)
{
	int total = 0;
	for(int i=index; i<=index+14; i++)
	{

			total = total + contracts[i].m_current_yr_salary;
	}

	return total;
}


bool CHireStaff::AffordContract(CPlayer contract, CStaff gm, bool &exception)
{ 
	int team = m_team_index; 
	bool afford = true;
	int off = m_offers_this_round + 1;


		for(int y=1; y<=1; y++)//switched to 1 from 5 must be under only year 1?
		{
			int projected_payroll = m_temp_payroll[y] + m_top_free_agent_salaries[off][y];
			if(projected_payroll > m_salary_cap) afford = false;
		}
		
		if(contract.m_yrs_on_team >= 3 && team == contract.m_previous_team)
		//this should work too - contract.m_yrs_on_team >= 3
		{
			afford = true;
			exception = true;

		}

		return afford;
}

bool CHireStaff::ContractUnderOwnerSalaryCap(CPlayer contract)
{ 
	int team = m_team_index; 
	int off = m_offers_this_round + 1;

	bool afford = true;

		for(int y=1; y<=1; y++)
		{
			int projected_payroll = m_temp_payroll[y] + m_top_free_agent_salaries[off][y];
			if(projected_payroll * 10 > m_owner_salary_cap)  afford = false;
		}
		
		return afford;
}

bool CHireStaff::OverCap(bool exception)
{
	bool over_cap = false;
	if(m_temp_payroll[1] > m_salary_cap && exception == false) over_cap = true;
	return over_cap;
}

void CHireStaff::SetLeagueSalaryCap(int m_cap)
{
	m_salary_cap = m_cap;
}

void CHireStaff::AdjustContractOfferToMinimum(CPlayer contract, int n)
{

	double trade_value = contract.GetTradeTrueRating(FALSE);
	bool use = PossiblyUseMidLevelException(n, trade_value, contract.m_accept_factor, contract.m_security_factor);
	bool use_million = PossiblyUseMillionException(n);
	int off = m_offers_this_round + 1;

	
	if(use == false && use_million == false)
	{
		for(int i=0; i<=6; i++)
		{
			m_top_free_agent_salaries[off][i] = 0;
		}
			
		int total_salary = 0;
		int contract_years = 1;
		int salary = MinimumSalary(contract);
			
		m_top_free_agent_salaries[off][1] = salary;	
		m_top_free_agent_total_salary[off] = salary;
		m_top_free_agent_years[off] = contract_years;
	}		
}


int CHireStaff::MinimumSalary(CPlayer contract)
{


	int yrs = contract.m_yrs_of_service;

	int current_money = MIN0;

	if(yrs == 0)
		current_money = MIN0;
	else if(yrs == 1)
		current_money = MIN1;
	else if(yrs == 2)
		current_money = MIN2;
	else if(yrs == 3)
		current_money = MIN3;
	else if(yrs == 4)
		current_money = MIN4;
	else if(yrs == 5)
		current_money = MIN5;
	else if(yrs == 6)
		current_money = MIN6;
	else if(yrs == 7)
		current_money = MIN7;
	else if(yrs == 8)
		current_money = MIN8;
	else if(yrs == 9 )
		current_money = MIN9;
	else if(yrs >= 10)
		current_money = MIN10;

	return current_money;

}

bool CHireStaff::PossiblyUseMidLevelException(int n, double trade_value, double accept_factor, int security)
{
	bool use = false;
	int off = m_offers_this_round + 1;

	if(m_top_free_agent_salaries[off][1] >= MIDEX && m_mid_exception_used == false && m_mid_exception_offered < 0)
	{
		m_x[n] = 1;
		m_top_free_agent_salaries[off][1] = MIDEX;
		m_top_free_agent_total_salary[off] = MIDEX;

		double f = trade_value / ((double) MIDEX / 100) * ( .7 + (double)security / 10) * (2 - accept_factor);
		int top = 6 - (int)f;
		if(top < 1) top = 1;
		else if(top > 6) top = 6;
		int ye = IntRandom(top);
		int raise = MIDEX / 10;

		if(ye >= 2)
		{
			int mon = MIDEX;
			for(int i=2; i<=ye; i++)
			{
				mon = mon + raise;
				m_top_free_agent_salaries[off][i] = mon;
				m_top_free_agent_total_salary[off] = m_top_free_agent_total_salary[off] + mon;

			}
		}


		m_top_free_agent_years[off] = ye;
		if(ye <= 5)
		{
			for(int i=ye + 1; i<=6; i++)
			{
				m_top_free_agent_salaries[off][i] = 0;
			}
		}
		use = true;
	}
	return use;
		
}

bool CHireStaff::PossiblyUseMillionException(int n)
{
	bool use = false;
	int off = m_offers_this_round + 1;

	if(m_top_free_agent_salaries[off][1] >= MINEX && (m_mid_exception_offered >= 0 || m_mid_exception_used == true) && m_million_exception_used == false && m_million_exception_offered < 0)
	{
		m_x[n] = 2;
		m_top_free_agent_salaries[off][1] = MINEX;
		m_top_free_agent_total_salary[off] = MINEX;
		m_top_free_agent_years[off] = 1;
		for(int i=2; i<=6; i++)
		{
			m_top_free_agent_salaries[off][i] = 0;
		}
		use = true;
	}
	return use;
		
}


void CHireStaff::DisallowStaffHiring(CString pFileName)
{

	CFile file( pFileName, CFile::modeWrite);		
	file.Seek(19501, CFile::begin );
	file.Write("1", 1);

}

bool CHireStaff::AllowHiring(CString file_name)
{
	char s[16];
	bool allow = true;
	CFile file( file_name, CFile::modeRead);
	file.Seek(19501, CFile::begin );
	int bytes = file.Read(s, 1);
	s[bytes] = 0;
	int i = atoi(s);
	if(i == 1) allow = false;
	return allow;

}



double CHireStaff::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}

void CHireStaff::SetOwnerSalaryCap(int owner_salary_cap)
{
	m_owner_salary_cap = owner_salary_cap;
}



void CHireStaff::SetTopFreeAgentExtension(CPlayer actual, CStaff gm)
{
	bool min = false;
	
		int off = 1;

		for(int i=0; i<=6; i++)
		{
			m_top_free_agent_salaries[off][i] = 0;
		}
			
		CPlayer m_player = actual;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), gm.m_scoring, gm.m_shooting, gm.m_rebounding, gm.m_passing, gm.m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(gm.m_pot1, gm.m_pot2, gm.m_effort);
		double trade_value = m_player.GetTradeTrueRating(TRUE);
		int yrs_service = m_player.m_yrs_of_service;

		double money = trade_value * 100;
		if(money < 32) money = 32;
		money = money * (.80 + (double)IntRandom(20)/100);
		if(money > MAX10 && yrs_service >= 10)
		{
			money = MAX10;
		}
		else if(money > MAX7 && yrs_service >= 7) 
		{
			money = MAX7;
		}
		else if(money > MAX0) 
		{
			money = MAX0;
		}
		

		int total_salary = 0;
		
		int contract_max =  5;
			//write some code based on age to set years wanted
		int age = m_player.GetAge();
		if(age > 28) contract_max = 35 - age;

			if(contract_max > 5) contract_max = 5;
			else if(contract_max < 1) contract_max = 1;
			int contract_years = IntRandom(contract_max);
			if(contract_years == 1) contract_years = 2;//1 year contracts have rare chance (1 in 4) to be 2
			
			int current_money = (int)money;
			int current_yr_salary = current_money;
			m_top_free_agent_salaries[off][1] = current_money;
			total_salary = total_salary + current_money;

			if(contract_years != 1)//end of contract
			{
			
					double d_raise = 12.5;
					double inc = (double)current_money * (d_raise/100.);
				
				
				for(int j=2; j<=contract_years; j++)
				{

			

					double money = double(current_money) + inc;
					current_money = (int)money;
					m_top_free_agent_salaries[off][j] = current_money;
					total_salary = total_salary + current_money;
				}
			
			}
				
			m_top_free_agent_total_salary[off] = total_salary;
			m_top_free_agent_years[off] = contract_years;

			if(yrs_service > 10) yrs_service = 10;		
			if(current_yr_salary < m_minimum[yrs_service]) min = true;




		bool exception = false;
		//bool afford = AffordContract(m_player, gm, exception);//can fit salary without going over cap?
		//bool over = OverCap(exception);//currently over cap?
		bool owner_afford = ContractUnderOwnerSalaryCap(m_player);//can fit salary without going over cap?





		if(owner_afford == false || min == true)//over cap
		{
			
			for(int i=0; i<=6; i++)
			{
				m_top_free_agent_salaries[off][i] = 0;
			}
			int total_salary = 0;
			int contract_years = 1;
			int salary = MinimumSalary(m_player);
			
			m_top_free_agent_salaries[off][1] = salary;	
			m_top_free_agent_total_salary[off] = salary;
			m_top_free_agent_years[off] = contract_years;			
		}
}

void CHireStaff::CheckOffers(int off, int owner_index, int choice, CPlayer &player)
{
		//int choice = avg.m_owner[t].m_top_free_agent[off];
		bool afford = true;
		for(int y=1; y<=5; y++)
		{
			int projected_payroll = m_temp_payroll[y] + m_top_free_agent_salaries[off][y];
			if(projected_payroll > m_salary_cap) afford = false;
		}
		
		if(player.m_yrs_on_team >= 3 && owner_index == player.m_previous_team) afford = true;



		bool owner_afford = true;

		for(int y=1; y<=5; y++)
		{
			int projected_payroll = m_temp_payroll[y] + m_top_free_agent_salaries[off][y];
			if(projected_payroll * 10 > m_owner_salary_cap)  owner_afford = false;
		}
		

		bool clear = true;
		if(owner_afford == true && afford == true || m_mid_exception_offered == choice || m_million_exception_offered == choice) clear = false;


		if(clear == true)
		{
		for(int i=0; i<=6; i++)
		{
		
			m_top_free_agent_salaries[off][0] = 0;
		}


		m_mid_exception_offered = -1;
		m_million_exception_offered = -1;


		for(int k=0; k<=6; k++)
		{
			int mon = m_top_free_agent_salaries[off][k];
			m_temp_payroll[k] = m_temp_payroll[k] - mon;
			player.m_salary_offer[owner_index][k] = 0;
			m_top_free_agent_salaries[off][k] = 0;
		}


		player.m_top_offer[owner_index] = true;
		player.m_year_offer[owner_index] = 0;
		player.m_total_salary_offer[owner_index] = 0;
		player.m_offer_slot[owner_index] = 0;

		m_top_free_agent_total_salary[off] = 0;
		m_top_free_agent_years[off]  = 0;
		m_top_free_agent[off] = -1;

		}		

}
