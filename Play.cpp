#include "stdafx.h"
#ifndef Play_h
#include "Play.h"
#define Play_h
#endif 
#include <time.h>

CPlay::CPlay()
{
	m_quarter_ended = false;
	m_1stPossesion = 1;
	m_visitorIndex = 0;
	m_homeIndex = 0;
	m_lines = 0;
	m_defAdj = 0;
	m_time = 720;
    m_quarter = 1;
	m_possesion = 0;
	m_ballHandler = 0;
	m_avg_time = 0;
	m_toVisitor = 7;
	m_toHome = 7;
	m_toVisitor20 = 1;
	m_toHome20 = 1;
	m_visitorTo = false;
	m_homeTo = false;
	m_visitorTo20 = false;
	m_homeTo20 = false;
	m_toCalled = false;
	m_toOk = true;
	for(int i=0; i<=10; i++)
	{
		m_match[i] = 0;
	}

	for( i=0; i<=2; i++)
	{
		for(int j=0; j<=5; j++)
		{
			m_quarter_score[i][j] = 0;
		}
	}

	m_game_started = false;


	PlayerArray = new CPlayer[31];
	PlayerRatings = new CPlayerRatings[31];
	TeamRatings = new CTeamRatings[3];
	PlayerStats = new CPlayerStats[31];
	m_scout = new CStaff[101]; 
	m_gm = new CStaff[101]; 
	m_coach = new CStaff[101]; 


}
CPlay::~CPlay()
{

	delete [] PlayerArray;
	delete [] PlayerRatings;
	delete [] TeamRatings;
	delete [] PlayerStats;
	delete [] m_scout;
	delete [] m_gm;
	delete [] m_coach;
}

int CPlay::IntRandom(int n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return (int)number + 1;
}

double CPlay::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}


int CPlay::JumpBall()
{
	return CPlay::IntRandom(2);
}


int CPlay::BallHandler(int ballHandler, int m_possesion, int Lineup[3][6], BOOL m_homeCourt, bool &shotOk, int typeShot, bool &forced3)
{
	CPlayer m_playerRatings;
	double Touches[6];
	Touches[0] = 0;

	if(typeShot == 5 && ballHandler == 0)//Auto3
	{
	double n1 = TeamRatings[m_possesion].GetGameCoachTfgaPer48Min();
	
	double n2 = TeamRatings[m_possesion].GetGameFgaPer48Min()+
		TeamRatings[m_possesion].GetGameTfgaPer48Min()+
		TeamRatings[m_possesion].GetGameToPer48Min()+
		TeamRatings[m_possesion].GetGameFoulsDrawnPer48Min();
	
	double number = CPlay::Random(n2);
	forced3 = (number <= n1);
	}




	for(int i = 1; i <= 5; i++)
	{
		int player = Lineup[m_possesion][i];
		m_playerRatings = avg.m_actual[player];
		double FoulsDrawn = m_playerRatings.GetGameAdjustedFoulsDrawnPer48Min();
		double To = m_playerRatings.GetGameAdjustedToPer48Min();
		if(m_homeCourt == TRUE)
			FoulsDrawn = FoulsDrawn + double(m_possesion * 2 - 3) * .3;
		if(m_homeCourt == TRUE)
			To = To - double(m_possesion * 2 - 3) * .3;

		double factor = m_playerRatings.GetGameAdjustedTfgaPer48Min()/m_playerRatings.GetGameAdjustedFgaPer48Min()*1;
		if(forced3 == true)//THREE AUTO
			Touches[i] = Touches[i-1] + m_playerRatings.GetGameAdjustedTfgaPer48Min() + To*factor;
		else
			Touches[i] = Touches[i-1] +
			m_playerRatings.GetGameAdjustedFgaPer48Min() + 
			m_playerRatings.GetGameAdjustedTfgaPer48Min() +
			FoulsDrawn + To;
	}

	int ineligible = 0;//save position number in case player refuses to "shoot" he cant

	if(forced3 == true) TeamRatings[m_possesion].ReduceGameCoachTfgaPer48Min(2);
	if(ballHandler > 0)
	{
		int player = ballHandler;
		double n = avg.m_actual[player].GetGameCoachFgaPer48Min();
		double temp = (avg.m_actual[player].GetGameAdjustedFgaPer48Min() + avg.m_actual[player].GetGameAdjustedTfgaPer48Min() + 
			avg.m_actual[player].GetGameAdjustedFoulsDrawnPer48Min() + avg.m_actual[player].GetGameAdjustedToPer48Min()) * 3;

		if(typeShot == 5)
		{
			double To = m_playerRatings.GetGameAdjustedToPer48Min();
			if(m_homeCourt == TRUE)	To = To - double(m_possesion * 2 - 3) * .3;
			n = avg.m_actual[player].GetGameCoachTfgaPer48Min();
			temp = avg.m_actual[player].GetGameTfgaPer48Min()*4;
			avg.m_actual[player].ReduceGameCoachTfgaPer48Min(1);
		}

		if(m_visitorTo == true)// after to better chance for called shot
		{		
			n = n * 3;
			m_visitorTo = false;
		}
		else if(m_visitorTo20 == true)
		{
			n = n * 2;
			m_visitorTo20 = false;
		}
		else if(m_homeTo == true)
		{
			n = n * 3;
			m_homeTo = false;
		}
		else if(m_visitorTo20 == true)
		{
			n = n * 2;
			m_homeTo20 = false;
		}
		int team_index = GetTeamWithBall();

		double f = 0;
		double auto_type = 0;
		if(typeShot == 6) auto_type = IntRandom(3);
		if(typeShot == 1 || auto_type == 1)
		    f = (double(avg.m_coach[team_index].m_coachO) - 3) / 100;
		else if(typeShot == 2 || auto_type == 2)
		    f = (double(avg.m_coach[team_index].m_coachP) - 3) / 100;
		else if(typeShot == 3 || auto_type == 3)
		    f = (double(avg.m_coach[team_index].m_coachI) - 3) / 100;

		n = n * (1 + f*10);
		if(n > temp) n = temp;//n after to can be no higher than original coach fga
     


		double number = Random(Touches[5]);
		if(number > n)
		{
			if(typeShot != 5) ineligible = ballHandler;
			ballHandler = 0;
			shotOk = false;
		} 
		else shotOk = true;
		PlayerRatings[player].ReduceCoachFgaPer48Min();
	}

//	int position = CPlay::IntRandom(5);
	do
	{
	double number = CPlay::Random(Touches[5]);
	for(i = 1; i <= 5; i++)
	{
		if(number <= Touches[i] && number > Touches[i-1] && 
			ballHandler == 0 && i!= ineligible) ballHandler = i;
	}
	} while(ballHandler == 0);
	return ballHandler;
}

