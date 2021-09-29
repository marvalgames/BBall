#include "stdafx.h"
#include "bball.h"
#include "bballfile.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"



#ifndef Awards_h
#include "Awards.h"
#define Awards_h
#endif 

CAwards::CAwards()
{
	for(int i=0; i<=10; i++)
	{
		m_mvp[i] = 0;
		m_defense[i] = 0;
		m_rookie[i] = 0;
		m_pts[i] = 0;
		m_reb[i] = 0;
		m_ast[i] = 0;
		m_stl[i] = 0;
		m_blk[i] = 0;
		m_6th[i] = 0;
	}

	for(int i=0; i<=15; i++)
	{
		m_ring[i] = 0;
	}

	for(int i=0; i<= 5; i++)
	{
		for(int j=0; j<=3; j++)
		{
			m_all_league[i][j] = 0;
			m_all_defense[i][j] = 0;
			m_all_rookie[i][j] = 0;
		}
	}

	m_po_mvp = 0;

}

CAwards::~CAwards()
{
}

void CAwards::ChooseAwards()
{
	ChooseMvp();
	ChoosePoMvp();
	ChooseDefense();
	ChooseRookie();
	ChoosePts();
	ChooseReb();
	ChooseAst();
	ChooseStl();
	ChooseBlk();
	Choose6th();
	ChooseAllLeague();
	ChooseAllDefense();
	ChooseAllRookie();

}

void CAwards::ChooseMvp()
{
	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;
		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);

		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_mvp[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];


		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;
		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);

		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_mvp[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;
		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_mvp[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;
		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_mvp[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;
		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_mvp[5] = winner;


}

void CAwards::ChooseAllLeague()
{
	double hi[6] = {0,0,0,0,0,0};
	int winner[6] = {0,0,0,0,0,0};
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;


		if(m_player.m_name == "" || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_league[i][1] = winner[i];
	}



	hi[0] = 0; hi[1] = 0; hi[2] = 0; hi[3] = 0; hi[4] = 0; hi[5] = 0;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_league[i][2] = winner[i];
	}

	hi[0] = 0; hi[1] = 0; hi[2] = 0; hi[3] = 0; hi[4] = 0; hi[5] = 0;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_league[i][3] = winner[i];
	}
}


void CAwards::ChooseAllDefense()
{
	double hi[6] = {0,0,0,0,0,0};
	int winner[6] = {0,0,0,0,0,0};
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_defense;
		}
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_defense[i][1] = winner[i];
	}



	hi[0] = 0; hi[1] = 0; hi[2] = 0; hi[3] = 0; hi[4] = 0; hi[5] = 0;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_defense;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_defense[i][2] = winner[i];
	}
	hi[0] = 0; hi[1] = 0; hi[2] = 0; hi[3] = 0; hi[4] = 0; hi[5] = 0;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_defense;
		}
		else if(m_player.m_sim_defense > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_defense;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_defense[i][3] = winner[i];
	}

}


void CAwards::ChooseAllRookie()
{
	double hi[6] = {-69,-69,-69,-69,-69,-69};
	int winner[6] = {0,0,0,0,0,0};
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double f = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 12) continue;
		if(m_player.m_name == "" || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_rookie[i][1] = winner[i];
	}



	hi[0] = -69; hi[1] = -69; hi[2] = -69; hi[3] = -69; hi[4] = -69; hi[5] = -69;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double f = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 12) continue;

		if(m_player.m_name == "" || m_player.m_yrs_of_service > 1 || chosen[i] == true) continue;

		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_rookie[i][2] = winner[i];
	}

	hi[0] = -69; hi[1] = -69; hi[2] = -69; hi[3] = -69; hi[4] = -69; hi[5] = -69;
	winner[0] = 0; winner[1] = 0; winner[2] = 0; winner[3] = 0; winner[4] = 0; winner[5] = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double f = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 12) continue;

		if(m_player.m_name == "" || m_player.m_yrs_of_service > 1 || chosen[i] == true) continue;

		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi[1] && m_player.m_pos == "PG")
		{
			winner[1] = i;
			hi[1] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[2] && m_player.m_pos == "SG")
		{
			winner[2] = i;
			hi[2] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[3] && m_player.m_pos == "SF")
		{
			winner[3] = i;
			hi[3] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[4] && m_player.m_pos == "PF")
		{
			winner[4] = i;
			hi[4] = m_player.m_sim_trueRating;
		}
		else if(m_player.m_sim_trueRating > hi[5] && m_player.m_pos == " C")
		{
			winner[5] = i;
			hi[5] = m_player.m_sim_trueRating;
		}		
	}

	for(int i=1; i<=5; i++)
	{
		chosen[winner[i]] = true;
		m_all_rookie[i][3] = winner[i];
	}
}




