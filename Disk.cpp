#include "stdafx.h"

//#ifndef ProgressDlg1_h
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#ifndef BBallSettings_h
#include "BBallSettings.h"
#define BBallSettings_h
#endif 

#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 

#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 


void CDisk::WritePlayerData(CString m_file_name)
{



/*CString pFileName = m_file_name;;
CFile file(	pFileName, CFile::modeWrite	);
for(int t=0; t<=32; t++) //team 32 is free agents
{
	
	int players = 15;
	if(t == 32)
	{
		file.Seek(56001, CFile::begin );
		players = 96;
	}
	else
	{
		CString TeamName = m_leagueTeamNames[t] + "                                ";
		file.Write(TeamName, 32);
	}

	for(int  i = 1; i <= players; ++i )
	{
		CPlayer	m_player;
		
		if(t == 32 || (i != 15 && t < 32)) m_player = avg.m_actual[t*15+i];

		
		CString buffer;
		buffer.Format("%d", i);
		buffer = buffer + "               ";
		file.Write( buffer, 2);
		CString Name;
	    Name = m_player.GetName() 
			+ "                                 ";
		buffer = buffer + "               ";
		file.Write(	Name, 16);
		buffer.Format("%d", m_player.GetAge());
		buffer = buffer + "               ";
		file.Write( buffer, 2);
		buffer.Format("%d", m_player.GetID());
		buffer = buffer + "               ";
		file.Write( buffer, 9);
		buffer.Format("%d", m_player.m_team_paying);
		buffer = buffer + "               ";
		file.Write( buffer, 2);
		buffer.Format("%d", m_player.m_original_slot);
		buffer = buffer + "   ";
		file.Write( buffer, 3);
		buffer = buffer + "               ";
		file.Write(	m_player.GetPos(), 2);
		buffer.Format("%d", m_player.GetGames());
		buffer = buffer + "               ";
		file.Write( buffer, 2);
		buffer.Format("%d", m_player.GetMin());
		buffer = buffer + "               ";
		file.Write( buffer, 4);

		int adj = m_player.GetFgm() - m_player.GetTfgm();


		adj = adj*1 + m_player.GetTfgm();


		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 4);

		adj = m_player.GetFga() - m_player.GetTfga();
		adj = adj*1 + m_player.GetTfga();


		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 4);

		adj = m_player.GetFtm() * 1;
		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 4);		

		adj = m_player.GetFta() * 1;
		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 4);		

		buffer.Format("%d", m_player.GetTfgm());
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		buffer.Format("%d", m_player.GetTfga());
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		buffer.Format("%d", m_player.GetOreb());
		buffer = buffer + "               ";
		file.Write( buffer, 3);

		
		buffer.Format("%d", m_player.GetReb()); //put back




		buffer = buffer + "               ";
		file.Write( buffer, 4);
		adj = m_player.GetAst()*1;
		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetStl());
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		buffer.Format("%d", m_player.GetTo());
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		buffer.Format("%d", m_player.GetBlk());
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		adj = m_player.GetPf() * 1;
		buffer.Format("%d", adj);
		buffer = buffer + "               ";
		file.Write( buffer, 3);
		buffer.Format("%d", m_player.GetMovOff());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetMovDef());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenOff());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenDef());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostOff());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostDef());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransOff());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransDef());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetClutch());
		buffer = buffer + "               ";
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetConsistency());
		buffer = buffer + "               ";
		file.Write( buffer, 1);		
		int pg = m_player.GetPgRot();		
		int sg = m_player.GetSgRot();		
		int sf = m_player.GetSfRot();		
		int pf = m_player.GetPfRot();		
		int  c = m_player.GetCRot();
		buffer.Format("%d", pg);
		file.Write( buffer, 1);
		buffer.Format("%d", sg);
		file.Write( buffer, 1);
		buffer.Format("%d", sf);
		file.Write( buffer, 1);
		buffer.Format("%d", pf);
		file.Write( buffer, 1);
		buffer.Format("%d", c);
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetActive());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetBetter());
		file.Write( buffer, 2);
	}
}
file.Close();	




*/

}


void CDisk::WriteLeagueAverages(CString m_file_name)
{

CFile file(	m_file_name, CFile::modeWrite	);
int seek = 0;
file.Seek(seek, CFile::begin ); 



CString buffer;

buffer.Format("%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f",
				avg.m_avg_g[0],
				avg.m_avg_min[0],
				avg.m_avg_fgm[0],
				avg.m_avg_fga[0],
				avg.m_avg_fgp[0],
				avg.m_avg_fga_t[0],
				avg.m_avg_fgp_t[0],
				avg.m_avg_tgm[0],
				avg.m_avg_tga[0],
				avg.m_avg_tgp[0],
				avg.m_avg_ftm[0],
				avg.m_avg_fta[0],
				avg.m_avg_ftp[0],
				avg.m_avg_orb[0],
				avg.m_avg_drb[0],
				avg.m_avg_ast[0],
				avg.m_avg_stl[0],
				avg.m_avg_to[0],
				avg.m_avg_blk[0],
				avg.m_avg_pf[0],
				avg.m_avg_trade_tru[0]); 




file.Write(buffer, 512);


file.Close();

}



void CDisk::WriteLeagueHighs(CString m_file_name)
{

CStdioFile file(	m_file_name, CFile::modeWrite	);

CString buffer;
buffer.Format("2ga, %d", avg.m_hi_fga[0]);
file.WriteString( buffer + "\n");		
buffer.Format("fta, %d", avg.m_hi_fta[0]);
file.WriteString( buffer + "\n");		
buffer.Format("3ga, %d", avg.m_hi_tga[0]);
file.WriteString( buffer + "\n");		
buffer.Format("orb, %d", avg.m_hi_orb[0]);
file.WriteString( buffer + "\n");		
buffer.Format("drb, %d", avg.m_hi_drb[0]);
file.WriteString( buffer + "\n");		
buffer.Format("ast, %d", avg.m_hi_ast[0]);
file.WriteString( buffer + "\n");		
buffer.Format("stl, %d", avg.m_hi_stl[0]);
file.WriteString( buffer + "\n");		
buffer.Format("to, %d", avg.m_hi_to[0]);
file.WriteString( buffer + "\n");		
buffer.Format("blk, %d", avg.m_hi_blk[0]);
file.WriteString( buffer + "\n");		

file.Close();

}




void CDisk::WriteCareerContractFile(CString file_name, double tru_factor)
{






}

void CDisk::CreateEmptyFile(CString file_name, int size)
{
	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) 
	{
		CFile file( pFileName, CFile::modeCreate | CFile::modeWrite );
		char buffer[500001];
		memset( buffer, ' ', size);
		file.Write( buffer, size);
		file.Write( buffer, size);
		file.Close();
	}
}


void CDisk::ReadCareerContractFile(CString file_name)
{


    CFile file( file_name, CFile::modeRead);
	for(int  n = 0; n <= 1440; n++ )
	{
	  

		CPlayer m_player = avg.m_actual[n];

		int id = m_player.GetID();
		m_player.m_salary_id = id;
		int seek = 2000 + id*500 + 1; 
		file.Seek( seek, CFile::begin);

		char s[33];

		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString nm = CString(s);
	    nm.TrimRight();
		
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		bool j = true;
		if(i == 0) j = 0;
		m_player.m_random_contract_ratings = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_contracts = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_projections = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_yrs_service = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_pot1 = i;

	

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_pot2 = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_effort = i;

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
		int te = -1;

	



		m_player.m_current_team = te;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
	

		m_player.m_previous_team = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_yrs_of_service = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_yrs_on_team = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_current_contract_yr = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_contract_yrs = i;			
			
		//read year by year salaries
		
		int yrs = m_player.m_contract_yrs;
		seek = 2000 + id*500 + 48 + m_player.m_yrs_of_service*4;//point file to id + 50 + 4 bytes for each year salary starting at player current year in league
		seek = seek - (yrs-1)*4;
		int salary = 0;
		int remaining_salary = 0;
		int y=0;
		for(y=1; y<=m_player.m_contract_yrs; y++)
//		for(int y=1; y<=6; y++)
		{
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 4);
			s[bytes] = 0;
			i = atoi(s);
			m_player.m_contract_salaries[y] = i;			
			seek = seek + 4;
			salary = salary + i;
			if(y >= m_player.m_current_contract_yr) remaining_salary = remaining_salary + i;
				
		}
		if(y <= 6)
		{
			for(int n=y; n<=6; n++)
			{
				m_player.m_contract_salaries[n] = 0;			
			}
		}
		m_player.m_total_salary = salary;
		m_player.m_remaining_salary = remaining_salary;
		
		if(m_player.m_contract_yrs == m_player.m_current_contract_yr) 
			m_player.m_is_free_agent = true;
		else
			m_player.m_is_free_agent = 0;

		m_player.m_current_yr_salary = m_player.m_contract_salaries[m_player.m_current_contract_yr]; 

		avg.m_actual[n] = m_player;
	}
	file.Close();
}




void CDisk::ReadDraftPositions(CString file_name)
{
    CFile file( file_name, CFile::modeRead);
	for(int  n = 0; n <= 1440; n++ )
	{
		
		CPlayer m_player = avg.m_actual[n];

		int id = m_player.GetID();

		long int seek = id*2500 + 26 + 24*100; 
		file.Seek( seek, CFile::begin);

		char s[33];


		int bytes = file.Read(s, 1);
		s[bytes] = 0;
		m_player.m_round_selected = atoi(s);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		m_player.m_pick_selected = atoi(s);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int overall = atoi(s);
	}	
	file.Close();
}


bool CDisk::FileExists(CString file_name)
{
	bool exists = true;
	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) exists = 0;
	return exists;
}

void CDisk::CreateBlankFile(CString file_name, int size)
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

void CDisk::ReadPlayerData(CString file_name)
{

    CFile file( file_name, CFile::modeRead);
	char s[33];
	file.Seek(0, CFile::begin );
	int fa_sk = 56001;
	int bytes = 0;
	CString tm;
	for(int p=1; p<=580; p++)
	{

		int t = (p-1) / 15;
		double f_t = ((double)p - 1) / 15;

		

		if( t == f_t && t <= 31)
		{
			bytes = file.Read(s, 32);
			s[bytes] = 0;
			tm = CString(s);
			tm.TrimRight();
			CPlayer m_player;
			avg.m_actual[p-1] = m_player;
		}
		else if(p == 481)
		{
			CPlayer m_player;
			avg.m_actual[480] = m_player;
			file.Seek(fa_sk, CFile::begin );
			tm = "";
		}

		CPlayer	m_player; 
		m_player.m_team = tm;

		
		int bytes = file.Read(s, 2);
		s[bytes] = 0;
		int i = atoi(s);
		
		m_player.SetRosterNumber(p);
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString nm = CString(s);
	    nm.TrimRight();
		m_player.SetName(nm);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);

		m_player.SetAge(i);

		bytes = file.Read(s, 9);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetID(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_team_paying = i;

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i= atoi(s);
		m_player.m_original_slot = i;


		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString Position;
		if(CString(s) == "") Position = "PG"; else Position = CString(s);
		m_player.SetPos(Position);
		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
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
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTfgm(i);
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTfga(i);
		bytes = file.Read(s, 3);
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
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetStl(i);
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetTo(i);
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetBlk(i);
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_player.SetPf(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetMovOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetMovDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetPenOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetPenDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetPostOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetPostDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetTransOff(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 1;
		m_player.SetTransDef(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 2;
		m_player.SetClutch(i);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = 2;
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

		m_player.SetOutside();
		m_player.SetDriving();
		m_player.SetPost();
		m_player.SetTransition();
		m_player.SetOutsideDefense();
		m_player.SetDrivingDefense();
		m_player.SetPostDefense();
		m_player.SetTransitionDefense();
		m_player.SetTrueRatingSimple(2);
		m_player.SetTradeTrueRating(0);
		m_player.SetTradeValue();
		m_player.SetLastName(m_player.GetName());

	

		int team_index = t + 1;
		if(team_index > 32 || m_player.m_name == "") team_index = 0;
		m_player.m_team_index = team_index;

		m_player.m_original_number = p;


		avg.m_actual[p] = m_player;
	}
	
	file.Close();
	
}

void CDisk::ReadFranchiseData(CString file_name)
{

	





   CFile file( file_name, CFile::modeRead);
	char s[33];
	int bytes = 0;
	for(int p=0; p<=99; p++)
	{
	
		file.Seek(p*1000, CFile::begin );


		CTeamFinancial m_finance = avg.m_finance[p]; 
		

		int bytes = file.Read(s, 32);
		s[bytes] = 0;
		CString city = CString(s);
	    city.TrimRight();
		if(city == "") city.Format("City %d", p+1);
		m_finance.m_city_name = city;

		bytes = file.Read(s, 32);
		s[bytes] = 0;
		CString arena = CString(s);
	    arena.TrimRight();
		if(arena == "") arena.Format("Arena %d", p+1);
		m_finance.m_arena_name = arena;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		int i = atoi(s);
		m_finance.m_ticket_price = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_suite_price = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_club_price = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_network_share = i;

		bytes = file.Read(s, 6);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_local_tv = i;

		bytes = file.Read(s, 6);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_local_radio = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_concessions = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_parking = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_advertising = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_sponsorship = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_current_value = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		if(i==0)
		{
			double f =  (25 + (double)avg.m_owner[p].m_player_spending) / 100;
			m_finance.m_owner_salary_cap = long ( (double) m_finance.m_current_value * f * 100000) / 1000;
		}
		else
		{
			m_finance.m_owner_salary_cap = i;
		}

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_capacity = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_suites = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_club_seats = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_parking_spots = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_fan_support = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_economy = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_political_support = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_interest = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_operating = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_arena = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_marketing = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_population = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_cost_of_living = i;

		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_competition = i;



		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_finance.m_stadium_value = i;


		if(p < 32) m_finance.m_team_name = avg.m_settings.m_leagueTeamNames[p];
		

		avg.m_finance[p] = m_finance;
	}
	
	file.Close();
	

}


void CDisk::WriteFranchiseData(CString file_name, int s1, int s2)
{




CFile file(	file_name, CFile::modeWrite);
CString buffer;
for(int  i = s1; i <= s2; i++ )
{




		CTeamFinancial m_finance = avg.m_finance[i];

		int offset = i;
		if(offset > 100) offset = i-100;
		int seek = offset*1000;


		file.Seek(seek, CFile::begin );

		buffer = m_finance.m_city_name;
		buffer = buffer + "                                ";
		file.Write( buffer, 32);
	
		buffer = m_finance.m_arena_name;
		buffer = buffer + "                                ";
		file.Write( buffer, 32);
	
		buffer.Format("%d", m_finance.m_ticket_price);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_suite_price);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_club_price);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_network_share);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_local_tv);
		buffer = buffer + "               ";
		file.Write( buffer, 6);
	
		buffer.Format("%d", m_finance.m_local_radio);
		buffer = buffer + "               ";
		file.Write( buffer, 6);
	
		buffer.Format("%d", m_finance.m_concessions);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_parking);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_advertising);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_sponsorship);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	


		buffer.Format("%d", m_finance.m_current_value);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_owner_salary_cap);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_capacity);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_suites);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_club_seats);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_parking_spots);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_fan_support);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_economy);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_political_support);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_interest);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
		//not yet viewed in a screen (adjustable)	
		buffer.Format("%d", m_finance.m_operating);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_arena);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_marketing);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_population);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_cost_of_living);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
		buffer.Format("%d", m_finance.m_competition);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
	
		buffer.Format("%d", m_finance.m_stadium_value);
		buffer = buffer + "               ";
		file.Write( buffer, 5);
	
}

file.Close();	

}







bool CDisk::PlayoffsStarted(CString file_name)
{
	bool started = 0;
	CFile f( file_name, CFile::modeRead);
	char s[7];
	int seek = 72046;
	f.Seek(seek, CFile::begin );			
	int bytes = f.Read(s, 2);
	s[bytes] = 0;
	int team1 = atoi(s);
	bytes = f.Read(s, 3);
	s[bytes] = 0;
	int score1 = atoi(s);
	if(team1 > 0 && score1 > 0) started = true;
	f.Close();
	return started;
}

void CDisk::ReadPlayerStats(CString file_name, bool signing_ok)
{
	CFile file( file_name, CFile::modeRead);
//	if(m_stat_type == 2) saveOffset = saveOffset + 144000;
	int players = 14;
	int f=15;
	//if(signing_ok == true) f=20;
	for(int  n = 0; n <= 32; n++ )
	{
		int saveOffset = n * 90 * 32 + 1;
		if(n == 32) players = 480;
		file.Seek( saveOffset, CFile::begin );	
		char s[33];
		for(int p=1; p<=players; p++)
		{
		int slot = n*f + p;			
		CPlayer m_player = avg.m_actual[slot];
		CString nm = m_player.GetName();
		m_player.m_original_number = slot;
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString Name = CString(s);
		Name.TrimRight();
		if(m_player.GetName() == "") m_player.SetName(Name);
		
		bytes = file.Read(s, 14);
		s[bytes] = 0;
		int i = atoi(s);
		m_player.SetInjury(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_starter = i;;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_sim_games = i;
		
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_sim_min = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_ftm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fta = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_tfgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_tfga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_oreb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_reb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_ast = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_stl = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_to = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_blk = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_pf = i;




		if(nm != "") avg.m_actual[slot] = m_player;
		}
		
	}
}

void CDisk::ReadPlayoffStats(CString file_name)
{

	CFile file( file_name, CFile::modeRead);
//	if(m_stat_type == 2) saveOffset = saveOffset + 144000;
	for(int  n = 0; n <= 31; n++ )
	{
		int saveOffset = 144000 + n * 90 * 32 + 1;
		file.Seek( saveOffset, CFile::begin );	
		char s[33];
		for(int p=1; p<=14; p++)
		{
		int slot = n*30 + p;			
		CPlayer m_player = avg.m_actual[slot];
		CString nm = m_player.GetName();
		m_player.m_original_po_number = slot;
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString Name = CString(s);
		Name.TrimRight();
		if(m_player.GetName() == "") m_player.SetName(Name);
		
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		int i = atoi(s);
//		m_player.SetInjury(i);
		

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_po_games = i;
		
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_po_min = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_ftm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fta = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_tfgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_tfga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_oreb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_reb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_ast = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_stl = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_to = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_blk = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_pf = i;
		if(nm != "") avg.m_actual[slot] = m_player;
		}
	}
}

void CDisk::ReadTeamStats(CString file_name)
{
//pFileName = m_path + m_leagueName + ".sta";
	CFile file( file_name, CFile::modeRead);
//	if(m_stat_type == 2) saveOffset = saveOffset + 144000;
	for(int  n = 0; n <= 31; n++ )
	{
		int saveOffset = n * 90 * 32 + 30 * 90 + 1;
		file.Seek( saveOffset, CFile::begin );	
		char s[33];
		for(int p=1; p<=2; p++)
		{
		int slot = 701 + (p-1)*32 + n;//701,733,702,734
		int slot1 = 1441 + (p-1)*32 + n;//701,733,702,734
		CPlayer m_player = avg.m_actual[slot];
		m_player.m_original_number = slot1;
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString Name = CString(s);
		Name.TrimRight();
		if(m_player.GetName() == "") m_player.SetName(Name);
		
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		int i = atoi(s);
		m_player.SetInjury(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_sim_games = i;
		
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_sim_min = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_ftm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_fta = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_tfgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_tfga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_oreb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_reb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_ast = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_stl = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_to = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_blk = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_sim_pf = i;

		m_player.SetPos("");

		avg.m_actual[slot] = m_player;
		slot = slot + 1;
		}
	}

}

void CDisk::ReadPlayoffTeamStats(CString file_name)
{

	CFile file( file_name, CFile::modeRead);
//	if(m_stat_type == 2) saveOffset = saveOffset + 144000;
	
	for(int  n = 0; n <= 31; n++ )
	{
		int saveOffset = 144000 + n * 90 * 32 + 30 * 90 + 1;
		file.Seek( saveOffset, CFile::begin );	
		char s[33];
		for(int p=1; p<=2; p++)
		{
		int slot = 701 + (p-1)*32 + n;//701,733,702,734
		int slot1 = 1441 + (p-1)*32 + n;//701,733,702,734
		CPlayer m_player = avg.m_actual[slot];
		m_player.m_original_number = slot1;
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString Name = CString(s);
		Name.TrimRight();
		if(m_player.GetName() == "") m_player.SetName(Name);
		
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		int i = atoi(s);
		m_player.SetInjury(i);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_po_games = i;
		
		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
//		if(i == 0) i = 1;
		m_player.m_po_min = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_ftm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_fta = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_tfgm = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_tfga = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_oreb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_reb = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_ast = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_stl = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_to = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_blk = i;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_po_pf = i;

		m_player.SetPos("");

		avg.m_actual[slot] = m_player;
		slot = slot + 1;
		}
	}
}


void CDisk::GetSavedHighs(CString file_name)
{

  	CStdioFile file(file_name, CFile::modeRead);
			
	CString buffer[10];
	CString str;
	for(int i = 1; i<=9; i++)
	{
		file.ReadString(buffer[i]);
	}
	file.Close();

	int offset = 0;
	int index = buffer[1].Find(",", offset); 
	offset = index + 1;
	str = buffer[1].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_fga[0] = atoi(str);

	offset = 0;
	index = buffer[2].Find(",", offset); 
	offset = index + 1;
	str = buffer[2].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_fta[0] = atoi(str);

	offset = 0;
	index = buffer[3].Find(",", offset); 
	offset = index + 1;
	str = buffer[3].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_tga[0] = atoi(str);

	offset = 0;
	index = buffer[4].Find(",", offset); 
	offset = index + 1;
	str = buffer[4].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_orb[0] = atoi(str);

	offset = 0;
	index = buffer[5].Find(",", offset); 
	offset = index + 1;
	str = buffer[5].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_drb[0] = atoi(str);

	offset = 0;
	index = buffer[6].Find(",", offset); 
	offset = index + 1;
	str = buffer[6].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_ast[0] = atoi(str);

	offset = 0;
	index = buffer[7].Find(",", offset); 
	offset = index + 1;
	str = buffer[7].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_stl[0] = atoi(str);

	offset = 0;
	index = buffer[8].Find(",", offset); 
	offset = index + 1;
	str = buffer[8].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_to[0] = atoi(str);

	offset = 0;
	index = buffer[9].Find(",", offset); 
	offset = index + 1;
	str = buffer[9].Mid(offset, 4); 
	str.TrimRight();
	avg.m_hi_blk[0] = atoi(str);

}

void CDisk::GetSavedAverages(CString file_name)
{
	CFile f(file_name, CFile::modeRead);

	CPlayer m_player; 

	char s[17];
	f.Seek(0, CFile::begin );

	int bytes = f.Read(s, 10);
	double i1 = atof(s);
	
	bytes = f.Read(s, 10);
	double i2 = atof(s);
	
	bytes = f.Read(s, 10);
	double i3 = atof(s);
	
	bytes = f.Read(s, 10);
	double i4 = atof(s);
	
	bytes = f.Read(s, 10);
	double i5 = atof(s);
	
	bytes = f.Read(s, 10);
	double i6 = atof(s);
	
	bytes = f.Read(s, 10);
	double i7 = atof(s);
	
	bytes = f.Read(s, 10);
	double i8 = atof(s);
	
	bytes = f.Read(s, 10);
	double i9 = atof(s);
	
	bytes = f.Read(s, 10);
	double i10 = atof(s);
	
	bytes = f.Read(s, 10);
	double i11 = atof(s);
	
	bytes = f.Read(s, 10);
	double i12 = atof(s);
	
	bytes = f.Read(s, 10);
	double i13 = atof(s);
	
	bytes = f.Read(s, 10);
	double i14 = atof(s);
	
	bytes = f.Read(s, 10);
	double i15 = atof(s);
	
	bytes = f.Read(s, 10);
	double i16 = atof(s);
	
	bytes = f.Read(s, 10);
	double i17 = atof(s);
	
	bytes = f.Read(s, 10);
	double i18 = atof(s);
	
	bytes = f.Read(s, 10);
	double i19 = atof(s);
	
	bytes = f.Read(s, 10);
	double i20 = atof(s);
	
	bytes = f.Read(s, 10);
	double i21 = atof(s);
	
	

	avg.m_avg_g[0] = i1;
	avg.m_avg_min[0] = i2;
	avg.m_avg_fgm[0] = i3;
	avg.m_avg_fga[0] = i4;
	avg.m_avg_fgp[0] = i5;
	avg.m_avg_fga_t[0] = i6;
	avg.m_avg_fgp_t[0] = i7;
	avg.m_avg_tgm[0] = i8;
	avg.m_avg_tga[0] = i9 ;
	avg.m_avg_tgp[0] = i10;
	avg.m_avg_ftm[0] = i11;
	avg.m_avg_fta[0] = i12;
	avg.m_avg_ftp[0] = i13;
	avg.m_avg_orb[0] = i14;
	avg.m_avg_drb[0] = i15;
	avg.m_avg_ast[0] = i16;
	avg.m_avg_stl[0] = i17;
	avg.m_avg_to[0] = i18;
	avg.m_avg_blk[0] = i19;
	avg.m_avg_pf[0] = i20;
	avg.m_avg_trade_tru[0] = i21;
	f.Close();

}

void CDisk::WriteBudgetFile(CString file_name, int t1, int t2)
{
	CString buffer;

	CFile file(	file_name, CFile::modeWrite);


for(int i=t1; i<=t2; i++)
{


	CTeamFinancial m_finance = avg.m_finance[i];	

	int offset = i;
	if(offset > 100) offset = i-100;
	int seek = offset*1000;
	
	file.Seek(seek, CFile::begin );


		buffer.Format("%d", m_finance.m_home_games);
		buffer = buffer + "               ";
		file.Write( buffer, 10);	

		buffer.Format("%d", (int)m_finance.m_season_att);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_suites_sold);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_clubs_sold);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_att_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_suite_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_club_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_concession_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_parking_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_total_revenue);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_payroll);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_scout_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_coach_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_gm_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_operating_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_arena_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_marketing_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
		buffer.Format("%d", m_finance.m_season_total_expenses);
		buffer = buffer + "               ";
		file.Write( buffer, 10);
	
	

}
file.Close();	

}

