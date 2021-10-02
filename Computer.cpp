#include "stdafx.h"

#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "Computer.h"
#include "ProgressDlg1.h"
#ifndef OfferTrades1_h
#include "OfferTrades1.h"
#define OfferTrades1_h
#endif 
#include <time.h>

CComputer::CComputer()
{
	srand( (unsigned)time( NULL ) );

	m_last_released_player_id = 0;
	m_own = new COwn[33];
	m_team1 = 0;
	m_team2 = 0;
	m_getoffersforteam = -1;
	m_players_on_block = 0;
	m_use_trading_block = false;

	m_trade_made = false;

for(int i=0; i<=32; i++)
{
	m_receive_offers[i] = false;
}

}

CComputer::~CComputer()
{
	delete [] m_own;
}

bool CComputer::Trade(int offered[33], int loops, int max_offers, int stage)
{

		CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Trading Period";
        dlgProgress.Create(IDD_PROGRESSDLG,NULL);        // change these parameters
		dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, loops);



	m_trade_made = false;
	int offers = 0;
	for(int times=1; times<=loops; times++)
	{

	if(offers == max_offers) continue;
	bool not_enough = false;

	dlgProgress.m_progress.SetPos(times);
	m_players_on_block = 0;
	t1_offered = false;
	t2_offered = false;
	int value_picks1[4] = {0,0,0,0};
	int value_picks2[4] = {0,0,0,0};
	bool invalid = false;
	int Signed[481];
	int team2 = 0;
	Signed[0] = 0;
	m_team1 = 0;
	m_team2 = 0;
	do
	{
		m_team2 = IntRandom(m_numberteams);
		m_team1 = IntRandom(m_numberteams);
		if(m_getoffersforteam >= 0) m_team1 = m_getoffersforteam + 1;
	} while(m_team1 == m_team2);



	if(offered[m_team1-1] != 0 && offered[m_team2-1] != 0)
	{
		offered[m_team1-1] = true;
		offered[m_team2-1] = true;
	}

	if(offered[m_team1-1] != false) t1_offered = true; else t1_offered = false;
	if(offered[m_team2-1] != false) t2_offered = true; else t2_offered = false;

	if(m_getoffersforteam >= 0)
	{
		offered[m_team1-1] = true;
		offered[m_team2-1] = false;
	}


	int Offset[] = {0,0,0};
	double faTru[] = {0,0};
	Offset[1] = (m_team1 - 1) * 30;
	Offset[2] = (m_team2 - 1) * 30;

	int players1 = IntRandom(2);
	if(players1 == 2) players1 = IntRandom(4);
	int players2 = IntRandom(2);
	if(players2 == 2) players2 = IntRandom(4);
	int picks1 = IntRandom(4);



	int win[33], loss[33];
	double pct[33];
	for(int j=0; j<=32; j++)
	{
		win[j] = avg.m_standings[j].m_win;
		loss[j] = avg.m_standings[j].m_loss;
		if((win[j] + loss[j]) == 0) pct[j] = 1;
		else pct[j] = avg.m_standings[j].m_leaguePct;
	}



	if(picks1 > 1) picks1 = 0;
	else 
	{
		SetOwnDraftPicks(m_team1);
		int index = IntRandom(m_own[m_team1].m_number_actual_picks);

		int y = m_own[m_team1].SetDraftPickAddition(index, avg.m_avg_tru[0], avg.m_team_avg_tru[m_team1], win, loss, pct, avg.m_sched.m_games_in_season);
		value_picks1[0] = m_own[m_team1].m_actual_picks[index];
		if(m_own[m_team2].m_number_picks_year[y] >= 6)
		{
			m_own[m_team1].m_draft_pick_addition = 0;
			value_picks1[0] = 0;
		}

	}
	int picks2 = IntRandom(4);



	if(picks2 > 1) picks2 = 0;
	else
	{
		SetOwnDraftPicks(m_team2);
		int index = IntRandom(m_own[m_team2].m_number_actual_picks);
		int y = m_own[m_team2].SetDraftPickAddition(index, avg.m_avg_tru[0], avg.m_team_avg_tru[m_team2], win, loss, pct, avg.m_sched.m_games_in_season);
		value_picks2[0] = m_own[m_team2].m_actual_picks[index];
		if(m_own[m_team1].m_number_picks_year[y] >= 6)
		{
			m_own[m_team2].m_draft_pick_addition = 0;
			value_picks2[0] = 0;

		}
	}



	CPlayer* NewFA;
	NewFA = new CPlayer[481];
	CPlayer* signFA;
	signFA = new CPlayer[481];//used by transaction file to find names of signed players


	int facount = 0;
	for(int i=1; i<=480; i++)
	{
		Signed[i] = 0;
		if(avg.m_actual[960+i].GetName() != "")
		{
			facount = facount + 1;
			NewFA[facount] = avg.m_actual[960+i];

			signFA[facount] = avg.m_actual[960+i];			
		}
	}
	for(int i=0; i<=40; i++)
	{
		players[i] = 0;
	}
	CPlayer* NewRoster = new CPlayer[41];
	CPlayer* NewTeam = new CPlayer[41];//same as original team but with eligible players in trade only
	int playerCount[] = {0,20};
	double tru[] = {0,0};
	double newTru[] = {0,0};
	int elig = 0;







	CPlayer* tmp_player = new CPlayer[61];
	double true_values[61];
	true_values[0] = 0;
	for(int tmp=1; tmp<=60; tmp++)
	{


		int temp = Offset[1] + tmp;
		if(tmp > 30)
		{
			temp = Offset[2] + tmp - 30;
		}


		true_values[tmp] = 0;
		tmp_player[tmp] = avg.m_actual[temp];
	}
	avg.ComputerRotationForTrades(tmp_player, true_values, 30, m_team1-1, m_team2-1);

	
	for(int i=1; i<=60; i++)
	{
		double add = 0;
		if(i == 31)
		{
			if(elig < 8) not_enough = true;
			elig = 0;
		}
			





	
		CPlayer m_player = tmp_player[i];		

		if(m_player.m_min == 0) continue;

		double mn = double(m_player.GetMin()) / double(m_player.GetGames());
		if(m_player.GetName() != "" && i<=30 && mn > 0 && elig < 15 && m_player.GetActive() != 0)
		{
			elig = elig + 1;

			m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[m_team1-1].m_scoring, avg.m_gm[m_team1-1].m_shooting, avg.m_gm[m_team1-1].m_rebounding, avg.m_gm[m_team1-1].m_passing, avg.m_gm[m_team1-1].m_defense);
			m_player.SetTradeTrueRating(0);
			m_player.SetAdjTradeValue(avg.m_gm[m_team1-1].m_pot1, avg.m_gm[m_team1-1].m_pot2, avg.m_gm[m_team1-1].m_effort);


			playerCount[0] = playerCount[0] + 1;
			NewTeam[playerCount[0]] = m_player;



			add = true_values[i];

			if(add != 0 && m_player.m_on_block == true && m_player.m_injury == 0 &&
				m_player.m_active == 1 && m_use_trading_block == true)
				m_players_on_block = m_players_on_block + 1;
			tru[0] = tru[0] + add;
			players[playerCount[0]] = 1;
		}
		else if(m_player.GetName() != "" && mn > 0 && elig < 15 && m_player.GetActive() != 0)
		{
			elig = elig + 1;
			m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[m_team2-1].m_scoring, avg.m_gm[m_team2-1].m_shooting, avg.m_gm[m_team2-1].m_rebounding, avg.m_gm[m_team2-1].m_passing, avg.m_gm[m_team2-1].m_defense);
			m_player.SetTradeTrueRating(0);
			m_player.SetAdjTradeValue(avg.m_gm[m_team2-1].m_pot1, avg.m_gm[m_team2-1].m_pot2, avg.m_gm[m_team2-1].m_effort);


			playerCount[1] = playerCount[1] + 1;
			NewTeam[playerCount[1]] = m_player;

			//if(m_checkCareer == FALSE)
			//	add = m_player.GetTradeTrueRating(m_checkCareer);
			//else
			add = true_values[i];

			tru[1] = tru[1] + add;
			players[playerCount[1]] = 2;

		}

	}

	if(elig < 8) not_enough = true;


	delete [] tmp_player;

	if(not_enough == false)
	{



//	if(tru[0] == 0) tru[o] = avg.m_avg_tru[0] * 5;
//	if(originalteam2true == 0) originalteam2true = avg.m_avg_tru[0] * 5;

	if(m_players_on_block > 0 && players1 > m_players_on_block)
	{
		int tem = m_players_on_block;
		players1 = IntRandom(tem);
		if(players1 > 2) players1 = IntRandom(tem);
	}


	bool check[] = {false, false, false,  false, false, false,  
		false, false, false,  false, false, false, false, false, false,false};

	for(int i=1; i<=players1; i++)
	{
		int n = 0;
		do
		{
			n = IntRandom(15);
		} 
		while(check[n] == true || NewTeam[n].GetName() == ""
			|| NewTeam[n].GetInjury() > 0 
			|| NewTeam[n].GetActive() == 0 || (NewTeam[n].m_on_block == false && m_players_on_block > 0));
        check[n] = true;
		players[n] = 2;

	}
	
	for(int i=1; i<=15; i++){check[i] = false;}

	for(int i=1; i<=players2; i++)
	{
		int n = 0;
		do
		{
			n = IntRandom(15);
		} 
		while(check[n] == true || NewTeam[20+n].GetName() == "" 
			|| NewTeam[20+n].GetInjury() > 0
			|| NewTeam[20+n].GetActive() == 0);
        check[n] = true;
		players[20 + n] = 1;
	}
	


	int count[] = {0,20};
	int s1 = 0, s2 = 0;
	m_own[m_team1].m_total_true_in_trade = 0;
	m_own[m_team1].m_total_salary_in_trade = 0;
	m_own[m_team2].m_total_true_in_trade = 0;
	m_own[m_team2].m_total_salary_in_trade = 0;

	for(int i=1; i<=40; i++)
	{
		if(players[i] == 1 && NewTeam[i].GetName() != "")
		{
			
			count[0] = count[0] + 1;
			NewRoster[count[0]] = NewTeam[i];


			if(i > 20)
			{

			s1 = s1 + NewRoster[count[0]].m_current_yr_salary;
			int yrs_left = 1 + NewRoster[count[0]].m_contract_yrs 
					- NewRoster[count[0]].m_current_contract_yr;

			m_own[m_team1].m_total_true_in_trade = m_own[m_team1].m_total_true_in_trade + NewRoster[count[0]].GetTradeTrueRating(m_checkCareer)*yrs_left;

			int rem_sal = NewRoster[count[0]].m_remaining_salary;
			if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;


			m_own[m_team1].m_total_salary_in_trade =
					m_own[m_team1].m_total_salary_in_trade 
					+ rem_sal;

			}




		}
		else if(players[i] == 2 && NewTeam[i].GetName() != "")
		{
			count[1] = count[1] + 1;
			NewRoster[count[1]] = NewTeam[i];


			if(i <= 20)
			{

			s2 = s2 + NewRoster[count[1]].m_current_yr_salary;
			int yrs_left = 1 + NewRoster[count[1]].m_contract_yrs 
					- NewRoster[count[1]].m_current_contract_yr;


			int rem_sal = NewRoster[count[1]].m_remaining_salary;
			if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;


			m_own[m_team2].m_total_true_in_trade = m_own[m_team2].m_total_true_in_trade + NewRoster[count[1]].GetTradeTrueRating(m_checkCareer)*yrs_left;
			m_own[m_team2].m_total_salary_in_trade =
					m_own[m_team2].m_total_salary_in_trade 
					+ rem_sal;
			}

		}
	}

	double tru_factor_1 = m_own[m_team1].m_total_true_in_trade;
	double tru_factor_2 = m_own[m_team2].m_total_true_in_trade;
	double under_paid_1 =	tru_factor_1 - (double)m_own[m_team1].m_total_salary_in_trade / 100;
	double under_paid_2 =	tru_factor_2 - (double)m_own[m_team2].m_total_salary_in_trade / 100;
	double value_factor_1 = 0;
	double value_factor_2 = 0;
	value_factor_1 = under_paid_1*400 / (double)avg.m_finance[m_team1-1].m_current_value;
	value_factor_2 = under_paid_2*400 / (double)avg.m_finance[m_team2-1].m_current_value;


	double sa1 = (double)s1;
	double sa2 = (double)s2;
	bool salary_fit = true;
	
	double min = sa1*.85 - 10;
	double max = sa1*1.15 + 10;
	if(sa2 <  min || sa2 > max) salary_fit = false;

		for(int computerTeam = 0; computerTeam <=1; computerTeam++)
		{
		int pg=2,sg=2,sf=2,pf=2,c=2;
		int t = m_team1;
		if(computerTeam == 1) t = m_team2;
	    for(int i=1; i<=480; i++)
		{
	        CPlayer m_player = avg.m_actual[960+i];
            avg.m_actual[960+i].SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[t].m_scoring, avg.m_gm[t].m_shooting, avg.m_gm[t].m_rebounding, avg.m_gm[t].m_passing, avg.m_gm[t].m_defense);
	        avg.m_actual[960+i].SetTradeTrueRating(0);
	        avg.m_actual[960+i].SetAdjTradeValue(avg.m_gm[t].m_pot1, avg.m_gm[t].m_pot2, avg.m_gm[t].m_effort);
		}
		for(int i=1; i<=15; i++)
		{
			if(NewRoster[computerTeam*20+i].GetPos() == "PG" && NewRoster[computerTeam*20+i].GetName() != "" && NewRoster[computerTeam*20+i].GetActive() == 1) pg=pg-1;
			else if(NewRoster[computerTeam*20+i].GetPos() == "SG" && NewRoster[computerTeam*20+i].GetActive() == 1) sg=sg-1;
			else if(NewRoster[computerTeam*20+i].GetPos() == "SF" && NewRoster[computerTeam*20+i].GetActive() == 1) sf=sf-1;
			else if(NewRoster[computerTeam*20+i].GetPos() == "PF" && NewRoster[computerTeam*20+i].GetActive() == 1) pf=pf-1;
			else if(NewRoster[computerTeam*20+i].GetPos() == " C" && NewRoster[computerTeam*20+i].GetActive() == 1) c=c-1;
		}
		
		if( ((pg > 0 && m_player_gm[t-1] == "Computer") || (pg > 0 && m_ast_gm == TRUE)) && avg.m_settings.m_current_stage == 0)
		{
			int temp = pg;
			if(pg > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
						&& NewFA[n].GetPos() == "PG"
						&& Signed[n] == 0
						&& NewFA[n].GetName() != "") high = n;
				}
				if(high > 0 && pg>0 && count[computerTeam] < (20 + computerTeam*20))
				{
					count[computerTeam] = count[computerTeam] + 1;
					NewRoster[count[computerTeam]] = NewFA[high];
					NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
					NewRoster[count[computerTeam]].m_current_team = t-1;
					NewRoster[count[computerTeam]].SetJustSignedContracts();
					Signed[high] = computerTeam + 1;
					faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
					pg = pg-1;
				}
			}
			}
		}
		if( ((sg > 0 && m_player_gm[t-1] == "Computer") || (sg > 0 && m_ast_gm == TRUE)) && avg.m_settings.m_current_stage == 0)
		{
			int temp = sg;
			if(sg > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
						&& NewFA[n].GetPos() == "SG"
						&& Signed[n] == 0
						&& NewFA[n].GetName() != "") high = n;
				}
				if(high > 0 && sg>0 && count[computerTeam] < (20 + computerTeam*20))
				{
					count[computerTeam] = count[computerTeam] + 1;
					NewRoster[count[computerTeam]] = NewFA[high];
					NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
					NewRoster[count[computerTeam]].m_current_team = t-1;
					NewRoster[count[computerTeam]].SetJustSignedContracts();
					Signed[high] = computerTeam + 1;
					faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
					sg = sg-1;
				}
			}
			}
		}
		if( ((sf > 0 && m_player_gm[t-1] == "Computer") || (sf > 0 && m_ast_gm == TRUE)) && avg.m_settings.m_current_stage == 0)
		{
			int temp = sf;
			if(sf > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
						&& NewFA[n].GetPos() == "SF"
						&& Signed[n] == 0 
						&& NewFA[n].GetName() != "") high = n;
				}
				if(high > 0 && sf>0 && count[computerTeam] < (20 + computerTeam*20))
				{
					count[computerTeam] = count[computerTeam] + 1;
					NewRoster[count[computerTeam]] = NewFA[high];
					NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
					NewRoster[count[computerTeam]].m_current_team = t-1;
					NewRoster[count[computerTeam]].SetJustSignedContracts();
					Signed[high] = computerTeam + 1;
					faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
					sf = sf-1;
				}
			}
			}
		}
		if( ((pf > 0 && m_player_gm[t-1] == "Computer") || (pf > 0 && m_ast_gm == TRUE)) && avg.m_settings.m_current_stage == 0)
		{
			int temp = pf;
			if(pf > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
						&& NewFA[n].GetPos() == "PF"
						&& Signed[n] == 0
						&& NewFA[n].GetName() != "") high = n;
				}
				if(high > 0 && pf>0 && count[computerTeam] < (20 + computerTeam*20))
				{
					count[computerTeam] = count[computerTeam] + 1;
					NewRoster[count[computerTeam]] = NewFA[high];
					NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
					NewRoster[count[computerTeam]].m_current_team = t-1;
					NewRoster[count[computerTeam]].SetJustSignedContracts();
					Signed[high] = computerTeam + 1;
					faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
					pf = pf-1;
				}
			}
			}
		}
		if( ((c > 0 && m_player_gm[t-1] == "Computer") || (c > 0 && m_ast_gm == TRUE)) && avg.m_settings.m_current_stage == 0)
		{
			int temp = c;
			if(c > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
						&& NewFA[n].GetPos() == " C"
						&& Signed[n] == 0
						&& NewFA[n].GetName() != "") high = n;
				}
				if(high > 0 && c>0 && count[computerTeam] < (20 + computerTeam*20))
				{
					count[computerTeam] = count[computerTeam] + 1;
					NewRoster[count[computerTeam]] = NewFA[high];
					NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
					NewRoster[count[computerTeam]].m_current_team = t-1;
					NewRoster[count[computerTeam]].SetJustSignedContracts();	Signed[high] = computerTeam + 1;
					faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
					c = c-1;
				}
			}
			}
		}
		int newOffset = computerTeam*20;
		int sign = (12+newOffset) - count[computerTeam];
				int temp = sign;
				if( (sign > 0 && m_player_gm[t-1] == "Computer") || (sign > 0 && m_ast_gm == TRUE))
				{
				for(int i=1; i<=temp; i++)
				{
					int high = 0;
					for(int n=1; n<=480; n++)
					{
						if(NewFA[n].GetTradeTrueRating(m_checkCareer) >= NewFA[high].GetTradeTrueRating(m_checkCareer)
							&& NewFA[n].GetName()!=""
							&& Signed[n] == 0) high = n;
					}
					if(high > 0 && sign>0 && count[computerTeam] < (20 + computerTeam*20))
					{
						count[computerTeam] = count[computerTeam] + 1;
						NewRoster[count[computerTeam]] = NewFA[high];
						NewRoster[count[computerTeam]].m_previous_team = NewFA[high].m_current_team;
						NewRoster[count[computerTeam]].m_current_team = t-1;
						NewRoster[count[computerTeam]].SetJustSignedContracts();
						Signed[high] = computerTeam + 1;
						faTru[computerTeam] = faTru[computerTeam] + NewFA[high].GetTradeTrueRating(m_checkCareer);
						sign = sign-1;
					}
				}
				}

			if(pg>0 || sg>0 || sf>0 || pf>0 || c>0) invalid = true;

							

			for(int player=0; player<=40; player++)
			{

				int inj = NewRoster[player].GetInjury();//reset injuries
				NewRoster[player].SetTradeTrueRating(inj);//reset injuries
			}

					//cut 15-20 slot
					for(int i=16;i<=20;i++)
					{
						bool ok = true;//if already fa don't add again
						for(int p=1; p<=480; p++)
						{
							if(NewFA[p].GetName() == NewRoster[newOffset+i].GetName() &&
								NewFA[p].GetName() != "" &&
								NewFA[p].GetMin() == NewRoster[newOffset+i].GetMin())
							{
								Signed[p] = 0;
								ok = false;
							}
						}
						if(ok == true && NewRoster[newOffset+i].GetName() != "")
						{
							CPlayer m_player;
							facount = facount + 1;
							NewFA[facount] = NewRoster[newOffset+i];

							if(computerTeam == 0)
							{
								NewFA[facount].m_team_paying = m_team1;
								NewFA[facount].m_team_paying_name = m_leagueTeamNames[m_team1-1];
								NewFA[facount].m_current_team = -1;

							}
							else
							{
								NewFA[facount].m_team_paying = m_team2;
								NewFA[facount].m_team_paying_name = m_leagueTeamNames[m_team2-1];
								NewFA[facount].m_current_team = -1;
							}


							NewRoster[newOffset + i] = m_player;
							if(Signed[facount] == 1 || Signed[facount] == 2) faTru[computerTeam] = faTru[computerTeam] - NewFA[facount].GetTradeTrueRating(m_checkCareer);
							Signed[facount] = computerTeam + 3;//player cut
							signFA[facount] = NewFA[facount];//add to FA to be used by write trans
						}
					}

		






	CPlayer* tmpa_player = new CPlayer[41];
	double new_true_values[41];
	for(int tmp=0; tmp<=40; tmp++)
	{
		new_true_values[tmp] = 0;
		tmpa_player[tmp] = NewRoster[tmp];
	}
	avg.ComputerRotationForTrades(tmpa_player, new_true_values, 20, m_team1-1, m_team2-1);
	delete [] tmpa_player;


	for(int i=1; i<=15; i++)
	{

		
		//int t = m_team1 - 1;
		//if(computerTeam == 1) t = m_team2 - 1;

		CPlayer m_player = NewRoster[newOffset + i];
		if(m_player.m_min == 0) continue;

		CString name = m_player.GetName();
		double mn = double(m_player.GetMin()) / double(m_player.GetGames());
		if(name == "" || mn == 0 || m_player.GetActive() == 0) continue;
		double add = new_true_values[computerTeam*20+i];

		newTru[computerTeam] = newTru[computerTeam] + add;
		
	}

			newTru[computerTeam] = newTru[computerTeam] - faTru[computerTeam];
		}    
			for(int p=1; p<=480; p++)
			{
				if(Signed[p] == 1 || Signed[p] == 2)
				{
					CPlayer m_player;
					NewFA[p] = m_player;//clear signed guy
				}

			}

    if(m_control[m_team1-1] == "Player" && m_control[m_team2-1] == "Player") invalid = true;

	if(not_enough == true) invalid = true;
	if(invalid == false)
	{

		
		double pick_diff = m_own[m_team2].m_draft_pick_addition - m_own[m_team1].m_draft_pick_addition;
		double value_diff = (value_factor_1 - value_factor_2) / 2;
		
		newTru[0] = newTru[0] + pick_diff/2 + value_diff;
		newTru[1] = newTru[1] - pick_diff/2 - value_diff;

		double f1 = .98;
		double f2 = 1.06;
		

		if(avg.m_settings.m_salary_matching == false)
			salary_fit = true;
//		else
//		{
//			f1 = .98;
//			f2 = 1.06;
//		}

		//f1 = .8; f2 = 1.2;
		

		if(salary_fit == false)
			invalid = true;
		else if(m_computerTrades == TRUE && t1_offered == false && t2_offered == false && m_control[m_team1-1] != "Player" && m_control[m_team2-1] != "Player" && m_player_gm[m_team1-1] == "Computer" && m_player_gm[m_team2-1] == "Computer")
		{
			double v_t = newTru[0] / tru[0];
			double h_t = newTru[1] / tru[1];
			invalid = (v_t <= f1 || h_t <= f1				|| v_t >= f2 || h_t >= f2);
		
		}
		else if(t1_offered == true && t2_offered == false && m_player_gm[m_team2-1] == "Computer")
		{
			double compOffer = newTru[1] / tru[1];
			double playerOffer = newTru[0] / tru[0];
            if(compOffer > 1.08 && compOffer < 1.16 && playerOffer < .98 )
			{
				offers = offers + 1;
				invalid = OfferTrade(NewTeam, value_picks1, value_picks2);
				
			}
			else invalid = true;
        }
		else if(t2_offered == true && t1_offered == false && m_player_gm[m_team1-1] == "Computer")
        {
			double compOffer = newTru[0] / tru[0];
			double playerOffer = newTru[1] / tru[1];
            if(compOffer > 1.08 && compOffer < 1.16 && playerOffer < .98 )
			{
				offers = offers + 1;
				invalid = OfferTrade(NewTeam, value_picks1, value_picks2);

			}
			else invalid = true;
        }
		else
			invalid = true;

		
		if(invalid == false)
		{

		//avg.ComputerSortsRosterAfterTrades(NewRoster, 20);
		
		for(int i=1; i<=15; i++)
		{
			int offset = Offset[1] + i;
			avg.m_actual[offset] = NewRoster[i];
			avg.m_actual[offset].SetActive(TRUE);
			avg.m_actual[offset].m_team_paying_name = m_leagueTeamNames[m_team1-1];
		}
		for(int i=1; i<=15; i++)
		{
			int offset = Offset[2] + i;
			avg.m_actual[offset] = NewRoster[20+i];
			avg.m_actual[offset].SetActive(TRUE);
			avg.m_actual[offset].m_team_paying_name = m_leagueTeamNames[m_team2-1];
		}

		facount = 0;
		for(int i=1; i<=480; i++)
		{
			if(NewFA[i].GetName() != "" && NewFA[i].GetMin() > 0)
			{
				facount = facount + 1;
                NewFA[i].SetActive(0);
				avg.m_actual[960+facount] = NewFA[i];
				avg.m_actual[960+facount].SetTradeTrueRating(0);
			}
		}
		for(int i=(facount+1); i<=480; i++)
		{
			CPlayer m_player;//clear the rest
			avg.m_actual[960+i] = m_player;
		}

		
		for(int i=0; i<=32; i++)
		{
			m_future.m_own[i] = m_own[i];
		}
		m_future.SetDraftChartComputerTrades(m_team2, value_picks1[0]);
		m_future.SetDraftChartComputerTrades(m_team1, value_picks2[0]);

		m_own[0] = m_future.m_own[0];

		m_own[0].WriteOwnData(m_path + m_leagueName + ".own");		

		WriteTransaction(NewTeam, Signed, signFA, value_picks1, value_picks2);

		avg.SortTeamRosters(avg.m_actual, false);

		m_trade_made = true;

		}

		
	}

	}

	delete [] NewRoster;
	delete [] NewTeam;
	delete [] NewFA;
	delete [] signFA;
	
	
	}
	bool invalid = true;
	if(m_trade_made == true) invalid = false;
	return invalid;


}





