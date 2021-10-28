#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif

#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 






#include <cmath>                    // for sqrt() and pow()

class CPlayer: public CObject
{

public:
	void InkedNewDeal(int best_contract);
	void AdjustForPro(int team, int comp, int dur, int ten);
	void Calculate(bool rookie_import);

private:
//	int m_teamFouls;


public:


	int m_height;
	int m_weight;

	bool m_just_signed;
	
	bool m_end_season_fa;
	int m_stop_negotiating;
	int m_content;
	int m_health;
	CString m_injury_desc;
	bool m_on_block;
	int m_game_stamina;
	int m_3ptscore[4];
	int m_dunkscore[4];

	int m_temp_pointer;

	int m_gamepgrot;
	int m_gamesgrot;
	int m_gamesfrot;
	int m_gamepfrot;
	int m_gamecrot;

	int m_all_star;
	int m_rookie_star;
	int m_3contest;
	int m_dunkcontest;
	
	int m_all_star_index;//team player was on during allstar stuff
	int m_rookie_star_index;
	int m_3contest_index;
	int m_dunkcontest_index;
	
	int m_game_stat_slot;
	CString m_game_name;
	int m_game_injury;
	int m_game_Min;
	int m_game_Fgm;
	int m_game_Fga;
	int m_game_Ftm;
	int m_game_Fta;
	int m_game_Tfgm;
	int m_game_Tfga;
	int m_game_Oreb;
	int m_game_Dreb;
	int m_game_Ast;
	int m_game_Stl;
	int m_game_To;
	int m_game_Blk;
	int m_game_Pf;
	int m_game_player_pointer; 
	

int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}

	
void SetGameName(CString n){m_game_name = n;}
void SetGameInjury(int i){m_game_injury = i;}
void SetGameMin(int time){m_game_Min = m_game_Min + time;}
void SetGameFgm(){m_game_Fgm = m_game_Fgm + 1;}
void SetGameFga(){m_game_Fga = m_game_Fga + 1;}
void SetGameTfgm(){m_game_Tfgm = m_game_Tfgm + 1;}
void SetGameTfga(){m_game_Tfga = m_game_Tfga + 1;}
void SetGameFtm(){m_game_Ftm = m_game_Ftm + 1;}
void SetGameFta(){m_game_Fta = m_game_Fta + 1;}
void SetGameOreb(){m_game_Oreb = m_game_Oreb + 1;}
void SetGameDreb(){m_game_Dreb = m_game_Dreb + 1;}
void SetGameAst(){m_game_Ast = m_game_Ast + 1;}
void SetGameStl(){m_game_Stl = m_game_Stl + 1;}
void SetGameTo(){m_game_To = m_game_To + 1;}
void SetGameBlk(){m_game_Blk = m_game_Blk + 1;}
void SetGamePf(){m_game_Pf = m_game_Pf + 1;}
void SetGameCurrentStamina(int stamina){m_game_stamina = stamina;}



//int GetGameTeamFouls(){retGameurn m_teamFouls;}
CString GetGameName(){return m_game_name;}
int GetGameInjury(){return m_injury;}
int GetGameMin(){return m_game_Min;}
int GetGameFgm(){return m_game_Fgm;}
int GetGameFga(){return m_game_Fga;}
int GetGameTfgm(){return m_game_Tfgm;}
int GetGameTfga(){return m_game_Tfga;}
int GetGameFtm(){return m_game_Ftm;}
int GetGameFta(){return m_game_Fta;}
int GetGameOreb(){return m_game_Oreb;}
int GetGameDreb(){return m_game_Dreb;}
int GetGameAst(){return m_game_Ast;}
int GetGameStl(){return m_game_Stl;}
int GetGameTo(){return m_game_To;}
int GetGameBlk(){return m_game_Blk;}
int GetGamePf(){return m_game_Pf;}
int GetGameStamina(){return m_stamina;}
int GetGameCurrentStamina()
{
	return m_game_stamina;
}





	long int m_hi_pts;
	long int m_hi_reb;
	long int m_hi_ast;
	long int m_hi_stl;
	long int m_hi_blk;
	long int m_double;
	long int m_triple;

	long int m_hi_pts_po;
	long int m_hi_reb_po;
	long int m_hi_ast_po;
	long int m_hi_stl_po;
	long int m_hi_blk_po;

	long int m_hi_pts_car;
	long int m_hi_reb_car;
	long int m_hi_ast_car;
	long int m_hi_stl_car;
	long int m_hi_blk_car;
	long int m_double_car;
	long int m_triple_car;

	long int m_hi_pts_car_po;
	long int m_hi_reb_car_po;
	long int m_hi_ast_car_po;
	long int m_hi_stl_car_po;
	long int m_hi_blk_car_po;



	bool m_retired;
	int m_starter;
	int m_number;
	CString m_lastName;
	int m_injury;
	int m_age;
	int m_id;
	int m_games;
	int m_min;
	int m_fgm;
	int m_fga;
	int m_ftm;
	int m_fta;
	int m_tfgm;
	int m_tfga;
	int m_oreb;
	int m_reb;
	int m_ast;
	int m_stl;
	int m_to;
	int m_blk;
	int m_pf;


	int m_oldmovoff;
	int m_oldmovdef;
	int m_oldpenoff;
	int m_oldpendef;
	int m_oldpostoff;
	int m_oldpostdef;
	int m_oldtransoff;
	int m_oldtransdef;
	int m_oldprFga;
	int m_oldprFgp;
	int m_oldprFta;
	int m_oldprFtp;
	int m_oldprTga;
	int m_oldprTgp;
	int m_oldprOrb;
	int m_oldprDrb;
	int m_oldprAst;
	int m_oldprStl;
	int m_oldprTo;
	int m_oldprBlk;


	int m_movoff;
	int m_movdef;
	int m_penoff;
	int m_pendef;
	int m_postoff;
	int m_postdef;
	int m_transoff;
	int m_transdef;


	int m_clutch;
	int m_consistency;
	BOOL m_pgrot;
	BOOL m_sgrot;
	BOOL m_sfrot;
	BOOL m_pfrot;
	BOOL m_crot;
	BOOL m_active;
	int m_better;
	CString m_team;
	int m_totalGames;
	int m_teamGames;

	double m_minPerGame;
	double m_pointsPerGame;
	double m_reboundsPerGame;
	double m_assistsPerGame;
	double m_stealsPerGame;
	double m_blocksPerGame;
	double m_orbPerGame;
	double m_toPerGame;
	double m_pfPerGame;
	double m_fgPct;
	double m_tfgPct;
	double m_ftPct;

	double m_sim_minPerGame;
	double m_sim_pointsPerGame;
	double m_sim_reboundsPerGame;
	double m_sim_assistsPerGame;
	double m_sim_stealsPerGame;
	double m_sim_blocksPerGame;
	double m_sim_orbPerGame;
	double m_sim_toPerGame;
	double m_sim_pfPerGame;
	double m_sim_fgPct;
	double m_sim_tfgPct;
	double m_sim_ftPct;

	double m_po_minPerGame;
	double m_po_pointsPerGame;
	double m_po_reboundsPerGame;
	double m_po_assistsPerGame;
	double m_po_stealsPerGame;
	double m_po_blocksPerGame;
	double m_po_orbPerGame;
	double m_po_toPerGame;
	double m_po_pfPerGame;
	double m_po_fgPct;
	double m_po_tfgPct;
	double m_po_ftPct;
	double m_tradeTrueRating;

	double m_trueRating;
	double m_teammatesBetterRating;
	double m_astTo;
	double m_defense;
	double m_outside;
	double m_driving;
	double m_post;
	double m_transition;
	double m_outsideDefense;
	double m_drivingDefense;
	double m_postDefense;
	double m_transitionDefense;
	double m_outsidePer48Min;
	double m_drivingPer48Min;
	double m_postPer48Min;
	double m_transitionPer48Min;
	double m_outsideDefensePer48Min;
	double m_drivingDefensePer48Min;
	double m_postDefensePer48Min;
	double m_transitionDefensePer48Min;
	double m_mvp;

	double m_sim_trueRating;
	double m_sim_teammatesBetterRating;
	double m_sim_astTo;
	double m_sim_defense;
	double m_sim_outside;
	double m_sim_driving;
	double m_sim_post;
	double m_sim_transition;
	double m_sim_outsideDefense;
	double m_sim_drivingDefense;
	double m_sim_postDefense;
	double m_sim_transitionDefense;
	double m_sim_outsidePer48Min;
	double m_sim_drivingPer48Min;
	double m_sim_postPer48Min;
	double m_sim_transitionPer48Min;
	double m_sim_outsideDefensePer48Min;
	double m_sim_drivingDefensePer48Min;
	double m_sim_postDefensePer48Min;
	double m_sim_transitionDefensePer48Min;
	double m_sim_mvp;

	double m_po_trueRating;
	double m_po_teammatesBetterRating;
	double m_po_astTo;
	double m_po_defense;
	double m_po_outside;
	double m_po_driving;
	double m_po_post;
	double m_po_transition;
	double m_po_outsideDefense;
	double m_po_drivingDefense;
	double m_po_postDefense;
	double m_po_transitionDefense;
	double m_po_outsidePer48Min;
	double m_po_drivingPer48Min;
	double m_po_postPer48Min;
	double m_po_transitionPer48Min;
	double m_po_outsideDefensePer48Min;
	double m_po_drivingDefensePer48Min;
	double m_po_postDefensePer48Min;
	double m_po_transitionDefensePer48Min;
	double m_po_mvp;

	double m_tradeValue;

	int m_prFga;
	int m_prFgp;
	int m_prFta;
	int m_prFtp;
	int m_prTga;
	int m_prTgp;
	int m_prOrb;
	int m_prDrb;
	int m_prAst;
	int m_prStl;
	int m_prTo;
	int m_prBlk;



	int m_adjPrFga;
	int m_adjPrFgp;
	int m_adjPrFta;
	int m_adjPrFtp;
	int m_adjPrTga;
	int m_adjPrTgp;
	int m_adjPrOrb;
	int m_adjPrDrb;
	int m_adjPrAst;
	int m_adjPrStl;
	int m_adjPrTo;
	int m_adjPrBlk;
	int m_adjPot1;
	int m_adjPot2;
	int m_adjEffort;
	int m_adjPrime;

	

	int m_contract_salaries[7];
	int m_current_yr_salary;
	int m_coach_factor;
	int m_security_factor;
	int m_loyalty_factor;
	int m_winning_factor;
	int m_playing_time_factor;
	int m_tradition_factor;
	
	int m_original_number;
	int m_original_po_number;
	int m_round_selected;
	int m_pick_selected;
	double m_trueRatingSimple;
	int m_contract_pointer;

	int m_sim_games;
	int m_sim_min;
	int m_sim_fgm;
	int m_sim_fga;
	int m_sim_ftm;
	int m_sim_fta;
	int m_sim_tfgm;
	int m_sim_tfga;
	int m_sim_oreb;
	int m_sim_reb;
	int m_sim_ast;
	int m_sim_stl;
	int m_sim_to;
	int m_sim_blk;
	int m_sim_pf;

	int m_car_games;
	int m_car_min;
	int m_car_fgm;
	int m_car_fga;
	int m_car_ftm;
	int m_car_fta;
	int m_car_tfgm;
	int m_car_tfga;
	int m_car_oreb;
	int m_car_reb;
	int m_car_ast;
	int m_car_stl;
	int m_car_to;
	int m_car_blk;
	int m_car_pf;

	int m_po_games;
	int m_po_min;
	int m_po_fgm;
	int m_po_fga;
	int m_po_ftm;
	int m_po_fta;
	int m_po_tfgm;
	int m_po_tfga;
	int m_po_oreb;
	int m_po_reb;
	int m_po_ast;
	int m_po_stl;
	int m_po_to;
	int m_po_blk;
	int m_po_pf;
	int m_team_index;		

	int m_pot1;
	int m_pot2;
	int m_effort;
	int m_prime;

	int m_original_slot;

	double m_accept_factor;

	bool m_random_yrs_service;	
	bool m_random_contracts;	
	bool m_random_contract_ratings;	
	bool m_random_projections;	

	bool m_rookie;
	bool m_bird_player;
	CString m_name;
	CString m_pos;
	int m_salary_id;
	int m_current_team;
	int m_previous_team;
	int m_yrs_on_team;
	int m_yrs_of_service;
	int m_contract_yrs;
	int m_total_salary;
	int m_remaining_salary;
	int m_total_salary_seeking;
	int m_current_contract_yr;
	int m_new_contract_salaries[7];
	int m_seeking[33];
	int m_qualifying_offer_years;
	int m_qualifying_salaries[7];
	bool m_is_free_agent;

	int m_team_paying;
	CString m_team_paying_name;

	bool m_top_offer[33];//teams that make this player their top choice

	int m_year_offer[33];//yrs offered by all teams (top offer has to be true)
	int m_salary_offer[33][7];//yr by yr salaries offered by each team
	int m_total_salary_offer[33];//total contract amount by team
	int m_best_contract;
	int m_offer_slot[33];
	bool m_signed;
	int m_player_pointer;
	
	int m_game_minutes;
	int m_offensive_focus;
	int m_defensive_focus;
	int m_offensive_intensity;
	int m_defensive_intensity;
	int m_play_maker;


	void SetOriginalAdjustedRatings();

	double m_MinPerGame;
	int m_FgPct;
	int m_adjustedFgPct;
	int m_FtPct;
	double m_FoulsDrawnPer48Min;
	double m_AdjustedFoulsDrawnPer48Min;
	int m_TfgPct;
	double m_FgaPer48Min;
	double m_AdjustedFgaPer48Min;
	double m_coachFgaPer48Min;
	double m_coachTfgaPer48Min;
	double m_TfgaPer48Min;
	double m_AdjustedTfgaPer48Min;

	double m_OrebPer48Min;
	double m_DrebPer48Min;
	double m_AstPer48Min;
	double m_StlPer48Min;
	double m_ToPer48Min;
	double m_AdjustedToPer48Min;
	double m_BlkPer48Min;
	double m_PfPer48Min;
	int m_injuryRating;
	int m_stamina;

	double m_OriginalAdjustedFoulsDrawnPer48Min;
	double m_OriginalAdjustedFgaPer48Min;
	double m_OriginalAdjustedTfgaPer48Min;
	double m_OriginalStlPer48Min;
	double m_OriginalBlkPer48Min;


	CPlayer()
	{
		m_oldmovoff = 0;
		m_oldmovdef = 0;
		m_oldpenoff = 0;
		m_oldpendef = 0;
		m_oldpostoff = 0;
		m_oldpostdef = 0;
		m_oldtransoff = 0;
		m_oldtransdef = 0;
		m_oldprFga = 0;
		m_oldprFgp = 0;
		m_oldprFta = 0;
		m_oldprFtp = 0;
		m_oldprTga = 0;
		m_oldprTgp = 0;
		m_oldprOrb = 0;
		m_oldprDrb = 0;
		m_oldprAst = 0;
		m_oldprStl = 0;
		m_oldprTo = 0;
		m_oldprBlk = 0;




		m_height = 0;
		m_weight = 0;
		m_just_signed = false;
		m_end_season_fa = false;
		m_gamepgrot = 0;
		m_gamesgrot = 0;
		m_gamesfrot = 0;
		m_gamepfrot = 0;
		m_gamecrot = 0;
		m_stop_negotiating = 0;
		m_health = 100;
		m_content = 0;
		m_on_block = false;
		m_injury_desc = "";

		m_temp_pointer = 0;

		m_all_star = 0;
		m_rookie_star = 0;
		m_3contest = 0;
		m_dunkcontest = 0;
	
		m_all_star_index = 0;
		m_rookie_star_index = 0;
		m_3contest_index = 0;
		m_dunkcontest = 0;
		m_hi_blk_car_po = 0;
		m_dunkcontest_index = 0;


		m_retired = false;
		m_starter = 0;
		m_round_selected = 0;
		m_pick_selected = 0;
		m_contract_pointer = 0;
		m_number = 1;
		m_name = "";
		m_age = 22;
		m_id = 0;
		m_lastName = "";
		m_injury = 0;
		m_pos = "PG";
		m_games = 0;
	    m_min = 1;
	    m_fgm = 0;
	    m_fga = 0;
	    m_ftm = 0;
	    m_fta = 0;
	    m_tfgm = 0;
	    m_tfga = 0;
	    m_oreb = 0;
	    m_reb = 0;
	    m_ast = 0;
	    m_stl = 0;
	    m_to = 0;
	    m_blk = 0;
	    m_pf = 0;

		m_sim_games = 0;
	    m_sim_min = 0;
	    m_sim_fgm = 0;
	    m_sim_fga = 0;
	    m_sim_ftm = 0;
	    m_sim_fta = 0;
	    m_sim_tfgm = 0;
	    m_sim_tfga = 0;
	    m_sim_oreb = 0;
	    m_sim_reb = 0;
	    m_sim_ast = 0;
	    m_sim_stl = 0;
	    m_sim_to = 0;
	    m_sim_blk = 0;
	    m_sim_pf = 0;

		m_car_games = 0;
	    m_car_min = 0;
	    m_car_fgm = 0;
	    m_car_fga = 0;
	    m_car_ftm = 0;
	    m_car_fta = 0;
	    m_car_tfgm = 0;
	    m_car_tfga = 0;
	    m_car_oreb = 0;
	    m_car_reb = 0;
	    m_car_ast = 0;
	    m_car_stl = 0;
	    m_car_to = 0;
	    m_car_blk = 0;
	    m_car_pf = 0;

		m_po_games = 0;
	    m_po_min = 0;
	    m_po_fgm = 0;
	    m_po_fga = 0;
	    m_po_ftm = 0;
	    m_po_fta = 0;
	    m_po_tfgm = 0;
	    m_po_tfga = 0;
	    m_po_oreb = 0;
	    m_po_reb = 0;
	    m_po_ast = 0;
	    m_po_stl = 0;
	    m_po_to = 0;
	    m_po_blk = 0;
	    m_po_pf = 0;
		m_movoff = 1;
		m_movdef = 1;
		m_penoff = 1;
		m_pendef = 1;
		m_postoff = 1;
		m_postdef = 1;
		m_transoff = 1;
		m_transdef = 1;
		m_clutch = 1;
		m_consistency = 1;
		m_pgrot = FALSE;
		m_sgrot = FALSE;
		m_sfrot = FALSE;
		m_pfrot = FALSE;
		m_crot = FALSE;
		m_active = TRUE;
		m_better = 0;
	    m_totalGames = 0;
		m_teamGames = 0;

		m_minPerGame = 0;
		m_pointsPerGame = 0;
		m_reboundsPerGame = 0;
		m_assistsPerGame = 0;
		m_stealsPerGame = 0;
		m_blocksPerGame = 0;
		m_orbPerGame = 0;
		m_toPerGame = 0;
		m_pfPerGame = 0;
		m_fgPct = 0;
		m_tfgPct = 0;
		m_ftPct = 0;

		m_sim_minPerGame = 0;
		m_sim_pointsPerGame = 0;
		m_sim_reboundsPerGame = 0;
		m_sim_assistsPerGame = 0;
		m_sim_stealsPerGame = 0;
		m_sim_blocksPerGame = 0;
		m_sim_orbPerGame = 0;
		m_sim_toPerGame = 0;
		m_sim_pfPerGame = 0;
		m_sim_fgPct = 0;
		m_sim_tfgPct = 0;
		m_sim_ftPct = 0;



		m_po_minPerGame = 0;
		m_po_pointsPerGame = 0;
		m_po_reboundsPerGame = 0;
		m_po_assistsPerGame = 0;
		m_po_stealsPerGame = 0;
		m_po_blocksPerGame = 0;
		m_po_orbPerGame = 0;
		m_po_toPerGame = 0;
		m_po_pfPerGame = 0;
		m_po_fgPct = 0;
		m_po_tfgPct = 0;
		m_po_ftPct = 0;



		m_tradeTrueRating = 0;
		m_tradeValue = 0;
		m_trueRatingSimple = 0;

		m_trueRating = 0;
		m_teammatesBetterRating = 0;
		m_astTo = 0;
		m_defense = 0;
		m_outside = 0;
		m_driving = 0;
		m_post = 0;
		m_transition = 0;
		m_outsideDefense = 0;
		m_drivingDefense = 0;
		m_postDefense = 0;
		m_transitionDefense = 0;
		m_outsidePer48Min = 0;
		m_drivingPer48Min = 0;
		m_postPer48Min = 0;
		m_transitionPer48Min = 0;
		m_outsideDefensePer48Min = 0;
		m_drivingDefensePer48Min = 0;
		m_postDefensePer48Min = 0;
		m_transitionDefensePer48Min = 0;
		m_mvp = 0;

		m_sim_trueRating = 0;
		m_sim_teammatesBetterRating = 0;
		m_sim_astTo = 0;
		m_sim_defense = 0;
		m_sim_outside = 0;
		m_sim_driving = 0;
		m_sim_post = 0;
		m_sim_transition = 0;
		m_sim_outsideDefense = 0;
		m_sim_drivingDefense = 0;
		m_sim_postDefense = 0;
		m_sim_transitionDefense = 0;
		m_sim_outsidePer48Min = 0;
		m_sim_drivingPer48Min = 0;
		m_sim_postPer48Min = 0;
		m_sim_transitionPer48Min = 0;
		m_sim_outsideDefensePer48Min = 0;
		m_sim_drivingDefensePer48Min = 0;
		m_sim_postDefensePer48Min = 0;
		m_sim_transitionDefensePer48Min = 0;
		m_sim_mvp = 0;

		m_po_trueRating = 0;
		m_po_teammatesBetterRating = 0;
		m_po_astTo = 0;
		m_po_defense = 0;
		m_po_outside = 0;
		m_po_driving = 0;
		m_po_post = 0;
		m_po_transition = 0;
		m_po_outsideDefense = 0;
		m_po_drivingDefense = 0;
		m_po_postDefense = 0;
		m_po_transitionDefense = 0;
		m_po_outsidePer48Min = 0;
		m_po_drivingPer48Min = 0;
		m_po_postPer48Min = 0;
		m_po_transitionPer48Min = 0;
		m_po_outsideDefensePer48Min = 0;
		m_po_drivingDefensePer48Min = 0;
		m_po_postDefensePer48Min = 0;
		m_po_transitionDefensePer48Min = 0;
		m_po_mvp = 0;

	    m_prFga = 0;
	    m_prFgp = 0;
	    m_prFta = 0;
	    m_prFtp = 0;
	    m_prTga = 0;
	    m_prTgp = 0;
	    m_prOrb =0;
	    m_prDrb = 0;
	    m_prAst = 0;
	    m_prStl = 0;
	    m_prTo = 0;
	    m_prBlk = 0;
		m_pot1 = 3;
		m_pot2 = 3;
		m_effort = 3;
		m_prime = 27;
	    
		m_adjPrFga = 0;
	    m_adjPrFgp = 0;
	    m_adjPrFta = 0;
	    m_adjPrFtp = 0;
	    m_adjPrTga = 0;
	    m_adjPrTgp = 0;
	    m_adjPrOrb =0;
	    m_adjPrDrb = 0;
	    m_adjPrAst = 0;
	    m_adjPrStl = 0;
	    m_adjPrTo = 0;
	    m_adjPrBlk = 0;
		m_adjPot1 = 3;
		m_adjPot2 = 3;
		m_adjEffort = 3;
		m_adjPrime = 27;
		m_team_index = 0;
		m_original_number = 0;
		m_original_po_number = 0;

		for(int i=0; i<= 6; i++)
		{
			m_contract_salaries[i] = 0;
		}
	


	    m_coach_factor = 3;
	    m_security_factor = 3;
	    m_loyalty_factor = 3;
	    m_winning_factor = 3;
	    m_playing_time_factor = 3;
	    m_tradition_factor = 3;

		m_is_free_agent = false;

		m_team_paying = 0;
		m_team_paying_name = "";


		m_yrs_on_team = 0;
		m_current_yr_salary = 0;

		m_original_slot = 0;

	m_accept_factor = 0;
		m_rookie = false;
		m_bird_player = 0;
		m_name = "";
		m_pos = "";
		m_salary_id = 0;
	    m_current_team = -1;
	    m_previous_team = -1;
		m_yrs_on_team = 0;
		m_yrs_of_service = 0;
		m_contract_yrs = 0;
		m_total_salary = 0;
		m_remaining_salary = 0;
		m_total_salary_seeking = 0;
		m_current_contract_yr = 0;
		m_qualifying_offer_years = 0;



			for(int j=0; j<=3; j++)
			{
				m_3ptscore[j] = 0;
				m_dunkscore[j] = 0;
			}

		for(int i=0; i<= 6; i++)
		{
			m_new_contract_salaries[i] = 0;
			m_qualifying_salaries[i] = 0;
		}
		for(int i=0; i<= 32; i++)
		{
			m_seeking[i] = 0;
			m_offer_slot[i] = 0;
		}
		m_is_free_agent = false;


		for(int i=0; i<= 32; i++)
		{
			m_top_offer[i] = false;
			m_year_offer[i] = 0;
			m_total_salary_offer[i] = 0;
			for(int j=0; j<= 6; j++)
			{
				m_salary_offer[i][j] = 0;
			}
		}
		m_best_contract = 0;
		m_signed = false;
		m_player_pointer = 0;

			m_random_yrs_service = true;	
			m_random_contracts = true;	
			m_random_contract_ratings = true;	
			m_random_projections = true;	
  



		m_hi_pts = 0;
		m_hi_reb = 0;
		m_hi_ast = 0;
		m_hi_stl = 0;
		m_hi_blk = 0;
		m_double = 0;
		m_triple = 0;

		m_hi_pts_po = 0;
		m_hi_reb_po = 0;
		m_hi_ast_po = 0;
		m_hi_stl_po = 0;
		m_hi_blk_po = 0;

		m_hi_pts_car = 0;
		m_hi_reb_car = 0;
		m_hi_ast_car = 0;
		m_hi_stl_car = 0;
		m_hi_blk_car = 0;
		m_double_car = 0;
		m_triple_car = 0;

		m_hi_pts_car_po = 0;
		m_hi_reb_car_po = 0;
		m_hi_ast_car_po = 0;
		m_hi_stl_car_po = 0;
		m_hi_blk = 0;

		m_game_minutes = 0;
		m_offensive_focus = 0;
		m_defensive_focus = 0;
		m_offensive_intensity = 0;
		m_defensive_intensity = 0;
		m_play_maker = 0;

m_MinPerGame = 0;
	m_FgPct = 0;
	m_adjustedFgPct = 0;
	m_FtPct = 0;
	m_FoulsDrawnPer48Min = 0;
	m_AdjustedFoulsDrawnPer48Min = 0;
	m_TfgPct = 0;
	m_FgaPer48Min = 0;
	m_AdjustedFgaPer48Min = 0;
	m_coachFgaPer48Min = 0;
	m_coachTfgaPer48Min = 0;
	m_TfgaPer48Min = 0;
	m_AdjustedTfgaPer48Min = 0;
	m_OrebPer48Min = 0;
	m_DrebPer48Min = 0;
	m_AstPer48Min = 0;
	m_StlPer48Min = 0;
	m_ToPer48Min = 0;
	m_AdjustedToPer48Min = 0;
	m_BlkPer48Min = 0;
	m_PfPer48Min = 0;
	m_injuryRating = 0;
	m_stamina = 0;

	m_OriginalAdjustedFoulsDrawnPer48Min = 0;
	m_OriginalAdjustedFgaPer48Min = 0;
	m_OriginalAdjustedTfgaPer48Min = 0;
	m_OriginalStlPer48Min = 0;
	m_OriginalBlkPer48Min = 0;


	m_game_name = "";	
	m_game_injury = 0;
	m_game_Min = 0;
	m_game_Fgm = 0;
	m_game_Fga = 0;
	m_game_Ftm = 0;
	m_game_Fta = 0;
	m_game_Tfgm = 0;
	m_game_Tfga = 0;
	m_game_Oreb = 0;
	m_game_Dreb = 0;
	m_game_Ast = 0;
	m_game_Stl = 0;
	m_game_To = 0;
	m_game_Blk = 0;
	m_game_Pf = 0;
	m_game_stamina = 0;
	m_game_stat_slot = 0;
	m_game_player_pointer = 0; 


	}
	~CPlayer(){}