int CPlay::Result(int player, bool PutBack,
				  int Lineup[3][6], BOOL m_homeCourt, double avgStl, double avgTo,
				  double better, int typeShot, bool forced3, double avg_pf)
{
	CPlayerRatings m_playerRatings;
	double Touches;
	int result = 0;
	int team = 1, team_index = m_visitorIndex;
	if(player > 15) {team = 2; team_index = m_homeIndex;}
	m_playerRatings = PlayerRatings[player];
	double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
	if(fatigueFactor > 1) fatigueFactor = 1;
	double playerTo = m_playerRatings.GetAdjustedToPer48Min()*(2-fatigueFactor);

	double lineupStl = CurrentLineupSteals(player, Lineup, avgStl);
	double lineupTo
		= CurrentLineupTurnovers(player, Lineup, m_homeCourt);

	double fo_dr = 0;
	for(int i = 1; i <= 5; i++)
	{
		int plyr = Lineup[team][i];
		fo_dr = fo_dr + PlayerRatings[plyr].GetAdjustedFoulsDrawnPer48Min(); 
	}
	double fds = m_playerRatings.GetAdjustedFoulsDrawnPer48Min();
 
	if(fo_dr > avg_pf*4./3.)
	{
		fds = fds * ((avg_pf) / fo_dr);
	}

	double FoulsDrawn = fds * fatigueFactor;
	if(m_homeCourt == TRUE)
		FoulsDrawn = FoulsDrawn + double(team * 2 - 3) * .3;
	if(m_homeCourt == TRUE)
		playerTo = playerTo - double(team * 2 - 3) * .3;
	//adjust Turnovers based on opponents steals
	playerTo = 
		playerTo + playerTo / lineupTo * (lineupStl - avgStl*5/6); // avg steals per game 
	playerTo = playerTo - better/4/(avgTo/5)*playerTo;

  	FoulsDrawn = FoulsDrawn + better/4;
	if(FoulsDrawn <= 0) FoulsDrawn = Random(.030);
	if(playerTo <= 0) playerTo = Random(.60);
	if(forced3 == true)
	{
		double factor = m_playerRatings.GetAdjustedTfgaPer48Min()/m_playerRatings.GetAdjustedFgaPer48Min()*1.;
		playerTo = playerTo*factor;
	}
	Touches =
		m_playerRatings.GetAdjustedFgaPer48Min() + 
		m_playerRatings.GetAdjustedTfgaPer48Min() +
		FoulsDrawn + playerTo; 
	

	do
	{
	double number = CPlay::Random(Touches);
	result = CPlay::IntRandom(5);
	double limit1, limit2;
	limit1 = m_playerRatings.GetAdjustedFgaPer48Min();
	limit2 = limit1 + m_playerRatings.GetAdjustedTfgaPer48Min();
	if(number <= limit1) result = 1;
	if(number <= limit2 && number > limit1) result = 2;
	limit1 = limit2;
	limit2 = limit1 + FoulsDrawn;
	if(number <= limit2 && number > limit1) result = 3;
	limit1 = limit2;
	limit2 = limit1 + playerTo;
	if(number <= limit2 && number > limit1) result = 4;
	}
	while ( (PutBack == TRUE && (result == 2 || result == 4))
		|| (typeShot == 5 && result == 2) 
		|| (forced3 == true && result != 2 && result != 4));
	
	int number = CPlay::IntRandom(1025);//683
	int injury = m_playerRatings.GetInjuryRating();
	double adjInjury = sqrt(double(injury));
	if(number <= adjInjury && PutBack == FALSE) result = 5;
	return result;
}

