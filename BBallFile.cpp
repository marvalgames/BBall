#include "stdafx.h"

//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef BBallFile_h
#include "BBallFile.h"
#define BBallFile_h
#endif 







bool CBBallFile::FileExists(CString file_name)
{
	bool exists = true;
	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) exists = 0;
	return exists;
}

void CBBallFile::CreateBlankFile(CString file_name, int size)
{
	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) 
	{
		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[600001];
		memset( buffer, ' ', size);
		file.Write( buffer, size);
		file.Close();
	}
}

void CBBallFile::DeleteFile(CString file_name)
{
	CFile fil;
	CFileStatus status;
	if( CFile::GetStatus( file_name, status )) fil.Remove(file_name);
}

void CBBallFile::IncreaseFileSize(CString file_name, int size)
{
	CFile file(	file_name, CFile::modeReadWrite);	
	int seek = (int)file.GetLength();
	file.SetLength(seek + size);
	char buffer[600001];
	file.Seek( seek, CFile::begin);
	memset( buffer, ' ', size);		
	file.Write( buffer, size);
	file.Close(); 
}

void CBBallFile::WriteAwardHistoryFile(CString file_name, CString exp_file_name, int current_year,
								  int mvp[11], int mvp_team_index[11],
								  int sth[11], int sth_team_index[11],
								  int defense[11], int defense_team_index[11],
								  int rookie[11], int rookie_team_index[11],
								  int pts[11], int pts_team_index[11], int pts_avg[11],
								  int reb[11], int reb_team_index[11], int reb_avg[11],
								  int ast[11], int ast_team_index[11], int ast_avg[11],
								  int stl[11], int stl_team_index[11], int stl_avg[11],
								  int blk[11], int blk_team_index[11], int blk_avg[11],
								  int po_mvp, int po_mvp_team_index,
								  int winner, int loser, int win, int loss,
									int allstar, int allstar_index, int rookiestar, int rookiestar_index, int three, int three_index, int dunk, int dunk_index
								  
								  )
{


	int exp_count = ReadCurrentExpansionCount(exp_file_name);


	CFile file(	file_name, CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 5);
	s[bytes] = 0; 
	int start_yr = atoi(s);
	if(start_yr == 0) start_yr = current_year;
	buffer.Format("%d", start_yr);
	buffer = buffer + "    ";
 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 4);

	int current_award_year = current_year - start_yr;
	





	int aw_seek = 1000 + current_award_year*1000;//starts at index 1000 for history (996 bytes unused)
	file.Seek( aw_seek, CFile::begin);

	//write ids of players here
	
	
	for(int i=1; i<=5; i++)
	{
	    buffer.Format("%d", mvp[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", mvp_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", sth[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", sth_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", defense[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", defense_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", rookie[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", rookie_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", pts[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", pts_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", pts_avg[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 4);  

	    buffer.Format("%d", reb[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", reb_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", reb_avg[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 4);  

	    buffer.Format("%d", ast[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", ast_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", ast_avg[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 4);  

	    buffer.Format("%d", stl[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", stl_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", stl_avg[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 4);  

	    buffer.Format("%d", blk[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", blk_team_index[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", blk_avg[i]);
	    buffer = buffer + "       ";
	    file.Write(buffer, 4);  

	    buffer.Format("%d", po_mvp);//saves only once (5 copies) for playoffs mvp
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", po_mvp_team_index);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

		if(i == 1)
		{
	    buffer.Format("%d", winner);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", allstar);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", allstar_index);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", rookiestar);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", rookiestar_index);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", three);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", three_index);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer.Format("%d", dunk);
	    buffer = buffer + "       ";
	    file.Write(buffer, 6);  

	    buffer.Format("%d", dunk_index);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  


		}
		else if(i == 2)
		{
	    buffer.Format("%d", loser);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  


	    buffer = buffer + "                                                        ";
	    file.Write(buffer, 32);  

		}
		else if(i == 3)
		{
	    buffer.Format("%d", win);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer = buffer + "                                                        ";
	    file.Write(buffer, 32);  


		}
		else if(i == 4)
		{
	    buffer.Format("%d", loss);
	    buffer = buffer + "       ";
	    file.Write(buffer, 2);  

	    buffer = buffer + "                                                        ";
	    file.Write(buffer, 32);  




		}
		else if(i == 5)
		{
	    buffer = buffer + "                                                        ";
	    file.Write(buffer, 34);  

		}


    }	

	aw_seek = 1000 + current_award_year*1000 + 995;
	file.Seek( aw_seek, CFile::begin);
	buffer.Format("clr%d", exp_count);//write clr to clear out not meaningful data
	buffer = buffer + "       ";
	file.Write(buffer, 5);  

}


int CBBallFile::ReadCurrentExpansionCount(CString file_name)
{
	int exp_count = 0;

	if(FileExists(file_name) == true)
	{

	CFile file(	file_name, CFile::modeRead);	
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	exp_count = atoi(s);
	}
	return exp_count;
	
}


void CBBallFile::CreateHugeBlankFile(CString file_name, int times)
{

	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) 
	{

		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[500001];
		for(int i=1; i<=times; i++)
		{
			memset( buffer, ' ', 500000);
			file.Write( buffer, 500000);
		}
		file.Close();
	}
}

void CBBallFile::OpenRookies(CString file_name, CPlayer *Rookies)
{
    CFile file( file_name, CFile::modeRead);

	for(int  n = 1; n <= 96; n++ )
	{
		
		file.Seek((n-1)*200, CFile::begin );
		CPlayer	m_player; 
		char s[33];
		int bytes = file.Read(s, 2);
		s[bytes] = 0;
		int i = atoi(s);
		m_player.SetRosterNumber(i);
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString nm = CString(s);
	    nm.TrimRight();
		m_player.SetName(nm);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetAge(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int pot1 = atoi(s);
		m_player.SetPot1(pot1);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int pot2 = atoi(s);
		m_player.SetPot2(pot2);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int effort = atoi(s);
		m_player.SetEffort(effort);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int prime = atoi(s);
		m_player.SetPrime(prime);


		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString Position = CString(s);
		m_player.SetPos(Position);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetGames(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetMin(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetFgm(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetFga(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetFtm(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetFta(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTfgm(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTfga(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetOreb(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetReb(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetAst(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetStl(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTo(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetBlk(i);
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPf(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetMovOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetMovDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPenOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPenDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPostOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPostDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTransOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTransDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetClutch(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetConsistency(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPgRot(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetSgRot(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetSfRot(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPfRot(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetCRot(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetActive(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetBetter(i);
		m_player.SetTrueRatingSimple(2);
		m_player.SetTradeTrueRating(0);
		m_player.SetTradeValue();

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_coach_factor = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_loyalty_factor = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_playing_time_factor = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_winning_factor = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_tradition_factor = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_security_factor = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_height = i;

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		int j = atoi(s);
		m_player.m_weight = j;

		//if(i==0 || j==0) m_player.GenerateRandomHeightWeight();


		Rookies[n] = m_player;
	}
	file.Close();
}

void CBBallFile::ReadFutureFile(CFuture *m_future, CString file_name)
{
	
	CFile file( file_name, CFile::modeRead);
	char s[33];
	for(int t=0; t<=99; t++)
	{
		int seek = t*1000;
		file.Seek(seek, CFile::begin );
		int bytes = 0;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		int i = atoi(s);
		m_future[t].m_move_year = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_initial_move_year = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_new_city = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_capacity = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_club_seats = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_suites = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_parking_spots = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_team_cost = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_city_cost = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_game_new_arena_expense = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		m_future[t].m_yrs_since_move = i;

	}	
	file.Close();

}




void CBBallFile::WriteFutureFile(CFuture *m_future, CString file_name)
{
	CString buffer;

	CFile file(	file_name, CFile::modeWrite);
	for(int t=0; t<=99; t++)
	{	

		int seek = t*1000;
		file.Seek(seek, CFile::begin );


		buffer.Format("%d", m_future[t].m_move_year);
		buffer = buffer + "               ";
		file.Write( buffer, 10);

		buffer.Format("%d", m_future[t].m_initial_move_year);
		buffer = buffer + "               ";
		file.Write( buffer, 10);

		buffer.Format("%d", m_future[t].m_new_city);
		buffer = buffer + "               ";
		file.Write( buffer, 10);	

	
		buffer.Format("%d", m_future[t].m_capacity);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_club_seats);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_suites);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_parking_spots);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_team_cost);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_city_cost);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_game_new_arena_expense);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_future[t].m_yrs_since_move);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
	
	}
file.Close();	


}


void CBBallFile::WriteRookieFile(CString file_name, CPlayer *Rookies)
{

	CFile file(	file_name, CFile::modeWrite	);
	int players = 96;

	for(  int i = 1; i <= players; ++i )
	{
		file.Seek((i-1)*200, CFile::begin ); 
		CPlayer m_player = Rookies[i];//rookie list passed to first 96 players

		
		CString buffer;
		buffer.Format("%d", i);
		file.Write( buffer, 2);
		CString Name;
	    Name = m_player.GetName() 
			+ "                                 ";
		file.Write(	Name, 16);
		buffer.Format("%d", m_player.GetAge());
		buffer = buffer + "                ";
		file.Write( buffer, 2);

		int pot1 = m_player.GetPot1();
		int pot2 = m_player.GetPot2();
		int eff = m_player.GetEffort();



		
		buffer.Format("%d", pot1);
		buffer = buffer + "                ";
		file.Write( buffer, 2);
		buffer.Format("%d", pot2);
		buffer = buffer + "                ";
		file.Write( buffer, 2);
		buffer.Format("%d", eff);
		buffer = buffer + "                ";
		file.Write( buffer, 2);

		int age = m_player.GetPrime();
		buffer.Format("%d", age);
		buffer = buffer + "                ";
		file.Write( buffer, 2);

		file.Write(	m_player.GetPos(), 2);
		buffer.Format("%d", m_player.GetGames());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMin());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
        int min_stl = int(double(m_player.GetMin())*.01);
		int stl = m_player.GetStl();
		if(stl < min_stl) stl = min_stl;
		int fgm = m_player.GetFgm();
		int fga = m_player.GetFga();
		double fgp = (double)fgm/(double)fga;
		if(fga>=3 && fgp <= .25) fgm = fga/4;
			
		buffer.Format("%d", fgm);
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", fga);
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetFtm());
		buffer = buffer + "                ";
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetFta());
		buffer = buffer + "                ";
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetTfgm());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTfga());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetOreb());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetReb());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetAst());
		buffer = buffer + "                ";
		file.Write( buffer, 4);

		buffer.Format("%d", stl);
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTo());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetBlk());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetPf());
		buffer = buffer + "                ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMovOff());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetMovDef());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenOff());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenDef());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostOff());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostDef());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransOff());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransDef());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetClutch());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetConsistency());
		buffer = buffer + "                ";
		file.Write( buffer, 1);		
		int pg = m_player.GetPgRot();		
		int sg = m_player.GetSgRot();		
		int sf = m_player.GetSfRot();		
		int pf = m_player.GetPfRot();		
		int  c = m_player.GetCRot();
		buffer.Format("%d", pg);
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", sg);
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", sf);
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", pf);
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", c);
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetActive());
		buffer = buffer + "                ";
		file.Write( buffer, 1);
		int better = 50;
		buffer = buffer + "                ";
		buffer.Format("%d", better);
		file.Write( buffer, 2);


		buffer.Format("%d", m_player.m_coach_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);

		

		buffer.Format("%d", m_player.m_loyalty_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);

		buffer.Format("%d", m_player.m_playing_time_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);
			
		buffer.Format("%d", m_player.m_winning_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);
			
		buffer.Format("%d", m_player.m_tradition_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);
			
		buffer.Format("%d", m_player.m_security_factor);
		buffer = buffer + "                ";
		file.Write(buffer, 1);
			
		buffer.Format("%d", m_player.m_height);
		buffer = buffer + "                ";
		file.Write(buffer, 2);
			
		buffer.Format("%d", m_player.m_weight);
		buffer = buffer + "                ";
		file.Write(buffer, 3);
			




	}
	file.Close();	
}


void CBBallFile::ResetSeasonFiles(CString file_name)
{
		CFile file;

		//have to zero out stats for resetting

		//remove league transactions
		CFileStatus status;

		CString pFileName = file_name + ".trn";
		if( CFile::GetStatus( pFileName, status )) file.Remove(pFileName);
		//remove season box scores
		pFileName = file_name + ".sco";
		if( CFile::GetStatus( pFileName, status )) file.Remove(pFileName);

		pFileName = file_name + ".bud";
		if( CFile::GetStatus( pFileName, status )) file.Remove(pFileName);


		DeleteFile(file_name + ".sch");
		CreateBlankFile(file_name + ".sch", 80000);
	
		DeleteFile(file_name + ".asw");
	
		//create stats files if necessary
		CreateBlankFile(file_name + ".trn", 64000);
		CreateBlankFile(file_name + ".bud", 110000);
		CreateHugeBlankFile(file_name + ".sco", 16);
}