bool CComputer::OfferTrade(CPlayer NewTeam[41], int value_picks1[4], int value_picks2[4])
{
	COfferTrades* offer = new COfferTrades;
	offer->avg = avg;
	for(int i=0; i<=40; i++)
	{
		offer->players[i] = players[i];
		offer->NewTeam[i] = NewTeam[i];
	}
	for(int i=0; i<=32; i++)
	{
		offer->avg.m_gm[i] = avg.m_gm[i];
		offer->m_scout[i] = avg.m_scout[i];
		offer->m_coach[i] = avg.m_coach[i];
		offer->m_leagueTeamNames[i] = m_leagueTeamNames[i];
		if(m_receive_offers[i] == true)
			offer->m_control[i] = "Player";
		else
			offer->m_control[i] = "Computer";

	}
	offer->m_team1Name = m_leagueTeamNames[m_team1-1];
	offer->m_team1 = m_team1 - 1;
	offer->m_team2 = m_team2 - 1;
	offer->m_team2Name = m_leagueTeamNames[m_team2-1];
	offer->m_path = m_path;
	offer->m_leagueName = m_leagueName;
	offer->m_current_year = m_current_year;
	if(t2_offered == true) 
	{
		offer->m_teamOffering = offer->m_team1Name;
		offer->m_standing_team = m_team1-1;
	}
	else
	{
		offer->m_teamOffering = offer->m_team2Name;
		offer->m_standing_team = m_team2-1;
	}

	bool invalid = true;

	for(int i=0; i<=3; i++)
	{
		offer->m_value_picks1[i] = value_picks1[i];
		offer->m_value_picks2[i] = value_picks2[i];
	}

	int result = offer->DoModal();

	if(result == IDOK) invalid = false;
	if(offer->m_trade_made_via_trading_screen == true)
	{
		invalid = true;//check if trades made in trade screen work?
		m_trade_made = true;
		for(int i=1; i<=480; i++)
		{
			avg.m_actual[960+i] = offer->avg.m_actual[960+i];
		}
		for(int t=0; t<=31; t++)
		{
			m_own[t] = offer->avg.m_own[t];
			for(int p=1; p<=30; p++)
			{
				avg.m_actual[t*30+p] = offer->avg.m_actual[t*30+p];
			}
		}


	}

	delete offer;
	return invalid;
}

