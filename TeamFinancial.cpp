#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 





double CTeamFinancial::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}


void CTeamFinancial::GenerateRandomFinances()
{
	m_current_value = int((double)m_stadium_value / 2*10) + IntRandom(2500);
	if(m_current_value <= m_stadium_value*10) m_current_value = m_stadium_value*10 + IntRandom(160);

	m_ticket_price = (24 + IntRandom(36)) * 10;
	m_suite_price = (250 + IntRandom(200)) * 10;
	m_club_price = (10 + IntRandom(10)) * 10;
	m_network_share = int(660000./29./82);
	m_local_tv = (40000 + IntRandom(m_current_value * 40));
	m_local_radio = (20000 + IntRandom(m_current_value * 20));
	if(m_local_radio > (m_local_tv * 1 / 2)	) m_local_radio = m_local_tv * 1/2;


	m_concessions = (15 + IntRandom(10)) * 10;
	m_parking = (4 + IntRandom(5));
	int f_a = (m_current_value + m_stadium_value*10) * 10;
	int f_s = (m_current_value + m_stadium_value*10) * 5;
	m_advertising = (10000 + IntRandom(f_a));
	m_sponsorship = (10000 + IntRandom(f_s));
	m_operating = int( ((double) m_current_value + (double) (m_stadium_value * 10)) * 1000 / 20 / 82);//number saved in 100's i.e 63 is 630 spent
	m_marketing = int( (double) m_current_value * 1000 / 50 / 82);

	m_arena = int( (double) m_current_value * 1000 / 100 / 82);

}

void CTeamFinancial::GenerateRandomArenas()
{
	m_capacity = 15000 + IntRandom(5000);
	if(Random(1) < .1) m_capacity = 12000 + IntRandom(12000);

	int f = m_capacity / 100;
	m_suites = IntRandom(f);
	f = m_capacity / 10;
	m_club_seats = m_suites * 10 + IntRandom(f);
	f = m_capacity / 4;
	m_parking_spots = m_capacity / 10 + IntRandom(f);

	
	int cost = m_capacity  + m_club_seats * 4 + m_suites * 100;
	double tmp = (double)cost / 200;
	tmp = tmp * (.8 + Random(.4));
	m_stadium_value = (int)tmp;

}

void CTeamFinancial::GenerateRandomCities()
{
	m_fan_support = IntRandom(7);
	m_economy = IntRandom(7);
	m_political_support = IntRandom(7);
	m_interest = IntRandom(7);
	m_population = IntRandom(7);
	m_cost_of_living = IntRandom(7);
	m_competition = IntRandom(7);
}



void CTeamFinancial::GamePlayerPayroll()
{
	long total_salary = 0;
	for(int i=1; i<=15; i++)
	{
		long money = m_contract[i].m_current_yr_salary;
		double salary = (double) money*10000 / 82;
		total_salary = total_salary + (long)salary;
	}
	m_game_payroll = total_salary;
}

void CTeamFinancial::SetTeamRosterValue()
{
	double total = 0;
	for(int i=1; i<=15; i++)
	{
		double value = m_contract[i].GetTradeValue();
		total = total + value;
	}

	m_team_roster_value = total;
}

