#include "stdafx.h"
#include "bball.h"
#include "HistoryAwards.h"

void CHistoryAwards::InitClass()
{

	CFileStatus status;

	m_current_exp_count = 0;


	if( CFile::GetStatus( m_path + m_league_name + ".exp", status ) != FALSE) 
	{
	CFile file(	m_path + m_league_name + ".exp", CFile::modeRead);	
	CString buffer;
	char s[33];
	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	m_current_exp_count = atoi(s);

	}

	ReadOriginalNames();
	ReadAwards();
	ListMvp();
	List6th();
	ListPoMvp();
	ListDefense();
	ListRookie();
	ListPts();
	ListReb();
	ListAst();
	ListStl();
	ListBlk();
	ListChampion();
	Listdunkcontest();
	ListThreecontest();
	ListRookiestarMVP();
	ListAllstarMVP();

}

void CHistoryAwards::ListMvp()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_mvp[i]*2500 + 8; 
	
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_mvp_team_index[i]][exp_co];
    
    //if(name == "") continue;
		m_mvp_name[i] = name;
		m_mvp_po[i] = pos;
		m_mvp_team[i] = team;

	m_pointer[n] = m_mvp[i];
	n = n + 1;

}

	
}

void CHistoryAwards::List6th()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_6th[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_6th_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_6th_team_index[i]][exp_co];
    
//    if(name == "") continue;
		m_6th_name[i] = name;
		m_6th_po[i] = pos;
		m_6th_team[i] = team;
	m_pointer[n] = m_6th[i];
	n = n + 1;

}
	
}

void CHistoryAwards::ListPoMvp()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_po_mvp[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_po_mvp_team_index[i]][exp_co];
    
//    if(name == "") continue;
		m_po_mvp_name[i] = name;
		m_po_mvp_po[i] = pos;
		m_po_mvp_team[i] = team;

	m_pointer[n] = m_po_mvp[i];
	n = n + 1;


}
	
}

void CHistoryAwards::ReadAwards()
{
 CFile file(	m_file_name + ".awa", CFile::modeRead);	
	long size = (long)file.GetLength();
	long tmp = size / 1000;
	int lines = (int)tmp - 16;
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 5);
	s[bytes] = 0; 
	int start_yr = atoi(s);
 	

    for(int i=0; i< lines; i++)
	{


	int aw_seek = 1000 + i*1000;//starts at index 1000 for history (996 bytes unused)
	file.Seek( aw_seek, CFile::begin);

 	int bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_mvp[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_mvp_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_6th[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_6th_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_defense[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_defense_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_rookie[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_rookie_team_index[i] = atoi(s);


 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_pts[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_pts_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_pts_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_reb[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_reb_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_reb_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_ast[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_ast_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_ast_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_stl[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_stl_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_stl_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_blk[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_blk_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_blk_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_po_mvp[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_po_mvp_team_index[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_champ[i] = atoi(s);


 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_allstar[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_allstar_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_rookiestar[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_rookiestar_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_3contest[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_3contest_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_dunkcontest[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_dunkcontest_team_index[i] = atoi(s);





	aw_seek = 1000 + i*1000 + 995;
 	file.Seek( aw_seek, CFile::begin);

 		
	bytes = file.Read(s, 3);
	s[bytes] = 0; 
    CString check = CString(s);
	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    if(check == "clr") 
		m_exp_count[i] = atoi(s);
	else
		m_exp_count[i] = 0;

	if(m_exp_count[i] > m_current_exp_count) m_exp_count[i] = m_current_exp_count;

	}

	m_lines = lines;
    m_start_year = start_yr;	
}


void CHistoryAwards::ListDefense()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_defense[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_defense_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_defense_team_index[i]][exp_co];
    
//    if(name == "") continue;
		m_defense_name[i] = name;
		m_defense_po[i] = pos;
		m_defense_team[i] = team;

	m_pointer[n] = m_defense[i];
	n = n + 1;

}
}

void CHistoryAwards::ListRookie()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_rookie[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_rookie_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_rookie_team_index[i]][exp_co];
    
//    if(name == "") continue;

		m_rookie_name[i] = name;
		m_rookie_po[i] = pos;
		m_rookie_team[i] = team;

	m_pointer[n] = m_rookie[i];
	n = n + 1;

}
}

void CHistoryAwards::ListPts()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_pts[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_pts_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_pts_team_index[i]][exp_co];
		//m_blk_name[i] = name;
		//m_blk_po[i] = pos;
		//m_blk_team[i] = team;

    
    //if(name == "") continue;
	m_pointer[n] = m_pts[i];
	n = n + 1;

	//CString av;
	double f = (double)m_pts_avg[i] / 100;
	//av.Format("%.2f", f);
		m_pts_name[i] = name;
		m_pts_po[i] = pos;
		m_pts_team[i] = team;
		m_pts_avg[i] = f;


}
	//SetCursor();
}

void CHistoryAwards::ListReb()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_reb[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_reb_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_reb_team_index[i]][exp_co];
		
//		m_reb_name[i] = name;
//		m_reb_po[i] = pos;
//		m_reb_team[i] = team;
    
//    if(name == "") continue;
	m_pointer[n] = m_reb[i];
	n = n + 1;

//	CString av;
	double f = (double)m_reb_avg[i] / 100;
//	av.Format("%.2f", f);
		m_reb_name[i] = name;
		m_reb_po[i] = pos;
		m_reb_team[i] = team;
		m_reb_avg[i] = f;


}
}

void CHistoryAwards::ListAst()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_ast[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_ast_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_ast_team_index[i]][exp_co];
//		m_ast_name[i] = name;
//		m_ast_po[i] = pos;
//		m_ast_team[i] = team;
    
//    if(name == "") continue;
	m_pointer[n] = m_ast[i];
	n = n + 1;

	//CString av;
	double f = (double)m_ast_avg[i] / 100;
	//av.Format("%.2f", f);
		m_ast_name[i] = name;
		m_ast_po[i] = pos;
		m_ast_team[i] = team;
		m_ast_avg[i] = f;



}
}

void CHistoryAwards::ListStl()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_stl[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_stl_team_index[i]];
    		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_stl_team_index[i]][exp_co];

	//	m_stl_name[i] = name;
	//	m_stl_po[i] = pos;
	//	m_stl_team[i] = team;
//    if(name == "") continue;
	m_pointer[n] = m_stl[i];
	n = n + 1;

	//CString av;
	double f = (double)m_stl_avg[i] / 100;
	//av.Format("%.2f", f);
		m_stl_name[i] = name;
		m_stl_po[i] = pos;
		m_stl_team[i] = team;
		m_stl_avg[i] = f;

}
}

void CHistoryAwards::ListBlk()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
		long int seek = m_blk[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_blk_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_blk_team_index[i]][exp_co];
    

		m_pointer[n] = m_blk[i];
		n = n + 1;
		double f = (double)m_blk_avg[i] / 100;
		m_blk_name[i] = name;
		m_blk_po[i] = pos;
		m_blk_team[i] = team;
		m_blk_avg[i] = f;

}
}


