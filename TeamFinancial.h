

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 


class CTeamFinancial: public CObject
{

	
public:
	void ClearBudgetData();
	void SetEndOfSeasonCityAdjustments(long last_year_total_revenue);
	void SetEndOfSeasonMiscRevenues();

	void SetEndOfSeasonParkingPrice( double avg_roster_value);
	void SetEndOfSeasonArenaValue();

	void PossibleMoveCity( int political_support, int economy,
			int fan_support, int cost_of_living,
			int population, int interest,
			int competition, int city_cost);


	void SetEndOfSeasonValue();
	void GameMarketingPayroll();
	void GameArenaPayroll();
	void GameOperatingPayroll();
	void GameGmPayroll();
	void GameCoachPayroll();
	void GameScoutPayroll();
//	void GenerateStaffSalaries(CStaff scout, CStaff coach,  CStaff gm);
	void SeasonExpenses();
	void GameTotalExpenses(int gameType);
	void SeasonRevenueRoadGame();
	void SetEndOfSeasonMiscExpenses();//adjust the expenses for next year based on stats

	int m_original_slot;

	int m_home_games;
	long m_scout_expenses;
	long m_coach_expenses;
	long m_gm_expenses;
	long m_arena_expenses;
	long m_marketing_expenses;
	long m_operating_expenses;
	int m_arena;
	int m_marketing;
	int m_operating;
	long m_game_total_expenses;
	long m_season_total_expenses;

	long m_season_scout_expenses;
	long m_season_coach_expenses;
	long m_season_gm_expenses;
	long m_season_arena_expenses;
	long m_season_marketing_expenses;
	long m_season_operating_expenses;

	long m_owner_salary_cap;

	void SetEndOfSeasonSalaryCap(int player_spending);
	void SetEndOfSeasonConcessionPrice(double avg_roster_value);
	void SetEndOfSeasonClubPrice(int personality, double avg_roster_value, int w, int l, int hi_g);
	void SetEndOfSeasonSuitePrice(int personality, double avg_roster_value, int w, int l, int hi_g);
	void SetEndOfSeasonTicketPrice(int personality, double avg_roster_value, int w, int l, int hi_g);

