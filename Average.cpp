#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"


#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 




void CAverage::ReSortFranchiseData()
{

	



}














void CAverage::GenerateRandomContracts(BOOL skip_ages, BOOL skip_contracts, BOOL skip_pot)//false ages will be same as previous so no change
{
	CFileStatus status;
	//int prime_factor = 28; //may become a passed variable that changes for new contracts



		for(int i=1; i<=1440; i++)
		{
			CString pos = m_actual[i].GetPos();
			m_actual[i].GenerateRandomPrime();

			

			int age = m_actual[i].GetAge(); 
			int start_yr = 19 + IntRandom(4);
			if(start_yr == 23) start_yr = 17+IntRandom(7);
			int yrs_pro = age - start_yr;
			if(yrs_pro <= 0) yrs_pro = 1;

//				yrs_pro = m_actual[i].m_yrs_of_service;//REMOVE

			if(skip_ages == FALSE)
			{
				yrs_pro = m_actual[i].m_yrs_of_service;
				m_actual[i].m_yrs_on_team = IntRandom(yrs_pro);
				//m_actual[i].m_yrs_of_service = yrs_pro;
			}


			if(skip_contracts == FALSE)
			{
				m_actual[i].m_contract_salaries[0] = 0;
				m_actual[i].m_contract_salaries[1] = 0;
				m_actual[i].m_contract_salaries[2] = 0;
				m_actual[i].m_contract_salaries[3] = 0;
				m_actual[i].m_contract_salaries[4] = 0;
				m_actual[i].m_contract_salaries[5] = 0;
				m_actual[i].m_contract_salaries[6] = 0;
			}

			if(skip_pot == FALSE)
			{
				m_actual[i].m_pos = pos;
				m_actual[i].m_pot2 = IntRandom(5);
				m_actual[i].m_pot1 = IntRandom(5);
				m_actual[i].m_effort = IntRandom(5);
			}

		}

	
		for(int i=1; i<=960; i++)
		{

			int orig_sal[7];
			int orig_con_yrs = 0;
			int orig_curr_con_yr = 0;
			int orig_total_sal = 0;
			for(int j=0; j<=6; j++)
			{
				int sal = m_actual[i].m_contract_salaries[j];
				orig_sal[j] = sal;
				if(sal > 0)
				{
					orig_con_yrs = j;
					if(orig_curr_con_yr == 0) orig_curr_con_yr = j;
					orig_total_sal = orig_total_sal + sal;
				}
			}
			int orig_age = m_actual[i].m_age;
			int orig_yrs = m_actual[i].m_yrs_of_service;
			int orig_yrs_on_team = m_actual[i].m_yrs_on_team;



			int age = m_actual[i].GetAge(); 
			CString name = m_actual[i].GetName();
			int id = m_actual[i].GetID();		
			
			double money = m_actual[i].GetTradeTrueRating(FALSE) * 98;
			money = money * (.8 + (double)IntRandom(40)/100);
			int total_salary = 0;


			double m_minimum[11];
			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;
			int y_s = m_actual[i].m_yrs_of_service;
			if(y_s > 10) y_s = 10;
			if(money < m_minimum[y_s]) money = m_minimum[y_s];

			int contract_max = 6;
			if(age > 28) contract_max = 35 - age;

			double mpy_f = money / 200;
			int mpy_i = (int) mpy_f;

			int possible = contract_max + mpy_i - 3;
			if(possible < 2) possible = 2;

			int contract_years = IntRandom(possible);
			if(contract_years > 6) contract_years = 6;
			if(contract_years == 1 && IntRandom(4) <= 2) contract_years = 2;//1 year contracts have rare chance (1 in 4) to be 2

			int current_contract_year = IntRandom(contract_years);
			if(current_contract_year == contract_years)
			{
				current_contract_year = IntRandom(contract_years);
			}
			if(m_actual[i].m_yrs_of_service <= 4) 
			{
				m_actual[i].m_yrs_on_team = m_actual[i].m_yrs_of_service; 
				if(IntRandom(4) == 1) m_actual[i].m_yrs_on_team = IntRandom(m_actual[i].m_yrs_of_service); 
				contract_years = 4;
				current_contract_year = m_actual[i].m_yrs_of_service;
			}



			bool max_raise = false;
			
			if(money > MAX10 && m_actual[i].m_yrs_of_service >= 10)
			{
				max_raise = true;
				money = MAX10;
			}
			else if(money > MAX7 && m_actual[i].m_yrs_of_service >= 7) 
			{
				max_raise = true;
				money = MAX7;
			}
			else if(money > MAX0) 
			{
				max_raise = true;
				money = MAX0;
			}

			if(m_actual[i].m_yrs_of_service <= 1 && money > 295) money = 295;
			if(m_actual[i].m_yrs_of_service == 2 && money > 317) money = 317;
			if(m_actual[i].m_yrs_of_service == 3 && money > 339) money = 339;


			if(m_actual[i].m_yrs_of_service <= 1)
			{
				contract_years = 3;
				current_contract_year = 1;
			}
			else if(m_actual[i].m_yrs_of_service == 2)
			{
				contract_years = 3;
				current_contract_year = 2;
			}
			else if(m_actual[i].m_yrs_of_service == 3)
			{
				contract_years = 3;
				current_contract_year = 3;
			}



			int current_money = (int)money;
			m_actual[i].m_contract_salaries[current_contract_year] = current_money;
			total_salary = total_salary + current_money;

			if(contract_years != current_contract_year)//end of contract
			{
				m_actual[i].m_is_free_agent = false;
				int raise = IntRandom(contract_years*3);
				if(max_raise == true) raise = 10;
				if(raise > 10) raise = 10;
				total_salary = 0;
				double inc = (double)current_money * (double) raise / 100;

			for(int j=current_contract_year+1; j<=contract_years; j++)
			{
				double money = double(current_money) + inc;
				current_money = (int)money;
				m_actual[i].m_contract_salaries[j] = current_money;
				total_salary = total_salary + current_money;
			}

			}
			else
			{
				m_actual[i].m_is_free_agent = true;
			}
			m_actual[i].m_name = name;
			m_actual[i].m_salary_id = id;


			if(skip_contracts == TRUE)
			{
				m_actual[i].m_yrs_on_team = orig_yrs_on_team;

				for(int j=0; j<=6; j++)
				{
					m_actual[i].m_contract_salaries[j] = orig_sal[j];
				}
				contract_years = orig_con_yrs;
				current_contract_year = orig_curr_con_yr;
				total_salary = orig_total_sal;
			}

			
			if(skip_ages == TRUE)
			{
				m_actual[i].m_age = orig_age;
				m_actual[i].m_yrs_of_service = orig_yrs;
				m_actual[i].GenerateRandomHeightWeight(false);
			}

			m_actual[i].m_contract_yrs = contract_years;
			m_actual[i].m_current_contract_yr = current_contract_year;
			m_actual[i].m_current_team = int((i-1)/30);
			m_actual[i].m_previous_team = m_actual[i].m_current_team;
			m_actual[i].m_total_salary = total_salary;
			m_actual[i].m_current_yr_salary = m_actual[i].m_contract_salaries[m_actual[i].m_current_contract_yr]; 

			int remaining_salary = 0;
			for(int  y=1; y<=m_actual[i].m_contract_yrs; y++)
			{
				int j = m_actual[i].m_contract_salaries[y];			
				if(y >= m_actual[i].m_current_contract_yr) remaining_salary = remaining_salary + i;
				
			}
			m_actual[i].m_remaining_salary = remaining_salary;

		}


		for(int i=961; i<=1440; i++)
		{
			CString name = m_actual[i].GetName();
			int id = m_actual[i].GetID();		
			m_actual[i].m_is_free_agent = true;
			m_actual[i].m_name = name;
			m_actual[i].m_salary_id = id;
		}
	

		for(int i=0; i<=1440; i++)
		{
			//deciding request for contract factors;	
	

			m_actual[i].m_coach_factor = IntRandom(5);
			m_actual[i].m_security_factor = IntRandom(5);
			m_actual[i].m_loyalty_factor = IntRandom(5);
			m_actual[i].m_winning_factor = IntRandom(5);
			m_actual[i].m_playing_time_factor = IntRandom(5);
			m_actual[i].m_tradition_factor = IntRandom(5);

		}
	
}