void CComputer::WriteTransaction(CPlayer NewTeam[41], int Signed[480], CPlayer signFA[480], int value_picks1[4], int value_picks2[4])
{
	CString temp, temp1, string, string1;
	int mo = m_currentMonth + 10;
	if(mo > 12) mo = mo - 12;
	int da = m_currentDay + 1;
	int yr = m_current_year;
	int ty = 2;//trade
	int team1 = m_team1;
	int team2 = m_team2;
	
	string.Format("%2d%2d%4d%2d", mo, da, yr, ty);                          
	string1.Format("%2d%2d%4d%2d", mo, da, yr, ty);
	
	
	for(int i=1; i<=20; i++)
	{
		int pic = 0;
		if(players[i] == 2)
		{
			CString id;
			id.Format("%d%6d%6d%6d", pic, team1, team2, NewTeam[i].GetID());
			string = string + id;
		}
	}
	
	CString pick_string1, pick_string2;

	int pick = value_picks1[0];
	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);
	int pic = 1;
    int te1 = p;
	if(y > 0 || r > 0 || te1 > 0)
		pick_string1.Format("%d%6d%6d%6d", pic, m_current_year - 1 + y, r, te1);

	string = string + pick_string1;

	for(int i=21; i<=40; i++)
	{
		int pic = 0;
		if(players[i] == 1)
		{
			CString id;
			id.Format("%d%6d%6d%6d", pic, team2, team1, NewTeam[i].GetID());
			string1 = string1 + id;
		}
	}
	
	pick = value_picks2[0];
	y = pick / 1000;
	r = (pick - y*1000) / 100;
	p = pick - (y*1000 + r*100);
	pic = 1;
    int te2 = p;
	if(y > 0 || r > 0 || te2 > 0)
		pick_string2.Format("%d%6d%6d%6d", pic, m_current_year - 1 + y, r, te2);

	string1 = string1 + pick_string2;

	



	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = string;

	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = string1;

	ty = 3;//sign
	for(int i=1; i<=480; i++)
	{
		CString moreString;
		CString nm = signFA[i].GetPos() + " " + signFA[i].GetName();
		int id = signFA[i].GetID();
		if(Signed[i] == 1)
		{
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);
		}
		else if(Signed[i] == 2)
		{
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team2, id);
		}
		else if(Signed[i] == 3)
		{
			ty = 4;//release
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);

		}
		else if(Signed[i] == 4)
		{
			ty = 4;
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team2, id);

		}
		if(Signed[i] > 0)
		{
//			moreString = moreString + "                                                                                                                                ";
//			f.Write(moreString, 128);
			avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
			avg.m_trans_str[avg.m_settings.m_number_transactions] = moreString;


		}
	}