bool CPlay::FieldGoalAttempt(int FgPct, int Fga, int player,
							 bool m_numbers[31][100])
{
	int i,n;
	double temp;
	bool OK = false;

	int team_index = m_visitorIndex;
	if(player > 15) team_index = m_homeIndex;
	
	double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
	if(fatigueFactor > 1) fatigueFactor = 1;

	int cons = 4 - (PlayerArray[player].GetConsistency() - 1);
	int factor = Fga*(cons/2)-1;
	if(factor<3) factor = 3;
	double cells = 1000/double(factor+1);
	for(int j=0; j<=factor; j++)
	{
		if(m_numbers[player][j] == false) OK = true;
	}
	if(OK == false)
	{
		for(j=0; j<=factor; j++)
		{
			m_numbers[player][j] = false;
		}
	}
	do
	{
		i = CPlay::IntRandom(1000);
		temp = (i-1)/cells;
		n = int(temp);
	} while(m_numbers[player][n] == true);
	m_numbers[player][n] = true;
	if (i <= (FgPct*fatigueFactor))
		return TRUE;
	else
		return FALSE;
}

bool CPlay::ThreePtFieldGoalAttempt(int TfgPct, int player)//not used
{
	int i = CPlay::IntRandom(1000);

	int team_index = m_visitorIndex;
	if(player > 15) team_index = m_homeIndex;
	
	double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

	if(fatigueFactor > 1) fatigueFactor = 1;
	if (i <= (TfgPct*fatigueFactor))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool CPlay::FreeThrowAttempt(int FtPct, int player)
{
	int i = CPlay::IntRandom(1000);

	int team_index = m_visitorIndex;
	if(player > 15) team_index = m_homeIndex;
	
	double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
	if(fatigueFactor > 1) fatigueFactor = 1;
	if (i <= (FtPct*fatigueFactor))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int CPlay::ReboundTeam(int m_possesion, int Lineup[3][6])
{
	CPlayerRatings m_playerRatings;
	double OffReb = 0, DefReb = 0;
	int OffTeam = 0, DefTeam = 0, RebTeam = 0, player = 0;
	OffTeam = m_possesion;
	if(OffTeam == 1)
	{
		DefTeam = 2;
	}
	else
	{
		DefTeam = 1;
	}
	for(int i = 1; i <= 5; i++)
	{
		player = Lineup[OffTeam][i];
	    int team_index = m_visitorIndex;
	    if(OffTeam == 2) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
		m_playerRatings = PlayerRatings[player];
		if(fatigueFactor > 1) fatigueFactor = 1;
		OffReb = OffReb + (m_playerRatings.GetOrebPer48Min()*fatigueFactor);
	}
	for(i = 1; i <= 5; i++)
	{
		player = Lineup[OffTeam][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		m_playerRatings = PlayerRatings[player];
		
		if(fatigueFactor > 1) fatigueFactor = 1;
		DefReb = DefReb + (m_playerRatings.GetDrebPer48Min()*fatigueFactor);
	}
	double number = CPlay::Random(OffReb + DefReb);
	if(number <= OffReb)
	{
		RebTeam = OffTeam;
	}
	else
	{
		RebTeam = DefTeam;
	}
	return RebTeam;
}

int CPlay::ReboundPlayer(int m_possesion, int Lineup[3][6], int m_reboundTeam)
{
	CPlayerRatings m_playerRatings;
	double Touches[6];
	int player = 0;
	Touches[0] = 0;
	for(int i = 1; i < 6; ++i)
	{

		player = Lineup[m_reboundTeam][i];


	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		m_playerRatings = PlayerRatings[player];
		
		if(fatigueFactor > 1) fatigueFactor = 1;
		if(m_possesion == m_reboundTeam)
		{
			Touches[i] = Touches[i-1] +	(m_playerRatings.GetOrebPer48Min()*fatigueFactor); 
		}
		else
		{
			Touches[i] = Touches[i-1] +	(m_playerRatings.GetDrebPer48Min()*fatigueFactor); 
		}
	}
	double number = CPlay::Random(Touches[5]);
	int position = CPlay::IntRandom(5);
	for(i = 1; i < 6; ++i)
	{
		if(number <= Touches[i] && number > Touches[i-1]){position = i;}
	}
    return position;
}

int CPlay::PfPlayer(int m_possesion, int Lineup[3][6])
{
	CPlayerRatings m_playerRatings;
	double Touches[6];
	Touches[0] = 0;
	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[m_possesion][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
		
		
		m_playerRatings = PlayerRatings[player];
		
		if(fatigueFactor > 1) fatigueFactor = 1;
		double foulRating = m_playerRatings.GetPfPer48Min();
		bool foulTrouble = FoulProblem(player);
		if(foulTrouble == true) foulRating = foulRating * 2/3;// 2/3 is foul caution factor;
		Touches[i] = Touches[i-1] +	foulRating*(2-fatigueFactor); 
	}
	double number = CPlay::Random(Touches[5]);
	int position = CPlay::IntRandom(5);
	for(i = 1; i < 6; ++i)
	{
		if(number <= Touches[i] && number > Touches[i-1]){position = i;}
	}
    return position;
}

int CPlay::AssistPlayer(int m_possesion, int Lineup[3][6], int m_ballHandler)
{
	CPlayerRatings m_playerRatings;
	double Assists[6];
	double FieldGoals[6];
	double AstRating[6];//used to adjust ast Rating
	int Positions[6];
	int Ast = 0;
	Assists[0] = 0;
	FieldGoals[0] = 0;
	AstRating[0] = 0;
	for(int i = 1; i <= 5; i++)
	{
		m_playerRatings = PlayerRatings[Lineup[m_possesion][i]];
		Assists[i] = Assists[i-1] +	m_playerRatings.GetAstPer48Min(); 
		// calculate shots made by team
		double fgm = m_playerRatings.GetAdjustedFgaPer48Min() * double(m_playerRatings.GetAdjustedFgPct())/1000;
		double tfgm = m_playerRatings.GetAdjustedTfgaPer48Min() * double(m_playerRatings.GetTfgPct())/1000;
		FieldGoals[i] =	FieldGoals[i-1] + fgm + tfgm;
	}
	int p = 0;
	for(i = 1; i <= 5; i++)
	{
		if(i == m_ballHandler) continue;
		p = p + 1;
		int player = Lineup[m_possesion][i];

	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		if(fatigueFactor > 1) fatigueFactor = 1;
		m_playerRatings = PlayerRatings[player];
		double fg = (m_playerRatings.GetAstPer48Min()*fatigueFactor) / (FieldGoals[5] - (FieldGoals[i] - FieldGoals[i-1]));	
		AstRating[p] = AstRating[p-1] + fg;
		Positions[p] = i;
	}

	double tmp = AstRating[4];//lower assist amount if team has too many 
	double factor = 1;
	if(tmp > (9./11.)) factor = tmp*11/9;

	double number = CPlay::Random(factor);
	for(i = 1; i <= 4; i++)
	{
		if(number <= AstRating[i] && number > AstRating[i-1]) Ast = Positions[i];
	}	
	return Ast;
}

int CPlay::StealPlayer(int m_possesion, int Lineup[3][6], double avg_stl)
{
	CPlayerRatings m_playerRatings;
	int defTeam = m_possesion;
	int offTeam = 0;

	if(m_possesion == 1) offTeam = 2; 
	else offTeam = 1;
	double Steals[6];
	double Turnovers[6];
	int Stl = 1;
	Steals[0] = 0;
	Turnovers[0] = 0;
	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];

	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		m_playerRatings = PlayerRatings[player];

		if(fatigueFactor > 1) fatigueFactor = 1;

		Steals[i] = Steals[i-1] + m_playerRatings.GetStlPer48Min()*fatigueFactor; 
	}

	if(Steals[5] > (avg_stl * 1.5))
	{
		double f = (avg_stl * 1.5) / Steals[5];
		for(int i = 1; i <=5; i++)
		{
			Steals[i] = Steals[i] * f;
		}		
	};


	for(i = 1; i <= 5; i++)
	{
		int player = Lineup[offTeam][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
		m_playerRatings = PlayerRatings[player];
		Turnovers[i] = Turnovers[i-1] + m_playerRatings.GetToPer48Min()*(2-fatigueFactor); 
	}
	double number = CPlay::Random(Turnovers[5]);
	if(number >= Steals[5])
		Stl = FALSE;
	else
	{
		for(i = 1; i <=5; i++)
		{
			if(number <= Steals[i] && number > Steals[i-1]) Stl = i;		
		}
	}
	return Stl;
}

int CPlay::BlockPlayer(int m_possesion, int Lineup[3][6], bool ThreePointer, double avgBlk)
{
	CPlayerRatings m_playerRatings;
	int defTeam = m_possesion;
	int offTeam;
	double TptBlkPct;
	double f = avgBlk*.04;
	if(ThreePointer == true)
		TptBlkPct = f/avgBlk;
	else
		TptBlkPct = (avgBlk-f)/avgBlk;
	
	if(defTeam == 1)
		offTeam = 2;
	else
		offTeam = 1;
	
	double Blocks[6];
	int Blk = CPlay::IntRandom(5);
	Blocks[0] = 0;
	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		if(fatigueFactor > 1) fatigueFactor = 1;
		m_playerRatings = PlayerRatings[player];
		Blocks[i] = Blocks[i-1] + fatigueFactor * m_playerRatings.GetBlkPer48Min() * TptBlkPct;
	}

	if(Blocks[5] > (avgBlk * 1.5))
	{
		double f = (avgBlk * 1.5) / Blocks[5];
		for(int i = 1; i <=5; i++)
		{
			Blocks[i] = Blocks[i] * f;
		}		
	}


	double ShotsMissed[6];
	ShotsMissed[0] = 0;
	for(i = 1; i < 6; ++i)
	{
		double fgm, fgMissed;
		int player = Lineup[defTeam][i];
//		m_playerRatings = PlayerRatings[player];
//		double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
		m_playerRatings = PlayerRatings[player];		
	if(ThreePointer == true)
	{
		fgm =
			m_playerRatings.GetTfgaPer48Min()
			* double(m_playerRatings.GetTfgPct())/1000;
	    fgMissed =
			m_playerRatings.GetTfgaPer48Min() - fgm;
	}
	else
	{
		fgm =
			m_playerRatings.GetFgaPer48Min()  
			* double(m_playerRatings.GetFgPct())/1000;
	    fgMissed =
			m_playerRatings.GetFgaPer48Min() - fgm;
	}
		ShotsMissed[i] = ShotsMissed[i-1] + fgMissed;
	}
	double number = CPlay::Random(ShotsMissed[5]);
	if(number > Blocks[5])
		Blk = FALSE;
	else
	{
		for(i = 1; i < 6; ++i)
		{
			if(number <= Blocks[i] && number > Blocks[i-1]) Blk = i;
		}
	}
	return Blk;
}

double CPlay::CurrentLineupBetter(int player, 
								  int m_possesion, int Lineup[3][6])
{
	CPlayer m_player;
	int offTeam = m_possesion;	
	int ballhandler = player;
	double better = 0;//current players around
	m_player = PlayerArray[Lineup[offTeam][ballhandler]];
	int usual = m_player.GetBetter();//ballhandler norm of players around 
	double d = double(usual) * 2 / 10 - 9.9;
	for(int i = 1; i <= 5; i++)
	{
		if(player != i)
		{

	        int team_index = m_visitorIndex;
	        if(player > 15) team_index = m_homeIndex;
	        double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	        fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);
	
			if(fatigueFactor > 1) fatigueFactor = 1;
			m_player = PlayerArray[Lineup[offTeam][i]];
			better = 
				better + m_player.GetTeammatesBetterRating()*fatigueFactor; 
		}
	}

	better = better + m_defAdj;

	double result = (better - d) / 4;
	return result;


}