void CAverage::CalculateBetter(bool started)//calculate make better ratings
{

CPlayer* P = new CPlayer[1441];
double Chart[33][31][31];
for(int team=0; team<32; team++)//set slots 1-15 for each team
{
	
	for(int i = 1; i <= 30; i++)
	{
		P[team*30+i] = m_actual[team*30 + i];
		P[team*30+i].SetRosterNumber(i);
	}	
}

for(int team=0; team<32; team++)//sort by most minutes
{
	
	for(int i = 1; i <= 30; i++)
	{
			for(int j = 1; j < i; j++)
			{
					if(P[team*30+j].GetMin() < P[team*30+i].GetMin())
					{
						CPlayer temp = P[team*30+i];
						P[team*30+i] = P[team*30+j];
						P[team*30+j] = temp;
					}
			}
	}	
	double minutes = 0;
	for(int i = 1; i <= 30; i++)
	{
		if(P[team*30+i].GetName() != "")
		{
			minutes = minutes + double(P[team*30+i].GetMin());
			P[team*30+i].SetTeammatesBetterRating( m_avg_fga[0], m_avg_fta[0], m_avg_tga[0], m_avg_tru[0], m_avg_orb[0], m_avg_drb[0], m_avg_ast[0], m_avg_stl[0], m_avg_to[0], m_avg_blk[0]);
		}

	}
	for(int i = 1; i <= 30; i++)
	{
			for(int j = 1; j <= 30; j++)
			{
				double n1 = 0, n2 = 0, n3 = 0, n4 = 0;
				n1 = minutes / 15;//minutes starters play together 
				if(i <= 5 && j <= 5)
				{
					n1 = 0;
					n2 = n1;
					n3 = n1;
					n4 = n1;
				}
				else if(i <= 5 && j > 5)
				{
					n1 = 0;
					n2 = n1;
					n3 = 0;
					n4 = 0;
				}
				else if(i > 5 && j <= 5)
				{
					n1 = 0;
					n2 = 0;
					n3 = n1;
					n4 = 0;
				}
				else
				{
					n1 = 0;
					n2 = 0;
					n3 = 0;
					n4 = 0;
				}
				double f = double(P[team*30+i].GetMin()) - n2;
				double g = double(P[team*30+j].GetMin()) - n3;
				double h = f*g/(minutes-n1*5)*5;
				Chart[team][i][j] = h + n4;
			}
	}		
	for(int i = 1; i <= 30; i++)
	{
		double better = 0;
			for(int j = 1; j <= 30; j++)
			{
				if(i!=j)
				{
					better =
						better + 
						Chart[team][i][j] * P[team*30+j].GetTeammatesBetterRating();
				}
			}
			double min = double(P[team*30+i].GetMin());
			double rating =  better /  min;
			if(rating > 8.0) rating = 8.0;
			else if(rating < -2.0) rating = -2.0;
			int r = int( ((rating + 9.9) * 10) / 2);
			int n = P[team*30+i].GetRosterNumber();
	if(started == false)
		P[team*30+i].SetBetter(r);
	else
		P[team*30+i].SetBetter(m_actual[team*30+n].GetBetter());

	}		
}


for(int team=0; team<32; team++)
{
	for(int i = 1; i <= 15; i++)
	{
		int n = P[team*30+i].GetRosterNumber();
		m_actual[team*30 + n]  = P[team*30+i];
	}
}


delete [] P;


}

void CAverage::GenerateRandomProjections()
{


		for(int i=1; i<=1440; i++)
		{
			m_actual[i].GenerateRandomPrime();
			int pt1 = IntRandom(5);
			int pt2 = IntRandom(5);
			int eff = IntRandom(5);
			m_actual[i].m_pot1 = pt1;
			m_actual[i].m_pot2 = pt2;
			m_actual[i].m_effort = eff;
		}

}

void CAverage::ExpandRosters()
{
	CPlayer* temp = new CPlayer[1001];
	int t = 1, p = 1;
	for(int i=1; i<=480; i++)
	{
		int slot = t*15-15 + p;
		temp[t*20-20+p] = m_actual[slot];
		p = p + 1;
		if(p == 16) { t=t+1; p = 1;}
	}

	for(int i=1; i<=96; i++)
	{
		temp[800+i] = m_actual[480+i];
	}

	for(int i=0; i<=700; i++)
	{
		m_actual[i] = temp[i];
	}

	//701-764 is team stats that we dont wanna change or touch

	for(int i=765; i<=1000; i++)
	{
		m_actual[i] = temp[i];
	}
	delete [] temp;
}

void CAverage::CalculateCurrentPayroll(bool off_season)
{
	int slots = 30;
	int fa_offset = 960;
	if(off_season == true)
	{
		slots = 30;
		fa_offset = 960;
	}

	for(int t=0; t<=31; t++)
	{

		
		int index = t*slots + 1;
		int total[7] = {0,0,0,0,0,0,0};
		int t_age = 0, p_count = 0;
		int t_age1 = 0, p_count1 = 0;
		int t_age2 = 0, p_count2 = 0;
		int t_age3 = 0, p_count3 = 0;
		for(int i=index; i<=index + (slots - 1); i++)
		{
			if(m_actual[i].m_retired == true && off_season == true) continue;
			
			if(m_actual[i].m_name != "")
			{
				p_count = p_count + 1;
				t_age = t_age + m_actual[i].m_age;
				p_count1 = p_count1 + 1;
				t_age1 = t_age1 + m_actual[i].m_yrs_of_service;
				p_count2 = p_count2 + 1;
				t_age2 = t_age2 + m_actual[i].m_height;
				p_count3 = p_count3 + 1;
				t_age3 = t_age3 + m_actual[i].m_weight;
			}
			for(int y=0; y<=5; y++)
			{
				int yr = m_actual[i].m_current_contract_yr + y;
				if(yr <= 6)
				total[y] = total[y] + m_actual[i].m_contract_salaries[yr];
			
			}
		}

		m_actual[1441 + t].m_age = int((double)t_age / (double)p_count * 10);
		m_actual[1441 + t].m_yrs_of_service = int((double)t_age1 / (double)p_count1 * 10);
		m_actual[1441 + t].m_height = int((double)t_age2 / (double)p_count2 * 10);
		m_actual[1441 + t].m_weight = int((double)t_age3 / (double)p_count3 * 10);
		


		for(int y=0; y<=5; y++)
		{
			m_actual[1441 + t].m_contract_salaries[y] = total[y];
		}
	}

	for(int i=1; i<=480; i++)
	{
		int tp = m_actual[fa_offset+i].m_team_paying; 
		if(tp == 0) continue;
		for(int y=0; y<=5; y++)
		{
			int yr = m_actual[fa_offset+i].m_current_contract_yr + y;
			if(yr <= 6)
			{
				int money =  m_actual[fa_offset+i].m_contract_salaries[yr];
				m_actual[1440+tp].m_contract_salaries[y] = 
					m_actual[1440+tp].m_contract_salaries[y] + money;
			}
		}
	}

}







void CAverage::ConvertDataNewFormat()
{
	CPlayer *temp = new CPlayer[1601];
	for(int t=1; t<=32; t++)
	{
		for(int p=1; p<=15; p++)
		{
			int original_slot = (t-1)*15 + p;
			int new_slot = (t-1)*30 + p;
			temp[new_slot] = m_actual[original_slot];
			temp[new_slot].m_current_team = t-1;
		}
	}


	for(int p=1; p<=96; p++)//FA
	{
		int original_slot = 480 + p;
		int new_slot = 960 + p;
		temp[new_slot] = m_actual[original_slot];
	}

	for(int p=1; p<=64; p++)//teams
	{
		int original_slot = 700 + p;
		int new_slot = 1440 + p;
		temp[new_slot] = m_actual[original_slot];
	}




	for(int i=0; i<=1600; i++)
	{
		m_actual[i] = temp[i];
		m_actual[i].m_temp_pointer = i;
		m_actual[i].m_original_number = i;

	}

	delete [] temp;

}