void CDisk::ReadBudgetFile(CString file_name)
{
	CFile file( file_name, CFile::modeRead);

	for(int t=0; t<=100; t++)
	{

		char s[33] = "";
		int seek = t*1000;
		
		file.Seek(seek, CFile::begin );
		int bytes = 0;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		int i = atoi(s);
		avg.m_finance[t].m_home_games = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_att = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		CString str = s;
		i = atoi(str);
		avg.m_finance[t].m_season_suites_sold = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		str = s;
		i = atoi(str);
		avg.m_finance[t].m_season_clubs_sold = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_att_revenue = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_suite_revenue = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_club_revenue = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_concession_revenue = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_parking_revenue = i;

		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_total_revenue = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_payroll = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_scout_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_coach_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_gm_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_operating_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_arena_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_marketing_expenses = i;
		
		bytes = file.Read(s, 10);
		s[bytes] = 0;
		i = atoi(s);
		avg.m_finance[t].m_season_total_expenses = i;
	
	}	
	file.Close();

}

void CDisk::WriteRookieFile(CString file_name, BOOL random)//for imported only
{

//	avg.m_actual[i].GenerateODPT();

	

	CFile file(	file_name, CFile::modeWrite	);
	int players = 96;

	for(int  i = 1; i <= players; ++i )
	{
		file.Seek((i-1)*200, CFile::begin ); 
		CPlayer m_player = avg.m_actual[i];


	int cl = 2;
	int co = 2;
	int r = IntRandom(8);
	if(r == 1) cl = IntRandom(3);
	r = IntRandom(8);
	if(r == 1) co = IntRandom(3);
	m_player.SetClutch(cl);
	m_player.SetConsistency(co);

	int better = 30 + IntRandom(40);
	if(better <= 35 || better >= 66) better = IntRandom(99);
	m_player.SetBetter(better);
	m_player.SetPgRot(0);
	m_player.SetSgRot(0);
	m_player.SetSfRot(0);
	m_player.SetPfRot(0);
	m_player.SetCRot(0);


	m_player.m_coach_factor = IntRandom(5);	
	m_player.m_loyalty_factor = IntRandom(5);	
	m_player.m_playing_time_factor = IntRandom(5);	
	m_player.m_winning_factor = IntRandom(5);	
	m_player.m_tradition_factor = IntRandom(5);	
	m_player.m_security_factor = IntRandom(5);	
	m_player.m_content = 2 + IntRandom(5);	

//	m_player.GenerateRandomHeightWeight(true);
	m_player.GenerateRandomPrime();

	r = IntRandom(6);
	if(r==1) m_player.m_clutch = 1;
	else if(r==2) m_player.m_clutch = 3;

	r = IntRandom(6);
	if(r==1) m_player.m_consistency = 1;
	else if(r==2) m_player.m_consistency = 3;


	
		
		CString buffer;
		buffer.Format("%d", i);
		file.Write( buffer, 2);
		CString Name;
	    Name = m_player.GetName() 
			+ "                                 ";
		file.Write(	Name, 16);
		buffer.Format("%d", m_player.GetAge());
		file.Write( buffer, 2);

		int pot1 = m_player.m_pot1;
		int pot2 = m_player.m_pot2;
		int effort = m_player.m_effort;

		if(random == TRUE)
		{
			pot1 = IntRandom(5);
			pot2 = IntRandom(5);
			effort = IntRandom(5);
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && pot1 < 5) pot1 = pot1 + 1;
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && pot2 < 5) pot2 = pot2 + 1;
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && effort > 1) effort = effort - 1;

			if(m_player.GetAge() > 21 && Random(1) < 1./3. && pot1 > 1) pot1 = pot1 - 1;
			if(m_player.GetAge() > 21 && Random(1) < 1./3. && pot2 > 1) pot2 = pot2 - 1;
			if(m_player.GetAge() > 21 && Random(1) < 1./3. && effort < 5) effort = effort + 1;


		}
	


	
		
		buffer.Format("%d", pot1);
		file.Write( buffer, 2);
		buffer.Format("%d", pot2);
		file.Write( buffer, 2);
		buffer.Format("%d", effort);
		file.Write( buffer, 2);
		buffer.Format("%d", m_player.m_prime);
		file.Write( buffer, 2);

		file.Write(	m_player.GetPos(), 2);
		buffer.Format("%d", m_player.GetGames());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMin());
		file.Write( buffer, 4);
        int min_stl = int(double(m_player.GetMin())*.01);
		int stl = m_player.GetStl();
		if(stl < min_stl) stl = min_stl;
		int fgm = m_player.GetFgm();
		int fga = m_player.GetFga();
		double fgp = (double)fgm/(double)fga;
		if(fga>=3 && fgp <= .25) fgm = fga/4;
			
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetFtm());
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetFta());
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetTfgm());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTfga());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetOreb());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetReb());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetAst());
		file.Write( buffer, 4);

		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTo());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetBlk());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetPf());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMovOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetMovDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetClutch());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetConsistency());
		file.Write( buffer, 1);		
		int pg = m_player.GetPgRot();		
		int sg = m_player.GetSgRot();		
		int sf = m_player.GetSfRot();		
		int pf = m_player.GetPfRot();		
		int  c = m_player.GetCRot();
		buffer.Format("%d", pg);
		file.Write( buffer, 1);
		buffer.Format("%d", sg);
		file.Write( buffer, 1);
		buffer.Format("%d", sf);
		file.Write( buffer, 1);
		buffer.Format("%d", pf);
		file.Write( buffer, 1);
		buffer.Format("%d", c);
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetActive());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.m_better);
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

	avg.m_actual[i] = m_player;

	}
	file.Close();	


}


CBBallSchedule CDisk::ReadSchedule(CString file_name)
{

	CBBallSchedule schedule;
	
		CFile file( file_name, CFile::modeRead);


		for(int i = 0; i <= 11; i++ )
		{
			for(int  j = 0; j <= 30; j++ )
			{
				int games_on_this_day = 0;

				for(int  k = 0; k <= 15; k++ )
				{
					char s[7];		
					int bytes = file.Read(s, 4);
					s[bytes] = 0;
					int game = atoi(s);
					schedule.m_schedule[i][j][k] = game;




					bytes = file.Read(s, 6);
					s[bytes] = 0;
					int score = atoi(s);
					schedule.m_game_score[i][j][k] = score;
					if(score > 0) schedule.m_season_started = true;
					

				}
			
			}
		}		
		file.Close();


	CString format1, format2, format3, format4;
	int m_currentRound = 0, m_playoffRounds = 0, m_currentPlayoffDay = 0, m_currentPlayoffGame = 0;


	BOOL m_seasonStarted = 0;
	BOOL CurrentGame = 0;

	CPlayoff *po = new CPlayoff;

		



	if(PlayoffsStarted(file_name) == true) 
	{
		bool round_complete = po->GetPlayoffResults(file_name,format1, format2, format3, format4,
		m_currentRound, m_playoffRounds, m_currentPlayoffDay, m_currentPlayoffGame,
		 m_seasonStarted, schedule.m_currentMonth, schedule.m_currentDay, schedule.m_currentGame, CurrentGame, 0, 0);
	}

		schedule.m_series_win1 = po->m_win1;
		schedule.m_series_win2 = po->m_win2;
		schedule.m_currentRound = m_currentRound;

		for(int j=0; j<=30; j++)
		{
			
			for(int k=0; k<=15; k++)
			{

					
					schedule.m_game_score[12][j][k] = po->m_gameScore[12][j][k];
					schedule.m_schedule[12][j][k] = po->m_sched[12][j][k];

			}
		}

		if(PlayoffsStarted(file_name) == true)
		{
			schedule.m_playoff_started = true;
		}

		delete po;

		schedule.GetNewSeasonAllstarDayEtc();

		return schedule;

}




void CDisk::IncreaseFileSize(CString file_name, int size)
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

void CDisk::DecreaseFileSize(CString file_name, int size)
{
	CFile file(	file_name, CFile::modeReadWrite);	
	int seek = (int)file.GetLength();
	file.SetLength(seek + size);
	file.Close(); 
}

void CDisk::CreateRookies(CString file_name, bool create_preview_file)
{

	CString first, last;
	CPlayer* m_rookies = new CPlayer[961];
	CPlayer* m_pool = new CPlayer[97];
	if(create_preview_file == true)
	{

	int n1=0, n2=0;

	int elig = 0;
	CString rookieName[961];

	int m_hiG = avg.m_hi_g[0];
	for(int i=1; i<=960; i++)
	{
		int min_games = int(double(m_hiG)*1/4);
		if(avg.m_actual[i].GetName() != "" && avg.m_actual[i].GetGames() >=min_games && avg.m_actual[i].GetMin() > (m_hiG*8))
		{
			elig = elig + 1;
			m_rookies[elig]= avg.m_actual[i];
		}
	}


	for (int i=1; i<=96; i++)//change to 96
	{
		do
		{
			n1=IntRandom(1000);
			n2=IntRandom(3000);
		}
		while((fname[n1] == "" || lname[n2] == "") || (fname[n1] == lname[n2]));
		rookieName[i] = fname[n1] + " " + lname[n2];
	
	int p[21] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0};
	int pos = IntRandom(5);
	CString ps[6] = {"","PG","SG","SF","PF"," C"};
	for(int j=1; j<=20; j++)
	{
		p[j] = FindDataForRookie(pos, elig, m_rookies, j);
	}
	int age = 18 + IntRandom(4);
	if(age == 22) age = 18 + IntRandom(6);
	if(age == 22) age = 17 + IntRandom(8);
	int tmp_age = age;
	if(tmp_age > 23) tmp_age = 23;

//	double ageFactor = 4/10 + double(tmp_age)/100*2;
	double ageFactor = 45./100. + double(tmp_age)/100*2;


	double blow = .75;
	int n_blow = IntRandom(9);
	if(n_blow == 1) blow = 1.;

	double temp = (1. - ageFactor)*2.;
	ageFactor = 1. - temp + Random(temp*blow);

	int ga = m_rookies[p[1]].GetGames();
	double gam = double(ga)/double(m_hiG)*82.;
	int games = int(gam);
	double mpg = double(m_rookies[p[1]].GetMin()) / double(games);
	if(mpg > 40) mpg = 38 + Random(2);
	double min = mpg*games;

	double fgm = double(m_rookies[p[2]].GetFgm()) - double(m_rookies[p[2]].GetTfgm());
	double fga = double(m_rookies[p[2]].GetFga()) - double(m_rookies[p[2]].GetTfga());
	double tgm = double(m_rookies[p[3]].GetTfgm());
	double tga = double(m_rookies[p[3]].GetTfga());



	double ftm = double(m_rookies[p[4]].GetFtm());
	double fta = double(m_rookies[p[4]].GetFta());


	double hi = (fga - fta/3/2);
	if(tga > hi && hi > 0)
	{
		double f1 = (fga - fta/3);
		if( f1 > 0)
		{
			double f2 = f1 / fga;
			double f3 = 1 - f2;
			double f4 = Random(f3);
			double f5 = f2 + f4;
			if(f5 < 1)
			{
				tgm = tgm * f5;
				tga = tga * f5;	
			}
		}
	}


	double orb = double(m_rookies[p[5]].GetOreb());
	double drb = double(m_rookies[p[5]].GetReb()) - double(m_rookies[p[5]].GetOreb());
	double ast = double(m_rookies[p[6]].GetAst());
	double stl = double(m_rookies[p[7]].GetStl());
	double to = double(m_rookies[p[8]].GetTo());
	double blk = double(m_rookies[p[9]].GetBlk());
	double pf = double(m_rookies[p[10]].GetPf());

	
	fgm = fgm * ageFactor;
	fga = fga *  ageFactor;
	tgm = tgm * ageFactor;
	tga = tga * ageFactor;
	double ftm_added = 1;
	double fta_added = 1;
	ftm = ftm * (ageFactor*ftm_added);
	fta = fta * (ageFactor*fta_added);
	orb = orb * ageFactor;
	drb = drb * ageFactor;
	ast = ast * ageFactor;
	stl = stl * (1 - (1 - ageFactor)/2);
	to = to  * (2-ageFactor);
	blk = blk * (1 - (1 - ageFactor)/2);
	pf = pf*1.00;
	if (tga == 0) tga = 1 + IntRandom(3);

	fgm = fgm / double(m_rookies[p[2]].GetMin())*mpg ;
	fga = fga / double(m_rookies[p[2]].GetMin())*mpg ;
	tgm = tgm / double(m_rookies[p[3]].GetMin())*mpg ;
	tga = tga / double(m_rookies[p[3]].GetMin())*mpg ;
	ftm = ftm / double(m_rookies[p[4]].GetMin())*mpg ;
	fta = fta / double(m_rookies[p[4]].GetMin())*mpg ;
	double ftp = ftm/fta;
	
	if(fta > fga) {fta = fga; ftm = fta*ftp;}


	orb = orb / double(m_rookies[p[5]].GetMin())*mpg ;
	drb = drb / double(m_rookies[p[5]].GetMin())*mpg ;
	ast = ast / double(m_rookies[p[6]].GetMin())*mpg ;
	stl = stl / double(m_rookies[p[7]].GetMin())*mpg ;
	to = to / double(m_rookies[p[8]].GetMin())*mpg  ;
	if (blk == 0) blk = 1 + IntRandom(3);
	blk = blk / double(m_rookies[p[9]].GetMin())*mpg ;
	pf = pf / double(m_rookies[p[10]].GetMin())*mpg ;

	//ajdust mpg && games
	double tru = GetRookieTrue(games, mpg, fgm, fga, tgm, tga, ftm, fta, orb, drb, ast, stl, to, blk, pf);
	tru = tru*(mpg/48);
//	double mpg2 = tru*(3) + IntRandom(11) - 12;
	double mpg2 = tru * 2.5 + 4 + IntRandom(7);
	if(mpg2 <= 2) mpg2 = 2;
	double factor = mpg2/mpg;
	double fgp = fgm/fga;

	double tgp = tgm/tga;
	fgp = fgp * (1 - (1 - ageFactor)/2) * 1.03;
	ftp = ftp * (1 - (1 - ageFactor)/2) * 1.05;
	tgp = tgp * (1 - (1 - ageFactor)/2) * 1.05;
	fga = fga * factor;
	tga = tga * factor;
	fta = fta * factor;
	orb = orb * factor;
	drb = drb * factor;
	ast = ast * factor;
	stl = stl * factor;
	to = to * factor;
	blk = blk * factor;
	pf = pf * factor;
	if(fgp > (5./9.)) fgm = double( fga * ( double(500 + IntRandom(75))/1000 ));
	else fgm = fga * fgp;
	if(ftp > (8./9.)) ftm = double( fta * ( double(825 + IntRandom(100))/1000 ));
	else ftm = fta * ftp;
	if(tgp > (4./9.)) tgm = double( tga * ( double(325 + IntRandom(100))/1000 ));
	else tgm = tga * tgp;

	if(pf>4) pf = 4 + Random(.5);
	if(to > 0 && ast > 0)
	{
		double at = ast/to;
		if(at > 3) at = 3 + Random(1.);
		to = ast/at;
	}

	double ft_ratio = fta / (fga+orb);
	if(ft_ratio < (1./6.))
	{
		ft_ratio = 1./6. + Random(1./30.);
		double ftp = ftm/fta;
		fta = ft_ratio*(fga+orb);
		ftm = fta*ftp;
	}
	if(to < 0) to = 1;
	m_pool[i].SetName(rookieName[i]);
	m_pool[i].SetPos(ps[pos]);
	m_pool[i].SetAge(age);
	m_pool[i].SetGames(games);
	m_pool[i].SetMin(int(mpg2*games));
	m_pool[i].SetFgm(int(games*(fgm+tgm)));
	m_pool[i].SetFga(int(games*(fga+tga)));
	m_pool[i].SetTfgm(int(games*tgm));
	m_pool[i].SetTfga(int(games*tga));
	m_pool[i].SetFtm(int(games*ftm));
	m_pool[i].SetFta(int(games*fta));
	m_pool[i].SetOreb(int(games*orb));
	m_pool[i].SetReb(int(games*(orb+drb)));
	m_pool[i].SetAst(int(games*ast));
	m_pool[i].SetStl(int(games*stl));
	m_pool[i].SetTo(int(games*to));
	if(blk == 0 && Random(1) < .5) m_pool[i].SetBlk(1);
	else m_pool[i].SetBlk(int(games*blk));
	m_pool[i].SetPf(int(games*pf));

	m_pool[i].GenerateODPT();	


	int cl = 2;
	int co = 2;
	int r = IntRandom(8);
	if(r == 1) cl = IntRandom(3);
	r = IntRandom(8);
	if(r == 1) co = IntRandom(3);
	m_pool[i].SetClutch(cl);
	m_pool[i].SetConsistency(co);

	int better = 30 + IntRandom(40);
	if(better <= 35 || better >= 66) better = IntRandom(99);
	m_pool[i].SetBetter(better);
	m_pool[i].SetPgRot(0);
	m_pool[i].SetSgRot(0);
	m_pool[i].SetSfRot(0);
	m_pool[i].SetPfRot(0);
	m_pool[i].SetCRot(0);


	m_pool[i].m_coach_factor = IntRandom(5);	
	m_pool[i].m_loyalty_factor = IntRandom(5);	
	m_pool[i].m_playing_time_factor = IntRandom(5);	
	m_pool[i].m_winning_factor = IntRandom(5);	
	m_pool[i].m_tradition_factor = IntRandom(5);	
	m_pool[i].m_security_factor = IntRandom(5);	
	m_pool[i].m_content = 2 + IntRandom(5);	



	m_pool[i].GenerateRandomHeightWeight(true);
	r = IntRandom(6);
	if(r==1) m_pool[i].m_clutch = 1;
	else if(r==2) m_pool[i].m_clutch = 3;

	r = IntRandom(6);
	if(r==1) m_pool[i].m_consistency = 1;
	else if(r==2) m_pool[i].m_consistency = 3;


	}
	}

