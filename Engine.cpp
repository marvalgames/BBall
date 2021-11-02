// Engine.cpp: implementation of the CEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#ifndef Engine_h
#include "Engine.h"
#define Engine_h
#endif 
#include "Computer.h"
#include "Playoff.h"
//#include "Constants.h"
//#include "High.h"
#ifndef High_h
#include "High.h"
#define High_h
#endif 
#include "AllStarWeekend.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEngine::CEngine()
{
	TeamRatings = new CPlayer[3];
	m_injury_count = 0;
	m_play_over = false;
	m_sub_ok = true;
	m_milk = false;

	m_score_string = "";
	m_all_star_weekend_game = false;

	m_before_pbp_lines = 0;
	m_player_selected_type_shot = 1;
	m_player_selected_ball_handler = 0;

	m_avg_player_min_factor = 0;
	m_sim_paused = false;
	m_crash = false;
	m_time = 720;
	m_pbp_results = 0;
	m_position_ball_handler = 0;
	m_defAdj = 0;
	m_visitor_player_offset = 0;
	m_home_player_offset = 0;

	m_update_lineup = true;
	GarbageTime = FALSE;
	m_toVisitor = 7;
	m_toHome = 7;
	m_toVisitor20 = 1;
	m_toHome20 = 1;

	m_visitorTo = false;
	m_homeTo = false;
	m_visitorTo20 = false;
	m_homeTo20 = false;
	m_toCalled = false;

	m_game_saved = false;
	m_gameOver = false;

	m_firstPossesion = 1;
	m_edit_games = 0;
	m_previousTime = 0;
	m_ballHandler = 0;
	m_fbChance = true;
	m_visitorIndex = 0;
	m_homeIndex = 0;
	m_visitor = "";
	m_home = "";
	m_injury = 0;
	//m_valid_visitor_rosters = true;
	//m_valid_home_rosters = true;
	//m_dont_sign_visitor = true;
	//m_dont_sign_home = true;
	//m_release_player_visitor = false;
	//m_release_player_home = false;
	m_gameType = EXHIBITION;
	m_possesion = 0;

	for (int i = 0; i <= 2; i++)
	{
		m_auto_sub[i] = TRUE;
		m_must_sub[i] = 0;
		for (int j = 0; j <= 5; j++)
		{
			Lineup[i][j] = 0;
			Defense[i][j] = 0;
			m_quarter_score[i][j] = 0;
		}
	}

	for (int i = 0; i <= 10; i++)
	{
		m_starters[i] = 0;
		m_match[i] = 0;
	}


	for (int i = 0; i <= 2; i++)
	{
		m_possesion_team_index[i] = 0;//stores index of team with ball 1 visitor 2 home - m_possesion put here to get value
		m_teamFouls[i] = 0;
		m_score[i] = 0;
	}

	for (int i = 0; i <= 60; i++)
	{
		m_playing_players_list[i] = 0;
	}

	for (int i = 0; i <= 3200; i++)
	{
		m_pbp_strings[i] = "";
	}

	m_simulate = TRUE;
	m_newGame = false;
	m_injury_notify = -1;
	m_lineupSet = false;
	m_toOk = false;
	m_toCalled = false;
	m_homeCourt = TRUE;


	m_teamName = "";
	m_team = "";
	m_playerName = "";

	m_hca = .20;

	//srand( (unsigned)time( NULL ) );
}

CEngine::~CEngine()
{
	delete[] TeamRatings;

}


CString CEngine::GetTeamWithBallName()
{
	CString string;
	return string;

}


int CEngine::GetTeamWithoutBall()
{
	int te = 0;
	int po = m_possesion;
	if (po == 1) po = 2; else po = 1;
	te = m_possesion_team_index[po];
	return te;
}

int CEngine::GetTeamWithBall()
{
	int te = m_possesion_team_index[m_possesion];
	return te;
}

int CEngine::GetPossesionOfTeamWithoutBall()
{
	int po = 1;
	if (m_possesion == 1) po = 2;

	return po;

}

void CEngine::SetupComputerLineups()
{
	// TODO: Add your command handler code here
	CString PositionNames[6] = { "", "PG", "SG", "SF", "PF", " C" };
	CString TeamName;
	int number = 0;
	int Totals[16] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };
	double avg_min[] = { 0,0,0 };
	double vet[] = { 0,0 };
	for (int team = 1; team <= 2; team++)
	{
		for (int i = 0; i <= 30; i++)
		{
			int pla = m_playing_players_list[(team - 1) * 30 + i];
			CPlayer m_player = avg.m_actual[pla];
			vet[team - 1] = vet[team - 1] + (double)m_player.m_effort * (double)m_player.m_yrs_of_service;
		}
	}

	double fac3 = (vet[0] - vet[1]) / 6000;
	if (m_gameType == PLAYOFF) fac3 = (vet[0] - vet[1]) / 4000;

	for (int team = 1; team <= 2; team++)
	{
		for (int i = 0; i <= 15; i++)
		{
			Totals[i] = 0;
		}

		double fac4 = 1 + fac3 / 2;
		if (team == 2) fac4 = 1 - fac3 / 2;//veterans

		for (int n = 1; n <= 30; n++)
		{

			int pla = m_playing_players_list[(team - 1) * 30 + n];
			int te = m_possesion_team_index[team];
			CPlayer m_player = avg.m_actual[pla];
			double fac1 = (95 + (double)m_player.m_content) / 100.;
			double fac2 = (double)m_player.m_health / 100.;
			double fac = (fac1 + fac2) / 2;


			//		fac = 1;
			m_player.SetTeammatesBetterRating(avg.m_avg_fga[0], avg.m_avg_fta[0], avg.m_avg_tga[0], avg.m_avg_tru_on_roster, avg.m_avg_orb[0], avg.m_avg_drb[0], avg.m_avg_ast[0], avg.m_avg_stl[0], avg.m_avg_to[0], avg.m_avg_blk[0]);

			if (m_player.m_teammatesBetterRating > 0) m_player.m_teammatesBetterRating = m_player.m_teammatesBetterRating * fac * fac4;
			else m_player.m_teammatesBetterRating = m_player.m_teammatesBetterRating * (2. - fac) * fac4;


			m_player.SetTrueRatingSimple(ACTUAL);
			//		m_player.SetTradeTrueRating(m_player.GetGameInjury());
			m_player.SetTradeTrueRating(0);
			// add to Team Totals
			int tg = m_player.GetGames();
			int tmin = m_player.GetMin();



			int tfgm = int((double)m_player.GetFgm() * fac);
			int tfga = m_player.GetFga();
			int tftm = int((double)m_player.GetFtm() * fac);
			int tfta = m_player.GetFta();
			int ttgm = int((double)m_player.GetTfgm() * fac);
			int ttga = m_player.GetTfga();
			int torb = int((double)m_player.GetOreb() * fac);
			int treb = int((double)m_player.GetReb() * fac);
			int tast = int((double)m_player.GetAst() * fac);
			int tstl = int((double)m_player.GetStl() * fac);
			int tto = int((double)m_player.GetTo() * (2. - fac));
			int tblk = int((double)m_player.GetBlk() * fac);
			int tpf = int((double)m_player.GetPf() * (2 - fac));

			Totals[1] = Totals[1] + tg;
			Totals[2] = Totals[2] + tmin;
			Totals[3] = Totals[3] + tfgm;
			Totals[4] = Totals[4] + tfga;
			Totals[5] = Totals[5] + tftm;
			Totals[6] = Totals[6] + tfta;
			Totals[7] = Totals[7] + ttgm;
			Totals[8] = Totals[8] + ttga;
			Totals[9] = Totals[9] + torb;
			Totals[10] = Totals[10] + treb;
			Totals[11] = Totals[11] + tast;
			Totals[12] = Totals[12] + tstl;
			Totals[13] = Totals[13] + tto;
			Totals[14] = Totals[14] + tblk;
			Totals[15] = Totals[15] + tpf;

			int game_min = m_player.m_game_minutes * m_player.m_games;
			if (game_min == 0) game_min = m_player.m_min;

			if (avg.m_settings.m_player_gm[m_possesion_team_index[team] - 1] != "Player"
				&& avg.m_settings.m_control[m_possesion_team_index[team] - 1] != "Player") game_min = int((double)game_min * fac2);//computer cuts minutes of unhealthy player because it knows the health


			m_player.SetGameMinPerGame(
				m_player.GetGames(), game_min, 40);

			m_player.SetGameFgPct(
				tfgm - ttgm,
				tfga - ttga);

			m_player.SetGameFtPct(
				tftm, tfta);

			m_player.SetGameFoulsDrawnPer48Min(
				tfta, tmin,
				(avg.m_avg_pf[0] * 5 - avg.m_avg_to[0] * 5 * .1) / (avg.m_avg_fta[0] * 5));

			m_player.SetGameTfgPct(
				ttgm, ttga);

			m_player.SetGameFgaPer48Min(
				tfga - ttga, tmin);

			m_player.SetGameTfgaPer48Min(
				ttga, tmin);

			m_player.SetGameAdjustedTfgaPer48Min(
				ttga, tmin);

			m_player.SetGameOrebPer48Min(
				torb, tmin);

			m_player.SetGameDrebPer48Min(
				torb, treb, tmin);

			m_player.SetGameAstPer48Min(
				tast, tmin);

			m_player.SetGameStlPer48Min(
				tstl, tmin);

			m_player.SetGameToPer48Min(
				tto, tmin);

			m_player.SetGameAdjustedToPer48Min(
				tto, tmin);

			m_player.SetGameBlkPer48Min(
				tblk, tmin);

			m_player.SetGamePfPer48Min(
				tpf - tto / 10, tmin);//fouls reduced by off foul turnovers

			m_player.SetGameAdjustedFgaPer48Min(0);
			m_player.SetGameAdjustedFoulsDrawnPer48Min();
			m_player.SetGameAdjustedFgPct();

			m_player.SetGameInjuryRating(tg,
				tmin, tfga,
				tfta, tto, avg.m_settings.m_injury, avg.m_hi_g[0]);

			m_player.SetGameCoachTfgaPer48Min(false);

			m_player.SetGameStamina(tg, tmin, avg.m_coach[te].m_coachEndurance);
			m_player.SetOriginalAdjustedRatings();

			m_player.SetGameCurrentStamina(m_player.m_stamina);

			avg.m_actual[pla] = m_player;


			number = number + 1;
		}

		//store team ratings
//		m_avg_player_min_factor = avg.m_avg_min[0] / ((double) Totals[2] /  (double) Totals[1]);
		avg_min[team] = avg.m_avg_min_on_roster / ((double)Totals[2] / (double)Totals[1]);


		Totals[2] = Totals[2] / 5;
		TeamRatings[team].SetGameFgPct(Totals[3] - Totals[7], Totals[4] - Totals[8]);
		TeamRatings[team].SetGameFtPct(Totals[5], Totals[6]);
		TeamRatings[team].SetGameFoulsDrawnPer48Min(Totals[6], Totals[2],
			(avg.m_avg_pf[0] * 5 - avg.m_avg_to[0] * 5 * .1) / (avg.m_avg_fta[0] * 5));
		TeamRatings[team].SetGameTfgPct(Totals[7], Totals[8]);
		TeamRatings[team].SetGameFgaPer48Min(Totals[4] - Totals[8], Totals[2]);
		TeamRatings[team].SetGameTfgaPer48Min(Totals[8], Totals[2]);
		TeamRatings[team].SetGameOrebPer48Min(Totals[9], Totals[2]);
		TeamRatings[team].SetGameDrebPer48Min(Totals[9], Totals[10], Totals[2]);
		TeamRatings[team].SetGameAstPer48Min(Totals[11], Totals[2]);
		TeamRatings[team].SetGameStlPer48Min(Totals[12], Totals[2]);
		TeamRatings[team].SetGameToPer48Min(Totals[13], Totals[2]);
		TeamRatings[team].SetGameBlkPer48Min(Totals[14], Totals[2]);
		TeamRatings[team].SetGamePfPer48Min(Totals[15], Totals[2]);
		TeamRatings[team].SetGameCoachTfgaPer48Min(true);
		double factor = (TeamRatings[team].GetGameDrebPer48Min() + TeamRatings[team].GetGameStlPer48Min()) / 5;

		for (int p = 1; p <= 30; p++)
		{
			int player = m_playing_players_list[(team - 1) * 30 + p];
			double fbFga = (double(avg.m_actual[player].GetTransOff())) / 25 * factor;//avg 1.8 fga on fb
			avg.m_actual[player].SetGameAdjustedFgaPer48Min(fbFga);
			avg.m_actual[player].SetGameCoachFgaPer48Min();

		}
	}


	m_avg_player_min_factor = (avg_min[1] + avg_min[2]) / 2;




	for (int team = 0; team <= 2; team++)
	{

		for (int position = 0; position <= 5; position++)
		{
			for (int n = 0; n <= 9; n++)
			{
				Rotation[team][position][n].Chart = 0;
				Rotation[team][position][n].Priority = 0;
				Rotation[team][position][n].Minutes = 0;
				Rotation[team][position][n].InRotation = false;
			}
		}
	}

	for (int team = 1; team <= 2; team++)// is there a player at each position?
	{
		for (int n = 1; n <= 15; n++)
		{
			int pla = m_playing_players_list[(team - 1) * 30 + n];
			avg.m_actual[pla].m_gamepgrot = avg.m_actual[pla].GetPgRot();
			avg.m_actual[pla].m_gamesgrot = avg.m_actual[pla].GetSgRot();
			avg.m_actual[pla].m_gamesfrot = avg.m_actual[pla].GetSfRot();
			avg.m_actual[pla].m_gamepfrot = avg.m_actual[pla].GetPfRot();
			avg.m_actual[pla].m_gamecrot = avg.m_actual[pla].GetCRot();
		}

		for (int n = 1; n <= 15; n++)
		{
			int pla = m_playing_players_list[(team - 1) * 30 + n];
			CPlayer m_player = avg.m_actual[pla];
			if (m_player.GetPos() == "PG" && m_player.m_gamepgrot == 0) m_player.m_gamepgrot = 5;
			else if (m_player.GetPos() == "SG" && m_player.m_gamesgrot == 0) m_player.m_gamesgrot = 5;
			else if (m_player.GetPos() == "SF" && m_player.m_gamesfrot == 0) m_player.m_gamesfrot = 5;
			else if (m_player.GetPos() == "PF" && m_player.m_gamepfrot == 0) m_player.m_gamepfrot = 5;
			else if (m_player.GetPos() == " C" && m_player.m_gamecrot == 0) m_player.m_gamecrot = 5;

			avg.m_actual[pla] = m_player;

		}
		//if not then set people to that position
		for (int n = 1; n <= 15; n++)
		{
			int pla = m_playing_players_list[(team - 1) * 30 + n];
			CPlayer m_player = avg.m_actual[pla];

			if ((m_player.GetPos() == "SG" || m_player.GetPos() == "SF") && m_player.m_gamepgrot == 0)
				m_player.m_gamepgrot = 6;//5 means OK on depth chart			
			if ((m_player.GetPos() == "PG" || m_player.GetPos() == "SF") && m_player.m_gamesgrot == 0)
				m_player.m_gamesgrot = 6;//5 means OK on depth chart			
			if ((m_player.GetPos() == "SG" || m_player.GetPos() == "PF") && m_player.m_gamesfrot == 0)
				m_player.m_gamesfrot = 6;//5 means OK on depth chart			
			if ((m_player.GetPos() == "SF" || m_player.GetPos() == " C") && m_player.m_gamepfrot == 0)
				m_player.m_gamepfrot = 6;//5 means OK on depth chart			
			if ((m_player.GetPos() == "PF" || m_player.GetPos() == "SF") && m_player.m_gamecrot == 0)
				m_player.m_gamecrot = 6;//5 means OK on depth chart			

			avg.m_actual[pla] = m_player;

		}
	}
	bool used[961];
	for (int team = 0; team <= 960; team++) { used[team] = false; }
	for (int team = 1; team <= 2; team++)
	{



		for (int position = 1; position <= 5; position++)
		{
			double CurrentHighMinutes = 0;
			int starter = 0;
			double factor = 0;
			for (int n = 1; n <= 12; n++)
			{
				int slot = (team - 1) * 30 + n;
				int player = m_playing_players_list[slot];
				CPlayer m_player = avg.m_actual[player];


				if (m_player.GetName() == "") continue;
				m_player = avg.m_actual[player];
				//set starters
				if (position == 1 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.m_gamepgrot * 240.) > CurrentHighMinutes
					&& m_player.m_gamepgrot > 0 && used[player] != true)
				{
					starter = player;
					factor = 2400. - m_player.m_gamepgrot * 240;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
				}
				else if (position == 2 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.m_gamesgrot * 240.) > CurrentHighMinutes
					&& m_player.m_gamesgrot > 0 && used[player] != true)
				{
					starter = player;
					factor = 2400 - m_player.m_gamesgrot * 240.;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
				}
				else if (position == 3 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.m_gamesfrot * 240.) > CurrentHighMinutes
					&& m_player.m_gamesfrot > 0 && used[player] != true)
				{
					starter = player;
					factor = 2400 - m_player.m_gamesfrot * 240.;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
				}
				else if (position == 4 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.m_gamepfrot * 240.) > CurrentHighMinutes
					&& m_player.m_gamepfrot > 0 && used[player] != true)
				{
					starter = player;
					factor = 2400 - m_player.m_gamepfrot * 240.;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
				}
				else if (position == 5 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.m_gamecrot * 240.) > CurrentHighMinutes
					&& m_player.m_gamecrot > 0 && used[player] != true)
				{
					starter = player;
					factor = 2400 - m_player.m_gamecrot * 240.;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
				}
				else if (position == 1 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
					&& m_player.GetPos() == "PG" && used[player] != true)
				{
					starter = player;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
				}
				else if (position == 2 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
					&& m_player.GetPos() == "SG" && used[player] != true)
				{
					starter = player;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
				}
				else if (position == 3 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
					&& m_player.GetPos() == "SF" && used[player] != true)
				{
					starter = player;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
				}
				else if (position == 4 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
					&& m_player.GetPos() == "PF" && used[player] != true)
				{
					starter = player;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
				}
				else if (position == 5 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
					&& m_player.GetPos() == " C" && used[player] != true)
				{
					starter = player;
					CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
				}
			}
			Rotation[team][position][0].Chart = starter;
			used[starter] = true;
			Rotation[team][position][0].Minutes = CurrentHighMinutes + 480 - factor;
		}

	}




	double minutes[961];
	BOOL InLineup[961];
	for (int i = 0; i <= 960; i++)
	{
		InLineup[i] = FALSE;
		minutes[i] = 0;
	}

	for (int team = 1; team <= 2; team++)
	{
		bool used[961];
		for (int i = 0; i <= 960; i++)
		{
			used[i] = false;
		}



		for (int position = 1; position <= 5; position++)
		{
			double CurrentHighMinutes = 0;
			for (int n = 1; n <= 12; n++)
			{


				int player = m_playing_players_list[(team - 1) * 30 + n];
				CPlayer m_player = avg.m_actual[player];

				if (m_player.GetName() == "") continue;
				//set starters
				//set best 5
				if (m_player.GetPos() == PositionNames[position] && m_player.GetGameMinPerGame() + 240 > CurrentHighMinutes)
				{
					bool OK = false;
					if (Rotation[team][position][0].Chart == player) OK = true;
					if (position == 1 && m_player.m_gamepgrot > 0 && m_player.m_gamepgrot < 3)
						OK = true;
					else if (position == 2 && m_player.m_gamesgrot > 0 && m_player.m_gamesgrot < 3)
						OK = true;
					else if (position == 3 && m_player.m_gamesfrot > 0 && m_player.m_gamesfrot < 3)
						OK = true;
					else if (position == 4 && m_player.m_gamepfrot > 0 && m_player.m_gamepfrot < 3)
						OK = true;
					else if (position == 5 && m_player.m_gamecrot > 0 && m_player.m_gamecrot < 3)
						OK = true;
					if (OK == true && used[player] != true)
					{
						used[player] = true;
						Rotation[team][position][1].Chart = player;
						Rotation[team][position][1].Minutes = m_player.GetGameMinPerGame() + 240;
						CurrentHighMinutes = m_player.GetGameMinPerGame() + 240;
					}
				}
			}


		}
		for (int position = 1; position <= 5; position++)
		{


			double CurrentHighMinutes = 12;
			//		int slot = 2;
			int currentSlot = 2;
			for (int n = 1; n <= 12; n++)
			{
				BOOL FoundPlayer = FALSE;
				BOOL OK = TRUE;

				int player = m_playing_players_list[(team - 1) * 30 + n];
				CPlayer m_player = avg.m_actual[player];



				if (m_player.GetName() == "") continue;
				double min = m_player.GetGameMinPerGame();
				//starter at that position can't be backup
				if (Rotation[team][position][0].Chart == player && m_player.GetPos() == PositionNames[position]) continue;
				//check if starter at another position
				for (int p = 1; p <= 5; p++)
				{
					if (Rotation[team][p][1].Chart == player && position != p)
					{
						OK = FALSE;
					}
				}

				bool NoRotation = false;//ok to play but not in rotation
				if (position == 1 && m_player.m_gamepgrot > 0 &&
					currentSlot <= 8)
				{
					FoundPlayer = TRUE;
					if (m_player.m_gamepgrot >= 5) NoRotation = true;
				}
				else if (position == 2 && m_player.m_gamesgrot > 0 &&
					currentSlot <= 8)
				{
					FoundPlayer = TRUE;
					if (m_player.m_gamesgrot >= 5) NoRotation = true;
				}
				else if (position == 3 && m_player.m_gamesfrot > 0 &&
					currentSlot <= 8)
				{
					FoundPlayer = TRUE;
					if (m_player.m_gamesfrot >= 5) NoRotation = true;
				}
				else if (position == 4 && m_player.m_gamepfrot > 0 &&
					currentSlot <= 8)
				{
					FoundPlayer = TRUE;
					if (m_player.m_gamepfrot >= 5) NoRotation = true;
				}
				else if (position == 5 && m_player.m_gamecrot > 0 &&
					currentSlot <= 8)
				{
					FoundPlayer = TRUE;
					if (m_player.m_gamecrot >= 5) NoRotation = true;
				}
				else if (m_player.GetPos() == PositionNames[position] && OK == TRUE && currentSlot <= 5)
				{
					Rotation[team][position][currentSlot].Chart = player;
					if (min >= CurrentHighMinutes)
						Rotation[team][position][currentSlot].Minutes = min + 48;
					else
						Rotation[team][position][currentSlot].Minutes = min + 0;
					currentSlot = currentSlot + 1;
				}
				if (FoundPlayer == TRUE)
				{
					Rotation[team][position][currentSlot].Chart = player;
					if (NoRotation == false)
						Rotation[team][position][currentSlot].InRotation = true;

					if (OK == TRUE && NoRotation == false)
					{
						if (min >= CurrentHighMinutes)
							Rotation[team][position][currentSlot].Minutes = min + 192;
						else
							Rotation[team][position][currentSlot].Minutes = min + 144;
					}
					else if (NoRotation == false)
					{
						Rotation[team][position][currentSlot].Minutes = min + 96;
					}
					else if (OK == TRUE && NoRotation == true)
					{
						Rotation[team][position][currentSlot].Minutes = min + 0;
					}


					currentSlot = currentSlot + 1;

				}

			}




			for (int i = 1; i < currentSlot; i++)
			{
				for (int j = 1; j < i; j++)
				{
					int x = j;
					int y = i;
					if (Rotation[team][position][x].Minutes < Rotation[team][position][y].Minutes)
					{//swap
						ROTATION temp = Rotation[team][position][y];
						Rotation[team][position][y] = Rotation[team][position][x];
						Rotation[team][position][x] = temp;
					}
				}
			}
			for (int i = 1; i < currentSlot; i++)
			{
				for (int j = 1; j < i; j++)
				{
					if (i == 1 || j == 1) continue;

					bool swap = false;
					int x = j;
					int y = i;
					int player1 = Rotation[team][position][y].Chart;
					int player2 = Rotation[team][position][x].Chart;

					if (position == 1 && avg.m_actual[player1].m_gamepgrot > 0 &&
						avg.m_actual[player2].m_gamepgrot > 0
						&& avg.m_actual[player1].m_gamepgrot < avg.m_actual[player2].m_gamepgrot)
						swap = TRUE;

					else if (position == 2 && avg.m_actual[player1].m_gamesgrot > 0 &&
						avg.m_actual[player2].m_gamesgrot > 0
						&& avg.m_actual[player1].m_gamesgrot < avg.m_actual[player2].m_gamesgrot)
						swap = TRUE;
					else if (position == 3 && avg.m_actual[player1].m_gamesfrot > 0 &&
						avg.m_actual[player2].m_gamesfrot > 0
						&& avg.m_actual[player1].m_gamesfrot < avg.m_actual[player2].m_gamesfrot)
						swap = TRUE;

					else if (position == 4 && avg.m_actual[player1].m_gamepfrot > 0 &&
						avg.m_actual[player2].m_gamepfrot > 0
						&& avg.m_actual[player1].m_gamepfrot < avg.m_actual[player2].m_gamepfrot)
						swap = TRUE;

					else if (position == 5 && avg.m_actual[player1].m_gamecrot > 0 &&
						avg.m_actual[player2].m_gamecrot > 0
						&& avg.m_actual[player1].m_gamecrot < avg.m_actual[player2].m_gamecrot)
						swap = TRUE;


					if (swap == TRUE)
					{
						ROTATION temp = Rotation[team][position][y];
						Rotation[team][position][y] = Rotation[team][position][x];
						Rotation[team][position][x] = temp;
					}
				}
			}



			for (int p = 1; p <= 5; p++)
			{
				int player = 0;
				for (int i = 2; i < currentSlot; i++)//set garbage time lineup
				{
					BOOL OK = TRUE;
					player = Rotation[team][position][i].Chart;
					for (int pl = 1; pl <= 5; pl++)
					{
						if (player == Rotation[team][pl][0].Chart ||
							player == Rotation[team][pl][1].Chart
							|| InLineup[player] == TRUE) OK = FALSE;
					}
					if (OK == TRUE)
					{
						int current = Rotation[team][position][9].Chart;
						if (current > 0) InLineup[current] = FALSE;
						Rotation[team][position][9].Chart = player;
					}

				}
				if (Rotation[team][position][9].Chart == 0)
					Rotation[team][position][9].Chart =
					Rotation[team][position][0].Chart;

				InLineup[player] = TRUE;
			}
		}
		for (int position = 1; position <= 5; position++)
		{
			CPlayer m_starterRatings;
			CPlayer m_finisherRatings;
			int starter = Rotation[team][position][0].Chart;
			int finisher = Rotation[team][position][1].Chart;
			m_starterRatings = avg.m_actual[starter];
			m_finisherRatings = avg.m_actual[finisher];
			minutes[starter] = m_starterRatings.GetGameMinPerGame();
			minutes[finisher] = m_finisherRatings.GetGameMinPerGame();
		}
		for (int position = 1; position <= 5; position++)
		{
			int starter = Rotation[team][position][0].Chart;
			int finisher = Rotation[team][position][1].Chart;
			minutes[starter] = minutes[starter] - 8;
			minutes[finisher] = minutes[finisher] - 8;
		}

		for (int position = 1; position <= 5; position++)
		{
			int backup = Rotation[team][position][2].Chart;
			int starter = Rotation[team][position][0].Chart;
			double minBackup = 32 - minutes[starter];
			for (int p = 1; p <= 5; p++)
			{
				int starter = Rotation[team][p][0].Chart;
				if (starter == backup)
				{
					double minStarter = minutes[starter] - minBackup;
					Rotation[team][p][0].Priority = minStarter;
				}
			}
		}

		for (int position = 1; position <= 5; position++)
		{
			CPlayer m_starterRatings;
			int starter = Rotation[team][position][0].Chart;
			double minStarter;
			if (Rotation[team][position][0].Priority == 0)
				minStarter = minutes[starter];
			else
				minStarter = Rotation[team][position][0].Priority;
			double minBackup = 32 - minStarter;
			Rotation[team][position][0].Priority = minStarter * 4 / 3;
			Rotation[team][position][2].Priority = minBackup * 3 / 4;
		}



		double PositionPlayed[961];
		for (int i = 0; i <= 960; i++)
		{
			PositionPlayed[i] = 0;
		}


		for (int position = 1; position <= 5; position++)
		{
			int backup = Rotation[team][position][2].Chart;
			int starter = Rotation[team][position][0].Chart;
			double factor = 1;
			if (Rotation[team][position][3].InRotation == true) factor = .6;

			if (PositionPlayed[starter] > 0)
				Rotation[team][position][0].Priority = Rotation[team][position][0].Priority - PositionPlayed[starter] * factor;
			else if (PositionPlayed[backup] > 0)
				Rotation[team][position][0].Priority = Rotation[team][position][0].Priority - PositionPlayed[backup] * factor;


			PositionPlayed[starter] = PositionPlayed[starter] + Rotation[team][position][0].Priority * factor;
			PositionPlayed[backup] = PositionPlayed[backup] + Rotation[team][position][2].Priority * factor;
		}

	}


	for (int team = 1; team <= 2; team++)
	{
		int te = m_visitorIndex;
		if (team == 2) te = m_homeIndex;

		for (int n = 1; n <= 30; n++)
		{

			int slot = (te - 1) * 30 + n;
			int games_out = avg.m_actual[slot].GetInjury();


			if (m_gameType == EXHIBITION) games_out = 0;// no previous injuries count in exhibition

		}


	}


	AdjustIntensityForGamePlan();
}




void CEngine::SetStarters()
{
	for (int team = 1; team <= 2; team++)
	{

		int otherteam = 1;
		if (team == 1) otherteam = 2;
		for (int player = 1; player <= 5; player++)
		{
			if (Lineup[team][player] == 0)
				Lineup[team][player] = Rotation[team][player][0].Chart;
			//			Defense[otherteam][player] = Rotation[team][player][0].Chart;
			Defense[team][player] = Rotation[otherteam][player][0].Chart;


			if (team == 1)
			{
				m_starters[(team - 1) * 5 + player] = Rotation[team][player][0].Chart;
			}
			else if (team == 2)
			{
				m_starters[(team - 1) * 5 + player] = Rotation[team][player][0].Chart;
			}



		}
	}

	for (int team = 1; team <= 2; team++)
	{
		bool ok = true;

		for (int player = 1; player <= 5; player++)
		{
			if (Lineup[team][player] == 0) ok = false;
		}

		if (ok == false)
		{
			for (int player = 1; player <= 5; player++)
			{
				Lineup[team][player] = Rotation[team][player][1].Chart;
				Rotation[team][player][0] = Rotation[team][player][1];
			}

		}
	}



}


void CEngine::PossesionChange()
{
	if (m_possesion == 1) m_possesion = 2; else m_possesion = 1;
}

