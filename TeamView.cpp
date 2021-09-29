// TeamView.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
#include "MyComboBox.h"
#include "TeamView.h"
#include "BBallDoc.h"
#include "BudgetSheetDlg.h"
#include "FreeAgentDlg.h"
#include "FranchiseChangeDlg.h"
#include "CampDlg.h"
#include "AwardsDlg.h"
#include "Awards.h"
#include "HistoryStats.h"
#include "HistoryDraftDlg.h"
#include "HistoryAwardsDlg.h"
#include "HistoryTeamDlg.h"
#include "AllTimeDlg.h"
#include "HofDlg.h"
#include "ReportDlg.h"
#include "PbpDlg.h"
#include "BoxDlg.h"
#include "CreateDlg.h"
#include "TransactionsDlg.h"
#include "TradeDlg.h"
#include "TradeBlockDlg.h"
#include "FranchiseEdit.h"
#include "HtmlDlg.h"
#include "ImportDlg.h"
#include "PlayerCardDlg.h"
#include "DataSort.h"


//#include "Disk.h"
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 




#ifndef Computer_h
#include "Computer.h"
#define Computer_h
#endif 

//#ifndef xShadeButton_h
//#include "xShadeButton.h"
//#deavg.m_finance[scout]e xShadeButton_h
//#endif 

#include "StaffDlg.h"
#include "RookieDlg.h"
#include "LeagueTeamSchedule.h"
//#include "Playoff.h"
#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTeamView

IMPLEMENT_DYNCREATE(CTeamView, CFormView)

CTeamView::CTeamView()
	: CFormView(CTeamView::IDD)
{
	//{{AFX_DATA_INIT(CTeamView)
	//}}AFX_DATA_INIT
//	pDoc->m_page = 0;

	//m_bmp = new CBitmap;
	//m_bmp->LoadBitmap(IDB_BITMAPSCREEN);
	//m_bmp->SetBitmapDimension(182,240); /* if the size of bitmap is 50 by 40 */
	//m_bmp->SetBitmapDimension(1680, 1050); /* if the size of bitmap is 50 by 40 */

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */



	myBrush.CreateStockObject(HOLLOW_BRUSH);


	//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
	  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));
}

CTeamView::~CTeamView()
{
	delete m_bmp;
}

void CTeamView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeamView)
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_button_next);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_button_back);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_RECORDS, m_button_records);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_BUDGET_SHEET, m_button_budget_sheet);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_TRADE, m_button_trade);
	DDX_Control(pDX, IDC_BUTTON_TRANSACTIONS, m_button_transaction);
	DDX_Control(pDX, IDC_BUTTON_DEPTH_CHARTS, m_button_depth);
	DDX_Control(pDX, IDC_BUTTON_HISTORY_TEAM_RESULTS, m_button_history_team);
	DDX_Control(pDX, IDC_BUTTON_FA, m_button_fa);
	DDX_Control(pDX, IDC_BUTTON_STAFFS, m_button_staffs);
	DDX_Control(pDX, IDC_BUTTON_ROOKIES, m_button_rookies);
	DDX_Control(pDX, IDC_BUTTON_TEAM_SCHEDULE, m_button_team_schedule);
	DDX_Control(pDX, IDC_BUTTON_VIEW_ROSTER, m_button_view_roster);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_BUTTON1, m_buttons[1]);
	DDX_Control(pDX, IDC_BUTTON9, m_buttons[9]);
	DDX_Control(pDX, IDC_BUTTON8, m_buttons[8]);
	DDX_Control(pDX, IDC_BUTTON7, m_buttons[7]);
	DDX_Control(pDX, IDC_BUTTON6, m_buttons[6]);
	DDX_Control(pDX, IDC_BUTTON5, m_buttons[5]);
	DDX_Control(pDX, IDC_BUTTON4, m_buttons[4]);
	DDX_Control(pDX, IDC_BUTTON32, m_buttons[32]);
	DDX_Control(pDX, IDC_BUTTON31, m_buttons[31]);
	DDX_Control(pDX, IDC_BUTTON30, m_buttons[30]);
	DDX_Control(pDX, IDC_BUTTON3, m_buttons[3]);
	DDX_Control(pDX, IDC_BUTTON29, m_buttons[29]);
	DDX_Control(pDX, IDC_BUTTON28, m_buttons[28]);
	DDX_Control(pDX, IDC_BUTTON27, m_buttons[27]);
	DDX_Control(pDX, IDC_BUTTON26, m_buttons[26]);
	DDX_Control(pDX, IDC_BUTTON25, m_buttons[25]);
	DDX_Control(pDX, IDC_BUTTON24, m_buttons[24]);
	DDX_Control(pDX, IDC_BUTTON23, m_buttons[23]);
	DDX_Control(pDX, IDC_BUTTON22, m_buttons[22]);
	DDX_Control(pDX, IDC_BUTTON21, m_buttons[21]);
	DDX_Control(pDX, IDC_BUTTON20, m_buttons[20]);
	DDX_Control(pDX, IDC_BUTTON2, m_buttons[2]);
	DDX_Control(pDX, IDC_BUTTON19, m_buttons[19]);
	DDX_Control(pDX, IDC_BUTTON18, m_buttons[18]);
	DDX_Control(pDX, IDC_BUTTON17, m_buttons[17]);
	DDX_Control(pDX, IDC_BUTTON16, m_buttons[16]);
	DDX_Control(pDX, IDC_BUTTON15, m_buttons[15]);
	DDX_Control(pDX, IDC_BUTTON14, m_buttons[14]);
	DDX_Control(pDX, IDC_BUTTON13, m_buttons[13]);
	DDX_Control(pDX, IDC_BUTTON12, m_buttons[12]);
	DDX_Control(pDX, IDC_BUTTON11, m_buttons[11]);
	DDX_Control(pDX, IDC_BUTTON10, m_buttons[10]);


}