CFile file(	file_name, CFile::modeWrite	);
	int players = 96;

	for(int  i = 1; i <= players; ++i )
	{
		file.Seek((i-1)*200, CFile::begin ); 
		CPlayer m_player = m_pool[i];
		if(create_preview_file == 0) m_player = Rookies[i];
		
		CString buffer;
		buffer.Format("%d", i);
		file.Write( buffer, 2);
		CString Name;
	    Name = m_player.GetName() 
			+ "                                 ";
		file.Write(	Name, 16);
		buffer.Format("%d", m_player.GetAge());
		file.Write( buffer, 2);

		int pot1 = m_player.m_pot1;
		int pot2 = m_player.m_pot2;
		int effort = m_player.m_effort;

		if(create_preview_file == true)
		{
			pot1 = IntRandom(5);
			pot2 = IntRandom(5);
			effort = IntRandom(5);
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && pot1 < 5) pot1 = pot1 + 1;
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && pot2 < 5) pot2 = pot2 + 1;
			if(m_player.GetAge() < 20 && Random(1) < 1./3. && effort > 1) effort = effort - 1;

			if(m_player.GetAge() > 21 && Random(1) < 1./3. && pot1 > 1) pot1 = pot1 - 1;
			if(m_player.GetAge() > 21 && Random(1) < 1./3. && pot2 > 1) pot2 = pot2 - 1;
			if(m_player.GetAge() > 21 && Random(1) < 1./3. && effort < 5) effort = effort + 1;


		}
	

		m_player.GenerateRandomPrime();

		buffer.Format("%d", pot1);
		file.Write( buffer, 2);
		buffer.Format("%d", pot2);
		file.Write( buffer, 2);
		buffer.Format("%d", effort);
		file.Write( buffer, 2);
		buffer.Format("%d", m_player.m_prime);
		file.Write( buffer, 2);

		file.Write(	m_player.GetPos(), 2);
		buffer.Format("%d", m_player.GetGames());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMin());
		file.Write( buffer, 4);
        int min_stl = int(double(m_player.GetMin())*.01);
		int stl = m_player.GetStl();
		if(stl < min_stl) stl = min_stl;
		int fgm = m_player.GetFgm();
		int fga = m_player.GetFga();
		double fgp = (double)fgm/(double)fga;
		if(fga>=3 && fgp <= .25) fgm = fga/4;
			
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetFtm());
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetFta());
		file.Write( buffer, 4);		
		buffer.Format("%d", m_player.GetTfgm());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTfga());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetOreb());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetReb());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetAst());
		file.Write( buffer, 4);

		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetTo());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetBlk());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetPf());
		file.Write( buffer, 4);
		buffer.Format("%d", m_player.GetMovOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetMovDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPenDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetPostDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransOff());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetTransDef());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetClutch());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetConsistency());
		file.Write( buffer, 1);		
		int pg = m_player.GetPgRot();		
		int sg = m_player.GetSgRot();		
		int sf = m_player.GetSfRot();		
		int pf = m_player.GetPfRot();		
		int  c = m_player.GetCRot();
		buffer.Format("%d", pg);
		file.Write( buffer, 1);
		buffer.Format("%d", sg);
		file.Write( buffer, 1);
		buffer.Format("%d", sf);
		file.Write( buffer, 1);
		buffer.Format("%d", pf);
		file.Write( buffer, 1);
		buffer.Format("%d", c);
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.GetActive());
		file.Write( buffer, 1);
		buffer.Format("%d", m_player.m_better);
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

	delete [] m_rookies;
	delete [] m_pool;
}

void CDisk::ReadNames(CString f_file_name, CString l_file_name)
{
  	CStdioFile file(f_file_name, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		file.ReadString(fname[i]);
	}
	file.Close();
  	CStdioFile f(l_file_name, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		f.ReadString(lname[i]);
	}
	f.Close();
}

int CDisk::FindDataForRookie(int pos, int elig, CPlayer m_rookies[], int stat)
{
	int n = 0;
	bool ok = 0;
	do
	{
		n = IntRandom(elig);
		if(pos == 1 && m_rookies[n].GetPos() == "PG") ok = true;
		else if(pos == 2 && m_rookies[n].GetPos() == "SG") ok = true;
		else if(pos == 3 && m_rookies[n].GetPos() == "SF") ok = true;
		else if(pos == 4 && m_rookies[n].GetPos() == "PF") ok = true;
		else if(pos == 5 && m_rookies[n].GetPos() == " C") ok = true;
//		else if(m_rookies[n].GetPos() == " C" && stat==2) ok = true;
//		else if(m_rookies[n].GetPos() == "PF" && stat==2) ok = true;
		else if(pos == 4 && stat==2) ok = true;
		else if(pos == 5 && stat==2) ok = true;
	}
	while (ok == 0);

	return n;
}

double CDisk::GetRookieTrue(int g, double min, double fgm, double fga, double tgm, double tga, double ftm, double fta, 
							  double orb, double drb, double ast, double stl, double to, double blk, double pf)
{
	fgm = fgm + tgm;
	fga= fga + tga;
  	double gun = fgm + tgm - (fga - fgm) * 2/3;
  	gun = gun + ftm - fta / 2; 
	gun = gun + (fta - ftm) * 1/6;
	gun = gun * 3/2;//fix this shit maybe

 	double skill = orb * 2/3 + drb * 1/3;
	skill = skill + stl -  to + blk;
	skill = skill + ast * 4 / 5;
	skill = skill * 3/4;//fix this shit maybe
	double tru = gun + skill;
	if(g == 0)
		tru = 0;
	else
	tru = tru / min * 48;
	return tru;
}


double CDisk::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}

void CDisk::OpenRookies(CString file_name)
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


bool CDisk::SelectHallOfFame(CPlayer m_player)
{
	bool hall = 0;
	double avgTru = avg.m_avg_tru[0];
	double avgFga = avg.m_avg_fga[0];
	double avgFta = avg.m_avg_fta[0];
	double avgTfga = avg.m_avg_tga[0];

	double currentTru = m_player.GetTradeTrueRating(0);
	double pr = double(m_player.GetPrime());
	double pastPrime = double(m_player.GetAge()) - pr;
	if(pastPrime > 10) pastPrime = 10;
		double factor = (100 - pastPrime*3) / 100;
		double skillFactor = (100 - pastPrime*2.5) / 100;
		double primeTru = currentTru/skillFactor;
		double pastPrimeFactor  = (33 - pastPrime*3)/100;
		double standard = avgTru*(1+pastPrimeFactor);
		bool scorer = 0;
		double ppg = (double(m_player.GetFgm())*2 +
			double(m_player.GetTfgm()) +
			 double(m_player.GetFtm()))/double(m_player.GetGames());
		
		if(primeTru == 0) 
			scorer = 0;
		else
		{
			ppg = ppg / factor;
			double points = avgFga*9/10 + avgFta*4/5 + avgTfga*1/3;
			scorer = (ppg > points*1.125) && pastPrime >= 3;
		}
		
		if(((primeTru > standard || scorer == true) && pastPrime > 0) && m_player.GetName() != "") hall = true;
		return hall;
}


void CDisk::WritePlayerStats(CString file_name)
{
/*	CFile file( file_name, CFile::modeWrite );
	int players = 14;

	for(int t=0; t<=32; t++)
	{
		int saveOffset = t * 90 * 32 + 1;
		file.Seek( saveOffset, CFile::begin );
		if(t==32) players = 96;
	for(int  i = 1; i <= players; i++ )
	{
		int slot = t*15+i;

		CPlayer m_player = avg.m_actual[slot];
		CString buffer;
		file.Write(m_player.GetName(), 16); 
		int injury = m_player.GetInjury();
		buffer.Format("%d", injury);
		file.Write( buffer, 14);		
		int starts = m_player.m_starter;
		buffer.Format("%d", starts);
		buffer = buffer + "  ";
		file.Write( buffer, 2);		
		int games = m_player.m_sim_games;
		buffer.Format("%d", games);
		file.Write( buffer, 2);
		int min = m_player.m_sim_min;
		buffer.Format("%d", min);
		file.Write( buffer, 4);		
		int fgm = m_player.m_sim_fgm;
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		int fga = m_player.m_sim_fga;
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		int ftm = m_player.m_sim_ftm;		
		buffer.Format("%d", ftm);
		file.Write( buffer, 4);
		int fta = m_player.m_sim_fta;
		buffer.Format("%d", fta);
		file.Write( buffer, 4);
		int tfgm = m_player.m_sim_tfgm;		
		buffer.Format("%d", tfgm);
		file.Write( buffer, 4);
		int tfga = m_player.m_sim_tfga;		
		buffer.Format("%d", tfga);
		file.Write( buffer, 4);
		int oreb = m_player.m_sim_oreb;		
		buffer.Format("%d", oreb);
		file.Write( buffer, 4);
		int reb = m_player.m_sim_reb;
		buffer.Format("%d", reb);
		file.Write( buffer, 4);
		int ast = m_player.m_sim_ast;		
		buffer.Format("%d", ast);
		file.Write( buffer, 4);
		int stl = m_player.m_sim_stl;
		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		int to = m_player.m_sim_to;
		buffer.Format("%d", to);
		file.Write( buffer, 4);
		int blk = m_player.m_sim_blk;
		buffer.Format("%d", blk);
		file.Write( buffer, 4);
		int pf = m_player.m_sim_pf;
		buffer.Format("%d", pf);
		file.Write( buffer, 4);
		
	}
	}
	file.Close();*/


}

void CDisk::WritePlayoffStats(CString file_name)
{
	/*CFile file( file_name, CFile::modeWrite );
	int players = 14;

	for(int t=0; t<=32; t++)
	{
		int saveOffset = 144000 + t * 90 * 32 + 1;
		file.Seek( saveOffset, CFile::begin );
		if(t==32) players = 96;
	for(int  i = 1; i <= players; i++ )
	{
		int slot = t*15+i;

		CPlayer m_player = avg.m_actual[slot];
		CString buffer;
		file.Write(m_player.GetName(), 16); 
		int injury = m_player.GetInjury();
		buffer.Format("%d", injury);
		file.Write( buffer, 16);		
		int games = m_player.m_po_games;
		buffer.Format("%d", games);
		file.Write( buffer, 2);
		int min = m_player.m_po_min;
		buffer.Format("%d", min);
		file.Write( buffer, 4);		
		int fgm = m_player.m_po_fgm;
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		int fga = m_player.m_po_fga;
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		int ftm = m_player.m_po_ftm;		
		buffer.Format("%d", ftm);
		file.Write( buffer, 4);
		int fta = m_player.m_po_fta;
		buffer.Format("%d", fta);
		file.Write( buffer, 4);
		int tfgm = m_player.m_po_tfgm;		
		buffer.Format("%d", tfgm);
		file.Write( buffer, 4);
		int tfga = m_player.m_po_tfga;		
		buffer.Format("%d", tfga);
		file.Write( buffer, 4);
		int oreb = m_player.m_po_oreb;		
		buffer.Format("%d", oreb);
		file.Write( buffer, 4);
		int reb = m_player.m_po_reb;
		buffer.Format("%d", reb);
		file.Write( buffer, 4);
		int ast = m_player.m_po_ast;		
		buffer.Format("%d", ast);
		file.Write( buffer, 4);
		int stl = m_player.m_po_stl;
		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		int to = m_player.m_po_to;
		buffer.Format("%d", to);
		file.Write( buffer, 4);
		int blk = m_player.m_po_blk;
		buffer.Format("%d", blk);
		file.Write( buffer, 4);
		int pf = m_player.m_po_pf;
		buffer.Format("%d", pf);
		file.Write( buffer, 4);
		
	}
	}
	file.Close();*/


}

void CDisk::WritePlayoffTeamStats(CString file_name)
{
		
	/*CFile file( file_name, CFile::modeWrite );

	for(int t=0; t<=31; t++)
	{
		int saveOffset = 144000 + t * 90 * 32 + 30 * 90 + 1;
		file.Seek( saveOffset, CFile::begin );	
		for(int p=1; p<=2; p++)
		{
		int slot = 701 + (p-1)*32 + t;//701,733,702,734
		CPlayer m_player = avg.m_actual[slot];
		CString buffer;
		file.Write(m_player.GetName(), 16); 
		int injury = m_player.GetInjury();
		buffer.Format("%d", injury);
		file.Write( buffer, 16);		
		int games = m_player.m_po_games;
		buffer.Format("%d", games);
		file.Write( buffer, 2);
		int min = m_player.m_po_min;
		buffer.Format("%d", min);
		file.Write( buffer, 4);		
		int fgm = m_player.m_po_fgm;
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		int fga = m_player.m_po_fga;
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		int ftm = m_player.m_po_ftm;		
		buffer.Format("%d", ftm);
		file.Write( buffer, 4);
		int fta = m_player.m_po_fta;
		buffer.Format("%d", fta);
		file.Write( buffer, 4);
		int tfgm = m_player.m_po_tfgm;		
		buffer.Format("%d", tfgm);
		file.Write( buffer, 4);
		int tfga = m_player.m_po_tfga;		
		buffer.Format("%d", tfga);
		file.Write( buffer, 4);
		int oreb = m_player.m_po_oreb;		
		buffer.Format("%d", oreb);
		file.Write( buffer, 4);
		int reb = m_player.m_po_reb;
		buffer.Format("%d", reb);
		file.Write( buffer, 4);
		int ast = m_player.m_po_ast;		
		buffer.Format("%d", ast);
		file.Write( buffer, 4);
		int stl = m_player.m_po_stl;
		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		int to = m_player.m_po_to;
		buffer.Format("%d", to);
		file.Write( buffer, 4);
		int blk = m_player.m_po_blk;
		buffer.Format("%d", blk);
		file.Write( buffer, 4);
		int pf = m_player.m_po_pf;
		buffer.Format("%d", pf);
		file.Write( buffer, 4);
		
		}
	}
	file.Close();*/


		
}

void CDisk::WriteTeamStats(CString file_name)
{


	/*	
	CFile file( file_name, CFile::modeWrite );

	for(int t=0; t<=31; t++)
	{
		int saveOffset = t * 90 * 32 + 30 * 90 + 1;
	//int saveOffset = t * 90 * 32 + 1;
		file.Seek( saveOffset, CFile::begin );	
		for(int p=1; p<=2; p++)
		{
		int slot = 701 + (p-1)*32 + t;//701,733,702,734
		CPlayer m_player = avg.m_actual[slot];
		CString buffer;
		file.Write(m_player.GetName(), 16); 
		int injury = m_player.GetInjury();
		buffer.Format("%d", injury);
		file.Write( buffer, 16);		
		int games = m_player.m_sim_games;
		buffer.Format("%d", games);
		file.Write( buffer, 2);
		int min = m_player.m_sim_min;
		buffer.Format("%d", min);
		file.Write( buffer, 4);		
		int fgm = m_player.m_sim_fgm;
		buffer.Format("%d", fgm);
		file.Write( buffer, 4);
		int fga = m_player.m_sim_fga;
		buffer.Format("%d", fga);
		file.Write( buffer, 4);
		int ftm = m_player.m_sim_ftm;		
		buffer.Format("%d", ftm);
		file.Write( buffer, 4);
		int fta = m_player.m_sim_fta;
		buffer.Format("%d", fta);
		file.Write( buffer, 4);
		int tfgm = m_player.m_sim_tfgm;		
		buffer.Format("%d", tfgm);
		file.Write( buffer, 4);
		int tfga = m_player.m_sim_tfga;		
		buffer.Format("%d", tfga);
		file.Write( buffer, 4);
		int oreb = m_player.m_sim_oreb;		
		buffer.Format("%d", oreb);
		file.Write( buffer, 4);
		int reb = m_player.m_sim_reb;
		buffer.Format("%d", reb);
		file.Write( buffer, 4);
		int ast = m_player.m_sim_ast;		
		buffer.Format("%d", ast);
		file.Write( buffer, 4);
		int stl = m_player.m_sim_stl;
		buffer.Format("%d", stl);
		file.Write( buffer, 4);
		int to = m_player.m_sim_to;
		buffer.Format("%d", to);
		file.Write( buffer, 4);
		int blk = m_player.m_sim_blk;
		buffer.Format("%d", blk);
		file.Write( buffer, 4);
		int pf = m_player.m_sim_pf;
		buffer.Format("%d", pf);
		file.Write( buffer, 4);
		
		}
	}
	file.Close();


		
	*/	
		
}

int CDisk::OpenCurrentYear(CString file_name)
{
	int current_yr = 2000;

	if( FileExists(file_name) == true) 
	{
		CFile file( file_name, CFile::modeRead);
		char s[33];		

		file.Seek(3992, CFile::begin);	
		int bytes = file.Read(s, 4);
		s[bytes] = 0;
		int year = atoi(s);
		current_yr = year;
		if(current_yr == 0) current_yr = 2000;		
	}
	else	
		AfxMessageBox("Go to League Edit to set up your new league", IDOK);

	return current_yr;
}

void CDisk::ReadPlayerContract(CString file_name)
{


    CFile file( file_name, CFile::modeRead);

		int id = m_player.GetID();
		m_player.m_salary_id = id;
		int seek = 2000 + id*500 + 1; 
		file.Seek( seek, CFile::begin);

		char s[33];

		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString nm = CString(s);
	    nm.TrimRight();



		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		bool j = true;
		if(i == 0) j = 0;
		m_player.m_random_contract_ratings = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_contracts = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_projections = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		j = true;
		if(i == 0) j = 0;
		m_player.m_random_yrs_service = j;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_pot1 = i;

	

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_pot2 = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_effort = i;

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

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_yrs_of_service = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_yrs_on_team = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_current_contract_yr = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		m_player.m_contract_yrs = i;			
			
		//read year by year salaries
		
		int yrs = m_player.m_contract_yrs;
		seek = 2000 + id*500 + 48 + m_player.m_yrs_of_service*4;//point file to id + 50 + 4 bytes for each year salary starting at player current year in league
		seek = seek - (yrs-1)*4;
		int salary = 0;
		
		for(int y=1; y<=m_player.m_contract_yrs; y++)
		{
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 4);
			s[bytes] = 0;
			i = atoi(s);
			m_player.m_contract_salaries[y] = i;			
			seek = seek + 4;
			salary = salary + i;
		}
		m_player.m_total_salary = salary;
		
		if(m_player.m_contract_yrs == m_player.m_current_contract_yr) m_player.m_is_free_agent = true;

		m_player.m_current_yr_salary = m_player.m_contract_salaries[m_player.m_current_contract_yr]; 
	
		file.Close();
}


bool CDisk::SeasonStarted(CString file_name)
{
	bool started = 0;
	CFile file( file_name, CFile::modeRead);
	for(int i = 0; i <= 11; i++ )
	{
		for(int  j = 0; j <= 30; j++ )
		{
			for(int  k = 0; k <= 15; k++ )
			{
				if(started == true) continue;
				char s[7];		

				int bytes = file.Read(s, 4);
				s[bytes] = 0;
				int game = atoi(s);
				bytes = file.Read(s, 6);
				s[bytes] = 0;
				int score = atoi(s);
				if(score > 0) started = true;				
			}
		}
	}
	file.Close();
	return started;
}