void CTeamFinancial::GameTicketSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value)
{

	double price = (double) m_ticket_price / 10;
	long capacity = m_capacity - m_club_seats - m_suites*20;
	double avg_revenue = (double) 35000000 / 41;
	double avg_price = 48;
	double roster_factor = m_team_roster_value / avg_roster_value;
	int tot = w + l;
//	if( tot == 0) roster_factor = 1.5;//1st home game	
	double max_revenue = roster_factor * avg_revenue * (((double)m_stadium_value + 200) / 400);
	max_revenue = max_revenue * (((double)visitor_current_value + 8000) / 10000);

	double pct = .5;
	if(tot > 0) pct = (double)w / (double)tot;
	double f = double(tot) / (double)hi_g;//further into the season the record is more significant
	double m = .5 + pct;	
	max_revenue = max_revenue + (max_revenue * m - max_revenue) * f;
	max_revenue = max_revenue * (21 + (double) m_economy) / 25;
	max_revenue = max_revenue * (11 + (double) m_fan_support) / 15;
	max_revenue = max_revenue * (31 + (double) m_population) / 35;
	max_revenue = max_revenue * (41 + (double) (8-m_cost_of_living)) / 45;
	max_revenue = max_revenue * (51 + (double) (8-m_competition)) / 55;
	max_revenue = max_revenue * (61 + (double) personality) / 65;




	double best_price = avg_price * (21 + (double) m_economy) / 25 * roster_factor;
	best_price = best_price * (11 + (double) m_fan_support) / 15;
	best_price = best_price * (31 + (double) m_population) / 35;
	best_price = best_price * (41 + (double) (8-m_cost_of_living)) / 45;
	best_price = best_price * (51 + (double) (8-m_competition)) / 55;
	best_price = best_price * (61 + personality) / 65;
	best_price = best_price * (((double) m_stadium_value + 200)/ 400);


	double avg_expected_att = max_revenue / best_price;//

	
	double pct_factor = price / best_price;
	if(pct_factor > 1) pct_factor = best_price / price;
	
	pct_factor = (1 - pct_factor) * (1 - (double)m_interest / 8);
	double projected_revenue = max_revenue * (1 - pct_factor);
	    



	double sold = projected_revenue / price;
	sold = (.9 + Random(.2)) * sold;
	sold = sold * .98;

	m_tickets_sold = (long) sold;
	if(m_tickets_sold > capacity) m_tickets_sold = capacity;
	double ticket_revenue = (double) m_tickets_sold * price;
	m_ticket_revenue = (long) ticket_revenue;
}


void CTeamFinancial::GameClubSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value)
{
	double pct = .5;

	int tot = w + l;

	if(tot > 0) pct = (double)w / (double)tot;
	double f = (double)tot / (double)hi_g;//further into the season the record is more significant
	double m = .5 + pct;

	double price = (double) m_club_price;
	long capacity = m_club_seats;
	double avg_revenue = 2200*150;
	double avg_price = 150;
	double roster_factor = m_team_roster_value / avg_roster_value;

//	if((w+l) == 0) roster_factor = 1.5;//1st home game
//	if( tot == 0) roster_factor = 1.5;//1st home game	

	double max_revenue = roster_factor * avg_revenue * (((double)m_stadium_value + 200)/ 400);
	max_revenue = max_revenue * (((double)visitor_current_value + 8000) / 10000);
//	max_revenue = max_revenue * .8;


	max_revenue = max_revenue + (max_revenue * m - max_revenue) * f;

	max_revenue = max_revenue * (16 + (double) m_economy) / 20;
	max_revenue = max_revenue * (16 + (double) m_fan_support) / 20;
	max_revenue = max_revenue * (36 + (double) m_population) / 40;
	max_revenue = max_revenue * (26 + (double) (8-m_cost_of_living)) / 30;
	max_revenue = max_revenue * (36 + (double) (8-m_competition)) / 40;
	max_revenue = max_revenue * (46 + personality) / 50;

	double best_price = avg_price * (16 + (double) m_economy) / 20 * roster_factor;
	best_price = best_price * (16 + (double) m_fan_support) / 20;
	best_price = best_price * (36 + (double) m_population) / 40;
	best_price = best_price * (26 + (double) (8-m_cost_of_living)) / 30;
	best_price = best_price * (36 + (double) (8-m_competition)) / 40;
	best_price = best_price * (((double) m_stadium_value+200) / 400);
	best_price = best_price * (46 + (double) personality) / 50;


	double avg_expected_att = max_revenue / best_price;//

	
	double pct_factor = price / best_price;
	if(pct_factor > 1) pct_factor = best_price / price;
	
	pct_factor = (1 - pct_factor) * (1 - (double)m_interest / 8);
	double projected_revenue = max_revenue * (1 - pct_factor);
	    



	double sold = projected_revenue / price;
	sold = (.9 + Random(.2)) * sold;
	sold = sold * .98;

	m_clubs_sold = (long) sold;
	if(m_clubs_sold > capacity) m_clubs_sold = capacity;
	double club_revenue = (double) m_clubs_sold * price;
	m_club_revenue = (long) club_revenue;




}

