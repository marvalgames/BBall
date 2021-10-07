// CityProfileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "CityProfileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCityProfileDlg dialog


CCityProfileDlg::CCityProfileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCityProfileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCityProfileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCityProfileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCityProfileDlg)
	DDX_Control(pDX, IDC_LIST_REVENUE, m_list_revenues);
	DDX_Control(pDX, IDC_LIST_EXPENSES, m_list_expenses);
	DDX_Control(pDX, IDC_LIST_CITY, m_list_city);
	DDX_Control(pDX, IDC_LIST_ARENA, m_list_arena);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCityProfileDlg, CDialog)
	//{{AFX_MSG_MAP(CCityProfileDlg)
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCityProfileDlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCityProfileDlg message handlers

BOOL CCityProfileDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	CString heading;
	CString city_name = m_finance[100].m_city_name;
	CString arena_name = m_finance[100].m_arena_name;
	CString team_name = m_finance[100].m_team_name;

	heading.Format("%s %s - %s", city_name, team_name, arena_name);

	SetWindowText(heading);
	InitListCtrl();
	InitLabels();
	SetListBoxHeaders();
	ListExpenses();
	ListRevenues();
	ListArena();
	ListCity();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CCityProfileDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
switch (nCtlColor)
     {
     //Edit controls need white background and black text
     //Note the 'return hbr' which is needed to draw the Edit
     //control's internal background (as opposed to text background)
     case CTLCOLOR_EDIT:
          pDC->SetTextColor(EDITCOLOR);
          pDC->SetBkColor(EDITBKCOLOR);
          return hbr;
     //Static controls need black text and same background as myBrush
     case CTLCOLOR_STATIC:
          LOGBRUSH logbrush;
          myBrush.GetLogBrush( &logbrush );
          pDC->SetTextColor(STATICCOLOR);
          pDC->SetBkColor(logbrush.lbColor);
          return myBrush;
     case CTLCOLOR_BTN:
          pDC->SetTextColor(RGB(0,255,255));
          pDC->SetBkColor(RGB(255,128,128));
          return myBrush;
     case CTLCOLOR_LISTBOX:
          pDC->SetBkColor(LISTBOXCOLOR);
          pDC->SetTextColor(LISTBOXTEXTCOLOR);
          return myBrush;

     case CTLCOLOR_SCROLLBAR:
          pDC->SetTextColor(RGB(0,0,0));
          pDC->SetBkColor(LISTBOXCOLOR);
          return myBrush;

     case CTLCOLOR_MSGBOX:
          pDC->SetTextColor(RGB(255,255,255));
          pDC->SetBkColor(RGB(255,128,128));
          return myBrush;

     case CTLCOLOR_DLG:
          return myBrush;
     //This shouldn't occurr since we took all the cases, but
     //JUST IN CASE, return the new brush
     default:
          return hbr;
     } 	
	


//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}

void CCityProfileDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	WinHelp(HID_FINANCES_CITYPROFILE);	
//	return TRUE;

	
}

BOOL CCityProfileDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	WinHelp(HID_FINANCES_CITYPROFILE);	
	return TRUE;
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CCityProfileDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CCityProfileDlg::InitListCtrl()
{

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_expenses.SetBkColor(BK_COLOR);
	m_list_expenses.SetTextBkColor(TEXT_BK_COLOR);
    m_list_expenses.SetTextColor(RGB(0,0,0));
	m_list_expenses.SetFont(&m_font);

	m_list_revenues.SetBkColor(BK_COLOR);
	m_list_revenues.SetTextBkColor(TEXT_BK_COLOR);
    m_list_revenues.SetTextColor(RGB(0,0,0));
	m_list_revenues.SetFont(&m_font);

	m_list_arena.SetBkColor(BK_COLOR);
	m_list_arena.SetTextBkColor(TEXT_BK_COLOR);
    m_list_arena.SetTextColor(RGB(0,0,0));
	m_list_arena.SetFont(&m_font);

	m_list_city.SetBkColor(BK_COLOR);
	m_list_city.SetTextBkColor(TEXT_BK_COLOR);
    m_list_city.SetTextColor(RGB(0,0,0));
	m_list_city.SetFont(&m_font);

	m_list_arena.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_city.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_revenues.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_expenses.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


}