void SetRatings(int m_hi_fga, int m_hi_fta, int m_hi_tga, int m_hi_orb, int m_hi_drb, int m_hi_ast, int m_hi_stl, int m_hi_to, int m_hi_blk)
{

	

	double g = double(GetMin());
	if(g == 0) g = 1;

	double fga2 = (double(GetFga()) - double(GetTfga()));
	double fga3 = double(GetTfga());
	double fta = double(GetFta());
	if(fga2 == 0) fga2 = 1;
	if(fga3 == 0) fga3 = 1;
	if(fta == 0) fta = 1;


	double pen =
		1 + ((g / double(GetGames()) - 24) / 2 / 48);
	
	if(pen > 1) pen = 1;
	double tmp = (fga2/g)*480;
	tmp = tmp * pen / double(m_hi_fga)*100;

	SetPrFga(int(tmp));

	tmp = (double(GetFgm()) - double(GetTfgm()))/
		(fga2) * 100;
	SetPrFgp(int(tmp));

	double diff = tmp - int(tmp);
	if(diff > .5) SetPrFgp(int(tmp + 1));
	
	tmp = double(GetFta())/g*480;
	tmp = tmp * pen / double(m_hi_fta)*100;
	SetPrFta(int(tmp));

	tmp = double(GetFtm())/fta*100;
	SetPrFtp(int(tmp));
	diff = tmp - int(tmp);
	if(diff > .5) 	SetPrFtp(int(tmp + 1));

	tmp = double(GetTfga())/g*480;
	tmp = tmp * pen / double(m_hi_tga)*100;
	SetPrTga(int(tmp));


	tmp = double(GetTfgm())/fga3*100;
	SetPrTgp(int(tmp));

	diff = tmp - int(tmp);
	if(diff > .5) SetPrTgp(int(tmp + 1));
	
	tmp = double(GetOreb())/g*480;
	tmp = tmp * pen / double(m_hi_orb)*100;
	SetPrOrb(int(tmp));

	tmp = ((double(GetReb()) - double(GetOreb()))/g)*480;
	tmp = tmp * pen / double(m_hi_drb)*100;
	SetPrDrb(int(tmp));

	tmp = double(GetAst())/g*480;
	tmp = tmp * pen / double(m_hi_ast)*100;
	SetPrAst(int(tmp));

	tmp = double(GetStl())/g*480;
	tmp = tmp * pen / double(m_hi_stl)*100;
	SetPrStl(int(tmp));

	tmp = double(GetTo())/g*480;
	tmp = tmp * pen / double(m_hi_to)*100;
	SetPrTo(100 - int(tmp));

	tmp = double(GetBlk())/g*480;
	tmp = tmp * pen / double(m_hi_blk)*100;
	SetPrBlk(int(tmp));
	
}

void ConvertRatings(int orig_g, int orig_min, 
					int orig_fga, int orig_fgp,
					int orig_fta, int orig_ftp,
					int orig_tga, int orig_tgp,
					int orig_orb, int orig_drb, int orig_ast,
					int orig_stl, int orig_to, int orig_blk,
					double m_avg_g, double m_avg_min, 
					double m_avg_fga, double m_avg_fgp,
					double m_avg_fta, double m_avg_ftp,
					double m_avg_tga, double m_avg_tgp,
					double m_avg_orb, double m_avg_drb, double m_avg_ast,
					double m_avg_stl, double m_avg_to, double m_avg_blk,
					double m_avg_pf,
					int m_hi_fga, int m_hi_fta, int m_hi_tga, 
					int m_hi_orb, int m_hi_drb, int m_hi_ast,
					int m_hi_stl, int m_hi_to, int m_hi_blk					
					)

{


	int current_min = int( double(m_min) / orig_g);
	double min_factor = double(orig_min) / current_min;
	double g_factor = double(m_games) / orig_g;
	double factor = min_factor * g_factor;

	double temp = 0;
		
	m_fgm = m_fgm - m_tfgm;
	m_fga = m_fga - m_tfga;

	if(orig_ftp != m_prFtp || orig_fta != m_prFta || orig_g != m_games  || orig_min != current_min)
	{
		m_fta = int( double(m_prFta+1) / 100 * m_hi_fta / 480 * m_min * factor);
		temp = double(m_prFtp)/100 * m_fta;
		m_ftm = int(temp);
		if( temp - m_ftm >= .5) m_ftm = m_ftm + 1;
	}




	if(orig_fgp != m_prFgp || orig_fga != m_prFga || orig_g != m_games  || orig_min != current_min)
	{
		m_fga = int( double(m_prFga+1) / 100 * m_hi_fga / 480 * m_min * factor);
		temp = double(m_prFgp)/100 * m_fga;
		m_fgm = int(temp);
		if( temp - m_fgm >= .5) m_fgm = m_fgm + 1;
	}

	if(orig_tgp != m_prTgp || orig_tga != m_prTga || orig_g != m_games  || orig_min != current_min)
	{
		m_tfga = int( double(m_prTga+1) / 100 * m_hi_tga / 480 * m_min * factor);
		temp = double(m_prTgp)/100 * m_tfga;
		m_tfgm = int(temp);
		if( temp - m_tfga >= .5) m_tfgm = m_tfgm + 1;
	}

	m_fgm = m_fgm + m_tfgm;
	m_fga = m_fga + m_tfga;
	
	

	if(orig_orb != m_prOrb|| orig_g != m_games  || orig_min != current_min)
		m_oreb  = int( double(m_prOrb+1) / 100 * m_hi_orb / 480 * m_min * factor);
	if(orig_drb != m_prDrb|| orig_g != m_games  || orig_min != current_min)
		m_reb  = m_oreb + int( double(m_prDrb+1) / 100 * m_hi_drb / 480 * m_min * factor);
	if(orig_ast != m_prAst|| orig_g != m_games  || orig_min != current_min)
		m_ast  = int( double(m_prAst+1) / 100 * m_hi_ast / 480 * m_min * factor);
	if(orig_stl != m_prStl|| orig_g != m_games  || orig_min != current_min)
		m_stl  = int( double(m_prStl+1) / 100 * m_hi_stl / 480 * m_min * factor);
	if(orig_to  != m_prTo || orig_g != m_games  || orig_min != current_min)
		m_to   = int( double(101 - m_prTo ) / 100 * m_hi_to  / 480 * m_min * factor);
	if(orig_blk != m_prBlk|| orig_g != m_games  || orig_min != current_min)
		m_blk  = int( double(m_prBlk+1) / 100 * m_hi_blk / 480 * m_min * factor);



	if(orig_min != current_min || orig_g != m_games) m_min = int(double(m_min) * factor);
	

	
	if(m_pf == 0)
		m_pf = int( double(m_min) * m_avg_pf / 48);
	else if(orig_g != m_games || orig_min != current_min)
	{
		temp  =  double(m_pf) * factor ;
		m_pf = int(temp);
		if( temp - m_pf >= .5) m_pf = m_pf + 1;
	}

}


void ConvertRatingsToStats(int orig_g, int orig_min, 
					double m_avg_g, double m_avg_min, 
					double m_avg_fga, double m_avg_fgp,
					double m_avg_fta, double m_avg_ftp,
					double m_avg_tga, double m_avg_tgp,
					double m_avg_orb, double m_avg_drb, double m_avg_ast,
					double m_avg_stl, double m_avg_to, double m_avg_blk,
					double m_avg_pf,
					int m_hi_fga, int m_hi_fta, int m_hi_tga, 
					int m_hi_orb, int m_hi_drb, int m_hi_ast,
					int m_hi_stl, int m_hi_to, int m_hi_blk					
					)

{


	m_games = orig_g;
	m_min = orig_g * orig_min;

	double factor = 1;

	double temp = 0;
		
		m_fta = int( double(m_prFta+1) / 100 * m_hi_fta / 480 * m_min * factor);
		temp = double(m_prFtp)/100 * m_fta;
		m_ftm = int(temp);
		if( temp - m_ftm >= .5) m_ftm = m_ftm + 1;
		m_fga = int( double(m_prFga+1) / 100 * m_hi_fga / 480 * m_min * factor);
		temp = double(m_prFgp)/100 * m_fga;
		m_fgm = int(temp);
		if( temp - m_fgm >= .5) m_fgm = m_fgm + 1;
		m_tfga = int( double(m_prTga+1) / 100 * m_hi_tga / 480 * m_min * factor);
		temp = double(m_prTgp)/100 * m_tfga;
		m_tfgm = int(temp);
		if( temp - m_tfga >= .5) m_tfgm = m_tfgm + 1;

	m_fgm = m_fgm + m_tfgm;
	m_fga = m_fga + m_tfga;
	
	

		m_oreb  = int( double(m_prOrb+1) / 100 * m_hi_orb / 480 * m_min * factor);
		m_reb  = m_oreb + int( double(m_prDrb+1) / 100 * m_hi_drb / 480 * m_min * factor);
		m_ast  = int( double(m_prAst+1) / 100 * m_hi_ast / 480 * m_min * factor);
		m_stl  = int( double(m_prStl+1) / 100 * m_hi_stl / 480 * m_min * factor);
		m_to   = int( double(101 - m_prTo ) / 100 * m_hi_to  / 480 * m_min * factor);
		m_blk  = int( double(m_prBlk+1) / 100 * m_hi_blk / 480 * m_min * factor);

		
		m_min = int(double(m_min) * factor);
	

	
		temp  =  double(m_pf) * factor ;
		m_pf = int(temp);
		if( temp - m_pf >= .5) m_pf = m_pf + 1;

}



int PrRating(bool shooting, int r, int m_chart[11])
{
	if(r > 99 && r <= 200) r = 99;
	int d1 = int(r/10.);
	int d2 = r - d1*10;
	int tmp_d1 = 0, tmp_d2 = 0;

	if(d1 <= 4)
	{
		tmp_d1 = m_chart[d1+1] - 1;
	}
	else
	{
		tmp_d1 = m_chart[d1-4] + 4;
	}
	if(d2 <= 4)
	{
		tmp_d2 = m_chart[d2+1] - 1;
	}
	else
	{
		tmp_d2 = m_chart[d2-4] + 4;
	}
	int result = int(double(tmp_d1*10) + double(tmp_d2));	
	double multiplier = 1;
	if(shooting == true) multiplier = 1./4.;
	double factor = 100. + (double(result) - double(r)) * multiplier;	
	result = int( double(r) * factor/100.);

	if(r > 200 && r <= 210) result = m_chart[r - 200];

	return result;

}





void SetRosterNumber(int n){m_number=n;}
void SetName(CString n){m_name = n;}
void SetLastName(CString n)
{
	int pos = n.Find(' ');
	m_lastName = n.Mid(pos + 1);
}

void SetInjury(int i)
{
	m_injury = i;
}
void SetAge(int i){m_age = i;}
void SetID(int i){m_id = i;}
void SetPos(CString n){m_pos = n;}
void SetGames(int n){m_games = n;}
void SetMin(int n){m_min=n;}
void SetFgm(int n){m_fgm=n;}
void SetFga(int n){m_fga=n;}
void SetFtm(int n){m_ftm=n;}
void SetFta(int n){m_fta=n;}
void SetTfgm(int n){m_tfgm=n;}
void SetTfga(int n){m_tfga=n;}
void SetOreb(int n){m_oreb=n;}
void SetReb(int n){m_reb=n;}
void SetAst(int n){m_ast=n;}
void SetStl(int n){m_stl=n;}
void SetTo(int n){m_to=n;}
void SetBlk(int n){m_blk=n;}
void SetPf(int n){m_pf=n;}
virtual void SetMovOff(int n){m_movoff=n;}
void SetMovDef(int n){m_movdef=n;}
void SetPenOff(int n){m_penoff=n;}
void SetPenDef(int n){m_pendef=n;}
void SetPostOff(int n){m_postoff=n;}
void SetPostDef(int n){m_postdef=n;}
void SetTransOff(int n){m_transoff=n;}
void SetTransDef(int n){m_transdef=n;}
void SetClutch(int n){m_clutch=n;}
void SetConsistency(int n){m_consistency=n;}
void SetPgRot(int n){m_pgrot=n;}
void SetSgRot(int n){m_sgrot=n;}
void SetSfRot(int n){m_sfrot=n;}
void SetPfRot(int n){m_pfrot=n;}
void SetCRot(int n){m_crot=n;}
void SetActive(BOOL n){m_active=n;}
void SetBetter(int n){m_better=n;}
void SetTeam(CString team){	m_team = team;}

void SetPrFga(int n){m_prFga=n;}
void SetPrFgp(int n){m_prFgp=n;}
void SetPrTga(int n){m_prTga=n;}
void SetPrTgp(int n){m_prTgp=n;}
void SetPrOrb(int n){m_prOrb=n;}
void SetPrDrb(int n){m_prDrb=n;}
void SetPrAst(int n){m_prAst=n;}
void SetPrStl(int n){m_prStl=n;}
void SetPrTo(int n){m_prTo=n;}
void SetPrBlk(int n){m_prBlk=n;}
void SetPrFta(int n){m_prFta=n;}
void SetPrFtp(int n){m_prFtp=n;}
void SetPot1(int n){m_pot1 = n;}
void SetPot2(int n){m_pot2 = n;}
void SetEffort(int n){m_effort = n;}
void SetPrime(int n){m_prime = n;}
	
void SetAdjPrFga(int n){m_adjPrFga=n;}
void SetAdjPrFgp(int n){m_adjPrFgp=n;}
void SetAdjPrTga(int n){m_adjPrTga=n;}
void SetAdjPrTgp(int n){m_adjPrTgp=n;}
void SetAdjPrOrb(int n){m_adjPrOrb=n;}
void SetAdjPrDrb(int n){m_adjPrDrb=n;}
void SetAdjPrAst(int n){m_adjPrAst=n;}
void SetAdjPrStl(int n){m_adjPrStl=n;}
void SetAdjPrTo(int n){m_adjPrTo=n;}
void SetAdjPrBlk(int n){m_adjPrBlk=n;}
void SetAdjPrFta(int n){m_adjPrFta=n;}
void SetAdjPrFtp(int n){m_adjPrFtp=n;}
void SetAdjPot1(int n){m_adjPot1 = n;}
void SetAdjPot2(int n){m_adjPot2 = n;}
void SetAdjEffort(int n){m_adjEffort = n;}
void SetAdjPrime(int n){m_adjPrime = n;}
	
void SetTotalGames(int g)
{
	m_totalGames = g;
}

void SetTeamGames(int g)
{
	m_teamGames = g;
}

void SetTrueRating(double factor, bool simple)
{

	int	fgm = m_fgm;
	int	fga = m_fga;
	int	reb = m_reb;

	double gun = double(fgm) + double(m_tfgm) - ((double(fga) - double(fgm)) * 2 / 3);
	gun = gun + double(m_ftm) - (double(m_fta) / 2);
	gun = gun + (double(m_fta) - double(m_ftm)) * 1 / 6;

	double skill = double(m_oreb) * 2 / 3 + (double(reb) - double(m_oreb)) * 1 / 3;
	skill = skill + double(m_stl) - double(m_to) + double(m_blk);
	skill = skill + double(m_ast) * 4 / 5;

	double tru = gun * 3 / 2 + skill * 3 / 4;

	int t_mi = m_min;
	if (t_mi == 0) t_mi = 1;
	gun = gun / t_mi * 48;
	skill = skill / t_mi * 48;




	if (m_games == 0)
		tru = 0;
	else
	{
		double min = double(m_min) / double(m_games);
		double games = double(m_games);
		tru = tru / games;
		tru = tru - factor / 48 * min;
		tru = (pow(100 + tru, 13.0)) / (pow(100, 13.0) + pow(100 + tru, 13.0));
		tru = tru * games - games / 2;
	}





	if (m_min > 0) m_trueRating = tru;

	fgm = m_sim_fgm + m_sim_tfgm;
	fga = m_sim_fga + m_sim_tfga;
	reb = m_sim_reb + m_sim_oreb;

	gun = double(fgm) + double(m_sim_tfgm) - ((double(fga) - double(fgm)) * 2 / 3);
	gun = gun + double(m_sim_ftm) - (double(m_sim_fta) / 2);
	gun = gun + (double(m_sim_fta) - double(m_sim_ftm)) * 1 / 6;

	skill = double(m_sim_oreb) * 2 / 3 + (double(reb) - double(m_sim_oreb)) * 1 / 3;
	skill = skill + double(m_sim_stl) - double(m_sim_to) + double(m_sim_blk);
	skill = skill + double(m_sim_ast) * 4 / 5;

	tru = gun * 3 / 2 + skill * 3 / 4;

	t_mi = m_sim_min;
	if (t_mi == 0) t_mi = 1;
	gun = gun / t_mi * 48;
	skill = skill / t_mi * 48;

	if (m_sim_games == 0)
		tru = 0;
	else
	{
		double min = double(m_sim_min) / double(m_sim_games);
		double games = double(m_sim_games);
		if (simple == false)//simple is tru doesnt do per minute here - good for awards!!
		{
			tru = tru / games;
			tru = tru - factor / 48 * min;
			tru = (pow(100 + tru, 13.0)) / (pow(100, 13.0) + pow(100 + tru, 13.0));
			tru = tru * games - games / 2;
		}
	}
	if (m_sim_min > 0) m_sim_trueRating = tru;

	fgm = m_po_fgm + m_po_tfgm;
	fga = m_po_fga + m_po_tfga;
	reb = m_po_reb + m_po_oreb;

	gun = double(fgm) + double(m_po_tfgm) - ((double(fga) - double(fgm)) * 2 / 3);
	gun = gun + double(m_po_ftm) - (double(m_po_fta) / 2);
	gun = gun + (double(m_po_fta) - double(m_po_ftm)) * 1 / 6;

	skill = double(m_po_oreb) * 2 / 3 + (double(reb) - double(m_po_oreb)) * 1 / 3;
	skill = skill + double(m_po_stl) - double(m_po_to) + double(m_po_blk);
	skill = skill + double(m_po_ast) * 4 / 5;

	tru = gun * 3 / 2 + skill * 3 / 4;

	t_mi = m_po_min;
	if (t_mi == 0) t_mi = 1;
	gun = gun / t_mi * 48;
	skill = skill / t_mi * 48;

	if (m_po_games == 0)

		tru = 0;

	else
	{
		double min = double(m_po_min) / double(m_po_games);
		double games = double(m_po_games);
		tru = tru / games;
		tru = tru - factor / 48 * min;
		tru = (pow(100 + tru, 13.0)) / (pow(100, 13.0) + pow(100 + tru, 13.0));
		tru = tru * games - games / 2;
	}
	if (m_po_min > 0)
		m_po_trueRating = tru;

}