double CPlay::CurrentLineupBlocks(int m_possesion, int Lineup[3][6], double avg_blk)
{
	CPlayerRatings m_playerRatings;
	int offTeam = m_possesion;
	int defTeam = 0;

	if(m_possesion == 1)
		defTeam = 2;
	else
		defTeam = 1;
	
	double Blocks[6];
	int Blk = CPlay::IntRandom(5);
	Blocks[0] = 0;
	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		if(fatigueFactor > 1) fatigueFactor = 1;
		m_playerRatings = PlayerRatings[player];
		Blocks[i] = Blocks[i-1] + m_playerRatings.GetBlkPer48Min(); 
	}


	if(Blocks[5] > (avg_blk * 1.5))
	{
		double f = (avg_blk * 1.5) / Blocks[5];
		for(int i = 1; i <=5; i++)
		{
			Blocks[i] = Blocks[i] * f;
		}		
	};

	return Blocks[i-1];
}

double CPlay::CurrentLineupSteals(int player, int Lineup[3][6], double avg_stl)
{
	CPlayerRatings m_playerRatings;
	int defTeam;
	if(player <= 15)
		defTeam = 2;
	else
		defTeam = 1;
	
	double Steals[6];
	int Stl = CPlay::IntRandom(5);
	Steals[0] = 0;
	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[defTeam][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		if(fatigueFactor > 1) fatigueFactor = 1;
		m_playerRatings = PlayerRatings[player];
		Steals[i] = Steals[i-1] + m_playerRatings.GetStlPer48Min();
	}
	if(Steals[5] > (avg_stl * 1.5))
	{
		double f = (avg_stl * 1.5) / Steals[5];
		for(int i = 1; i <=5; i++)
		{
			Steals[i] = Steals[i] * f;
		}		
	};
	
	return Steals[i-1];
}