void CAwards::Choose6th()
{
	double hi = -69;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;

		CPlayer m_player = avg.m_actual[i];
		double f = (double)m_player.m_starter / (double)m_player.m_sim_games;

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);

		if(m_player.m_name == "" || chosen[i] == true || f > .375 || m < .625  || m_player.m_sim_minPerGame < 16) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_6th[1] = winner;


	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		double f = (double)m_player.m_starter / (double)m_player.m_sim_games;

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);

		if(m_player.m_name == "" || chosen[i] == true || f > .375 || m < .625  || m_player.m_sim_minPerGame < 16) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_6th[2] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		double f = (double)m_player.m_starter / (double)m_player.m_sim_games;

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);

		if(m_player.m_name == "" || chosen[i] == true || f > .375 || m < .625  || m_player.m_sim_minPerGame < 16) continue;

		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_6th[3] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		double f = (double)m_player.m_starter / (double)m_player.m_sim_games;

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);

		if(m_player.m_name == "" || chosen[i] == true || f > .375 || m < .625  || m_player.m_sim_minPerGame < 16) continue;



		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_6th[4] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		double f = (double)m_player.m_starter / (double)m_player.m_sim_games;

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);

		if(m_player.m_name == "" || chosen[i] == true || f > .375 || m < .625  || m_player.m_sim_minPerGame < 16) continue;

		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_6th[5] = winner;



}


void CAwards::ChoosePoMvp()
{
	double hi = 0;
	int winner = 0;

	for(int i=m_ring[1]; i<=m_ring[15]; i++)
	{
		CPlayer m_player = avg.m_actual[i];


//		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
//		if(games == 0) games = 1;
//		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetPoMinPerGame(m_player.m_po_games, m_player.m_po_min);

		if(m_player.m_name == "" || m_player.m_po_minPerGame < 24) continue;

		if(m_player.m_name == "") continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_po_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_po_trueRating;
		}
	}

	m_po_mvp = winner;



}




void CAwards::ChooseRookie()
{
	double hi = -69;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;


		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 16) continue;


		if(m_player.m_name == "" || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);

		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_rookie[1] = winner;


	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 16) continue;


		if(m_player.m_name == "" || chosen[i] == true || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_rookie[2] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
//		if(m_player.m_sim_minPerGame < 16) continue;


		if(m_player.m_name == "" || chosen[i] == true || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_rookie[3] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		if(m_player.m_name == "" || chosen[i] == true || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
	//	if(m_player.m_sim_minPerGame < 16) continue;


		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_rookie[4] = winner;

	hi = -69;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
	//	if(m_player.m_sim_minPerGame < 16) continue;


		if(m_player.m_name == "" || chosen[i] == true || m_player.m_yrs_of_service > 1) continue;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		if(m_player.m_sim_trueRating > hi)
		{
			winner = i;
			hi = m_player.m_sim_trueRating;
		}
	}

	chosen[winner] = true;
	m_rookie[5] = winner;



}

void CAwards::ChoosePts()
{







	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		bool elig = false;
		double x =  m_player.m_sim_pointsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 1400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;				



		if(m_player.m_sim_pointsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_pointsPerGame;
		}
	}

	chosen[winner] = true;
	m_pts[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		bool elig = false;
		double x =  m_player.m_sim_pointsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 1400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;				


		if(m_player.m_sim_pointsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_pointsPerGame;
		}
	}

	chosen[winner] = true;
	m_pts[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		bool elig = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_pointsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 1400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;				

		if(m_player.m_sim_pointsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_pointsPerGame;
		}
	}

	chosen[winner] = true;
	m_pts[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		bool elig = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_pointsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 1400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;				

		if(m_player.m_sim_pointsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_pointsPerGame;
		}
	}

	chosen[winner] = true;
	m_pts[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		bool elig = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);

		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_pointsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 1400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;				

		if(m_player.m_sim_pointsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_pointsPerGame;
		}
	}

	chosen[winner] = true;
	m_pts[5] = winner;

}