void CAverage::UpdateStandings(int t1, int sc1, int t2, int sc2)
{

					if(sc1 < sc2) 
					{	
						m_standings[t1].m_vsOpponent[t2+1] = m_standings[t1].m_vsOpponent[t2+1] + 1;
						m_standings[t1].m_leagueRecord = m_standings[t1].m_leagueRecord + 1;
						m_standings[t1].m_visitorRecord = m_standings[t1].m_visitorRecord + 1;
						if(m_standings[t1].m_conference == m_standings[t2].m_conference)
							m_standings[t1].m_conferenceRecord = m_standings[t1].m_conferenceRecord + 1;
						if(m_standings[t1].m_division == m_standings[t2].m_division)
							m_standings[t1].m_divisionRecord = m_standings[t1].m_divisionRecord + 1;

						m_standings[t2].m_vsOpponent[t1+1] = m_standings[t2].m_vsOpponent[t1+1] + 100;
						m_standings[t2].m_leagueRecord = m_standings[t2].m_leagueRecord + 100;
						m_standings[t2].m_homeRecord = m_standings[t2].m_homeRecord + 100;
						if(m_standings[t2].m_conference == m_standings[t1].m_conference)
							m_standings[t2].m_conferenceRecord = m_standings[t2].m_conferenceRecord + 100;
						if(m_standings[t2].m_division == m_standings[t1].m_division)
							m_standings[t2].m_divisionRecord = m_standings[t2].m_divisionRecord + 100;

					}
					else if(sc1 > sc2)
					{
						m_standings[t1].m_vsOpponent[t2+1] = m_standings[t1].m_vsOpponent[t2+1] + 100;
						m_standings[t1].m_leagueRecord = m_standings[t1].m_leagueRecord + 100;
						m_standings[t1].m_visitorRecord = m_standings[t1].m_visitorRecord + 100;
						if(m_standings[t1].m_conference == m_standings[t2].m_conference)
							m_standings[t1].m_conferenceRecord = m_standings[t1].m_conferenceRecord + 100;
						if(m_standings[t1].m_division == m_standings[t2].m_division)
							m_standings[t1].m_divisionRecord = m_standings[t1].m_divisionRecord + 100;

						m_standings[t2].m_vsOpponent[t1+1] = m_standings[t2].m_vsOpponent[t1+1] + 1;
						m_standings[t2].m_leagueRecord = m_standings[t2].m_leagueRecord + 1;
						m_standings[t2].m_homeRecord = m_standings[t2].m_homeRecord + 1;
						if(m_standings[t2].m_conference == m_standings[t1].m_conference)
							m_standings[t2].m_conferenceRecord = m_standings[t2].m_conferenceRecord + 1;
						if(m_standings[t2].m_division == m_standings[t1].m_division)
							m_standings[t2].m_divisionRecord = m_standings[t2].m_divisionRecord + 1;
					}
				

			int w = m_standings[t1].m_leagueRecord / 100;
			int l = m_standings[t1].m_leagueRecord - w * 100;
			m_standings[t1].m_win = w;
			m_standings[t1].m_loss = l;
			int games = w + l;
			if(games == 0) games = 1;
			double pct = double(w) / double(games);
			m_standings[t1].m_leaguePct = pct;
			m_standings[t1].m_leagueGamesBack = w - l;

			w = m_standings[t1].m_divisionRecord / 100;
			l = m_standings[t1].m_divisionRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			m_standings[t1].m_divisionPct = pct;
			w = m_standings[t1].m_conferenceRecord / 100;
			l = m_standings[t1].m_conferenceRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			m_standings[t1].m_conferencePct = pct;
			
			
			w = m_standings[t1].m_vsOpponent[t2+1] / 100;
			l = m_standings[t1].m_vsOpponent[t2+1] - w * 100;
			games = w + l;
				if(games == 0) games = 1;
			pct = double(w) / double(games);
				m_standings[t1].m_vsOpponentPct[t2+1] = pct;
			

			w = m_standings[t2].m_leagueRecord / 100;
			l = m_standings[t2].m_leagueRecord - w * 100;
			m_standings[t2].m_win = w;
			m_standings[t2].m_loss = l;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			m_standings[t2].m_leaguePct = pct;
			m_standings[t2].m_leagueGamesBack = w - l;

			w = m_standings[t2].m_divisionRecord / 100;
			l = m_standings[t2].m_divisionRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			m_standings[t2].m_divisionPct = pct;
			w = m_standings[t2].m_conferenceRecord / 100;
			l = m_standings[t2].m_conferenceRecord - w * 100;
			games = w + l;
			if(games == 0) games = 1;
			pct = double(w) / double(games);
			m_standings[t2].m_conferencePct = pct;
			w = m_standings[t2].m_vsOpponent[t1+1] / 100;
			l = m_standings[t2].m_vsOpponent[t1+1] - w * 100;
			games = w + l;
				if(games == 0) games = 1;
			pct = double(w) / double(games);
				m_standings[t2].m_vsOpponentPct[t1+1] = pct;





}





//void CAverage::CreateReport(CStaff m_scout, CPlayer &m_player)
//{

//}




bool CAverage::FileExists(CString file_name)
{
	bool exists = true;
	CFileStatus status;
	CString pFileName = file_name;
	if( CFile::GetStatus( pFileName, status ) == 0) exists = 0;
	return exists;
}

void CAverage::SetStartSeasonAttributes(bool age)
{
	m_sched.m_playoff_started = false;
	m_sched.m_season_started = false;
	for(int i=0; i<=1024; i++)
	{
		m_trans_str[i] = "";
	}
	m_settings.m_number_transactions = 0;
	m_sched.m_regular_season_ended = false;

	for(int i=1; i<=1600; i++)
	{
		m_actual[i].m_dunkcontest = 0;
		m_actual[i].m_3contest = 0;

		m_actual[i].SetGameInjuryRating(m_actual[i].m_games,
			m_actual[i].m_min, m_actual[i].m_fga - m_actual[i].m_tfga, m_actual[i].m_fta, m_actual[i].m_to, m_settings.m_injury, 82);

		int te = (i-1)/30 + 1;
		if(te > m_settings.m_numberteams) te = 0;
		m_actual[i].m_team_paying = te;
		if(te > 0) 
			m_actual[i].m_team_paying_name = m_settings.m_leagueTeamNames[te-1];
		else
			m_actual[i].m_team_paying_name = "";

		
		if(i <= 960 && age == true)
		{
			m_actual[i].m_yrs_on_team = m_actual[i].m_yrs_on_team + 1;	
		}

		if(i <= 1440 && age == true)
		{
			m_actual[i].m_yrs_of_service = m_actual[i].m_yrs_of_service + 1;
		}

		if(i <= 1440)
		{
			m_actual[i].m_original_number = i;
		}

		m_actual[i].SetActive(1);
		m_actual[i].SetLastName(m_actual[i].m_name);
		m_actual[i].ClearSeasonStats();

		//m_actual[i].SetOldRatings();
		m_actual[i].SetOldRatings();
		int team = m_actual[i].m_current_team;
		if(team == -1) team = 99;
		m_actual[i].SetAdjustedOldRatings(m_coach[team], false);


		m_actual[i].m_temp_pointer = i;
		m_actual[i].m_just_signed = false;

		if(m_actual[i].m_contract_yrs == m_actual[i].m_current_contract_yr) m_actual[i].m_is_free_agent = true;
		if(m_actual[i].m_yrs_on_team < 3) m_actual[i].m_bird_player = false; else m_actual[i].m_bird_player = true;


		int remaining_salary = 0;
		for(int  y=1; y<=m_actual[i].m_contract_yrs; y++)
		{
			int j = m_actual[i].m_contract_salaries[y];			
			if(y >= m_actual[i].m_current_contract_yr) remaining_salary = remaining_salary + i;
				
		}
		m_actual[i].m_remaining_salary = remaining_salary;
		m_actual[i].m_current_yr_salary = m_actual[i].m_contract_salaries[m_actual[i].m_current_contract_yr];
		if(remaining_salary == 0 && i <= 1440)
		{
			m_actual[i].m_is_free_agent = true;
			m_actual[i].m_current_contract_yr = 0;
			m_actual[i].m_contract_yrs = 0;
		}

		double trade_value = m_actual[i].m_tradeTrueRating;//happy with pay
		double money = trade_value * 100;
		double pd = (double)m_actual[i].m_current_yr_salary;
		double f = pd / money;
		double r = Random(m_actual[i].m_loyalty_factor + 1);
		if(m_actual[i].m_content == 0) m_actual[i].m_content = 5;
		if(r < f && m_actual[i].m_content < 9)
			m_actual[i].m_content = m_actual[i].m_content + 1;
		else if(r > f && r < 2 && m_actual[i].m_content > 1)
			m_actual[i].m_content = m_actual[i].m_content - 1;

		m_actual[i].m_health = 100;
		m_actual[i].m_injury = m_actual[i].m_injury - 120 + m_actual[i].m_effort * 5;
		if(m_actual[i].m_injury < 0) 
		{
			m_actual[i].m_injury = 0;
			m_actual[i].m_health = 100;
		}
	}
}

