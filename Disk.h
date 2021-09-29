
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 


#ifndef High_h
#include "High.h"
#define High_h
#endif 


class CDisk: public CObject
{
private:
	bool SelectHallOfFame(CPlayer m_player);
	
double GetRookieTrue(int g, double min, double fgm, double fga, double tgm, double tga, double ftm, double fta, 
							  double orb, double drb, double ast, double stl, double to, double blk, double pf);	
							  
int FindDataForRookie(int pos, int elig, CPlayer m_rookies[481], int stat);

	CString fname[3001];
	CString lname[3001];

	
public:
	void WriteCareerStaff(CString pFileName, CStaff *m_scout, CStaff *m_coach, CStaff *m_gm, CHireStaff *m_owner, int scouts, int coaches);
	void SaveTransactionsFile(CString file_name);
	void ReadTransactionsFile(CString file_name);
	CHigh m_high;
	void WriteRecordBookFile(CString file_name);
	void ReadRecordBookFile(CString file_name);
	void WriteLeagueFile(CString league_name, CBBallSettings settings);
	void CreateCleanLeagueFiles(CString file_name);


	void WritePlayoffResults(CString pFileName, int m_currentMonth, int m_currentDay, int m_currentGame,
				int m_team1, int score1, int m_win1, int m_team2, int score2, int m_win2);


	void SetStandings(CBBallSchedule sched, CRecord* record);

	void ReadStandingsFile(CString file_name, CBBallSettings settings, CBBallSchedule sched, CRecord* record);
	bool ReadStaff(CString staff_file_name, int number_teams);
	CBBallSettings ReadLeagueFile(CString league_name);
	void WriteGamePlan(CString file_name, CString strings[65]);
	void TranslateCsvContractFile(CString m_file_name);
	void ReadNewPlayerDataFile(CString file_name, CString dumb_file_name, CString team_names[33]);
	void WriteNewPlayerDataFile(CString file_name);
	void SetUpTeamsFromImportedFile(CString names_list[33], int league_style);
	int CreatePlayerObjectFromPlayerSpreadSheet(CString file_name, BOOL &check_ages, BOOL &check_contracts, int current_yr, BOOL swap_name);
//	void MergeRosters(CString filename);
	int CreatePlayerObjectFromDataBase(CString file_name, int current_yr, bool rookies);
	int CreatePlayerObjectFromSpreadSheet(CString file_name, BOOL adjust, BOOL random, int lines);
	void LoadPlayoffMonth(CString file_name, CBBallSchedule schedule);
	void CreateHugeBlankFile(CString file_name, int times);

	void SaveSchedule(CString file_name, CBBallSchedule schedule);
	void WriteStaffData(CString file_name);
	void UpdateExpansionFile(CString exp_name, CString team_names[33]);
	//int Random(int n);
	double Random(double n);

		int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}


	void DeleteAllFiles(CString file_name);
	void WriteCurrentYear(CString file_name, int yr);
	void DeleteFile(CString file_name);
	void CreateFictionalPool();
	

	bool SeasonStarted(CString file_name);
	CPlayer m_player;
	void ReadPlayerContract(CString file_name);
	int OpenCurrentYear(CString file_name);
	void WriteTeamStats(CString file_name);
	void WritePlayoffTeamStats(CString file_name);
	void WritePlayoffStats(CString file_name);
	void WritePlayerStats(CString file_name);


	CPlayer* Rookies;
	void OpenRookies(CString file_name);
	void ReadNames(CString f_file_name, CString l_file_name);
	void CreateRookies(CString file_name, bool create_preview_file);
	void IncreaseFileSize(CString file_name, int size);
	void DecreaseFileSize(CString file_name, int size);
	void ReadFutureFile(CString file_name);
	void WriteFutureFile(CString file_name);
	CString m_string[101];
	CBBallSchedule ReadSchedule(CString file_name);
	void WriteRookieFile(CString file_name, BOOL random);
	void WriteBudgetFile( CString file_name, int t1, int t2);
	void ReadBudgetFile(CString file_name);
	void GetSavedAverages(CString file_name);
	void GetSavedHighs(CString file_name);
	void ReadPlayoffTeamStats(CString file_name);
	void ReadTeamStats(CString file_name);
	void ReadPlayerStats(CString file_name, bool signing_ok);
	void ReadPlayoffStats(CString file_name);
	bool PlayoffsStarted(CString file_na);
	void ReadPlayerData(CString file_name);




	void CreateBlankFile(CString file_name, int size);
	bool FileExists(CString file_name);	
	void ReadDraftPositions(CString file_name);

	void ReadCareerContractFile(CString file_name);
	void CreateEmptyFile(CString file_name, int size);


	CAverage avg;
	CString m_leagueTeamNames[33];
	void WriteLeagueAverages(CString m_file_name);
	void WritePlayerData(CString m_file_name);
	void WriteCareerContractFile(CString file_name, double tru_factor);
	void WriteLeagueHighs(CString m_file_name);
	void WriteFranchiseData(CString m_file_name,int s1, int s2);
	void ReadFranchiseData(CString m_file_name);

	
	double m_saved_avg_pf;
	double m_saved_min;
	double m_saved_avg_fta;
	double m_saved_avg_tga;
	double m_saved_avg_to;
	double m_saved_avg_blk;
	double m_saved_avg_fga;
	double m_save_avg_stl;
	double m_save_avg_orb;
	double m_save_avg_reb;
	double m_save_avg_drb;
	double m_save_avg_ast;
	double m_save_avg_tru;


CDisk()
{
	Rookies = new CPlayer[97];
	srand( (unsigned)time( NULL ) );	
}






~CDisk()
{
	delete [] Rookies;
}	
	

};