BEGIN_MESSAGE_MAP(CTeamView, CFormView)
	//{{AFX_MSG_MAP(CTeamView)
	ON_WM_ERASEBKGND()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_ROSTER, OnButtonViewRoster)
	ON_BN_CLICKED(IDC_BUTTON_TEAM_SCHEDULE, OnButtonTeamSchedule)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY_TEAM_RESULTS, OnButtonHistoryTeamResults)
	ON_BN_CLICKED(IDC_BUTTON_DEPTH_CHARTS, OnButtonDepthCharts)
	ON_BN_CLICKED(IDC_BUTTON_TRANSACTIONS, OnButtonTransactions)
	ON_BN_CLICKED(IDC_BUTTON_TRADE, OnButtonTrade)
	ON_BN_CLICKED(IDC_BUTTON_RECORDS, OnButtonRecords)
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_ROOKIES, OnButtonRookies)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON_FA, OnButtonFa)
	ON_BN_CLICKED(IDC_BUTTON_STAFFS, OnButtonStaffs)
	ON_BN_CLICKED(IDC_BUTTON_BUDGET_SHEET, OnButtonBudgetSheet)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON21, OnButton21)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_TEAM_BUDGET, OnTeamBudget)
	ON_COMMAND(ID_TEAM_DRAFTPREVIEW, OnTeamDraftpreview)
	ON_COMMAND(ID_TEAM_FREEAGENTS, OnTeamFreeagents)
	ON_COMMAND(ID_TEAM_HISTORY, OnTeamHistory)
	ON_COMMAND(ID_TEAM_LINEUP, OnTeamLineup)
	ON_COMMAND(ID_TEAM_RECORDS, OnTeamRecords)
	ON_COMMAND(ID_TEAM_RESULTS, OnTeamResults)
	ON_COMMAND(ID_TEAM_ROSTER, OnTeamRoster)
	ON_COMMAND(ID_TEAM_STAFF, OnTeamStaff)
	ON_COMMAND(ID_TEAM_TRADE, OnTeamTrade)
	ON_COMMAND(ID_TEAM_TRANSACTIONS, OnTeamTransactions)
	ON_COMMAND(ID_EDIT_PLAYERS, OnEditPlayers)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeamView diagnostics

#ifdef _DEBUG
void CTeamView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeamView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeamView message handlers

void CTeamView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	//m_buttons[1].m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	int i = 0;
	for (i = 0; i <= 32; i++)
	{
		if (i < 32)
		{
			m_buttons[i].m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
			m_buttons[i].m_nAlignStyle = CMFCButton::ALIGN_LEFT;
		}
		m_buttons[i].m_bTransparent = TRUE;

		//	m_buttons[i].SetTextColor(RGB(0,0,0));
		//	m_buttons[i].SetImage(IDB_BUTTON, IDB_BUTTON, FALSE);
	}
	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();

	//	myBrush.CreateSolidBrush(DLGCOLOR); 
		//myBrush.CreateSysColorBrush(HS_CROSS); 

		//COLORREF	crBtnColor;

		// Calculate a color effect for hilighting the button
		//crBtnColor = ::GetSysColor(COLOR_BTNFACE) + RGB(30, 30, 30);


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 26;
	strcpy_s(lf.lfFaceName, USERFONT);
	//	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font1.CreateFontIndirect(&lf);    // Create the font.

	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 12;
	lf.lfUnderline = TRUE;
	strcpy_s(lf.lfFaceName, USERFONT);
	//	strcpy_s(lf.lfFaceName, "Courier New");    //    with face name "Arial".
	m_font2.CreateFontIndirect(&lf);    // Create the font.




//	m_button_history.SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);






	// Resize parent to fit dialog template exactly    
	// while not resizing beyond size of screen
	VERIFY(pFrame = GetParentFrame());
	pFrame->GetClientRect(rectFrame);
	GetClientRect(rectView);
	//    if ( rectFrame.Width() < rectView.Width()
	  //       || rectFrame.Height() < rectView.Height() )
		//{        
			// Resize so can be refit to any template that fits the screen
	//        pFrame->MoveWindow( 0, 0, GetSystemMetrics(SM_CXSCREEN), 
	//                        GetSystemMetrics(SM_CYSCREEN), FALSE ); 

	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	if (w > WIDTH) w = WIDTH;
	if (h > HEIGHT) h = HEIGHT;
	pFrame->SetWindowPos(NULL, 0, 0, w, h, SWP_NOSIZE);
	pFrame->RecalcLayout();
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();

	//if(w > 1023) w = 1023;
	//if(h > 750) h = 750;
//        pFrame->MoveWindow( 0, 0, w, h, FALSE ); 

	//pFrame->SetWindowPos(NULL, 0, 0, w, h, FALSE);


	//}
	//pFrame->RecalcLayout();
	////ResizeParentToFit(TRUE);    // Shrink to fit template 



}

void CTeamView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	m_backnextindex = pDoc->m_combo_team_index;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

	if (pDoc->m_page == 8) OnButtonRookies();
	else if (pDoc->m_page == 9) OnButtonFa();
	else if (pDoc->m_page == 10) OnButtonStaffs();
	else if (pDoc->m_page == 11) OnButtonBudgetSheet();
	else if (pDoc->m_page == 5) OnButtonDepthCharts();
	else if (pDoc->m_page == 7) OnButtonRecords();
	else if (pDoc->m_page == 6) OnButtonHistoryTeamResults();
	else if (pDoc->m_page == 4) OnButtonTrade();
	else if (pDoc->m_page == 3) OnButtonTransactions();
	else if (pDoc->m_page == 2) OnButtonTeamSchedule();
	else if (pDoc->m_page <= 1) OnButtonViewRoster();




}

void CTeamView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	if (bShow == TRUE)
	{
		InitView();
	}




	FillButtons();
}

void CTeamView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(0);

}

void CTeamView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(1);

}

void CTeamView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(4);
}

