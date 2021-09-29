// GamePlan.cpp: implementation of the CGamePlan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"


#ifndef GamePlan_h
#include "GamePlan.h"
#define GamePlan_h
#endif 

//#include "GamePlan.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGamePlan::CGamePlan()
{

}

CGamePlan::~CGamePlan()
{

}

void CGamePlan::InitGamePlans(CString plan_file_name)
{
	ReadGamePlan(plan_file_name);
	GenerateGamePlans();


}

void CGamePlan::ReadGamePlan(CString file_name)
{
	CStdioFile file(file_name, CFile::modeRead);
	CString str;
	for(int i = 0; i<=32; i++)
	{
		file.ReadString(str);
		str.TrimRight();
		m_save_plan[i] = str;		
	}
	file.Close();
}

void CGamePlan::GenerateGamePlans()
{

	for(int t=0; t<=31; t++)
	{
		for(int c = 1; c<=30; c=c+1)
		{
			int slot = t*30 + c;
			CPlayer m_player = avg.m_actual[slot];
			CString str = m_save_plan[t];
			str = str + "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ";

			CString buf = str.Mid(0 + (c-1)*12,2);
			m_player.m_game_minutes = atoi(buf);

			buf = str.Mid(2 + (c-1)*12,2);
			m_player.m_offensive_focus = atoi(buf);

			buf = str.Mid(4 + (c-1)*12,2);
			m_player.m_defensive_focus = atoi(buf);

			buf = str.Mid(6 + (c-1)*12,2);
			m_player.m_offensive_intensity = atoi(buf);

			buf = str.Mid(8 + (c-1)*12,2);
			m_player.m_defensive_intensity = atoi(buf);

			buf = str.Mid(10 + (c-1)*12,2);
			m_player.m_play_maker = atoi(buf);



			avg.m_actual[slot] = m_player;
		}


	}



}

void CGamePlan::CreateDataForSavingGamePlans()
{

	for(int i=0; i<=31; i++)
	{
		CString line = "";
		for(int p=1; p<=30; p++)
		{
			CPlayer player = avg.m_actual[i*30+p];
			CString string;
			string.Format("%2d%2d%2d%2d%2d%2d", player.m_game_minutes, player.m_offensive_focus, player.m_defensive_focus, player.m_offensive_intensity, player.m_defensive_intensity, player.m_play_maker);
			line = line + string;
		}
		m_save_plan[i] = line;
	}

}

/*void CGamePlan::ComputerAdjustsGamePlan(CString control[33])
{
	for(int i=1; i<=1440; i++)
	{
		int team = (i-1)/30;
		if(team > 32) team = 32;
		if(team == 32 || control[team] != "Player")
		{
			avg.m_actual[i].m_game_minutes = 0;
			avg.m_actual[i].m_offensive_focus = 0;
			avg.m_actual[i].m_defensive_focus = 0;
			avg.m_actual[i].m_offensive_intensity = 0;
			avg.m_actual[i].m_defensive_intensity = 0;
		}
	}




}*/
