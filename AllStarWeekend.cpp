#include "stdafx.h"
//#include "constants.h"
//#include "bball.h"
#ifndef bball_h
#include "bball.h"
#define bball_h
#endif 
//#include "constants.h"
//#include "resource.h"

#ifndef AllStarWeekend_h
#include "AllStarWeekend.h"	// Added by ClassView
#define AllStarWeekend_h
#endif

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

CAllStarWeekend::CAllStarWeekend()
{
	m_actual = new CPlayer[81];
	srand( (unsigned)time( NULL ) );
	for(int i=0; i<=30; i++)
	{

		m_scores[i] = 0;
	}


}

CAllStarWeekend::~CAllStarWeekend()
{
	delete [] m_actual;
}



void CAllStarWeekend::SelectAllStarTeams()
{
	
	CString con1 = avg.m_settings.m_conferenceName1;
	CString con2 = avg.m_settings.m_conferenceName2;

	if(con2 == "") con2 = con1;
	











	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".asw";

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == TRUE) 
	{
  		CStdioFile file(file_name, CFile::modeRead);
		CString str;
		for(int i = 0; i<=30; i++)
		{
			file.ReadString(str);
			str.TrimRight();
			CString na = str.Mid(0, 6);
			int index = atoi(na);

			int offset = i;
			if(i > 15) offset = i+15;
			for(int j=1; j<=1440; j++)
			{
				if(avg.m_actual[j].m_id == index && avg.m_actual[j].m_name != "") 
					m_actual[offset] = avg.m_actual[j];
			}

		}

	}
	else
	{

	for(int i=1; i<=960; i++)
	{
		double n1 = (double)(avg.m_actual[i].m_sim_fgm * 2 + avg.m_actual[i].m_sim_tfgm * 3 + avg.m_actual[i].m_sim_ftm + avg.m_actual[i].m_sim_oreb + avg.m_actual[i].m_sim_reb + avg.m_actual[i].m_sim_ast + avg.m_actual[i].m_sim_stl + avg.m_actual[i].m_sim_blk)  * (100 + avg.m_actual[i].m_age) / 128;//128 used for age factor
		for(int j=1; j<=960; j++)
		{
			if(avg.m_actual[i].m_name == "" || avg.m_actual[j].m_name == "") continue;
			double n2 = (double)(avg.m_actual[j].m_sim_fgm * 2 + avg.m_actual[j].m_sim_tfgm * 3 + avg.m_actual[j].m_sim_ftm + avg.m_actual[j].m_sim_oreb + avg.m_actual[j].m_sim_reb + avg.m_actual[j].m_sim_ast + avg.m_actual[j].m_sim_stl + avg.m_actual[j].m_sim_blk)  * (100 + avg.m_actual[j].m_age) / 128;
			if(n1 > n2)
			{
					CPlayer temp = avg.m_actual[i];
					avg.m_actual[i] =  avg.m_actual[j];
					avg.m_actual[j] = temp;
			}
		}
	}
	


	int c1=1, c2=31;//get first 10 of each

	bool selected[121];
	for(int i=0; i<=120; i++)
	{
		selected[i] = false;
	}

for(int t=1; t<=6; t++)
{

	for(int i=1; i<=120; i++)
	{
		int t1 = avg.m_actual[i].m_current_team;
		CString pos = avg.m_actual[i].m_pos;
		int po = 1;
		if(pos == "SG") po = 2;
		else if(pos == "SF") po = 3;
		else if(pos == "PF") po = 4;
		else if(pos == " C") po = 5;
		if(t==6) po=6; //position check enabled for last 2 slots
		
		CString con;
		if(t1 >= 0)
		{
			con = avg.m_standings[t1].m_conference;
			if(con == con1 && c1 <= t*2 && t==po && selected[i] == false && avg.m_actual[i].m_name != "")
			{
				m_actual[c1] = avg.m_actual[i];
				selected[i] = true;
				c1 = c1 + 1;
			}
			else if(con == con2 && c2 <= 30+t*2 && t==po && selected[i] == false && avg.m_actual[i].m_name != "")
			{
				m_actual[c2] = avg.m_actual[i];
				selected[i] = true;
				c2 = c2 + 1;
			}
		}

	}
}

	}
}