void CAwards::ChooseReb()
{
	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);

		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_reboundsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 800./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;


		if(m_player.m_sim_reboundsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_reboundsPerGame;
		}
	}

	chosen[winner] = true;
	m_reb[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
	m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);

		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_reboundsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 800./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;



	if(m_player.m_sim_reboundsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_reboundsPerGame;
		}
	}

	chosen[winner] = true;
	m_reb[2] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
	m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_reboundsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 800./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;


	if(m_player.m_sim_reboundsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_reboundsPerGame;
		}
	}

	chosen[winner] = true;
	m_reb[3] = winner;



	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
	m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_reboundsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 800./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;


		if(m_player.m_sim_reboundsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_reboundsPerGame;
		}
	}

	chosen[winner] = true;
	m_reb[4] = winner;



	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;

		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_reboundsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 800./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_reboundsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_reboundsPerGame;
		}
	}

	chosen[winner] = true;
	m_reb[5] = winner;



}

void CAwards::ChooseAst()
{
	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);

		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_assistsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;


		if(m_player.m_sim_assistsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_assistsPerGame;
		}
	}

	chosen[winner] = true;
	m_ast[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_assistsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_assistsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_assistsPerGame;
		}
	}

	chosen[winner] = true;
	m_ast[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_assistsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_assistsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_assistsPerGame;
		}
	}

	chosen[winner] = true;
	m_ast[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_assistsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_assistsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_assistsPerGame;
		}
	}

	chosen[winner] = true;
	m_ast[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_assistsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 400./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_assistsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_assistsPerGame;
		}
	}

	chosen[winner] = true;
	m_ast[5] = winner;


}

void CAwards::ChooseStl()
{
	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_stealsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 125./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_stealsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_stealsPerGame;
		}
	}

	chosen[winner] = true;
	m_stl[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_stealsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 125./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;
		if(m_player.m_sim_stealsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_stealsPerGame;
		}
	}

	chosen[winner] = true;
	m_stl[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_stealsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 125./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;
		if(m_player.m_sim_stealsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_stealsPerGame;
		}
	}

	chosen[winner] = true;
	m_stl[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_stealsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 125./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;
		if(m_player.m_sim_stealsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_stealsPerGame;
		}
	}

	chosen[winner] = true;
	m_stl[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_stealsPerGame * double( m_player.m_sim_games)/double(games);
		double y = 125./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;
		if(m_player.m_sim_stealsPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_stealsPerGame;
		}
	}

	chosen[winner] = true;
	m_stl[5] = winner;

}

void CAwards::ChooseBlk()
{
	double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);

		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_blocksPerGame * double( m_player.m_sim_games)/double(games);
		double y = 100./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_blocksPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_blocksPerGame;
		}
	}

	chosen[winner] = true;
	m_blk[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_blocksPerGame * double( m_player.m_sim_games)/double(games);
		double y = 100./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		
		if(m_player.m_sim_blocksPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_blocksPerGame;
		}
	}

	chosen[winner] = true;
	m_blk[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_blocksPerGame * double( m_player.m_sim_games)/double(games);
		double y = 100./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_blocksPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_blocksPerGame;
		}
	}

	chosen[winner] = true;
	m_blk[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_blocksPerGame * double( m_player.m_sim_games)/double(games);
		double y = 100./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_blocksPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_blocksPerGame;
		}
	}

	chosen[winner] = true;
	m_blk[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "" || chosen[i] == true) continue;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		bool elig = false;
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double x =  m_player.m_sim_blocksPerGame * double( m_player.m_sim_games)/double(games);
		double y = 100./82.;
		if(x >= y || double( m_player.m_sim_games)/double(games) >= 70./82.) elig = true;
		if(elig == false) continue;

		if(m_player.m_sim_blocksPerGame > hi)
		{
			winner = i;
			hi = m_player.m_sim_blocksPerGame;
		}
	}

	chosen[winner] = true;
	m_blk[5] = winner;


}


