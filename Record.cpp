#include "stdafx.h"
#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 






void CRecord::ClearTeamStandings(int i)
{
	for(int y=1; y<=32; y++)
	{
		m_vsOpponent[y] = 0; //set vs. opponent to 0
	}

	m_leagueRecord = 0;
	m_visitorRecord = 0;
	m_homeRecord = 0;
	m_divisionRecord = 0;
	m_conferenceRecord = 0;
	m_leaguePct = 0;
	m_leagueGamesBack = 0;
	m_divisionPct = 0;
	m_conferencePct = 0;

	m_playoff_team = false;
	m_initialNumber = i;
	m_playoff = false;
	m_ring = false;

}