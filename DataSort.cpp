#include "stdafx.h"
#include "bball.h"

#include "DataSort.h"

//#ifndef BBallFile_h
#include "BBallFile.h"
//#define BBallFile_h
//#endif 




void CDataSort::SortRookies()
{

	CBBallFile* disk = new CBBallFile;
	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name;
	if(disk->FileExists(file_name + ".roo") == true)
		file_name = file_name + ".roo";
	else
		file_name = file_name + ".kie";

	CPlayer Rookies[97];
	disk->OpenRookies(file_name, Rookies);
	for(int i=1; i<=96; i++)
	{
		avg.m_actual[i] = Rookies[i];
	}
	delete disk;

	SetRatings(96);
	QuickSort(96);

}

void CDataSort::SortFA()
{


	SetRatings(1440);
	QuickSort(1440);

}

void CDataSort::SetRatings(int count)
{
	CPlayer m_player;
	for(int i=1; i<=count; i++)
	{
		avg.m_actual[i].m_temp_pointer = i;
		m_player = avg.m_actual[i];
		CStaff scout = avg.m_scout[m_scout_team];		
		m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	
		m_player.SetAdjustedRatings(scout);
		avg.m_actual[i] = m_player;
	}
}


void CDataSort::QuickSort (int items)
{

	int initial_increment = 4;
    int i=0, j=0;
	CPlayer temp;
    int inc = initial_increment;

    while ( inc > 0) 
	{
      for (i=0; i <= items; i++)
	  {
		
        j = i;
        temp = avg.m_actual[i];
		bool swap =  false;

		if(j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

        while (swap == true)
		{
			swap = false;

			avg.m_actual[j] = avg.m_actual[j - inc];
			j = j - inc;

		if(j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

        }
        avg.m_actual[j] = temp;
      }

      if (inc/2 != 0) inc = inc/2;
      else if (inc == 1) inc = 0;
      else inc = 1;

    }
}

bool CDataSort::SortFunction(CPlayer m_contract_i, CPlayer m_contract_j)
{

	int team = m_scout_team;
	bool swap = false;
	m_contract_i.SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);
	double tru1 = m_contract_i.GetTradeValue();
	double tru2 = m_contract_j.GetTradeValue();
	m_contract_i.SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);
	double tru3 = m_contract_i.GetTradeValue();
	double tru4 = m_contract_j.GetTradeValue();
	m_contract_i.SetAdjTradeValue(avg.m_gm[team].m_pot1, avg.m_gm[team].m_pot2, avg.m_gm[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_gm[team].m_pot1, avg.m_gm[team].m_pot2, avg.m_gm[team].m_effort);
	double tru5 = m_contract_i.GetTradeValue();
	double tru6 = m_contract_j.GetTradeValue();

	tru1 = tru1 + tru3 + tru5;
	tru2 = tru2 + tru4 + tru6;

	int ca = 22;

switch(ca) 
{



	case 0:

		swap = m_contract_i.m_pos > m_contract_j.m_pos;
	    break;
    case 1:
		swap = m_contract_i.m_name > m_contract_j.m_name;
        break;
    case 2:
		swap = m_contract_i.m_yrs_of_service < m_contract_j.m_yrs_of_service;
        break;
    case 3:        
		swap = m_contract_i.m_yrs_on_team < m_contract_j.m_yrs_on_team;
        break;
    case 4:
		swap = m_contract_i.m_contract_yrs < m_contract_j.m_contract_yrs;
        break;
    case 5:
		swap = (m_contract_i.m_contract_yrs - m_contract_i.m_current_contract_yr + 1) <
			(m_contract_j.m_contract_yrs - m_contract_j.m_current_contract_yr + 1);
        break;
    case 6:
		swap = m_contract_i.m_total_salary < m_contract_j.m_total_salary;
        break;
    case 7:
		swap = m_contract_i.m_qualifying_offer_years < m_contract_j.m_qualifying_offer_years;
        break;
    case 8:
		swap = m_contract_i.m_total_salary_seeking < m_contract_j.m_total_salary_seeking;
        break;
    case 9:
		swap = m_contract_i.m_year_offer[m_contract_i.m_best_contract] <
			m_contract_j.m_year_offer[m_contract_j.m_best_contract]; 
        break;
    case 10:
		swap = m_contract_i.m_total_salary_offer[m_contract_i.m_best_contract] <
			m_contract_j.m_total_salary_offer[m_contract_j.m_best_contract];
        break;
    case 11:
       break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        break;
    case 17:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
    case 22:
		swap = tru1 < tru2;
        break;

}


return swap;

}


void CDataSort::GetStarters(int team)
{

		for(int  n = 1; n <= 15; n++ )
		{
			int pla = team*30 + n;;
			CPlayer m_player = avg.m_actual[pla];
			if(m_player.GetPos() == "PG" && m_player.GetPgRot() == 0) m_player.SetPgRot(5);
			else if(m_player.GetPos() == "SG" && m_player.GetSgRot() == 0) m_player.SetSgRot(5);
			else if(m_player.GetPos() == "SF" && m_player.GetSfRot() == 0) m_player.SetSfRot(5);
			else if(m_player.GetPos() == "PF" && m_player.GetPfRot() == 0) m_player.SetPfRot(5);
			else if(m_player.GetPos() == " C" && m_player.GetCRot() == 0) m_player.SetCRot(5);

			avg.m_actual[pla] = m_player;

		}

bool used[61];
for(int p=0;p<=60;p++){used[p]=false;}
		


	for(int  position = 1; position <= 5; position++ )
	{
		double CurrentHighMinutes = 0;
		int starter = 0;
		double factor = 0;
		for(int  n = 1; n <= 12; n++ )
		{
			int player = team*30 + n;
			CPlayer m_player = avg.m_actual[player];


			if(m_player.GetName() == "") continue;
			m_player = avg.m_actual[player];
			//set starters
			
	
			if(position == 1 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.GetPgRot()*240) > CurrentHighMinutes
				&& m_player.GetPgRot() > 0  && used[player] != true)
			{
				starter = player;
				factor = 2400 - m_player.GetPgRot()*240;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
			}
			else if(position == 2 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.GetSgRot()*240) > CurrentHighMinutes
				&& m_player.GetSgRot() > 0 && used[player] != true)
			{
				starter = player;
				factor = 2400 - m_player.GetSgRot()*240;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
			}
			else if(position == 3 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.GetSfRot()*240) > CurrentHighMinutes
				&& m_player.GetSfRot() > 0 && used[player] != true)
			{
				starter = player;
				factor = 2400 - m_player.GetSfRot()*240;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
			}
			else if(position == 4 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.GetPfRot()*240) > CurrentHighMinutes
				&& m_player.GetPfRot() > 0 && used[player] != true)
			{
				starter = player;
				factor = 2400 - m_player.GetPfRot()*240;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
			}
			else if(position == 5 && (m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + 2400 - m_player.GetCRot()*240) > CurrentHighMinutes
				&& m_player.GetCRot() > 0 && used[player] != true)
			{
				starter = player;
				factor = 2400 - m_player.GetCRot()*240;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) + factor;
			}
			else if(position == 1 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
				&& m_player.GetPos() == "PG"  && used[player] != true)
			{
				starter = player;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
			}
			else if(position == 2 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
				&& m_player.GetPos() == "SG"  && used[player] != true)
			{
				starter = player;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
			}
			else if(position == 3 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
				&& m_player.GetPos() == "SF"  && used[player] != true)
			{
				starter = player;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
			}
			else if(position == 4 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
				&& m_player.GetPos() == "PF"  && used[player] != true)
			{
				starter = player;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
			}
			else if(position == 5 && m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer) > CurrentHighMinutes
				&& m_player.GetPos() == " C"  && used[player] != true)
			{
				starter = player;
				CurrentHighMinutes = m_player.GetTradeTrueRating(avg.m_settings.m_checkCareer);
			}

			if(position == 1 && m_player.GetPgRot() == 1)
				starter = player;
			else if(position == 2 && m_player.GetSgRot() == 1)
				starter = player;
			else if(position == 3 && m_player.GetSfRot() == 1)
				starter = player;
			else if(position == 4 && m_player.GetPfRot() == 1)
				starter = player;
			else if(position == 5 && m_player.GetCRot() == 1)
				starter = player;


		}
		m_starters[position] = starter;
		used[starter] = true;
	}
}

