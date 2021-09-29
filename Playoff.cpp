#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"

#include "Playoff.h"

CPlayoff::CPlayoff()
{
	record = new CRecord[33];
	m_playoffRounds = 0;
	m_currentMonth = 0;
	m_currentDay = 0;
	m_currentYear = 0;
	m_win1 = 0;
	m_win2 = 0;
	m_team1 = 0;
	m_team2 = 0;
	m_champion = false;
	for(int i=0; i<=13; i++)
	{
		for(int j=0; j<=31; j++)
		{
//			m_po_team_list[j] = -1;
			for(int k=0; k<=16; k++)
			{
				m_sched[i][j][k] = 0;
				m_gameScore[i][j][k] = 0;
			}
		}
	}

}

CPlayoff::~CPlayoff()
{
	delete [] record;

}

void CPlayoff::SetDivisionChamps(
	CString m_divisionName1,
	CString m_divisionName2,
	CString m_divisionName3,
	CString m_divisionName4)
{
	int t = 0;
	bool found = false;
	do
	{

		if(record[t].m_division == m_divisionName1)
		{
			record[t].m_divisionChamps = true;
			found = true;
		}
		t = t + 1;
	} while(found == false && t <= 31);
	
	t = 0;
	found = false;
	do
	{
		if(record[t].m_division == m_divisionName2)
		{
			record[t].m_divisionChamps = true;
			found = true;
		}
		t = t + 1;
	} while(found == false && t <= 31);
	
	t = 0;
	found = false;
	do
	{
		if(record[t].m_division == m_divisionName3)
		{
			record[t].m_divisionChamps = true;
			found = true;
		}
		t = t + 1;
	} while(found == false && t <= 31);
	
	t = 0;
	found = false;
	do
	{
		if(record[t].m_division == m_divisionName4)
		{
			record[t].m_divisionChamps = true;
			found = true;
		}
		t = t + 1;
	} while(found == false && t <= 31);
	




}

void CPlayoff::SortStandings(CString choice)
{
	BOOL swap = FALSE;
	for(int t = 0; t <= 31; t++)
	{
		CString divisionOfTeam = record[t].m_division;
		CString conferenceOfTeam = record[t].m_conference;
		if(divisionOfTeam == choice || conferenceOfTeam == choice)
		{
			for(int j = 0; j <= 31; j++)
			{
				swap = FALSE;
				CString divisionOfTeam = record[j].m_division;
				CString conferenceOfTeam = record[j].m_conference;
				double pctj = record[j].m_leaguePct;
				double pctt = record[t].m_leaguePct;
				if(record[j].m_divisionChamps == true) pctj = pctj + 1;
				if(record[t].m_divisionChamps == true) pctt = pctt + 1;

				if(divisionOfTeam == choice || conferenceOfTeam == choice)
				{
					//if(record[j].m_divisionChamps == false && record[t].m_divisionChamps == true)
					//	swap = TRUE;
					if((pctj < pctt)
						&& 
					(
						(record[j].m_divisionChamps == false ||	
						record[j].m_divisionChamps == true && record[t].m_divisionChamps == true)	
					)
	
	
	
					) 
						swap = TRUE;
					else if(pctj == pctt) 
					{
						if(record[j].m_leagueGamesBack < record[t].m_leagueGamesBack) swap = TRUE;
						else if(record[j].m_leagueGamesBack == record[t].m_leagueGamesBack)
						{
							if(divisionOfTeam == choice)//division tiebreakers
							{
								if(record[j].m_divisionPct < record[t].m_divisionPct) swap = TRUE;
								else if(record[j].m_divisionPct == record[t].m_divisionPct) 
								{
									if(record[j].m_conferencePct < record[t].m_conferencePct) swap = TRUE;
								}
							}
							if(conferenceOfTeam == choice)//conference tiebreakers
							{
								if(record[j].m_conferencePct < record[t].m_conferencePct) swap = TRUE;
							}
						}

					}
					if(swap == TRUE)
					{
						swap = FALSE;
						CRecord temp = record[t];
						record[t] = record[j];
						record[j] = temp;
					}
				}
			}
		}	
	}
	BOOL FirstPlace = TRUE;
	double gb = 0;
	int FirstPlaceWin = 0;
	int FirstPlaceLoss = 0;
	for(int t=0; t<=31; t++)
	{
		CString divisionOfTeam = record[t].m_division;
		CString conferenceOfTeam = record[t].m_conference;
		if(divisionOfTeam == choice || conferenceOfTeam == choice)
		{
			int w = record[t].m_leagueRecord / 100;
			int l = record[t].m_leagueRecord - w * 100;
			if(t<=30)//break 2 team ties with head to head results
			{
				int wn = record[t+1].m_leagueRecord / 100;
				int ln = record[t+1].m_leagueRecord - w * 100;
				if(w == wn && l == ln)
				{
					int init = record[t].m_initialNumber + 1;
					int initn = record[t+1].m_initialNumber + 1;
					if(record[t].m_vsOpponentPct[initn] < record[t+1].m_vsOpponentPct[init])
					{
						CRecord temp = record[t];//swap
						record[t] = record[t+1];
						record[t+1] = temp;
					}
				}
			}
				
		}
	}
}






bool CPlayoff::ConferencePlayoff(int &teams, CString m_playoffFormat)
{
	bool conferencePlayoffs = false;
	if(m_playoffFormat == "1 team per conference" ||
		m_playoffFormat == "2 teams per conference" ||
		m_playoffFormat == "4 teams per conference" ||
		m_playoffFormat == "8 teams per conference")
	{
		conferencePlayoffs = true;
		if(m_playoffFormat == "2 teams per conference") teams = 2;
		else if(m_playoffFormat == "4 teams per conference") teams = 4;
		else if(m_playoffFormat == "8 teams per conference") teams = 8;
	}
	else
	{
		if(m_playoffFormat == "2 teams per division") teams = 2;
		else if(m_playoffFormat == "4 teams per division") teams = 4;
	}
	return conferencePlayoffs;
}