bool CEngine::Rebounder(int& player, bool Rebounder_Same_As_Shooter, bool block) // return put back 
{


	bool PutBack = FALSE;

	int shooter = player;
	int m_reboundTeam = ReboundTeam(m_possesion, Lineup);
	int m_reboundPlayer = ReboundPlayer(m_possesion, Lineup, m_reboundTeam);

	player = Lineup[m_reboundTeam][m_reboundPlayer];
	int reboundTeam = 1440 + m_possesion_team_index[m_reboundTeam]; // 1441-1504

	CPlayer m_player = avg.m_actual[player];
	CPlayer m_teamTotals = avg.m_actual[reboundTeam];

	CString Name = m_player.GetLastName();
	CString playerName = m_player.GetLastName();


	double tr = Random(1);//used to determine team or player rebound 
	CString team;
	if (m_reboundTeam != m_possesion)//Defensive rebound
	{
		PossesionChange();
		if (tr > .06)
		{
			int typeShot = INSIDE;
			m_fbChance = true;

			m_displayString = DefRebound(player) + FieldGoalAttemptCommentary(typeShot,
				shooter);
			FillPbp(m_displayString);
			m_player.SetGameDreb();
		}
		else
		{

			team = m_team_names[m_possesion];
			m_displayString = TeamRebound(team);
			FillPbp(m_displayString);

		}
		m_teamTotals.SetGameDreb();
	}
	else //Offensive rebound
	{
		bool offTeamRebound = false;
		if (tr > .06)
		{
			CPlayer m_player = avg.m_actual[player];
			double pb = Random(1);//used to determine putback or ball back out
			double factor =
				.25 + (m_player.GetGameFgaPer48Min() / (m_player.GetGameFgaPer48Min()
					+ m_player.GetGameOrebPer48Min())) / 2;
			if (pb < factor && offTeamRebound == false)
			{
				PutBack = TRUE;
				Rebounder_Same_As_Shooter = (player == shooter);
				m_ballHandler = player;
			}
		}

		if (tr > .06)
		{
			m_displayString = OffRebound(playerName, player,
				Rebounder_Same_As_Shooter, block, PutBack);
			FillPbp(m_displayString);


			m_player.SetGameOreb();
		}
		else
		{
			team = m_team_names[m_possesion];

			m_displayString = TeamRebound(team);
			FillPbp(m_displayString);

			offTeamRebound = true;
		}
		m_teamTotals.SetGameOreb();
	}
	avg.m_actual[reboundTeam] = m_teamTotals;
	avg.m_actual[player] = m_player;
	if (PutBack == TRUE) SetTime(PutBack, AUTO);
	return PutBack;
}

void CEngine::DisplayAssistCommentary(int astPlayer)
{



	int player = Lineup[m_possesion][astPlayer];
	CPlayer m_player = avg.m_actual[player];
	CString playerName = m_player.GetLastName();



	playerName = m_player.GetLastName();
	m_displayString = AssistCommentary(player,
		playerName);
	FillPbp(m_displayString);

}



void CEngine::Passer(int astPlayer, int passReceiver, bool Fgm)
{

	int passingTeam = GetTeamWithBall();
	int player = Lineup[m_possesion][astPlayer];
	CPlayer m_player = avg.m_actual[player];
	CString playerName = m_player.GetLastName();
	m_displayString = Assist(player, passReceiver);
	FillPbp(m_displayString);

	if (Fgm == TRUE)
	{
		CPlayer m_teamTotals = avg.m_actual[1440 + passingTeam];
		m_player.SetGameAst();
		m_teamTotals.SetGameAst();
		avg.m_actual[player] = m_player;
		avg.m_actual[1440 + passingTeam] = m_teamTotals;
	}
}

bool CEngine::Stealer(int player)
{

	bool Stolen = FALSE;
	int defTeamIndex = GetTeamWithoutBall();
	int defTeam = GetPossesionOfTeamWithoutBall();

	int m_stlPlayer = StealPlayer(Lineup, avg.m_avg_stl[0] * 5);
	if (m_stlPlayer != FALSE)
	{
		m_fbChance = true;
		// get name of player with steal
		int playerStl = Lineup[defTeam][m_stlPlayer];
		CPlayer m_playerStl = avg.m_actual[playerStl];
		CString playerName = m_playerStl.GetLastName();

		int playerTo = player;
		CPlayer m_playerTo = avg.m_actual[playerTo];
		CString m_playerToName = m_playerTo.GetLastName();

		m_displayString = Steal(playerStl, playerName, m_playerToName);
		FillPbp(m_displayString);

		CPlayer m_teamTotals = avg.m_actual[1440 + defTeamIndex];
		m_playerStl.SetGameStl();
		m_teamTotals.SetGameStl();
		avg.m_actual[playerStl] = m_playerStl;
		avg.m_actual[1440 + defTeamIndex] = m_teamTotals;
		Stolen = TRUE;
	}
	return Stolen;
}

bool CEngine::Blocker(int player, bool ThreePointer)
{


	bool Blocked = FALSE;

	int defTeam = GetPossesionOfTeamWithoutBall();

	int m_blkPlayer = BlockPlayer(Lineup, ThreePointer, avg.m_avg_blk[0] * 5);

	if (m_blkPlayer != FALSE)
	{
		int blocker = Lineup[defTeam][m_blkPlayer];
		CPlayer m_player = avg.m_actual[blocker];
		CString playerName = m_player.GetLastName();

		int playerBlocked = player;
		CPlayer m_playerBlocked = avg.m_actual[playerBlocked];
		CString m_playerBlockedName = m_playerBlocked.GetLastName();

		if (ThreePointer == false)
		{
			m_displayString = Block(playerName, m_playerBlockedName, blocker);
			FillPbp(m_displayString);
		}
		else
		{
			m_displayString = BlockThreePointer(playerName, m_playerBlockedName);
			FillPbp(m_displayString);
		}


		CPlayer m_teamTotals = avg.m_actual[1440 + m_possesion_team_index[defTeam]];
		m_player.SetGameBlk();
		m_teamTotals.SetGameBlk();
		avg.m_actual[blocker] = m_player;
		avg.m_actual[1440 + m_possesion_team_index[defTeam]] = m_teamTotals;
		Blocked = TRUE;
	}
	return Blocked;
}

void CEngine::SetMinutesPlayedStat()
{


	int currentQuarter = GetQuarter();
	int currentTime = 0;
	if (currentQuarter <= 4)
	{
		currentTime =
			720 - GetTime() + (currentQuarter - 1) * 720;
	}
	else
	{
		currentTime =
			2880 + (300 - GetTime()) + (currentQuarter - 5) * 300;
	}
	int player = 0;
	int timePlayed = currentTime - m_previousTime;
	bool InLineup[61] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,
						 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 };

	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 5; j++)
		{

			player = Lineup[i][j];
			avg.m_actual[player].m_game_Min = avg.m_actual[player].m_game_Min + timePlayed;

			for (int k = 1; k <= 60; k++)
			{
				if (player == m_playing_players_list[k]) InLineup[k] = true;
			}

		}
	}

	for (int i = 1; i <= 60; i++)
	{

		int pl = m_playing_players_list[i];

		int staminaRating = avg.m_actual[pl].GetGameStamina();
		int staminaGame = avg.m_actual[pl].GetGameCurrentStamina();

		if (InLineup[i] == true)
		{
			avg.m_actual[pl].SetGameCurrentStamina(staminaGame - timePlayed);//time played
		}
		else
		{
			avg.m_actual[pl].SetGameCurrentStamina(staminaGame + timePlayed * 3);//time resting
			int staminaGame = avg.m_actual[i].GetGameCurrentStamina();
			if (staminaGame > staminaRating)
			{
				avg.m_actual[pl].SetGameCurrentStamina(staminaRating);
			}
		}
	}


	m_previousTime = currentTime;


}


void CEngine::GameStart()
{

	//srand( (unsigned)time( NULL ) );	

	m_sub_ok = true;

	//BOOL VisitorOk = TRUE;
	//BOOL HomeOk = TRUE;
	//for(int i=1; i<=5; i++)
	//{
	//	if(Rotation[VISITOR][i][0].Chart == 0) VisitorOk = FALSE;
	//}

	//for(i=1; i<=5; i++)
	//{
	//	if(Rotation[HOME][i][0].Chart == 0) HomeOk = FALSE;
	//}

	bool play_ball = true;


	//if((VisitorOk == FALSE || m_valid_visitor_rosters == false) && avg.m_settings.m_player_gm[m_visitorIndex-1] == "Player" && m_gameType != EXHIBITION)
	//{
	//	CString message;
	//	AfxFormatString1( message, IDS_STRING_MESSAGE1, m_visitor); 
	//	AfxMessageBox(message, MB_OK);		
	//	play_ball = false;
	//	m_simulate = FALSE;
	//}
	//else if((HomeOk == FALSE || m_valid_home_rosters == false) && avg.m_settings.m_player_gm[m_homeIndex-1] == "Player" && m_gameType != EXHIBITION)
	//{
	//	CString message;
	//	AfxFormatString1( message, IDS_STRING_MESSAGE1, m_home); 
	//	AfxMessageBox(message, MB_OK);
	//	play_ball = false;
	//	m_simulate = FALSE;
	//}


	if (play_ball == true)
	{
		m_newGame = FALSE;
		double poss = avg.m_avg_pf[0] * 5 + avg.m_avg_to[0] * 5 * .9 + avg.m_avg_fga_t[0] * 5;
		SetAvgTime(poss, avg.m_avg_orb[0] * 5);
		SetStarters();
		m_game_started = true;
	}



}