void CHistoryAwards::ListChampion()
{

CString team;



for(int i=0; i < m_lines; i++)
{
	if(m_champ[i] <= 0) team = "";
	else
	{
		//team = m_league_team_names[m_champ[i] - 1];
		int exp_co = m_exp_count[i];
		team = m_original_names[m_champ[i] - 1][exp_co];
	}

    CString yr;
	yr.Format("%d", m_start_year + i);

    m_champ_team[i] = team;

}

}




void CHistoryAwards::ReadOriginalNames()
{
	for(int i=0; i<=32; i++)
	{
		m_original_names[i][m_current_exp_count] = m_league_team_names[i];
	}

	CString exp_name = m_path + m_league_name + ".exp";



	CFileStatus status;
	if( CFile::GetStatus( exp_name, status ) != FALSE) 
	{


	CFile file(	exp_name, CFile::modeRead);	
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	int exp_count = atoi(s);
	if(exp_count > 27) exp_count = 28;

	for(int t=1; t <= exp_count; t++)
	{
 	
	seek = 1100*t;//starts at index 1100 for expansion list team names
	file.Seek( seek, CFile::begin);

	for(int i=0; i<=32; i++)
	{
 		int bytes = file.Read(s, 32);
		s[bytes] = 0; 
		m_original_names[i][t-1] = CString(s);
	}

	}

	}
}


void CHistoryAwards::ListAllstarMVP()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
	long int seek = m_allstar[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_allstar_team_index[i]][exp_co];
		m_allstar_name[i] = name;
		m_allstar_po[i] = pos;
		m_allstar_team[i] = team;
    
 //   if(name == "") continue;
	m_pointer[n] = m_allstar[i];
	n = n + 1;


}
	
}

void CHistoryAwards::ListRookiestarMVP()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
	long int seek = m_rookiestar[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_rookiestar_team_index[i]][exp_co];
		m_rookiestar_name[i] = name;
		m_rookiestar_po[i] = pos;
		m_rookiestar_team[i] = team;
    
//    if(name == "") continue;
	m_pointer[n] = m_rookiestar[i];
	n = n + 1;


}
	

}

void CHistoryAwards::ListThreecontest()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
	long int seek = m_3contest[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_3contest_team_index[i]][exp_co];

		m_3contest_name[i] = name;
		m_3contest_po[i] = pos;
		m_3contest_team[i] = team;

		m_pointer[n] = m_3contest[i];
		n = n + 1;


}
	
}

void CHistoryAwards::Listdunkcontest()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;

for(int i=0; i < m_lines; i++)
{
	long int seek = m_dunkcontest[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_dunkcontest_team_index[i]][exp_co];
		m_dunkcontest_name[i] = name;
		m_dunkcontest_po[i] = pos;
		m_dunkcontest_team[i] = team;
    
	m_pointer[n] = m_dunkcontest[i];

	n = n + 1;

}
	

}