void CCityProfileDlg::InitLabels()
{

	m_label[1][0] = "player salaries";
	m_label[1][1] = "scouting";
	m_label[1][2] = "coaching";
	m_label[1][3] = "general manager";
	m_label[1][4] = "operating";
	m_label[1][5] = "arena maintenance";
	m_label[1][6] = "marketing costs";
	m_label[1][7] = "total expenses";

	m_label[2][0] = "ticket price";
	m_label[2][1] = "attendance revenue";
	m_label[2][2] = "suite price";
	m_label[2][3] = "suite revenue";
	m_label[2][4] = "club seat price";
	m_label[2][5] = "club seat revenue";
	m_label[2][6] = "concession pack price";
	m_label[2][7] = "concession pack revenue";
	m_label[2][8] = "parking price";
	m_label[2][9] = "parking revenue";	

	m_label[2][10] = "local television";
	m_label[2][11] = "local radio";
	m_label[2][12] = "arena advertising";
	m_label[2][13] = "arena sponsorship";	

	m_label[2][14] = "total revenue";
	m_label[2][15] = " arena value";
	m_label[2][16] = " team value";
	m_label[2][17] = " profit";
	
	m_label[3][0] = "arena capacity";
	m_label[3][1] = "attendance avg";
	m_label[3][2] = "attendance pct";
	m_label[3][3] = "suite capacity";
	m_label[3][4] = "suite avg";
	m_label[3][5] = "suite pct";
	m_label[3][6] = "club seat capacity";
	m_label[3][7] = "club seat avg";
	m_label[3][8] = "club seat pct";
	m_label[3][9] = "parking capacity";
	m_label[3][10] = "parking avg";
	m_label[3][11] = "parking pct";

	m_label[4][0] = "fan support";
	m_label[4][1] = "political support";
	m_label[4][2] = "general interest";
	m_label[4][3] = "local competition";
	m_label[4][4] = "local economy";
	m_label[4][5] = "cost of living";
	m_label[4][6] = "population";

}

void CCityProfileDlg::ListExpenses()
{
	m_list_expenses.DeleteAllItems();
	CTeamFinancial fin = m_finance[100];

	double g = (double)fin.m_home_games;
		if(g == 0) g = 1;

		CString Stats[33];

		
		double r = (double)fin.m_season_payroll/ 1000000;
		Stats[0].Format("%.2f", r);

		r = (double)fin.m_season_scout_expenses/ 1000000;
		Stats[1].Format("%.2f", r);

		r = (double)fin.m_season_coach_expenses/ 1000000;
		Stats[2].Format("%.2f", r);

		r = (double)fin.m_season_gm_expenses/ 1000000;
		Stats[3].Format("%.2f", r);

		r = (double)fin.m_season_operating_expenses/ 1000000;
		Stats[4].Format("%.2f", r);

		r = (double)fin.m_season_arena_expenses/ 1000000;
		Stats[5].Format("%.2f", r);

		r = (double)fin.m_season_marketing_expenses/ 1000000;
		Stats[6].Format("%.2f", r);

		r = (double)fin.m_season_total_expenses/ 1000000;
		Stats[7].Format("%.2f", r);


//r = ((double)fin.m_season_total_revenue - (double)fin.m_season_total_expenses) / 1000000;
//Stats[8].Format("%.2f", r);

	CTeamFinancial fin_l = m_finance[200];

		g = (double)fin_l.m_home_games;
		if(g == 0) g = 1;

		CString Stats_l[33];

		
		r = (double)fin_l.m_season_payroll/ 1000000;
		Stats_l[0].Format("%.2f", r);

		r = (double)fin_l.m_season_scout_expenses/ 1000000;
		Stats_l[1].Format("%.2f", r);

		r = (double)fin_l.m_season_coach_expenses/ 1000000;
		Stats_l[2].Format("%.2f", r);

		r = (double)fin_l.m_season_gm_expenses/ 1000000;
		Stats_l[3].Format("%.2f", r);

		r = (double)fin_l.m_season_operating_expenses/ 1000000;
		Stats_l[4].Format("%.2f", r);

		r = (double)fin_l.m_season_arena_expenses/ 1000000;
		Stats_l[5].Format("%.2f", r);

		r = (double)fin_l.m_season_marketing_expenses/ 1000000;
		Stats_l[6].Format("%.2f", r);

		r = (double)fin_l.m_season_total_expenses/ 1000000;
		Stats_l[7].Format("%.2f", r);

	for(int  index = 0; index < 19; index++)
	{
		if(Stats[index] == "") continue;
		m_list_expenses.InsertItem(index, m_label[1][index]);
		m_list_expenses.SetItemText(index, 1, Stats[index]);
		m_list_expenses.SetItemText(index, 2, Stats_l[index]);
	}
}