void CAwards::SaveAwards(CString file_name)
{
	SeekAllstarContestants(file_name);

	SaveMvp(file_name);
	SavePoMvp(file_name);
	SaveDefense(file_name);
	SaveRookie(file_name);
	SavePts(file_name);
	SaveReb(file_name);
	SaveAst(file_name);
	SaveStl(file_name);
	SaveBlk(file_name);
	SaveRing(file_name);
	Save6th(file_name);
	SaveAllLeague(file_name);
	SaveAllDefense(file_name);
	SaveAllRookie(file_name);

}

void CAwards::SaveMvp(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_mvp[i]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 680 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}
}

void CAwards::SaveAllLeague(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=3; j++)
		{

	int id = avg.m_actual[m_all_league[i][j]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 691 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", j);
	file.Write(buffer, 1);
		}
	}
}

void CAwards::SaveAllDefense(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=3; j++)
		{

	int id = avg.m_actual[m_all_defense[i][j]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 692 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", j);
	file.Write(buffer, 1);
		}
	}
}

void CAwards::SaveAllRookie(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=3; j++)
		{

	int id = avg.m_actual[m_all_rookie[i][j]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 693 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", j);
	file.Write(buffer, 1);
		}
	}
}

void CAwards::Save6th(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_6th[i]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 690 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}
}


void CAwards::SavePoMvp(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	int id = avg.m_actual[m_po_mvp].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 689 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	file.Write("1", 1);

}

void CAwards::SaveRookie(CString file_name)
{

	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_rookie[i]].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 682 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}
}


void CAwards::WriteAwardHistoryFile(CString file_name)
{
	CString award_file_name = file_name + ".awa";
	CString exp_file_name = file_name + ".exp";
	CBBallFile* disk = new CBBallFile;
    disk->IncreaseFileSize(award_file_name, 1000);
    disk->IncreaseFileSize(	file_name + ".sal", 50000);

	int mvp[11], mvp_team_index[11];
	int sth[11], sth_team_index[11];
	int defense[11], defense_team_index[11];
	int rookie[11], rookie_team_index[11];
	int pts[11], pts_team_index[11], pts_avg[11];
	int reb[11], reb_team_index[11], reb_avg[11]; 
	int ast[11], ast_team_index[11], ast_avg[11];
	int stl[11], stl_team_index[11], stl_avg[11];
	int blk[11], blk_team_index[11], blk_avg[11];
	int po_mvp = avg.m_actual[m_po_mvp].m_id;
	int po_mvp_team_index = avg.m_actual[m_po_mvp].m_current_team;

	for(int i=0; i<=10; i++)
	{
		mvp[i] = avg.m_actual[m_mvp[i]].m_id;
		mvp_team_index[i] = avg.m_actual[m_mvp[i]].m_current_team;
		sth[i] = avg.m_actual[m_6th[i]].m_id;
		sth_team_index[i] = avg.m_actual[m_6th[i]].m_current_team;
		defense[i] = avg.m_actual[m_defense[i]].m_id;
		defense_team_index[i] = avg.m_actual[m_defense[i]].m_current_team;
		rookie[i] = avg.m_actual[m_rookie[i]].m_id;
		rookie_team_index[i] = avg.m_actual[m_rookie[i]].m_current_team;
		pts[i] = avg.m_actual[m_pts[i]].m_id;
		pts_team_index[i] = avg.m_actual[m_pts[i]].m_current_team;


		CPlayer m_player = avg.m_actual[m_pts[i]];
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);
		pts_avg[i] = int(m_player.m_sim_pointsPerGame * 100.);


		m_player = avg.m_actual[m_reb[i]];
		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		reb_avg[i] = int(m_player.m_sim_reboundsPerGame * 100.);

		m_player = avg.m_actual[m_ast[i]];
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		ast_avg[i] = int(m_player.m_sim_assistsPerGame * 100.);

		m_player = avg.m_actual[m_stl[i]];
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		stl_avg[i] = int(m_player.m_sim_stealsPerGame * 100.);

		m_player = avg.m_actual[m_blk[i]];
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		blk_avg[i] = int(m_player.m_sim_blocksPerGame * 100.);



		reb[i] = avg.m_actual[m_reb[i]].m_id;
		reb_team_index[i] = avg.m_actual[m_reb[i]].m_current_team;
		ast[i] = avg.m_actual[m_ast[i]].m_id;
		ast_team_index[i] = avg.m_actual[m_ast[i]].m_current_team;
		stl[i] = avg.m_actual[m_stl[i]].m_id;
		stl_team_index[i] = avg.m_actual[m_stl[i]].m_current_team;
		blk[i] = avg.m_actual[m_blk[i]].m_id;
		blk_team_index[i] = avg.m_actual[m_blk[i]].m_current_team;
	}
    disk->WriteAwardHistoryFile(award_file_name, exp_file_name, m_current_year, mvp, mvp_team_index,
		sth, sth_team_index,
		defense, defense_team_index,
		rookie, rookie_team_index,
		pts, pts_team_index, pts_avg,
		reb, reb_team_index, reb_avg, 
		ast, ast_team_index, ast_avg,
		stl, stl_team_index, stl_avg,
		blk, blk_team_index, blk_avg,
		po_mvp, po_mvp_team_index,
		m_winner, m_loser, m_win, m_loss, avg.m_settings.m_all_star, avg.m_settings.m_all_star_index, avg.m_settings.m_rookie_star, avg.m_settings.m_rookie_star_index, avg.m_settings.m_3contest, avg.m_settings.m_3contest_index, avg.m_settings.m_dunkcontest, avg.m_settings.m_dunkcontest_index);
	delete disk;
}

