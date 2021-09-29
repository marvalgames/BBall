
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 




#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

class CHigh: public CObject
{

private:
	void WriteHighs(CString name, int amount, int m_team, int rank, int stat);


public:
	void ClearSeasonHighs(int d1, int d2);
	void SetGameHighs(int p, int player_list[61], CPlayer m_actual[1601], int currentYear);

	void SetAllTimeSeasonHighs(CPlayer m_actual[1601], int currentYear, int games_in_season);
	//CAverage avg;
	int m_offset;
	void OpenAllHighs(CString file_name);

	CString m_g_name[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_amt[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_id[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_ye[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)

	CString m_g_po_name[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_po_amt[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_po_id[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)
	int m_g_po_ye[2][33][10][8];//all 0 based season/career, team, rank, stat (0-7, 0 pts 1 reb etc.)


	int m_team1;
	int m_team2;

	CString m_ppg_name[33][51];
	double m_ppg[33][51];//team, rank
	int m_ppg_id[33][51];
	int m_ppg_te[33][51];
	int m_ppg_ye[33][51];

	CString m_car_ppg_name[33][51];
	double m_car_ppg[33][51];//team, rank
	int m_car_pts[33][51];//team, rank
	int m_car_ppg_id[33][51];
	int m_car_ppg_te[33][51];



	CString m_rpg_name[33][51];
	double m_rpg[33][51];//team, rank
	int m_rpg_id[33][51];
	int m_rpg_te[33][51];
	int m_rpg_ye[33][51];

	CString m_car_rpg_name[33][51];
	double m_car_rpg[33][51];//team, rank
	int m_car_reb[33][51];//team, rank
	int m_car_rpg_id[33][51];
	int m_car_rpg_te[33][51];


	CString m_apg_name[33][51];
	double m_apg[33][51];//team, rank
	int m_apg_id[33][51];
	int m_apg_te[33][51];
	int m_apg_ye[33][51];

	CString m_car_apg_name[33][51];
	double m_car_apg[33][51];//team, rank
	int m_car_ast[33][51];//team, rank
	int m_car_apg_id[33][51];
	int m_car_apg_te[33][51];

	CString m_spg_name[33][51];
	double m_spg[33][51];//team, rank
	int m_spg_id[33][51];
	int m_spg_te[33][51];
	int m_spg_ye[33][51];

	CString m_car_spg_name[33][51];
	double m_car_spg[33][51];//team, rank
	int m_car_stl[33][51];//team, rank
	int m_car_spg_id[33][51];
	int m_car_spg_te[33][51];


	CString m_bpg_name[33][51];
	double m_bpg[33][51];//team, rank
	int m_bpg_id[33][51];
	int m_bpg_te[33][51];
	int m_bpg_ye[33][51];

	CString m_car_bpg_name[33][51];
	double m_car_bpg[33][51];//team, rank
	int m_car_blk[33][51];//team, rank
	int m_car_bpg_id[33][51];
	int m_car_bpg_te[33][51];

	CString m_fgp_name[33][51];
	double m_fgp[33][51];//team, rank
	int m_fgp_id[33][51];
	int m_fgp_te[33][51];
	int m_fgp_ye[33][51];

	CString m_car_fgp_name[33][51];
	double m_car_fgp[33][51];//team, rank
	int m_car_fgm[33][51];//team, rank
	int m_car_fgp_id[33][51];
	int m_car_fgp_te[33][51];

	CString m_ftp_name[33][51];
	double m_ftp[33][51];//team, rank
	int m_ftp_id[33][51];
	int m_ftp_te[33][51];
	int m_ftp_ye[33][51];

	CString m_car_ftp_name[33][51];
	double m_car_ftp[33][51];//team, rank
	int m_car_ftm[33][51];//team, rank
	int m_car_ftp_id[33][51];
	int m_car_ftp_te[33][51];

	CString m_tgp_name[33][51];
	double m_tgp[33][51];//team, rank
	int m_tgp_id[33][51];
	int m_tgp_te[33][51];
	int m_tgp_ye[33][51];

	CString m_car_tgp_name[33][51];
	double m_car_tgp[33][51];//team, rank
	int m_car_tgm[33][51];//team, rank
	int m_car_tgp_id[33][51];
	int m_car_tgp_te[33][51];





	CString m_fileName;
	void OpenHighs(CString file_name);
	CHigh();
	~CHigh();

	CHigh( const CHigh& a ) 
	{ 
	for(int i=0; i<=32; i++)
	{
		for(int j=0; j<=50; j++)
		{
				m_ppg_name[i][j] = a.m_ppg_name[i][j];
				m_ppg[i][j] = a.m_ppg[i][j];
				m_ppg_id[i][j] = a.m_ppg_id[i][j];
				m_ppg_te[i][j] = a.m_ppg_te[i][j];
				m_ppg_ye[i][j] = a.m_ppg_ye[i][j];

			
				m_car_ppg_name[i][j] = a.m_car_ppg_name[i][j];
				m_car_ppg[i][j] = a.m_car_ppg[i][j];
				m_car_pts[i][j] = a.m_car_pts[i][j];
				m_car_ppg_id[i][j] = a.m_car_ppg_id[i][j];
				m_car_ppg_te[i][j] = a.m_car_ppg_te[i][j];


				


				m_rpg_name[i][j] = a.m_rpg_name[i][j];
				m_rpg[i][j] = a.m_rpg[i][j];
				m_rpg_id[i][j] = a.m_rpg_id[i][j];
				m_rpg_te[i][j] = a.m_rpg_te[i][j];
				m_rpg_ye[i][j] = a.m_rpg_ye[i][j];

			
				m_car_rpg_name[i][j] = a.m_car_rpg_name[i][j];
				m_car_rpg[i][j] = a.m_car_rpg[i][j];
				m_car_reb[i][j] = a.m_car_reb[i][j];
				m_car_rpg_id[i][j] = a.m_car_rpg_id[i][j];
				m_car_rpg_te[i][j] = a.m_car_rpg_te[i][j];


				
				m_apg_name[i][j] = a.m_apg_name[i][j];
				m_apg[i][j] = a.m_apg[i][j];
				m_apg_id[i][j] = a.m_apg_id[i][j];
				m_apg_te[i][j] = a.m_apg_te[i][j];
				m_apg_ye[i][j] = a.m_apg_ye[i][j];

			
				m_car_apg_name[i][j] = a.m_car_apg_name[i][j];
				m_car_apg[i][j] = a.m_car_apg[i][j];
				m_car_ast[i][j] = a.m_car_ast[i][j];
				m_car_apg_id[i][j] = a.m_car_apg_id[i][j];
				m_car_apg_te[i][j] = a.m_car_apg_te[i][j];

			
				m_spg_name[i][j] = a.m_spg_name[i][j];
				m_spg[i][j] = a.m_spg[i][j];
				m_spg_id[i][j] = a.m_spg_id[i][j];
				m_spg_te[i][j] = a.m_spg_te[i][j];
				m_spg_ye[i][j] = a.m_spg_ye[i][j];

			
				m_car_spg_name[i][j] = a.m_car_spg_name[i][j];
				m_car_spg[i][j] = a.m_car_spg[i][j];
				m_car_stl[i][j] = a.m_car_stl[i][j];
				m_car_spg_id[i][j] = a.m_car_spg_id[i][j];
				m_car_spg_te[i][j] = a.m_car_spg_te[i][j];

			
				m_bpg_name[i][j] = a.m_bpg_name[i][j];
				m_bpg[i][j] = a.m_bpg[i][j];
				m_bpg_id[i][j] = a.m_bpg_id[i][j];
				m_bpg_te[i][j] = a.m_bpg_te[i][j];
				m_bpg_ye[i][j] = a.m_bpg_ye[i][j];

			
				m_car_bpg_name[i][j] = a.m_car_bpg_name[i][j];
				m_car_bpg[i][j] = a.m_car_bpg[i][j];
				m_car_blk[i][j] = a.m_car_blk[i][j];
				m_car_bpg_id[i][j] = a.m_car_bpg_id[i][j];
				m_car_bpg_te[i][j] = a.m_car_bpg_te[i][j];


			
				m_fgp_name[i][j] = a.m_fgp_name[i][j];
				m_fgp[i][j] = a.m_fgp[i][j];
				m_fgp_id[i][j] = a.m_fgp_id[i][j];
				m_fgp_te[i][j] = a.m_fgp_te[i][j];
				m_fgp_ye[i][j] = a.m_fgp_ye[i][j];

			
				m_car_fgp_name[i][j] = a.m_car_fgp_name[i][j];
				m_car_fgp[i][j] = a.m_car_fgp[i][j];
				m_car_fgm[i][j] = a.m_car_fgm[i][j];
				m_car_fgp_id[i][j] = a.m_car_fgp_id[i][j];
				m_car_fgp_te[i][j] = a.m_car_fgp_te[i][j];


			
				m_ftp_name[i][j] = a.m_ftp_name[i][j];
				m_ftp[i][j] = a.m_ftp[i][j];
				m_ftp_id[i][j] = a.m_ftp_id[i][j];
				m_ftp_te[i][j] = a.m_ftp_te[i][j];
				m_ftp_ye[i][j] = a.m_ftp_ye[i][j];

				m_car_ftp_name[i][j] = a.m_car_ftp_name[i][j];
				m_car_ftp[i][j] = a.m_car_ftp[i][j];
				m_car_ftm[i][j] = a.m_car_ftm[i][j];
				m_car_ftp_id[i][j] = a.m_car_ftp_id[i][j];
				m_car_ftp_te[i][j] = a.m_car_ftp_te[i][j];


				

				m_tgp_name[i][j] = a.m_tgp_name[i][j];
				m_tgp[i][j] = a.m_tgp[i][j];
				m_tgp_id[i][j] = a.m_tgp_id[i][j];
				m_tgp_te[i][j] = a.m_tgp_te[i][j];
				m_tgp_ye[i][j] = a.m_tgp_ye[i][j];

			
				m_car_tgp_name[i][j] = a.m_car_tgp_name[i][j];
				m_car_tgp[i][j] = a.m_car_tgp[i][j];
				m_car_tgm[i][j] = a.m_car_tgm[i][j];
				m_car_tgp_id[i][j] = a.m_car_tgp_id[i][j];
				m_car_tgp_te[i][j] = a.m_car_tgp_te[i][j];



			

			
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

					m_g_po_name[i][j][k][l] = a.m_g_po_name[i][j][k][l];
					m_g_po_amt[i][j][k][l] = a.m_g_po_amt[i][j][k][l];
					m_g_po_id[i][j][k][l] = a.m_g_po_id[i][j][k][l];
					m_g_po_ye[i][j][k][l] = a.m_g_po_ye[i][j][k][l];

					m_g_name[i][j][k][l] = a.m_g_name[i][j][k][l];
					m_g_amt[i][j][k][l] = a.m_g_amt[i][j][k][l];
					m_g_id[i][j][k][l] = a.m_g_id[i][j][k][l];
					m_g_ye[i][j][k][l] = a.m_g_ye[i][j][k][l];
				}
			}
		}
	}



	}

	const CHigh& operator=( const CHigh& a )
    {
	for(int i=0; i<=32; i++)
	{
		for(int j=0; j<=50; j++)
		{
				m_ppg_name[i][j] = a.m_ppg_name[i][j];
				m_ppg[i][j] = a.m_ppg[i][j];
				m_ppg_id[i][j] = a.m_ppg_id[i][j];
				m_ppg_te[i][j] = a.m_ppg_te[i][j];
				m_ppg_ye[i][j] = a.m_ppg_ye[i][j];

			
				m_car_ppg_name[i][j] = a.m_car_ppg_name[i][j];
				m_car_ppg[i][j] = a.m_car_ppg[i][j];
				m_car_pts[i][j] = a.m_car_pts[i][j];
				m_car_ppg_id[i][j] = a.m_car_ppg_id[i][j];
				m_car_ppg_te[i][j] = a.m_car_ppg_te[i][j];


				


				m_rpg_name[i][j] = a.m_rpg_name[i][j];
				m_rpg[i][j] = a.m_rpg[i][j];
				m_rpg_id[i][j] = a.m_rpg_id[i][j];
				m_rpg_te[i][j] = a.m_rpg_te[i][j];
				m_rpg_ye[i][j] = a.m_rpg_ye[i][j];

			
				m_car_rpg_name[i][j] = a.m_car_rpg_name[i][j];
				m_car_rpg[i][j] = a.m_car_rpg[i][j];
				m_car_reb[i][j] = a.m_car_reb[i][j];
				m_car_rpg_id[i][j] = a.m_car_rpg_id[i][j];
				m_car_rpg_te[i][j] = a.m_car_rpg_te[i][j];


				
				m_apg_name[i][j] = a.m_apg_name[i][j];
				m_apg[i][j] = a.m_apg[i][j];
				m_apg_id[i][j] = a.m_apg_id[i][j];
				m_apg_te[i][j] = a.m_apg_te[i][j];
				m_apg_ye[i][j] = a.m_apg_ye[i][j];

			
				m_car_apg_name[i][j] = a.m_car_apg_name[i][j];
				m_car_apg[i][j] = a.m_car_apg[i][j];
				m_car_ast[i][j] = a.m_car_ast[i][j];
				m_car_apg_id[i][j] = a.m_car_apg_id[i][j];
				m_car_apg_te[i][j] = a.m_car_apg_te[i][j];

			
				m_spg_name[i][j] = a.m_spg_name[i][j];
				m_spg[i][j] = a.m_spg[i][j];
				m_spg_id[i][j] = a.m_spg_id[i][j];
				m_spg_te[i][j] = a.m_spg_te[i][j];
				m_spg_ye[i][j] = a.m_spg_ye[i][j];

			
				m_car_spg_name[i][j] = a.m_car_spg_name[i][j];
				m_car_spg[i][j] = a.m_car_spg[i][j];
				m_car_stl[i][j] = a.m_car_stl[i][j];
				m_car_spg_id[i][j] = a.m_car_spg_id[i][j];
				m_car_spg_te[i][j] = a.m_car_spg_te[i][j];

			
				m_bpg_name[i][j] = a.m_bpg_name[i][j];
				m_bpg[i][j] = a.m_bpg[i][j];
				m_bpg_id[i][j] = a.m_bpg_id[i][j];
				m_bpg_te[i][j] = a.m_bpg_te[i][j];
				m_bpg_ye[i][j] = a.m_bpg_ye[i][j];

			
				m_car_bpg_name[i][j] = a.m_car_bpg_name[i][j];
				m_car_bpg[i][j] = a.m_car_bpg[i][j];
				m_car_blk[i][j] = a.m_car_blk[i][j];
				m_car_bpg_id[i][j] = a.m_car_bpg_id[i][j];
				m_car_bpg_te[i][j] = a.m_car_bpg_te[i][j];


			
				m_fgp_name[i][j] = a.m_fgp_name[i][j];
				m_fgp[i][j] = a.m_fgp[i][j];
				m_fgp_id[i][j] = a.m_fgp_id[i][j];
				m_fgp_te[i][j] = a.m_fgp_te[i][j];
				m_fgp_ye[i][j] = a.m_fgp_ye[i][j];

			
				m_car_fgp_name[i][j] = a.m_car_fgp_name[i][j];
				m_car_fgp[i][j] = a.m_car_fgp[i][j];
				m_car_fgm[i][j] = a.m_car_fgm[i][j];
				m_car_fgp_id[i][j] = a.m_car_fgp_id[i][j];
				m_car_fgp_te[i][j] = a.m_car_fgp_te[i][j];


			
				m_ftp_name[i][j] = a.m_ftp_name[i][j];
				m_ftp[i][j] = a.m_ftp[i][j];
				m_ftp_id[i][j] = a.m_ftp_id[i][j];
				m_ftp_te[i][j] = a.m_ftp_te[i][j];
				m_ftp_ye[i][j] = a.m_ftp_ye[i][j];

				m_car_ftp_name[i][j] = a.m_car_ftp_name[i][j];
				m_car_ftp[i][j] = a.m_car_ftp[i][j];
				m_car_ftm[i][j] = a.m_car_ftm[i][j];
				m_car_ftp_id[i][j] = a.m_car_ftp_id[i][j];
				m_car_ftp_te[i][j] = a.m_car_ftp_te[i][j];


				

				m_tgp_name[i][j] = a.m_tgp_name[i][j];
				m_tgp[i][j] = a.m_tgp[i][j];
				m_tgp_id[i][j] = a.m_tgp_id[i][j];
				m_tgp_te[i][j] = a.m_tgp_te[i][j];
				m_tgp_ye[i][j] = a.m_tgp_ye[i][j];

			
				m_car_tgp_name[i][j] = a.m_car_tgp_name[i][j];
				m_car_tgp[i][j] = a.m_car_tgp[i][j];
				m_car_tgm[i][j] = a.m_car_tgm[i][j];
				m_car_tgp_id[i][j] = a.m_car_tgp_id[i][j];
				m_car_tgp_te[i][j] = a.m_car_tgp_te[i][j];



			

			
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

					m_g_name[i][j][k][l] = a.m_g_name[i][j][k][l];
					m_g_amt[i][j][k][l] = a.m_g_amt[i][j][k][l];
					m_g_id[i][j][k][l] = a.m_g_id[i][j][k][l];
					m_g_ye[i][j][k][l] = a.m_g_ye[i][j][k][l];

					m_g_po_name[i][j][k][l] = a.m_g_po_name[i][j][k][l];
					m_g_po_amt[i][j][k][l] = a.m_g_po_amt[i][j][k][l];
					m_g_po_id[i][j][k][l] = a.m_g_po_id[i][j][k][l];
					m_g_po_ye[i][j][k][l] = a.m_g_po_ye[i][j][k][l];

				}
			}
		}
	}


	return *this;
	}

};