double CPlay::CurrentLineupTurnovers(int player, int Lineup[3][6], BOOL m_homeCourt)
{
	CPlayerRatings m_playerRatings;
	int Team;
	if(player <= 15)
		Team = 1;
	else
		Team = 2;
	
	double Turnovers[6];
	double playerTo;
//	int To = CPlay::IntRandom(5);
	Turnovers[0] = 0;



	for(int i = 1; i < 6; ++i)
	{
		int player = Lineup[Team][i];
	    int team_index = m_visitorIndex;
	    if(player > 15) team_index = m_homeIndex;
	    double fatigueFactor = (100 + double(PlayerStats[player].GetStamina())/30)/100;
//	    fatigueFactor = fatigueFactor * (1 + (double(m_coach[team_index].m_coachEndurance) - 3)/20);

		if(fatigueFactor > 1) fatigueFactor = 1;
		m_playerRatings = PlayerRatings[Lineup[Team][i]];
		if(m_homeCourt == TRUE)
			playerTo = m_playerRatings.GetAdjustedToPer48Min()
			- double(Team * 2 - 3) * .3;
		else
			playerTo = m_playerRatings.GetAdjustedToPer48Min();
		Turnovers[i] = Turnovers[i-1] + playerTo; 
	}
	return Turnovers[i-1];
}