void CTeamView::OnButtonViewRoster()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 1;

	//	int scout = pDoc->m_combo_team_index-1;
	//	int te = pDoc->m_combo_team_index-1;
	int scout = m_backnextindex - 1;
	int te = m_backnextindex - 1;
	if (scout < 0) scout = 0;//yuk


	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Stats / Attributes / Contracts";
	m_button_id[i] = 0;

	if (te >= 0) m_button_text[29] = pDoc->avg.m_finance[te].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[te] + " " + "Roster (Click Name for Player Card)";


	int pl = scout * 30;
	int co = 1;
	for (int i = 1; i <= 15; i++)
	{
		CPlayer m_player = pDoc->avg.m_actual[pl + i];

		if (co == 13 || te < 0) continue;
		if (m_player.m_active > 0 && m_player.m_name != "")
		{

			m_player.SetSeasonAverages();
			CString str;
			str.Format("%.2f pts, %.2f reb, %.2f ast", m_player.m_sim_pointsPerGame, m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame, m_player.m_sim_assistsPerGame);
			m_button_text[co] = m_player.m_pos + " " + m_player.m_name;
			m_button_id[co] = pl + i;
			m_button_text[co + 12] = str;
			co = co + 1;
		}
	}

	FillButtons();


}

BOOL CTeamView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;

}

void CTeamView::OnButtonTeamSchedule()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	//	int scout = pDoc->m_combo_team_index;
	//	int te = pDoc->m_combo_team_index - 1;

	//	int scout = pDoc->m_combo_team_index;
	//	int te = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex;
	int te = m_backnextindex - 1;


	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	CString list[33];
	data->GetScheduleStrings(list);

	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Complete Team Schedules";
	m_button_id[i] = 0;

	if (te >= 0) m_button_text[29] = pDoc->avg.m_finance[te].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[te] + " " + " Recent Schedule";


	for (int i = 1; i <= 8; i++)
	{
		if (te >= 0) m_button_text[i] = list[i];
	}


	delete data;

	FillButtons();
}




void CTeamView::OnButtonHistoryTeamResults()
{
	// TODO: Add your control notification handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	//	int scout = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex - 1;
	//	int te = m_backnextindex-1;


	int te = scout;
	if (scout < 0) scout = 0;//yuk

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;


	CString file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".his";
	if (pDoc->avg.FileExists(file_name) == true) data->FillTeamHistoryStrings();

	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Team Yearly Results";
	m_button_id[i] = 0;


	if (te >= 0)
		m_button_text[29] = pDoc->avg.m_finance[te].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[te] + " " + " History";

	for (int i = 1; i <= 7; i++)
	{
		if (te < 0) continue;
		int ind = i;
		if (i > 3) ind = i + 9;
		m_button_text[ind] = data->m_history_strings[i];
	}


	delete data;

	FillButtons();


}



void CTeamView::OnButtonDepthCharts()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	//	int scout = pDoc->m_combo_team_index - 1;
	//	int tm = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex - 1;
	int tm = m_backnextindex - 1;


	if (scout < 0) scout = 0;//yuk

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	data->GetStarters(scout);


	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Change Game Plan";
	m_button_id[i] = 0;


	if (tm >= 0)
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " " + " Starting Lineup (Click Name for Player Card)";


	CString pos[] = { "", "PG ", "SG ", "SF ", "PF ", " C " };
	for (int i = 1; i <= 5; i++)
	{
		if (tm < 0) continue;
		CPlayer m_player = pDoc->avg.m_actual[data->m_starters[i]];
		m_player.SetSeasonAverages();

		m_button_text[i] = pos[i] + m_player.m_name;
		m_button_id[i] = data->m_starters[i];
		CString str;
		str.Format("%.2f pts, %.2f reb, %.2f ast", m_player.m_sim_pointsPerGame, m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame, m_player.m_sim_assistsPerGame);
		m_button_text[i + 12] = str;

	}

	FillButtons();

	delete data;

}

void CTeamView::OnButtonTransactions()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	//int scout = pDoc->m_combo_team_index;
	//int tm = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex;
	int tm = m_backnextindex - 1;

	if (scout < 0) scout = 0;//yuk

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	CTransactions trans[256];
	CString string[65];
	int id_list[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int ids_of_roster[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 1; i <= 30; i++)
	{
		if (scout > 0) ids_of_roster[i] = pDoc->avg.m_actual[(scout - 1) * 30 + i].m_id;
	}


	data->GetTransactions(string, 1, trans, id_list, ids_of_roster);

	delete data;

	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Complete Transactions";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " " + " Injuries (Click Name for Player Card)";
		m_button_text[30] = "Status";
	}


	for (int i = 1; i <= 24; i++)
	{
		if (tm < 0) continue;
		m_button_text[i] = string[i];
		m_button_id[i] = id_list[i];
	}


	FillButtons();
}


void CTeamView::OnButtonTrade()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	pDoc->m_page = 4;
	//	int scout = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex - 1;
	//	int te = m_backnextindex-1;


	int tm = scout;
	if (scout < 0) scout = 0;//yuk

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	int strong[] = { 0,0,0,0,0,0 };
	data->TeamStrengths(strong);

	delete data;

	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Trade / Release / Sign";
	m_button_id[i] = 0;


	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Stengths";
		m_button_text[30] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Needs";
		m_button_text[25] = "Trading Block";
	}


	CString pos[] = { "", "point guard","shooting guard","small forward", "power forward", "center" };
	int s = 1, w = 13;
	for (int i = 1; i <= 5; i++)
	{
		if (tm < 0) continue;
		if (strong[i] == 1)
		{
			m_button_text[s] = pos[i];
			s = s + 1;
		}
		else if (strong[i] == -1)
		{
			m_button_text[w] = pos[i];
			w = w + 1;
		}
	}

	FillButtons();



}


void CTeamView::OnButtonRecords()
{
	// TODO: Add your control notification handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	//	int team = pDoc->m_combo_team_index;

	//	int scout = m_backnextindex-1;
	int team = m_backnextindex;


	int tm = team - 1;

	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "View Record Book";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Season Highs";
		m_button_text[30] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Career Highs";
	}
	else
	{
		m_button_text[29] = "League Season Highs";
		m_button_text[30] = "League Career Highs";
	}

	int co = 1;
	CString label[] = { "pts", "reb", "ast", "stl", "blk", "fgm", "tgm", "ftm" };
	for (int t = 0; t <= 1; t++)
	{
		for (int s = 0; s <= 7; s++)
		{
			CString name = pDoc->m_recordbook.m_g_name[t][team][0][s];
			if (name == "") continue;
			int amt = pDoc->m_recordbook.m_g_amt[t][team][0][s];
			int id = pDoc->m_recordbook.m_g_id[t][team][0][s];
			m_button_text[co].Format("%s %d", name, amt);
			m_button_text[co] = m_button_text[co] + " " + label[s];
			m_button_id[co] = 0;
			co = co + 1;
		}
		co = 13;
	}


	FillButtons();





}