void CAverage::ComputerSetsRotation()
{


	double avgTru = m_avg_trade_tru[0];

	for(int t=1; t<=m_settings.m_numberteams; t++)
	{



		if(m_settings.m_player_gm[t-1] == "Player") continue;

	int offset = 1 + (t-1)*30;	

	for(int i=offset; i<=offset+29; i++)
	{
			// clear rotations
				m_actual[i].SetPgRot(0);
				m_actual[i].SetSgRot(0);
				m_actual[i].SetSfRot(0);
				m_actual[i].SetPfRot(0);
				m_actual[i].SetCRot(0);

			//clear player controlled game plans
				m_actual[i].m_game_minutes = 0;
				m_actual[i].m_offensive_focus = 0;
				m_actual[i].m_defensive_focus = 0;
				m_actual[i].m_offensive_intensity = 0;
				m_actual[i].m_defensive_intensity = 0;

				m_actual[i].m_play_maker = 0;



		//if(m_actual[i].GetPgRot() == 1) m_actual[i].SetPgRot(2); what why?
	}
	BOOL career = FALSE;
	for(int i=offset; i<=offset+29; i++)
	{
        if(m_actual[i].GetTradeTrueRating(career) > avgTru*3/4 && m_actual[i].GetPos() == "PG")        
			m_actual[i].SetPgRot(2);
        else if(m_actual[i].GetTradeTrueRating(career) > avgTru*3/4 && m_actual[i].GetPos() == "SG")        
			m_actual[i].SetSgRot(2);
        else if(m_actual[i].GetTradeTrueRating(career) > avgTru*3/4 && m_actual[i].GetPos() == "SF")        
			m_actual[i].SetSfRot(2);
        else if(m_actual[i].GetTradeTrueRating(career) > avgTru*3/4 && m_actual[i].GetPos() == "PF")        
			m_actual[i].SetPfRot(2);
        else if(m_actual[i].GetTradeTrueRating(career) > avgTru*3/4 && m_actual[i].GetPos() == " C")        
			m_actual[i].SetCRot(2);
	}
	int hiPg = -1, hiSg = -1, hiSf = -1, hiPf = -1, hiC = -1;
	double truPg = 0, truSg = 0, truSf = 0, truPf = 0, truC = 0;
	for(int i=offset; i<=offset+29; i++)
	{
		if(m_actual[i].GetPos() == "PG" && m_actual[i].GetTradeTrueRating(career) > truPg)
		{
			hiPg = i; truPg = m_actual[i].GetTradeTrueRating(career);
		}
		else if(m_actual[i].GetPos() == "SG" && m_actual[i].GetTradeTrueRating(career) > truSg)
		{
			hiSg = i; truSg = m_actual[i].GetTradeTrueRating(career);
		}
		else if(m_actual[i].GetPos() == "SF" && m_actual[i].GetTradeTrueRating(career) > truSf)
		{
			hiSf = i; truSf = m_actual[i].GetTradeTrueRating(career);
		}
		else if(m_actual[i].GetPos() == "PF" && m_actual[i].GetTradeTrueRating(career) > truPf)
		{
			hiPf = i; truPf = m_actual[i].GetTradeTrueRating(career);
		}
		else if(m_actual[i].GetPos() == " C" && m_actual[i].GetTradeTrueRating(career) > truC)
		{
			hiC = i; truC = m_actual[i].GetTradeTrueRating(career);
		}
	}
	if(hiPg > -1) m_actual[hiPg].SetPgRot(1);
	if(hiSg > -1) m_actual[hiSg].SetSgRot(1);
	if(hiSf > -1) m_actual[hiSf].SetSfRot(1);
	if(hiPf > -1) m_actual[hiPf].SetPfRot(1);
	if(hiC  > -1) m_actual[hiC].SetCRot(1);


	for(int i=offset; i<=offset+29; i++)
	{
        if(m_actual[i].GetPos() == "PG"
			&& m_actual[i].GetSgRot() == 0 && m_actual[i].GetPgRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career) &&
					m_actual[j].GetSgRot() == 2 && m_actual[i].GetReb() > m_actual[j].GetReb())
				{
					m_actual[i].SetSgRot(2);
					m_actual[j].SetSgRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == "SG"
			&& m_actual[i].GetPgRot() == 0 && m_actual[i].GetSgRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career) &&
					m_actual[j].GetPgRot() == 2 && m_actual[i].GetAst() > m_actual[j].GetAst())
				{
					m_actual[i].SetPgRot(2);
					m_actual[j].SetPgRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == "SG"
			&& m_actual[i].GetSgRot() == 0 && m_actual[i].GetSfRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career) &&
					m_actual[j].GetSfRot() == 2)
				{
					m_actual[i].SetSfRot(2);
					m_actual[j].SetSfRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == "SF"
			&& m_actual[i].GetSfRot() == 0 && m_actual[i].GetSgRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSgRot() == 2 && (m_actual[i].GetReb()+m_actual[i].GetAst()) > (m_actual[j].GetReb()+m_actual[j].GetAst()))
				{
					m_actual[i].SetSgRot(2);
					m_actual[j].SetSgRot(0);
				}
			}
		}	
		if(m_actual[i].GetPos() == "SF"
			&& m_actual[i].GetSfRot() == 0 && m_actual[i].GetPfRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetPfRot() == 2 && m_actual[i].GetReb() > m_actual[j].GetReb())
				{
					m_actual[i].SetPfRot(2);
					m_actual[j].SetPfRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == "PF"
			&& m_actual[i].GetPfRot() == 0 && m_actual[i].GetSfRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSfRot() == 2 && m_actual[i].GetAst() > m_actual[j].GetAst())
				{
					m_actual[i].SetSfRot(2);
					m_actual[j].SetSfRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == "PF"
			&& m_actual[i].GetPfRot() == 0 && m_actual[i].GetCRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career) &&
					m_actual[j].GetCRot() == 2 && (m_actual[i].GetReb() + m_actual[i].GetBlk()) > (m_actual[j].GetReb()+m_actual[j].GetBlk()))
				{
					m_actual[i].SetCRot(2);
					m_actual[j].SetCRot(0);
				}
			}
		}
		if(m_actual[i].GetPos() == " C"
			&& m_actual[i].GetPfRot() == 0 && m_actual[i].GetCRot() != 1)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career) &&
					m_actual[j].GetPfRot() == 2 && (m_actual[i].GetReb() + m_actual[i].GetAst()) > (m_actual[j].GetReb()+m_actual[j].GetAst()))
				{
					m_actual[i].SetPfRot(2);
					m_actual[j].SetPfRot(0);
				}
			}
		}

	}







	for(int i=offset; i<=offset+29; i++)
	{
        if(m_actual[i].GetPgRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSgRot() == 1 && m_actual[i].GetReb() > m_actual[j].GetReb())
				{
					m_actual[i].SetSgRot(1);//swap if better player for starting
					m_actual[j].SetSgRot(2);
				}
			}
		}

        if(m_actual[i].GetSgRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetPgRot() == 1 && m_actual[i].GetAst() > m_actual[j].GetAst())
				{
					m_actual[i].SetPgRot(1);//swap if better player for starting
					m_actual[j].SetPgRot(2);
				}
			}
		}

        if(m_actual[i].GetSfRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSgRot() == 1  && (m_actual[i].GetReb()+m_actual[i].GetAst()) > (m_actual[j].GetReb()+m_actual[j].GetAst()))
				{
					m_actual[i].SetSgRot(1);//swap if better player for starting
					m_actual[j].SetSgRot(2);
				}
			}
		}

        if(m_actual[i].GetSgRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSfRot() == 1 && m_actual[i].GetReb() > m_actual[j].GetReb())
				{
					m_actual[i].SetSfRot(1);//swap if better player for starting
					m_actual[j].SetSfRot(2);
				}
			}
		}

        if(m_actual[i].GetSfRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetPfRot() == 1  && m_actual[i].GetReb() > m_actual[j].GetReb())
				{
					m_actual[i].SetPfRot(1);//swap if better player for starting
					m_actual[j].SetPfRot(2);
				}
			}
		}

        if(m_actual[i].GetPfRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetSfRot() == 1  && m_actual[i].GetAst() > m_actual[j].GetAst())
				{
					m_actual[i].SetSfRot(1);//swap if better player for starting
					m_actual[j].SetSfRot(2);
				}
			}
		}

        if(m_actual[i].GetPfRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetCRot() == 1 && (m_actual[i].GetReb() + m_actual[i].GetBlk()) > (m_actual[j].GetReb()+m_actual[j].GetBlk()))
				{
					m_actual[i].SetCRot(1);//swap if better player for starting
					m_actual[j].SetCRot(2);
				}
			}
		}

        if(m_actual[i].GetCRot() == 2)        
		{
			for(int j=offset; j<=offset+29; j++)
			{
				if(m_actual[i].GetTradeTrueRating(career) > m_actual[j].GetTradeTrueRating(career)  &&
					m_actual[j].GetPfRot() == 1 && (m_actual[i].GetReb() + m_actual[i].GetAst()) > (m_actual[j].GetReb()+m_actual[j].GetAst()))
				{
					m_actual[i].SetPfRot(1);//swap if better player for starting
					m_actual[j].SetPfRot(2);
				}
			}
		}


	}

	}


	
}



void CAverage::ComputerSortsRosterAfterTrades(CPlayer *actual, int slots)
{
	for(int times = 0; times <= 1; times ++)
	{

	int offset = 1 + times*slots;

	for(int i=offset; i<=offset + (slots-1); i++)
	{
		CString posi = actual[i].m_pos;
		double ptsi = actual[i].m_tradeValue;
		if(posi == "PG") ptsi = ptsi + 500;
		else if(posi == "SG") ptsi = ptsi + 400;
		else if(posi == "SF") ptsi = ptsi + 300;
		else if(posi == "PF") ptsi = ptsi + 200;
		else if(posi == " C") ptsi = ptsi + 100;
		for(int j=offset; j<=offset + (slots-1); j++)
		{
			if(actual[i].m_name == "" || actual[j].m_name == "") continue;
			CString posj = actual[j].m_pos;
			double ptsj = actual[j].m_tradeValue;
			if(posj == "PG") ptsj = ptsj + 500;
			else if(posj == "SG") ptsj = ptsj + 400;
			else if(posj == "SF") ptsj = ptsj + 300;
			else if(posj == "PF") ptsj = ptsj + 200;
			else if(posj == " C") ptsj = ptsj + 100;

			if(ptsi > ptsj)
			{
				CPlayer temp = actual[i];
				actual[i] = actual[j];
				actual[j] = temp;
			}


		}
	}

	}

	
}