double GetSimTrueSimple(bool per48)
{

	int fgm = m_sim_fgm + m_sim_tfgm;
	int fga = m_sim_fga + m_sim_tfga;
	int reb = m_sim_reb + m_sim_oreb;

	double gun = double(fgm) + double(m_sim_tfgm) - ((double(fga) - double(fgm)) * 2 / 3);
	gun = gun + double(m_sim_ftm) - (double(m_sim_fta) / 2);
	gun = gun + (double(m_sim_fta) - double(m_sim_ftm)) * 1 / 6;

	double skill = double(m_sim_oreb) * 2 / 3 + (double(reb) - double(m_sim_oreb)) * 1 / 3;
	skill = skill + double(m_sim_stl) - double(m_sim_to) + double(m_sim_blk);
	skill = skill + double(m_sim_ast) * 4 / 5;

	double tru = gun * 3 / 2 + skill * 3 / 4;

	if (m_sim_min == 0) m_sim_min = 1;

	if (m_sim_games == 0)
		tru = 0;
	else if (per48)
	{
		tru = tru / m_sim_min * 48;
	}

	return tru;
}

void SetAdjTrueRatingSimple(int fgm, int fga, int tgm, int tga, int ftm, int fta, int orb, int reb, int ast, int stl, int to, int blk, int scoring[6], int shooting[6], int rebounding[6], int passing[6], int defense[6])
{
	double shoot = double(abs(shooting[1] - 1) + abs(shooting[2]-2) + abs(shooting[3]-3) + abs(shooting[4]-4) + abs(shooting[5]-5))/100;
	if(shooting[1] <= 3) shoot = 1-shoot; else shoot = 1+shoot;
	double score = double(abs(scoring[1] - 1) + abs(scoring[2]-2) + abs(scoring[3]-3) + abs(scoring[4]-4) + abs(scoring[5]-5))/100;
	if(scoring[1] <= 3) score = 1-score; else score = 1+score;
	double rebound = double(abs(rebounding[1] - 1) + abs(rebounding[2]-2) + abs(rebounding[3]-3) + abs(rebounding[4]-4) + abs(rebounding[5]-5))/100;
	if(rebounding[1] <= 3) rebound = 1-rebound; else rebound = 1+rebound;
	double pass = double(abs(passing[1] - 1) + abs(passing[2]-2) + abs(passing[3]-3) + abs(passing[4]-4) + abs(passing[5]-5))/100;
	if(passing[1] <= 3) pass = 1-pass; else pass = 1+pass;
	double defend = double(abs(defense[1] - 1) + abs(defense[2]-2) + abs(defense[3]-3) + abs(defense[4]-4) + abs(defense[5]-5))/100;
	if(defense[1] <= 3) defend = 1-defend; else defend = 1+defend;



  	double gun = double(fgm)*shoot + double(tgm)*shoot - ((double(fga)*score - double(fgm)*shoot) * 2/3);
  	gun = gun + double(ftm)*shoot - (double(fta)*score / 2); 
	gun = gun + ( double(fta)*score - double(ftm)*shoot) * 1/6;
	gun = gun * 3/2;//fix this shit maybe
  	double skill = double(orb)*rebound * 2/3 + (double(reb)*rebound - double(orb)*rebound) * 1/3;
	skill = skill + double(stl)*defend -  double(to)*pass + double(blk)*defend;
  	skill = skill + double(ast)*pass * 4 / 5;
	skill = skill * 3/4;//fix this shit maybe
	double tru = gun + skill;
	m_trueRatingSimple = tru;

}

void SetTrueRatingSimple(int m_statStyle)
{
	int fgm = 0, fga = 0, reb = 0;


	if(m_statStyle == 2)
	{
		fgm = GetFgm();
		fga = GetFga();
		reb = GetReb();
	}
	else
	{
		fgm = GetFgm() + GetTfgm();
		fga = GetFga() + GetTfga();
		reb = GetOreb() + GetReb();
	}

  	double gun = double(fgm) + double(GetTfgm()) - ((double(fga) - double(fgm)) * 2/3);
  	gun = gun + double(GetFtm()) - (double(GetFta()) / 2); 
	gun = gun + ( double(GetFta()) - double(GetFtm())) * 1/6;
	gun = gun * 3/2;//fix this shit maybe
  	double skill = double(GetOreb()) * 2/3 + (double(reb) - double(GetOreb())) * 1/3;
	skill = skill + double(GetStl()) -  double(GetTo()) + double(GetBlk());
  	skill = skill + double(GetAst()) * 4 / 5;
	skill = skill * 3/4;//fix this shit maybe
	double tru = gun + skill;
	m_trueRatingSimple = tru;

	double tru48 = tru / m_min * 48;

}



void GenerateODPT()
{


	SetOutside();
	SetOutsideDefense();
	SetDriving();
	SetDrivingDefense();
	SetPost();
	SetPostDefense();
	SetTransition();
	SetTransitionDefense();
//	RandomizeODPT();


	int oo = Round(GetOutside()) - 3 + IntRandom(3);
	int od = Round(GetOutsideDefense()) - 3 + IntRandom(3);
	int po = Round(GetDriving()) - 3 + IntRandom(3);
	int pd = Round(GetDrivingDefense()) - 3 + IntRandom(3);
	int io = Round(GetPost()) - 3 + IntRandom(3);
	int id = Round(GetPostDefense()) - 3 + IntRandom(3);
	int fo = Round(GetTransition()) - 3 + IntRandom(3);
	int fd = Round(GetTransitionDefense()) - 3 + IntRandom(3);
	if(oo > 9) oo = 9; else if(oo < 1) oo = 1;
	if(od > 9) od = 9; else if(od < 1) od = 1;
	if(po > 9) po = 9; else if(po < 1) po = 1;
	if(pd > 9) pd = 9; else if(pd < 1) pd = 1;
	if(io > 9) io = 9; else if(io < 1) io = 1;
	if(id > 9) id = 9; else if(id < 1) id = 1;
	if(fo > 9) fo = 9; else if(fo < 1) fo = 1;
	if(fd > 9) fd = 9; else if(fd < 1) fd = 1;
	
	
	SetMovOff(oo);
	SetMovDef(od);
	SetPenOff(po);
	SetPenDef(pd);
	SetPostOff(io);
	SetPostDef(id);
	SetTransOff(fo);
	SetTransDef(fd);



}

void SetTradeTrueRating(int m_injury)
{


	double defense = (double(m_movdef) + double(m_postdef) + double(m_pendef) + double(m_transdef) - 20) * .25;
	defense = defense/48 * m_min;
	if(m_injury >= 5 || m_games == 0) m_tradeTrueRating = 0;
	else m_tradeTrueRating = (m_trueRatingSimple + defense) / m_games;

}




void SetTeammatesBetterRating(double avgFga,
							  double avgFta, double avgTfga, double avgTru,
							  double avgOrb, double avgDrb, double avgAst,
							  double avgStl, double avgTo, double avgBlk)
							  
{



	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double ftm = double(m_ftm);
	double fta = double(m_fta);

	double fgm = double(m_fgm);
	double fga = double(m_fga);
	int reb = m_reb;

	double fgm2 = 0, tfgm3 = 0, ftm1 = 0;
	

	if((fga - tfga) == 0) 
		fgm2 = 0; 
	else 
		fgm2 = (fgm - tfgm) / (fga - tfga) * avgFga;//2's made based on league avg 
	
	if(tfga == 0)
		tfgm3 = 0;
	else 
		tfgm3 = tfgm / tfga * avgTfga;//3's 
	
	if(fta == 0)
		ftm1 = 0; 
	else 
		ftm1 = ftm / fta * avgFta;//fts
	
	fgm2 = fgm2 - tfgm3;
  	double tru = fgm + tfgm - (fga - fgm) * 2/3;
	tru = tru + ftm - fta / 2; 
	tru = tru + (fta - ftm) * 1/6;
	tru = tru + double(m_oreb) * 2/3 + (double(reb) - double(m_oreb)) * 1/3;
	tru = tru + double(m_stl) -  double(m_to) + double(m_blk);
	tru = tru + double(m_ast) * 4 / 5;
	double min = double(m_min);
	if(min == 0) min = 1;
	double games = double(m_games);
	if(games == 0) games = 1;
	tru = tru / min * 48 - avgTru; //tru per 48 minutes

	double tm = fgm2 + tfgm3 - (avgFga - fgm2) * 2/3;
	tm = tm + ftm1 - avgFta / 2; 
	tm = tm + (avgFta - ftm1) * 1/6;
	tm = tm + double(m_oreb) / min * 48 * 2/3 + 
		(double(reb) / min * 48 - double(m_oreb) / min * 48) * 1/3;
	tm = tm + double(m_stl) / min * 48 -  
		double(m_to) / min * 48 + double(m_blk) / min * 48;
	double avg_skill = avgOrb*2/3 + avgDrb*1/3 + avgAst*4/5 + avgStl - avgTo + avgBlk;
	//fix this shit maybe
	tm = tm - avg_skill; //teammates better per 48 minutes
	if(m_min > 0) 
	m_teammatesBetterRating = tru - tm;

	//m_teammatesBetterRating = 0;



	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);

	fgm = double(m_sim_fgm + m_sim_tfgm);
	fga = double(m_sim_fga + m_sim_tfga);
	reb = m_sim_reb + m_sim_oreb;

	fgm2 = 0, tfgm3 = 0, ftm1 = 0;
	

	if((fga - tfga) == 0) 
		fgm2 = 0; 
	else 
		fgm2 = (fgm - tfgm) / (fga - tfga) * avgFga;//2's made based on league avg 
	
	if(tfga == 0)
		tfgm3 = 0;
	else 
		tfgm3 = tfgm / tfga * avgTfga;//3's 
	
	if(fta == 0)
		ftm1 = 0; 
	else 
		ftm1 = ftm / fta * avgFta;//fts
	
	fgm2 = fgm2 - tfgm3;
  	tru = fgm + tfgm - (fga - fgm) * 2/3;
	tru = tru + ftm - fta / 2; 
	tru = tru + (fta - ftm) * 1/6;
	tru = tru + double(m_sim_oreb) * 2/3 + (double(reb) - double(m_sim_oreb)) * 1/3;
	tru = tru + double(m_sim_stl) -  double(m_sim_to) + double(m_sim_blk);
	tru = tru + double(m_sim_ast) * 4 / 5;
	min = double(m_sim_min);
	if(min == 0) min = 1;
	games = double(m_sim_games);
	if(games == 0) games = 1;
	tru = tru / min * 48 - avgTru; //tru per 48 minutes

	tm = fgm2 + tfgm3 - (avgFga - fgm2) * 2/3;
	tm = tm + ftm1 - avgFta / 2; 
	tm = tm + (avgFta - ftm1) * 1/6;
	tm = tm + double(m_sim_oreb) / min * 48 * 2/3 + 
		(double(reb) / min * 48 - double(m_sim_oreb) / min * 48) * 1/3;
	tm = tm + double(m_sim_stl) / min * 48 -  
		double(m_sim_to) / min * 48 + double(m_sim_blk) / min * 48;
	avg_skill = avgOrb*2/3 + avgDrb*1/3 + avgAst*4/5 + avgStl - avgTo + avgBlk;
	//fix this shit maybe
	tm = tm - avg_skill; //teammates better per 48 minutes
	if(m_sim_min > 0) 
	m_sim_teammatesBetterRating = tru - tm;

	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	ftm = double(m_po_ftm);
	fta = double(m_po_fta);

	fgm = double(m_po_fgm + m_po_tfgm);
	fga = double(m_po_fga + m_po_tfga);
	reb = m_po_reb + m_po_oreb;

	fgm2 = 0, tfgm3 = 0, ftm1 = 0;
	

	if((fga - tfga) == 0) 
		fgm2 = 0; 
	else 
		fgm2 = (fgm - tfgm) / (fga - tfga) * avgFga;//2's made based on league avg 
	
	if(tfga == 0)
		tfgm3 = 0;
	else 
		tfgm3 = tfgm / tfga * avgTfga;//3's 
	
	if(fta == 0)
		ftm1 = 0; 
	else 
		ftm1 = ftm / fta * avgFta;//fts
	
	fgm2 = fgm2 - tfgm3;
  	tru = fgm + tfgm - (fga - fgm) * 2/3;
	tru = tru + ftm - fta / 2; 
	tru = tru + (fta - ftm) * 1/6;
	tru = tru + double(m_po_oreb) * 2/3 + (double(reb) - double(m_po_oreb)) * 1/3;
	tru = tru + double(m_po_stl) -  double(m_po_to) + double(m_po_blk);
	tru = tru + double(m_po_ast) * 4 / 5;
	min = double(m_po_min);
	if(min == 0) min = 1;
	games = double(m_po_games);
	if(games == 0) games = 1;
	tru = tru / min * 48 - avgTru; //tru per 48 minutes

	tm = fgm2 + tfgm3 - (avgFga - fgm2) * 2/3;
	tm = tm + ftm1 - avgFta / 2; 
	tm = tm + (avgFta - ftm1) * 1/6;
	tm = tm + double(m_po_oreb) / min * 48 * 2/3 + 
		(double(reb) / min * 48 - double(m_po_oreb) / min * 48) * 1/3;
	tm = tm + double(m_po_stl) / min * 48 -  
		double(m_po_to) / min * 48 + double(m_po_blk) / min * 48;
	avg_skill = avgOrb*2/3 + avgDrb*1/3 + avgAst*4/5 + avgStl - avgTo + avgBlk;
	//fix this shit maybe
	tm = tm - avg_skill; //teammates better per 48 minutes
	if(m_po_min > 0) 
	m_po_teammatesBetterRating = tru - tm;


} 



double AdjustTeammatesBetterRatingForPasser(double avgAst)
{



	double tru = (m_AstPer48Min - avgAst) * 4/5; //tru per 48 minutes
	return tru;



} 





void SetAstTo()
{
	if(m_to > 0)
		m_astTo = double(m_ast) / double(m_to);
	else 
		m_astTo = (double)m_ast;

	if(m_sim_to > 0)
		m_sim_astTo = double(m_sim_ast) / double(m_sim_to);
	else 
		m_sim_astTo = (double)m_sim_ast;

	if(m_po_to > 0)
		m_po_astTo = double(m_po_ast) / double(m_po_to);
	else 
		m_po_astTo = (double)m_po_ast;
}

void SetDefense()
{
	double rebRatio = 0;
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	double fgm = double(m_fgm - m_tfgm);
	double reb = double(m_reb - m_oreb) * 1/3;
	double fga = double(m_fga - m_tfga);
	
	double fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_defense = (double(m_stl)  + double(m_blk) +
		reb  - m_pf) / games;
	double ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	if(m_min > 0) 
		m_defense =  m_defense + ftRatio - rebRatio;
	else 
		m_defense = 0;


	rebRatio = 0;
	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm);
	reb = double(m_sim_reb) * 1/3;
	fga = double(m_sim_fga);
	
	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_sim_defense = (double(m_sim_stl)  + double(m_sim_blk) +
		reb  - m_sim_pf) / games;
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	if(m_sim_min > 0) 
		m_sim_defense =  m_sim_defense + ftRatio - rebRatio;
	else
		m_sim_defense = 0;
	rebRatio = 0;
	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm);
	reb = double(m_po_reb) * 1/3;
	fga = double(m_po_fga);
	

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_po_defense = (double(m_po_stl)  + double(m_po_blk) +
		reb  - m_po_pf) / games;
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	if(m_po_min > 0) 
		m_po_defense =  m_po_defense + ftRatio - rebRatio;
	else
		m_po_defense = 0;

}

void SetOutside()
{

	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	
	double fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);

	m_outside = fgm * 2 + tfgm * 3 - fta  - oreb - 
		(fga - fgm) - (tfga - tfgm) ;//shooting
	m_outside = m_outside / m_min * 48 + ftPct;
	if(m_min > 0) 
		m_outside = (m_outside + 10) / 2;
	else
		m_outside = 0;
	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);

	m_sim_outside = fgm * 2 + tfgm * 3 - fta  - oreb - 
		(fga - fgm) - (tfga - tfgm) ;//shooting
	m_sim_outside = m_sim_outside / m_sim_min * 48 + ftPct;
	if(m_sim_min > 0)
		m_sim_outside = (m_sim_outside + 10) / 2;
	else
		m_sim_outside = 0;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);

	m_po_outside = fgm * 2 + tfgm * 3 - fta  - oreb - 
		(fga - fgm) - (tfga - tfgm) ;//shooting
	m_po_outside = m_po_outside / m_po_min * 48 + ftPct;
	if(m_po_min > 0)
		m_po_outside = (m_po_outside + 10) / 2;
	else
		m_po_outside = 0;


}
void SetDriving()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);
	double fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_driving = (fgm + fta) / 6 + m_ast / 2;//penetration

//		m_outside = 0;
	m_driving = m_driving / m_min * 48 +  rebRatio * 2;

	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(fgm - tfgm);
	reb = double(reb - oreb) * 1/3;
	fga = double(fga) - double(tfga);
	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_sim_driving = (fgm + fta) / 6 + m_sim_ast / 2;//penetration
	m_sim_driving = m_sim_driving / m_sim_min * 48 +  rebRatio * 2;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(fgm - tfgm);
	reb = double(reb - oreb) * 1/3;
	fga = double(fga) - double(tfga);
	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_po_driving = (fgm + fta) / 6 + m_po_ast / 2;//penetration
	m_po_driving = m_po_driving / m_po_min * 48 +  rebRatio * 2;

	if(m_min == 0) m_driving = 0;
	if(m_sim_min == 0) m_sim_driving = 0;
	if(m_po_min == 0) m_po_driving = 0;

}

void SetPost()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	//higher the ratio the quicker he is vs. the stronger he is
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	double to = double(m_to);
	m_post = (oreb * 4/5 + reb) * fgPct + fta * 3/5 - to * 4/5;//post game
	m_post = m_post / m_min * 48 + ( 1 - rebRatio);
//		m_outside = 0;
//	m_driving = m_driving / m_min * 48 +  rebRatio * 2;
	m_post = (m_post + 1) * 9/8;

	ftm = double(m_ftm);
	fta = double(m_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm - m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	//higher the ratio the quicker he is vs. the stronger he is
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	to = double(m_sim_to);
	m_sim_post = (oreb * 4/5 + reb) * fgPct + fta * 3/5 - to * 4/5;//post game
	m_sim_post = m_sim_post / m_sim_min * 48 + ( 1 - rebRatio);
	m_sim_post = (m_sim_post + 1) * 9/8;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct =  0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm - m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	//higher the ratio the quicker he is vs. the stronger he is
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	to = double(m_po_to);
	m_po_post = (oreb * 4/5 + reb) * fgPct + fta * 3/5 - to * 4/5;//post game
	m_po_post = m_po_post / m_po_min * 48 + ( 1 - rebRatio);
	m_po_post = (m_po_post + 1) * 9/8;

	if(m_min == 0) m_post = 0;
	if(m_sim_min == 0) m_sim_post = 0;
	if(m_po_min == 0) m_po_post = 0;

}

void SetTransition()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_transition = fta/2 + oreb/2 + m_ast/2 - reb;//transition
	m_transition = m_transition / m_min * 48;
//		m_outside = 0;
//	m_driving = m_driving / m_min * 48 +  rebRatio * 2;
//	m_post = (m_post + 1) * 9/8;

	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_sim_transition = fta/2 + oreb/2 + m_sim_ast/2 - reb;//transition
	m_sim_transition = m_sim_transition / m_sim_min * 48;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = 0;
	if(fta > 0) ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = 0;
	if(tfga > 0) tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);

	fgPct = 0;
	if(fga > 0) fgPct = fgm / fga;

	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	m_po_transition = fta/2 + oreb/2 + m_po_ast/2 - reb;//transition
	m_po_transition = m_po_transition / m_po_min * 48;

	if(m_min == 0) m_transition = 0;
	if(m_sim_min == 0) m_sim_transition = 0;
	if(m_po_min == 0) m_po_transition = 0;


}


void SetOutsideDefense()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	double pf = double(m_pf);
	double stl = double(m_stl);
	double blk = double(m_blk);
	double to = double(m_to);
	double ast = double(m_ast);
	double ratio = (ast + reb*3)/ (ast + reb*3 + to);
	double stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	double blkpfRatio = 0;
	if(pf > 0) blkpfRatio = blk/pf;
	double stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	double rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	double ftRatio = 0;
	if(fga > 0) ftRatio =  fta / fga;
	double orebFactor = 0;

	orebFactor = (oreb + reb * 3) / m_min * 10;
	m_outsideDefense = stl + blk / 4 - pf / 4;//outside defense
	m_outsideDefense = m_outsideDefense / m_min * 48 + ftRatio * 2 
		+ stlblkRatio + (1-rebRatio) * 2 + blkpfRatio + orebFactor;


	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	pf = double(m_sim_pf);
	stl = double(m_sim_stl);
	blk = double(m_sim_blk);
	to = double(m_sim_to);
	ast = double(m_sim_ast);
	ratio = (ast + reb*3)/ (ast + reb*3 + to);
	stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	blkpfRatio = 0;
	if(pf > 0) blkpfRatio = blk/pf;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	ftRatio = 0;
	if(fga > 0) ftRatio =  fta / fga;
	orebFactor = 0;

	orebFactor = (oreb + reb * 3) / m_sim_min * 10;
	m_sim_outsideDefense = stl + blk / 4 - pf / 4;//outside defense
	m_sim_outsideDefense = m_sim_outsideDefense / m_sim_min * 48 + ftRatio * 2 
		+ stlblkRatio + (1-rebRatio) * 2 + blkpfRatio + orebFactor;


	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);

	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	pf = double(m_po_pf);
	stl = double(m_po_stl);
	blk = double(m_po_blk);
	to = double(m_po_to);
	ast = double(m_po_ast);
	ratio = (ast + reb*3)/ (ast + reb*3 + to);
	stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	blkpfRatio = 0;
	if(pf > 0) blkpfRatio = blk/pf;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	ftRatio = 0;
	if(fga > 0) ftRatio =  fta / fga;
	orebFactor = 0;

	orebFactor = (oreb + reb * 3) / m_po_min * 10;
	m_po_outsideDefense = stl + blk / 4 - pf / 4;//outside defense
	m_po_outsideDefense = m_po_outsideDefense / m_po_min * 48 + ftRatio * 2 
		+ stlblkRatio + (1-rebRatio) * 2 + blkpfRatio + orebFactor;


	if(m_min == 0) m_outsideDefense = 0;
	if(m_sim_min == 0) m_sim_outsideDefense = 0;
	if(m_po_min == 0) m_po_outsideDefense = 0;

}