void CAwards::ChooseDefense()
{
double hi = 0;
	int winner = 0;
    bool chosen[1441];

	for(int i=0; i<=1440; i++)
	{
        chosen[i] = false;
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;

		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;

		if(m_player.m_name == "" || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi)
		{
			winner = i;
			hi = m_player.m_sim_defense;
		}
	}

	chosen[winner] = true;
	m_defense[1] = winner;


	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;


		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi)
		{
			winner = i;
			hi = m_player.m_sim_defense;
		}
	}

	chosen[winner] = true;
	m_defense[2] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;


		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi)
		{
			winner = i;
			hi = m_player.m_sim_defense;
		}
	}

	chosen[winner] = true;
	m_defense[3] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;


		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi)
		{
			winner = i;
			hi = m_player.m_sim_defense;
		}
	}

	chosen[winner] = true;
	m_defense[4] = winner;

	hi = 0;
	winner = 0;
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		int games = avg.m_actual[1441].m_sim_games;//use high of 1st team since its end of season
		if(games == 0) games = 1;
		double m = (double)m_player.m_sim_games / (double) games;
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		if(m_player.m_sim_minPerGame < 24) continue;


		if(m_player.m_name == "" || chosen[i] == true || m < .625) continue;
		m_player.SetDefense();
		if(m_player.m_sim_defense > hi)
		{
			winner = i;
			hi = m_player.m_sim_defense;
		}
	}

	chosen[winner] = true;
	m_defense[5] = winner;

}