//	f.Close();
}


void CComputer::SignFreeAgent(int team)//pass team needing player
{
	CString pos = PositionNeeded(team);
	int index = BestFreeAgent(team, pos);
	if(index > 0)//player found
	{
		AddFreeAgentToTeam(team, index);//must be before remove
		RemoveFreeAgentFromList(index);
		int player_index = ReorderRoster(team);

		avg.m_actual[player_index].m_team_paying = team;
		avg.m_actual[player_index].m_team_paying_name = avg.m_settings.m_leagueTeamNames[team-1];

		WriteSigningsToFile(team, player_index);
	}
}

CString CComputer::PositionNeeded(int team)
{
	CString string = "ANY";

	int player_index = (team-1)*30 + 1;
	//count 
	int h_pg = 0, h_sg = 0, h_sf = 0, h_pf = 0, h_c = 0;//track healthy
	int pg = 0, sg = 0, sf = 0, pf = 0, c = 0;//track regardless of injury
	for(int i=player_index; i<=player_index+14; i++)
	{
		if(avg.m_actual[i].GetPos() == "PG" && avg.m_actual[i].GetInjury() == 0) h_pg = h_pg + 1;
		else if(avg.m_actual[i].GetPos() == "SG" && avg.m_actual[i].GetInjury() == 0) h_sg = h_sg + 1;
		else if(avg.m_actual[i].GetPos() == "SF" && avg.m_actual[i].GetInjury() == 0) h_sf = h_sf + 1;
		else if(avg.m_actual[i].GetPos() == "PF" && avg.m_actual[i].GetInjury() == 0) h_pf = h_pf + 1;
		else if(avg.m_actual[i].GetPos() == " C" && avg.m_actual[i].GetInjury() == 0) h_c  = h_c  + 1;
	}		

	if(h_pg < 2)
		string = "PG";
	else if(h_sg < 2)
		string = "SG";
	else if(h_sf < 2)
		string = "SF";
	else if(h_pf < 2)
		string = "PF";
	else if(h_c  < 2)
		string = " C";
	//else if(pg < 2)
	//	string = "PG";
	//else if(sg < 2)
//		string = "SG";
//	else if(sf < 2)
//		string = "SF";
//	else if(pf < 2)
//		string = "PF";
//	else if(c  < 2)
//		string = " C";
		
	return string;
}