void SetDrivingDefense()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	double pf = double(m_pf);
	double stl = double(m_stl);
	double blk = double(m_blk);
	double to = double(m_to);
	double ast = double(m_ast);
	double ratio = 0;
	if((ast + reb + to) > 0)
		ratio = (ast + reb*3)/ (ast + reb*3 + to);
	double stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	double stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	double rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	double ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_drivingDefense = stl -  pf / 4;//driving defense
	m_drivingDefense = m_drivingDefense / m_min * 48 + ftRatio
		+ stlblkRatio + rebfgaRatio + stlpfRatio + ratio;
	m_drivingDefense = m_drivingDefense * 4/3;

	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	pf = double(m_sim_pf);
	stl = double(m_sim_stl);
	blk = double(m_sim_blk);
	to = double(m_sim_to);
	ast = double(m_sim_ast);
	ratio = 0;
	double fa = ast + reb*3 + to; 
	if(fa > 0) ratio = (ast + reb*3)/ fa;
	stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_sim_drivingDefense = stl -  pf / 4;//driving defense
	m_sim_drivingDefense = m_sim_drivingDefense / m_min * 48 + ftRatio
		+ stlblkRatio + rebfgaRatio + stlpfRatio + ratio;
	m_sim_drivingDefense = m_sim_drivingDefense * 4/3;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);


	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	pf = double(m_po_pf);
	stl = double(m_po_stl);
	blk = double(m_po_blk);
	to = double(m_po_to);
	ast = double(m_po_ast);
	ratio = 0;
	if((ast + reb + to) > 0)
		ratio = (ast + reb*3)/ (ast + reb*3 + to);
	stlpfRatio = 0;
	if(pf > 0) stlpfRatio = stl/pf;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	rebfgaRatio = 0;
	if(fga > 0) rebfgaRatio =  reb * 3 / fga;
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_po_drivingDefense = stl -  pf / 4;//driving defense
	m_po_drivingDefense = m_po_drivingDefense / m_min * 48 + ftRatio
		+ stlblkRatio + rebfgaRatio + stlpfRatio + ratio;
	m_po_drivingDefense = m_po_drivingDefense * 4/3;


	if(m_min == 0) m_drivingDefense = 0;
	if(m_sim_min == 0) m_sim_drivingDefense = 0;
	if(m_po_min == 0) m_po_drivingDefense = 0;

}

void SetPostDefense()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	double pf = double(m_pf);
	double blk = double(m_blk);
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	double ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_postDefense = oreb * 2/3 + reb + blk -  pf / 4;//post defense
	m_postDefense = m_postDefense / m_min * 48 + ftRatio * 2 - rebRatio;

	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);



	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	pf = double(m_sim_pf);
	blk = double(m_sim_blk);
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_sim_postDefense = oreb * 2/3 + reb + blk -  pf / 4;//post defense
	m_sim_postDefense = m_sim_postDefense / m_sim_min * 48 + ftRatio * 2 - rebRatio;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);


	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	pf = double(m_po_pf);
	blk = double(m_po_blk);
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	m_po_postDefense = oreb * 2/3 + reb + blk -  pf / 4;//post defense
	m_po_postDefense = m_po_postDefense / m_po_min * 48 + ftRatio * 2 - rebRatio;

	if(m_min == 0) m_postDefense = 0;
	if(m_sim_min == 0) m_sim_postDefense = 0;
	if(m_po_min == 0) m_po_postDefense = 0;

}

void SetTransitionDefense()
{
	double ftm = double(m_ftm);
	double fta = double(m_fta);
	double ftPct = ftm / fta;

	double games = double(m_games);
	if(games == 0) games = 1;
	double oreb = double(m_oreb);
	double tfgm = double(m_tfgm);
	double tfga = double(m_tfga);
	double tfgPct = tfgm / tfga;

	double fgm = double(m_fgm);
	double reb = double(m_reb) * 1/3;
	double fga = double(m_fga);

	double fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	double pf = double(m_pf);
	double stl = double(m_stl);
	double blk = double(m_blk);
	double rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	double ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	double stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	m_transitionDefense = stl -  pf / 4;//transition d
	m_transitionDefense = 
		m_transitionDefense / m_min * 48 + ftRatio + (1 - rebRatio) * 2 +  stlblkRatio;
	m_transitionDefense = (m_transitionDefense + .5) * 1.5;

	ftm = double(m_sim_ftm);
	fta = double(m_sim_fta);
	ftPct = ftm / fta;

	games = double(m_sim_games);
	if(games == 0) games = 1;
	oreb = double(m_sim_oreb);
	tfgm = double(m_sim_tfgm);
	tfga = double(m_sim_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_sim_fgm) - double(m_sim_tfgm);
	reb = double(m_sim_reb - m_sim_oreb) * 1/3;
	fga = double(m_sim_fga) - double(m_sim_tfga);

	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	pf = double(m_sim_pf);
	stl = double(m_sim_stl);
	blk = double(m_sim_blk);
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	m_sim_transitionDefense = stl -  pf / 4;//transition d
	m_sim_transitionDefense = 
		m_sim_transitionDefense / m_sim_min * 48 + ftRatio + (1 - rebRatio) * 2 +  stlblkRatio;
	m_sim_transitionDefense = (m_sim_transitionDefense + .5) * 1.5;

	ftm = double(m_po_ftm);
	fta = double(m_po_fta);
	ftPct = ftm / fta;

	games = double(m_po_games);
	if(games == 0) games = 1;
	oreb = double(m_po_oreb);
	tfgm = double(m_po_tfgm);
	tfga = double(m_po_tfga);
	tfgPct = tfgm / tfga;

	fgm = double(m_po_fgm) - double(m_po_tfgm);
	reb = double(m_po_reb - m_po_oreb) * 1/3;
	fga = double(m_po_fga) - double(m_po_tfga);

	fgPct = fgm / fga;
	if(fga == 0) fgPct = 0.;
	if(tfga == 0) tfgPct = 0.;
	if(fta == 0) ftPct = 0.;
	

	pf = double(m_po_pf);
	stl = double(m_po_stl);
	blk = double(m_po_blk);
	rebRatio = 0;
	if(reb > 0) rebRatio = oreb / (reb * 3);
	ftRatio = 0;
	if(fga > 0) ftRatio = fta/fga;
	stlblkRatio = 0;
	if((stl+blk) > 0) stlblkRatio = stl/(stl+blk);
	m_po_transitionDefense = stl -  pf / 4;//transition d
	m_po_transitionDefense = 
		m_po_transitionDefense / m_po_min * 48 + ftRatio + (1 - rebRatio) * 2 +  stlblkRatio;
	m_po_transitionDefense = (m_po_transitionDefense + .5) * 1.5;

	if(m_min == 0) m_transitionDefense = 0;
	if(m_sim_min == 0) m_sim_transitionDefense = 0;
	if(m_po_min == 0) m_po_transitionDefense = 0;


}
void SetOutsidePer48Min(int hi)
{

	double min = double(m_min)/double(hi)/48;
		m_outsidePer48Min = m_outside * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_outsidePer48Min = m_sim_outside * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_outsidePer48Min = m_po_outside * min;

}
void SetDrivingPer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_drivingPer48Min = m_driving * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_drivingPer48Min = m_sim_driving * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_drivingPer48Min = m_po_driving * min;


}
void SetPostPer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_postPer48Min = m_post * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_postPer48Min = m_sim_post * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_postPer48Min = m_po_post * min;


}
void SetTransitionPer48Min(int hi)
{

	double min = double(m_min)/double(hi)/48;
		m_transitionPer48Min = m_transition * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_transitionPer48Min = m_sim_transition * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_transitionPer48Min = m_po_transition * min;


}



void SetOutsideDefensePer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_outsideDefensePer48Min = m_outsideDefense * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_outsideDefensePer48Min = m_sim_outsideDefense * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_outsideDefensePer48Min = m_po_outsideDefense * min;


}
void SetDrivingDefensePer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_drivingDefensePer48Min = m_drivingDefense * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_drivingDefensePer48Min = m_sim_drivingDefense * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_drivingDefensePer48Min = m_po_drivingDefense * min;

}
void SetPostDefensePer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_postDefensePer48Min = m_postDefense * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_postDefensePer48Min = m_sim_postDefense * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_postDefensePer48Min = m_po_postDefense * min;


}
void SetTransitionDefensePer48Min(int hi)
{
	double min = double(m_min)/double(hi)/48;
		m_transitionDefensePer48Min = m_transitionDefense * min;

	min = double(m_sim_min)/double(hi)/48;
		m_sim_transitionDefensePer48Min = m_sim_transitionDefense * min;

	min = double(m_po_min)/double(hi)/48;
		m_po_transitionDefensePer48Min = m_po_transitionDefense * min;

}

void SetMvp(double factor)
{

	int fgm = m_fgm;
	int fga = m_fga;
	int reb = m_oreb;

  	double gun = double(fgm) + double(m_tfgm) - ((double(fga) - double(fgm)) * 2/3);
	gun = gun + double(m_ftm) - (double(m_fta) / 2); 
	gun = gun + ( double(m_fta) - double(m_ftm)) * 1/6;
	gun = gun * 3/2;//fix this shit maybe
	double skill  = double(m_oreb) * 2/3 + (double(reb) - double(m_oreb)) * 1/3;
	skill = skill + double(m_stl) -  double(m_to) + double(m_blk);
	skill = skill + double(m_ast) * 4 / 5;
	skill = skill*3/4;//fix this shit maybe
	double tru = gun + skill;
	double games = double(m_games);
	if(games == 0) games = 1;
	double min = double(m_min) / games;
	tru = tru / games - factor / 48 * min;
	double def = (m_outsideDefensePer48Min + m_drivingDefensePer48Min +
		m_postDefensePer48Min + m_transitionDefensePer48Min);
	def = (def - min*20/48) * .25;
	tru = tru + def; 
	tru = (pow(100 + tru,13.0)) / ( pow(100,13.0) + pow(100 + tru,13.0) );
	tru = tru * games - games / 2;
	m_mvp = tru;

	fgm = m_sim_fgm + m_sim_tfgm;
	fga = m_sim_fga + m_sim_tfga;
	reb = m_sim_oreb + m_sim_reb;

  	gun = double(fgm) + double(m_sim_tfgm) - ((double(fga) - double(fgm)) * 2/3);
	gun = gun + double(m_sim_ftm) - (double(m_sim_fta) / 2); 
	gun = gun + ( double(m_sim_fta) - double(m_sim_ftm)) * 1/6;
	gun = gun * 3/2;//fix this shit maybe
	skill  = double(m_sim_oreb) * 2/3 + (double(reb) - double(m_sim_oreb)) * 1/3;
	skill = skill + double(m_sim_stl) -  double(m_sim_to) + double(m_sim_blk);
	skill = skill + double(m_sim_ast) * 4 / 5;
	skill = skill*3/4;//fix this shit maybe
	tru = gun + skill;
	games = double(m_sim_games);
	if(games == 0) games = 1;
	min = double(m_sim_min) / games;
	tru = tru / games - factor / 48 * min;
	def = (m_sim_outsideDefensePer48Min + m_sim_drivingDefensePer48Min +
		m_sim_postDefensePer48Min + m_sim_transitionDefensePer48Min);
	def = (def - min*20/48) * .25;
	tru = tru + def; 
	tru = (pow(100 + tru,13.0)) / ( pow(100,13.0) + pow(100 + tru,13.0) );
	tru = tru * games - games / 2;
	m_sim_mvp = tru;

	fgm = m_po_fgm + m_po_tfgm;
	fga = m_po_fga + m_po_tfga;
	reb = m_po_oreb + m_po_reb;

  	gun = double(fgm) + double(m_po_tfgm) - ((double(fga) - double(fgm)) * 2/3);
	gun = gun + double(m_po_ftm) - (double(m_po_fta) / 2); 
	gun = gun + ( double(m_po_fta) - double(m_po_ftm)) * 1/6;
	gun = gun * 3/2;//fix this shit maybe
	skill  = double(m_po_oreb) * 2/3 + (double(reb) - double(m_po_oreb)) * 1/3;
	skill = skill + double(m_po_stl) -  double(m_po_to) + double(m_po_blk);
	skill = skill + double(m_po_ast) * 4 / 5;
	skill = skill*3/4;//fix this shit maybe
	tru = gun + skill;
	games = double(m_po_games);
	if(games == 0) games = 1;
	min = double(m_po_min) / games;
	tru = tru / games - factor / 48 * min;
	def = (m_po_outsideDefensePer48Min + m_po_drivingDefensePer48Min +
		m_po_postDefensePer48Min + m_po_transitionDefensePer48Min);
	def = (def - min*20/48) * .25;
	tru = tru + def; 
	tru = (pow(100 + tru,13.0)) / ( pow(100,13.0) + pow(100 + tru,13.0) );
	tru = tru * games - games / 2;
	m_po_mvp = tru;

	if(m_min == 0) m_mvp = 0;
	if(m_sim_min == 0) m_sim_mvp = 0;
	if(m_po_min == 0) m_po_mvp = 0;


}

void SetTradeValue()
{
	double rating = m_tradeTrueRating;
	double factor = 0;
	int age = m_age;
	double overTheHill = 1. - (double(age) - 28.)/100.;
	if(overTheHill > 1) overTheHill = 1;
	double pot = (double(m_pot1) + 1.)/4. + (double(m_pot2) + 1.)/4.;
	pot = pot/2.;
	if(age > 28) age = 28;
	factor = 1. + (((28. - double(age))*3.)/100.) * double(pot);
	double misc = (100. + double(m_effort) + double(m_pot1) + double(m_pot2) - 9.)/100.;
	
	m_tradeValue = rating*factor*misc*overTheHill;
}

double SetTruePotential(double tru)
{
	double tru_pot = 0;

	double rating = tru;
	double factor = 0;
	int age = m_age;

	double overTheHill = 1. - (double(age) - 28.)/100.;
	if(overTheHill > 1) overTheHill = 1;
	if(age < 18) age = 18;
	else if(age > 28) age = 28;

	double pot = (double(m_pot1) + 1.)/4. + (double(m_pot2) + 1.)/4.;
	pot = pot/1.;
	double chart[11] = {0,1,3, 6,10,13, 15,16,17, 18,19};
	factor = double(100 + chart[28-age] * pot) / 100;
	double misc = (97. + double(m_effort) ) / 100.;
	tru_pot = rating*factor*misc*overTheHill;
	return tru_pot;
}

void SetAdjTradeValue(int pot1[6], int pot2[6], int effort[6])
{
	int p1 = pot1[m_pot1];
	int p2 = pot2[m_pot2];
	int ef = effort[m_effort];
	double rating = m_tradeTrueRating;
	double factor = 0;
	int age = m_age;
	double overTheHill = 1. - (double(age) - 28.)/100.;
	if(overTheHill > 1) overTheHill = 1;
	double pot = (double(p1) + 1.)/4. + (double(p2) + 1.)/4.;
	pot = pot/2.;
	if(age > 28) age = 28;
	factor = 1. + (((28. - double(age))*3.)/100.) * double(pot);
	double misc = (100. + double(ef) + double(p1) + double(p2) - 9.)/100.;
	m_tradeValue = rating*factor*misc*overTheHill;
}

void SetMinPerGame(int g, int m_min)
{
	if(g == 0) g = 1;
	m_minPerGame = double(m_min) / double(g);
}

void SetPointsPerGame(int g, int m_fgm, int m_ftm, int m_tfgm)
{
	if(g == 0) g = 1;
	m_pointsPerGame = (double(m_fgm) * 2 + double(m_ftm) + double(m_tfgm) * 3) / double(g);
}


void SetReboundsPerGame(int g, int m_reb)
{
	if(g == 0) g = 1;
	m_reboundsPerGame = double(m_reb) / double(g);
}

void SetAssistsPerGame(int g, int m_ast)
{
	if(g == 0) g = 1;
	m_assistsPerGame = double(m_ast) / double(g);
}

void SetStealsPerGame(int g, int m_stl)
{
	if(g == 0) g = 1;
	m_stealsPerGame = double(m_stl) / double(g);
}

void SetBlocksPerGame(int g, int m_blk)
{
	if(g == 0) g = 1;
	m_blocksPerGame = double(m_blk) / double(g);
}

void SetFgPct(int m_fgm, int m_fga)
{
	if(m_fga == 0) m_fga = 1;
	m_fgPct = double(m_fgm) / double(m_fga) * 100;
}

void SetTfgPct(int m_tfgm, int m_tfga)
{
	if(m_tfga == 0) m_tfga = 1;
	m_tfgPct = double(m_tfgm) / double(m_tfga) * 100;
}

void SetFtPct(int m_ftm, int m_fta)
{
	if(m_fta == 0) m_fta = 1;
	m_ftPct = double(m_ftm) / double(m_fta) * 100;
}

void SetOrebPerGame(int g, int m_orb)
{
	if(g == 0) g = 1;
	m_orbPerGame = double(m_orb) / double(g);
}

void SetToPerGame(int g, int m_to)
{
	if(g == 0) g = 1;
	m_toPerGame = double(m_to) / double(g);
}

void SetPfPerGame(int g, int m_pf)
{
	if(g == 0) g = 1;
	m_pfPerGame = double(m_pf) / double(g);
}


void SetSimMinPerGame(int g, int m_sim_min)
{
	if(g == 0) g = 1;
	m_sim_minPerGame = double(m_sim_min) / double(g);
}

void SetSimPointsPerGame(int g, int m_sim_fgm, int m_sim_ftm, int m_sim_tfgm)
{
	if(g == 0) g = 1;
	m_sim_pointsPerGame = (double(m_sim_fgm) * 2 + double(m_sim_ftm) + double(m_sim_tfgm) * 3) / double(g);
}


void SetSimReboundsPerGame(int g, int m_sim_reb)
{
	if(g == 0) g = 1;
	m_sim_reboundsPerGame = double(m_sim_reb) / double(g);
}

void SetSimAssistsPerGame(int g, int m_sim_ast)
{
	if(g == 0) g = 1;
	m_sim_assistsPerGame = double(m_sim_ast) / double(g);
}

void SetSimStealsPerGame(int g, int m_sim_stl)
{
	if(g == 0) g = 1;
	m_sim_stealsPerGame = double(m_sim_stl) / double(g);
}

void SetSimBlocksPerGame(int g, int m_sim_blk)
{
	if(g == 0) g = 1;
	m_sim_blocksPerGame = double(m_sim_blk) / double(g);
}

void SetSimFgPct(int m_sim_fgm, int m_sim_fga)
{
	if(m_sim_fga == 0) m_sim_fga = 1;
	m_sim_fgPct = double(m_sim_fgm) / double(m_sim_fga) * 100;
}

void SetSimTfgPct(int m_sim_tfgm, int m_sim_tfga)
{
	if(m_sim_tfga == 0) m_sim_tfga = 1;
	m_sim_tfgPct = double(m_sim_tfgm) / double(m_sim_tfga) * 100;
}

void SetSimFtPct(int m_sim_ftm, int m_sim_fta)
{
	if(m_sim_fta == 0) m_sim_fta = 1;
	m_sim_ftPct = double(m_sim_ftm) / double(m_sim_fta) * 100;
}

void SetSimOrebPerGame(int g, int m_sim_orb)
{
	if(g == 0) g = 1;
	m_sim_orbPerGame = double(m_sim_orb) / double(g);
}

void SetSimToPerGame(int g, int m_sim_to)
{
	if(g == 0) g = 1;
	m_sim_toPerGame = double(m_sim_to) / double(g);
}

void SetSimPfPerGame(int g, int m_sim_pf)
{
	if(g == 0) g = 1;
	m_sim_pfPerGame = double(m_sim_pf) / double(g);
}

void SetPoMinPerGame(int g, int m_po_min)
{
	if(g == 0) g = 1;
	m_po_minPerGame = double(m_po_min) / double(g);
}

void SetPoPointsPerGame(int g, int m_po_fgm, int m_po_ftm, int m_po_tfgm)
{
	if(g == 0) g = 1;
	m_po_pointsPerGame = (double(m_po_fgm) * 2 + double(m_po_ftm) + double(m_po_tfgm) * 3) / double(g);
}


void SetPoReboundsPerGame(int g, int m_po_reb)
{
	if(g == 0) g = 1;
	m_po_reboundsPerGame = double(m_po_reb) / double(g);
}

void SetPoAssistsPerGame(int g, int m_po_ast)
{
	if(g == 0) g = 1;
	m_po_assistsPerGame = double(m_po_ast) / double(g);
}

void SetPoStealsPerGame(int g, int m_po_stl)
{
	if(g == 0) g = 1;
	m_po_stealsPerGame = double(m_po_stl) / double(g);
}

void SetPoBlocksPerGame(int g, int m_po_blk)
{
	if(g == 0) g = 1;
	m_po_blocksPerGame = double(m_po_blk) / double(g);
}

void SetPoFgPct(int m_po_fgm, int m_po_fga)
{
	if(m_po_fga == 0) m_po_fga = 1;
	m_po_fgPct = double(m_po_fgm) / double(m_po_fga) * 100;
}

void SetPoTfgPct(int m_po_tfgm, int m_po_tfga)
{
	if(m_po_tfga == 0) m_po_tfga = 1;
	m_po_tfgPct = double(m_po_tfgm) / double(m_po_tfga) * 100;
}

void SetPoFtPct(int m_po_ftm, int m_po_fta)
{
	if(m_po_fta == 0) m_po_fta = 1;
	m_po_ftPct = double(m_po_ftm) / double(m_po_fta) * 100;
}

void SetPoOrebPerGame(int g, int m_po_orb)
{
	if(g == 0) g = 1;
	m_po_orbPerGame = double(m_po_orb) / double(g);
}

void SetPoToPerGame(int g, int m_po_to)
{
	if(g == 0) g = 1;
	m_po_toPerGame = double(m_po_to) / double(g);
}

void SetPoPfPerGame(int g, int m_po_pf)
{
	if(g == 0) g = 1;
	m_po_pfPerGame = double(m_po_pf) / double(g);
}






void SetSeasonAverages()
{
		SetMinPerGame(GetGames(), GetMin());
		SetPointsPerGame(GetGames(), GetFgm() - GetTfgm(), GetFtm(), GetTfgm());
		SetReboundsPerGame(GetGames(), GetReb());
		SetAssistsPerGame(GetGames(), GetAst());
		SetStealsPerGame(GetGames(), GetStl());
		SetBlocksPerGame(GetGames(), GetBlk());
		SetOrebPerGame(GetGames(), GetOreb());
		SetToPerGame(GetGames(), GetTo());
		SetPfPerGame(GetGames(), GetPf());
		SetFgPct(GetFgm(), GetFga());
		SetFtPct(GetFtm(), GetFta());
		SetTfgPct(GetTfgm(), GetTfga());
//		SetPointsPerGame(GetGames(), GetFgm() - GetTfgm(), GetFtm(), GetTfgm());

		SetSimMinPerGame(m_sim_games, m_sim_min);
		SetSimPointsPerGame(m_sim_games, m_sim_fgm, m_sim_ftm, m_sim_tfgm);
		SetSimReboundsPerGame(m_sim_games, m_sim_reb);
		SetSimAssistsPerGame(m_sim_games, m_sim_ast);
		SetSimStealsPerGame(m_sim_games, m_sim_stl);
		SetSimBlocksPerGame(m_sim_games, m_sim_blk);
		SetSimOrebPerGame(m_sim_games, m_sim_oreb);
		SetSimToPerGame(m_sim_games,m_sim_to );
		SetSimPfPerGame(m_sim_games, m_sim_pf);
		SetSimFgPct(m_sim_fgm + m_sim_tfgm, m_sim_fga + m_sim_tfga);
		SetSimFtPct(m_sim_ftm, m_sim_fta);
		SetSimTfgPct(m_sim_tfgm, m_sim_tfga);

		SetPoMinPerGame(m_po_games, m_po_min);
		SetPoPointsPerGame(m_po_games, m_po_fgm, m_po_ftm, m_po_tfgm);
		SetPoReboundsPerGame(m_po_games, m_po_reb);
		SetPoAssistsPerGame(m_po_games, m_po_ast);
		SetPoStealsPerGame(m_po_games, m_po_stl);
		SetPoBlocksPerGame(m_po_games, m_po_blk);
		SetPoOrebPerGame(m_po_games, m_po_oreb);
		SetPoToPerGame(m_po_games,m_po_to );
		SetPoPfPerGame(m_po_games, m_po_pf);
		SetPoFgPct(m_po_fgm + m_po_tfgm, m_po_fga + m_po_tfga);
		SetPoFtPct(m_po_ftm, m_po_fta);
		SetPoTfgPct(m_po_tfgm, m_po_tfga);
}