void CDataSort::FillTeamHistoryStrings()
{

	
	CString str[5001];
	int rings = 0;
    int finals = 0;
	int playoffs = 0;
	int index = m_scout_team;
	CString selectedTeam = avg.m_settings.m_leagueTeamNames[index];
	
	int co = 0;

	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".his";
	CString string;
  	CStdioFile file(pFileName, CFile::modeRead);
	do
	{
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
	

		int pos = string.Find('(');
		CString team = string.Left(pos-1);
		if(team == selectedTeam)
		{
			int pos1 = string.Find("championship");
			if(pos1 >= 0) finals = finals + 1;

			int pos2 = string.Find("lose");
			int pos3 = string.Find("defeat");
			if(pos2 >= 0 || pos3 >= 0) playoffs = playoffs + 1;
			if(pos3 >= 0) rings = rings + 1;

			co = co + 1;
			str[co] = string;
		}
	}
	while(string != "");

	file.Close();
	CString ringString;
	ringString.Format("Championships: %d", rings);
	CString playoffString;
	playoffString.Format("Playoffs: %d", playoffs);
	CString finalsString;
	finalsString.Format("Finals: %d", finals);

	m_history_strings[1] = ringString;
	m_history_strings[2] = playoffString;
	m_history_strings[3] = finalsString;

	m_history_strings[4] = str[co];
	if((co-1) >= 0)
		m_history_strings[5] = str[co-1];
	if((co-2) >= 0)
		m_history_strings[6] = str[co-2];
	if((co-3) >= 0)
		m_history_strings[7] = str[co-3];
	if((co-4) >= 0)
		m_history_strings[8] = str[co-4];


}