void CTeamFinancial::GameSuiteSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value)
{
	double price = (double) m_suite_price;
	long capacity = m_suites;
	double avg_revenue = 85*3500;
	double avg_price = 3500;
	double roster_factor = m_team_roster_value / avg_roster_value;
//	if((w+l) == 0) roster_factor = 1.5;//1st home game

	int tot = w + l;
//	if( tot == 0) roster_factor = 1.5;//1st home game	

	double max_revenue = roster_factor * avg_revenue * (((double)m_stadium_value + 200)/ 400);
	max_revenue = max_revenue * (((double)visitor_current_value + 8000) / 10000);
//	max_revenue = max_revenue * .8;

	double pct = .5;
	if(tot > 0) pct = (double) w / (double) tot;
	double f = (double) tot / (double)hi_g;//further into the season the record is more significant
	double m = .5 + pct;	
	max_revenue = max_revenue + (max_revenue * m - max_revenue) * f;

	max_revenue = max_revenue * (16 + (double) m_economy) / 10;
	max_revenue = max_revenue * (26 + (double) m_fan_support) / 30;
	max_revenue = max_revenue * (26 + (double) m_population) / 30;
	max_revenue = max_revenue * (26 + (double) (8-m_cost_of_living)) / 30;
	max_revenue = max_revenue * (36 + (double) (8-m_competition)) / 40;
	max_revenue = max_revenue * (46 + (double) personality) / 50;

	double best_price = avg_price * (16 + (double) m_economy) / 10 * roster_factor;
	best_price = best_price * (26 + (double) m_fan_support) / 30;
	best_price = best_price * (26 + (double) m_population) / 30;
	best_price = best_price * (26 + (double) (8-m_cost_of_living)) / 30;
	best_price = best_price * (36 + (double) (8-m_competition)) / 40;
	best_price = best_price * (((double) m_stadium_value + 200)/ 400);
	best_price = best_price * (46 + (double) personality) / 50;


	double avg_expected_att = max_revenue / best_price;//

	
	double pct_factor = price / best_price;
	if(pct_factor > 1) pct_factor = best_price / price;
	
	pct_factor = (1 - pct_factor) * (1 - (double)m_interest / 8);
	double projected_revenue = max_revenue * (1 - pct_factor);
	    
    

	double sold = projected_revenue / price;
	sold = (.9 + Random(.2)) * sold;

	sold = sold * .98;

	m_suites_sold = (long) sold;
	if(m_suites_sold > capacity) m_suites_sold = capacity;
	double suite_revenue = (double) m_suites_sold * price;
	m_suite_revenue = (long) suite_revenue;

}

void CTeamFinancial::GameConcessionSales(double avg_roster_value)
{
	double avg_revenue = 200;
	double avg_price = 700;

	long att = m_tickets_sold + m_clubs_sold + m_suites_sold * 20;

	double roster_factor = m_team_roster_value / avg_roster_value;
	double max_revenue = roster_factor * avg_revenue;

	double price = (double) m_concessions + (double) m_ticket_price;
	long capacity = 1;

	max_revenue = max_revenue * (26 + (double) m_economy) / 30;
	max_revenue = max_revenue * (46 + (double) m_fan_support) / 50;
	max_revenue = max_revenue * (106 + (double) m_population) / 110;
	max_revenue = max_revenue * (16 + (double) (8-m_cost_of_living)) / 20;
	max_revenue = max_revenue * (106 + (double) (8-m_competition)) / 110;


	double best_price = avg_price * (26 + (double) m_economy) / 30 * roster_factor;
	best_price = best_price * (46 + (double) m_fan_support) / 40;
	best_price = best_price * (106 + (double) m_population) / 100;
	best_price = best_price * (16 + (double) (8-m_cost_of_living)) / 20;
	best_price = best_price * (106 + (double) (8-m_competition)) / 100;
	best_price = best_price * (((double) m_stadium_value + 500) / 700);

	double pct_factor = price / best_price;
	if(pct_factor > 1) pct_factor = best_price / price;
	
	pct_factor = (1 - pct_factor) * (1 - (double)m_interest / 8);
	double projected_revenue = max_revenue * (1 - pct_factor);
	    	
	double revenue = (double) att * projected_revenue;
	m_concession_revenue = (long) revenue / 10;





}