void CPlay::SetAvgTime(double avgPos, double avgOreb)
{
        //calculate avg time of possesion
		double visitorPossesions = TeamRatings[1].GetFgaPer48Min()
			+ TeamRatings[1].GetTfgaPer48Min()
			+ TeamRatings[1].GetToPer48Min()
			+ TeamRatings[1].GetFoulsDrawnPer48Min();

		double homePossesions = TeamRatings[2].GetFgaPer48Min()
			+ TeamRatings[2].GetTfgaPer48Min()
			+ TeamRatings[2].GetToPer48Min()
			+ TeamRatings[2].GetFoulsDrawnPer48Min();

//		double possesions = (visitorPossesions + homePossesions - 20) * 2 - 210;
		double pb = (TeamRatings[1].GetOrebPer48Min() +
			TeamRatings[2].GetOrebPer48Min()) * 5/8; 
		double fbv = (TeamRatings[1].GetDrebPer48Min() + TeamRatings[1].GetStlPer48Min())/5;
		double fbh = (TeamRatings[2].GetDrebPer48Min() + TeamRatings[2].GetStlPer48Min())/5;
		double fb = (fbv+fbh)*7/5;
		double avgFbChances = avgPos*2/10;
		avgOreb = avgOreb*2*5/8;
		double poss = avgPos*2 - pb - fb;
		double possesions = (visitorPossesions + homePossesions - avgOreb - avgFbChances) * 2 - poss;
		m_avg_time = (2880-pb*2-fb*4) / possesions;
		if(m_avg_time < 13) m_avg_time = 13;
		if(m_avg_time > 16) m_avg_time = 16;

		m_avg_time = m_avg_time * (2 - m_scoring_factor);
		if(m_avg_time < 1 || m_avg_time > 24) m_avg_time = 24;
}