void CPlayoff::SetPlayoffs( bool conferencePlayoff, int teamsPer,
	CString m_conferenceName1,
	CString m_conferenceName2,
	CString m_divisionName1,
	CString m_divisionName2,
	CString m_divisionName3,
	CString m_divisionName4)
{
	CRecord playoffTeamList[33];
	CRecord matchup[17];
	int playoffTeams = 0;
	if(conferencePlayoff == true)
	{
		int t = 0;
		do
		{
			if(m_conferenceName1 == record[t].m_conference)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer);
		t = 0;
		do
		{
			if(m_conferenceName2 == record[t].m_conference)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*2 && t<=31);
	}
	else
	{

		int t = 0;
		do
		{
			if(m_divisionName1 == record[t].m_division)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer && t<=31);
		t = 0;
		do
		{
			if(m_divisionName2 == record[t].m_division)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*2 && t<=31);
		t = 0;
		do
		{
			if(m_divisionName3 == record[t].m_division)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*3 && t<=31);
		t = 0;
		do
		{
			if(m_divisionName4 == record[t].m_division)
			{
				playoffTeamList[playoffTeams] = record[t];
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*4 && t<=31);



	}

	for(int t = 0; t <= 31; t++)
	{
		record[t] = playoffTeamList[t];
	}
	
	if(conferencePlayoff == true)
	{
		if(teamsPer == 1)
		{
			matchup[0] = record[0];
			matchup[1] = record[1];
		}
		else if(teamsPer == 2)
		{
			matchup[0] = record[0];
			matchup[1] = record[1];
			matchup[2] = record[2];
			matchup[3] = record[3];
		}
		else if(teamsPer == 4)
		{
			matchup[0] = record[0];matchup[1] = record[3];
			matchup[2] = record[1];matchup[3] = record[2];
			matchup[4] = record[4];matchup[5] = record[7];
			matchup[6] = record[5];matchup[7] = record[6];
		}
		else if(teamsPer == 8)
		{
			matchup[0] = record[0]; matchup[1] = record[7];
			matchup[2] = record[3]; matchup[3] = record[4];
			matchup[4] = record[1]; matchup[5] = record[6];
			matchup[6] = record[2]; matchup[7] = record[5];
			matchup[8] = record[8]; matchup[9] = record[15];
			matchup[10] = record[11]; matchup[11] = record[12];
			matchup[12] = record[9]; matchup[13] = record[14];
			matchup[14] = record[10]; matchup[15] = record[13];
		}
	}
	else
	{
		if(teamsPer == 1)
		{
			matchup[0] = record[0];
			matchup[1] = record[1];
			matchup[2] = record[2];
			matchup[3] = record[3];
		}
		else if(teamsPer == 2)
		{
			matchup[0] = record[0]; matchup[1] = record[1];
			matchup[2] = record[2]; matchup[3] = record[3];
			matchup[4] = record[4]; matchup[5] = record[5];
			matchup[6] = record[6]; matchup[7] = record[7];
		}
		else if(teamsPer == 4)
		{
			matchup[0] = record[0];matchup[1] = record[3];
			matchup[2] = record[1];matchup[3] = record[2];

			matchup[4] = record[4];matchup[5] = record[7];
			matchup[6] = record[5];matchup[7] = record[6];

			matchup[8] = record[8];matchup[9] = record[11];
			matchup[10] = record[9];matchup[11] = record[10];

			matchup[12] = record[12];matchup[13] = record[15];
			matchup[14] = record[13];matchup[15] = record[14];
		}
	}

	for(int t = 0; t <= 16; t++)
	{
		record[t] = matchup[t];
	}

	

}

void CPlayoff::SetPlayoffRounds(CString m_rd1Format, CString m_rd2Format,
		CString m_rd3Format, CString m_rd4Format)
{
	if(m_rd1Format == "None") m_playoffRounds = 0;
	else if(m_rd2Format == "None") m_playoffRounds = 1;
	else if(m_rd3Format == "None") m_playoffRounds = 2;
	else if(m_rd4Format == "None") m_playoffRounds = 3;
	else m_playoffRounds = 4;

}

void CPlayoff::WriteFirstRound(CString pFileName, 
							   int m_playoffRounds,
							   CString m_rd1Format,
							   CString m_rd2Format,
							   CString m_rd3Format,
							   CString m_rd4Format)
{
		//set home and away
	int m_currentRound = 1;
	int m_currentDay = 0;
	int m_currentGame = 0;
	CString format1, format2, format3, format4;
	
	format1 = 
		SetSeriesFormat(m_currentRound, m_playoffRounds, m_rd1Format);

	if(m_rd2Format != "None") 
		format2 = SetSeriesFormat(2, m_playoffRounds, m_rd2Format);

	if(m_rd3Format != "None") 
		format3 = SetSeriesFormat(3, m_playoffRounds, m_rd3Format);

	if(m_rd4Format != "None") 
		format4 = SetSeriesFormat(4, m_playoffRounds, m_rd4Format);


		CFile file(	pFileName, CFile::modeWrite	);
		int seek = 72000;
		file.Seek(seek, CFile::begin );
		CString playoffStart = "Y";
		file.Write( playoffStart, 1);
		file.Write( format1, 10);
		file.Write( format2, 10);
		file.Write( format3, 10);
		file.Write( format4, 10);
		CString buffer;
		
		buffer.Format("%d", m_currentRound);
		file.Write( buffer, 1);
		
		buffer.Format("%d", m_playoffRounds);
		file.Write( buffer, 1);
		
		buffer.Format("%d", m_currentDay);
		file.Write( buffer, 2);

		buffer.Format("%d", m_currentGame);
		file.Write( buffer, 1);
		
		format1 = format1 + "          ";
		CString gamesToWin = format1.GetAt(0); 
		CString gamesInSeries = format1.GetAt(1); 
		int games = atoi(gamesInSeries);
		CString home_away[8];
		for(int g=1; g<=7; g++)
		{
			home_away[g] = format1.GetAt(g+1);
		}


		for(int g=1; g<=7; g++)
		{
			bool swap = false;
			bool roundOver = false;
			if(g<=games)
			{
				if(home_away[g] == "1") swap = true;
			}
		for(int i=0; i<=7; i++)
		{
			int team1 = record[i*2].m_initialNumber + 1;
			int team2 = record[i*2+1].m_initialNumber + 1;
			int te1 = i*2;
			int te2 = i*2 + 1;
			if(g > games || team1 == team2) {team1 = 0; team2 = 0;}
			else if(swap == true) 
			{int temp = team2; team2 = team1; team1 = temp;}



			bool exchange = false;// if 2nd team has better record exchange home & away
			double win_pct1 = 0;
			double win_pct2 = 0;
			if(record[te1].m_leagueTeamNames != "" && record[te2].m_leagueTeamNames != "")
			{
			
			win_pct1 = record[te1].m_leaguePct;
			win_pct2 = record[te2].m_leaguePct;
			
			if(win_pct2 > win_pct1) exchange = true; 
			else if(win_pct2 == win_pct1) 
			{
				int i1 = record[te1].m_initialNumber + 1;//team they were before the playoff matchups changed the slot
				int i2 = record[te2].m_initialNumber + 1;//team they were before the playoff matchups changed the slot
				bool head_to_head = (record[te2].m_vsOpponent[i1] > record[te1].m_vsOpponent[i2]);
				bool tie = (record[te2].m_vsOpponent[i1] == record[te1].m_vsOpponent[i2]);
				if(head_to_head == true) exchange = true;

					if(tie == true)
					{
					if(record[te2].m_division == record[te1].m_division) 
					{	
						if(record[te2].m_divisionRecord > record[te1].m_divisionRecord){exchange = true; tie = false;}
						else if(record[te2].m_divisionRecord == record[te1].m_divisionRecord) tie = true;
					}
					}
					if(tie == true)
					{
					if(record[te2].m_conference == record[te1].m_conference) 
					{	
						if(record[te2].m_conferenceRecord > record[te1].m_conferenceRecord){exchange = true; tie = false;}
						else if(record[te2].m_conferenceRecord == record[te1].m_conferenceRecord) tie = true;
					}
					}
					if(tie == true)
					{
						if(record[te2].m_conferenceRecord > record[te1].m_conferenceRecord){exchange = true; tie = false;}
						else if(record[te2].m_conferenceRecord == record[te1].m_conferenceRecord) tie = true;
					}
					if(tie == true)
					{
						if(record[te2].m_divisionRecord > record[te1].m_divisionRecord){exchange = true; tie = false;}
						else if(record[te2].m_divisionRecord == record[te1].m_divisionRecord) tie = true;
					}

			}

			if(exchange == true) 
			{
				int temp = team2; team2 = team1; team1 = temp;
			}
			
			}


			int score1 = 0;
			int score2 = 0;

			int wins1 = 0;
			int wins2 = 0;

			CString buffer;
			buffer.Format("%d", team1);
			file.Write( buffer, 2);

			buffer.Format("%d", score1);
			file.Write( buffer, 3);

			buffer.Format("%d", wins1);
			file.Write( buffer, 1);

			buffer.Format("%d", team2);
			file.Write( buffer, 2);

			buffer.Format("%d", score2);
			file.Write( buffer, 3);

			buffer.Format("%d", wins2);
			file.Write( buffer, 1);


		}				
		}
}

CString	CPlayoff::SetSeriesFormat(int m_currentRound, int m_playoffRounds,
								  CString m_rdFormat)
{
		CString format = "";
		if(m_rdFormat == "4 of 7" && (m_playoffRounds == 1 || m_currentRound == m_playoffRounds || m_currentRound == 4))//final round
			format = "471100011";
		else if(m_rdFormat == "4 of 7")
			format = "471100101";
		else if(m_rdFormat == "3 of 5")
			format = "3511001";
		else if(m_rdFormat == "2 of 3")
			format = "23011";
		else if(m_rdFormat == "1 of 1")
			format = "111";

		return format;

}


bool CPlayoff::GetPlayoffResults(CString file_name,
	CString format1, CString format2, CString format3, CString format4,
	int &m_currentRound, int &m_playoffRounds, int m_currentPlayoffDay, int m_currentPlayoffGame,
	BOOL &m_seasonStarted,
	int &m_currentMonth, int &m_currentDay, int &m_currentGame, BOOL &CurrentGame, int visitor, int home)
{


		int teams_in_next_game = visitor*100 + home;
		bool any_game = false;
		if(teams_in_next_game == 0) any_game = true;
	
		//m_champion = false;
		bool round_complete = false;
		int seek = 72001;
		bool series_winner[33];
		int no_more_in_round[33];//series loser and day team lost
		int playoff_teams[17];
		m_champion = false;
		for(int i=0; i<=32; i++){series_winner[i] = false; no_more_in_round[i] = 0;}
		for(int i=0; i<=16; i++){playoff_teams[i] = 0;}
		CString pFileName = file_name;
		CFile file( pFileName,  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_currentPlayoffGame = i;
		CString games;
		CString next_rd_format;
		if(m_currentRound == 1)
		{
			games = format1 + "          ";
			next_rd_format = format2 + "           ";
		}
		else if(m_currentRound == 2)
  		{
			games = format2 + "          ";
			next_rd_format = format3 + "           ";
		}
		else if(m_currentRound == 3)
		{
			games = format3 + "          ";
			next_rd_format = format2 + "           ";
		}
		else if(m_currentRound == 4)
		{
			games = format4 + "          ";
		}

		CString gamesToWin = games.GetAt(0); 
		int wins_needed = atoi(gamesToWin);//wins to advance to next round

		i = 12;//playoff Month
		int series_round1 = 0;
		int teams = 0;
		for(int  j = 0; j <= 27; j++ )//28 playoff days
		{
			for(int  k = 0; k <= 7; k++ )//8 max plaoff games per day
			{
				char s[7];

				int seek = 72046 + j*96 + k*12;
				file.Seek(seek, CFile::begin );
				
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team1 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score1 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win1 = atoi(s);

				
				bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team2 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score2 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win2 = atoi(s);


				bool round_ok = false;

				if(j==0 && team1>0 && m_currentRound == 1)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==7 && team1>0 && m_currentRound == 2)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==14 && team1>0 && m_currentRound == 3)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==21 && team1>0 && m_currentRound == 4)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}

		
				if(j>=0 && j<=6 && m_currentRound==1)
				{
					if(win1 == wins_needed)
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}
					else if(win2 == wins_needed)
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}
					round_ok = true;
				}
				else if(j>=7 && j<=13 && m_currentRound==2)
				{
					if(win1 == wins_needed)
					//	series_winner[team1] = true;
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
//						series_winner[team2] = true;
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}
				else if(j>=14 && j<=20 && m_currentRound==3)
				{
					if(win1 == wins_needed)
						//series_winner[team1] = true;
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
						//series_winner[team2] = true;
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}
				else if(j>=21 && j<=27 && m_currentRound==4)
				{
					if(win1 == wins_needed)
						//series_winner[team1] = true;
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
						//series_winner[team2] = true;
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}

				int team_before1 = 0;
				int team_before2 = 0;
			

		
		bool seriesOver = false;		
		if(j != 0 && j != 7 && j != 14 && j != 21)
		{
			int seek_team1 = 72046 + (j - 1) * 96 + k * 12;
			file.Seek(seek_team1, CFile::begin );
			int bytes = file.Read(s, 2);
			s[bytes] = 0;
			team_before1 = atoi(s);

			int seek_score1 = 72046 + (j - 1) * 96 + k * 12 + 2;
			file.Seek(seek_score1, CFile::begin );
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			int sc1 = atoi(s);

			int seek_wins1 = 72046 + (j - 1) * 96 + k * 12 + 5;
			file.Seek(seek_wins1, CFile::begin );
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			win1 = atoi(s);

			int seek_team2 = 72046 + (j - 1) * 96 + k * 12 + 6;
			file.Seek(seek_team2, CFile::begin );
			bytes = file.Read(s, 2);
			s[bytes] = 0;
			team_before2 = atoi(s);

			int seek_score2 = 72046 + (j - 1) * 96 + k * 12 + 8;
			file.Seek(seek_score2, CFile::begin );
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			int sc2 = atoi(s);

			int seek_wins2 = 72046 + (j - 1) * 96 + k * 12 + 11;
			file.Seek(seek_wins2, CFile::begin );
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			win2 = atoi(s);


			if(sc1 == 0 && sc2 == 0) seriesOver = true;


			if(team_before1 != team1)
			{
				int temp = win1;
				win1 = win2;
				win2 = temp;
			}
			else if(win2 == wins_needed && round_ok == true) series_winner[team2] = true;
		}





				int matchup = team1*100 + team2;
				int score = score1*1000 + score2;
				if((no_more_in_round[team1] > 0 && j >= no_more_in_round[team1]) || (no_more_in_round[team2] > 0 && j>=no_more_in_round[team2]) && score == 0) matchup = 0;
				m_sched[i][j][k] = matchup;
				m_gameScore[i][j][k] = score;
				if(score > 0) m_seasonStarted = TRUE;
				
		


				if(((matchup == teams_in_next_game && any_game == false) || 
					(matchup > 0 && any_game == true))
					&& score == 0 &&
					CurrentGame == FALSE && 
					win1 < wins_needed && win2 < wins_needed && seriesOver == false && round_ok == true)
				{
					m_win1 = win1; m_win2 = win2; m_team1 = team1; m_team2 = team2;
					m_currentMonth = i;
					m_currentDay = j;
					m_currentGame = k;
					CurrentGame = TRUE;
				}
			}
		}
		file.Close();
		int series_completed = 0;
			
		for(int i=0; i<=32; i++)
		{
			if(series_winner[i] == true) series_completed = series_completed + 1;
		}



		if(series_completed == series_round1 && m_currentRound < m_playoffRounds) 
		{
			m_currentRound = m_currentRound + 1;
			round_complete = true;
			CString	m_playoffFormat,m_rd1Format,m_rd2Format,m_rd3Format,m_rd4Format,m_conferenceName1,
				m_conferenceName2,m_divisionName1,m_divisionName2,m_divisionName3,m_divisionName4;

			WriteRound(pFileName, m_currentRound, m_playoffRounds, series_winner, playoff_teams, next_rd_format, record);


		}
		else if(series_completed == series_round1 && m_currentRound == m_playoffRounds) 
		{
			round_complete = true;
			m_champion = true;
		}
				


	return round_complete;

}



