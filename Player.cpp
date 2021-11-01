#include "stdafx.h"

//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 



//#ifndef Staff_h
//#include "Staff.h"
//#define Staff_h
//#endif



void CPlayer::Calculate(bool rookie_import)
{




	SetOutside();
	SetDriving();
	SetPost();
	SetTransition();
	SetOutsideDefense();
	SetDrivingDefense();
	SetPostDefense();
	SetTransitionDefense();

	int outside = Round(GetOutside());
	int outsideDefense = Round(GetOutsideDefense());
	int driving = Round(GetDriving());
	int drivingDefense = Round(GetDrivingDefense());
	int post = Round(GetPost());
	int postDefense = Round(GetPostDefense());
	int transition = Round(GetTransition());
	int transitionDefense = Round(GetTransitionDefense());

	if(rookie_import == true)
	{

	outside = Round(GetOutside() + 1);
	outsideDefense = Round(GetOutsideDefense() - 2.);
	driving = Round(GetDriving() + 1);
	drivingDefense = Round(GetDrivingDefense() - 2.);
	post = Round(GetPost() + 1);
	postDefense = Round(GetPostDefense() - 2.);
	transition = Round(GetTransition() + 1);
	transitionDefense = Round(GetTransitionDefense() - 2.);

	}

	if(outside > 9) outside = 9; else if(outside < 1) outside = 1;
	if(outsideDefense > 9) outsideDefense = 9; else if(outsideDefense < 1) outsideDefense = 1;
	if(driving > 9) driving = 9; else if(driving < 1) driving = 1;
	if(drivingDefense > 9) drivingDefense = 9; else if(drivingDefense < 1) drivingDefense = 1;
	if(post > 9) post = 9; else if(post < 1) post = 1;
	if(postDefense > 9) postDefense = 9; else if(postDefense < 1) postDefense = 1;
	if(transition > 9) transition = 9; else if(transition < 1) transition = 1;
	if(transitionDefense > 9) transitionDefense = 9; else if(transitionDefense < 1) transitionDefense = 1;

	SetMovOff(outside);
	SetMovDef(outsideDefense);
	SetPenOff(driving);
	SetPenDef(drivingDefense);
	SetPostOff(post);
	SetPostDef(postDefense);
	SetTransOff(transition);
	SetTransDef(transitionDefense);


	SetTrueRatingSimple(2);
	SetTradeTrueRating(GetInjury());
	SetTradeValue();

}



void CPlayer::AdjustForPro(int team, int comp, int dur, int ten)
{
	double factor1 = (70 + (comp + team) * 2) / 100. * (double)ten / 100.;
	double factor2 = (85 + (comp + team) * 1) / 100. * (double)ten / 100.;
	double factor3 = (70 + comp * 4) / 100. * (double)ten / 100.;
	double factor4 = (86 + comp * 4 - team) / 100. * (double)ten / 100.;
	double factor7 = (82 + comp * 4 - team) / 100. * (double)ten / 100.;//steal
	double factor5 = (50 + comp * 6) / 100. * (double) ten / 100.;
	double factor6 = 1 + (10-comp)/100;




	int old_touches = m_fga + m_tfga + m_ast;


	double min_factor = 1; //used for no reason in 1st part lazy

	double fgm = ((double)m_fgm - (double)m_tfgm) * factor1 * factor2 * min_factor;
	double fga = ((double)m_fga - (double)m_tfga) * factor1* min_factor;

	double tgm = (double)m_tfgm * factor1 * factor2 * min_factor;
	double tga = (double)m_tfga * factor1 * min_factor;

	
	SetFgm((int)fgm + (int)tgm);
	SetFga((int)fga + (int)tga);


	SetFtm(int((double)m_ftm * factor1 * min_factor));
	SetFta(int((double)m_fta * factor1 * min_factor));

	SetTfgm(int(tgm));
	SetTfga(int(tga));

	
	SetOreb(int((double)m_oreb * factor3 * min_factor));
	SetReb(int((double)m_reb * factor3 * min_factor));
 
	SetAst(int((double)m_ast * factor4 * min_factor));
	SetStl(int((double)m_stl * factor7 * min_factor));


	int new_touches = GetFga() + GetFta() + GetAst();
	double factor = (double)new_touches / (double)old_touches;
	if(m_pos != "PG") factor = (100. + (double)team - (double)comp) / 100.;


	SetTo(int((double)m_to * factor * min_factor));
	SetBlk(int((double)m_blk * factor5 * min_factor));
	SetPf(int(double(m_pf) * factor6 * min_factor));






	if(dur > 5) dur = 5;
	else if(dur < 1) dur = 1;

	int old_g = m_games;
	int new_g = 60 + dur*4 + IntRandom(5) - 3;
	double g_factor = (double) new_g / (double) old_g;

	double old_mpg = (double) m_min / (double) m_games;


	//ajdust mpg && games
//	double tru = GetRookieTrue(games, mpg, fgm, fga, tgm, tga, ftm, fta, orb, drb, ast, stl, to, blk, pf);
  	double gun = m_fgm + m_tfgm - (m_fga - m_fgm) * 2/3;
  	gun = gun + m_ftm - m_fta / 2; 
	gun = gun + (m_fta - m_ftm) * 1/6;
	gun = gun * 3/2;

 	double skill = m_oreb * 2/3 + (m_reb - m_oreb)* 1/3;
	skill = skill + m_stl -  m_to + m_blk;
	skill = skill + m_ast * 4 / 5;
	skill = skill * 3/4;//fix this shit maybe
	double tru = gun + skill;
	if(m_games == 0)
		tru = 0;
	else
		tru = tru / m_min * 48;


	tru = tru*(old_mpg/48);
	double mpg2 = tru * 2.5 + 8;
	if(mpg2 <= 2) mpg2 = 2;
min_factor = mpg2 / old_mpg;


	m_games = new_g;
	m_min = int((double)m_min * g_factor * min_factor);






min_factor = g_factor * min_factor;




fgm = ((double)m_fgm - (double)m_tfgm)  * min_factor;
fga = ((double)m_fga - (double)m_tfga) * min_factor;

tgm = (double)m_tfgm * min_factor;
tga = (double)m_tfga * min_factor;

	
	SetFgm((int)fgm + (int)tgm);
	SetFga((int)fga + (int)tga);


	SetFtm(int((double)m_ftm  * min_factor));
	SetFta(int((double)m_fta  * min_factor));

	SetTfgm(int(tgm));
	SetTfga(int(tga));

	
	SetOreb(int((double)m_oreb * min_factor));
	SetReb(int((double)m_reb * min_factor));

	SetAst(int((double)m_ast *  min_factor));
	SetStl(int((double)m_stl *  min_factor));


new_touches = GetFga() + GetFta() + GetAst();
factor = (double)new_touches / (double)old_touches;
	SetTo(int((double)m_to *  min_factor));
	SetBlk(int((double)m_blk * min_factor));
	SetPf(int(double(m_pf) * min_factor));

}


void CPlayer::InkedNewDeal(int best_contract)
{


		m_just_signed = true;
		for(int y=0; y<=6; y++)
		{
			m_contract_salaries[y] = 0;
		}		

		m_contract_yrs = m_year_offer[best_contract];
		m_current_contract_yr = 0;
		m_is_free_agent = false;
		m_signed = true;
		int sal = 0 ;
		for(int y=1; y<=m_contract_yrs; y++)
		{
			m_contract_salaries[y] = m_new_contract_salaries[y];
			sal = sal + m_contract_salaries[y];
		}
		m_remaining_salary = sal;
		m_total_salary = sal;
//		m_best_contract = -1;
}

void CPlayer::SetOriginalAdjustedRatings()
{

		m_OriginalAdjustedFoulsDrawnPer48Min = m_AdjustedFoulsDrawnPer48Min;
		m_OriginalAdjustedFgaPer48Min = m_AdjustedFgaPer48Min;
		m_OriginalAdjustedTfgaPer48Min = m_AdjustedTfgaPer48Min;
		m_OriginalStlPer48Min = m_StlPer48Min;
		m_OriginalBlkPer48Min = m_BlkPer48Min;



}



