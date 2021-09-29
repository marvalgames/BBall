#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef Future_h
#include "Future.h"
#define Future_h
#endif 





void CFuture::UpdateFutureData(int i)
{
	//moving also means newe arena

	m_move_year = m_move_year - 1;
	m_yrs_since_move = m_yrs_since_move - 1;
	if(m_yrs_since_move == -1) m_yrs_since_move = 0;


	if(m_move_year == -1 || m_yrs_since_move > 0)
	{
		m_moving = false;//not moving
	}

	if(m_move_year == -1) m_move_year = 0;
	
	else if(m_move_year == 0)//moving now
	{
		m_moving = true;
		m_yrs_since_move = 15;
	}
		
	if(m_move_year > 0)
	{
		m_yrs_since_move = 15;
		m_paying_for_arena = true;
	}
	else
		m_paying_for_arena = false;

	//other moving but not this year

}

void CFuture::SetGameNewArenaExpense()
{
    int yrs_pay = m_initial_move_year - 1;
    if(yrs_pay > 0)
    {
	    double f = (double)m_team_cost / (double) yrs_pay * 10000 / 82;
	    m_game_new_arena_expense = (int) f;
	}
	else
	    m_game_new_arena_expense = 0;
}

void CFuture::SetDraftChart(int team, int trading_team)
{

	for(int i=1; i<= m_own[team].m_number_proposed_picks; i++)
	{
		int n = m_own[team].m_proposed_picks[i];
		int y = n / 1000;
		int r = (n - y*1000) / 100;
		int p = n - (y*1000 + r*100);
		m_own[0].m_draft_chart[y][r][p] = trading_team;
	}


}

void CFuture::SetDraftChartComputerTrades(int team, int value_picks)
{
	int n = value_picks;
	int y = n / 1000;
	int r = (n - y*1000) / 100;
	int p = n - (y*1000 + r*100);
	m_own[0].m_draft_chart[y][r][p] = team;	
}