void CAwards::SaveDefense(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_defense[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 681 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}

void CAwards::SavePts(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_pts[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 683 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}
void CAwards::SaveReb(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_reb[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 684 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}
void CAwards::SaveAst(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_ast[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 685 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}
void CAwards::SaveStl(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_stl[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 686 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}
void CAwards::SaveBlk(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=5; i++)
	{

	int id = avg.m_actual[m_blk[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 687 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write(buffer, 1);

	}

}

void CAwards::ChooseRings(CString award_file)
{
	
	m_winner = 0;
	m_loser = 0;
	m_win = 0;
	m_loss = 0;//final results
  	

  	CString file_name = award_file;
			
	int seek = 72001;
	file_name = file_name + ".sch";
		CFile file( file_name,  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		int m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffGame = i;
		int round = 1;
		int wins_needed = 0;
		int champions = 0, loser = 0, win = 0, loss = 0;
		CString format = format1;
		if(format != "")//no playoffs
		{
		for(int  j = 0; j <= 27; j++ )//28 playoff days
		{
			if(j>=21 && format4 == "" || j>=14 && format3 == "" || j>=7 && format2 == "") continue;

			
			if(j <= 6)
				format = format1.GetAt(0);
			else if(j <= 13)
				format = format2.GetAt(0);
			else if(j <=20)
				format = format3.GetAt(0);
			else if(j <= 27)
				format = format4.GetAt(0);
			
			wins_needed = atoi(format);
			for(int  k = 0; k <= 7; k++ )//8 max playoff games per day
			{
				char s[7];

				int seek = 72046 + j*96 + k*12;
				file.Seek(seek, CFile::begin );
				
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team1 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score1 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win1 = atoi(s);

				
				bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team2 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score2 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win2 = atoi(s);

				CString result;
				if(team1 > 0 && team2 > 0 && m_currentRound == m_playoffRounds)
				{
					if(win1 == wins_needed)
					{
						champions = team1;
						loser = team2;
						win = win1;
						loss = win2;
					}
					else if(win2 == wins_needed)
					{
						champions = team2;
						loser = team1;
						win = win2;
						loss = win1;
					}

				}
			}

					

		}

		}

		if(champions > 0)
		{
			m_winner = champions;
			m_loser = loser;
			m_win = win;
			m_loss = loss;

			for(int p=1; p<=15; p++)
			{
				m_ring[p] = (champions-1) * 30 + p;
			}	
		}
}


void CAwards::SaveRing(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	for(int i=1; i<=15; i++)
	{

	if(avg.m_actual[m_ring[i]].m_name == "") continue;

	int id = avg.m_actual[m_ring[i]].m_id;
	int seek = 2000 + id*500 + 676;


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 688 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("%d", i);
	file.Write("1", 1);

	}

}


void CAwards::SaveAllstarMVP(CString file_name)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	int id = avg.m_actual[m_po_mvp].m_id;
	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int aw_seek = 2000 + id*500 + 689 + (current_award_year*15);
	file.Seek( aw_seek, CFile::begin);
	file.Write("1", 1);
}

void CAwards::SaveRookiestarMVP(CString file_name)
{

}

void CAwards::SaveThreeContest(CString file_name)
{

}

void CAwards::SaveDunkContest(CString file_name)
{

}

void CAwards::SaveAllstarWeekend(CString file_name, int id, int offset, CString str)
{
	CFile file(	file_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	int seek = 2000 + id*500 + 676; 


 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = m_current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = m_current_year - start_yr;
	if(current_award_year > 20) current_award_year = 20;

	int multiplier = 15;
	if(offset >= 995) multiplier = 3;

	int aw_seek = 2000 + id*500 + offset + (current_award_year*multiplier);
	file.Seek( aw_seek, CFile::begin);
	file.Write(str, 1);
}

void CAwards::SeekAllstarContestants(CString file_name)
{
	for(int i=0; i<=1440; i++)
	{
		CPlayer m_player = avg.m_actual[i];
		if(m_player.m_name == "") continue;
		if(m_player.m_all_star == 1)
			SaveAllstarWeekend(file_name, m_player.m_id, 694, "1");
		else if(m_player.m_all_star == 2)
			SaveAllstarWeekend(file_name, m_player.m_id, 694, "2");

		if(m_player.m_rookie_star == 1)
			SaveAllstarWeekend(file_name, m_player.m_id, 995, "1");
		else if(m_player.m_rookie_star == 2)
			SaveAllstarWeekend(file_name, m_player.m_id, 995, "2");

		if(m_player.m_3contest == 1)
			SaveAllstarWeekend(file_name, m_player.m_id, 996, "1");
		else if(m_player.m_3contest == 2)
			SaveAllstarWeekend(file_name, m_player.m_id, 996, "2");

		if(m_player.m_dunkcontest == 1)
			SaveAllstarWeekend(file_name, m_player.m_id, 997, "1");
		else if(m_player.m_dunkcontest == 2)
			SaveAllstarWeekend(file_name, m_player.m_id, 997, "2");


	}
}