void SetAdjustedRatings(CStaff scout)
{
	
		int r = GetPrFga();
		int rating = PrRating(false, r, scout.m_scoring);
		SetAdjPrFga(rating);

		r = GetPrFgp();
		rating = PrRating(true, r, scout.m_shooting);
		SetAdjPrFgp(rating);
	
		r = GetPrFta();
		rating = PrRating(false, r, scout.m_scoring);
		SetAdjPrFta(rating);

		r = GetPrFtp();
		rating = PrRating(true, r, scout.m_shooting);
		SetAdjPrFtp(rating);

		r = GetPrTga();
		rating = PrRating(false, r, scout.m_scoring);
		SetAdjPrTga(rating);

		r = GetPrTgp();
		rating = PrRating(true, r, scout.m_shooting);
		SetAdjPrTgp(rating);
	
		r = GetPrOrb();
		rating = PrRating(false, r, scout.m_rebounding);
		SetAdjPrOrb(rating);

		r = GetPrDrb();
		rating = PrRating(false, r, scout.m_rebounding);
		SetAdjPrDrb(rating);

		r = GetPrAst();
		rating = PrRating(false, r, scout.m_passing);
		SetAdjPrAst(rating);

		r = GetPrStl();
		rating = PrRating(false, r, scout.m_defense);
		SetAdjPrStl(rating);

		r = GetPrTo();
		rating = PrRating(false, r, scout.m_passing);
		SetAdjPrTo(rating);

		r = GetPrBlk();
		rating = PrRating(false, r, scout.m_defense);
		SetAdjPrBlk(rating);

		r = GetPot1()+200;
		rating = PrRating(false, r, scout.m_pot1);
		SetAdjPot1(rating);

		r = GetPot2()+200;
		rating = PrRating(false, r, scout.m_pot2);
		SetAdjPot2(rating);

		r = GetEffort()+200;
		rating = PrRating(false, r, scout.m_effort);
		SetAdjEffort(rating);

}

void SetAdjustedOldRatings(CStaff scout, bool change)
{

	m_oldprFga = PrRating(false, m_oldprFga, scout.m_scoring);
	m_oldprFgp = PrRating(false, m_oldprFgp, scout.m_shooting);
	m_oldprFta = PrRating(false, m_oldprFta, scout.m_scoring);
	m_oldprFtp = PrRating(false, m_oldprFtp, scout.m_shooting);
	m_oldprTga = PrRating(false, m_oldprTga, scout.m_scoring);
	m_oldprTgp = PrRating(false, m_oldprTgp, scout.m_shooting);
	m_oldprOrb = PrRating(false, m_oldprOrb, scout.m_rebounding);
	m_oldprDrb = PrRating(false, m_oldprDrb, scout.m_rebounding);
	m_oldprAst = PrRating(false, m_oldprAst, scout.m_passing);
	m_oldprStl = PrRating(false, m_oldprStl, scout.m_defense);
	m_oldprTo = PrRating(false, m_oldprTo, scout.m_passing);
	m_oldprBlk = PrRating(false, m_oldprBlk, scout.m_defense);


	if(change == true)
	{
	m_oldprFga = m_adjPrFga - m_oldprFga;
	m_oldprFgp = m_adjPrFgp - m_oldprFgp;
	m_oldprFta = m_adjPrFta - m_oldprFta;
	m_oldprFtp = m_adjPrFtp - m_oldprFtp;
	m_oldprTga = m_adjPrTga - m_oldprTga;
	m_oldprTgp = m_adjPrTgp - m_oldprTgp;
	m_oldprOrb = m_adjPrOrb - m_oldprOrb;
	m_oldprDrb = m_adjPrDrb - m_oldprDrb;
	m_oldprAst = m_adjPrAst - m_oldprAst;
	m_oldprStl = m_adjPrStl - m_oldprStl;
	m_oldprTo = m_adjPrTo - m_oldprTo;
	m_oldprBlk = m_adjPrBlk - m_oldprBlk;

	m_oldmovoff = m_movoff - m_oldmovoff;
	m_oldpenoff = m_penoff - m_oldpenoff;
	m_oldpostoff = m_postoff - m_oldpostoff;
	m_oldtransoff = m_transoff - m_oldtransoff;
	m_oldmovdef = m_movdef - m_oldmovdef;
	m_oldpendef = m_pendef - m_oldpendef;
	m_oldpostdef = m_postdef - m_oldpostdef;
	m_oldtransdef = m_transdef - m_oldtransdef;
	}
		
}

//void SetRatingsChange(int* change)
//{

//}




int GetRosterNumber(){return m_number;}
CString GetName(){return m_name;}
CString GetLastName(){return m_lastName;}
int GetInjury(){return m_injury;}
int GetAge(){return m_age;}
int GetID(){return m_id;}
CString GetPos(){return m_pos;}
int GetGames(){return m_games;}
int GetMin(){return m_min;}
int GetFgm(){return m_fgm;}
int GetFga(){return m_fga;}
int GetFtm(){return m_ftm;}
int GetFta(){return m_fta;}
int GetTfgm(){return m_tfgm;}
int GetTfga(){return m_tfga;}
int GetOreb(){return m_oreb;}
int GetReb(){return m_reb;}
int GetAst(){return m_ast;}
int GetStl(){return m_stl;}
int GetTo(){return m_to;}
int GetBlk(){return m_blk;}
int GetPf(){return m_pf;}
int GetMovOff(){return m_movoff;}
int GetMovDef(){return m_movdef;}
int GetPenOff(){return m_penoff;}
int GetPenDef(){return m_pendef;}
int GetPostOff(){return m_postoff;}
int GetPostDef(){return m_postdef;}
int GetTransOff(){return m_transoff;}
int GetTransDef(){return m_transdef;}
int GetClutch(){return m_clutch;}
int GetConsistency(){return m_consistency;}
int GetPgRot(){return m_pgrot;}
int GetSgRot(){return m_sgrot;}
int GetSfRot(){return m_sfrot;}
int GetPfRot(){return m_pfrot;}
int GetCRot(){return m_crot;}
BOOL GetActive(){return m_active;}
int GetBetter()
{
	if(m_better == 0) m_better = 50;	
	return m_better;

}

int GetPrFga(){return m_prFga;}
int GetPrFgp(){return m_prFgp;}
int GetPrFta(){return m_prFta;}
int GetPrFtp(){return m_prFtp;}
int GetPrTga(){return m_prTga;}
int GetPrTgp(){return m_prTgp;}
int GetPrOrb(){return m_prOrb;}
int GetPrDrb(){return m_prDrb;}
int GetPrAst(){return m_prAst;}
int GetPrStl(){return m_prStl;}
int GetPrTo(){return m_prTo;}
int GetPrBlk(){return m_prBlk;}
int GetPot1(){return m_pot1;}
int GetPot2(){return m_pot2;}
int GetEffort(){return m_effort;}
int GetPrime(){return m_prime;}

int GetAdjPrFga(){return m_adjPrFga;}
int GetAdjPrFgp(){return m_adjPrFgp;}
int GetAdjPrFta(){return m_adjPrFta;}
int GetAdjPrFtp(){return m_adjPrFtp;}
int GetAdjPrTga(){return m_adjPrTga;}
int GetAdjPrTgp(){return m_adjPrTgp;}
int GetAdjPrOrb(){return m_adjPrOrb;}
int GetAdjPrDrb(){return m_adjPrDrb;}
int GetAdjPrAst(){return m_adjPrAst;}
int GetAdjPrStl(){return m_adjPrStl;}
int GetAdjPrTo(){return m_adjPrTo;}
int GetAdjPrBlk(){return m_adjPrBlk;}
int GetAdjPot1(){return m_adjPot1;}
int GetAdjPot2(){return m_adjPot2;}
int GetAdjEffort(){return m_adjEffort;}
int GetAdjPrime(){return m_adjPrime;}







CString GetTeam(){return m_team;}
int GetTotalGames(){return m_totalGames;}
int GetTeamGames(){return m_teamGames;}

double GetTrueRating(){return m_trueRating;}
double GetTradeTrueRating(BOOL m_checkCareer)
{
	double rating = m_tradeTrueRating;
	if(m_checkCareer == TRUE) rating = m_tradeValue;
	return rating;
}
double GetTrueRatingSimple(){return m_trueRatingSimple;}
double GetTeammatesBetterRating(){return m_teammatesBetterRating;}
double GetAstTo(){return m_astTo;}
double GetDefense(){return m_defense;}
double GetOutside(){return m_outside;}
double GetDriving(){return m_driving;}
double GetPost(){return m_post;}
double GetTransition(){return m_transition;}
double GetOutsideDefense(){return m_outsideDefense;}
double GetDrivingDefense(){return m_drivingDefense;}
double GetPostDefense(){return m_postDefense;}
double GetTransitionDefense(){return m_transitionDefense;}
double GetOutsidePer48Min(){return m_outsidePer48Min;}
double GetDrivingPer48Min(){return m_drivingPer48Min;}
double GetPostPer48Min(){return m_postPer48Min;}
double GetTransitionPer48Min(){return m_transitionPer48Min;}
double GetOutsideDefensePer48Min(){return m_outsideDefensePer48Min;}
double GetDrivingDefensePer48Min(){return m_drivingDefensePer48Min;}
double GetPostDefensePer48Min(){return m_postDefensePer48Min;}
double GetTransitionDefensePer48Min(){return m_transitionDefensePer48Min;}
double GetMvp(){return m_mvp;}
double GetTradeValue(){return m_tradeValue;}

double GetMinPerGame(){return m_minPerGame;}
double GetPointsPerGame(){return m_pointsPerGame;}
double GetReboundsPerGame(){return m_reboundsPerGame;}
double GetAssistsPerGame(){return m_assistsPerGame;}
double GetStealsPerGame(){return m_stealsPerGame;}
double GetBlocksPerGame(){return m_blocksPerGame;}
double GetOrebPerGame(){return m_orbPerGame;}
double GetToPerGame(){return m_toPerGame;}
double GetPfPerGame(){return m_pfPerGame;}
double GetFgPct(){return m_fgPct;}
double GetTfgPct(){return m_tfgPct;}
double GetFtPct(){return m_ftPct;}

double GetSimMinPerGame(){return m_sim_minPerGame;}
double GetSimPointsPerGame(){return m_sim_pointsPerGame;}
double GetSimReboundsPerGame(){return m_sim_reboundsPerGame;}
double GetSimAssistsPerGame(){return m_sim_assistsPerGame;}
double GetSimStealsPerGame(){return m_sim_stealsPerGame;}
double GetSimBlocksPerGame(){return m_sim_blocksPerGame;}
double GetSimOrebPerGame(){return m_sim_orbPerGame;}
double GetSimToPerGame(){return m_sim_toPerGame;}
double GetSimPfPerGame(){return m_sim_pfPerGame;}
double GetSimFgPct(){return m_sim_fgPct;}
double GetSimTfgPct(){return m_sim_tfgPct;}
double GetSimFtPct(){return m_sim_ftPct;}

double GetPoMinPerGame(){return m_po_minPerGame;}
double GetPoPointsPerGame(){return m_po_pointsPerGame;}
double GetPoReboundsPerGame(){return m_po_reboundsPerGame;}
double GetPoAssistsPerGame(){return m_po_assistsPerGame;}
double GetPoStealsPerGame(){return m_po_stealsPerGame;}
double GetPoBlocksPerGame(){return m_po_blocksPerGame;}
double GetPoOrebPerGame(){return m_po_orbPerGame;}
double GetPoToPerGame(){return m_po_toPerGame;}
double GetPoPfPerGame(){return m_po_pfPerGame;}
double GetPoFgPct(){return m_po_fgPct;}
double GetPoTfgPct(){return m_po_tfgPct;}
double GetPoFtPct(){return m_po_ftPct;}


void SetRequests(int franchise_w[33], int franchise_l[33], CRecord record[33], CStaff coach[33], double val[6], double pos_value[33][6])
{

	double trade_value = m_tradeTrueRating;
	double sim_value = 0;
	if(m_sim_games > 4)
	{
		sim_value = m_sim_trueRating / m_sim_games;
	}

	if(sim_value > trade_value) trade_value = sim_value;

	int age = m_age;

			if(m_yrs_on_team >= 3)
				m_bird_player = true;			
			double money = trade_value * 100;
			money = money * (.875 + (double)IntRandom(25)/100);
			if(money < m_current_yr_salary) money = m_current_yr_salary;

			bool max_raise = false;

			if(money > MAX10 && m_yrs_of_service >= 10)
			{
				money = MAX10;
				max_raise = true;
			}
			else if(money > MAX7 && m_yrs_of_service >= 7) 
			{
				money = MAX7;
				max_raise = true;
			}
			else if(money > MAX0) 
			{
				money = MAX0;
				max_raise = true;
			}

			double m_minimum[11];
			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;
			int y_s = m_yrs_of_service;
			if(y_s > 10) y_s = 10;
			if(money < m_minimum[y_s] || y_s == 0)
				money = m_minimum[y_s];

			int contract_max =  6;
			//write some code based on age to set years wanted
			if(age > 28) contract_max = 35 - age;

			if(contract_max > 6) contract_max = 6;
			else if(contract_max < 2) contract_max = 2;
			
			int current_money = (int)money;
				m_qualifying_salaries[1] = current_money;
			int total_salary = current_money;


			double d_mpy = (double)money / 100;
			int mpy = (int)d_mpy;
			int o_mpy = mpy + 1;
			mpy = mpy - 3 + m_security_factor;
			if(mpy < 1) mpy = 1;

			int contract_years = 1 + IntRandom(mpy);

			if(contract_years < 1) contract_years = 1;
			else if(contract_years > 6) contract_years = 6;

			if(contract_years > contract_max) contract_years = contract_max; 
			if(contract_years > o_mpy) contract_years = o_mpy; 

			if(contract_years != 1)//end of contract
			{
				double inc = double(current_money) * .10;
				
				for(int j=2; j<=contract_years; j++)
				{
					double money = double(current_money) + inc;
					current_money = (int)money;
					m_qualifying_salaries[j] = current_money;
					total_salary = total_salary + current_money;
				}
			
			}


			m_total_salary_seeking = total_salary;
			m_qualifying_offer_years = contract_years;
			money = total_salary / contract_years;

	

	for(int i=0; i<=32; i++)
	{

		//adjust for last seasons win pct
		double w_pct = record[i].m_leaguePct;

		if(record[i].m_loss == 0 && franchise_l[i] == 0)//expansion team
		{
			w_pct = .1;
		}


		double factor = 1;

		double win_factor =  (.5 - w_pct) * (double) m_winning_factor / 8; //tweaked from 7



		if(record[i].m_loss == 0 && franchise_l[i] != 0)
		{
			factor = 1;
		}
		else
		{
			factor = 1 + win_factor;
		}




		double var =  money * (.875 + (double)IntRandom(25)/100);//lets randomize what they want to give more chance to all
		double salary_request = var * factor;


		if(franchise_l[i] == 0 && record[i].m_loss == 0) w_pct = .1;//expansion team
		else if(franchise_l[i] == 0) w_pct = .5;
		else w_pct = (double)franchise_w[i] / ((double)franchise_w[i] + double(franchise_l[i]));

		
		win_factor =  (.5 - w_pct) * (double) m_tradition_factor / 8;//tweaked from 7
		factor = 1 + win_factor;
		salary_request = salary_request * factor;

		factor = 1;
		int loyal = m_loyalty_factor;
		if(m_yrs_on_team < 3) loyal = loyal*2;//increase loyalty for player who needs bird rights
		double loy = (double)loyal*3 / 1000; // 3/40 percent less for average loyal will be accepted
		if(m_previous_team == i) factor =  1 - loy;
		salary_request = salary_request * factor;

		
		int coach_rating1 = (coach[i].m_pot1Rating + coach[i].m_pot2Rating + coach[i].m_effortRating + coach[i].m_scoringRating + coach[i].m_shootingRating + coach[i].m_reboundingRating + coach[i].m_passingRating + coach[i].m_defenseRating)*1;
		int coach_rating2 = (coach[i].m_coachPot1 + coach[i].m_coachPot2 + coach[i].m_coachEffort + coach[i].m_coachScoring + coach[i].m_coachShooting + coach[i].m_coachRebounding + coach[i].m_coachPassing + coach[i].m_coachDefense)*3;
		int coach_rating3 = (coach[i].m_coachO + coach[i].m_coachP + coach[i].m_coachI + coach[i].m_coachF + coach[i].m_coachOD + coach[i].m_coachPD + coach[i].m_coachID + coach[i].m_coachFD)*3;
		int coach_rating4 = (coach[i].m_personality)*24;
		int r = coach_rating1 + coach_rating2 + coach_rating3 + coach_rating4;
		factor = (200 - (99 + (double)r/200)) / 100;
		salary_request = salary_request * factor;

		
		double pv_factor = 0;//playing time 
		
		if(m_pos == "PG" && val[1] > 0 && pos_value[i][1] > val[1]) 
			pv_factor = pos_value[i][1]  / val[1];
		else if(m_pos == "PG" && pos_value[i][1] > 0 && pos_value[i][1] <= val[1]) 
			pv_factor = - val[1] / pos_value[i][1];
		else if(m_pos == "SG" && val[2] > 0 && pos_value[i][2] > val[2]) 
			pv_factor = pos_value[i][2]  / val[2];
		else if(m_pos == "SG" && pos_value[i][2] > 0 && pos_value[i][2] <= val[2]) 
			pv_factor = - val[2] / pos_value[i][2];
		else if(m_pos == "SF" && val[3] > 0 && pos_value[i][3] > val[3]) 
			pv_factor = pos_value[i][3]  / val[3];
		else if(m_pos == "SF" && pos_value[i][3] > 0 && pos_value[i][3] <= val[3]) 
			pv_factor = - val[3] / pos_value[i][3];
		else if(m_pos == "PF" && val[4] > 0 && pos_value[i][4] > val[4]) 
			pv_factor = pos_value[i][4]  / val[4];
		else if(m_pos == "PF" && pos_value[i][4] > 0 && pos_value[i][4] <= val[4]) 
			pv_factor = - val[4] / pos_value[i][4];
		else if(m_pos == " C" && val[5] > 0 && pos_value[i][5] > val[5]) 
			pv_factor = pos_value[i][5]  / val[5];
		else if(m_pos == " C" && pos_value[i][5] > 0 && pos_value[i][5] <= val[5]) 
			pv_factor = - val[5] / pos_value[i][5];

		
		if(pv_factor > 4) pv_factor = 4;
		else if(pv_factor < -4) pv_factor = -4;


		pv_factor = (94 + (double)m_playing_time_factor * 2) / 100 * (1+pv_factor/10);

		if(record[i].m_leagueTeamNames == "") pv_factor = 0;

		salary_request = salary_request * pv_factor;		

		if(m_previous_team == i) salary_request = salary_request * 99 / 100;

		salary_request = salary_request * 99. / 100.;

		m_seeking[i] = (int) salary_request;
	}
	
	
}


void SetAdjustedRequests(int franchise_w[33], int franchise_l[33], CRecord record[33], CStaff coach[33], double val[6], double pos_value[33][6])
{
	
	int total_salary = m_total_salary_seeking;
	int contract_years = m_qualifying_offer_years;
	double money = (double)total_salary / (double)contract_years;


	

	for(int i=0; i<=32; i++)
	{
		//adjust for last seasons win pct
		double w_pct = record[i].m_leaguePct;

		if(record[i].m_loss == 0 && franchise_l[i] == 0)//expansion team
		{
			w_pct = .1;
		}


		double factor = 1;

		double win_factor =  (.5 - w_pct) * (double) m_winning_factor / 8;



		if(record[i].m_loss == 0 && franchise_l[i] != 0)
		{
			factor = 1;
		}
		else
		{
			factor = 1 + win_factor;
		}


		double var =  money * (.875 + (double)IntRandom(25)/100);//lets randomize what they want to give more chance to all
		double salary_request = var * factor;
		//double salary_request = money * factor;


		
		if(franchise_l[i] == 0 && record[i].m_loss == 0) w_pct = .1;//expansion team
		else if(franchise_l[i] == 0) w_pct = .5;
		else w_pct = (double)franchise_w[i] / ((double)franchise_w[i] + double(franchise_l[i]));

		win_factor =  (.5 - w_pct) * (double) m_tradition_factor / 8;
		factor = 1 + win_factor;
		salary_request = salary_request * factor;

		factor = 1;
		int loyal = m_loyalty_factor;
		if(m_yrs_on_team < 3) loyal = loyal*2;//increase loyalty for player who needs bird rights
		double loy = (double)loyal*3 / 1000; // 3/40 percent less for average loyal will be accepted
		if(m_previous_team == i) factor =  1 - loy;
		salary_request = salary_request * factor;

		
		int coach_rating1 = (coach[i].m_pot1Rating + coach[i].m_pot2Rating + coach[i].m_effortRating + coach[i].m_scoringRating + coach[i].m_shootingRating + coach[i].m_reboundingRating + coach[i].m_passingRating + coach[i].m_defenseRating)*1;
		int coach_rating2 = (coach[i].m_coachPot1 + coach[i].m_coachPot2 + coach[i].m_coachEffort + coach[i].m_coachScoring + coach[i].m_coachShooting + coach[i].m_coachRebounding + coach[i].m_coachPassing + coach[i].m_coachDefense)*3;
		int coach_rating3 = (coach[i].m_coachO + coach[i].m_coachP + coach[i].m_coachI + coach[i].m_coachF + coach[i].m_coachOD + coach[i].m_coachPD + coach[i].m_coachID + coach[i].m_coachFD)*3;
		int coach_rating4 = (coach[i].m_personality)*24;
		int r = coach_rating1 + coach_rating2 + coach_rating3 + coach_rating4;
		factor = (200 - (99 + (double)r/200)) / 100;
		salary_request = salary_request * factor;

		
		double pv_factor = 0;//playing time 
		
		if(m_pos == "PG" && val[1] > 0 && pos_value[i][1] > val[1]) 
			pv_factor = pos_value[i][1]  / val[1];
		else if(m_pos == "PG" && pos_value[i][1] > 0 && pos_value[i][1] <= val[1]) 
			pv_factor = - val[1] / pos_value[i][1];
		else if(m_pos == "SG" && val[2] > 0 && pos_value[i][2] > val[2]) 
			pv_factor = pos_value[i][2]  / val[2];
		else if(m_pos == "SG" && pos_value[i][2] > 0 && pos_value[i][2] <= val[2]) 
			pv_factor = - val[2] / pos_value[i][2];
		else if(m_pos == "SF" && val[3] > 0 && pos_value[i][3] > val[3]) 
			pv_factor = pos_value[i][3]  / val[3];
		else if(m_pos == "SF" && pos_value[i][3] > 0 && pos_value[i][3] <= val[3]) 
			pv_factor = - val[3] / pos_value[i][3];
		else if(m_pos == "PF" && val[4] > 0 && pos_value[i][4] > val[4]) 
			pv_factor = pos_value[i][4]  / val[4];
		else if(m_pos == "PF" && pos_value[i][4] > 0 && pos_value[i][4] <= val[4]) 
			pv_factor = - val[4] / pos_value[i][4];
		else if(m_pos == " C" && val[5] > 0 && pos_value[i][5] > val[5]) 
			pv_factor = pos_value[i][5]  / val[5];
		else if(m_pos == " C" && pos_value[i][5] > 0 && pos_value[i][5] <= val[5]) 
			pv_factor = - val[5] / pos_value[i][5];

		
		if(pv_factor > 4) pv_factor = 4;
		else if(pv_factor < -4) pv_factor = -4;

//		pv_factor = (100 + pv_factor * m_playing_time_factor) / 100;
		pv_factor = (94 + (double)m_playing_time_factor * 2) / 100 * (1+pv_factor/10);

		if(record[i].m_leagueTeamNames == "") pv_factor = 0;

		salary_request = salary_request * pv_factor;		

		if(m_previous_team == i) salary_request = salary_request * 99 / 100;

		salary_request = salary_request * 99. / 100.;

		m_seeking[i] = (int) salary_request;
	}
	
	
}



double Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}

int ChooseBestContract( int m_counter[33], int m_count)
{
	int best = -1;
	double requested_salary_avg = 0;
	if(m_qualifying_offer_years > 0) requested_salary_avg =  (double) m_total_salary_seeking / (double) m_qualifying_offer_years;
	double hi_diff = 0;
	for(int t=0; t<=32; t++)
	{

		if(m_counter[t] >= m_count || m_seeking[t] == 0) continue;

		int bottom = m_year_offer[t];

		if(bottom == 0) continue;//no years offered
		double offered_salary_avg = (double) m_total_salary_offer[t] / (double) bottom;

		double max_years = 0;
		double tr = 1;

		double value = requested_salary_avg * (.7 + (6 - (double)m_security_factor)/10);
		tr = offered_salary_avg / value;

		max_years = 6*tr;
		int i_max_years = (int)max_years;
		double rem = max_years - (double)i_max_years;
		if(rem >= .5)  i_max_years = i_max_years + 1;
		if(i_max_years < 1) i_max_years = 1;
		if(bottom > i_max_years && m_qualifying_offer_years != bottom ) continue;

		double sec_factor = (100 + ((double)m_security_factor * (double) bottom) / 2) / 100;//security importance,//tweaked from 3 to 2
		double diff = offered_salary_avg * sec_factor / requested_salary_avg / (double) m_seeking[t]; 
		bool ok = true;

		if(diff > hi_diff && (m_rookie == false || m_rookie == true && m_round_selected == 0) && ok == true)
		{
			hi_diff = diff;
			best = t;
		}		
	}

	if(m_round_selected > 0 && m_rookie == true)
		best = m_current_team;
	m_best_contract = best;

	return best;
}

void UpdateContracts(int best_contract)
{
	if(m_is_free_agent == false)
	{
		m_current_contract_yr = m_current_contract_yr + 1;
	}
	else if(m_is_free_agent == true)//player an unsigned free agent
	{
		for(int y=1; y<=6; y++)
		{
			m_contract_salaries[y] = 0;
		}		

		m_contract_yrs = 0;
		m_current_contract_yr = 0;
	}
	
	//m_yrs_on_team = m_yrs_on_team + 1;	
	m_previous_team = m_current_team;
	//m_yrs_of_service = m_yrs_of_service + 1;

}

void SetRookieContract(CPlayer player, int team, int number_teams)
{
	int rookie_salary_chart[3][33][7];
	m_rookie = true;
	int val = 32;
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=32; j++)
		{
			for(int k=0; k<=6; k++)
			{
				if(k == 1 && i==2) rookie_salary_chart[i][j][k] = MIN0;
				else if(k == 2 && i==2) rookie_salary_chart[i][j][k] = MIN1;
			}
		}
	}

	m_just_signed = true;

	rookie_salary_chart[1][1][1] = 321;
	rookie_salary_chart[1][1][2] = 345;
	rookie_salary_chart[1][1][3] = 369;

	rookie_salary_chart[1][2][1] = 287;
	rookie_salary_chart[1][2][2] = 309;
	rookie_salary_chart[1][2][3] = 330;

	rookie_salary_chart[1][3][1] = 258;
	rookie_salary_chart[1][3][2] = 277;
	rookie_salary_chart[1][3][3] = 297;

	rookie_salary_chart[1][4][1] = 232;
	rookie_salary_chart[1][4][2] = 250;
	rookie_salary_chart[1][4][3] = 267;

	rookie_salary_chart[1][5][1] = 210;
	rookie_salary_chart[1][5][2] = 226;
	rookie_salary_chart[1][5][3] = 242;

	rookie_salary_chart[1][6][1] = 191;
	rookie_salary_chart[1][6][2] = 205;
	rookie_salary_chart[1][6][3] = 220;

	rookie_salary_chart[1][7][1] = 174;
	rookie_salary_chart[1][7][2] = 187;
	rookie_salary_chart[1][7][3] = 201;

	rookie_salary_chart[1][8][1] = 160;
	rookie_salary_chart[1][8][2] = 172;
	rookie_salary_chart[1][8][3] = 184;

	rookie_salary_chart[1][9][1] = 147;
	rookie_salary_chart[1][9][2] = 158;
	rookie_salary_chart[1][9][3] = 169;

	rookie_salary_chart[1][10][1] = 139;
	rookie_salary_chart[1][10][2] = 150;
	rookie_salary_chart[1][10][3] = 160;

	rookie_salary_chart[1][11][1] = 132;
	rookie_salary_chart[1][11][2] = 142;
	rookie_salary_chart[1][11][3] = 152;

	rookie_salary_chart[1][12][1] = 126;
	rookie_salary_chart[1][12][2] = 135;
	rookie_salary_chart[1][12][3] = 145;

	rookie_salary_chart[1][13][1] = 119;
	rookie_salary_chart[1][13][2] = 128;
	rookie_salary_chart[1][13][3] = 137;

	rookie_salary_chart[1][14][1] = 113;
	rookie_salary_chart[1][14][2] = 125;
	rookie_salary_chart[1][14][3] = 131;


	rookie_salary_chart[1][15][1] = 108;
	rookie_salary_chart[1][15][2] = 116;
	rookie_salary_chart[1][15][3] = 124;

	rookie_salary_chart[1][16][1] = 102;
	rookie_salary_chart[1][16][2] = 110;
	rookie_salary_chart[1][16][3] = 118;

	rookie_salary_chart[1][17][1] = 97;
	rookie_salary_chart[1][17][2] = 105;
	rookie_salary_chart[1][17][3] = 112;

	rookie_salary_chart[1][18][1] = 92;
	rookie_salary_chart[1][18][2] = 99;
	rookie_salary_chart[1][18][3] = 106;

	rookie_salary_chart[1][19][1] = 88;
	rookie_salary_chart[1][19][2] = 95;
	rookie_salary_chart[1][19][3] = 101;

	rookie_salary_chart[1][20][1] = 85;
	rookie_salary_chart[1][20][2] = 91;
	rookie_salary_chart[1][20][3] = 97;

	rookie_salary_chart[1][21][1] = 81;
	rookie_salary_chart[1][21][2] = 87;
	rookie_salary_chart[1][21][3] = 93;

	rookie_salary_chart[1][22][1] = 78;
	rookie_salary_chart[1][22][2] = 84;
	rookie_salary_chart[1][22][3] = 90;

	rookie_salary_chart[1][23][1] = 75;
	rookie_salary_chart[1][23][2] = 80;
	rookie_salary_chart[1][23][3] = 86;

	rookie_salary_chart[1][24][1] = 72;
	rookie_salary_chart[1][24][2] = 77;
	rookie_salary_chart[1][24][3] = 83;

	rookie_salary_chart[1][25][1] = 69;
	rookie_salary_chart[1][25][2] = 74;
	rookie_salary_chart[1][25][3] = 79;

	rookie_salary_chart[1][26][1] = 67;
	rookie_salary_chart[1][26][2] = 72;
	rookie_salary_chart[1][26][3] = 77;

	rookie_salary_chart[1][27][1] = 65;
	rookie_salary_chart[1][27][2] = 70;
	rookie_salary_chart[1][27][3] = 75;

	rookie_salary_chart[1][28][1] = 65;
	rookie_salary_chart[1][28][2] = 70;
	rookie_salary_chart[1][28][3] = 74;

	rookie_salary_chart[1][29][1] = 64;
	rookie_salary_chart[1][29][2] = 69;
	rookie_salary_chart[1][29][3] = 74;

	rookie_salary_chart[1][30][1] = 63;
	rookie_salary_chart[1][30][2] = 68;
	rookie_salary_chart[1][30][3] = 73;

	rookie_salary_chart[1][31][1] = 62;
	rookie_salary_chart[1][31][2] = 67;
	rookie_salary_chart[1][31][3] = 72;

	rookie_salary_chart[1][32][1] = 61;
	rookie_salary_chart[1][32][2] = 66;
	rookie_salary_chart[1][32][3] = 71;


	m_signed = true;//if listed then player permanently signed	
	int total = 0;
	int yr = 3;
	if(player.m_round_selected == 2) yr = 2;

	for(int i=1; i<=yr; i++)
	{
		double sl = (double)player.m_pick_selected / (double)number_teams * 29;
		int slot = (int) sl;
		if(slot == 0) slot = 1;
		if(player.m_round_selected == 2 ) slot = player.m_pick_selected;
		int salary = rookie_salary_chart[player.m_round_selected][slot][i];
		m_new_contract_salaries[i] = salary;
		total = total + salary;
	}

	


	m_best_contract = team;
	m_current_team = team;
	m_previous_team = team;
	m_year_offer[m_best_contract] = yr;
	m_total_salary_offer[m_best_contract] = total;
	m_top_offer[team] = true;
	m_is_free_agent = false;
	m_yrs_on_team = 0;
	m_yrs_of_service = 0;

		m_total_salary = total;
		m_contract_yrs = yr;
		m_current_contract_yr = 0;
		for(int y=1; y<=m_contract_yrs; y++)
		{
			m_contract_salaries[y] = m_new_contract_salaries[y];
		}


}

bool AcceptOffer(int stage, int cap[], int teams, int m_cap, int fav[], double avg_tru)
{


	RankFavorites(fav, teams);

	int best_offer = m_best_contract;
	bool accept = false;


	int offer1 = m_new_contract_salaries[1];
	int possible = 0;
	double accept_factor = m_accept_factor * 2;
	if(accept_factor > 1) accept_factor = 1;
	for(int i=0; i<=31; i++)
	{
		cap[i] = cap[i] - m_salary_offer[i][1];
		int room = m_cap - cap[i];
		double f = (1. - accept_factor);
		if(f < 0) f = 0;
		double want = m_seeking[i] * f;
		if((((double)room - want) > 0 || i==m_previous_team) && offer1 < want)
			possible = possible + 1;//teams with money to offer still
	}

	//if(possible > 4) possible = 4;

	double f = ((double)possible/(double)teams * 10 +  (10-accept_factor*10)) * GetTradeValue() / avg_tru;

	double min_f = m_accept_factor * 1.1;
//	double min_f = m_accept_factor * 1;
	if(min_f < 0) min_f = 0;

	int yr = 7 - stage;
	if(yr < 1) yr = 1;
	int total_offered_best = 0;
	int i=0;
	for(int i=1; i<=yr; i++)
	{
		total_offered_best = total_offered_best + m_salary_offer[m_best_contract][i];
	}


//	double min_money_to_accept = (double)m_seeking[m_best_contract] * (1-min_f) * 1.05;
	double min_money_to_accept = (double)m_seeking[m_best_contract] * (1-min_f) * 1.05 * yr;

	double r = Random(20);

//	if(m_top_offer[best_offer] == true && m_signed == false && m_name != "" && r > f && (double)m_salary_offer[m_best_contract][1] >= min_money_to_accept)
//		accept = true;
	if(m_top_offer[best_offer] == true && m_signed == false && m_name != "" && r > f && (double)total_offered_best >= min_money_to_accept)
		accept = true;


//	min_f = m_accept_factor * 2.;
	min_f = m_accept_factor * 1.125;
	if(min_f < 0) min_f = 0;
//	min_money_to_accept = (double)m_seeking[m_best_contract] * (1-min_f) * 1.05;
	min_money_to_accept = (double)m_seeking[m_best_contract] * (1-min_f) * 1.05 * yr;
	

	if(stage >= teams) stage = teams;


	for(int i=1; i<=stage; i++)
	{
//		if(fav[i] == (m_best_contract+1) && (double)m_salary_offer[m_best_contract][1] >= min_money_to_accept)
//			accept = true;
		if(fav[i] == (m_best_contract+1) &&  (double)total_offered_best >= min_money_to_accept)
			accept = true;
	}


	//if(m_rookie == true) accept = false;


	return accept;
}

void GenerateRandomOffCourtData()
{

		GenerateRandomPrime();
		m_pot2 = IntRandom(5);
		m_pot1 = IntRandom(5);
		m_effort = IntRandom(5);
		m_coach_factor = IntRandom(5);
		m_security_factor = IntRandom(5);
		m_loyalty_factor = IntRandom(5);
		m_winning_factor = IntRandom(5);
		m_playing_time_factor = IntRandom(5);
		m_tradition_factor = IntRandom(5);
}