void CCityProfileDlg::SetListBoxHeaders()
{
	m_list_expenses.DeleteAllItems();
	m_list_expenses.DeleteColumn(0);
    m_list_expenses.InsertColumn(0,"expenses");    
	m_list_expenses.DeleteColumn(1);
    m_list_expenses.InsertColumn(1,"current");    
	m_list_expenses.DeleteColumn(2);
    m_list_expenses.InsertColumn(2,"last");    
    m_list_expenses.SetColumnWidth( 0, 120);
    m_list_expenses.SetColumnWidth( 1, 80);
    m_list_expenses.SetColumnWidth( 2, 80);

	m_list_revenues.DeleteAllItems();
	m_list_revenues.DeleteColumn(0);
    m_list_revenues.InsertColumn(0,"revenues");    
	m_list_revenues.DeleteColumn(1);
    m_list_revenues.InsertColumn(1,"current");    
	m_list_revenues.DeleteColumn(2);
    m_list_revenues.InsertColumn(2,"last");    
    m_list_revenues.SetColumnWidth( 0, 120);
    m_list_revenues.SetColumnWidth( 1, 79);
    m_list_revenues.SetColumnWidth( 2, 79);

	m_list_arena.DeleteAllItems();
	m_list_arena.DeleteColumn(0);
    m_list_arena.InsertColumn(0,"attendance");    
	m_list_arena.DeleteColumn(1);
    m_list_arena.InsertColumn(1,"current");    
	m_list_arena.DeleteColumn(2);
    m_list_arena.InsertColumn(2,"last");    
    m_list_arena.SetColumnWidth( 0, 120);
    m_list_arena.SetColumnWidth( 1, 79);
    m_list_arena.SetColumnWidth( 2, 79);

	m_list_city.DeleteAllItems();
	m_list_city.DeleteColumn(0);
    m_list_city.InsertColumn(0,"city ratings");    
	m_list_city.DeleteColumn(1);
    m_list_city.InsertColumn(1,"current");    
	m_list_city.DeleteColumn(2);
    m_list_city.InsertColumn(2,"last");    
    m_list_city.SetColumnWidth( 0, 120);
    m_list_city.SetColumnWidth( 1, 79);
    m_list_city.SetColumnWidth( 2, 79);
}

void CCityProfileDlg::ListRevenues()
{

		m_list_revenues.DeleteAllItems();
		CTeamFinancial fin = m_finance[100];

		double g = (double)fin.m_home_games;
		if(g == 0) g = 1;

		CString Stats[33];
		
		double r = (double)fin.m_ticket_price / 10;
		Stats[0].Format("%.f", r);

		r = (double)fin.m_att_revenue/ 1000000;
		Stats[1].Format("%.2f", r);

		r = (double)fin.m_suite_price;
		Stats[2].Format("%.f", r);

		r = (double)fin.m_season_suite_revenue/ 1000000;
		Stats[3].Format("%.2f", r);

		r = (double)fin.m_club_price;
		Stats[4].Format("%.f", r);

		r = (double)fin.m_season_club_revenue/ 1000000;
		Stats[5].Format("%.2f", r);

		r = (double)fin.m_concessions / 10;
		Stats[6].Format("%.f", r);

		r = (double)fin.m_season_concession_revenue/ 1000000;
		Stats[7].Format("%.2f", r);

		r = (double)fin.m_parking;
		Stats[8].Format("%.f", r);

		r = (double)fin.m_season_parking_revenue/ 1000000;
		Stats[9].Format("%.2f", r);


		r = (double)fin.m_local_tv * (double)m_hi_games / 1000000;
		Stats[10].Format("%.2f", r);
	    r = (double)fin.m_local_radio * (double)m_hi_games / 1000000;
		Stats[11].Format("%.2f", r);
	    r = (double)fin.m_advertising * (double)m_hi_games / 1000000;
		Stats[12].Format("%.2f", r);
	    r = (double)fin.m_sponsorship * (double)m_hi_games / 1000000;
		Stats[13].Format("%.2f", r);

		r = (double)fin.m_season_total_revenue / 1000000;
		Stats[14].Format("%.2f", r);

		r = (double)fin.m_stadium_value;
		Stats[15].Format("%.f", r);

		r = (double)fin.m_current_value / 10;
		Stats[16].Format("%.f", r);

		r = ((double)fin.m_season_total_revenue - (double)fin.m_season_total_expenses) / 1000000;
		Stats[17].Format("%.2f", r);

		CTeamFinancial fin_l = m_finance[200];

		g = (double)fin_l.m_home_games;
		if(g == 0) g = 1;

		CString Stats_l[33];
		
		r = (double)fin_l.m_ticket_price / 10;
		Stats_l[0].Format("%.f", r);

		r = (double)fin_l.m_att_revenue/ 1000000;
		Stats_l[1].Format("%.2f", r);

		r = (double)fin_l.m_suite_price;
		Stats_l[2].Format("%.f", r);

		r = (double)fin_l.m_season_suite_revenue/ 1000000;
		Stats_l[3].Format("%.2f", r);

		r = (double)fin_l.m_club_price;
		Stats_l[4].Format("%.f", r);

		r = (double)fin_l.m_season_club_revenue/ 1000000;
		Stats_l[5].Format("%.2f", r);

		r = (double)fin_l.m_concessions / 10;
		Stats_l[6].Format("%.f", r);

		r = (double)fin_l.m_season_concession_revenue/ 1000000;
		Stats_l[7].Format("%.2f", r);

		r = (double)fin_l.m_parking;
		Stats_l[8].Format("%.f", r);

		r = (double)fin_l.m_season_parking_revenue/ 1000000;
		Stats_l[9].Format("%.2f", r);

		r = (double)fin_l.m_local_tv * (double)m_hi_games / 1000000;
		Stats_l[10].Format("%.2f", r);
	    r = (double)fin_l.m_local_radio * (double)m_hi_games / 1000000;
		Stats_l[11].Format("%.2f", r);
	    r = (double)fin_l.m_advertising * (double)m_hi_games / 1000000;
		Stats_l[12].Format("%.2f", r);
	    r = (double)fin_l.m_sponsorship * (double)m_hi_games / 1000000;
		Stats_l[13].Format("%.2f", r);




		r = (double)fin_l.m_season_total_revenue / 1000000;
		Stats_l[14].Format("%.2f", r);

		r = (double)fin_l.m_stadium_value;
		Stats_l[15].Format("%.f", r);

		r = (double)fin_l.m_current_value / 10;
		Stats_l[16].Format("%.f", r);

		r = ((double)fin_l.m_season_total_revenue - (double)fin_l.m_season_total_expenses) / 1000000;
		Stats_l[17].Format("%.2f", r);



	for(int  index = 0; index < 19; index++)
	{
		if(Stats[index] == "") continue;
		m_list_revenues.InsertItem(index, m_label[2][index]);
		m_list_revenues.SetItemText(index, 1, Stats[index]);
		m_list_revenues.SetItemText(index, 2, Stats_l[index]);
	}
	//	m_list_revenues.InsertItem(0,Stats[0]);
	//	for(int s=0; s<=20; s++)
	//	{	
	//		m_list_revenues.SetItemText(co,s+1,Stats[s+1]);
	//	}

}