void CAverage::ComputerRotationForTrades(CPlayer* actual, double* trade_values, int slots, int team1, int team2)
{
	
	double avgTru = m_avg_trade_tru[0];

	for(int times = 0; times <= 1; times ++)
	{
		int offset = 1 + times*slots;
		int tea = team1;
		if(times == 1) tea = team2;

	for(int i=offset; i<=offset+19; i++)
	{
			// clear rotations
			actual[i].SetPgRot(0);
			actual[i].SetSgRot(0);
			actual[i].SetSfRot(0);
			actual[i].SetPfRot(0);
			actual[i].SetCRot(0);
			actual[i].SetAdjTrueRatingSimple(actual[i].GetFgm(), actual[i].GetFga(), actual[i].GetTfgm(), actual[i].GetTfga(), actual[i].GetFtm(),  actual[i].GetFta(), actual[i].GetOreb(),  actual[i].GetReb(), actual[i].GetAst(), actual[i].GetStl(), actual[i].GetTo(), actual[i].GetBlk(), m_gm[tea].m_scoring, m_gm[tea].m_shooting, m_gm[tea].m_rebounding, m_gm[tea].m_passing, m_gm[tea].m_defense);
	        actual[i].SetTradeTrueRating(0);
            actual[i].SetAdjTradeValue(m_gm[tea].m_pot1, m_gm[tea].m_pot2, m_gm[tea].m_effort);

	}
	BOOL career = TRUE;
	for(int i=offset; i<=offset+19; i++)
	{
        if(actual[i].GetTradeTrueRating(career) > avgTru*3/4 && actual[i].GetPos() == "PG")        
			actual[i].SetPgRot(2);
        else if(actual[i].GetTradeTrueRating(career) > avgTru*3/4 && actual[i].GetPos() == "SG")        
			actual[i].SetSgRot(2);
        else if(actual[i].GetTradeTrueRating(career) > avgTru*3/4 && actual[i].GetPos() == "SF")        
			actual[i].SetSfRot(2);
        else if(actual[i].GetTradeTrueRating(career) > avgTru*3/4 && actual[i].GetPos() == "PF")        
			actual[i].SetPfRot(2);
        else if(actual[i].GetTradeTrueRating(career) > avgTru*3/4 && actual[i].GetPos() == " C")        
			actual[i].SetCRot(2);
	}
	int hiPg = -1, hiSg = -1, hiSf = -1, hiPf = -1, hiC = -1;
	double truPg = 0, truSg = 0, truSf = 0, truPf = 0, truC = 0;
	for(int i=offset; i<=offset+19; i++)
	{
		if(actual[i].GetPos() == "PG" && actual[i].GetTradeTrueRating(career) > truPg)
		{
			hiPg = i; truPg = actual[i].GetTradeTrueRating(career);
		}
		else if(actual[i].GetPos() == "SG" && actual[i].GetTradeTrueRating(career) > truSg)
		{
			hiSg = i; truSg = actual[i].GetTradeTrueRating(career);
		}
		else if(actual[i].GetPos() == "SF" && actual[i].GetTradeTrueRating(career) > truSf)
		{
			hiSf = i; truSf = actual[i].GetTradeTrueRating(career);
		}
		else if(actual[i].GetPos() == "PF" && actual[i].GetTradeTrueRating(career) > truPf)
		{
			hiPf = i; truPf = actual[i].GetTradeTrueRating(career);
		}
		else if(actual[i].GetPos() == " C" && actual[i].GetTradeTrueRating(career) > truC)
		{
			hiC = i; truC = actual[i].GetTradeTrueRating(career);
		}
	}
	if(hiPg > -1) actual[hiPg].SetPgRot(1);
	if(hiSg > -1) actual[hiSg].SetSgRot(1);
	if(hiSf > -1) actual[hiSf].SetSfRot(1);
	if(hiPf > -1) actual[hiPf].SetPfRot(1);
	if(hiC  > -1) actual[hiC].SetCRot(1);

	for(int i=offset; i<=offset+19; i++)
	{
        if(actual[i].GetPos() == "PG"
			&& actual[i].GetSgRot() == 0 && actual[i].GetPgRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career) &&
					actual[j].GetSgRot() == 2 && actual[i].GetReb() > actual[j].GetReb())
				{
					actual[i].SetSgRot(2);
					actual[j].SetSgRot(0);
				}
			}
		}
		if(actual[i].GetPos() == "SG"
			&& actual[i].GetPgRot() == 0 && actual[i].GetSgRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career) &&
					actual[j].GetPgRot() == 2 && actual[i].GetAst() > actual[j].GetAst())
				{
					actual[i].SetPgRot(2);
					actual[j].SetPgRot(0);
				}
			}
		}
		if(actual[i].GetPos() == "SG"
			&& actual[i].GetSgRot() == 0 && actual[i].GetSfRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career) &&
					actual[j].GetSfRot() == 2)
				{
					actual[i].SetSfRot(2);
					actual[j].SetSfRot(0);
				}
			}
		}
		if(actual[i].GetPos() == "SF"
			&& actual[i].GetSfRot() == 0 && actual[i].GetSgRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSgRot() == 2 && (actual[i].GetReb()+actual[i].GetAst()) > (actual[j].GetReb()+actual[j].GetAst()))
				{
					actual[i].SetSgRot(2);
					actual[j].SetSgRot(0);
				}
			}
		}	
		if(actual[i].GetPos() == "SF"
			&& actual[i].GetSfRot() == 0 && actual[i].GetPfRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetPfRot() == 2 && actual[i].GetReb() > actual[j].GetReb())
				{
					actual[i].SetPfRot(2);
					actual[j].SetPfRot(0);
				}
			}
		}
		if(actual[i].GetPos() == "PF"
			&& actual[i].GetPfRot() == 0 && actual[i].GetSfRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSfRot() == 2 && actual[i].GetAst() > actual[j].GetAst())
				{
					actual[i].SetSfRot(2);
					actual[j].SetSfRot(0);
				}
			}
		}
		if(actual[i].GetPos() == "PF"
			&& actual[i].GetPfRot() == 0 && actual[i].GetCRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career) &&
					actual[j].GetCRot() == 2 && (actual[i].GetReb() + actual[i].GetBlk()) > (actual[j].GetReb()+actual[j].GetBlk()))
				{
					actual[i].SetCRot(2);
					actual[j].SetCRot(0);
				}
			}
		}
		if(actual[i].GetPos() == " C"
			&& actual[i].GetPfRot() == 0 && actual[i].GetCRot() != 1)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career) &&
					actual[j].GetPfRot() == 2 && (actual[i].GetReb() + actual[i].GetAst()) > (actual[j].GetReb()+actual[j].GetAst()))
				{
					actual[i].SetPfRot(2);
					actual[j].SetPfRot(0);
				}
			}
		}

	}







	for(int i=offset; i<=offset+19; i++)
	{
        if(actual[i].GetPgRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSgRot() == 1 && actual[i].GetReb() > actual[j].GetReb())
				{
					actual[i].SetSgRot(1);//swap if better player for starting
					actual[j].SetSgRot(2);
				}
			}
		}

        if(actual[i].GetSgRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetPgRot() == 1 && actual[i].GetAst() > actual[j].GetAst())
				{
					actual[i].SetPgRot(1);//swap if better player for starting
					actual[j].SetPgRot(2);
				}
			}
		}

        if(actual[i].GetSfRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSgRot() == 1  && (actual[i].GetReb()+actual[i].GetAst()) > (actual[j].GetReb()+actual[j].GetAst()))
				{
					actual[i].SetSgRot(1);//swap if better player for starting
					actual[j].SetSgRot(2);
				}
			}
		}

        if(actual[i].GetSgRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSfRot() == 1 && actual[i].GetReb() > actual[j].GetReb())
				{
					actual[i].SetSfRot(1);//swap if better player for starting
					actual[j].SetSfRot(2);
				}
			}
		}

        if(actual[i].GetSfRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetPfRot() == 1  && actual[i].GetReb() > actual[j].GetReb())
				{
					actual[i].SetPfRot(1);//swap if better player for starting
					actual[j].SetPfRot(2);
				}
			}
		}

        if(actual[i].GetPfRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetSfRot() == 1  && actual[i].GetAst() > actual[j].GetAst())
				{
					actual[i].SetSfRot(1);//swap if better player for starting
					actual[j].SetSfRot(2);
				}
			}
		}

        if(actual[i].GetPfRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetCRot() == 1 && (actual[i].GetReb() + actual[i].GetBlk()) > (actual[j].GetReb()+actual[j].GetBlk()))
				{
					actual[i].SetCRot(1);//swap if better player for starting
					actual[j].SetCRot(2);
				}
			}
		}

        if(actual[i].GetCRot() == 2)        
		{
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[i].GetTradeTrueRating(career) > actual[j].GetTradeTrueRating(career)  &&
					actual[j].GetPfRot() == 1 && (actual[i].GetReb() + actual[i].GetAst()) > (actual[j].GetReb()+actual[j].GetAst()))
				{
					actual[i].SetPfRot(1);//swap if better player for starting
					actual[j].SetPfRot(2);
				}
			}
		}

		

		}

			double starter[6] = {0,0,0,0,0,0};//get starter minutes
			bool is_starter[61];
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[j].m_min == 0) continue;
				double mpg = (double) actual[j].GetMin() / (double) actual[j].GetGames();
				if(actual[j].GetPgRot() == 1)
				{
					starter[1] = mpg;
					is_starter[j] = true;
				}
				else if(actual[j].GetSgRot() == 1)
				{
					starter[2] = mpg;
					is_starter[j] = true;
				}
				else if(actual[j].GetSfRot() == 1)
				{
					is_starter[j] = true;
					starter[3] = mpg;
				}
				else if(actual[j].GetPfRot() == 1)
				{
					starter[4] = mpg;
					is_starter[j] = true;
				}
				else if(actual[j].GetCRot() == 1)
				{
					starter[5] = mpg;
					is_starter[j] = true;
				}

			}


			//adjust true of backup
			for(int j=offset; j<=offset+19; j++)
			{
				if(actual[j].m_min == 0) continue;
				double f = 0;

				if(actual[j].GetPgRot() == 2) f = f + (48-starter[1]);
				if(actual[j].GetSgRot() == 2) f = f + (48-starter[2]);
				if(actual[j].GetSfRot() == 2) f = f + (48-starter[3]);
				if(actual[j].GetPfRot() == 2) f = f + (48-starter[4]);
				if(actual[j].GetCRot() == 2) f = f + (48-starter[5]);

				if(actual[j].GetPos() == "PG" && actual[j].GetPgRot() == 0 || actual[j].GetPgRot() > 2) f = f + starter[1]/10;
				if(actual[j].GetPos() == "SG" && actual[j].GetSgRot() == 0 || actual[j].GetSgRot() > 2) f = f + starter[2]/10;
				if(actual[j].GetPos() == "SF" && actual[j].GetSfRot() == 0 || actual[j].GetSfRot() > 2) f = f + starter[3]/10;
				if(actual[j].GetPos() == "PF" && actual[j].GetPfRot() == 0 || actual[j].GetPfRot() > 2) f = f + starter[4]/10;
				if(actual[j].GetPos() == " C" && actual[j].GetCRot() == 0 || actual[j].GetCRot() > 2) f = f + starter[5]/10;

				double mpg = (double) actual[j].GetMin() / (double)actual[j].GetGames();
				double adj_mpg = f / mpg;
				if(adj_mpg > 1) adj_mpg = 1;
				if(f > 0 && is_starter[j] != true)
					actual[j].m_tradeValue = actual[j].m_tradeValue * adj_mpg;
				

				trade_values[j] = actual[j].m_tradeValue;

			}

	}



}

	


