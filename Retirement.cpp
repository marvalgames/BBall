#include "stdafx.h"
//#include "constants.h"
#include "bball.h"

//#include "constants.h"
//#include "resource.h"

#ifndef Retirement_h
#include "Retirement.h"
#define Retirement_h
#endif 






void CRetirement::SetRetirements(int hi_fga, int hi_fta, int hi_tga, int hi_orb, int hi_drb, int hi_ast, int hi_stl, int hi_to, int hi_blk)
{
	int n=0;
	int t=0;
	int p=1;

//	avg.SetHighs(false);
	
	for(int i=0; i<=1440; i++)
	{
		double f = .0005;
		int age = avg.m_actual[i].GetAge();
		avg.m_actual[i].SetRatings(hi_fga, hi_fta, hi_tga, hi_orb, hi_drb, hi_ast, hi_stl, hi_to, hi_blk);	
		if((avg.m_actual[i].GetPrime()+5) < age)
		{
			f = double(avg.m_actual[i].GetAge()) - double(avg.m_actual[i].GetPrime());
			f = (f + avg.m_actual[i].GetTradeTrueRating(TRUE))/250.;
		}
		if(age > 40) f = f*(age - 39);
        CPlayer m_player = avg.m_actual[i];
        bool ok = (m_player.GetPrFga() >= 3 && m_player.GetPrFta() >= 3 && m_player.GetPrFgp() >= 25);


		if(((avg.Random(1) < f && avg.m_actual[i].GetName() != "") || (ok == false && avg.m_actual[i].GetName() != "")) && avg.m_actual[i].m_pos != "") 
		{
			//SetRetiredPlayer
			avg.m_actual[i].m_retired = true;
			n = n+1;
			m_retired_list_id[n] = avg.m_actual[i].m_id;
			m_retired_list_name[n] = avg.m_actual[i].m_name;
		}
		else
		{
			avg.m_actual[i].m_retired = false;
		}

	}
	m_retirement_count = n;
}

void CRetirement::WriteRetirements()
{
	CString file_name = m_path + m_league_name + ".ret";

	CFile fil;
	CFileStatus status;
	if( CFile::GetStatus( file_name, status )) fil.Remove(file_name);

	CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
	char buffer[600001];
	memset( buffer, ' ', 16000);
	file.Write( buffer, 16000);
	file.Close();

	CStdioFile fi( file_name, CFile::modeWrite );
	for(int i=1; i<=32; i++)
	{
		CString string;
		string.Format("%s %d", m_retired_list_name[i], m_retired_list_id[i]);
		fi.WriteString( string + "\n");		
	}
	fi.Close();     

}

void CRetirement::ReadRetirements()
{

	CString pFileName = m_path + m_league_name + ".ret";

  	CStdioFile file(pFileName, CFile::modeRead);

	for(int i = 1; i<=32; i++)
	{
		file.ReadString(m_read_retirement_strings[i]);
		m_read_retirement_strings[i].TrimRight();
	}
	
	file.Close();

}

void CRetirement::UpdatePlayerClass()
{
	for(int i=0; i<=1440; i++)
	{
		CString string;
		string.Format("%s %d", avg.m_actual[i].m_name, avg.m_actual[i].m_id);
		for(int j=1; j<=32; j++)
		{
			if(avg.m_actual[i].m_retired == true) continue;

			if(string == m_read_retirement_strings[j] && string != "" && string != " 0")
				avg.m_actual[i].m_retired = true;
			else
				avg.m_actual[i].m_retired = false;
		}
	}
}