void SetJustSignedContracts()
{

	int m_minimum[11];
			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;



	if(m_remaining_salary == 0)
	{
		m_yrs_on_team = 0;
		m_current_contract_yr = 1;
		m_contract_yrs = 1;
		int yr = m_yrs_of_service;
		if(yr > 10) yr = 10;
		m_contract_salaries[0] = 0;
		m_contract_salaries[1] = m_minimum[yr];
		m_contract_salaries[2] = 0;
		m_contract_salaries[3] = 0;
		m_contract_salaries[4] = 0;
		m_contract_salaries[5] = 0;
		m_contract_salaries[6] = 0;
		m_current_yr_salary = m_contract_salaries[1];
		m_remaining_salary = m_contract_salaries[1];
	}
}








	//copy constructor
	CPlayer( const CPlayer& a ) 
	{ 

		m_oldmovoff = a.m_oldmovoff;
		m_oldmovdef = a.m_oldmovdef;
		m_oldpenoff = a.m_oldpenoff;
		m_oldpendef = a.m_oldpendef;
		m_oldpostoff = a.m_oldpostoff;
		m_oldpostdef = a.m_oldpostdef;
		m_oldtransoff = a.m_oldtransoff;
		m_oldtransdef = a.m_oldtransdef;
		m_oldprFga = a.m_oldprFga;
		m_oldprFgp = a.m_oldprFgp;
		m_oldprFta = a.m_oldprFta;
		m_oldprFtp = a.m_oldprFtp;
		m_oldprTga = a.m_oldprTga;
		m_oldprTgp = a.m_oldprTgp;
		m_oldprOrb = a.m_oldprOrb;
		m_oldprDrb = a.m_oldprDrb;
		m_oldprAst = a.m_oldprAst;
		m_oldprStl = a.m_oldprStl;
		m_oldprTo = a.m_oldprTo;
		m_oldprBlk = a.m_oldprBlk;

		m_height = a.m_height;
		m_weight = a.m_weight;

		m_just_signed = a.m_just_signed;
		m_end_season_fa = a.m_end_season_fa;

		m_gamepgrot = a.m_gamepgrot;
		m_gamesgrot = a.m_gamesgrot;
		m_gamesfrot = a.m_gamesfrot;
		m_gamepfrot = a.m_gamepfrot;
		m_gamecrot = a.m_gamecrot;



		m_stop_negotiating = a.m_stop_negotiating;
		m_health = a.m_health;
		m_content = a.m_content;
		m_on_block = a.m_on_block;
		m_injury_desc = a.m_injury_desc;

		m_retired = a.m_retired;

		m_temp_pointer = a.m_temp_pointer;
		m_all_star = a.m_all_star;
		m_rookie_star = a.m_rookie_star;
		m_3contest = a.m_3contest;
		m_dunkcontest = a.m_dunkcontest;
	
		m_all_star_index = a.m_all_star_index;
		m_rookie_star_index = a.m_rookie_star_index;
		m_3contest_index = a.m_3contest_index;
		m_dunkcontest_index = a.m_dunkcontest_index;
	



		m_starter = a.m_starter;
		m_number = a.m_number;
		m_name = a.m_name;
		m_lastName = a.m_lastName;
		m_injury = a.m_injury;
		m_age = a.m_age;
		m_id = a.m_id;
		m_pos = a.m_pos;
		m_games = a.m_games;
		m_min = a.m_min;
		m_fgm = a.m_fgm;
		m_fga = a.m_fga;
		m_ftm = a.m_ftm;
		m_fta = a.m_fta;
		m_tfgm = a.m_tfgm;
		m_tfga = a.m_tfga;
		m_oreb = a.m_oreb;
		m_reb = a.m_reb;
		m_ast = a.m_ast;
		m_stl = a.m_stl;
		m_to = a.m_to;
		m_blk = a.m_blk;
		m_pf = a.m_pf;

		m_sim_games = a.m_sim_games;
		m_sim_min = a.m_sim_min;
		m_sim_fgm = a.m_sim_fgm;
		m_sim_fga = a.m_sim_fga;
		m_sim_ftm = a.m_sim_ftm;
		m_sim_fta = a.m_sim_fta;
		m_sim_tfgm = a.m_sim_tfgm;
		m_sim_tfga = a.m_sim_tfga;
		m_sim_oreb = a.m_sim_oreb;
		m_sim_reb = a.m_sim_reb;
		m_sim_ast = a.m_sim_ast;
		m_sim_stl = a.m_sim_stl;
		m_sim_to = a.m_sim_to;
		m_sim_blk = a.m_sim_blk;
		m_sim_pf = a.m_sim_pf;

		m_car_games = a.m_car_games;
		m_car_min = a.m_car_min;
		m_car_fgm = a.m_car_fgm;
		m_car_fga = a.m_car_fga;
		m_car_ftm = a.m_car_ftm;
		m_car_fta = a.m_car_fta;
		m_car_tfgm = a.m_car_tfgm;
		m_car_tfga = a.m_car_tfga;
		m_car_oreb = a.m_car_oreb;
		m_car_reb = a.m_car_reb;
		m_car_ast = a.m_car_ast;
		m_car_stl = a.m_car_stl;
		m_car_to = a.m_car_to;
		m_car_blk = a.m_car_blk;
		m_car_pf = a.m_car_pf;

		m_po_games = a.m_po_games;
		m_po_min = a.m_po_min;
		m_po_fgm = a.m_po_fgm;
		m_po_fga = a.m_po_fga;
		m_po_ftm = a.m_po_ftm;
		m_po_fta = a.m_po_fta;
		m_po_tfgm = a.m_po_tfgm;
		m_po_tfga = a.m_po_tfga;
		m_po_oreb = a.m_po_oreb;
		m_po_reb = a.m_po_reb;
		m_po_ast = a.m_po_ast;
		m_po_stl = a.m_po_stl;
		m_po_to = a.m_po_to;
		m_po_blk = a.m_po_blk;
		m_po_pf = a.m_po_pf;
		m_movoff = a.m_movoff;
		m_movdef = a.m_movdef;
		m_penoff = a.m_penoff;
		m_pendef = a.m_pendef;
		m_postoff = a.m_postoff;
		m_postdef = a.m_postdef;
		m_transoff = a.m_transoff;
		m_transdef = a.m_transdef;
		m_clutch = a.m_clutch;
		m_consistency = a.m_consistency;
		m_pgrot = a.m_pgrot;
		m_sgrot = a.m_sgrot;
		m_sfrot = a.m_sfrot;
		m_pfrot = a.m_pfrot;
		m_crot = a.m_crot;
		m_active = a.m_active;		
		m_better = a.m_better;		
	    m_team = a.m_team;
		m_totalGames = a.m_totalGames;
		m_teamGames = a.m_teamGames;

		m_minPerGame = a.m_minPerGame;
		m_pointsPerGame = a.m_pointsPerGame;
		m_reboundsPerGame = a.m_reboundsPerGame;
		m_assistsPerGame = a.m_assistsPerGame;
		m_stealsPerGame = a.m_stealsPerGame;
		m_blocksPerGame = a.m_blocksPerGame;
		m_orbPerGame = a.m_orbPerGame;
		m_toPerGame = a.m_toPerGame;
		m_pfPerGame = a.m_pfPerGame;
		m_fgPct = a.m_fgPct;
		m_tfgPct = a.m_tfgPct;
		m_ftPct = a.m_ftPct;

		m_sim_minPerGame = a.m_sim_minPerGame;
		m_sim_pointsPerGame = a.m_sim_pointsPerGame;
		m_sim_reboundsPerGame = a.m_sim_reboundsPerGame;
		m_sim_assistsPerGame = a.m_sim_assistsPerGame;
		m_sim_stealsPerGame = a.m_sim_stealsPerGame;
		m_sim_blocksPerGame = a.m_sim_blocksPerGame;
		m_sim_orbPerGame = a.m_sim_orbPerGame;
		m_sim_toPerGame = a.m_sim_toPerGame;
		m_sim_pfPerGame = a.m_sim_pfPerGame;
		m_sim_fgPct = a.m_sim_fgPct;
		m_sim_tfgPct = a.m_sim_tfgPct;
		m_sim_ftPct = a.m_sim_ftPct;

		m_po_minPerGame = a.m_po_minPerGame;
		m_po_pointsPerGame = a.m_po_pointsPerGame;
		m_po_reboundsPerGame = a.m_po_reboundsPerGame;
		m_po_assistsPerGame = a.m_po_assistsPerGame;
		m_po_stealsPerGame = a.m_po_stealsPerGame;
		m_po_blocksPerGame = a.m_po_blocksPerGame;
		m_po_orbPerGame = a.m_po_orbPerGame;
		m_po_toPerGame = a.m_po_toPerGame;
		m_po_pfPerGame = a.m_po_pfPerGame;
		m_po_fgPct = a.m_po_fgPct;
		m_po_tfgPct = a.m_po_tfgPct;
		m_po_ftPct = a.m_po_ftPct;

		m_trueRatingSimple = a.m_trueRatingSimple;
		m_tradeTrueRating = a.m_tradeTrueRating;
		m_tradeValue = a.m_tradeValue;

		m_trueRating = a.m_trueRating;
		m_teammatesBetterRating = a.m_teammatesBetterRating;
		m_astTo = a.m_astTo;
		m_defense = a.m_defense;
		m_outside = a.m_outside;
		m_driving = a.m_driving;
		m_post = a.m_post;
		m_transition = a.m_transition;
		m_outsideDefense = a.m_outsideDefense;
		m_drivingDefense = a.m_drivingDefense;
		m_postDefense = a.m_postDefense;
		m_transitionDefense = a.m_transitionDefense;
		m_outsidePer48Min = a.m_outsidePer48Min;
		m_drivingPer48Min = a.m_drivingPer48Min;
		m_postPer48Min = a.m_postPer48Min;
		m_transitionPer48Min = a.m_transitionPer48Min;
		m_outsideDefensePer48Min = a.m_outsideDefensePer48Min;
		m_drivingDefensePer48Min = a.m_drivingDefensePer48Min;
		m_postDefensePer48Min = a.m_postDefensePer48Min;
		m_transitionDefensePer48Min = a.m_transitionDefensePer48Min;
		m_mvp = a.m_mvp;

		m_sim_trueRating = a.m_sim_trueRating;
		m_sim_teammatesBetterRating = a.m_sim_teammatesBetterRating;
		m_sim_astTo = a.m_sim_astTo;
		m_sim_defense = a.m_sim_defense;
		m_sim_outside = a.m_sim_outside;
		m_sim_driving = a.m_sim_driving;
		m_sim_post = a.m_sim_post;
		m_sim_transition = a.m_sim_transition;
		m_sim_outsideDefense = a.m_sim_outsideDefense;
		m_sim_drivingDefense = a.m_sim_drivingDefense;
		m_sim_postDefense = a.m_sim_postDefense;
		m_sim_transitionDefense = a.m_sim_transitionDefense;
		m_sim_outsidePer48Min = a.m_sim_outsidePer48Min;
		m_sim_drivingPer48Min = a.m_sim_drivingPer48Min;
		m_sim_postPer48Min = a.m_sim_postPer48Min;
		m_sim_transitionPer48Min = a.m_sim_transitionPer48Min;
		m_sim_outsideDefensePer48Min = a.m_sim_outsideDefensePer48Min;
		m_sim_drivingDefensePer48Min = a.m_sim_drivingDefensePer48Min;
		m_sim_postDefensePer48Min = a.m_sim_postDefensePer48Min;
		m_sim_transitionDefensePer48Min = a.m_sim_transitionDefensePer48Min;
		m_sim_mvp = a.m_sim_mvp;

		m_po_trueRating = a.m_po_trueRating;
		m_po_teammatesBetterRating = a.m_po_teammatesBetterRating;
		m_po_astTo = a.m_po_astTo;
		m_po_defense = a.m_po_defense;
		m_po_outside = a.m_po_outside;
		m_po_driving = a.m_po_driving;
		m_po_post = a.m_po_post;
		m_po_transition = a.m_po_transition;
		m_po_outsideDefense = a.m_po_outsideDefense;
		m_po_drivingDefense = a.m_po_drivingDefense;
		m_po_postDefense = a.m_po_postDefense;
		m_po_transitionDefense = a.m_po_transitionDefense;
		m_po_outsidePer48Min = a.m_po_outsidePer48Min;
		m_po_drivingPer48Min = a.m_po_drivingPer48Min;
		m_po_postPer48Min = a.m_po_postPer48Min;
		m_po_transitionPer48Min = a.m_po_transitionPer48Min;
		m_po_outsideDefensePer48Min = a.m_po_outsideDefensePer48Min;
		m_po_drivingDefensePer48Min = a.m_po_drivingDefensePer48Min;
		m_po_postDefensePer48Min = a.m_po_postDefensePer48Min;
		m_po_transitionDefensePer48Min = a.m_po_transitionDefensePer48Min;
		m_po_mvp = a.m_po_mvp;

		m_prFga = a.m_prFga;
		m_prFgp = a.m_prFgp;
		m_prTga = a.m_prTga;
		m_prTgp = a.m_prTgp;
		m_prFta = a.m_prFta;
		m_prFtp = a.m_prFtp;
		m_prOrb = a.m_prOrb;
		m_prDrb = a.m_prDrb;
		m_prAst = a.m_prAst;
		m_prStl = a.m_prStl;
		m_prTo = a.m_prTo;
		m_prBlk = a.m_prBlk;
		m_pot1 = a.m_pot1;
		m_pot2 = a.m_pot2;
		m_effort = a.m_effort;
		m_prime = a.m_prime;

		m_adjPrFga = a.m_adjPrFga;
		m_adjPrFgp = a.m_adjPrFgp;
		m_adjPrTga = a.m_adjPrTga;
		m_adjPrTgp = a.m_adjPrTgp;
		m_adjPrFta = a.m_adjPrFta;
		m_adjPrFtp = a.m_adjPrFtp;
		m_adjPrOrb = a.m_adjPrOrb;
		m_adjPrDrb = a.m_adjPrDrb;
		m_adjPrAst = a.m_adjPrAst;
		m_adjPrStl = a.m_adjPrStl;
		m_adjPrTo = a.m_adjPrTo;
		m_adjPrBlk = a.m_adjPrBlk;
		m_adjPot1 = a.m_adjPot1;
		m_adjPot2 = a.m_adjPot2;
		m_adjEffort = a.m_adjEffort;
		m_adjPrime = a.m_adjPrime;		
		m_contract_pointer = a.m_contract_pointer;
		m_round_selected = a.m_round_selected;
		m_pick_selected = a.m_pick_selected;
		m_team_index = a.m_team_index;
		m_original_number = a.m_original_number;
		m_original_po_number = a.m_original_po_number;

		for(int i=0; i<= 6; i++)
		{
			m_contract_salaries[i] = a.m_contract_salaries[i];
		}
	    m_coach_factor = a.m_coach_factor;
	    m_security_factor = a.m_security_factor;
	    m_loyalty_factor = a.m_loyalty_factor;
	    m_winning_factor = a.m_winning_factor;
	    m_playing_time_factor = a.m_playing_time_factor;
	    m_tradition_factor = a.m_tradition_factor;
		m_is_free_agent = a.m_is_free_agent;
		m_yrs_on_team = a.m_yrs_on_team;

		m_original_slot = a.m_original_slot;
		m_current_yr_salary = a.m_current_yr_salary;

	m_accept_factor = a.m_accept_factor;
		m_rookie = a.m_rookie;
		m_bird_player = a.m_bird_player;
		m_name = a.m_name;
		m_pos = a.m_pos;
		m_salary_id = a.m_salary_id;
	    m_current_team = a.m_current_team;
	    m_previous_team = a.m_previous_team;
		m_yrs_on_team = a.m_yrs_on_team;
		m_yrs_of_service = a.m_yrs_of_service;
		m_contract_yrs = a.m_contract_yrs;
		m_total_salary = a.m_total_salary;
		m_remaining_salary = a.m_remaining_salary;
		m_total_salary_seeking = a.m_total_salary_seeking;
		m_current_contract_yr = a.m_current_contract_yr;
		m_qualifying_offer_years = a.m_qualifying_offer_years;

		
			for(int j=0; j<=3; j++)
			{
				m_3ptscore[j] = a.m_3ptscore[j];
				m_dunkscore[j] = a.m_dunkscore[j];
			}
		

		for(int i=0; i<= 6; i++)
		{
			m_qualifying_salaries[i] = a.m_qualifying_salaries[i];
			m_new_contract_salaries[i] = a.m_new_contract_salaries[i];
		}

		for(int i=0; i<= 32; i++)
		{
			m_seeking[i] = a.m_seeking[i];
		}
		m_is_free_agent = a.m_is_free_agent;
	    
		for(int i=0; i<= 32; i++)
		{
			m_top_offer[i] = a.m_top_offer[i];
			m_year_offer[i] = a.m_year_offer[i];
			m_total_salary_offer[i] = a.m_total_salary_offer[i];
			m_offer_slot[i] = a.m_offer_slot[i];
			for(int  j=0; j<= 6; j++)
			{
				m_salary_offer[i][j] = a.m_salary_offer[i][j];
			}
		}
		m_best_contract = a.m_best_contract;
		m_signed = a.m_signed;
		m_player_pointer = a.m_player_pointer;
		

			m_random_yrs_service = a.m_random_yrs_service;	
			m_random_contracts = a.m_random_contracts;	
			m_random_contract_ratings = a.m_random_contract_ratings;	
			m_random_projections = a.m_random_projections;	
  

	for(int i=0; i<= 6; i++)
		{
			m_contract_salaries[i] = a.m_contract_salaries[i];
		}


		m_team_paying = a.m_team_paying;
		m_team_paying_name = a.m_team_paying_name;


		m_hi_pts = a.m_hi_pts;
		m_hi_reb = a.m_hi_reb;
		m_hi_ast = a.m_hi_ast;
		m_hi_stl = a.m_hi_stl;
		m_hi_blk = a.m_hi_blk;
		m_double = a.m_double;
		m_triple = a.m_triple;

		m_hi_pts_po = a.m_hi_pts_po;
		m_hi_reb_po = a.m_hi_reb_po;
		m_hi_ast_po = a.m_hi_ast_po;
		m_hi_stl_po = a.m_hi_stl_po;
		m_hi_blk_po = a.m_hi_blk_po;

		m_hi_pts_car = a.m_hi_pts_car;
		m_hi_reb_car = a.m_hi_reb_car;
		m_hi_ast_car = a.m_hi_ast_car;
		m_hi_stl_car = a.m_hi_stl_car;
		m_hi_blk_car = a.m_hi_blk_car;
		m_double_car = a.m_double_car;
		m_triple_car = a.m_triple_car;

		m_hi_pts_car_po = a.m_hi_pts_car_po;
		m_hi_reb_car_po = a.m_hi_reb_car_po;
		m_hi_ast_car_po = a.m_hi_ast_car_po;
		m_hi_stl_car_po = a.m_hi_stl_car_po;
		m_hi_blk_car_po = a.m_hi_blk_car_po;


		m_game_minutes = a.m_game_minutes;
		m_offensive_focus = a.m_offensive_focus;
		m_defensive_focus = a.m_defensive_focus;
		m_offensive_intensity = a.m_offensive_intensity;
		m_defensive_intensity = a.m_defensive_intensity;
		m_play_maker = a.m_play_maker;


	m_MinPerGame = a.m_MinPerGame;
	    m_FgPct = a.m_FgPct;
	    m_adjustedFgPct = a.m_adjustedFgPct;
	    m_FtPct = a.m_FtPct;
		m_FoulsDrawnPer48Min = a.m_FoulsDrawnPer48Min;
		m_AdjustedFoulsDrawnPer48Min = a.m_AdjustedFoulsDrawnPer48Min;
	    m_TfgPct = a.m_TfgPct;
	    m_FgaPer48Min = a.m_FgaPer48Min;
	    m_AdjustedFgaPer48Min = a.m_AdjustedFgaPer48Min;
	    m_coachFgaPer48Min = a.m_coachFgaPer48Min;
	    m_coachTfgaPer48Min = a.m_coachTfgaPer48Min;
	    m_TfgaPer48Min = a.m_TfgaPer48Min;
	    m_AdjustedTfgaPer48Min = a.m_AdjustedTfgaPer48Min;
	    m_OrebPer48Min = a.m_OrebPer48Min;
		m_DrebPer48Min = a.m_DrebPer48Min;
		m_AstPer48Min = a.m_AstPer48Min;
		m_StlPer48Min = a.m_StlPer48Min;
		m_ToPer48Min = a.m_ToPer48Min;
		m_AdjustedToPer48Min = a.m_AdjustedToPer48Min;
		m_BlkPer48Min = a.m_BlkPer48Min;
		m_PfPer48Min = a.m_PfPer48Min;
  		m_injuryRating = a.m_injuryRating;
		m_stamina = a.m_stamina;	

		m_OriginalAdjustedFoulsDrawnPer48Min = a.m_OriginalAdjustedFoulsDrawnPer48Min;
		m_OriginalAdjustedFgaPer48Min = a.m_OriginalAdjustedFgaPer48Min;
		m_OriginalAdjustedTfgaPer48Min = a.m_OriginalAdjustedTfgaPer48Min;
		m_OriginalStlPer48Min = a.m_OriginalStlPer48Min;
		m_OriginalBlkPer48Min = a.m_OriginalBlkPer48Min;


		m_game_name = a.m_game_name;
		m_game_injury = a.m_game_injury;
		m_game_Min = a.m_game_Min;
		m_game_Fgm = a.m_game_Fgm;
		m_game_Fga = a.m_game_Fga;
		m_game_Tfgm = a.m_game_Tfgm;
		m_game_Tfga = a.m_game_Tfga;
		m_game_Ftm = a.m_game_Ftm;
		m_game_Fta = a.m_game_Fta;
		m_game_Oreb = a.m_game_Oreb;
		m_game_Dreb = a.m_game_Dreb;
		m_game_Ast = a.m_game_Ast;
		m_game_Stl = a.m_game_Stl;
		m_game_To = a.m_game_To;
		m_game_Blk = a.m_game_Blk;
		m_game_Pf = a.m_game_Pf;
		m_game_stamina = a.m_game_stamina;
		m_game_stat_slot = a.m_game_stat_slot;
		m_game_player_pointer = a.m_game_player_pointer;

	} 

	const CPlayer& operator=( const CPlayer& a )
    {
		m_oldmovoff = a.m_oldmovoff;
		m_oldmovdef = a.m_oldmovdef;
		m_oldpenoff = a.m_oldpenoff;
		m_oldpendef = a.m_oldpendef;
		m_oldpostoff = a.m_oldpostoff;
		m_oldpostdef = a.m_oldpostdef;
		m_oldtransoff = a.m_oldtransoff;
		m_oldtransdef = a.m_oldtransdef;
		m_oldprFga = a.m_oldprFga;
		m_oldprFgp = a.m_oldprFgp;
		m_oldprFta = a.m_oldprFta;
		m_oldprFtp = a.m_oldprFtp;
		m_oldprTga = a.m_oldprTga;
		m_oldprTgp = a.m_oldprTgp;
		m_oldprOrb = a.m_oldprOrb;
		m_oldprDrb = a.m_oldprDrb;
		m_oldprAst = a.m_oldprAst;
		m_oldprStl = a.m_oldprStl;
		m_oldprTo = a.m_oldprTo;
		m_oldprBlk = a.m_oldprBlk;

		m_height = a.m_height;
		m_weight = a.m_weight;

		m_just_signed = a.m_just_signed;
		m_end_season_fa = a.m_end_season_fa;

		m_gamepgrot = a.m_gamepgrot;
		m_gamesgrot = a.m_gamesgrot;
		m_gamesfrot = a.m_gamesfrot;
		m_gamepfrot = a.m_gamepfrot;
		m_gamecrot = a.m_gamecrot;

		m_stop_negotiating = a.m_stop_negotiating;
		m_health = a.m_health;
		m_on_block = a.m_on_block;
		m_content = a.m_content;

		m_injury_desc = a.m_injury_desc;
		m_retired = a.m_retired;

		m_temp_pointer = a.m_temp_pointer;
		m_all_star = a.m_all_star;
		m_rookie_star = a.m_rookie_star;
		m_3contest = a.m_3contest;
		m_dunkcontest = a.m_dunkcontest;
	
		m_all_star_index = a.m_all_star_index;
		m_rookie_star_index = a.m_rookie_star_index;
		m_3contest_index = a.m_3contest_index;
		m_dunkcontest_index = a.m_dunkcontest_index;
	

		m_starter = a.m_starter;
		m_number = a.m_number;
		m_name = a.m_name;
		m_lastName = a.m_lastName;
		m_injury = a.m_injury;
		m_age = a.m_age;
		m_id = a.m_id;
		m_pos = a.m_pos;
		m_games = a.m_games;
		m_min = a.m_min;
		m_fgm = a.m_fgm;
		m_fga = a.m_fga;
		m_ftm = a.m_ftm;
		m_fta = a.m_fta;
		m_tfgm = a.m_tfgm;
		m_tfga = a.m_tfga;
		m_oreb = a.m_oreb;
		m_reb = a.m_reb;
		m_ast = a.m_ast;
		m_stl = a.m_stl;
		m_to = a.m_to;
		m_blk = a.m_blk;
		m_pf = a.m_pf;
		m_sim_games = a.m_sim_games;
		m_sim_min = a.m_sim_min;
		m_sim_fgm = a.m_sim_fgm;
		m_sim_fga = a.m_sim_fga;
		m_sim_ftm = a.m_sim_ftm;
		m_sim_fta = a.m_sim_fta;
		m_sim_tfgm = a.m_sim_tfgm;
		m_sim_tfga = a.m_sim_tfga;
		m_sim_oreb = a.m_sim_oreb;
		m_sim_reb = a.m_sim_reb;
		m_sim_ast = a.m_sim_ast;
		m_sim_stl = a.m_sim_stl;
		m_sim_to = a.m_sim_to;
		m_sim_blk = a.m_sim_blk;
		m_sim_pf = a.m_sim_pf;

		m_car_games = a.m_car_games;
		m_car_min = a.m_car_min;
		m_car_fgm = a.m_car_fgm;
		m_car_fga = a.m_car_fga;
		m_car_ftm = a.m_car_ftm;
		m_car_fta = a.m_car_fta;
		m_car_tfgm = a.m_car_tfgm;
		m_car_tfga = a.m_car_tfga;
		m_car_oreb = a.m_car_oreb;
		m_car_reb = a.m_car_reb;
		m_car_ast = a.m_car_ast;
		m_car_stl = a.m_car_stl;
		m_car_to = a.m_car_to;
		m_car_blk = a.m_car_blk;
		m_car_pf = a.m_car_pf;



		m_po_games = a.m_po_games;
		m_po_min = a.m_po_min;
		m_po_fgm = a.m_po_fgm;
		m_po_fga = a.m_po_fga;
		m_po_ftm = a.m_po_ftm;
		m_po_fta = a.m_po_fta;
		m_po_tfgm = a.m_po_tfgm;
		m_po_tfga = a.m_po_tfga;
		m_po_oreb = a.m_po_oreb;
		m_po_reb = a.m_po_reb;
		m_po_ast = a.m_po_ast;
		m_po_stl = a.m_po_stl;
		m_po_to = a.m_po_to;
		m_po_blk = a.m_po_blk;
		m_po_pf = a.m_po_pf;

		m_movoff = a.m_movoff;
		m_movdef = a.m_movdef;
		m_penoff = a.m_penoff;
		m_pendef = a.m_pendef;
		m_postoff = a.m_postoff;
		m_postdef = a.m_postdef;
		m_transoff = a.m_transoff;
		m_transdef = a.m_transdef;
		m_clutch = a.m_clutch;
		m_consistency = a.m_consistency;
		m_pgrot = a.m_pgrot;
		m_sgrot = a.m_sgrot;
		m_sfrot = a.m_sfrot;
		m_pfrot = a.m_pfrot;
		m_crot = a.m_crot;
		m_active = a.m_active;		
		m_better = a.m_better;		
	    m_team = a.m_team;
		m_totalGames = a.m_totalGames;
		m_teamGames = a.m_teamGames;

		m_minPerGame = a.m_minPerGame;
		m_pointsPerGame = a.m_pointsPerGame;
		m_reboundsPerGame = a.m_reboundsPerGame;
		m_assistsPerGame = a.m_assistsPerGame;
		m_stealsPerGame = a.m_stealsPerGame;
		m_blocksPerGame = a.m_blocksPerGame;
		m_orbPerGame = a.m_orbPerGame;
		m_toPerGame = a.m_toPerGame;
		m_pfPerGame = a.m_pfPerGame;
		m_fgPct = a.m_fgPct;
		m_tfgPct = a.m_tfgPct;
		m_ftPct = a.m_ftPct;

		m_sim_minPerGame = a.m_sim_minPerGame;
		m_sim_pointsPerGame = a.m_sim_pointsPerGame;
		m_sim_reboundsPerGame = a.m_sim_reboundsPerGame;
		m_sim_assistsPerGame = a.m_sim_assistsPerGame;
		m_sim_stealsPerGame = a.m_sim_stealsPerGame;
		m_sim_blocksPerGame = a.m_sim_blocksPerGame;
		m_sim_orbPerGame = a.m_sim_orbPerGame;
		m_sim_toPerGame = a.m_sim_toPerGame;
		m_sim_pfPerGame = a.m_sim_pfPerGame;
		m_sim_fgPct = a.m_sim_fgPct;
		m_sim_tfgPct = a.m_sim_tfgPct;
		m_sim_ftPct = a.m_sim_ftPct;

		m_po_minPerGame = a.m_po_minPerGame;
		m_po_pointsPerGame = a.m_po_pointsPerGame;
		m_po_reboundsPerGame = a.m_po_reboundsPerGame;
		m_po_assistsPerGame = a.m_po_assistsPerGame;
		m_po_stealsPerGame = a.m_po_stealsPerGame;
		m_po_blocksPerGame = a.m_po_blocksPerGame;
		m_po_orbPerGame = a.m_po_orbPerGame;
		m_po_toPerGame = a.m_po_toPerGame;
		m_po_pfPerGame = a.m_po_pfPerGame;
		m_po_fgPct = a.m_po_fgPct;
		m_po_tfgPct = a.m_po_tfgPct;
		m_po_ftPct = a.m_po_ftPct;


		m_trueRatingSimple = a.m_trueRatingSimple;
		m_tradeTrueRating = a.m_tradeTrueRating;
		m_tradeValue = a.m_tradeValue;

		m_trueRating = a.m_trueRating;
		m_teammatesBetterRating = a.m_teammatesBetterRating;
		m_astTo = a.m_astTo;
		m_defense = a.m_defense;
		m_outside = a.m_outside;
		m_driving = a.m_driving;
		m_post = a.m_post;
		m_transition = a.m_transition;
		m_outsideDefense = a.m_outsideDefense;
		m_drivingDefense = a.m_drivingDefense;
		m_postDefense = a.m_postDefense;
		m_transitionDefense = a.m_transitionDefense;
		m_outsidePer48Min = a.m_outsidePer48Min;
		m_drivingPer48Min = a.m_drivingPer48Min;
		m_postPer48Min = a.m_postPer48Min;
		m_transitionPer48Min = a.m_transitionPer48Min;
		m_outsideDefensePer48Min = a.m_outsideDefensePer48Min;
		m_drivingDefensePer48Min = a.m_drivingDefensePer48Min;
		m_postDefensePer48Min = a.m_postDefensePer48Min;
		m_transitionDefensePer48Min = a.m_transitionDefensePer48Min;
		m_mvp = a.m_mvp;

		m_sim_trueRating = a.m_sim_trueRating;
		m_sim_teammatesBetterRating = a.m_sim_teammatesBetterRating;
		m_sim_astTo = a.m_sim_astTo;
		m_sim_defense = a.m_sim_defense;
		m_sim_outside = a.m_sim_outside;
		m_sim_driving = a.m_sim_driving;
		m_sim_post = a.m_sim_post;
		m_sim_transition = a.m_sim_transition;
		m_sim_outsideDefense = a.m_sim_outsideDefense;
		m_sim_drivingDefense = a.m_sim_drivingDefense;
		m_sim_postDefense = a.m_sim_postDefense;
		m_sim_transitionDefense = a.m_sim_transitionDefense;
		m_sim_outsidePer48Min = a.m_sim_outsidePer48Min;
		m_sim_drivingPer48Min = a.m_sim_drivingPer48Min;
		m_sim_postPer48Min = a.m_sim_postPer48Min;
		m_sim_transitionPer48Min = a.m_sim_transitionPer48Min;
		m_sim_outsideDefensePer48Min = a.m_sim_outsideDefensePer48Min;
		m_sim_drivingDefensePer48Min = a.m_sim_drivingDefensePer48Min;
		m_sim_postDefensePer48Min = a.m_sim_postDefensePer48Min;
		m_sim_transitionDefensePer48Min = a.m_sim_transitionDefensePer48Min;
		m_sim_mvp = a.m_sim_mvp;

		m_po_trueRating = a.m_po_trueRating;
		m_po_teammatesBetterRating = a.m_po_teammatesBetterRating;
		m_po_astTo = a.m_po_astTo;
		m_po_defense = a.m_po_defense;
		m_po_outside = a.m_po_outside;
		m_po_driving = a.m_po_driving;
		m_po_post = a.m_po_post;
		m_po_transition = a.m_po_transition;
		m_po_outsideDefense = a.m_po_outsideDefense;
		m_po_drivingDefense = a.m_po_drivingDefense;
		m_po_postDefense = a.m_po_postDefense;
		m_po_transitionDefense = a.m_po_transitionDefense;
		m_po_outsidePer48Min = a.m_po_outsidePer48Min;
		m_po_drivingPer48Min = a.m_po_drivingPer48Min;
		m_po_postPer48Min = a.m_po_postPer48Min;
		m_po_transitionPer48Min = a.m_po_transitionPer48Min;
		m_po_outsideDefensePer48Min = a.m_po_outsideDefensePer48Min;
		m_po_drivingDefensePer48Min = a.m_po_drivingDefensePer48Min;
		m_po_postDefensePer48Min = a.m_po_postDefensePer48Min;
		m_po_transitionDefensePer48Min = a.m_po_transitionDefensePer48Min;
		m_po_mvp = a.m_po_mvp;



		m_prFga = a.m_prFga;
		m_prFgp = a.m_prFgp;
		m_prTga = a.m_prTga;
		m_prTgp = a.m_prTgp;
		m_prFta = a.m_prFta;
		m_prFtp = a.m_prFtp;
		m_prOrb = a.m_prOrb;
		m_prDrb = a.m_prDrb;
		m_prAst = a.m_prAst;
		m_prStl = a.m_prStl;
		m_prTo = a.m_prTo;
		m_prBlk = a.m_prBlk;
		m_pot1 = a.m_pot1;
		m_pot2 = a.m_pot2;
		m_effort = a.m_effort;
		m_prime = a.m_prime;

		m_adjPrFga = a.m_adjPrFga;
		m_adjPrFgp = a.m_adjPrFgp;
		m_adjPrTga = a.m_adjPrTga;
		m_adjPrTgp = a.m_adjPrTgp;
		m_adjPrFta = a.m_adjPrFta;
		m_adjPrFtp = a.m_adjPrFtp;
		m_adjPrOrb = a.m_adjPrOrb;
		m_adjPrDrb = a.m_adjPrDrb;
		m_adjPrAst = a.m_adjPrAst;
		m_adjPrStl = a.m_adjPrStl;
		m_adjPrTo = a.m_adjPrTo;
		m_adjPrBlk = a.m_adjPrBlk;
		m_adjPot1 = a.m_adjPot1;
		m_adjPot2 = a.m_adjPot2;
		m_adjEffort = a.m_adjEffort;
		m_adjPrime = a.m_adjPrime;
		m_contract_pointer = a.m_contract_pointer;
		m_round_selected = a.m_round_selected;
		m_pick_selected = a.m_pick_selected;
		m_team_index = a.m_team_index;
		m_original_number = a.m_original_number;
		m_original_po_number = a.m_original_po_number;

		for(int i=0; i<= 6; i++)
		{
			m_contract_salaries[i] = a.m_contract_salaries[i];
		}
	    m_coach_factor = a.m_coach_factor;
	    m_security_factor = a.m_security_factor;
	    m_loyalty_factor = a.m_loyalty_factor;
	    m_winning_factor = a.m_winning_factor;
	    m_playing_time_factor = a.m_playing_time_factor;
	    m_tradition_factor = a.m_tradition_factor;

		m_is_free_agent = a.m_is_free_agent;
		m_yrs_on_team = a.m_yrs_on_team;
		m_original_slot = a.m_original_slot;
		m_current_yr_salary = a.m_current_yr_salary;

		m_accept_factor = a.m_accept_factor;
		m_rookie = a.m_rookie;
		m_bird_player = a.m_bird_player;
		m_name = a.m_name;
		m_pos = a.m_pos;
		m_salary_id = a.m_salary_id;
	    m_current_team = a.m_current_team;
	    m_previous_team = a.m_previous_team;
		m_yrs_on_team = a.m_yrs_on_team;
		m_yrs_of_service = a.m_yrs_of_service;
		m_contract_yrs = a.m_contract_yrs;
		m_total_salary = a.m_total_salary;
		m_remaining_salary = a.m_remaining_salary;
		m_total_salary_seeking = a.m_total_salary_seeking;
		m_current_contract_yr = a.m_current_contract_yr;
		m_qualifying_offer_years = a.m_qualifying_offer_years;

			for(int j=0; j<=3; j++)
			{
				m_3ptscore[j] = a.m_3ptscore[j];
				m_dunkscore[j] = a.m_dunkscore[j];
			}
		
		for(int i=0; i<= 6; i++)
		{
			m_qualifying_salaries[i] = a.m_qualifying_salaries[i];
			m_new_contract_salaries[i] = a.m_new_contract_salaries[i];
		}

		for(int i=0; i<= 32; i++)
		{
			m_seeking[i] = a.m_seeking[i];
		}
		m_is_free_agent = a.m_is_free_agent;
		m_team_paying = a.m_team_paying;
		m_team_paying_name = a.m_team_paying_name;
	    
		for(int i=0; i<= 32; i++)
		{
			m_top_offer[i] = a.m_top_offer[i];
			m_year_offer[i] = a.m_year_offer[i];
			m_total_salary_offer[i] = a.m_total_salary_offer[i];
			m_offer_slot[i] = a.m_offer_slot[i];
			for(int  j=0; j<= 6; j++)
			{
				m_salary_offer[i][j] = a.m_salary_offer[i][j];
			}
		}
		m_best_contract = a.m_best_contract;
		m_signed = a.m_signed;
		m_player_pointer = a.m_player_pointer;
		

			m_random_yrs_service = a.m_random_yrs_service;	
			m_random_contracts = a.m_random_contracts;	
			m_random_contract_ratings = a.m_random_contract_ratings;	
			m_random_projections = a.m_random_projections;	
  

		for(int i=0; i<= 6; i++)
		{
			m_contract_salaries[i] = a.m_contract_salaries[i];
		}

		m_hi_pts = a.m_hi_pts;
		m_hi_reb = a.m_hi_reb;
		m_hi_ast = a.m_hi_ast;
		m_hi_stl = a.m_hi_stl;
		m_hi_blk = a.m_hi_blk;
		m_double = a.m_double;
		m_triple = a.m_triple;

		m_hi_pts_po = a.m_hi_pts_po;
		m_hi_reb_po = a.m_hi_reb_po;
		m_hi_ast_po = a.m_hi_ast_po;
		m_hi_stl_po = a.m_hi_stl_po;
		m_hi_blk_po = a.m_hi_blk_po;

		m_hi_pts_car = a.m_hi_pts_car;
		m_hi_reb_car = a.m_hi_reb_car;
		m_hi_ast_car = a.m_hi_ast_car;
		m_hi_stl_car = a.m_hi_stl_car;
		m_hi_blk_car = a.m_hi_blk_car;
		m_double_car = a.m_double_car;
		m_triple_car = a.m_triple_car;

		m_hi_pts_car_po = a.m_hi_pts_car_po;
		m_hi_reb_car_po = a.m_hi_reb_car_po;
		m_hi_ast_car_po = a.m_hi_ast_car_po;
		m_hi_stl_car_po = a.m_hi_stl_car_po;
		m_hi_blk_car_po = a.m_hi_blk_car_po;


		m_game_minutes = a.m_game_minutes;
		m_offensive_focus = a.m_offensive_focus;
		m_defensive_focus = a.m_defensive_focus;
		m_offensive_intensity = a.m_offensive_intensity;
		m_defensive_intensity = a.m_defensive_intensity;
		m_play_maker = a.m_play_maker;



	m_MinPerGame = a.m_MinPerGame;
	    m_FgPct = a.m_FgPct;
	    m_adjustedFgPct = a.m_adjustedFgPct;
	    m_FtPct = a.m_FtPct;
		m_FoulsDrawnPer48Min = a.m_FoulsDrawnPer48Min;
		m_AdjustedFoulsDrawnPer48Min = a.m_AdjustedFoulsDrawnPer48Min;
	    m_TfgPct = a.m_TfgPct;
	    m_FgaPer48Min = a.m_FgaPer48Min;
	    m_AdjustedFgaPer48Min = a.m_AdjustedFgaPer48Min;
	    m_coachFgaPer48Min = a.m_coachFgaPer48Min;
	    m_coachTfgaPer48Min = a.m_coachTfgaPer48Min;
	    m_TfgaPer48Min = a.m_TfgaPer48Min;
	    m_AdjustedTfgaPer48Min = a.m_AdjustedTfgaPer48Min;
	    m_OrebPer48Min = a.m_OrebPer48Min;
		m_DrebPer48Min = a.m_DrebPer48Min;
		m_AstPer48Min = a.m_AstPer48Min;
		m_StlPer48Min = a.m_StlPer48Min;
		m_ToPer48Min = a.m_ToPer48Min;
		m_AdjustedToPer48Min = a.m_AdjustedToPer48Min;
		m_BlkPer48Min = a.m_BlkPer48Min;
		m_PfPer48Min = a.m_PfPer48Min;
  		m_injuryRating = a.m_injuryRating;
		m_stamina = a.m_stamina;	

		m_OriginalAdjustedFoulsDrawnPer48Min = a.m_OriginalAdjustedFoulsDrawnPer48Min;
		m_OriginalAdjustedFgaPer48Min = a.m_OriginalAdjustedFgaPer48Min;
		m_OriginalAdjustedTfgaPer48Min = a.m_OriginalAdjustedTfgaPer48Min;
		m_OriginalStlPer48Min = a.m_OriginalStlPer48Min;
		m_OriginalBlkPer48Min = a.m_OriginalBlkPer48Min;


		m_game_name = a.m_game_name;
		m_game_injury = a.m_game_injury;
		m_game_Min = a.m_game_Min;
		m_game_Fgm = a.m_game_Fgm;
		m_game_Fga = a.m_game_Fga;
		m_game_Tfgm = a.m_game_Tfgm;
		m_game_Tfga = a.m_game_Tfga;
		m_game_Ftm = a.m_game_Ftm;
		m_game_Fta = a.m_game_Fta;
		m_game_Oreb = a.m_game_Oreb;
		m_game_Dreb = a.m_game_Dreb;
		m_game_Ast = a.m_game_Ast;
		m_game_Stl = a.m_game_Stl;
		m_game_To = a.m_game_To;
		m_game_Blk = a.m_game_Blk;
		m_game_Pf = a.m_game_Pf;
		m_game_stamina = a.m_game_stamina;
		m_game_stat_slot = a.m_game_stat_slot;
		m_game_player_pointer = a.m_game_player_pointer;
		return *this;
    }


		public:
			bool TestingMarket(bool signed_extension);
			void SetAswScores();