void CAverage::ComputerNegotiatesContracts()
{
	double avgTru = m_avg_trade_tru[0];

	int days_passed = (m_sched.m_currentMonth - m_sched.m_first_mo)*30 +
		(m_sched.m_currentDay - m_sched.m_first_da);



	for(int t=1; t<=m_settings.m_numberteams; t++)
	{
		if(m_settings.m_player_gm[t-1] == "Player") continue;

	int offset = 1 + (t-1)*30;	
	m_owner[t-1].SetRosterValue(m_actual, offset);
	m_owner[t-1].CurrentPayroll(m_actual, offset, true);
	m_owner[t-1].m_temp_payroll[1] = m_owner[t-1].m_current_payroll[1];


	for(int i=offset; i<=offset+29; i++)
	{
		if(m_actual[i].m_name == "" || m_actual[i].m_current_contract_yr != m_actual[i].m_contract_yrs) continue;
		double player_val = m_actual[i].m_tradeTrueRating / avgTru * 2;
		double loyalty_val = .7 + (double)m_actual[i].m_loyalty_factor / 10.;
		double team_val = (double)m_owner[t-1].m_rosterValue / 100.;
		double record_val = m_standings[t-1].m_leaguePct;
		double season_pt = (double)days_passed / m_sched.m_days_in_season;
		if(season_pt < .25) record_val = .5;//before 1st quarter of season dont account for team record
		double payroll_val = (double)m_owner[t-1].m_current_payroll[1] * 10 / (double)m_finance[t-1].m_owner_salary_cap * 2;
		double sc = player_val*loyalty_val*team_val*record_val*payroll_val;
		if(Random(1) < (sc*1 / m_sched.m_days_in_season)) 
		{
			//offer extension
			m_owner[t-1].m_owner_salary_cap = m_finance[t-1].m_owner_salary_cap;
			if(m_settings.m_financial_on == false)
				m_owner[t-1].m_owner_salary_cap = 355000;
			m_owner[t-1].SetTopFreeAgentExtension(m_actual[i], m_gm[t-1]);
			m_owner[t-1].SetPositionValues(m_actual, t*30+1, m_coach[t-1]);

			double pos_value[6] = {0,0,0,0,0,0};
			double avg_pv[6] = {0,0,0,0,0,0};
			double t_pv[6] = {0,0,0,0,0,0};

			int franchise_win = m_owner[t-1].m_win;
			int franchise_loss = m_owner[t-1].m_loss;
	

			for(int j=1; j<=5; j++)
			{
				pos_value[j] = m_owner[t-1].m_position_values[j];
				t_pv[j] = t_pv[j] + m_owner[t-1].m_position_values[j];
			}	

	

			for(int j=1; j<=5; j++)
			{
				avg_pv[j] = t_pv[j] / m_settings.m_numberteams;
			}	

			CStaff coach = m_coach[t-1];
			int coach_rating1 = (coach.m_pot1Rating + coach.m_pot2Rating + coach.m_effortRating + coach.m_scoringRating + coach.m_shootingRating + coach.m_reboundingRating + coach.m_passingRating + coach.m_defenseRating)*1;
			int coach_rating2 = (coach.m_coachPot1 + coach.m_coachPot2 + coach.m_coachEffort + coach.m_coachScoring + coach.m_coachShooting + coach.m_coachRebounding + coach.m_coachPassing + coach.m_coachDefense)*3;
			int coach_rating3 = (coach.m_coachO + coach.m_coachP + coach.m_coachI + coach.m_coachF + coach.m_coachOD + coach.m_coachPD + coach.m_coachID + coach.m_coachFD)*3;
			int coach_rating4 = (coach.m_personality)*24;
			int coach_rating = coach_rating1 + coach_rating2 + coach_rating3 + coach_rating4;

			m_actual[i].SetTrueRating(m_avg_tru[0], true);			
			int seeking_factor = m_actual[i].SetExtensionRequests(franchise_win, franchise_loss, avg_pv, pos_value, coach_rating, false, m_sched.m_games_in_season);
			int total_salary_offer = m_owner[t-1].m_top_free_agent_total_salary[1];
			int year_offer = m_owner[t-1].m_top_free_agent_years[1];
			bool m_signed_extension = m_actual[i].AcceptComputerExtension(seeking_factor, year_offer, total_salary_offer);
			if(m_signed_extension == true)
			{
				m_actual[i].m_contract_salaries[1] = m_actual[i].m_contract_salaries[m_actual[i].m_current_contract_yr];

				m_actual[i].m_current_contract_yr = 1;
				m_actual[i].m_contract_yrs = m_owner[t-1].m_top_free_agent_years[1] + 1;
				
				m_actual[i].m_contract_salaries[2] = m_owner[t-1].m_top_free_agent_salaries[1][1];
				m_actual[i].m_contract_salaries[3] = m_owner[t-1].m_top_free_agent_salaries[1][2];
				m_actual[i].m_contract_salaries[4] = m_owner[t-1].m_top_free_agent_salaries[1][3];
				m_actual[i].m_contract_salaries[5] = m_owner[t-1].m_top_free_agent_salaries[1][4];
				m_actual[i].m_contract_salaries[6] = m_owner[t-1].m_top_free_agent_salaries[1][5];

				m_actual[i].m_is_free_agent = false;
				m_actual[i].m_signed = true;
				int sal = 0 ;
				for(int y=1; y<=m_actual[i].m_contract_yrs; y++)
				{
					sal = sal + m_actual[i].m_contract_salaries[y];
				}
				m_actual[i].m_remaining_salary = sal;
				m_actual[i].m_total_salary = sal;

				m_settings.m_number_transactions = m_settings.m_number_transactions + 1;


				CString string;
				int mo = m_sched.m_currentMonth + 10;
				if(mo > 12) mo = mo - 12;
				int da = m_sched.m_currentDay + 1;
				int yr = m_settings.m_currentYear;
				int ty = 5;//trade
				int team = m_actual[i].m_current_team + 1;
				int id = m_actual[i].m_id;
				int yr_ex = m_actual[i].m_contract_yrs - 1;
				int sa_ex = m_actual[i].m_remaining_salary - m_actual[i].m_current_yr_salary;

				string.Format("%2d%2d%4d%2d%2d%6d%d%5d", mo, da, yr, ty, team, id, yr_ex, sa_ex);                          			
				m_trans_str[m_settings.m_number_transactions] = string;

			}

		}	


	}


	}

}