void CEngine::GamePlay()
{


	m_quarter_ended = false;
	m_play_over = false;

	if (m_lineupSet == true)
	{
		m_toOk = false;
		bool shotOk = false;
		bool forced3 = false;
		int typeShot = AUTO;
		int originalShot = AUTO;//used to determine type of fb shot

		typeShot = m_player_selected_type_shot;
		m_ballHandler = Lineup[m_possesion][m_player_selected_ball_handler];
		if (m_player_selected_ball_handler > 0)
			m_position_ball_handler = m_player_selected_ball_handler;
		int selection = m_ballHandler;


		int adj_for_coach = IntRandom(2);
		int current_team = m_visitorIndex - 1;
		if (m_possesion == 2) current_team = m_homeIndex - 1;
		int add = 0;


		if (m_fbChance == true && forced3 == false && m_toCalled == FALSE)
		{
			m_fbChance = false;
			int p = IntRandom(5);
			int pl = Lineup[m_possesion][p];
			int n = IntRandom(18);
			int fb = avg.m_actual[pl].GetTransOff() - (m_gameType == PLAYOFF);

			if ((avg.m_coach[current_team].m_coachF == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachF == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachF == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachF == 1) add = -1;
			fb = fb + add;

			if (n <= fb)
			{
				originalShot = FASTBREAK;
				m_ballHandler = pl;
				m_position_ball_handler = p;
			}
		}



		int score_diff = GetGameScore(1) - GetGameScore(2);


		if (originalShot != FASTBREAK) m_ballHandler = BallHandler(m_ballHandler, m_possesion, Lineup, m_homeCourt, shotOk, typeShot, forced3);

		bool int_foul = false;
		if ((m_time <= 24 && GetQuarter() >= 4 && m_possesion == 1 && score_diff <= 3 && score_diff >= 1)
			|| (m_time <= 24 && GetQuarter() >= 4 && m_possesion == 2 && score_diff >= -3 && score_diff <= -1)
			)
		{

			int avoid_foul_factor = avg.m_actual[m_ballHandler].GetPenOff();
			int attempt_at_int_foul = IntRandom(10);
			if (attempt_at_int_foul > avoid_foul_factor)
			{
				int_foul = true;
			}
		}

		if (m_time <= 24 && GetQuarter() >= 4 && m_possesion == 1 && score_diff == -3) forced3 = true;
		else if (m_time <= 24 && GetQuarter() >= 4 && m_possesion == 2 && score_diff == 3) forced3 = true;

		if (m_time <= 24 && GetQuarter() >= 4 && m_possesion == 1 && score_diff > 0 && int_foul == false)
		{
			m_milk = true;
		}
		else if (m_time <= 24 && GetQuarter() >= 4 && m_possesion == 2 && score_diff < 0 && int_foul == false)
		{
			m_milk = true;
		}
		else
		{
			m_milk = false;
		}

		bool PutBack = false;
		bool Three = false; //used to see if putback attempt is off a 3
		bool Rebounder_Same_As_Shooter = false;
		bool block = false;//shot blocked then tip in not allowed (Put up and in)
		bool injury = false;
		do
		{//repeat main loop until no more shots on possesion i.e. no put backs
			m_sub_ok = false;
			int orig_poss = m_possesion;

			int player = m_ballHandler;
			CString playerName = avg.m_actual[player].GetLastName();
			m_teamName = m_team_names[m_possesion];



			int Mov = avg.m_actual[player].GetMovOff();
			int Pen = avg.m_actual[player].GetPenOff();
			int Post = avg.m_actual[player].GetPostOff();
			int Trans = avg.m_actual[player].GetTransOff();
			AdjustOffenseForGamePlan(avg.m_actual[player], Mov, Pen, Post, Trans);

			//adjust for defense fg%
			int dMov = Mov;
			int dPen = Pen;
			int dPost = Post;


			AdjustOffenseForGamePlan(avg.m_actual[player], dMov, dPen, dPost, Trans);


			//adjust for coaching

			add = 0;
			if ((avg.m_coach[current_team].m_coachO == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachO == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachO == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachO == 1) add = -1;
			dMov = dMov + add;

			add = 0;
			if ((avg.m_coach[current_team].m_coachP == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachP == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachP == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachP == 1) add = -1;
			dPen = dPen + add;

			add = 0;
			if ((avg.m_coach[current_team].m_coachI == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachI == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachI == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachI == 1) add = -1;
			dPost = dPost + add;



			if (shotOk == true && typeShot != THREE && typeShot != AUTO)//sometimes coach doesn't get requested type shot
			{
				int factor = 0;
				int total = Mov + Pen + Post;
				if (typeShot == OUTSIDE) factor = Mov * 2;
				else if (typeShot == PENETRATION) factor = Pen * 2;
				else if (typeShot == INSIDE) factor = Post * 2;
				int shot = IntRandom(total);
				if (shot > factor) shotOk = false;
			}
			else if (shotOk == false && typeShot != THREE && typeShot != AUTO && selection == 0)// Auto Player - Shot Selected 
			{
				int factor = 0, AdjMov = 0, AdjPen = 0, AdjPost = 0;
				if (typeShot == OUTSIDE) { AdjMov = Mov * 2; AdjPen = Pen / 2; AdjPost = Post / 2; }
				else if (typeShot == PENETRATION) { AdjPen = Pen * 2; AdjMov = Mov / 2; AdjPost = Post / 2; }
				else if (typeShot == INSIDE) { AdjPost = Post * 2; AdjMov = Mov / 2; AdjPen = Pen / 2; }
				int total = AdjMov + AdjPen + AdjPost;
				typeShot = OUTSIDE;
				int shot = IntRandom(total);
				if (shot > AdjPen + AdjMov)
					typeShot = INSIDE;
				else if (shot > AdjMov)
					typeShot = PENETRATION;
			}
			// m_toCalled == FALSE
			if (shotOk == false || PutBack == TRUE || typeShot == AUTO)
			{

				//      out post drive trans
				//pg    7     3      7       7  
				//sg    6     4      6       6
				//sf     5     5      5        5
				//pf     4     6      4        4
				//c      3     7      3        3


				short pun[5][3];
				int po = 0;
				if (avg.m_actual[player].GetPos() == "SG") po = 1;
				else if (avg.m_actual[player].GetPos() == "SF") po = 2;
				else if (avg.m_actual[player].GetPos() == "PF") po = 3;
				else if (avg.m_actual[player].GetPos() == " C") po = 4;


				pun[0][0] = 9; pun[0][1] = 1; pun[0][2] = 9;
				pun[1][0] = 8; pun[1][1] = 3; pun[1][2] = 8;
				pun[2][0] = 7; pun[2][1] = 5; pun[2][2] = 7;
				pun[3][0] = 5; pun[3][1] = 7; pun[3][2] = 5;
				pun[4][0] = 4; pun[4][1] = 8; pun[4][2] = 4;

				int tMov = dMov - (pun[po][0] - pun[m_position_ball_handler - 1][0]);
				int tPost = dPost - (pun[po][1] - pun[m_position_ball_handler - 1][1]);
				int tPen = dPen - (pun[po][2] - pun[m_position_ball_handler - 1][2]);
				if (tMov < 1) tMov = 1;
				if (tPost < 1) tPost = 1;
				if (tPen < 1) tPen = 1;


				int total = tMov + tPen + tPost;
				typeShot = OUTSIDE;
				int shot = IntRandom(total);
				if (shot > tPen + tMov)
					typeShot = INSIDE;
				else if (shot > tMov)
					typeShot = PENETRATION;
			}

			if (m_toCalled == FALSE && PutBack == FALSE && m_time <= 3)
			{
				forced3 = true;
			}
			int defTeam = m_possesion + 1;
			if (defTeam == 3) defTeam = 1;
			int d = m_position_ball_handler;
			if (m_possesion == 1) d = d + 5;//fix later when changing m_match 
			DefensiveAdjustments(d, dMov, dPen, dPost, Lineup, typeShot);
			int m_astPlayer = AssistPlayer(Lineup, m_ballHandler);
			double better = CurrentLineupBetter(m_position_ball_handler, m_ballHandler, m_astPlayer, m_possesion, Lineup);
			int m_result = 0;
			if (PutBack == TRUE) forced3 = false;//no forced 3 on oreb
			do//repeat if injury occured but injuries are disabled
			{
				if (typeShot == THREE && shotOk == true)
					m_result = 2;
				else
					m_result = Result(player, PutBack, Lineup, m_homeCourt, better, typeShot, forced3);
			} while (m_injury == 1 && m_result == 5);

			//m_result = 5;

			if (m_result == 2 && avg.m_settings.m_check3pt == TRUE) m_result = 1;
			bool assister = (m_astPlayer != false);
			int passReceiver = player; //ball handler also catches pass
			m_score[1] = m_score[1];
			m_score[2] = m_score[2];
			m_time = GetTime();
			m_quarter = GetQuarter();
			bool AndOne = false;
			BOOL ThreeFt = FALSE;
			bool ThreePointer = false;


			int defender = Defense[m_possesion][m_position_ball_handler];

			int MovDef = avg.m_actual[defender].GetMovDef();
			int PenDef = avg.m_actual[defender].GetPenDef();
			int	PostDef = avg.m_actual[defender].GetPostDef();
			int	TransDef = avg.m_actual[defender].GetTransDef();

			AdjustDefenseForGamePlan(avg.m_actual[defender], MovDef, PenDef, PostDef, TransDef);



			if (m_possesion == 2) current_team = m_visitorIndex - 1;
			else if (m_possesion == 1) current_team = m_homeIndex - 1;

			add = 0;
			if ((avg.m_coach[current_team].m_coachOD == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachOD == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachOD == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachOD == 1) add = -1;
			MovDef = MovDef + add;

			add = 0;
			if ((avg.m_coach[current_team].m_coachPD == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachPD == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachPD == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachPD == 1) add = -1;
			PenDef = PenDef + add;

			add = 0;
			if ((avg.m_coach[current_team].m_coachID == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachID == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachID == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachID == 1) add = -1;
			PostDef = PostDef + add;

			add = 0;
			if ((avg.m_coach[current_team].m_coachFD == 4 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachFD == 5) add = 1;
			else if ((avg.m_coach[current_team].m_coachFD == 2 && adj_for_coach == 1)
				|| avg.m_coach[current_team].m_coachFD == 1) add = -1;
			TransDef = TransDef + add;


			double factor = 1 + avg.m_actual[player].GetGameMinPerGame() / 96;
			double defDiff = 0;
			int ratingsTotal = Mov + Pen + Post;
			double fo = 5, fd = 5, fp = 5;
			if (m_position_ball_handler == 1) { fo = 3 / 2 * factor; fd = 9 / 2 * factor; fp = 9 / 2 * factor; }
			else if (m_position_ball_handler == 2) { fo = 3 * factor; fd = 6 * factor; fp = 3 * factor; }
			else if (m_position_ball_handler == 3) { fo = 3 * factor; fd = 6 * factor; fp = 3 * factor; }
			else if (m_position_ball_handler == 4) { fo = 3 * factor; fd = 4 * factor; fp = 5 * factor; }
			else if (m_position_ball_handler == 5) { fo = 3 * factor; fd = 3 * factor; fp = 6 * factor; }

			double Difference = (((double)Mov - fo) * (double)Mov + ((double)Pen - fd) * (double)Pen + ((double)Post - fp) * (double)Post);
			double Diff = double(Difference) / double(ratingsTotal);

			if (originalShot == FASTBREAK) defDiff = 5 - double(TransDef);
			else if (typeShot == OUTSIDE || typeShot == THREE)
				//			defDiff = (double(dMov)-double(MovDef));		
				defDiff = (double(dMov) - double(Diff) - double(MovDef));
			else if (typeShot == PENETRATION)
				//			defDiff = (double(dPen)-double(PenDef));
				defDiff = (double(dPen) - double(Diff) - double(PenDef));
			else if (typeShot == INSIDE)
				//			defDiff = (double(dPost)-double(PostDef));
				defDiff = (double(dPost) - double(Diff) - double(PostDef));
			if (forced3 == true && m_result == 2)
				defDiff = defDiff - 4;//use higher defense rating for forced 3		
			defDiff = defDiff + defDiff * ((m_gameType == PLAYOFF) * .25);	//20% increase in defense effect in playoff

			if (originalShot == FASTBREAK && PutBack == FALSE)
			{
				CString team = m_team_names[m_possesion];
				int fbPasser = Lineup[m_possesion][m_astPlayer];
				m_displayString = Fastbreak(player, fbPasser, team);
				FillPbp(m_displayString);

			}


			if (int_foul == true) m_result = 3;

			if (m_result == 1)
			{

				double tempPct = 0;

				int FgPct = avg.m_actual[player].GetGameAdjustedFgPct();
				if (m_homeCourt == TRUE)
				{
					FgPct = FgPct + int(m_hca * 10 * 8 / 3) * (m_possesion * 2 - 3);
				}
				//		if(m_position_ball_handler == 1) defDiff = defDiff - 1;//weaker defenders 
				//		defDiff = defDiff - 1;//weaker defenders 
				if (PutBack == TRUE)
					tempPct = double(avg.m_actual[player].GetGameFgPct()) * 4 / 3;
				else
				{
					double f = (avg.m_avg_fga[0] * 5) / 5;
					tempPct = double(FgPct) + (defDiff / 2 / (avg.m_avg_fga[0] * 5 / 5) * 1000);
				}

				if (m_quarter >= 4 && abs(m_score[1] - m_score[2]) <= 5)
					tempPct = tempPct * (.98 + (double)avg.m_actual[player].m_clutch / 100);



				FgPct = int(tempPct);
				int Fga = int(avg.m_actual[player].GetGameFgaPer48Min() + //used for consistency cells
					avg.m_actual[player].GetGameAdjustedTfgaPer48Min());
				double blocks =
					CurrentLineupBlocks(m_possesion, Lineup, avg.m_avg_blk[0] * 5);
				double AdjustedFgPct = // adjust fgpct based on opponents blocking ability
					double(FgPct) / 1000 + (avg.m_avg_blk[0] * 5 - blocks) / 2 / (avg.m_avg_fga[0] * 5);//avg fga in game
				double betterPct = better / 4 / avg.m_actual[player].GetGameFgaPer48Min();
				//		double betterPct = 0;
				//if (betterPct > 3)
				//{
					//betterPct = 3;
				//}
				AdjustedFgPct = AdjustedFgPct + betterPct;
				//betterPct = 0;
				//AdjustedFgPct = AdjustedFgPct * (1 + betterPct);
				FgPct = int(AdjustedFgPct * 1000);
				bool Fgm = FieldGoalAttemptGame(FgPct, Fga, player, m_numbers);
				if (PutBack == FALSE && assister == true)
					Passer(m_astPlayer, passReceiver, Fgm);
				if (Fgm == TRUE)
				{
					double n = Random(1);
					if (n < .05) { m_result = 3; AndOne = TRUE; }

					avg.m_actual[player].SetGameFgm();
					avg.m_actual[player].SetGameFga();
					int te = GetTeamWithBall();
					avg.m_actual[1440 + te].SetGameFgm();
					avg.m_actual[1440 + te].SetGameFga();

					//if(m_possesion == 1) m_team = m_visitor;
					//else if(m_possesion == 2) m_team = m_home;
					m_team = m_team_names[m_possesion];
					m_displayString = FieldGoalAttempt(typeShot,
						Fgm, PutBack,
						player,
						AndOne,
						Three, Rebounder_Same_As_Shooter, block);
					FillPbp(m_displayString);


					if (PutBack == FALSE && assister == true)
						DisplayAssistCommentary(m_astPlayer);
					PutBack = FALSE;
					m_score[m_possesion] = m_score[m_possesion] + 2;
					if (AndOne == FALSE) PossesionChange();
				}
				else
				{
					ThreePointer = false;
					bool Blocked = CEngine::Blocker(player, ThreePointer);


					block = Blocked;

					//avg.m_actual[player].SetGameFgm();
					avg.m_actual[player].SetGameFga();
					int te = GetTeamWithBall();
					//avg.m_actual[1440 + te].SetGameFgm();
					avg.m_actual[1440 + te].SetGameFga();




					if (Blocked == FALSE)
					{
						m_displayString = FieldGoalAttempt(typeShot,
							Fgm, PutBack,
							player,
							AndOne,
							Three, Rebounder_Same_As_Shooter, block);
						FillPbp(m_displayString);
					}

					PutBack = Rebounder(player, Rebounder_Same_As_Shooter, block);
				}
			}
			if (m_result == 2 && PutBack == FALSE)
			{
				double tempPct = 0;
				int TfgPct = avg.m_actual[player].GetGameTfgPct();
				//	if(m_position_ball_handler == 2 || m_position_ball_handler == 3) defDiff = defDiff - 1;//weaker defenders at sg and sf
				double f = avg.m_avg_fga[0] * 5 / 5 * 3 / 2;
				tempPct = double(TfgPct) + (defDiff / 2 / f * 1000);//change 1000 to 1500 for more 3 fg pct defense impact???
				TfgPct = int(tempPct);
				if (m_homeCourt == TRUE)
					TfgPct = TfgPct + int(m_hca * 10 * 8 / 3) * (m_possesion * 2 - 3);
				double blocks =
					CurrentLineupBlocks(m_possesion, Lineup, avg.m_avg_blk[0] * 5);
				double AdjustedTfgPct = // adjust fgpct based on opponents blocking ability
					double(TfgPct) / 1000 + (avg.m_avg_blk[0] * 5 - blocks) / 2 / (f * 5);
				TfgPct = int(AdjustedTfgPct * 1000);
				int Fga = int(avg.m_actual[player].GetGameAdjustedFgaPer48Min() +
					avg.m_actual[player].GetGameAdjustedTfgaPer48Min());
				bool Tfgm = FieldGoalAttemptGame(TfgPct, Fga, player, m_numbers);
				//		bool Tfgm = ThreePtFieldGoalAttempt(TfgPct);
				if (assister == true) Passer(m_astPlayer, passReceiver, Tfgm);
				if (Tfgm == TRUE)
				{
					double n = Random(1);
					if (n < .01) { m_result = 3; AndOne = TRUE; }
					m_displayString = DisplayThreePtFieldGoalAttempt(Tfgm,
						player, AndOne);

					FillPbp(m_displayString);


					if (assister == true)
						DisplayAssistCommentary(m_astPlayer);



					avg.m_actual[player].SetGameTfgm();
					avg.m_actual[player].SetGameTfga();
					int te = GetTeamWithBall();
					avg.m_actual[1440 + te].SetGameTfgm();
					avg.m_actual[1440 + te].SetGameTfga();


					m_score[m_possesion] = m_score[m_possesion] + 3;
					if (AndOne == FALSE) PossesionChange();
				}
				else
				{
					ThreePointer = true;
					bool Blocked = CEngine::Blocker(player, ThreePointer);
					if (Blocked == FALSE)
					{
						m_displayString = DisplayThreePtFieldGoalAttempt(Tfgm,
							player,
							AndOne);
						FillPbp(m_displayString);
					}


					block = Blocked;
					double n = Random(1);
					if (n < .01) { m_result = 3; ThreeFt = TRUE; }
					else {


						//			avg.m_actual[player].SetGameTfgm();
						avg.m_actual[player].SetGameTfga();
						int te = GetTeamWithBall();
						//			avg.m_actual[1440 + te].SetGameFgm();
						avg.m_actual[1440 + te].SetGameTfga();



					}


					if (ThreeFt == FALSE) PutBack = Rebounder(player, Rebounder_Same_As_Shooter, block);
					Three = true;
				}
			}
			if (m_result == 3)
			{
				int typeShot = 0;
				m_sub_ok = true;
				if (PutBack == FALSE && assister == true && AndOne == FALSE && ThreeFt == FALSE)
					Passer(m_astPlayer, passReceiver, FALSE);
				bool InTheAct = Random(1) > .5 || AndOne == TRUE || ThreeFt == TRUE;
				if (int_foul == true) InTheAct = false;

				if (AndOne == FALSE && ThreeFt == FALSE && InTheAct == TRUE)
				{
					m_displayString = FieldGoalAttempt(typeShot,
						FALSE, PutBack,
						player,
						AndOne,
						Three, Rebounder_Same_As_Shooter, block);
					FillPbp(m_displayString);
				}

				int m_pfPlayer = 0; //Personal Foul
				PossesionChange();
				PutBack = FALSE;
				m_pfPlayer = PfPlayer(m_possesion, Lineup);
				int Pfplayer = Lineup[m_possesion][m_pfPlayer];

				m_teamFouls[m_possesion] = m_teamFouls[m_possesion] + 1;

				avg.m_actual[Pfplayer].SetGamePf();
				//			avg.m_actual[player].SetGameFga();
				int te = GetTeamWithBall();
				avg.m_actual[1440 + te].SetGamePf();
				//			avg.m_actual[1440 + te].SetGameFga();

				m_displayString = Pf(player, avg.m_actual[Pfplayer].GetLastName(), avg.m_actual[Pfplayer].GetGamePf(), AndOne, InTheAct, ThreePointer, false);
				FillPbp(m_displayString);


				AutoSub();

				if (avg.m_actual[Pfplayer].GetGamePf() >= 6 && m_auto_sub[m_possesion] == FALSE)
				{
					m_must_sub[m_possesion] = Pfplayer;
				}

				int m_foulingTeam = m_possesion;
				CString m_foulingTeamName = m_team_names[m_possesion];
				m_displayString = FreeThrowType(InTheAct, m_teamFouls[m_possesion], m_foulingTeamName, assister, PutBack);
				FillPbp(m_displayString);


				PossesionChange();

				if (ThreeFt == TRUE && avg.m_settings.m_check3ft == FALSE) //Fouled while shooting 3 shoot xtra ft
				{
					int FtPct = avg.m_actual[player].GetGameFtPct();
					bool Ftm = FreeThrowAttemptGame(FtPct, player);//Ft 1
					m_displayString = FreeThrowAttempt(Ftm,
						PutBack, player,
						"1st");
					FillPbp(m_displayString);




					if (Ftm == TRUE)
					{

						avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();

						m_score[m_possesion] = m_score[m_possesion] + 1;
						m_sub_ok = true;
					}
					else
					{

						//				avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						//				avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();
						m_sub_ok = false;




					}
				}


				if (InTheAct == TRUE || m_teamFouls[m_foulingTeam] >= 5
					|| AndOne == TRUE || ThreeFt == TRUE) //Fouled while shooting or bonus or 1 FT after FG or 3ft
				{
					int FtPct = avg.m_actual[player].GetGameFtPct();
					bool Ftm = FreeThrowAttemptGame(FtPct, player);//Ft 1

					if (Ftm == TRUE)
					{

						avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();

						m_sub_ok = true;

						m_score[m_possesion] = m_score[m_possesion] + 1;
						if (AndOne == TRUE)
						{
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"extra");
							FillPbp(m_displayString);

							PossesionChange();
						}


					}
					else
					{


						//				avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						//				avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();

						m_sub_ok = false;



						if (AndOne == TRUE)
						{
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"bonus");
							FillPbp(m_displayString);


							PutBack = Rebounder(player, Rebounder_Same_As_Shooter, block);// rebound xtra FT if missed
						}
					}
					if (AndOne == FALSE)
					{
						if (ThreeFt == TRUE)
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"2nd");
						else
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"1st");

						FillPbp(m_displayString);


						Ftm = FreeThrowAttemptGame(FtPct, player);//Ft2
						if (ThreeFt == TRUE)
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"3rd");

						else
							m_displayString = FreeThrowAttempt(Ftm,
								PutBack, player,
								"2nd");

						FillPbp(m_displayString);


					}
					if (Ftm == TRUE && AndOne == FALSE)
					{


						avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();
						m_sub_ok = true;

						m_score[m_possesion] = m_score[m_possesion] + 1;
						PossesionChange();
					}
					else if (AndOne == FALSE)
					{

						m_sub_ok = false;

						//	avg.m_actual[player].SetGameFtm();
						avg.m_actual[player].SetGameFta();
						int te = GetTeamWithBall();
						//	avg.m_actual[1440 + te].SetGameFtm();
						avg.m_actual[1440 + te].SetGameFta();



						PutBack = Rebounder(player, Rebounder_Same_As_Shooter, block);
					}
				}
			}
			if (m_result == 4 && PutBack == FALSE)
			{
				bool offFoul = Random(1) < .1;



				avg.m_actual[player].SetGameTo();
				if (offFoul == true) avg.m_actual[player].SetGamePf();
				int te = GetTeamWithBall();
				avg.m_actual[1440 + te].SetGameTo();
				if (offFoul == true) avg.m_actual[1440 + te].SetGamePf();


				bool Stolen = false;
				if (offFoul == false) Stolen = Stealer(player);
				if (Stolen == FALSE)
				{
					AutoSub();
					m_displayString = Turnover(player, offFoul);
					FillPbp(m_displayString);
					m_sub_ok = true;


				}
				if (offFoul == true)
				{
					m_displayString = Pf(player, avg.m_actual[player].GetLastName(), avg.m_actual[player].GetGamePf(), AndOne, false, ThreePointer, offFoul);
					FillPbp(m_displayString);

					AutoSub();


					if (avg.m_actual[player].GetGamePf() >= 6 && m_auto_sub[m_possesion] == FALSE)
					{
						m_must_sub[m_possesion] = player;
					}



					/*			if(m_playerStats.GetPf() >= 6 && m_possesion == VISITOR && m_autoSubVisitor == FALSE)
								{
									bool autoplay = false;
									if(m_simulate == TRUE) autoplay = true;
									m_simulate = FALSE;
									OnPlayersSubstitute();
									if(autoplay == true) m_simulate = TRUE;
								}
								else if(m_playerStats.GetPf() >= 6 	&& m_possesion == HOME && m_autoSubHome == FALSE)
								{
									bool autoplay = false;
									if(m_simulate == TRUE) autoplay = true;
									m_simulate = FALSE;
									OnPlayersSubstitute();
									if(autoplay == true) m_simulate = TRUE;
								}*/

				}
				PossesionChange();
			}
			if (m_result == 5 && PutBack == FALSE)
			{
				//injury (i = games out);
				m_toOk = true;
				int injuryRating = avg.m_actual[m_ballHandler].GetGameInjuryRating();
				double adjInjury = sqrt(double(injuryRating));
				double factor1 = adjInjury * 2 / 9;
				double factor2 = factor1 + adjInjury * 2 / 9 * 2 / 3;
				double factor3 = factor2 + adjInjury * 2 / 9 * 2 / 3 * 2 / 6;
				double factor4 = factor3 + adjInjury * 2 / 9 * 2 / 3 * 2 / 9 * 2 / 6;

				double i = Random(adjInjury);
				if (i <= factor1)
					i = i * 3;
				else if (i <= factor2)
					i = i * 9;
				else if (i <= factor3)
					i = i * 27;
				else if (i <= factor4)
					i = i * 81;
				int g = int(i) + 1;

				if (g < 1)
					g = 1;
				else if (g > 160)
					g = 160;


				if (avg.m_settings.m_injury_prompt > 0 && avg.m_settings.m_injury_prompt <= g - 1 && m_possesion == 1 && avg.m_settings.m_player_gm[m_visitorIndex - 1] == "Player")
					m_injury_notify = m_visitorIndex - 1;
				else if (avg.m_settings.m_injury_prompt > 0 && avg.m_settings.m_injury_prompt <= g - 1 && m_possesion == 2 && avg.m_settings.m_player_gm[m_homeIndex - 1] == "Player")
					m_injury_notify = m_homeIndex - 1;


				int days_missed = int((double)g * 2.25 - Random(1));
				avg.m_actual[m_ballHandler].SetInjury(days_missed);

				if (g > 1)
				{
					bool dis = avg.m_actual[m_ballHandler].Disabled(g);

					int team = m_visitorIndex;
					if (m_possesion == 2) team = m_homeIndex;

					if (m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
					{
						CString desc = SetInjuryString(g, avg.m_actual[m_ballHandler].m_pos);
						avg.m_actual[player].m_injury_desc = desc;
						WriteInjury(team, avg.m_actual[player].GetID(), days_missed, desc);


						m_injury_string[m_injury_count].Format("%16s %d", avg.m_actual[m_ballHandler].m_name, days_missed);
						if (m_injury_count < 9) m_injury_count = m_injury_count + 1;

					}
				}
				injury = true;
				m_displayString = Injury(m_ballHandler, g);
				m_sub_ok = true;
				FillPbp(m_displayString);

				if (m_auto_sub[orig_poss] == FALSE)
				{

					m_must_sub[orig_poss] = m_ballHandler;
				}

				m_time = m_time - 1;
				AutoSub();
			}


		} while (PutBack == TRUE);

		if (m_must_sub[m_possesion] > 0)
			m_sub_ok = true;


		//	if(injury == false) SetTime(PutBack, originalShot);
		SetTime(PutBack, originalShot);
		if (m_quarter_ended == true //end of quarter sub time
			&& GetQuarter() > 1)
		{
			m_sub_ok = true;
			if (m_firstPossesion == 1) m_firstPossesion = 2;
			else if (m_firstPossesion == 2) m_firstPossesion = 1;

			m_possesion = m_firstPossesion;


			CString eoq;
			m_fbChance = false;
			int q = GetQuarter();
			if (q == 2)
			{
				eoq = "*** End of the 1st Quarter ***\n";
				m_quarter_score[1][1] = m_score[1];
				m_quarter_score[2][1] = m_score[2];
			}
			else if (q == 3)
			{
				eoq = "*** End of the 1st Half ***\n";
				m_quarter_score[1][2] = m_score[1] - m_quarter_score[1][1];
				m_quarter_score[2][2] = m_score[2] - m_quarter_score[2][1];
			}
			else if (q == 4)
			{
				eoq = "*** End of the 3rd Quarter ***\n";
				m_quarter_score[1][3] = m_score[1] -
					(
						m_quarter_score[1][1] +
						m_quarter_score[1][2]
						);

				m_quarter_score[2][3] = m_score[2] -
					(
						m_quarter_score[2][1] +
						m_quarter_score[2][2]
						);
			}

			m_displayString = eoq;
			FillPbp(m_displayString);

			AutoSub();

			if (GetTime() == 300)
			{
				m_toVisitor = 3;
				m_toHome = 3;
			}

			else if (GetQuarter() == 3)//set stamina to max for each player
			{
				m_toVisitor20 = 1;
				m_toHome20 = 1;
				for (int i = 1; i <= 60; i++)
				{
					int pl = m_playing_players_list[i];
					int staminaRating = avg.m_actual[pl].GetGameStamina();
					avg.m_actual[pl].SetGameCurrentStamina(staminaRating);
				}
			}
			else if (GetQuarter() == 4)
			{
				m_toVisitor = 4;
				m_toHome = 4;
			}

			m_teamFouls[1] = 0;
			m_teamFouls[2] = 0;
		}

		if (GetTime() == 300 //end of game 
			&& GetQuarter() > 4
			&& m_score[1] != m_score[2] && m_game_saved == false)
		{


			CString eoq = "*** End of the Game ***\n";

			m_displayString = eoq;
			FillPbp(m_displayString);



			if (m_quarter_score[1][4] == 0)//4th quarter not OT
			{
				m_quarter_score[1][4] = m_score[1] -
					(
						m_quarter_score[1][1] +
						m_quarter_score[1][2] +
						m_quarter_score[1][3]
						);

				m_quarter_score[2][4] = m_score[2] -
					(
						m_quarter_score[2][1] +
						m_quarter_score[2][2] +
						m_quarter_score[2][3]
						);
			}
			else //ot
			{
				m_quarter_score[1][5] = m_score[1] -
					(
						m_quarter_score[1][1] +
						m_quarter_score[1][2] +
						m_quarter_score[1][3] +
						m_quarter_score[1][4]
						);
				m_quarter_score[2][5] = m_score[2] -
					(
						m_quarter_score[2][1] +
						m_quarter_score[2][2] +
						m_quarter_score[2][3] +
						m_quarter_score[2][4]
						);
			}



			SetMinutesPlayedStat();
			m_gameOver = true;
			if (m_gameType == LEAGUE || m_gameType == SINGLE_TEAM)
				avg.UpdateStandings(m_visitorIndex - 1, m_score[1], m_homeIndex - 1, m_score[2]);
			if (m_gameType == LEAGUE || m_gameType == SINGLE_TEAM || m_gameType == ALLSTAR || m_gameType == ROOKIE || m_gameType == PLAYOFF)
			{

				int i = avg.m_sched.m_currentMonth;
				int j = avg.m_sched.m_currentDay;
				int k = avg.m_sched.m_currentGame;
				int game = avg.m_sched.m_schedule[i][j][k];
				int score = m_score[VISITOR] * 1000 + m_score[HOME];
				avg.m_sched.m_game_score[i][j][k] = score;


				if (m_gameType == PLAYOFF)
				{
					bool more_games = false;
					for (int x = 0; x <= 16; x++)
					{
						int game = avg.m_sched.m_schedule[12][j][x];
						int score = avg.m_sched.m_game_score[12][j][x];
						if (score == 0 && game > 0) more_games = true;
					}
					if (more_games == false)//day ended
					{
						//play unhealthy for one game ? May want to make more better :)
						for (int i = 0; i <= 1600; i++)
						{
							int sl = i;
							int g = avg.m_actual[sl].GetInjury() - 3;//3 days
							if (g == 0 && avg.m_actual[sl].Random(1) >= (double)avg.m_actual[sl].m_games / (double)avg.m_hi_g[0])
								avg.m_actual[sl].m_health = 90 + avg.m_actual[sl].IntRandom(10);
							else
								avg.m_actual[sl].m_health = 100;
							if (avg.m_actual[sl].m_health >= 100) avg.m_actual[sl].m_injury_desc = "";
							if (g < 0) g = 0;
							avg.m_actual[sl].SetInjury(g);
						}
					}
				}

			}

			m_game_saved = true;
			SaveCurrentGameData();
			if (m_gameType == EXHIBITION) m_simulate = FALSE;

		}
		else if (GetTime() == 300 //OT
			&& GetQuarter() > 4)
		{
			m_quarter_score[1][4] = m_score[1] -
				(
					m_quarter_score[1][1] +
					m_quarter_score[1][2] +
					m_quarter_score[1][3]
					);

			m_quarter_score[2][4] = m_score[2] -
				(
					m_quarter_score[2][1] +
					m_quarter_score[2][2] +
					m_quarter_score[2][3]
					);

		}

	}
	else
	{
		m_lineupSet = true;
		m_possesion = JumpBall();
		m_firstPossesion = m_possesion;
		m_sub_ok = false;
		bool shotOk = false;
		bool forced3 = false;
		m_ballHandler =
			BallHandler(0, m_possesion, Lineup, m_homeCourt, shotOk, AUTO, forced3);

		int player = m_ballHandler;
		CString playerName = avg.m_actual[player].GetLastName();

		m_teamName = m_team_names[m_possesion];





		m_displayString = DisplayJumpBall(playerName);






		FillPbp(m_displayString);






	}
	m_visitorTo = false;
	m_homeTo = false;
	m_visitorTo20 = false;
	m_homeTo20 = false;
	m_toCalled = false;
	m_play_over = true;
	FillPbp("");



}


void CEngine::AutoSub()
{



	SetMinutesPlayedStat();


	bool problem = false;

	m_toOk = true;
	int seconds = GetTime();
	int quarter = GetQuarter();
	int time = 720 - seconds + (quarter - 1) * 720;
	if (quarter > 4) time = 2880 + (300 - seconds) + (quarter - 5) * 300;
	int margin = abs(m_score[VISITOR] - m_score[HOME]);
	int minutesLeft = (2880 - time) / 60 + 1;
	if ((margin > 48 && quarter < 4) || (quarter == 4 && margin > ((2880 - time) / 60 + 1) * 2 + 12))
		GarbageTime = TRUE;
	bool catastrophe = false;
	for (int t = 1; t <= 2; t++)
	{

		if (m_auto_sub[t] == FALSE) continue;

		catastrophe = false;
		m_update_lineup = true;
		bool InLineup[61];
		bool starters[961];
		for (int c = 0; c <= 60; c++)
		{
			InLineup[c] = false;
		}
		for (int c = 0; c <= 960; c++)
		{
			starters[c] = false;;
		}

		for (int p = 1; p <= 5; p++)
		{
			int starter = Rotation[t][p][0].Chart;
			starters[starter] = true;
		}

		for (int p = 1; p <= 5; p++)
		{
			Lineup[t][p] = 0;
			bool FoulTrouble1 = FALSE;
			bool FoulTrouble2 = FALSE;
			bool FoulTrouble3 = FALSE;
			bool FoulTrouble4 = FALSE;
			bool FoulTrouble5 = FALSE;
			bool FoulTrouble_top = FALSE;
			bool Injury1 = FALSE;
			bool Injury2 = FALSE;
			bool Injury3 = FALSE;
			bool Injury4 = FALSE;
			bool Injury5 = FALSE;
			bool Injury = FALSE;


			int starter = Rotation[t][p][0].Chart;
			int FirstString = Rotation[t][p][0].Chart;
			int TopString = Rotation[t][p][1].Chart;
			int SecondString = Rotation[t][p][2].Chart;
			int ThirdString = Rotation[t][p][3].Chart;
			int FourthString = Rotation[t][p][4].Chart;
			int FifthString = Rotation[t][p][9].Chart;

			if (SecondString == 0) SecondString = FirstString;
			if (ThirdString == 0) ThirdString = SecondString;
			if (FourthString == 0) FourthString = ThirdString;
			if (GarbageTime == TRUE)
			{
				if (starters[FifthString] == false) FirstString = FifthString;
				else if (starters[FourthString] == false) FirstString = FourthString;
				else if (starters[ThirdString] == false) FirstString = ThirdString;
				else if (starters[SecondString] == false) FirstString = SecondString;
			}

			if (FirstString == 0) FirstString = SecondString;

			bool OK = FALSE;

			//foul trouble top string?

			CPlayer m_topStats = avg.m_actual[TopString];
			int fouls = m_topStats.GetGamePf();
			int injury = m_topStats.GetGameInjury();
			if (injury > 0) Injury = TRUE;
			if (injury > 0 || m_topStats.GetGameCurrentStamina() < 0) Injury = TRUE;//actually FoulTrouble also represents fatigue
			if (fouls >= 2 && quarter == 1) FoulTrouble_top = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble_top = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble_top = TRUE;
			else if (fouls >= 5 && time > 2160 && time <= 2580) FoulTrouble_top = TRUE;
			if (fouls == 6) FoulTrouble_top = TRUE;


			CPlayer m_topStats1 = avg.m_actual[FirstString];
			fouls = m_topStats1.GetGamePf();
			injury = m_topStats1.GetGameInjury();
			if (injury > 0) Injury1 = TRUE;
			if (m_topStats1.GetGameCurrentStamina() < 0)
			{
				Injury1 = TRUE;//actually FoulTrouble also represents fatigue
			}
			if (fouls >= 2 && quarter == 1) FoulTrouble1 = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble1 = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble1 = TRUE;
			else if (fouls >= 5 && time > 2160 && time <= 2580) FoulTrouble1 = TRUE;
			if (Random(1) <= 1 / 15) FoulTrouble1 = FALSE; //computer coach takes chance 
			if (fouls == 6) FoulTrouble1 = TRUE;


			//foul trouble backup?
			CPlayer m_topStats2 = avg.m_actual[SecondString];
			fouls = m_topStats2.GetGamePf();
			injury = m_topStats2.GetGameInjury();
			if (injury > 0) Injury2 = TRUE;
			if (m_topStats2.GetGameCurrentStamina() < 0) Injury2 = TRUE;//actually FoulTrouble also represents fatigue
			if (fouls >= 2 && quarter == 1) FoulTrouble2 = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble2 = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble2 = TRUE;
			else if (fouls >= 5 && time > 2160 && time >= 2580) FoulTrouble2 = TRUE;
			if (Random(1) <= 1 / 15) FoulTrouble2 = FALSE; //computer coach takes chance 
			if (fouls == 6) FoulTrouble2 = TRUE;

			CPlayer m_topStats3 = avg.m_actual[ThirdString];
			fouls = m_topStats3.GetGamePf();
			injury = m_topStats3.GetGameInjury();
			if (injury > 0) Injury3 = TRUE;
			if (m_topStats3.GetGameCurrentStamina() < 0) Injury3 = TRUE;//actually FoulTrouble also represents fatigue
			if (fouls >= 2 && quarter == 1) FoulTrouble3 = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble3 = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble3 = TRUE;
			else if (fouls >= 5 && time > 2160 && time >= 2580) FoulTrouble3 = TRUE;
			if (Random(1) <= 1 / 15) FoulTrouble3 = FALSE; //computer coach takes chance 
			if (fouls == 6) FoulTrouble3 = TRUE;

			//foul trouble 4th String?
			CPlayer m_topStats4 = avg.m_actual[FourthString];
			fouls = m_topStats4.GetGamePf();
			injury = m_topStats4.GetGameInjury();
			if (injury > 0) Injury4 = TRUE;
			if (m_topStats4.GetGameCurrentStamina() < 0) Injury4 = TRUE;//actually FoulTrouble also represents fatigue
			if (fouls >= 2 && quarter == 1) FoulTrouble4 = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble4 = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble4 = TRUE;
			else if (fouls >= 5 && time > 2160 && time >= 2580) FoulTrouble4 = TRUE;
			if (Random(1) <= 1 / 15) FoulTrouble4 = FALSE; //computer coach takes chance 
			if (fouls == 6) FoulTrouble4 = TRUE;

			//foul trouble 5th String?
			CPlayer m_topStats5 = avg.m_actual[FifthString];
			fouls = m_topStats5.GetGamePf();
			injury = m_topStats5.GetGameInjury();
			if (m_topStats5.GetGameCurrentStamina() < 0) Injury5 = TRUE;//actually FoulTrouble also represents fatigue
			if (injury > 0) Injury5 = TRUE;
			if (m_topStats.GetGameCurrentStamina() < 0) FoulTrouble5 = TRUE;//actually FoulTrouble also represents fatigue
			if (fouls >= 2 && quarter == 1) FoulTrouble5 = TRUE;
			else if (fouls >= 3 && time > 720 && time <= 1440) FoulTrouble5 = TRUE;
			else if (fouls >= 4 && time > 1440 && time <= 2160) FoulTrouble5 = TRUE;
			else if (fouls >= 5 && time > 2160 && time >= 2580) FoulTrouble5 = TRUE;
			if (Random(1) <= 1 / 15) FoulTrouble5 = FALSE; //computer coach takes chance 
			if (fouls == 6) FoulTrouble5 = TRUE;

			if ((time <= 240 || (time >= 1380 && time <= 1680)) && FoulTrouble1 == FALSE && Injury1 == FALSE && InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE)
			{
				Lineup[t][p] = FirstString;
				OK = TRUE;
			}
			else if (((time >= 1200 && time <= 1440) || time >= 2580) && FoulTrouble_top == FALSE && Injury == FALSE && InLineup[avg.m_actual[TopString].m_game_stat_slot] != TRUE && GarbageTime != TRUE)
			{
				Lineup[t][p] = TopString;
				OK = TRUE;
			}
			else if (((time >= 1200 && time <= 1440) || time >= 2580) && FoulTrouble1 == FALSE && Injury1 == FALSE && InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE && GarbageTime == TRUE && FirstString != 0)
			{
				Lineup[t][p] = FirstString;
				OK = TRUE;
			}
			//else if(FoulTrouble_top == FALSE && Injury == FALSE && InLineup[avg.m_actual[TopString].m_game_stat_slot] != 0)
			//{
			//	Lineup[t][p] = TopString;				
			//	OK = TRUE;
			//}



			bool filledSlot = false;
			if (OK == FALSE)
			{

				double total = Rotation[t][p][0].Priority +
					Rotation[t][p][2].Priority;
				double n = Random(total);
				double compare1 = Rotation[t][p][0].Priority;
				if (compare1 < 0) compare1 = 0;
				double compare2 = compare1 + Rotation[t][p][2].Priority;
				double compare3 = compare1 + (compare2 - compare1) * 2 / 3;
				double compare4 = compare1 + (compare2 - compare1) * 8 / 9;
				if (Rotation[t][p][3].InRotation != true)
				{
					//give priority to 1st and 2nd string if 3rd string 
					//	not in rotation

					if (InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE && n < compare1 && FoulTrouble1 == FALSE && Injury1 == FALSE)
					{
						Lineup[t][p] = FirstString;
						filledSlot = true;
					}
					else if (InLineup[avg.m_actual[SecondString].m_game_stat_slot] != TRUE && FoulTrouble2 == FALSE && Injury2 == FALSE)
					{
						Lineup[t][p] = SecondString;
						filledSlot = true;
					}
					else if (InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE && FoulTrouble1 == FALSE && Injury1 == FALSE)
					{
						Lineup[t][p] = FirstString;
						filledSlot = true;
					}
				}
				bool fillSlot = false;
				if (filledSlot == false)
				{
					if (n >= compare4 && FoulTrouble4 == FALSE && Injury4 == FALSE
						&& (Rotation[t][p][4].InRotation == true ||
							Random(1) > .9) && InLineup[avg.m_actual[FourthString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = FourthString;

					else if (n >= compare3 && FoulTrouble3 == FALSE && Injury3 == FALSE
						&& (Rotation[t][p][3].InRotation == true ||
							Random(1) > .9) && InLineup[avg.m_actual[ThirdString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = ThirdString;

					else if (n >= compare1 && FoulTrouble2 == FALSE && Injury2 == FALSE
						&& InLineup[avg.m_actual[SecondString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = SecondString;

					else if (InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE && FoulTrouble1 == FALSE && Injury1 == FALSE)

						Lineup[t][p] = FirstString;

					else if (n >= compare4 && FoulTrouble4 == FALSE && Injury4 == FALSE
						&& InLineup[avg.m_actual[FourthString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = FourthString;


					else if (FoulTrouble3 == FALSE && Injury3 == FALSE
						&& InLineup[avg.m_actual[ThirdString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = ThirdString;

					else if (FoulTrouble4 == FALSE && Injury4 == FALSE
						&& InLineup[avg.m_actual[FourthString].m_game_stat_slot] != TRUE)

						Lineup[t][p] = FourthString;

					else if (InLineup[avg.m_actual[FifthString].m_game_stat_slot] != TRUE && FoulTrouble5 == FALSE
						&& Injury5 == FALSE)

						Lineup[t][p] = FifthString;

					else
						fillSlot = true;
				}

				if ((((InLineup[avg.m_actual[FourthString].m_game_stat_slot] == TRUE || FoulTrouble4 == TRUE || Injury4 == TRUE) &&

					(InLineup[avg.m_actual[ThirdString].m_game_stat_slot] == TRUE || FoulTrouble3 == TRUE || Injury3 == TRUE) &&

					(InLineup[avg.m_actual[FifthString].m_game_stat_slot] == TRUE || FoulTrouble5 == TRUE || Injury5 == TRUE) &&

					(InLineup[avg.m_actual[SecondString].m_game_stat_slot] == TRUE || FoulTrouble2 == TRUE || Injury2 == TRUE) &&

					(InLineup[avg.m_actual[FirstString].m_game_stat_slot] == TRUE || FoulTrouble1 == TRUE || Injury1 == TRUE)))

					||

					(fillSlot == true) || Lineup[t][p] == 0)
				{
					if (InLineup[avg.m_actual[FirstString].m_game_stat_slot] != TRUE && m_topStats.GetGamePf() < 6 && m_topStats.GetGameInjury() == 0)
						Lineup[t][p] = FirstString;
					else if (InLineup[avg.m_actual[SecondString].m_game_stat_slot] != TRUE && m_topStats2.GetGamePf() < 6 && m_topStats2.GetGameInjury() == 0)
						Lineup[t][p] = SecondString;
					else if (InLineup[avg.m_actual[ThirdString].m_game_stat_slot] != TRUE && m_topStats3.GetGamePf() < 6 && m_topStats3.GetGameInjury() == 0)
						Lineup[t][p] = ThirdString;
					else if (InLineup[avg.m_actual[FourthString].m_game_stat_slot] != TRUE && m_topStats4.GetGamePf() < 6 && m_topStats4.GetGameInjury() == 0)
						Lineup[t][p] = FourthString;
					else if (InLineup[avg.m_actual[FifthString].m_game_stat_slot] != TRUE && m_topStats5.GetGamePf() < 6 && m_topStats5.GetGameInjury() == 0)
						Lineup[t][p] = FifthString;

				}
			}
			InLineup[avg.m_actual[Lineup[t][p]].m_game_stat_slot] = TRUE;
			//			if(Lineup[t][p] == 0)
			//			{
			//				AfxMessageBox("Bug");
			//			}
		}

		//if lineups contain an empty slot fill emergency player
		bool tragedy = false;
		bool small_emergency = false;
		bool super_emergency = false;
		int emergency = 0;
		int elig = 0;
		bool min_5 = false;
		for (int p = 1; p <= 5; p++)
		{
			elig = 0;
			min_5 = false;

			int player = Lineup[t][p];
			emergency = 0;
			small_emergency = false;
			super_emergency = false;

			if (player == 0)
			{
				small_emergency = true;

				int foulsE = 0, injuryE = 0;

				//any player on depth chart
				for (int i = 1; i <= 15; i++)
				{

					int n = m_visitor_player_offset - 1 + i;
					if (t == 2) n = m_home_player_offset - 1 + i;
					injuryE = avg.m_actual[n].GetGameInjury();
					foulsE = avg.m_actual[n].GetGamePf();
					CString nm = avg.m_actual[n].GetName();
					if (nm == "") continue;
					if (foulsE < 6 && injuryE <= 3 && nm != "") elig = elig + 1;
					for (int slot = 0; slot <= 9; slot++)
					{
						int pl = Rotation[t][p][slot].Chart;
						if (pl == n && pl > 0 && InLineup[avg.m_actual[n].m_game_stat_slot] != TRUE && foulsE < 6 && injuryE <= 3 && nm != "") emergency = pl;
					}
				}
				Lineup[t][p] = emergency;
				InLineup[avg.m_actual[emergency].m_game_stat_slot] = TRUE;
				if (emergency == 0) super_emergency = true;

			}

			if (super_emergency == true)//super emergency
			{

				int foulsE = 0, injuryE = 0;

				//use any player 
				for (int i = 1; i <= 15; i++)
				{
					int n = m_visitor_player_offset - 1 + i;
					if (t == 2) n = m_home_player_offset - 1 + i;

					injuryE = avg.m_actual[n].GetGameInjury();
					foulsE = avg.m_actual[n].GetGamePf();
					CString nm = avg.m_actual[n].GetName();
					if (nm == "") continue;
					if (InLineup[avg.m_actual[n].m_game_stat_slot] != TRUE && foulsE < 6 && injuryE <= 3 && nm != "") emergency = n;

				}
				Lineup[t][p] = emergency;
				InLineup[avg.m_actual[emergency].m_game_stat_slot] = TRUE;
				if (emergency == 0) tragedy = true;

			}

		}
		if (tragedy == true)
		{
			if (elig >= 5)
				min_5 = true;
			else
				problem = true;
			for (int p = 1; p <= 5; p++)
			{
				int foulsE = 0, injuryE = 0;
				Lineup[t][p] = 0;
				for (int i = 1; i <= 15; i++)
				{
					int n = m_visitor_player_offset - 1 + i;
					if (t == 2) n = m_home_player_offset - 1 + i;

					injuryE = avg.m_actual[n].GetGameInjury();
					foulsE = avg.m_actual[n].GetGamePf();

					CString nm = avg.m_actual[n].GetName();
					if (nm == "") continue;
					if (InLineup[avg.m_actual[n].m_game_stat_slot] != TRUE && (foulsE < 6 || min_5 == false) && (injuryE <= 3 || min_5 == false) && nm != "") emergency = n;

				}
				Lineup[t][p] = emergency;
				InLineup[avg.m_actual[emergency].m_game_stat_slot] = TRUE;
				if (emergency == 0) catastrophe = true;

			}
		}
		if (GarbageTime == TRUE || small_emergency == true || super_emergency == true)//swap positions in rare situations     
		{
			if (
				(avg.m_actual[Lineup[t][2]].GetGameAstPer48Min() /
					avg.m_actual[Lineup[t][2]].GetGameToPer48Min())

					>

				(avg.m_actual[Lineup[t][1]].GetGameAstPer48Min() /
					avg.m_actual[Lineup[t][1]].GetGameToPer48Min()))
			{
				int temp = Lineup[t][1];
				Lineup[t][1] = Lineup[t][2];
				Lineup[t][2] = temp;
			}
			if (avg.m_actual[Lineup[t][4]].GetGameBlkPer48Min() <
				avg.m_actual[Lineup[t][3]].GetGameBlkPer48Min())
			{
				int temp = Lineup[t][4];
				Lineup[t][4] = Lineup[t][3];
				Lineup[t][3] = temp;
			}
			if (avg.m_actual[Lineup[t][5]].GetGameDrebPer48Min() <
				avg.m_actual[Lineup[t][4]].GetGameDrebPer48Min())
			{
				int temp = Lineup[t][5];
				Lineup[t][5] = Lineup[t][4];
				Lineup[t][4] = temp;
			}
		}

	}


	for (int t1 = 1; t1 <= 2; t1++)
	{
		int ot = 1;//other team
		if (t1 == 1) ot = 2;
		for (int t2 = 1; t2 <= 5; t2++)
		{
			int p = Lineup[ot][t2];
			if (m_auto_sub[ot] == TRUE)
			{
				Defense[t1][t2] = p;
			}
			int foulsT = avg.m_actual[p].GetGamePf();
			if (foulsT > 6 || p == 0 || problem == true || catastrophe == true)
			{
				m_crash = true;
			}
		}

		if (m_crash == true)
		{
			int in_emergency[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			m_crash = false;
			for (int p = 1; p <= 5; p++)
			{
				int foulsE = 0;
				int emergency = 0;

				for (int i = 1; i <= 15; i++)
				{
					int n = m_visitor_player_offset - 1 + i;
					if (t1 == 2) n = m_home_player_offset - 1 + i;
					foulsE = avg.m_actual[n].GetGamePf();
					CString nm = avg.m_actual[n].GetName();
					if (nm == "") continue;
					if (foulsE < 6 && nm != "" && in_emergency[i] == 0 && emergency == 0)
					{
						emergency = n;
						in_emergency[i] = 1;
					}

				}
				Lineup[t1][p] = emergency;
			}

		}

	}




}













int CEngine::IntRandom(int n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return (int)number + 1;
}

double CEngine::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}


int CEngine::JumpBall()
{
	return IntRandom(2);
}



int CEngine::BallHandler(int ballHandler, int m_possesion, int Lineup[3][6], BOOL m_homeCourt, bool& shotOk, int typeShot, bool& forced3)
{
	CPlayer m_playerRatings;
	double Touches[6];
	Touches[0] = 0;

	if (typeShot == 5 && ballHandler == 0)//Auto3
	{
		double n1 = TeamRatings[m_possesion].GetGameCoachTfgaPer48Min();

		double n2 = TeamRatings[m_possesion].GetGameFgaPer48Min() +
			TeamRatings[m_possesion].GetGameTfgaPer48Min() +
			TeamRatings[m_possesion].GetGameToPer48Min() +
			TeamRatings[m_possesion].GetGameFoulsDrawnPer48Min();

		double number = Random(n2);
		forced3 = (number <= n1);
	}



	//9/20 / 9/25 * 50/45
	int tot_mov = 0;
	int tot_pen = 0;
	int tot_post = 0;
	double shots = 0;
	for (int i = 1; i <= 5; i++)
	{

		int player = Lineup[m_possesion][i];
		tot_mov = tot_mov + avg.m_actual[player].m_movoff;
		tot_pen = tot_pen + avg.m_actual[player].m_penoff;
		tot_post = tot_post + avg.m_actual[player].m_postoff;
		shots = shots + avg.m_actual[player].GetGameAdjustedFgaPer48Min();
	}

	for (int i = 1; i <= 5; i++)
	{
		int player = Lineup[m_possesion][i];
		m_playerRatings = avg.m_actual[player];
		double FoulsDrawn = m_playerRatings.GetGameAdjustedFoulsDrawnPer48Min();
		double To = m_playerRatings.GetGameAdjustedToPer48Min();

		int hi = 0;
		int set = 0;


		if (i == 1)
		{
			hi = m_playerRatings.GetPenOff();
			set = tot_pen;
		}
		else if (i == 2)
		{
			hi = m_playerRatings.GetMovOff();
			set = tot_mov;
		}
		else if (i == 3)
		{
			hi = m_playerRatings.GetMovOff();
			set = tot_mov;
		}
		else if (i == 4)
		{
			hi = m_playerRatings.GetPostOff();
			set = tot_post;
		}
		else if (i == 5)
		{
			hi = m_playerRatings.GetPostOff();
			set = tot_post;
		}


		double adj = (double)hi / ((double)set - (double)hi) / ((double)hi / 20.) * (double)m_playerRatings.GetPrFgp() / avg.m_avg_fgp[i];
		adj = (adj + 1) / 2;
		if (avg.m_settings.m_checkCareer == FALSE) adj = 1;

		double attempts = m_playerRatings.GetGameAdjustedFgaPer48Min();


		if ((attempts / shots) > .3)
		{
			//attempts = shots * .4;
			int d = i;
			if (m_possesion == 1)
			{
				d = d + 5;
			}
			double r = Random(.5);
			m_match[d] = 0;
			if (r < (attempts / shots))
			{
				m_match[d] = 4;
			}
			if ((attempts / shots) > .375)
			{
				attempts = shots * .375;
			}

		}



		if (m_homeCourt == TRUE)
			FoulsDrawn = FoulsDrawn + double(m_possesion * 2. - 3) * m_hca;
		if (m_homeCourt == TRUE)
			To = To - double(m_possesion * 2. - 3) * m_hca;

		double factor = m_playerRatings.GetGameAdjustedTfgaPer48Min() / attempts * 1;
		if (forced3 == true)//THREE AUTO
			Touches[i] = Touches[i - 1] + m_playerRatings.GetGameAdjustedTfgaPer48Min() + To * factor;
		else
			Touches[i] = Touches[i - 1] +
			attempts * adj +
			m_playerRatings.GetGameAdjustedTfgaPer48Min() + //add * adj here ???
			FoulsDrawn * adj + To * adj;
	}

	int ineligible = 0;//save position number in case player refuses to "shoot" he cant

	if (forced3 == true) TeamRatings[m_possesion].ReduceGameCoachTfgaPer48Min(2);
	if (ballHandler > 0)
	{
		int player = ballHandler;
		double n = avg.m_actual[player].GetGameCoachFgaPer48Min();
		double temp = (avg.m_actual[player].GetGameAdjustedFgaPer48Min() + avg.m_actual[player].GetGameAdjustedTfgaPer48Min() +
			avg.m_actual[player].GetGameAdjustedFoulsDrawnPer48Min() + avg.m_actual[player].GetGameAdjustedToPer48Min()) * 3;

		if (typeShot == 5)
		{
			double To = m_playerRatings.GetGameAdjustedToPer48Min();
			if (m_homeCourt == TRUE)	To = To - double(m_possesion * 2. - 3) * m_hca;
			n = avg.m_actual[player].GetGameCoachTfgaPer48Min();
			temp = avg.m_actual[player].GetGameTfgaPer48Min() * 4;
			avg.m_actual[player].ReduceGameCoachTfgaPer48Min(1);
		}

		if (m_visitorTo == true)// after to better chance for called shot
		{
			n = n * 3;
			m_visitorTo = false;
		}
		else if (m_visitorTo20 == true)
		{
			n = n * 2;
			m_visitorTo20 = false;
		}
		else if (m_homeTo == true)
		{
			n = n * 3;
			m_homeTo = false;
		}
		else if (m_visitorTo20 == true)
		{
			n = n * 2;
			m_homeTo20 = false;
		}
		int team_index = GetTeamWithBall();

		double f = 0;
		double auto_type = 0;
		if (typeShot == 6) auto_type = IntRandom(3);
		if (typeShot == 1 || auto_type == 1)
			f = (double(avg.m_coach[team_index].m_coachO) - 3) / 100;
		else if (typeShot == 2 || auto_type == 2)
			f = (double(avg.m_coach[team_index].m_coachP) - 3) / 100;
		else if (typeShot == 3 || auto_type == 3)
			f = (double(avg.m_coach[team_index].m_coachI) - 3) / 100;

		n = n * (1 + f * 10);
		if (n > temp) n = temp;//n after to can be no higher than original coach fga



		double number = Random(Touches[5]);
		if (number > n)
		{
			if (typeShot != 5) ineligible = ballHandler;
			ballHandler = 0;
			shotOk = false;
		}
		else shotOk = true;
		avg.m_actual[player].ReduceGameCoachFgaPer48Min();
	}

	do
	{
		int team_index = m_possesion;
		double number = Random(Touches[5]);
		for (int i = 1; i <= 5; i++)
		{
			if (number <= Touches[i] && number > Touches[i - 1] &&
				ballHandler == 0 && Lineup[team_index][i] != ineligible)
			{
				ballHandler = Lineup[team_index][i];
				m_position_ball_handler = i;
			}
		}
	} while (ballHandler == 0);
	return ballHandler;
}


int CEngine::Result(int player, bool PutBack,
	int Lineup[3][6], BOOL m_homeCourt,
	double better, int typeShot, bool forced3)
{
	double avgStl = avg.m_avg_stl[0] * 5;
	double avgTo = avg.m_avg_to[0] * 5;
	double avg_pf = avg.m_avg_pf[0] * 5;
	double Touches = 0;
	int result = 0;
	int team = m_possesion;

	CPlayer m_player = avg.m_actual[player];
	double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
	if (fatigueFactor > 1) fatigueFactor = 1;
	double playerTo = m_player.GetGameAdjustedToPer48Min() * (2 - fatigueFactor);

	double lineupStl = CurrentLineupSteals(Lineup);
	double lineupTo
		= CurrentLineupTurnovers(Lineup, m_homeCourt);

	double fo_dr = 0;
	double fga_g = 0;
	//	double fo_dr_adj = 0;//adjust for intensity
	for (int i = 1; i <= 5; i++)
	{
		int plyr = Lineup[team][i];

		//		double factor = (100 - (double)avg.m_actual[plyr].m_offensive_intensity * 20) / 100;
		//		fo_dr_adj = fo_dr_adj + avg.m_actual[plyr].GetGameAdjustedFoulsDrawnPer48Min() * factor;//adds what the fo_dr was before the game plan adjustment
		fo_dr = fo_dr + avg.m_actual[plyr].GetGameAdjustedFoulsDrawnPer48Min();
		fga_g = fga_g + avg.m_actual[plyr].GetGameAdjustedFgaPer48Min() + avg.m_actual[plyr].GetGameAdjustedTfgaPer48Min() + avg.m_actual[plyr].GetGameAdjustedToPer48Min();
	}
	double fds = m_player.GetGameAdjustedFoulsDrawnPer48Min();
	double f_f = TeamRatings[GetPossesionOfTeamWithoutBall()].GetGamePfPer48Min() * 4. / 5.;
	//	double avg_f = (avg.m_avg_pf[0] * 5. * (4./5.)) * (fo_dr / fo_dr_adj);
	//	double avg_f = (avg.m_avg_pf[0] * 5. * (4./5.) + avg.m_avg_fga_t[0]);
	//	double avg_f = avg.m_avg_pf[0] / (avg.m_avg_fta[0] + avg.m_avg_fga_t[0] + avg.m_avg_to[0]);
	double avg_f = (fga_g / 5) / ((avg.m_avg_fta[0] + avg.m_avg_fga_t[0] + avg.m_avg_to[0]) * 4 / 5);
	f_f = avg_f * f_f;
	avg_f = (avg.m_avg_pf[0] * 4 / 5) * avg_f * 5;


	if (f_f < (avg_f)) f_f = (avg_f - 1);
	else if (f_f > (avg_f + 1)) f_f = (avg_f + 1);

	fds = fds * (f_f / fo_dr);
	//fds = fds * (fo_dr / fo_dr_adj); 



	double FoulsDrawn = fds * fatigueFactor;
	if (m_homeCourt == TRUE)
		FoulsDrawn = FoulsDrawn + double(team * 2. - 3.) * m_hca;
	if (m_homeCourt == TRUE)
		playerTo = playerTo - double(team * 2. - 3.) * m_hca;
	//adjust Turnovers based on opponents steals
	playerTo =
		playerTo + playerTo / lineupTo * (lineupStl - avgStl * 5 / 6); // avg steals per game 
	playerTo = playerTo - better / 4 / (avgTo / 5) * playerTo;

	FoulsDrawn = FoulsDrawn + better / 4;
	if (FoulsDrawn <= 0) FoulsDrawn = Random(.030);
	if (playerTo <= 0) playerTo = Random(.60);
	if (forced3 == true && m_player.GetGameAdjustedTfgaPer48Min() > 0)
	{
		double factor = m_player.GetGameAdjustedTfgaPer48Min() / m_player.GetGameAdjustedFgaPer48Min() * 1.;
		playerTo = playerTo * factor;
	}
	Touches =
		m_player.GetGameAdjustedFgaPer48Min() +
		m_player.GetGameAdjustedTfgaPer48Min() +
		FoulsDrawn + playerTo;


	do
	{
		double number = Random(Touches);
		result = IntRandom(5);
		double limit1 = m_player.GetGameAdjustedFgaPer48Min();
		double limit2 = limit1 + m_player.GetGameAdjustedTfgaPer48Min();
		if (number <= limit1) result = 1;
		if (number <= limit2 && number > limit1) result = 2;
		limit1 = limit2;
		limit2 = limit1 + FoulsDrawn;
		if (number <= limit2 && number > limit1) result = 3;
		limit1 = limit2;
		limit2 = limit1 + playerTo;
		if (number <= limit2 && number > limit1) result = 4;
	} while ((PutBack == TRUE && (result == 2 || result == 4))
		|| (typeShot == 5 && result == 2)
		|| (forced3 == true && result != 2 && result != 4));

	//int number = IntRandom(1025);//683
//	int number = IntRandom(1537);//683
	int number = IntRandom(1793);//683
	int injury = m_player.GetGameInjuryRating();
	double adjInjury = sqrt(double(injury));
	if (number <= adjInjury && PutBack == FALSE && avg.m_settings.m_injury > 0)
	{
		result = 5;
	}
	return result;
}

bool CEngine::FieldGoalAttemptGame(int FgPct, int Fga, int player,
	bool m_numbers[61][100])
{
	int i, n;
	double temp;
	bool OK = false;


	double fatigueFactor = (100 + double(avg.m_actual[player].GetGameStamina()) / 30) / 100;
	if (fatigueFactor > 1) fatigueFactor = 1;

	int cons = 4 - (avg.m_actual[player].GetConsistency() - 1);
	int factor = Fga * (cons / 2) - 1;
	if (factor < 3) factor = 3;
	double cells = 1000 / double(factor + 1.0);

	player = avg.m_actual[player].m_game_stat_slot;

	for (int j = 0; j <= factor; j++)
	{
		if (m_numbers[player][j] == false) OK = true;
	}
	if (OK == false)
	{
		for (int j = 0; j <= factor; j++)
		{
			m_numbers[player][j] = false;
		}
	}
	do
	{
		i = IntRandom(1000);
		temp = (i - 1.) / cells;
		n = int(temp);
	} while (m_numbers[player][n] == true);
	m_numbers[player][n] = true;
	if (i <= (FgPct * fatigueFactor))
		return TRUE;
	else
		return FALSE;
}

bool CEngine::ThreePtFieldGoalAttempt(int TfgPct, int player)//not used
{
	int i = IntRandom(1000);


	double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

	if (fatigueFactor > 1) fatigueFactor = 1;
	if (i <= (TfgPct * fatigueFactor))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool CEngine::FreeThrowAttemptGame(int FtPct, int player)
{
	int i = IntRandom(1000);


	double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
	if (fatigueFactor > 1) fatigueFactor = 1;
	if (i <= (FtPct * fatigueFactor))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int CEngine::ReboundTeam(int m_possesion, int Lineup[3][6])
{
	double OffReb = 0, DefReb = 0;
	int OffTeam = 0, DefTeam = 0, RebTeam = 0, player = 0;
	OffTeam = m_possesion;
	if (OffTeam == 1)
	{
		DefTeam = 2;
	}
	else
	{
		DefTeam = 1;
	}
	for (int i = 1; i <= 5; i++)
	{
		player = Lineup[OffTeam][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
		CPlayer m_player = avg.m_actual[player];
		if (fatigueFactor > 1) fatigueFactor = 1;
		OffReb = OffReb + (m_player.GetGameOrebPer48Min() * fatigueFactor);
	}
	for (int i = 1; i <= 5; i++)
	{
		player = Lineup[DefTeam][i];

		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		CPlayer m_player = avg.m_actual[player];

		if (fatigueFactor > 1) fatigueFactor = 1;
		DefReb = DefReb + (m_player.GetGameDrebPer48Min() * fatigueFactor);
	}
	double normalrate = avg.m_avg_orb[0] / (avg.m_avg_orb[0] + avg.m_avg_drb[0]) * 100;
	if (OffReb > DefReb) OffReb = DefReb;
	double rate = OffReb / (OffReb + DefReb) * 100;
	double diff1 = (rate - normalrate) * 1 / 2;
	double diff2 = (rate - normalrate) * 1 / 2;
	//double diff = diff1 + sqrt(fabs(diff2));
	if (diff1 > 0)
	{
		OffReb = normalrate + diff1 + sqrt(fabs(diff2));;
	}
	else
	{
		OffReb = normalrate + diff1 - sqrt(fabs(diff2));;
	}

	double number = Random(100);

	if (number <= OffReb)
	{
		RebTeam = OffTeam;
	}
	else
	{
		RebTeam = DefTeam;
	}


	/*	double number = Random(OffReb + DefReb);

		if(number <= OffReb)
		{
			RebTeam = OffTeam;
		}
		else
		{
			RebTeam = DefTeam;
		}*/


	return RebTeam;
}

int CEngine::ReboundPlayer(int m_possesion, int Lineup[3][6], int m_reboundTeam)
{
	double Touches[6] = { 0,0,0,0,0,0 };
	int player = 0;
	Touches[0] = 0;
	for (int i = 1; i < 6; ++i)
	{

		player = Lineup[m_reboundTeam][i];



		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		CPlayer m_player = avg.m_actual[player];

		if (fatigueFactor > 1) fatigueFactor = 1;
		if (m_possesion == m_reboundTeam)
		{
			Touches[i] = Touches[i - 1] + (m_player.GetGameOrebPer48Min() * fatigueFactor);
		}
		else
		{
			Touches[i] = Touches[i - 1] + (m_player.GetGameDrebPer48Min() * fatigueFactor);
		}
	}
	double number = Random(Touches[5]);
	int position = IntRandom(5);
	for (int i = 1; i < 6; ++i)
	{
		if (number <= Touches[i] && number > Touches[i - 1])
		{
			position = i;
			player = Lineup[m_reboundTeam][i];
		}
	}

	m_position_ball_handler = position;
	return position;
}

int CEngine::PfPlayer(int m_possesion, int Lineup[3][6])
{
	double Touches[6] = { 0,0,0,0,0,0 };
	for (int i = 1; i < 6; ++i)
	{
		int player = Lineup[m_possesion][i];

		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;


		CPlayer m_player = avg.m_actual[player];

		if (fatigueFactor > 1) fatigueFactor = 1;
		double foulRating = m_player.GetGamePfPer48Min();
		bool foulTrouble = FoulProblem(player);
		if (foulTrouble == true) foulRating = foulRating * 2 / 3;// 2/3 is foul caution factor;
		Touches[i] = Touches[i - 1] + foulRating * (2 - fatigueFactor);
	}
	double number = Random(Touches[5]);
	int position = IntRandom(5);
	for (int i = 1; i < 6; ++i)
	{
		if (number <= Touches[i] && number > Touches[i - 1]) { position = i; }
	}
	return position;
}

int CEngine::AssistPlayer(int Lineup[3][6], int m_ballHandler)
{
	double Assists[6] = { 0,0,0,0,0,0 };
	double FieldGoals[6] = { 0,0,0,0,0,0 };
	double AstRating[6] = { 0,0,0,0,0,0 };//used to adjust ast Rating
	int Positions[6] = { 0,0,0,0,0,0 };
	int Ast = 0;
	for (int i = 1; i <= 5; i++)
	{
		CPlayer m_player = avg.m_actual[Lineup[m_possesion][i]];
		Assists[i] = Assists[i - 1] + m_player.GetGameAstPer48Min();
		// calculate shots made by team
		double fgm = m_player.GetGameAdjustedFgaPer48Min() * double(m_player.GetGameAdjustedFgPct()) / 1000;
		double tfgm = m_player.GetGameAdjustedTfgaPer48Min() * double(m_player.GetGameTfgPct()) / 1000;
		FieldGoals[i] = FieldGoals[i - 1] + fgm + tfgm;
	}
	int p = 0;
	for (int i = 1; i <= 5; i++)
	{
		if (i == m_position_ball_handler) continue;
		p = p + 1;
		int player = Lineup[m_possesion][i];

		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		if (fatigueFactor > 1) fatigueFactor = 1;
		CPlayer m_player = avg.m_actual[player];
		double fg = (m_player.GetGameAstPer48Min() * fatigueFactor) / (FieldGoals[5] - (FieldGoals[i] - FieldGoals[i - 1]));
		AstRating[p] = AstRating[p - 1] + fg;
		Positions[p] = i;
	}

	double tmp = AstRating[4];//lower assist amount if team has too many 
	double factor = 1;
	if (tmp > (9. / 11.)) factor = tmp * 11 / 9;

	double number = Random(factor);
	for (int i = 1; i <= 4; i++)
	{
		if (number <= AstRating[i] && number > AstRating[i - 1]) Ast = Positions[i];
	}


	return Ast;
}

int CEngine::StealPlayer(int Lineup[3][6], double avg_stl)
{

	int defteam = GetPossesionOfTeamWithoutBall();
	int offteam = m_possesion;

	double Steals[6] = { 0,0,0,0,0,0 };
	double Turnovers[6] = { 0,0,0,0,0,0 };
	int Stl = 1;
	for (int i = 1; i < 6; ++i)
	{
		int player = Lineup[defteam][i];

		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		CPlayer m_player = avg.m_actual[player];

		if (fatigueFactor > 1) fatigueFactor = 1;

		Steals[i] = Steals[i - 1] + m_player.GetGameStlPer48Min() * fatigueFactor;
	}

	if (Steals[5] > (avg_stl * 1.5))
	{
		double f = (avg_stl * 1.5) / Steals[5];
		for (int i = 1; i <= 5; i++)
		{
			Steals[i] = Steals[i] * f;
		}
	};


	for (int i = 1; i <= 5; i++)
	{
		int player = Lineup[offteam][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
		CPlayer m_player = avg.m_actual[player];
		Turnovers[i] = Turnovers[i - 1] + m_player.GetGameToPer48Min() * (2 - fatigueFactor);
	}

	double number = Random(Turnovers[5]);
	if (number >= Steals[5])
		Stl = FALSE;
	else
	{
		for (int i = 1; i <= 5; i++)
		{
			if (number <= Steals[i] && number > Steals[i - 1]) Stl = i;
		}
	}
	return Stl;
}

int CEngine::BlockPlayer(int Lineup[3][6], bool ThreePointer, double avgBlk)
{
	CPlayer m_player;
	double TptBlkPct = 0;
	double f = avgBlk * .04;
	if (ThreePointer == true)
		TptBlkPct = f / avgBlk;
	else
		TptBlkPct = (avgBlk - f) / avgBlk;

	int defTeam = GetPossesionOfTeamWithoutBall();

	double Blocks[6] = { 0,0,0,0,0,0 };
	int Blk = IntRandom(5);
	for (int i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
		if (fatigueFactor > 1) fatigueFactor = 1;
		m_player = avg.m_actual[player];
		double gameBlk = m_player.GetGameBlkPer48Min();
		if (gameBlk > avg.m_avg_blk[i] * 3.)
		{
			gameBlk = avg.m_avg_blk[i] * 3;
		}
		Blocks[i] = Blocks[i - 1] + fatigueFactor * gameBlk * TptBlkPct;
	}

	if (Blocks[5] > (avgBlk * 1.5))
	{
		double f = (avgBlk * 1.5) / Blocks[5];
		for (int i = 1; i <= 5; i++)
		{
			Blocks[i] = Blocks[i] * f;
		}
	}


	double ShotsMissed[6] = { 0,0,0,0,0,0 };
	for (int i = 1; i < 6; ++i)
	{
		double fgm = 0;
		double fgMissed = 0;
		int player = Lineup[defTeam][i];
		CPlayer m_player = avg.m_actual[player];
		if (ThreePointer == true)
		{
			fgm =
				m_player.GetGameTfgaPer48Min()
				* double(m_player.GetGameTfgPct()) / 1000;
			fgMissed =
				m_player.GetGameTfgaPer48Min() - fgm;
		}
		else
		{
			fgm =
				m_player.GetGameFgaPer48Min()
				* double(m_player.GetGameFgPct()) / 1000;
			fgMissed =
				m_player.GetGameFgaPer48Min() - fgm;
		}
		ShotsMissed[i] = ShotsMissed[i - 1] + fgMissed;
	}
	double number = Random(ShotsMissed[5]);
	if (number > Blocks[5])
		Blk = FALSE;
	else
	{
		for (int i = 1; i < 6; ++i)
		{
			if (number <= Blocks[i] && number > Blocks[i - 1]) Blk = i;
		}
	}
	return Blk;
}

double CEngine::CurrentLineupBetter(int position_ball_handler, int player, int passer,
	int m_possesion, int Lineup[3][6])
{
	int offTeam = m_possesion;
	int ballhandler = player;
	double better = 0;//current players around
	CPlayer m_player = avg.m_actual[ballhandler];
	int usual = m_player.GetBetter();//ballhandler norm of players around 
	double d = double(usual) * 2 / 10 - 9.9;
	if (passer <= 0) passer = 1;
	double pos_factor = 1;
	if (position_ball_handler == 1) pos_factor = 2 / 3;
	else if (position_ball_handler == 2) pos_factor = 1;
	else if (position_ball_handler == 3) pos_factor = 1;
	else if (position_ball_handler == 4) pos_factor = 1;
	else if (position_ball_handler == 5) pos_factor = 1;

	for (int i = 1; i <= 5; i++)
	{
		if (player != Lineup[m_possesion][i])
		{

			double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

			if (fatigueFactor > 1) fatigueFactor = 1;
			CPlayer m_player = avg.m_actual[Lineup[offTeam][i]];
			if (i != passer)
			{
				better =
					better + m_player.GetTeammatesBetterRating() * fatigueFactor * pos_factor;
			}
			else
			{
				better =
					better + m_player.AdjustTeammatesBetterRatingForPasser(avg.m_avg_ast[i]) * fatigueFactor;
			}
		}
	}



	better = better + m_defAdj;

	if (better > 4)
	{
		better = sqrt(better) * 2;
	}
	else if (better < -4)
	{
		better = sqrt(abs(better)) * (-2);
	}


	double result = (better - d) / 5;
	return result;


}

double CEngine::CurrentLineupBlocks(int m_possesion, int Lineup[3][6], double avg_blk)
{
	CPlayer m_player;
	int offTeam = m_possesion;
	int defTeam = 0;

	if (m_possesion == 1)
		defTeam = 2;
	else
		defTeam = 1;

	double Blocks[6] = { 0,0,0,0,0,0 };
	int Blk = IntRandom(5);
	int i = 0;

	for (i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;
		if (fatigueFactor > 1) fatigueFactor = 1;
		m_player = avg.m_actual[player];
		Blocks[i] = Blocks[i - 1] + m_player.GetGameBlkPer48Min();
	}


	if (Blocks[5] > (avg_blk * 1.5))
	{
		double f = (avg_blk * 1.5) / Blocks[5];
		for (int i = 1; i <= 5; i++)
		{
			Blocks[i] = Blocks[i] * f;
		}
	};

	return Blocks[i - 1];
}

double CEngine::CurrentLineupSteals(int Lineup[3][6])
{
	int defTeam = GetPossesionOfTeamWithoutBall();

	double avg_stl = avg.m_avg_stl[0] * 5;


	double Steals[6] = { 0,0,0,0,0,0 };
	int Stl = IntRandom(5);
	int i = 0;
	for (i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		if (fatigueFactor > 1) fatigueFactor = 1;
		CPlayer m_player = avg.m_actual[player];
		Steals[i] = Steals[i - 1] + m_player.GetGameStlPer48Min();
	}
	if (Steals[5] > (avg_stl * 1.5))
	{
		double f = (avg_stl * 1.5) / Steals[5];
		for (int i = 1; i <= 5; i++)
		{
			Steals[i] = Steals[i] * f;
		}
	};

	return Steals[i - 1];
}

double CEngine::CurrentLineupTurnovers(int Lineup[3][6], BOOL m_homeCourt)
{
	int Team = m_possesion;

	double Turnovers[6] = { 0,0,0,0,0,0 };
	double playerTo = 0;


	int i = 0;
	for (i = 1; i < 6; ++i)
	{
		int player = Lineup[Team][i];
		double fatigueFactor = (100 + double(avg.m_actual[player].GetGameCurrentStamina()) / 30) / 100;

		if (fatigueFactor > 1) fatigueFactor = 1;
		CPlayer m_player = avg.m_actual[Lineup[Team][i]];
		if (m_homeCourt == TRUE)
			playerTo = m_player.GetGameAdjustedToPer48Min()
			- double(Team * 2 - 3) * m_hca;
		else
			playerTo = m_player.GetGameAdjustedToPer48Min();
		Turnovers[i] = Turnovers[i - 1] + playerTo;
	}
	return Turnovers[i - 1];
}

void CEngine::SetAvgTime(double avgPos, double avgOreb)
{
	//calculate avg time of possesion
	if (m_avg_player_min_factor > 1) m_avg_player_min_factor = 1;

	double visitorPossesions = (TeamRatings[1].GetGameFgaPer48Min()
		+ TeamRatings[1].GetGameTfgaPer48Min()
		+ TeamRatings[1].GetGameToPer48Min()
		+ TeamRatings[1].GetGameFoulsDrawnPer48Min()) * m_avg_player_min_factor;

	double homePossesions = (TeamRatings[2].GetGameFgaPer48Min()
		+ TeamRatings[2].GetGameTfgaPer48Min()
		+ TeamRatings[2].GetGameToPer48Min()
		+ TeamRatings[2].GetGameFoulsDrawnPer48Min()) * m_avg_player_min_factor;

	//		double possesions = (visitorPossesions + homePossesions - 20) * 2 - 210;
	double pb = (TeamRatings[1].GetGameOrebPer48Min() * m_avg_player_min_factor +
		TeamRatings[2].GetGameOrebPer48Min() * m_avg_player_min_factor) * 5 / 8;
	double fbv = (TeamRatings[1].GetGameDrebPer48Min() * m_avg_player_min_factor + TeamRatings[1].GetGameStlPer48Min() * m_avg_player_min_factor) / 5;
	double fbh = (TeamRatings[2].GetGameDrebPer48Min() * m_avg_player_min_factor + TeamRatings[2].GetGameStlPer48Min() * m_avg_player_min_factor) / 5;
	double fb = (fbv + fbh) * 7 / 5;
	double avgFbChances = avgPos * m_avg_player_min_factor * 2 / 10;
	avgOreb = avgOreb * m_avg_player_min_factor * 2 * 5 / 8;
	double poss = avgPos * m_avg_player_min_factor * 2 - pb - fb;
	double possesions = (visitorPossesions + homePossesions - avgOreb - avgFbChances) * 2 - poss;
	m_avg_time = (2880 - pb * 2 - fb * 4) / possesions;
	if (m_avg_time < 14) m_avg_time = 14;
	if (m_avg_time > 15) m_avg_time = 15;
	m_avg_time = 14.5;

	m_avg_time = m_avg_time * (2 - m_scoring_factor);
	if (m_avg_time < 1 || m_avg_time > 24) m_avg_time = 24;
}

void CEngine::SetTime(bool PutBack, int originalShot)
{
	//calculate seconds elapsed on possesion
	double d_seconds = 0;
	int i_seconds = 0;
	if (PutBack == TRUE)
	{
		i_seconds = IntRandom(3);
	}
	else if (originalShot == 7)
	{
		i_seconds = IntRandom(3) + 2;
	}
	else
	{
		int i_avg_time = int(m_avg_time);
		double factor = m_avg_time / 2;
		double f = m_avg_time - factor;
		d_seconds = CEngine::Random(m_avg_time) + f;
		double r = d_seconds - int(d_seconds);
		if (r < .5) i_seconds = int(d_seconds);
		else i_seconds = int(d_seconds) + 1;
		if (i_seconds == i_avg_time) i_seconds = IntRandom(21) + 3;
	}
	if (m_milk == true)
	{
		i_seconds = IntRandom(21) + 3;
		m_milk = false;
	}
	m_time = m_time - i_seconds;

	//	if(m_time <= 0) m_time = 0;


	if (m_time <= 0)
	{
		SetQuarter();
		m_quarter_ended = true;
	}
	if (PutBack == TRUE && m_quarter >= 5 && m_time == 300)//putback in progress game cant end
	{
		m_quarter = m_quarter - 1;
		m_quarter_ended = false;
		m_time = 1;
	}

}

void CEngine::SetQuarter()
{

	m_quarter = m_quarter + 1;

	if (m_quarter < 5)
		m_time = 720;
	else
		m_time = 300;

}

int CEngine::GetTime()
{
	return m_time;
}

int CEngine::GetQuarter()
{
	return m_quarter;
}


bool CEngine::FoulProblem(int player)
{
	bool foulTrouble = false;
	CPlayer m_player = avg.m_actual[player];
	int fouls = m_player.GetGamePf();
	int seconds = m_time;
	int quarter = m_quarter;
	int time = 720 - seconds + (quarter - 1) * 720;
	//	if(quarter > 4) time = 2880 + (300 - seconds) + (quarter - 5) * 300;

	if ((quarter == 1 && fouls >= 1) || (quarter == 2 && fouls >= 2)
		|| (quarter == 3 && fouls >= 3) || (quarter >= 4 && time < 2580 && fouls >= 4)
		|| (fouls >= 5)) foulTrouble = true;
	return foulTrouble;
}

void CEngine::DefensiveAdjustments(int d, int& mov, int& pen, int& post, int Lineup[3][6], int typeShot)
{
	int t = 1, p = 6;
	m_defAdj = 0;
	if (d <= 5)
	{
		t = 2; p = 1;
	}

	if (m_match[d] == 1)
	{
		mov = mov - 4;
		pen = pen + 2;
		post = post + 2;
	}
	else if (m_match[d] == 2)
	{
		mov = mov + 2;
		pen = pen - 4;
		post = post + 2;
	}
	else if (m_match[d] == 3)
	{
		mov = mov + 2;
		pen = pen + 2;
		post = post - 4;
	}
	else if (m_match[d] == 4)
	{
		mov = mov - 2;
		pen = pen - 2;
		post = post - 2;

	}

	if (m_match[d] != 4)//non doubled
	{
		for (int q = p; q <= p + 4; q++)
		{
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();

			if (m_match[q] == 4 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}

	}


	if (m_match[d] != 3 && typeShot == 3)//post up by non post defended player
	{
		for (int q = p; q <= p + 4; q++)
		{
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();

			if (m_match[q] == 3 && adj > 0)// add posted up players rating
				m_defAdj = m_defAdj + adj;
		}
	}
	else if (typeShot == 3)//post up by post defended player
	{
		for (int q = p; q <= p + 4; q++)
		{
			if (m_match[q] == 3) continue;
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();
			if (m_match[q] == 3) m_defAdj = m_defAdj + adj;
		}
	}
	if (m_match[d] != 2 && typeShot == 2)
	{
		for (int q = p; q <= p + 4; q++)
		{
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();

			if (m_match[q] == 2 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}
	}
	else if (typeShot == 2)
	{
		for (int q = p; q <= p + 4; q++)
		{
			if (m_match[q] == 2) continue;
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();
			if (m_match[q] == 2) m_defAdj = m_defAdj + adj;
		}
	}
	if (m_match[d] != 1 && typeShot == 1)
	{
		for (int q = p; q <= p + 4; q++)
		{
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();

			if (m_match[q] == 1 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}
	}
	else if (typeShot == 1)
	{
		for (int q = p; q <= p + 4; q++)
		{
			if (m_match[q] == 1) continue;
			int player = q;
			if (player > 5) player = player - 5;
			player = Lineup[t][player];
			double adj = avg.m_actual[player].GetTeammatesBetterRating();
			if (m_match[q] == 1) m_defAdj = m_defAdj + adj;
		}
	}


	for (int q = p; q <= p + 4; q++)// too many dbl teams punish
	{
		if (m_match[q] == 4 && q != d)
		{
			mov = mov + 1;
			pen = pen + 1;
			post = post + 1;
		}
		else if (m_match[q] == 3 && q != d) //too many posts 
		{
			mov = mov + 1;
			pen = pen + 1;
		}
		else if (m_match[q] == 2 && q != d) //too many drives defended 
		{
			mov = mov + 1;
			post = post + 1;
		}
		else if (m_match[q] == 1 && q != d)  //two many jumpshots defended
		{
			pen = pen + 1;
			post = post + 1;
		}
	}
}

void CEngine::AdjustOffenseForGamePlan(CPlayer m_player, int& Mov, int& Pen, int& Post, int& Trans)
{
	if (m_player.m_offensive_focus == 1)
	{
		Mov = Mov + 1;
		if (Random(1) <= .5)
			Pen = Pen - 1;
		else
			Post = Post - 1;

	}
	else if (m_player.m_offensive_focus == 2)
	{
		Pen = Pen + 1;
		if (Random(1) <= .5)
			Mov = Mov - 1;
		else
			Post = Post - 1;

	}
	else if (m_player.m_offensive_focus == 3)
	{
		Post = Post + 1;
		if (Random(1) <= .5)
			Pen = Pen - 1;
		else
			Mov = Mov - 1;

	}




	if (m_player.m_offensive_intensity < 0)
	{
		int i = IntRandom(4);
		if (i > (m_player.m_offensive_intensity + 4))
		{
			Trans = Trans - 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_offensive_intensity + 8))
		{
			Pen = Pen - 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_offensive_intensity + 8))
		{
			Mov = Mov - 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_offensive_intensity + 8))
		{
			Post = Post - 1;
		}
	}





}

void CEngine::AdjustDefenseForGamePlan(CPlayer m_player, int& MovDef, int& PenDef, int& PostDef, int& TransDef)
{
	if (m_player.m_defensive_focus == 1)
	{
		MovDef = MovDef + 1;
		if (Random(1) <= .5)
			PenDef = PenDef - 1;
		else
			PostDef = PostDef - 1;

	}
	else if (m_player.m_defensive_focus == 2)
	{
		PenDef = PenDef + 1;
		if (Random(1) <= .5)
			MovDef = MovDef - 1;
		else
			PostDef = PostDef - 1;

	}
	else if (m_player.m_defensive_focus == 3)
	{
		PostDef = PostDef + 1;
		if (Random(1) <= .5)
			PenDef = PenDef - 1;
		else
			MovDef = MovDef - 1;

	}









	if (m_player.m_defensive_intensity > 0)
	{
		int i = IntRandom(4);
		if (i <= m_player.m_defensive_intensity)
		{
			TransDef = TransDef - 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_defensive_intensity)
		{
			PenDef = PenDef - 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_defensive_intensity)
		{
			MovDef = MovDef - 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_defensive_intensity)
		{
			PostDef = PostDef - 1;
		}
	}
	else if (m_player.m_defensive_intensity < 0)
	{
		int i = IntRandom(4);
		if (i > (m_player.m_defensive_intensity + 4))
		{
			TransDef = TransDef + 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_defensive_intensity + 8))
		{
			PenDef = PenDef + 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_defensive_intensity + 8))
		{
			MovDef = MovDef + 1;
		}
		i = IntRandom(8);
		if (i > (m_player.m_defensive_intensity + 8))
		{
			PostDef = PostDef + 1;
		}
	}




	if (m_player.m_offensive_intensity > 0)
	{
		int i = IntRandom(4);
		if (i <= m_player.m_offensive_intensity)
		{
			TransDef = TransDef + 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_offensive_intensity)
		{
			MovDef = MovDef + 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_offensive_intensity)
		{
			PostDef = PostDef + 1;
		}
		i = IntRandom(8);
		if (i <= m_player.m_offensive_intensity)
		{
			PenDef = PenDef + 1;
		}
	}



}

void CEngine::AdjustIntensityForGamePlan()
{
	for (int i = 1; i <= 60; i++)
	{
		int player = m_playing_players_list[i];
		CPlayer m_player = avg.m_actual[player];
		double factor = (100 + (double)m_player.m_offensive_intensity * 5) / 100;
		double factor_x = (100 + (double)m_player.m_offensive_intensity * 10) / 100;

		double factor1 = (100 - (double)m_player.m_offensive_intensity * 5) / 100;
		double factor1_x = (100 - (double)m_player.m_offensive_intensity * 10) / 100;

		double bh_factor = (100 + (double)m_player.m_play_maker * Random(m_player.m_content)) / 100;
		double stamina_factor = (100 - (double)m_player.m_play_maker * 5.) / 100;


		if (m_player.m_offensive_focus == 1) m_player.m_OrebPer48Min = m_player.m_OrebPer48Min * (1 - Random(.1));
		else if (m_player.m_offensive_focus == 3) m_player.m_OrebPer48Min = m_player.m_OrebPer48Min * (1 + Random(.1));

		if (m_player.m_defensive_focus == 1) m_player.m_DrebPer48Min = m_player.m_DrebPer48Min * (1 - Random(.1));
		else if (m_player.m_defensive_focus == 3) m_player.m_DrebPer48Min = m_player.m_DrebPer48Min * (1 + Random(.1));

		m_player.m_AdjustedFgaPer48Min = m_player.m_OriginalAdjustedFgaPer48Min * factor * (2. - bh_factor);
		m_player.m_AdjustedTfgaPer48Min = m_player.m_OriginalAdjustedTfgaPer48Min * factor * (2 - bh_factor);
		m_player.m_AdjustedFoulsDrawnPer48Min = m_player.m_OriginalAdjustedFoulsDrawnPer48Min * factor * (2 - bh_factor);//?

//		m_player.m_AdjustedFoulsDrawnPer48Min = m_player.m_OriginalAdjustedFoulsDrawnPer48Min * .1;//?

		m_player.m_AdjustedToPer48Min = m_player.m_AdjustedToPer48Min * factor * bh_factor;

		//		m_player.m_AstPer48Min = m_player.m_AstPer48Min  * factor1;
		//		m_player.m_AstPer48Min = m_player.m_AstPer48Min  * factor;

		if (factor > 1)
		{
			m_player.m_AstPer48Min = m_player.m_AstPer48Min * factor1;
		}
		else if (factor < 1)
		{
			m_player.m_AstPer48Min = m_player.m_AstPer48Min * factor;
		}


		m_player.m_AstPer48Min = m_player.m_AstPer48Min * bh_factor;


		if (factor > 0) stamina_factor = stamina_factor * factor1;

		factor = (100 + (double)m_player.m_defensive_intensity * 5) / 100;
		factor_x = (100 + (double)m_player.m_defensive_intensity * 10) / 100;
		factor1 = (100 - (double)m_player.m_defensive_intensity * 5) / 100;
		factor1_x = (100 - (double)m_player.m_defensive_intensity * 10) / 100;
		if (factor > 0) stamina_factor = stamina_factor * factor1;
		m_player.m_StlPer48Min = m_player.m_OriginalStlPer48Min * factor;
		m_player.m_BlkPer48Min = m_player.m_OriginalBlkPer48Min * factor;
		m_player.m_PfPer48Min = m_player.m_PfPer48Min * factor;

		m_player.m_stamina = int((double)m_player.m_stamina * stamina_factor);
		avg.m_actual[player] = m_player;

	}

}



CString CEngine::DisplayJumpBall(CString playerName)
{








	//	double r = Random(1);
	double r = .5;






	CString string;


	CString teamName = m_teamName;

	if (r <= .25)
		string.Format("%s get the tip.\nIt's Controlled by %s.\n",
			teamName, playerName);
	else if (r <= .50)
		string.Format("%s won the tip.\nIt's Controlled by %s.\n",
			teamName, playerName);
	else if (r <= .75)
		string.Format("%s with control of the tip.\nIt's Controlled by %s.\n",
			teamName, playerName);
	else if (r <= 1)
		string.Format("%s with control of the jump ball.\nIt's Controlled by %s.\n",
			teamName, playerName);



	return string;
}

CString CEngine::FieldGoalAttempt(int typeShot,
	bool Fgm, bool PutBack,
	int Player,
	bool AndOne, bool Three,
	bool Rebounder_Same_As_Shooter,
	bool block)
{
	CString string;
	CString comment;
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();

	if (Fgm == TRUE)
	{

		if (PutBack == TRUE && block == false && y <= .3
			&& Rebounder_Same_As_Shooter == false)
			string.Format("Tipped back up and in.\n");
		else if (PutBack == TRUE && block == false && y <= .6
			&& Rebounder_Same_As_Shooter == false)
			string.Format("Tipped up and in.\n");
		else if (PutBack == TRUE && block == false && y <= .8
			&& Rebounder_Same_As_Shooter == false)
			string.Format("Follow up shot goes in.\n");
		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == false)
		{
			double dunk = (double(m_player.GetPostOff()) + m_player.GetGameOrebPer48Min() - m_player.GetGameAstPer48Min()) / 10;
			if (dunk > n && x < .4) string.Format("%s with the tip in slam!\n", playerName);
			else if (dunk > n && x < .8) string.Format("%s with the follow up jam!\n", playerName);
			else if (dunk > n) string.Format("%s throws it down from high over the top!\n", playerName);
			else string.Format("Pump fake...putback goes through for %s.\n", playerName);
		}





		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == true
			&& Three == false)
			string.Format("Tipped up and in.\n");


		else if (PutBack == TRUE && block == true)
			string.Format("Put back up and in.\n");

		else if (PutBack == TRUE
			&& Rebounder_Same_As_Shooter == true
			&& Three == true)
			string.Format("Put back goes in.\n");
		else
		{

			if (typeShot == OUTSIDE)
			{
				if (n < .05)
					string.Format("The jump shot by %s is good.\n", playerName);
				else if (n < .1)
					string.Format("%s's outside shot hits nothing but net.\n", playerName);
				else if (n < .15)
					string.Format("The open shot by %s is on target.\n", playerName);
				else if (n < .25)
					string.Format("Great off balance jump shot by %s!\n", playerName);
				else if (n < .3)
					string.Format("The jumper by %s is on the mark.\n", playerName);
				else if (n < .35)
					string.Format("The jump shot by %s rolls around and in.\n", playerName);
				else if (n < .4)
					string.Format("%s takes a jumper for two.\n", playerName);
				else if (n < .45)
					string.Format("%s's jump shot is up and in.\n", playerName);
				else if (n < .5)
					string.Format("Easy outside shot for %s.\n", playerName);
				else if (n < .55)
					string.Format("Off balance jumper goes in for %s.\n", playerName);
				else if (n < .6)
					string.Format("Open jumper by %s is good.\n", playerName);
				else if (n < .65)
					string.Format("Wide open jumper taken by %s is good.\n", playerName);
				else if (n < .7)
					string.Format("The jump shot by %s clears the net.\n", playerName);
				else if (n < .75)
					string.Format("%s's jump shot bounces off the rim and in.\n", playerName);
				else if (n < .8)
					string.Format("%s's jumper from the corner is good.\n", playerName);
				else if (n < .85)
					string.Format("Baseline jump shot by %s is on target.\n", playerName);
				else if (n < .9)
					string.Format("%s's jump shot finds its mark.\n", playerName);
				else if (n < .92)
					string.Format("%s's jumper is off the glass and in.\n", playerName);
				else if (n < .94)
					string.Format("%s hits the jump shot under pressure.\n", playerName);
				else if (n < .95)
					string.Format("%s's jumper had no business going in but it did.\n", playerName);
				else
					string.Format("The outside shot by %s is good.\n", playerName);
			}
			else if (typeShot == PENETRATION)
			{
				if (n < .05)
					string.Format("The driving shot by %s is good.\n", playerName);
				else if (n < .1)
					string.Format("%s's drive is off the glass and in.\n", playerName);
				else if (n < .15)
					string.Format("The layin by %s is on target.\n", playerName);
				else if (n < .2)
					string.Format("What a great reverse layup by %s!\n", playerName);
				else if (n < .25)
					string.Format("%s takes it into the paint for the bucket.\n", playerName);
				else if (n < .3)
					string.Format("Driving shot by %s rolls around and in.\n", playerName);
				else if (n < .35)
					string.Format("%s takes it strong for two.\n", playerName);
				else if (n < .4)
					string.Format("%s's quick drive is up and in.\n", playerName);
				else if (n < .45)
					string.Format("Easy layup for %s.\n", playerName);
				else if (n < .5)
					string.Format("%s drives to the basket and lays it up and in.\n", playerName);
				else if (n < .55)
					string.Format("The layup by %s is on the mark.\n", playerName);
				else if (n < .6 && m_player.GetPenOff() <= 3)
					string.Format("Rare move to the basket by %s!\n", playerName);
				else if (n < .6 && m_player.GetPenOff() <= 6)
					string.Format("Real nice move to the basket by %s.\n", playerName);
				else if (n < .6)
					string.Format("Outstanding move to the basket by %s!\n", playerName);
				else if (n < .64)
					string.Format("%s drives hard to the basket for two.\n", playerName);
				else if (n < .68)
					string.Format("Penetrating shot by %s goes off the glass and in.\n", playerName);
				else if (n < .72)
					string.Format("%s takes it to the hole for two.\n", playerName);
				else if (n < .76)
					string.Format("%s's off balance drive some how goes in.\n", playerName);
				else if (n < .8)
					string.Format("Drive and layup by %s.\n", playerName);
				else if (n < .9)
				{
					double dunk = (double(m_player.GetPenOff()) - m_player.GetGameAstPer48Min()) / 5;
					if (dunk > n && x <= .4) string.Format("%s with the slam!\n", playerName);
					else if (dunk > n && x <= .8) string.Format("%s throws it down with 2 hands from the baseline!\n", playerName);
					else if (dunk > n) string.Format("Incoming flight: %s JAM!\n", playerName);
					else string.Format("%s with the layup.\n", playerName);
				}
				else if (n < .95)
					string.Format("Drive and layup by %s.\n", playerName);
				else
					string.Format("The penetration by %s is good.\n", playerName);
			}
			else if (typeShot == INSIDE)
			{
				if (n < .05)
					string.Format("The inside shot by %s is good.\n", playerName);
				else if (n < .1)
					string.Format("%s's short turnaround hits nothing but net.\n", playerName);
				else if (n < .15)
					string.Format("The post shot by %s is on target.\n", playerName);
				else if (n < .2 && m_player.GetPostOff() <= 3)
					string.Format("Rare inside move by %s\n", playerName);
				else if (n < .2 && m_player.GetPostOff() <= 6)
					string.Format("Strong inside move by %s\n", playerName);
				else if (n < .2 && m_player.GetPostOff() <= 9)
					string.Format("Great post move by %s\n", playerName);
				else if (n < .25)
					string.Format("The inside shot by %s is on the mark.\n", playerName);
				else if (n < .3)
					string.Format("The inside shot by %s rolls around and in.\n", playerName);
				else if (n < .34)
					string.Format("%s posts up and takes it in for two.\n", playerName);
				else if (n < .38)
					string.Format("%s's post up jumper is up and in.\n", playerName);
				else if (n < .42)
					string.Format("Quick post move is good for %s.\n", playerName);
				else if (n < .46)
					string.Format("%s's shot from the low block clears the net.\n", playerName);
				else if (n < .5)
					string.Format("The low post move by %s is on the money.\n", playerName);
				else if (n < .6)

				{
					double dunk = (double(m_player.GetPostOff()) - m_player.GetGameAstPer48Min()) * .2;
					if (dunk > n && x <= .4) string.Format("%s slams it down with power!\n", playerName);
					else if (dunk > n && x <= .8) string.Format("%s pump fakes and jams it home!\n", playerName);
					else if (dunk > n) string.Format("Powerful reverse dunk by %s!\n", playerName);
					else if (m_player.GetPostOff() <= 3)
						string.Format("Good inside move by %s.\n", playerName);
					else if (m_player.GetPostOff() <= 6)
						string.Format("Strong inside move by %s.\n", playerName);
					else if (m_player.GetPostOff() <= 9)
						string.Format("Outstanding post move by %s.\n", playerName);
				}
				else if (n < .65)
					string.Format("Shot inside by %s finds the mark.\n", playerName);
				else if (n < .7)
					string.Format("The inside shot by %s hits the board and goes in.\n", playerName);
				else if (n < .75)
					string.Format("%s backs down and takes it up for two.\n", playerName);
				else if (n < .80)
					string.Format("%s's post up baseline jumper is up and good.\n", playerName);
				else if (n < .85)
					string.Format("Up and under move is good by %s.\n", playerName);
				else if (n < .90)
					string.Format("Good aggresive move earns %s the hoop.\n", playerName);
				else if (n < .94)
					string.Format("%s gets the ball down low, spins and scores.\n", playerName);
				else if (n < .95)
					string.Format("%s charges through with an elbow but the basket counts.\n", playerName);
				else if (n < .98)
					string.Format("%s on the block, turns toward the baseline and hits.\n", playerName);
				else
					string.Format("The strong inside move by %s leads to a basket.\n", playerName);
			}

		}
	}
	else
	{

		if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == false && y <= .4)
			string.Format("The tip in is no good.\n");
		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == false && y <= .6)
			string.Format("The tip is off the mark.\n");
		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == false && y <= .8)
			string.Format("Attempted tip in fails.\n");
		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == false && y <= 1)
			string.Format("Put back is no good.\n");

		else if (PutBack == TRUE && block == false
			&& Rebounder_Same_As_Shooter == true
			&& Three == false)
			string.Format("The tip in misses.\n");


		else if (PutBack == TRUE && block == true)
			string.Format("Put back up and no good.\n");

		else if (PutBack == TRUE
			&& Rebounder_Same_As_Shooter == true
			&& Three == true)
			string.Format("The follow up shot is no good.\n");

		else
		{

			if (typeShot == OUTSIDE)
			{

				if (n < .05)
					string.Format("The shot by %s is no good.\n", playerName);
				else if (n < .1)
					string.Format("%s's shot barely hits rim.\n", playerName);
				else if (n < .15)
					string.Format("The shot by %s is off target.\n", playerName);
				else if (n < .2)
					string.Format("That was a wild shot by %s.\n", playerName);
				else if (n < .25)
					string.Format("The shot by %s is off the mark.\n", playerName);
				else if (n < .3)
					string.Format("The shot by %s rolls around and just out.\n", playerName);
				else if (n < .35)
					string.Format("%s takes it in and misses.\n", playerName);
				else if (n < .4)
					string.Format("%s's shot is up and ... no good.\n", playerName);
				else if (n < .45)
					string.Format("Tough shot missed by %s.\n", playerName);
				else if (n < .5)
					string.Format("%s's shot glances off the rim.\n", playerName);
				else if (n < .55)
					string.Format("The shot by %s is off the mark.\n", playerName);
				else if (n < .6)
					string.Format("Bad shot by %s.\n", playerName);
				else if (n < .65)
					string.Format("The shot by %s misses the mark.\n", playerName);
				else if (n < .7)
					string.Format("The shot by %s hits the rim and bounces away.\n", playerName);
				else if (n < .75)
					string.Format("%s takes the jumper and misses.\n", playerName);
				else if (n < .8)
					string.Format("%s has a clear look but misses.\n", playerName);
				else if (n < .90)
					string.Format("%s's shot is off the mark.\n", playerName);
				else if (n < .95)
					string.Format("Bank shot misses for %s.\n", playerName);
				else if (n < .96)
					string.Format("%s hits nothing but air on that attempt.\n", playerName);
				else
					string.Format("%s shot is no good.\n", playerName);
			}
			else if (typeShot == PENETRATION)
			{

				if (n < .05)
					string.Format("The shot by %s is no good.\n", playerName);
				else if (n < .1)
					string.Format("%s's shot barely hits rim.\n", playerName);
				else if (n < .15)
					string.Format("The shot by %s is off target.\n", playerName);
				else if (n < .2)
					string.Format("That was an ill advised shot by %s.\n", playerName);
				else if (n < .25)
					string.Format("The shot by %s is off the mark.\n", playerName);
				else if (n < .3)
					string.Format("The shot by %s rolls around and just out.\n", playerName);
				else if (n < .35)
					string.Format("%s takes it in and misses.\n", playerName);
				else if (n < .4)
					string.Format("%s's shot is up and ... no good.\n", playerName);
				else if (n < .45)
					string.Format("Tough shot missed by %s.\n", playerName);
				else if (n < .5)
					string.Format("%s's shot barely hits rim.\n", playerName);
				else if (n < .55)
					string.Format("The shot by %s is off target.\n", playerName);
				else if (n < .6)
					string.Format("The shot by %s is hurried and off the mark.\n", playerName);
				else if (n < .65)
					string.Format("The shot by %s is off the mark.\n", playerName);
				else if (n < .7)
					string.Format("The shot by %s rolls around and just out.\n", playerName);
				else if (n < .75)
					string.Format("%s takes it in and misses.\n", playerName);
				else if (n < .8)
					string.Format("%s's shot is up and ... no good.\n", playerName);
				else if (n < .85)
					string.Format("%s's field goal attempt is no good.\n", playerName);
				else if (n < .9)
					string.Format("%s drives the baseline and misses.\n", playerName);
				else if (n < .95)
					string.Format("%s dribbles in the paint\nputs up the shot and misses.\n", playerName);
				else
					string.Format("%s misses the shot.\n", playerName);
			}
			//		else if(typeShot == INSIDE)
			else
			{

				if (n < .05)
					string.Format("The shot by %s is no good.\n", playerName);
				else if (n < .1)
					string.Format("%s's shot barely hits rim.\n", playerName);
				else if (n < .15)
					string.Format("The shot by %s is off target.\n", playerName);
				else if (n < .2)
					string.Format("The shot by %s is forced up and ... no good.\n", playerName);
				else if (n < .25)
					string.Format("The shot by %s is off the mark.\n", playerName);
				else if (n < .3)
					string.Format("The shot by %s rolls around and just out.\n", playerName);
				else if (n < .35)
					string.Format("%s takes it in and misses.\n", playerName);
				else if (n < .4)
					string.Format("%s's shot is up and ... no good.\n", playerName);
				else if (n < .45)
					string.Format("Tough shot missed by %s.\n", playerName);
				else if (n < .5)
					string.Format("%s's shot just did glance off the rim.\n", playerName);
				else if (n < .55)
					string.Format("The shot by %s is off center and no good.\n", playerName);
				else if (n < .56)
					string.Format("%s with a terrible shot\nas the coach just nods in anguish.\n", playerName);
				else if (n < .65)
					string.Format("The shot by %s is off target.\n", playerName);
				else if (n < .7)
					string.Format("The shot by %s bounces off the glass and out.\n", playerName);
				else if (n < .75)
					string.Format("%s takes it strong inside but misses.\n", playerName);
				else if (n < .8)
					string.Format("%s on the block, turns toward the baseline and misses.\n", playerName);
				else if (n < .85)
					string.Format("Clear shot missed by %s.\n", playerName);
				else if (n < .9)
					string.Format("Strong move fails for %s.\n", playerName);
				else if (n < .95)
					string.Format("%s's shot misses.\n", playerName);
				else if (n < .96)
				{
					if (y <= .5)
					{
						double dunk = double(m_player.GetPenOff()) - m_player.GetGameAstPer48Min();
						if (dunk > 0) string.Format("%s nearly broke the rim but it didn't go in!\n", playerName);
						else string.Format("There not much excuse for %s to miss such an easy one.\n", playerName);
					}
					else string.Format("%s some how failed to make the shot.\n", playerName);
				}
				else
					string.Format("The shot by %s is no good.\n", playerName);
			}


		}
	}

	if (AndOne == TRUE && Fgm == TRUE)
	{
		double y = Random(1);
		CString extraString;
		if (y < .25)
			extraString.Format("Count the basket!\n");
		if (y < .5)
			extraString.Format("The basket counts!\n");
		if (y < .75)
			extraString.Format("The shot counts!\n");
		else
			extraString.Format("Count the bucket!\n");
		string = string + extraString;
	}

	double Fg = (m_player.GetGameFgaPer48Min() * m_player.GetGameFgPct()) / 1000;
	int attempts = m_player.GetGameFga() + m_player.GetGameTfga();
	int shots = m_player.GetGameFgm() + m_player.GetGameTfgm();
	double Pct = double(shots) / double(attempts);
	int Pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 +
		m_player.GetGameFtm();

	if (Fgm == TRUE)//commentary
	{

		int team = 1;
		int other_team = 2;
		if (m_possesion == 2)
		{
			team = 2; other_team = 1;
		}
		int diff = m_score[team] + 2 - m_score[other_team];

		if (x < .1)
		{
			if (diff > 30 && m_quarter == 4)
				comment.Format("%s leading by %d!\n", m_team, diff);
			else if (diff > 30 && m_quarter < 4)
				comment.Format("%s blowing this contest wide open.\n", m_team);
			else if (diff > 20 && m_quarter < 4)
				comment.Format("%s beginning to run away with the game.\n", m_team);
			else if (diff > 10)
				comment.Format("%s opening up a %d point lead.\n", m_team, diff);
			else if (diff <= 3 && diff >= 0 && m_quarter == 4 && m_time > 300)
				comment.Format("Looks like we may be headed to a photo finish.\n");
			else if (diff <= 3 && diff >= -3 && m_quarter == 4 && m_time <= 300)
				comment.Format("Clutch basket by %s.\n", playerName);
		}

		else if (x < .125)
		{
			if (Fg < 5)
				comment.Format("A rare bucket for %s.\n", playerName);
		}
		else if (x < .15)
		{
			if (Fg < 5)
				comment.Format("%s is not exactly a scoring machine.\n", playerName);
		}
		else if (x < .175)
		{
			if (Fg < 5)
				comment.Format("%s gets an unexpected field goal.\n", playerName);
		}
		else if (x < .2)
		{
			if (Fg < 5)
				comment.Format("A rare basket by %s.\n", playerName);
		}
		else if (x < .3)
		{
			if (Pct > .6667 && attempts >= 9 && y <= .33)
				comment.Format("%s is red hot from the floor.\n", playerName);
			else if (Pct > .6667 && attempts >= 9 && y <= .66)
				comment.Format("%s is feeling it out there.\n", playerName);
			else if (Pct > .8 && attempts >= 10 && y <= 1)
				comment.Format("%s is in the zone.\n", playerName);
			else if (Pct > .6 && attempts >= 4 && y <= .25)
				comment.Format("%s is shooting well from the field.\n", playerName);
			else if (Pct > .6 && attempts >= 4 && y <= .5)
				comment.Format("%s is shooting the ball well.\n", playerName);
			else if (Pct > .6 && attempts >= 4 && y <= .75)
				comment.Format("%s is doing a fine job making shots.\n", playerName);
			else if (Pct > .6 && attempts >= 4 && y <= .1)
				comment.Format("The ball keeps finding its way into the basket for %s.\n", playerName);
			else comment.Format("%s is %d for %d from the field.\n", playerName, shots, attempts);
		}
		else if (x < .4)
		{
			if (Fg > 10 && y <= .25)
				comment.Format("%s showing big time scoring ability.\n", playerName);
			else if (Fg > 10 && y <= .5)
				comment.Format("%s is a lethal offensive player.\n", playerName);
			else if (Fg > 10 && y <= .75)
				comment.Format("%s is hard to control on the offensive end.\n", playerName);
			else if (Fg > 10 && y <= .1)
				comment.Format("Quality scorers like %s are a valuable property.\n", playerName);
			else if (Fg > 8 && y <= .25)
				comment.Format("%s definitely can score.\n", playerName);
			else if (Fg > 8 && y <= .5)
				comment.Format("%s is a solid offensive player.\n", playerName);
			else if (Fg > 8 && y <= .75)
				comment.Format("%s has to be respected offensively.\n", playerName);
			else if (Fg > 8 && y <= .1)
				comment.Format("%s's scoring ability came out on that shot.\n", playerName);
		}
		else if (x < .5)
		{
		}
		else if (x < .53)
		{
			comment.Format("%d points for %s.\n", Pts, playerName);
		}
		else if (x < .56)
		{
			comment.Format("%s has %d points.\n", playerName, Pts);
		}
		else if (x < .6)
		{
			comment.Format("%s now with %d points.\n", playerName, Pts);
		}
		else if (x < .64)
		{
			double ppg = double(m_player.m_sim_fgm * 2) +
				double(m_player.m_sim_tfgm * 3) + double(m_player.m_sim_ftm);

			double games = double(m_player.m_sim_games);
			if (games == 0) games = 1;
			ppg = ppg / games;
			if (ppg > 2 && games > 1) comment.Format("%s comes in averaging %.1f points per game.\n", playerName, ppg);
		}
		else if (x < .66)
		{
			double fgm = double(m_player.m_sim_fgm) +
				double(m_player.m_sim_tfgm);

			double fga = double(m_player.m_sim_fga) +
				double(m_player.m_sim_tfga);

			double fgp = fgm / fga * 100;

			double games = double(m_player.m_sim_games);
			if (games == 0) games = 1;
			if (fgp >= 40 && games > 1) comment.Format("%s comes in shooting %.1f percent from the floor.\n", playerName, fgp);
			else if (fgp > 0 && games > 1) comment.Format("%s is shooting just %.1f percent for the year.\n", playerName, fgp);

		}
		else if (x < .9)
		{
		}
		else
		{
		}
	}
	string = string + comment;
	return string;
}
CString CEngine::FieldGoalAttemptCommentary(int typeShot,
	int Player)

{
	CString comment;
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();
	double Fg = (m_player.GetGameFgaPer48Min() * m_player.GetGameFgPct()) / 1000;
	int attempts = m_player.GetGameFga() + m_player.GetGameTfga();
	int shots = m_player.GetGameFgm() + m_player.GetGameTfgm();
	double Pct = double(shots) / double(attempts);
	int Pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 +
		m_player.GetGameFtm();


	if (x < .1)
	{
	}
	else if (x < .2)
	{
	}
	else if (x < .3)
	{
		if (Pct < .25 && attempts >= 8 && y <= .25)
			comment.Format("%s, just %d for %d, is struggling from the field.\n", playerName, shots, attempts);
		if (Pct < .25 && attempts >= 8 && y <= .50)
			comment.Format("%s is ice cold at %d for %d from the floor.\n", playerName, shots, attempts);
		if (Pct < .25 && attempts >= 8 && y <= .75)
			comment.Format("%s is really shooting the ball poorly.\n", playerName, shots, attempts);
		if (Pct < .25 && attempts >= 8 && y <= 1)
			comment.Format("For the game %s is shooting a horrible %d for %d.\n", playerName, shots, attempts);
		if (Pct < .4 && attempts >= 4)
			comment.Format("%s is just %d for %d from the field.\n", playerName, shots, attempts);
		if (Pct < .4 && attempts >= 4)
			comment.Format("%s is still only shooting %d for %d from the floor.\n", playerName, shots, attempts);
		if (Pct < .4 && attempts >= 4)
			comment.Format("%s, only %d for %d, is struggling somewhat.\n", playerName, shots, attempts);
		if (Pct < .4 && attempts >= 4)
			comment.Format("%s is just %d for %d from the floor.\n", playerName, shots, attempts);
		else if (attempts > 0)
			comment.Format("%s is %d for %d from the field.\n", playerName, shots, attempts);

	}
	else if (x < .4)
	{
		if (Pct == 0 && (attempts == 5 || attempts == 10) && y <= .5)
			comment.Format("%s can't buy a shot.\n", playerName);
		else if (Pct == 0 && (attempts == 5 || attempts == 10))
			comment.Format("%s has yet to hit a shot.\n", playerName);
	}
	else if (x < .5)
	{
	}
	else if (x < .6)
	{
	}
	else if (x < .7)
	{
	}
	else if (x < .73)
	{

		double fgm = double(m_player.m_sim_fgm) +
			double(m_player.m_sim_tfgm);

		double fga = double(m_player.m_sim_fga) +
			double(m_player.m_sim_tfga);

		double fgp = fgm / fga * 100;

		double games = double(m_player.m_sim_games);
		if (games == 0) games = 1;



		if (fgp >= 40 && games > 1 && y <= .5)
			comment.Format("For the season %s is shooting %.1f percent from the field.\n", playerName, fgp);
		else if (fgp >= 40 && games > 1)
			comment.Format("%s comes in shooting %.1f percent.\n", playerName, fgp);
		else if (fgp > 0 && games > 1) comment.Format("On the year, %s is shooting at just a %.1f percent clip.\n", playerName, fgp);

	}
	else if (x < .8)
	{
	}
	else
	{
	}
	return comment;
}

CString CEngine::DisplayThreePtFieldGoalAttempt(BOOL Tfgm,
	int Player,
	bool AndOne)


{
	CString string;
	CString comment;
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();
	CString te_na = m_team_names[m_possesion];

	if (Tfgm == TRUE)
	{
		if (AndOne == TRUE)
			string.Format("Three point shot by %s is good.\nCount it! A chance for a rare four point play.\n", playerName);
		else if (n < .1)
			string.Format("Three point shot by %s is good.\n", playerName);
		else if (n < .2)
			string.Format("%s's three pointer hits nothing but net.\n", playerName);
		else if (n < .3)
			string.Format("Three point shot by %s is on the money.\n", playerName);
		else if (n < .4)
			string.Format("Long Range Bomb is good by %s.\n", playerName);
		else if (n < .5)
			string.Format("The trey by %s is on the mark.\n", playerName);
		else if (n < .6)
			string.Format("The three by %s rolls around and in.\n", playerName);
		else if (n < .7)
			string.Format("%s takes it from deep and nails the three.\n", playerName);
		else if (n < .8)
			string.Format("%s's three pointer is up and in.\n", playerName);
		else if (n < .9)
			string.Format("Tough three goes in for %s.\n", playerName);
		else
			string.Format("Three point shot by %s is good.\n", playerName);
	}
	else
	{
		if (n < .1)
			string.Format("Three point shot by %s is no good.\n", playerName);
		else if (n < .2)
			string.Format("%s's three pointer is way off.\n", playerName);
		else if (n < .3)
			string.Format("Three point shot by %s is off by a penny.\n", playerName);
		else if (n < .4)
			string.Format("Long range bomb is no good for %s.\n", playerName);
		else if (n < .5)
			string.Format("The trey by %s is off the mark.\n", playerName);
		else if (n < .6)
			string.Format("The three by %s rolls around and out.\n", playerName);
		else if (n < .7)
			string.Format("%s takes it from deep and misses with the three.\n", playerName);
		else if (n < .8)
			string.Format("%s's three pointer is up... in... and out.\n", playerName);
		else if (n < .9)
			string.Format("Tough three barely misses for %s.\n", playerName);
		else
			string.Format("Three point shot by %s is no good.\n", playerName);
	}

	double TfgPct = double(m_player.GetGameTfgPct()) / 1000;
	double Tfg = m_player.GetGameTfgaPer48Min() * TfgPct;
	int Pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 +
		m_player.GetGameFtm() + 3;

	if (Tfgm == TRUE)//commentary
	{

		int team = 1;
		int other_team = 2;
		if (m_possesion == 2)
		{
			team = 2; other_team = 1;
		}
		int diff = m_score[team] + 3 - m_score[other_team];
		if (diff == 2 && m_time == 0 && m_quarter >= 4)
			comment.Format("The %s have opened up a %d point lead.\n", te_na, diff);

		CString te_na = m_team_names[m_possesion];
		//CString te_na2 = m_team_names[m_possesion];

		if (x < .1)
		{
			if (diff > 10 && diff <= 20)
				comment.Format("%s opening up a %d point lead.\n", te_na, diff);
			else if (diff > 20 && diff <= 30 && m_quarter < 4)
				comment.Format("%s running away with the game.\n", te_na);
			else if (diff > 30 && m_quarter < 4)
				comment.Format("%s turning this contest into a blowout.\n", te_na);
			else if (diff > 30 && m_quarter == 4)
				comment.Format("%s leading by %d!\n", te_na, diff);
			else if (diff <= 3 && diff >= 0 && m_quarter == 4 && m_time > 300)
				comment.Format("Looks like we may be headed to a photo finish.\n");
			else if (diff <= 3 && diff >= -3 && m_quarter == 4 && m_time <= 300)
				comment.Format("Huge three pointer by %s.\n", playerName);
		}

		else if (x < .2)
		{
			if (Tfg < .25 && y <= .5)
				comment.Format("A rare three for %s.\n", playerName);
			if (Tfg < .25)
				comment.Format("%s is not exactly the person\nyou want shooting threes.\n", playerName);
		}
		else if (x < .3)
		{
		}
		else if (x < .4)
		{
			if (Tfg > 1 && TfgPct > .40 && y >= .5)
				comment.Format("%s is nearly unstoppable from the arc.\n", playerName);
			else if (Tfg > 1 && TfgPct > .375 && y <= .25)
				comment.Format("%s is so dangerous from beyond the arc.\n", playerName);
			else if (Tfg > 1 && TfgPct > .375 && y <= .5)
				comment.Format("%s is lethal from three.\n", playerName);
			else if (Tfg > 1 && TfgPct > .375 && y <= .75)
				comment.Format("%s is a terrific long range shooter.\n", playerName);
			else if (Tfg > 1 && TfgPct > .375 && y <= 1)
				comment.Format("%s can hit threes with the best of them.\n", playerName);
		}
		else if (x < .5)
		{
		}
		else if (x < .53)
		{
			comment.Format("%d points for %s.\n", Pts, playerName);
		}
		else if (x < .56)
		{
			comment.Format("%s has %d points.\n", playerName, Pts);
		}
		else if (x < .6)
		{
			comment.Format("%s now with %d points.\n", playerName, Pts);
		}
		else if (x < .7)
		{
		}
		else if (x < .73)
		{

			double fgm = double(m_player.m_sim_tfgm);

			double fga = double(m_player.m_sim_tfga);

			double fgp = fgm / fga * 100;

			double games = double(m_player.m_sim_games);
			if (games == 0) games = 1;



			if (fgp >= 40 && games > 1 && y <= .5)
				comment.Format("For the season %s is shooting %.1f percent behind the arc.\n", playerName, fgp);
			else if (fgp >= 40 && games > 1)
				comment.Format("%s comes in shooting %.1f percent from three.\n", playerName, fgp);
			else if (fgp > 0 && games > 1) comment.Format("On the year, %s is shooting at just a %.1f percent clip.\n", playerName, fgp);

		}
		else if (x < .8)
		{
		}
		else if (x < .9)
		{
		}
		else
		{
		}
	}



	string = string + comment;

	return string;
}


CString CEngine::FreeThrowAttempt(bool Ftm, bool PutBack,
	int Player,
	CString number)
	//Number is 1st 2nd or 3rd FT

{
	CString string;
	CString comment;
	n = Random(1);
	x = Random(1);
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();

	if (Ftm == TRUE)
	{
		if (n < .05)
			string.Format("%s free throw by %s is good.\n", number, playerName);
		else if (n < .1)
			string.Format("%s's %s free throw goes through cleanly.\n", playerName, number);
		else if (n < .15)
			string.Format("%s free throw for %s is on the money.\n", number, playerName);
		else if (n < .2)
			string.Format("%s free throw bounces off the rim and in for %s.\n", number, playerName);
		else if (n < .25)
			string.Format("The %s free throw by %s is on the mark.\n", number, playerName);
		else if (n < .3)
			string.Format("The free throw by %s rolls around and in.\n", playerName);
		else if (n < .35)
			string.Format("%s tosses in the %s free throw.\n", playerName, number);
		else if (n < .4)
			string.Format("%s's %s free throw is up and in.\n", playerName, number);
		else if (n < .45)
			string.Format("The %s free throw goes in for %s.\n", number, playerName);
		else if (n < .5)
			string.Format("%s's %s free throw goes through the net.\n", playerName, number);
		else if (n < .55)
			string.Format("%s free throw for %s is on target.\n", number, playerName);
		else if (n < .6)
			string.Format("%s free throw hits the rim and goes in for %s.\n", number, playerName);
		else if (n < .65)
			string.Format("The %s free throw by %s is good.\n", number, playerName);
		else if (n < .7)
			string.Format("The free throw by %s rolls around and in.\n", playerName);
		else if (n < .75)
			string.Format("%s makes the %s free throw.\n", playerName, number);
		else if (n < .8)
			string.Format("%s's %s free throw is just in.\n", playerName, number);
		else if (n < .85)
			string.Format("The %s free throw attempt by %s is good.\n", number, playerName);
		else if (n < .9)
			string.Format("%s's %s free throw attempt is good.\n", playerName, number);
		else if (n < .95)
			string.Format("%s hits the %s free throw.\n", playerName, number);
		else if (n < .96)
			string.Format("The %s free throw attempt by %s\ngoes off the glass and in!.\n", number, playerName);
		else
			string.Format("%s free throw attempt by %s is good.\n", number, playerName);
	}
	else
	{
		if (n < .05)
			string.Format("%s free throw by %s misses.\n", number, playerName);
		else if (n < .1)
			string.Format("%s's %s free throw just does get a piece of the rim.\n", playerName, number);
		else if (n < .15)
			string.Format("%s free throw by %s just does miss.\n", number, playerName);
		else if (n < .2)
			string.Format("%s free throw by %s is off.\n", number, playerName);
		else if (n < .25)
			string.Format("The %s free throw attempt by %s no good.\n", number, playerName);
		else if (n < .3)
			string.Format("The %s free throw by %s rolls off the rim.\n", number, playerName);
		else if (n < .35)
			string.Format("%s takes the %s free throw and misses.\n", playerName, number);
		else if (n < .4)
			string.Format("%s's %s free throw is ... just out.\n", playerName, number);
		else if (n < .43)
			string.Format("Bad break as %s just does miss the %s free throw.\n", playerName, number);
		else if (n < .45)
			string.Format("%s's %s free throw almost bent the rim.\n", playerName, number);
		else if (n < .55)
			string.Format("%s free throw by %s is a little bit off.\n", number, playerName);
		else if (n < .6)
			string.Format("%s charity stripe toss for %s is no good.\n", number, playerName);
		else if (n < .64)
			string.Format("%s's %s free throw is no good.\n", playerName, number);
		else if (n < .7)
			string.Format("%s's %s free throw misses.\n", playerName, number);
		else if (n < .75)
			string.Format("%s takes and misses the %s attempt from the line.\n", playerName, number);
		else if (n < .8)
			string.Format("%s's %s attempt from the line is in and out.\n", playerName, number);
		else if (n < .85)
			string.Format("Hard bounce as %s misses the free throw.\n", playerName);
		else if (n < .9)
			string.Format("%s misses the %s attempt from the line.\n", playerName, number);
		else if (n < .95)
			string.Format("%s misses, as the %s free throw is off the rim.\n", playerName, number);
		else if (n < .96)
			string.Format("Terrible looking free throw by %s.\n", playerName);
		else
			string.Format("%s free throw by %s is no good.\n", number, playerName);
	}
	double FtPct = double(m_player.GetGameFtPct()) / 1000;


	double ftm = double(m_player.m_sim_ftm);

	double fta = double(m_player.m_sim_fta);

	double ftp = ftm / fta * 100;

	double games = double(m_player.m_sim_games);
	if (games == 0) games = 1;



	double Ft = m_player.GetGameFoulsDrawnPer48Min() * FtPct;
	FtPct = FtPct * 100;
	int Pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 +
		m_player.GetGameFtm() + 1;

	if (Ftm == TRUE)//commentary
	{

		if (x < .05)
		{
			if (ftp > 65 && games > 1)
				comment.Format("%s is a %.1f percent shooter from the line.\n", playerName, ftp);
			else if (ftp > 0 && games > 1)
				comment.Format("%s not a good free throw shooter at just %.1f percent.\n", playerName, ftp);
		}

		else if (x < .2)
		{
		}
		else if (x < .3)
		{
		}
		else if (x < .33)
		{
			if (FtPct > 87.5 && number == "1st")
				comment.Format("%s is an outstanding free throw shooter.\n", playerName);
		}
		else if (x < .36)
		{
			if (FtPct > 87.5 && number == "1st")
				comment.Format("%s is a great free throw shooter.\n", playerName);
		}
		else if (x < .39)
		{
			if (FtPct > 90 && number == "1st")
				comment.Format("%s is amazing from the free throw line.\n", playerName);
		}
		else if (x < .5)
		{
		}
		else if (x < .53)
		{
			//				comment.Format("%d points for %s.\n", Pts, playerName);
		}
		else if (x < .56)
		{
			//				comment.Format("%s has %d points.\n", playerName, Pts);
		}
		else if (x < .6)
		{
			//				comment.Format("%s now with %d points.\n", playerName, Pts);
		}

		else if (x < .7)
		{
		}
		else if (x < .8)
		{
		}
		else if (x < .9)
		{
		}
		else
		{
		}
	}
	else
	{

		if (x < .1)
		{
		}
		else if (x < .2)
		{
		}
		else if (x < .3)
		{
		}
		else if (x < .33)
		{
			if (FtPct > 87.5)
				comment.Format("A rare miss by %s.\n", playerName);
		}
		else if (x < .36)
		{
			if (FtPct > 87.5)
				comment.Format("%s doesn't miss many free throws..\n", playerName);
		}
		else if (x < .39)
		{
			if (FtPct >= 90)
				comment.Format("It's news when %s misses from the line.\n", playerName);
		}
		else if (x < .5)
		{
		}
		else if (x < .6)
		{
		}
		else if (x < .7)
		{
		}
		else if (x < .8)
		{
		}
		else if (x < .9)
		{
		}
		else
		{
		}

	}



	string = string + comment;

	return string;
}



CString CEngine::FreeThrowType(BOOL InTheAct, int m_teamFouls,
	CString m_foulingTeamName,
	bool assister, bool PutBack)
{
	CString string1, string2, string;
	if (InTheAct == FALSE)
	{

		if (PutBack == TRUE)
			string2.Format("Over the back foul.\n");
		else if (assister == true)
			string2.Format("Foul called before the shot.\n");
		else
			string2.Format("Foul called away from the ball.\n");

		if (m_teamFouls == 5)
			string1.Format("%s now over the limit.\n", m_foulingTeamName);

	}
	string = string2 + string1;
	return string;
}




CString CEngine::Turnover(int Player,
	bool offFoul)
{
	CString string;
	CString comment;
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();

	if (offFoul == true && y <= .25)
		string.Format("Offensive foul by %s.\n", playerName);
	else if (offFoul == true && y <= .5)
		string.Format("Charging foul by %s.\n", playerName);
	else if (offFoul == true && y <= .75)
		string.Format("Offensive foul charged to %s.\n", playerName);
	else if (offFoul == true && y <= 1)
		string.Format("%s charged with the offensive foul.\n", playerName);
	else
	{
		if (n < .05)
			string.Format("The pass by %s is off the mark\nand goes out of bounds.\n", playerName);
		else if (n < .1)
			string.Format("%s puts the ball on the floor and loses control.\n", playerName);
		else if (n < .15)
			string.Format("Ball stripped and goes off of %s's leg.\n", playerName);
		else if (n < .18)
			string.Format("The ball appeared to go off of a defender\nbut the turnover is charged on %s.\n", playerName);
		else if (n < .25)
			string.Format("Thrown away by %s.\n", playerName);
		else if (n < .3)
			string.Format("%s is charged with traveling.\n", playerName);
		else if (n < .38)
			string.Format("%s is charged with a backcourt violation.\n", playerName);
		else if (n < .45)
			string.Format("Poor decision by %s leads to a turnover.\n", playerName);
		else if (n < .5)
			string.Format("Unforced turnover by %s.\n", playerName);
		else if (n < .55)
			string.Format("%s trying to create\nis forced to give the ball up and throws it away.\n", playerName);
		else if (n < .56)
			string.Format("Three second violation charged to %s.\n", playerName);
		else if (n < .65)
			string.Format("Thrown away out of bounds by %s.\n", playerName);
		else if (n < .7)
			string.Format("Traveling called on %s.\n", playerName);
		else if (n < .75)
			string.Format("The ref calls a double dribble on %s.\n", playerName);
		else if (n < .8)
			string.Format("The ball goes off of %s's foot and out of bounds.\n", playerName);
		else if (n < .81)
			string.Format("%s threw that one to one of the vendors.\n", playerName);
		else if (n < .85)
			string.Format("%s is trapped in the corner and steps on the endline.\n", playerName);
		else if (n < .90)
			string.Format("%s loses control of the dribble\nand the ball goes out of bounds.\n", playerName);
		else if (n < .97)
			string.Format("%s mishandles the pass and turns it over.\n", playerName);
		else if (n < .98)
			string.Format("%s throws the ball to a teammate (who is not playing :)\n", playerName);
		else
			string.Format("Bizzare turnover by %s.\n", playerName);

		double To = m_player.GetGameToPer48Min();
		double Ast = m_player.GetGameAstPer48Min();
		int To_game = m_player.GetGameTo();
		double Ast_To = Ast / To;

		if (x < .1)
		{
		}
		else if (x < .2)
		{
		}
		else if (x < .3)
		{
		}
		else if (x < .4)
		{
			if (Ast_To < 1)
				comment.Format("%s is not much of a ballhandler.\n", playerName);
		}
		else if (x < .5)
		{
			if (Ast_To > 3)
				comment.Format("%s usually doesn't make those types of mistakes.\n", playerName);
		}
		else if (x < .6)
		{
			if (Ast_To > 2 && To < 2)
				comment.Format("%s with a rare turnover.\n", playerName);

		}
		else if (x < .7)
		{
			if (To_game > 5)
				comment.Format("%s with turnover number %d.\n", playerName, To_game);



		}
		else if (x < .75)
		{
			if (To_game > 5)
				comment.Format("%s now with %d turnovers! .\n", playerName, To_game);



		}
		else if (x < .8)
		{
			if (double(To_game) > (To + 2))
				comment.Format("%s has struggled with turnovers.\n", playerName);

		}
		else if (x < .85)
		{
			if (double(To_game) > (To + 2))
				comment.Format("Turnovers have plagued %s in this game.\n", playerName);

		}
		else if (x < .9)
		{
		}
		else
		{
		}
	}
	string = string + comment;
	return string;
}

CString CEngine::Injury(int Player,
	int gamesOut)
{
	CString string;
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();

	if (gamesOut == 1)
		string.Format("%s is injured.\n", playerName);
	else if (gamesOut <= 3)
		string.Format("%s suffers an injury.\n", playerName);
	else if (gamesOut <= 10)
		string.Format("%s is injured and it could be pretty serious.\n", playerName);
	else if (gamesOut <= 20)
		string.Format("%s is injured and it looks pretty serious.\n", playerName);
	else if (gamesOut <= 40)
		string.Format("%s suffers a serious injury.\n", playerName);
	else if (gamesOut <= 82)
		string.Format("%s is badly hurt and it doesn't look good.\n", playerName);
	else if (gamesOut <= 99)
		string.Format("%s is injured.\nFrom the looks of it, that could be a season ender.\n", playerName);
	return string;
}





CString CEngine::OffRebound(CString playerName, int Player,
	bool Rebounder_Same_As_Shooter,
	bool block, bool PutBack)
{
	CString string;
	CString comment;
	n = Random(1);
	x = Random(1);
	y = Random(1);
	CPlayer m_player = avg.m_actual[Player];
	CString te_na = m_team_names[m_possesion];


	if (Rebounder_Same_As_Shooter == true && block == false)
		string.Format("%s rebounds own miss.\n", playerName);
	else if (block == true)
		string.Format("%s recovers the loose ball.\n", playerName);
	else if (PutBack == TRUE)
	{
		if (n < .05)
			string.Format("Rebounded by %s.\n", playerName);
		else if (n < .1)
			string.Format("%s with the offensive board.\n", playerName);
		else if (n < .15)
			string.Format("%s gets the offensive board.\n", playerName);
		else if (n < .2)
			string.Format("Offensive rebound by %s.\n", playerName);
		else if (n < .25)
			string.Format("Offensive board by %s.\n", playerName);
		else if (n < .3)
			string.Format("%s working the offensive glass.\n", playerName);
		else if (n < .35)
			string.Format("%s gets a hand on the offensive board.\n", playerName);
		else if (n < .4)
			string.Format("%s the offensive rebound.\n", playerName);
		else if (n < .45)
			string.Format("%s gets the ball off the %s backboard.\n", playerName, te_na);
		else if (n < .5)
			string.Format("%s controls the offensive board.\n", playerName);
		else if (n < .55)
			string.Format("%s gets the offensive rebound.\n", playerName);
		else if (n < .6)
			string.Format("%s gets up for the offensive rebound.\n", playerName);
		else if (n < .65)
			string.Format("Offensive board controlled by %s.\n", playerName);
		else if (n < .7)
			string.Format("%s hustling to the offensive glass.\n", playerName);
		else if (n < .75)
			string.Format("%s recovers the offensive board.\n", playerName);
		else if (n < .8)
			string.Format("%s picks up the offensive rebound.\n", playerName);
		else if (n < .85)
			string.Format("The offensive rebound goes to %s.\n", playerName);
		else if (n < .9)
			string.Format("Offensive rebound for %s.\n", playerName);
		else if (n < .95)
			string.Format("Rebound off the offensive glass for %s.\n", playerName);
		else if (n < .96)
			string.Format("%s some how manages to get the ball off the %s glass.\n", playerName, te_na);
		else
			string.Format("%s fights for the offensive rebound in traffic.\n", playerName);
	}
	else
	{
		if (n < .05)
			string.Format("Offensive Board by %s.\n", playerName);
		else if (n < .1)
			string.Format("%s snares the offensive board.\n", playerName);
		else if (n < .15)
			string.Format("%s grabs the offensive board.\n", playerName);
		else if (n < .2)
			string.Format("%s crashes in for the offensive board.\n", playerName);
		else if (n < .25)
			string.Format("Offensive rebound deflected then controlled by %s.\n", playerName);
		else if (n < .3)
			string.Format("Offensive rebound by %s.\n", playerName);
		else if (n < .35)
			string.Format("Credit %s with an offensive rebound.\n", playerName);
		else if (n < .4)
			string.Format("Tough offensive rebound by %s.\n", playerName);
		else if (n < .45)
			string.Format("Ball grabbed off the offensive glass by %s.\n", playerName);
		else if (n < .48)
			string.Format("%s working the %s offensive glass.\n", playerName, te_na);
		else if (n < .5)
			string.Format("%s comes down with the offensive board.\n", playerName);
		else if (n < .55)
			string.Format("%s comes up with the offensive board.\n", playerName);
		else if (n < .6)
			string.Format("%s hustles in for the offensive board.\n", playerName);
		else if (n < .65)
			string.Format("Offensive rebound volleyed then picked up by %s.\n", playerName);
		else if (n < .7)
			string.Format("Offensive rebound grabbed by %s.\n", playerName);
		else if (n < .75)
			string.Format("Credit %s with the offensive rebound.\n", playerName);
		else if (n < .8)
			string.Format("Tough offensive rebound in traffic by %s.\n", playerName);
		else if (n < .85)
			string.Format("%s controls the %s rebound.\n", playerName, te_na);
		else if (n < .9)
			string.Format("Ball picked up off the glass by %s.\n", playerName);
		else if (n < .95)
			string.Format("The offensive rebound to %s.\n", playerName);
		else if (n < .96)
			string.Format("%s loses control but then hustles over\nto pick up the loose ball for the %s offense.\n", playerName, te_na);
		else
			string.Format("Offensive Rebound some how controlled by %s.\n", playerName);
	}

	double oreb = m_player.GetGameOrebPer48Min();
	double dreb = m_player.GetGameDrebPer48Min();
	int oreb_game = m_player.GetGameOreb() + 1;
	int dreb_game = m_player.GetGameDreb();
	int reb_game = oreb_game + dreb_game;
	if (PutBack == FALSE)
	{
		if (x < .1)
		{
			if (oreb > 4)
				comment.Format("%s is an outstanding offensive rebounder.\n", playerName);
		}
		if (x < .13)
		{
			if (oreb > 4)
				comment.Format("%s is hard to handle on the offensive glass.\n", playerName);
		}
		if (x < .16)
		{
			if (oreb > 4)
				comment.Format("%s is very dangerous on the offensive board.\n", playerName);
		}
		else if (x < .2)
		{
			if (oreb_game > 3 && (double(oreb_game) > oreb * 2))
				comment.Format("%s has been sensational on the offensive board.\n", playerName);

		}
		else if (x < .23)
		{
			if (oreb_game > 3 && (double(oreb_game) > oreb * 2))
				comment.Format("Great performance by %s on the offensive board.\n", playerName);

		}
		else if (x < .26)
		{
			if (oreb_game > 3 && (double(oreb_game) > oreb * 2))
				comment.Format("%s is doing a fantastic job of offensive rebounding.\n", playerName);

		}
		else if (x < .3)
		{
			if (oreb_game > 1)
				comment.Format("%s with %d offensive rebounds.\n", playerName, oreb_game);
		}
		else if (x < .4)
		{
			if (reb_game > 1)
				comment.Format("%s with %d rebounds.\n", playerName, reb_game);
		}
		else if (x < .5)
		{
		}
		else if (x < .6)
		{

		}
		else if (x < .7)
		{



		}
		else if (x < .8)
		{

		}
		else if (x < .9)
		{
		}
		else
		{
		}
	}

	string = string + comment;

	return string;

}


CString CEngine::DefRebound(int Player)
{
	CString string;
	CString comment;
	n = Random(1);
	x = Random(1);
	y = Random(1);
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();

	CString te_na = m_team_names[m_possesion];


	int pl = 0;

	if (n < .05)
		string.Format("Rebounded by %s.\n", playerName);
	else if (n < .1)
		string.Format("%s with the board.\n", playerName);
	else if (n < .15)
		string.Format("%s gets the rebound.\n", playerName);
	else if (n < .2)
		string.Format("Rebound by %s.\n", playerName);
	else if (n < .25)
		string.Format("Defensive board by %s.\n", playerName);
	else if (n < .3)
		string.Format("%s with the rebound.\n", playerName);
	else if (n < .35)
		string.Format("%s gets the board.\n", playerName);
	else if (n < .4)
		string.Format("%s tracks down the rebound.\n", playerName);
	else if (n < .45)
		string.Format("%s grabs the rebound.\n", playerName);
	else if (n < .5)
		string.Format("%s with the rebound.\n", playerName);
	else if (n < .55)
		string.Format("%s gets the rebound for the %s defense.\n", playerName, te_na);
	else if (n < .6)
		string.Format("Rebound in traffic picked up by %s.\n", playerName);
	else if (n < .65)
		string.Format("Defensive board controlled by %s.\n", playerName);
	else if (n < .7)
		string.Format("%s grabs the rebound.\n", playerName);
	else if (n < .75)
		string.Format("%s controls the deflection and gets the board.\n", playerName);
	else if (n < .8)
		string.Format("%s tracks down the rebound in the corner.\n", playerName);
	else if (n < .85)
		string.Format("%s hustles for the rebound.\n", playerName);
	else if (n < .9)
		string.Format("The rebound is picked up by %s.\n", playerName);
	else if (n < .95)
		string.Format("The missed shot is grabbed by %s.\n", playerName);
	else if (n < .995)
		string.Format("%s grabs the errant shot.\n", playerName);
	else
		string.Format("Rebound falls into %s's lap while on the floor!\n", playerName);

	double oreb = m_player.GetGameOrebPer48Min();
	double dreb = m_player.GetGameDrebPer48Min();
	int oreb_game = m_player.GetGameOreb() + 1;
	int dreb_game = m_player.GetGameDreb();
	int reb_game = oreb_game + dreb_game;
	if (x < .1)
	{
		if (dreb > 8)
			comment.Format("%s is tough on the defensive glass.\n", playerName);
	}
	else if (x < .2)
	{
		if (dreb_game > 6 && (double(dreb_game) > dreb * 2))
			comment.Format("%s has been terrific on the defensive board.\n", playerName);

	}
	else if (x < .23)
	{
		if (reb_game > 1)
			comment.Format("%s with %d rebounds.\n", playerName, reb_game);
	}
	else if (x < .26)
	{
		if (reb_game > 1)
			comment.Format("%s now has %d rebounds.\n", playerName, reb_game);
	}
	else if (x < .29)
	{
		if (reb_game > 1)
			comment.Format("%d rebounds for %s.\n", reb_game, playerName);
	}
	else if (x < .4)
	{
	}
	else if (x < .5)
	{
	}
	else if (x < .53)
	{
		double reb = double(m_player.m_sim_oreb) +
			double(m_player.m_sim_reb);

		double games = double(m_player.m_sim_games);
		if (games == 0) games = 1;

		double rpg = reb / games;

		if (rpg >= 1 && games > 1 && y <= .5)
			comment.Format("%s comes in averaging %.1f rebounds per game.\n", playerName, rpg);
		else if (rpg >= 1 && games > 1)
			comment.Format("%s averages %.1f rebounds a contest.\n", playerName, rpg);
	}
	else if (x < .7)
	{
	}
	else if (x < .8)
	{
	}
	else if (x < .9)
	{
	}
	else
	{
	}

	string = string + comment;

	return string;

}


CString CEngine::Fastbreak(int fbReceiver, int fbPasser, CString team)
{
	CString string;
	CString passer = avg.m_actual[fbPasser].GetLastName();
	CString playerName = avg.m_actual[fbReceiver].GetLastName();
	if (n < .20)
		string.Format("%s out on the run.\n", team);
	else if (n < .40 && fbPasser > 0)
		string.Format("Its %s and %s on the fastbreak.\n", playerName, passer);
	else if (n < .40 && fbPasser == 0)
		string.Format("%s out on the break.\n", team);
	else if (n < .50)
		string.Format("Fast break for the %s offense.\n", team);
	else if (n < .55)
		string.Format("%s with a fast break chance.\n", team);
	else if (n < .60)
		string.Format("%s filling the lanes.\n", team);
	else if (n < .70)
		string.Format("%s pushing the ball upcourt.\n", team);
	else if (n < .80)
		string.Format("%s looking to run.\n", team);
	else if (n < .90)
		string.Format("%s running the floor.\n", team);
	else
		string.Format("%s in transition.\n", team);
	return string;
}


CString CEngine::Assist(int Player, int passReceiver)
{

	CString string;
	if (Player == passReceiver)
	{

		AfxMessageBox("", IDOK);
	}
	CPlayer m_player = avg.m_actual[Player];
	CString playerName = m_player.GetLastName();
	CPlayer m_receiver = avg.m_actual[passReceiver];
	CString m_receiverName = m_receiver.GetLastName();
	double Ast = .62 + m_player.GetGameAstPer48Min() / 800;
	if (n < .1)
		string.Format("Pass from %s to %s.\n", playerName, m_receiverName);
	else if (n < .2)
		string.Format("Feed from %s to %s.\n", playerName, m_receiverName);
	else if (n < .3)
		string.Format("%s with a pass to %s.\n", playerName, m_receiverName);
	else if (n < .35)
		string.Format("%s over to %s.\n", playerName, m_receiverName);
	else if (n < .4)
		string.Format("%s dishes to %s.\n", playerName, m_receiverName);
	else if (n < .45)
		string.Format("%s feeds the ball to %s.\n", playerName, m_receiverName);
	else if (n < .5)
		string.Format("%s passes the ball to %s.\n", playerName, m_receiverName);
	else if (n < .55)
		string.Format("%s with a pass to %s.\n", playerName, m_receiverName);
	else if (n < .6)
		string.Format("%s with a pass over to %s.\n", playerName, m_receiverName);
	else if (n < .61)
		string.Format("%s with a crosscourt pass to %s.\n", playerName, m_receiverName);
	else if (n < .62)
		string.Format("Bounce pass from %s to %s.\n", playerName, m_receiverName);
	else if (n < Ast)
		string.Format("%s behind the back pass to %s!\n", playerName, m_receiverName);
	else
		string.Format("%s passes to %s.\n", playerName, m_receiverName);

	return string;
}

CString CEngine::AssistCommentary(int Player, CString playerName)
{

	CString comment;
	CPlayer m_player = avg.m_actual[Player];

	double Ast = m_player.GetGameAstPer48Min();
	int AstToday = m_player.GetGameAst();

	if (x < .05)
		comment.Format("%s set that up with a fine pass.\n", playerName);
	else if (x < .1)
		comment.Format("Credit the assist to %s.\n", playerName);
	else if (x < .15)
		comment.Format("The assist goes to %s.\n", playerName);
	else if (x < .2)
		comment.Format("The assist is credited to %s.\n", playerName);
	else if (x < .25)
		comment.Format("The assist for %s.\n", playerName);
	else if (x < .3)
		comment.Format("%s with the assist.\n", playerName);
	else if (x < .35)
		comment.Format("Good pass by %s.\n", playerName);
	else if (x < .4)
	{
		if (Ast > 9 && y <= .25)
			comment.Format("%s showing off those passing skills.\n", playerName);
		else if (Ast > 9 && y <= .5)
			comment.Format("%s is an excellent passer.\n", playerName);
		else if (Ast > 9 && y <= .75)
			comment.Format("Outstanding passers like %s are hard to come by.\n", playerName);
		else if (Ast > 9 && y <= 1)
			comment.Format("%s demonstrating that fine passing ability.\n", playerName);
	}
	else if (x < .5)
	{
		if (Ast < 3 && y <= .25)
			comment.Format("%s is usually not much of a passer.\n", playerName);
		if (Ast < 3 && y <= .50)
			comment.Format("%s pass by a poor passer.\n", playerName);
		if (Ast < 3 && y <= .75)
			comment.Format("%s with a rare assist.\n", playerName);
		if (Ast < 3 && y <= 1)
			comment.Format("Passing the basketball is not exactly %s's strength.\n", playerName);
	}
	else if (x < .53)
	{
		double reb = double(m_player.m_sim_ast);

		double games = double(m_player.m_sim_games);
		if (games == 0) games = 1;

		double rpg = reb / games;

		if (rpg >= 1 && games > 1 && y <= .5)
			comment.Format("%s's current assist average is %.1f.\n", playerName, rpg);
		else if (rpg >= 1 && games > 1)
			comment.Format("%s is averaging %.1f assists.\n", playerName, rpg);
	}
	else if (x < .6)
	{
		if (AstToday > 2)
			comment.Format("%s has %d assists.\n", playerName, AstToday);
		else
			comment.Format("The assist to %s.\n", playerName);

	}
	else if (x < .7)
	{
		if (double(AstToday) >= (Ast * 2) && AstToday > 4)
			comment.Format("%s is racking up the assists today.\n", playerName);
	}
	return comment;
}


CString CEngine::Steal(int player,
	CString playerName,
	CString m_playerToName)

{
	n = Random(1);
	x = Random(1);
	y = Random(1);
	CString string;
	CString comment;


	CPlayer m_player = avg.m_actual[player];
	if (n < .1)
		string.Format("%s steals the ball from %s.\n", playerName, m_playerToName);
	else if (n < .2)
		string.Format("%s has the ball stolen by %s.\n", m_playerToName, playerName);
	else if (n < .3)
		string.Format("%s steals the pass from %s.\n", playerName, m_playerToName);
	else if (n < .35)
		string.Format("%s knocks the ball away from %s and forces the turnover.\n", playerName, m_playerToName);
	else if (n < .375)
		string.Format("%s steals the ball from under %s's nose.\n", playerName, m_playerToName);
	else if (n < .4)
		string.Format("%s with a clean steal away from %s.\n", playerName, m_playerToName);
	else if (n < .45)
		string.Format("%s's pass is stolen by %s.\n", m_playerToName, playerName);
	else if (n < .5)
		string.Format("%s loses the ball to %s.\n", m_playerToName, playerName);
	else if (n < .55)
		string.Format("%s strips the ball from %s.\n", playerName, m_playerToName);
	else if (n < .6)
		string.Format("%s with a steal as %s is forced to pass.\n", playerName, m_playerToName);
	else if (n < .65)
		string.Format("%s with a steal from behind %s.\n", playerName, m_playerToName);
	else if (n < .7)
		string.Format("%s in trouble and it's stolen away by %s.\n", m_playerToName, playerName);
	else
		string.Format("%s steals the ball from %s.\n", playerName, m_playerToName);

	double stl = m_player.GetGameStlPer48Min();
	int stl_game = m_player.GetGameStl();
	if (x < .1)
	{
		if (stl > 3 && y <= .25)
			comment.Format("%s is one dangerous theif.\n", playerName);
		else if (stl > 3 && y <= .5)
			comment.Format("%s is clearly one of the league's best pick pockets.\n", playerName);
		else if (stl > 3 && y <= .75)
			comment.Format("Ball handlers have to be extra careful when %s is on the court.\n", playerName);
		else if (stl > 3 && y <= .95)
			comment.Format("%s again raising havoc with the ability to get steals.\n", playerName);
		else if (stl > 3)
			comment.Format("%s could end up in prison with steals like that.\n", playerName);
	}
	else if (x < .2)
	{
		if (stl_game > 3 && (double(stl_game) >= stl * 2))
			comment.Format("%s has been all over the passing lanes defensively.\n", playerName);

	}
	else if (x < .3)
	{
		if (stl_game > 1 && y <= .5)
			comment.Format("%s with %d steals.\n", playerName, stl_game);
		else if (stl_game > 1)
			comment.Format("%s has %d steals.\n", playerName, stl_game);
	}
	else if (x < .4)
	{
		comment.Format("Excellent defensive play by %s.\n", playerName);
	}
	else if (x < .43)
	{
		double reb = double(m_player.m_sim_stl);

		double games = double(m_player.m_sim_games);
		if (games == 0) games = 1;

		double rpg = reb / games;

		if (rpg >= 1 && games > 1 && y <= .5)
			comment.Format("%s averages %.1f swipes per contest.\n", playerName, rpg);
		else if (rpg >= 1 && games > 1)
			comment.Format("%s came into the contest averaging %.1f steals.\n", playerName, rpg);
	}
	else if (x < .6)
	{
	}
	else if (x < .7)
	{
	}
	else if (x < .8)
	{
	}
	else if (x < .9)
	{
	}
	else
	{
	}
	string = string + comment;
	return string;
}


CString CEngine::Block(CString playerName,
	CString m_playerBlockedName, int blocker)


{
	n = Random(1);
	x = Random(1);
	y = Random(1);


	CPlayer m_player = avg.m_actual[blocker];

	CString string, comment;
	if (n <= .1)
		string.Format("%s's shot is blocked by %s.\n", m_playerBlockedName, playerName);
	else if (n <= .2)
		string.Format("%s's shot is deflected by %s.\n", m_playerBlockedName, playerName);
	else if (n <= .3)
		string.Format("Blocked by %s as %s goes up with the shot.\n", playerName, m_playerBlockedName);
	else if (n <= .4)
		string.Format("%s's shot is blocked cleanly by %s.\n", m_playerBlockedName, playerName);
	else if (n <= .5)
		string.Format("%s with a piece of the shot by %s.\n", playerName, m_playerBlockedName);
	else if (n <= .6)
		string.Format("%s has the shot blocked by %s.\n", m_playerBlockedName, playerName);
	else if (n <= .7)
		string.Format("%s's shot is swatted away by %s.\n", m_playerBlockedName, playerName);
	else if (n <= .8)
		string.Format("%s blocks %s's shot.\n", playerName, m_playerBlockedName);
	else if (n <= .9)
		string.Format("%s rejected by %s.\n", m_playerBlockedName, playerName);
	else if (n <= 1)
		string.Format("%s's shot is blocked by %s.\n", m_playerBlockedName, playerName);

	double stl = m_player.GetGameBlkPer48Min();
	int stl_game = m_player.GetGameBlk();
	if (x < .1)
	{
		if (stl > 3 && y <= .25)
			comment.Format("%s is a dangerous shot blocker.\n", playerName);
		else if (stl > 4 && y <= .5)
			comment.Format("%s is one of the top shot blockers in the game.\n", playerName);
		else if (stl > 4 && y <= .75)
			comment.Format("Shooters must proceed with caution\nas long as %s is in the paint.\n", playerName);
		else if (stl > 4 && y <= .95)
			comment.Format("%s can intimidate opponents with shot blocking ability.\n", playerName);
		else if (stl > 4)
			comment.Format("Shot blockers like %s are a rare bunch.\n", playerName);
	}
	else if (x < .2)
	{
		if (stl_game > 3 && (double(stl_game) >= stl * 2))
			comment.Format("%s is making a difference with rejections.\n", playerName);

	}
	else if (x < .3)
	{
		if (stl_game > 1 && y <= .25)
			comment.Format("%s with %d blocks.\n", playerName, stl_game);
		else if (stl_game > 1 && y <= .5)
			comment.Format("%s has %d blocks.\n", playerName, stl_game);
		else if (stl_game > 1 && y <= .75)
			comment.Format("%s with %d rejections.\n", playerName, stl_game);
		else if (stl_game > 1)
			comment.Format("%s has %d rejections.\n", playerName, stl_game);
	}
	else if (x < .4)
	{
		comment.Format("Excellent defensive play by %s.\n", playerName);
	}
	else if (x < .425)
	{
		comment.Format("Nearly a goaltending call.\n");
	}
	else if (x < .6)
	{
	}
	else if (x < .63)
	{
		double reb = double(m_player.m_sim_blk);

		double games = double(m_player.m_sim_games);
		if (games == 0) games = 1;

		double rpg = reb / games;

		if (rpg >= 1 && games > 1 && y <= .5)
			comment.Format("%s averages %.1f rejections a game.\n", playerName, rpg);
		else if (rpg >= 1 && games > 1)
			comment.Format("%s is averaging %.1f blocks per game.\n", playerName, rpg);
	}
	else if (x < .8)
	{
	}
	else if (x < .9)
	{
	}
	else
	{
	}
	string = string + comment;
	return string;
}

CString CEngine::BlockThreePointer(CString playerName,
	CString m_playerBlockedName)

{
	CString string;
	if (y <= .25) string.Format("%s's three is blocked by %s.\n", m_playerBlockedName, playerName);
	else if (y <= .5) string.Format("%s's three is swatted away by %s.\n", m_playerBlockedName, playerName);
	else if (y <= .75) string.Format("%s gets a piece of the three pointer by %s.\n", playerName, m_playerBlockedName);
	else if (y <= .1) string.Format("The three by %s is rejected by %s.\n", m_playerBlockedName, playerName);
	return string;
}

CString CEngine::Pf(int player, CString m_foulPlayerName, int pf,
	bool AndOne, bool InTheAct, bool ThreePointer,
	bool offFoul)
{
	CString firstString, secondString, string;

	CString playerName = avg.m_actual[player].GetLastName();

	if (AndOne == FALSE && InTheAct == TRUE && y <= .25)
		firstString.Format("Foul is drawn by %s.\n", playerName);
	else if (AndOne == FALSE && InTheAct == TRUE && y <= .5)
		firstString.Format("%s draws the foul.\n", playerName);
	else if (AndOne == FALSE && InTheAct == TRUE && y <= .75)
		firstString.Format("%s is fouled on the shot.\n", playerName);
	else if (AndOne == FALSE && InTheAct == TRUE)
		firstString.Format("%s draws the personal foul.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false && y <= .4)
		firstString.Format("%s is fouled on the play.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false && y <= .65)
		firstString.Format("%s is fouled.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false && y <= .75)
		firstString.Format("%s manages to draw a foul.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false && y <= .85)
		firstString.Format("The whistle blows and %s is fouled.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false && y <= .95)
		firstString.Format("%s is hacked on the play.\n", playerName);
	else if (AndOne == FALSE && InTheAct == FALSE && offFoul == false)
		firstString.Format("%s is knocked down and the ref calls the foul.\n", playerName);

	if (pf == 1 && y <= .25) secondString.Format("%s's %dst.\n", m_foulPlayerName, pf);
	else if (pf == 2 && y <= .25) secondString.Format("%s's %dnd.\n", m_foulPlayerName, pf);
	else if (pf == 3 && y <= .25) secondString.Format("%s's %drd.\n", m_foulPlayerName, pf);
	else if (pf == 4 && y <= .25) secondString.Format("%s's %dth.\n", m_foulPlayerName, pf);
	else if (pf == 5 && y <= .25) secondString.Format("%s's %dth.\n", m_foulPlayerName, pf);
	else if (pf == 6 && y <= .25)
	{
		secondString.Format(" %s has fouled out.\n", m_foulPlayerName);
	}
	else if (pf == 1 && y <= .50) secondString.Format("The %dst on %s.\n", pf, m_foulPlayerName);
	else if (pf == 2 && y <= .50) secondString.Format("The %dnd on %s.\n", pf, m_foulPlayerName);
	else if (pf == 3 && y <= .50) secondString.Format("The %drd on %s.\n", pf, m_foulPlayerName);
	else if (pf == 4 && y <= .50) secondString.Format("The %dth on %s.\n", pf, m_foulPlayerName);
	else if (pf == 5 && y <= .50) secondString.Format("The %dth on %s.\n", pf, m_foulPlayerName);
	else if (pf == 6 && y <= .50)
	{
		secondString.Format(" Fouling out of the game is %s.\n", m_foulPlayerName);
	}
	else if (pf == 1 && y <= .75) secondString.Format("%s's %dst in the game.\n", m_foulPlayerName, pf);
	else if (pf == 2 && y <= .75) secondString.Format("%s's %dnd in the game.\n", m_foulPlayerName, pf);
	else if (pf == 3 && y <= .75) secondString.Format("%s's %drd in the game.\n", m_foulPlayerName, pf);
	else if (pf == 4 && y <= .75) secondString.Format("%s's %dth in the game.\n", m_foulPlayerName, pf);
	else if (pf == 5 && y <= .75) secondString.Format("%s's %dth in the game.\n", m_foulPlayerName, pf);
	else if (pf == 6 && y <= .75)
	{
		secondString.Format(" %s has fouled out of the game.\n", m_foulPlayerName);
	}
	else if (pf == 1) secondString.Format("%dst foul called on %s.\n", pf, m_foulPlayerName);
	else if (pf == 2) secondString.Format("%dnd foul called on %s.\n", pf, m_foulPlayerName);
	else if (pf == 3) secondString.Format("%drd foul called on %s.\n", pf, m_foulPlayerName);
	else if (pf == 4) secondString.Format("%dth foul called on %s.\n", pf, m_foulPlayerName);
	else if (pf == 5) secondString.Format("%dth foul called on %s.\n", pf, m_foulPlayerName);
	else if (pf == 6)
	{
		secondString.Format(" %s just fouled out of the game.\n", m_foulPlayerName);
	}
	string = firstString + secondString;
	if (pf == 7)
	{
		bool crash = true;
	}

	return string;

}

CString CEngine::TeamRebound(CString team)
{
	//	y = Random(1);
	CString string;
	if (y < .25)
		string.Format("Rebound batted out of bounds.\n%s ball.\n", team);
	else if (y < .5)
		string.Format("Rebound deflected out of bounds.\n%s with the ball.\n", team);
	else if (y < .75)
		string.Format("Scramble for the rebound.\n%s with control.\n", team);
	else
		string.Format("Rebound out of bounds.\n%s basketball.\n", team);
	return string;
}






void CEngine::Initialize(int visitor, int home)
{
	//m_injury_notify = avg.m_settings.m_injury_prompt;
	int t1 = visitor;
	int t2 = home;
	m_visitorIndex = visitor;
	m_homeIndex = home;
	m_visitor_player_offset = (m_visitorIndex - 1) * 30;
	m_home_player_offset = (m_homeIndex - 1) * 30;

	int co = 1;
	for (int p = 1; p <= 30; p++)
	{

		avg.m_actual[m_visitor_player_offset + p].ClearGameStats();


		if (avg.m_actual[m_visitor_player_offset + p].m_injury == 0 &&
			avg.m_actual[m_visitor_player_offset + p].m_name != "" &&
			avg.m_actual[m_visitor_player_offset + p].m_active == 1 && co < 13 && avg.m_actual[m_visitor_player_offset + p].m_min >= 72)
		{
			m_playing_players_list[co] = m_visitor_player_offset + p;
			avg.m_actual[m_playing_players_list[co]].m_game_stat_slot = p;
			co = co + 1;
		}
	}

	co = 31;
	for (int p = 1; p <= 30; p++)
	{

		avg.m_actual[m_home_player_offset + p].ClearGameStats();


		if (avg.m_actual[m_home_player_offset + p].m_injury == 0 &&
			avg.m_actual[m_home_player_offset + p].m_name != "" &&
			avg.m_actual[m_home_player_offset + p].m_active == 1 && co < 43 && avg.m_actual[m_home_player_offset + p].m_min >= 72)
		{
			m_playing_players_list[co] = m_home_player_offset + p;
			avg.m_actual[m_playing_players_list[co]].m_game_stat_slot = 30 + p;
			co = co + 1;
		}
	}

	if (m_team_names[1] == "")
		m_team_names[1] = avg.m_settings.m_leagueTeamNames[t1 - 1];
	if (m_team_names[2] == "")
		m_team_names[2] = avg.m_settings.m_leagueTeamNames[t2 - 1];

	avg.m_actual[1440 + t1].ClearGameStats();
	avg.m_actual[1440 + t2].ClearGameStats();

	m_possesion_team_index[1] = t1;//


	m_possesion_team_index[2] = t2;//

	m_quarter = 1;



	m_score[1] = 0;
	m_score[2] = 0;



}

void CEngine::FillPbp(CString line)
{

	//m_pbp_strings[m_pbp_results] = line;

	if (m_play_over == false)
	{

		int co = 0;
		CString str = line;
		do
		{
			co = str.Find("\n");
			m_pbp_results = m_pbp_results + 1;
			m_pbp_strings[m_pbp_results] = str.Left(co);
			CString tmp = str;
			if (co >= 0) str = tmp.Mid(co + 1);
		} while (co != -1);
	}
	else if (m_play_over == true)
	{


		CString PositionNames[6] = { "", "PG", "SG", "SF", "PF", " C" };
		CString m_visitorScore;
		CString m_homeScore;
		CString quarterString;
		CString minutesString;
		CString secondsString;
		CString time;
		minutesString = "";
		int minutes = 0;
		int seconds = 0;
		int quarter = 0;

		minutes = GetTime() / 60;
		seconds = GetTime() - minutes * 60;
		quarter = GetQuarter();

		minutesString.Format("%d", minutes);
		secondsString.Format("%d", seconds);
		quarterString.Format("%d", quarter);


		if (seconds < 10) secondsString = "0" + secondsString;
		if (quarter == 1) quarterString = "1st";
		else if (quarter == 2) quarterString = "2nd";
		else if (quarter == 3) quarterString = "3rd";
		else if (quarter == 4) quarterString = "4th";
		else quarterString = "OT ";

		if (minutes < 10)
			time = quarterString + "         " + minutesString + ":" + secondsString;
		else time = quarterString + "        " + minutesString + ":" + secondsString;

		m_visitorScore.Format("%d", m_score[VISITOR]);
		m_homeScore.Format("%d", m_score[HOME]);

		CString time_string = time;

		CString score_string = m_team_names[1] + " " + m_visitorScore + " " + m_team_names[2] + " " + m_homeScore;




		CString m_current_string =
			time + "\n" + m_team_names[1] + " " + m_visitorScore + " " +
			m_team_names[2] + " " + m_homeScore;


		if (m_current_string != m_score_string)
		{
			m_pbp_results = m_pbp_results + 1;
			m_pbp_strings[m_pbp_results] = time_string;
			m_pbp_results = m_pbp_results + 1;
			m_pbp_strings[m_pbp_results] = score_string;
		}

		m_score_string = m_current_string;

	}

}

void CEngine::GetPbpStrings(CString* pbp_strings)
{
	for (int i = 1; i <= m_pbp_results; i++)
	{
		*(&pbp_strings[i]) = *(&m_pbp_strings[i]);
	}


}

int CEngine::GetTotalPbpResults()
{
	return m_pbp_results;
}




int CEngine::GetVisitorIndex()
{
	return m_visitorIndex;
}

int CEngine::GetHomeIndex()
{
	return m_homeIndex;
}

int CEngine::GetVisitorPlayerOffset()
{
	return m_visitor_player_offset;
}

int CEngine::GetHomePlayerOffset()
{
	return m_home_player_offset;

}

int CEngine::GetPlayingPlayersList(int i)
{

	return m_playing_players_list[i];
}

int CEngine::GetOffensiveLineup(int t, int p)
{
	return Lineup[t][p];
}

int CEngine::GetDefensiveLineup(int t, int p)
{
	return Defense[t][p];

}

CString CEngine::GetGameTeamNames(int i)
{
	return m_team_names[i];
}

int CEngine::GetGameScore(int i)
{
	return m_score[i];
}

int CEngine::GetGamePossessionTeamIndex(int i)
{
	return m_possesion_team_index[i];
}

int CEngine::GetPossession()
{
	return m_possesion;
}

void CEngine::SetOffensiveLineup(int t, int p, int player)
{
	int orig = Lineup[t][p];//original defensive assignmenet of player coming out
	Lineup[t][p] = player;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			if (orig == Defense[i][j])
				Defense[i][j] = player;
		}
	}
}

int CEngine::GetScore(int t)
{
	return m_score[t];
}


void CEngine::SaveCurrentGameData()
{
	bool saveOk = false;
	//	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".pbp";
	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".log";
	CFile* file = new CFile();
	file->Open(pFileName, CFile::modeRead);
	char s[17];
	int bytes = file->Read(s, 14);
	s[bytes] = 0;
	int game = atoi(s);
	int visitor = m_visitorIndex - 1;
	int home = m_homeIndex - 1;
	if (avg.m_settings.m_save_pbp[visitor] == TRUE ||
		avg.m_settings.m_save_pbp[home] == TRUE) saveOk = true;

	file->Close();
	delete file;

	//Save History Boxes
	if (m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
	{
		char s0[17];
		saveOk = false;
		pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".bxs";
		CFile* file1 = new CFile();
		file1->Open(pFileName, CFile::modeRead);
		bytes = file1->Read(s0, 16);
		s0[bytes] = 0;
		game = atoi(s0);

		if (avg.m_settings.m_save_box[visitor] == TRUE ||
			avg.m_settings.m_save_box[home] == TRUE) saveOk = true;

		file1->Close();
		delete file1;
	}



	if (saveOk == true && m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
	{

		CString buffer;
		CFile* f = new CFile();
		f->Open(pFileName, CFile::modeWrite);
		game = game + 1;
		if (game > 40000) game = 1;
		buffer.Format("%d", game);
		buffer = buffer + "               ";
		f->Write(buffer, 16);
		int seek = (game - 1) * 50000 + 17 + 32;
		f->Seek(seek, CFile::begin);
		buffer.Format("%d", avg.m_sched.m_currentMonth);
		buffer = buffer + "   ";
		f->Write(buffer, 4);
		buffer.Format("%d", avg.m_sched.m_currentDay);
		buffer = buffer + "   ";
		f->Write(buffer, 4);
		CString vis = m_team_names[1] + "               ";
		f->Write(vis, 16);

		buffer.Format("%d", m_score[1]);
		buffer = buffer + "   ";
		f->Write(buffer, 3);


		CString home = m_team_names[2] + "               ";
		f->Write(home, 16);

		buffer.Format("%d", m_score[2]);
		buffer = buffer + "   ";
		f->Write(buffer, 3);
		bool pbp = true;
		int lines = GetTotalPbpResults();
		CString big_buf;
		//pDoc->m_play->m_playByPlay[lines] = m_displayString + "\n" + pDoc->m_play->m_scoreString;
		for (int i = 0; i <= lines; i++)
		{
			//		buffer = buffer + m_pbp_strings[i] + "\n";
			big_buf = big_buf + (LPCSTR)m_pbp_strings[i] + "\n";
		}
		big_buf = big_buf + "                                                                                                                                                                                                                                                                                                                                                                                                               ";
		f->Write((LPCSTR)big_buf, big_buf.GetLength());

		char buf[200001];
		memset(buf, ' ', 200000);
		f->Write(buf, 200000);
		f->Close();
		delete f;
	}


	int t1 = m_visitorIndex - 1;
	int t2 = m_homeIndex - 1;

	if (m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
	{


		for (int i = 1; i <= 15; i++)
		{
			CPlayer m_contract = avg.m_actual[t1 * 30 + i];
			avg.m_finance[t1].m_contract[i] = m_contract;
		}


		avg.m_finance[t1].GamePlayerPayroll();
		//	avg.m_finance[t1].GameScoutPayroll(avg.m_scout[t1]);
		//	avg.m_finance[t1].GameCoachPayroll(avg.m_coach[t1]);
			//avg.m_finance[t1].GameGmPayroll(avg.m_gm[t1]);

		int coach_rating1 = (avg.m_coach[t1].m_pot1Rating + avg.m_coach[t1].m_pot2Rating + avg.m_coach[t1].m_effortRating + avg.m_coach[t1].m_scoringRating + avg.m_coach[t1].m_shootingRating + avg.m_coach[t1].m_reboundingRating + avg.m_coach[t1].m_passingRating + avg.m_coach[t1].m_defenseRating) * 1;
		int coach_rating2 = (avg.m_coach[t1].m_coachPot1 + avg.m_coach[t1].m_coachPot2 + avg.m_coach[t1].m_coachEffort + avg.m_coach[t1].m_coachScoring + avg.m_coach[t1].m_coachShooting + avg.m_coach[t1].m_coachRebounding + avg.m_coach[t1].m_coachPassing + avg.m_coach[t1].m_coachDefense) * 3;
		int coach_rating3 = (avg.m_coach[t1].m_coachO + avg.m_coach[t1].m_coachP + avg.m_coach[t1].m_coachI + avg.m_coach[t1].m_coachF + avg.m_coach[t1].m_coachOD + avg.m_coach[t1].m_coachPD + avg.m_coach[t1].m_coachID + avg.m_coach[t1].m_coachFD) * 3;
		int coach_rating = (coach_rating1 + coach_rating2 + coach_rating3) * 10200 / 82 * 2;
		avg.m_finance[t1].m_coach_expenses = (long)coach_rating;



		int scout_rating = (avg.m_scout[t1].m_pot1Rating + avg.m_scout[t1].m_pot2Rating + avg.m_scout[t1].m_effortRating + avg.m_scout[t1].m_scoringRating + avg.m_scout[t1].m_shootingRating + avg.m_scout[t1].m_reboundingRating + avg.m_scout[t1].m_passingRating + avg.m_scout[t1].m_defenseRating) * 102000 / 82 * 2;
		avg.m_finance[t1].m_scout_expenses = (long)scout_rating;

		int gm_rating = (avg.m_gm[t1].m_pot1Rating + avg.m_gm[t1].m_pot2Rating + avg.m_gm[t1].m_effortRating + avg.m_gm[t1].m_scoringRating + avg.m_gm[t1].m_shootingRating + avg.m_gm[t1].m_reboundingRating + avg.m_gm[t1].m_passingRating + avg.m_gm[t1].m_defenseRating) * 102000 / 82;
		avg.m_finance[t1].m_gm_expenses = (long)gm_rating;

		avg.m_finance[t1].GameOperatingPayroll();
		avg.m_finance[t1].GameArenaPayroll();
		avg.m_finance[t1].GameMarketingPayroll();
		avg.m_finance[t1].GameTotalExpenses(m_gameType);


		for (int i = 1; i <= 15; i++)
		{
			CPlayer m_contract = avg.m_actual[t2 * 30 + i];
			avg.m_finance[t2].m_contract[i] = m_contract;
		}
		avg.m_finance[t2].GamePlayerPayroll();
		for (int i = 1; i <= 480; i++)
		{
			long money = avg.m_actual[960 + i].m_current_yr_salary;
			double salary = (double)money * 10000 / 82;
			if (avg.m_actual[960 + i].m_team_paying == (t1 + 1))
				avg.m_finance[t1].m_game_payroll = avg.m_finance[t1].m_game_payroll + (long)salary;
			else if (avg.m_actual[960 + i].m_team_paying == (t2 + 1))
				avg.m_finance[t2].m_game_payroll = avg.m_finance[t2].m_game_payroll + (long)salary;
			//reduce the season injury for fa (not related to finances)
			if ((t1 == 0 || t2 == 0) && avg.m_actual[960 + i].m_injury > 0)
				avg.m_actual[960 + i].m_injury = avg.m_actual[960 + i].m_injury - 1;
		}



		//	avg.m_finance[t2].GameScoutPayroll(avg.m_scout[t2]);
		//	avg.m_finance[t2].GameCoachPayroll(avg.m_coach[t2]);
			//avg.m_finance[t2].GameGmPayroll(avg.m_gm[t2]);

		scout_rating = (avg.m_scout[t2].m_pot1Rating + avg.m_scout[t2].m_pot2Rating + avg.m_scout[t2].m_effortRating + avg.m_scout[t2].m_scoringRating + avg.m_scout[t2].m_shootingRating + avg.m_scout[t2].m_reboundingRating + avg.m_scout[t2].m_passingRating + avg.m_scout[t2].m_defenseRating) * 102000 / 82 * 2;
		avg.m_finance[t2].m_scout_expenses = (long)scout_rating;

		gm_rating = (avg.m_gm[t2].m_pot1Rating + avg.m_gm[t2].m_pot2Rating + avg.m_gm[t2].m_effortRating + avg.m_gm[t2].m_scoringRating + avg.m_gm[t2].m_shootingRating + avg.m_gm[t2].m_reboundingRating + avg.m_gm[t2].m_passingRating + avg.m_gm[t2].m_defenseRating) * 102000 / 82;
		avg.m_finance[t2].m_gm_expenses = (long)gm_rating;

		coach_rating1 = (avg.m_coach[t2].m_pot1Rating + avg.m_coach[t2].m_pot2Rating + avg.m_coach[t2].m_effortRating + avg.m_coach[t2].m_scoringRating + avg.m_coach[t2].m_shootingRating + avg.m_coach[t2].m_reboundingRating + avg.m_coach[t2].m_passingRating + avg.m_coach[t2].m_defenseRating) * 1;
		coach_rating2 = (avg.m_coach[t2].m_coachPot1 + avg.m_coach[t2].m_coachPot2 + avg.m_coach[t2].m_coachEffort + avg.m_coach[t2].m_coachScoring + avg.m_coach[t2].m_coachShooting + avg.m_coach[t2].m_coachRebounding + avg.m_coach[t2].m_coachPassing + avg.m_coach[t2].m_coachDefense) * 3;
		coach_rating3 = (avg.m_coach[t2].m_coachO + avg.m_coach[t2].m_coachP + avg.m_coach[t2].m_coachI + avg.m_coach[t2].m_coachF + avg.m_coach[t2].m_coachOD + avg.m_coach[t2].m_coachPD + avg.m_coach[t2].m_coachID + avg.m_coach[t2].m_coachFD) * 3;
		coach_rating = (coach_rating1 + coach_rating2 + coach_rating3) * 10200 / 82 * 2;
		avg.m_finance[t2].m_coach_expenses = (long)coach_rating;



		avg.m_finance[t2].GameOperatingPayroll();
		avg.m_finance[t2].GameArenaPayroll();
		avg.m_finance[t2].GameMarketingPayroll();
		avg.m_finance[t2].GameTotalExpenses(m_gameType);


		//void CNbaDoc::SaveRevenue()

		for (int i = 1; i <= 15; i++)
		{
			CPlayer m_player = avg.m_actual[t2 * 30 + i];
			avg.m_finance[t2].m_contract[i] = m_player;
		}

		double avg_roster_value = avg.m_avg_trade_tru[0] * 15;
		avg.m_finance[t2].SetTeamRosterValue();
		int w = avg.m_standings[t2].m_win;
		int l = avg.m_standings[t2].m_loss;
		//	int hi_g = avg.m_hi_g[0];
		int hi_g = avg.m_sched.m_games_in_season;
		int visitor_current_value = (int)avg.m_finance[t1].m_current_value;
		avg.m_finance[t2].GameTicketSales(avg.m_coach[t2].m_personality, avg_roster_value, w, l, hi_g, visitor_current_value);
		avg.m_finance[t2].GameSuiteSales(avg.m_coach[t2].m_personality, avg_roster_value, w, l, hi_g, visitor_current_value);
		avg.m_finance[t2].GameClubSales(avg.m_coach[t2].m_personality, avg_roster_value, w, l, hi_g, visitor_current_value);
		avg.m_finance[t2].GameParkingSales(avg_roster_value);
		avg.m_finance[t2].GameConcessionSales(avg_roster_value);
		avg.m_finance[t2].GameTotalRevenues();

	}
	//SaveSeasonBox();
	CString buffer_pos, buffer_id, buffer, buffer0, buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7, buffer8, buffer9, buffer10, buffer11, buffer12, buffer13, buffer14, buffer15, buffer16, buffer17, buffer18, buffer19;


	int da = avg.m_sched.m_currentDay;
	int mo = avg.m_sched.m_currentMonth;
	int ga = avg.m_sched.m_currentGame;

	if (m_gameType == EXHIBITION)
	{
		da = 30;
		mo = 12;
		ga = 0;
	}


	int att = avg.m_finance[t2].m_tickets_sold +
		avg.m_finance[t2].m_clubs_sold +
		avg.m_finance[t2].m_suites_sold * 20;

	int cap = avg.m_finance[t2].m_capacity;

	int v_rec = avg.m_standings[t1].m_leagueRecord;
	int h_rec = avg.m_standings[t2].m_leagueRecord;

	int q_score[3][6];

	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			q_score[i][j] = m_quarter_score[i][j];
		}
	}


	pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".sco";
	CFile* f0 = new CFile();
	f0->Open(pFileName,
		CFile::modeReadWrite |
		CFile::modeCreate |
		CFile::modeNoTruncate |
		CFile::typeBinary |
		CFile::shareDenyNone);
	//CFile f(pFileName, CFile::modeReadWrite);

	long seek = (mo * 500 + da * 15 + ga) * 2000;
	f0->Seek(seek, CFile::begin);

	buffer1.Format("%2d", mo);
	buffer2.Format("%2d", da);
	buffer3.Format("%2d", ga);
	buffer4.Format("%2d", visitor);
	buffer5.Format("%2d", home);

	buffer6.Format("%5d", att);
	buffer7.Format("%5d", cap);
	buffer8.Format("%4d", v_rec);
	buffer9.Format("%4d", h_rec);

	buffer10.Format("%3d", q_score[1][1]);
	buffer11.Format("%3d", q_score[1][2]);
	buffer12.Format("%3d", q_score[1][3]);
	buffer13.Format("%3d", q_score[1][4]);
	buffer14.Format("%3d", q_score[1][5]);

	buffer15.Format("%3d", q_score[2][1]);
	buffer16.Format("%3d", q_score[2][2]);
	buffer17.Format("%3d", q_score[2][3]);
	buffer18.Format("%3d", q_score[2][4]);
	buffer19.Format("%3d", q_score[2][5]);


	buffer = buffer1 + buffer2 + buffer3 + buffer4 + buffer5 +
		buffer6 + buffer7 + buffer8 + buffer9 + buffer10 +
		buffer11 + buffer12 + buffer13 + buffer14 + buffer15 +
		buffer16 + buffer17 + buffer18 + buffer19;


	for (int i = 1; i <= 30; i++)
	{
		int j = i;
		if (i >= 16) j = 15 + i;

		int slot = m_playing_players_list[j];
		CPlayer* m_playerStats = new CPlayer;

		if (i == 15) slot = 1441 + t1;
		else if (i == 30) slot = 1441 + t2;
		*m_playerStats = avg.m_actual[slot];

		CString name_t = m_playerStats->GetName();
		CString name;
		int id = m_playerStats->GetID();
		CString pos = m_playerStats->GetPos();
		buffer_id.Format("%6d", id);
		name = name_t.Mid(0, 16);
		buffer0.Format("%-16s", name);
		buffer_pos.Format("%-2s", pos);


		float min_f = round((float)m_playerStats->m_game_Min / 60);
		int min = (int)min_f;
		if (m_playerStats->m_game_Min > 0 && min == 0) min = 1;

		buffer1.Format("%2d", min);
		int fgm = m_playerStats->m_game_Fgm;
		buffer2.Format("%2d", fgm);
		int fga = m_playerStats->m_game_Fga;
		buffer3.Format("%3d", fga);
		int ftm = m_playerStats->m_game_Ftm;
		buffer4.Format("%2d", ftm);
		int fta = m_playerStats->m_game_Fta;
		buffer5.Format("%2d", fta);
		int tfgm = m_playerStats->m_game_Tfgm;
		buffer6.Format("%2d", tfgm);
		int tfga = m_playerStats->m_game_Tfga;
		buffer7.Format("%2d", tfga);
		int oreb = m_playerStats->m_game_Oreb;
		buffer8.Format("%2d", oreb);
		int reb = m_playerStats->m_game_Dreb;
		buffer9.Format("%2d", reb);
		int ast = m_playerStats->m_game_Ast;
		buffer10.Format("%2d", ast);
		int stl = m_playerStats->m_game_Stl;
		buffer11.Format("%2d", stl);
		int to = m_playerStats->m_game_To;
		buffer12.Format("%2d", to);
		int blk = m_playerStats->m_game_Blk;
		buffer13.Format("%2d", blk);
		int pf = m_playerStats->m_game_Pf;
		buffer14.Format("%2d", pf);
		delete m_playerStats;

		buffer = buffer + buffer0 + buffer_pos + buffer_id + buffer1 + buffer2 + buffer3 + buffer4 + buffer5 +
			buffer6 + buffer7 + buffer8 + buffer9 + buffer10 +
			buffer11 + buffer12 + buffer13 + buffer14;
	}

	for (int i = 0; i <= 9; i++)
	{
		CString string = m_injury_string[i];
		string = string + "                                           ";
		string.Left(20);
		buffer = buffer + m_injury_string[i];
	}

	int len = buffer.GetLength();
	if (mo >= 0 && da >= 0 && ga >= 0 && mo <= 12 && da <= 30 && ga <= 16)
	{
		f0->Write(buffer, len);
	}


	f0->Close();
	delete f0;


	if (saveOk == true && m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
	{
		CString buffer;
		CFile* f1 = new CFile();
		f1->Open(pFileName, CFile::modeWrite);
		game = game + 1;
		buffer.Format("%d", game);
		buffer = buffer + "               ";
		f1->Write(buffer, 16);

		int seek = (game - 1) * 3000 + 17 + 32;
		f1->Seek(seek, CFile::begin);
		buffer.Format("%d", avg.m_sched.m_currentMonth);
		buffer = buffer + "   ";
		f1->Write(buffer, 4);
		buffer.Format("%d", avg.m_sched.m_currentDay);
		buffer = buffer + "   ";
		f1->Write(buffer, 4);
		CString vis = m_team_names[1] + "               ";
		f1->Write(vis, 16);

		buffer.Format("%d", m_score[1]);
		buffer = buffer + "   ";
		f1->Write(buffer, 3);


		CString home = m_team_names[2] + "               ";
		f1->Write(home, 16);

		buffer.Format("%d", m_score[2]);
		buffer = buffer + "   ";
		f1->Write(buffer, 3);

		buffer = "";


		for (int i = 1; i <= 30; i++)
		{
			int j = i;
			if (i >= 16) j = 15 + i;

			int slot = m_playing_players_list[j];
			CPlayer* m_playerStats = new CPlayer;

			if (i == 15)
			{
				slot = 1441 + t1;
			}
			else if (i == 30)
			{
				slot = 1441 + t2;
			}
			*m_playerStats = avg.m_actual[slot];

			CString name = m_playerStats->GetName();
			int id = m_playerStats->GetID();
			CString pos = m_playerStats->GetPos();
			name = pos + " " + name;

			buffer_id.Format("%6d", id);
			buffer0.Format("%-32s", (LPCTSTR)name);


			float min_f = round((float)m_playerStats->m_game_Min / 60);
			int min = (int)min_f;
			if (m_playerStats->m_game_Min > 0 && min == 0) min = 1;

			buffer1.Format("%4d", min);
			int fgm = m_playerStats->m_game_Fgm;
			buffer2.Format("%4d", fgm);
			int fga = m_playerStats->m_game_Fga;
			buffer3.Format("%4d", fga);
			int ftm = m_playerStats->m_game_Ftm;
			buffer4.Format("%4d", ftm);
			int fta = m_playerStats->m_game_Fta;
			buffer5.Format("%4d", fta);
			int tfgm = m_playerStats->m_game_Tfgm;
			buffer6.Format("%4d", tfgm);
			int tfga = m_playerStats->m_game_Tfga;
			buffer7.Format("%4d", tfga);
			int oreb = m_playerStats->m_game_Oreb;
			buffer8.Format("%4d", oreb);
			int reb = m_playerStats->m_game_Dreb;
			buffer9.Format("%4d", reb);
			int ast = m_playerStats->m_game_Ast;
			buffer10.Format("%4d", ast);
			int stl = m_playerStats->m_game_Stl;
			buffer11.Format("%4d", stl);
			int to = m_playerStats->m_game_To;
			buffer12.Format("%4d", to);
			int blk = m_playerStats->m_game_Blk;
			buffer13.Format("%4d", blk);
			int pf = m_playerStats->m_game_Pf;
			buffer14.Format("%4d", pf);
			delete m_playerStats;

			buffer = buffer + buffer0 + buffer_id + buffer1 + buffer2 + buffer3 + buffer4 + buffer5 +
				buffer6 + buffer7 + buffer8 + buffer9 + buffer10 +
				buffer11 + buffer12 + buffer13 + buffer14;

		}


		int len = buffer.GetLength();
		f1->Write(buffer, len);





		seek = (game - 1) * 3000 + 2501;	//500 bytes for extra box score stuff
		buffer.Format("%d", visitor);
		f1->Write(buffer, 2);
		buffer.Format("%d", (LPCTSTR)home);
		f1->Write(buffer, 2);


		char buf[6001];
		memset(buf, ' ', 6000);
		f1->Write(buf, 6000);
		f1->Close();
		delete f1;
	}



	avg.m_actual[1440 + m_visitorIndex].m_game_Min = 48;
	avg.m_actual[1440 + m_homeIndex].m_game_Min = 48;


	avg.m_finance[t1].SeasonExpenses();
	avg.m_finance[t1].SeasonRevenueRoadGame();
	avg.m_finance[t2].SeasonExpenses();
	avg.m_finance[t2].SeasonRevenues();



	for (int i = 1; i <= 64; i++)
	{

		int slot = 0;
		int index = 0;



		CPlayer* m_players = new CPlayer;
		CPlayer* m_players1 = new CPlayer;

		if (i <= 60)
		{
			slot = m_playing_players_list[i];
			index = m_playing_players_list[i];
		}
		else if (i == 61)
		{
			slot = 1440 + m_visitorIndex;
			index = 1440 + m_visitorIndex;
			avg.m_actual[slot].m_name = m_team_names[1];
		}
		else if (i == 62)
		{
			slot = 1440 + m_homeIndex;
			index = 1440 + m_homeIndex;
			avg.m_actual[slot].m_name = m_team_names[2];
		}

		else if (i == 63)
		{
			slot = 1472 + m_visitorIndex;
			index = 1440 + m_homeIndex;
			avg.m_actual[slot].m_name = m_team_names[2];
		}
		else if (i == 64)
		{
			slot = 1472 + m_homeIndex;
			index = 1440 + m_visitorIndex;
			avg.m_actual[slot].m_name = m_team_names[2];
		}






		*m_players = avg.m_actual[slot];
		*m_players1 = avg.m_actual[index];
		int gamesInjured = m_players->GetInjury();


		int games = (m_players1->m_game_Min != 0);
		int min = round(m_players1->m_game_Min / 60);
		if (m_players1->m_game_Min > 0 && min == 0) min = 1;
		int fgm = m_players1->m_game_Fgm;
		int fga = m_players1->m_game_Fga;
		int ftm = m_players1->m_game_Ftm;
		int fta = m_players1->m_game_Fta;
		int tfgm = m_players1->m_game_Tfgm;
		int tfga = m_players1->m_game_Tfga;
		int oreb = m_players1->m_game_Oreb;
		int reb = m_players1->m_game_Dreb;
		int ast = m_players1->m_game_Ast;
		int stl = m_players1->m_game_Stl;
		int to = m_players1->m_game_To;
		int blk = m_players1->m_game_Blk;
		int pf = m_players1->m_game_Pf;

		m_players1->SetInjury(gamesInjured);
		if (m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE && m_gameType != PLAYOFF)
		{
			m_players->m_sim_games = m_players->m_sim_games + games;
			m_players->m_sim_min = m_players->m_sim_min + min;
			m_players->m_sim_fgm = m_players->m_sim_fgm + fgm;
			m_players->m_sim_fga = m_players->m_sim_fga + fga;
			m_players->m_sim_ftm = m_players->m_sim_ftm + ftm;
			m_players->m_sim_fta = m_players->m_sim_fta + fta;
			m_players->m_sim_tfgm = m_players->m_sim_tfgm + tfgm;
			m_players->m_sim_tfga = m_players->m_sim_tfga + tfga;
			m_players->m_sim_oreb = m_players->m_sim_oreb + oreb;
			m_players->m_sim_reb = m_players->m_sim_reb + reb;
			m_players->m_sim_ast = m_players->m_sim_ast + ast;
			m_players->m_sim_stl = m_players->m_sim_stl + stl;
			m_players->m_sim_to = m_players->m_sim_to + to;
			m_players->m_sim_blk = m_players->m_sim_blk + blk;
			m_players->m_sim_pf = m_players->m_sim_pf + pf;
			double tmpg = (double)m_players->m_sim_min / (double)m_players->m_sim_games;
			double ampg = (double)m_players->m_min / (double)m_players->m_games * ((double)m_players->m_sim_games / (double)avg.m_sched.m_games_in_season);

			int win_happy = IntRandom(avg.m_sched.m_games_in_season); //winning affects happinesss
			if (i <= 30 && m_score[1] < m_score[2] &&
				m_players->m_winning_factor >= win_happy
				&& m_players->m_content > 1)
				m_players->m_content = m_players->m_content - 1;
			else if (i > 30 && i <= 60 && m_score[2] < m_score[1] &&
				m_players->m_winning_factor >= win_happy
				&& m_players->m_content > 1)
				m_players->m_content = m_players->m_content - 1;
			else if (i <= 30 && m_score[1] > m_score[2] &&
				m_players->m_winning_factor >= win_happy
				&& m_players->m_content < 9)
				m_players->m_content = m_players->m_content + 1;
			else if (i > 30 && i <= 60 && m_score[2] > m_score[1] &&
				m_players->m_winning_factor >= win_happy
				&& m_players->m_content < 9)
				m_players->m_content = m_players->m_content + 1;




			if (tmpg < ampg && tmpg < 36)
			{
				int tm = m_visitorIndex - 1;
				if (i > 30) tm = m_homeIndex - 1;
				int n = IntRandom(m_players->m_loyalty_factor + m_players->m_effort + (5 - m_players->m_playing_time_factor) + avg.m_coach[tm].m_personality);
				if (n < 3 && m_players->m_content > 1) m_players->m_content = m_players->m_content - 1;
			}
			else if (tmpg > ampg)
			{
				int tm = m_visitorIndex - 1;
				if (i > 30) tm = m_homeIndex - 1;
				int n = IntRandom(m_players->m_loyalty_factor + m_players->m_effort + m_players->m_playing_time_factor + avg.m_coach[tm].m_personality);
				if (n > 9 && m_players->m_content < 9) m_players->m_content = m_players->m_content + 1;
			}
		}
		else if (m_gameType == PLAYOFF)
		{

			m_players->m_po_games = m_players->m_po_games + games;
			m_players->m_po_min = m_players->m_po_min + min;
			m_players->m_po_fgm = m_players->m_po_fgm + fgm;
			m_players->m_po_fga = m_players->m_po_fga + fga;
			m_players->m_po_ftm = m_players->m_po_ftm + ftm;
			m_players->m_po_fta = m_players->m_po_fta + fta;
			m_players->m_po_tfgm = m_players->m_po_tfgm + tfgm;
			m_players->m_po_tfga = m_players->m_po_tfga + tfga;
			m_players->m_po_oreb = m_players->m_po_oreb + oreb;
			m_players->m_po_reb = m_players->m_po_reb + reb;
			m_players->m_po_ast = m_players->m_po_ast + ast;
			m_players->m_po_stl = m_players->m_po_stl + stl;
			m_players->m_po_to = m_players->m_po_to + to;
			m_players->m_po_blk = m_players->m_po_blk + blk;
			m_players->m_po_pf = m_players->m_po_pf + pf;
		}
		avg.m_actual[slot] = *m_players;



		if (i <= 64 && m_gameType != EXHIBITION && m_gameType != ALLSTAR && m_gameType != ROOKIE)
			avg.m_actual[slot].SetGameHighs(m_gameType);

		delete m_players;
		delete m_players1;
	}



	for (int i = 1; i <= 10; i++)
	{
		int index = m_starters[i];
		if (m_gameType == LEAGUE)
			avg.m_actual[index].m_starter = avg.m_actual[index].m_starter + 1;
	}


	if (m_gameType == LEAGUE || m_gameType == SINGLE_TEAM)
		m_recordbook.SetGameHighs(0, m_playing_players_list, avg.m_actual, avg.m_settings.m_currentYear);
	else if (m_gameType == PLAYOFF)
		m_recordbook.SetGameHighs(1, m_playing_players_list, avg.m_actual, avg.m_settings.m_currentYear);


	avg.m_settings.m_current_stage = 0;

}

void CEngine::InitializeAllStarGame()
{


	m_gameType = ALLSTAR;
	m_hca = 0;
	m_visitorIndex = 1;
	m_homeIndex = 2;
	m_visitor_player_offset = 0;
	m_home_player_offset = 30;


	CAllStarWeekend* asw = new CAllStarWeekend;
	asw->avg = avg;
	asw->SelectAllStarTeams();




	for (int p = 1; p <= 60; p++)
	{
		m_playing_players_list[p] = p;
		avg.m_actual[p] = asw->m_actual[p];
		avg.m_actual[p].ClearGameStats();
		if (avg.m_actual[p].m_name == "") m_playing_players_list[p] = 0;
		avg.m_actual[p].m_game_stat_slot = p;

	}


	avg.m_actual[1441].ClearGameStats();
	avg.m_actual[1442].ClearGameStats();
	delete asw;

	m_team_names[1] = avg.m_settings.m_conferenceName1;



	m_team_names[2] = avg.m_settings.m_conferenceName2;



	m_possesion_team_index[1] = 1;


	m_possesion_team_index[2] = 2;

	m_quarter = 1;



	m_score[1] = 0;
	m_score[2] = 0;

}

void CEngine::InitializeRookieGame()
{

	m_gameType = ROOKIE;
	m_hca = 0;

	m_visitorIndex = 1;
	m_homeIndex = 2;
	m_visitor_player_offset = 0;
	m_home_player_offset = 30;


	CAllStarWeekend* asw = new CAllStarWeekend;
	asw->avg = avg;
	asw->SelectRookieTeams();




	for (int p = 1; p <= 60; p++)
	{
		m_playing_players_list[p] = p;
		avg.m_actual[p] = asw->m_actual[p];
		avg.m_actual[p].ClearGameStats();
		if (avg.m_actual[p].m_name == "") m_playing_players_list[p] = 0;
		avg.m_actual[p].m_game_stat_slot = p;

	}

	avg.m_actual[1441].ClearGameStats();
	avg.m_actual[1442].ClearGameStats();

	delete asw;

	m_team_names[1] = "Rookies";



	m_team_names[2] = "Sophomores";



	m_possesion_team_index[1] = 1;


	m_possesion_team_index[2] = 2;

	m_quarter = 1;



	m_score[1] = 0;
	m_score[2] = 0;


}

int CEngine::GameMvp()
{
	int pointer = 0;
	int hi = 0;
	for (int i = 1; i <= 60; i++)
	{
		int index = m_playing_players_list[i];
		int mvp =
			avg.m_actual[index].m_game_Fgm * 2 + avg.m_actual[index].m_game_Tfgm + avg.m_actual[index].m_game_Ftm +
			avg.m_actual[index].m_game_Oreb + avg.m_actual[index].m_game_Dreb + avg.m_actual[index].m_game_Ast;
		if (mvp > hi)
		{
			pointer = avg.m_actual[index].m_temp_pointer;
			hi = mvp;
		}
	}

	return pointer;

}

void CEngine::WriteInjury(int team, int id, int g, CString desc)//change ?
{
	//	char s[17];
	int mo = avg.m_sched.m_currentMonth + 10;
	if (mo > 12) mo = mo - 12;
	CString string;
	int da = avg.m_sched.m_currentDay + 1;
	int yr = avg.m_settings.m_currentYear;
	int ty = 1;//injury


	string.Format("%2d%2d%4d%2d%6d%2d%4d%32s", mo, da, yr, ty, id, team, g, desc);
	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = string;


}


void CEngine::SetDefensiveLineup(int t, int p, int player)
{

	Defense[t][p] = player;
}

CString CEngine::SetInjuryString(int g, CString pos)
{
	if (g > 99) g = 99;
	CString str;
	if (m_injury_table[1].m_injury == "")
		str = "injury";
	else
	{

		do
		{
			int n = IntRandom(306);
			int f = IntRandom(10);

			if (m_injury_table[n].m_min <= g && m_injury_table[n].m_max >= g &&
				m_injury_table[n].m_frequency >= f && m_injury_table[n].m_frequency <= 10)
				str = m_injury_table[n].m_injury;

		} while (str == "");

	}

	return str;
}