//			void RandomizeODPT();
		int OffSeasonInjury(int stage, int &days);
		bool Disabled(int games);
		int GetAwardPoints(CString file_name, int &major_points);
		bool HallofFamer(int awa_pts, int major_points);
		void SetOldRatings();
		void GenerateRandomHeightWeight(bool rookie);
		bool AcceptComputerExtension(int seeking_factor, int year_offer, int total_salary_offer);
		void RankFavorites(int *fav, int teams);
		bool AcceptContract(int seeking_factor, int year_offer, int total_salary_offer, double &quality_of_offer);
		int SetExtensionRequests(int franchise_w, int franchise_l, double val[6], double pos_value[6], int coach_rating, bool extension, int games_season);
		void UpdateCareerStats();
		void ListHighs(CString string[36]);
		//void CreateReport(CString m_lines[33], CStaff m_scout, int r_ast[6]);

		void CreateReport(CString m_lines[33], 
			int r_ast[6], int r_fta[6], int r_tga[6], double m_avg_tgp[6], int r_orb[6], int r_drb[6],
			int r_stl[6], int r_to[6], int r_blk[6],
		int r_fga[6], double m_avg_fgp[6], double m_avg_fga[6], double m_avg_ftp[6], double m_avg_trade_tru[6]);

		void SetGameHighs(int game_type);
		void ClearSeasonStats();
		void ClearGameStats();



	void SetGameMinPerGame(int Games, int Min)
	{
		m_MinPerGame = double(Min) / double(Games);
	}

	void SetGameFgPct(int Fgm, int Fga)
	{
		double FgPct = 0;
		if(Fga > 0) FgPct = double(Fgm) / double(Fga) * 1000;
		m_FgPct = Round(FgPct);
	}

	void SetGameAdjustedFgPct()
	{
		double adjustedFg = double(GetGameFgPct()) * (4 * GetGameAdjustedFgaPer48Min() - GetGameFgaPer48Min()) / 3000;
		double Fga = GetGameAdjustedFgaPer48Min();
		double FgPct = 0;
		if(Fga > 0) FgPct = adjustedFg / Fga * 1000;
		m_adjustedFgPct = Round(FgPct);
	}

	void SetGameFtPct(int Ftm, int Fta)
	{
		double FtPct = 0;
		if(Fta > 0) FtPct = double(Ftm) / double(Fta) * 1000;
		m_FtPct = Round(FtPct);
	}

	void SetGameFoulsDrawnPer48Min(int Fta, int Min, double foulRatio)
	{
		if(Min > 0)
			m_FoulsDrawnPer48Min = Fta * foulRatio / double(Min) * 48;
		else
			m_FoulsDrawnPer48Min = 0;
	}

	void SetGameAdjustedFoulsDrawnPer48Min()
	{
		m_AdjustedFoulsDrawnPer48Min = 0;

		if((m_FgaPer48Min + m_OrebPer48Min) > 0 && m_AdjustedFgaPer48Min > 0)
		{

		double factor =
			.25 + (GetGameFgaPer48Min() / (GetGameFgaPer48Min()
				+ GetGameOrebPer48Min())) / 2;

		double adj2 = GetGameFgaPer48Min() * (double(GetGameFgPct()) / 1000) * .05;
		double adj3 = GetGameTfgaPer48Min() * .02;
		double adj = adj2 + adj3;

		m_AdjustedFoulsDrawnPer48Min = 
			(GetGameFoulsDrawnPer48Min()
			- factor *
			(GetGameFoulsDrawnPer48Min()
			/ GetGameAdjustedFgaPer48Min() *
			GetGameOrebPer48Min())) - adj;
		}
	}


	void SetGameTfgPct(int Tfgm, int Tfga)
	{
		double TfgPct = 0;
		if(Tfga > 0) TfgPct = double(Tfgm) / double(Tfga) * 1000;
		m_TfgPct = Round(TfgPct);
	}

	void SetGameFgaPer48Min(int Fga, int Min)
	{
		m_FgaPer48Min = double(Fga) / double(Min) * 48;
	}

	void SetGameAdjustedFgaPer48Min(double fb)
	{
	

		if(fb > 0 && m_AdjustedFgaPer48Min > 0)//adjust for fast breaks
		{


			double fd = m_AdjustedFoulsDrawnPer48Min;
			double to = m_AdjustedToPer48Min;
			double tg = m_AdjustedTfgaPer48Min;
			double ga = m_AdjustedFgaPer48Min;
			double po = fd + to + tg + ga;
			double ratio = (po - fb) / po;
			m_AdjustedFgaPer48Min = ga*ratio;
			m_AdjustedFoulsDrawnPer48Min = fd*ratio;
			m_AdjustedToPer48Min = to*ratio;
			m_AdjustedTfgaPer48Min = tg*ratio;

		}
		else if((GetGameFgaPer48Min() + GetGameFoulsDrawnPer48Min()) > 0)
		{
		double factor =
			.25 + (GetGameFgaPer48Min() / (GetGameFgaPer48Min()
				+ GetGameOrebPer48Min())) / 2;

		m_AdjustedFgaPer48Min = 
			(GetGameFgaPer48Min()
			- factor *
			(GetGameFgaPer48Min()
			/ (GetGameFgaPer48Min() + GetGameFoulsDrawnPer48Min()) *
			GetGameOrebPer48Min()));
		}
	}

	void SetGameCoachFgaPer48Min()
	{
		m_coachFgaPer48Min = (m_AdjustedFgaPer48Min + m_AdjustedTfgaPer48Min + 
			m_AdjustedFoulsDrawnPer48Min + m_AdjustedToPer48Min) * 3;
	}

	void SetGameCoachTfgaPer48Min(bool team)
	{
		if(team == false)
			m_coachTfgaPer48Min = m_TfgaPer48Min*4;
		else
			m_coachTfgaPer48Min = 
				m_FgaPer48Min + m_TfgaPer48Min + m_FoulsDrawnPer48Min; 
	}




void SetViewedRequests(int &total_salary, int &contract_yrs)
{

	double actual_value = m_tradeTrueRating;
	double sim_value = actual_value;
	if(m_sim_games > 0) sim_value = m_sim_trueRating / m_sim_games;
	double trade_value = (sim_value + actual_value) / 2;
	

	int age = m_age;

			double money = trade_value * 100;
			money = money * (.875 + (double)IntRandom(25)/100);
			bool max_raise = false;

			if(money > MAX10 && m_yrs_of_service >= 10)
			{
				money = MAX10;
				max_raise = true;
			}
			else if(money > MAX7 && m_yrs_of_service >= 7) 
			{
				money = MAX7;
				max_raise = true;
			}
			else if(money > MAX0) 
			{
				money = MAX0;
				max_raise = true;
			}

			double m_minimum[11];
			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;
			int y_s = m_yrs_of_service;
			if(y_s > 10) y_s = 10;
			if(money < m_minimum[y_s] || y_s == 0)
				money = m_minimum[y_s];

			int contract_max =  6;
			//write some code based on age to set years wanted
			if(age > 28) contract_max = 35 - age;

			if(contract_max > 6) contract_max = 6;
			else if(contract_max < 2) contract_max = 2;
			
			int current_money = (int)money;
			total_salary = current_money;


			double d_mpy = (double)money / 100;
			int mpy = (int)d_mpy;
			int o_mpy = mpy + 1;
			mpy = mpy - 3 + m_security_factor;
			if(mpy < 1) mpy = 1;

			int contract_years = 1 + IntRandom(mpy);

			if(contract_years < 1) contract_years = 1;
			else if(contract_years > 6) contract_years = 6;

			if(contract_years > contract_max) contract_years = contract_max; 
			if(contract_years > o_mpy) contract_years = o_mpy; 

			m_qualifying_salaries[1] = int(money);
			m_qualifying_offer_years = contract_yrs;

			if(contract_years != 1)//end of contract
			{
				double inc = double(current_money) * .10;
				
				for(int j=2; j<=contract_years; j++)
				{
					double money = double(current_money) + inc;
					m_qualifying_salaries[j] = int(money);
					current_money = (int)money;
					total_salary = total_salary + current_money;
				}
			
			}

		
}
	
	










	void ReduceGameCoachFgaPer48Min()
	{
		m_coachFgaPer48Min = m_coachFgaPer48Min - 2;
		double min = (m_AdjustedFgaPer48Min + m_AdjustedTfgaPer48Min + 
			m_AdjustedFoulsDrawnPer48Min + m_AdjustedToPer48Min) * 1/2;
		if(m_coachFgaPer48Min < min) m_coachFgaPer48Min = min;
	}

	void ReduceGameCoachTfgaPer48Min(int factor)
	{
		m_coachTfgaPer48Min = m_coachTfgaPer48Min-factor;
		if(m_coachTfgaPer48Min < factor) m_coachTfgaPer48Min = factor;
	}

	void SetGameTfgaPer48Min(int Tfga, int Min)
	{
		m_TfgaPer48Min = double(Tfga) / double(Min) * 48;
	}

	void SetGameAdjustedTfgaPer48Min(int Tfga, int Min)
	{
		m_AdjustedTfgaPer48Min = double(Tfga) / double(Min) * 48;
	}

	
	void SetGameOrebPer48Min(int Oreb, int Min)
	{
		m_OrebPer48Min = double(Oreb) / double(Min) * 48;
	}

	void SetGameDrebPer48Min(int Oreb, int Reb, int Min)
	{
		m_DrebPer48Min = 
			( double(Reb) - double(Oreb) ) / double(Min) * 48;
	}

	void SetGameAstPer48Min(int Ast, int Min)
	{
		m_AstPer48Min = double(Ast) / double(Min) * 48;
	}

	void SetGameStlPer48Min(int Stl, int Min)
	{
		m_StlPer48Min = double(Stl) / double(Min) * 48 * 5/6*11/10;
	}

	void SetGameToPer48Min(int To, int Min)
	{
		m_ToPer48Min = double(To) / double(Min) * 48;
	}
	
	void SetGameAdjustedToPer48Min(int To, int Min)
	{
		m_AdjustedToPer48Min = double(To) / double(Min) * 48;
	}

	void SetGameBlkPer48Min(int Blk, int Min)
	{
		m_BlkPer48Min = double(Blk) / double(Min) * 48;
	}

	void SetGamePfPer48Min(int Pf, int Min)
	{
		m_PfPer48Min = double(Pf) / double(Min) * 48;
	}

  	void SetGameInjuryRating(int g, int min, int fga, int fta, int to, int injury, int m_hiGames)
	{
		
			if(m_hiGames > 82) m_hiGames = 82;	
			int plays = fga + fta + to;
			double playsPerGame = double(plays) / double(g);
			double plays82 = playsPerGame * m_hiGames;
			double playsMissed = plays82 - double(plays);
			double rating = playsMissed / 20;

			int g_missed = m_hiGames - g;
			rating = g_missed * 1000 / plays82;

			if(rating < 1) rating = 1;
//			else if(rating > 99) rating = m_hiGames + 1 - g;
			else if(rating > 27) rating = 27;
  			m_injuryRating = int(rating);
			if(injury == 2 && m_injuryRating > 5) m_injuryRating = 5;
			else if(injury == 2 && m_injuryRating < 2) m_injuryRating = 2;

	}
	
	void SetGameStamina(int g, int min, int coach_endurance_rating)
	{
		double stamina = double(min)/double(g)/3*60;
		double factor = 1 + double(coach_endurance_rating) / 50.;
		stamina = stamina * factor;
		if(stamina < 480) stamina = 480; //minimum stamina 8 minutes straight
		m_stamina = int(stamina);
	}

	void GenerateRandomPrime()
	{
				
				int prime = 26 + IntRandom(3);
				if(IntRandom(5)<=1)
				{
					prime = 25 + IntRandom(5);
					if(IntRandom(5)<=1)
					{
						prime = 24 + IntRandom(7);
						if(IntRandom(1)<=5)
						{
							prime = 23 + IntRandom(9);
							if(IntRandom(5)<=1)
							{
								prime = 22 + IntRandom(11);
							}	
						}
					}
				}
				
				if(m_age < 21) prime = prime-1;
				if(GetPos() == " C") prime = prime + 1;
				m_prime = prime;
	}

	double GetGameMinPerGame(){return m_MinPerGame;}
	int GetGameFgPct(){return m_FgPct;}
	int GetGameAdjustedFgPct(){return m_adjustedFgPct;}
	int GetGameFtPct(){return m_FtPct;}	
	double GetGameFoulsDrawnPer48Min(){return m_FoulsDrawnPer48Min;}
	double GetGameAdjustedFoulsDrawnPer48Min(){return m_AdjustedFoulsDrawnPer48Min;}
	int GetGameTfgPct(){return m_TfgPct;}
	double GetGameFgaPer48Min(){return m_FgaPer48Min;}
	double GetGameAdjustedFgaPer48Min(){return m_AdjustedFgaPer48Min;}
	double GetGameCoachFgaPer48Min(){return m_coachFgaPer48Min;}
	double GetGameCoachTfgaPer48Min(){return m_coachTfgaPer48Min;}
	double GetGameTfgaPer48Min(){return m_TfgaPer48Min;}
	double GetGameAdjustedTfgaPer48Min(){return m_AdjustedTfgaPer48Min;}
	double GetGameOrebPer48Min(){return m_OrebPer48Min;}
	double GetGameDrebPer48Min(){return m_DrebPer48Min;}
	double GetGameAstPer48Min(){return m_AstPer48Min;}
	double GetGameStlPer48Min(){return m_StlPer48Min;}
	double GetGameToPer48Min(){return m_ToPer48Min;}
	double GetGameAdjustedToPer48Min(){return m_AdjustedToPer48Min;}
	double GetGameBlkPer48Min(){return m_BlkPer48Min;}
	double GetGamePfPer48Min(){return m_PfPer48Min;}
  	int GetGameInjuryRating(){return m_injuryRating;}
	//int GetGameStamina(){return m_stamina;}
	// Round off numbers function
	int Round(double number)
	{
		double diff = number - int(number);
		int eger = 0;
		int integer = 0;
		if(diff > .5)
			integer = int(number + 1);
		else
			integer = int(number);
		return integer;
	}




};