int CComputer::BestFreeAgent(int team, CString pos)
{
	double high = -99;
	int leader = -1;
//	do
//	{
	for(int i=1; i<=480; i++)
	{
		CPlayer m_player =avg.m_actual[960+i];	
		CString string = m_player.GetPos();
		if(pos == "ANY") string = "ANY";
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[team-1].m_scoring, avg.m_gm[team-1].m_shooting, avg.m_gm[team-1].m_rebounding, avg.m_gm[team-1].m_passing, avg.m_gm[team-1].m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(avg.m_gm[team-1].m_pot1, avg.m_gm[team-1].m_pot2, avg.m_gm[team-1].m_effort);
		if(m_player.GetName() != "" && m_player.GetTradeValue() > high && pos == string && m_player.GetInjury() == 0 && m_player.m_id != m_last_released_player_id) leader = i;
	}
	pos = "ANY";// set pos to ANY if need to run thru again to insure a player is found (ie run out of PG's to sign)
//	if(avg.m_actual[480+i].GetName() == "") leader = -1;
//	}
//	while (leader == 0);

	return leader;
}

void CComputer::RemoveFreeAgentFromList(int index)
{
	CPlayer m_player;
	for(int i=index; i<=480; i++)
	{
		avg.m_actual[960+i] =avg.m_actual[960+i+1];
	}
	avg.m_actual[960+480] = m_player;
}

