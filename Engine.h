// Engine.h: interface for the CEngine class.
//
//////////////////////////////////////////////////////////////////////



#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef High_h
#include "High.h"
#define High_h
#endif 

#ifndef InjuryTable_h
#include "InjuryTable.h"
#define InjuryTable_h
#endif 




class CEngine : public CObject  
{


private:
	CString m_injury_string[11];
	bool m_milk;
	int m_injury_count;
	double m_avg_player_min_factor;
	CString SetInjuryString(int g, CString pos);
	CString m_score_string;

	bool m_crash;
	int m_firstPossesion;
	CString DisplayJumpBall(CString playerName);
	CString m_teamName;
	CString m_team;
	CString m_playerName;
	int Lineup[3][6];
	int Defense[3][6];
	CString m_pbp_strings[3201];
	int m_pbp_results;
	int m_playing_players_list[61];
	struct ROTATION
	{
		int Chart;
		double Priority;
		double Minutes;
		bool InRotation;
	};

	int m_possesion;

	double m_avg_time; 
	double m_defAdj;
	int m_visitor_player_offset;
	int m_home_player_offset;
	bool m_update_lineup;
	bool GarbageTime;
	bool m_numbers[61][100];
	int m_edit_games;
	bool m_game_saved;

//	bool m_valid_visitor_rosters;
//	bool m_valid_home_rosters;
//	bool m_dont_sign_visitor;
//	bool m_dont_sign_home;
//	bool m_release_player_visitor;
//	bool m_release_player_home;

	int m_previousTime;
	bool m_fbChance;
	CString m_displayString;
	double n;//variables used to generate random numbers
	double x;//
	double y;

	int m_position_ball_handler;
	int m_teamFouls[3];
	bool m_homeCourt;
	bool m_lineupSet;
	bool m_newGame;
	int m_ballHandler;
	int m_quarter;
	int m_time;
	int m_score[3];
	int m_starters[11];
	CPlayer* TeamRatings;
	int m_visitorIndex;
	int m_homeIndex;
	CString m_visitor;
	CString m_home;
	int m_injury;
	bool m_game_started;
	bool m_quarter_ended;	

	ROTATION Rotation[3][6][10];

public:

	void GamePlay();
	void GameStart();
	void FillPbp(CString paragraph);
	bool m_sub_ok;
	int m_toVisitor;
	int m_toHome;
	int m_toVisitor20;
	int m_toHome20;
	bool m_play_over;

	bool m_toOk;
	bool m_visitorTo;
    bool m_homeTo;
    bool m_visitorTo20;
    bool m_homeTo20;
    bool m_toCalled;
	int m_possesion_team_index[3];//stores index of team with ball 1 visitor 2 home - m_possesion put here to get value

	CString m_team_names[3];
	int m_match[11];
	int m_quarter_score[3][6];
	int m_player_selected_ball_handler;
	int m_player_selected_type_shot;
	int m_injury_notify;
	int m_gameType;
	double m_scoring_factor;
	void GetPbpStrings(CString *strings);
	int m_before_pbp_lines;
	CAverage avg;
	bool m_gameOver;
	bool m_simulate;
	CInjuryTable m_injury_table[307];


	int GetPossesionOfTeamWithoutBall();
	int GetTeamWithBall();
	int GetTeamWithoutBall();
	
	CString GetTeamWithBallName();

public:
	void SetDefensiveLineup(int t, int p, int player);
	int m_must_sub[3];
	BOOL m_auto_sub[3];
	double m_hca;
//	void ValidateCompRosters();
	CHigh m_recordbook;
	int GameMvp();
	void InitializeRookieGame();
	void InitializeAllStarGame();
	
	bool m_all_star_weekend_game;
	void SaveCurrentGameData();
	int GetScore(int t);
	void SetOffensiveLineup(int t, int p, int player);
	int GetPossession();
	int GetGamePossessionTeamIndex(int i);
	int GetGameScore(int i);
	CString GetGameTeamNames(int i);
	int GetOffensiveLineup(int t, int p);
	int GetDefensiveLineup(int t, int p);
	int GetPlayingPlayersList(int i);
	int GetHomePlayerOffset();
	int GetVisitorPlayerOffset();
	int GetHomeIndex();
	int GetVisitorIndex();
	bool m_sim_paused;
	int GetTotalPbpResults();
	void Initialize(int visitor, int home);



