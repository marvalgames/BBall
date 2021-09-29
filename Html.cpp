#include "stdafx.h"
#include "bball.h"
//#ifndef BBall_h
//#include "BBall.h"
//#define BBall_h
//#endif // Added by ClassView
//#include "constants.h"
//#include "resource.h"


#include "Html.h"

#ifndef BBallFile_h
#include "BBallFile.h"
#define BBallFile_h
#endif 

#ifndef DataSort_h
#include "DataSort.h"
#define DataSort_h
#endif 


#include "HistoryAwards.h"

#include <direct.h>


CHtml::CHtml()
{
	m_current_line = 1;

}

CHtml::~CHtml()
{
}

void CHtml::GenerateReports()
{
	InitData();
	_mkdir(m_path + m_league_name);

	//m_font = "<font size = \"1\" face = \"Tahoma\">";
	
	CreatePlayoffTree();
	GenerateAwardsHistory();


	GenerateMainPage();
	GenerateStandings();
	GenerateTeamPages();
	GenerateSchedulePage();
	GenerateTeamSchedules();
	GenerateBoxScores();
	CreateAwardsPage();
	GenerateInjuryPage();
	GenerateTransactionPage();
	GeneratePlayerPages();

	GenerateBudgetPage();
	GenerateRookiePreview();
	GenerateFaPreview();
	GenerateScoutPage();
	GenerateCoachPage();
	GenerateGmPage();



	int result = AfxMessageBox("HTML Creation Complete", MB_OK);
}

void CHtml::GenerateStandings()
{
	m_current_line = 1;
	BeginPage(m_league_name + " Standings");
	AddLine("<table><tr><td><table>");
	SortStandings();
	EndPage();
	CString path = m_path + m_league_name + "\\";
	WritePage(path + "Standings" + ".htm");


}

void CHtml::BeginPage(CString heading)
{



	CString line;
	line.Format("<html><head><title>%s</title></head><body bgcolor = %s text = %s link = %s vlink = %s><pre><table border= \"1\" cellpadding = \"1\">", heading, m_bk_color, m_text_color, m_link_color, m_vlink_color);
	m_strings[m_current_line] = line;
	m_current_line = m_current_line + 1;


	
	line.Format("<style>td{text-align: Left; %s; color:%s; border-width: small; border-style: none; border-color: %s; background-color: %s }th{text-align: Left; %s; color:%s; border-width: small; border-style: none; border-color: %s ; background-color: %s}.tdp { %s; font-weight: bold; text-align: Left; font-size: 10pt; color:%s; border-width: small; border-style: none; border-color: %s; background-color: %s } </style>", m_html_font, m_text_color, m_bk_color, m_bk_color, m_html_font ,"White", "Black", "Black", m_html_font, m_text_color, m_bk_color, m_bk_color);
	m_strings[m_current_line] = line;
	m_current_line = m_current_line + 1;

//	line.Format("<style>th{ %s; color:white; border-width: small; border-style: solid; border-color: navy ; background-color: navy}td      { text-align: Left; %s; color:black; border-width: small; border-style: solid; border-color: white; background-color: white }
//	line.Format("<style>td{ %s; color:white; border-width: small; border-style: solid; border-color: navy ; background-color: navy}td      { text-align: Left; %s; color:black; border-width: small; border-style: solid; border-color: white; background-color: white }.tdp { font-weight: bold; text-align: Left; font-size: 10pt; color:black; border-width: small; border-style: solid; border-color: white; background-color: white } </style>", m_html_font, m_html_font);
//	m_strings[m_current_line] = line;
//	m_current_line = m_current_line + 1;


	CString str;
	str.Format("<th align=\"center\" colspan=\"%d\"><u><b>%s</b></u></th>", 1,heading);
	AddLine(str);

	//WriteTableHeader(1, heading);

}

void CHtml::EndPage()
{
	CString line = "</table></pre></body></html>";	
	m_strings[m_current_line] = line;
	m_current_line = m_current_line + 1;
}


void CHtml::SortStandings()
{
	CDataSort* data = new CDataSort;
	data->SortStandings(avg.m_standings);
	delete data;
	for(int t=1; t<=6; t++)
	{
			
			int gb = 0;
			int init_gb = 0;
			CString check;
		if(t==1)
			check = avg.m_settings.m_conferenceName1;
		else if(t==2)
			check = avg.m_settings.m_conferenceName2;
		else if(t==3)
			check = avg.m_settings.m_divisionName1;
		else if(t==4)
			check = avg.m_settings.m_divisionName2;
		else if(t==5)
			check = avg.m_settings.m_divisionName3;
		else if(t==6)
			check = avg.m_settings.m_divisionName4;


		if(t==3) AddLine("</table></td><td><table>");


			//int d_gb = 0;
			//string = current;
			//last = current;
			// = "<font size = \"2\" face = \"Tahoma\">";
			SetRowString("");
			SetRowString(check);
			CString strings[] = {"","team","league","pct","gb","conf","div","home","away"};
			WriteRow(strings, 8, true, 0);
	BOOL FirstPlace = TRUE;
	int FirstPlaceWin = 0;
	int FirstPlaceLoss = 0;
	for(int i=0; i<=32; i++)
		{
		CString current;
		if(t==1)
			current = avg.m_standings[i].m_conference;
		else if(t==2)
			current = avg.m_standings[i].m_conference;
		else if(t==3)
			current = avg.m_standings[i].m_division;
		else if(t==4)
			current = avg.m_standings[i].m_division;
		else if(t==5)
			current = avg.m_standings[i].m_division;
		else if(t==6)
			current = avg.m_standings[i].m_division;

		CString team = avg.m_standings[i].m_leagueTeamNames + ".htm";
		team.Remove(' ');
		
		if(avg.m_standings[i].m_leagueTeamNames != "" && check == current)
		{

		if(t == 2) current = avg.m_standings[i].m_division;





		//int gb = avg.m_standings[i].m_leagueGamesBack;
		//double d_gb  = ((double)init_gb - (double)gb) / 2;
		double d_gb  = 0;

		// = "<font size = \"1\" face = \"Tahoma\">";
		int w = avg.m_standings[i].m_win;
		int l = avg.m_standings[i].m_loss;
		double pct = avg.m_standings[i].m_leaguePct;


			if(FirstPlace == TRUE)
			{
				//save 1st place teams numbers
				FirstPlace = FALSE;
				d_gb = 0; 
				FirstPlaceWin = w;
				FirstPlaceLoss = l;
			}
			else
			{
				//calculate Games Back
				d_gb = (double(FirstPlaceWin) - double(w) + double(l) - double(FirstPlaceLoss)) / 2; 
			}




		int con_w = avg.m_standings[i].m_conferenceRecord / 100;
		int con_l = avg.m_standings[i].m_conferenceRecord - con_w*100;
		
		int div_w = avg.m_standings[i].m_divisionRecord / 100;;
		int div_l = avg.m_standings[i].m_divisionRecord - div_w*100;
		
		int hom_w = avg.m_standings[i].m_homeRecord / 100;
		int hom_l = avg.m_standings[i].m_homeRecord - hom_w*100;
		
		int vis_w = avg.m_standings[i].m_visitorRecord / 100;
		int vis_l = avg.m_standings[i].m_visitorRecord - vis_w*100;
		
		CString strings[14], strings2, strings3, strings6, strings7, strings8, strings9, strings10, strings11, strings12, strings13;
		strings[1].Format("<a href=\"%s\">%-32s</a>", team, avg.m_standings[i].m_leagueTeamNames); 


		strings2.Format("%d", w); 
		strings3.Format("%d", l); 

		strings6.Format("%d", con_w); 
		strings7.Format("%d", con_l); 

		strings8.Format("%d", div_w); 
		strings9.Format("%d", div_l); 

		strings10.Format("%d", hom_w); 
		strings11.Format("%d", hom_l); 

		strings12.Format("%d", vis_w); 
		strings13.Format("%d", vis_l); 

		strings[2] = strings2 + "-" + strings3;
		strings[3].Format("%5.3f", pct); 
		strings[4].Format("%.1f", d_gb); 

		strings[5] = strings6 + "-" + strings7;
		strings[6] = strings8 + "-" + strings9;
		strings[7] = strings10 + "-" + strings11;
		strings[8] = strings12 + "-" + strings13;

		WriteRow(strings, 8, false, 0);

		
		}


	}


	//CString end_font = "</font>";
	//m_strings[m_current_line] = end_font;
	//m_current_line = m_current_line + 1;

	}	

	AddLine("</table></td></tr></table>");

}

void CHtml::WritePage(CString title)
{


	CBBallFile* file = new CBBallFile;
	if(file->FileExists(title) == true) file->DeleteFile(title);
	file->CreateBlankFile(title, 1);
	delete file;

	CStdioFile fi( title, CFile::modeWrite );
	
	
/*
CString str = "<script type=\"text/javascript\"><!--";
fi.WriteString( str + "\n");		
str = "google_ad_client = \"pub-3171007136355048\";";
fi.WriteString( str + "\n");		
str = "google_ad_width = 234;";
fi.WriteString( str + "\n");		
str = "google_ad_height = 60;";
fi.WriteString( str + "\n");		
str = "google_ad_format = \"234x60_as\";";
fi.WriteString( str + "\n");		
str = "google_ad_channel =\"\";";
fi.WriteString( str + "\n");		
str = "//--></script>";
fi.WriteString( str + "\n");		
str = "<script type=\"text/javascript\"";
fi.WriteString( str + "\n");		
str = " src=\"http://pagead2.googlesyndication.com/pagead/show_ads.js\">";
fi.WriteString( str + "\n");		
str = "</script>";
fi.WriteString( str + "\n");		
*/	
	
	m_current_line = m_current_line - 1;
	if(m_current_line == 0) m_current_line = 1;

	for(int i=1; i<=m_current_line; i++)
	{
		CString string = m_strings[i];
		fi.WriteString( string + "\n");		
	}








	fi.Close(); 
}



void CHtml::GenerateBudgetPage()
{


 
	m_current_line = 1;
	int count = 30;


	BeginPage("");
//	CString header[] = {"", "BUDGET",""};



	CString Stats[] = {"", "team","salary", "scout", "coach", "gm","oper","arena","mark","tick$",
		"att rev", "ste$", "suite", "clb$", "club", "con$", "concess", "park$", "park", "rev", "exp", "profit"};
	// = "<font size = \"2\" face = \"Tahoma\">";
//	WriteRow(header, 1, true, 0);
	WriteTableHeader(1, "FINANCIAL REPORT");
	AddLine("<table><hr>");
	WriteTableHeader(1, "FINANCES");
	WriteRow(Stats, 21, true, 1);

	// = "<font size = \"1\" face = \"Tahoma\">";

	for(int  index = 0; index < avg.m_settings.m_numberteams; index++)
	{
		//int i=index;
		//CTeamFinancial fin = avg.m_finance[index];
		CTeamFinancial* fin = new CTeamFinancial;			
		*fin	= avg.m_finance[index];
		CString Stats[33];
		
		CString na = fin->m_city_name + " " + fin->m_team_name;
		na.MakeUpper();
		CString team = fin->m_team_name + ".htm";
		team.Remove(' ');
		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 

		if(Stats[1] == "") continue;
		double r = (double)fin->m_season_payroll/ 1000000;
		Stats[2].Format("%.2f", r);

		r = (double)fin->m_season_scout_expenses/ 1000000;
		Stats[3].Format("%.2f", r);

		r = (double)fin->m_season_coach_expenses/ 1000000;
		Stats[4].Format("%.2f", r);

		r = (double)fin->m_season_gm_expenses/ 1000000;
		Stats[5].Format("%.2f", r);

		r = (double)fin->m_season_operating_expenses/ 1000000;
		Stats[6].Format("%.2f", r);

		r = (double)fin->m_season_arena_expenses/ 1000000;
		Stats[7].Format("%.2f", r);

		r = (double)fin->m_season_marketing_expenses/ 1000000;
		Stats[8].Format("%.2f", r);


		r = (double)fin->m_ticket_price / 10;
		Stats[9].Format("%.f", r);

		r = (double)fin->m_att_revenue/ 1000000;
		Stats[10].Format("%.2f", r);

		r = (double)fin->m_suite_price;
		Stats[11].Format("%.f", r);

		r = (double)fin->m_season_suite_revenue/ 1000000;
		Stats[12].Format("%.2f", r);

		r = (double)fin->m_club_price;
		Stats[13].Format("%.f", r);

		r = (double)fin->m_season_club_revenue/ 1000000;
		Stats[14].Format("%.2f", r);

		r = (double)fin->m_concessions / 10;
		Stats[15].Format("%.f", r);

		r = (double)fin->m_season_concession_revenue/ 1000000;
		Stats[16].Format("%.2f", r);

		r = (double)fin->m_parking;
		Stats[17].Format("%.f", r);

		r = (double)fin->m_season_parking_revenue/ 1000000;
		Stats[18].Format("%.2f", r);


		r = (double)fin->m_season_total_revenue / 1000000;
		Stats[19].Format("%.2f", r);

		r = (double)fin->m_season_total_expenses/ 1000000;
		Stats[20].Format("%.2f", r);


		r = ((double)fin->m_season_total_revenue - (double)fin->m_season_total_expenses) / 1000000;
		Stats[21].Format("%.2f", r);

		
		///r = ((double)fin->m_season_total_revenue - (double)fin->m_season_total_expenses) / 1000000;
		//Stats[24].Format("%.2f", r);
		delete fin;

		WriteRow(Stats, 21, false, 1);


	}




	AddLine("</table><table>");
	AddLine("<hr>");
	CString string[] = {"", "team", "attend", "attend", "att%", "___", "#ste","suites","ste%","___","#clb","club","clb%","___","#park","park","park%"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	WriteTableHeader(1, "ATTENDANCE");
	WriteRow(string, 16, true, 1);


	for(int index = 0; index < avg.m_settings.m_numberteams; index++)
	{
		//int i=index;
		//CTeamFinancial fin = avg.m_finance[index];
		CTeamFinancial* fin = new CTeamFinancial;			
		*fin	= avg.m_finance[index];
		CString Stats[33];

		double g = (double)fin->m_home_games;
		if(g == 0) g = 1;

		CString na = fin->m_city_name + " " + fin->m_team_name;
		na.MakeUpper();
		CString team = fin->m_team_name + ".htm";
		team.Remove(' ');
		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 


//		CString na = fin->m_city_name + " " + fin->m_team_name;
//		CString team = fin->m_team_name;
//		team.Remove(' ');
//		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 
//		Stats[1].MakeUpper();


//		Stats[1] = fin->m_city_name + " " + fin->m_team_name;
//		Stats[1].MakeUpper();


		if(Stats[1] == "") continue;

		double r = fin->m_capacity;
		Stats[2 ].Format("%.f", r);

		r = (fin->m_season_att + fin->m_season_suites_sold*20 + fin->m_season_clubs_sold) / g;
		Stats[3].Format("%.f", r);

		int pct = int((fin->m_season_att + fin->m_season_suites_sold*20 + fin->m_season_clubs_sold) / ((double)fin->m_capacity * g) * 1000);
		r = (double) pct / 10;
		Stats[4 ].Format("%.2f", r);

		Stats[5] = "___";

		r = fin->m_suites;
		Stats[6 ].Format("%.f", r);

		r = fin->m_season_suites_sold / g;
		Stats[7 ].Format("%.f", r);

		pct = int((double)fin->m_season_suites_sold / ((double)fin->m_suites * g) * 1000);
		r = (double) pct / 10;
		Stats[8 ].Format("%.2f", r);

		Stats[9] = "___";



		r = fin->m_club_seats;
		Stats[10 ].Format("%.f", r);

		r = fin->m_season_clubs_sold / g;
		Stats[11 ].Format("%.f", r);

		pct = int((double) fin->m_season_clubs_sold / ((double)fin->m_club_seats * g) * 1000);
		r = (double) pct / 10;
		Stats[12 ].Format("%.2f", r);

		Stats[13] = "___";


		int d = fin->m_parking_spots;
		Stats[14 ].Format("%d", d);

		if(fin->m_parking == 0) r = 0;
		else r = fin->m_season_parking_revenue / (double)fin->m_parking / g;
		Stats[15 ].Format("%.f", r);

		pct = int((double) fin->m_season_parking_revenue / (double) fin->m_parking / ((double)fin->m_parking_spots * g) * 1000);
		r = (double) pct / 10;
		Stats[16 ].Format("%.2f", r);	

		delete fin;
		WriteRow(Stats, 16, false, 1);

	}





	AddLine("</table><table>");
	AddLine("<hr>");

	

	CString strng[] = {"", "team", "fan support", "population", "loyalty", "competition", "economy", "cost of living", "political support", "arena value", "franchise value"};
	WriteTableHeader(1, "CITIES");
	WriteRow(strng, 10, true, 1);




	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};
	for(int index = 0; index < avg.m_settings.m_numberteams; index++)
	{
		
		CTeamFinancial* fin = new CTeamFinancial;			
		*fin	= avg.m_finance[index];
		//CTeamFinancial fin = avg.m_finance[index];
		CString Stats[33];


		CString na = fin->m_city_name + " " + fin->m_team_name;
		na.MakeUpper();
		CString team = fin->m_team_name + ".htm";
		team.Remove(' ');
		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 

//		CString na = fin->m_city_name + " " + fin->m_team_name;
//		CString team = fin->m_team_name;
//		team.Remove(' ');
//		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 
//		Stats[1].MakeUpper();
		
//		Stats[1] = fin->m_city_name + " " + fin->m_team_name;
//		Stats[1].MakeUpper();

		if(Stats[1] == "") continue;
		int r = fin->m_fan_support;
		Stats[2].Format("%s", lbl[r]);

		r = fin->m_population;
		Stats[3].Format("%s", lbl[r]);

		r = fin->m_interest;
		Stats[4].Format("%s", lbl[r]);

		r = fin->m_competition;
		Stats[5].Format("%s", lbl[r]);

		r = fin->m_economy;
		Stats[6].Format("%s", lbl[r]);

		r = fin->m_cost_of_living;
		Stats[7].Format("%s", lbl[r]);

		r = fin->m_political_support;
		Stats[8].Format("%s", lbl[r]);

		double f_r = (double)fin->m_stadium_value;
		Stats[9].Format("%.f", f_r);

		f_r = (double)fin->m_current_value / 10;
		Stats[10].Format("%.f", f_r);
		delete fin;

		WriteRow(Stats, 10, false, 1);


	}





	AddLine("</table><table>");
	AddLine("<hr>");

	CString stng[] = {"", "team","arena", "local tv deal", "local radio deal", "arena advertising","arena sponsor",
	"arena expenses", "marketing expenses"};	




	WriteTableHeader(1, "DEALS");
	WriteRow(stng, 8, true, 1);


	for(int index = 0; index < avg.m_settings.m_numberteams; index++)
	{
		
		CTeamFinancial* fin = new CTeamFinancial;
			
		*fin	= avg.m_finance[index];
		CString Stats[33];

		CString na = fin->m_city_name + " " + fin->m_team_name;
		na.MakeUpper();
		CString team = fin->m_team_name + ".htm";
		team.Remove(' ');
		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 

//		CString na = fin->m_city_name + " " + fin->m_team_name;
//		CString team = fin->m_team_name;
//		team.Remove(' ');
//		Stats[1].Format("<a href=\"%s\">%-32s</a>", team, na); 
//		Stats[1].MakeUpper();

//		Stats[1] = fin->m_city_name + " " + fin->m_team_name;
//		Stats[1].MakeUpper();

		if(Stats[1] == "") continue;

		Stats[2] = fin->m_arena_name;
		Stats[2].MakeUpper();

		double r = (double)fin->m_local_tv * (double)avg.m_hi_g[0]/ 1000000;
		Stats[3].Format("%.2f", r);
	    r = (double)fin->m_local_radio * (double)avg.m_hi_g[0] / 1000000;
		Stats[4].Format("%.2f", r);
	    r = (double)fin->m_advertising * (double)avg.m_hi_g[0] / 1000000;
		Stats[5].Format("%.2f", r);
	    r = (double)fin->m_sponsorship * (double)avg.m_hi_g[0] / 1000000;
		Stats[6].Format("%.2f", r);

		r = (double)fin->m_arena * (double)avg.m_hi_g[0] / 10000;
		Stats[7].Format("%.2f", r);
	    r = (double)fin->m_marketing * (double)avg.m_hi_g[0] / 10000;
		Stats[8].Format("%.2f", r);

		delete fin;

		WriteRow(Stats, 8, false, 1);


	}




	EndPage();

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "finances" + ".htm");	

}