void CComputer::AddFreeAgentToTeam(int team, int index)
{
	int player_index = (team-1)*30 + 16;
	avg.m_actual[player_index] =avg.m_actual[960+index];
	avg.m_actual[player_index].SetActive(1);
}

int CComputer::ReorderRoster(int team)
{

	int player_index = (team-1)*30;
	int counter = 0;	
	do
	{
		player_index = player_index + 1;
		counter = counter + 1;
	}
	while (avg.m_actual[player_index].GetName() != "" && counter <= 15); 
		
	int last_slot = (team-1)*30 + 16;
	avg.m_actual[player_index] = avg.m_actual[last_slot];//stick the free agent added  into the 1st blank slot
	avg.m_actual[player_index].m_previous_team = avg.m_actual[last_slot].m_current_team;
	avg.m_actual[player_index].m_current_team = team;
	avg.m_actual[player_index].SetJustSignedContracts();
	CPlayer m_player;
	avg.m_actual[last_slot] = m_player;
	return player_index;
}




void CComputer::WriteSigningsToFile(int team, int player_index)
{
	int mo = avg.m_sched.m_currentMonth + 10;
	if(mo > 12) mo = mo - 12;
	int da = avg.m_sched.m_currentDay + 1;
	int yr = avg.m_settings.m_currentYear;

	int ty = 3;
	int team1 = team;
	CString moreString;
	int id = avg.m_actual[player_index].GetID();
	avg.m_actual[player_index].m_team_paying = team;
	avg.m_actual[player_index].m_team_paying_name = avg.m_settings.m_leagueTeamNames[team1-1];
	moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);
	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = moreString;


}