void CPlayoff::WriteRound(CString pFileName, int m_currentRound, int m_playoffRounds, bool series_winner[33], int playoff_teams[17] , CString format, CRecord record[33])
{

	CString wins_needed_in_final = format.GetAt(0); 
	if(wins_needed_in_final == "4" && m_currentRound == m_playoffRounds) format = "471100011             ";           

	int teams_advance[9] = {0,0,0,0,0,0,0,0,0};
	int count = 0;
	for(int i=0; i<=15; i++)
	{
		int team = playoff_teams[i];
		if(series_winner[team] == true)
		{
			teams_advance[count] = team;
			count = count + 1;
		}
	}

	int m_currentDay = 0;
	int m_currentGame = 0;

		CFile file(	pFileName, CFile::modeWrite	);
		int seek = 72041;
		file.Seek(seek, CFile::begin );
		CString buffer;
		
		buffer.Format("%d", m_currentRound);
		file.Write( buffer, 1);
		
		buffer.Format("%d", m_playoffRounds);
		file.Write( buffer, 1);

		buffer.Format("%d", m_currentDay);
		file.Write( buffer, 2);

		buffer.Format("%d", m_currentGame);
		file.Write( buffer, 1);
		
		seek = 72046 + 672*(m_currentRound-1);
		file.Seek(seek, CFile::begin );
		
		format = format + "          ";
		CString gamesToWin = format.GetAt(0); 
		CString gamesInSeries = format.GetAt(1); 
		int games = atoi(gamesInSeries);
		CString home_away[8];
		for(int g=1; g<=7; g++)
		{
			home_away[g] = format.GetAt(g+1);
		}


		for(int g=1; g<=7; g++)
		{
			bool swap = false;
			bool roundOver = false;
			if(g<=games)
			{
				if(home_away[g] == "1") swap = true;
			}
		count = 0;
		bool exchange = false;// if 2nd team has better record exchange home & away
		for(int i=0; i<=7; i++)
		{

			bool exchange = false;// if 2nd team has better record exchange home & away
			int team1 = teams_advance[count];
			int team2 = teams_advance[count + 1];
			double win_pct1 = 0;
			double win_pct2 = 0;
			if(team1 > 0 && team2 > 0)
			{
			
			win_pct1 = record[team1 - 1].m_leaguePct;
			win_pct2 = record[team2 - 1].m_leaguePct;
			
			if(win_pct2 > win_pct1) exchange = true; 
			else if(win_pct2 == win_pct1) 
			{

				int i1 = record[team1-1].m_initialNumber + 1;//team they were before the playoff matchups changed the slot
				int i2 = record[team2-1].m_initialNumber + 1;//team they were before the playoff matchups changed the slot

				bool head_to_head = (record[team2-1].m_vsOpponent[i1] > record[team1-1].m_vsOpponent[i2]);
				bool tie = (record[team2-1].m_vsOpponent[i1] == record[team1-1].m_vsOpponent[i2]);
				if(head_to_head == true) exchange = true;

					if(tie == true)
					{
					if(record[team2-1].m_division == record[team1-1].m_division) 
					{	
						if(record[team2-1].m_divisionRecord > record[team1-1].m_divisionRecord){exchange = true; tie = false;}
						else if(record[team2-1].m_divisionRecord == record[team1-1].m_divisionRecord) tie = true;
					}
					}
					if(tie == true)
					{
					if(record[team2-1].m_conference == record[team1-1].m_conference) 
					{	
						if(record[team2-1].m_conferenceRecord > record[team1-1].m_conferenceRecord){exchange = true; tie = false;}
						else if(record[team2-1].m_conferenceRecord == record[team1-1].m_conferenceRecord) tie = true;
					}
					}
					if(tie == true)
					{
						if(record[team2-1].m_conferenceRecord > record[team1-1].m_conferenceRecord){exchange = true; tie = false;}
						else if(record[team2-1].m_conferenceRecord == record[team1-1].m_conferenceRecord) tie = true;
					}
					if(tie == true)
					{
						if(record[team2-1].m_divisionRecord > record[team1-1].m_divisionRecord){exchange = true; tie = false;}
						else if(record[team2-1].m_divisionRecord == record[team1-1].m_divisionRecord) tie = true;
					}

			}

			if(exchange == true) 
			{
				int temp = team2; team2 = team1; team1 = temp;
			}
			
			}

			if(g > games || team1 == team2 || i >= 4){team1 = 0; team2 = 0;}
			else if(swap == true) 
			{
				int temp = team2; team2 = team1; team1 = temp; count = count + 2;
			}
			else
				count = count + 2;
			int score1 = 0;
			int score2 = 0;

			int wins1 = 0;
			int wins2 = 0;

			CString buffer;
			buffer.Format("%d", team1);
			file.Write( buffer, 2);

			buffer.Format("%d", score1);
			file.Write( buffer, 3);

			buffer.Format("%d", wins1);
			file.Write( buffer, 1);

			buffer.Format("%d", team2);
			file.Write( buffer, 2);

			buffer.Format("%d", score2);
			file.Write( buffer, 3);

			buffer.Format("%d", wins2);
			file.Write( buffer, 1);

			int day = (m_currentRound-1)*7 + g - 1;
			int game = i;
			m_sched[12][day][i] = team1*100 + team2;
			m_gameScore[12][day][i] = 0;

		}				
		}

}