void CPlay::SetTime(bool PutBack, int originalShot)
{
	//calculate seconds elapsed on possesion
	double d_seconds = 0;
    int i_seconds = 0;
	if(PutBack == TRUE)
	{
		i_seconds = CPlay::IntRandom(3);
	}
	else if(originalShot == 7)
	{
		i_seconds = CPlay::IntRandom(3)+2;
	}
	else
	{
		int i_avg_time = int(m_avg_time);
		double factor = m_avg_time/2;
		double f = m_avg_time - factor;
		d_seconds = CPlay::Random(m_avg_time) + f;
		double r = d_seconds - int(d_seconds);
		if(r < .5) i_seconds = int(d_seconds);
		else i_seconds = int(d_seconds) + 1;
		if(i_seconds == i_avg_time) i_seconds = CPlay::IntRandom(21) + 3;
	}
	m_time = m_time - i_seconds;

//	if(m_time <= 0) m_time = 0;


	if(m_time <= 0) 
	{
		SetQuarter();
		m_quarter_ended = true;
	}
	if(PutBack == TRUE && m_quarter >= 5 && m_time == 300)//putback in progress game cant end
	{
		m_quarter = m_quarter - 1;
		m_quarter_ended = false;
		m_time = 1;
	}

}

void CPlay::SetQuarter()
{

    m_quarter = m_quarter + 1;

	if(m_quarter < 5)
		m_time = 720; 
	else 
		m_time = 300;

}

int CPlay::GetTime()
{
    return m_time;
}

int CPlay::GetQuarter()
{
    return m_quarter;
}


bool CPlay::FoulProblem(int player)
{
	bool foulTrouble = false;
	CPlayerStats m_playerStats;
	m_playerStats = PlayerStats[player];
	int fouls = m_playerStats.GetPf();
	int seconds = m_time; 
	int quarter = m_quarter; 
	int time = 720 - seconds + (quarter - 1) * 720;
//	if(quarter > 4) time = 2880 + (300 - seconds) + (quarter - 5) * 300;

	if( (quarter == 1 && fouls >= 1) || (quarter == 2 && fouls >= 2)
		|| (quarter == 3 && fouls >= 3) || (quarter >= 4 && time < 2580 && fouls >= 4)
		|| (fouls >= 5) ) foulTrouble = true;
	return foulTrouble;
}