void CAllStarWeekend::SelectRookieTeams()
{
	CString con1 = avg.m_settings.m_conferenceName1;
	CString con2 = avg.m_settings.m_conferenceName2;
	if(con2 == "") con2 = con1;




	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".asw";

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == TRUE) 
	{
  		CStdioFile file(file_name, CFile::modeRead);
		CString str;

		for(int i = 0; i<=30; i++)
		{
			file.ReadString(str);
		}


		for(int i = 1; i<=30; i++)
		{
			file.ReadString(str);
			str.TrimRight();
			CString na = str.Mid(0, 6);
			int index = atoi(na);

			int offset = i;
			if(i > 15) offset = i+15;
			for(int j=1; j<=1440; j++)
			{
				if(avg.m_actual[j].m_id == index && avg.m_actual[j].m_name != "") 
					m_actual[offset] = avg.m_actual[j];
			}

		}

	}
	else
	{



	bool valid = true;
	int r1 = 0, s1 = 0;
	do
	{

	r1 = 0;
	s1 = 0;
	for(int i=1; i<=960; i++)
	{
		double n1 = 0;
		int yrs_i = 0;

		if(valid == true && avg.m_actual[i].m_name != "")
		{
			n1 = (double)(avg.m_actual[i].m_sim_fgm * 2 + avg.m_actual[i].m_sim_tfgm * 3 + avg.m_actual[i].m_sim_ftm + avg.m_actual[i].m_sim_oreb + avg.m_actual[i].m_sim_reb + avg.m_actual[i].m_sim_ast + avg.m_actual[i].m_sim_stl + avg.m_actual[i].m_sim_blk);
			yrs_i = avg.m_actual[i].m_yrs_of_service;
			if(yrs_i == 1 || yrs_i == 2) n1=n1+20000.*(3.-(double)yrs_i);//20000 insures ranked higher for rookies
			if(yrs_i == 1) r1 = r1 + 1;
			if(yrs_i == 2) s1 = s1 + 1;
		}
		else if(avg.m_actual[i].m_name != "")
		{
			n1 = ((double)avg.m_actual[i].m_sim_stl + (double)avg.m_actual[i].m_sim_blk) * 4
					+ double(avg.m_actual[i].m_pendef) + double(avg.m_actual[i].m_movdef) + double(avg.m_actual[i].m_postdef) + double(avg.m_actual[i].m_movdef)/2;

			r1 = r1 + 1;
			s1 = s1 + 1;

		}

		for(int j=1; j<=960; j++)
		{
			if(avg.m_actual[i].m_name == "" || avg.m_actual[j].m_name == "") continue;

			double n2 = 0;

			if(valid == true)
			{
				n2 = (double)(avg.m_actual[j].m_sim_fgm * 2 + avg.m_actual[j].m_sim_tfgm * 3 + avg.m_actual[j].m_sim_ftm + avg.m_actual[j].m_sim_oreb + avg.m_actual[j].m_sim_reb + avg.m_actual[j].m_sim_ast + avg.m_actual[j].m_sim_stl + avg.m_actual[j].m_sim_blk);
				int yrs_j = avg.m_actual[j].m_yrs_of_service;
				if(yrs_j == 1 || yrs_j == 2) n2=n2+20000.*(3.-(double)yrs_j);//20000 insures ranked higher for rookies
//				if(yrs_j == 1) r1 = r1 + 1;
//				if(yrs_j == 2) s1 = s1 + 1;
				if(n1 > n2)
				{
					CPlayer temp = avg.m_actual[i];
					avg.m_actual[i] =  avg.m_actual[j];
					avg.m_actual[j] = temp;
				}
			}
			else 
			{
				n2 = ((double)avg.m_actual[j].m_sim_stl + (double)avg.m_actual[j].m_sim_blk) * 4
					+ double(avg.m_actual[j].m_pendef) + double(avg.m_actual[j].m_movdef) + double(avg.m_actual[j].m_postdef) + double(avg.m_actual[j].m_movdef)/2;
				if(n1 > n2)
				{
					CPlayer temp = avg.m_actual[i];
					avg.m_actual[i] =  avg.m_actual[j];
					avg.m_actual[j] = temp;
				}
			}


		}
	}

	if (r1 < 9 || s1 < 9) valid = false;


	}
	while (r1 < 9 || s1 < 9);



	

	int c1=1, c2=31;//get first 10 of each
for(int t=1; t<=5; t++)
{



	for(int i=1; i<=960; i++)
	{
		int t1 = avg.m_actual[i].m_yrs_of_service;
		CString con;


		if(valid == false)
		{
			t1 = avg.m_actual[i].m_current_team;
			if(t1 >= 0)
			{
				con = avg.m_standings[t1].m_conference;
			}
		}



		CString pos = avg.m_actual[i].m_pos;
		int po = 1;
		if(pos == "SG") po = 2;
		else if(pos == "SF") po = 3;
		else if(pos == "PF") po = 4;
		else if(pos == " C") po = 5;
		


		if(t1 == 1 && c1 <= t*2 && po == t && valid == true && avg.m_actual[i].m_name != "")
		{
				m_actual[c1] = avg.m_actual[i];
				c1 = c1 + 1;
		}
		else if(t1 == 2 && c2 <= 30+t*2 && po == t && valid == true && avg.m_actual[i].m_name != "")
		{
				m_actual[c2] = avg.m_actual[i];
				c2 = c2 + 1;
		}
		else if(c1 <= t*2 && po == t && valid == false && con==con1 && avg.m_actual[i].m_name != "")
		{
				m_actual[c1] = avg.m_actual[i];
				c1 = c1 + 1;
		}
		else if(c2 <= 30+t*2 && po == t && valid == false && con==con2 && avg.m_actual[i].m_name != "")
		{
				m_actual[c2] = avg.m_actual[i];
				c2 = c2 + 1;
		}
		

	}
}

if(valid == false) 
{
	HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
	int res = MessageBox(hWnd, "This Year the All Defense Game will replace the Rookie/Soph Game", "Defenders of the Basketball Universe", MB_OK);
}

}
}

