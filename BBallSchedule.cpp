#include "stdafx.h"
#include "bballschedule.h"

void CBBallSchedule::GetNextGame(bool playoff)
{
	bool found = false;
	for(int i=0; i<=12; i++)
	{
		if(i<=12 && m_regular_season_ended == 1) continue;
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
				if(m_game_score[i][j][k] == 0 && m_schedule[i][j][k] != 0 && found == false)
				{
						m_currentMonth = i;
						m_currentDay = j;
						m_currentGame = k;
						found = true;
				}
			}
		}
	}
}

int CBBallSchedule::GetCurrentPlayoffDay(int &last_day)
{

	bool found = false;
	int playoff_day = 0;
	int i=12;
//	int last_day_completed = -1;
	last_day = -1;
		for(int j=0; j<=30; j++)
		{
			bool all_played = true;
			bool game_on_day = false;
			for(int k=0; k<=15; k++)
			{
				//if(m_game_score[i][j][k] != 0) last_day = j;
				if(m_schedule[i][j][k] != 0) game_on_day = true;//game scheduled in this day
				if(m_schedule[i][j][k] > 0 && m_game_score[i][j][k] == 0) all_played = false;
			}
			if(all_played == true && game_on_day == true) last_day = j;
		}


		for(int j=0; j<=30; j++)
		{
			if(found == true) continue;
			bool game_on_day = false;
			if(m_schedule[i][j][0] != 0) game_on_day = true;//game scheduled in this day
			if(game_on_day ==  false) continue;
			bool games_played = false;

			for(int k=0; k<=15; k++)
			{
				if(m_game_score[i][j][k] != 0)
				{
					games_played = true;
					playoff_day = j;
			//		last_day = j;
				}
			}

			if(games_played == false)
			{
				playoff_day = j;
				found = true;
			}
		}

		//if(m_currentRound == 1 && playoff_day <= 6) playoff_day = 7;
		if(m_currentRound == 2 && playoff_day <= 6) playoff_day = 7;
		else if(m_currentRound == 3 && playoff_day <= 13) playoff_day = 14;
		else if(m_currentRound == 4 && playoff_day <= 20) playoff_day = 21;

		return playoff_day;
}


void CBBallSchedule::ClearSchedule()
{
	bool found = false;
	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
				m_game_score[i][j][k] = 0;
				if(i == 12) m_schedule[i][j][k] = 0;
			}
		}
	}

	GetNewSeasonAllstarDayEtc();

}