	void SeasonRevenues();
	void GameTotalRevenues();
	void GameTicketSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value);
	void GameParkingSales(double avg_roster_value);
	void GameConcessionSales(double avg_roster_value);
	void GameSuiteSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value);
	void GameClubSales(int personality, double avg_roster_value, int w, int l, int hi_g, int visitor_current_value);
	double m_team_roster_value;
	void SetTeamRosterValue();
	CPlayer m_contract[31];
	void GamePlayerPayroll();
	void GenerateRandomCities();
	void GenerateRandomArenas();
	void GenerateRandomFinances();

	CString m_team_name;
	CString m_city_name;
	CString m_arena_name;

	long m_tickets_sold;
	long m_ticket_revenue;
	long m_game_payroll;
	long m_suites_sold;
	long m_clubs_sold;
	long m_parking_sold;
	long m_suite_revenue;
	long m_club_revenue;
	long m_parking_revenue;
	long m_concession_revenue;
	long m_game_total_revenue;

	long m_season_att;
	long m_att_revenue;
	long m_season_payroll;
	long m_season_suites_sold;
	long m_season_clubs_sold;
	long m_season_parking_sold;
	long m_season_suite_revenue;
	long m_season_club_revenue;
	long m_season_parking_revenue;
	long m_season_concession_revenue;
	long m_season_total_revenue;

	long m_ticket_price;
	long m_suite_price;
	long m_club_price;
	long m_network_share;
	long m_local_tv;
	long m_local_radio;
	long m_concessions;
	long m_parking;
	long m_advertising;
	long m_sponsorship;
	long m_current_value;

	long m_capacity;
	long m_suites;
	long m_club_seats;
	long m_parking_spots;

	long m_possible_capacity;
	long m_possible_suites;
	long m_possible_club_seats;
	long m_possible_parking_spots;

	long m_fan_support;
	long m_economy;
	long m_political_support;
	long m_interest;

	int m_possible_move_score;
	bool m_possible_move_city;
	int m_possible_move_years;
	int m_possible_new_city;
	
	bool m_move_city;
	int m_move_years;
	int m_new_city;

	int m_stadium_value;
	int m_population;
	int m_cost_of_living;
	int m_competition;
	
	CTeamFinancial()
	{

		m_original_slot = 0;

		m_team_name = "";
		m_city_name = "";
		m_arena_name = "";
		m_home_games = 0;
		m_scout_expenses = 0;
		m_coach_expenses = 0;
		m_gm_expenses = 0;
		m_arena_expenses = 0;
		m_marketing_expenses = 0;
		m_operating_expenses = 0;

		m_arena = 0;
		m_marketing = 0;
		m_operating = 0;

		m_season_scout_expenses = 0;
		m_season_coach_expenses = 0;
		m_season_gm_expenses = 0;
		m_season_arena_expenses = 0;
		m_season_marketing_expenses = 0;
		m_season_operating_expenses = 0;
		m_owner_salary_cap = 0;



		m_game_total_expenses = 0;
		m_season_total_expenses = 0;

		m_team_roster_value = 0;
		m_tickets_sold = 0;
		m_ticket_revenue = 0;
		m_game_payroll = 0;

		m_suites_sold = 0;
		m_clubs_sold = 0;
		m_parking_sold = 0;
		m_suite_revenue = 0;
		m_club_revenue = 0;
		m_parking_revenue = 0;
		m_concession_revenue = 0;
		m_game_total_revenue = 0;

	    m_season_att= 0;
	    m_att_revenue= 0;
	    m_season_payroll= 0;
	    m_season_suites_sold= 0;
	    m_season_clubs_sold= 0;
	    m_season_parking_sold= 0;
	    m_season_suite_revenue= 0;
	    m_season_club_revenue= 0;
	    m_season_parking_revenue= 0;
	    m_season_concession_revenue= 0;
		m_season_total_revenue= 0;




		m_ticket_price = 420;
		m_suite_price = 3000;
		m_club_price = 150;
		m_network_share = 500000;
		m_local_tv = 100000;
		m_local_radio = 50000;
		m_concessions = 120;
		m_parking = 6;
		m_advertising = 25000;
		m_sponsorship = 25000;
		m_current_value = 1750;

		m_capacity = 19000;
		m_suites = 85;
		m_club_seats = 2200;
		m_parking_spots = 5000;

		m_fan_support = 3;
		m_economy = 3;
		m_political_support = 3;
		m_interest = 3;

		m_possible_move_score = 0;
		m_possible_move_city = false;
		m_possible_move_years = 0;
		m_possible_new_city = 0;

		m_move_city = false;
		m_move_years = 0;
		m_new_city = 0;

		m_stadium_value = 0;
		m_population = 3;
		m_cost_of_living = 3;
		m_competition = 3;

		m_possible_capacity = 0;
		m_possible_suites = 0;
		m_possible_club_seats = 0;
		m_possible_parking_spots = 0;



	}
	~CTeamFinancial(){}

	//copy constructor
	CTeamFinancial( const CTeamFinancial& a ) 
	{ 

		m_original_slot = a.m_original_slot;
		m_home_games = a.m_home_games;
		m_scout_expenses = a.m_scout_expenses;
		m_coach_expenses = a.m_coach_expenses;
		m_gm_expenses = a.m_gm_expenses;
		m_arena_expenses = a.m_arena_expenses;
		m_marketing_expenses = a.m_marketing_expenses;
		m_operating_expenses = a.m_operating_expenses;
		m_game_total_expenses = a.m_game_total_expenses;
		m_season_total_expenses = a.m_season_total_expenses;

		m_season_scout_expenses = a.m_season_scout_expenses;
		m_season_coach_expenses = a.m_season_coach_expenses;
		m_season_gm_expenses = a.m_season_gm_expenses;
		m_season_arena_expenses = a.m_season_arena_expenses;
		m_season_marketing_expenses = a.m_season_marketing_expenses;
		m_season_operating_expenses = a.m_season_operating_expenses;
		m_owner_salary_cap = a.m_owner_salary_cap;


		m_team_name = a.m_team_name;
		m_city_name = a.m_city_name;
		m_arena_name = a.m_arena_name;
		m_team_roster_value = a.m_team_roster_value;
		m_ticket_revenue = a.m_ticket_revenue;
		m_game_payroll = a.m_game_payroll;
		m_tickets_sold = a.m_tickets_sold;

		m_suites_sold = a.m_suites_sold;
		m_clubs_sold = a.m_clubs_sold;
		m_parking_sold = a.m_parking_sold;
		m_suite_revenue = a.m_suite_revenue;
		m_club_revenue = a.m_club_revenue;
		m_parking_revenue = a.m_parking_revenue;
		m_concession_revenue = a.m_concession_revenue;
		m_game_total_revenue = a.m_game_total_revenue;

		m_season_att = a.m_season_att;
	    m_att_revenue = a.m_att_revenue;
	    m_season_payroll = a.m_season_payroll;
	    m_season_suites_sold = a.m_season_suites_sold;
	    m_season_clubs_sold = a.m_season_clubs_sold;
	    m_season_parking_sold = a.m_season_parking_sold;
	    m_season_suite_revenue = a.m_season_suite_revenue;
	    m_season_club_revenue = a.m_season_club_revenue;
	    m_season_parking_revenue = a.m_season_parking_revenue;
	    m_season_concession_revenue = a.m_season_concession_revenue;
		m_season_total_revenue = a.m_season_total_revenue;




		m_advertising = a.m_advertising;
		m_capacity = a.m_capacity;
		m_club_price = a.m_club_price;
		m_club_seats = a.m_club_seats;
		m_concessions = a.m_concessions;
		m_current_value = a.m_current_value;
		m_economy = a.m_economy;
		m_fan_support = a.m_fan_support;
		m_interest = a.m_interest;
		m_local_radio = a.m_local_radio;
		m_local_tv = a.m_local_tv;
		m_network_share = a.m_network_share;
		m_parking = a.m_parking;
		m_parking_spots = a.m_parking_spots;
		m_political_support = a.m_political_support;
		m_sponsorship = a.m_sponsorship;
		m_suite_price = a.m_suite_price;
		m_suites = a.m_suites;
		m_ticket_price = a.m_ticket_price;
		m_arena = a.m_arena;
		m_marketing = a.m_marketing;
		m_operating = a.m_operating;


		m_possible_move_score = a.m_possible_move_score;
		m_possible_move_city = a.m_possible_move_city;
		m_possible_move_years = a.m_possible_move_years;
		m_possible_new_city = a.m_possible_new_city;

		m_move_city = a.m_move_city;
		m_move_years = a.m_move_years;
		m_new_city = a.m_new_city;

		m_stadium_value = a.m_stadium_value;
		m_population = a.m_population;
		m_cost_of_living = a.m_cost_of_living;

		m_competition = a.m_competition;

		m_possible_capacity = a.m_possible_capacity;
		m_possible_suites = a.m_possible_suites;
		m_possible_club_seats = a.m_possible_club_seats;
		m_possible_parking_spots = a.m_possible_parking_spots;



	}

	const CTeamFinancial& operator=( const CTeamFinancial& a )
    {
		m_original_slot = a.m_original_slot;
		m_home_games = a.m_home_games;
		m_scout_expenses = a.m_scout_expenses;
		m_coach_expenses = a.m_coach_expenses;
		m_gm_expenses = a.m_gm_expenses;
		m_arena_expenses = a.m_arena_expenses;
		m_marketing_expenses = a.m_marketing_expenses;
		m_operating_expenses = a.m_operating_expenses;
		m_game_total_expenses = a.m_game_total_expenses;
		m_season_total_expenses = a.m_season_total_expenses;

		m_season_scout_expenses = a.m_season_scout_expenses;
		m_season_coach_expenses = a.m_season_coach_expenses;
		m_season_gm_expenses = a.m_season_gm_expenses;
		m_season_arena_expenses = a.m_season_arena_expenses;
		m_season_marketing_expenses = a.m_season_marketing_expenses;
		m_season_operating_expenses = a.m_season_operating_expenses;
		m_owner_salary_cap = a.m_owner_salary_cap;



		m_team_name = a.m_team_name;
		m_city_name = a.m_city_name;
		m_arena_name = a.m_arena_name;
		m_team_roster_value = a.m_team_roster_value;
		m_ticket_revenue = a.m_ticket_revenue;
		m_game_payroll = a.m_game_payroll;
		m_tickets_sold = a.m_tickets_sold;

		m_suites_sold = a.m_suites_sold;
		m_clubs_sold = a.m_clubs_sold;
		m_parking_sold = a.m_parking_sold;
		m_suite_revenue = a.m_suite_revenue;
		m_club_revenue = a.m_club_revenue;
		m_parking_revenue = a.m_parking_revenue;
		m_concession_revenue = a.m_concession_revenue;
		m_game_total_revenue = a.m_game_total_revenue;

		m_season_att = a.m_season_att;
	    m_att_revenue = a.m_att_revenue;
	    m_season_payroll = a.m_season_payroll;
	    m_season_suites_sold = a.m_season_suites_sold;
	    m_season_clubs_sold = a.m_season_clubs_sold;
	    m_season_parking_sold = a.m_season_parking_sold;
	    m_season_suite_revenue = a.m_season_suite_revenue;
	    m_season_club_revenue = a.m_season_club_revenue;
	    m_season_parking_revenue = a.m_season_parking_revenue;
	    m_season_concession_revenue = a.m_season_concession_revenue;
		m_season_total_revenue = a.m_season_total_revenue;

		m_advertising = a.m_advertising;
		m_capacity = a.m_capacity;
		m_club_price = a.m_club_price;
		m_club_seats = a.m_club_seats;
		m_concessions = a.m_concessions;
		m_current_value = a.m_current_value;
		m_economy = a.m_economy;
		m_fan_support = a.m_fan_support;
		m_interest = a.m_interest;
		m_local_radio = a.m_local_radio;
		m_local_tv = a.m_local_tv;
		m_network_share = a.m_network_share;
		m_parking = a.m_parking;
		m_parking_spots = a.m_parking_spots;
		m_political_support = a.m_political_support;
		m_sponsorship = a.m_sponsorship;
		m_suite_price = a.m_suite_price;
		m_suites = a.m_suites;
		m_ticket_price = a.m_ticket_price;
		m_arena = a.m_arena;
		m_marketing = a.m_marketing;
		m_operating = a.m_operating;

		m_possible_move_score = a.m_possible_move_score;
		m_possible_move_city = a.m_possible_move_city;
		m_possible_move_years = a.m_possible_move_years;
		m_possible_new_city = a.m_possible_new_city;

		m_move_city = a.m_move_city;
		m_move_years = a.m_move_years;
		m_new_city = a.m_new_city;

		m_stadium_value = a.m_stadium_value;
		m_population = a.m_population;
		m_cost_of_living = a.m_cost_of_living;

		m_competition = a.m_competition;

	    m_possible_capacity = a.m_possible_capacity;
		m_possible_suites = a.m_possible_suites;
		m_possible_club_seats = a.m_possible_club_seats;
		m_possible_parking_spots = a.m_possible_parking_spots;

		return *this;
	}
	
private:
//	CFuture m_future;

	void PossibleMoveYears();
	//int Random(int n);
	double Random(double n);
	int IntRandom(int n)
	{	
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}

};