void CTeamFinancial::GameParkingSales(double avg_roster_value)
{
	double price = (double) m_parking;
	long capacity = m_capacity - m_club_seats - m_suites*20;
	double avg_revenue = 3750 * 7;
	double avg_price = 7;
	double roster_factor = m_team_roster_value / avg_roster_value;
	double max_revenue = roster_factor * avg_revenue;
	double f = (((double) m_stadium_value + 500) / 700);

	double sc = (double) m_economy*6 +
		(double) m_fan_support*1 +
		(double)m_population*6 + (double) (8-m_cost_of_living)*1 + (double) m_competition*1;



	sc = (4+sc/15)/5 * roster_factor * f;

	max_revenue = max_revenue * (6 + sc) / 10;

	double best_price = 3 + (int)sc;

	double avg_expected_att = max_revenue / best_price;
	
	double pct_factor = price / best_price;
	if(pct_factor > 1) pct_factor = best_price / price;
	
	pct_factor = (1 - pct_factor) * (1 - (double)m_interest / 8);
	double projected_revenue = max_revenue * (1 - pct_factor);
	    

	double sold = projected_revenue / price;
	sold = (.9 + Random(.2)) * sold;
	sold = sold * .98;

	m_parking_sold = (long) sold;
	if(m_parking_sold > m_parking_spots) m_parking_sold = m_parking_spots;
	double parking_revenue = (double) m_parking_sold * price;
	m_parking_revenue = (long) parking_revenue;

}

void CTeamFinancial::GameTotalRevenues()
{
	m_game_total_revenue  =
		m_ticket_revenue + 
	+ m_suite_revenue
	+ m_club_revenue
	+ m_parking_revenue
	+ m_concession_revenue

	+ (m_network_share*1000)
	+ m_local_tv
	+ m_local_radio
	+ m_advertising
	+ m_sponsorship;
}

void CTeamFinancial::SeasonRevenues()
{
	m_season_att = m_season_att + m_tickets_sold;
	m_att_revenue = m_att_revenue + m_ticket_revenue; 
//	m_season_payroll =    m_season_payroll +    m_game_payroll;
	m_season_suites_sold =    m_season_suites_sold +    m_suites_sold;
	m_season_clubs_sold =    m_season_clubs_sold +    m_clubs_sold;
	m_season_parking_sold =    m_season_parking_sold +    m_parking_sold;
	m_season_suite_revenue =    m_season_suite_revenue +    m_suite_revenue;
	m_season_club_revenue =    m_season_club_revenue +    m_club_revenue;
	m_season_parking_revenue =    m_season_parking_revenue +    m_parking_revenue;
	m_season_concession_revenue =    m_season_concession_revenue +    m_concession_revenue;
	m_season_total_revenue =    m_season_total_revenue +    m_game_total_revenue;
	m_home_games = m_home_games + 1;
}

void CTeamFinancial::SetEndOfSeasonTicketPrice(int personality, double avg_roster_value, int w, int l, int hi_g)
{
	double roster_factor = m_team_roster_value / avg_roster_value;

	double price = (double) m_ticket_price / 10;
	double avg_price = 48;

	double best_price = avg_price * (21 + (double) m_economy) / 25 * roster_factor;
	best_price = best_price * (11 + (double) m_fan_support) / 15;
	best_price = best_price * (31 + (double) m_population) / 35;
	best_price = best_price * (41 + (double) (8-m_cost_of_living)) / 45;
	best_price = best_price * (51 + (double) (8-m_competition)) / 55;
	best_price = best_price * (61 + (double) personality) / 65;
	best_price = best_price * (((double) m_stadium_value + 200) / 400);	
	
	double factor = (best_price - price);
	m_ticket_price = m_ticket_price + (int)factor;
	m_ticket_price =  int((double)m_ticket_price / 10) * 10;

	if(m_ticket_price < 50) m_ticket_price = 50;
}