void CAverage::UpdateStaffStats(int *tempRosterValues, CRecord *record)
{
	//CFileStatus status;
	//CString fileName = m_path + m_leagueName + ".fro";
	//CFile f( fileName, CFile::modeReadWrite );
//	int tempRosterValues[33];
	int i=0;
	for(int c = 1; c<=300; c++)
	{
		if(c == 1 || c == 101 || c == 201) i = 0;
		if(i>31) continue;

		CStaff m_staff;
		if(c<=100)
			m_staff = m_scout[i];
		else if(c<=200)
			m_staff = m_coach[i];
		else
			m_staff = m_gm[i];



		int career_win = m_staff.m_win;

		int career_loss = m_staff.m_loss;

		int playoff = m_staff.m_playoffs;

		int ring = m_staff.m_rings;


		int old_roster_value = tempRosterValues[i];
		int current_roster_value = m_owner[i].m_rosterValue;

		int status = m_staff.m_points;

		if(c<=100)
			m_staff.m_points = m_owner[i].GmStatus(status, old_roster_value, current_roster_value, career_win, career_loss, record[i]);
		else if(c<=200)
			m_staff.m_points = m_owner[i].ScoutStatus(status, old_roster_value, current_roster_value, career_win, career_loss, record[i]);
		else
			m_staff.m_points = m_owner[i].CoachStatus(status, old_roster_value, current_roster_value, career_win, career_loss, record[i]);

		//end evaluation function

		int win = record[i].m_leagueRecord / 100;
		int loss = record[i].m_leagueRecord - win*100;

		career_win = career_win + win;
		career_loss = career_loss + loss;
		m_staff.m_playoffs = m_staff.m_playoffs + record[i].m_playoff;
		m_staff.m_rings = m_staff.m_rings + record[i].m_ring;
		m_staff.m_win = career_win;
		m_staff.m_loss = career_loss;
	
				
		if(c <= 100)
		{
			m_owner[i].m_rosterValue = current_roster_value;
			m_owner[i].m_win = m_owner[i].m_win + win;
			m_owner[i].m_loss = m_owner[i].m_loss + loss;
		}


		if(c<=100)
			m_scout[i] = m_staff;
		else if(c<=200)
			m_coach[i] = m_staff;
		else
			m_gm[i] = m_staff;

		
		i = i + 1;

	}

}

void CAverage::VerifyRosters(int t, bool &valid_rosters, bool &dont_sign, bool &release_player)
{

		int pg = 0, sg = 0, sf = 0, pf = 0, c = 0, count = 0, eligible_players = 0, player_count = 0, active_roster = 0;
		bool on_injured_list = false;
		for(int p=1; p<=30; p++)
		{
			int slot = t*30 + p;
			if(m_actual[slot].m_name != "") 
				player_count = player_count + 1;

			if(m_actual[slot].GetInjury() >= 5) on_injured_list = true;

		//	if(m_actual[slot].m_name != "" && m_actual[slot].m_active == 1) 
			if(m_actual[slot].m_name != "") 
				active_roster = active_roster + 1;

//			if(m_actual[slot].m_name != "" && m_actual[slot].m_active == 1 && m_actual[slot].GetInjury() == 0)
			if(m_actual[slot].m_name != "" && m_actual[slot].GetInjury() == 0)
				eligible_players = eligible_players + 1;

			if(m_actual[slot].GetInjury() > 0 || m_actual[slot].m_name == "") continue;


			if((m_actual[slot].m_pos == "PG" || m_actual[slot].GetPgRot() >= 1)
				&& m_actual[slot].m_active == 1) pg = pg + 1;
			if((m_actual[slot].m_pos == "SG" || m_actual[slot].GetSgRot() >= 1)
				&& m_actual[slot].m_active == 1) sg = sg + 1;
			if((m_actual[slot].m_pos == "SF" || m_actual[slot].GetSfRot() >= 1)
				&& m_actual[slot].m_active == 1) sf = sf + 1;
			if((m_actual[slot].m_pos == "PF" || m_actual[slot].GetPfRot() >= 1)
				&& m_actual[slot].m_active == 1) pf = pf + 1;
			if((m_actual[slot].m_pos == " C" || m_actual[slot].GetCRot() >= 1)
				&& m_actual[slot].m_active == 1) c = c + 1;
		}

		if(pg<1 || sg<1 || sf<1 || pf<1 || c<1 || eligible_players < 9 && m_settings.m_player_gm[t] != "Player")
			valid_rosters = false;
//		if((pg<1 || sg<1 || sf<1 || pf<1 || c<1 || active_roster < 9)
		if(active_roster < 9
			&& m_settings.m_player_gm[t] == "Player")
			valid_rosters = false;
				
		if(player_count >= 16 && valid_rosters == true) release_player = true;
		else if(player_count == 15 && valid_rosters == false) release_player = true;
		
		if(valid_rosters == false)
			dont_sign = false;



}

void CAverage::SortTeamRosters(CPlayer *actual, bool ok_erase)
{
CPlayer* pl = new CPlayer[1601];//start here

BOOL career = TRUE;



for(int  team=1; team<=m_settings.m_numberteams; team++)
{

	int offset = (team-1)*30 + 1;
	bool used[31];
	for(int i=0; i<=30; i++)
	{
		used[i] = false;
	}
	int rosterSlot = offset;
	for(int p=1; p<=6; p++)
	{
		int f=2;
		if(p==6) f=10;
		for(int d=1; d<=f; d++)
		{
			double hi= -9999999;
			int slot=-1;
			for(int i=offset; i<=offset+29; i++)
			{
			
				
				
				
				CPlayer m_player = actual[i];
			



                //bool ok = (m_player.GetPrFga() >= 5 && m_player.GetPrFta() >= 5 && m_player.GetPrFgp() > 4/14);
                bool ok = (m_player.GetPrFga() >= 5 && m_player.GetPrFta() >= 5 && m_player.GetPrFgp() > 4/14 && m_player.GetFgm() > 4 && m_player.GetFtm() > 2);				
				if(ok_erase == false) ok = true;
				int yrsToPrime = m_player.GetPrime() - m_player.GetAge();

               
				if(m_player.GetName() == "" || ok == false) continue;
				int prospectPoints = m_player.GetPot1() + m_player.GetPot2() + m_player.GetEffort();
                bool prospect = (yrsToPrime >= 7) && (prospectPoints > (6 - m_gm[team-1].m_power2) + 8);
                m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_coach[team-1].m_scoring, m_coach[team-1].m_shooting, m_coach[team-1].m_rebounding, m_coach[team-1].m_passing, m_coach[team-1].m_defense);
	            m_player.SetTradeTrueRating(0);
	            m_player.SetAdjTradeValue(m_coach[team-1].m_pot1, m_coach[team-1].m_pot2, m_coach[team-1].m_effort);


				
				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

				int rem =  m_player.m_remaining_salary;

				double tr =  m_player.GetTradeValue() * yrs_left; 
				double under_paid =	tr - (double) rem / 100;
				if(under_paid < 0) under_paid = -under_paid;
				double value = 0;
				value =  under_paid*400 / (double)m_finance[team-1].m_current_value;
				double tr_value = m_player.GetTradeValue() + value;



				
				
				if(tr_value  > hi
					&& used[i-offset] == false
					&& p==1 && m_player.GetPos() == "PG")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==2 && m_player.GetPos() == "SG")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==3 && m_player.GetPos() == "SF")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==4 && m_player.GetPos() == "PF")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==5 && m_player.GetPos() == " C")		
				{
					hi = tr_value;
					slot = i;
				}
				else if( (tr_value  > hi || prospect == true)
					&& used[i-offset] == false
					&& p==6 )		
				{
					hi = tr_value;
					if(prospect == true) hi = 9999999;
					slot = i;
				}
			}
			if(slot > -1)
			{
				used[slot-offset] = true;
				pl[rosterSlot] = actual[slot];
				pl[rosterSlot].SetRosterNumber(rosterSlot);
				rosterSlot = rosterSlot + 1;
			}
		}

	}





	for(int i=offset; i<=offset+29; i++)
	{
		actual[i] = pl[i];
		actual[i].m_current_team = team-1;
	}

}


delete [] pl;
}