bool CComputer::ReleasePlayer(int team)//release worst injured player
{

	bool never_mind = true;

	int player_index = (team-1)*30+1;


	//count 
	int pg = 0, sg = 0, sf = 0, pf = 0, c = 0;//track regardless of injury
	for(int i=player_index; i<=player_index+29; i++)
	{

		if(avg.m_actual[i].m_name == "") continue;


		if(avg.m_actual[i].GetPos() == "PG") pg = pg + 1;
		else if(avg.m_actual[i].GetPos() == "SG") sg = sg + 1;
		else if(avg.m_actual[i].GetPos() == "SF") sf = sf + 1;
		else if(avg.m_actual[i].GetPos() == "PF") pf = pf + 1;
		else if(avg.m_actual[i].GetPos() == " C") c  = c  + 1;
	}		

	double high = 255;//set to random hi
	int leader = 0;
	for(int i=player_index; i<=player_index+29; i++)
	{
		CPlayer m_player = avg.m_actual[i];	
		if(m_player.m_name == "") continue;
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[team-1].m_scoring, avg.m_gm[team-1].m_shooting, avg.m_gm[team-1].m_rebounding, avg.m_gm[team-1].m_passing, avg.m_gm[team-1].m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(avg.m_gm[team-1].m_pot1, avg.m_gm[team-1].m_pot2, avg.m_gm[team-1].m_effort);
		double sc = 0;
		if(m_player.m_pos == "PG") sc = m_player.GetTradeValue() - (double)pg*100;
		else if(m_player.m_pos == "SG") sc = m_player.GetTradeValue() - (double)sg*100;
		else if(m_player.m_pos == "SF") sc = m_player.GetTradeValue() - (double)sf*100;
		else if(m_player.m_pos == "PF") sc = m_player.GetTradeValue() - (double)pf*100;
		else if(m_player.m_pos == " C") sc = m_player.GetTradeValue() - (double)c*100;


		if(sc < high) {leader = i; high = sc;};
	}
	
	if(leader > 0)
	{
		never_mind = false;
		CPlayer m_player;
		bool found = false;
		for(int i=1; i<=480; i++)
		{
			if(found == true) continue;
			m_player =avg.m_actual[960+i];
			if(m_player.GetName() == "")
			{
				avg.m_actual[960+i] = avg.m_actual[leader];
				avg.m_actual[960+i].m_team_paying = team;
				avg.m_actual[960+i].m_team_paying_name = m_leagueTeamNames[team-1]; 
				found = true;
			}
		}
		if(found == true)
		{
			int id = avg.m_actual[leader].GetID();
			m_last_released_player_id = id;
			WriteReleaseToFile(team, id);
		}


		avg.m_actual[leader] = m_player;// blank out player
	}

	return never_mind;
//	after this a player must be signed to fill the blank spot
}