void CAllStarWeekend::SelectThreePointContestants()
{

	
	for(int i=1; i<=960; i++)
	{
		avg.m_actual[i].SetAswScores();		

	}

	for(int i=0; i<=960; i++)
	{

		for(int j=0; j<=i; j++)
		{
		
			if(avg.m_actual[i].m_name == "" ||
				avg.m_actual[i].m_active == 0 ||
				avg.m_actual[i].m_injury > 0 ||
				avg.m_actual[j].m_name == "" ||
				avg.m_actual[j].m_active == 0 ||
				avg.m_actual[j].m_injury > 0) continue;


			if(avg.m_actual[i].m_3ptscore[0] > avg.m_actual[j].m_3ptscore[0])
			{
					CPlayer temp = avg.m_actual[i];
					avg.m_actual[i] =  avg.m_actual[j];
					avg.m_actual[j] = temp;
			}
		}
	}	

	for(int i=1; i<=8; i++)
	{
				m_actual[60+i] = avg.m_actual[i];
	}


}

void CAllStarWeekend::SelectDunkContestants()
{




	for(int i=1; i<=960; i++)
	{

		for(int j=1; j<=960; j++)
		{
			if(avg.m_actual[i].m_name == "" ||
				avg.m_actual[i].m_active == 0 ||
				avg.m_actual[i].m_injury > 0 ||

				avg.m_actual[j].m_name == "" ||
				avg.m_actual[j].m_active == 0 ||
				avg.m_actual[j].m_injury > 0) continue;

			if(avg.m_actual[i].m_dunkscore[0] > avg.m_actual[j].m_dunkscore[0])
			{
					CPlayer temp = avg.m_actual[i];
					avg.m_actual[i] =  avg.m_actual[j];
					avg.m_actual[j] = temp;
			}
		}
	}	

	for(int i=1; i<=8; i++)
	{
			m_actual[70+i] = avg.m_actual[i];
	}

}