void CTeamView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CTeamView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CTeamView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

/*void CTeamView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
		CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//pDoc->avg.m_settings.m_loadbmp = true;

	if(pDoc->avg.m_settings.m_loadbmp == false)
	{
		CRect rc;
		GetWindowRect(&rc);
		ScreenToClient(&rc);
		CBrush brush(SCREENCOLOR);
		pDC->FillRect(rc, &brush);
		pDC->SelectStockObject(ANSI_VAR_FONT);
		pDC->DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);
	}
	else if(pDoc->avg.m_settings.m_loadbmp == true)
	{
	bitmapBkgnd.Detach();
	bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");
CRect rect;
   GetClientRect(&rect);
   CDC dc;
   dc.CreateCompatibleDC(pDC);
   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

	BITMAP bm;
	bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
	iBitmapWidth = bm.bmWidth;
	iBitmapHeight = bm.bmHeight;

   // If our bitmap is smaller than the background and tiling is
   // supported, tile it. Otherwise watch the efficiency - don't
   // spend time setting up loops you won't need.

   if (iBitmapWidth  >= rect.Width() &&
	   iBitmapHeight >= rect.Height() )
   {
	  pDC->BitBlt (rect.left,
				   rect.top,
				   rect.Width(),
				   rect.Height(),
				   &dc,
				   0, 0, SRCCOPY);
   }
   else
   {
	  for (iyOrg = 0; iyOrg < rect.Height(); iyOrg += iBitmapHeight)
	  {
		 for (ixOrg = 0; ixOrg < rect.Width(); ixOrg += iBitmapWidth)
		 {
			pDC->BitBlt (ixOrg,
						 iyOrg,
						 rect.Width(),
						 rect.Height(),
						 &dc,
						 0, 0, SRCCOPY);
		 }
	  }
   }

   dc.SelectObject(pOldBitmap);




	}


}
*/


void CTeamView::OnButtonRookies()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	//	int scout = pDoc->m_combo_team_index - 1;
	//	int tm = pDoc->m_combo_team_index - 1;
	int scout = m_backnextindex - 1;
	int tm = m_backnextindex - 1;


	if (scout < 0) scout = 0;//yuk

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	data->SortRookies();

	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "Rookie Draft Preview";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Draft Board";
	}



	int index = 0;
	for (int i = 1; i <= 12; i++)
	{
		if (data->avg.m_actual[i].m_name != "" && tm >= 0)
		{
			index = index + 1;
			m_button_text[index] = data->avg.m_actual[i - 1].m_pos +
				" " + data->avg.m_actual[i - 1].m_name;
		}
	}


	delete data;

	FillButtons();

}


void CTeamView::FillButtons()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	for (int i = 1; i <= 32; i++)
	{
		//		m_button_text[i].MakeUpper();
		//		m_buttons[i].Repaint(TRUE);



		m_buttons[i].SetWindowText(m_button_text[i]);
		if (m_button_text[i] == "") m_buttons[i].ShowWindow(FALSE);
		else m_buttons[i].ShowWindow(TRUE);

		//if(i < 32) m_buttons[i].DrawBorder(false);
		//m_buttons[i].SetDefaultColors(TRUE);
	}

	if (pDoc->avg.m_settings.m_scouts[32] == 1 && pDoc->avg.m_settings.m_coaches[32] == 1)
		m_button_staffs.EnableWindow(FALSE);
	else
		m_button_staffs.EnableWindow(TRUE);

	if (pDoc->avg.m_settings.m_financial_on == 1)
		m_button_budget_sheet.EnableWindow(TRUE);
	else
		m_button_budget_sheet.EnableWindow(FALSE);


	if (pDoc->avg.m_settings.m_free_agency_on == 1)
		m_button_fa.EnableWindow(TRUE);
	else
		m_button_fa.EnableWindow(FALSE);

}

void CTeamView::OnButton32()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_page == 8) OpenRookieDlg();
	else if (pDoc->m_page == 9) OpenFreeAgentDlg();
	else if (pDoc->m_page == 10) OpenStaff();
	else if (pDoc->m_page == 11) OpenBudget();
	else if (pDoc->m_page == 5) OpenDepthChart();
	else if (pDoc->m_page == 7) OpenRecords();
	else if (pDoc->m_page == 6) OpenTeamHistory();
	else if (pDoc->m_page == 4) OpenTradeDlg();
	else if (pDoc->m_page == 3) OpenTransactionsDlg();
	else if (pDoc->m_page == 2) OpenTeamScheduleDlg();
	else if (pDoc->m_page == 1) ViewTeamRosters();

}