void CPlayoff::WriteCareerTeamHistory()
{
	int points[33];//tracks points earned by a team staff in a season
	for(int i=0; i<=32;i++){points[i]=0;}
	CString	m_playoffFormat,m_rd1Format,m_rd2Format,m_rd3Format,m_rd4Format,m_conferenceName1,
		m_conferenceName2,m_divisionName1,m_divisionName2,m_divisionName3,m_divisionName4;

  	CString file_name = m_path + m_leagueName + ".sch";
	

//	LoadStandings(file_name, 
//		m_playoffFormat,m_rd1Format,m_rd2Format,m_rd3Format,m_rd4Format,m_conferenceName1,
  //		m_conferenceName2,m_divisionName1,m_divisionName2,m_divisionName3,m_divisionName4);
	int seek = 72001;
	CFile file( file_name,  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		int m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffGame = i;
		int round = 1;
		bool round_over = false;
		int wins_needed = 0;
		int champions = 0;
		bool champs_found = false;
		bool started = false;
		bool rd_started = false;
		CString format = format1;

		CString result;
		CString matchup;
		CString round_string;
		CString champs;
		if(format != "")//no playoffs
		{
		for(int  j = 0; j <= 27; j++ )//28 playoff days
		{
			if(j>=21 && format4 == "" || j>=14 && format3 == "" || j>=7 && format2 == "") continue;

			if(j == 6 || j == 13 || j == 20 || j == 27)
				round_over = true;
			else 
				round_over = false;

			if(j == 7 || j == 14 || j == 21 || j == 28)
				rd_started = false;

			if(j == 7)
				round = 2;
			else if(j == 14)
				round = 3;
			else if(j == 21)
				round = 4;

			if(j>=0 && j<=6)
				format = format1.GetAt(0);
			else if(j>=7 && j<=13)
				format = format2.GetAt(0);
			else if(j>=14 && j<=20)
				format = format3.GetAt(0);
			else if(j>=21 && j<=27)
				format = format4.GetAt(0);
			
			wins_needed = atoi(format);
			for(int  k = 0; k <= 7; k++ )//8 max plaoff games per day
			{
				CString series_won = "";
				char s[7];

				int seek = 72046 + j*96 + k*12;
				file.Seek(seek, CFile::begin );
				
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team1 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score1 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win1 = atoi(s);

				
				bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team2 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score2 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win2 = atoi(s);

				CString round_desc;
				int max = 0;//max points earned by staff member
				if(round == m_playoffRounds)
				{
					round_desc = "championship";
					max = 4;
				}
				else if(round == (m_playoffRounds-1))
				{
					round_desc = "semi-finals";
					max = 2;
				}
				else if(round == (m_playoffRounds-2))
				{
					round_desc = "quarter-finals";
					max = 1;
				}
				else if(round == (m_playoffRounds-3))
				{
					round_desc = "first round";
					max = 1;
				}
				

				if(team1 > 0 && team2 > 0)
				{
					int rec_win1 = record[team1-1].m_leagueRecord / 100;
					int rec_loss1 = record[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = record[team2-1].m_leagueRecord / 100;
					int rec_loss2 = record[team2-1].m_leagueRecord - rec_win2 * 100;
					CString teamName1 = m_leagueTeamNames[team1-1];
					CString teamName2 = m_leagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;
					if(win2 > win1)
					{
						CString temp = teamName1;
						teamName1 = teamName2;
						teamName2 = temp;
						int tmp = win1;
						win1 = win2;
						win2 = tmp;

						tmp = team1;
						team1 = team2;
						team2 = tmp;

						tmp = rec_win1;
						rec_win1 = rec_win2;
						rec_win2 = tmp;

						tmp = rec_loss1;
						rec_loss1 = rec_loss2;
						rec_loss2 = tmp;
						
					}


					if(score2 > score1)
					{
						CString temp = teamNameScore1;
						teamNameScore1 = teamNameScore2;
						teamNameScore2 = temp;
						int tmp = score1;
						score1 = score2;
						score2 = tmp;
					}

					if(win1 == wins_needed || win2 == wins_needed)
					{
						series_won = " defeat the ";
						if(m_playoffRounds == round) champions = team1;
					}
					
					if(win1 > 1 && series_won == " defeat the ")
					{
						result.Format("%s (%d-%d) %s %s (%d-%d) %d games to %d in the %s", teamName1, rec_win1, rec_loss1, series_won ,teamName2, rec_win2, rec_loss2, win1,win2, round_desc);
						CString loser;
						loser.Format("%s (%d-%d) lose to the %s (%d-%d) %d games to %d in the %s", teamName2, rec_win2, rec_loss2, teamName1, rec_win1, rec_loss1, win1,win2,round_desc);
						m_result[team1-1] = result;
						if(m_playoffRounds == round)
							record[team1-1].m_ring = true;
						points[team1-1] = points[team1-1]+max;
						m_result[team2-1] = loser;
						record[team1-1].m_playoff = true;
						record[team2-1].m_playoff = true;

					}
					else if(series_won == "defeat the ")
					{
						result.Format("%s (%d-%d) %s %s (%d-%d) %d game to %d in the %s", teamName1, rec_win1, rec_loss1, series_won ,teamName2, rec_win2, rec_loss2, win1,win2, round_desc);
						CString loser;
						loser.Format("%s (%d-%d) lose to the %s (%d-%d) %d game to %d in the %s", teamName2, rec_win2, rec_loss2, teamName1, rec_win1, rec_loss1, win1,win2,round_desc);
						m_result[team1-1] = result;
						if(m_playoffRounds == round)
							record[team1-1].m_ring = true;
						points[team1-1] = points[team1-1]+max;
						m_result[team2-1] = loser;
						record[team1-1].m_playoff = true;
						record[team2-1].m_playoff = true;
					}
					
					if(score1 > 0)
					{
						started = true;
						rd_started = true;
					}
				}
			}

		}

		}
		else//no playoffs
		{
						CString string;
						string.Format("No playoff scheduled for the league %s", m_leagueName);
		}
		for(int i=0; i<=32; i++)
		{
			if(m_result[i] != "") record[i].m_points = points[i];
			if(m_result[i] != "") continue;			

			int win = record[i].m_leagueRecord / 100;
			int loss = record[i].m_leagueRecord - win * 100;
			m_result[i].Format("%s (%d-%d)", m_leagueTeamNames[i], win, loss);
			if(m_leagueTeamNames[i] == "") m_result[i] = "";
			
		}

	    WriteTeamHistoryFile();
}

void CPlayoff::WriteTeamHistoryFile()
{
	CFileStatus status;
	CString fileName = m_path + m_leagueName + ".his";
	char buffer[4001];
	int seek = 0;
	if( CFile::GetStatus( fileName, status ) == FALSE) // create file for hall of fame
	{
		CFile f( fileName, CFile::modeCreate | CFile::modeWrite );
		memset( buffer, ' ', 4000);		
		f.Write( buffer, 4000);
		f.Close();
	}
	else // increase file size
	{
	    CStdioFile f( fileName, CFile::modeWrite );
		seek = (int)f.GetLength();
		f.SetLength(seek + 4000);
		f.Seek( seek, CFile::begin);
		memset( buffer, ' ', 4000);		
		f.Write( buffer, 4000);	
		f.Close();
	}
	CStdioFile fi( fileName, CFile::modeWrite );
	fi.Seek( seek, CFile::begin);

	for(int i=0; i<=32; i++)
	{
		CString string;
		string.Format("%s (%d)", m_result[i], m_currentYear);
		fi.WriteString( string + "\n");		
	}

	fi.Close(); 
}



int CPlayoff::ReadPlayoffResults(CString pFileName, CString LeagueTeamNames[33])
{
		int count = 0;
		int seek = 72001;

		CFile file( pFileName,  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		int m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffGame = i;
		int round = 1;
		bool round_over = false;
		int wins_needed = 0;
		int champions = 0;
		bool champs_found = false;
		bool started = false;
		bool rd_started = false;
		CString format = format1;
		if(format != "")//no playoffs
		{
		for(int  j = 0; j <= 27; j++ )//28 playoff days
		{
			if(j>=21 && format4 == "" || j>=14 && format3 == "" || j>=7 && format2 == "") continue;

			if(j == 6 || j == 13 || j == 20 || j == 27)
				round_over = true;
			else 
				round_over = false;

			if(j == 7 || j == 14 || j == 21 || j == 28)
				rd_started = false;

			if(j == 7)
				round = 2;
			else if(j == 14)
				round = 3;
			else if(j == 21)
				round = 4;

			if(j>=0 && j<=6)
				format = format1.GetAt(0);
			else if(j>=7 && j<=13)
				format = format2.GetAt(0);
			else if(j>=14 && j<=20)
				format = format3.GetAt(0);
			else if(j>=21 && j<=27)
				format = format4.GetAt(0);
			
			wins_needed = atoi(format);
			for(int  k = 0; k <= 7; k++ )//8 max plaoff games per day
			{
				char s[7];

				int seek = 72046 + j*96 + k*12;
				file.Seek(seek, CFile::begin );
				
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team1 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score1 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win1 = atoi(s);

				
				bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team2 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score2 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win2 = atoi(s);

				CString result;
				if(team1 > 0 && team2 > 0)
				{
					int rec_win1 = record[team1-1].m_leagueRecord / 100;
					int rec_loss1 = record[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = record[team2-1].m_leagueRecord / 100;
					int rec_loss2 = record[team2-1].m_leagueRecord - rec_win2 * 100;
					CString matchup;
					CString teamName1 = LeagueTeamNames[team1-1];
					CString teamName2 = LeagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;
					CString series_won = " lead the ";
					matchup.Format("%s %d-%d at %s %d-%d", teamName1, rec_win1, rec_loss1,
						teamName2, rec_win2, rec_loss2);
					if(score2 != score1 )
					{
						list[count] = matchup;
						count = count + 1;
					}
					if(win1 == win2) series_won = " are tied with the ";
					if(win2 > win1)
					{
						CString temp = teamName1;
						teamName1 = teamName2;
						teamName2 = temp;
						int tmp = win1;
						win1 = win2;
						win2 = tmp;
						tmp = team1;
						team1 = team2;
						team2 = tmp;
					}


					if(score2 > score1)
					{
						CString temp = teamNameScore1;
						teamNameScore1 = teamNameScore2;
						teamNameScore2 = temp;
						int tmp = score1;
						score1 = score2;
						score2 = tmp;
					}

					if(win1 == wins_needed || win2 == wins_needed)
					{
						series_won = " defeat the ";
						if(m_playoffRounds == round) champions = team1;
					}
					
					CString show_score;
					CString desc;

					if((score1 - score2) <= 3) desc = " edge out the "; 
					else if((score1 - score2) <= 7) desc = " get by the  "; 
					else if((score1 - score2) <= 14) desc = " beat the"; 
					else if((score1 - score2) <= 21) desc = " win easily over the "; 
					else if((score1 - score2) <= 35) desc = " blow out the "; 
					else desc = " humiliate the "; 

					show_score.Format("%s %s %s %d-%d", teamNameScore1, desc, teamNameScore2, score1, score2);
					if(win1 > 1 && series_won != " defeat the ")
						result.Format("%s %s %s %d games to %d ", teamName1, series_won ,teamName2,win1,win2);
					else if(win1 > 1 && series_won == " defeat the ")
						result.Format("*** %s %s %s %d games to %d ***", teamName1, series_won ,teamName2,win1,win2);
					else
						result.Format("%s %s %s %d game to %d ", teamName1, series_won ,teamName2,win1,win2);
					
					if(score1 > 0)
					{
						started = true;
						rd_started = true;
											
						list[count] = show_score;
						count = count + 1;
						list[count] = result;
						count = count + 1;
						list[count] = "";
						count = count + 1;
					
					}
				}
			}
					CString round_string;
					if(round != m_playoffRounds && round_over == true && rd_started == true && m_currentRound > round)
						round_string.Format("*** Round %d completed ***", round); 

					
					if(round_over == true && champs_found == false && round == m_playoffRounds && champions > 0)
					{
						CString champs;
						champs_found = true;
						champs.Format("%s win the %s league championship", LeagueTeamNames[champions-1], m_leagueName); 
						list[count] = champs;
						count = count + 1;
						list[count] = "";
						count = count + 1;

						round_string.Format("*** End of playoffs ***"); 
					}

					if(round_over == true && started == true)
					{
						list[count] = round_string;
						count = count + 1;
						list[count] = "";
						count = count + 1;
					}
					else if(round_over == true && round == 1 && started == false)
					{
						CString string;
						string.Format("No playoff results for the league %s", m_leagueName);
						list[count] = string;
						count = count + 1;

					}
		}

		}
		else//no playoffs
		{
						CString string;
						string.Format("No playoff scheduled for the league %s", m_leagueName);
						list[count] = string;
						count = count + 1;

		}


	return count;
}




void CPlayoff::SetAllPlayoffTeams( bool conferencePlayoff, int teamsPer,
	CString m_conferenceName1,
	CString m_conferenceName2,
	CString m_divisionName1,
	CString m_divisionName2,
	CString m_divisionName3,
	CString m_divisionName4)
{
	int playoffTeams = 0;
	if(conferencePlayoff == true)
	{
		int t = 0;
		do
		{
			if(m_conferenceName1 == record[t].m_conference)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer);
		t = 0;
		do
		{
			if(m_conferenceName2 == record[t].m_conference)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*2 && t<=31);
	}
	else
	{

		int t = 0;
		do
		{
			if(m_divisionName1 == record[t].m_division)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer && t<=31);
		t = 0;
		do
		{
			if(m_divisionName2 == record[t].m_division)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*2 && t<=31);
		t = 0;
		do
		{
			if(m_divisionName3 == record[t].m_division)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*3 && t<=31);
		t = 0;
		do
		{
			if(m_divisionName4 == record[t].m_division)
			{
				record[t].m_playoff_team = true;
				playoffTeams = playoffTeams + 1;
			}
			t = t + 1;
		
		} while (playoffTeams < teamsPer*4 && t<=31);



	}

}







void CPlayoff::GetPlayoffMatchupWins(CString file_name,
	int visitor, int home)
{

		BOOL CurrentGame = FALSE; 
		int teams_in_next_game = visitor*100 + home;
	
	
		int seek = 72001;
		bool series_winner[33];
		int no_more_in_round[33];//series loser and day team lost
		int playoff_teams[17];
		for(int i=0; i<=32; i++){series_winner[i] = false; no_more_in_round[i] = 0;}
		for(int i=0; i<=16; i++){playoff_teams[i] = 0;}
		CFile file( file_name,  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		int m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffGame = i;
		CString games;
		CString next_rd_format;
		if(m_currentRound == 1)
		{
			games = format1 + "          ";
			next_rd_format = format2 + "           ";
		}
		else if(m_currentRound == 2)
  		{
			games = format2 + "          ";
			next_rd_format = format3 + "           ";
		}
		else if(m_currentRound == 3)
		{
			games = format3 + "          ";
			next_rd_format = format2 + "           ";
		}
		else if(m_currentRound == 4)
		{
			games = format4 + "          ";
		}

		CString gamesToWin = games.GetAt(0); 
		int wins_needed = atoi(gamesToWin);//wins to advance to next round

		i = 12;//playoff Month
		int series_round1 = 0;
		int teams = 0;
		for(int  j = 0; j <= 27; j++ )//28 playoff days
		{
			for(int  k = 0; k <= 7; k++ )//8 max plaoff games per day
			{
				char s[7];

				int seek = 72046 + j*96 + k*12;
				file.Seek(seek, CFile::begin );
				
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team1 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score1 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win1 = atoi(s);

				
				bytes = file.Read(s, 2);
				s[bytes] = 0;
				int team2 = atoi(s);

				bytes = file.Read(s, 3);
				s[bytes] = 0;
				int score2 = atoi(s);

				bytes = file.Read(s, 1);
				s[bytes] = 0;
				int win2 = atoi(s);


				bool round_ok = false;

				if(j==0 && team1>0 && m_currentRound == 1)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==7 && team1>0 && m_currentRound == 2)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==14 && team1>0 && m_currentRound == 3)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}
				else if(j==21 && team1>0 && m_currentRound == 4)
				{
					series_round1 = series_round1+1;
					playoff_teams[teams] = team1;
					playoff_teams[teams + 1] = team2;
					teams = teams + 2;
				}

		
				if(j>=0 && j<=6 && m_currentRound==1)
				{
					if(win1 == wins_needed)
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}
					else if(win2 == wins_needed)
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}
					round_ok = true;
				}
				else if(j>=7 && j<=13 && m_currentRound==2)
				{
					if(win1 == wins_needed)
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}
				else if(j>=14 && j<=20 && m_currentRound==3)
				{
					if(win1 == wins_needed)
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}
				else if(j>=21 && j<=27 && m_currentRound==4)
				{
					if(win1 == wins_needed)
					{
						series_winner[team1] = true;					
						no_more_in_round[team2] = j+1;
					}

					else if(win2 == wins_needed)
					{
						series_winner[team2] = true;					
						no_more_in_round[team1] = j+1;
					}

					round_ok = true;
				}

				int team_before1 = 0;
				int team_before2 = 0;
			

		
		bool seriesOver = false;		
		if(j != 0 && j != 7 && j != 14 && j != 21)
		{
			int seek_team1 = 72046 + (j - 1) * 96 + k * 12;
			file.Seek(seek_team1, CFile::begin );
			int bytes = file.Read(s, 2);
			s[bytes] = 0;
			team_before1 = atoi(s);

			int seek_score1 = 72046 + (j - 1) * 96 + k * 12 + 2;
			file.Seek(seek_score1, CFile::begin );
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			int sc1 = atoi(s);

			int seek_wins1 = 72046 + (j - 1) * 96 + k * 12 + 5;
			file.Seek(seek_wins1, CFile::begin );
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			win1 = atoi(s);

			int seek_team2 = 72046 + (j - 1) * 96 + k * 12 + 6;
			file.Seek(seek_team2, CFile::begin );
			bytes = file.Read(s, 2);
			s[bytes] = 0;
			team_before2 = atoi(s);

			int seek_score2 = 72046 + (j - 1) * 96 + k * 12 + 8;
			file.Seek(seek_score2, CFile::begin );
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			int sc2 = atoi(s);

			int seek_wins2 = 72046 + (j - 1) * 96 + k * 12 + 11;
			file.Seek(seek_wins2, CFile::begin );
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			win2 = atoi(s);


			if(sc1 == 0 && sc2 == 0) seriesOver = true;


			if(team_before1 != team1)
			{
				int temp = win1;
				win1 = win2;
				win2 = temp;
			}
			else if(win2 == wins_needed && round_ok == true) series_winner[team2] = true;
		}





				int matchup = team1*100 + team2;
				int score = score1*1000 + score2;
				if((no_more_in_round[team1] > 0 && j >= no_more_in_round[team1]) || (no_more_in_round[team2] > 0 && j>=no_more_in_round[team2]) && score == 0) matchup = 0;
				m_sched[i][j][k] = matchup;
				m_gameScore[i][j][k] = score;
				
	

				if(matchup == teams_in_next_game 
					&& score == 0 &&
					CurrentGame == FALSE && 
					win1 < wins_needed && win2 < wins_needed && seriesOver == false && round_ok == true)
				{
					m_win1 = win1; m_win2 = win2; m_team1 = team1; m_team2 = team2;
					CurrentGame = TRUE;
				}
			}
		}
		file.Close();

}