void CAverage::SortTeamRoster(int team, int s1, int s2, CPlayer *actual, bool ok_erase)
{

CPlayer* pl = new CPlayer[31];//start here

BOOL career = TRUE;



//for(int  team=1; team<=m_settings.m_numberteams; team++)
//{

	int offset = s1;
	bool used[31];
	for(int i=0; i<=30; i++)
	{
		used[i] = false;
	}
	int rosterSlot = 1;
	for(int p=1; p<=6; p++)
	{
		int f=2;
		if(p==6) f=10;
		for(int d=1; d<=f; d++)
		{
			double hi= -9999999;
			int slot=-1;
			for(int i=s1; i<=s2; i++)
			{
			
				
				
				
				CPlayer m_player = actual[i];
			



                bool ok = (m_player.GetPrFga() >= 5 && m_player.GetPrFta() >= 5 && m_player.GetPrFgp() > 4/14 && m_player.GetFgm() > 4 && m_player.GetFtm() > 2);
				if(ok_erase == false) ok = true;
				int yrsToPrime = m_player.GetPrime() - m_player.GetAge();

               
				if(m_player.GetName() == "" || ok == false) continue;
				int prospectPoints = m_player.GetPot1() + m_player.GetPot2() + m_player.GetEffort();
                bool prospect = (yrsToPrime >= 7) && (prospectPoints > (6 - m_gm[team-1].m_power2) + 8);
                m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_coach[team].m_scoring, m_coach[team].m_shooting, m_coach[team].m_rebounding, m_coach[team].m_passing, m_coach[team].m_defense);
	            m_player.SetTradeTrueRating(0);
	            m_player.SetAdjTradeValue(m_coach[team].m_pot1, m_coach[team].m_pot2, m_coach[team].m_effort);


				
				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

				int rem =  m_player.m_remaining_salary;

				double tr =  m_player.GetTradeValue() * yrs_left; 
				double under_paid =	tr - (double) rem / 100;
				if(under_paid < 0) under_paid = -under_paid;
				double value = 0;
				value =  under_paid*400 / (double)m_finance[team].m_current_value;
				double tr_value = m_player.GetTradeValue() + value;



				
				
				if(tr_value  > hi
					&& used[i-offset] == false
					&& p==1 && m_player.GetPos() == "PG")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==2 && m_player.GetPos() == "SG")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==3 && m_player.GetPos() == "SF")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==4 && m_player.GetPos() == "PF")		
				{
					hi = tr_value;
					slot = i;
				}
				else if(tr_value  > hi
					&& used[i-offset] == false
					&& p==5 && m_player.GetPos() == " C")		
				{
					hi = tr_value;
					slot = i;
				}
				else if( (tr_value  > hi || prospect == true)
					&& used[i-offset] == false
					&& p==6 )		
				{
					hi = tr_value;
					if(prospect == true) hi = 9999999;
					slot = i;
				}
			}
			if(slot > -1)
			{
				used[slot-offset] = true;
				pl[rosterSlot] = actual[slot];
				pl[rosterSlot].SetRosterNumber(rosterSlot);
				rosterSlot = rosterSlot + 1;
			}
		}

	}




	int co = 1;
	for(int i=offset; i<=offset+29; i++)
	{
		actual[i] = pl[co];
		co = co + 1;
	}





//}


delete [] pl;

}




void CAverage::CalculateCareerStats(CString file_name)
{
	CFile file( file_name, CFile::modeRead );
	char s[17];


for(int p=1; p<=1440; p++)
{

	CPlayer m_player = m_actual[p];
	if(m_player.m_name == "") continue;

	int id = m_player.GetID();

for(int y=0; y<=23; y++)
{


			long int seek = id*2500 + 1; 
			file.Seek( seek, CFile::begin);

			int bytes = file.Read(s, 2);
			s[bytes] = 0;
			int year = atoi(s);

			bytes = file.Read(s, 2);
			s[bytes] = 0; 
			int prime = atoi(s);

			bytes = file.Read(s, 1);
			s[bytes] = 0; 
			int pt1 = atoi(s);

			bytes = file.Read(s, 1);
			s[bytes] = 0; 
			int pt2 = atoi(s);

			bytes = file.Read(s, 1);
			s[bytes] = 0; 
			int eff = atoi(s);
			m_player.SetEffort(eff);
			m_player.SetPot1(pt1);
			m_player.SetPot2(pt2);
			m_player.SetPrime(prime);






	seek = id*2500 + 64 + y*100; 


	file.Seek( seek, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int number = atoi(s);
	if(number == 0) continue;

	m_player.m_car_games = m_player.m_car_games + number;

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_min = m_player.m_car_min + number;

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_fgm = m_player.m_car_fgm + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_fga = m_player.m_car_fga + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_ftm = m_player.m_car_ftm + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_fta = m_player.m_car_fta + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_tfgm = m_player.m_car_tfgm + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_tfga = m_player.m_car_tfga + number;
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_oreb = m_player.m_car_oreb + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_reb = m_player.m_car_reb + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_ast = m_player.m_car_ast + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_stl = m_player.m_car_stl + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_to = m_player.m_car_to + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_blk = m_player.m_car_blk + number;
	
	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_player.m_car_pf = m_player.m_car_pf + number;
	

	
}

	long int seek = id*2500 + 2426; 
	file.Seek( seek, CFile::begin);

	int bytes = file.Read(s, 1);
	s[bytes] = 0;
	m_player.m_round_selected = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	m_player.m_pick_selected = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int overall = atoi(s);

	m_actual[p] = m_player;

}

	file.Close();




}

void CAverage::CalculateCareerAwards(CString file_name)
{

	CString awards[512];

	CFile file(	file_name, CFile::modeReadWrite);	
	CString buffer;
	char s[33];


	for(int p=1; p<=1440; p++)
	{

	int count = 0;
	int id = m_actual[p].GetID();

	if(id == 0) continue;
 	
	int seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);

	CString place[6] = {"", "1st", "2nd", "3rd", "4th", "5th"};
	bool skip = false;

	for(int y=0; y<=20; y++)
	{

		int yr = start_yr + y;
		if(yr > m_settings.m_currentYear)
		{

			int seek = 2000 + id*500 + 680 + (y*15);
			char buffer[501];
			int spc = (2000 + id*500 + 1176) - seek; 	
			memset( buffer, ' ', 500);
			file.Seek( seek, CFile::begin);
			file.Write( buffer, spc);
			skip = true;

		}


		if(skip == true) continue;



		int mvp_seek = 2000 + id*500 + 680 + (y*15);
		file.Seek( mvp_seek, CFile::begin);
 		int bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int mvp = atoi(s);
		if(mvp > 0 && mvp <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d most valuable player (%s)", yr, place[mvp]);
			awards[count] = string;
			count = count + 1;
		}

		int defense_seek = 2000 + id*500 + 681 + (y*15);
		file.Seek( defense_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int defense = atoi(s);
		if(defense > 0 && defense <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d defensive player of the year  (%s)", yr, place[defense]);
			awards[count] = string;
			count = count + 1;
		}

		int rookie_seek = 2000 + id*500 + 682 + (y*15);
		file.Seek( rookie_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int rookie = atoi(s);
		if(rookie > 0 && rookie <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie of the year (%s)", yr, place[rookie]);
			awards[count] = string;
			count = count + 1;
		}

		int pts_seek = 2000 + id*500 + 683 + (y*15);
		file.Seek( pts_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int pts = atoi(s);
		if(pts > 0 && pts <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d scoring (%s)", yr, place[pts]);
			awards[count] = string;
			count = count + 1;
		}

		int reb_seek = 2000 + id*500 + 684 + (y*15);
		file.Seek( reb_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int reb = atoi(s);
		if(reb > 0 && reb <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rebounds (%s)", yr, place[reb]);
			awards[count] = string;
			count = count + 1;
		}

		int ast_seek = 2000 + id*500 + 685 + (y*15);
		file.Seek( ast_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ast = atoi(s);
		if(ast > 0 && ast <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d assists (%s)", yr, place[ast]);
			awards[count] = string;
			count = count + 1;
		}

		int stl_seek = 2000 + id*500 + 686 + (y*15);
		file.Seek( stl_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int stl = atoi(s);
		if(stl > 0 && stl <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d steals (%s)", yr, place[stl]);
			awards[count] = string;
			count = count + 1;
		}

		int blk_seek = 2000 + id*500 + 687 + (y*15);
		file.Seek( blk_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int blk = atoi(s);
		if(blk > 0 && blk <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d blocks (%s)", yr, place[blk]);
			awards[count] = string;
			count = count + 1;
		}

		int ring_seek = 2000 + id*500 + 688 + (y*15);
		file.Seek( ring_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ring = atoi(s);
		if(ring > 0)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d championship", yr);
			awards[count] = string;
			count = count + 1;
		}

		int po_mvp_seek = 2000 + id*500 + 689 + (y*15);
		file.Seek( po_mvp_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int po_mvp = atoi(s);
		if(po_mvp > 0 )
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d playoff mvp", yr);
			awards[count] = string;
			count = count + 1;
		}

		int sth_seek = 2000 + id*500 + 690 + (y*15);
		file.Seek( sth_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int sth = atoi(s);
		if(sth > 0 && sth <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d 6th man (%s)", yr, place[sth]);
			awards[count] = string;
			count = count + 1;
		}

		int seek = 2000 + id*500 + 691 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all league %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}

		seek = 2000 + id*500 + 692 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all defense %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}

		seek = 2000 + id*500 + 693 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all rookie %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}



	long int asw_seek = 2000 + id*500 + 694 + (y*15);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star mvp", yr);
			awards[count] = string;
			count = count + 1;
		}


		asw_seek = 2000 + id*500 + 995 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game mvp", yr);
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 996 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest champ", yr);
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 997 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest champ", yr);
			awards[count] = string;
			count = count + 1;
		}


	}


	if(start_yr < 1000)
	{
		int seek = 2000 + id*500 + 676; 	
		char buffer[501];
		memset( buffer, ' ', 500);
		file.Seek( seek, CFile::begin);
		file.Write( buffer, 500);
	}


	}

}