void CComputer::WriteReleaseToFile(int team, int id)
{
//	int player_index = team*30;
	int mo = avg.m_sched.m_currentMonth + 10;
	if(mo > 12) mo = mo - 12;
	int da = avg.m_sched.m_currentDay + 1;
	int yr = avg.m_settings.m_currentYear;

	int ty = 4;
	int team1 = team;
	CString moreString;
	moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);
	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = moreString;
                                                                                                         	
}

bool CComputer::AvailableFA()
{
	bool avail = false;
	for(int i=0; i<=480; i++)
	{
		if(avg.m_actual[960+i].GetName() != "" && avg.m_actual[960+i].GetInjury() == 0)
			avail = true;
	}
	return avail;
}

void CComputer::SetOwnDraftPicks(int t1)
{

	for(int i=0; i<=27; i++)
	{
		m_own[t1].m_actual_picks[i] = 0;
	}
	for(int i=0; i<=3; i++)
	{
		m_own[t1].m_number_picks_year[i] = 0;
	}
	m_own[t1].m_number_actual_picks = 0;


		for(int y=1; y<=3; y++)
		{
			for(int r=1; r<=2; r++)
			{
				for(int p=1; p<=32; p++)
				{
					int t = m_own[0].m_draft_chart[y][r][p];
					CString string1, string2;
					
					if(t == t1 && t > 0)
					{
						m_own[t1].m_number_actual_picks = m_own[t1].m_number_actual_picks + 1;
						int count = m_own[t1].m_number_actual_picks;
						m_own[t1].m_actual_picks[count] = y*1000 + r*100+p;
						m_own[t1].m_number_picks_year[y] = m_own[t1].m_number_picks_year[y] + 1;
					}
					
				}
			}
		}

}



double CComputer::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}



