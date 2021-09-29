#include "stdafx.h"

#include "bball.h"


#include "ImpExp.h"

#include <direct.h>
	  

void CImpExp::WriteDirectory(CString file_name)
{
	_mkdir(file_name);
	
}

void CImpExp::CreateGamePlanString(CPlayer m_player, int index)
{
	CString buffer[256];
	CString Name = m_player.GetName(); 
	Name.TrimLeft();
	Name.TrimRight();
	buffer[0].Format("%s,", Name);	
	buffer[1].Format("%d,", m_player.m_pgrot);
	buffer[2].Format("%d,", m_player.m_sgrot);
	buffer[3].Format("%d,", m_player.m_sfrot);
	buffer[4].Format("%d,", m_player.m_pfrot);
	buffer[5].Format("%d,", m_player.m_crot);
	buffer[6].Format("%d,", m_player.m_active);
	buffer[7].Format("%d,", m_player.m_game_minutes);
	buffer[8].Format("%d,", m_player.m_offensive_focus);
	buffer[9].Format("%d,", m_player.m_defensive_focus);
	buffer[10].Format("%d,", m_player.m_offensive_intensity);
	buffer[11].Format("%d,", m_player.m_defensive_intensity);
	buffer[12].Format("%d", m_player.m_play_maker);


		CString write_string;
		for(int y=0; y<=12; y++)
		{
			write_string = write_string + buffer[y];
		}
			
		m_game_plan_strings[index] = write_string;

}

void CImpExp::ExportGamePlan(CString file_name)
{

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == 0) 
	{
		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[256];
		memset( buffer, ' ', 1);
		file.Write( buffer, 1);
		file.Close();
	}

	CString buffer[256];
	CStdioFile fil( file_name, CFile::modeWrite );
	m_game_plan_strings[0] = "Name,PG,SG,SF,PF,C,ACTIVE,MIN,OF,DF,OI,DI";

	for(int i=0; i<=15; i++)
	{
		fil.WriteString( m_game_plan_strings[i] + "\n");		
	}
	fil.Close(); 
}

void CImpExp::ImportGamePlan(CString file_name)
{

		for(int i=0; i<=15; i++)
		{
			m_game_plan_strings[i] = "";
		}


	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) != 0) 
	{
		CStdioFile file(file_name, CFile::modeRead);

		for(int i=0; i<=15; i++)
		{
			CString str;
			file.ReadString( str);	
			m_game_plan_strings[i] = str + ",";
		}
		file.Close(); 
	}
}

void CImpExp::ConvertGamePlanString(CPlayer &m_player, int i)
{

	CString string = m_game_plan_strings[i];

		string.TrimLeft();
		string.TrimRight();

		int offset = 0;
		int index = string.Find(",", offset); 


	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 
	CString name = str;//just read do not set

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_pgrot = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_sgrot = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_sfrot = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_pfrot = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_crot = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_active = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_game_minutes = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_offensive_focus = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_defensive_focus = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_offensive_intensity = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_defensive_intensity = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_play_maker = atoi(str);


}


void CImpExp::ExportOffers(CString file_name, CString *m_offer_strings)
{

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == 0) 
	{
		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[256];
		memset( buffer, ' ', 1);
		file.Write( buffer, 1);
		file.Close();
	}

	CString buffer[256];
	CStdioFile fil( file_name, CFile::modeWrite );
	CString header = "";
	fil.WriteString( header + "\n");		

	for(int i=0; i<=14; i++)
	{
		fil.WriteString( m_offer_strings[i] + "\n");		
	}
	fil.Close(); 
}


bool CImpExp::ImportFaOffers(CString file_name, CString *strings)
{

	bool found = false;
	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) != 0) 
	{
		found = true;
		CStdioFile file(file_name, CFile::modeRead);
		CString str;
		file.ReadString( str);	

		for(int i=0; i<=15; i++)
		{
			CString str;
			file.ReadString( str);	
			strings[i] = str + ",";
		}
		file.Close(); 
	}
	return found;
}