void CCityProfileDlg::ListArena()
{
	m_list_arena.DeleteAllItems();
	CTeamFinancial fin = m_finance[100];

		CString Stats[33];


	double g = (double)fin.m_home_games;
		if(g == 0) g = 1;

		double r = fin.m_capacity;
		Stats[0 ].Format("%.f", r);

		r = (fin.m_season_att + fin.m_season_suites_sold*20 + fin.m_season_clubs_sold) / g;
		Stats[1].Format("%.f", r);

		int pct = int((fin.m_season_att + fin.m_season_suites_sold*20 + fin.m_season_clubs_sold) / ((double)fin.m_capacity * g) * 1000);
		r = (double) pct / 10;
		Stats[2 ].Format("%.2f", r);

		r = fin.m_suites;
		Stats[3 ].Format("%.f", r);

		r = fin.m_season_suites_sold / g;
		Stats[4 ].Format("%.f", r);

		pct = int((double)fin.m_season_suites_sold / ((double)fin.m_suites * g) * 1000);
		r = (double) pct / 10;
		Stats[5 ].Format("%.2f", r);

		r = fin.m_club_seats;
		Stats[6 ].Format("%.f", r);

		r = fin.m_season_clubs_sold / g;
		Stats[7 ].Format("%.f", r);

		pct = int((double) fin.m_season_clubs_sold / ((double)fin.m_club_seats * g) * 1000);
		r = (double) pct / 10;
		Stats[8 ].Format("%.2f", r);

		int d = fin.m_parking_spots;
		Stats[9 ].Format("%d", d);

		if(fin.m_parking == 0) r = 0;
		else r = fin.m_season_parking_revenue / (double)fin.m_parking / g;
		Stats[10 ].Format("%.f", r);

		pct = int((double) fin.m_season_parking_revenue / (double) fin.m_parking / ((double)fin.m_parking_spots * g) * 1000);
		r = (double) pct / 10;
		Stats[11 ].Format("%.2f", r);	

		CString Stats_l[33];
		
		CTeamFinancial fin_l = m_finance[200];


		g = (double)fin_l.m_home_games;
		if(g == 0) g = 1;

		r = fin_l.m_capacity;
		Stats_l[0 ].Format("%.f", r);

		r = (fin_l.m_season_att + fin_l.m_season_suites_sold*20 + fin_l.m_season_clubs_sold) / g;
		Stats_l[1].Format("%.f", r);

		pct = int((fin_l.m_season_att + fin_l.m_season_suites_sold*20 + fin_l.m_season_clubs_sold) / ((double)fin_l.m_capacity * g) * 1000);
		r = (double) pct / 10;
		Stats_l[2 ].Format("%.2f", r);

		r = fin_l.m_suites;
		Stats_l[3 ].Format("%.f", r);

		r = fin_l.m_season_suites_sold / g;
		Stats_l[4 ].Format("%.f", r);

		pct = int((double)fin_l.m_season_suites_sold / ((double)fin_l.m_suites * g) * 1000);
		r = (double) pct / 10;
		Stats_l[5 ].Format("%.2f", r);

		r = fin_l.m_club_seats;
		Stats_l[6 ].Format("%.f", r);

		r = fin_l.m_season_clubs_sold / g;
		Stats_l[7 ].Format("%.f", r);

		pct = int((double) fin_l.m_season_clubs_sold / ((double)fin_l.m_club_seats * g) * 1000);
		r = (double) pct / 10;
		Stats_l[8 ].Format("%.2f", r);

		d = fin_l.m_parking_spots;
		Stats_l[9 ].Format("%d", d);

		if(fin_l.m_parking == 0) r = 0;
		else r = fin_l.m_season_parking_revenue / (double)fin_l.m_parking / g;
		Stats_l[10 ].Format("%.f", r);

		pct = int((double) fin_l.m_season_parking_revenue / (double) fin_l.m_parking / ((double)fin_l.m_parking_spots * g) * 1000);
		r = (double) pct / 10;
		Stats_l[11 ].Format("%.2f", r);	


	for(int  index = 0; index < 19; index++)
	{
		if(Stats[index] == "") continue;
		m_list_arena.InsertItem(index, m_label[3][index]);
		m_list_arena.SetItemText(index, 1, Stats[index]);
		m_list_arena.SetItemText(index, 2, Stats_l[index]);
	}
		
	//	m_list_arena.InsertItem(co,Stats[0]);
	//	for(int s=0; s<=20; s++)
	//	{	
	//		m_list_arena.SetItemText(co,s+1,Stats[s+1]);
	//	}


}