void CTeamFinancial::SetEndOfSeasonSuitePrice(int personality, double avg_roster_value, int w, int l, int hi_g)
{
	double roster_factor = m_team_roster_value / avg_roster_value;

	double price = (double) m_suite_price ;
	double avg_price = 3500;


	double best_price = avg_price * (16 + (double) m_economy) / 20 * roster_factor;
	best_price = best_price * (26 + (double) m_fan_support) / 30;
	best_price = best_price * (26 + (double) m_population) / 30;
	best_price = best_price * (26 + (double) (8-m_cost_of_living)) / 30;
	best_price = best_price * (36 + (double) (8-m_competition)) / 40;
	best_price = best_price * (((double) m_stadium_value + 200)/ 400);	
	best_price = best_price * (46 + (double) personality) / 50;
	
	double factor = (best_price - price) / 10;
	m_suite_price = m_suite_price + (int)factor;
	if(m_suite_price < 500) m_suite_price = 500;

}

void CTeamFinancial::SetEndOfSeasonClubPrice(int personality, double avg_roster_value, int w, int l, int hi_g)
{

	double roster_factor = m_team_roster_value / avg_roster_value;

	double price = (double) m_club_price ;
	double avg_price = 150;

	double best_price = avg_price * (16 + (double) m_economy) / 20 * roster_factor;
	best_price = best_price * (16 + (double) m_fan_support) / 20;
	best_price = best_price * (36 + (double) m_population) / 40;
	best_price = best_price * (26 + (double) (8-m_cost_of_living)) / 30;
	best_price = best_price * (36 + (double) (8-m_competition)) / 40;
	best_price = best_price * (((double) m_stadium_value + 200)/ 400);
	best_price = best_price * (46 + (double) personality) / 50;

	double factor = (best_price - price) / 10;
	m_club_price = m_club_price + (int)factor;
	if(m_club_price < 15) m_club_price = 15;


}

void CTeamFinancial::SetEndOfSeasonConcessionPrice(double avg_roster_value)
{
	double roster_factor = m_team_roster_value / avg_roster_value;

	double price = (double) m_concessions + (double) m_ticket_price;
	double avg_price = 700;



	double best_price = avg_price * (26 + (double) m_economy) / 30 * roster_factor;
	best_price = best_price * (46 + (double) m_fan_support) / 50;
	best_price = best_price * (106 + (double) m_population) / 110;
	best_price = best_price * (16 + (double) (8-m_cost_of_living)) / 20;
	best_price = best_price * (106 + (double) (8-m_competition)) / 110;
	best_price = best_price * (((double) m_stadium_value + 200)/ 400);
	
	double factor = (best_price - price) / 10;
	m_concessions = m_concessions + (int)factor;
	m_concessions =  int((double)m_concessions / 10) * 10;

	if(m_concessions < 50) m_concessions = 50;

}

void CTeamFinancial::SetEndOfSeasonSalaryCap(int player_spending)
{
	double f =  (25 + (double)player_spending) / 100;
	m_owner_salary_cap = long ( (double) m_current_value * f * 100000);
}

void CTeamFinancial::SeasonRevenueRoadGame()
{
	m_game_total_revenue  =

	(m_network_share*1000)
	+ m_local_tv
	+ m_local_radio
	+ m_advertising
	+ m_sponsorship;

	m_season_total_revenue =    m_season_total_revenue +    m_game_total_revenue;

}

void CTeamFinancial::GameTotalExpenses(int gameType)
{
	if(gameType != 4)
	{
		m_game_total_expenses  = m_game_payroll
		+ m_scout_expenses
		+ m_coach_expenses
		+ m_gm_expenses
		+ m_operating_expenses
		+ m_arena_expenses
		+ m_marketing_expenses;
	}
	else
	{
		m_game_total_expenses  = m_operating_expenses + m_arena_expenses + m_marketing_expenses;
	}

}

void CTeamFinancial::SeasonExpenses()
{
	m_season_payroll = m_season_payroll  + m_game_payroll; 
	m_season_scout_expenses = m_season_scout_expenses + m_scout_expenses;
	m_season_coach_expenses = m_season_coach_expenses  + m_coach_expenses;
	m_season_gm_expenses = m_season_gm_expenses + m_gm_expenses;
	m_season_operating_expenses = m_season_operating_expenses + m_operating_expenses;
	m_season_arena_expenses = m_season_arena_expenses + m_arena_expenses;
	m_season_marketing_expenses = m_season_marketing_expenses + m_marketing_expenses;
	m_season_total_expenses = m_season_total_expenses + m_game_total_expenses;

}


void CTeamFinancial::GameScoutPayroll()
{
}