	void AdjustIntensityForGamePlan();
	void AdjustOffenseForGamePlan(CPlayer m_player, int &Mov, int &Pen, int &Post, int &Trans);
	void AdjustDefenseForGamePlan(CPlayer m_player,int &MovDef, int &PenDef, int &PostDef, int &TransDef);



	CEngine();
	~CEngine();
	void SetupComputerLineups(); 

	void SetStarters(); 
	void PossesionChange();
	bool Rebounder(int &player, bool Rebounder_Same_As_Shooter, bool block); // return put back 
	int ReboundTeam(int possesion, int Lineup[3][6]);
	int ReboundPlayer(int possesion, int Lineup[3][6], int m_reboundTeam);
	int PfPlayer(int possesion, int Lineup[3][6]);
	int AssistPlayer(int Lineup[3][6], int m_ballHandler);
	int StealPlayer(int Lineup[3][6], double avg_stl);
	int BlockPlayer(int Lineup[3][6], bool ThreePointer, double avgBlk);
	double CurrentLineupBetter(int position_ball_handler, int player, int passer, int possesion, int Lineup[3][6]);
	double CurrentLineupBlocks(int possesion, int Lineup[3][6], double avg_blk);
	double CurrentLineupSteals(int Lineup[3][6]);
	double CurrentLineupTurnovers(int Lineup[3][6], BOOL m_homeCourt);
    void SetAvgTime(double avgPos, double avgOreb);
	void SetTime(bool PutBack, int originalShot);
	void SetQuarter();
	int GetTime();
	int GetQuarter();
	void DefensiveAdjustments(int d, int &mov, int &pen, int &post, int Lineup[3][6], int typeShot);
	void WriteInjury(int team, int id, int g, CString desc);

	
	
	double Random(double n);
	int IntRandom(int n);
	int JumpBall();
	CString FieldGoalAttempt(int typeShot, bool Fgm, bool PutBack, 
		int Player, 
		bool AndOne, bool Three, bool Rebounder_Same_As_Shooter,
		  bool block);

	bool FieldGoalAttemptGame(int FgPct, int Fga, int player,
							 bool m_numbers[31][100]);

	CString FieldGoalAttemptCommentary(int typeShot, int Player);
				
	CString DisplayThreePtFieldGoalAttempt(BOOL Tfgm,
		int Player, bool AndOne);

	bool FoulProblem(int player);

	bool CEngine::ThreePtFieldGoalAttempt(int TfgPct, int player);


	CString FreeThrowAttempt(bool Ftm, bool PutBack,
		int Player,  CString number);

	CString FreeThrowType(BOOL InTheAct, int m_teamFouls, 
		CString m_foulingTeamName, bool assister, bool PutBack);

	CString Turnover(int Player, 
		bool offFoul);

	CString Injury(int Player, 
		int gamesOut);
	
	CString OffRebound(CString m_playerName, int Player,
							   bool Rebounder_Same_As_Shooter,
							   bool block, bool PutBack);
	CString DefRebound(int Player);
    CString Fastbreak(int fbReceiver, int fbPasser, CString team);
	CString Assist(	int Player, int passReceiver);
				
	CString AssistCommentary(int Player,  CString m_playerName);

	void DisplayAssistCommentary(int astPlayer);

	CString Steal(int player, CString m_playerName,
						 CString m_playerToName);
	CString Block(CString m_playerBlockedName, CString m_playerName, int blocker);
		
	CString BlockThreePointer(CString m_playerName,
						CString m_playerBlockedName);
		
	CString Pf(int player, CString m_foulPlayerName, int pf, bool AndOne, 
		bool InTheAct, bool ThreePointer, bool offFoul);
	CString TeamRebound(CString team);


	void Passer(int astPlayer, int passReceiver, bool Fgm);
	bool Stealer(int player);
	bool Blocker(int player, bool ThreePointer);
	int BallHandler(int ballHandler, int possesion, int Lineup[3][6], BOOL m_homeCourt, bool &shotOk, int typeShot, bool &forced3);
	int Result(int player, bool PutBack,
				  int Lineup[3][6], BOOL m_homeCourt,
				  double better, int typeShot, bool forced3);
	void SetMinutesPlayedStat();
	void AutoSub();
	bool FreeThrowAttemptGame(int FtPct, int player);

};


