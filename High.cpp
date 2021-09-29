#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"


#include "High.h"

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

CHigh::CHigh()
{
	m_team1 = 32;
	m_team2 = 32;
	m_offset = 0;


	for(int i=0; i<=32; i++)
	{
		for(int j=0; j<=50; j++)
		{
				m_ppg_name[i][j] = "";
				m_ppg[i][j] = 0;
				m_ppg_id[i][j] = 0;
				m_ppg_te[i][j] = 0;
				m_ppg_ye[i][j] = 0;

			
				m_car_ppg_name[i][j] = "";
				m_car_ppg[i][j] = 0;
				m_car_pts[i][j] = 0;
				m_car_ppg_id[i][j] = 0;
				m_car_ppg_te[i][j] = 0;


				


				m_rpg_name[i][j] = "";
				m_rpg[i][j] = 0;
				m_rpg_id[i][j] = 0;
				m_rpg_te[i][j] = 0;
				m_rpg_ye[i][j] = 0;

			
				m_car_rpg_name[i][j] = "";
				m_car_rpg[i][j] = 0;
				m_car_reb[i][j] = 0;
				m_car_rpg_id[i][j] = 0;
				m_car_rpg_te[i][j] = 0;


				
				m_apg_name[i][j] = "";
				m_apg[i][j] = 0;
				m_apg_id[i][j] = 0;
				m_apg_te[i][j] = 0;
				m_apg_ye[i][j] = 0;

			
				m_car_apg_name[i][j] = "";
				m_car_apg[i][j] = 0;
				m_car_ast[i][j] = 0;
				m_car_apg_id[i][j] = 0;
				m_car_apg_te[i][j] = 0;

			
				m_spg_name[i][j] = "";
				m_spg[i][j] = 0;
				m_spg_id[i][j] = 0;
				m_spg_te[i][j] = 0;
				m_spg_ye[i][j] = 0;

			
				m_car_spg_name[i][j] = "";
				m_car_spg[i][j] = 0;
				m_car_stl[i][j] = 0;
				m_car_spg_id[i][j] = 0;
				m_car_spg_te[i][j] = 0;

			
				m_bpg_name[i][j] = "";
				m_bpg[i][j] = 0;
				m_bpg_id[i][j] = 0;
				m_bpg_te[i][j] = 0;
				m_bpg_ye[i][j] = 0;

			
				m_car_bpg_name[i][j] = "";
				m_car_bpg[i][j] = 0;
				m_car_blk[i][j] = 0;
				m_car_bpg_id[i][j] = 0;
				m_car_bpg_te[i][j] = 0;


			
				m_fgp_name[i][j] = "";
				m_fgp[i][j] = 0;
				m_fgp_id[i][j] = 0;
				m_fgp_te[i][j] = 0;
				m_fgp_ye[i][j] = 0;

			
				m_car_fgp_name[i][j] = "";
				m_car_fgp[i][j] = 0;
				m_car_fgm[i][j] = 0;
				m_car_fgp_id[i][j] = 0;
				m_car_fgp_te[i][j] = 0;


			
				m_ftp_name[i][j] = "";
				m_ftp[i][j] = 0;
				m_ftp_id[i][j] = 0;
				m_ftp_te[i][j] = 0;
				m_ftp_ye[i][j] = 0;

				m_car_ftp_name[i][j] = "";
				m_car_ftp[i][j] = 0;
				m_car_ftm[i][j] = 0;
				m_car_ftp_id[i][j] = 0;
				m_car_ftp_te[i][j] = 0;


				

				m_tgp_name[i][j] = "";
				m_tgp[i][j] = 0;
				m_tgp_id[i][j] = 0;
				m_tgp_te[i][j] = 0;
				m_tgp_ye[i][j] = 0;

			
				m_car_tgp_name[i][j] = "";
				m_car_tgp[i][j] = 0;
				m_car_tgm[i][j] = 0;
				m_car_tgp_id[i][j] = 0;
				m_car_tgp_te[i][j] = 0;
			
		}
	}











	for(int i=0; i<=1; i++)
	{
		for(int j=0; j<=32; j++)
		{
			for(int k=0; k<=9; k++)
			{
				for(int l=0; l<=7; l++)
				{

					m_g_name[i][j][k][l] = "";
					m_g_amt[i][j][k][l] = 0;
					m_g_id[i][j][k][l] = 0;
					m_g_ye[i][j][k][l] = 0;

					m_g_po_name[i][j][k][l] = "";
					m_g_po_amt[i][j][k][l] = 0;
					m_g_po_id[i][j][k][l] = 0;
					m_g_po_ye[i][j][k][l] = 0;
				}
			}
		}
	}

}

CHigh::~CHigh()
{
}