void CDisk::CreateFictionalPool()
{
	CString first, last;
	CPlayer* m_rookies = new CPlayer[581];

	int n1=0, n2=0;

	int elig = 0;

	int m_hiG = avg.m_hi_g[0];


	for(int i=1; i<=580; i++)
	{
		int min_games = int(double(m_hiG)*1/4);
		if(avg.m_actual[i].GetName() != "" && avg.m_actual[i].GetGames() >=min_games && avg.m_actual[i].GetMin() > (m_hiG*8))
		{
			elig = elig + 1;
			m_rookies[elig]= avg.m_actual[i];
		}
	}


	CString rookieName[581];
	int i = 1;
	int count = 1;
	do
	{

	 
		do
		{
			n1=IntRandom(1000);
			n2=IntRandom(3000);
		}
		while((fname[n1] == "" || lname[n2] == "") || (fname[n1] == lname[n2]));
		rookieName[i] = fname[n1] + " " + lname[n2];
	
	int p[21] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0};
	int pos = IntRandom(5);
	CString ps[6] = {"","PG","SG","SF","PF"," C"};
	for(int j=1; j<=20; j++)
	{
		p[j] = FindDataForRookie(pos, elig, m_rookies, j);
	}
	int age = 21 + IntRandom(11);
	if(age == 22) age = 17 + IntRandom(18);
	if(age == 18) age = 18 + IntRandom(22);
	int tmp_age = age;
	if(tmp_age > 28) tmp_age = 28 + (28 - tmp_age);





	double ageFactor = .70 + double(tmp_age - 20)*.05;
	double temp = 0;


	if(ageFactor < 1) 
	{
		temp = (1. - ageFactor)*2.;
		ageFactor = 1. - temp + Random(temp);
	}
	else
	{
		temp = (ageFactor - 1)*2.;
		ageFactor = 1. + Random(temp);
	}

	int ga = m_rookies[p[1]].GetGames();
	double gam = double(ga)/double(m_hiG)*double(m_hiG);
	int games = int(gam);
	double mpg = double(m_rookies[p[1]].GetMin()) / double(games);
	double min = mpg*games;

	double fgm = double(m_rookies[p[2]].GetFgm()) - double(m_rookies[p[2]].GetTfgm());
	double fga = double(m_rookies[p[2]].GetFga()) - double(m_rookies[p[2]].GetTfga());
	double tgm = double(m_rookies[p[3]].GetTfgm());
	double tga = double(m_rookies[p[3]].GetTfga());
	double ftm = double(m_rookies[p[4]].GetFtm());
	double fta = double(m_rookies[p[4]].GetFta());


	double hi = (fga - fta/3/2);
	if(tga > hi && hi > 0)
	{
		double f1 = (fga - fta/3);
		if( f1 > 0)
		{
			double f2 = f1 / fga;
			double f3 = 1 - f2;
			double f4 = Random(f3);
			double f5 = f2 + f4;
			if(f5 < 1)
			{
				tgm = tgm * f5;
				tga = tga * f5;	
			}
		}
	}

	double orb = double(m_rookies[p[5]].GetOreb());
	double drb = double(m_rookies[p[5]].GetReb()) - double(m_rookies[p[5]].GetOreb());
	double ast = double(m_rookies[p[6]].GetAst());
	double stl = double(m_rookies[p[7]].GetStl());
	double to = double(m_rookies[p[8]].GetTo());
	double blk = double(m_rookies[p[9]].GetBlk());
	double pf = double(m_rookies[p[10]].GetPf());

	
	fgm = fgm * ageFactor;
	fga = fga *  ageFactor;
	tgm = tgm * ageFactor;
	tga = tga * ageFactor;
	double ftm_added = 1;
	double fta_added = 1;
	ftm = ftm * (ageFactor*ftm_added);
	fta = fta * (ageFactor*fta_added);
	orb = orb * ageFactor;
	drb = drb * ageFactor;
	ast = ast * ageFactor;
	stl = stl * (1 - (1 - ageFactor)/2);
	to = to  * (2-ageFactor);
	blk = blk * (1 - (1 - ageFactor)/2);
	pf = pf*1.00;
	
	fgm = fgm / double(m_rookies[p[2]].GetMin())*mpg ;
	fga = fga / double(m_rookies[p[2]].GetMin())*mpg ;
	tgm = tgm / double(m_rookies[p[3]].GetMin())*mpg ;
	tga = tga / double(m_rookies[p[3]].GetMin())*mpg ;
	ftm = ftm / double(m_rookies[p[4]].GetMin())*mpg ;
	fta = fta / double(m_rookies[p[4]].GetMin())*mpg ;
	double ftp = ftm/fta;
	
	if(fta > fga) {fta = fga; ftm = fta*ftp;}


	orb = orb / double(m_rookies[p[5]].GetMin())*mpg ;
	drb = drb / double(m_rookies[p[5]].GetMin())*mpg ;
	ast = ast / double(m_rookies[p[6]].GetMin())*mpg ;
	stl = stl / double(m_rookies[p[7]].GetMin())*mpg ;
	to = to / double(m_rookies[p[8]].GetMin())*mpg  ;
	blk = blk / double(m_rookies[p[9]].GetMin())*mpg ;
	pf = pf / double(m_rookies[p[10]].GetMin())*mpg ;

	//ajdust mpg && games
	double tru = GetRookieTrue(games, mpg, fgm, fga, tgm, tga, ftm, fta, orb, drb, ast, stl, to, blk, pf);
	double mpg2 = tru*(3) + IntRandom(11) - 12;
	if(mpg2 > 40) mpg2 = 40 + Random(2);
	if(mpg2 <= 2) mpg2 = 2;

	double factor = 0;
	double fgp = 0;
	double tgp = 0;

	if(mpg > 0) factor = mpg2/mpg;
	if(fga > 0) fgp = fgm/fga;
	if(tga > 0) tgp = tgm/tga;

	fgp = fgp * (1 - (1 - ageFactor)/2) * .99;
	ftp = ftp * (1 - (1 - ageFactor)/2) * 1.00;
	tgp = tgp * (1 - (1 - ageFactor)/2) * 1.00;
	fga = fga * factor;
	tga = tga * factor;
	fta = fta * factor;
	orb = orb * factor;
	drb = drb * factor;
	ast = ast * factor;
	stl = stl * factor;
	to = to * factor;
	blk = blk * factor;
	pf = pf * factor;
	if(fgp > (5./9.)) fgm = double( fga * ( double(500 + IntRandom(75))/1000 ));
	else fgm = fga * fgp;
	if(ftp > (8./9.)) ftm = double( fta * ( double(825 + IntRandom(100))/1000 ));
	else ftm = fta * ftp;
	if(tgp > (4./9.)) tgm = double( tga * ( double(325 + IntRandom(100))/1000 ));
	else tgm = tga * tgp;

	if(pf>4) pf = 4 + Random(.5);
	if(to > 0 && ast > 0)
	{
		double at = ast/to;
		if(at > 3) at = 3 + Random(1.);
		to = ast/at;
	}

	double ft_ratio = fta / (fga+orb);
	if(ft_ratio < (1./6.))
	{
		ft_ratio = 1./6. + Random(1./30.);
		double ftp = ftm/fta;
		fta = ft_ratio*(fga+orb);
		ftm = fta*ftp;
	}
	if(to < 0) to = 1;



	m_rookies[i].SetName(rookieName[i]);
	m_rookies[i].SetPos(ps[pos]);
	m_rookies[i].SetAge(age);
	m_rookies[i].SetGames(games);
	m_rookies[i].SetMin(int(mpg2*games));
	m_rookies[i].SetFgm(int(games*(fgm+tgm)));
	m_rookies[i].SetFga(int(games*(fga+tga)));
	m_rookies[i].SetTfgm(int(games*tgm));
	m_rookies[i].SetTfga(int(games*tga));
	m_rookies[i].SetFtm(int(games*ftm));
	m_rookies[i].SetFta(int(games*fta));
	m_rookies[i].SetOreb(int(games*orb));
	m_rookies[i].SetReb(int(games*(orb+drb)));
	m_rookies[i].SetAst(int(games*ast));
	m_rookies[i].SetStl(int(games*stl));
	m_rookies[i].SetTo(int(games*to));
	if(blk == 0 && Random(1) < .5) m_rookies[i].SetBlk(1);
	else m_rookies[i].SetBlk(int(games*blk));
	m_rookies[i].SetPf(int(games*pf));

    int min_stl = int(double(m_rookies[i].GetMin())*.01);
	int i_stl = m_rookies[i].GetStl();
	if(i_stl < min_stl) i_stl = min_stl;
	m_rookies[i].SetStl(i_stl);

	

	m_rookies[i].GenerateODPT();


	int cl = 2;
	int co = 2;
	int r = IntRandom(8);
	if(r == 1) cl = IntRandom(3);
	r = IntRandom(8);
	if(r == 1) co = IntRandom(3);
	m_rookies[i].SetClutch(cl);
	m_rookies[i].SetConsistency(co);
	m_rookies[i].SetBetter(50);
	m_rookies[i].SetPgRot(0);
	m_rookies[i].SetSgRot(0);
	m_rookies[i].SetSfRot(0);
	m_rookies[i].SetPfRot(0);
	m_rookies[i].SetCRot(0);
	m_rookies[i].SetTrueRatingSimple(2);
	m_rookies[i].SetTradeTrueRating(0);
	m_rookies[i].SetTradeValue();




	m_rookies[i].m_content = 2 + IntRandom(5);	







	if(fgm > 1)
	{
		m_rookies[i].SetID(count);
		count = count + 1;
		i=i+1;
	} 
	}
	while (i <= 580);

	
	for(int i = 1; i <= 580; ++i )
	{
		avg.m_actual[i] = m_rookies[i];	
		int age = avg.m_actual[i].GetAge(); 
		int start_yr = 19 + IntRandom(4);
		if(start_yr == 23) start_yr = 17+IntRandom(7);
		int yrs_pro = age - start_yr;
		if(yrs_pro <= 0) yrs_pro = 1;
		avg.m_actual[i].m_yrs_on_team = IntRandom(yrs_pro);
		avg.m_actual[i].m_yrs_of_service = yrs_pro;
		avg.m_actual[i].SetLastName(avg.m_actual[i].m_name);
		avg.m_actual[i].GenerateRandomHeightWeight(false);
	}


	avg.ConvertDataNewFormat();

	delete [] m_rookies;
}




void CDisk::DeleteFile(CString file_name)
{
	CFile fil;
	CFileStatus status;
	if( CFile::GetStatus( file_name, status )) fil.Remove(file_name);
}

void CDisk::WriteCurrentYear(CString file_name, int yr)
{

	CString buffer;
	CFile file(	file_name, CFile::modeWrite);	
	file.Seek(3992, CFile::begin);
	buffer.Format("%d", yr);
	buffer = buffer + "                ";
	file.Write(buffer, 4);
	file.Close();

}

void CDisk::DeleteAllFiles(CString file_name)
{




	DeleteFile(file_name + ".all");
	DeleteFile(file_name + ".asw");
	DeleteFile(file_name + ".arf");
	DeleteFile(file_name + ".awa");
	DeleteFile(file_name + ".box");
	DeleteFile(file_name + ".bxs");
	DeleteFile(file_name + ".bud");
	DeleteFile(file_name + ".car");
	DeleteFile(file_name + ".dra");
	DeleteFile(file_name + ".dub");
	DeleteFile(file_name + ".frn");
	DeleteFile(file_name + ".fro");
	DeleteFile(file_name + ".fut");
	DeleteFile(file_name + ".his");
	DeleteFile(file_name + ".hof");
	DeleteFile(file_name + ".lge");
	DeleteFile(file_name + ".kie");
	DeleteFile(file_name + ".sch");
	DeleteFile(file_name + ".plb");
	DeleteFile(file_name + ".own");
	DeleteFile(file_name + ".exp");
	DeleteFile(file_name + ".pbp");
	DeleteFile(file_name + ".log");
	DeleteFile(file_name + ".rec");
	DeleteFile(file_name + ".roo");
	DeleteFile(file_name + ".sal");
	DeleteFile(file_name + ".trn");
	DeleteFile(file_name + ".sco");
	
	DeleteFile(file_name + ".con");//no longer used
	DeleteFile(file_name + ".mis");//
	DeleteFile(file_name + ".fra");//
	DeleteFile(file_name + ".dea");//

	DeleteFile(file_name + ".avg");
	DeleteFile(file_name + ".eng");
	DeleteFile(file_name + ".ret");
	DeleteFile(file_name + ".plr");
	DeleteFile(file_name + ".sav");
	DeleteFile(file_name + ".sta");
	DeleteFile(file_name + ".rcb");

	DeleteFile(file_name + ".bxs");
	DeleteFile(file_name + ".log");




}



void CDisk::UpdateExpansionFile(CString exp_name, CString team_names[])
{
	CFile file(	exp_name, CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	int exp_count = atoi(s);

	exp_count = exp_count + 1;
	buffer.Format("%d", exp_count);
	buffer = buffer + "    ";
 	
	file.Seek( seek, CFile::begin);
	file.Write(buffer, 2);


	seek = 1100*exp_count;//starts at index 1100 for expansion list team names
	file.Seek( seek, CFile::begin);

	//write ids of players here
	
	
	for(int i=0; i<=32; i++)
	{
	    buffer =  team_names[i];
	    buffer = buffer + "                                                   ";
	    file.Write(buffer, 32);  
	}

}



void CDisk::WriteStaffData(CString file_name)
{

}

void CDisk::SaveSchedule(CString file_name, CBBallSchedule schedule)
{
	CFile file( file_name, CFile::modeWrite);
		for(int i = 0; i <= 11; i++ )
		{
			for(int  j = 0; j <= 30; j++ )
			{
				for(int  k = 0; k <= 15; k++ )
				{
					CString buffer;
					buffer.Format("%d", schedule.m_schedule[i][j][k]);
					buffer = buffer + "       ";
					file.Write(buffer, 4);
					
					buffer.Format("%d", schedule.m_game_score[i][j][k]);
					buffer = buffer + "       ";
					file.Write(buffer, 6);
					

				}
			}
		}		

		//file.SetLength(64000);
		file.Close();
}


void CDisk::CreateHugeBlankFile(CString file_name, int times)
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

void CDisk::LoadPlayoffMonth(CString file_name, CBBallSchedule schedule)
{
		CFile file( file_name,  CFile::modeRead);


		int len = (int)file.GetLength();
		if(len > 72000)
		{

		
	


		int i = 12;//playoff Month
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





				int matchup = team1*100 + team2;
				int score = score1*1000 + score2;
				schedule.m_schedule[i][j][k] = matchup;
				schedule.m_game_score[i][j][k] = score;
			}
		
		}
		}
		file.Close();
}

int CDisk::CreatePlayerObjectFromSpreadSheet(CString file_name, BOOL adjust, BOOL random, int lines)
{
//	int players_loaded = 0;	

	CStdioFile file(file_name, CFile::modeRead);
	CString string;
	int count = 1;
	for(int i=0; i<=lines; i++)
	{
    CPlayer m_player;
//	avg.m_actual[i] = m_player;
	int team = 4;
	int comp = 4;
	int dur = 3;
	int ten = 90;
	int pot1 = 3;
	int pot2 = 3;
	int effort = 3;
	
		bool eol = false;//end of line
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
		if(i == 0)  continue;
	int len = string.GetLength();
	string = string + ",";

	int offset = 0;
	int index = string.Find(",", offset); 
//	if(index <= 0) continue;

	m_player.m_clutch = 2;
	m_player.m_consistency = 2;

	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 
	m_player.m_name = str;

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 

	if(str == "C") str = " C";
	m_player.m_pos = str;

	
	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_age = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_games = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_min = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fga = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ftm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fta = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfga = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_oreb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_reb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ast = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_stl = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_to = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_blk = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_pf = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	CString ft, in;
	if(index > 0 && eol == false) 
	{
		chars = (index - offset);
		str = string.Mid(offset, chars); 
		ft = str;
	}
	else eol = true;


	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	if(index > 0 && eol == false)
	{
		chars = (index - offset);
		str = string.Mid(offset, chars); 
		in = str;
		int size = atoi(ft)*12 + atoi(in); 
		m_player.m_height = size;
	}
	else eol = true;

	offset = index + 1;
	index = string.Find(",", offset); 
//	if(index <= 0) continue;
	if(index > 0 && eol == false)
	{
		chars = (index - offset);
		str = string.Mid(offset, chars); 
		int weight = atoi(str);
		m_player.m_weight = weight;
	}
	else eol = true;

	if(m_player.m_height == 0 || m_player.m_weight == 0) m_player.GenerateRandomHeightWeight(true);


	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false)
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	pot1 = atoi(str);
	}
	else eol = true;

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false) 
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	pot2 = atoi(str);
	}
	else eol = true;

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0  &&  eol == false)
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	effort = atoi(str);
	}
	else eol = true;


	

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false) 
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	team = atoi(str);
	}
	else eol = true;

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false)
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	comp = atoi(str);
	}
	else eol = true;

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false) 
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	dur = atoi(str);
	}
	else eol = true;


	offset = index + 1;
	index = string.Find(",", offset); 
	if(index > 0 && eol == false) 
	{
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	ten = atoi(str);
	}
	else eol = true;




	if(random == TRUE)
	{
		pot1 = IntRandom(5);
		pot2 = IntRandom(5);
		effort = IntRandom(5);
	}
	if(adjust == TRUE)
	{
		m_player.AdjustForPro(team, comp, dur, ten);
	}

//	if(m_player.m_yrs_of_service < 1 && lines != 96)
//		m_player.m_yrs_of_service = 1;
	
	bool adj = true;
	if(adjust == FALSE) adj = false;
	m_player.Calculate(adj);
	m_player.m_pot1 = pot1;
	m_player.m_pot2 = pot2;
	m_player.m_effort = effort;

			m_player.m_coach_factor = IntRandom(5);
			m_player.m_security_factor = IntRandom(5);
			m_player.m_loyalty_factor = IntRandom(5);
			m_player.m_winning_factor = IntRandom(5);
			m_player.m_playing_time_factor = IntRandom(5);
			m_player.m_tradition_factor = IntRandom(5);
			m_player.m_yrs_on_team = 1;
			m_player.m_yrs_of_service = 1;
			m_player.GenerateRandomPrime();
			
			if( m_player.m_name == ""  ||  m_player.m_min < 96 || m_player.m_fga < 1 || m_player.m_fta < 1 || m_player.m_to < 1 || m_player.m_tfga > m_player.m_fga || m_player.m_fgm > m_player.m_fga 
				|| m_player.m_ftm > m_player.m_fta || m_player.m_tfgm > m_player.m_tfga || (m_player.m_fgm - m_player.m_tfgm) > (m_player.m_fga - m_player.m_tfga) ||
				(m_player.m_stl * 8) > (m_player.m_min * 1)) continue;

			avg.m_actual[count] = m_player;
			count = count + 1;

	}	
	
	return count - 1;
	
}

/*void CDisk::MergeRosters(CString filename)
{
	CStdioFile file(filename, CFile::modeRead);
	CString string;
	int i = 0; 
	int count = 0;
	for(int j=0; j<=580; j++)
	{

		CPlayer m_player;
		//avg.m_actual[i] = temp;
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
		string = string + ",";
	int len = string.GetLength();
	
	int offset = 0;
	int index = string.Find(",", offset); 
	int chars = (index - offset);
	CString name = string.Mid(offset, chars); 

	int pos = name.Find(' ');
	CString last = name.Mid(pos + 1);
	CString first = name.Left(4);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	CString feet = string.Mid(offset, chars); 

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	CString inch = string.Mid(offset, chars); 


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	CString weight = string.Mid(offset, chars); 

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	CString birth = string.Mid(offset, chars); 

	int ch = birth.Find("/", 0);
	CString mo = birth.Mid(0,ch);
	int mon = atoi(mo);

	CString byr = birth.Right(4);
	int byear = atoi(byr);

	int age = 2006 - byear;
	if(mon > 10) age = age - 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	CString years = string.Mid(offset, chars); 
	int yr = 0;
	if(years.Left(1) == "R")
	{
		yr = 1;
	}
	else
	{
		yr = atoi(years)+1;
	}

	for(int i=0; i<=580; i++)
	{
		avg.m_actual[i].SetLastName(avg.m_actual[i].m_name);
		CString last1 = avg.m_actual[i].m_lastName;
		CString first1 = avg.m_actual[i].m_name.Left(4);
		if(first1 == "") continue;

		first.Remove('.');
		first.Remove(' ');
		first.MakeUpper();
		last.Remove('.');
		last.Remove(' ');
		last.MakeUpper();

		first1.Remove('.');
		first1.Remove(' ');
		first1.MakeUpper();
		last1.Remove('.');
		last1.Remove(' ');
		last1.MakeUpper();


		
		//na.SetLastName(na.m_name);
		if(first == first1 && last == last1) 
		{
			count = count + 1;
			avg.m_actual[i].m_weight = atoi(weight);
			avg.m_actual[i].m_height = atoi(feet)*12 + atoi(inch);
			avg.m_actual[i].m_age = age;
			avg.m_actual[i].m_yrs_of_service = yr;

		}
	}


	}


	

}*/

int CDisk::CreatePlayerObjectFromPlayerSpreadSheet(CString file_name, BOOL &check_ages, BOOL &check_contracts, int current_yr, BOOL swap_name)
{

	int players_loaded = 0;
	avg.SetHighs(true);
	CStdioFile file(file_name, CFile::modeRead);
	CString string;
	int i = 0; 

	for(int j=0; j<=580; j++)
	{

		CPlayer m_player;
		//avg.m_actual[i] = temp;
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
		string = string + ",";
		if(j == 0)  continue;
	int len = string.GetLength();
	
	int offset = 0;
	int index = string.Find(",", offset); 

	m_player.m_clutch = 2;
	m_player.m_consistency = 2;

	int age = 20 + IntRandom(14);
	if(age == 20 || age == 34) age = 17 + IntRandom(24);
	m_player.m_age = age;



	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 

	if(swap_name == TRUE)
	{
		offset = index + 1;
		index = string.Find(',', offset);
		//CString last = string.Mid(index+1);
		chars = (index - offset);
		CString first = string.Mid(offset, chars);
		//str = first + " " + last;
		str = first + " " + str;
	}

	str.Remove('"');
	if(swap_name == TRUE) str.MakeUpper();
	m_player.m_name = str;


	
	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 






	m_player.m_team_paying_name = str;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 

	if(str == "C") str = " C";
	if(str != "PG" && str != "SG" && str != "SF" && str != "PF" && str != " C") continue;
	m_player.m_pos = str;


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_games = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_min = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fga = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfga = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ftm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fta = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_oreb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_reb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ast = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_stl = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_to = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_blk = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_pf = atoi(str);

	if(check_ages == TRUE)
	{

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_age = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_yrs_of_service = atoi(str);



	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	CString ft = str;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	CString in = str;

	int size = atoi(ft)*12 + atoi(in); 
	m_player.m_height = size;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	int weight = atoi(str);
	m_player.m_weight = weight;

	}

	if(check_contracts == TRUE)
	{

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_yrs_on_team = atoi(str);

	m_player.m_contract_salaries[0] = 0;
	
	
	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[1] = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[2] = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[3] = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[4] = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[5] = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_contract_salaries[6] = atoi(str);

	}

	if( m_player.m_name == ""  ||  m_player.m_min < 96 || m_player.m_fga < 1 || m_player.m_fta < 1 || m_player.m_to < 1 || m_player.m_tfga > m_player.m_fga || m_player.m_fgm > m_player.m_fga 
				|| m_player.m_ftm > m_player.m_fta || m_player.m_tfgm > m_player.m_tfga || (m_player.m_fgm - m_player.m_tfgm) > (m_player.m_fga - m_player.m_tfga) ||
				(m_player.m_stl * 8) > (m_player.m_min * 1)) continue;	
			
		i = i + 1;
		avg.m_actual[i] = m_player;



	}
	
	players_loaded = i;
	
	file.Close();

	for(int i=0; i<=580; i++)
	{
		if(i > players_loaded || i==0)
		{
			CPlayer tmp;
			avg.m_actual[i] = tmp;
		}
		else if(avg.m_actual[i].m_yrs_of_service < 1)
			avg.m_actual[i].m_yrs_of_service = 1;
		avg.m_actual[i].Calculate(0);
	}

	avg.CalculateBetter(0);

	return players_loaded;
}


int CDisk::CreatePlayerObjectFromDataBase(CString file_name,  int current_yr, bool rookies)
{

	//bool misc_found = false;
	int players_loaded = 0;

	avg.SetHighs(true);
	

	CStdioFile file(file_name, CFile::modeRead);
	CString string;

	int i = 0;
	for(int j=0; j<=9999; j++)
	{
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
		string = string + ",";
		if(j == 0)  continue;

	

	int len = string.GetLength();
	
	int offset = 0;
	int index = string.Find(",", offset); 
	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 
	int yr = atoi(str);
	if(yr != current_yr) continue;




	if(index <= 0) continue;



	
	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	CString po = string.Mid(offset, chars); 

	if(po == "C") po = " C";
	if(po != "PG" && po != "SG" && po != "SF" && po != "PF" && po != " C") continue;


	
	
	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	CString first = string.Mid(offset, chars); 

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	CString last = string.Mid(offset, chars); 


	
	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	CString tea = string.Mid(offset, chars); 



	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	CString ft = str;

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	CString in = str;

	int size = atoi(ft)*12 + atoi(in); 

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	int weight = atoi(str);



	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	int yrs = atoi(str);
	if(yrs != 1 && rookies == true) continue;
		


	CPlayer m_player;
	m_player.m_clutch = 2;
	m_player.m_consistency = 2;
	m_player.m_pos = po;
	m_player.m_name = first + " " + last;
	m_player.m_team_paying_name = tea;
	m_player.m_height = size;
	m_player.m_weight = weight;	
	m_player.m_yrs_of_service = yrs;
	m_player.m_yrs_on_team = IntRandom(yrs);


	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_age = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_games = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_min = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fga = atoi(str);
//	if(m_player.m_fga < 3) continue;



	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfgm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_tfga = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ftm = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_fta = atoi(str);



	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_oreb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_reb = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_ast = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_stl = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_to = atoi(str);

	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_blk = atoi(str);



	offset = index + 1;
	index = string.Find(",", offset); 
	if(index <= 0) continue;
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_player.m_pf = atoi(str);

			int r = IntRandom(5);			
			m_player.m_coach_factor = r;

			r = IntRandom(5);			
			m_player.m_loyalty_factor = r;

			r = IntRandom(5);			
			m_player.m_playing_time_factor = r;

			r = IntRandom(5);			
			m_player.m_winning_factor = r;

			r = IntRandom(5);			
			m_player.m_tradition_factor = r;

			r = IntRandom(5);			
			m_player.m_security_factor = r;

	if( m_player.m_name == ""  ||  m_player.m_min < 96 || m_player.m_fga < 1 || m_player.m_fta < 1 || m_player.m_to < 1 || m_player.m_tfga > m_player.m_fga || m_player.m_fgm > m_player.m_fga 
				|| m_player.m_ftm > m_player.m_fta || m_player.m_tfgm > m_player.m_tfga || (m_player.m_fgm - m_player.m_tfgm) > (m_player.m_fga - m_player.m_tfga) ||
				(m_player.m_stl * 8) > (m_player.m_min * 1)) continue;	
			
		i = i + 1;
		avg.m_actual[i] = m_player;

	}


	players_loaded = i;	

	file.Close();



	avg.CalculateBetter(0);	
	for(int j=0; j<=960; j++)
	{
		if(avg.m_actual[j].m_yrs_of_service < 1)
			avg.m_actual[j].m_yrs_of_service = 1;
		avg.m_actual[j].m_content = 5;
		avg.m_actual[i].GenerateRandomPrime();
		avg.m_actual[j].Calculate(0);
		if( j > i) 
		{
			CPlayer temp;
			avg.m_actual[j] = temp;
		}

	}

	return players_loaded;	

}