void CTeamFinancial::GameCoachPayroll()
{
		
}

void CTeamFinancial::GameGmPayroll()
{

}

void CTeamFinancial::GameOperatingPayroll()
{
	double exp = .8 + Random(.4);
	exp = (double)m_operating * 102 * exp;
	m_operating_expenses = (long) exp;
}

void CTeamFinancial::GameArenaPayroll()
{
	double exp = .8 + Random(.4);
	exp = (double)m_arena * 100 * exp;
	m_arena_expenses = (long) exp;

}

void CTeamFinancial::GameMarketingPayroll()
{
	double exp = .8 + Random(.4);
	exp = (double)m_marketing * 102 * exp;
	m_marketing_expenses = (long) exp;
}

void CTeamFinancial::SetEndOfSeasonValue()
{
	long profit = m_season_total_revenue - m_season_total_expenses; 
	m_current_value = m_current_value + profit/100000;
	if(m_current_value < 500) m_current_value = 500;
	else if(m_current_value > 7500) m_current_value = 7500;
}



void CTeamFinancial::PossibleMoveCity( 
			int political_support, int economy,
			int fan_support, int cost_of_living,
			int population, int interest,
			int competition, int city_cost)
{

	bool move = false;
	competition = 8 - competition;
	cost_of_living = 8 - cost_of_living;
	int sc = political_support*7 + economy*6 +
			fan_support*5 + cost_of_living*4 +
			population*3 + interest*2 +
			competition*1;

	double fa = (double) m_current_value * (double)sc / 28;

	int factor = (int)fa - city_cost * 20;
	int n = IntRandom(25000);
	if(n <= factor)
	{
		move = true;
		m_possible_move_city = move;
		if(move == true) PossibleMoveYears();
		else m_move_years = 0;
		m_possible_move_score = factor;
	}
}

void CTeamFinancial::PossibleMoveYears()
{
	m_possible_move_years = IntRandom(3) + 3;//change me
}

void CTeamFinancial::SetEndOfSeasonArenaValue()
{
	double avg_team_value = 175;
	double current_team_value = (double) m_current_value / 10;
	double factor = 1 - avg_team_value / current_team_value * .05;
	double new_arena_value = (double) m_stadium_value * factor;
	m_stadium_value = (int)new_arena_value - 1 + IntRandom(2);
	if(m_stadium_value < 10) m_stadium_value = 10;
}

void CTeamFinancial::SetEndOfSeasonParkingPrice(double avg_roster_value)
{
	double roster_factor = m_team_roster_value / avg_roster_value;

	double price = (double) m_parking;
	double avg_price = 7;
	double best_price = avg_price * (6 + (double) m_economy) / 10;
	
	double sc = (double) m_economy*6 +
		(double) m_fan_support*1 +
		(double)m_population*6 + (double) (8-m_cost_of_living)*1 + (double) (8-m_competition)*1;

	double f = (((double) m_stadium_value + 500) / 700);

	sc = (4+sc/15)/5 * roster_factor * f;

	m_parking = 3 + (int)sc;

	if(m_parking < 1) m_parking = 1;
}

void CTeamFinancial::SetEndOfSeasonMiscExpenses()
{

	double profit_pct = (double)m_season_total_revenue / (double)m_season_total_expenses ;


	m_operating = int( (double) m_current_value * 1000 / 20 / 82);//number saved in 100's i.e 63 is 630 spent
	m_arena = int( (double) m_stadium_value * 10000 / 100 / 82);
	m_marketing = int( (double) m_current_value * 1000 / 50 / 82);

}