void CTeamView::OpenRookieDlg()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CString po_format = pDoc->avg.m_settings.m_playoffFormat;
	CPlayoff* playoff = new CPlayoff;

	if (po_format != "")
	{

		for (int i = 0; i <= 31; i++)
		{
			playoff->record[i] = pDoc->avg.m_standings[i];
		}




		int teamsPer = 1;
		bool conferencePlayoff = playoff->ConferencePlayoff(teamsPer, po_format);
		playoff->SortStandings(pDoc->avg.m_settings.m_divisionName1);
		playoff->SortStandings(pDoc->avg.m_settings.m_divisionName2);
		playoff->SortStandings(pDoc->avg.m_settings.m_divisionName3);
		playoff->SortStandings(pDoc->avg.m_settings.m_divisionName4);

		playoff->SetDivisionChamps(pDoc->avg.m_settings.m_divisionName1, pDoc->avg.m_settings.m_divisionName2,
			pDoc->avg.m_settings.m_divisionName3, pDoc->avg.m_settings.m_divisionName4);

		if (conferencePlayoff == true)
		{
			playoff->SortStandings(pDoc->avg.m_settings.m_conferenceName1);
			playoff->SortStandings(pDoc->avg.m_settings.m_conferenceName2);
		}

		playoff->SetPlayoffRounds(pDoc->avg.m_settings.m_rd1Format, pDoc->avg.m_settings.m_rd2Format,
			pDoc->avg.m_settings.m_rd3Format, pDoc->avg.m_settings.m_rd4Format);

		playoff->SetAllPlayoffTeams(conferencePlayoff, teamsPer,
			pDoc->avg.m_settings.m_conferenceName1,
			pDoc->avg.m_settings.m_conferenceName2,
			pDoc->avg.m_settings.m_divisionName1,
			pDoc->avg.m_settings.m_divisionName2,
			pDoc->avg.m_settings.m_divisionName3,
			pDoc->avg.m_settings.m_divisionName4);

		for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
		{
			int n = playoff->record[i].m_initialNumber;
			pDoc->avg.m_standings[n] = playoff->record[i];
		}


	}


	delete playoff;


	CRookieDlg* roo;
	roo = new CRookieDlg;
	roo->m_shareware = false;
	roo->avg = pDoc->avg;
	roo->m_currentYear = pDoc->avg.m_settings.m_currentYear;





	for (int i = 0; i <= (pDoc->avg.m_settings.m_numberteams - 1); i++)
	{
		roo->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		roo->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
	}
	roo->m_numberteams = pDoc->avg.m_settings.m_numberteams;
	roo->m_path = pDoc->avg.m_settings.m_path;
	roo->m_leagueName = pDoc->avg.m_settings.m_league_name;

	roo->m_default_team = pDoc->m_combo_team_index;


	int result = roo->DoModal();
	delete roo;
}

void CTeamView::OnButtonFa()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;

	int scout = m_backnextindex - 1;
	//	int te = m_backnextindex-1;


	//	int scout = pDoc->m_combo_team_index - 1;
	int tm = scout;



	if (scout < 0) scout = 0;//doesn't show then so no matter

	CDataSort* data = new CDataSort;
	data->avg = pDoc->avg;
	data->m_scout_team = scout;
	data->SortFA();

	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}

	m_button_text[i] = "Free Agent Preview";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Free Agent Board";
	}


	int index = 0;
	for (int i = 1; i <= 1440; i++)
	{
		if (index == 12 || tm < 0) continue;
		if (data->avg.m_actual[i - 1].m_name != "" && data->avg.m_actual[i - 1].m_current_contract_yr == data->avg.m_actual[i - 1].m_contract_yrs)
		{
			index = index + 1;
			m_button_text[index] = data->avg.m_actual[i - 1].m_pos +
				" " + data->avg.m_actual[i - 1].m_name;
			m_button_id[index] = data->avg.m_actual[i - 1].m_temp_pointer;

			CPlayer m_player = data->avg.m_actual[i - 1];
			m_player.SetSeasonAverages();
			CString str;
			str.Format("%.2f pts, %.2f reb, %.2f ast", m_player.m_sim_pointsPerGame, m_player.m_sim_orbPerGame + m_player.m_sim_reboundsPerGame, m_player.m_sim_assistsPerGame);
			m_button_text[index + 12] = str;
		}
	}

	delete data;

	FillButtons();

}

void CTeamView::OpenFreeAgentDlg()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CFreeAgentDlg* free = new CFreeAgentDlg;

	int cap = (int)pDoc->avg.m_settings.m_cap;
	free->m_cap = cap;
	free->m_default_team = pDoc->m_combo_team_index - 1;
	if (free->m_default_team < 0) free->m_default_team = 0;


	free->m_signing_ok = false;

	free->avg = pDoc->avg;
	int count = 0;
	for (int i = 1; i <= 960; i++)
	{

		int te = pDoc->avg.m_actual[i].m_team_paying;
		if (te > 0) free->avg.m_actual[i].m_team_paying_name = pDoc->avg.m_settings.m_leagueTeamNames[te - 1];

		free->avg.m_actual[i] = pDoc->avg.m_actual[i - 1];
		free->avg.m_actual[i].m_previous_team = (i - 1) / 30;//season in progress so previous team is current team
		free->avg.m_actual[i].m_current_team = (i - 1) / 30;//season in progress so previous team is current team
		if (free->avg.m_actual[i].m_name != "") count = count + 1;
	}

	count = int((double)count / (double)pDoc->avg.m_settings.m_numberteams - 1);
	if (count < 10) count = 10;
	else if (count > 12) count = 15;

	free->m_path = pDoc->avg.m_settings.m_path;
	free->m_league_name = pDoc->avg.m_settings.m_league_name;
	free->m_count = count;


	for (int i = 0; i <= 32; i++)
	{
		free->m_league_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		free->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
	}

	free->m_number_teams = pDoc->avg.m_settings.m_numberteams;
	free->m_check_finances_on = pDoc->avg.m_settings.m_financial_on;



	int result = free->DoModal();

	delete free;
}

void CTeamView::OnButtonStaffs()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	//	int scout = pDoc->m_combo_team_index - 1;
	//	int tm = pDoc->m_combo_team_index - 1;

	int scout = m_backnextindex - 1;
	int tm = m_backnextindex - 1;


	if (scout < 0) scout = 0;//yuk

	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "View Complete Staffs";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Staff (Click for Card)";
	}


	if (tm >= 0)
	{
		m_button_text[1] = "Scout: " + pDoc->avg.m_scout[scout].m_name;
		m_button_text[2] = "Coach: " + pDoc->avg.m_coach[scout].m_name;
		m_button_text[3] = "GM: " + pDoc->avg.m_gm[scout].m_name;

		if (pDoc->avg.m_scout[scout].m_name == "")
		{
			m_button_text[1] = "Scout: N/A";
			//m_button_text[2] = "Coach: N/A";
			m_button_text[3] = "GM: N/A";;
		}
		if (pDoc->avg.m_coach[scout].m_name == "")
		{
			//m_button_text[1] = "Scout: N/A";
			m_button_text[2] = "Coach: N/A";
			//m_button_text[3] = "GM: N/A";;
		}

	}

	FillButtons();
}