void CDisk::SetUpTeamsFromImportedFile(CString names_list[33], int league_style)
{

	CPlayer* m_player = new CPlayer[1441];
	int team_counters[33];
	for(int i=0; i<= 32; i++)
	{
		team_counters[i] = 0;
	}

	

	//convert names list if necessary
	CString names_list1[33], names_list2[33], names_list3[33], names_list4[33], names_list5[33];

		for(int j=0; j<=32; j++)
		{
		CString name = names_list[j];
		name.MakeLower();
		if(name == "phi" || name == "philadelphia" || name == "76ers")
		{
			names_list1[j] = "phi";
			names_list2[j] = "philadelphia";
			names_list3[j] = "76ers";
		}
		else if(name == "bos" || name == "boston" || name == "celtics")
		{
			names_list1[j] = "bos";
			names_list2[j] = "boston";
			names_list3[j] = "celtics";
		}
		else if(name == "mia" || name == "miami" || name == "heat")
		{
			names_list1[j] = "mia";
			names_list2[j] = "miami";
			names_list3[j] = "heat";
		}
		else if(name == "nj" || name == "njn" || name == "new jersey"
			|| name == "nets")
		{
			names_list1[j] = "nj";
			names_list2[j] = "njn";
			names_list3[j] = "new jersey";
			names_list4[j] = "nets";
		}
		else if(name == "ny" || name == "nyk" || name == "new york"
			|| name == "knicks")
		{
			names_list1[j] = "ny";
			names_list2[j] = "nyk";
			names_list3[j] = "new york";
			names_list4[j] = "knicks";
		}
		else if(name == "orl" || name == "orlando" || name == "magic")
		{
			names_list1[j] = "orl";
			names_list2[j] = "orlando";
			names_list3[j] = "magic";
		}
		else if(name == "was" || name == "washington" || name == "wizards" || name == "bullets")
		{
			names_list1[j] = "was";
			names_list2[j] = "washington";
			names_list3[j] = "wizards";
			names_list4[j] = "bullets";
		}
		else if(name == "atl" || name == "atlanta" || name == "hawks")
		{
			names_list1[j] = "atl";
			names_list2[j] = "atlanta";
			names_list3[j] = "hawks";
		}
		else if(name == "cha" || name == "charlotte" || name == "hornets"
			|| name == "nor" || name == "new orleans")
		{
			names_list1[j] = "cha";
			names_list2[j] = "charlotte";
			names_list3[j] = "hornets";
			names_list4[j] = "nor";
			names_list5[j] = "new orleans";
		}
		else if(name == "bobcats")
		{
			names_list1[j] = "bobcats";
		}
		else if(name == "chi" || name == "chicago" || name == "bulls")
		{
			names_list1[j] = "chi";
			names_list2[j] = "chicago";
			names_list3[j] = "bulls";
		}
		else if(name == "cle" || name == "cleveland" || name == "cavs" || name == "cavaliers")
		{
			names_list1[j] = "cle";
			names_list2[j] = "cleveland";
			names_list3[j] = "cavs";
			names_list4[j] = "cavaliers";
		}
		else if(name == "det" || name == "detroit" || name == "pistons")
		{
			names_list1[j] = "det";
			names_list2[j] = "detroit";
			names_list3[j] = "pistons";
		}
		else if(name == "ind" || name == "indiana" || name == "pacers")
		{
			names_list1[j] = "ind";
			names_list2[j] = "indiana";
			names_list3[j] = "pacers";
		}
		else if(name == "mil" || name == "milwaukee" || name == "bucks")
		{
			names_list1[j] = "mil";
			names_list2[j] = "milwaukee";
			names_list3[j] = "bucks";
		}
		else if(name == "tor" || name == "toronto" || name == "raptors")
		{
			names_list1[j] = "tor";
			names_list2[j] = "toronto";
			names_list3[j] = "raptors";
		}
		else if(name == "dal" || name == "dallas" || name == "mavs" 
			|| name == "mavericks")
		{
			names_list1[j] = "dal";
			names_list2[j] = "dallas";
			names_list3[j] = "mavs";
			names_list4[j] = "mavericks";
		}
		else if(name == "den" || name == "denver" || name == "nuggets")
		{
			names_list1[j] = "den";
			names_list2[j] = "denver";
			names_list3[j] = "nuggets";
		}
		else if(name == "hou" || name == "houston" || name == "rockets")
		{
			names_list1[j] = "hou";
			names_list2[j] = "houston";
			names_list3[j] = "rockets";
		}
		else if(name == "min" || name == "minnesota" || name == "wolves"
			|| name == "timberwolves" || name == "twolves")
		{
			names_list1[j] = "min";
			names_list2[j] = "minnesota";
			names_list3[j] = "wolves";
			names_list4[j] = "timberwolves";
			names_list5[j] = "twolves";
		}
		else if(name == "san" || name == "san antonio" || name == "spurs"
			|| name == "sa")
		{
			names_list1[j] = "san";
			names_list2[j] = "san antonio";
			names_list3[j] = "spurs";
			names_list4[j] = "sa";
		}
		else if(name == "uta" || name == "utah" || name == "jazz")
		{
			names_list1[j] = "uta";
			names_list2[j] = "utah";
			names_list3[j] = "jazz";
		}
		else if(name == "mem" || name == "memphis" || name == "grizzlies"
			|| name == "van" || name == "vancouver")
		{
			names_list1[j] = "mem";
			names_list2[j] = "memphis";
			names_list3[j] = "grizzlies";
			names_list4[j] = "van";
			names_list5[j] = "vancouver";
		}
		else if(name == "gsw" || name == "golden state" || name == "warriors"
			|| name == "gs")
		{
			names_list1[j] = "gsw";
			names_list2[j] = "golden state";
			names_list3[j] = "warriors";
			names_list4[j] = "gs";
		}
		else if(name == "lac" || name == "la clippers" || name == "clippers")
		{
			names_list1[j] = "lac";
			names_list2[j] = "la clippers";
			names_list3[j] = "clippers";
		}
		else if(name == "lal" || name == "la lakers" || name == "lakers")
		{
			names_list1[j] = "lal";
			names_list2[j] = "la lakers";
			names_list3[j] = "lakers";
		}
		else if(name == "pho" || name == "phoenix" || name == "suns")
		{
			names_list1[j] = "pho";
			names_list2[j] = "phoenix";
			names_list3[j] = "suns";
		}
		else if(name == "por" || name == "portland" || name == "blazers"
			|| name == "trailblazers")
		{
			names_list1[j] = "por";
			names_list2[j] = "portland";
			names_list3[j] = "blazers";
			names_list4[j] = "trailblazers";
		}
		else if(name == "sac" || name == "sacramento" || name == "kings")
		{
			names_list1[j] = "sac";
			names_list2[j] = "sacramento";
			names_list3[j] = "kings";
		}
		else if(name == "sea" || name == "okl" || name == "sonics"
			|| name == "supersonics")
		{
			names_list1[j] = "sea";
			names_list2[j] = "okl";
			names_list3[j] = "sonics";
			names_list4[j] = "supersonics";
		}


	}



	
	for(int i = 0; i<= 580; i++)
	{
		if(avg.m_actual[i].m_name == "") continue;
		int slot = -1;
		for(int j=0; j<=31; j++)
		{
			CString na1 = names_list[j];
			na1.MakeLower();
			CString na2 = avg.m_actual[i].m_team_paying_name;
			na2.MakeLower();
			if((na2 == na1 ||
				na2 == names_list1[j] ||
				na2 == names_list2[j] ||
				na2 == names_list3[j] ||
				na2 == names_list4[j] ||
				na2 == names_list5[j])
				&& team_counters[j] < 14 && na2 != "") 
			{
				avg.m_actual[i].m_team_paying_name = m_leagueTeamNames[j];
				team_counters[j] = team_counters[j] + 1;
				slot = j*30 + team_counters[j];
				m_player[slot] = avg.m_actual[i];
			}
		}
		if(slot == -1)
		{
			team_counters[32] = team_counters[32] + 1;
			if(team_counters[32] <= 96) m_player[960 + team_counters[32]] = avg.m_actual[i];
		}

	}

	for(int i=0; i<=1440; i++)
	{
		if(league_style != 2)//2 is draft league so no reassign just draft
			avg.m_actual[i] = m_player[i];
	}



	delete [] m_player;

	avg.SetHighs(true);
}

void CDisk::WriteNewPlayerDataFile(CString file_name)
{
	CString buffer[256];
	CreateHugeBlankFile(file_name, 2);
	CStdioFile file( file_name, CFile::modeWrite );
	int player = 0;
	int index = 0;
	for(int i=0; i<=1600; i++)
	{

		CPlayer m_player;
		if (i <= 1320)
		{
			m_player = avg.m_actual[i];
		}
		else if (i >= 1441)
		{
			m_player = avg.m_actual[i];
		}

		buffer[0].Format("%4d", i);
		CString Name = m_player.GetName(); 
		Name.TrimLeft();
		Name.TrimRight();
		buffer[1].Format("%32s", Name);	
		buffer[2].Format("%2d", m_player.GetAge());
		buffer[3].Format("%6d", m_player.GetID());
		buffer[4].Format("%2d", m_player.m_team_paying);
		buffer[5].Format("%4d", m_player.m_prime);
		buffer[6].Format("%2s", m_player.m_pos);
		buffer[7].Format("%4d", m_player.GetGames());
		buffer[8].Format("%4d", m_player.GetMin());
		buffer[9].Format("%4d", m_player.GetFgm());
		buffer[10].Format("%4d", m_player.GetFga());
		buffer[11].Format("%4d", m_player.GetFtm());
		buffer[12].Format("%4d", m_player.GetFta());
		buffer[13].Format("%4d", m_player.GetTfgm());
		buffer[14].Format("%4d", m_player.GetTfga());
		buffer[15].Format("%4d", m_player.GetOreb());
		buffer[16].Format("%4d", m_player.GetReb());
		buffer[17].Format("%4d", m_player.GetAst());
		buffer[18].Format("%4d", m_player.GetStl());
		buffer[19].Format("%4d", m_player.GetTo());
		buffer[20].Format("%4d", m_player.GetBlk());
		buffer[21].Format("%4d", m_player.GetPf());
		buffer[22].Format("%2d", m_player.GetMovOff());
		buffer[23].Format("%2d", m_player.GetMovDef());
		buffer[24].Format("%2d", m_player.GetPenOff());
		buffer[25].Format("%2d", m_player.GetPenDef());
		buffer[26].Format("%2d", m_player.GetPostOff());
		buffer[27].Format("%2d", m_player.GetPostDef());
		buffer[28].Format("%2d", m_player.GetTransOff());
		buffer[29].Format("%2d", m_player.GetTransDef());
		buffer[30].Format("%2d", m_player.GetClutch());
		buffer[31].Format("%2d", m_player.GetConsistency());
		int pg = m_player.GetPgRot();		
		int sg = m_player.GetSgRot();		
		int sf = m_player.GetSfRot();		
		int pf = m_player.GetPfRot();		
		int  c = m_player.GetCRot();
		buffer[32].Format("%d", pg);
		buffer[33].Format("%d", sg);
		buffer[34].Format("%d", sf);
		buffer[35].Format("%d", pf);
		buffer[36].Format("%d", c);
		buffer[37].Format("%d", m_player.GetActive());
		buffer[38].Format("%2d", m_player.GetBetter());
	
		int injury = m_player.GetInjury();
		buffer[39].Format("%4d", injury);
		int starts = m_player.m_starter;
		buffer[40].Format("%4d", starts);
		int games = m_player.m_sim_games;
		buffer[41].Format("%4d", games);
		int min = m_player.m_sim_min;
		buffer[42].Format("%4d", min);
		int fgm = m_player.m_sim_fgm;
		buffer[43].Format("%4d", fgm);
		int fga = m_player.m_sim_fga;
		buffer[44].Format("%4d", fga);
		int ftm = m_player.m_sim_ftm;		
		buffer[45].Format("%4d", ftm);
		int fta = m_player.m_sim_fta;
		buffer[46].Format("%4d", fta);
		int tfgm = m_player.m_sim_tfgm;		
		buffer[47].Format("%4d", tfgm);
		int tfga = m_player.m_sim_tfga;		
		buffer[48].Format("%4d", tfga);
		int oreb = m_player.m_sim_oreb;		
		buffer[49].Format("%4d", oreb);
		int reb = m_player.m_sim_reb;
		buffer[50].Format("%4d", reb);
		int ast = m_player.m_sim_ast;		
		buffer[51].Format("%4d", ast);
		int stl = m_player.m_sim_stl;
		buffer[52].Format("%4d", stl);
		int to = m_player.m_sim_to;
		buffer[53].Format("%4d", to);
		int blk = m_player.m_sim_blk;
		buffer[54].Format("%4d", blk);
		pf = m_player.m_sim_pf;
		buffer[55].Format("%4d", pf);

		games = m_player.m_po_games;
		buffer[56].Format("%4d", games);
		min = m_player.m_po_min;
		buffer[57].Format("%4d", min);
		fgm = m_player.m_po_fgm;
		buffer[58].Format("%4d", fgm);
		fga = m_player.m_po_fga;
		buffer[59].Format("%4d", fga);
		ftm = m_player.m_po_ftm;		
		buffer[60].Format("%4d", ftm);
		fta = m_player.m_po_fta;
		buffer[61].Format("%4d", fta);
		tfgm = m_player.m_po_tfgm;		
		buffer[62].Format("%4d", tfgm);
		tfga = m_player.m_po_tfga;		
		buffer[63].Format("%4d", tfga);
		oreb = m_player.m_po_oreb;		
		buffer[64].Format("%4d", oreb);
		reb = m_player.m_po_reb;
		buffer[65].Format("%4d", reb);
		ast = m_player.m_po_ast;		
		buffer[66].Format("%4d", ast);
		stl = m_player.m_po_stl;
		buffer[67].Format("%4d", stl);
		to = m_player.m_po_to;
		buffer[68].Format("%4d", to);
		blk = m_player.m_po_blk;
		buffer[69].Format("%4d", blk);
		pf = m_player.m_po_pf;
		buffer[70].Format("%4d", pf);
		
		buffer[71].Format("%2d", m_player.m_pot1);
		buffer[72].Format("%2d", m_player.m_pot2);
		buffer[73].Format("%2d", m_player.m_effort);
		buffer[74].Format("%2d", m_player.m_coach_factor);
		buffer[75].Format("%2d", m_player.m_loyalty_factor);
		buffer[76].Format("%2d", m_player.m_playing_time_factor);
		buffer[77].Format("%2d", m_player.m_winning_factor);
		buffer[78].Format("%2d", m_player.m_tradition_factor);
		buffer[79].Format("%2d", m_player.m_security_factor);
	
		buffer[80].Format("%2d", m_player.m_yrs_of_service);
		buffer[81].Format("%2d", m_player.m_yrs_on_team);
		buffer[82].Format("%2d", m_player.m_current_contract_yr);
		buffer[83].Format("%2d", m_player.m_contract_yrs);
		//write year by year salaries
		int yrs = m_player.m_contract_yrs;
		int co = 83;
		for(int y=0; y<=6; y++)
		{
			co = co + 1;
			buffer[co].Format("%4d", m_player.m_contract_salaries[y]);
		}
	
		buffer[91].Format("%1d", m_player.m_random_contract_ratings);
		buffer[92].Format("%1d", m_player.m_random_contracts);
		buffer[93].Format("%1d", m_player.m_random_projections);
		buffer[94].Format("%1d", m_player.m_random_yrs_service);
		buffer[95].Format("%2d", m_player.m_round_selected);
		buffer[96].Format("%2d", m_player.m_pick_selected);

		if(m_player.m_rookie == 0) buffer[97] = "0";
		else buffer[97] = "1";


		buffer[98].Format("%2d", m_player.m_team_paying);
		buffer[99].Format("%2d", m_player.m_current_team);
		buffer[100].Format("%2d", m_player.m_previous_team);

		buffer[101].Format("%1d", m_player.m_all_star);
		buffer[102].Format("%1d", m_player.m_rookie_star);
		buffer[103].Format("%1d", m_player.m_3contest);
		buffer[104].Format("%1d", m_player.m_dunkcontest);

		buffer[105].Format("%2d", m_player.m_hi_pts);
		buffer[106].Format("%2d", m_player.m_hi_reb);
		buffer[107].Format("%2d", m_player.m_hi_ast);
		buffer[108].Format("%2d", m_player.m_hi_stl);
		buffer[109].Format("%2d", m_player.m_hi_blk);
		buffer[110].Format("%2d", m_player.m_double);
		buffer[111].Format("%2d", m_player.m_triple);

		buffer[112].Format("%2d", m_player.m_hi_pts_po);
		buffer[113].Format("%2d", m_player.m_hi_reb_po);
		buffer[114].Format("%2d", m_player.m_hi_ast_po);
		buffer[115].Format("%2d", m_player.m_hi_stl_po);
		buffer[116].Format("%2d", m_player.m_hi_blk_po);


		buffer[117].Format("%6d", m_player.m_hi_pts_car);		
		buffer[118].Format("%6d", m_player.m_hi_reb_car);
		buffer[119].Format("%6d", m_player.m_hi_ast_car);
		buffer[120].Format("%6d", m_player.m_hi_stl_car);
		buffer[121].Format("%6d", m_player.m_hi_blk_car);
		buffer[122].Format("%6d", m_player.m_double_car);
		buffer[123].Format("%6d", m_player.m_triple_car);

		buffer[124].Format("%6d", m_player.m_hi_pts_car_po);
		buffer[125].Format("%6d", m_player.m_hi_reb_car_po);
		buffer[126].Format("%6d", m_player.m_hi_ast_car_po);
		buffer[127].Format("%6d", m_player.m_hi_stl_car_po);
		buffer[128].Format("%6d", m_player.m_hi_blk_car_po);

		buffer[129].Format("%5d", m_player.m_car_games);
		buffer[130].Format("%5d", m_player.m_car_min);
		buffer[131].Format("%5d", m_player.m_car_fgm);
		buffer[132].Format("%5d", m_player.m_car_fga);
		buffer[133].Format("%5d", m_player.m_car_ftm);
		buffer[134].Format("%5d", m_player.m_car_fta);
		buffer[135].Format("%5d", m_player.m_car_tfgm);
		buffer[136].Format("%5d", m_player.m_car_tfga);
		buffer[137].Format("%5d", m_player.m_car_oreb);
		buffer[138].Format("%5d", m_player.m_car_reb);
		buffer[139].Format("%5d", m_player.m_car_ast);
		buffer[140].Format("%5d", m_player.m_car_stl);
		buffer[141].Format("%5d", m_player.m_car_to);
		buffer[142].Format("%5d", m_player.m_car_blk);
		buffer[143].Format("%5d", m_player.m_car_pf);

		CString desc = m_player.m_injury_desc; 
		desc.TrimLeft();
		desc.TrimRight();
		buffer[144].Format("%32s", desc);	


		buffer[145] = "0";
		if(m_player.m_on_block == true) buffer[145] = "1";

		buffer[146].Format("%1d", m_player.m_content);
		buffer[147].Format("%3d", m_player.m_health);
		buffer[148].Format("%1d", m_player.m_stop_negotiating);
		if(m_player.m_stop_negotiating > 9) m_player.m_stop_negotiating = 9;

		buffer[149].Format("%2d", m_player.m_height);
		buffer[150].Format("%3d", m_player.m_weight);

		buffer[151].Format("%3d", m_player.m_oldprFga);
		buffer[152].Format("%3d", m_player.m_oldprFgp);
		buffer[153].Format("%3d", m_player.m_oldprFta);
		buffer[154].Format("%3d", m_player.m_oldprFtp);
		buffer[155].Format("%3d", m_player.m_oldprTga);
		buffer[156].Format("%3d", m_player.m_oldprTgp);
		buffer[157].Format("%3d", m_player.m_oldprOrb);
		buffer[158].Format("%3d", m_player.m_oldprDrb);
		buffer[159].Format("%3d", m_player.m_oldprAst);
		buffer[160].Format("%3d", m_player.m_oldprStl);
		buffer[161].Format("%3d", m_player.m_oldprTo);
		buffer[162].Format("%3d", m_player.m_oldprBlk);
		buffer[163].Format("%2d", m_player.m_oldmovoff);
		buffer[164].Format("%2d", m_player.m_oldpenoff);
		buffer[165].Format("%2d", m_player.m_oldpostoff);
		buffer[166].Format("%2d", m_player.m_oldtransoff);
		buffer[167].Format("%2d", m_player.m_oldmovdef);
		buffer[168].Format("%2d", m_player.m_oldpendef);
		buffer[169].Format("%2d", m_player.m_oldpostdef);
		buffer[170].Format("%2d", m_player.m_oldtransdef);


		


		CString write_string;
		for(int y=0; y<=170; y++)
		{
			write_string = write_string + buffer[y];
		}
	
		file.WriteString( write_string + "\n");		

		
	}		

	file.Close(); 

}