void CAllStarWeekend::SimThreePointContestRoundOne()
{
	for(int i=1; i<=8; i++)
	{

		double n1 = (double)(avg.m_actual[i].m_sim_tfgm);
		double n2 = n1 / (double)(avg.m_actual[i].m_sim_tfga);
		n1 = n1*n2* (1+ (double)avg.m_actual[i].m_prTga/100);

		double f = ((double) m_actual[60+i].m_prTga * ((double) m_actual[60+i].m_prTgp / 50)) / (double) 120;

		for(int s=1; s<=25; s++)
		{
			double r = avg.Random(1);
			if( r<= f)
			{
				m_actual[60+i].m_3ptscore[1] = m_actual[60+i].m_3ptscore[1] + 1;
				if(s >= 21)	m_actual[60+i].m_3ptscore[1] = m_actual[60+i].m_3ptscore[1] + 1;//money ball
			}
		}
	}



	for(int i=61; i<=68; i++)
	{
		int n1 = m_actual[i].m_3ptscore[1];
//		m_scores[i-45] = n1;
//
		for(int j=61; j<=68; j++)
		{

			int n2 = m_actual[j].m_3ptscore[1];
			if(n1 > n2)
			{
					CPlayer temp = m_actual[i];
					m_actual[i] =  m_actual[j];
					m_actual[j] = temp;
			}
		}
	}	


	for(int i=61; i<=68; i++)
	{
		int n1 = m_actual[i].m_3ptscore[1];

		m_scores[i-45] = n1;
	}


}

void CAllStarWeekend::SimThreePointContestRoundTwo()
{
	for(int i=1; i<=4; i++)
	{
		double f = ((double) m_actual[60+i].m_prTga * ((double) m_actual[60+i].m_prTgp / 50)) / (double) 120;
		for(int s=1; s<=25; s++)
		{
			double r = avg.Random(1);
			if( r<= f)
			{
				m_actual[60+i].m_3ptscore[2] = m_actual[60+i].m_3ptscore[2] + 1;
				if(s >= 21)
					m_actual[60+i].m_3ptscore[2] = m_actual[60+i].m_3ptscore[2] + 1;//money ball
			}
		}
	}



	for(int i=61; i<=64; i++)
	{
		int n1 = m_actual[i].m_3ptscore[2];
//		m_scores[i-37] = n1;

		for(int j=61; j<=64; j++)
		{

			int n2 = m_actual[j].m_3ptscore[2];
			if(n1 > n2)
			{
					CPlayer temp = m_actual[i];
					m_actual[i] =  m_actual[j];
					m_actual[j] = temp;
			}
		}
	}	


	for(int i=61; i<=64; i++)
	{
		int n1 = m_actual[i].m_3ptscore[2];

		m_scores[i-37] = n1;
	}

}

void CAllStarWeekend::SimThreePointContestRoundThree()
{
	for(int i=1; i<=2; i++)
	{
		double f = ((double) m_actual[60+i].m_prTga * ((double) m_actual[60+i].m_prTgp / 50)) / (double) 120;
		for(int s=1; s<=25; s++)
		{
			double r = avg.Random(1);
			if( r<= f)
			{
				m_actual[60+i].m_3ptscore[3] = m_actual[60+i].m_3ptscore[3] + 1;
				if(s >= 21)	m_actual[60+i].m_3ptscore[3] = m_actual[60+i].m_3ptscore[3] + 1;//money ball
			}
		}
	}



	for(int i=61; i<=62; i++)
	{
		int n1 = m_actual[i].m_3ptscore[3];

		for(int j=61; j<=62; j++)
		{

			int n2 = m_actual[j].m_3ptscore[3];
			if(n1 > n2)
			{
					CPlayer temp = m_actual[i];
					m_actual[i] =  m_actual[j];
					m_actual[j] = temp;
			}
		}
	}	


	for(int i=61; i<=62; i++)
	{
		int n1 = m_actual[i].m_3ptscore[3];

		m_scores[i-33] = n1;
	}

}