void CCityProfileDlg::ListCity()
{

	m_list_city.DeleteAllItems();
	CTeamFinancial fin = m_finance[100];


	double g = (double)fin.m_home_games;
		if(g == 0) g = 1;


		CString Stats[33];
		
		CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};

		int r = fin.m_fan_support;
		Stats[0].Format("%s", lbl[r]);

		r = fin.m_political_support;
		Stats[1].Format("%s", lbl[r]);

		r = fin.m_interest;
		Stats[2].Format("%s", lbl[r]);

		r = fin.m_competition;
		Stats[3].Format("%s", lbl[r]);

		r = fin.m_economy;
		Stats[4].Format("%s", lbl[r]);

		r = fin.m_cost_of_living;
		Stats[5].Format("%s", lbl[r]);

		r = fin.m_population;
		Stats[6].Format("%s", lbl[r]);

	CTeamFinancial fin_l = m_finance[200];


	g = (double)fin_l.m_home_games;
		if(g == 0) g = 1;


		CString Stats_l[33];
		


		r = fin_l.m_fan_support;
		Stats_l[0].Format("%s", lbl[r]);

		r = fin_l.m_political_support;
		Stats_l[1].Format("%s", lbl[r]);

		r = fin_l.m_interest;
		Stats_l[2].Format("%s", lbl[r]);

		r = fin_l.m_competition;
		Stats_l[3].Format("%s", lbl[r]);

		r = fin_l.m_economy;
		Stats_l[4].Format("%s", lbl[r]);

		r = fin_l.m_cost_of_living;
		Stats_l[5].Format("%s", lbl[r]);

		r = fin_l.m_population;
		Stats_l[6].Format("%s", lbl[r]);



	for(int  index = 0; index < 19; index++)
	{
		if(Stats[index] == "") continue;
		m_list_city.InsertItem(index, m_label[4][index]);
		m_list_city.SetItemText(index, 1, Stats[index]);
		m_list_city.SetItemText(index, 2, Stats_l[index]);
	}
	//	m_list_city.InsertItem(co,Stats[0]);
	//	for(int s=0; s<=20; s++)
	//	{	
	//		m_list_city.SetItemText(co,s+1,Stats[s+1]);
	//	}

}


void CCityProfileDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