void CDisk::ReadNewPlayerDataFile(CString file_name, CString dumb_file_name, CString team_names[33])
{

	bool exist = FileExists(dumb_file_name);
	if(exist == true) file_name = dumb_file_name;

  	CStdioFile file(file_name, CFile::modeRead);
	CString str;
	int player = 0;
	for(int i = 0; i<=1600; i++)
	{
		CPlayer m_player;
		file.ReadString(str);
		str.TrimRight();
		

		CString buf = str.Mid(0,4);
		m_player.SetRosterNumber(atoi(buf));

		buf = str.Mid(4,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_player.m_name = buf;

		if(i>=1473 && i<=1504)
		{
			m_player.m_name = avg.m_actual[i-32].m_name;
		}


		buf = str.Mid(38,6);
		m_player.m_id = atoi(buf);

		buf = str.Mid(44,2);
		m_player.m_team_paying = atoi(buf);

		buf = str.Mid(36,2);
		m_player.m_age = atoi(buf);

		buf = str.Mid(46, 4);
		m_player.m_prime = atoi(buf);



		buf = str.Mid(50,2);
		m_player.m_pos = buf;

		if(m_player.m_prime == 0)//screwed up leagues who all default to 27
		{
				m_player.GenerateRandomPrime();
		}


		buf = str.Mid(52,4);
		CString cBuf = buf;
		m_player.m_games = atoi(cBuf);
		buf = str.Mid(56,4);
		m_player.m_min = atoi(buf);

	

		buf = str.Mid(60,4);
		m_player.m_fgm = atoi(buf);
		buf = str.Mid(64,4);
		m_player.m_fga = atoi(buf);
		buf = str.Mid(68,4);
		m_player.m_ftm = atoi(buf);
		buf = str.Mid(72,4);
		m_player.m_fta = atoi(buf);
		buf = str.Mid(76,4);
		m_player.m_tfgm = atoi(buf);
		buf = str.Mid(80,4);
		m_player.m_tfga = atoi(buf);
		buf = str.Mid(84,4);
		m_player.m_oreb = atoi(buf);
		buf = str.Mid(88,4);
		m_player.m_reb = atoi(buf);
		buf = str.Mid(92,4);
		m_player.m_ast = atoi(buf);
		buf = str.Mid(96,4);
		m_player.m_stl = atoi(buf);
		buf = str.Mid(100,4);
		m_player.m_to = atoi(buf);
		buf = str.Mid(104,4);
		m_player.m_blk = atoi(buf);
		buf = str.Mid(108,4);
		m_player.m_pf = atoi(buf);

		//m_player.m_pf = int((double)m_player.m_min * 4/48);


		buf = str.Mid(112,2);
		m_player.m_movoff = atoi(buf);
		buf = str.Mid(114,2);
		m_player.m_movdef = atoi(buf);
		buf = str.Mid(116,2);
		m_player.m_penoff = atoi(buf);
		buf = str.Mid(118,2);
		m_player.m_pendef = atoi(buf);
		buf = str.Mid(120,2);
		m_player.m_postoff = atoi(buf);
		buf = str.Mid(122,2);
		m_player.m_postdef = atoi(buf);
		buf = str.Mid(124,2);
		m_player.m_transoff = atoi(buf);
		buf = str.Mid(126,2);
		m_player.m_transdef = atoi(buf);
		buf = str.Mid(128,2);
		m_player.m_clutch = atoi(buf);
		buf = str.Mid(130,2);
		m_player.m_consistency = atoi(buf);
		buf = str.Mid(132,1);
		m_player.m_pgrot = atoi(buf);		
		buf = str.Mid(133,1);
		m_player.m_sgrot = atoi(buf);		
		buf = str.Mid(134,1);
		m_player.m_sfrot = atoi(buf);		
		buf = str.Mid(135,1);
		m_player.m_pfrot = atoi(buf);		
		buf = str.Mid(136,1);
		m_player.m_crot = atoi(buf);
		buf = str.Mid(137,1);
		m_player.m_active = atoi(buf);
		buf = str.Mid(138,2);
		m_player.m_better = atoi(buf);
		buf = str.Mid(140,4);
		m_player.m_injury = atoi(buf);
		buf = str.Mid(144,4);
		m_player.m_starter = atoi(buf);
		buf = str.Mid(148,4);
		m_player.m_sim_games = atoi(buf);
		buf = str.Mid(152,4);
		m_player.m_sim_min = atoi(buf);
		buf = str.Mid(156,4);
		m_player.m_sim_fgm = atoi(buf);
		buf = str.Mid(160,4);
		m_player.m_sim_fga = atoi(buf);
		buf = str.Mid(164,4);
		m_player.m_sim_ftm = atoi(buf);		
		buf = str.Mid(168,4);
		m_player.m_sim_fta = atoi(buf);
		buf = str.Mid(172,4);
		m_player.m_sim_tfgm = atoi(buf);		
		buf = str.Mid(176,4);
		m_player.m_sim_tfga = atoi(buf);		
		buf = str.Mid(180,4);
		m_player.m_sim_oreb = atoi(buf);		
		buf = str.Mid(184,4);
		m_player.m_sim_reb = atoi(buf);
		buf = str.Mid(188,4);
		m_player.m_sim_ast = atoi(buf);		
		buf = str.Mid(192,4);
		m_player.m_sim_stl = atoi(buf);
		buf = str.Mid(196,4);
		m_player.m_sim_to = atoi(buf);
		buf = str.Mid(200,4);
		m_player.m_sim_blk = atoi(buf);
		buf = str.Mid(204,4);
		m_player.m_sim_pf = atoi(buf);
		buf = str.Mid(208,4);

		m_player.m_po_games = atoi(buf);
		buf = str.Mid(212,4);
		m_player.m_po_min = atoi(buf);
		buf = str.Mid(216,4);
		m_player.m_po_fgm = atoi(buf);
		buf = str.Mid(220,4);
		m_player.m_po_fga = atoi(buf);
		buf = str.Mid(224,4);
		m_player.m_po_ftm = atoi(buf);		
		buf = str.Mid(228,4);
		m_player.m_po_fta = atoi(buf);
		buf = str.Mid(232,4);
		m_player.m_po_tfgm = atoi(buf);		
		buf = str.Mid(236,4);
		m_player.m_po_tfga = atoi(buf);		
		buf = str.Mid(240,4);
		m_player.m_po_oreb = atoi(buf);		
		buf = str.Mid(244,4);
		m_player.m_po_reb = atoi(buf);
		buf = str.Mid(248,4);
		m_player.m_po_ast = atoi(buf);		
		buf = str.Mid(252,4);
		m_player.m_po_stl = atoi(buf);
		buf = str.Mid(256,4);
		m_player.m_po_to = atoi(buf);
		buf = str.Mid(260,4);
		m_player.m_po_blk = atoi(buf);
		buf = str.Mid(264,4);
		m_player.m_po_pf = atoi(buf);
		buf = str.Mid(268,2);
		m_player.m_pot1 = atoi(buf);
		buf = str.Mid(270,2);
		m_player.m_pot2 = atoi(buf);
		buf = str.Mid(272,2);
		m_player.m_effort = atoi(buf);
		buf = str.Mid(274,2);
		m_player.m_coach_factor = atoi(buf);
		buf = str.Mid(276,2);
		m_player.m_loyalty_factor = atoi(buf);
		buf = str.Mid(278,2);
		m_player.m_playing_time_factor = atoi(buf);
		buf = str.Mid(280,2);
		m_player.m_winning_factor = atoi(buf);
		buf = str.Mid(282,2);
		m_player.m_tradition_factor = atoi(buf);
		buf = str.Mid(284,2);
		m_player.m_security_factor = atoi(buf);
		buf = str.Mid(286,2);
		m_player.m_yrs_of_service = atoi(buf);

		//if(m_player.m_yrs_of_service >= 2)
		//	m_player.m_yrs_of_service = m_player.m_yrs_of_service - 1;




		buf = str.Mid(288,2);
		m_player.m_yrs_on_team = atoi(buf);
		buf = str.Mid(290,2);
		m_player.m_current_contract_yr = atoi(buf);
		buf = str.Mid(292,2);
		m_player.m_contract_yrs = atoi(buf);
		//write year by year salaries
		int yrs = m_player.m_contract_yrs;
		int co = 294;
		for(int y=0; y<=6; y++)
		{
			buf = str.Mid(co,4);
			m_player.m_contract_salaries[y] = atoi(buf);
			co = co + 4;
		}
		buf = str.Mid(322, 1);
		if(buf == "1")
			m_player.m_random_contract_ratings = true;
		else
			m_player.m_random_contract_ratings = 0;

		buf = str.Mid(323, 1);
		if(buf == "1")
			m_player.m_random_contracts = true;
		else
			m_player.m_random_contracts = 0;

		buf = str.Mid(324, 1);
		if(buf == "1")
			m_player.m_random_projections = true;
		else
			m_player.m_random_projections = 0;

		buf = str.Mid(325, 1);
		if(buf == "1")
			m_player.m_random_yrs_service = true;
		else
			m_player.m_random_yrs_service = 0;
	
		buf = str.Mid(326, 2);
		m_player.m_round_selected = atoi(buf);
		buf = str.Mid(328, 2);
		m_player.m_pick_selected = atoi(buf);
		buf = str.Mid(330, 1);
		if(buf == "1")
			m_player.m_rookie = true;
		else
			m_player.m_rookie = 0;

		buf = str.Mid(331,2);
		m_player.m_team_paying = atoi(buf);
		int te = m_player.m_team_paying - 1;

		if(te >= 0)
			m_player.m_team_paying_name = team_names[te];
		else
			m_player.m_team_paying_name = "";

		buf = str.Mid(333,2);
		m_player.m_current_team = atoi(buf);

		//set no matter what it reads just in case
		if(i <= 960 && i >= 1 && m_player.m_name != "")
		{
			int te = (i-1) / 30;
			m_player.m_current_team = te;
		}
		else
			m_player.m_current_team = -1;

		buf = str.Mid(335,2);
		m_player.m_previous_team = atoi(buf);


		buf = str.Mid(337,1);
		m_player.m_all_star = atoi(buf);

		buf = str.Mid(338,1);
		m_player.m_rookie_star = atoi(buf);

		buf = str.Mid(339,1);
		m_player.m_3contest = atoi(buf);

		buf = str.Mid(340,1);
		m_player.m_dunkcontest = atoi(buf);



		buf = str.Mid(341,2);
		m_player.m_hi_pts = atoi(buf);

		buf = str.Mid(343,2);
		m_player.m_hi_reb = atoi(buf);

		buf = str.Mid(345,2);
		m_player.m_hi_ast = atoi(buf);

		buf = str.Mid(347,2);
		m_player.m_hi_stl = atoi(buf);

		buf = str.Mid(349,2);
		m_player.m_hi_blk = atoi(buf);

		buf = str.Mid(351,2);
		m_player.m_double = atoi(buf);

		buf = str.Mid(353,2);
		m_player.m_triple = atoi(buf);




		buf = str.Mid(355,2);
		m_player.m_hi_pts_po = atoi(buf);

		buf = str.Mid(357,2);
		m_player.m_hi_reb_po = atoi(buf);

		buf = str.Mid(359,2);
		m_player.m_hi_ast_po = atoi(buf);

		buf = str.Mid(361,2);
		m_player.m_hi_stl_po = atoi(buf);

		buf = str.Mid(363,2);
		m_player.m_hi_blk_po = atoi(buf);


		buf = str.Mid(365,6);
		m_player.m_hi_pts_car = atoi(buf);

		buf = str.Mid(371,6);
		m_player.m_hi_reb_car = atoi(buf);

		buf = str.Mid(377,6);
		m_player.m_hi_ast_car = atoi(buf);

		buf = str.Mid(383,6);
		m_player.m_hi_stl_car = atoi(buf);

		buf = str.Mid(389,6);
		m_player.m_hi_blk_car = atoi(buf);

		buf = str.Mid(395,6);
		m_player.m_double_car = atoi(buf);

		buf = str.Mid(401,6);
		m_player.m_triple_car = atoi(buf);


		buf = str.Mid(407,6);
		m_player.m_hi_pts_car_po = atoi(buf);

		buf = str.Mid(413,6);
		m_player.m_hi_reb_car_po = atoi(buf);

		buf = str.Mid(419,6);
		m_player.m_hi_ast_car_po = atoi(buf);

		buf = str.Mid(425,6);
		m_player.m_hi_stl_car_po = atoi(buf);

		buf = str.Mid(431,6);
		m_player.m_hi_blk_car_po = atoi(buf);

		buf = str.Mid(437,5);
		m_player.m_car_games = atoi(buf);

		buf = str.Mid(442,5);
		m_player.m_car_min = atoi(buf);

		buf = str.Mid(447,5);
		m_player.m_car_fgm = atoi(buf);

		buf = str.Mid(452,5);
		m_player.m_car_fga = atoi(buf);

		buf = str.Mid(457,5);
		m_player.m_car_ftm = atoi(buf);

		buf = str.Mid(462,5);
		m_player.m_car_fta = atoi(buf);

		buf = str.Mid(467,5);
		m_player.m_car_tfgm = atoi(buf);

		buf = str.Mid(472,5);
		m_player.m_car_tfga = atoi(buf);

		buf = str.Mid(477,5);
		m_player.m_car_oreb = atoi(buf);

		buf = str.Mid(482,5);
		m_player.m_car_reb = atoi(buf);

		buf = str.Mid(487,5);
		m_player.m_car_ast = atoi(buf);

		buf = str.Mid(492,5);
		m_player.m_car_stl = atoi(buf);

		buf = str.Mid(497,5);
		m_player.m_car_to = atoi(buf);

		buf = str.Mid(502,5);
		m_player.m_car_blk = atoi(buf);

		buf = str.Mid(507,5);
		m_player.m_car_pf = atoi(buf);


		buf = str.Mid(512,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_player.m_injury_desc = buf;

		buf = str.Mid(544,1);
		buf.TrimRight();
		buf.TrimLeft();
		m_player.m_on_block = false;
		if(buf == "1") m_player.m_on_block = true;

		buf = str.Mid(545,1);
		m_player.m_content = atoi(buf);
		if(m_player.m_content == 0) m_player.m_content = 5;


		buf = str.Mid(546,3);
		m_player.m_health = atoi(buf);
		if(m_player.m_health == 0) m_player.m_health = 100;


		buf = str.Mid(549,1);
		m_player.m_stop_negotiating = atoi(buf);


		buf = str.Mid(550,2);
		m_player.m_height = atoi(buf);

		buf = str.Mid(552,3);
		m_player.m_weight = atoi(buf);

		if((m_player.m_height == 0 || m_player.m_weight == 0) && m_player.m_name != "") m_player.GenerateRandomHeightWeight(false);

		buf = str.Mid(555,3);
		m_player.m_oldprFga = atoi(buf);

		buf = str.Mid(558,3);
		m_player.m_oldprFgp = atoi(buf);

		buf = str.Mid(561,3);
		m_player.m_oldprFta = atoi(buf);

		buf = str.Mid(564,3);
		m_player.m_oldprFtp = atoi(buf);

		buf = str.Mid(567,3);
		m_player.m_oldprTga = atoi(buf);

		buf = str.Mid(570,3);
		m_player.m_oldprTgp = atoi(buf);

		buf = str.Mid(573,3);
		m_player.m_oldprOrb = atoi(buf);

		buf = str.Mid(576,3);
		m_player.m_oldprDrb = atoi(buf);

		buf = str.Mid(579,3);
		m_player.m_oldprAst = atoi(buf);

		buf = str.Mid(582,3);
		m_player.m_oldprStl = atoi(buf);

		buf = str.Mid(585,3);
		m_player.m_oldprTo = atoi(buf);

		buf = str.Mid(588,3);
		m_player.m_oldprBlk = atoi(buf);


		buf = str.Mid(591,2);
		m_player.m_oldmovoff = atoi(buf);

		buf = str.Mid(593,2);
		m_player.m_oldpenoff = atoi(buf);

		buf = str.Mid(595,2);
		m_player.m_oldpostoff = atoi(buf);

		buf = str.Mid(597,2);
		m_player.m_oldtransoff = atoi(buf);


		buf = str.Mid(599,2);
		m_player.m_oldmovdef = atoi(buf);

		buf = str.Mid(601,2);
		m_player.m_oldpendef = atoi(buf);

		buf = str.Mid(603,2);
		m_player.m_oldpostdef = atoi(buf);

		buf = str.Mid(605,2);
		m_player.m_oldtransdef = atoi(buf);




		yrs = m_player.m_contract_yrs;
		int salary = 0;
		int remaining_salary = 0;
		int y=0;
		for( y=1; y<=m_player.m_contract_yrs; y++)
		{
			int i = m_player.m_contract_salaries[y];			
			salary = salary + i;
			if(y >= m_player.m_current_contract_yr) remaining_salary = remaining_salary + i;
				
		}
		if(y <= 6)
		{
			for(int n=y; n<=6; n++)
			{
				m_player.m_contract_salaries[n] = 0;			
			}
		}
		m_player.m_total_salary = salary;
		m_player.m_remaining_salary = remaining_salary;
		
		if(m_player.m_contract_yrs == m_player.m_current_contract_yr) m_player.m_is_free_agent = true;

		m_player.m_current_yr_salary = m_player.m_contract_salaries[m_player.m_current_contract_yr]; 

		m_player.m_original_number = i;
		m_player.m_original_po_number = i;

		m_player.SetOutside();
		m_player.SetDriving();
		m_player.SetPost();
		m_player.SetTransition();
		m_player.SetOutsideDefense();
		m_player.SetDrivingDefense();
		m_player.SetPostDefense();
		m_player.SetTransitionDefense();
		m_player.SetTrueRatingSimple(2);
		m_player.SetTradeTrueRating(0);
		m_player.SetTradeValue();

		m_player.SetGameInjuryRating(m_player.m_games,
			m_player.m_min, m_player.m_fga - m_player.m_tfga, m_player.m_fta, m_player.m_to, 1, 82);

		m_player.m_temp_pointer = i;
		m_player.SetLastName(m_player.GetName());	

		if(m_player.m_yrs_on_team >= 3) m_player.m_bird_player = true;		
		if(m_player.m_height == 0) m_player.m_height = 78;
		if(m_player.m_weight == 0) m_player.m_weight = 200;
		if(m_player.m_min == 0) m_player.m_min = 1;
		if(m_player.m_name == "")
		{
			m_player.m_clutch = 2;
			m_player.m_consistency = 2;
		}

		if(
			m_player.m_coach_factor > 5 || m_player.m_coach_factor < 1
			|| 
			m_player.m_pot1 > 5 || m_player.m_pot1 < 1
			|| 
			m_player.m_pot2 > 5 || m_player.m_pot2 < 1
			|| 
			m_player.m_effort > 5 || m_player.m_effort < 1
			|| 
			m_player.m_coach_factor > 5 || m_player.m_coach_factor < 1
			|| 
			m_player.m_security_factor > 5 || m_player.m_security_factor < 1
			|| 
			m_player.m_loyalty_factor > 5 || m_player.m_loyalty_factor < 1
			|| 
			m_player.m_winning_factor > 5 || m_player.m_winning_factor < 1
			|| 
			m_player.m_playing_time_factor > 5 || m_player.m_playing_time_factor < 1
			|| 
			m_player.m_tradition_factor > 5 || m_player.m_tradition_factor < 1
			)
			{
				m_player.GenerateRandomOffCourtData();
				m_player.m_yrs_on_team = 1;
				m_player.m_yrs_of_service = 1;
			}

		if (m_player.m_games > 16 && m_player.m_min > 240)
		{
			avg.m_actual[i] = m_player;
		}
		if (i >= 1440 && i <= 1504)
		{
			avg.m_actual[i] = m_player;
		}


	}
	
	file.Close();

	if(exist == true) DeleteFile(dumb_file_name);
}

void CDisk::TranslateCsvContractFile(CString file_name)
{
	CStdioFile file(file_name, CFile::modeRead);
	CString string;
	for(int i=0; i<=580; i++)
	{

    CPlayer m_player = avg.m_actual[i];
	int yrs = 0;
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
		if(i == 0)  continue;
	int len = string.GetLength();

	int offset = 0;
	int index = string.Find(",", offset); 
	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 
	m_player.m_name = str;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	double sal = atof(str) / 10000.;
	m_player.m_contract_salaries[0] = 0;
	m_player.m_contract_salaries[1] = (int)sal;

	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str) / 10000.;
	m_player.m_contract_salaries[2] = (int)sal;
	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str) / 10000.;
	m_player.m_contract_salaries[3] = (int)sal;
	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str) / 10000.;
	m_player.m_contract_salaries[4] = (int)sal;
	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str) / 10000.;
	m_player.m_contract_salaries[5] = (int)sal;
	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str) / 10000.;
	m_player.m_contract_salaries[6] = (int)sal;
	if(sal > 0) yrs = yrs + 1;

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str);
	m_player.m_yrs_of_service = (int)sal + 1;

	offset = index + 1;
	index = string.GetLength(); //last
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	sal = atof(str);
	m_player.m_yrs_on_team = (int)sal;

		for(int j=0; j<=580; j++)
		{
			CPlayer m_current_player = avg.m_actual[j];

			CString s1 = m_player.m_name;
			CString s2 = m_current_player.m_name;
			s1.MakeLower();
			s2.MakeLower();

			if(s1 != "" && s1 == s2)
			{
				m_current_player.m_contract_salaries[1] = m_player.m_contract_salaries[1];
				m_current_player.m_contract_salaries[2] = m_player.m_contract_salaries[2];
				m_current_player.m_contract_salaries[3] = m_player.m_contract_salaries[3];
				m_current_player.m_contract_salaries[4] = m_player.m_contract_salaries[4];
				m_current_player.m_contract_salaries[5] = m_player.m_contract_salaries[5];
				m_current_player.m_contract_salaries[6] = m_player.m_contract_salaries[6];
				m_current_player.m_contract_yrs = yrs;
				m_current_player.m_current_contract_yr = 1;

				m_current_player.m_total_salary = m_current_player.m_contract_salaries[1] + m_player.m_contract_salaries[2] +
				m_current_player.m_contract_salaries[3] + m_player.m_contract_salaries[4] +
				m_current_player.m_contract_salaries[5] + m_player.m_contract_salaries[6];

				m_current_player.m_total_salary = m_current_player.m_remaining_salary;
				m_current_player.m_is_free_agent = 0;

				m_current_player.m_yrs_of_service = m_player.m_yrs_of_service;
				m_current_player.m_yrs_on_team = m_player.m_yrs_on_team;
				
				
				avg.m_actual[j] = m_current_player;
			}

		}
	}

}

void CDisk::WriteGamePlan(CString file_name, CString strings[65])
{

	CString buffer;
	CStdioFile file( file_name, CFile::modeWrite );
	for(int i=0; i<=64; i++)
	{	
		file.WriteString( strings[i] + "\n");			
	}		

	file.Close(); 
}