void CAllStarWeekend::SimSlamDunkContestRoundOne()
{
	for(int i=1; i<=8; i++)
	{
		m_actual[70+i].m_dunkscore[1] = 60;


		double f = (double)(m_actual[70+i].m_prFta) / (double)(m_actual[70+i].m_prFga);
		f = f + (double)(avg.m_actual[70+i].m_prOrb) / (double)(m_actual[70+i].m_prDrb) + ((double)(m_actual[70+i].m_transoff) + (double)m_actual[70+i].m_transdef)/10.;

		if(f > 3.6) f=3.6 + f/10;

		for(int s=1; s<=50; s++)
		{
			double r = avg.Random(6);
			if( r<= f)
			{
				m_actual[70+i].m_dunkscore[1] = m_actual[70+i].m_dunkscore[1] + 1;
			}
		}

		m_actual[70+i].m_dunkscore[1] = m_actual[70+i].m_dunkscore[1]*10 + avg.IntRandom(10);
		if(m_actual[70+i].m_dunkscore[1] > 1000) m_actual[70+i].m_dunkscore[1] = 1000;
	}




	for(int i=71; i<=78; i++)
	{
		int n1 = m_actual[i].m_dunkscore[1];

//		m_scores[i-70] = n1;

		for(int j=71; j<=78; j++)
		{

			int n2 = m_actual[j].m_dunkscore[1];
			if(n1 > n2)
			{
					CPlayer temp = m_actual[i];
					m_actual[i] =  m_actual[j];
					m_actual[j] = temp;
			}
		}
	}	

	for(int i=71; i<=78; i++)
	{
		int n1 = m_actual[i].m_dunkscore[1];

		m_scores[i-70] = n1;
	}



}

void CAllStarWeekend::SimSlamDunkContestRoundTwo()
{

	for(int i=1; i<=3; i++)
	{
		m_actual[70+i].m_dunkscore[2] = 60;
		double f = (double)(m_actual[70+i].m_prFta) / (double)(m_actual[70+i].m_prFga);
		f = f + (double)(avg.m_actual[70+i].m_prOrb) / (double)(m_actual[70+i].m_prDrb) + ((double)(m_actual[70+i].m_transoff) + (double)m_actual[70+i].m_transdef)/10.;
		if(f > 3.6) f=3.6 + f/10;
		for(int s=1; s<=50; s++)
		{
			double r = avg.Random(6);
			if( r<= f)
			{
				m_actual[70+i].m_dunkscore[2] = m_actual[70+i].m_dunkscore[2] + 1;
			}
		}
		m_actual[70+i].m_dunkscore[2] = m_actual[70+i].m_dunkscore[2]*10 + avg.IntRandom(10);
		if(m_actual[70+i].m_dunkscore[2] > 1000) m_actual[70+i].m_dunkscore[2] = 1000;

	}




	for(int i=71; i<=73; i++)
	{
		int n1 = m_actual[i].m_dunkscore[2];

		for(int j=71; j<=73; j++)
		{

			int n2 = m_actual[j].m_dunkscore[2];
//			m_scores[i-62] = n1;
			if(n1 > n2)
			{
					CPlayer temp = m_actual[i];
					m_actual[i] =  m_actual[j];
					m_actual[j] = temp;
			}
		}
	}	


	for(int i=71; i<=73; i++)
	{
		int n1 = m_actual[i].m_dunkscore[2];

		m_scores[i-62] = n1;
	}

}



void CAllStarWeekend::ReadUserSelections(int *m_index, CString user_file_name)
{
		for(int i=0; i<=80; i++)
		{
			m_index[i] = 0;
		}


		CStdioFile file(user_file_name, CFile::modeRead);

		CString str;
		file.ReadString( str);	//east all stars
		for(int i=1; i<=12; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
					m_index[i] = avg.m_actual[j].m_id;				
			}
		}

		file.ReadString( str);	//west all stars
		for(int i=1; i<=12; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
					m_index[15+i] = avg.m_actual[j].m_id;				
			}
		}

		file.ReadString( str);	//rookie all stars
		for(int i=1; i<=10; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
					m_index[30+i] = avg.m_actual[j].m_id;				
			}
		}

		file.ReadString( str);	//soph all stars
		for(int i=1; i<=10; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
				{
		//			m_actual[45+i] = avg.m_actual[j];
					m_index[45+i] = avg.m_actual[j].m_id;				
				}
			}
		}


		file.ReadString( str);	//3
		for(int i=1; i<=8; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
				{
					m_actual[60+i] = avg.m_actual[j];
					m_index[60+i] = avg.m_actual[j].m_id;				
				}
			}
		}

		file.ReadString( str);	//dunk
		for(int i=1; i<=8; i++)
		{
			file.ReadString( str);	
			str.TrimRight();
			str.TrimLeft();
			for(int j=1; j<=960; j++)
			{
				if(str == avg.m_actual[j].m_name && str != "")
				{
					m_actual[70+i] = avg.m_actual[j];
					m_index[70+i] = avg.m_actual[j].m_id;				
				}

			}
		}


		file.Close(); 
}