void CDataSort::TeamStrengths(int *strong)
{
	double score[] = {0,0,0, 0,0,0};
	for(int i=1; i<=15; i++)	
	{

		int pl = m_scout_team*30 + i;
		CPlayer m_player = avg.m_actual[pl];
		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_gm[m_scout_team].m_scoring, avg.m_gm[m_scout_team].m_shooting, avg.m_gm[m_scout_team].m_rebounding, avg.m_gm[m_scout_team].m_passing, avg.m_gm[m_scout_team].m_defense);
	    m_player.SetTradeTrueRating(0);
        m_player.SetAdjTradeValue(avg.m_gm[m_scout_team].m_pot1, avg.m_gm[m_scout_team].m_pot2, avg.m_gm[m_scout_team].m_effort);



		CString pos = m_player.m_pos;		

		double f = (double)m_player.m_min / (double)m_player.m_games / 48.;
		double sc = m_player.GetTradeValue() * f;	
		if(pos == "PG" || m_player.GetPgRot() == 1)  
			score[1] = score[1] + sc;
		else if(pos == "SG" || m_player.GetSgRot() == 1)  
			score[2] = score[2] + sc;
		else if(pos == "SF" || m_player.GetSfRot() == 1)  
			score[3] = score[3] + sc;
		else if(pos == "PF" || m_player.GetPfRot() == 1)  
			score[4] = score[4] + sc;
		else if(pos == " C" || m_player.GetCRot() == 1)  
			score[5] = score[5] + sc;

	}

	int w = 0, s = 0;
	for(int i=1; i<=5; i++)
	{
		double f=avg.m_team_avg_tru[i];
		if(score[i] > (f * 1.0) )
		{
			strong[i] = 1;
		}
		else if(score[i] < (f * .6) )
		{
			strong[i] = -1;
		}
	}

}