void CPlay::DefensiveAdjustments(int d, int &mov, int &pen, int &post, int Lineup[3][6], int typeShot)
{
	int t = 1, p = 6;
	m_defAdj = 0;
	if(d <= 5)
	{t = 2; p = 1;}



	if(m_match[d] == 1)
	{
		mov = mov - 4;
		pen = pen + 2;
		post = post + 2;
	}
	else if(m_match[d] == 2)
	{
		mov = mov + 2;
		pen = pen - 4;
		post = post + 2;
	}
	else if(m_match[d] == 3)
	{
		mov = mov + 2;
		pen = pen + 2;
		post = post - 4;
	}
	else if(m_match[d] == 4)
	{
		mov = mov - 2;
		pen = pen - 2;
		post = post - 2;

	}
	
	if(m_match[d] != 4)//non doubled
	{
		for(int q = p; q <= p+4; q++)
		{
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();

			if(m_match[q] == 4 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}

	}
	

	if(m_match[d] != 3 && typeShot == 3)//post up by non post defended player
	{
		for(int q = p; q <= p+4; q++)
		{
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();

			if(m_match[q] == 3 && adj > 0)// add posted up players rating
				m_defAdj = m_defAdj + adj;
		}
	}
	else if(typeShot == 3)//post up by post defended player
	{
		for(int q = p; q <= p+4; q++)
		{
			if(m_match[q] == 3) continue; 
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();
			if(m_match[q] == 3) m_defAdj = m_defAdj + adj;
		}
	}
	if(m_match[d] != 2 && typeShot == 2)
	{
		for(int q = p; q <= p+4; q++)
		{
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();

			if(m_match[q] == 2 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}
	}
	else if(typeShot == 2)
	{
		for(int q = p; q <= p+4; q++)
		{
			if(m_match[q] == 2) continue; 
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();
			if(m_match[q] == 2) m_defAdj = m_defAdj + adj;
		}
	}
	if(m_match[d] != 1 && typeShot == 1)
	{
		for(int q = p; q <= p+4; q++)
		{
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();

			if(m_match[q] == 1 && adj > 0)
				m_defAdj = m_defAdj + adj;
		}
	}
	else if(typeShot == 1)
	{
		for(int q = p; q <= p+4; q++)
		{
			if(m_match[q] == 1) continue; 
			int player = q;
			if(player > 5) player = player - 5;
  			player = Lineup[t][player];
			double adj = PlayerArray[player].GetTeammatesBetterRating();
			if(m_match[q] == 1) m_defAdj = m_defAdj + adj;
		}
	}


		for(int q = p; q <= p+4; q++)// too many dbl teams punish
		{
			if(m_match[q] == 4 && q != d)  
			{
				mov = mov + 1;
				pen = pen + 1;
				post = post + 1;
			}
			else if(m_match[q] == 3 && q != d) //too many posts 
			{
				mov = mov + 1;
				pen = pen + 1;
//				post = post + 1;
			}
			else if(m_match[q] == 2 && q != d) //too many drives defended 
			{
				mov = mov + 1;
//				pen = pen + 1;
				post = post + 1;
			}
			else if(m_match[q] == 1 && q != d)  //two many jumpshots defended
			{
//				mov = mov + 1;
				pen = pen + 1;
				post = post + 1;
			}
		}
}

CPlay::AdjustOffenseForGamePlan(CPlayer &m_player)
{
	if(m_player.m_offensive_focus == 1)
	{
		m_player.m_movoff = m_player.m_movoff + 1;
		if(Random(1) <= .5) 
			m_player.m_penoff = m_player.m_penoff - 1;
		else
			m_player.m_postoff = m_player.m_postoff - 1;

	}
	else if(m_player.m_offensive_focus == 2)
	{
		m_player.m_penoff = m_player.m_penoff + 1;
		if(Random(1) <= .5) 
			m_player.m_movoff = m_player.m_movoff - 1;
		else
			m_player.m_postoff = m_player.m_postoff - 1;

	}
	else if(m_player.m_offensive_focus == 3)
	{
		m_player.m_postoff = m_player.m_postoff + 1;
		if(Random(1) <= .5) 
			m_player.m_penoff = m_player.m_penoff - 1;
		else
			m_player.m_movoff = m_player.m_movoff - 1;

	}


}

CPlay::AdjustDefenseForGamePlan(CPlayer &m_player, CPlayerRatings &m_player_ratings, double avg_stl, double avg_to)
{
	


	if(m_player.m_defensive_focus == 1)
	{
		m_player.m_movdef = m_player.m_movdef + 1;
		if(Random(1) <= .5) 
			m_player.m_pendef = m_player.m_pendef - 1;
		else
			m_player.m_postdef = m_player.m_postdef - 1;

	}
	else if(m_player.m_defensive_focus == 2)
	{
		m_player.m_pendef = m_player.m_pendef + 1;
		if(Random(1) <= .5) 
			m_player.m_movdef = m_player.m_movdef - 1;
		else
			m_player.m_postdef = m_player.m_postdef - 1;

	}
	else if(m_player.m_defensive_focus == 3)
	{
		m_player.m_postdef = m_player.m_postdef + 1;
		if(Random(1) <= .5) 
			m_player.m_pendef = m_player.m_pendef - 1;
		else
			m_player.m_movdef = m_player.m_movdef - 1;

	}

	double factor = (100 + (double)m_player.m_defensive_intensity * 5) / 100;

	double s1 = avg_to / avg_stl * m_player_ratings.m_OriginalStlPer48Min * factor;
	double s2 = avg_to / avg_stl * m_player_ratings.m_OriginalStlPer48Min;
	double diff = s1 - s2;

}

void CPlay::AdjustIntensityForGamePlan()
{
	for(int i=1; i<=30; i++)
	{
		double factor = (100 + (double)PlayerArray[i].m_offensive_intensity * 5) / 100;
		PlayerRatings[i].m_AdjustedFgaPer48Min = PlayerRatings[i].m_OriginalAdjustedFgaPer48Min * factor;
		PlayerRatings[i].m_AdjustedTfgaPer48Min = PlayerRatings[i].m_OriginalAdjustedTfgaPer48Min * factor;
		PlayerRatings[i].m_AdjustedFoulsDrawnPer48Min = PlayerRatings[i].m_OriginalAdjustedFoulsDrawnPer48Min * factor;

		factor = (100 + (double)PlayerArray[i].m_defensive_intensity * 5) / 100;
		PlayerRatings[i].m_StlPer48Min = PlayerRatings[i].m_OriginalStlPer48Min * factor;
		PlayerRatings[i].m_BlkPer48Min = PlayerRatings[i].m_OriginalBlkPer48Min * factor;

	}

}
