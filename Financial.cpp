#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef Financial_h
#include "Financial.h"
#define Financial_h
#endif 








double CFinancial::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}



void CFinancial::GenerateComputerProposals(CString control[33])
{

for(int i=0; i<m_number_teams; i++)
{
	if(control[i] == "Player") continue;

	int t = IntRandom(100) - 1;
	

	if(	(m_finance[t].m_team_name != "" && i != t) || (m_future[i].m_yrs_since_move > 0)
		|| (m_future[i].m_proposal_made == true) || (m_future[i].m_move_year > 0)) continue;
		
	

	int current_city_score = m_finance[i].m_economy +
		m_finance[i].m_fan_support + m_finance[i].m_political_support; 

	int proposed_city_score = m_finance[t].m_economy +
		m_finance[t].m_fan_support + m_finance[t].m_political_support; 

//	double val =  (double) m_finance[t].m_stadium_value;
	double ratio1 = (double)proposed_city_score / (double)current_city_score;
//	double ratio2 = (double) 200 / val - 1;
	if(ratio1 < 0) ratio1 = 0;
//	if(ratio2 < 0) ratio2 = 0;
//	double ratio = ratio1 + ratio2;
	double possible = Random(ratio1);
	if(ratio1 < 1.2){ t=i; possible = 1.2;}
	if(possible >= 1.2)
	{
		m_finance[i].m_possible_move_city = true;
		m_finance[i].m_possible_new_city = t;
		m_finance[i].PossibleMoveCity( 
			m_finance[t].m_political_support, m_finance[t].m_economy,
			m_finance[t].m_fan_support, m_finance[t].m_cost_of_living,
			m_finance[t].m_population, m_finance[t].m_interest,
			m_finance[t].m_competition, m_future[i].m_city_cost);
	}







}


for(int i=0; i<m_number_teams; i++)
{

//	if(control[i] == "Player") continue;
	

	bool must_build = false;

	int p_city = m_finance[i].m_possible_new_city;
	if(p_city == -1) continue;

	int current_arena_score = m_finance[i].m_stadium_value;
	if(control[i] == "Player" && p_city != i)
		current_arena_score = int( (double)m_finance[i].m_current_value / 10.);




	int j = IntRandom(current_arena_score);
	if(m_finance[i].m_possible_move_city == true) must_build = true;

	if(control[i] == "Player" && j <= 50)
	{
		m_finance[i].m_possible_new_city = -1;
		m_finance[i].m_possible_move_city = false;
	}

	if(control[i] == "Player") continue;

	if( j >= 75 && must_build == true) must_build = false;

	
	if(m_future[i].m_yrs_since_move > 0 || m_future[i].m_move_year > 0 || m_future[i].m_proposal_made == true) continue;
		





	if(j <= 50 || must_build == true)
	{//25000, 250, 5000, 7500

		if(must_build == false || p_city == -1) p_city = i;

		m_finance[i].m_possible_move_city = true;
		m_finance[i].m_possible_new_city = p_city;
		m_finance[i].PossibleMoveCity( 
			m_finance[p_city].m_political_support, m_finance[p_city].m_economy,
			m_finance[p_city].m_fan_support, m_finance[p_city].m_cost_of_living,
			m_finance[p_city].m_population, m_finance[p_city].m_interest,
			m_finance[p_city].m_competition, m_future[i].m_city_cost);

	    int capacity = m_finance[i].m_capacity;
	    int club_seats = m_finance[i].m_club_seats;
	    int suites = m_finance[i].m_suites;
	    int spots = m_finance[i].m_parking_spots;


		int factor = 25000 - capacity;
		if(factor < 0) factor = 0;
		m_finance[i].m_possible_capacity = capacity + IntRandom(factor);
		if(m_finance[i].m_possible_capacity > 20000)
			m_finance[i].m_possible_capacity = 18000 + IntRandom(4000);

		factor = 300 - suites;
		if(factor < 0) factor = 0;
		m_finance[i].m_possible_suites = suites + IntRandom(factor);

		factor = 5000 - club_seats;
		if(factor < 0) factor = 0;
		m_finance[i].m_possible_club_seats = club_seats + IntRandom(factor);

		factor = 6000 - spots;
		if(factor < 0) factor = 0;
		m_finance[i].m_possible_parking_spots = spots + IntRandom(factor);

	    int p_capacity = m_finance[i].m_possible_capacity;
	    int p_club_seats = m_finance[i].m_possible_club_seats;
	    int p_suites = m_finance[i].m_possible_suites;
	    int p_spots = m_finance[i].m_possible_parking_spots;



	    int cost = p_capacity  + p_club_seats * 4 + p_suites * 100;
		double f = Random(.1);//increase up to 10%
	    double tmp = (double)cost / 200 * (1+f);
	    cost = (int) tmp;
		int pct = 50 + m_finance[i].m_current_value / 100;
		if(pct > 90) pct = 90 + IntRandom(9);
	    double tmp_city_cost = (double) pct / 100 * tmp;
	    double tmp_team_cost = tmp - tmp_city_cost;

	    int team_cost = (int) tmp_team_cost;
	    int city_cost = (int) tmp_city_cost;

	    m_future[i].m_team_cost = team_cost;
	    m_future[i].m_city_cost = city_cost;


	}
	else
	{
		m_finance[i].m_possible_new_city = -1;
		m_finance[i].m_possible_move_city = false;
	}


}

}