void CDataSort::GetTransactions(CString *str, int type, CTransactions m_trans_list[], int *m_id_list, int *ids)
{

	CString string;
//	char s[129];
//	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".tra";
//	CFile file(	pFileName, CFile::modeRead);
	
//	int bytes = file.Read(s, 16);
//	s[bytes] = 0;
	int n = avg.m_settings.m_number_transactions;
    int t1 = 0, t2 = 0;

	int co=1;
	int month = 0;
	int day = 0;
	int year = 0;
	for(int i=1; i<=n; i++)
	{
//		int seek = (i-1)*128+17;
//		file.Seek( seek, CFile::begin );
//		int bytes = file.Read(s, 128);
//		s[bytes] = 0;
//		string = CString(s);

	//string.Format("%2d%2d%4d%2d%6d%2d%4d%32s", mo, da, yr, ty, avg.m_actual[i].GetID(), avg.m_actual[i].m_current_team + 1, days, str);

		string = avg.m_trans_str[i];
		string = string + "                                                            ";
		month = atoi(string.Mid(0,2));
		day = atoi(string.Mid(2,2));
		year = atoi(string.Mid(4,4));
		int ty = atoi(string.Mid(8,2));
		if(type == ty && ty == 2) 
		{
			//Read Trades
			int col = 0;
			for(int seek = 0; seek <= 76; seek = seek + 19)
			{

				int pic = atoi(string.Mid(seek+10,1));
				if(pic == 0)
				{
					int team1 = atoi(string.Mid(seek+11,6));
					int team2 = atoi(string.Mid(seek+17,6));
					int id = atoi(string.Mid(seek+23,6));
					m_trans_list[co].m_team1[col] = team1;
					m_trans_list[co].m_team2[col] = team2;
					m_trans_list[co].m_id[col] = id;					
					m_trans_list[co].m_pic[col] = 0;					
					m_trans_list[co].m_type = ty;
					m_trans_list[co].m_month = month;
					m_trans_list[co].m_day = day;
					m_trans_list[co].m_year = year;
					//m_id_list[co] = 0;

				}
				else
				{
					int yr = atoi(string.Mid(seek+11,6));
					int rd = atoi(string.Mid(seek+17,6));
					int tm = atoi(string.Mid(seek+23,6));
					m_trans_list[co].m_pick_yr[col] = yr;
					m_trans_list[co].m_pick_rd[col] = rd;
					m_trans_list[co].m_pick_te[col] = tm;					
					m_trans_list[co].m_pic[col] = 1;					
					m_trans_list[co].m_type = ty;
					m_trans_list[co].m_month = month;
					m_trans_list[co].m_day = day;
					m_trans_list[co].m_year = year;
					//m_id_list[co] = 0;
				}
				col = col + 1;
				co = co + 1;

			}

		}
		else if(type >= 3 && type == ty)
		{
			//Read Signings
			int team = atoi(string.Mid(10,2));
			int id = atoi(string.Mid(12,6));
			m_trans_list[co].m_signing_team = team;
			m_trans_list[co].m_signing_id = id;
			m_trans_list[co].m_type = ty;
			//m_id_list[co] = 0;
			m_trans_list[co].m_month = month;
			m_trans_list[co].m_day = day;
			m_trans_list[co].m_year = year;
			co = co + 1;

		}
		else if(type == 1 && type == ty)
		{
		//	Read Injuries


			int id = atoi(string.Mid(10,6));
			int team = atoi(string.Mid(16,2));
			int games = atoi(string.Mid(18,4));
			CString inj = string.Mid(22,32);
			inj.TrimLeft();
			inj.TrimRight();


			bool on_team = false;
			for(int j=1; j<=30; j++)
			{
				if(ids[j] == id && on_team == false) on_team = true;
			}

//			if(team == m_scout_team)
			if(on_team == true)
			{
				m_trans_list[co].m_injury_team = team;
				m_trans_list[co].m_injury_id = id;
				m_trans_list[co].m_injury_games = games;
				m_trans_list[co].m_type = ty;
				//m_id_list[co] = 0;
				m_trans_list[co].m_month = month;
				m_trans_list[co].m_day = day;
				m_trans_list[co].m_year = year;
				m_trans_list[co].m_injury_desc = inj;
				co = co + 1;
			}

		}

	}
    
	//file.Close();		



	int start = co-12;
	int end = co-1;
	if(start < 1) start = 1;
//	if(end > (start + 10)) end = start + 9;

	int li = 1;
	if(start > 0 && end >= start)
	{

		for(int index=start; index<=end; index++)
		{
			int mo = m_trans_list[index].m_month;
			int da = m_trans_list[index].m_day;
			int ye = m_trans_list[index].m_year;
			int typ = m_trans_list[index].m_type;
			int ga = m_trans_list[index].m_injury_games;

			int id = m_trans_list[index].m_injury_id;

			CString inj = m_trans_list[index].m_injury_desc;

			CString name = "";
			int slot = -1;
			for(int i=0; i<=1440; i++)
			{
				if(avg.m_actual[i].m_id == id)
				{
					name = avg.m_actual[i].m_pos + " " + avg.m_actual[i].m_name;
					ga = avg.m_actual[i].GetInjury();//games still out
					slot = i;
				}
			}

			CString months[] = {"Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

			CString c1, c2;
			c1.Format("%s %d %s", months[mo], da, name);
			CString tmp = "day";
			if(ga > 1) tmp = "days";
		
			c2.Format("%s - %d %s", inj, ga, tmp);
			if(ga == 0) c2 = "healthy";
			
			str[li] = c1;		
			str[li+12] = c2;		

			if(slot >= 0) m_id_list[li] = slot;


			li = li + 1;
		}
	}
	else
	{
		str[2] = "no injuries";		
	}


}


void CDataSort::GetScheduleStrings(CString *list)
{
	CString months[] = {"Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep"}; 
	CString m_strings[101];
	int t = m_scout_team;
	int win = 0;
	int loss = 0;
	int lines = 1;
	int row = 1;

	int last_with_score = 1;

	for(int i=0; i<=11; i++)
	{
		for(int j=0; j<=30; j++)
		{
		CString month = months[i];
		int d = j + 1;
		CString day;
		day.Format("%d", d);
		CString date;
		CString Opponent;
		CString result;
		CString other;
		CString sc;
		CString rs;
		CString res;
		date = month + "" + day;

			for(int k=0; k<=15; k++)
			{
			int road = 1;
			CString visitor;
			CString home;
			CString visitorScore;
			CString homeScore;
			Opponent = "";
			result = "";
			int v = 0, h = 0, vs = 0, hs = 0, game = 0, score = 0;
			v = avg.m_sched.m_schedule[i][j][k] / 100;
			h = avg.m_sched.m_schedule[i][j][k] - v * 100;	
			vs = avg.m_sched.m_game_score[i][j][k] / 1000;
			hs = avg.m_sched.m_game_score[i][j][k] - vs * 1000;	
			visitorScore.Format("%d", vs);
			homeScore.Format("%d", hs);
			if(vs == 0 && hs == 0 && v >= 1 && h >= 1 && (v == t || h == t))
			{
				visitorScore = "";
				homeScore = "";
				visitor = avg.m_settings.m_leagueTeamNames[v - 1];
				home = avg.m_settings.m_leagueTeamNames[h - 1];
				result = date + "  " + "@" + home;
				other = "@" + home;
				if(v != t)
				{
					result = date + " " + visitor;
					other = visitor;
					road = 0;
				}
				Opponent.Format("%s", result);

			}
			else if(v >= 1 && h >= 1 && v == t)
			{
				last_with_score = row;
				visitor = avg.m_settings.m_leagueTeamNames[v - 1];
				home = avg.m_settings.m_leagueTeamNames[h - 1];
				result = date + "  " + "@" + home + "  " +
					visitorScore + "-" + homeScore;
				other = "@" + home;
				sc = visitorScore + "-" + homeScore;
				if(vs < hs)
				{
					loss = loss + 1;
					result = result + "  L";
					res = "loss";
				}
				else if(vs > hs)
				{
					win = win + 1;
					result = result + "  W"; 
					res = "win";

				}
				Opponent.Format("%s (%d-%d)", result, win, loss);
	
			}
			else if(v >= 1 && h >= 1 && h == t)
			{
				last_with_score = row;
				visitor = avg.m_settings.m_leagueTeamNames[v - 1];
				home = avg.m_settings.m_leagueTeamNames[h - 1];
				result = date + "  " +  visitor + "  " +
					homeScore + "-" + visitorScore;
				other = visitor;
				sc = homeScore + "-" + visitorScore;
				if(vs < hs)
				{
					result = result + "  W";
					res = "win";
					win = win + 1;
				}
				else if(vs > hs)
				{
					result = result + "  L";
					res = "loss";
					loss = loss + 1;
				}
				Opponent.Format("%s (%d-%d)", result, win, loss);
				road = 0;
			}
			
			if(Opponent != "")
			{
//				CString r = "";
//				if(sc != "") r.Format("%d-%d", win, loss);
//				m_listSchedule.InsertItem(row,date);
//				m_listSchedule.SetItemText(row,1,other);
//				m_listSchedule.SetItemText(row,2,sc);
//				m_listSchedule.SetItemText(row,3,res);
//				m_listSchedule.SetItemText(row,4,r);
//				m_mo_list[row] = i;
//				m_da_list[row] = j;
//				m_ga_list[row] = k;
//				m_v_list[row] = road;
				m_strings[row] = Opponent;
				row = row + 1;
			}
			}
		}
	}		


	int start = last_with_score-4;
	int end =  last_with_score+5;

	if(start<1) start = 1;

	int ctr = 1;
	for(int i=start; i<=end; i++)
	{
		if(m_strings[i] != "")
		{
			list[ctr] = m_strings[i];
			ctr = ctr + 1;
		}
	}

}

void CDataSort::SortStandings(CRecord *standing)
{


	BOOL swap = FALSE;
	for(int t = 0; t <= 31; t++)
	{
		if(standing[t].m_leagueTeamNames == "") continue;
			for(int j = 0; j <= 31; j++)
			{
				swap = FALSE;
				if(standing[j].m_leagueTeamNames == "") continue;

					if(standing[j].m_leaguePct < standing[t].m_leaguePct)
						swap = TRUE;
					else if(standing[j].m_leaguePct == standing[t].m_leaguePct) 
					{
						if(standing[j].m_leagueGamesBack < standing[t].m_leagueGamesBack)
							swap = TRUE;
						else if(standing[j].m_leagueGamesBack == standing[t].m_leagueGamesBack)
						{
								if(standing[j].m_conference == standing[t].m_conference  &&
									standing[j].m_conferencePct < standing[t].m_conferencePct) swap = TRUE;
						}

					}
					if(swap == TRUE)
					{
						swap = FALSE;
						CRecord temp = standing[t];
						standing[t] = standing[j];
						standing[j] = temp;
					}
				
			}

	}

	int w = standing[32].m_leagueRecord / 100;
	int l = standing[32].m_leagueRecord - w * 100;
	double gb = 0;
	for(int t=0; t<=31; t++)
	{
			if(t < avg.m_settings.m_numberteams)//break 2 team ties with head to head results
			{
				int wn = standing[t+1].m_leagueRecord / 100;
				int ln = standing[t+1].m_leagueRecord - w * 100;
				if(w == wn && l == ln)
				{
					int init = standing[t].m_initialNumber + 1;
					int initn = standing[t+1].m_initialNumber + 1;
					if(standing[t].m_vsOpponentPct[initn] < standing[t+1].m_vsOpponentPct[init])
					{
						CRecord temp = standing[t];//swap
						standing[t] = standing[t+1];
						standing[t+1] = temp;
					}
				}
			}
	}
}