void CHigh::OpenHighs(CString file_name)
{



	CFile file( file_name, CFile::modeRead);

	for(int t=0; t<=1; t++)
	{

		int m_offset = 0;
		if(t==1) m_offset = 33000;

	int offset = 1 + m_offset;
	file.Seek(offset, CFile::begin);
	char s[17];
	int rd[] = {1,2,3,4,0};
	//load lge records
	for(int stat=0; stat<=4; stat++)
	{
	for(int rank=0; rank<=2; rank++)
	{
		int bytes = file.Read(s, 16);
		s[bytes] = 0;

		if(t==0)
			m_g_name[0][0][rank][rd[stat]] = CString(s);
		else
			m_g_po_name[0][0][rank][rd[stat]] = CString(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int i = atoi(s);
		if(t==0)
			m_g_amt[0][0][rank][rd[stat]] = i;
		else
			m_g_po_amt[0][0][rank][rd[stat]] = i;
	}
	}
	//load team records
	for(int te=1; te<=32; te++)
	{

	offset = (te*1000+1) + m_offset;
	file.Seek(offset, CFile::begin);

	for(int stat=0; stat<=4; stat++)
	{
	for(int rank=0; rank<=2; rank++)
	{
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		if(t==0)
			m_g_name[0][te][rank][rd[stat]] = CString(s);
		else
			m_g_po_name[0][te][rank][rd[stat]] = CString(s);


		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int i = atoi(s);
		if(t==0)
			m_g_amt[0][te][rank][rd[stat]] = i;
		else
			m_g_po_amt[0][te][rank][rd[stat]] = i;


	}
	}

	}
	
	}

	file.Close();
}



void CHigh::OpenAllHighs(CString file_name)
{
	CFile file( file_name, CFile::modeRead);
	int rd[] = {1,2,3,4,0};

	for(int t=0; t<=1; t++)
	{

		int m_offset = 0;
		if(t==1) m_offset = 33000;

	int offset = 1 + m_offset;
	file.Seek(offset, CFile::begin);
	char s[17];
	//load lge records



	for(int stat=0; stat<=4; stat++)
	{
	for(int rank=0; rank<=2; rank++)
	{
		int bytes = file.Read(s, 16);
		s[bytes] = 0;

		if(t==0)
			m_g_name[1][0][rank][rd[stat]] = CString(s);
		else
			m_g_po_name[1][0][rank][rd[stat]] = CString(s);


		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int i = atoi(s);

		if(t==0)
			m_g_amt[1][0][rank][rd[stat]] = i;
		else
			m_g_po_amt[1][0][rank][rd[stat]] = i;
	}
	}
	//load team records
	for(int te=1; te<=32; te++)
	{

	offset = (te*1000+1) + m_offset;
	file.Seek(offset, CFile::begin);

	for(int stat=0; stat<=4; stat++)
	{
	for(int rank=0; rank<=2; rank++)
	{
		int bytes = file.Read(s, 16);
		s[bytes] = 0;

		if(t==0)
			m_g_name[1][te][rank][rd[stat]] = CString(s);
		else
			m_g_po_name[1][te][rank][rd[stat]] = CString(s);


		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int i = atoi(s);

		if(t==0)
			m_g_amt[1][te][rank][rd[stat]] = i;
		else
			m_g_po_amt[1][te][rank][rd[stat]] = i;

	}
	}

	}
	
	}

	file.Close();







}

void CHigh::SetAllTimeSeasonHighs(CPlayer m_actual[1601], int currentYear, int games_in_season)
{
	for(int i=0; i<=1440; i++)
	{

		if(m_actual[i].m_name == "") continue;
		m_actual[i].SetSeasonAverages();




					










		double pts = m_actual[i].m_sim_pointsPerGame;
		int car_pts = m_actual[i].m_car_fgm*2 + m_actual[i].m_car_tfgm*3 + m_actual[i].m_car_ftm;

		double reb = (m_actual[i].m_sim_reboundsPerGame + m_actual[i].m_sim_orbPerGame);
		int car_reb = m_actual[i].m_car_reb + m_actual[i].m_car_oreb;

		double ast =  (m_actual[i].m_sim_assistsPerGame);
		int car_ast = m_actual[i].m_car_ast;

		double stl =  (m_actual[i].m_sim_stealsPerGame);
		int car_stl = m_actual[i].m_car_stl;

		double blk =  (m_actual[i].m_sim_blocksPerGame);
		int car_blk = m_actual[i].m_car_blk;

		double fgp =  m_actual[i].m_sim_fgPct;
		double car_fgp = 0;
		if(m_actual[i].m_car_fgm > 0)
			car_fgp = ((double)m_actual[i].m_car_fgm + (double)m_actual[i].m_car_tfgm) / ((double)m_actual[i].m_car_fga + (double)m_actual[i].m_car_tfga) * 100;

		
		double ftp =  m_actual[i].m_sim_ftPct;
		double car_ftp = 0;
		if(m_actual[i].m_car_ftm > 0)
			car_ftp = (double)m_actual[i].m_car_ftm  / (double)m_actual[i].m_car_fta * 100;

		double tgp =  m_actual[i].m_sim_tfgPct;
		double car_tgp = 0;
		if(m_actual[i].m_car_tfgm > 0)
			car_tgp = (double)m_actual[i].m_car_tfgm  / (double)m_actual[i].m_car_tfga * 100;


		bool pts_ok = false;			
		if(pts >= 1400./82. || (double)m_actual[i].m_sim_games/ (double)games_in_season >= 70./82.) 
				pts_ok = true;

		bool reb_ok = false;			
		if(reb >= 800./82. || (double)m_actual[i].m_sim_games/ (double)games_in_season >= 70./82.) 
				reb_ok = true;

		bool ast_ok = false;			
		if(ast >= 400./82. || (double)m_actual[i].m_sim_games/ (double)games_in_season >= 70./82.) 
				ast_ok = true;

		bool stl_ok = false;			
		if(stl >= 125./82. || (double)m_actual[i].m_sim_games/ (double)games_in_season >= 70./82.) 
				stl_ok = true;

		bool blk_ok = false;			
		if(blk >= 100./82. || (double)m_actual[i].m_sim_games/ (double)games_in_season >= 70./82.) 
				blk_ok = true;

		double qualify = (double)games_in_season;

		bool fgm_ok = false;			
		if( (((double)m_actual[i].m_sim_fgm + (double)m_actual[i].m_sim_tfgm) / qualify)  >= 300./82.) 
				fgm_ok = true;

		bool ftm_ok = false;			
		if( ((double)m_actual[i].m_sim_ftm / qualify) >= 55./82.) 
				ftm_ok = true;

		bool tgm_ok = false;			
		if( ((double)m_actual[i].m_sim_tfgm / qualify)>= 125./82.) 
				tgm_ok = true;



		CString na = m_actual[i].m_name;
		int te = m_actual[i].m_current_team + 1;
		int id = m_actual[i].m_id;
		int yr = currentYear;


		for(int t=1; t<=2; t++)//2 times 2nd for team only
		{

		if(i > 960 && t==1) continue;

		int ra = 50;
		int slot[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};


		int ts=0;
		if(t==1) ts=te;
			
		bool win = false;
		do
		{
			if(pts >= m_ppg[ts][ra] && pts_ok==true)
			{
				slot[0] = ra;
				ra = ra - 1;
				win = true;
			}
			else
				win = false;

			if(ra == 0) win = false;//cant do better
		}
		while (win == true);


		if(slot[0] <= 50)
		{
			for(int j=50; j>= slot[0]+1; j--)
			{
				m_ppg[ts][j] = m_ppg[ts][j-1];
				m_ppg_id[ts][j] = m_ppg_id[ts][j-1];
				m_ppg_te[ts][j] = m_ppg_te[ts][j-1];
				m_ppg_ye[ts][j] = m_ppg_ye[ts][j-1];
				m_ppg_name[ts][j] = m_ppg_name[ts][j-1];
			}
			m_ppg[ts][slot[0]] = pts;
			m_ppg_id[ts][slot[0]] = id;
			m_ppg_te[ts][slot[0]] = te;
			m_ppg_ye[ts][slot[0]] = yr;
			m_ppg_name[ts][slot[0]] = na;





		}
		



		int ra1 = 50;
		int slot1[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win1 = false;
		do
		{
			if(reb >= m_rpg[ts][ra1] && reb_ok==true)
			{
				slot1[0] = ra1;
				ra1 = ra1 - 1;
				win1 = true;
			}
			else
				win1 = false;

			if(ra1 == 0) win1= false;//cant do better
		}
		while (win1 == true);


		if(slot1[0] <= 50)
		{
			for(int  j=50; j>= slot1[0]+1; j--)
			{
				m_rpg[ts][j] = m_rpg[ts][j-1];
				m_rpg_id[ts][j] = m_rpg_id[ts][j-1];
				m_rpg_te[ts][j] = m_rpg_te[ts][j-1];
				m_rpg_ye[ts][j] = m_rpg_ye[ts][j-1];
				m_rpg_name[ts][j] = m_rpg_name[ts][j-1];
			}
			m_rpg[ts][slot1[0]] = reb;
			m_rpg_id[ts][slot1[0]] = id;
			m_rpg_te[ts][slot1[0]] = te;
			m_rpg_ye[ts][slot1[0]] = yr;
			m_rpg_name[ts][slot1[0]] = na;




		}
		


	int ra2 = 50;
		int slot2[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win2 = false;
		do
		{
			if(ast >= m_apg[ts][ra2] && ast_ok==true)
			{
				slot2[0] = ra2;
				ra2 = ra2 - 1;
				win2 = true;
			}
			else
				win2 = false;

			if(ra2 == 0) win2= false;//cant do better
		}
		while (win2 == true);


		if(slot2[0] <= 50)
		{
			for(int j=50; j>= slot2[0]+1; j--)
			{
				m_apg[ts][j] = m_apg[ts][j-1];
				m_apg_id[ts][j] = m_apg_id[ts][j-1];
				m_apg_te[ts][j] = m_apg_te[ts][j-1];
				m_apg_ye[ts][j] = m_apg_ye[ts][j-1];
				m_apg_name[ts][j] = m_apg_name[ts][j-1];
			}
			m_apg[ts][slot2[0]] = ast;
			m_apg_id[ts][slot2[0]] = id;
			m_apg_te[ts][slot2[0]] = te;
			m_apg_ye[ts][slot2[0]] = yr;
			m_apg_name[ts][slot2[0]] = na;






		}
				
		
		
		
			int ra3 = 50;
		int slot3[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win3 = false;
		do
		{
			if(stl >= m_spg[ts][ra3] && stl_ok==true)
			{
				slot3[0] = ra3;
				ra3 = ra3 - 1;
				win3 = true;
			}
			else
				win3 = false;

			if(ra3 == 0) win3= false;//cant do better
		}
		while (win3 == true);


		if(slot3[0] <= 50)
		{
			for(int j=50; j>= slot3[0]+1; j--)
			{
				m_spg[ts][j] = m_spg[ts][j-1];
				m_spg_id[ts][j] = m_spg_id[ts][j-1];
				m_spg_te[ts][j] = m_spg_te[ts][j-1];
				m_spg_ye[ts][j] = m_spg_ye[ts][j-1];
				m_spg_name[ts][j] = m_spg_name[ts][j-1];
			}
			m_spg[ts][slot3[0]] = stl;
			m_spg_id[ts][slot3[0]] = id;
			m_spg_te[ts][slot3[0]] = te;
			m_spg_ye[ts][slot3[0]] = yr;
			m_spg_name[ts][slot3[0]] = na;





		}
				
		
			int ra4 = 50;
		int slot4[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win4 = false;
		do
		{
			if(blk >= m_bpg[ts][ra4] && blk_ok==true)
			{
				slot4[0] = ra4;
				ra4 = ra4 - 1;
				win4 = true;
			}
			else
				win4 = false;

			if(ra4 == 0) win4= false;//cant do better
		}
		while (win4 == true);


		if(slot4[0] <= 50)
		{
			for(int j=50; j>= slot4[0]+1; j--)
			{
				m_bpg[ts][j] = m_bpg[ts][j-1];
				m_bpg_id[ts][j] = m_bpg_id[ts][j-1];
				m_bpg_te[ts][j] = m_bpg_te[ts][j-1];
				m_bpg_ye[ts][j] = m_bpg_ye[ts][j-1];
				m_bpg_name[ts][j] = m_bpg_name[ts][j-1];
			}
			m_bpg[ts][slot4[0]] = blk;
			m_bpg_id[ts][slot4[0]] = id;
			m_bpg_te[ts][slot4[0]] = te;
			m_bpg_ye[ts][slot4[0]] = yr;
			m_bpg_name[ts][slot4[0]] = na;



		}
				
		

	int ra5 = 50;
		int slot5[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win5 = false;
		do
		{
			if(fgp >= m_fgp[ts][ra5] && fgm_ok==true)
			{
				slot5[0] = ra5;
				ra5 = ra5 - 1;
				win5 = true;
			}
			else
				win5 = false;

			if(ra5 == 0) win5= false;//cant do better
		}
		while (win5 == true);


		if(slot5[0] <= 50)
		{
			for(int j=50; j>= slot5[0]+1; j--)
			{
				m_fgp[ts][j] = m_fgp[ts][j-1];
				m_fgp_id[ts][j] = m_fgp_id[ts][j-1];
				m_fgp_te[ts][j] = m_fgp_te[ts][j-1];
				m_fgp_ye[ts][j] = m_fgp_ye[ts][j-1];
				m_fgp_name[ts][j] = m_fgp_name[ts][j-1];
			}
			m_fgp[ts][slot5[0]] = fgp;
			m_fgp_id[ts][slot5[0]] = id;
			m_fgp_te[ts][slot5[0]] = te;
			m_fgp_ye[ts][slot5[0]] = yr;
			m_fgp_name[ts][slot5[0]] = na;




		}
				
		
	int ra6 = 50;
		int slot6[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win6 = false;
		do
		{
			if(ftp >= m_ftp[ts][ra6] && ftm_ok==true)
			{
				slot6[0] = ra6;
				ra6 = ra6 - 1;
				win6 = true;
			}
			else
				win6 = false;

			if(ra6 == 0) win6= false;//cant do better
		}
		while (win6 == true);


		if(slot6[0] <= 50)
		{
			for(int j=50; j>= slot6[0]+1; j--)
			{
				m_ftp[ts][j] = m_ftp[ts][j-1];
				m_ftp_id[ts][j] = m_ftp_id[ts][j-1];
				m_ftp_te[ts][j] = m_ftp_te[ts][j-1];
				m_ftp_ye[ts][j] = m_ftp_ye[ts][j-1];
				m_ftp_name[ts][j] = m_ftp_name[ts][j-1];
			}
			m_ftp[ts][slot6[0]] = ftp;
			m_ftp_id[ts][slot6[0]] = id;
			m_ftp_te[ts][slot6[0]] = te;
			m_ftp_ye[ts][slot6[0]] = yr;
			m_ftp_name[ts][slot6[0]] = na;



		}
				
		
				
	int ra7 = 50;
		int slot7[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win7 = false;
		do
		{
			if(tgp >= m_tgp[ts][ra7] && tgm_ok==true)
			{
				slot7[0] = ra7;
				ra7 = ra7 - 1;
				win7 = true;
			}
			else
				win7 = false;

			if(ra7 == 0) win7= false;//cant do better
		}
		while (win7 == true);


		if(slot7[0] <= 50)
		{
			for(int j=50; j>= slot7[0]+1; j--)
			{
				m_tgp[ts][j] = m_tgp[ts][j-1];
				m_tgp_id[ts][j] = m_tgp_id[ts][j-1];
				m_tgp_te[ts][j] = m_tgp_te[ts][j-1];
				m_tgp_ye[ts][j] = m_tgp_ye[ts][j-1];
				m_tgp_name[ts][j] = m_tgp_name[ts][j-1];
			}
			m_tgp[ts][slot7[0]] = tgp;
			m_tgp_id[ts][slot7[0]] = id;
			m_tgp_te[ts][slot7[0]] = te;
			m_tgp_ye[ts][slot7[0]] = yr;
			m_tgp_name[ts][slot7[0]] = na;



		}
				
		


		
		}


	}


	for(int i=0; i<=1504; i++)
	{


		if(m_actual[i].m_name == "") continue;

		if(i > 1440)
		{
			m_actual[i].m_car_games = 1;
			m_actual[i].SetSeasonAverages();
		}



		double pts = m_actual[i].m_sim_pointsPerGame;
		int car_pts = m_actual[i].m_car_fgm*2 + m_actual[i].m_car_tfgm*3 + m_actual[i].m_car_ftm;

		double reb = m_actual[i].m_sim_reboundsPerGame + m_actual[i].m_sim_orbPerGame;
		int car_reb = m_actual[i].m_car_reb + m_actual[i].m_car_oreb;

		double ast =  m_actual[i].m_sim_assistsPerGame;
		int car_ast = m_actual[i].m_car_ast;

		double stl =  m_actual[i].m_sim_stealsPerGame;
		int car_stl = m_actual[i].m_car_stl;

		double blk =  m_actual[i].m_sim_blocksPerGame;
		int car_blk = m_actual[i].m_car_blk;

		


		double fgp =  m_actual[i].m_sim_fgPct;
		double car_fgp = 0;
		if(m_actual[i].m_car_fgm > 0)
			car_fgp = ((double)m_actual[i].m_car_fgm + (double)m_actual[i].m_car_tfgm) / ((double)m_actual[i].m_car_fga + (double)m_actual[i].m_car_tfga) * 100;

		
		double ftp =  m_actual[i].m_sim_ftPct;
		double car_ftp = 0;
		if(m_actual[i].m_car_ftm > 0)
			car_ftp = (double)m_actual[i].m_car_ftm  / (double)m_actual[i].m_car_fta * 100;

		double tgp =  m_actual[i].m_sim_tfgPct;
		double car_tgp = 0;
		if(m_actual[i].m_car_tfgm > 0)
			car_tgp = (double)m_actual[i].m_car_tfgm  / (double)m_actual[i].m_car_tfga * 100;

		
		bool fgm_ok=true, ftm_ok=true, tgm_ok=true;
		if((m_actual[i].m_car_fgm + m_actual[i].m_car_tfgm) < 100) fgm_ok = false;
		if(m_actual[i].m_car_tfgm < 25) tgm_ok = false;
		if(m_actual[i].m_car_ftm < 50) ftm_ok = false;



		CString na = m_actual[i].m_name;
		int te = m_actual[i].m_current_team + 1;
		int id = m_actual[i].m_id;
		int yr = currentYear;





		for(int t=0; t<=4; t++)//2 times 2nd for team only
		{

		int ra = 50;
		int slot[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};

		if(t==0 && i > 1440) continue;
		if(t==1 && (i < 1441 || i > 1472)) continue;
		if(t==2 && (i < 1473 || i > 1504)) continue;
		if(t==3 && (i < 1441 || i > 1472)) continue;
		if(t==4 && (i < 1473 || i > 1504)) continue;

		if(i>1440)
		{
			id=currentYear;
			te=0;
		}


		if(t>=1 && t<=4)
		{

		car_pts = int(pts*100);//mask but really using season averages for teams now
		car_reb = int(reb*100);
		car_ast = int(ast*100);
		car_stl = int(stl*100);
		car_blk = int(blk*100);
		car_fgp = fgp;
		car_ftp = ftp;
		car_tgp = tgp;

		}


		int ts=t;
			
		bool win = false;
		do
		{
			if(t>=3 && m_car_pts[ts][ra] == 0) m_car_pts[ts][ra] = 65535;


			if(t>=3 && car_pts <= m_car_pts[ts][ra])
			{
				slot[0] = ra;
				ra = ra - 1;
				win = true;
			}
			else if(t<3 && car_pts >= m_car_pts[ts][ra])
			{
				slot[0] = ra;
				ra = ra - 1;
				win = true;
			}
			else
				win = false;

			if(ra == 0) win = false;//cant do better
		}
		while (win == true);


		if(slot[0] <= 50)
		{
			for(int j=50; j>= slot[0]+1; j--)
			{
				m_car_ppg_name[ts][j] = m_car_ppg_name[ts][j-1];
				m_car_ppg_id[ts][j] = m_car_ppg_id[ts][j-1];
				m_car_pts[ts][j] = m_car_pts[ts][j-1];
				m_car_ppg[ts][j] = m_car_ppg[ts][j-1];
				m_car_ppg_te[ts][j] = m_car_ppg_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double ppg = 0;
			if(ga > 0 && ts==0) ppg = (double)car_pts / ga;		

			m_car_pts[ts][slot[0]] = car_pts;
			m_car_ppg[ts][slot[0]] = ppg;
			m_car_ppg_id[ts][slot[0]] = id;
			m_car_ppg_te[ts][slot[0]] = te;
			m_car_ppg_name[ts][slot[0]] = na;
		}


			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
				if(ts>0) continue;
			
				if(m_car_ppg_id[ts][slot[0]] == m_car_ppg_id[ts][j] && slot[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_pts[ts][k] = m_car_pts[ts][k+1];
						m_car_ppg_id[ts][k] = m_car_ppg_id[ts][k+1];
						m_car_ppg[ts][k] = m_car_ppg[ts][k+1];
						m_car_ppg_te[ts][k] = m_car_ppg_te[ts][k+1];
						m_car_ppg_name[ts][k] = m_car_ppg_name[ts][k+1];
					}

					m_car_pts[ts][50] = 0;
					m_car_ppg_id[ts][50] = 0;
					m_car_ppg_te[ts][50] = 0;
					m_car_ppg[ts][50] = 0;
					m_car_ppg_name[ts][50] = "";
				}
			}
			//end check




		int ra1 = 50;
		int slot1[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win1 = false;
		do
		{
			if(t>=3 && m_car_reb[ts][ra1] == 0) m_car_reb[ts][ra1] = 65535;
			if( t>=3 && car_reb <= m_car_reb[ts][ra1] )
			{
				slot1[0] = ra1;
				ra1 = ra1 - 1;
				win1 = true;
			}
			else if(t<3 && car_reb >= m_car_reb[ts][ra1])
			{
				slot1[0] = ra1;
				ra1 = ra1 - 1;
				win1 = true;
			}
			else
				win1 = false;

			if(ra1 == 0) win1 = false;//cant do better
		}
		while (win1 == true);


		if(slot1[0] <= 50)
		{
			for(int j=50; j>= slot1[0]+1; j--)
			{
				m_car_rpg_name[ts][j] = m_car_rpg_name[ts][j-1];
				m_car_rpg_id[ts][j] = m_car_rpg_id[ts][j-1];
				m_car_reb[ts][j] = m_car_reb[ts][j-1];
				m_car_rpg[ts][j] = m_car_rpg[ts][j-1];
				m_car_rpg_te[ts][j] = m_car_rpg_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double rpg = 0;
			if(ga > 0 && ts==0) rpg = (double)car_reb / ga;		

			m_car_reb[ts][slot1[0]] = car_reb;
			m_car_rpg[ts][slot1[0]] = rpg;
			m_car_rpg_id[ts][slot1[0]] = id;
			m_car_rpg_te[ts][slot1[0]] = te;
			m_car_rpg_name[ts][slot1[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
				if(ts>0) continue;
			
				if(m_car_rpg_id[ts][slot1[0]] == m_car_rpg_id[ts][j] && slot1[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_reb[ts][k] = m_car_reb[ts][k+1];
						m_car_rpg_id[ts][k] = m_car_rpg_id[ts][k+1];
						m_car_rpg[ts][k] = m_car_rpg[ts][k+1];
						m_car_rpg_te[ts][k] = m_car_rpg_te[ts][k+1];
						m_car_rpg_name[ts][k] = m_car_rpg_name[ts][k+1];
					}

					m_car_reb[ts][50] = 0;
					m_car_rpg_id[ts][50] = 0;
					m_car_rpg_te[ts][50] = 0;
					m_car_rpg[ts][50] = 0;
					m_car_rpg_name[ts][50] = "";
				}
			}
			//end check




		int ra2 = 50;
		int slot2[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win2 = false;
		do
		{
			if(t>=3 && m_car_ast[ts][ra2] == 0) m_car_ast[ts][ra2] = 65535;
			if(t>=3 && car_ast <= m_car_ast[ts][ra2])
			{
				slot2[0] = ra2;
				ra2 = ra2 - 1;
				win2 = true;
			}
			else if(t<3 && car_ast >= m_car_ast[ts][ra2])
			{
				slot2[0] = ra2;
				ra2 = ra2 - 1;
				win2 = true;
			}
			else
				win2 = false;

			if(ra2 == 0) win2 = false;//cant do better
		}
		while (win2 == true);


		if(slot2[0] <= 50)
		{
			for(int j=50; j>= slot2[0]+1; j--)
			{
				m_car_apg_name[ts][j] = m_car_apg_name[ts][j-1];
				m_car_apg_id[ts][j] = m_car_apg_id[ts][j-1];
				m_car_ast[ts][j] = m_car_ast[ts][j-1];
				m_car_apg[ts][j] = m_car_apg[ts][j-1];
				m_car_apg_te[ts][j] = m_car_apg_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double apg = 0;
			if(ga > 0 && ts==0) apg = (double)car_ast / ga;		

			m_car_ast[ts][slot2[0]] = car_ast;
			m_car_apg[ts][slot2[0]] = apg;
			m_car_apg_id[ts][slot2[0]] = id;
			m_car_apg_te[ts][slot2[0]] = te;
			m_car_apg_name[ts][slot2[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_apg_id[ts][slot2[0]] == m_car_apg_id[ts][j] && slot2[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_ast[ts][k] = m_car_ast[ts][k+1];
						m_car_apg_id[ts][k] = m_car_apg_id[ts][k+1];
						m_car_apg[ts][k] = m_car_apg[ts][k+1];
						m_car_apg_te[ts][k] = m_car_apg_te[ts][k+1];
						m_car_apg_name[ts][k] = m_car_apg_name[ts][k+1];
					}

					m_car_ast[ts][50] = 0;
					m_car_apg_id[ts][50] = 0;
					m_car_apg_te[ts][50] = 0;
					m_car_apg[ts][50] = 0;
					m_car_apg_name[ts][50] = "";
				}
			}
			//end check


		int ra3 = 50;
		int slot3[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win3 = false;
		do
		{
			if(t>=3 && m_car_stl[ts][ra3] == 0) m_car_stl[ts][ra3] = 65535;
			if(t>=3 && car_stl <= m_car_stl[ts][ra3])
			{
				slot3[0] = ra3;
				ra3 = ra3 - 1;
				win3 = true;
			}
			else if(t<3 && car_stl >= m_car_stl[ts][ra3])
			{
				slot3[0] = ra3;
				ra3 = ra3 - 1;
				win3 = true;
			}
			else
				win3 = false;

			if(ra3 == 0) win3 = false;//cant do better
		}
		while (win3 == true);


		if(slot3[0] <= 50)
		{
			for(int j=50; j>= slot3[0]+1; j--)
			{
				m_car_spg_name[ts][j] = m_car_spg_name[ts][j-1];
				m_car_spg_id[ts][j] = m_car_spg_id[ts][j-1];
				m_car_stl[ts][j] = m_car_stl[ts][j-1];
				m_car_spg[ts][j] = m_car_spg[ts][j-1];
				m_car_spg_te[ts][j] = m_car_spg_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double spg = 0;
			if(ga > 0 && ts==0) spg = (double)car_stl / ga;		

			m_car_stl[ts][slot3[0]] = car_stl;
			m_car_spg[ts][slot3[0]] = spg;
			m_car_spg_id[ts][slot3[0]] = id;
			m_car_spg_te[ts][slot3[0]] = te;
			m_car_spg_name[ts][slot3[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_spg_id[ts][slot3[0]] == m_car_spg_id[ts][j] && slot3[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_stl[ts][k] = m_car_stl[ts][k+1];
						m_car_spg_id[ts][k] = m_car_spg_id[ts][k+1];
						m_car_spg[ts][k] = m_car_spg[ts][k+1];
						m_car_spg_te[ts][k] = m_car_spg_te[ts][k+1];
						m_car_spg_name[ts][k] = m_car_spg_name[ts][k+1];
					}

					m_car_stl[ts][50] = 0;
					m_car_spg_id[ts][50] = 0;
					m_car_spg_te[ts][50] = 0;
					m_car_spg[ts][50] = 0;
					m_car_spg_name[ts][50] = "";
				}
			}
			//end check



	int ra4 = 50;
		int slot4[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win4 = false;
		do
		{
			if(t>=3 && m_car_blk[ts][ra4] == 0) m_car_blk[ts][ra4] = 65535;
			if(t>=3 && car_blk <= m_car_blk[ts][ra4])
			{
				slot4[0] = ra4;
				ra4 = ra4 - 1;
				win4 = true;
			}
			else if(t<3 && car_blk >= m_car_blk[ts][ra4])
			{
				slot4[0] = ra4;
				ra4 = ra4 - 1;
				win4 = true;
			}
			else
				win4 = false;

			if(ra4 == 0) win4 = false;//cant do better
		}
		while (win4 == true);


		if(slot4[0] <= 50)
		{
			for(int j=50; j>= slot4[0]+1; j--)
			{
				m_car_bpg_name[ts][j] = m_car_bpg_name[ts][j-1];
				m_car_bpg_id[ts][j] = m_car_bpg_id[ts][j-1];
				m_car_blk[ts][j] = m_car_blk[ts][j-1];
				m_car_bpg[ts][j] = m_car_bpg[ts][j-1];
				m_car_bpg_te[ts][j] = m_car_bpg_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double bpg = 0;
			if(ga > 0 && ts==0) bpg = (double)car_blk / ga;		

			m_car_blk[ts][slot4[0]] = car_blk;
			m_car_bpg[ts][slot4[0]] = bpg;
			m_car_bpg_id[ts][slot4[0]] = id;
			m_car_bpg_te[ts][slot4[0]] = te;
			m_car_bpg_name[ts][slot4[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_bpg_id[ts][slot4[0]] == m_car_bpg_id[ts][j] && slot4[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_blk[ts][k] = m_car_blk[ts][k+1];
						m_car_bpg_id[ts][k] = m_car_bpg_id[ts][k+1];
						m_car_bpg[ts][k] = m_car_bpg[ts][k+1];
						m_car_bpg_te[ts][k] = m_car_bpg_te[ts][k+1];
						m_car_bpg_name[ts][k] = m_car_bpg_name[ts][k+1];
					}

					m_car_blk[ts][50] = 0;
					m_car_bpg_id[ts][50] = 0;
					m_car_bpg_te[ts][50] = 0;
					m_car_bpg[ts][50] = 0;
					m_car_bpg_name[ts][50] = "";
				}
			}
			//end check




	int ra5 = 50;
		int slot5[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win5 = false;
		do
		{

			if(m_car_fgp[ts][ra5] == 6553.5) m_car_fgp[ts][ra5] = 0;
			if(t>=3 && (m_car_fgp[ts][ra5] == 0 || m_car_fgp_id[ts][ra5] == 0))
			{
				if(ts != 1 && ts != 2)
					m_car_fgp[ts][ra5] = 65535;
			}


			


			if(t>=3 && car_fgp <= m_car_fgp[ts][ra5])
			{
				slot5[0] = ra5;
				ra5 = ra5 - 1;
				win5 = true;
			}
			else if(t<3 && car_fgp >= m_car_fgp[ts][ra5] && (fgm_ok==true || ts>0))
			{
				slot5[0] = ra5;
				ra5 = ra5 - 1;
				win5 = true;
			}
			else
				win5 = false;

			if(ra5 == 0) win5 = false;//cant do better
		}
		while (win5 == true);


		if(slot5[0] <= 50)
		{
			for(int j=50; j>= slot5[0]+1; j--)
			{
				m_car_fgp_name[ts][j] = m_car_fgp_name[ts][j-1];
				m_car_fgp_id[ts][j] = m_car_fgp_id[ts][j-1];
				m_car_fgm[ts][j] = m_car_fgm[ts][j-1];
				m_car_fgp[ts][j] = m_car_fgp[ts][j-1];
				m_car_fgp_te[ts][j] = m_car_fgp_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			int car_fgm = m_actual[i].m_car_fgm + m_actual[i].m_car_tfgm;
			double fgp = 0;
			if(ga > 0 ) fgp = (double)car_fgp;		
			if(ts > 0) car_fgm = 0;

			m_car_fgm[ts][slot5[0]] = car_fgm;
			m_car_fgp[ts][slot5[0]] = fgp;
			m_car_fgp_id[ts][slot5[0]] = id;
			m_car_fgp_te[ts][slot5[0]] = te;
			m_car_fgp_name[ts][slot5[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_fgp_id[ts][slot5[0]] == m_car_fgp_id[ts][j] && slot5[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_fgm[ts][k] = m_car_fgm[ts][k+1];
						m_car_fgp_id[ts][k] = m_car_fgp_id[ts][k+1];
						m_car_fgp[ts][k] = m_car_fgp[ts][k+1];
						m_car_fgp_te[ts][k] = m_car_fgp_te[ts][k+1];
						m_car_fgp_name[ts][k] = m_car_fgp_name[ts][k+1];
					}

					m_car_fgm[ts][50] = 0;
					m_car_fgp_id[ts][50] = 0;
					m_car_fgp_te[ts][50] = 0;
					m_car_fgp[ts][50] = 0;
					m_car_fgp_name[ts][50] = "";
				}
			}
			//end check




	int ra6 = 50;
		int slot6[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win6 = false;
		do
		{
			if(m_car_ftp[ts][ra6] == 6553.5) m_car_ftp[ts][ra6] = 0;
			if(t>=3 && (m_car_ftp[ts][ra6] == 0 || m_car_ftp_id[ts][ra6] == 0))
			{
				if(ts != 1 && ts != 2)
					m_car_ftp[ts][ra6] = 65535;
			}
			if(t>=3 && car_ftp <= m_car_ftp[ts][ra6])
			{
				slot6[0] = ra6;
				ra6 = ra6 - 1;
				win6 = true;
			}
			else if(t<3 && car_ftp >= m_car_ftp[ts][ra6] && (ftm_ok==true || ts>0))
			{
				slot6[0] = ra6;
				ra6 = ra6 - 1;
				win6 = true;
			}
			else
				win6 = false;

			if(ra6 == 0) win6 = false;//cant do better
		}
		while (win6 == true);


		if(slot6[0] <= 50)
		{
			for(int j=50; j>= slot6[0]+1; j--)
			{
				m_car_ftp_name[ts][j] = m_car_ftp_name[ts][j-1];
				m_car_ftp_id[ts][j] = m_car_ftp_id[ts][j-1];
				m_car_ftm[ts][j] = m_car_ftm[ts][j-1];
				m_car_ftp[ts][j] = m_car_ftp[ts][j-1];
				m_car_ftp_te[ts][j] = m_car_ftp_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double ftp = 0;
			if(ga > 0) ftp = (double)car_ftp;		
			int car_ftm = m_actual[i].m_car_ftm;
			if(ts > 0) car_ftm = 0;


			m_car_ftm[ts][slot6[0]] = car_ftm;
			m_car_ftp[ts][slot6[0]] = ftp;
			m_car_ftp_id[ts][slot6[0]] = id;
			m_car_ftp_te[ts][slot6[0]] = te;
			m_car_ftp_name[ts][slot6[0]] = na;
		}
		

			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_ftp_id[ts][slot6[0]] == m_car_ftp_id[ts][j] && slot6[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_ftm[ts][k] = m_car_ftm[ts][k+1];
						m_car_ftp_id[ts][k] = m_car_ftp_id[ts][k+1];
						m_car_ftp[ts][k] = m_car_ftp[ts][k+1];
						m_car_ftp_te[ts][k] = m_car_ftp_te[ts][k+1];
						m_car_ftp_name[ts][k] = m_car_ftp_name[ts][k+1];
					}

					m_car_ftm[ts][50] = 0;
					m_car_ftp_id[ts][50] = 0;
					m_car_ftp_te[ts][50] = 0;
					m_car_ftp[ts][50] = 0;
					m_car_ftp_name[ts][50] = "";
				}
			}
			//end check





	int ra7 = 50;
		int slot7[16] = {51,51,51,51, 51,51,51,51, 51,51,51,51, 51,51,51,51};
			
		bool win7 = false;
		do
		{
			if(m_car_tgp[ts][ra7] == 6553.5) m_car_tgp[ts][ra7] = 0;
			if(t>=3 && (m_car_tgp[ts][ra7] == 0 || m_car_tgp_id[ts][ra7] == 0))
			{
				if(ts != 1 && ts != 2)
					m_car_tgp[ts][ra7] = 65535;
			}
			if(t>=3 && car_tgp <= m_car_tgp[ts][ra7])
			{
				slot7[0] = ra7;
				ra7 = ra7 - 1;
				win7 = true;
			}
			else if(t<3 && car_tgp >= m_car_tgp[ts][ra7] && (tgm_ok==true || ts>0))
			{
				slot7[0] = ra7;
				ra7 = ra7 - 1;
				win7 = true;
			}
			else
				win7 = false;

			if(ra7 == 0) win7 = false;//cant do better
		}
		while (win7 == true);


		if(slot7[0] <= 50)
		{
			for(int j=50; j>= slot7[0]+1; j--)
			{
				m_car_tgp_name[ts][j] = m_car_tgp_name[ts][j-1];
				m_car_tgp_id[ts][j] = m_car_tgp_id[ts][j-1];
				m_car_tgm[ts][j] = m_car_tgm[ts][j-1];
				m_car_tgp[ts][j] = m_car_tgp[ts][j-1];
				m_car_tgp_te[ts][j] = m_car_tgp_te[ts][j-1];
			}
			double ga = (double) m_actual[i].m_car_games;		
			double tgp = 0;
			if(ga > 0) tgp = (double)car_tgp;		

			int car_tgm = m_actual[i].m_car_tfgm;

			if(ts > 0) car_tgm = 0;

			m_car_tgm[ts][slot7[0]] = car_tgm;
			m_car_tgp[ts][slot7[0]] = tgp;
			m_car_tgp_id[ts][slot7[0]] = id;
			m_car_tgp_te[ts][slot7[0]] = te;
			m_car_tgp_name[ts][slot7[0]] = na;
		}
		
			//check for duplicate player
			for(int j=50; j >= 1; j--)
			{
			
				if(ts>0) continue;
				if(m_car_tgp_id[ts][slot7[0]] == m_car_tgp_id[ts][j] && slot7[0] != j)
				{
					for(int k=j; k <= 49; k++)
					{
						m_car_tgm[ts][k] = m_car_tgm[ts][k+1];
						m_car_tgp_id[ts][k] = m_car_tgp_id[ts][k+1];
						m_car_tgp[ts][k] = m_car_tgp[ts][k+1];
						m_car_tgp_te[ts][k] = m_car_tgp_te[ts][k+1];
						m_car_tgp_name[ts][k] = m_car_tgp_name[ts][k+1];
					}

					m_car_tgm[ts][50] = 0;
					m_car_tgp_id[ts][50] = 0;
					m_car_tgp_te[ts][50] = 0;
					m_car_tgp[ts][50] = 0;
					m_car_tgp_name[ts][50] = "";
				}
			}
			//end check

		}
	
	}
}

void CHigh::SetGameHighs(int p, int player_list[61], CPlayer m_actual[1601], int currentYear)
{

for(int i=1; i<=60; i++)
{

		CPlayer m_player = m_actual[player_list[i]];
		if(m_player.m_name == "") continue;
		CString na = m_player.m_pos + " " + m_player.m_name;
		int id = m_player.m_id;
		int yr = currentYear;
		int te = m_player.m_current_team + 1;


		for(int m=0; m<=1; m++)//season or career
		{

		for(int s=0; s<=7; s++)//stats
		{

		int pts = m_player.m_game_Fgm*2 + m_player.m_game_Tfgm*3 + m_player.m_game_Ftm;
		if(s==1) pts = m_player.m_game_Dreb + m_player.m_game_Oreb;
		else if(s==2) pts = m_player.m_game_Ast;
		else if(s==3) pts = m_player.m_game_Stl;
		else if(s==4) pts = m_player.m_game_Blk;
		else if(s==5) pts = m_player.m_game_Fgm + m_player.m_game_Tfgm;
		else if(s==6) pts = m_player.m_game_Tfgm;
		else if(s==7) pts = m_player.m_game_Ftm;
		

		for(int t=1; t<=2; t++)//2 times 2nd for team only
		{

			
	
		int ra = 9;
		int slot[16] = {11,11,11,11, 11,11,11,11, 11,11,11,11, 11,11,11,11};


		int ts=0;
		if(t==1) ts=te;
			
		bool win = false;
		do
		{

			if(p==0 && pts >= m_g_amt[m][ts][ra][s])
			{
				slot[0] = ra;
				ra = ra - 1;
				win = true;
			}
			else if(p==1 && pts >= m_g_po_amt[m][ts][ra][s])
			{
				slot[0] = ra;
				ra = ra - 1;
				win = true;
			}
			else
				win = false;

			if(ra == -1) win = false;//cant do better
		}
		while (win == true);


		if(slot[0] <= 9)
		{
			for(int j=9; j>= slot[0]+1; j--)
			{
				if(p==0)
				{
				m_g_name[m][ts][j][s] = m_g_name[m][ts][j-1][s];
				m_g_amt[m][ts][j][s] = m_g_amt[m][ts][j-1][s];
				m_g_id[m][ts][j][s] = m_g_id[m][ts][j-1][s];
				m_g_ye[m][ts][j][s] = m_g_ye[m][ts][j-1][s];
				}
				else
				{
				m_g_po_name[m][ts][j][s] = m_g_po_name[m][ts][j-1][s];
				m_g_po_amt[m][ts][j][s] = m_g_po_amt[m][ts][j-1][s];
				m_g_po_id[m][ts][j][s] = m_g_po_id[m][ts][j-1][s];
				m_g_po_ye[m][ts][j][s] = m_g_po_ye[m][ts][j-1][s];
				}

			}
			if(p==0)
			{
				m_g_name[m][ts][slot[0]][s] = na;
				m_g_amt[m][ts][slot[0]] [s]= pts;
				m_g_id[m][ts][slot[0]][s] = id;
				m_g_ye[m][ts][slot[0]][s] = yr;
			}
			else
			{
				m_g_po_name[m][ts][slot[0]][s] = na;
				m_g_po_amt[m][ts][slot[0]][s]= pts;
				m_g_po_id[m][ts][slot[0]][s] = id;
				m_g_po_ye[m][ts][slot[0]][s] = yr;
			}

		}
		
		}
		}
		}

	
}
}

void CHigh::ClearSeasonHighs(int d1, int d2)
{
	//d1 = 1, season
	//d2 = 2, career
	for(int i=d1; i<=d2; i++)
	{
		for(int j=0; j<=32; j++)
		{
			for(int k=0; k<=9; k++)
			{
				for(int l=0; l<=7; l++)
				{

					m_g_po_name[i][j][k][l] = "";
					m_g_po_amt[i][j][k][l] = 0;
					m_g_po_id[i][j][k][l] = 0;
					m_g_po_ye[i][j][k][l] = 0;

					m_g_name[i][j][k][l] = "";
					m_g_amt[i][j][k][l] = 0;
					m_g_id[i][j][k][l] = 0;
					m_g_ye[i][j][k][l] = 0;
				}
			}
		}
	}

}