void CTeamView::OpenStaff()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	if (pDoc->avg.m_settings.m_scouts[32] == 0 || pDoc->avg.m_settings.m_coaches[32] == 0)//scouts on
	{
		CStaffDlg* staff = new CStaffDlg;
		staff->m_hiring_ok = false;
		staff->m_default_team = pDoc->m_combo_team_index - 1;
		if (staff->m_default_team < 0) staff->m_default_team = 0;
		staff->avg = pDoc->avg;
		int result = staff->DoModal();
		delete staff;
	}
}

void CTeamView::OnButtonBudgetSheet()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	//	int scout = pDoc->m_combo_team_index - 1;
	//	int tm = pDoc->m_combo_team_index - 1;

	int scout = m_backnextindex - 1;
	int tm = m_backnextindex - 1;


	if (scout < 0) scout = 0;//yuk



	int i = 0;
	for (i = 1; i <= 31; i++)
	{
		m_button_text[i] = "";
		m_button_id[i] = 0;
	}
	m_button_text[i] = "View Complete Finances";
	m_button_id[i] = 0;

	if (tm >= 0)
	{
		m_button_text[29] = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm] + " Finance Report";
	}

	CString Stats[33];

	double g = (double)pDoc->avg.m_finance[scout].m_home_games;
	if (g >= 0) g = 1;
	double r = pDoc->avg.m_finance[scout].m_capacity;
	Stats[2].Format("seats: %.f", r);

	r = (pDoc->avg.m_finance[scout].m_season_att + pDoc->avg.m_finance[scout].m_season_suites_sold * 20 + pDoc->avg.m_finance[scout].m_season_clubs_sold) / g;
	Stats[1].Format("attendance: %.f", r);

	int pct = int((pDoc->avg.m_finance[scout].m_season_att + pDoc->avg.m_finance[scout].m_season_suites_sold * 20 + pDoc->avg.m_finance[scout].m_season_clubs_sold) / ((double)pDoc->avg.m_finance[scout].m_capacity * g) * 1000);
	r = (double)pct / 10;
	Stats[3].Format("percent: %.2f", r);




	r = ((double)pDoc->avg.m_finance[scout].m_season_total_revenue - (double)pDoc->avg.m_finance[scout].m_season_total_expenses) / 1000000;
	Stats[0].Format("profit: %.2f", r);

	r = (double)pDoc->avg.m_finance[scout].m_ticket_price / 10;
	Stats[5].Format("ticket: %.2f $", r);

	int i_r = pDoc->avg.m_finance[scout].m_fan_support;
	CString str[] = { "","horrible", "poor", "below", "average", "above", "good", "great" };


	Stats[6] = "fan support: " + str[i_r];

	//i_r = pDoc->avg.m_finance[scout].m_;


	for (int i = 0; i <= 27; i++)
	{
		if (tm >= 0) m_button_text[i + 1] = Stats[i];
	}

	FillButtons();

}

void CTeamView::OpenBudget()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CBudgetSheetDlg* bud = new CBudgetSheetDlg;
	bud->m_ok = false;



	for (int i = 0; i <= 99; i++)
	{
		pDoc->avg.m_finance[i].m_original_slot = i;
		bud->m_finance[i] = pDoc->avg.m_finance[i];
		if (i < pDoc->avg.m_settings.m_numberteams) bud->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
	}

	bud->m_hi_games = pDoc->avg.m_hi_g[0];
	bud->m_path = pDoc->avg.m_settings.m_path;
	bud->m_league_name = pDoc->avg.m_settings.m_league_name;




	for (int i = 0; i <= 99; i++)
	{
		bud->m_finance[100 + i] = pDoc->avg.m_finance[100 + i];
	}


	bud->m_default_team = pDoc->m_combo_team_index - 1;
	if (bud->m_default_team < 0) bud->m_default_team = 0;
	bud->m_number_teams = pDoc->avg.m_settings.m_numberteams;

	int result = bud->DoModal();
	if (result == IDOK)
	{


		for (int i = 0; i <= 200; i++)
		{
			pDoc->avg.m_finance[i] = bud->m_finance[i];
		}
		//		pDoc->avg.m_settings.m_current_stage = 6;

	}
	delete bud;
}

void CTeamView::OpenDepthChart()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
	if (result == IDOK) OnButtonDepthCharts();

}

void CTeamView::OpenRecords()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CAllTimeDlg all;
	for (int i = 0; i <= 31; i++)
	{
		all.m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}

	all.m_leagueName = pDoc->avg.m_settings.m_league_name;
	all.high = pDoc->m_recordbook;
	int tm = pDoc->m_combo_team_index;
	if (tm < 0) tm = 0;
	all.m_default_team = tm;
	all.DoModal();

}

void CTeamView::OpenTeamHistory()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CHistoryTeamDlg team;
	team.m_default_team = pDoc->m_combo_team_index - 1;
	if (team.m_default_team < 0) team.m_default_team = 0;

	for (int i = 0; i <= 32; i++)
	{
		team.m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	team.m_path = pDoc->avg.m_settings.m_path;
	team.m_leagueName = pDoc->avg.m_settings.m_league_name;
	team.DoModal();
}

void CTeamView::OpenTradeDlg()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();
	if (result == IDOK)
	{
		OnButtonTrade();
	}
}

void CTeamView::OpenTransactionsDlg()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CTransactionsDlg trans;
	//trans.m_league = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".tra";
	trans.avg = pDoc->avg;
	trans.m_default_team = pDoc->m_combo_team_index - 1;
	trans.m_path = pDoc->avg.m_settings.m_path;
	trans.m_league_name = pDoc->avg.m_settings.m_league_name;


	for (int i = 0; i <= 32; i++)
	{
		trans.m_league_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	trans.DoModal();
}

void CTeamView::OpenTeamScheduleDlg()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CLeagueTeamSchedule* sch = new CLeagueTeamSchedule;
	sch->avg = pDoc->avg;
	sch->m_default_team = pDoc->m_combo_team_index - 1;
	if (sch->m_default_team < 0) sch->m_default_team = 0;
	sch->DoModal();
	delete sch;
}