void CHtml::GenerateTeamPages()
{

CPlayer m_player;

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing Team Pages";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 33);

for(int t=0; t<=32; t++)
{
	dlgProgress.m_progress.SetPos(t+1);
	CString team = avg.m_finance[t].m_team_name;
	if(t == 32) team = "Available";
	if(team == "") continue;


	m_current_line = 1;
	int count = 30;

//	if(m_stage > 0) count = 30;

	BeginPage(team);

	if(t == 32)
		count = 480;
	else
	{

		CString stri[33];
		CString tm = team;
		tm.Remove(' ');
		CString link = tm + "Schedule.htm";
		stri[1] = "<a href=\"" + link + "\">"+ team + " Schedule" + "</a>"; 

		link = "Standings.htm";
		stri[2] = "<a href=\"" + link + "\">"+ m_league_name + " Standings" + "</a>"; 

		// = "<font size = \"2\" face = \"Tahoma\">";
		WriteRow(stri, 2, false, 0);
		// = "<font size = \"1\" face = \"Tahoma\">";

	}


	
	
	
	
	

	CString string[] = {"", "po", "player", "age", "2ga","2g%","fta","ft%","3ga","3g%","orb","drb","ast","stl","to","blk","o-o","d-o","p-o","t-o","o-d","d-d","p-d","t-d"};
	// = "<font size = \"2\" face = \"Tahoma\">";


	WriteTableHeader(1, "Ratings");

	AddLine("<table><hr>");


	WriteRow(string, 23, true, 2);




	for(int p=1; p<=count; p++)
	{
		int index = t*30+p;
		//if(m_stage > 0) index = t*20+p;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;

		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		string[1] = m_player.m_pos;
		if(m_player_page_index == 0) 
			string[2] = m_player.m_name;
		else if(m_player_page_index > 1 && ((t+2) != m_player_page_index || t==32))
			string[2] = m_player.m_name;
		else string[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 
	

		string[3].Format("%d", m_player.m_age);
		string[4].Format("%d", m_player.m_prFga);
		string[5].Format("%d", m_player.m_prFgp);
		string[6].Format("%d", m_player.m_prFta);
		string[7].Format("%d", m_player.m_prFtp);
		string[8].Format("%d", m_player.m_prTga);
		string[9].Format("%d", m_player.m_prTgp);
		string[10].Format("%d", m_player.m_prOrb);
		string[11].Format("%d", m_player.m_prDrb);
		string[12].Format("%d", m_player.m_prAst);
		string[13].Format("%d", m_player.m_prStl);
		string[14].Format("%d", m_player.m_prTo);
		string[15].Format("%d", m_player.m_prBlk);
		string[16].Format("%d", m_player.m_movoff);
		string[17].Format("%d", m_player.m_penoff);
		string[18].Format("%d", m_player.m_postoff);
		string[19].Format("%d", m_player.m_transoff);
		string[20].Format("%d", m_player.m_movdef);
		string[21].Format("%d", m_player.m_pendef);
		string[22].Format("%d", m_player.m_postdef);
		string[23].Format("%d", m_player.m_transdef);
		WriteRow(string, 23, false, 2);
	}

	AddLine("</table><table>");
	AddLine("<hr>");


	CString stringA[] = {"", "po", "player", "g","gs","min","fgm","fga","fgp","ftm","fta","ftp","3gm","3ga","3gp","orb","reb","ast","stl","to","blk","pf","ppg","inj"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	
	WriteTableHeader(1, "Statistics");
	WriteRow(stringA, 23, true, 2);

	// = "<font size = \"1\" face = \"Tahoma\">";


	if(t<=32)
	{
		for(int p=1; p<=count; p++)
		{
		int index = t*30+p;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;


		
		
		stringA[1] = m_player.m_pos;


		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		if(m_player_page_index == 0) 
			stringA[2] = m_player.m_name;
		else if(m_player_page_index > 1 && ((t+2) != m_player_page_index || t==32))
			stringA[2] = m_player.m_name;
		else stringA[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 


		stringA[3].Format("%d", m_player.m_sim_games);
		stringA[4].Format("%d", m_player.m_starter);
		stringA[5].Format("%.2f", m_player.m_sim_minPerGame);
		stringA[6].Format("%d", m_player.m_sim_fgm + m_player.m_sim_tfgm);
		stringA[7].Format("%d", m_player.m_sim_fga + m_player.m_sim_tfga);
		stringA[8].Format("%.2f", m_player.m_sim_fgPct);
		stringA[9].Format("%d", m_player.m_sim_ftm);
		stringA[10].Format("%d", m_player.m_sim_fta);
		stringA[11].Format("%.2f", m_player.m_sim_ftPct);
		stringA[12].Format("%d", m_player.m_sim_tfgm);
		stringA[13].Format("%d", m_player.m_sim_tfga);
		stringA[14].Format("%.2f", m_player.m_sim_tfgPct);
		stringA[15].Format("%.2f", m_player.m_sim_orbPerGame);
		stringA[16].Format("%.2f", m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame);
		stringA[17].Format("%.2f", m_player.m_sim_assistsPerGame);
		stringA[18].Format("%.2f", m_player.m_sim_stealsPerGame);
		stringA[19].Format("%.2f", m_player.m_sim_toPerGame);
		stringA[20].Format("%.2f", m_player.m_sim_blocksPerGame);
		stringA[21].Format("%.2f", m_player.m_sim_pfPerGame);
		stringA[22].Format("%.2f", m_player.m_sim_pointsPerGame);
		stringA[23].Format("%d", m_player.m_injury);
		WriteRow(stringA, 23, false, 2);
	
		}



/*	for( p=0; p<=1; p++)
	{
		int index = 1441 + (p*32) + t;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;
		if(p == 0) m_player.m_pos = "Offense";
		else m_player.m_pos = "Defense";

		stringA[1] = m_player.m_pos;
		stringA[2] = m_player.m_name;
		stringA[3].Format("%d", m_player.m_sim_games);
		stringA[4] = "-";
		stringA[5] = "-";
		stringA[6].Format("%d", m_player.m_sim_fgm + m_player.m_sim_tfgm);
		stringA[7].Format("%d", m_player.m_sim_fga + m_player.m_sim_tfga);
		stringA[8].Format("%.2f", m_player.m_sim_fgPct);
		stringA[9].Format("%d", m_player.m_sim_ftm);
		stringA[10].Format("%d", m_player.m_sim_fta);
		stringA[11].Format("%.2f", m_player.m_sim_ftPct);
		stringA[12].Format("%d", m_player.m_sim_tfgm);
		stringA[13].Format("%d", m_player.m_sim_tfga);
		stringA[14].Format("%.2f", m_player.m_sim_tfgPct);
		stringA[15].Format("%.2f", m_player.m_sim_orbPerGame);
		stringA[16].Format("%.2f", m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame);
		stringA[17].Format("%.2f", m_player.m_sim_assistsPerGame);
		stringA[18].Format("%.2f", m_player.m_sim_stealsPerGame);
		stringA[19].Format("%.2f", m_player.m_sim_toPerGame);
		stringA[20].Format("%.2f", m_player.m_sim_blocksPerGame);
		stringA[21].Format("%.2f", m_player.m_sim_pfPerGame);
		stringA[22].Format("%.2f", m_player.m_sim_pointsPerGame);
		stringA[23].Format("%d", m_player.m_injury);
		WriteRow(stringA, 23, false, 2);
	}*/






	for(int p=0; p<=1; p++)
	{
		int index = 1441 + (p*32) + t;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;
		if(p == 0) m_player.m_pos = "Offense";
		else m_player.m_pos = "Defense";

		stringA[1] = m_player.m_pos;

		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		if(p == 0) head = "";

		str = str + head + ".htm";

		if(m_player_page_index == 0) 
			stringA[2] = m_player.m_name;
		else if(m_player_page_index > 1 && ((t+2) != m_player_page_index || t==32))
			stringA[2] = m_player.m_name;
		else stringA[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 



		stringA[3].Format("%d", m_player.m_sim_games);
		stringA[4] = "-";
		stringA[5] = "-";
		stringA[6].Format("%d", m_player.m_sim_fgm + m_player.m_sim_tfgm);
		stringA[7].Format("%d", m_player.m_sim_fga + m_player.m_sim_tfga);
		stringA[8].Format("%.2f", m_player.m_sim_fgPct);
		stringA[9].Format("%d", m_player.m_sim_ftm);
		stringA[10].Format("%d", m_player.m_sim_fta);
		stringA[11].Format("%.2f", m_player.m_sim_ftPct);
		stringA[12].Format("%d", m_player.m_sim_tfgm);
		stringA[13].Format("%d", m_player.m_sim_tfga);
		stringA[14].Format("%.2f", m_player.m_sim_tfgPct);
		stringA[15].Format("%.2f", m_player.m_sim_orbPerGame);
		stringA[16].Format("%.2f", m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame);
		stringA[17].Format("%.2f", m_player.m_sim_assistsPerGame);
		stringA[18].Format("%.2f", m_player.m_sim_stealsPerGame);
		stringA[19].Format("%.2f", m_player.m_sim_toPerGame);
		stringA[20].Format("%.2f", m_player.m_sim_blocksPerGame);
		stringA[21].Format("%.2f", m_player.m_sim_pfPerGame);
		stringA[22].Format("%.2f", m_player.m_sim_pointsPerGame);
		stringA[23].Format("%d", m_player.m_injury);
		WriteRow(stringA, 23, false, 2);
	}



	AddLine("</table>");
	AddLine("<table><hr><tr><td><table>");

	CString stringP[] = {"", "po", "player", "g","gs","min","fgm","fga","fgp","ftm","fta","ftp","3gm","3ga","3gp","orb","reb","ast","stl","to","blk","pf","ppg","inj"};
	// = "<font size = \"2\" face = \"Tahoma\">";	
	WriteTableHeader(1, "Playoff Statistics");
	WriteRow(stringP, 23, true, 2);


	// = "<font size = \"1\" face = \"Tahoma\">";
	if(t<32)
	{
		for(int p=1; p<=count; p++)
		{
		int index = t*30+p;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;

		stringA[1] = m_player.m_pos;


		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		if(m_player_page_index == 0) 
			stringA[2] = m_player.m_name;
		else if(m_player_page_index > 1 && ((t+2) != m_player_page_index || t==32))
			stringA[2] = m_player.m_name;
		else stringA[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 



		stringA[3].Format("%d", m_player.m_po_games);
		stringA[4] = "-";
		stringA[5].Format("%.2f", m_player.m_po_minPerGame);
		stringA[6].Format("%d", m_player.m_po_fgm + m_player.m_po_tfgm);
		stringA[7].Format("%d", m_player.m_po_fga + m_player.m_po_tfga);
		stringA[8].Format("%.2f", m_player.m_po_fgPct);
		stringA[9].Format("%d", m_player.m_po_ftm);
		stringA[10].Format("%d", m_player.m_po_fta);
		stringA[11].Format("%.2f", m_player.m_po_ftPct);
		stringA[12].Format("%d", m_player.m_po_tfgm);
		stringA[13].Format("%d", m_player.m_po_tfga);
		stringA[14].Format("%.2f", m_player.m_po_tfgPct);
		stringA[15].Format("%.2f", m_player.m_po_orbPerGame);
		stringA[16].Format("%.2f", m_player.m_po_orbPerGame + m_player.m_po_reboundsPerGame);
		stringA[17].Format("%.2f", m_player.m_po_assistsPerGame);
		stringA[18].Format("%.2f", m_player.m_po_stealsPerGame);
		stringA[19].Format("%.2f", m_player.m_po_toPerGame);
		stringA[20].Format("%.2f", m_player.m_po_blocksPerGame);
		stringA[21].Format("%.2f", m_player.m_po_pfPerGame);
		stringA[22].Format("%.2f", m_player.m_po_pointsPerGame);
		stringA[23].Format("%d", m_player.m_injury);
		WriteRow(stringA, 23, false, 2);
	
		}




	for(int p=0; p<=1; p++)
	{
		int index = 1441 + (p*32) + t;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;
		if(p == 0) m_player.m_pos = "Offense";
		else m_player.m_pos = "Defense";

		stringA[1] = m_player.m_pos;
		stringA[2] = m_player.m_name;
		stringA[3].Format("%d", m_player.m_po_games);
		stringA[4] = "-";
		stringA[5] = "-";
		stringA[6].Format("%d", m_player.m_po_fgm + m_player.m_po_tfgm);
		stringA[7].Format("%d", m_player.m_po_fga + m_player.m_po_tfga);
		stringA[8].Format("%.2f", m_player.m_po_fgPct);
		stringA[9].Format("%d", m_player.m_po_ftm);
		stringA[10].Format("%d", m_player.m_po_fta);
		stringA[11].Format("%.2f", m_player.m_po_ftPct);
		stringA[12].Format("%d", m_player.m_po_tfgm);
		stringA[13].Format("%d", m_player.m_po_tfga);
		stringA[14].Format("%.2f", m_player.m_po_tfgPct);
		stringA[15].Format("%.2f", m_player.m_po_orbPerGame);
		stringA[16].Format("%.2f", m_player.m_po_orbPerGame + m_player.m_po_reboundsPerGame);
		stringA[17].Format("%.2f", m_player.m_po_assistsPerGame);
		stringA[18].Format("%.2f", m_player.m_po_stealsPerGame);
		stringA[19].Format("%.2f", m_player.m_po_toPerGame);
		stringA[20].Format("%.2f", m_player.m_po_blocksPerGame);
		stringA[21].Format("%.2f", m_player.m_po_pfPerGame);
		stringA[22].Format("%.2f", m_player.m_po_pointsPerGame);
		stringA[23].Format("%d", m_player.m_injury);
		WriteRow(stringA, 23, false, 2);
	}









	
	CString stringB[] = {"", "pos", "player", "age","year 1","year 2","year 3","year 4","year 5","year 6"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	AddLine("</table>");







	
	//CString stringB[] = {"", "pos", "player", "age","year 1","year 2","year 3","year 4","year 5","year 6"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	//AddLine("</table>");


	AddLine("<table><hr><tr><td><table>");
	WriteTableHeader(1, "Contracts");
	WriteRow(stringB, 9, true, 2);




















	// = "<font size = \"1\" face = \"Tahoma\">";
	for(int p=1; p<=30; p++)
	{
		int index = t*30+p;
		//if(m_stage > 0) index = t*20+p;
		m_player = avg.m_actual[index];
		if(m_player.m_name == "") continue;
		CString str = m_player.m_name;

		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		stringB[1] = m_player.m_pos;
//		stringA[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 

		if(m_player_page_index == 0) 
			stringB[2] = m_player.m_name;
		else if(m_player_page_index > 1 && ((t+2) != m_player_page_index || t==32))
			stringB[2] = m_player.m_name;
		else stringB[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 

		stringB[3].Format("%d", m_player.m_age); 

		int cur = m_player.m_current_contract_yr;
		int c_yr = 4;
		if(cur == 0) cur = 1;
		for(int s=cur; s<=6; s++)
		{
			int r = m_player.m_contract_salaries[s];
			if( r == 0)
			{
				stringB[c_yr] = "";
			}
			else
			{
				stringB[c_yr].Format("%.2f", (double)r/100);
			}
			c_yr = c_yr + 1;
		}

		WriteRow(stringB, c_yr-1, false, 2);

	}
	

	AddLine("</table></td><td><table>");


		CString stringD[33];
		int cou = 1;
		for(int y=1; y<=3; y++)
		{

			for(int r=1; r<=2; r++)
			{
				for(int p=1; p<=32; p++)
				{
					int t1 = avg.m_own[0].m_draft_chart[y][r][p];
					CString string1;
					
					if((t+1) == t1)
					{
						stringD[cou].Format("%d-%d round %d", avg.m_settings.m_currentYear -1 + y, avg.m_settings.m_currentYear  + y, r);
						CString tm = avg.m_settings.m_leagueTeamNames[p-1];
						tm.Remove(' ');
						CString li = tm + ".htm";
						stringD[cou+1].Format("<a href=\"%s\">%s</a>", li, tm);
						cou = cou + 2;
					}
					
				}
			}
		}

		FillList(stringD, "Draft Picks");

	AddLine("</table></td></tr></table>");

	}
	EndPage();

	team.Remove(' ');

	CString path = m_path + m_league_name + "\\";
	WritePage(path + team + ".htm");	

}
}
}

void CHtml::GeneratePlayerPages()
{

	CPlayer m_player;

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing Player Pages";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 1441);




for(int i=0; i<=1440; i++)
{
	dlgProgress.m_progress.SetPos(i+1);
	m_player = avg.m_actual[i];
	CString name = m_player.m_name;
	if(name == "") continue;

		int te = m_player.m_team_index;
		if(m_player_page_index == 0) continue;
		if(m_player_page_index > 1 && ((te+2) != m_player_page_index || te>=32)) continue;

	m_current_line = 1;

	BeginPage(name);
	CString string[] = {"", "pos", "player", "g","gs","min","fgm","fga","fgp","ftm","fta","ftp","3gm","3ga","3gp","orb","reb","ast","stl","to","blk","pf","ppg","inj"};
	CString stringA[33];
	// = "<font size = \"2\" face = \"Tahoma\">";
	WriteRow(string, 23, true, 2);



		string[1] = m_player.m_pos;

			
		
		string[2] = m_player.m_name; 



		string[3].Format("%d", m_player.m_sim_games);
		string[4].Format("%d", m_player.m_starter);
		string[5].Format("%.2f", m_player.m_sim_minPerGame);
		string[6].Format("%d", m_player.m_sim_fgm + m_player.m_sim_tfgm);
		string[7].Format("%d", m_player.m_sim_fga + m_player.m_sim_tfga);
		string[8].Format("%.2f", m_player.m_sim_fgPct);
		string[9].Format("%d", m_player.m_sim_ftm);
		string[10].Format("%d", m_player.m_sim_fta);
		string[11].Format("%.2f", m_player.m_sim_ftPct);
		string[12].Format("%d", m_player.m_sim_tfgm);
		string[13].Format("%d", m_player.m_sim_tfga);
		string[14].Format("%.2f", m_player.m_sim_tfgPct);
		string[15].Format("%.2f", m_player.m_sim_orbPerGame);
		string[16].Format("%.2f",m_player.m_sim_orbPerGame+m_player.m_sim_reboundsPerGame);
		string[17].Format("%.2f", m_player.m_sim_assistsPerGame);
		string[18].Format("%.2f", m_player.m_sim_stealsPerGame);
		string[19].Format("%.2f", m_player.m_sim_toPerGame);
		string[20].Format("%.2f", m_player.m_sim_blocksPerGame);
		string[21].Format("%.2f", m_player.m_sim_pfPerGame);
		string[22].Format("%.2f", m_player.m_sim_pointsPerGame);
		string[23].Format("%d", m_player.m_injury);
		WriteRow(string, 23, false, 2);


		string[1] = "";
		string[2] = ""; 



		string[3].Format("%d", m_player.m_po_games);
		string[4] = "-";
		string[5].Format("%.2f", m_player.m_po_minPerGame);
		string[6].Format("%d", m_player.m_po_fgm + m_player.m_po_tfgm);
		string[7].Format("%d", m_player.m_po_fga + m_player.m_po_tfga);
		string[8].Format("%.2f", m_player.m_po_fgPct);
		string[9].Format("%d", m_player.m_po_ftm);
		string[10].Format("%d", m_player.m_po_fta);
		string[11].Format("%.2f", m_player.m_po_ftPct);
		string[12].Format("%d", m_player.m_po_tfgm);
		string[13].Format("%d", m_player.m_po_tfga);
		string[14].Format("%.2f", m_player.m_po_tfgPct);
		string[15].Format("%.2f", m_player.m_po_orbPerGame);
		string[16].Format("%.2f",m_player.m_po_orbPerGame+m_player.m_po_reboundsPerGame);
		string[17].Format("%.2f", m_player.m_po_assistsPerGame);
		string[18].Format("%.2f", m_player.m_po_stealsPerGame);
		string[19].Format("%.2f", m_player.m_po_toPerGame);
		string[20].Format("%.2f", m_player.m_po_blocksPerGame);
		string[21].Format("%.2f", m_player.m_po_pfPerGame);
		string[22].Format("%.2f", m_player.m_po_pointsPerGame);
		string[23].Format("%d", m_player.m_injury);
		WriteRow(string, 23, false, 2);














		CString string1[] = {"", "", "", "age", "2ga","2g%","fta","ft%","3ga","3g%","orb","drb","ast","stl","to","blk","o-o","d-o","p-o","t-o","o-d","d-d","p-d","t-d"};
		WriteRow(string1, 23, true, 0);
		string1[1] = "";
		string1[2] = "";
	

		string1[3].Format("%d", m_player.m_age);
		string1[4].Format("%d", m_player.m_prFga);
		string1[5].Format("%d", m_player.m_prFgp);
		string1[6].Format("%d", m_player.m_prFta);
		string1[7].Format("%d", m_player.m_prFtp);
		string1[8].Format("%d", m_player.m_prTga);
		string1[9].Format("%d", m_player.m_prTgp);
		string1[10].Format("%d", m_player.m_prOrb);
		string1[11].Format("%d", m_player.m_prDrb);
		string1[12].Format("%d", m_player.m_prAst);
		string1[13].Format("%d", m_player.m_prStl);
		string1[14].Format("%d", m_player.m_prTo);
		string1[15].Format("%d", m_player.m_prBlk);
		string1[16].Format("%d", m_player.m_movoff);
		string1[17].Format("%d", m_player.m_penoff);
		string1[18].Format("%d", m_player.m_postoff);
		string1[19].Format("%d", m_player.m_transoff);
		string1[20].Format("%d", m_player.m_movdef);
		string1[21].Format("%d", m_player.m_pendef);
		string1[22].Format("%d", m_player.m_postdef);
		string1[23].Format("%d", m_player.m_transdef);
		WriteRow(string1, 23, false, 0);	













	SetRowString("");
	CString header[] = {"",""};
	AddLine("<table><td><table>");


	CreateScoutingReport(m_player);
	WriteTableHeader(1, "Scouting Report");
	
	
	for(int l=0; l<=32; l++)
	{
		if(m_lines[l] == "") continue;
		header[1] = m_lines[l];
		WriteRow(header, 1, false, 0);
	}

	AddLine("</table></td><td><table>");



















	CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};

		CString Stats[33];
				
//		WriteTableHeader(1, "Contract");


		for(int i=1; i<=6; i++)
		{
			CString str;
			str.Format("Year %d", i);
			Stats[i*2-1] = str;
			double fn = (double)m_player.m_contract_salaries[i]/100;
			Stats[i*2].Format("%.2f", fn);
		}
		int mo = m_player.m_contract_salaries[1] +
			m_player.m_contract_salaries[2] +
			m_player.m_contract_salaries[3] +
			m_player.m_contract_salaries[4] +
			m_player.m_contract_salaries[5] +
			m_player.m_contract_salaries[6];

		double mon = (double)mo/100;

		Stats[13] = "Total";
		Stats[14].Format("%.2f", mon);


		FillList(Stats, "Player Contract");


		//bool f = m_player.m_is_free_agent;
		//if(f == true) Stats[0] = "yes"; else Stats[0] = "no";

		int n = m_player.m_loyalty_factor;
		Stats[1] = "Loyalty";
		Stats[2] = display[n];

		n = m_player.m_winning_factor;
		Stats[3] = "Play for Winner";
		Stats[4] = display[n];

		n = m_player.m_playing_time_factor;
		Stats[5] = "Playing Time";
		Stats[6] = display[n];

		n = m_player.m_security_factor;
		Stats[7] = "Security";
		Stats[8] = display[n];

		n = m_player.m_coach_factor;
		Stats[9] = "Coach";
		Stats[10] = display[n];

		n = m_player.m_tradition_factor;
		Stats[11] = "Tradition";
		Stats[12] = display[n];

		Stats[13] = "";
		Stats[14] = "";
					
		FillList(Stats, "Player Attributes");

	int count = CreateAwardReport(m_player);
	if(count > 0) 
		WriteTableHeader(1, "Player Awards");
	for(int l=0; l<=count; l++)
	{
		if(awards[l] == "") continue;
		header[1] = awards[l];
		WriteRow(header, 1, false, 0);

	}


	AddLine("</table></td><td><table>");

	WriteTableHeader(1, "Player Highs");

	
	string[1] = "Category";
	string[2] = "Season";;
	string[3] = "Playoff";
	string[4] = "Career";
	string[5] = "Playoff";
	WriteRow(string, 5, true, 0);	

	string[1] = "points";
	string[2].Format(" %2d", m_player.m_hi_pts);
	string[3].Format(" %2d", m_player.m_hi_pts_po);
	string[4].Format(" %2d", m_player.m_hi_pts_car);
	string[5].Format(" %2d", m_player.m_hi_pts_car_po);
	WriteRow(string, 5, false, 1);	

	string[1] = "rebounds";
	string[2].Format(" %2d", m_player.m_hi_reb);
	string[3].Format(" %2d", m_player.m_hi_reb_po);
	string[4].Format(" %2d", m_player.m_hi_reb_car);
	string[5].Format(" %2d", m_player.m_hi_reb_car_po);
	WriteRow(string, 5, false, 1);	

	string[1] = "assists";
	string[2].Format(" %2d", m_player.m_hi_ast);
	string[3].Format(" %2d", m_player.m_hi_ast_po);
	string[4].Format(" %2d", m_player.m_hi_ast_car);
	string[5].Format(" %2d", m_player.m_hi_ast_car_po);
	WriteRow(string, 5, false, 1);	

	string[1] = "steals";
	string[2].Format(" %2d", m_player.m_hi_stl);
	string[3].Format(" %2d", m_player.m_hi_stl_po);
	string[4].Format(" %2d", m_player.m_hi_stl_car);
	string[5].Format(" %2d", m_player.m_hi_stl_car_po);
	WriteRow(string, 5, false, 1);	

	string[1] = "blocks";
	string[2].Format(" %2d", m_player.m_hi_blk);
	string[3].Format(" %2d", m_player.m_hi_blk_po);
	string[4].Format(" %2d", m_player.m_hi_blk_car);
	string[5].Format(" %2d", m_player.m_hi_blk_car_po);
	WriteRow(string, 5, false, 1);	

	string[1] = "double double";
	string[2].Format(" %2d", m_player.m_double);
	string[3] = "";
	string[4].Format(" %2d", m_player.m_double_car);
	string[5] = "";
	WriteRow(string, 5, false, 1);	

	string[1] = "triple double";
	string[2].Format(" %2d", m_player.m_triple);
	string[3] = "";
	string[4].Format(" %2d", m_player.m_triple_car);
	string[5] = "";
	WriteRow(string, 5, false, 1);	



	SetRowString("");
	AddLine("</table></td></table><table>");
	WriteTableHeader(1, "Career Stats");
	CreateCareerStatsReport(m_player);
	AddLine("</table>");

	EndPage();
	int id = m_player.m_id;
	name = m_player.m_name;
	CString head;
	head.Format("%d", id);
	name.Remove(' ');



	CString path = m_path + m_league_name + "\\";
	
	WritePage(path + name + head + ".htm");

}

}

void CHtml::InitData()
{
	CPlayer m_player;
	for(int i=0; i<=1600; i++)
	{
		m_player = avg.m_actual[i];
		int te = (i-1)/15;
		if(m_stage > 0) te = (i-1)/20;
		if(te < 0) te = 0;
		else if(te >= 32) te = 32;
		CStaff scout;
		int team = m_player.m_team_index;
		if(team > 0) scout = avg.m_scout[team-1];		
		else scout.InitVariables();
		m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	
		m_player.SetAdjustedRatings(scout);
		avg.m_actual[i] = m_player;
		avg.m_actual[i].m_team_index = te;
		avg.m_actual[i].SetSeasonAverages();
	}

}

void CHtml::CreateScoutingReport(CPlayer m_player)
{
	for(int i=0; i<=32; i++)
	{
		m_lines[i] = "";
	}

	
	m_player.CreateReport(m_lines, avg.r_ast, avg.r_fta, avg.r_tga, avg.m_avg_tgp, avg.r_orb, avg.r_drb, avg.r_stl, avg.r_to, avg.r_blk,
		avg.r_fga, avg.m_avg_fgp, avg.m_avg_fga, avg.m_avg_ftp, avg.m_avg_trade_tru);

}

int CHtml::CreateAwardReport(CPlayer m_player)
{

	CFile file(	m_path + m_league_name + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	int count = 1;
	int id = m_player.m_id;
 	
	int seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);

	CString place[6] = {"", "1st", "2nd", "3rd", "4th", "5th"};
	for(int y=0; y<=20; y++)
	{
		awards[y] = "";
	}

	for(int y=0; y<=20; y++)
	{

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
//			string.Format("%d mvp  %d", yr, mvp);
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
//			string.Format("%d defense - %d", yr, defense);
			awards[count] = string;
			count = count + 1;
		}

		int rookie_seek = 2000 + id*500 + 682 + (y*15);
		file.Seek( rookie_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int rookie = atoi(s);
		if(rookie > 0 && rookie <=5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d rookie - %d", yr, rookie);
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
//			string.Format("%d pts - %d", yr, pts);
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
//			string.Format("%d reb - %d", yr, reb);
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
//			string.Format("%d ast - %d", yr, ast);
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
//			string.Format("%d stl - %d", yr, stl);
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
//			string.Format("%d blk - %d", yr, blk);
			string.Format("%d blocks (%s)", yr, place[blk]);
			awards[count] = string;
			count = count + 1;
		}

		int ring_seek = 2000 + id*500 + 688 + (y*15);
		file.Seek( ring_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ring = atoi(s);
		if(ring > 0 && ring <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d championship", yr);
//			string.Format("%d mvp (%s)", yr, place[mvp]);

			awards[count] = string;
			count = count + 1;
		}

		int po_mvp_seek = 2000 + id*500 + 689 + (y*15);
		file.Seek( po_mvp_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int po_mvp = atoi(s);
		if(po_mvp > 0 && po_mvp <= 5)
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
//			string.Format("%d 6th - %d", yr, sth);
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
//			string.Format("%d all league - %d", yr, all);
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
//			string.Format("%d all defense - %d", yr, all);
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
//			string.Format("%d all rookie - %d", yr, all);
			string.Format("%d all rookie %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}




	}

	return count;
}

void CHtml::CreateCareerStatsReport(CPlayer m_player)
{
int yrsPro = 0;
CString buffer;
CString pFileName = m_path + m_league_name + ".car";
CFile file(	pFileName, CFile::modeRead);	


char s[17];
int slot = m_player.GetID();
int g=0, min=0, fgm=0, fga=0, ftm=0, fta=0, tgm=0, tga=0, orb=0, reb=0, ast=0, stl=0, to=0, blk=0, pf=0;
int yearsPro = 0; 
int round = 0, pos = 0, overall = 0;
	CString header[] = {"",""};


CString stringA[] = {"", "year", "team", "g","min","fgm","fga","fgp","ftm","fta","ftp","3gm","3ga","3gp","orb","reb","ast","stl","to","blk","pf","ppg"};
// = "<font size = \"2\" face = \"Tahoma\">";
WriteRow(stringA, 21, true, 0);
// = "<font size = \"1\" face = \"Tahoma\">";

for(int y=0; y<=24; y++)
{
	CString string[33];

	CPlayer m_stats;

	if(y <= 23)
	{

	long int seek = slot*2500 + 24 + y*100; 
	file.Seek( seek, CFile::begin);
	int bytes = file.Read(s, 4);
	s[bytes] = 0;
	int number = atoi(s);
	m_stats.SetRosterNumber(number);//set year

	bytes = file.Read(s, 16);
	s[bytes] = 0;
	m_stats.SetTeam(CString(s));//set team
	string[2] = CString(s);
	file.Seek( seek+40, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetGames(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetMin(number);
	if(number > 0) yrsPro = yrsPro + 1;

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetFgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetFga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetFtm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetFta(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetTfgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetTfga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetOreb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetReb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetAst(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetStl(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetTo(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetBlk(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats.SetPf(number);

	}
	int seek = slot*2500 + 26 + 24*100; 
	file.Seek( seek, CFile::begin);

	int bytes = file.Read(s, 1);
	s[bytes] = 0;
	round = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	pos = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	overall = atoi(s);
	






		if(m_stats.GetGames() == 0 && y <= 23) continue;
		int s1 = m_stats.GetGames();
		int s2 = m_stats.GetMin();
		int s3 = m_stats.GetFgm() + m_stats.GetTfgm();
		int s4 = m_stats.GetFga() + m_stats.GetTfga();
		int s5 = m_stats.GetFtm();
		int s6 = m_stats.GetFta();
		int s7 = m_stats.GetTfgm();
		int s8 = m_stats.GetTfga();
		int s9 = m_stats.GetOreb();
		int s10 =m_stats.GetReb() + s9;
		int s11 =m_stats.GetAst();
		int s12 =m_stats.GetStl();
		int s13 =m_stats.GetTo();
		int s14 =m_stats.GetBlk();
		int s15 =m_stats.GetPf();




		if(y == 24)
		{
			s1 = g; s2 = min; s3 = fgm; s4 = fga; s5 = ftm;
			s6 = fta; s7 = tgm; s8 = tga; s9 = orb; s10 = reb;
			s11 = ast; s12 = stl; s13 = to; s14 = blk; s15 = pf;
		}
		else
		{

		g = g + s1;
		min = min + s2;
		fgm = fgm + s3;
		fga = fga + s4;
		ftm = ftm + s5;
		fta = fta + s6;
		tgm = tgm + s7;
		tga = tga + s8;
		orb = orb + s9;
		reb = reb + s10;
		ast = ast + s11;
		stl = stl + s12;
		to =  to + s13;
		blk = blk + s14;
		pf = pf + s15;

		}
		

		if(g == 0) continue;

		if(y != 24)
			string[1].Format("%4d ", m_stats.GetRosterNumber());
		else 
			string[1] = "---- ";
		

	    string[3].Format("%4d ", s1);
			
	    string[4].Format("%2.1f ", double(s2) / double(s1) );
			
	    string[5].Format("%2.1f ", double(s3) / double(s1) );
			
	    string[6].Format("%2.1f ", double(s4) / double(s1) );
			
		if(s4 == 0)
			string[7] = "-- ";
		else
			string[7].Format("%2.1f ", (double(s3)/double(s1))/ (double(s4) / double(s1)) *100);
			
	    string[8].Format("%2.1f ", double(s5) / double(s1) );
			
	    string[9].Format("%2.1f ", double(s6) / double(s1) );
		
		if(s6 == 0)
			string[10] = "-- ";
		else
			string[10].Format("%2.1f ", (double(s5)/double(s1))/ (double(s6) / double(s1)) *100);

			
	    string[11].Format("%2.1f ", double(s7) / double(s1) );
			
	    string[12].Format("%2.1f ", double(s8) / double(s1) );
			
		if(s8 == 0)
			string[13] = "-- ";
		else
			string[13].Format("%2.1f ", (double(s7)/double(s1))/ (double(s8) / double(s1)) *100);
	    
	    string[14].Format("%2.1f ", double(s9) / double(s1) );
			
	    string[15].Format("%2.1f ", double(s10) / double(s1) );
			
	    string[16].Format("%2.1f ", double(s11) / double(s1) );
			
	    string[17].Format("%2.1f ", double(s12) / double(s1) );
			
	    string[18].Format("%2.1f ", double(s13) / double(s1) );
			
	    string[19].Format("%2.1f ", double(s14) / double(s1) );
			
	    string[20].Format("%2.1f ", double(s15) / double(s1) );

	    string[21].Format("%2.1f ", double(s3*2+s5+s7) / double(s1) );

		WriteRow(string, 21, false, 0);

		yearsPro = yearsPro + 1;
			
}

    file.Close();

		if(round > 0)
	{
		buffer.Format("Round: %d", round);
		header[1] = buffer;
		WriteRow(header, 1, false, 0);
		buffer.Format("Pick: %d", pos);
		//m_car_string[2] = buffer;
		header[1] = buffer;
		WriteRow(header, 1, false, 0);
		buffer.Format("Overall: %d", overall);
		header[1] = buffer;
		WriteRow(header, 1, false, 0);

		//m_car_string[3] = buffer;
		buffer.Format("Years Pro: %d", yrsPro);
		header[1] = buffer;
		WriteRow(header, 1, false, 0);

		//m_car_string[4] = buffer;

	}

}

void CHtml::AddLine(CString str)
{
	m_strings[m_current_line] = str;
	m_current_line = m_current_line + 1;
}

void CHtml::CreateAwardsPage()
{
	CAwards* aw = new CAwards;
	aw->avg = avg;
	aw->m_current_year = m_current_year;
	aw->ChooseAwards();

	m_current_line = 1;
	CString strings[33];

	BeginPage(m_league_name + " Leaders");

//	SetHeading("Most Valuable Player");

//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Most Valuable Player<table>");



	strings[1] = "po"; strings[2] = "most valuable player"; strings[3] = "team";
	WriteBoldRow(strings, 3);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_mvp[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;


	strings[3] = m_player.m_team_paying_name;
	WriteRow(strings, 3, false, 2);
	}
	AddLine("");	
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Defensive Player of the Year<table>");

//	SetHeading("Defensive Player of the Year");
	strings[1] = "po"; strings[2] = "defensive player"; strings[3] = "team";
	WriteBoldRow(strings, 3);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_defense[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	WriteRow(strings, 3, false, 2);
	}
	AddLine("");	


//	SetHeading("Rookie of the Year");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Rookie of the Year<table>");

	strings[1] = "po"; strings[2] = "rookie of the year"; strings[3] = "team";
	WriteBoldRow(strings, 3);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_rookie[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);	strings[3] = m_player.m_team_paying_name;
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	WriteRow(strings, 3, false, 2);
	}
	AddLine("");	


//	SetHeading("6th Man Award");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>6th Man Award<table>");
	strings[1] = "po"; strings[2] = "6th Man Award"; strings[3] = "team";
	WriteBoldRow(strings, 3);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_6th[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	WriteRow(strings, 3, false, 2);
	}

	AddLine("");	

//	SetHeading("Scoring");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Scoring<table>");
	strings[1] = "po"; strings[2] = "scoring leader"; strings[3] = "team";strings[4] = "ppg";
//	string[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	WriteBoldRow(strings, 4);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_pts[co]];
	strings[1] = m_player.m_pos;
//	strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;


	strings[4].Format("%.2f", m_player.m_sim_pointsPerGame);
	WriteRow(strings, 4, false, 2);
	}
	AddLine("");	


//	SetHeading("Rebounds");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Rebounds<table>");
	strings[1] = "po"; strings[2] = "rebound leader"; strings[3] = "team";strings[4] = "reb";
	WriteBoldRow(strings, 4);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_reb[co]];
	strings[1] = m_player.m_pos;
//	strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	strings[4].Format("%.2f", m_player.m_sim_reboundsPerGame + m_player.m_sim_orbPerGame);
	WriteRow(strings, 4, false, 2);
	}
	AddLine("");	


//	SetHeading("Assists");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Assists<table>");
	strings[1] = "po"; strings[2] = "assists leader"; strings[3] = "team";strings[4] = "ast";
	WriteBoldRow(strings, 4);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_ast[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	strings[4].Format("%.2f", m_player.m_sim_assistsPerGame);
	WriteRow(strings, 4, false, 2);
	}
	AddLine("");	


//	SetHeading("Steals");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Steals<table>");
	strings[1] = "po"; strings[2] = "steals leader"; strings[3] = "team";strings[4] = "stl";
	WriteBoldRow(strings, 4);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_stl[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	strings[4].Format("%.2f", m_player.m_sim_stealsPerGame);
	WriteRow(strings, 4, false, 2);
	}
	AddLine("");	


//	SetHeading("Blocks");
//	m_font = "<font size = \"1\" face = \"Tahoma\">";
//	AddLine("</table>Blocks<table>");
	strings[1] = "po"; strings[2] = "blocks leader"; strings[3] = "team";strings[4] = "blk";
	WriteBoldRow(strings, 4);

	for(int co=1; co<=5; co++)
	{
	CPlayer m_player = avg.m_actual[aw->m_blk[co]];
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;
	strings[4].Format("%.2f", m_player.m_sim_blocksPerGame);
	WriteRow(strings, 4, false, 2);
	}
	AddLine("");	




	CPlayer m_player;

	strings[1] = ""; strings[2] = "All League 1st"; strings[3] = "";
	strings[4] = ""; strings[5] = "All League 2nd"; strings[6] = "";
	strings[7] = ""; strings[8] = "All League 3rd"; strings[9] = "";
	SetHeading("");
	WriteBoldRow(strings, 9);


	
	strings[1] = "po"; strings[2] = "player"; strings[3] = "team";
	strings[4] = "po"; strings[5] = "player"; strings[6] = "team";
	strings[7] = "po"; strings[8] = "player"; strings[9] = "team";
	WriteBoldRow(strings, 9);


	for(int co=1; co<=5; co++)
	{

	m_player = avg.m_actual[aw->m_all_league[co][1]];
	
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;

	m_player = avg.m_actual[aw->m_all_league[co][2]];
	strings[4] = m_player.m_pos;
	str = GetPlayerPageName(m_player);
	strings[5].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[5] = m_player.m_name;

//	strings[5] = m_player.m_name;
	strings[6] = m_player.m_team_paying_name;


	m_player = avg.m_actual[aw->m_all_league[co][3]];
	strings[7] = m_player.m_pos;
//	strings[8] = m_player.m_name;
	str = GetPlayerPageName(m_player);
	strings[8].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[8] = m_player.m_name;
	strings[9] = m_player.m_team_paying_name;


	WriteRow(strings, 9, false, 2);

	}
	AddLine("");	

	strings[1] = ""; strings[2] = "All Defense 1st"; strings[3] = "";
	strings[4] = ""; strings[5] = "All Defense 2nd"; strings[6] = "";
	strings[7] = ""; strings[8] = "All Defense 3rd"; strings[9] = "";
	SetHeading("");
	WriteBoldRow(strings, 9);


	
	strings[1] = "po"; strings[2] = "player"; strings[3] = "team";
	strings[4] = "po"; strings[5] = "player"; strings[6] = "team";
	strings[7] = "po"; strings[8] = "player"; strings[9] = "team";
	WriteBoldRow(strings, 9);


	for(int co=1; co<=5; co++)
	{

	m_player = avg.m_actual[aw->m_all_defense[co][1]];
	
	strings[1] = m_player.m_pos;
	//strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;

	m_player = avg.m_actual[aw->m_all_defense[co][2]];
	strings[4] = m_player.m_pos;
	//strings[5] = m_player.m_name;
	str = GetPlayerPageName(m_player);
	strings[5].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[5] = m_player.m_name;
	strings[6] = m_player.m_team_paying_name;


	m_player = avg.m_actual[aw->m_all_defense[co][3]];
	strings[7] = m_player.m_pos;
	//strings[8] = m_player.m_name;
	str = GetPlayerPageName(m_player);
	strings[8].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[8] = m_player.m_name;
	strings[9] = m_player.m_team_paying_name;


	WriteRow(strings, 9, false, 2);

	}
	AddLine("");	

strings[1] = ""; strings[2] = "All Rookie 1st"; strings[3] = "";
	strings[4] = ""; strings[5] = "All Rookie 2nd"; strings[6] = "";
	strings[7] = ""; strings[8] = "All Rookie 3rd"; strings[9] = "";
	SetHeading("");

	WriteBoldRow(strings, 9);


	
	strings[1] = "po"; strings[2] = "player"; strings[3] = "team";
	strings[4] = "po"; strings[5] = "player"; strings[6] = "team";
	strings[7] = "po"; strings[8] = "player"; strings[9] = "team";
	WriteBoldRow(strings, 9);


	for(int co=1; co<=5; co++)
	{

	m_player = avg.m_actual[aw->m_all_rookie[co][1]];
	
	strings[1] = m_player.m_pos;
//	strings[2] = m_player.m_name;
	CString str = GetPlayerPageName(m_player);
	strings[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[2] = m_player.m_name;
	strings[3] = m_player.m_team_paying_name;

	m_player = avg.m_actual[aw->m_all_rookie[co][2]];
	strings[4] = m_player.m_pos;
	//strings[5] = m_player.m_name;
	str = GetPlayerPageName(m_player);
	strings[5].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[5] = m_player.m_name;
	strings[6] = m_player.m_team_paying_name;


	m_player = avg.m_actual[aw->m_all_rookie[co][3]];
	strings[7] = m_player.m_pos;
	//strings[8] = m_player.m_name;
	str = GetPlayerPageName(m_player);
	strings[8].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name);
	if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
		strings[8] = m_player.m_name;
	strings[9] = m_player.m_team_paying_name;


	WriteRow(strings, 9, false, 2);

	}
	AddLine("");	
	EndPage();

	CString path = m_path + m_league_name + "\\";	
	WritePage(path + "Leaders" + ".htm");




	delete aw;

}

void CHtml::GenerateInjuryPage()
{
	CString string;
	//char s[129];

	m_current_line = 1;

//	CFile file(	m_path + m_league_name + ".tra", CFile::modeRead);

	BeginPage(m_league_name + " Injuries");
	
//	int bytes = file.Read(s, 16);
//	s[bytes] = 0;
	int n = avg.m_settings.m_number_transactions;
    int t1 = 0, t2 = 0;
	int id = 0, team = 0, games = 0;

	CString strings[] = {"","month","day","year","name","team","days","injury"};
	WriteBoldRow(strings, 7);


	for(int i=1; i<=n; i++)
	{
		//int seek = (i-1)*128+17;
		//file.Seek( seek, CFile::begin );
		//int bytes = file.Read(s, 128);
		//s[bytes] = 0;
		string = avg.m_trans_str[i];
		//string = CString(s);
		int month = atoi(string.Mid(0,2));
		int day = atoi(string.Mid(2,2));
		int year = atoi(string.Mid(4,4));
		int ty = atoi(string.Mid(8,2));
		if(ty == 1)
		{

			id = atoi(string.Mid(10,6));
			team = atoi(string.Mid(16,2));
			if(team <= 0) continue;
			CString desc = string.Mid(22, 32);
			team = team - 1;
			games = atoi(string.Mid(18,4));
			int sl = 0;
			for(int j=1; j<=1440; j++)
			{
				if(avg.m_actual[j].m_id == id) sl = j;
			}
			CPlayer m_player = avg.m_actual[sl];
			CString str[33];
			str[1].Format("%d", month);
			str[2].Format("%d", day);
			str[3].Format("%d", year);
			CString str1 = GetPlayerPageName(m_player);
			str[4].Format("<a href=\"%s\">%-32s</a>", str1, m_player.m_name);

			if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
				str[4] = m_player.m_name;

			
			str[5] = avg.m_finance[team].m_team_name;
			str[6].Format("%d", games);
			str[7] = desc;
			WriteRow(str, 7, false, 0);
			
		}
		
	}
	EndPage();

	CString path = m_path + m_league_name + "\\";	
	WritePage(path + "Injuries" + ".htm");    
//	file.Close();		
}

void CHtml::SetRowString(CString string)
{
	string = "<tr><td CLASS=tdp>" + string + "</td></tr>";


	AddLine(string);
}

void CHtml::WriteRow(CString strings[], int items, bool start_table, int class_row)
{
	CString string = "<tr>";

//<tr><th width=16%>Player</th><th width=12%>Pos</th><th width=12%>Inside Scoring</th><th width=12%>Outside Scoring</th><th width=12%>Handling</th><th width=12%>Defense</th><th width=12%>Rebounding</th><th width=12%>Potential</th></tr>



	for(int i=1; i<=items; i++)
	{
		CString start = "<td>";
		CString end = "</td>";
		if(start_table == true)
		{
			start = "<th>";
			end = "</th>";
		}
		else if(i <= class_row)
			start = "<td CLASS=tdp>";
//		else
//			start = "<td CLASS=tdc>";
		string = string + start  + strings[i] + end;
	}



	//line.Format("<style>th{ %s; color:white; border-width: small; border-style: solid; border-color: navy ; background-color: navy}td      { text-align: Left; %s; color:black; border-width: small; border-style: solid; border-color: white; background-color: white }.tdp { font-weight: bold; text-align: Left; font-size: 10pt; color:black; border-width: small; border-style: solid; border-color: white; background-color: white } </style>", m_html_font, m_html_font);


	string = string + "</tr>";
	AddLine(string);
}

void CHtml::SetHeading(CString string)
{
	SetRowString("");
	//m_font = "<font size = \"2\" face = \"Tahoma\">";
	SetRowString(string);
	// = "<font size = \"1\" face = \"Tahoma\">";
}

void CHtml::WriteBoldRow(CString strings[], int items)
{
	// = "<font size = \"2\" face = \"Tahoma\">";
	WriteRow(strings, items, true, 0);
	// = "<font size = \"1\" face = \"Tahoma\">";
}

CString CHtml::GetPlayerPageName(CPlayer m_player)
{

		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";
		return str;
}

void CHtml::GenerateSchedulePage()
{

	m_current_line = 1;
	BeginPage(m_league_name + " Schedule");

	CString month[] = {"October","November","December","January","February","March","April","May","June","July","August","September", "Post"};


	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing League Schedule";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 12);


	for(int i = 0; i <= 12; i++ )
		{
			dlgProgress.m_progress.SetPos(i+1);
			for(int  j = 0; j <= 30; j++ )
			{
				CString stringA[33];
				CString mon = month[i];
				CString day, year;
				day.Format("%d", j+1);
				int ye = avg.m_settings.m_currentYear;
				if(i >= 3) ye = ye + 1;
				year.Format("%d", ye);
				CString da = mon + " " + day + " " + year;
				stringA[1] = da;
				CString string[33];
				CString stringB[] = {"","visitor","score","home","score"};

				bool no_games = true;

				for(int  k = 0; k <= 15; k++ )
				{
					
	int v = avg.m_sched.m_schedule[i][j][k] / 100;
	int h = avg.m_sched.m_schedule[i][j][k]  - v*100;
	if(v <= 0 || h <= 0) continue;

	if(no_games == true)
	{
		WriteBoldRow(stringA, 1);
		WriteBoldRow(stringB, 4);
		no_games = false;
	}
	int s1 = avg.m_sched.m_game_score[i][j][k] / 1000;
	int s2 = avg.m_sched.m_game_score[i][j][k]  - s1*1000;
	//m_game_score[i][j][k] = avg.m_sched.m_game_score[i][j][k];
	//m_schedule[i][j][k] = avg.m_sched.m_schedule[i][j][k];
	CString vis = avg.m_finance[v-1].m_team_name;
	CString hom = avg.m_finance[h-1].m_team_name;


	CString v_team = vis + ".htm";
	v_team.Remove(' ');
	string[1].Format("<a href=\"%s\">%-32s</a>", v_team, vis); 


	CString h_team = hom + ".htm";
	h_team.Remove(' ');
	string[3].Format("<a href=\"%s\">%-32s</a>", h_team, hom); 


					int slot = (i*500 + j*15 + k); 					
					CString box_name;
					box_name.Format("box%d",slot);
					box_name = box_name + ".htm";
					string[2].Format("<a href=\"%s\">%d</a>", box_name, s1); 
					string[4].Format("<a href=\"%s\">%d</a>", box_name, s2); 
				if(m_box_index == 0 || m_box_index >= 2 &&  (v+1) != m_box_index
					&&  (h+1) != m_box_index)				
				{
					string[2].Format("%d", s1);
					string[4].Format("%d", s2);
				}

				
					if(s1 == 0)
					{
						string[2] = "";
						string[4] = "";
					}
					WriteRow(string, 4, false, 0);

				}
			}
	}


	EndPage();
	CString path = m_path + m_league_name + "\\";
	WritePage(path + "Schedule" + ".htm");
}

void CHtml::GenerateBoxScores()
{
	CString file_name = m_path + m_league_name + ".sco";

	CFile file( file_name, CFile::modeRead);
	char s[3001];

	CFileStatus status;

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing Box Scores";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 12);
	for(int m = 0; m <= 12; m++ )
		{
			dlgProgress.m_progress.SetPos(m+1);

			for(int  j = 0; j <= 30; j++ )
			{
				for(int  k = 0; k <= 15; k++ )
				{

				int ind = (m*500 + j*15 + k);
				CString box_date;
				box_date.Format("box%d", ind);
				CString path = m_path + m_league_name + "\\";

				CString pFileName = path + box_date + ".htm";
				if( CFile::GetStatus( pFileName, status ) != FALSE) continue;

				CString fi_na = m_path + m_league_name + "\\" + box_date + ".htm";

				if( CFile::GetStatus( fi_na, status ) == TRUE) continue;



				if(avg.m_sched.m_game_score[m][j][k] <= 0) continue;





	int seek = (m*500 + j*15 + k) * 2000;
	file.Seek(seek, CFile::begin );
	int bytes = file.Read(s, 2000);
	CString str = CString(s);
	CString buf;
	str = str + "                                                                                                              ";
	buf = str.Mid(6,2);
	int visitor_index = atoi(buf);
	buf = str.Mid(8,2);
	int home_index = atoi(buf);


		if(m_box_index == 0) continue;
		if(m_box_index > 1 && 
			((visitor_index+2) != m_box_index) 
			&&			
			((home_index+2) != m_box_index) 
			) continue;


	buf = str.Mid(10,5);
	int att = atoi(buf);

	buf = str.Mid(15,5);
	int cap = atoi(buf);

	buf = str.Mid(20,4);
	int v_rec = atoi(buf);

	buf = str.Mid(24,4);
	int h_rec = atoi(buf);

	buf = str.Mid(28,3);
	int quarter_score11 = atoi(buf);


	buf = str.Mid(31,3);
	int quarter_score12 = atoi(buf);

	if(quarter_score11 <= 0 || quarter_score12 <= 0) continue;

	buf = str.Mid(34,3);
	int quarter_score13 = atoi(buf);

	buf = str.Mid(37,3);
	int quarter_score14 = atoi(buf);

	buf = str.Mid(40,3);
	int quarter_score15 = atoi(buf);

	buf = str.Mid(43,3);
	int quarter_score21 = atoi(buf);

	buf = str.Mid(46,3);
	int quarter_score22 = atoi(buf);

	buf = str.Mid(49,3);
	int quarter_score23 = atoi(buf);

	buf = str.Mid(52,3);
	int quarter_score24 = atoi(buf);

	buf = str.Mid(55,3);
	int quarter_score25 = atoi(buf);


	int v_win = v_rec / 100;
	int v_loss = v_rec - v_win * 100;

	int h_win = h_rec / 100;
	int h_loss = h_rec - h_win * 100;

	CString visitor = avg.m_finance[visitor_index].m_team_name;
	CString home = avg.m_finance[home_index].m_team_name;
	if(quarter_score11 == 0) continue;

	m_current_line = 1;
	BeginPage("Box Score");
//	WriteTableHeader(1, "Box Score");
//	AddLine("<table>");

	//int spot = 0;

	int sc1 = 0;
	int sc2 = 0;

	for(int i=0; i<=29; i++)
	{
		CString string[33];
		if(i == 0 || i == 15)
		{
			CString stringA[] = {"", "pos", "player","min","fgm","fga","ftm","fta","3gm","3ga","orb","reb","ast","stl","to","blk","pf","pts"};

			// = "<font size = \"2\" face = \"Tahoma\">";
			WriteRow(stringA, 17, true, 2);
			// = "<font size = \"1\" face = \"Tahoma\">";
		}


		buf = str.Mid(58 + i*53,16);
		buf.TrimRight();
		CString na = buf;

		buf = str.Mid(58 + i*53+16,2);
		buf.TrimRight();
		string[1] = buf;//pos

		buf = str.Mid(58 + i*53+18,6);
		buf.TrimRight();
		int id = atoi(buf);
		CString s_id;
		s_id.Format("%d", id);
		CString str1 = na + s_id + ".htm";

		str1.Remove(' ');
		buf.Format("<a href=\"%s\">%-32s</a>", str1, na); 

		if(i == 14)
		{
			buf = visitor;
			na = visitor;
		}
		else if(i == 29)
		{
			buf = home;
			na = home;
		}
		string[2] = buf;//name

		if(na == "") continue;

		buf = str.Mid(58 + i*53+24,2);
		string[3] = buf;

		buf = str.Mid(58 + i*53+26,2);
		int fgm = atoi(buf);

		buf = str.Mid(58 + i*53+28,3);
		int fga = atoi(buf);

		buf = str.Mid(58 + i*53+31,2);
		string[6] = buf;//fgm
		int ftm = atoi(buf);

		buf = str.Mid(58 + i*53+33,2);
		string[7] = buf;//fgm

		buf = str.Mid(58 + i*53+35,2);
		string[8] = buf;//fgm
		int tgm = atoi(buf);

		int pts = fgm*2 + ftm + tgm*3;

		if(i==14) sc1 = pts;
		else if(i==29) sc2 = pts;

		buf = str.Mid(58 + i*53+37,2);
		string[9] = buf;//fgm
		int tga = atoi(buf);

		fgm = fgm + tgm;
		fga = fga + tga;
		string[4].Format("%d", fgm);
		string[5].Format("%d", fga);

		buf = str.Mid(58 + i*53+39,2);
		string[10] = buf;//orb
		int orb = atoi(buf);

		buf = str.Mid(58 + i*53+41,2);
		int drb = atoi(buf);

		int t_reb = orb + drb;
		string[11].Format("%d", t_reb);


		buf = str.Mid(58 + i*53+43,2);
		string[12] = buf;//fgm

		buf = str.Mid(58 + i*53+45,2);
		string[13] = buf;//fgm

		buf = str.Mid(58 + i*53+47,2);
		string[14] = buf;//fgm

		buf = str.Mid(58 + i*53+49,2);
		string[15] = buf;//fgm

		buf = str.Mid(58 + i*53+51,2);
		string[16] = buf;//fgm


		string[17].Format("%d", pts);
		WriteRow(string, 17, false, 2);
	}



	CString q_str[17];






	CString stringA[] = {"", "", "team","1","2","3","4","","F"};
	WriteRow(stringA, 8, true, 2);


	q_str[0] = "";	
	q_str[1] = "";	
	q_str[2].Format("%s (%d - %d)", visitor, v_win, v_loss);
	q_str[3].Format("%d", quarter_score11 );
	q_str[4].Format("%d", quarter_score12 );
	q_str[5].Format("%d", quarter_score13 );
	q_str[6].Format("%d", quarter_score14 );
	q_str[7].Format("%d", quarter_score15 );
	q_str[8].Format("%d", sc1 );
	WriteRow(q_str, 8, false, 2);

	q_str[0] = "";	
	q_str[1] = "";	
	q_str[2].Format("%s (%d - %d)", home, h_win, h_loss);
	q_str[3].Format("%d", quarter_score21 );
	q_str[4].Format("%d", quarter_score22 );
	q_str[5].Format("%d", quarter_score23 );
	q_str[6].Format("%d", quarter_score24 );
	q_str[7].Format("%d", quarter_score25 );
	q_str[8].Format("%d", sc2 );
	WriteRow(q_str, 8, false, 2);


	q_str[1] = "";
	q_str[2].Format("ATTENDANCE: %d", att);
	WriteRow(q_str, 2, false, 2);

	q_str[1] = "";
	q_str[2].Format("CAPACITY: %d", cap);
	WriteRow(q_str, 2, false, 2);

	int spot = 58 + 29*53 + 53;//begin of injuries in game list

	for(int i=0; i<=9; i++)
	{
		CString string[3];
		if(str.GetLength() >= (spot+20))
		{
		string[2] = str.Mid(spot,20);
		string[2].TrimRight();
		CString tmp = string[2];
		string[2] = string[2] + " game injury";
		spot = spot + 20;
		if(tmp != "")
			WriteRow(string, 2, false, 2);
		}
	}









		EndPage();



//	if( CFile::GetStatus( pFileName, status ) == FALSE) 
		WritePage(path + box_date + ".htm");


			}		
		}
	}
}

void CHtml::GenerateMainPage()
{
	m_current_line = 1;
	BeginPage(m_league_name);
	CString string[33];
	// = "<font size = \"2\" face = \"Tahoma\">";

	string[1] = m_league_name + " Main Page";
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Standings.htm\">Standings</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Schedule.htm\">Schedule</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Leaders.htm\">Leaders</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Transactions.htm\">Transactions</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Bracket.htm\">Playoff Bracket</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"Injuries.htm\">Injuries</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"draft.htm\">Rookie Preview</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"fapreview.htm\">Free Agent Preview</a>"; 
	WriteRow(string, 1, false, 2);
	string[1] = "<a href=\"finances.htm\">Finances</a>"; 
	WriteRow(string, 1, false, 2);

	if(avg.m_settings.m_coaches[32] == 0 || avg.m_settings.m_scouts[32] == 0)
	{
		if(avg.m_settings.m_coaches[32] == 0 && avg.m_settings.m_scouts[32] == 0)
		{
			string[1] = "<a href=\"scouts.htm\">Scouts</a>"; 
			WriteRow(string, 1, false, 2);
			string[1] = "<a href=\"coaches.htm\">Coaches</a>"; 
			WriteRow(string, 1, false, 2);
			string[1] = "<a href=\"gms.htm\">General Managers</a>"; 
			WriteRow(string, 1, false, 2);
		}
		else if(avg.m_settings.m_coaches[32] == 0 && avg.m_settings.m_scouts[32] == 1)
		{
			string[1] = "<a href=\"coaches.htm\">Coaches</a>"; 
			WriteRow(string, 1, false, 2);
		}

	}



	// = "<font size = \"1\" face = \"Tahoma\">";



	CString path = m_path + m_league_name + "\\";

	EndPage();


	WritePage(path + "index" + ".htm");
}

void CHtml::GenerateTeamSchedules()
{

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing Team Schedules";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 32);

	

	for(int te=0; te<=31; te++)
	{

	m_current_line = 1;

	BeginPage(avg.m_finance[te].m_team_name + " Schedule");


	dlgProgress.m_progress.SetPos(te+1);
	m_current_line = 3;
	CString tm = avg.m_finance[te].m_team_name;
	tm.Remove(' ');
	if(tm == "") continue;
	CString month[] = {"October","November","December","January","February","March","April","May","June","July","August","September", "Post"};

	CString stringB[] = {"","month","day","visitor","score","home","score"};
	WriteBoldRow(stringB, 6);


	for(int i = 0; i <= 12; i++ )
		{
			for(int  j = 0; j <= 30; j++ )
			{
				CString mon = month[i];
				CString day, year;
				day.Format("%d", j+1);
				CString string[33];
				int ye = avg.m_settings.m_currentYear;
				if(i >= 3) ye = ye + 1;
				year.Format("%d", ye);
				day = day + ",  " + year;
				
				for(int  k = 0; k <= 15; k++ )
				{
					
				int v = avg.m_sched.m_schedule[i][j][k] / 100;
				int h = avg.m_sched.m_schedule[i][j][k]  - v*100;
				if(v != te+1 && h != te+1) continue;

				int s1 = avg.m_sched.m_game_score[i][j][k] / 1000;
				int s2 = avg.m_sched.m_game_score[i][j][k]  - s1*1000;
				CString vis = avg.m_finance[v-1].m_team_name;
				CString hom = avg.m_finance[h-1].m_team_name;
			
				string[1] = mon;
				string[2] = day;
				CString v_team = vis + ".htm";
				v_team.Remove(' ');
				string[3].Format("<a href=\"%s\">%-32s</a>", v_team, vis); 


				
				


				CString h_team = hom + ".htm";
				h_team.Remove(' ');
				string[5].Format("<a href=\"%s\">%-32s</a>", h_team, hom); 

		//		if(m_player_page_index == 0 || m_player_page_index >= 2 && 
		//			(h+1) != m_player_page_index && (v+1) != m_player_page_index
		//			)
		//		{
		//			string[3] = vis;
		//			string[5] = hom;
		//		}

				int slot = (i*500 + j*15 + k); 					
				CString box_name;
				box_name.Format("box%d",slot);
				box_name = box_name + ".htm";
				string[4].Format("<a href=\"%s\">%d</a>", box_name, s1); 
				string[6].Format("<a href=\"%s\">%d</a>", box_name, s2); 


				if(m_box_index == 0 || m_box_index >= 2 &&  (v+1) != m_box_index &&
					  (h+1) != m_box_index)
				{
					string[4].Format("%d", s1);
					string[6].Format("%d", s2);
				}

					if(s1 == 0)
					{
						string[4] = "";
						string[6] = "";
					}
					WriteRow(string, 6, false, 0);

				}
			}
	}


	EndPage();
	CString path = m_path + m_league_name + "\\";
	
	WritePage(path + tm + "Schedule" + ".htm");
	}
}

void CHtml::CreateMiscReport(CString label, CString labels[28], CString strings[581][28], int r1, int r2, CString name)
{

	_mkdir(m_path + m_league_name);

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Writing Page";
        dlgProgress.Create(288,NULL);        // change these parameters
        dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(r1, r2);


	r1 = r1 - 1;
	r2 = r2 - 1;
		
	m_current_line = 1;

	BeginPage(name);


	CString line_1[3];
	line_1[2] = label;
	WriteBoldRow(line_1, 2);

	CString line_2[28];
	int count = 0;
	for(int c=0; c<=25; c++)
	{
       if(labels[c] != "")
	   {
		   count = count + 1;
		   line_2[count] = labels[c];
	   }
	}

    if(count > 0) WriteBoldRow(line_2, count);

	count = 0;

	for(int r=r1; r<=r2; r++)
	{
	dlgProgress.m_progress.SetPos(r);

	CString line_3[581];
	int count = 0;
	for(int c=0; c<=25; c++)
	{
       if(strings[r][c] != "")
	   {
		   count = count + 1;
		   line_3[count] = strings[r][c];
	   }
	   
	}

    if(count > 0) WriteRow(line_3, count, false, 0);

	}
			



	EndPage();
	CString path = m_path + m_league_name + "\\";
	
	WritePage(path + name + ".htm");
}

void CHtml::GenerateTransactionPage()
{
	CString string;
	//char s[129];

	m_current_line = 1;

	//CFile file(	m_path + m_league_name + ".tra", CFile::modeRead);

	BeginPage(m_league_name + " Injuries");
	
	//int bytes = file.Read(s, 16);
	//s[bytes] = 0;
	int n = avg.m_settings.m_number_transactions;;
    int t1 = 0, t2 = 0;
	int id = 0, team = 0, games = 0;

	CString strings[] = {"","month","day","year","team","transaction","player","team"};
	WriteBoldRow(strings, 7);


	for(int i=1; i<=n; i++)
	{
		string = avg.m_trans_str[i];
		int month = atoi(string.Mid(0,2));
		int day = atoi(string.Mid(2,2));
		int year = atoi(string.Mid(4,4));
		int ty = atoi(string.Mid(8,2));
		CString str[33];
		str[1].Format("%d", month);
		str[2].Format("%d", day);
		str[3].Format("%d", year);
		int co = 3;
		CString team_name_1, team_name_2;

		if(ty == 2)
		{


			
			for(int seek = 0; seek <= 76; seek = seek + 19)
			{
			if(seek == 76 && string.GetLength() <= 95) continue;

			int pic = atoi(string.Mid(seek+10,1));

			if(pic == 0)
			{

				int team1 = atoi(string.Mid(seek+11,6)) - 1;
				int team2 = atoi(string.Mid(seek+17,6)) - 1;
				if(team1 < 0 || team2 < 0) continue;
				team_name_1 = avg.m_finance[team1].m_team_name;
				team_name_2 = avg.m_finance[team2].m_team_name;
				int id = atoi(string.Mid(seek+23,6));
				int sl = 0;
	
				co = co + 1;
				str[co] = team_name_1;

				co = co + 1;
				str[co] = "trade";



				for(int j=1; j<=1440; j++)
				{
					if(avg.m_actual[j].m_id == id) sl = j;
				}
				CPlayer m_player = avg.m_actual[sl];
				CString str1 = GetPlayerPageName(m_player);
				co = co + 1;
				str[co].Format("<a href=\"%s\">%-32s</a>", str1, m_player.m_name);

				if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
				{
					str[co] = m_player.m_name;
				}

				co = co + 1;
				str[co] = "to " + team_name_2;


			}
			else
			{
				int yr = atoi(string.Mid(seek+11,6));
				int rd = atoi(string.Mid(seek+17,6));
				int tm = atoi(string.Mid(seek+23,6)) - 1;
				if( tm >= 0)
				{
				CString year, round, team;
				year.Format("%d", yr);
				round.Format("Round %d", rd);
				team = avg.m_finance[tm].m_team_name;
				co = co + 1;
				str[co] = year;
				co = co + 1;
				str[co] = round;
				co = co + 1;
				str[co] = team;
				}
			}

			}
			WriteRow(str, co, false, 0);
			
		}
		else if(ty == 3)
		{
				int team = atoi(string.Mid(10,2)) - 1;
				CString team_name = avg.m_finance[team].m_team_name;

				int id = atoi(string.Mid(12,6));
				int sl = 0;
	
				co = co + 1;
				str[co] = team_name;

				for(int j=1; j<=1440; j++)
				{
					if(avg.m_actual[j].m_id == id) sl = j;
				}


				co = co + 1;
				str[co] = "sign";

				CPlayer m_player = avg.m_actual[sl];
				CString str1 = GetPlayerPageName(m_player);
				co = co + 1;
				str[co].Format("<a href=\"%s\">%-32s</a>", str1, m_player.m_name);

				if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
				{
					str[co] = m_player.m_name;
				}

				WriteRow(str, co, false, 0);
		}
		else if(ty == 4)
		{
				int team = atoi(string.Mid(10,2)) - 1;
				CString team_name = avg.m_finance[team].m_team_name;

				int id = atoi(string.Mid(12,6));
				int sl = 0;
	
				co = co + 1;
				str[co] = team_name;

				for(int j=1; j<=1440; j++)
				{
					if(avg.m_actual[j].m_id == id) sl = j;
				}
				co = co + 1;
				str[co] = "release";


				CPlayer m_player = avg.m_actual[sl];
				CString str1 = GetPlayerPageName(m_player);
				co = co + 1;
				str[co].Format("<a href=\"%s\">%-32s</a>", str1, m_player.m_name);

				if(m_player_page_index == 0 || (m_player_page_index >= 2 && (m_player.m_team_index+2) != m_player_page_index))
				{
					str[co] = m_player.m_name;
				}
				WriteRow(str, co, false, 0);

		}
		
	}
	EndPage();

	CString path = m_path + m_league_name + "\\";	
	WritePage(path + "Transactions" + ".htm");    
//	file.Close();		





}

void CHtml::GenerateRookiePreview()
{
	CDataSort *data = new CDataSort;
	data->avg = avg;
	//data->m_scout_team = 
	data->SortRookies();



CPlayer m_player;



	m_current_line = 1;
	int count = 30;

//	if(m_stage > 0) count = 30;

	BeginPage("");
	// = "<font size = \"1\" face = \"Tahoma\">";
	
	CString header[] = {"", "DRAFT","BOARD"};

	CString string[] = {"", "po", "player", "age", "2ga","2g%","fta","ft%","3ga","3g%","orb","drb","ast","stl","to","blk","o-o","d-o","p-o","t-o","o-d","d-d","p-d","t-d", "ta", "sk", "in"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	WriteRow(header, 2, true, 0);
	WriteRow(string, 26, true, 0);

	// = "<font size = \"1\" face = \"Tahoma\">";


	for(int p=0; p<=96; p++)
	{
		m_player = data->avg.m_actual[p];
		if(m_player.m_name == "") continue;

		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		string[1] = m_player.m_pos;
		string[2] = m_player.m_name; 
	

		string[3].Format("%d", m_player.m_age);
		string[4].Format("%d", m_player.m_prFga);
		string[5].Format("%d", m_player.m_prFgp);
		string[6].Format("%d", m_player.m_prFta);
		string[7].Format("%d", m_player.m_prFtp);
		string[8].Format("%d", m_player.m_prTga);
		string[9].Format("%d", m_player.m_prTgp);
		string[10].Format("%d", m_player.m_prOrb);
		string[11].Format("%d", m_player.m_prDrb);
		string[12].Format("%d", m_player.m_prAst);
		string[13].Format("%d", m_player.m_prStl);
		string[14].Format("%d", m_player.m_prTo);
		string[15].Format("%d", m_player.m_prBlk);
		string[16].Format("%d", m_player.m_movoff);
		string[17].Format("%d", m_player.m_penoff);
		string[18].Format("%d", m_player.m_postoff);
		string[19].Format("%d", m_player.m_transoff);
		string[20].Format("%d", m_player.m_movdef);
		string[21].Format("%d", m_player.m_pendef);
		string[22].Format("%d", m_player.m_postdef);
		string[23].Format("%d", m_player.m_transdef);
		string[24].Format("%d", m_player.m_pot1);
		string[25].Format("%d", m_player.m_pot2);
		string[26].Format("%d", m_player.m_effort);
		WriteRow(string, 26, false, 2);
	}
	EndPage();
	delete data;

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "draft" + ".htm");	
}

void CHtml::GenerateAwardsHistory()
{
	CHistoryAwards* award = new CHistoryAwards;;
	award->m_file_name = m_path + m_league_name;
	award->InitClass();
	//CPlayer m_player;


	m_current_line = 1;


	BeginPage("");

	//CString strings[] = {"","Slam Dunk","Three Point","All Star MVP"};
	//AddLine("<table>");
	//WriteBoldRow(strings, 3);
	//AddLine("</table>");


	AddLine("<table><tr><td><table>");

	CString str[33], head;
	// = "<font size = \"1\" face = \"Tahoma\">";


	//<td align="center" colspan="4"><u><b>Slam Dunk Contest:</b></u></td>
	WriteTableHeader(4, "Slam Dunk");

	for(int i=0; i<=4999; i++)
	{
		str[1] = award->m_dunkcontest_po[i];
		if(str[1] == "") continue;
		str[2] = CreateStringWithPlayerIdTag(award->m_dunkcontest_name[i], award->m_dunkcontest[i]);
		str[3] = award->m_dunkcontest_team[i];
		WriteRow(str, 3, false, 0);

	}

	AddLine("</table></td><td><table>");

	WriteTableHeader(4, "Three Point");
	for(int i=0; i<=4999; i++)
	{
		str[1] = award->m_3contest_po[i];
		if(str[1] == "") continue;
//		str[2] = award->m_3contest_name[i];



//		str[2].Format("<a href=\"%s\">%-32s</a>", str[2], award->m_3contest_name[i]);
		str[2] = CreateStringWithPlayerIdTag(award->m_3contest_name[i], award->m_3contest[i]);
		str[3] = award->m_3contest_team[i];
		WriteRow(str, 3, false, 0);

	}

	AddLine("</table></td><td><table>");
	WriteTableHeader(4, "All Star MVP");
	for(int i=0; i<=4999; i++)
	{
		str[1] = award->m_allstar_po[i];
		if(str[1] == "") continue;
		//str[2] = award->m_allstar_name[i];
		//str[2].Format("<a href=\"%s\">%-32s</a>", str[2], award->m_allstar_name[i]);
		str[2] = CreateStringWithPlayerIdTag(award->m_allstar_name[i], award->m_allstar[i]);

		str[3] = award->m_allstar_team[i];
		WriteRow(str, 3, false, 0);

	}

	AddLine("</table></td></tr>");
	EndPage();

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "temp" + ".htm");	


	delete award;
}

		






CString CHtml::CreateStringWithPlayerIdTag(CString name, int id)
{
		CString head, str, string;
		CString orig_name = name;
		head.Format("%d", id);
		name.Remove(' ');
		str = name + head + ".htm";

		string.Format("<a href=\"%s\">%-32s</a>", str, orig_name);
		return string;

}

void CHtml::WriteTableHeader(int colspan, CString string)
{
	CString str;
	str.Format("<td align=\"center\" colspan=\"%d\"><u><b>%s</b></u></td>", colspan,string);
	AddLine(str);
}

void CHtml::GenerateFaPreview()
{
	CDataSort *data = new CDataSort;
	data->avg = avg;
	//data->m_scout_team = 
	data->SortFA();



CPlayer m_player;



	m_current_line = 1;
	int count = 30;

//	if(m_stage > 0) count = 30;

	BeginPage("");
	// = "<font size = \"1\" face = \"Tahoma\">";
	
	CString header[] = {"", "FREE AGENCY","BOARD"};

	CString string[] = {"", "po", "player", "age", "2ga","2g%","fta","ft%","3ga","3g%","orb","drb","ast","stl","to","blk","o-o","d-o","p-o","t-o","o-d","d-d","p-d","t-d"};
	// = "<font size = \"2\" face = \"Tahoma\">";
	WriteRow(header, 2, true, 0);
	WriteRow(string, 23, true, 0);

	// = "<font size = \"1\" face = \"Tahoma\">";


	for(int p=1; p<=96; p++)
	{
		m_player = data->avg.m_actual[p];
		if(m_player.m_name == "") continue;

		CString str = m_player.m_name;
		int id = m_player.m_id;
		CString head;
		head.Format("%d", id);
		str.Remove(' ');
		str = str + head + ".htm";

		string[1] = m_player.m_pos;
		//string[2] = m_player.m_name; 
		string[2].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 
	

		string[3].Format("%d", m_player.m_age);
		string[4].Format("%d", m_player.m_prFga);
		string[5].Format("%d", m_player.m_prFgp);
		string[6].Format("%d", m_player.m_prFta);
		string[7].Format("%d", m_player.m_prFtp);
		string[8].Format("%d", m_player.m_prTga);
		string[9].Format("%d", m_player.m_prTgp);
		string[10].Format("%d", m_player.m_prOrb);
		string[11].Format("%d", m_player.m_prDrb);
		string[12].Format("%d", m_player.m_prAst);
		string[13].Format("%d", m_player.m_prStl);
		string[14].Format("%d", m_player.m_prTo);
		string[15].Format("%d", m_player.m_prBlk);
		string[16].Format("%d", m_player.m_movoff);
		string[17].Format("%d", m_player.m_penoff);
		string[18].Format("%d", m_player.m_postoff);
		string[19].Format("%d", m_player.m_transoff);
		string[20].Format("%d", m_player.m_movdef);
		string[21].Format("%d", m_player.m_pendef);
		string[22].Format("%d", m_player.m_postdef);
		string[23].Format("%d", m_player.m_transdef);
		WriteRow(string, 23, false, 2);
	}
	EndPage();
	delete data;

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "fapreview" + ".htm");	

}






void CHtml::FillList(CString strings[], CString heading)
{
	AddLine("");
	WriteTableHeader(1, heading);
	for(int i=1; i<=16; i++)
	{
		CString str[16];
		if(strings[i*2-1] == "") continue;
		str[1] = strings[i*2-1];
		str[2] = strings[i*2];
		WriteRow(str, 2, false, 1);	
	}

}



void CHtml::CreatePlayoffTree()
{
		int count = 0;
		int seek = 72001;

		CFile file( avg.m_settings.m_path + avg.m_settings.m_league_name + ".sch",  CFile::modeRead);

		file.Seek(seek, CFile::begin );
		
		char s[11];

		int bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format1 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format2 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format3 = CString(s);

		bytes = file.Read( s, 10);
		s[bytes] = 0;
		CString format4 = CString(s);

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		int i = atoi(s);
		int m_currentRound = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_playoffRounds = i;

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffDay = i;

		bytes = file.Read(s, 1);
		s[bytes] = 0;
		i = atoi(s);
		int m_currentPlayoffGame = i;
		int round = 1;
		bool round_over = false;
		int wins_needed = 0;
		int champions = 0;
		bool champs_found = false;
		bool started = false;
		bool rd_started = false;
		CString format = format1;
		//int w1[8] = {0,0,0,0, 0,0,0,0};

		CString table[39][6];//17 rows, 5 columns
		int row_count = 0;
		int wins[33] = {0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0};

		int po_teams = 0;
		int conf = 0;
		if(avg.m_settings.m_conferenceName1 != "") conf = conf + 1;
		if(avg.m_settings.m_conferenceName2 != "") conf = conf + 1;
		for(int i=0; i<=7; i++)
		{
			if(avg.m_sched.m_schedule[12][0][i] > 0) po_teams = po_teams + 2;
		}

		//sort playoff sched to match seeding
		int sched[28][17];
		int score[28][17];
		for(int i=0; i<=27; i++)
		{
			for(int j=0; j<=16; j++)
			{
				sched[i][j] = 0;
				score[i][j] = 0;


				//int t1 = avg.m_sched.m_schedule[12][i][j] / 100;
				//int t2 = avg.m_sched.m_schedule[12][i][j] - t1 * 100;
				//int s1 = avg.m_sched.m_game_score[12][i][j] / 100;
				//int s2 = avg.m_sched.m_game_score[12][i][j] - t1 * 100;
				//avg.m_sched.m_schedule[12][i][j] = t2*100 + t1;
				//avg.m_sched.m_game_score[12][i][j] = s2*1000 + s1;



			}
		}


		int slots[33] = {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0};
		int cou = 0;
		CString con = avg.m_settings.m_conferenceName1;
		int st = 0;
		for(int i=0; i<=6; i++)
		{
			for(int j=0; j<=16; j++)
			{
				sched[i][j] = avg.m_sched.m_schedule[12][i][j];
				score[i][j] = avg.m_sched.m_game_score[12][i][j];
				int t1 = avg.m_sched.m_schedule[12][i][j] / 100;
				int t2 = avg.m_sched.m_schedule[12][i][j] - t1 * 100;	
				if(t1 > 0 && slots[t1] == 0 && t2 > 0 && slots[t2] == 0)
				{
					if(avg.m_standings[t1].m_conference != con) st = j + 2;
					cou = cou + 1;
					slots[t1] = cou;  
					slots[t2] = cou;  
				}
			}
		
		}

		for(int i=7; i<=27; i++)
		{
			for(int j=0; j<=16; j++)
			{
				int t1 = avg.m_sched.m_schedule[12][i][j] / 100;
				int t2 = avg.m_sched.m_schedule[12][i][j] - t1 * 100;
				int new_slot_t1 = slots[t1];
				int new_slot_t2 = slots[t2];
				sched[i][new_slot_t1] = avg.m_sched.m_schedule[12][i][j];
				score[i][new_slot_t1] = avg.m_sched.m_game_score[12][i][j];
			}
		
		}


		int def[33] = {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0};
		int seed[33] = {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0};
		for(int i=0; i<=27; i++)
		{
			int cou = 0;
			for(int j=0; j<=16; j++)
			{
				int t1 = sched[i][j] / 100;
				int t2 = sched[i][j] - t1 * 100;


			

				int sc = score[i][j];
				if(t1 > 0 && t2 > 0)
				{

			

					sched[i][cou] = sched[i][j];
					score[i][cou] = score[i][j];
					if(def[t1] == 0) def[t1] = j*2+1;
					if(def[t2] == 0) def[t2] = j*2+2;
					cou = cou + 1;
				}
				
			}
			for(int j=cou; j<=16; j++)
			{
				sched[i][j] = 0;
				score[i][j] = 0;

			}
		
		}









		//for(int i=0; i<=27; i++)
		//{
			//int cou = 0;
			for(int j=0; j<=16; j++)
			{
				int t1 = sched[0][j] / 100;
				int t2 = sched[0][j] - t1 * 100;

				if(t1 == 0) continue;
			

				int sc = score[0][j];


				if(po_teams == 16 && (j==0 || j== 4) && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 1; seed[t1] = 8;
				}
				else if(po_teams == 16 && (j==1 || j==5) && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 4; seed[t1] = 5;
				}
				else if(po_teams == 16 && (j==2 || j== 6) && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 2; seed[t1] = 7;
				}
				else if(po_teams == 16 && (j==3 || j==7) && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 3; seed[t1] = 6;
				}
				else if(po_teams == 8 && j==0 && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 1; seed[t1] = 4;
				}
				else if(po_teams == 8 && j==1 && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 2; seed[t1] = 3;
				}
				else if(po_teams == 8 && j==2 && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 1; seed[t1] = 4;
				}
				else if(po_teams == 8 && j==3 && seed[t1] == 0 && conf == 2) 
				{
					seed[t2] = 2; seed[t1] = 3;
				}
				else if(po_teams <= 4)
				{
					seed[t2] = 1; seed[t1] = 2;
				}
				else if(po_teams == 8 && j==0 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 1; seed[t1] = 8;
				}
				else if(po_teams == 8 && j==1 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 4; seed[t1] = 5;
				}
				else if(po_teams == 8 && j==2 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 2; seed[t1] = 7;
				}
				else if(po_teams == 8 && j==3 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 3; seed[t1] = 6;
				}
				else if(po_teams == 4 && j==0 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 1; seed[t1] = 4;
				}
				else if(po_teams == 4 && j==1 && seed[t1] == 0 && conf == 1) 
				{
					seed[t2] = 2; seed[t1] = 3;
				}
				else
				{
					seed[t2] = 1; seed[t1] = 2;
				}



			}

		//}
	int chart[6][17];//zero them later
			for(int i=0; i<= 5; i++)
			{
				for(int j=0; j <= 16; j++)
				{
					chart[i][j] = 0;
				}
			}

		if(format != "")//no playoffs
		{




			chart[1][1] = 1;
			chart[1][2] = 3;
			chart[1][3] = 6;
			chart[1][4] = 8;
			chart[1][5] = 11;
			chart[1][6] = 13;
			chart[1][7] = 16;
			chart[1][8] = 18;

			chart[1][9] = 21;
			chart[1][10] = 23;
			chart[1][11] = 26;
			chart[1][12] = 28;
			chart[1][13] = 31;
			chart[1][14] = 33;
			chart[1][15] = 36;
			chart[1][16] = 38;

			chart[2][1] = 2;
			chart[2][2] = 7;
			chart[2][3] = 12;
			chart[2][4] = 17;
			chart[2][5] = 22;
			chart[2][6] = 27;
			chart[2][7] = 32;
			chart[2][8] = 37;


			chart[3][1] = 4;
			chart[3][2] = 14;
			chart[3][3] = 24;
			chart[3][4] = 34;


			chart[4][1] = 9;
			chart[4][2] = 29;

			chart[5][1] = 19;

			st = chart[1][st];


		
			
		for(int k = 0; k <= 15; k++ )//8 max plaoff games per day
		{

			for(int i=0; i<=32; i++){wins[i] = 0;}
			for(int  j = 0; j <= 6; j++ )//28 playoff days
			{
				format = format1.GetAt(0);
				wins_needed = atoi(format);
				int round = 1;
				int team1 = sched[j][k] / 100;
				int score1 = score[j][k] / 1000;
				int team2 = sched[j][k] - team1 * 100;
				int score2 = score[j][k] - score1 * 1000;
				if(score1 > score2) wins[team1] = wins[team1] + 1;
				else if(score2 > score1) wins[team2] = wins[team2] + 1;

				CString result1, result2;
				if(team1 > 0 && team2 > 0 && score1 > 0 && score2 > 0
					&& (wins[team1] == wins_needed || wins[team2] == wins_needed))
				{
					int rec_win1 = avg.m_standings[team1-1].m_leagueRecord / 100;
					int rec_loss1 = avg.m_standings[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = avg.m_standings[team2-1].m_leagueRecord / 100;
					int rec_loss2 = avg.m_standings[team2-1].m_leagueRecord - rec_win2 * 100;

					CString matchup;
					CString teamName1 = avg.m_settings.m_leagueTeamNames[team1-1];
					CString teamName2 = avg.m_settings.m_leagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;					
					//result1.Format("%s %d ", teamName1, wins[team1]);
					//result2.Format("%s %d ", teamName2, wins[team2]);
					result1.Format("(%i) %s %d ", seed[team1], teamName1, wins[team1]);
					result2.Format("(%i) %s %d ", seed[team2], teamName2, wins[team2]);

					if(def[team1] < def[team2]) 
					{
						CString temp = result1;
						result1 = result2;
						result2 = temp;
					}
					row_count = k*2 + 1;
					int row = chart[round][row_count];
					table[row][round] = result1; 
					row_count = k*2 + 2;
					row = chart[round][row_count];
					table[row][round] = result2;
					if(wins[team1] == wins_needed) table[1][5] = teamName1;
					else if(wins[team2] == wins_needed) table[1][5] = teamName2;
					
					
				}

			}

		}



		for(int k = 0; k <= 15; k++ )//8 max plaoff games per day
		{


			for(int i=0; i<=32; i++){wins[i] = 0;}
			for(int j = 7; j <= 13; j++ )//28 playoff days
			{
				format = format2.GetAt(0);
				wins_needed = atoi(format);
				int round = 2;
				int team1 = sched[j][k] / 100;
				int score1 = score[j][k] / 1000;
				int team2 = sched[j][k] - team1 * 100;
				int score2 = score[j][k] - score1 * 1000;
				if(score1 > score2) wins[team1] = wins[team1] + 1;
				else if(score2 > score1) wins[team2] = wins[team2] + 1;
				CString result1, result2;
				if(team1 > 0 && team2 > 0 && score1 > 0 && score2 > 0
					&& (wins[team1] == wins_needed || wins[team2] == wins_needed))
				{

					int rec_win1 = avg.m_standings[team1-1].m_leagueRecord / 100;
					int rec_loss1 = avg.m_standings[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = avg.m_standings[team2-1].m_leagueRecord / 100;
					int rec_loss2 = avg.m_standings[team2-1].m_leagueRecord - rec_win2 * 100;

					CString matchup;
					CString teamName1 = avg.m_settings.m_leagueTeamNames[team1-1];
					CString teamName2 = avg.m_settings.m_leagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;					
					result1.Format("(%i) %s %d ", seed[team1], teamName1, wins[team1]);
					result2.Format("(%i) %s %d ", seed[team2], teamName2, wins[team2]);
					//row_count = games;
					if(def[team1] > def[team2]) 
					{
						CString temp = result1;
						result1 = result2;
						result2 = temp;
					}
					//row_count = k+1;
					row_count = k*2 + 1;
					int row = chart[round][row_count];
					table[row][round] = result1; 
					//row_count = games + 1;
					row_count = k*2 + 2;
					row = chart[round][row_count];
					table[row][round] = result2; 
					if(wins[team1] == wins_needed) table[1][5] = teamName1;
					else if(wins[team2] == wins_needed) table[1][5] = teamName2;
					
				}

			}

		}
		for(int k = 0; k <= 15; k++ )//8 max plaoff games per day
		{

			for(int i=0; i<=32; i++){wins[i] = 0;}
			for(int  j = 14; j <= 20; j++ )//28 playoff days
			{
				format = format3.GetAt(0);
				wins_needed = atoi(format);
				int round = 3;
				int team1 = sched[j][k] / 100;
				int score1 = score[j][k] / 1000;
				int team2 = sched[j][k] - team1 * 100;
				int score2 = score[j][k] - score1 * 1000;
				if(score1 > score2) wins[team1] = wins[team1] + 1;
				else if(score2 > score1) wins[team2] = wins[team2] + 1;
				CString result1, result2;
				if(team1 > 0 && team2 > 0 && score1 > 0 && score2 > 0
					&& (wins[team1] == wins_needed || wins[team2] == wins_needed))
				{
					int rec_win1 = avg.m_standings[team1-1].m_leagueRecord / 100;
					int rec_loss1 = avg.m_standings[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = avg.m_standings[team2-1].m_leagueRecord / 100;
					int rec_loss2 = avg.m_standings[team2-1].m_leagueRecord - rec_win2 * 100;

					CString matchup;
					CString teamName1 = avg.m_settings.m_leagueTeamNames[team1-1];
					CString teamName2 = avg.m_settings.m_leagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;					
//					result1.Format("%s %d ", teamName1, wins[team1]);
//					result2.Format("%s %d ", teamName2, wins[team2]);
					result1.Format("(%i) %s %d ", seed[team1], teamName1, wins[team1]);
					result2.Format("(%i) %s %d ", seed[team2], teamName2, wins[team2]);
					if(def[team1] > def[team2]) 
					{
						CString temp = result1;
						result1 = result2;
						result2 = temp;
					}
					//row_count = k+1;
					row_count = k*2 + 1;
					//row_count = games;
					int row = chart[round][row_count];
					table[row][round] = result1; 
					row_count = k*2 + 2;
					//row_count = games + 1;
					row = chart[round][row_count];
					table[row][round] = result2; 
					if(wins[team1] == wins_needed) table[1][5] = teamName1;
					else if(wins[team2] == wins_needed) table[1][5] = teamName2;
					
				}

			}

		}

		for(int k = 0; k <= 15; k++ )//8 max plaoff games per day
		{

			for(int i=0; i<=32; i++){wins[i] = 0;}
			for(int  j = 21; j <= 27; j++ )//28 playoff days
			{
				format = format4.GetAt(0);
				wins_needed = atoi(format);
				int round = 4;
				int team1 = sched[j][k] / 100;
				int score1 = score[j][k] / 1000;
				int team2 = sched[j][k] - team1 * 100;
				int score2 = score[j][k] - score1 * 1000;
				if(score1 > score2) wins[team1] = wins[team1] + 1;
				else if(score2 > score1) wins[team2] = wins[team2] + 1;
				CString result1, result2;
				if(team1 > 0 && team2 > 0 && score1 > 0 && score2 > 0
					&& (wins[team1] == wins_needed || wins[team2] == wins_needed))
				{

					int rec_win1 = avg.m_standings[team1-1].m_leagueRecord / 100;
					int rec_loss1 = avg.m_standings[team1-1].m_leagueRecord - rec_win1 * 100;
					int rec_win2 = avg.m_standings[team2-1].m_leagueRecord / 100;
					int rec_loss2 = avg.m_standings[team2-1].m_leagueRecord - rec_win2 * 100;

					CString matchup;
					CString teamName1 = avg.m_settings.m_leagueTeamNames[team1-1];
					CString teamName2 = avg.m_settings.m_leagueTeamNames[team2-1];
					CString teamNameScore1 = teamName1;
					CString teamNameScore2 = teamName2;					
//					result1.Format("%s %d ", teamName1, wins[team1]);
//					result2.Format("%s %d ", teamName2, wins[team2]);
					result1.Format("(%i) %s %d ", seed[team1], teamName1, wins[team1]);
					result2.Format("(%i) %s %d ", seed[team2], teamName2, wins[team2]);
					if(def[team1] > def[team2]) 
					{
						CString temp = result1;
						result1 = result2;
						result2 = temp;
					}
					//row_count = k+1;
					//row_count = games;
					row_count = k*2 + 1;
					int row = chart[round][row_count];
					table[row][round] = result1; 
					//row_count = games + 1;
					row_count = k*2 + 2;
					row = chart[round][row_count];
					table[row][round] = result2; 
					if(wins[team1] == wins_needed) table[1][5] = teamName1;
					else if(wins[team2] == wins_needed) table[1][5] = teamName2;
					
				}

			}

		}




		}


	BeginPage("PLAYOFF BRACKET");
//	AddLine("<table><tr><td><table>");
//	WriteTableHeader(4, "Playoff Tree");
	CString cnf[2];
	//cnf[1] = avg.m_settings.m_conferenceName1;
	cnf[1] = avg.m_settings.m_conferenceName1 + " conference";
	cnf[1].MakeUpper();
	WriteRow(cnf, 1, true, 0);

	CString str[33];
	table[chart[5][1]][5] = table[1][5];//lower spot for final round champion
	table[1][5] = "";
	if(m_currentRound != m_playoffRounds)
		table[chart[5][1]][5] = "";//no champion yet

	table[chart[5][1]][5].MakeUpper();


	//Write headers for rounds;
	CString lab[5];
	if(m_playoffRounds == 1)
	{
		lab[1] = "Finals";
	}
	else if(m_playoffRounds == 2)
	{
		lab[1] = "Conference Finals";
		lab[2] = "Finals";
	}
	else if(m_playoffRounds == 3)
	{
		lab[2] = "Conference Finals";
		lab[3] = "Finals";
		lab[1] = "Conference Semis";
	}
	else if(m_playoffRounds == 4)
	{
		lab[3] = "Conference Finals";
		lab[4] = "Finals";
		lab[2] = "Conference Semis";
		lab[1] = "Opening Round";
	}

	WriteRow(lab, 4, true, 0);


	for(int r=1; r<=38; r++)
	{
		for(int c=1; c<=5; c++)
		{
			str[c] = table[r][c];
		}
		if(st == r)
		{
			CString cnf[2];
			cnf[1] = avg.m_settings.m_conferenceName2 + " conference";
			cnf[1].MakeUpper();
			WriteRow(cnf, 1, true, 0);
		}
		WriteRow(str, 5, false, 0);
	}


	AddLine("</table></td><td><table>");
	EndPage();
	CString path = m_path + m_league_name + "\\";
	WritePage(path + "Bracket" + ".htm");	

}




void CHtml::GenerateScoutPage()
{



	m_current_line = 1;
	BeginPage("");
	CString header[] = {"", "SCOUTS","RATINGS"};
	CString string[] = {"", "scout", "team", "age", "talent", "skill","intangibles","scoring","shooting","rebound","ball handling","defense","win","loss","playoffs","rings"};
	WriteRow(header, 2, true, 0);
	WriteRow(string, 15, true, 0);


	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};

	for(int p=0; p<=99; p++)
	{

	CStaff m_player = avg.m_scout[p];
	CString str = m_player.m_name;
	int id = p;
	CString head;
	head.Format("%d", id);
	str.Remove(' ');
	str = str + head + ".htm";
//	string[1].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 
	string[1] = m_player.m_name;

	CString team = m_player.m_team;
	if(str == "") continue;
	if(team == "") team = "none";
	string[2] = team;
	string[3].Format("%d", m_player.m_age);
	string[4].Format("%s", lbl[m_player.m_pot1Rating]);
	string[5].Format("%s", lbl[m_player.m_pot2Rating]);
	string[6].Format("%s", lbl[m_player.m_effortRating]);
	string[7].Format("%s", lbl[m_player.m_scoringRating]);
	string[8].Format("%s", lbl[m_player.m_shootingRating]);
	string[9].Format("%s", lbl[m_player.m_reboundingRating]);
	string[10].Format("%s", lbl[m_player.m_passingRating]);
	string[11].Format("%s", lbl[m_player.m_defenseRating]);
	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[12].Format("%d", win);
	string[13].Format("%d", loss);
	string[14].Format("%d", m_player.m_playoffs);
	string[15].Format("%d", m_player.m_rings);
	WriteRow(string, 15, false, 1);
	}
	EndPage();

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "scouts" + ".htm");	

}


void CHtml::GenerateCoachPage()
{

	m_current_line = 1;
	BeginPage("");
	CString header[] = {"", "COACHES","RATINGS"};
	CString string[] = {"", "coach", "team", "age",
		"ta", "sk","int","sc","sh","rb","bh","de","<-develop - coach->",
		"out", "drv", "pst", "trns", "out-d", "drv-d", "pst-d", "trns-d", "cnd", "win","loss","po","ring"};
	WriteRow(header, 2, true, 0);
	WriteRow(string, 25, true, 0);


	CString lbl[] = {"", "F", "D", "C", "B", "A"};

	for(int p=0; p<=99; p++)
	{

	CStaff m_player = avg.m_coach[p];
	CString str = m_player.m_name;
	int id = p;
	CString head;
	head.Format("%d", id);
	str.Remove(' ');
	str = str + head + ".htm";
	//string[1].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); 
	string[1] = m_player.m_name;

	CString team = m_player.m_team;
	if(str == "") continue;
	if(team == "") team = "none";
	string[2] = team;
	string[3].Format("%d", m_player.m_age);
	string[4].Format("%s", lbl[m_player.m_coachPot1]);
	string[5].Format("%s", lbl[m_player.m_coachPot2]);
	string[6].Format("%s", lbl[m_player.m_coachEffort]);
	string[7].Format("%s", lbl[m_player.m_coachScoring]);
	string[8].Format("%s", lbl[m_player.m_coachShooting]);
	string[9].Format("%s", lbl[m_player.m_coachRebounding]);
	string[10].Format("%s", lbl[m_player.m_coachPassing]);
	string[11].Format("%s", lbl[m_player.m_coachDefense]);

	string[12] = "";
	string[13].Format("%s", lbl[m_player.m_coachO]);
	string[14].Format("%s", lbl[m_player.m_coachP]);
	string[15].Format("%s", lbl[m_player.m_coachI]);
	string[16].Format("%s", lbl[m_player.m_coachF]);
	string[17].Format("%s", lbl[m_player.m_coachOD]);
	string[18].Format("%s", lbl[m_player.m_coachPD]);
	string[19].Format("%s", lbl[m_player.m_coachID]);
	string[20].Format("%s", lbl[m_player.m_coachFD]);
	string[21].Format("%s", lbl[m_player.m_coachEndurance]);



	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[22].Format("%d", win);
	string[23].Format("%d", loss);
	string[24].Format("%d", m_player.m_playoffs);
	string[25].Format("%d", m_player.m_rings);
	WriteRow(string, 25, false, 1);
	}
	EndPage();

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "coaches" + ".htm");	

}


void CHtml::GenerateGmPage()
{



	m_current_line = 1;
	BeginPage("");
	CString header[] = {"", "GM","RATINGS"};
	CString string[] = {"", "gm", "team", "age", "talent", "skill","intangibles","scoring","shooting","rebound","ball handling","defense","win","loss","playoffs","rings"};
	WriteRow(header, 2, true, 0);
	WriteRow(string, 15, true, 0);


	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};

	for(int p=0; p<=99; p++)
	{

	CStaff m_player = avg.m_gm[p];
	CString str = m_player.m_name;
	int id = p;
	CString head;
	head.Format("%d", id);
	str.Remove(' ');
	str = str + head + ".htm";
	//string[1].Format("<a href=\"%s\">%-32s</a>", str, m_player.m_name); use if making link
	string[1] = m_player.m_name;
	CString team = m_player.m_team;
	if(str == "") continue;
	if(team == "") team = "none";
	string[2] = team;
	string[3].Format("%d", m_player.m_age);
	string[4].Format("%s", lbl[m_player.m_pot1Rating]);
	string[5].Format("%s", lbl[m_player.m_pot2Rating]);
	string[6].Format("%s", lbl[m_player.m_effortRating]);
	string[7].Format("%s", lbl[m_player.m_scoringRating]);
	string[8].Format("%s", lbl[m_player.m_shootingRating]);
	string[9].Format("%s", lbl[m_player.m_reboundingRating]);
	string[10].Format("%s", lbl[m_player.m_passingRating]);
	string[11].Format("%s", lbl[m_player.m_defenseRating]);
	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[12].Format("%d", win);
	string[13].Format("%d", loss);
	string[14].Format("%d", m_player.m_playoffs);
	string[15].Format("%d", m_player.m_rings);
	WriteRow(string, 15, false, 1);
	}
	EndPage();

	CString path = m_path + m_league_name + "\\";
	WritePage(path + "gms" + ".htm");	

}