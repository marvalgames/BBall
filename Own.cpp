#include "stdafx.h"
#ifndef Own_h
#include "Own.h"
#define Own_h
#endif 










void COwn::InitOwnData()
{
	for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					m_draft_chart[y][r][p] = p;
				}
			}
		}
	
}

void COwn::WriteOwnData(CString file_name)
{
CFile file(	file_name, CFile::modeWrite);
CString buffer;

	for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					
					int i = m_draft_chart[y][r][p];
					if(y==0 || r==0) i=0;
					buffer.Format("%d", i);
					buffer = buffer + "  ";
					file.Write( buffer, 2);


				}
			}
		}

	

file.Close();	
}

void COwn::ReadOwnData(CString file_name, int numberteams)
{
 CFile file( file_name, CFile::modeRead);
	char s[33];
	int bytes = 0;

		for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{

					int bytes = file.Read(s, 2);
					s[bytes] = 0;
					int i = atoi(s);
					if(p > numberteams) i=0;
					m_draft_chart[y][r][p] = i;
				}
			}
		}

			for(int i=0; i<=96; i++)
			{
				int bytes = file.Read(s, 2);
				s[bytes] = 0;
				int j = atoi(s);
			}
		
	file.Close();
	
}

//void COwn::SetDraftChart(int trading_team)
//{
//	for(int i=1; i<=m_number_proposed_picks; i++)
//	{
//		int n = m_proposed_picks[i];
//		int y = n / 1000;
//		int r = (n - y*1000) / 100;
//		int p = n - (y*1000 + r*100);
//		m_draft_chart[y][r][p] = trading_team;
//	}
//
//}

int COwn::SetDraftPickAddition(int index, double avg_tru, double team_avg_tru, int *win, int *loss, double* pct, int hi_g)
{
	int pick = m_actual_picks[index];



	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);
	double tru_f = avg_tru + (team_avg_tru - avg_tru)*2;
	if(tru_f < 2) tru_f = 2;

	double ro = (double)r;
	if(r==2) ro = (double)3;
	double rating = avg_tru / tru_f / ro * (4/(3+(double)y));


	int total_g = win[p-1] + loss[p-1];
	double percent = pct[p-1];

	double f = (double)total_g / (double)hi_g;
	if(f > 1) f=1;
	double nu = rating*(f*(1-percent)*2) + rating*(1-f);
	if(nu > 2) nu=2;

	double pick_value = nu * avg_tru;
	m_draft_pick_addition = pick_value;
	return y;
}

void COwn::SetEndOfSeasonDraftChart()
{
	for(int y=1; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					if(y==3)
						m_draft_chart[y][r][p] = p;
					else
						m_draft_chart[y][r][p] = m_draft_chart[y+1][r][p];

				}
			}
		}
}