CBBallSettings CDisk::ReadLeagueFile(CString league_name)
{
	CBBallSettings settings;

	bool need_increase = false;

	if(FileExists(league_name) == true)
	{
		CFile fi( league_name, CFile::modeRead);
		if(fi.GetLength() < 10000) need_increase = true;
		fi.Close();
	}

	if(need_increase == true) IncreaseFileSize(league_name, 48000);


	CFileStatus status;
	if( CFile::GetStatus( league_name, status ) == TRUE) 
	{

		CFile file( league_name, CFile::modeRead);

		//if(file.GetLength() < 10000) IncreaseFileSize(league_name, 48000);
		char s[33];		
		file.Seek(3992, CFile::begin);
		int bytes = file.Read(s, 4);
		s[bytes] = 0;
		settings.m_currentYear = atoi(s);

		file.Seek(3996, CFile::begin);
		bytes = file.Read(s, 2);
		s[bytes] = 0;
		settings.m_checkCareer = atoi(s);

		file.Seek(4000, CFile::begin);	
		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int injury = atoi(s);

		if(injury < 0 || injury > 2) injury = 1;
		settings.m_injury = injury;

		file.Seek(4002, CFile::begin);	
		bytes = file.Read(s, 2);
		s[bytes] = 0;
		settings.m_numberteams = atoi(s);
		
		for(int  i = 0; i < settings.m_numberteams; i++ )
		{
			int offset = 160 + i*72;
			char s[33];	
			CString name;
			file.Seek(offset, CFile::begin);	
			bytes = file.Read(s, 32);
			s[bytes] = 0;
			name = s;
			name.TrimRight();
			settings.m_leagueTeamNames[i] = name;

			bytes = file.Read(s, 8);
			s[bytes] = 0;
			name = s;
			name.TrimRight();
			settings.m_control[i] = name;
						
		}
		for(int i = settings.m_numberteams; i<=32; i++)
		{
			settings.m_leagueTeamNames[i] = "";
		}


		file.Seek(0, CFile::begin);	

		bytes = file.Read(s, 32);
		s[bytes] = 0;
		settings.m_playoffFormat = s;
		settings.m_playoffFormat.TrimRight();
		bytes = file.Read(s, 8);
		s[bytes] = 0;
		settings.m_rd1Format = s;
		settings.m_rd1Format.TrimRight();
		bytes = file.Read(s, 8);
		s[bytes] = 0;
		settings.m_rd2Format = s;
		settings.m_rd2Format.TrimRight();
		bytes = file.Read(s, 8);
		s[bytes] = 0;
		settings.m_rd3Format = s;
		settings.m_rd3Format.TrimRight();
		bytes = file.Read(s, 8);
		s[bytes] = 0;
		settings.m_rd4Format = s;
		settings.m_rd4Format.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_conferenceName1 = s;
		settings.m_conferenceName1.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_conferenceName2 = s;
		settings.m_conferenceName2.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_divisionName1 = s;
		settings.m_divisionName1.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_divisionName2 = s;
		settings.m_divisionName2.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_divisionName3 = s;
		settings.m_divisionName3.TrimRight();
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		settings.m_divisionName4 = s;
		settings.m_divisionName4.TrimRight();

	
	




	file.Seek(10000, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_save_box[i] = atoi(s);
	}
	file.Seek(10100, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_save_pbp[i] = atoi(s);
	}
	file.Seek(10200, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_get_offers[i] = atoi(s);
	}

	file.Seek(10300, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_show_box[i] = atoi(s);
	}

	file.Seek(10400, CFile::begin);
	for(int i=0; i<=32; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_scouts[i] = atoi(s);
	}

	file.Seek(10450, CFile::begin);
	for(int i=0; i<=32; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		settings.m_coaches[i] = atoi(s);
	}




	file.Seek(10500, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_check3pt = atoi(s);
	
	file.Seek(10501, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_check3ft = atoi(s);


	file.Seek(10505, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int n = atoi(s);
		if(n == 0) settings.m_player_gm[i] = "Computer";
		else settings.m_player_gm[i] = "Player";
	}



	file.Seek(10600, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	settings.m_injury_prompt = atoi(s);


	file.Seek(10602, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_ast_gm = atoi(s);


	file.Seek(10604, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_salary_matching = atoi(s);

	file.Seek(10606, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_financial_on = atoi(s);

	file.Seek(10607, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_free_agency_on = atoi(s);

	file.Seek(10608, CFile::begin);
	bytes = file.Read(s, 5);
	s[bytes] = 0;
	int i = atoi(s);                 
	settings.m_cap = 3550 + (double) i;




	file.Seek(10614, CFile::begin);
	bytes = file.Read(s, 3);
	s[bytes] = 0;
	int scoring_factor = atoi(s);
	settings.m_scoring_factor = double(scoring_factor) / 100;
	if(settings.m_scoring_factor == 0) settings.m_scoring_factor = 1.0;

	
	file.Seek(12000, CFile::begin);	
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int trade = atoi(s);
	settings.m_computerTrades = trade;

	file.Seek(12002, CFile::begin);	
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int stage = atoi(s);
	settings.m_current_stage = stage;
	
	file.Seek(12004, CFile::begin);	
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int speed = atoi(s);
	if(speed <= 0) speed = 50;
	settings.m_sim_speed = speed;

	file.Seek(12006, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	int deadline = atoi(s);
	if(deadline == 1)//0 read is true or 1 or deadline on by default
		settings.m_deadline_on = 0;
	else
		settings.m_deadline_on = 1;

	file.Seek(12007, CFile::begin);
	bytes = file.Read(s, 1);
	s[bytes] = 0;
	settings.m_expanding = atoi(s);


	//read season all star winners here!!!
	file.Seek(12008, CFile::begin);
	bytes = file.Read(s, 6);
	s[bytes] = 0;
	settings.m_all_star = atoi(s);

	file.Seek(12014, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	settings.m_all_star_index = atoi(s);

	file.Seek(12016, CFile::begin);
	bytes = file.Read(s, 6);
	s[bytes] = 0;
	settings.m_rookie_star = atoi(s);

	file.Seek(12022, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	settings.m_rookie_star_index = atoi(s);

	file.Seek(12024, CFile::begin);
	bytes = file.Read(s, 6);
	s[bytes] = 0;
	settings.m_3contest = atoi(s);

	file.Seek(12030, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	settings.m_3contest_index = atoi(s);

	file.Seek(12032, CFile::begin);
	bytes = file.Read(s, 6);
	s[bytes] = 0;
	settings.m_dunkcontest = atoi(s);

	file.Seek(12038, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	settings.m_dunkcontest_index = atoi(s);








	file.Close();

	}
	return settings;
}

bool CDisk::ReadStaff(CString staff_file_name, int number_teams)
{

	bool bad_file = false;
	CFile file( staff_file_name, CFile::modeRead);
	int i = 0;
	for(int  n = 0; n <= 299; n++ )
	{
		
		file.Seek(n*1000, CFile::begin );
		CStaff	m_staff; 
		char s[33];
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString nm = CString(s);
	    nm.TrimRight();
		m_staff.m_name = nm;
		if(n==0 && nm == "") bad_file = true;

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_pot1[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_pot2[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_effort[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_scoring[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_shooting[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_rebounding[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_passing[j] = i;
		}

		for(int j=1; j<=5; j++)
		{

			bytes = file.Read(s, 2);
			s[bytes] = 0;
			i = atoi(s);
			m_staff.m_defense[j] = i;
		}
	

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		int i = atoi(s);
		m_staff.m_power = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_power1 = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_power2 = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachPot1 = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachPot2 = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachEffort = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachScoring = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachShooting = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachRebounding = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachPassing = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachDefense = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachO = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachP = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachI = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachF = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachOD = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachPD = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachID = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachFD = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_coachEndurance = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_loyalty = i;


		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		if(i == 0) i = IntRandom(5);
		m_staff.m_personality = i;//used for owner never rewritten when updating staffs



		// start owner random
		file.Seek(n*1000 + 151, CFile::begin );
		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int player_spending = i;//used for owner never rewritten when updating staffs

		//end


		file.Seek(n*1000 + 201, CFile::begin );
		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_id = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_age = i;
		m_staff.m_slot = n+1;

		file.Seek(n*1000 + 208, CFile::begin );
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_points = i;

		file.Seek(n*1000 + 211, CFile::begin );
		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_win = i;

		file.Seek(n*1000 + 216, CFile::begin );
		bytes = file.Read(s, 5);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_loss = i;

		file.Seek(n*1000 + 221, CFile::begin );
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_playoffs = i;

		file.Seek(n*1000 + 224, CFile::begin );
		bytes = file.Read(s, 3);
		s[bytes] = 0;
		i = atoi(s);
		m_staff.m_rings = i;

		if(n < number_teams)
		{
			avg.m_owner[n].m_team_index = n;

			int seek = n*1000+301;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 5);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_rosterValue = i;

			seek = n*1000+306;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_owner_patience = i;

			seek = n*1000+307;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_firingLineScout = i;

			seek = n*1000+310;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_firingLineCoach = i;

			seek = n*1000+313;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 3);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_firingLineGM = i;

			seek = n*1000+316;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 6);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_win = i;

			seek = n*1000+322;
			file.Seek( seek, CFile::begin);
			bytes = file.Read(s, 6);
			s[bytes] = 0;
			i = atoi(s);
			avg.m_owner[n].m_loss = i;

			avg.m_owner[n].m_player_spending = player_spending;



		}

		m_staff.SetRatings();
		if(n<=99)
			avg.m_gm[n] = m_staff;	
		else if(n>=100 && n<=199)
			avg.m_scout[n-100] = m_staff;
		else
			avg.m_coach[n-200] = m_staff;
	}

	for(int i=0; i<number_teams; i++)
	{
		avg.m_scout[i].m_team = avg.m_settings.m_leagueTeamNames[i];
		avg.m_coach[i].m_team = avg.m_settings.m_leagueTeamNames[i];
		avg.m_gm[i].m_team = avg.m_settings.m_leagueTeamNames[i];
	}



	file.Close();


	if(avg.m_settings.m_scouts[32] == 1)
	{
		CStaff	m_staff; 
		for(int i=0; i<=99; i++)
		{
			avg.m_scout[i] = m_staff;
			//avg.m_coach[i] = m_staff;
			avg.m_gm[i] = m_staff;
		}
	}
		
	if(avg.m_settings.m_coaches[32] == 1)
	{
		CStaff	m_staff; 
		for(int i=0; i<=99; i++)
		{
			//avg.m_scout[i] = m_staff;
			avg.m_coach[i] = m_staff;
			//avg.m_gm[i] = m_staff;
		}
	}
		


	return bad_file;


}



void CDisk::ReadStandingsFile(CString file_name, CBBallSettings settings, CBBallSchedule sched, CRecord* record)
{
		



		CFile file( file_name, CFile::modeRead ); 
		
		file.Seek(160, CFile::begin);	
	
		for(int i = 0; i < settings.m_numberteams; i++ )
		{
			char s[33];
			CString name;
			int bytes = file.Read(s, 32);
			s[bytes] = 0;
			name = CString(s);
			name.TrimRight();
			record[i].m_leagueTeamNames = name;
			bytes = file.Read(s, 8);
			s[bytes] = 0;
			name = CString(s);
			name.TrimRight();
			record[i].m_control = name;
			bytes = file.Read(s, 16);
			s[bytes] = 0;
			name = CString(s);
			name.TrimRight();
			record[i].m_conference = name;
			bytes = file.Read(s, 16);
			s[bytes] = 0;
			name = CString(s);
			name.TrimRight();
			record[i].m_division = name;
			record[i].m_initialNumber = i;
		}

		

	SetStandings(sched, record);
		
}


void CDisk::SetStandings(CBBallSchedule sched, CRecord *record)
{

for(int x=0; x<=31; x++)
{
	for(int y=1; y<=32; y++)
	{
		record[x].m_vsOpponent[y] = 0; //set vs. opponent to 0
	}
}

//calculate different records for all teams
for(int t=0; t<=31; t++)
{
	record[t].m_leagueRecord = 0;
	record[t].m_visitorRecord = 0;
	record[t].m_homeRecord = 0;
	record[t].m_divisionRecord = 0;
	record[t].m_conferenceRecord = 0;
	for(int i=0; i<=11; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
				int v;
				int h;
				int vs; 
				int hs;
				int game = 0;
				int score = 0;
				v = sched.m_schedule[i][j][k] / 100;
				h = sched.m_schedule[i][j][k] - v * 100;	
				vs = sched.m_game_score[i][j][k] / 1000;
				hs = sched.m_game_score[i][j][k] - vs * 1000;	
				if(v >= 1 && h >= 1 && v == t + 1)
				{	
					if(vs < hs) 
					{	
						record[t].m_vsOpponent[h] = record[t].m_vsOpponent[h] + 1;
						record[t].m_leagueRecord = record[t].m_leagueRecord + 1;
						record[t].m_visitorRecord = record[t].m_visitorRecord + 1;
						if(record[v-1].m_conference == record[h-1].m_conference)
							record[t].m_conferenceRecord = record[t].m_conferenceRecord + 1;
						if(record[v-1].m_division == record[h-1].m_division)
							record[t].m_divisionRecord = record[t].m_divisionRecord + 1;
					}
					else if(vs > hs)
					{
						record[t].m_vsOpponent[h] = record[t].m_vsOpponent[h] + 100;
						record[t].m_leagueRecord = record[t].m_leagueRecord + 100;
						record[t].m_visitorRecord = record[t].m_visitorRecord + 100;
						if(record[v-1].m_conference == record[h-1].m_conference)
							record[t].m_conferenceRecord = record[t].m_conferenceRecord + 100;
						if(record[v-1].m_division == record[h-1].m_division)
							record[t].m_divisionRecord = record[t].m_divisionRecord + 100;
					}
				}
				if(v >= 1 && h >= 1 && h == t + 1)
				{
					if(vs < hs) 
					{
						record[t].m_vsOpponent[v] = record[t].m_vsOpponent[v] + 100;
						record[t].m_leagueRecord = record[t].m_leagueRecord + 100;
						record[t].m_homeRecord = record[t].m_homeRecord + 100;
						if(record[v-1].m_conference == record[h-1].m_conference)
							record[t].m_conferenceRecord = record[t].m_conferenceRecord + 100;
						if(record[v-1].m_division == record[h-1].m_division)
							record[t].m_divisionRecord = record[t].m_divisionRecord + 100;
					}
					else if(vs > hs)
					{
						record[t].m_vsOpponent[v] = record[t].m_vsOpponent[v] + 1;
						record[t].m_leagueRecord = record[t].m_leagueRecord + 1;
						record[t].m_homeRecord = record[t].m_homeRecord + 1;
						if(record[v-1].m_conference == record[h-1].m_conference)
							record[t].m_conferenceRecord = record[t].m_conferenceRecord + 1;
						if(record[v-1].m_division == record[h-1].m_division)
							record[t].m_divisionRecord = record[t].m_divisionRecord + 1;
					}
				}
			}
		}
	}		
}

	for(int t = 0; t <= 31; t++)
	{
			int w = record[t].m_leagueRecord / 100;
			int l = record[t].m_leagueRecord - w * 100;
			record[t].m_win = w;
			record[t].m_loss = l;
			int games = w + l;
			if(games == 0) games = 1;
			double pct = double(w) / double(games);
			record[t].m_leaguePct = pct;
			record[t].m_leagueGamesBack = w - l;

			w = record[t].m_divisionRecord / 100;
			l = record[t].m_divisionRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			record[t].m_divisionPct = pct;
			w = record[t].m_conferenceRecord / 100;
			l = record[t].m_conferenceRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			record[t].m_conferencePct = pct;
			for(int x = 0; x <= 31; x++)
			{
				int w = record[t].m_vsOpponent[x] / 100;
				int l = record[t].m_vsOpponent[x] - w * 100;
				int games = w + l;
				if(games == 0) games = 1;
				double pct = double(w) / double(games);
				record[t].m_vsOpponentPct[x] = pct;
			}



	}



}




void CDisk::WritePlayoffResults(CString pFileName, int m_currentMonth, int m_currentDay, int m_currentGame,
				int m_team1, int score1, int m_win1, int m_team2, int score2, int m_win2)
{
	
		if(score1 > score2) m_win1 = m_win1 + 1; else m_win2 = m_win2 + 1;
		CFile file(	pFileName, CFile::modeWrite	);
		int seek = 72046 + m_currentDay * 96 + m_currentGame * 12 ;
		file.Seek(seek, CFile::begin );
		
		CString buffer;
		buffer.Format("%d", m_team1);
		file.Write( buffer, 2);

		buffer.Format("%d", score1);
		file.Write( buffer, 3);

		buffer.Format("%d", m_win1);
		file.Write( buffer, 1);

		buffer.Format("%d", m_team2);
		file.Write( buffer, 2);

		buffer.Format("%d", score2);
		file.Write( buffer, 3);

		buffer.Format("%d", m_win2);
		file.Write( buffer, 1);
}




void CDisk::CreateCleanLeagueFiles(CString file_name)
{
	CString recordbook_file = file_name + ".rcb";
	CString new_data_file_name = file_name + ".plr";
	CString plan_file_name = file_name + ".plb";
	CString season_box_file_name = file_name + ".sco";
	CString con_file_name = file_name + ".sal";
	CString bud_name = file_name + ".bud";
	CString budget_file = file_name + ".dub";
	CString own_name = file_name + ".own";//write own file
	CString frn_file_name = file_name + ".frn";
	CString finance_file = file_name + ".arf";
	CString lge_file = file_name + ".lge";
	
	CreateBlankFile(file_name + ".lge", 64000);
	CreateBlankFile(file_name + ".sch", 80000);
	CreateBlankFile(file_name + ".trn", 64000);
	CreateBlankFile(file_name + ".all", 66000);
	CreateBlankFile(file_name + ".log", 200000);
	CreateBlankFile(file_name + ".bxs", 10000);
	CreateBlankFile(file_name + ".fut", 100000);
	CreateBlankFile(file_name + ".dub", 110000);
	CreateBlankFile(file_name + ".arf", 110000);
	CreateBlankFile(file_name + ".awa", 32000);
	CreateBlankFile(file_name + ".sta", 100000);

	CreateBlankFile(con_file_name, 500000);	
	CreateBlankFile(plan_file_name, 160000);
	CreateHugeBlankFile(season_box_file_name, 16);
	CreateBlankFile(frn_file_name, 110000);
	CreateBlankFile(bud_name, 110000);
	CreateBlankFile(budget_file, 110000);
	CreateBlankFile(finance_file, 110000);

	bool rcb_exists = FileExists(recordbook_file);
	CreateBlankFile(recordbook_file, 500000);
	if(rcb_exists == false) WriteRecordBookFile(recordbook_file);//empty rcb file needed filled
	if(FileExists(own_name) == 0)
	{
		CreateBlankFile(own_name, 64000);
		avg.m_own[0].WriteOwnData(own_name);//write draft chart etc
	}


}

void CDisk::WriteLeagueFile(CString league_name, CBBallSettings settings)
{
	CString buffer;
	CFile fil( league_name + ".lge", CFile::modeWrite);



		fil.Seek(0, CFile::begin);	

		buffer = settings.m_playoffFormat;
		buffer = buffer + "                               ";
		fil.Write( buffer, 32);					

		buffer = settings.m_rd1Format;
		buffer = buffer + "                               ";
		fil.Write( buffer, 8);					

		buffer = settings.m_rd2Format;
		buffer = buffer + "                               ";
		fil.Write( buffer, 8);					

		buffer = settings.m_rd3Format;
		buffer = buffer + "                               ";
		fil.Write( buffer, 8);					

		buffer = settings.m_rd4Format;
		buffer = buffer + "                               ";
		fil.Write( buffer, 8);					

		buffer = settings.m_conferenceName1;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					

		buffer = settings.m_conferenceName2;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					

		buffer = settings.m_divisionName1;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					

		buffer = settings.m_divisionName2;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					

		buffer = settings.m_divisionName3;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					

		buffer = settings.m_divisionName4;
		buffer = buffer + "                               ";
		fil.Write( buffer, 16);					




	for(int  i = 0; i <= 31; i++ )
	{
		int offset = 160 + i*72;
		fil.Seek(offset, CFile::begin);
		buffer = settings.m_leagueTeamNames[i] + "                                ";
		fil.Write( buffer, 32);					
		buffer = settings.m_control[i] + "         ";
		fil.Write( buffer, 8);		
		buffer = avg.m_standings[i].m_conference + "                 ";
		if(buffer != "") fil.Write( buffer, 16);//dont write if this was not passed to function					
		buffer = avg.m_standings[i].m_division + "                ";
		if(buffer != "") fil.Write( buffer, 16);//dont write if this was not passed to function					
	}



	fil.Seek(10000, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		if(settings.m_save_box[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10100, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		if(settings.m_save_pbp[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10200, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		if(settings.m_get_offers[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10300, CFile::begin);
	for(int i=0; i<=31; i++)
	{
		if(settings.m_show_box[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10400, CFile::begin);
	for(int i=0; i<=32; i++)
	{
		if(settings.m_scouts[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10450, CFile::begin);
	for(int i=0; i<=32; i++)
	{
		if(settings.m_coaches[i] == 0) buffer = "0";
		else buffer = "1";
		fil.Write( buffer, 1);
	}

	fil.Seek(10500, CFile::begin);
	if(settings.m_check3pt == 0) buffer = "0";
	else buffer = "1";
	fil.Write( buffer, 1);

	fil.Seek(10501, CFile::begin);
	if(settings.m_check3ft == 0) buffer = "0";
	else buffer = "1";
	fil.Write( buffer, 1);


	fil.Seek(10505, CFile::begin);
	for(int i=0; i<=32; i++)
	{
		if(settings.m_player_gm[i] == "" || settings.m_player_gm[i] != "Player")
			buffer = "0"; else buffer = "1";
		fil.Write( buffer, 1);
	}


	fil.Seek(10600, CFile::begin);
	buffer.Format("%d", settings.m_injury_prompt);
	buffer = buffer + "  ";
	fil.Write( buffer, 2);

	int ast_gm = 0;
	if(settings.m_ast_gm == 0) ast_gm = 0;
	else ast_gm = 1;
	fil.Seek(10602, CFile::begin);
	buffer.Format("%d", ast_gm);
	buffer = buffer + "  ";
	fil.Write( buffer, 2);

	int finance = 0;
	if(settings.m_salary_matching == 0) finance = 0;
	else finance = 1;
	fil.Seek(10604, CFile::begin);
	buffer.Format("%d", finance);
	buffer = buffer + "  ";
	fil.Write( buffer, 2);


	int finances_on = 0;
	if(settings.m_financial_on == 0) finances_on = 0;
	else finances_on = 1;
	fil.Seek(10606, CFile::begin);
	buffer.Format("%d", finances_on);
	buffer = buffer + "  ";
	fil.Write( buffer, 1);

	int free_agency_on = 0;
	if(settings.m_free_agency_on == 0) free_agency_on = 0;
	else free_agency_on = 1;
	fil.Seek(10607, CFile::begin);
	buffer.Format("%d", free_agency_on);
	buffer = buffer + "  ";
	fil.Write( buffer, 1);

	double d_cap = settings.m_cap;
	int i_cap = (int)d_cap - 3550;
	fil.Seek(10608, CFile::begin);
	buffer.Format("%d", i_cap);
	buffer = buffer + "  ";
	fil.Write( buffer, 5);





	fil.Seek(10614, CFile::begin);
	int i_scoring = (int)settings.m_scoring_factor * 100;
	buffer.Format("%d", i_scoring);
	buffer = buffer + "  ";
	fil.Write( buffer, 3);



	fil.Seek(12000, CFile::begin);
	if(settings.m_computerTrades == 0) buffer = "0";
	else buffer = "1";
	fil.Write(buffer, 2);

	fil.Seek(12002, CFile::begin);
	int stage = (int)settings.m_current_stage;
	//stage = 3;
	buffer.Format("%d", stage);
	buffer = buffer + "   ";
	fil.Write(buffer, 2);

	fil.Seek(12004, CFile::begin);
	int speed = (int)settings.m_sim_speed;
	buffer.Format("%d", stage);
	buffer = buffer + "   ";
	fil.Write(buffer, 2);


	int deadline_on = 0;
	if(settings.m_deadline_on == 0) deadline_on = 1;
	else deadline_on = 0;
	fil.Seek(12006, CFile::begin);
	buffer.Format("%d", deadline_on);
	buffer = buffer + "  ";
	fil.Write( buffer, 1);

	fil.Seek(12007, CFile::begin);
	buffer.Format("%d", settings.m_expanding);
	buffer = buffer + "  ";
	fil.Write( buffer, 1);

	//write season asw winners
	fil.Seek(12008, CFile::begin);
	buffer.Format("%d", settings.m_all_star);
	buffer = buffer + "       ";
	fil.Write( buffer, 6);
	fil.Seek(12014, CFile::begin);
	buffer.Format("%d", settings.m_all_star_index);
	buffer = buffer + "       ";
	fil.Write( buffer, 2);

	fil.Seek(12016, CFile::begin);
	buffer.Format("%d", settings.m_rookie_star);
	buffer = buffer + "       ";
	fil.Write( buffer, 6);
	fil.Seek(12022, CFile::begin);
	buffer.Format("%d", settings.m_rookie_star_index);
	buffer = buffer + "       ";
	fil.Write( buffer, 2);

	fil.Seek(12024, CFile::begin);
	buffer.Format("%d", settings.m_3contest);
	buffer = buffer + "       ";
	fil.Write( buffer, 6);
	fil.Seek(12030, CFile::begin);
	buffer.Format("%d", settings.m_3contest_index);
	buffer = buffer + "       ";
	fil.Write( buffer, 2);

	fil.Seek(12032, CFile::begin);
	buffer.Format("%d", settings.m_dunkcontest);
	buffer = buffer + "       ";
	fil.Write( buffer, 6);
	fil.Seek(12038, CFile::begin);
	buffer.Format("%d", settings.m_dunkcontest_index);
	buffer = buffer + "       ";
	fil.Write( buffer, 2);












	fil.Seek(3992, CFile::begin);
	int year = (int)settings.m_currentYear;
	buffer.Format("%d", year);
	buffer = buffer + "   ";
	fil.Write(buffer, 4);

	fil.Seek(3996, CFile::begin);
	int car = (int)settings.m_checkCareer;
	buffer.Format("%d", car);
	buffer = buffer + "   ";
	fil.Write(buffer, 2);

	fil.Seek(4000, CFile::begin);
	int inj = (int)settings.m_injury;
	buffer.Format("%d", inj);
	buffer = buffer + "   ";
	fil.Write(buffer, 2);

	fil.Seek(4002, CFile::begin);
	int num = (int)settings.m_numberteams;
	buffer.Format("%d", num);
	buffer = buffer + "   ";
	fil.Write(buffer, 2);

	fil.Close();

}

void CDisk::WriteRecordBookFile(CString file_name)
{
	const int slots = 80*33;
	CString buffer[81+slots+1];
	CStdioFile file( file_name, CFile::modeWrite );
	int player = 0;
	int index = 0;
	for(int p=1; p<=50; p++)//lines each line is 1 place for each team + overall league
	{

		int index = 0;

		for(int t=0; t<=32; t++)//team
		{

		CString Name = m_high.m_ppg_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double ppg = m_high.m_ppg[t][p]*100;
		int i_ppg = (int)ppg;

		buffer[index+1].Format("%6d", m_high.m_ppg_id[t][p]);
		buffer[index+2].Format("%6d", i_ppg);
		buffer[index+3].Format("%2d", m_high.m_ppg_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_ppg_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_ppg_name[t][p];
		buffer[index].Format("%32s", Name);	

		ppg = m_high.m_car_ppg[t][p]*100;
		i_ppg = (int)ppg;

		buffer[index+1].Format("%6d", m_high.m_car_ppg_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_pts[t][p]);
		buffer[index+3].Format("%6d", i_ppg);
		buffer[index+4].Format("%2d", m_high.m_car_ppg_te[t][p]);

		index = index + 5;


	
		Name = m_high.m_rpg_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double rpg = m_high.m_rpg[t][p]*100;
		int i_rpg = (int)rpg;

		buffer[index+1].Format("%6d", m_high.m_rpg_id[t][p]);
		buffer[index+2].Format("%6d", i_rpg);
		buffer[index+3].Format("%2d", m_high.m_rpg_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_rpg_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_rpg_name[t][p];
		buffer[index].Format("%32s", Name);	

		rpg = m_high.m_car_rpg[t][p]*100;
		i_rpg = (int)rpg;

		buffer[index+1].Format("%6d", m_high.m_car_rpg_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_reb[t][p]);
		buffer[index+3].Format("%6d", i_rpg);
		buffer[index+4].Format("%2d", m_high.m_car_rpg_te[t][p]);

		index = index + 5;

		

		Name = m_high.m_apg_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double apg = m_high.m_apg[t][p]*100;
		int i_apg = (int)apg;

		buffer[index+1].Format("%6d", m_high.m_apg_id[t][p]);
		buffer[index+2].Format("%6d", i_apg);
		buffer[index+3].Format("%2d", m_high.m_apg_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_apg_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_apg_name[t][p];
		buffer[index].Format("%32s", Name);	

		apg = m_high.m_car_apg[t][p]*100;
		i_apg = (int)apg;

		buffer[index+1].Format("%6d", m_high.m_car_apg_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_ast[t][p]);
		buffer[index+3].Format("%6d", i_apg);
		buffer[index+4].Format("%2d", m_high.m_car_apg_te[t][p]);

		index = index + 5;

		

		Name = m_high.m_spg_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double spg = m_high.m_spg[t][p]*100;
		int i_spg = (int)spg;

		buffer[index+1].Format("%6d", m_high.m_spg_id[t][p]);
		buffer[index+2].Format("%6d", i_spg);
		buffer[index+3].Format("%2d", m_high.m_spg_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_spg_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_spg_name[t][p];
		buffer[index].Format("%32s", Name);	

		spg = m_high.m_car_spg[t][p]*100;
		i_spg = (int)spg;

		buffer[index+1].Format("%6d", m_high.m_car_spg_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_stl[t][p]);
		buffer[index+3].Format("%6d", i_spg);
		buffer[index+4].Format("%2d", m_high.m_car_spg_te[t][p]);

		index = index + 5;

		

		Name = m_high.m_bpg_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double bpg = m_high.m_bpg[t][p]*100;
		int i_bpg = (int)bpg;

		buffer[index+1].Format("%6d", m_high.m_bpg_id[t][p]);
		buffer[index+2].Format("%6d", i_bpg);
		buffer[index+3].Format("%2d", m_high.m_bpg_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_bpg_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_bpg_name[t][p];
		buffer[index].Format("%32s", Name);	

		bpg = m_high.m_car_bpg[t][p]*100;
		i_bpg = (int)bpg;

		buffer[index+1].Format("%6d", m_high.m_car_bpg_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_blk[t][p]);
		buffer[index+3].Format("%6d", i_bpg);
		buffer[index+4].Format("%2d", m_high.m_car_bpg_te[t][p]);

		index = index + 5;

		

		Name = m_high.m_fgp_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double fgp = m_high.m_fgp[t][p]*100;
		int i_fgp = (int)fgp;

		buffer[index+1].Format("%6d", m_high.m_fgp_id[t][p]);
		buffer[index+2].Format("%6d", i_fgp);
		buffer[index+3].Format("%2d", m_high.m_fgp_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_fgp_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_fgp_name[t][p];
		buffer[index].Format("%32s", Name);	

		fgp = m_high.m_car_fgp[t][p]*100;
		i_fgp = (int)fgp;

		buffer[index+1].Format("%6d", m_high.m_car_fgp_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_fgm[t][p]);
		buffer[index+3].Format("%6d", i_fgp);
		buffer[index+4].Format("%2d", m_high.m_car_fgp_te[t][p]);

		index = index + 5;

		

		Name = m_high.m_ftp_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double ftp = m_high.m_ftp[t][p]*100;
		int i_ftp = (int)ftp;

		buffer[index+1].Format("%6d", m_high.m_ftp_id[t][p]);
		buffer[index+2].Format("%6d", i_ftp);
		buffer[index+3].Format("%2d", m_high.m_ftp_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_ftp_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_ftp_name[t][p];
		buffer[index].Format("%32s", Name);	

		ftp = m_high.m_car_ftp[t][p]*100;
		i_ftp = (int)ftp;

		buffer[index+1].Format("%6d", m_high.m_car_ftp_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_ftm[t][p]);
		buffer[index+3].Format("%6d", i_ftp);
		buffer[index+4].Format("%2d", m_high.m_car_ftp_te[t][p]);

		index = index + 5;


		

		Name = m_high.m_tgp_name[t][p];                                         
		buffer[index].Format("%32s", Name);	
		
		double tgp = m_high.m_tgp[t][p]*100;
		int i_tgp = (int)tgp;

		buffer[index+1].Format("%6d", m_high.m_tgp_id[t][p]);
		buffer[index+2].Format("%6d", i_tgp);
		buffer[index+3].Format("%2d", m_high.m_tgp_te[t][p]);
		buffer[index+4].Format("%4d", m_high.m_tgp_ye[t][p]);

		index = index + 5;
	
		Name = m_high.m_car_tgp_name[t][p];
		buffer[index].Format("%32s", Name);	

		tgp = m_high.m_car_tgp[t][p]*100;
		i_tgp = (int)tgp;

		buffer[index+1].Format("%6d", m_high.m_car_tgp_id[t][p]);
		buffer[index+2].Format("%6d", m_high.m_car_tgm[t][p]);
		buffer[index+3].Format("%6d", i_tgp);
		buffer[index+4].Format("%2d", m_high.m_car_tgp_te[t][p]);

		index = index + 5;

		

		}


		CString write_string;
		for(int y=0; y<=slots; y++)
		{
			write_string = write_string + buffer[y];
		}
	
		file.WriteString( write_string + "\n");		

		
	}		




	for(int t=0; t<=32; t++)
	{
		CString write_string;
		index = 0;

		for(int i=0; i<=1; i++)
		{
		for(int j=0; j<=9; j++)
		{
		for(int k=0; k<=7; k++)
		{

		CString Name = m_high.m_g_name[i][t][j][k];                                         
		buffer[index].Format("%32s", Name);	
		buffer[index+1].Format("%6d", m_high.m_g_id[i][t][j][k]);
		buffer[index+2].Format("%3d", m_high.m_g_amt[i][t][j][k]);
		buffer[index+3].Format("%4d", m_high.m_g_ye[i][t][j][k]);


		Name = m_high.m_g_po_name[i][t][j][k];                                         
		buffer[index+4].Format("%32s", Name);	
		buffer[index+5].Format("%6d", m_high.m_g_po_id[i][t][j][k]);
		buffer[index+6].Format("%3d", m_high.m_g_po_amt[i][t][j][k]);
		buffer[index+7].Format("%4d", m_high.m_g_po_ye[i][t][j][k]);


		index = index + 8;
	
	
		








		}
		}
		}

		for(int y=0; y<=1280; y++)
		{
			write_string = write_string + buffer[y];
		}
	


		file.WriteString( write_string + "\n");		


	}




	file.Close(); 

}

void CDisk::ReadRecordBookFile(CString file_name)
{
	CStdioFile file(file_name, CFile::modeRead);
	CString str;
	int player = 0;
	for(int p = 1; p<=50; p++)//place / rank will go to 50
	{

		
		file.ReadString(str);
		//str.TrimRight();
		
		int co = 0;
		for(int t=0; t<=32; t++)
		{

		CString buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_ppg_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_ppg_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int pt = atoi(buf);
		m_high.m_ppg[t][p] = (double)pt/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_ppg_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_ppg_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_ppg_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_ppg_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_pts[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_ppg = atoi(buf);

		m_high.m_car_ppg[t][p] = (double)i_ppg/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_ppg_te[t][p] = atoi(buf);

		co = co + 102;




		
		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_rpg_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_rpg_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int rb = atoi(buf);
		m_high.m_rpg[t][p] = (double)rb /100;
		
		buf = str.Mid(co+44,2);
		m_high.m_rpg_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_rpg_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_rpg_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_rpg_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_reb[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_rpg = atoi(buf);

		m_high.m_car_rpg[t][p] = (double)i_rpg/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_rpg_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;





		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_apg_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_apg_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int as = atoi(buf);
		m_high.m_apg[t][p] = (double)as /100;
		
		buf = str.Mid(co+44,2);
		m_high.m_apg_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_apg_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_apg_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_apg_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_ast[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_apg = atoi(buf);

		m_high.m_car_apg[t][p] = (double)i_apg/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_apg_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;




		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_spg_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_spg_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int st = atoi(buf);
		m_high.m_spg[t][p] = (double)st/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_spg_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_spg_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_spg_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_spg_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_stl[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_spg = atoi(buf);

		m_high.m_car_spg[t][p] = (double)i_spg/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_spg_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;



		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_bpg_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_bpg_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int bl = atoi(buf);
		m_high.m_bpg[t][p] = (double)bl/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_bpg_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_bpg_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_bpg_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_bpg_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_blk[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_bpg = atoi(buf);

		m_high.m_car_bpg[t][p] = (double)i_bpg/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_bpg_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;




		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_fgp_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_fgp_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int fg = atoi(buf);
		m_high.m_fgp[t][p] = (double)fg/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_fgp_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_fgp_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_fgp_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_fgp_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_fgm[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_fgp = atoi(buf);

		m_high.m_car_fgp[t][p] = (double)i_fgp/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_fgp_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;


		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_ftp_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_ftp_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int ft = atoi(buf);
		m_high.m_ftp[t][p] = (double)ft/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_ftp_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_ftp_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_ftp_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_ftp_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_ftm[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_ftp = atoi(buf);

		m_high.m_car_ftp[t][p] = (double)i_ftp/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_ftp_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;


		buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_tgp_name[t][p] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_tgp_id[t][p] = atoi(buf);

		buf = str.Mid(co+38,6);
		int tg = atoi(buf);
		m_high.m_tgp[t][p] = (double)tg/100;
		
		buf = str.Mid(co+44,2);
		m_high.m_tgp_te[t][p] = atoi(buf);
		
		buf = str.Mid(co+46,4);
		m_high.m_tgp_ye[t][p] = atoi(buf);


		buf = str.Mid(co+50,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_car_tgp_name[t][p] = buf;

		buf = str.Mid(co+82,6);
		m_high.m_car_tgp_id[t][p] = atoi(buf);

		buf = str.Mid(co+88,6);
		m_high.m_car_tgm[t][p] = atoi(buf);
		
		buf = str.Mid(co+94,6);
		int i_tgp = atoi(buf);

		m_high.m_car_tgp[t][p] = (double)i_tgp/100;
		
		buf = str.Mid(co+100,2);
		m_high.m_car_tgp_te[t][p] = atoi(buf);


		
		//m_high = m_hi;
		co = co + 102;







		}
	}


	for(int t=0; t<=32; t++)
	{
		file.ReadString(str);
		int co=0;

		for(int i=0; i<=1; i++)
		{
		for(int j=0; j<=9; j++)
		{
		for(int k=0; k<=7; k++)
		{


		CString buf = str.Mid(co,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_g_name[i][t][j][k] = buf;

		buf = str.Mid(co+32,6);
		m_high.m_g_id[i][t][j][k] = atoi(buf);

		buf = str.Mid(co+38,3);
		m_high.m_g_amt[i][t][j][k] = atoi(buf);

		buf = str.Mid(co+41,4);
		m_high.m_g_ye[i][t][j][k] = atoi(buf);

		buf = str.Mid(co+45,32);
		buf.TrimRight();
		buf.TrimLeft();
		m_high.m_g_po_name[i][t][j][k] = buf;

		buf = str.Mid(co+77,6);
		m_high.m_g_po_id[i][t][j][k] = atoi(buf);

		buf = str.Mid(co+83,3);
		m_high.m_g_po_amt[i][t][j][k] = atoi(buf);

		buf = str.Mid(co+86,4);
		m_high.m_g_po_ye[i][t][j][k] = atoi(buf);

		co=co+90;

		}
		}
		}

	}

	
	file.Close();
}

void CDisk::ReadTransactionsFile(CString file_name)
{
	CString string;
	char s[129];
	CFile file(	file_name, CFile::modeRead);
	
	int bytes = file.Read(s, 16);
	s[bytes] = 0;

	int n = atoi(s);
	avg.m_settings.m_number_transactions = n;
    int t1 = 0, t2 = 0;

	for(int i=1; i<=n; i++)
	{
		int seek = (i-1)*128+17;
		file.Seek( seek, CFile::begin );
		int bytes = file.Read(s, 128);
		s[bytes] = 0;
		string = CString(s);
		avg.m_trans_str[i] = string + "                                                                                                                                ";
	}
    
	file.Close();		
}

void CDisk::SaveTransactionsFile(CString file_name)
{

	CFile f(file_name, CFile::modeWrite);
	CString buffer;
	buffer.Format("%d", avg.m_settings.m_number_transactions);
	buffer = buffer + "                 ";
	f.Write( buffer, 16);		
	for(int i=1; i<=avg.m_settings.m_number_transactions; i++)
	{
		int seek = (i-1)*128+17;
		f.Seek( seek, CFile::begin );
		avg.m_trans_str[i] = avg.m_trans_str[i] + "                                                                                                                       ";                      
		f.Write(avg.m_trans_str[i], 128);
	}
	f.Close();
}


void CDisk::WriteCareerStaff(CString pFileName, CStaff *m_scout, CStaff *m_coach, CStaff *m_gm, CHireStaff *m_owner, int scouts, int coaches)
{

	CFile file( pFileName, CFile::modeWrite);
	CString s;
	for(int  n = 0; n <= 299; n++ )
	{
		
		file.Seek(n*1000, CFile::begin );
		if(scouts == 1 && coaches == 1) continue;//dont write
		if(scouts == 1 && coaches == 0 && n<=199) continue;//only write coaches
		CStaff	m_staff; 

        if(n <= 99) m_staff = m_gm[n];
		else if(n <= 199) m_staff = m_scout[n - 100];
		else m_staff = m_coach[n - 200];

		CString buffer = m_staff.m_name;
		buffer.TrimRight();
		buffer = buffer + "               ";
		file.Write(buffer, 16);

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_pot1[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);
		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_pot2[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);

		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_effort[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);
		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_scoring[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);

		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_shooting[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);

		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_rebounding[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);
		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_passing[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);

		}

		for(int j=1; j<=5; j++)
		{
			buffer.Format("%d", m_staff.m_defense[j]);
			buffer = buffer + "               ";
			file.Write(buffer, 2);
		}

		buffer.Format("%d", m_staff.m_power);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_power1);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_power2);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachPot1);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachPot2);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachEffort);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachScoring);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachShooting);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachRebounding);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachPassing);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachDefense);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachO);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachP);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachI);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachF);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachOD);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachPD);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachID);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachFD);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_coachEndurance);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_loyalty);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		buffer.Format("%d", m_staff.m_personality);
		buffer = buffer + "               ";
		file.Write(buffer, 2);

		file.Seek(n*1000 + 201, CFile::begin );
		buffer.Format("%d", m_staff.m_id);
		buffer = buffer + "               ";
		file.Write(buffer, 5);

		buffer.Format("%d", m_staff.m_age);
		buffer = buffer + "               ";
		file.Write(buffer, 2);




	        int seek = n*1000+201;
			file.Seek( seek, CFile::begin);
			int id = m_staff.m_id;
			buffer.Format("%d", id);
			buffer = buffer + "    ";
			file.Write(buffer, 5);//write staff id

	        seek = n*1000+206;
			int age = m_staff.m_age;
			buffer.Format("%d", age);
			buffer = buffer + "    ";
			file.Write(buffer, 2);//write age

			seek = n*1000+208;
			file.Seek( seek, CFile::begin);
			int score = m_staff.m_points;
			buffer.Format("%d", score);
			buffer = buffer + "    ";
			file.Write(buffer, 3);//write current status of member (default is 8)

			seek = n*1000 + 211;
	        buffer.Format("%d", m_staff.m_win);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 5);

			seek = n*1000 + 216;
	        buffer.Format("%d", m_staff.m_loss);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 5);

			seek = n*1000 + 221;
	        buffer.Format("%d", m_staff.m_playoffs);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000 + 224;
	        buffer.Format("%d", m_staff.m_rings);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);


		if(n < avg.m_settings.m_numberteams)
		{

			int seek = n*1000+301;
	        buffer.Format("%d", avg.m_owner[n].m_rosterValue);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+306;
	        buffer.Format("%d", avg.m_owner[n].m_owner_patience);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+307;
	        buffer.Format("%d", avg.m_owner[n].m_firingLineScout);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+310;
	        buffer.Format("%d", avg.m_owner[n].m_firingLineCoach);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+313;
	        buffer.Format("%d", avg.m_owner[n].m_firingLineGM);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+316;
	        buffer.Format("%d", avg.m_owner[n].m_win);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);

			seek = n*1000+322;
	        buffer.Format("%d", avg.m_owner[n].m_loss);
			buffer = buffer + "         ";
		    file.Seek(seek, CFile::begin ); 				
		    file.Write(buffer, 3);


		}

	}

}