void CTeamView::ViewTeamRosters()
{
	((CBBallApp*)AfxGetApp())->SwitchView(2);
}

void CTeamView::OnButton1()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[1], 1);

}
void CTeamView::OnButton2()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[2], 2);

}
void CTeamView::OnButton3()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[3], 3);

}
void CTeamView::OnButton4()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[4], 4);

}
void CTeamView::OnButton5()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[5], 5);

}
void CTeamView::OnButton6()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[6], 6);

}
void CTeamView::OnButton7()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[7], 7);

}
void CTeamView::OnButton8()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[8], 8);

}
void CTeamView::OnButton9()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[9], 9);

}
void CTeamView::OnButton10()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[10], 10);

}
void CTeamView::OnButton11()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[11], 11);

}
void CTeamView::OnButton12()
{
	// TODO: Add your control notification handler code here
	DisplayPlayerCard(m_button_id[12], 12);

}
void CTeamView::OnButton13()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton14()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton15()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton16()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton17()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton18()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton19()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton20()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton21()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton22()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton23()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton24()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton25()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	CTradeBlockDlg* trade = new CTradeBlockDlg;


	trade->avg = pDoc->avg;
	trade->m_default_team = pDoc->m_combo_team_index - 1;
	int result = trade->DoModal();
	pDoc->avg = trade->avg;
	delete trade;


}

void CTeamView::OnButton26()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton27()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton28()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton29()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton30()
{
	// TODO: Add your control notification handler code here

}
void CTeamView::OnButton31()
{
	// TODO: Add your control notification handler code here

}


void CTeamView::DisplayPlayerCard(int id, int pointer)
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	if (pDoc->m_page == 10)
	{
		int j = m_backnextindex - 1;

		CScoutProfileDlg scout;

		if (pointer == 1)
		{
			scout.m_type = 1;
			scout.m_scout = pDoc->avg.m_scout[j];
		}
		else if (pointer == 2)
		{
			scout.m_scout = pDoc->avg.m_coach[j];
			scout.m_type = 2;
		}
		else if (pointer == 3)
		{
			scout.m_type = 3;
			scout.m_scout = pDoc->avg.m_gm[j];
		}

		scout.DoModal();

	}

	else
	{


		CPlayer m_player = pDoc->avg.m_actual[id];
		if (m_player.m_name != "")
		{

			//CPlayer *temp = new CPlayer[31];



			CPlayerCardDlg* scout = new CPlayerCardDlg;
			int tm = m_player.m_current_team;
			CString team = "";

			if (tm >= 0)
				team = pDoc->avg.m_finance[tm].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[tm];
			CString string = m_player.GetPos() + " " + m_player.GetName() + " - " + team;

			scout->m_path = pDoc->avg.m_settings.m_path;
			scout->m_leagueName = pDoc->avg.m_settings.m_league_name;
			scout->m_player_index = pointer;
			scout->m_title = "Scout";
			scout->m_default_scout = pDoc->m_combo_team_index;
			scout->m_data_slot = id;


			scout->avg = pDoc->avg;
			for (int i = 1; i <= 30; i++)
			{
				scout->avg.m_actual[i] = pDoc->avg.m_actual[m_button_id[i]];
				scout->avg.m_actual[i].m_player_pointer = m_button_id[i];
			}
			scout->m_pl_index_end = 30;
			if (tm >= 0)
			{
				if (pDoc->avg.m_settings.m_player_gm[tm] == "Player" && pDoc->avg.m_settings.m_current_stage == 0)
					scout->m_extension_allowed = true;
			}
			scout->DoModal();
			for (int i = 1; i <= 30; i++)
			{
				pDoc->avg.m_actual[m_button_id[i]] = scout->avg.m_actual[i];
			}
			for (int i = 0; i <= 31; i++)
			{
				pDoc->avg.m_owner[i] = scout->avg.m_owner[i];
			}

			pDoc->avg.m_sched = scout->avg.m_sched;
			pDoc->avg.m_settings = scout->avg.m_settings;

			for (int i = 0; i <= 2000; i++)
			{
				pDoc->avg.m_trans_str[i] = scout->avg.m_trans_str[i];
			}


			delete scout;

		}

	}

}

void CTeamView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	ViewTeamRosters();
}

void CTeamView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	pDoc->Options();

}

void CTeamView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CTeamView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CTeamView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	OnSelchangeComboTeams();

}

void CTeamView::OnButtonBack()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	int co = m_combo_teams.GetCount();
	m_backnextindex = m_backnextindex - 1;
	if (m_backnextindex < 0) m_backnextindex = co - 1;

	((CBBallApp*)AfxGetApp())->SwitchView(3);

	if (pDoc->m_page == 8) OnButtonRookies();
	else if (pDoc->m_page == 9) OnButtonFa();
	else if (pDoc->m_page == 10) OnButtonStaffs();
	else if (pDoc->m_page == 11) OnButtonBudgetSheet();
	else if (pDoc->m_page == 5) OnButtonDepthCharts();
	else if (pDoc->m_page == 7) OnButtonRecords();
	else if (pDoc->m_page == 6) OnButtonHistoryTeamResults();
	else if (pDoc->m_page == 4) OnButtonTrade();
	else if (pDoc->m_page == 3) OnButtonTransactions();
	else if (pDoc->m_page == 2) OnButtonTeamSchedule();
	else if (pDoc->m_page == 1) OnButtonViewRoster();


}

