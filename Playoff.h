#ifndef HireStaff_h
#include "HireStaff.h"
#define HireStaff_h
#endif 

#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 


class CPlayoff: public CObject
{

private:
	void WriteTeamHistoryFile();



public:

	
	void GetPlayoffMatchupWins(CString file_name, int visitor, int home);

	bool m_champion;
	CString list[1023];//list of playoff game results
	int ReadPlayoffResults(CString pFileName, CString LeagueTeamNames[33]);
	CHireStaff m_owner[33];
	int m_currentYear;
	CString m_result[33];
	CString m_leagueTeamNames[33];
	CString m_leagueName;
	CString m_path;
	void WriteCareerTeamHistory();
	int m_currentDay;
	int m_currentMonth;
	int m_team2;
	int m_team1;
	int m_win2;
	int m_win1;
	CRecord* record;
//	int m_po_team_list[33];


	int m_sched[14][32][17];
	int m_gameScore[14][32][17];

	int m_playoffRounds;

	void SetDivisionChamps(
	CString m_divisionName1,
	CString m_divisionName2,
	CString m_divisionName3,
	CString m_divisionName4);

	void SortStandings(CString choice);
//	void LoadStandings(CString file_name,
//	CString &m_playoffFormat,								 
//	CString &m_rd1Format,								 
//	CString &m_rd2Format,								 
//	CString &m_rd3Format,								 
//	CString &m_rd4Format,								 
//	CString &m_conferenceName1,
//	CString &m_conferenceName2,
//	CString &m_divisionName1,
//	CString &m_divisionName2,
//	CString &m_divisionName3,
//	CString &m_divisionName4);
	bool ConferencePlayoff(int &teams, CString m_playoffFormat);
	void SetPlayoffs(bool conferencePlayoff, int teamsPer,
		CString m_conferenceName1,
		CString m_conferenceName2,
		CString m_divisionName1,
		CString m_divisionName2,
		CString m_divisionName3,
		CString m_divisionName4);

	void SetAllPlayoffTeams(bool conferencePlayoff, int teamsPer,
		CString m_conferenceName1,
		CString m_conferenceName2,
		CString m_divisionName1,
		CString m_divisionName2,
		CString m_divisionName3,
		CString m_divisionName4);
	void SetPlayoffRounds(CString m_rd1Format, CString m_rd2Format,
		CString m_rd3Format, CString m_rd4Format);
	
	void WriteFirstRound(CString pFileName,
							  int m_playoffRounds,
							  CString m_rd1Format,
							  CString m_rd2Format,
						   CString m_rd3Format,
						   CString m_rd4Format);

CString	SetSeriesFormat(int m_currentRound, int m_playoffRounds,
								  CString m_rdFormat);

bool CPlayoff::GetPlayoffResults(CString pFileName,
	CString format1, CString format2, CString format3, CString format4,
	int &m_currentRound, int &m_playoffRounds, int m_currentPlayoffDay, int m_currentPlayoffGame,
	BOOL &m_seasonStarted,
	int &m_currentMonth, int &m_currentDay, int &m_currentGame, BOOL &CurrentGame, int visitor, int home);

//void CPlayoff::WritePlayoffResults(CString pFileName, int m_currentMonth, int m_currentDay, int m_currentGame,
//				int m_team1, int score1, int m_win1, int m_team2, int score2, int m_win2);

void CPlayoff::WriteRound(CString pFileName, int m_currentRound, int m_playoffRounds, bool series_winner[33], int playoff_teams[17], CString format, CRecord record[33]);

	CPlayoff();
	~CPlayoff();
};