void CPlayer::ClearGameStats()
{
/*	m_MinPerGame = 0;
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
	m_OriginalBlkPer48Min = 0;*/


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

void CPlayer::ClearSeasonStats()
{
	 m_sim_games = 0;
	 m_starter = 0;
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

		m_stop_negotiating = 0;

		m_all_star = 0;
		m_all_star_index = 0;
		m_rookie_star = 0;
		m_rookie_star_index = 0;

}

void CPlayer::SetGameHighs(int game_type)
{
	int points = m_game_Fgm*2 + m_game_Tfgm*3 + m_game_Ftm;
	int reb = m_game_Oreb + m_game_Dreb;
	int ast = m_game_Ast;
	int stl = m_game_Stl;
	int blk = m_game_Blk;


	int cats = 0;
	if(points >= 10) cats = cats + 1;
	if(reb >= 10) cats = cats + 1;
	if(ast >= 10) cats = cats + 1;
	if(stl >= 10) cats = cats + 1;
	if(blk >= 10) cats = cats + 1;


	if(game_type == LEAGUE)
	{
		if(cats == 2 || cats == 3)
		{
			m_double = m_double + 1;
			m_double_car = m_double_car + 1;
		}
		if(cats == 3)
		{
			m_triple = m_triple + 1;
			m_triple_car = m_triple_car + 1;
		}

		if(points > m_hi_pts) m_hi_pts = points;
		if(reb > m_hi_reb)	m_hi_reb = reb;
		if(m_game_Ast > m_hi_ast) m_hi_ast = m_game_Ast;
		if(m_game_Stl > m_hi_stl) m_hi_stl = m_game_Stl;
		if(m_game_Blk > m_hi_blk) m_hi_blk = m_game_Blk;

		if(points > m_hi_pts_car) m_hi_pts_car = points;
		if(reb > m_hi_reb_car)	m_hi_reb_car = reb;
		if(m_game_Ast > m_hi_ast_car) m_hi_ast_car = m_game_Ast;
		if(m_game_Stl > m_hi_stl_car) m_hi_stl_car = m_game_Stl;
		if(m_game_Blk > m_hi_blk_car) m_hi_blk_car = m_game_Blk;

	}
	else if(game_type == PLAYOFF)
	{

		if(points > m_hi_pts_po) m_hi_pts_po = points;
		if(reb > m_hi_reb_po) m_hi_reb_po = reb;
		if(m_game_Ast > m_hi_ast_po) m_hi_ast_po = m_game_Ast;
		if(m_game_Stl > m_hi_stl_po) m_hi_stl_po = m_game_Stl;
		if(m_game_Blk > m_hi_blk_po) m_hi_blk_po = m_game_Blk;

		if(points > m_hi_pts_car_po) m_hi_pts_car_po = points;
		if(reb > m_hi_reb_car_po)	m_hi_reb_car_po = reb;
		if(m_game_Ast > m_hi_ast_car_po) m_hi_ast_car_po = m_game_Ast;
		if(m_game_Stl > m_hi_stl_car_po) m_hi_stl_car_po = m_game_Stl;
		if(m_game_Blk > m_hi_blk_car_po) m_hi_blk_car_po = m_game_Blk;

	}

}

//void CPlayer::CreateReport(CString *m_lines[])
//{
//
//}


void CPlayer::CreateReport(CString m_lines[33], 
			int r_ast[6], int r_fta[6], int r_tga[6], double m_avg_tgp[6], int r_orb[6], int r_drb[6],
			int r_stl[6], int r_to[6], int r_blk[6],
		int r_fga[6], double m_avg_fgp[6], double m_avg_fga[6], double m_avg_ftp[6], double m_avg_trade_tru[6])
	{

	CString s_pot[31];
	CString s_tru[31];
	CString s_fb[21];
	CString s_def[37];
	CString s_bh[21];
	CString s_fga[21];
	CString s_fgp[21];
	CString s_fta[21];
	CString s_ftp[21];
	CString s_tga[21];
	CString s_tgp[21];
	CString s_orb[21];
	CString s_drb[21];
	CString s_ast[21];
	CString s_stl[21];
	CString s_to[21];
	CString s_blk[21];

	CString pos = GetPos();
	int m_po = 1;
	if(pos == "SG") m_po = 2;
	else if(pos == "SF") m_po = 3;
	else if(pos == "PF") m_po = 4;
	else if(pos == " C") m_po = 5;

	s_fga[0] = "Never looks to shoot";	
	s_fga[1] = "Rarely shoots";	
	s_fga[2] = "Doesn't really look for the shot";	

	s_fga[8] = "Looks to shoot";	
	s_fga[9] = "Can create a shot";	
	s_fga[10] = "Will take advantage of defenders";	
	s_fga[11] = "Can get a shot off basically at will";	

	s_ast[0] = "Black hole as a passer";
	s_ast[1] = "Basically not a passer";
	s_ast[2] = "Rarely passes";
	s_ast[3] = "Will look to pass on occasion";
	s_ast[4] = "Decent passer";
	s_ast[5] = "Solid passer";
	s_ast[6] = "Will make the tough pass";
	s_ast[7] = "Quality passer";
	s_ast[8] = "Excellent passer";
	s_ast[9] = "Terrific passer";
	s_ast[10] = "Amazing passer";
	s_ast[11] = "One of the best passers I've seen";

	s_orb[0] = "Never gets to the offensive board";
	if(m_po == 1) s_orb[0] = "";
	s_orb[1] = "Poor offensive rebounder";
//f(m_po == 1) s_orb[1] = "";
	s_orb[2] = "Won't give you much of anything on the offensive glass";
	if(m_po == 1) s_orb[2] = "";
	s_orb[3] = "Not a real threat on the offensive board";
	if(m_po == 1) s_orb[3] = "";
	s_orb[4] = "So-So offensive rebounder";
	if(m_po == 1) s_orb[4] = "";
	s_orb[5] = "Average offensive rebounder";
	if(m_po == 1) s_orb[5] = "";
	s_orb[6] = "Decent rebounder on offense";
	if(m_po == 1) s_orb[6] = "";
	s_orb[7] = "Quality offensive rebounder";
	s_orb[8] = "Very good offensive rebounder";
	s_orb[9] = "Terrific on the offensive glass";
	s_orb[10] = "Amazing offensive rebounder";
	s_orb[11] = "One of the best offensive rebounders ever at the position";
	if(m_po >= 4) s_orb[11] = "One of the best offensive rebounders ever";


	s_drb[0] = "Never gets to the defensive board";
	s_drb[1] = "Poor defensive rebounder";
//f(m_po == 1) s_drb[1] = "";
	s_drb[2] = "Won't give you much of anything on the defensive glass";
	if(m_po == 1) s_drb[2] = "";
	s_drb[3] = "Not a real threat on the defensive board";
	if(m_po == 1) s_drb[3] = "";
	s_drb[4] = "So-So defensive rebounder";
	if(m_po == 1) s_drb[4] = "";
	s_drb[5] = "Average defensive rebounder";
	if(m_po == 1) s_drb[5] = "";
	s_drb[6] = "Decent rebounder on defense";
	if(m_po == 1) s_drb[6] = "";
	s_drb[7] = "Quality defensive rebounder";
	s_drb[8] = "Very good defensive rebounder";
	s_drb[9] = "Terrific on the defensive glass";
	s_drb[10] = "Amazing defensive rebounder";
	s_drb[11] = "One of the best defensive rebounders ever";
	if(m_po <= 3) s_drb[7] = "Good defensive rebounder for the position";
	if(m_po <= 3) s_drb[8] = "Very good defensive rebounder for the position";
	if(m_po <= 3) s_drb[9] = "Terrific on the defensive glass at the position";
	if(m_po <= 3) s_drb[10] = "Amazing defensive rebounder at the position";
	if(m_po <= 3) s_drb[11] = "One of the best defensive rebounders ever at the position";

	s_fta[0] = "Never draws fouls";
	s_fta[1] = "Rarely gets to the line";
	s_fta[2] = "Doesn't look to drive";
	s_fta[6] = "Gets to the line";
	s_fta[7] = "Gets to the line often";
	s_fta[8] = "Solid ability to draw fouls";
	s_fta[9] = "Uncanny ability to draw fouls";
	s_fta[10] = "Gets to the free throw line almost at will";
	s_fta[11] = "Makes an incredible amount of trips to the line";

	s_tga[0] = "Doesn't have three point range";
	s_tga[1] = "Very rarely a threat from behind the arc";
	s_tga[2] = "Rarely a threat form three";
	s_tga[3] = "Will make an occasional three";
	s_tga[6] = "Has decent three point range";
	s_tga[7] = "Can make a three";
	s_tga[8] = "Has definite three point range";
	s_tga[9] = "Terrific three point shooter";
	s_tga[10] = "Deadly behind the arc";
	s_tga[11] = "Can make a three from anywhere";
	if(m_po >= 4) s_tga[0] = "";
	if(m_po >= 4) s_tga[1] = "";
	if(m_po >= 4) s_tga[2] = "";
	if(m_po >= 4) s_tga[6] = "";
	if(m_po >= 4) s_tga[7] = "Will surprise by making an occasional long range bomb";
	if(m_po >= 4) s_tga[8] = "Will shoot some threes";
	if(m_po >= 4) s_tga[9] = "Will shoot the three";
	if(m_po >= 4) s_tga[10] = "Likes the three";
	if(m_po >= 4) s_tga[11] = "Has rare 3 point range for a big player";

	s_stl[0] = "Never gets steals";
	s_stl[1] = "Rarely gets steals";
	s_stl[2] = "Doesn't look to get steals";
	s_stl[3] = "Doesn't play the passing lanes well";
	s_stl[4] = "";
	s_stl[5] = "Will get you some steals";
	s_stl[6] = "Solid in the steals department";
	s_stl[7] = "A threat to force turnovers";
	s_stl[8] = "Disruptive force in the passing lanes";
	s_stl[9] = "Gets a ton of steals";
	s_stl[10] = "Forces an amazing amount of turnovers";
	s_stl[11] = "One of the best thieves on the planet";

	if(m_po >= 4)
	{
	s_stl[0] = "Never gets steals";
	s_stl[1] = "Rarely gets steals";
	s_stl[2] = "Doesn't play the passing lanes well";
	s_stl[3] = "";
	s_stl[4] = "";
	s_stl[5] = "";
	s_stl[6] = "Will get some steals";
	s_stl[7] = "Nice job forcing some turnovers";
	s_stl[8] = "Very quick hands for a big player";
	s_stl[9] = "Gets a lot steals despite playing " + pos;
	s_stl[10] = "Gets a ton of steals despite playing " + pos;
	s_stl[11] = "One of the best thieves ever at " + pos;
	}

	s_to[0] = "Never seems to turn it over";
	s_to[1] = "Rarely turns it over";
	s_to[2] = "Commits few mistakes with the ball";
	s_to[3] = "Nice job protecting the ball";
	s_to[4] = "Decent job avoiding turnovers ";
	s_to[5] = "";
	s_to[6] = "";
	s_to[7] = "Commits fair share of turnovers";
	s_to[8] = "Needs to protect the ball better";
	s_to[9] = "Commits a ton of turnovers";
	s_to[10] = "Constantly forces the action and makes some mistakes";
	s_to[11] = "The ball does not belong in these hands";

	if(m_po == 1)
	{
	s_blk[0] = "No shot blocking ability";
	s_blk[1] = "";
	s_blk[2] = "";
	s_blk[3] = "";
	s_blk[4] = "";
	s_blk[5] = "";
	s_blk[6] = "";
	s_blk[7] = "";
	s_blk[8] = "";
	s_blk[9] = "Can block a shot";
	s_blk[10] = "Causes problems with shot blocking from the PG position";
	s_blk[11] = "Shot blocking ability";
	}
	else if(m_po <= 3)
	{
	s_blk[0] = "No shot blocking ability";
	s_blk[1] = "";
	s_blk[2] = "";
	s_blk[3] = "";
	s_blk[4] = "";
	s_blk[6] = "Will block some shots";
	s_blk[7] = "Capable shot blocker";
	s_blk[8] = "Solid swatter";
	s_blk[9] = "Very good shot blocker for a wing player";
	s_blk[10] = "Disruptive shot blocking for a " + pos;
	s_blk[11] = "Blocks just about everything from the " + pos + " position";
	}
	else if(m_po == 4)
	{
	s_blk[0] = "No shot blocking ability";
	s_blk[1] = "Rarely blocks a shot";
	s_blk[2] = "Don't expect many rejections on defense";
	s_blk[3] = "Will block shots on occasion";
	s_blk[4] = "Mediocre shot blocker at best";
	s_blk[5] = "Will block shots";
	s_blk[6] = "Capable shot blocker";
	s_blk[7] = "Solid swatter";
	s_blk[8] = "Very good shot blocker";
	s_blk[9] = "Disruptive shot blocker";
	s_blk[10] = "Outstanding shot blocker";
	s_blk[11] = "Sensational shot blocker";
	}
	else
	{
	s_blk[0] = "No shot blocking ability";
	s_blk[1] = "Rarely blocks a shot";
	s_blk[2] = "Don't expect many rejections on defense";
	s_blk[3] = "Will block shots on occasion";
	s_blk[4] = "Mediocre shot blocker at best";
	s_blk[5] = "Will block shots";
	s_blk[6] = "Capable shot blocker";
	s_blk[7] = "Solid swatter";
	s_blk[8] = "Very good shot blocker";
	s_blk[9] = "Extremely disruptive shot blocker";
	s_blk[10] = "Blocks just about everything";
	s_blk[11] = "An all time shot blocker";
	}


	s_fgp[0] = "Useless";
	s_fgp[1] = "Gives you nothing";
	s_fgp[2] = "Not good";
	s_fgp[3] = "Struggles mightily";
	s_fgp[4] = "Struggles";
	s_fgp[5] = "Not a threat";
	s_fgp[6] = "Not much";
	s_fgp[7] = "Needs work";
	s_fgp[8] = "Average at best";
	s_fgp[9] = "Average";
	s_fgp[10] = "Not bad";
	s_fgp[11] = "Decent";
	s_fgp[12] = "Steady";
	s_fgp[13] = "Very steady";
	s_fgp[14] = "Strong";
	s_fgp[15] = "Very effective";
	s_fgp[16] = "Extremely effective";
	s_fgp[17] = "Gets its done";
	s_fgp[18] = "Very hard to handle";
	s_fgp[19] = "Nearly unstoppable";
	s_fgp[20] = "Automatic 2 points";

	
	s_ftp[1] = "Terrible free throw shooter";
	s_ftp[2] = "Not much of a free throw shooter";
	s_ftp[3] = "Tends to struggle from the line";
	s_ftp[4] = "Average from the free throw stripe";
	s_ftp[5] = "Pretty good from the foul line";
	s_ftp[6] = "Good foul shooter";
	s_ftp[7] = "Solid free throw shooter";
	s_ftp[8] = "Makes most free throws";
	s_ftp[9] = "Terrific from the line";
	s_ftp[10] = "Nearly automatic from the line";
	s_ftp[11] = "Makes every free throw";


	s_bh[1] = "Terrible ballhandler";
	s_bh[2] = "Poor ballhandler";
	s_bh[3] = "Struggles handling the ball";
	s_bh[4] = "Needs some work on the handle";
	s_bh[5] = "Pretty good ballhandler";
	s_bh[6] = "Does a nice job handling the ball";
	s_bh[7] = "Good ballhandler";
	s_bh[8] = "Very solid ballhandler";
	s_bh[9] = "Absolutely no problem handling the ball";
	s_bh[10] = "Dazzling ballhandler";
	s_bh[11] = "Handles the ball like its on a string";

	if(m_po >= 4)
	{
	s_bh[1] = "Should not be handling the ball";
	s_bh[2] = "Rarely handles the ball";
	s_bh[3] = "Struggles handling the ball";
	s_bh[4] = "Needs to work on basic ball handling";
	s_bh[5] = "OK handling the ball";
	s_bh[6] = "Does a nice job handling the ball";
	s_bh[7] = "Good ballhandler";
	s_bh[8] = "Solid with the ball";
	s_bh[9] = "No problem handling the ball";
	s_bh[10] = "Impressive handle for a big player";
	s_bh[11] = "Handles the ball like a guard";
	}

	s_def[0] = "";
	s_def[1] = "";
	s_def[2] = "";
	s_def[3] = "";
	s_def[4] = "Couldn't guard a shadow";
	s_def[5] = "Useless defender";
	s_def[6] = "Major defensive liabilty";
	s_def[7] = "Poor defensive player";
	s_def[8] = "Weak defender";
	s_def[9] = "Struggles defensively";
	s_def[10] = "Has troubles on defense";
	s_def[11] = "Needs to really improve defensively";
	s_def[12] = "Not a good defender";
	s_def[13]= "Need to get better on defense";
	s_def[14] = "Needs work on the defensive end";
	s_def[15] = "Struggles at times defensively";
	s_def[16] = "Needs some work on defense";
	s_def[17] = "Mediocre defender";
	s_def[18] = "Decent defender";
	s_def[19] = "Adequate defensive player";
	s_def[20] = "OK defensively";
	s_def[21] = "Good defensively";
	s_def[22] = "Quality defender";
	s_def[23] = "Solid defender";
	s_def[24] = "Very good defender";
	s_def[25] = "Excellent defensively";
	s_def[26] = "Stopper type defensively";
	s_def[27] = "Great defender";
	s_def[28] = "Complete defender";
	s_def[29] = "Superb defender";
	s_def[30] = "Does a great job defensively";
	s_def[31] = "Complete stopper on defense";
	s_def[32] = "Defensively one of the best";
	s_def[33] = "Outstanding defender";
	s_def[34] = "Sensational defender";
	s_def[35] = "Brilliant defensive player";
	s_def[36] = "Might be the best defender ever";


	s_fb[0] = "Disaster in the open court";
	s_fb[1] = "Can barely walk up the floor";
	s_fb[2] = "Can't run the floor";
	s_fb[3] = "Struggles mightily in transition";
	s_fb[4] = "Struggles on the break";
	s_fb[5] = "Not a threat running the floor";
	s_fb[6] = "";
	s_fb[7] = "";
	s_fb[8] = "";
	s_fb[9] = "";
	s_fb[10] = "";
	s_fb[11] = "";
	s_fb[12] = "";
	s_fb[13] = "";
	s_fb[14] = "Runs the floor well";
	s_fb[15] = "Very effective on the break";
	s_fb[16] = "Solid finisher in transition";
	s_fb[17] = "Terrific finisher on the break";
	s_fb[18] = "Nightmare to handle in transition";
	s_fb[19] = "Nearly unstoppable in an open court game";
	s_fb[20] = "Breath taking and spectacular in the open floor";

	if(m_po == 1)
	{
		s_fb[0] = "Disaster running the break";
		s_fb[1] = "Can't run the break";
		s_fb[2] = "Struggles to push the ball in transition";
		s_fb[5] = "Not a threat in open court";
		s_fb[14] = "Runs the break well";
		s_fb[15] = "Very effective on the break";
		s_fb[16] = "Solid job pushing the ball on the break";
		s_fb[17] = "Terrific creator on the break";
		s_fb[18] = "Nightmare to handle in transition";
		s_fb[19] = "Nearly unstoppable in an open court game";
		s_fb[20] = "Breath taking and creative in the open floor";
	}
	else if(m_po >= 4)
	{
		s_fb[13] = "Runs the floor";
		s_fb[14] = "Runs in transition very well";
		s_fb[15] = "Very effective on the break";
		s_fb[17] = "Terrific runner of the floor";
		s_fb[18] = "Nightmare to handle running the lanes";
		s_fb[19] = "Runs the floor like a guard";
		s_fb[20] = "Dominant force in transition";
	}

	s_tru[0] = "Should think about a career change";
	s_tru[1] = "Not even close to pro caliber";
	s_tru[2] = "Definitely not a pro player";
	s_tru[3] = "A long way from making a team";
	s_tru[4] = "Not much of a chance to stick on a team";
	s_tru[5] = "Could make a team";
	s_tru[6] = "End of the bench player";
	s_tru[7] = "Belongs in the league but not in your rotation";
	s_tru[8] = "Can give you some minutes off the bench";
	s_tru[9] = "Not a starter but a capable backup in the rotation";
	s_tru[10] = "Solid bench player who can provide quality minutes";
	s_tru[11] = "Borderline starter";
	s_tru[12] = "Could start on most teams";
	s_tru[13] = "Solid player and starter";
	s_tru[14] = "Solid player and an excellent starter";
	s_tru[15] = "Extremely solid player";
	s_tru[16] = "High quality player";
	s_tru[17] = "Excellent player";
	s_tru[18] = "Terrific player";
	s_tru[19] = "Borderline all star";
	s_tru[20] = "All star caliber player";
	s_tru[21] = "Legitimate all star";
	s_tru[22] = "One of the better players in the game";
	s_tru[23] = "One of the best players in the game";
	s_tru[24] = "Superstar type player";
	s_tru[25] = "Bonafide superstar";
	s_tru[26] = "One of the better players I've seen";
	s_tru[27] = "One of the best players ever";
	s_tru[28] = "One of the greats";

	s_pot[0] = "Should get a real job";
	s_pot[1] = "Is probably looking at a career change";
	s_pot[2] = "Will never be close to a pro caliber player";
	s_pot[3] = "Is never going to be a pro player";
	s_pot[4] = "Will probably never make a team";
	s_pot[5] = "Not much of a chance to ever stick in the league";
	s_pot[6] = "Could eventually make a team";
	s_pot[7] = "Should be able to stick in the league";
	s_pot[8] = "Could develop into an end of the bench player";
	s_pot[9] = "Could develop into a bench player";
	s_pot[10] = "Probably a career on the end of the bench";
	s_pot[11] = "Probably a long career on the end of the bench";
	s_pot[12] = "Could eventually give you spot minutes off the bench";
	s_pot[13] = "Has a chance to be in your rotation";
	s_pot[14] = "Has a chance to develop into an extremely capable player";
	s_pot[15] = "At worse expect a very solid career as a strong bench player";
	s_pot[16] = "Decent chance to start in the league for a long time";
	s_pot[17] = "Could become a highly dependable starter";
	s_pot[18] = "Will become a solid player and a definite starter";
	s_pot[19] = "Expect a very solid career as a legitimate starter";
	s_pot[20] = "Should develop into a high quality starter";
	s_pot[21] = "Should become a top end starter";
	s_pot[22] = "Could develop into a borderline all star";
	s_pot[23] = "Has a chance at an all star caliber career";
	s_pot[24] = "Will become an all star";
	s_pot[25] = "Should develop into one of league's best";
	s_pot[26] = "Chance at superstar status";
	s_pot[27] = "Superstar in the making";
	s_pot[28] = "Hall of Fame type potential";

	int po = m_po;
	if(po < 0) po = 0;
	if(GetPos() == "PG") po = 1;
	else if(GetPos() == "SG") po = 2;
	else if(GetPos() == "SF") po = 3;
	else if(GetPos() == "PF") po = 4;
	else if(GetPos() == " C") po = 5;



	

	double ast_i = (double)GetAdjPrAst()/(double)r_ast[po] ;	
	if(r_ast[po] > 50 &&  GetAdjPrAst() > r_ast[po])
		ast_i =  1 + double (GetAdjPrAst() + 2 - r_ast[po]) / (100 - r_ast[po]) * 1;
	int i = int(ast_i * 5);	
	if(i>10){ i = 11; }
	else if(i<0) i = 0;
	m_lines[10] = s_ast[i];
	if(po >= 3 && i>8) m_lines[10] = m_lines[10] + " at that position";
	if(po == 1 && i<=1) m_lines[10] = "Poor passer who is not a point guard";


	double fta_i = (double)GetAdjPrFta()/(double)r_fta[po];	
	if(r_fta[po] > 50 &&  GetAdjPrFta() > r_fta[po])
		fta_i =  1 + double (GetAdjPrFta() + 2 - r_fta[po]) / (100 - r_fta[po]) * 1;
	i = int(fta_i * 5);	

	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[6] = s_fta[i];
	if(i <= 2 && GetPostOff() >= 7 && GetPenOff() > 7)
		m_lines[6] = m_lines[6] + " despite being an excellent penetrator and post player";
	else if(i <= 2 && GetPostOff() >= 7 )
		m_lines[6] = m_lines[6] + " despite being a terrific post player";
	else if(i <= 2 && GetPenOff() > 7)
		m_lines[6] = m_lines[6] + " despite being an outstanding penetrator";

	double tga_d = (double)GetAdjPrTga()/(double)r_tga[po];	
	if(r_tga[po] > 50 &&  GetAdjPrTga() > r_tga[po])
		tga_d =  1 + double (GetAdjPrTga() + 2 - r_tga[po]) / (100 - r_tga[po]) * 1;
	i = int(tga_d*5 / 2);	
	if(i>5) i = 5;
	else if(i<0) i = 0;
	
	double tgm = double(GetTfgm());
	double tga = double(GetTfga());
	double tgp = tgm/tga*100;

	double f = (tgp / m_avg_tgp[po] * 20) - 15 / 2;//?
	if(f < 0) f = 0; else if(f > 5) f = 5;
	int n = int(f+i);
	m_lines[8] = s_tga[n];
	if(tgp < m_avg_tgp[po] && n >= 7 && m_lines[8] != "") m_lines[8] = m_lines[8] + " but tends to force them up";
	int tga_i = n;




	double orb_i = (double)GetAdjPrOrb()/(double)r_orb[po];	
	if(r_orb[po] > 50 &&  GetAdjPrOrb() > r_orb[po])
		orb_i =  1 + double (GetAdjPrOrb() + 2 - r_orb[po]) / (100 - r_orb[po]) * 1;
	i = int(orb_i * 5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[11] = s_orb[i];

	double drb_i = (double)GetAdjPrDrb()/(double)r_drb[po];	
	if(r_drb[po] > 50 &&  GetAdjPrDrb() > (double)r_drb[po])
		drb_i = 1 + double (GetAdjPrDrb() + 2 - r_drb[po]) / (100 - r_drb[po]) * 1;
	i = int(drb_i * 5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[12] = s_drb[i];

	double stl_i = (double)GetAdjPrStl()/(double)r_stl[po];	
	if(r_stl[po] > 50 &&  GetAdjPrStl() > r_stl[po])
		stl_i =  1 + double (GetAdjPrStl() + 2 - r_stl[po]) / (100 - r_stl[po]) * 1;
	i = int(stl_i * 5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[13] = s_stl[i];


	double blk_i = (double)GetAdjPrBlk()/(double)r_blk[po];	
	if(r_blk[po] > 50 &&  GetAdjPrBlk() > r_blk[po])
		blk_i =  1 + double (GetAdjPrBlk() + 2 - r_blk[po]) / (100 - r_blk[po]) * 1;
	i = int(blk_i * 5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[15] = s_blk[i];

	double fga_i = (double)GetAdjPrFga()/(double)r_fga[po];	
	if(r_fga[po] > 50 &&  GetAdjPrFga() > r_fga[po])
		fga_i =  1 + double (GetAdjPrFga() + 2 - r_fga[po]) / (100 - r_fga[po]) * 1;
	i = int(fga_i * 5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[1] = s_fga[i];


	
	
	double fgm = double(GetFgm()) - double(GetTfgm());
	double fga = double(GetFga()) - double(GetTfga());
	double fgp = fgm/fga*100;




	f = fgp / m_avg_fgp[po] * 20 - 15;
	
	double o = f + (double)GetMovOff() - 5;
	if(o < 0) o = 0; else if(o > 10) o = 10;

	i = int(o + fga_i * 5);	
	i = i + tga_i - 5;
	if(i>20) i = 20; else if(i < 0) i = 0;
	int score_o = i;
	m_lines[2] = s_fgp[i] + " outside";

	if(fga > m_avg_fga[po] && i<5) 
		m_lines[2] = m_lines[2] + " and needs to work on shot selection";



	double p = f + (double)GetPenOff() - 5;
	if(p < 0) p = 0; else if(p > 10) p = 10;

	i = int(p + fga_i * 5);	
	if(i>20) i = 20;
	else if(i<0) i = 0;

	int score_p = i;
	m_lines[4] = s_fgp[i] + " driving to the hoop";

	double io = f + (double)GetPostOff() - 5;
	if(io < 0) io = 0; else if(io > 10) io = 10;

	i = int(io + fga_i*5);	
	if(i>20) i = 20;
	else if(i<0) i = 0;
	int score_i = i;
	m_lines[3] = s_fgp[i] + " inside";
	if(po == 1 && i <= 10) m_lines[3] = "";


	double i_f = f + (double)GetTransOff() - 5;
	if(i_f < 0) i_f = 0; else if(i_f > 10) i_f = 10;

	i = int(i_f + fga_i*5);
	if(po == 1) i = i + int(ast_i*5) - 5;	
	if(i>20) i = 20; else if(i<0) i=0;
	int score_f = i;
	m_lines[5] = s_fb[i];
	




	int total_score = score_o + score_p + score_i;
	int defense = GetMovDef() + GetPenDef() + GetPostDef() + GetTransDef();

	m_lines[17] = s_def[defense];
	if(GetPenDef() >= 8)
		m_lines[18] = "Tough to beat off the dribble";
	else if(GetPenDef() <= 2 && po <= 3)
		m_lines[18] = "Gets beat off the dribble";
	if(GetPostDef() >= 8)
		m_lines[19] = "Outstanding low post defender";
	else if(GetPostDef() <=2  && po >= 4)
		m_lines[19] = "Weak low post defender";

	if(score_o <= 7  && score_p <= 7 && score_i <= 7)
	{
		m_lines[3] == "";
		m_lines[4] == "";
		if(total_score <= 7) m_lines[2] = "Basically an offensive liability";
		else if(total_score <= 14) m_lines[2] = "Don't expect any real offense";
		else m_lines[2] = "Struggles to score";
	}
	if(score_o >= 14  && score_p >= 14 && score_i >= 14)
	{
		m_lines[3] == "";
		m_lines[4] == "";
		if(total_score >= 42 && total_score <=47) m_lines[2] = "Versatile offensive player";
		else if(total_score >= 48 && total_score <= 53) m_lines[2] = "Complete offensive player";
		else m_lines[2] = "The total package offensively";
	}

	double ftm = double(GetFtm());
	double fta = double(GetFta());
	double ftp = ftm/fta*100;
	f = ftp / m_avg_ftp[po] * 20 - 15;
	if(f < 0) f = 0; else if(f > 11) f = 11;
	n = int(f);
	m_lines[7] = s_ftp[n];


	double ast = (double) GetAdjPrAst();	
	double to = 101 - (double) GetAdjPrTo();	
	double bh = ast / to;
	double a_ast = (double)r_ast[po];
	double a_to = 101 - (double)r_to[po];
	double a_bh = a_ast / a_to;
	i = int(  bh / a_bh * 2.5 + ast_i * 2.5);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[16] = s_bh[i];


	double  to_i =  (double)GetAdjPrTo()/(double)r_to[po];	
	double poss = (ast_i * 3 + fta_i + fga_i) / 4;
	if(r_to[po] > 50 &&  GetAdjPrTo() > r_to[po])
		to_i =  1 + double (GetAdjPrTo() + 2. - r_to[po]) / (100. - r_to[po]) * 1;
	i = 11 - int(to_i * 5 * poss);	
	if(i>10) i = 11;
	else if(i<0) i = 0;
	m_lines[14] = s_to[i];




	//double tru = GetTrueRating() * 3/2 + 10;//tru is > 0 for above average less then o for below
	//SetMinPerGame(m_games, m_min);
	double temp = GetTradeTrueRating(FALSE);
	double temp_tru = temp;
	double av = m_avg_trade_tru[po];
	if(temp <= av) temp = av - (av - temp) * 1/3; else temp = av + (temp - av) * 2/3;
	double tru_i = temp / av * 10;	
	int tru = int(tru_i);	
	if(tru>27) tru = 27; else if(tru<0) tru=0;
	m_lines[32] = s_tru[tru];
	if(m_name == "Bebita Ramos" || m_name == "Nancy Ramos")
		m_lines[32] = "One in a million, the total package";

 

	//SetMinPerGame(m_games, m_min);
	//SetTrueRating(0, FALSE);
	////m_trueRating
	//double temp = m_tradeTrueRating;
	//double av = 0;
	//double tru_i =     (temp  + av) ;	
	//int tru = int(tru_i);	
	//if(tru>27) tru = 27; else if(tru<0) tru=0;
	//m_lines[32] = s_tru[tru];
	//if(m_name == "Bebita Ramos")
	//	m_lines[32] = "One in a million, the total package";


//	double temp_career = GetTradeTrueRating(TRUE);
	int _tru = (int)GetTradeTrueRating(FALSE);
	//tru_i =     (m_trueRating) ;	
	int _pot = (int)SetTruePotential(tru_i);
	//int pot = int(tru_i * temp_career / temp_tru);
	//int pot = int(tru_i * temp_career / temp);
	if (_pot > 28)
	{
		_pot = 28;
	}
	else if (_pot < 0)
	{
		_pot = 0;
	}

	if ((_pot - _tru) > 5)
	{
		m_lines[0] = s_pot[_pot];
	}
	//m_lines[0] = s_pot[pot];


	}

void CPlayer::ListHighs(CString string[])
{


	string[0] = "points";
	string[1].Format(" %2d", m_hi_pts);
	string[2].Format(" %2d", m_hi_pts_po);
	string[3].Format(" %2d", m_hi_pts_car);
	string[4].Format(" %2d", m_hi_pts_car_po);

	string[5] = "rebounds";
	string[6].Format(" %2d", m_hi_reb);
	string[7].Format(" %2d", m_hi_reb_po);
	string[8].Format(" %2d", m_hi_reb_car);
	string[9].Format(" %2d", m_hi_reb_car_po);

	string[10] = "assists";
	string[11].Format(" %2d", m_hi_ast);
	string[12].Format(" %2d", m_hi_ast_po);
	string[13].Format(" %2d", m_hi_ast_car);
	string[14].Format(" %2d", m_hi_ast_car_po);


	string[15] = "steals";
	string[16].Format(" %2d", m_hi_stl);
	string[17].Format(" %2d", m_hi_stl_po);
	string[18].Format(" %2d", m_hi_stl_car);
	string[19].Format(" %2d", m_hi_stl_car_po);


	string[20] = "blocks";
	string[21].Format(" %2d", m_hi_blk);
	string[22].Format(" %2d", m_hi_blk_po);
	string[23].Format(" %2d", m_hi_blk_car);
	string[24].Format(" %2d", m_hi_blk_car_po);


	string[25] = "doubles";

	string[26].Format(" %2d", m_double);
	string[27].Format(" %2d", m_double_car);

	string[28] = "triples";

	string[29].Format(" %2d", m_triple);
	string[30].Format(" %2d", m_triple_car);


//	string[20] = "blk";

/* long int m_hi_pts_po;
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
	long int m_hi_blk_car_po;*/

	
}

void CPlayer::UpdateCareerStats()
{

	m_car_games = m_car_games + m_sim_games;
	m_car_min = m_car_min + m_sim_min;
	m_car_fgm = m_car_fgm + m_sim_fgm;
	m_car_fga = m_car_fga + m_sim_fga;
	m_car_ftm = m_car_ftm + m_sim_ftm;
	m_car_fta = m_car_fta + m_sim_fta;
	m_car_tfgm = m_car_tfgm + m_sim_tfgm;
	m_car_tfga = m_car_tfga + m_sim_tfga;
	m_car_oreb = m_car_oreb + m_sim_oreb;
	m_car_reb = m_car_reb + m_sim_reb;
	m_car_ast = m_car_ast + m_sim_ast;
	m_car_stl = m_car_stl + m_sim_stl;
	m_car_to = m_car_to + m_sim_to;
	m_car_blk = m_car_blk + m_sim_blk;
	m_car_pf = m_car_pf + m_sim_pf;

}

int CPlayer::SetExtensionRequests(int franchise_w, int franchise_l, double val[], double pos_value[], int coach_rating, bool extension, int games_season)
{

	int seeking = 0;
	int age = m_age;

//	double actual_value = m_tradeTrueRating;
	double sim_value = 0;
	double trade_value =  m_tradeTrueRating;
/*	if(m_sim_games > 0)
	{
		double ga_factor = (double)m_sim_games / (double)games_season; 
		if(ga_factor > .5) ga_factor = .5;
		double act_factor = 1 - ga_factor;
		sim_value = m_sim_trueRating / m_sim_games;
		trade_value = actual_value * act_factor + ga_factor * sim_value;
	}*/
	if(m_sim_games > 4)
	{
		sim_value = m_sim_trueRating / m_sim_games;
	}

	if(sim_value > trade_value) trade_value = sim_value;


	int service = m_yrs_of_service;
	//if(extension == true) service = service + 1;

//			if(m_yrs_on_team >= 2)
//				m_bird_player = true;			
			double money = trade_value * 100;
//			money = money * (.99 + (double)IntRandom(20)/100);
			money = money * ( 1.10 );
			if(money <  m_current_yr_salary) 
				money = m_current_yr_salary;
		
			bool max_raise = false;

			if(money > MAX10 && service >= 10)
			{
				money = MAX10;
				max_raise = true;
			}
			else if(money > MAX7 && service >= 7) 
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
			int y_s = service;
			if(y_s > 10) y_s = 10;
			if(money < m_minimum[y_s]) money = m_minimum[y_s];

			int contract_max =  5;
			//write some code based on age to set years wanted
			if(age > 28) contract_max = 35 - age;

			if(contract_max > 5) contract_max = 5;
			else if(contract_max < 2) contract_max = 2;
			
			if(money < ((double)m_contract_salaries[m_contract_yrs] * 1.1) && extension == false) money = (double) (double)m_contract_salaries[m_contract_yrs] * 1.1;
			int current_money = (int)money;
			m_qualifying_salaries[1] = current_money;


			//m_qualifying_salaries[1] = m_current_yr_salary;

			int total_salary = current_money;


			double d_mpy = (double)money / 100;
			int mpy = (int)d_mpy;
			int o_mpy = mpy + 1;
			mpy = mpy - 3 + m_security_factor;
			if(mpy < 1) mpy = 1;

			int contract_years = 1 + IntRandom(mpy);

			if(contract_years < 1) contract_years = 1;
			else if(contract_years > 5) contract_years = 5;

			if(contract_years > contract_max) contract_years = contract_max; 
			if(contract_years > o_mpy) contract_years = o_mpy; 

			if(contract_years != 1)//end of contract
			{
				double inc = double(current_money) * .125;				

				for(int j=2; j<=contract_years; j++)
				{
					double d_raise = 12.5;
					double money = double(current_money) + inc;
					current_money = (int)money;
					m_qualifying_salaries[j] = current_money;
					total_salary = total_salary + current_money;
				}
			
			}


			m_total_salary_seeking = total_salary;
			m_qualifying_offer_years = contract_years;
			money = total_salary / contract_years;

		//adjust for last seasons win pct not included
		
	
		double w_pct = 0;
		double salary_request = money;

		if(franchise_l == 0) w_pct = .5;
		else w_pct = (double)franchise_w / ((double)franchise_w + double(franchise_l));
		double win_factor =  (.5 - w_pct) * (double) m_tradition_factor / 10;
		double factor = 1 + win_factor;
		salary_request = salary_request * factor;

		factor = 1;
		int loyal = m_loyalty_factor;
		if(m_yrs_on_team < 3) loyal = loyal*2;//increase loyalty for player who needs bird rights
		double loy = (double)loyal*3 / 60; // 3/40 percent less for average loyal will be accepted
		factor =  1 - loy;
		salary_request = salary_request * factor;

		
//		int coach_rating1 = (coach.m_pot1Rating + coach.m_pot2Rating + coach.m_effortRating + coach.m_scoringRating + coach.m_shootingRating + coach.m_reboundingRating + coach.m_passingRating + coach.m_defenseRating)*1;
//		int coach_rating2 = (coach.m_coachPot1 + coach.m_coachPot2 + coach.m_coachEffort + coach.m_coachScoring + coach.m_coachShooting + coach.m_coachRebounding + coach.m_coachPassing + coach.m_coachDefense)*3;
//		int coach_rating3 = (coach.m_coachO + coach.m_coachP + coach.m_coachI + coach.m_coachF + coach.m_coachOD + coach.m_coachPD + coach.m_coachID + coach.m_coachFD)*3;
//		int coach_rating4 = (coach.m_personality)*24;
//		int r = coach_rating1 + coach_rating2 + coach_rating3 + coach_rating4;
		factor = (200 - (99 + (double)coach_rating/200)) / 100;
		salary_request = salary_request * factor;

		
		double pv_factor = 1;//playing time 
		
		if(m_pos == "PG" && val[1] > 0 && pos_value[1] > val[1]) 
			pv_factor = pos_value[1]  / val[1];
		else if(m_pos == "PG" && pos_value[1] > 0 && pos_value[1] <= val[1]) 
			pv_factor = - val[1] / pos_value[1];
		else if(m_pos == "SG" && val[2] > 0 && pos_value[2] > val[2]) 
			pv_factor = pos_value[2]  / val[2];
		else if(m_pos == "SG" && pos_value[2] > 0 && pos_value[2] <= val[2]) 
			pv_factor = - val[2] / pos_value[2];
		else if(m_pos == "SF" && val[3] > 0 && pos_value[3] > val[3]) 
			pv_factor = pos_value[3]  / val[3];
		else if(m_pos == "SF" && pos_value[3] > 0 && pos_value[3] <= val[3]) 
			pv_factor = - val[3] / pos_value[3];
		else if(m_pos == "PF" && val[4] > 0 && pos_value[4] > val[4]) 
			pv_factor = pos_value[4]  / val[4];
		else if(m_pos == "PF" && pos_value[4] > 0 && pos_value[4] <= val[4]) 
			pv_factor = - val[4] / pos_value[4];
		else if(m_pos == " C" && val[5] > 0 && pos_value[5] > val[5]) 
			pv_factor = pos_value[5]  / val[5];
		else if(m_pos == " C" && pos_value[5] > 0 && pos_value[5] <= val[5]) 
			pv_factor = - val[5] / pos_value[5];

		
		if(pv_factor > 4) pv_factor = 4;
		else if(pv_factor < -4) pv_factor = -4;

//		pv_factor = (100 + pv_factor * m_playing_time_factor) / 100;
		pv_factor = (94 + (double)m_playing_time_factor * 2) / 100 * (1+pv_factor/10);

		salary_request = salary_request * pv_factor;		


//		if(m_bird_player == true) salary_request = salary_request * 9 / 10;

		salary_request = salary_request * .99;


		seeking = (int) salary_request;
		return seeking;

	
}

bool CPlayer::AcceptContract(int seeking_factor, int year_offer, int total_salary_offer, double &quality_of_offer)//contract extension offers
{
		bool accept = false;
		double requested_salary_avg =  (double) m_total_salary_seeking / (double) m_qualifying_offer_years;


		int bottom = year_offer;



		double offered_salary_avg = (double) total_salary_offer / (double) bottom;

		double max_years = 0;
		double tr = 1;

		double value = requested_salary_avg * (.7 + (6 - (double)m_security_factor)/10);
		tr = offered_salary_avg / value;

		max_years = 6*tr;
		int i_max_years = (int)max_years;
		double rem = max_years - (double)i_max_years;
		if(rem >= .5)  i_max_years = i_max_years + 1;
		
		if(i_max_years < 1) i_max_years = 1;
		double diff = 0;
		if(bottom <= i_max_years)
		{


			double sec_factor = (100 + ((double)m_security_factor * (double) bottom) / 2) / 100;//security importance
			diff = offered_salary_avg * sec_factor / requested_salary_avg; 

			if(diff > 1)
			{
				accept = true;
			}		

			quality_of_offer = diff;

		}

		if(m_stop_negotiating >= 3 && diff < 2) accept = false;

	return accept;
}

void CPlayer::RankFavorites(int *fav, int teams)
{
	bool used[33];
	for(int i=0; i<=32; i++)
	{
		used[i] = false;

	}


	for(int r=teams; r>=1; r--)
	{

		int hi = 0;
		int best = -1;

		for(int i=0; i<teams; i++)
		{	
			if(m_seeking[i] >= hi && used[i+1] == false)
			{
				best = i+1;
				hi = m_seeking[i];
			}
		}

		fav[r] = best;
		used[best] = true;

	}



}

bool CPlayer::AcceptComputerExtension(int seeking_factor, int year_offer, int total_salary_offer)//contract extension offers
{

	


		bool accept = false;
		double requested_salary_avg =  (double) m_total_salary_seeking / (double) m_qualifying_offer_years;

		int bottom = year_offer;

		double offered_salary_avg = (double) total_salary_offer / (double) bottom;

		double max_years = 0;
		double tr = 1;

		double value = requested_salary_avg * (.7 + (6 - (double)m_security_factor)/10);
		tr = offered_salary_avg / value;

		max_years = 6*tr;
		int i_max_years = (int)max_years;
		double rem = max_years - (double)i_max_years;
		if(rem >= .5)  i_max_years = i_max_years + 1;
		
		if(i_max_years < 1) i_max_years = 1;
		double diff = 0;
		if(bottom <= i_max_years)
		{


			double sec_factor = (100 + ((double)m_security_factor * (double) bottom) / 2) / 100;//security importance
			diff = offered_salary_avg * sec_factor / requested_salary_avg; 

			if(diff > 1)
			{
				accept = true;
			}		


		}


		double q=diff; //quality



		if(m_stop_negotiating >= 3 && diff < 2) accept = false;




			if(accept == true)
			{
				int n = IntRandom(6);
				if(n <= m_effort)
				{
					if(m_loyalty_factor < 5)
						m_loyalty_factor = m_loyalty_factor + 1;
					if(Random(3) < (q*2))
					{
						if(m_content <  9)
							m_content = m_content + 1;
					}
				}

			

			}
			else 
			{
				int n = IntRandom(10);
				int ne = 6-m_effort;
				if(n <= ne)
				{
					if(m_loyalty_factor > 1)
						m_loyalty_factor = m_loyalty_factor - 1;
					if(Random(2) > (q*2))
					{
						if(m_content >  1)
							m_content = m_content -1;
					}
				}
				

				double r=Random(2.6 - (double)m_loyalty_factor * 2 / 10);
				if(r > q) m_stop_negotiating = m_stop_negotiating + 1;

				
			}

	return accept;
}

void CPlayer::GenerateRandomHeightWeight(bool rookie)
{
	
	int h[] = {0,73,77,78,79,81};
	int w[] = {0,180,190,195,225,235};
		int r = m_movoff + m_movdef + m_penoff + m_pendef		
			+ m_postoff + m_postdef + m_transoff + m_transdef;		


		double fa1 = 20;
		double fa2 = 40;

		if(m_pos == " C") {fa1 = 12; fa2 = 30;}
		else if(m_pos == "PF") {fa1 = 12; fa2 = 30;}
		else if(m_pos == "SF") {fa1 = 18; fa2 = 36;}

		double fh = double(m_postoff + m_postdef) / (double)r * fa1;

		double fw1 = double(m_postoff + m_postdef) / (double)r * fa2;
		double fw2 = fw1 + double((10-m_transoff) + (10-m_transdef)) / (double)r * fa2;

		int init_h = 0, init_w = 0;

		if(m_pos == "PG") {init_h = h[1]; init_w = w[1];}
		else if(m_pos == "SG") {init_h = h[2]; init_w = w[2];}
		else if(m_pos == "SF") {init_h = h[3]; init_w = w[3];}
		else if(m_pos == "PF") {init_h = h[4]; init_w = w[4];}
		else if(m_pos == " C") {init_h = h[5]; init_w = w[5];}

		double height = (double)init_h + Random(fh);
		double weight = (double)init_w + Random(fw1 + fw2);
		m_height = int(height);
		m_weight = int(weight);


		double n = 0;
		double r1 = ((double)m_postoff + (double)m_postdef) / 100;
		if(r1 > .18) r1 = .18;

		do
		{
			n = Random(1);
			if(n > (.78 + r1))
				m_height = m_height - 1;
		}
		while (n > (.78 + r1));

		do
		{
			n = Random(1);
			if(n < r1)
				m_height = m_height + 1;
		}
		while (n < r1);

		do
		{
			n = Random(1);
			if(n > (.78 + r1))
				m_weight = m_weight - 5;
		}
		while (n > (.78 + r1));

		do
		{
			n = Random(1);
			if(n < r1)
				m_weight = m_weight + 5;
		}
		while (n < r1);



		if(m_age < 28)
			m_weight = m_weight - IntRandom(28-m_age);
		else
			m_weight = m_weight + IntRandom(m_age-28);

}

void CPlayer::SetOldRatings()
{
		m_oldmovoff = m_movoff;
		m_oldmovdef = m_movdef;
		m_oldpenoff = m_penoff;
		m_oldpendef = m_pendef;
		m_oldpostoff = m_postoff;
		m_oldpostdef = m_postdef;
		m_oldtransoff = m_transoff;
		m_oldtransdef = m_transdef;
		m_oldprFga = m_prFga;
		m_oldprFgp = m_prFgp;
		m_oldprFta = m_prFta;
		m_oldprFtp = m_prFtp;
		m_oldprTga = m_prTga;
		m_oldprTgp = m_prTgp;
		m_oldprOrb = m_prOrb;
		m_oldprDrb = m_prDrb;
		m_oldprAst = m_prAst;
		m_oldprStl = m_prStl;
		m_oldprTo = m_prTo;
		m_oldprBlk = m_prBlk;

}

bool CPlayer::HallofFamer(int awa_pts, int major_points)
{
	bool hof = false;

	if(m_car_games > 0)
	{

	int pts = m_car_fgm * 2 + m_car_tfgm * 3 + m_car_ftm;
	int reb = m_car_oreb + m_car_reb;

	double ppg = (double)pts / (double) m_car_games;
	double rpg = (double)reb / (double) m_car_games;
	double apg = (double)m_car_ast / (double) m_car_games;
	double spg = (double)m_car_stl / (double) m_car_games;
	double bpg = (double)m_car_blk / (double) m_car_games;

	double total_pts = (ppg+rpg+apg+spg+bpg)*5 + (double)awa_pts;
	double stats_pts = (ppg+rpg+apg+spg+bpg)*5;

	if(total_pts >= 200 && m_yrs_of_service >= 7 && major_points >= 20) hof = true;
	else if (stats_pts >= 180 && m_yrs_of_service >= 13) hof = true;
	else if (stats_pts >= 160 && m_yrs_of_service >= 10 && major_points > 0 && awa_pts > 0) hof = true;
	else if (stats_pts >= 150 && total_pts >= 180 && m_yrs_of_service >= 7 && major_points >= 20) hof = true;
	else if(awa_pts > 120 && major_points >= 20) hof = true;
	}
	return hof;

}

int CPlayer::GetAwardPoints(CString file_name, int &major_points)
{
	int awa_pts = 0;
	CString awards[512];

	CFile file(	file_name, CFile::modeRead);	
	CString buffer;
	char s[33];

	int count = 0;
	int id = GetID();
 	
	int seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);

	CString place[6] = {"", "1st", "2nd", "3rd", "4th", "5th"};

	for(int y=0; y<=20; y++)
	{

		int mvp_seek = 2000 + id*500 + 680 + (y*15);
		file.Seek( mvp_seek, CFile::begin);
 		int bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int mvp = atoi(s);
		if(mvp > 0 && mvp <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d most valuable player (%s)", yr, place[mvp]);
//			string.Format("%d mvp  %d", yr, mvp);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (6-mvp)*3;
			if(mvp == 1) major_points = major_points + 10;
		}

		int defense_seek = 2000 + id*500 + 681 + (y*15);
		file.Seek( defense_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int defense = atoi(s);
		if(defense > 0 && defense <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d defensive player of the year  (%s)", yr, place[defense]);
//			string.Format("%d defense - %d", yr, defense);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (8-defense);
			major_points = major_points + (6-defense)*1;
			if(defense == 1) major_points = major_points + 5;

		}

		int rookie_seek = 2000 + id*500 + 682 + (y*15);
		file.Seek( rookie_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int rookie = atoi(s);
		if(rookie > 0 && rookie <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d rookie - %d", yr, rookie);
			string.Format("%d rookie of the year (%s)", yr, place[rookie]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 3;
		}

		int pts_seek = 2000 + id*500 + 683 + (y*15);
		file.Seek( pts_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int pts = atoi(s);
		if(pts > 0 && pts <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d scoring (%s)", yr, place[pts]);
//			string.Format("%d pts - %d", yr, pts);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (8-pts);

		}

		int reb_seek = 2000 + id*500 + 684 + (y*15);
		file.Seek( reb_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int reb = atoi(s);
		if(reb > 0 && reb <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d reb - %d", yr, reb);
			string.Format("%d rebounds (%s)", yr, place[reb]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (7-reb);
		}

		int ast_seek = 2000 + id*500 + 685 + (y*15);
		file.Seek( ast_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ast = atoi(s);
		if(ast > 0 && ast <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d ast - %d", yr, ast);
			string.Format("%d assists (%s)", yr, place[ast]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (7-ast);

		}

		int stl_seek = 2000 + id*500 + 686 + (y*15);
		file.Seek( stl_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int stl = atoi(s);
		if(stl > 0 && stl <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d stl - %d", yr, stl);
			string.Format("%d steals (%s)", yr, place[stl]);
			awards[count] = string;
			awa_pts = awa_pts + (7-stl);
			count = count + 1;
		}

		int blk_seek = 2000 + id*500 + 687 + (y*15);
		file.Seek( blk_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int blk = atoi(s);
		if(blk > 0 && blk <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d blk - %d", yr, blk);
			string.Format("%d blocks (%s)", yr, place[blk]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (7-blk);
		}

		int ring_seek = 2000 + id*500 + 688 + (y*15);
		file.Seek( ring_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ring = atoi(s);
		if(ring > 0)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d championship", yr);
//			string.Format("%d mvp (%s)", yr, place[mvp]);

			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 5;
		}

		int po_mvp_seek = 2000 + id*500 + 689 + (y*15);
		file.Seek( po_mvp_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int po_mvp = atoi(s);
		if(po_mvp > 0 )
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d playoff mvp", yr);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 10;
		}

		int sth_seek = 2000 + id*500 + 690 + (y*15);
		file.Seek( sth_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int sth = atoi(s);
		if(sth > 0 && sth <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d 6th - %d", yr, sth);
			string.Format("%d 6th man (%s)", yr, place[sth]);
			awa_pts = awa_pts + 3;
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 1;
		}

		int seek = 2000 + id*500 + 691 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all league - %d", yr, all);
			string.Format("%d all league %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (7-all);
			if(all == 1) major_points = major_points + 5;
		}

		seek = 2000 + id*500 + 692 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all defense - %d", yr, all);
			string.Format("%d all defense %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + (6-all);
		}

		seek = 2000 + id*500 + 693 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all rookie - %d", yr, all);
			string.Format("%d all rookie %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}



	long int asw_seek = 2000 + id*500 + 694 + (y*15);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star", yr);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 3;
			major_points = major_points + 5;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star mvp", yr);
			awards[count] = string;
			count = count + 1;
			awa_pts = awa_pts + 4;

		}


		asw_seek = 2000 + id*500 + 995 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game mvp", yr);
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 996 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest champ", yr);
			awa_pts = awa_pts + 1;
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 997 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest champ", yr);
			awards[count] = string;
			awa_pts = awa_pts + 1;
			count = count + 1;
		}


	}
	return awa_pts;
}


bool CPlayer::Disabled(int ga)
{
	bool inj = false;
	if(ga > 99) ga = 99;
	if(ga > 5)
	{
		double g = (double) ga / 100;
		double f = g * g ;
		if(Random(1) <= f)//permanent injury!!!
		{
			inj = true;
			double eff = g *.2;
			double tMin = 1. - Random(eff);
			int games = m_games;
			int	fgm = int((double)GetFgm()*tMin * .98);
			int fga = int((double)GetFga()*tMin);
			int ftm = int((double)GetFtm()*tMin * .98);
			int fta = int((double)GetFta()*tMin);
			int tfgm = int((double)GetTfgm()*tMin * .98);
			int tfga = int((double)GetTfga()*tMin);
			int oreb = int((double)GetOreb()*tMin);
			int reb = int((double)GetReb()*tMin);
			int ast = int((double)GetAst()*tMin);
			int stl = int((double)GetStl()*tMin);
			int to = int((double)GetTo()*tMin);
			int blk = int((double)GetBlk()*tMin);
			int pf = int((double)GetPf()*tMin);
			SetFgm(fgm);
			SetFga(fga);
			SetFtm(ftm);
			SetFta(fta);
			SetTfgm(tfgm);
			SetTfga(tfga);
			SetOreb(oreb);
			SetReb(reb);
			SetAst(ast);
			SetStl(stl);
			SetTo(to);
			SetBlk(blk);
			SetPf(pf);
			if(Random(1) > tMin && m_movoff > 1) m_movoff = m_movoff - 1;
			if(Random(1) > tMin && m_penoff > 1) m_penoff = m_penoff - 1;
			if(Random(1) > tMin && m_postoff > 1) m_postoff = m_postoff - 1;
			if(Random(1) > tMin && m_transoff > 1) m_transoff = m_transoff - 1;
			if(Random(1) > tMin && m_movdef > 1) m_movdef = m_movdef - 1;
			if(Random(1) > tMin && m_pendef > 1) m_pendef = m_pendef - 1;
			if(Random(1) > tMin && m_postdef > 1) m_postdef = m_postdef - 1;
			if(Random(1) > tMin && m_transdef > 1) m_transdef = m_transdef - 1;


		}
	}

	return inj;
}

int CPlayer::OffSeasonInjury(int stage, int &days)
{
	int inj = 0;
	bool hurt = false;
	int f = 11667;
	if(stage > 0) f = 5833;
	int ch = IntRandom(f);
	if(ch <= m_injuryRating) hurt = true;

	if(hurt==true)
	{
			double adjInjury = sqrt(double(m_injuryRating));

			double factor1 = adjInjury * 2/9; 
			double factor2 = factor1 + adjInjury * 2/9 * 2/3; 
			double factor3 = factor2 + adjInjury * 2/9 * 2/3 * 2/6; 
			double factor4 = factor3 + adjInjury * 2/9 * 2/3 * 2/9 * 2/6; 

			double i = Random(adjInjury);
			if(i <= factor1)
				i = i*3;
			else if(i <= factor2)
				i = i*9;
			else if(i <= factor3)
				i = i*27;
			else if(i <= factor4)
				i = i*81;
			int g = int(i) + 1;

			if(g<1) g=1; else if(g>160) g=160;
			m_injury = int((double)g * 2.25  - Random(1));
			days = m_injury;
			inj = g;
	}
	return inj;
}

void CPlayer::SetAswScores()
{
		
		double n1 = (double)(m_sim_tfgm);
		double n2 = 0;
		if(n1 > 0)
			n2 = n1 / (double)(m_sim_tfga);
		n1 = n1*n2* (1+ (double)m_prTga/100);
		m_3ptscore[0] = int(n1*100);


		n1 = (double)(m_prFta) / (double)(m_prFga);
		double bonus = 1;
		if(m_pos == "SG" || m_pos == "SF") bonus = 1.2;
		else if(m_pos == "PF" || m_pos == " C") bonus = .8;
		n1 = n1 + (double)(m_prOrb) / (double)(m_prDrb) + ((double)(m_transoff) + (double)m_transdef)/10.;
		n2 = (double)(m_prFta) / (double)(m_prFga);
		n2 = n2 + (double)(m_prOrb) / (double)(m_prDrb) + ((double)(m_transoff) + (double)m_transdef)/10.;
		m_dunkscore[0] = int(n2*100 * bonus) ;
	
		if(m_injury > 0 || m_sim_games == 0 || m_active == 0 || m_min < 72) 
		{
			m_3ptscore[0] = -1;
			m_dunkscore[0] = -1;
		}
}

bool CPlayer::TestingMarket(bool signed_extension)
{
	bool test = false;

	double actual_value = m_tradeTrueRating;
	double sim_value = 0;
	double trade_value = actual_value;
	if(m_sim_games > 4)
	{
		sim_value = m_sim_trueRating / m_sim_games;
	}

	if(sim_value > trade_value) trade_value = sim_value;
	if(trade_value  >  14.88) trade_value = 14.88;
	double f = 15 * (1 + signed_extension);
	if( (trade_value - (double) m_loyalty_factor) >= Random(f))  test = true;
	return test;
}