void CTeamFinancial::SetEndOfSeasonMiscRevenues()
{
	if(m_season_total_expenses != 0)
	{
	double profit_pct = (double)m_season_total_revenue / (double) m_season_total_expenses ;
//use records and city ratings to set below as well
	m_network_share = m_network_share;

	double sc = (double) m_economy*3 + (double)m_interest*4 +
		(double) m_fan_support*2 +
		(double)m_population*2 + (double) (8-m_cost_of_living)*1
		+ (double) (8-m_competition)*2 + (double) m_political_support * 1;

	sc = (4 + sc/60) / 5;


	m_local_tv = (long)((double) m_local_tv * profit_pct * sc);
	m_local_radio = (long)((double)m_local_radio * profit_pct * sc);

	sc = (double) m_economy*3 +
		(double) m_fan_support*2 + (double)m_interest*2 +
		(double)m_population*1 + (double) (8-m_cost_of_living)*2
		+ (double) (8-m_competition)*1 + (double) m_political_support * 1;

	sc = sc/48;

	sc = (4 + sc/48) / 5;




	
	m_advertising = (long)((double)m_advertising * profit_pct * sc);
	m_sponsorship = (long)((double)m_sponsorship * profit_pct * sc);

	if( ((double)m_local_tv) >= ((double)m_current_value/.03)) 
		m_local_tv = (long)((double) m_current_value/.03);
	if( ((double)m_local_radio) >= ((double)m_current_value/.06)) 
		m_local_radio = (long)((double) m_current_value/.06);
	if( ((double)m_advertising) >= ((double)m_current_value/.08)) 
		m_advertising = (long)((double) m_current_value/.08);
	if( ((double)m_sponsorship) >= ((double)m_current_value/.12)) 
		m_sponsorship = (long)((double) m_current_value/.12);




	}

	
}

void CTeamFinancial::SetEndOfSeasonCityAdjustments(long last_year_total_revenue)
{
	if(m_season_total_expenses != 0 && last_year_total_revenue != 0)
	{
	double profit_pct = (double)m_season_total_revenue / (double)m_season_total_expenses;
	double revenue_increase_pct = (double)m_season_total_revenue / (double) last_year_total_revenue;
	



	if(revenue_increase_pct < 1)
	{
		double f = 1 - revenue_increase_pct;
		if(Random(1) < f) m_fan_support = m_fan_support - 1;
		if(Random(1) < f) m_economy = m_economy - 1;
		if(Random(1) < f) m_cost_of_living = m_cost_of_living + 1;
		if(Random(1) < f) m_political_support = m_political_support - 1;
		if(Random(1) < f) m_interest = m_interest - 1;
		if(Random(1) < f) m_population = m_population - 1;
		if(Random(1) < f) m_competition = m_competition + 1;
	}
	else if(revenue_increase_pct >= 1)
	{
		double f = revenue_increase_pct - 1;
		if(Random(1) < f) m_fan_support = m_fan_support + 1;
		if(Random(1) < f) m_economy = m_economy + 1;
		if(Random(1) < f) m_cost_of_living = m_cost_of_living - 1;
		if(Random(1) < f) m_political_support = m_political_support + 1;
		if(Random(1) < f) m_interest = m_interest + 1;
		if(Random(1) < f) m_population = m_population + 1;
		if(Random(1) < f) m_competition = m_competition - 1;
	}
	if(m_fan_support < 1) m_fan_support = 1;
	else if(m_fan_support > 7) m_fan_support = 7;

	if(m_economy < 1) m_economy = 1;
	else if(m_economy > 7) m_economy = 7;

	if(m_cost_of_living < 1) m_cost_of_living = 1;
	else if(m_cost_of_living > 7) m_cost_of_living = 7;

	if(m_political_support < 1) m_political_support = 1;
	else if(m_political_support > 7) m_political_support = 7;

	if(m_interest < 1) m_interest = 1;
	else if(m_interest > 7) m_interest = 7;

	if(m_population < 1) m_population = 1;
	else if(m_population > 7) m_population = 7;

	if(m_competition < 1) m_competition = 1;
	else if(m_competition > 7) m_competition = 7;

	}
}

void CTeamFinancial::ClearBudgetData()
{

		m_home_games = 0;
		m_season_att = 0;
		m_season_suites_sold = 0;
		m_season_clubs_sold = 0;
		m_att_revenue = 0;
		m_season_suite_revenue = 0;
		m_season_club_revenue = 0;
		m_season_concession_revenue = 0;
		m_season_parking_revenue = 0;
		m_season_total_revenue = 0;
		m_season_payroll = 0;
		m_season_scout_expenses = 0;
		m_season_coach_expenses = 0;
		m_season_gm_expenses = 0;
		m_season_operating_expenses = 0;
		m_season_arena_expenses = 0;
		m_season_marketing_expenses = 0;
		m_season_total_expenses = 0;
}