void CBBallSchedule::GetNewSeasonAllstarDayEtc()
{


		int last_da = 0;
		int last_mo = 0;
		int last_ga = 0;
		int cur_mo = -1;
		int cur_da = -1;
		int co = 0;
		int asd_mo = -1;
		int asd_da = -1;
		int asd_ga = -1;
		int first_mo = -1;
		int first_da = -1;
		int first_ga = -1;
		bool done = false;			
		int day_with_no_games = 0;
		bool season_start = false;
		int gam = 0;

		int days_in_season = 0;


		for(int i = 0; i <= 11; i++ )
		{
			for(int  j = 0; j <= 30; j++ )
			{
				bool games_on_this_day = false;

				for(int  k = 0; k <= 15; k++ )
				{
					int game = m_schedule[i][j][k];
					if(game > 0 && games_on_this_day == false)
					{
						days_in_season = days_in_season + 1;
						games_on_this_day = true;
					}
					int one_team = game / 100;
					if(one_team == 1)
						gam = gam + 1;

				}
			
			}
		}		


		m_games_in_season = gam*2;
		bool dead_found = false;

		for(int i = 0; i <= 11; i++ )
		{
			for(int  j = 0; j <= 30; j++ )
			{
				int games_on_this_day = 0;

				for(int  k = 0; k <= 15; k++ )
				{
					int game = m_schedule[i][j][k];
					if(game > 0)
					{
						if(first_da == -1) first_da = j;
						if(first_mo == -1) first_mo = i;
						if(first_ga == -1) first_ga = k;
						last_mo = i;
						last_da = j;
						last_ga = k;
						games_on_this_day = games_on_this_day + 1;
						day_with_no_games = 0;
						season_start = true;
					}
					//schedule.m_schedule[i][j][k] = game;

					int one_team = game / 100;
					if(one_team == 1)
						co = co + 1;
					double ti = (double)co / (double)gam;

					if(dead_found == false && ti > (45./82.))
					{
						dead_found = true;
						m_dead_mo = i;
						m_dead_da = j;
					}
				
					if(asd_mo == -1 && done == false)
					{
						if(ti > (45./82.) && last_da < 27)
						{
							asd_mo = last_mo;
							asd_da = last_da;
			
						}
					}



					int score = m_game_score[i][j][k];
					if(score > 0) m_season_started = true;
					
					if(game > 0 && score == 0 && cur_mo == -1)
					{
						cur_mo = i;
						cur_da = j;
					}

				}
				if(games_on_this_day == 0 && co < gam)
				{
					day_with_no_games = day_with_no_games + 1;
					if(day_with_no_games == 3 && done == false && season_start == true)
					{
						if(last_da < 26)
						{
							done = true;
							asd_mo = last_mo;
							asd_da = last_da + 2;
							if(asd_da == -1) asd_da=0;
							asd_ga = -1;
						}
						else if(last_da >= 26)
						{
							done = true;
							asd_mo = last_mo + 1;
							asd_da = 0;
							asd_ga = -1;
						}

					}
				}

				if(asd_mo >= 0 && asd_da >= 0 && asd_ga < 0) asd_ga = last_ga;
			
			}
		}		

		m_asw_mo = asd_mo;
		m_asw_da = asd_da;
		m_asw_ga = asd_ga;

	m_last_da = last_da;
	m_last_mo = last_mo;
	m_last_ga = last_ga;
	if(m_game_score[last_mo][last_da][last_ga] > 0) 
		m_regular_season_ended = true;
	else
		m_regular_season_ended = false;

	m_first_da = first_da;
	m_first_mo = first_mo;
	m_first_ga = first_ga;
	if(cur_mo < 0) cur_mo = 12;
	if(cur_da < 0) cur_da = 0;
	m_currentMonth = cur_mo;
	m_currentDay = cur_da;
	m_days_in_season = days_in_season;



		

}

int CBBallSchedule::DaysElapsed(int team)
{
	int elapsed = 0;
//CString months[] = {"Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep"}
	int days[] = {31,30,31,31,28,31,30,31,30,31,31,30};
	int co = -1;
	for(int i = m_currentMonth; i >= 0; i--)
	{
		int da = days[i];
		for(int j = da; j >= 0; j--)
		{
			co = co + 1;
			if(elapsed > 0) continue;
			for(int k=0; k<=16; k++)
			{
				int ga = m_schedule[i][j][k];
				int v = ga / 100;
				int h = ga - v*100;
				if((v == team || h == team) && co >= 1) elapsed = co;
			}
					
		}
	}

	return elapsed;
}


int CBBallSchedule::DaysSinceSeasonEnd()
{

	int elapsed = 0;
//CString months[] = {"Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep"}
	int days[] = {31,30,31,31,28,31,30,31,30,31,31,30};
	int co = -1;
	int reg_da = 0;
	for(int i = 0; i <= 11; i++)
	{
		int da = days[i];
		for(int j = 0; j <= da; j++)
		{
			bool played = false;
			for(int k=0; k<=16; k++)
			{
				int ga = m_schedule[i][j][k];
				if(ga > 0 && played == false)
				{
					reg_da = reg_da + 1;
					played = true;
				}
			}
		}
					
	}
	

	int po_da = 0;
	for(int i = 1; i <= 28; i++)
	{
			if(po_da > 0) continue;
			bool find = false;
			for(int k=0; k<=16; k++)
			{
				int ga = m_schedule[12][i][k];
				int sc = m_game_score[12][i][k];
				if(ga > 0 && sc > 0) find = true;
			}
			if(find == false) po_da = i*3;//total playoff days 
	}
	
	elapsed = 366 - (po_da + reg_da);
	return elapsed;


}

/*bool PlayoffDayCompleted()
{
	int po_da = 0;
	int i = m_currentDay;

	bool find = false;
	for(int k=m_currenGame + 1; k<=16; k++)
	{
		int ga = m_schedule[12][i][k];
		int sc = m_game_score[12][i][k];
		if(ga > 0 && sc > 0) find = true;
	}
	return find;
}*/