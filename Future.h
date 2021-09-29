//#ifndef TeamFinancial_h
//#include "TeamFinancial.h"
//#define TeamFinancial_h
//#endif

#ifndef Own_h
#include "Own.h"
#define Own_h
#endif

class CFuture: public CObject
{

	
public:
	void SetDraftChartComputerTrades(int team, int value_picks);
	COwn m_own[33];
	void SetDraftChart(int team, int trading_team);
	void SetGameNewArenaExpense();
//	CTeamFinancial m_finance;
	void UpdateFutureData(int i);




	int m_move_year;
	int m_new_city;
	int m_capacity;
	int m_suites;
	int m_club_seats;
	int m_parking_spots;
    int m_team_cost;
	int m_city_cost;
	int m_total_cost;
	bool m_moving;
	int m_game_new_arena_expense;
	bool m_paying_for_arena;
	int	m_yrs_since_move;
	bool m_proposal_made;
	int m_original_slot;
	int m_initial_move_year;

	CFuture()
	{
	    m_move_year = 0;
	    m_new_city = 0;
	    m_capacity = 0;
	    m_suites = 0;
	    m_club_seats = 0;
		m_parking_spots = 0;
        m_team_cost = 0;
	    m_city_cost = 0;
		m_total_cost = 0;
		m_moving = false;
		m_game_new_arena_expense = 0;
		m_paying_for_arena = false;
		m_yrs_since_move = 0;
		m_proposal_made = false;
		m_original_slot = 0;
		m_initial_move_year = 0;


	}
	~CFuture(){}

	//copy constructor
	CFuture( const CFuture& a ) 
	{ 
		m_moving = a.m_moving;
	    m_move_year = a.m_move_year;
	    m_new_city = a.m_new_city;
	    m_capacity = a.m_capacity;
	    m_suites = a.m_suites;
	    m_club_seats = a.m_club_seats;
		m_parking_spots = a.m_parking_spots;
        m_team_cost = a.m_team_cost;
	    m_city_cost = a.m_city_cost;
		m_total_cost = a.m_total_cost;
		m_game_new_arena_expense = a.m_game_new_arena_expense;
		m_paying_for_arena = a.m_paying_for_arena;
		m_yrs_since_move = a.m_yrs_since_move;
		m_proposal_made = a.m_proposal_made;
		m_original_slot = a.m_original_slot;
		m_initial_move_year = a.m_initial_move_year;




	}

	const CFuture& operator=( const CFuture& a )
    {
		m_moving = a.m_moving;
	    m_move_year = a.m_move_year;
	    m_new_city = a.m_new_city;
	    m_capacity = a.m_capacity;
	    m_suites = a.m_suites;
	    m_club_seats = a.m_club_seats;
		m_parking_spots = a.m_parking_spots;        
		m_team_cost = a.m_team_cost;
	    m_city_cost = a.m_city_cost;
		m_total_cost = a.m_total_cost;
		m_game_new_arena_expense = a.m_game_new_arena_expense;
		m_paying_for_arena = a.m_paying_for_arena;
		m_yrs_since_move = a.m_yrs_since_move;
		m_proposal_made = a.m_proposal_made;
		m_original_slot = a.m_original_slot;
		m_initial_move_year = a.m_initial_move_year;






		return *this;
	}
	
private:



};