void CTeamView::OnButtonNext()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	int co = m_combo_teams.GetCount();
	m_backnextindex = m_backnextindex + 1;
	if (m_backnextindex >= co) m_backnextindex = 0;

	((CBBallApp*)AfxGetApp())->SwitchView(3);

	if (pDoc->m_page == 8) OnButtonRookies();
	else if (pDoc->m_page == 9) OnButtonFa();
	else if (pDoc->m_page == 10) OnButtonStaffs();
	else if (pDoc->m_page == 11) OnButtonBudgetSheet();
	else if (pDoc->m_page == 5) OnButtonDepthCharts();
	else if (pDoc->m_page == 7) OnButtonRecords();
	else if (pDoc->m_page == 6) OnButtonHistoryTeamResults();
	else if (pDoc->m_page == 4) OnButtonTrade();
	else if (pDoc->m_page == 3) OnButtonTransactions();
	else if (pDoc->m_page == 2) OnButtonTeamSchedule();
	else if (pDoc->m_page == 1) OnButtonViewRoster();


}

void CTeamView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class
	InitView();

}

void CTeamView::InitView()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();




	//m_button_tools.SetFont(&m_font1);




	m_combo_teams.ResetContent();

	m_combo_teams.AddString("All Teams");

	for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
	{
		CString team_name = pDoc->avg.m_settings.m_leagueTeamNames[i];
		if (team_name != "")
			//m_combo_teams.AddString(team_name);
			m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
	}

	m_combo_teams.SetCurSel(pDoc->m_combo_team_index);

	m_backnextindex = pDoc->m_combo_team_index;









	if (pDoc->m_page == 8) OnButtonRookies();
	else if (pDoc->m_page == 9) OnButtonFa();
	else if (pDoc->m_page == 10) OnButtonStaffs();
	else if (pDoc->m_page == 11) OnButtonBudgetSheet();
	else if (pDoc->m_page == 5) OnButtonDepthCharts();
	else if (pDoc->m_page == 7) OnButtonRecords();
	else if (pDoc->m_page == 6) OnButtonHistoryTeamResults();
	else if (pDoc->m_page == 4) OnButtonTrade();
	else if (pDoc->m_page == 3) OnButtonTransactions();
	else if (pDoc->m_page == 2) OnButtonTeamSchedule();
	else if (pDoc->m_page == 1 || pDoc->m_page == 0) OnButtonViewRoster();
}

BOOL CTeamView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/teamroster.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

	return CFormView::OnHelpInfo(pHelpInfo);
}

void CTeamView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/teamroster.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

}





void CTeamView::OnTeamRoster()
{
	// TODO: Add your command handler code here
	/*if(pDoc->m_page == 8) OpenRookieDlg();
	else if(pDoc->m_page == 9) OpenFreeAgentDlg();
	else if(pDoc->m_page == 10) OpenStaff();
	else if(pDoc->m_page == 11) OpenBudget();
	else if(pDoc->m_page == 5) OpenDepthChart();
	else if(pDoc->m_page == 7) OpenRecords();
	else if(pDoc->m_page == 6) OpenTeamHistory();
	else if(pDoc->m_page == 4) OpenTradeDlg();
	else if(pDoc->m_page == 3) OpenTransactionsDlg();
	else if(pDoc->m_page == 2) OpenTeamScheduleDlg();
	else if(pDoc->m_page == 1) ViewTeamRosters();*/
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 1;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
}

void CTeamView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	InitView();
	//	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	

}

void CTeamView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CTeamView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CTeamView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}


BOOL CTeamView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	/*
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	if(pDoc->avg.m_settings.m_loadbmp == false)
//	{
//		CRect rc;
//		GetWindowRect(&rc);
//		ScreenToClient(&rc);
//		CBrush brush(SCREENCOLOR);
//		pDC->FillRect(rc, &brush);
//		pDC->SelectStockObject(ANSI_VAR_FONT);
//		pDC->DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);
//	}
//	else if(pDoc->avg.m_settings.m_loadbmp == true)
//	{

//bitmapBkgnd.Detach();
//	bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");

	CRect rect;
   GetClientRect(&rect);
   CDC dc;
   dc.CreateCompatibleDC(pDC);
   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

   BITMAP bm;
   bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
   iBitmapWidth = bm.bmWidth;
   iBitmapHeight = bm.bmHeight;

   // If our bitmap is smaller than the background and tiling is
   // supported, tile it. Otherwise watch the efficiency - don't
   // spend time setting up loops you won't need.

   if (iBitmapWidth  >= rect.Width() &&
	   iBitmapHeight >= rect.Height() )
   {
	  pDC->BitBlt (rect.left,
				   rect.top,
				   rect.Width(),
				   rect.Height(),
				   &dc,
				   0, 0, SRCCOPY);
   }
   else
   {
	  for (iyOrg = 0; iyOrg < rect.Height(); iyOrg += iBitmapHeight)
	  {
		 for (ixOrg = 0; ixOrg < rect.Width(); ixOrg += iBitmapWidth)
		 {
			pDC->BitBlt (ixOrg,
						 iyOrg,
						 rect.Width(),
						 rect.Height(),
						 &dc,
						 0, 0, SRCCOPY);
		 }
	  }
   }

   dc.SelectObject(pOldBitmap);

//	}
*/
//   return 0;


//		return CView::OnEraseBkgnd(pDC);


	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memdc.SelectObject(m_bmp);
	CRect rc;
	GetClientRect(&rc);

	const CSize sz = m_bmp->GetBitmapDimension();
	for (int y = 0; y <= rc.Height(); y += sz.cy)
	{
		for (int x = 0; x <= rc.Width(); x += sz.cx)
		{
			pDC->BitBlt(x, y, sz.cx, sz.cy, &memdc, 0, 0, SRCCOPY);
		}
	}

	memdc.SelectObject(pOldBitmap);
	return TRUE;





}




HBRUSH CTeamView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{



	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
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
		myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(STATICCOLOR);
		pDC->SetBkColor(logbrush.lbColor);
		return myBrush;



	case CTLCOLOR_BTN:
		pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(myBrush);

	case CTLCOLOR_LISTBOX:
		pDC->SetBkColor(LISTBOXCOLOR);
		pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return myBrush;

	case CTLCOLOR_SCROLLBAR:
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(LISTBOXCOLOR);
		return myBrush;

	case CTLCOLOR_MSGBOX:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return myBrush;

	case CTLCOLOR_DLG:
		return hbr;

		//This shouldn't occurr since we took all the cases, but
		//JUST IN CASE, return the new brush
	default:
		return hbr;
	}



}
