// GameView.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
#include "MyComboBox.h"
#include "GameView.h"
#include "BBallDoc.h"
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
//#include "Disk.h"
#include "stdafx.h"
//#include "BBall.h"
//#include "SimulatedStatsDlg.h"
#include "PlayerCardDlg.h"
#include "AwardsDlg.h"
#include "LeadersDlg.h"
#include "Awards.h"
//#ifndef Player_h
//#include "Player.h"
//#define Player_h
//#endif 




#ifndef MyString_h
#include "MyString.h"
#define MyString_h
#endif 


#include "HtmlMsc.h"

//#include "XListCtrl/XListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameView

IMPLEMENT_DYNCREATE(CGameView, CFormView)

CGameView::CGameView()
	: CFormView(CGameView::IDD)
{
	//{{AFX_DATA_INIT(CGameView)
	//}}AFX_DATA_INIT

//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));
	//m_bmp = new CBitmap;
	//m_bmp->LoadBitmap(IDB_BITMAPSCREEN);
	//m_bmp->SetBitmapDimension(182, 240); /* if the size of bitmap is 50 by 40 */
	//m_bmp->SetBitmapDimension(1680, 1050); /* if the size of bitmap is 50 by 40 */

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */


	m_rookie_view = false;

}

CGameView::~CGameView()
{
	delete m_bmp;
}


void CGameView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameView)
	DDX_Control(pDX, IDC_CHECK_ROOKIES, m_check_rookies);
	DDX_Control(pDX, IDC_BUTTON_LEADERS, m_button_leaders);
	DDX_Control(pDX, IDC_BUTTON_AWARDS, m_button_awards);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_RADIO_ALL, m_radio_all);
	DDX_Control(pDX, IDC_RADIO_PG, m_radio_pg);
	DDX_Control(pDX, IDC_RADIO_SG, m_radio_sg);
	DDX_Control(pDX, IDC_RADIO_SF, m_radio_sf);
	DDX_Control(pDX, IDC_RADIO_PF, m_radio_pf);
	DDX_Control(pDX, IDC_RADIO_C, m_radio_c);
	DDX_Control(pDX, IDC_RADIO_TEAMS, m_radio_teams);
	DDX_Control(pDX, IDC_RADIO_PLAYERS, m_radio_players);
	DDX_Control(pDX, IDC_RADIO_DEFENSE, m_radio_defense);
	DDX_Control(pDX, IDC_RADIO_HIGH, m_radio_high);
	DDX_Control(pDX, IDC_RADIO_LOW, m_radio_low);
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button_print);
	DDX_Control(pDX, IDC_BUTTON_HTML, m_button_html);
	//  DDX_Control(pDX, IDC_RADIO_SIMULATED, m_radio_simulated);
	DDX_Control(pDX, IDC_RADIO_PLAYOFFS, m_radio_playoffs);
	DDX_Control(pDX, IDC_RADIO_RATINGS, m_radio_ratings);
	DDX_Control(pDX, IDC_RADIO_CONTRACTS, m_radio_contracts);
	DDX_Control(pDX, IDC_RADIO_ACTUAL, m_radio_actual);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_LIST_CONTROL_STATS, m_list_stats);
	DDX_Control(pDX, IDC_COMBO_TEAM_NAMES, m_listTeams);
	DDX_Text(pDX, IDC_EDIT_RECORD, m_teamWL);
	DDV_MaxChars(pDX, m_teamWL, 32);
	DDX_Control(pDX, IDC_BUTTON_TEAM_PAGE, m_button_team_page);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	//}}AFX_DATA_MAP


	DDX_Control(pDX, IDC_RADIO_SIMULATED, m_radio_simulated);
	//DDX_Control(pDX, IDC_STATIC_G1, m_g[0]);
	//DDX_Control(pDX, IDC_STATIC_G2, m_g[1]);
	//DDX_Control(pDX, IDC_STATIC_G3, m_g[2]);
	//DDX_Control(pDX, IDC_STATIC_G4, m_g[3]);
	//DDX_Control(pDX, IDC_STATIC_G5, m_g[4]);
	//DDX_Control(pDX, IDC_STATIC_G6, m_g[5]);

}


BEGIN_MESSAGE_MAP(CGameView, CFormView)
	//{{AFX_MSG_MAP(CGameView)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_TEAM_PAGE, OnButtonTeamPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_BN_CLICKED(IDC_RADIO_ACTUAL, OnRadioActual)
	ON_BN_CLICKED(IDC_RADIO_SIMULATED, OnRadioSimulated)
	ON_BN_CLICKED(IDC_RADIO_RATINGS, OnRadioRatings)
	ON_BN_CLICKED(IDC_RADIO_PLAYERS, OnRadioPlayers)
	ON_BN_CLICKED(IDC_RADIO_TEAMS, OnRadioTeams)
	ON_BN_CLICKED(IDC_RADIO_DEFENSE, OnRadioDefense)
	ON_BN_CLICKED(IDC_RADIO_HIGH, OnRadioHigh)
	ON_BN_CLICKED(IDC_RADIO_LOW, OnRadioLow)
	ON_BN_CLICKED(IDC_RADIO_PLAYOFFS, OnRadioPlayoffs)
	ON_BN_CLICKED(IDC_RADIO_PG, OnRadioPg)
	ON_BN_CLICKED(IDC_RADIO_PF, OnRadioPf)
	ON_BN_CLICKED(IDC_RADIO_SF, OnRadioSf)
	ON_BN_CLICKED(IDC_RADIO_SG, OnRadioSg)
	ON_BN_CLICKED(IDC_RADIO_C, OnRadioC)
	ON_BN_CLICKED(IDC_RADIO_ALL, OnRadioAll)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTROL_STATS, OnDblclkListControlStats)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAM_NAMES, OnSelchangeComboTeamNames)
	ON_BN_CLICKED(IDC_RADIO_CONTRACTS, OnRadioContracts)
	ON_BN_CLICKED(IDC_BUTTON_HTML, OnButtonHtml)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_AWARDS, OnButtonAwards)
	ON_BN_CLICKED(IDC_BUTTON_LEADERS, OnButtonLeaders)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_ROOKIES, OnCheckRookies)
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
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CGameView::OnItemclickListControlStats)
	//ON_BN_CLICKED(IDC_STATIC_G1, &CGameView::OnBnClickedStaticG1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameView diagnostics

#ifdef _DEBUG
void CGameView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGameView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGameView message handlers

BOOL CGameView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;
}



void CGameView::OnInitialUpdate()
{

	SetWindowTheme(GetDlgItem(IDC_STATIC_G1)->GetSafeHwnd(), L"", L"");
	SetWindowTheme(GetDlgItem(IDC_STATIC_G2)->GetSafeHwnd(), L"", L"");
	SetWindowTheme(GetDlgItem(IDC_STATIC_G3)->GetSafeHwnd(), L"", L"");
	SetWindowTheme(GetDlgItem(IDC_STATIC_G4)->GetSafeHwnd(), L"", L"");
	SetWindowTheme(GetDlgItem(IDC_STATIC_G5)->GetSafeHwnd(), L"", L"");
	SetWindowTheme(GetDlgItem(IDC_STATIC_G6)->GetSafeHwnd(), L"", L"");

	/*m_button_schedule.SetButtonFontSize(16);
	m_button_schedule.SetButtonFontWeight(900);
	m_button_schedule.SetButtonFontType("Arial");*/

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();


	myBrush.CreateSolidBrush(SCREENCOLOR);

	m_check_rookies.SetWindowText("Rookies Only: Off");

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 14;
	//lf.lfWidth = 32;
	strcpy_s(lf.lfFaceName, USERFONT);
	m_font.CreateFontIndirect(&lf);    // Create the font.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 13;
	//	lf.lfUnderline = TRUE;
	strcpy_s(lf.lfFaceName, USERFONT);
	m_font1.CreateFontIndirect(&lf);    // Create the font.

	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 900;
	lf.lfHeight = 16;
	strcpy_s(lf.lfFaceName, USERFONT);
	m_font2.CreateFontIndirect(&lf);    // Create the font.


	GetDlgItem(IDC_STATIC_G1)->SetFont(&m_font2, TRUE);
	GetDlgItem(IDC_STATIC_G2)->SetFont(&m_font2, TRUE);
	GetDlgItem(IDC_STATIC_G3)->SetFont(&m_font2, TRUE);
	GetDlgItem(IDC_STATIC_G4)->SetFont(&m_font2, TRUE);
	GetDlgItem(IDC_STATIC_G5)->SetFont(&m_font2, TRUE);
	GetDlgItem(IDC_STATIC_G6)->SetFont(&m_font2, TRUE);

	//GetDlgItem(IDC_BUTTON_SCHEDULE)->SetFont(&m_font1, TRUE);



	// Update form's data from document
	SetFromDoc();



	// Resize parent to fit dialog template exactly    
	// while not resizing beyond size of screen
	VERIFY(pFrame = GetParentFrame());
	//pFrame->GetClientRect(rectFrame);
	GetClientRect(rectView);
	//    if ( rectFrame.Width() < rectView.Width()
	  //       || rectFrame.Height() < rectView.Height() )
		//{        
			// Resize so can be refit to any template that fits the screen

	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);
	//        pFrame->MoveWindow( 0, 0, w, h, FALSE ); 


	if (w > WIDTH) w = WIDTH;
	if (h > HEIGHT) h = HEIGHT;
	pFrame->SetWindowPos(NULL, 0, 0, w, h, SWP_SHOWWINDOW);
	pFrame->RecalcLayout();
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();


	CRect rectList;
	CWnd* pWnd = GetDlgItem(IDC_LIST_CONTROL_STATS);
	pWnd->GetWindowRect(&rectList);
	ScreenToClient(&rectList); //optional step - see below
	int listW = rectList.Width();
	int listH = rectList.Height();
	TRACE("int = % d\n", w);
	TRACE("int = % d\n", h);
	TRACE("int = % d\n", listW);
	TRACE("int = % d\n", listH);


	//position:  rect.left, rect.top
	//size: rect.Width(), rect.Height()


	//TRACE("msg=%s, int=%d\n", (LPCTSTR)listW , i);
	//if (w > WIDTH) w = WIDTH;
	//if (h > HEIGHT) h = HEIGHT;

	//if (w > 1023) w = 1023;
	//if (h > 750) h = 750;
	//pFrame->SetWindowPos(NULL, 0, 0, w, h, FALSE );
	//if(w > 800) m_list_stats.SetWindowPos(NULL, -1,-1,800,284,	SWP_NOMOVE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE);



//        pFrame->MoveWindow( 0, 0, GetSystemMetrics(SM_CXSCREEN), 
  //                      GetSystemMetrics(SM_CYSCREEN), FALSE ); 
	//}
	//pFrame->RecalcLayout();
	////ResizeParentToFit(TRUE);    // Shrink to fit template 
	//m_font2.DeleteObject();

	//m_button_schedule.SetFont(&m_font2);
	//m_button_schedule.SetButtonFontSize(40);









}

void CGameView::SetFromDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	UpdateData(FALSE);    // Set controls to these
}





void CGameView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(1);
}

void CGameView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(4);


}

void CGameView::OnSetupLoad()
{
	// TODO: Add your command handler code here



}

void CGameView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// TODO: Add your message handler code here
	if (bShow == TRUE)
	{
		avg = pDoc->avg;


		m_default_team = pDoc->m_combo_team_index;
		if (m_default_team < 1) m_default_team = 0;
		m_combo_teams.ResetContent();
		m_combo_teams.AddString("All Teams");

		for (int i = 0; i < avg.m_settings.m_numberteams; i++)
		{
			CString team_name = avg.m_settings.m_leagueTeamNames[i];
			if (team_name != "")
				//m_combo_teams.AddString(team_name);
				m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
		}

		m_combo_teams.SetCurSel(pDoc->m_combo_team_index);


		CheckDlgButton(IDC_RADIO_PLAYERS, 1);
		//	CheckDlgButton(IDC_RADIO_HIGH, 1);	 
		CheckDlgButton(IDC_RADIO_ALL, 6);

		CalculateCurrentPayroll();

		int slots = 30;
		int player_cell_end = 960;
		if (m_off_season == true)
		{
			slots = 30;
			player_cell_end = 960;
		}

		if (avg.m_settings.m_checkCareer == TRUE)
		{
			GetDlgItem(IDC_RADIO_ACTUAL)->ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_RADIO_ACTUAL)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO_ACTUAL)->ShowWindow(TRUE);

		}


		m_currentTeam = 0;
		if (m_stat_type == 1) CheckDlgButton(IDC_RADIO_SEASON, 1);
		if (m_stat_type == 2) CheckDlgButton(IDC_RADIO_PLAYOFF, 2);

		m_listTeams.ResetContent();
		m_listTeams.AddString(avg.m_settings.m_league_name);
		avg.m_settings.m_numberteams = 0;
		for (int i = 0; i < 32; i++)
		{
			if (avg.m_settings.m_leagueTeamNames[i] != "")
			{
				m_listTeams.AddString(avg.m_finance[i].m_city_name + " " + avg.m_settings.m_leagueTeamNames[i]);
				avg.m_settings.m_numberteams = avg.m_settings.m_numberteams + 1;
			}
		}
		m_listTeams.SetCurSel(m_default_team);

		m_co = 0;

		for (int i = 0; i <= player_cell_end; i++)
		{
			avg.m_actual[i].SetRosterNumber(i);
			int team = (i - 1) / slots + 1;
			avg.m_actual[i].m_team_index = team;
		}

		for (int i = 1473; i <= 1504; i++)
		{
			CString name = avg.m_settings.m_leagueTeamNames[i - 1473] + " opponents";
			avg.m_actual[i].SetName(name);
		}
		SetSeasonAverages();
		SetAdjustedRatings();
		OnSelchangeComboTeamNames();
		m_position = "";
		m_main_category = 1;
		m_switch_sort = false;
		if (avg.m_actual[1441 + m_default_team].m_sim_games == 0)
		{
			m_category = 3;
			m_changeHeading = 2;
			//		InitListCtrl();
			SetRatingsHeaders();
			CheckDlgButton(IDC_RADIO_RATINGS, 3);
			ListRatings();
		}
		else
		{
			m_category = 1;
			m_changeHeading = 1;
			//		InitListCtrl();
			SetColumnHeaders();
			CheckDlgButton(IDC_RADIO_SIMULATED, 1);
			ListSimulatedStats();
		}

		InitHeadings();

		UpdateData(FALSE);



	}


}

void CGameView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(0);

}




void CGameView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(3);


}

void CGameView::OnButtonTeamPage()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	((CBBallApp*)AfxGetApp())->SwitchView(3);


}


BOOL CGameView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/allstats.htm", HH_DISPLAY_TOPIC, 0);

//	return CDialog::OnHelpInfo(pHelpInfo);

	return TRUE;
}

void CGameView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/allstats.htm", HH_DISPLAY_TOPIC, 0);

//	return CDialog::OnHelpInfo(pHelpInfo);
}




void CGameView::OnButtonPrint()
{
	// TODO: Add your control notification handler code here
	//initialize a structure for my font

	CString pBuf;
	HDC    hdcPrn;
	// Instantiate a CPrintDialog.
	CPrintDialog* printDlg = new CPrintDialog(FALSE, PD_ALLPAGES | PD_RETURNDC, NULL);
	// Initialize some of the fields in PRINTDLG structure.
	printDlg->m_pd.nMinPage = printDlg->m_pd.nMaxPage = 1;
	printDlg->m_pd.nFromPage = printDlg->m_pd.nToPage = 1;
	// Display Windows print dialog box.       
	printDlg->DoModal();
	// Obtain a handle to the device context.
	hdcPrn = printDlg->GetPrinterDC();
	if (hdcPrn != NULL)
	{
		CDC* pDC = new CDC;
		pDC->Attach(hdcPrn);      // attach a printer DC
		pDC->StartDoc("Simulated Stats");  // begin a newe print job
		// for Win32 use
		// CDC::StartDoc(LPDOCINFO) override
		pDC->StartPage();          // begin a newe page
		SetPrintAlign(pDC, hdcPrn);// set the printing alignment
		LOGFONT lf;                        // Used to create the CFont.
		memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
		lf.lfWeight = 500;
		lf.lfHeight = 21;
		strcpy_s(lf.lfFaceName, "Courier New");
		CFont font;
		font.CreateFontIndirect(&lf);
		CFont* oldFont = pDC->SelectObject(&font);


		CString heading;
		int index = m_listTeams.GetCurSel();
		m_listTeams.GetLBText(index, heading);
		CString label = " Season Stats";
		if (m_category == 2) label = " Actual Stats";
		else if (m_category == 3) label = " Ratings";
		else if (m_category == 4) label = " Playoff Stats";
		else if (m_category == 5) label = " Contracts";
		heading = heading + label;


		pDC->TextOut(-900, 1000, heading);// write the string in pbuf
		int items = m_co;
		if (items > 50) items = 50;
		int row = 950;

		for (int i = 0; i <= items; i++)
		{
			if (i == 1) row = 900;
			for (int j = 0; j <= 25; j++)
			{
				if (i == 0 && m_category == 5)
					pBuf = m_column_headers[2][j];
				else if (i == 0 && m_category == 3)
					pBuf = m_column_headers[1][j];
				else if (i == 0)
					pBuf = m_column_headers[0][j];
				else
					pBuf = m_print_strings[i - 1][j];

				int col = -900 + j * 60;
				if (j == 0) col = -920;
				else if (j == 1) col = -870;
				else col = -720 + j * 77;

				pDC->TextOut(col, row, pBuf);// write the string in pbuf
			}
			row = row - 35;
		}
		pDC->EndPage();            // end a page
		pDC->EndDoc();             // end a print job
		pDC->Detach();             // detach the printer DC
		delete pDC;
	}
	delete printDlg;

}

void CGameView::SetPrintAlign(CDC* pDC, HDC hdcPrn)
{
	short cxPage, cyPage;
	cxPage = ::GetDeviceCaps(hdcPrn, HORZRES);
	cyPage = ::GetDeviceCaps(hdcPrn, VERTRES);

	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(1000, 1000);

	pDC->SetViewportExt(cxPage / 2, -cyPage / 2);
	pDC->SetViewportOrg(cxPage / 2, cyPage / 2);
	pDC->SetTextAlign(TA_BASELINE);
}







void CGameView::SetColumnHeaders()
{

	m_list_stats.DeleteAllItems();



	m_list_stats.DeleteColumn(0);
	m_list_stats.InsertColumn(0, "po");
	m_list_stats.DeleteColumn(1);
	m_list_stats.InsertColumn(1, "name");
	m_list_stats.DeleteColumn(2);
	m_list_stats.InsertColumn(2, "g");
	m_list_stats.DeleteColumn(3);
	m_list_stats.InsertColumn(3, "min");
	m_list_stats.DeleteColumn(4);
	m_list_stats.InsertColumn(4, "fgm");
	m_list_stats.DeleteColumn(5);
	m_list_stats.InsertColumn(5, "fga");
	m_list_stats.DeleteColumn(6);
	m_list_stats.InsertColumn(6, "fgp");
	m_list_stats.DeleteColumn(7);
	m_list_stats.InsertColumn(7, "ftm");
	m_list_stats.DeleteColumn(8);
	m_list_stats.InsertColumn(8, "fta");
	m_list_stats.DeleteColumn(9);
	m_list_stats.InsertColumn(9, "ftp");
	m_list_stats.DeleteColumn(10);
	m_list_stats.InsertColumn(10, "tgm");
	m_list_stats.DeleteColumn(11);
	m_list_stats.InsertColumn(11, "tga");
	m_list_stats.DeleteColumn(12);
	m_list_stats.InsertColumn(12, "tgp");
	m_list_stats.DeleteColumn(13);
	m_list_stats.InsertColumn(13, "orb");
	m_list_stats.DeleteColumn(14);
	m_list_stats.InsertColumn(14, "reb");
	m_list_stats.DeleteColumn(15);
	m_list_stats.InsertColumn(15, "ast");
	m_list_stats.DeleteColumn(16);
	m_list_stats.InsertColumn(16, "stl");
	m_list_stats.DeleteColumn(17);
	m_list_stats.InsertColumn(17, "to");
	m_list_stats.DeleteColumn(18);
	m_list_stats.InsertColumn(18, "blk");
	m_list_stats.DeleteColumn(19);
	m_list_stats.InsertColumn(19, "pf");
	m_list_stats.DeleteColumn(20);
	m_list_stats.InsertColumn(20, "ppg");
	m_list_stats.DeleteColumn(21);
	m_list_stats.InsertColumn(21, "inj");


	m_list_stats.DeleteColumn(22);
	m_list_stats.DeleteColumn(22);
	m_list_stats.DeleteColumn(22);

	m_list_stats.SetColumnWidth(0, 32);
	m_list_stats.SetColumnWidth(1, 128);
	m_list_stats.SetColumnWidth(2, 32);


	for (int i = 3; i <= 20 ; i++)
	{
		m_list_stats.SetColumnWidth(i, 48);
	}

	m_list_stats.SetColumnWidth(21, 32);


}

void CGameView::ListStats()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//avg.m_settings.

	m_list_stats.DeleteAllItems();
	int player = m_currentTeam * 15;
	int co = 0;
	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	//	memset(m_print_strings, 0,  sizeof(m_print_strings));


	for (int index = 0; index <= 1600; index++)
	{
		int i = index;
		m_player_pointer[index] = 0;
		if (m_switch_sort == true) i = 1600 - index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();

		int team = m_player.m_team_index;
		if (team != m_currentTeam && m_currentTeam > 0) continue;

		if (m_main_category == 1 && m_rookie_view == true && m_player.m_yrs_of_service > 1) continue;


		int g = m_player.GetGames();
		if (g == 0) continue;
		int min = m_player.GetMin();
		int tfgm = m_player.GetTfgm();
		int tfga = m_player.GetTfga();
		int fgm = m_player.GetFgm();
		int fga = m_player.GetFga();
		int ftm = m_player.GetFtm();
		int fta = m_player.GetFta();
		if (Name == "") continue;
		Stats[1] = Name;
		Stats[0] = m_player.GetPos();

		if (Stats[0] != "" && m_position != "" && Stats[0] != m_position) continue;


		Stats[2].Format("%d", g);

		double mpg = double(min) / g;
		if (min == 0) Stats[3].Format("%d", mpg);
		else Stats[3].Format("%.1f", mpg);



		Stats[4].Format("%d", fgm);
		Stats[5].Format("%d", fga);

		double fgp;
		if (fga == 0) { fgp = 0; }
		else fgp = double(fgm) / double(fga) * 100;
		if (fgp == 100)
			Stats[6].Format("%d", int(fgp));
		else
			Stats[6].Format("%.1f", fgp);
		Stats[10].Format("%d", tfgm);
		Stats[11].Format("%d", tfga);

		double tfgp;
		if (tfga == 0) tfgp = 0;
		else tfgp = double(tfgm) / double(tfga) * 100;
		Stats[12].Format("%.1f", tfgp);

		Stats[7].Format("%d", ftm);
		Stats[8].Format("%d", fta);

		double ftpct;
		if (fta == 0) ftpct = 0;
		else ftpct = double(ftm) / double(fta) * 100;
		Stats[9].Format("%.1f", ftpct);

		double oreb = double(m_player.GetOreb()) / g;
		if (oreb == 0) Stats[13].Format("%d", oreb);
		else Stats[13].Format("%.2f", oreb);

		double reb = double(m_player.GetReb()) / g;
		if (reb == 0) Stats[14].Format("%d", reb);
		else Stats[14].Format("%.2f", reb);

		double ast = double(m_player.GetAst()) / g;
		if (ast == 0) Stats[15].Format("%d", ast);
		else Stats[15].Format("%.2f", ast);

		double stl = double(m_player.GetStl()) / g;
		if (stl == 0) Stats[16].Format("%d", stl);
		else Stats[16].Format("%.2f", stl);

		double to = double(m_player.GetTo()) / g;
		if (to == 0) Stats[17].Format("%d", to);
		else Stats[17].Format("%.2f", to);

		double blk = double(m_player.GetBlk()) / g;
		if (blk == 0) Stats[18].Format("%d", blk);
		else Stats[18].Format("%.2f", blk);


		int pf = m_player.GetPf();
		Stats[19].Format("%d", pf);

		int injury = m_player.GetInjury();
		Stats[21].Format("%d", injury);

		double ppg = (double(fgm) * 2
			+ double(tfgm)
			+ ftm) / g;
		if (ppg == 0) Stats[21].Format("%d", ppg);
		else Stats[20].Format("%.1f", ppg);


		m_list_stats.InsertItem(co, Stats[0]);
		for (int s = 0; s <= 20; s++)
		{
			m_list_stats.SetItemText(co, s + 1, Stats[s + 1]);
		}
		m_player_pointer[co] = i;
		BuildString(Stats, co, 33);
		co = co + 1;
	}
	m_co = co;
}



void CGameView::OnRadioActual()
{
	// TODO: Add your control notification handler code here
	if (m_changeHeading >= 2)
	{
		m_changeHeading = 1;
		SetColumnHeaders();
	}
	if (m_category != 2)
	{
		m_category = 2;
		ListStats();
	}
}

void CGameView::OnRadioSimulated()
{
	// TODO: Add your control notification handler code here

	m_radio_simulated.SetState(TRUE);

	if (m_changeHeading >= 2)
	{
		m_changeHeading = 1;
		SetColumnHeaders();
	}
	if (m_category != 1)
	{
		m_category = 1;
		ListSimulatedStats();
	}
}

void CGameView::ListSimulatedStats()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//avg.m_settings.


	m_list_stats.DeleteAllItems();

	int co = 0;

	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[i][j] = "";
		}
	}


	for (int index = 0; index <= 1600; index++)
	{
		m_player_pointer[index] = 0;

		int i = index;
		if (m_switch_sort == true) i = 1600 - index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();



		int pointer = m_player.m_original_number;

		if (Pos != "" && m_position != "" && Pos != m_position && (pointer <= 1440 || pointer > 1504)) continue;
		if (Name == "") Pos = "";
		if (Name == "" && pointer >= 1473 && pointer <= 1504) Name = avg.m_settings.m_leagueTeamNames[pointer - 1473] + " opponents";
		else if (Name == "" && pointer >= 1441 && pointer <= 1472) Name = avg.m_settings.m_leagueTeamNames[pointer - 1441];
		else if (Name == "") continue;

		bool ok = false;
		int team = m_player.m_team_index;
		if (team == m_currentTeam && m_currentTeam > 0 && (pointer <= 1440 || pointer > 1504) && m_main_category == 1) ok = true;
		if (m_currentTeam == 0 && pointer <= 1440 && m_main_category == 1) ok = true;
		if (pointer >= 1473 && pointer <= 1504 && m_currentTeam > 0 && m_currentTeam == pointer - 1472) ok = true;
		else if (pointer >= 1441 && pointer <= 1472 && m_currentTeam > 0 && m_currentTeam == pointer - 1440) ok = true;
		else if (m_main_category == 3 && pointer >= 1473 && pointer <= 1504 && m_currentTeam == 0) ok = true;
		else if (m_main_category == 2 && pointer >= 1441 && pointer <= 1472 && m_currentTeam == 0) ok = true;

		if (m_main_category == 2 && pointer >= 1473 && pointer <= 1504) ok = false;
		else if (m_main_category == 3 && pointer >= 1441 && pointer <= 1472) ok = false;

		if (m_position != "" && pointer >= 1440 && pointer <= 1504) ok = false;


		if (m_main_category == 1 && m_rookie_view == true && m_player.m_yrs_of_service > 1) ok = false;

		if (ok == false) continue;
		int g = m_player.m_sim_games;
		if (g == 0) continue;
		int min = m_player.m_sim_min;
		int fgm = m_player.m_sim_fgm;
		int fga = m_player.m_sim_fga;
		int tfgm = m_player.m_sim_tfgm;
		int tfga = m_player.m_sim_tfga;
		fgm = fgm + tfgm;
		fga = fga + tfga;
		int ftm = m_player.m_sim_ftm;
		int fta = m_player.m_sim_fta;

		Stats[1] = Name;
		Stats[0] = m_player.GetPos();
		Stats[2].Format("%d", g);

		double mpg = double(min) / g;
		if (min == 0) Stats[3].Format("%d", mpg);
		else Stats[3].Format("%.1f", mpg);

		if (pointer >= 1441) Stats[3] = "";

		Stats[4].Format("%d", fgm);
		Stats[5].Format("%d", fga);

		double fgp;
		if (fga == 0) { fgp = 0; }
		else fgp = double(fgm) / double(fga) * 100;
		if (fgp == 100)
			Stats[6].Format("%d", int(fgp));
		else
			Stats[6].Format("%.1f", fgp);
		Stats[10].Format("%d", tfgm);
		Stats[11].Format("%d", tfga);

		double tfgp;
		if (tfga == 0) tfgp = 0;
		else tfgp = double(tfgm) / double(tfga) * 100;
		Stats[12].Format("%.1f", tfgp);

		Stats[7].Format("%d", ftm);
		Stats[8].Format("%d", fta);

		double ftpct;
		if (fta == 0) ftpct = 0;
		else ftpct = double(ftm) / double(fta) * 100;
		Stats[9].Format("%.1f", ftpct);

		double oreb = double(m_player.m_sim_oreb) / g;
		if (oreb == 0) Stats[13].Format("%d", oreb);
		else Stats[13].Format("%.2f", oreb);

		double reb = oreb + double(m_player.m_sim_reb) / g;
		if (reb == 0) Stats[14].Format("%d", reb);
		else Stats[14].Format("%.2f", reb);

		double ast = double(m_player.m_sim_ast) / g;
		if (ast == 0) Stats[15].Format("%d", ast);
		else Stats[15].Format("%.2f", ast);

		double stl = double(m_player.m_sim_stl) / g;
		if (stl == 0) Stats[16].Format("%d", stl);
		else Stats[16].Format("%.2f", stl);

		double to = double(m_player.m_sim_to) / g;
		if (to == 0) Stats[17].Format("%d", to);
		else Stats[17].Format("%.2f", to);

		double blk = double(m_player.m_sim_blk) / g;
		if (blk == 0) Stats[18].Format("%d", blk);
		else Stats[18].Format("%.2f", blk);


		int pf = m_player.m_sim_pf;
		Stats[19].Format("%d", pf);

		int injury = m_player.GetInjury();
		Stats[21].Format("%d", injury);

		double ppg = (double(fgm) * 2
			+ double(tfgm)
			+ ftm) / g;
		if (ppg == 0) Stats[21].Format("%d", ppg);
		else Stats[20].Format("%.1f", ppg);


		m_list_stats.InsertItem(co, Stats[0]);
		for (int s = 0; s <= 20; s++)
		{

			m_list_stats.SetItemText(co, s + 1, Stats[s + 1]);
		}

		m_player_pointer[co] = i;
		BuildString(Stats, co, 33);
		co = co + 1;
	}
	m_co = co;
}

void CGameView::OnRadioRatings()
{
	// TODO: Add your control notification handler code here

	if (m_changeHeading == 1 || m_changeHeading == 3)
	{
		m_changeHeading = 2;
		SetRatingsHeaders();
	}
	if (m_category != 3)
	{
		m_category = 3;
		ListRatings();
	}

}

void CGameView::ListRatings()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//avg.m_settings.

	m_list_stats.DeleteAllItems();
	int co = 0;
	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for (int index = 0; index <= 1600; index++)
	{
		m_player_pointer[index] = 0;
		int i = index;
		if (m_switch_sort == true) i = 1600 - index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		int pointer = m_player.m_original_number;
		if (Name == "" || (pointer > 1440 && pointer <= 1504)) continue;
		int team = m_player.m_team_index;

		if (m_main_category == 1 && m_rookie_view == true && m_player.m_yrs_of_service > 1) continue;

		if (team != m_currentTeam && m_currentTeam > 0) continue;


		Stats[1] = Name;
		Stats[0] = m_player.GetPos();

		if (Stats[0] != "" && m_position != "" && Stats[0] != m_position) continue;



		int r = m_player.GetAdjPrFga();
		Stats[2].Format("%d", r);


		r = m_player.GetAdjPrFgp();
		Stats[3].Format("%d", r);



		r = m_player.GetAdjPrFta();
		Stats[4].Format("%d", r);

		r = m_player.GetAdjPrFtp();
		Stats[5].Format("%d", r);


		r = m_player.GetAdjPrTga();
		Stats[6].Format("%d", r);


		r = m_player.GetAdjPrTgp();
		Stats[7].Format("%d", r);


		r = m_player.GetAdjPrOrb();
		Stats[8].Format("%d", r);

		r = m_player.GetAdjPrDrb();
		Stats[9].Format("%d", r);

		r = m_player.GetAdjPrAst();
		Stats[10].Format("%d", r);

		r = m_player.GetAdjPrStl();
		Stats[11].Format("%d", r);

		r = m_player.GetAdjPrTo();
		Stats[12].Format("%d", r);

		r = m_player.GetAdjPrBlk();
		Stats[13].Format("%d", r);

		int rating = m_player.GetMovOff();
		Stats[14].Format("%d", rating);

		rating = m_player.GetMovDef();
		Stats[18].Format("%d", rating);

		rating = m_player.GetPenOff();
		Stats[15].Format("%d", rating);

		rating = m_player.GetPenDef();
		Stats[19].Format("%d", rating);

		rating = m_player.GetPostOff();
		Stats[16].Format("%d", rating);

		rating = m_player.GetPostDef();
		Stats[20].Format("%d", rating);

		rating = m_player.GetTransOff();
		Stats[17].Format("%d", rating);

		rating = m_player.GetTransDef();
		Stats[21].Format("%d", rating);

		rating = m_player.GetAdjPot1();
		Stats[22].Format("%d", rating);

		rating = m_player.GetAdjPot2();
		Stats[23].Format("%d", rating);

		rating = m_player.GetAdjEffort();
		Stats[24].Format("%d", rating);

		m_list_stats.InsertItem(co, Stats[0]);
		for (int s = 0; s <= 23; s++)
		{
			m_list_stats.SetItemText(co, s + 1, Stats[s + 1]);
		}
		m_player_pointer[co] = i;
		BuildString(Stats, co, 33);
		co = co + 1;
	}
	m_co = co;

}

void CGameView::SetRatingsHeaders()
{

	m_list_stats.DeleteAllItems();

	m_list_stats.DeleteColumn(0);
	m_list_stats.InsertColumn(0, "po");
	m_list_stats.DeleteColumn(1);
	m_list_stats.InsertColumn(1, "name");
	m_list_stats.DeleteColumn(2);
	m_list_stats.InsertColumn(2, "2ga");
	m_list_stats.DeleteColumn(3);
	m_list_stats.InsertColumn(3, "2g%");
	m_list_stats.DeleteColumn(4);
	m_list_stats.InsertColumn(4, "fta");
	m_list_stats.DeleteColumn(5);
	m_list_stats.InsertColumn(5, "ft%");
	m_list_stats.DeleteColumn(6);
	m_list_stats.InsertColumn(6, "3ga");
	m_list_stats.DeleteColumn(7);
	m_list_stats.InsertColumn(7, "3g%");
	m_list_stats.DeleteColumn(8);
	m_list_stats.InsertColumn(8, "orb");
	m_list_stats.DeleteColumn(9);
	m_list_stats.InsertColumn(9, "drb");
	m_list_stats.DeleteColumn(10);
	m_list_stats.InsertColumn(10, "ast");
	m_list_stats.DeleteColumn(11);
	m_list_stats.InsertColumn(11, "stl");
	m_list_stats.DeleteColumn(12);
	m_list_stats.InsertColumn(12, "to");
	m_list_stats.DeleteColumn(13);
	m_list_stats.InsertColumn(13, "blk");
	m_list_stats.DeleteColumn(14);
	m_list_stats.InsertColumn(14, "oo");
	m_list_stats.DeleteColumn(15);
	m_list_stats.InsertColumn(15, "do");
	m_list_stats.DeleteColumn(16);
	m_list_stats.InsertColumn(16, "po");
	m_list_stats.DeleteColumn(17);
	m_list_stats.InsertColumn(17, "to");
	m_list_stats.DeleteColumn(18);
	m_list_stats.InsertColumn(18, "od");
	m_list_stats.DeleteColumn(19);
	m_list_stats.InsertColumn(19, "dd");
	m_list_stats.DeleteColumn(20);
	m_list_stats.InsertColumn(20, "pd");
	m_list_stats.DeleteColumn(21);
	m_list_stats.InsertColumn(21, "td");
	m_list_stats.DeleteColumn(22);
	m_list_stats.InsertColumn(22, "ta");
	m_list_stats.DeleteColumn(23);
	m_list_stats.InsertColumn(23, "sk");
	m_list_stats.DeleteColumn(24);
	m_list_stats.InsertColumn(24, "in");

	m_list_stats.SetColumnWidth(0, 24);
	m_list_stats.SetColumnWidth(1, 88);
	m_list_stats.SetColumnWidth(2, 30);
	m_list_stats.SetColumnWidth(3, 33);
	m_list_stats.SetColumnWidth(4, 30);
	m_list_stats.SetColumnWidth(5, 30);
	m_list_stats.SetColumnWidth(6, 30);
	m_list_stats.SetColumnWidth(7, 33);
	m_list_stats.SetColumnWidth(8, 30);
	m_list_stats.SetColumnWidth(9, 30);
	m_list_stats.SetColumnWidth(10, 30);
	m_list_stats.SetColumnWidth(11, 30);
	m_list_stats.SetColumnWidth(12, 30);
	m_list_stats.SetColumnWidth(13, 30);
	m_list_stats.SetColumnWidth(14, 24);
	m_list_stats.SetColumnWidth(15, 24);
	m_list_stats.SetColumnWidth(16, 24);
	m_list_stats.SetColumnWidth(17, 24);
	m_list_stats.SetColumnWidth(18, 24);
	m_list_stats.SetColumnWidth(19, 24);
	m_list_stats.SetColumnWidth(20, 24);
	m_list_stats.SetColumnWidth(21, 24);
	m_list_stats.SetColumnWidth(22, 24);
	m_list_stats.SetColumnWidth(23, 24);
	m_list_stats.SetColumnWidth(24, 24);

}



void CGameView::ListPlayoffStats()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//avg.m_settings.
	m_list_stats.DeleteAllItems();

	int co = 0;
	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for (int index = 0; index <= 1600; index++)
	{
		m_player_pointer[index] = 0;
		int i = index;
		if (m_switch_sort == true) i = 1600 - index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		int pointer = m_player.m_original_number;
		if (Pos != "" && m_position != "" && Pos != m_position && (pointer <= 1440 || pointer > 1504)) continue;


		if (Name == "") Pos = "";
		if (Name == "" && pointer >= 1473 && pointer <= 1504) Name = avg.m_settings.m_leagueTeamNames[pointer - 1473] + " opponents";
		else if (Name == "" && pointer >= 1441 && pointer <= 1472) Name = avg.m_settings.m_leagueTeamNames[pointer - 1441];
		else if (Name == "") continue;


		bool ok = false;
		int team = m_player.m_team_index;
		if (team == m_currentTeam && m_currentTeam > 0 && (pointer <= 1440 || pointer > 1504) && m_main_category == 1) ok = true;
		if (m_currentTeam == 0 && (pointer <= 1440 || pointer > 1504) && m_main_category == 1) ok = true;
		if (pointer >= 1473 && pointer <= 1504 && m_currentTeam > 0 && m_currentTeam == pointer - 1472) ok = true;
		else if (pointer >= 1441 && pointer <= 1472 && m_currentTeam > 0 && m_currentTeam == pointer - 1440) ok = true;
		else if (m_main_category == 3 && pointer >= 1473 && pointer <= 1504 && m_currentTeam == 0) ok = true;
		else if (m_main_category == 2 && pointer >= 1441 && pointer <= 1472 && m_currentTeam == 0) ok = true;

		if (m_main_category == 2 && pointer >= 1473 && pointer <= 1504) ok = false;
		else if (m_main_category == 3 && pointer >= 1441 && pointer <= 1472) ok = false;

		if (m_position != "" && pointer >= 1440 && pointer <= 1504) ok = false;

		if (m_main_category == 1 && m_rookie_view == true && m_player.m_yrs_of_service > 1) continue;







		if (ok == false) continue;
		int g = m_player.m_po_games;
		if (g == 0) continue;
		int min = m_player.m_po_min;
		int fgm = m_player.m_po_fgm;
		int fga = m_player.m_po_fga;
		int tfgm = m_player.m_po_tfgm;
		int tfga = m_player.m_po_tfga;
		fgm = fgm + tfgm;
		fga = fga + tfga;
		int ftm = m_player.m_po_ftm;
		int fta = m_player.m_po_fta;

		Stats[1] = Name;
		Stats[0] = m_player.GetPos();
		Stats[2].Format("%d", g);

		double mpg = double(min) / g;
		if (min == 0) Stats[3].Format("%d", mpg);
		else Stats[3].Format("%.1f", mpg);
		if (pointer >= 1441) Stats[3] = "";

		Stats[4].Format("%d", fgm);
		Stats[5].Format("%d", fga);

		double fgp;
		if (fga == 0) { fgp = 0; }
		else fgp = double(fgm) / double(fga) * 100;
		if (fgp == 100)
			Stats[6].Format("%d", int(fgp));
		else
			Stats[6].Format("%.1f", fgp);
		Stats[10].Format("%d", tfgm);
		Stats[11].Format("%d", tfga);

		double tfgp;
		if (tfga == 0) tfgp = 0;
		else tfgp = double(tfgm) / double(tfga) * 100;
		Stats[12].Format("%.1f", tfgp);

		Stats[7].Format("%d", ftm);
		Stats[8].Format("%d", fta);

		double ftpct;
		if (fta == 0) ftpct = 0;
		else ftpct = double(ftm) / double(fta) * 100;
		Stats[9].Format("%.1f", ftpct);

		double oreb = double(m_player.m_po_oreb) / g;
		if (oreb == 0) Stats[13].Format("%d", oreb);
		else Stats[13].Format("%.2f", oreb);

		double reb = oreb + double(m_player.m_po_reb) / g;
		if (reb == 0) Stats[14].Format("%d", reb);
		else Stats[14].Format("%.2f", reb);

		double ast = double(m_player.m_po_ast) / g;
		if (ast == 0) Stats[15].Format("%d", ast);
		else Stats[15].Format("%.2f", ast);

		double stl = double(m_player.m_po_stl) / g;
		if (stl == 0) Stats[16].Format("%d", stl);
		else Stats[16].Format("%.2f", stl);

		double to = double(m_player.m_po_to) / g;
		if (to == 0) Stats[17].Format("%d", to);
		else Stats[17].Format("%.2f", to);

		double blk = double(m_player.m_po_blk) / g;
		if (blk == 0) Stats[18].Format("%d", blk);
		else Stats[18].Format("%.2f", blk);


		int pf = m_player.m_po_pf;
		Stats[19].Format("%d", pf);

		int injury = m_player.GetInjury();
		Stats[21].Format("%d", injury);

		double ppg = (double(fgm) * 2
			+ double(tfgm)
			+ ftm) / g;
		if (ppg == 0) Stats[21].Format("%d", ppg);
		else Stats[20].Format("%.1f", ppg);

		m_list_stats.InsertItem(co, Stats[0]);
		for (int s = 0; s <= 20; s++)
		{
			m_list_stats.SetItemText(co, s + 1, Stats[s + 1]);
		}
		m_player_pointer[co] = i;
		BuildString(Stats, co, 33);
		co = co + 1;
	}
	m_co = co;
}



void CGameView::OnRadioPlayers()
{
	// TODO: Add your control notification handler code here
	if (m_main_category != 1)
	{
		m_main_category = 1;
		//		OnSelchangeListTeams();
		OnSelchangeComboTeamNames();
	}
}

void CGameView::OnRadioTeams()
{
	// TODO: Add your control notification handler code here
	if (m_main_category != 2)
	{
		m_main_category = 2;
		//		OnSelchangeListTeams();
		OnSelchangeComboTeamNames();
	}

}



void CGameView::OnRadioDefense()
{
	// TODO: Add your control notification handler code here
	if (m_main_category != 3)
	{
		m_main_category = 3;
		//		OnSelchangeListTeams();
		OnSelchangeComboTeamNames();
	}

}



void CGameView::QuickSort()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int initial_increment = 4;
	int i = 0, j = 0;
	CPlayer temp;
	int inc = initial_increment;

	while (inc > 0)
	{
		for (i = 0; i <= 1600; i++)
		{

			j = i;
			temp = avg.m_actual[i];
			bool swap = false;

			if (j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

			while (swap == true)
			{
				swap = false;

				avg.m_actual[j] = avg.m_actual[j - inc];
				j = j - inc;

				if (j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

			}
			avg.m_actual[j] = temp;
		}

		if (inc / 2 != 0) inc = inc / 2;
		else if (inc == 1) inc = 0;
		else inc = 1;

	}

	ChooseStatsToList();
}

bool CGameView::SortStats(CPlayer m_actual_i, CPlayer m_actual_j)
{
	bool swap = false;

	switch (m_column)
	{



	case 0:
		swap = m_actual_i.m_original_number > m_actual_j.m_original_number;
		//		swap = m_actual_i.m_pos > m_actual_j.m_pos;
		break;
	case 1:
		swap = m_actual_i.GetName() > m_actual_j.GetName();
		break;
	case 2:
		swap = m_actual_i.m_sim_games < m_actual_j.m_sim_games;
		break;
	case 3:
		swap = m_actual_i.GetSimMinPerGame() < m_actual_j.GetSimMinPerGame();
		break;
	case 4:
		swap = (m_actual_i.m_sim_fgm + m_actual_i.m_sim_tfgm) < (m_actual_j.m_sim_fgm + m_actual_j.m_sim_tfgm);
		break;
	case 5:
		swap = (m_actual_i.m_sim_fga + m_actual_i.m_sim_tfga) < (m_actual_j.m_sim_fga + m_actual_j.m_sim_tfga);
		break;
	case 6:
		swap = m_actual_i.GetSimFgPct() < m_actual_j.GetSimFgPct();
		break;
	case 7:
		swap = m_actual_i.m_sim_ftm < m_actual_j.m_sim_ftm;
		break;
	case 8:
		swap = m_actual_i.m_sim_fta < m_actual_j.m_sim_fta;
		break;
	case 9:
		swap = m_actual_i.GetSimFtPct() < m_actual_j.GetSimFtPct();
		break;
	case 10:
		swap = m_actual_i.m_sim_tfgm < m_actual_j.m_sim_tfgm;
		break;
	case 11:
		swap = m_actual_i.m_sim_tfga < m_actual_j.m_sim_tfga;
		break;
	case 12:
		swap = m_actual_i.GetSimTfgPct() < m_actual_j.GetSimTfgPct();
		break;
	case 13:
		swap = m_actual_i.GetSimOrebPerGame() < m_actual_j.GetSimOrebPerGame();
		break;
	case 14:
		swap = (m_actual_i.GetSimReboundsPerGame() + m_actual_i.GetSimOrebPerGame()) < (m_actual_j.GetSimReboundsPerGame() + m_actual_j.GetSimOrebPerGame());
		break;
	case 15:
		swap = m_actual_i.GetSimAssistsPerGame() < m_actual_j.GetSimAssistsPerGame();
		break;
	case 16:
		swap = m_actual_i.GetSimStealsPerGame() < m_actual_j.GetSimStealsPerGame();
		break;
	case 17:
		swap = m_actual_i.GetSimToPerGame() < m_actual_j.GetSimToPerGame();
		break;
	case 18:
		swap = m_actual_i.GetSimBlocksPerGame() < m_actual_j.GetSimBlocksPerGame();
		break;
	case 19:
		swap = m_actual_i.m_sim_pf < m_actual_j.m_sim_pf;
		break;
	case 20:
		swap = m_actual_i.GetSimPointsPerGame() < m_actual_j.GetSimPointsPerGame();
		break;
	case 21:
		swap = m_actual_i.GetInjury() < m_actual_j.GetInjury();
		break;
	case 22:
		break;

	}
	//insure that team stats always ranked below player stats
	if ((m_actual_i.m_original_number >= 1441 && m_actual_i.m_original_number <= 1504) && (m_actual_j.m_original_number <= 1440 || m_actual_j.m_original_number > 1504) && m_switch_sort == false)
		swap = true;
	else if ((m_actual_j.m_original_number >= 1441 && m_actual_j.m_original_number <= 1504) && (m_actual_i.m_original_number <= 1440 || m_actual_i.m_original_number > 1504) && m_switch_sort == false)
		swap = false;
	else if ((m_actual_i.m_original_number >= 1441 && m_actual_i.m_original_number <= 1504) && (m_actual_j.m_original_number <= 1440 || m_actual_j.m_original_number > 1504) && m_switch_sort == true)
		swap = false;
	else if ((m_actual_j.m_original_number >= 1441 && m_actual_j.m_original_number <= 1504) && (m_actual_i.m_original_number <= 1440 || m_actual_i.m_original_number > 1504) && m_switch_sort == true)
		swap = true;


	return swap;
}

bool CGameView::SortPlayoffStats(CPlayer m_actual_i, CPlayer m_actual_j)
{
	bool swap = false;

	switch (m_column)
	{



	case 0:

		swap = m_actual_i.m_original_number > m_actual_j.m_original_number;
		//		swap = m_actual_i.GetPos() < m_actual_j.GetPos();
		break;
	case 1:
		swap = m_actual_i.GetName() > m_actual_j.GetName();
		break;
	case 2:
		swap = m_actual_i.m_po_games < m_actual_j.m_po_games;
		break;
	case 3:
		swap = m_actual_i.GetPoMinPerGame() < m_actual_j.GetPoMinPerGame();
		break;
	case 4:
		swap = (m_actual_i.m_po_fgm + m_actual_i.m_po_tfgm) < (m_actual_j.m_po_fgm + m_actual_j.m_po_tfgm);
		break;
	case 5:
		swap = (m_actual_i.m_po_fga + m_actual_i.m_po_tfga) < (m_actual_j.m_po_fga + m_actual_j.m_po_tfga);
		break;
	case 6:
		swap = m_actual_i.GetPoFgPct() < m_actual_j.GetPoFgPct();
		break;
	case 7:
		swap = m_actual_i.m_po_ftm < m_actual_j.m_po_ftm;
		break;
	case 8:
		swap = m_actual_i.m_po_fta < m_actual_j.m_po_fta;
		break;
	case 9:
		swap = m_actual_i.GetPoFtPct() < m_actual_j.GetPoFtPct();
		break;
	case 10:
		swap = m_actual_i.m_po_tfgm < m_actual_j.m_po_tfgm;
		break;
	case 11:
		swap = m_actual_i.m_po_tfga < m_actual_j.m_po_tfga;
		break;
	case 12:
		swap = m_actual_i.GetPoTfgPct() < m_actual_j.GetPoTfgPct();
		break;
	case 13:
		swap = m_actual_i.GetPoOrebPerGame() < m_actual_j.GetPoOrebPerGame();
		break;
	case 14:
		swap = (m_actual_i.GetPoReboundsPerGame() + m_actual_i.GetPoOrebPerGame()) < (m_actual_j.GetPoReboundsPerGame() + m_actual_j.GetPoOrebPerGame());
		break;
	case 15:
		swap = m_actual_i.GetPoAssistsPerGame() < m_actual_j.GetPoAssistsPerGame();
		break;
	case 16:
		swap = m_actual_i.GetPoStealsPerGame() < m_actual_j.GetPoStealsPerGame();
		break;
	case 17:
		swap = m_actual_i.GetPoToPerGame() < m_actual_j.GetPoToPerGame();
		break;
	case 18:
		swap = m_actual_i.GetPoBlocksPerGame() < m_actual_j.GetPoBlocksPerGame();
		break;
	case 19:
		swap = m_actual_i.m_po_pf < m_actual_j.m_po_pf;
		break;
	case 20:
		swap = m_actual_i.GetPoPointsPerGame() < m_actual_j.GetPoPointsPerGame();
		break;
	case 21:
		swap = m_actual_i.GetInjury() < m_actual_j.GetInjury();
		break;
	case 22:
		break;

	}
	//insure that team stats always ranked below player stats
	if ((m_actual_i.m_original_number >= 1441 && m_actual_i.m_original_number <= 1504) && (m_actual_j.m_original_number <= 1440 || m_actual_j.m_original_number > 1504) && m_switch_sort == false)
		swap = true;
	else if ((m_actual_j.m_original_number >= 1441 && m_actual_j.m_original_number <= 1504) && (m_actual_i.m_original_number <= 1440 || m_actual_i.m_original_number > 1504) && m_switch_sort == false)
		swap = false;
	else if ((m_actual_i.m_original_number >= 1441 && m_actual_i.m_original_number <= 1504) && (m_actual_j.m_original_number <= 1440 || m_actual_j.m_original_number > 1504) && m_switch_sort == true)
		swap = false;
	else if ((m_actual_j.m_original_number >= 1441 && m_actual_j.m_original_number <= 1504) && (m_actual_i.m_original_number <= 1440 || m_actual_i.m_original_number > 1504) && m_switch_sort == true)
		swap = true;


	return swap;

}



bool CGameView::SortActual(CPlayer m_actual_i, CPlayer m_actual_j)
{
	bool swap = false;

	switch (m_column)
	{



	case 0:

		swap = m_actual_i.m_original_number > m_actual_j.m_original_number;
		//		swap = m_actual_i.GetPos() < m_actual_j.GetPos();
		break;
	case 1:
		swap = m_actual_i.GetName() > m_actual_j.GetName();
		break;
	case 2:
		swap = m_actual_i.GetGames() < m_actual_j.GetGames();
		break;
	case 3:
		swap = m_actual_i.GetMinPerGame() < m_actual_j.GetMinPerGame();
		break;
	case 4:
		swap = m_actual_i.GetFgm() < m_actual_j.GetFgm();
		break;
	case 5:
		swap = m_actual_i.GetFga() < m_actual_j.GetFga();
		break;
	case 6:
		swap = m_actual_i.GetFgPct() < m_actual_j.GetFgPct();
		break;
	case 7:
		swap = m_actual_i.GetFtm() < m_actual_j.GetFtm();
		break;
	case 8:
		swap = m_actual_i.GetFta() < m_actual_j.GetFta();
		break;
	case 9:
		swap = m_actual_i.GetFtPct() < m_actual_j.GetFtPct();
		break;
	case 10:
		swap = m_actual_i.GetTfgm() < m_actual_j.GetTfgm();
		break;
	case 11:
		swap = m_actual_i.GetTfga() < m_actual_j.GetTfga();
		break;
	case 12:
		swap = m_actual_i.GetTfgPct() < m_actual_j.GetTfgPct();
		break;
	case 13:
		swap = m_actual_i.GetOrebPerGame() < m_actual_j.GetOrebPerGame();
		break;
	case 14:
		swap = m_actual_i.GetReboundsPerGame() < m_actual_j.GetReboundsPerGame();
		break;
	case 15:
		swap = m_actual_i.GetAssistsPerGame() < m_actual_j.GetAssistsPerGame();
		break;
	case 16:
		swap = m_actual_i.GetStealsPerGame() < m_actual_j.GetStealsPerGame();
		break;
	case 17:
		swap = m_actual_i.GetToPerGame() < m_actual_j.GetToPerGame();
		break;
	case 18:
		swap = m_actual_i.GetBlocksPerGame() < m_actual_j.GetBlocksPerGame();
		break;
	case 19:
		swap = m_actual_i.GetPf() < m_actual_j.GetPf();
		break;
	case 20:
		swap = m_actual_i.GetPointsPerGame() < m_actual_j.GetPointsPerGame();
		break;
	case 21:
		swap = m_actual_i.GetInjury() < m_actual_j.GetInjury();
		break;
	case 22:
		break;

	}

	return swap;
}

bool CGameView::SortRatings(CPlayer m_actual_i, CPlayer m_actual_j)
{
	bool swap = false;

	switch (m_column)
	{



	case 0:

		swap = m_actual_i.m_original_number > m_actual_j.m_original_number;
		//		swap = m_actual_i.GetPos() < m_actual_j.GetPos();
		break;
	case 1:

		swap = m_actual_i.GetName() > m_actual_j.GetName();
		break;
	case 2:
		swap = m_actual_i.GetAdjPrFga() < m_actual_j.GetAdjPrFga();
		break;
	case 3:
		swap = m_actual_i.GetAdjPrFgp() < m_actual_j.GetAdjPrFgp();
		break;
	case 4:
		swap = m_actual_i.GetAdjPrFta() < m_actual_j.GetAdjPrFta();
		break;
	case 5:
		swap = m_actual_i.GetAdjPrFtp() < m_actual_j.GetAdjPrFtp();
		break;
	case 6:
		swap = m_actual_i.GetAdjPrTga() < m_actual_j.GetAdjPrTga();

		break;
	case 7:
		swap = m_actual_i.GetAdjPrTgp() < m_actual_j.GetAdjPrTgp();
		break;
	case 8:
		swap = m_actual_i.GetAdjPrOrb() < m_actual_j.GetAdjPrOrb();
		break;
	case 9:
		swap = m_actual_i.GetAdjPrDrb() < m_actual_j.GetAdjPrDrb();
		break;
	case 10:
		swap = m_actual_i.GetAdjPrAst() < m_actual_j.GetAdjPrAst();
		break;
	case 11:
		swap = m_actual_i.GetAdjPrStl() < m_actual_j.GetAdjPrStl();
		break;
	case 12:
		swap = m_actual_i.GetAdjPrTo() < m_actual_j.GetAdjPrTo();
		break;
	case 13:
		swap = m_actual_i.GetAdjPrBlk() < m_actual_j.GetAdjPrBlk();
		break;
	case 14:
		swap = m_actual_i.GetMovOff() < m_actual_j.GetMovOff();
		break;
	case 15:
		swap = m_actual_i.GetPenOff() < m_actual_j.GetPenOff();
		break;
	case 16:
		swap = m_actual_i.GetPostOff() < m_actual_j.GetPostOff();
		break;
	case 17:
		swap = m_actual_i.GetTransOff() < m_actual_j.GetTransOff();
		break;
	case 18:
		swap = m_actual_i.GetMovDef() < m_actual_j.GetMovDef();
		break;
	case 19:
		swap = m_actual_i.GetPenDef() < m_actual_j.GetPenDef();
		break;
	case 20:
		swap = m_actual_i.GetPostDef() < m_actual_j.GetPostDef();
		break;
	case 21:
		swap = m_actual_i.GetTransDef() < m_actual_j.GetTransDef();
		break;
	case 22:
		swap = m_actual_i.GetAdjPot1() < m_actual_j.GetAdjPot1();
		break;
	case 23:
		swap = m_actual_i.GetAdjPot2() < m_actual_j.GetAdjPot2();
		break;
	case 24:
		swap = m_actual_i.GetAdjEffort() < m_actual_j.GetAdjEffort();
		break;

	}


	return swap;

}

bool CGameView::SortFunction(CPlayer m_player, CPlayer temp)
{
	bool swap = false;
	if (m_column >= 0 && m_category == 4) swap = SortPlayoffStats(m_player, temp);
	else if (m_column >= 0 && m_category == 1) swap = SortStats(m_player, temp);
	else if (m_column >= 0 && m_category == 2) swap = SortActual(m_player, temp);
	else if (m_column >= 0 && m_category == 3) swap = SortRatings(m_player, temp);
	else if (m_column >= 0 && m_category == 5) swap = SortContracts(m_player, temp);
	return swap;
}

void CGameView::ChooseStatsToList()
{
	if (m_category == 1)
		ListSimulatedStats();
	else if (m_category == 2)
		ListStats();
	else if (m_category == 3)
		ListRatings();
	else if (m_category == 4)
		ListPlayoffStats();
	else if (m_category == 5)
		ListContracts();
}

void CGameView::SetSeasonAverages()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	for (int i = 0; i <= 1600; i++)
	{
		avg.m_actual[i].SetSeasonAverages();
	}



}

void CGameView::OnRadioHigh()
{
	// TODO: Add your control notification handler code here
	if (m_switch_sort == true)
	{
		m_switch_sort = false;
		OnSelchangeComboTeamNames();
		QuickSort();
	}
}

void CGameView::OnRadioLow()
{
	// TODO: Add your control notification handler code here
	if (m_switch_sort == false)
	{
		m_switch_sort = true;
		//		OnSelchangeListTeams();
		OnSelchangeComboTeamNames();
		QuickSort();
	}
}

void CGameView::SetAdjustedRatings()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	bool scout_found = false;
	CStaff defaultscout;

	int single_scout = -1;
	if (avg.m_settings.m_scouts[32] == 0)//scouts on
	{
		for (int i = 0; i <= 31; i++)
		{
			if (avg.m_settings.m_scouts[i] == 1)
			{
				single_scout = i;
				defaultscout = avg.m_scout[i];
				scout_found = true;
			}
		}
	}
	else
	{
		scout_found = true;//super scout
	}


	CPlayer m_player;
	for (int i = 1; i <= 1600; i++)
	{
		m_player = avg.m_actual[i];


		CStaff scout;
		int team = m_player.m_team_index;
		if (team > 0 && scout_found == false)
			scout = avg.m_scout[team - 1];
		else
			scout = defaultscout;

		m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
		m_player.SetAdjustedRatings(scout);

		//CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};

		avg.m_actual[i] = m_player;
	}
}

void CGameView::OnRadioPlayoffs()
{
	// TODO: Add your control notification handler code here
	if (m_changeHeading >= 2)
	{
		m_changeHeading = 1;
		SetColumnHeaders();
	}
	if (m_category != 4)
	{
		m_category = 4;
		ListPlayoffStats();
	}
}

void CGameView::OnRadioPg()
{
	// TODO: Add your control notification handler code here
	m_position = "PG";
	//  OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();
}

void CGameView::OnRadioPf()
{
	// TODO: Add your control notification handler code here
	m_position = "PF";
	//	OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();
}

void CGameView::OnRadioSf()
{
	// TODO: Add your control notification handler code here
	m_position = "SF";
	//	OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();

}

void CGameView::OnRadioSg()
{
	// TODO: Add your control notification handler code here
	m_position = "SG";
	//	OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();

}

void CGameView::OnRadioC()
{
	// TODO: Add your control notification handler code here
	m_position = " C";
	//	OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();

}

void CGameView::OnRadioAll()
{
	// TODO: Add your control notification handler code here
	m_position = "";
	//	OnSelchangeListTeams();	
	OnSelchangeComboTeamNames();
}

void CGameView::InitListCtrl()
{
	//LOGFONT lf;                        // Used to create the CFont.
	//memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	//lf.lfWeight = 100;
	//lf.lfHeight = 12;
	////lf.lfWidth = 24;
	//strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	////strcpy_s(lf.lfFaceName, "TAHOMA");    //    with face name "Arial".

	//m_font.CreateFontIndirect(&lf);    // Create the font.


	//	m_button_tools.SetWindowTextA("TEST");

	m_list_stats.SetFont(&m_font);


}

void CGameView::OnDblclkListControlStats(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int i = m_list_stats.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (i >= 0)
	{

		int pointer = m_player_pointer[i];
		CPlayer m_player = avg.m_actual[pointer];
		int tm = m_player.m_team_index - 1;

		CString team = "";
		if (tm < 0) team = "";
		else team = avg.m_settings.m_leagueTeamNames[tm];


		CPlayerCardDlg* scout = new CPlayerCardDlg;

		scout->m_default_scout = pDoc->m_combo_team_index;

		scout->m_path = avg.m_settings.m_path;
		scout->m_leagueName = avg.m_settings.m_league_name;

		scout->m_title = "Scout";
		scout->avg = avg;

		int players_listed = m_list_stats.GetItemCount();

		for (int c = 0; c <= players_listed; c++)
		{
			scout->avg.m_actual[c] = avg.m_actual[m_player_pointer[c]];
		}
		scout->m_player_index = i;
		scout->m_pl_index_end = players_listed;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;
	}
	*pResult = 0;

}

void CGameView::BuildString(CString s[], int co, int columns)
{
	if (co <= 1600)
	{
		CMyString* my = new CMyString;
		//	m_print_strings[co] = my->SetPrintString(s, columns);
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[co][j] = s[j];
		}
		delete my;
	}
}


void CGameView::InitHeadings()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	m_column_headers[0][0] = "po";
	m_column_headers[0][1] = "name";
	m_column_headers[0][2] = "g";
	m_column_headers[0][3] = "min";
	m_column_headers[0][4] = "fgm";
	m_column_headers[0][5] = "fga";
	m_column_headers[0][6] = "fgp";
	m_column_headers[0][7] = "ftm";
	m_column_headers[0][8] = "fta";
	m_column_headers[0][9] = "ftp";
	m_column_headers[0][10] = "tgm";
	m_column_headers[0][11] = "tga";
	m_column_headers[0][12] = "tgp";
	m_column_headers[0][13] = "orb";
	m_column_headers[0][14] = "reb";
	m_column_headers[0][15] = "ast";
	m_column_headers[0][16] = "stl";
	m_column_headers[0][17] = "to";
	m_column_headers[0][18] = "blk";
	m_column_headers[0][19] = "pf";
	m_column_headers[0][20] = "ppg";
	m_column_headers[0][21] = "inj";

	m_column_headers[1][0] = "po";
	m_column_headers[1][1] = "name";
	m_column_headers[1][2] = "2ga";
	m_column_headers[1][3] = "2%";
	m_column_headers[1][4] = "fta";
	m_column_headers[1][5] = "ft%";
	m_column_headers[1][6] = "3ga";
	m_column_headers[1][7] = "3%";
	m_column_headers[1][8] = "orb";
	m_column_headers[1][9] = "drb";
	m_column_headers[1][10] = "ast";
	m_column_headers[1][11] = "stl";
	m_column_headers[1][12] = "to";
	m_column_headers[1][13] = "blk";
	m_column_headers[1][14] = "oo";
	m_column_headers[1][15] = "do";
	m_column_headers[1][16] = "po";
	m_column_headers[1][17] = "to";
	m_column_headers[1][18] = "od";
	m_column_headers[1][19] = "dd";
	m_column_headers[1][20] = "pd";
	m_column_headers[1][21] = "td";
	m_column_headers[1][22] = "ta";
	m_column_headers[1][23] = "sk";
	m_column_headers[1][24] = "in";


	m_column_headers[2][0] = "po";
	m_column_headers[2][1] = "name";
	m_column_headers[2][2] = "age";
	m_column_headers[2][3] = "exp";
	m_column_headers[2][4] = "ht";
	m_column_headers[2][5] = "wt";
	CString head;
	int off = 6;
	for (int y = avg.m_settings.m_currentYear; y <= avg.m_settings.m_currentYear + 5; y++)
	{
		head.Format("%d", y);
		m_column_headers[2][off] = head;
		off = off + 1;
	}


	//CSxLogFont Arial10b(80,FW_NORMAL,false,"Arial");










	m_list_stats.SetBkColor(BK_COLOR);
	m_list_stats.SetTextBkColor(TEXT_BK_COLOR);
	m_list_stats.SetTextColor(RGB(0, 0, 0));

	//	m_list_stats.SetFont(&m_font);
	m_list_stats.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);





}



void CGameView::OnSelchangeComboTeamNames()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int index = m_listTeams.GetCurSel();
	m_currentTeam = index;
	if (index < 1)
		m_teamWL = "";
	else
	{
		int rec_win = avg.m_standings[index - 1].m_leagueRecord / 100;
		int rec_loss = avg.m_standings[index - 1].m_leagueRecord - rec_win * 100;
		m_teamWL.Format("%d-%d", rec_win, rec_loss);
	}
	UpdateData(FALSE);
	ChooseStatsToList();

}

BOOL CGameView::InitImageList()
{
	/*	HIMAGELIST hList = ImageList_Create(16,16,ILC_COLOR8 | ILC_MASK, 8, 1);
		m_cImageListSmall.Attach(hList);

		CBitmap cBmp;
		cBmp.LoadBitmap(IDB_IMAGES_SMALL);
		m_cImageListSmall.Add(&cBmp, RGB(255, 0, 255));
		cBmp.DeleteObject();

		m_list_stats.SetImageList(&m_cImageListSmall, LVSIL_SMALL);*/

	return TRUE;
}

void CGameView::OnRadioContracts()
{
	// TODO: Add your control notification handler code here
	if (m_changeHeading != 3)
	{
		m_changeHeading = 3;
		SetContractHeaders();
	}
	if (m_category != 5)
	{
		m_category = 5;
		ListContracts();
	}

}

void CGameView::ListContracts()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	m_list_stats.DeleteAllItems();
	int co = 0;
	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for (int index = 0; index <= 1600; index++)
	{
		m_player_pointer[index] = 0;
		int i = index;
		if (m_switch_sort == true) i = 1600 - index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		int pointer = m_player.m_original_number;
		//		if(Name == "" || pointer > 1440) continue;
		if (pointer >= 1441 && pointer <= 1472) Name = avg.m_settings.m_leagueTeamNames[pointer - 1441];
		if (Name == "") continue;
		int team = m_player.m_team_index;

		if (m_main_category == 1 && team != m_currentTeam && m_currentTeam > 0 && (m_currentTeam + 1440) != pointer) continue;
		if (m_main_category == 1 && m_currentTeam == 0 && pointer > 1440 && pointer <= 1504) continue;

		bool skip = false;

		if (m_main_category >= 2 && pointer >= 1441 && pointer <= 1472 && (m_currentTeam == 0 || (m_currentTeam + 1440) == pointer)) skip = false;
		else if (m_main_category >= 2) skip = true;

		if (m_main_category == 1 && m_rookie_view == true && m_player.m_yrs_of_service > 1) continue;

		if (skip == true) continue;


		Stats[0] = m_player.GetPos();
		Stats[1] = Name;

		if (Stats[0] != "" && m_position != "" && Stats[0] != m_position) continue;
		else if (m_position != "" && pointer > 1440) continue;

		CString ag, ex, ht, wt;


		int height = m_player.m_height;
		int ft = height / 12;
		int in = height - ft * 12;

		int weight = m_player.m_weight;



		if (pointer <= 1440 || pointer > 1504)
		{
			ht.Format("%d' %d", ft, in);
			wt.Format("%d", weight);
			ag.Format("%d", m_player.m_age);
			ex.Format("%d", m_player.m_yrs_of_service);
		}
		else
		{
			ft = height / 120;
			in = height - ft * 120;
			ht.Format("%d' %.1f", ft, (double)in / 10);
			wt.Format("%.1f", (double)weight / 10);
			ag.Format("%.1f", (double)m_player.m_age / 10);
			ex.Format("%.1f", (double)m_player.m_yrs_of_service / 10);
		}

		Stats[2] = ag;
		Stats[3] = ex;
		if (ex == "0" && pointer <= 1440) ex = "R";


		Stats[4] = ht;
		Stats[5] = wt;

		int cur = m_player.m_current_contract_yr;
		int c_yr = 6;
		for (int s = cur; s <= 6; s++)
		{
			int r = m_player.m_contract_salaries[s];
			if (r == 0)
			{
				Stats[c_yr] = "";
			}
			else
			{
				Stats[c_yr].Format("%.2f", (double)r / 100);
			}
			c_yr = c_yr + 1;
		}



		m_list_stats.InsertItem(co, Stats[0]);
		for (int s = 0; s <= 12; s++)
		{
			if (Stats[s + 1] == "") continue;
			m_list_stats.SetItemText(co, s + 1, Stats[s + 1]);
		}
		m_player_pointer[co] = i;
		BuildString(Stats, co, 33);
		co = co + 1;
	}
	m_co = co;

}

bool CGameView::SortContracts(CPlayer m_actual_i, CPlayer m_actual_j)
{
	bool swap = false;
	int r_i[7] = { 0,0,0,0,0,0,0 };
	int r_j[7] = { 0,0,0,0,0,0,0 };


	int cur_i = m_actual_i.m_current_contract_yr;
	int cur_j = m_actual_j.m_current_contract_yr;
	int count = 0;
	for (int s = cur_i; s <= 6; s++)
	{
		r_i[count] = m_actual_i.m_contract_salaries[s];
		count = count + 1;
	}

	count = 0;
	for (int s = cur_j; s <= 6; s++)
	{
		r_j[count] = m_actual_j.m_contract_salaries[s];
		count = count + 1;
	}



	switch (m_column)
	{



	case 0:

		swap = m_actual_i.m_original_number > m_actual_j.m_original_number;
		//		swap = m_actual_i.GetPos() < m_actual_j.GetPos();
		break;
	case 1:
		swap = m_actual_i.GetName() > m_actual_j.GetName();
		break;
	case 2:
		swap = m_actual_i.m_age < m_actual_j.m_age;
		break;
	case 3:
		swap = m_actual_i.m_yrs_of_service < m_actual_j.m_yrs_of_service;
		break;
	case 4:
		swap = m_actual_i.m_height < m_actual_j.m_height;
		break;
	case 5:
		swap = m_actual_i.m_weight < m_actual_j.m_weight;
		break;
	case 6:
		swap = r_i[0] < r_j[0];
		break;
	case 7:
		swap = r_i[1] < r_j[1];
		break;
	case 8:
		swap = r_i[2] < r_j[2];
		break;
	case 9:
		swap = r_i[3] < r_j[3];
		break;
	case 10:
		swap = r_i[4] < r_j[4];
		break;
	case 11:
		swap = r_i[5] < r_j[5];
		break;

	}




	//insure that team stats always ranked below player stats
	if (m_actual_i.m_original_number >= 1441 && m_actual_j.m_original_number <= 1440 && m_switch_sort == false)
		swap = true;
	else if (m_actual_j.m_original_number >= 1441 && m_actual_i.m_original_number <= 1440 && m_switch_sort == false)
		swap = false;
	else if (m_actual_i.m_original_number >= 1441 && m_actual_j.m_original_number <= 1440 && m_switch_sort == true)
		swap = false;
	else if (m_actual_j.m_original_number >= 1441 && m_actual_i.m_original_number <= 1440 && m_switch_sort == true)
		swap = true;



	return swap;
}

void CGameView::SetContractHeaders()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	m_list_stats.DeleteAllItems();
	CString head;

	m_list_stats.DeleteColumn(0);
	m_list_stats.InsertColumn(0, "po");

	m_list_stats.DeleteColumn(1);
	m_list_stats.InsertColumn(1, "name");

	m_list_stats.DeleteColumn(2);
	m_list_stats.InsertColumn(2, "age");

	m_list_stats.DeleteColumn(3);
	m_list_stats.InsertColumn(3, "exp");

	m_list_stats.DeleteColumn(4);
	m_list_stats.InsertColumn(4, "ht");

	m_list_stats.DeleteColumn(5);
	m_list_stats.InsertColumn(5, "wt");


	m_list_stats.DeleteColumn(6);
	head.Format("%d", avg.m_settings.m_currentYear);
	m_list_stats.InsertColumn(6, head);

	m_list_stats.DeleteColumn(7);
	head.Format("%d", avg.m_settings.m_currentYear + 1);
	m_list_stats.InsertColumn(7, head);

	m_list_stats.DeleteColumn(8);
	head.Format("%d", avg.m_settings.m_currentYear + 2);
	m_list_stats.InsertColumn(8, head);

	m_list_stats.DeleteColumn(9);
	head.Format("%d", avg.m_settings.m_currentYear + 3);
	m_list_stats.InsertColumn(9, head);

	m_list_stats.DeleteColumn(10);
	head.Format("%d", avg.m_settings.m_currentYear + 4);
	m_list_stats.InsertColumn(10, head);

	m_list_stats.DeleteColumn(11);
	head.Format("%d", avg.m_settings.m_currentYear + 5);
	m_list_stats.InsertColumn(11, head);




	m_list_stats.SetColumnWidth(0, 24);
	m_list_stats.SetColumnWidth(1, 90);
	m_list_stats.SetColumnWidth(2, 48);
	m_list_stats.SetColumnWidth(3, 48);
	m_list_stats.SetColumnWidth(4, 48);
	m_list_stats.SetColumnWidth(5, 48);
	m_list_stats.SetColumnWidth(6, 48);
	m_list_stats.SetColumnWidth(7, 48);
	m_list_stats.SetColumnWidth(8, 48);
	m_list_stats.SetColumnWidth(9, 48);
	m_list_stats.SetColumnWidth(10, 48);
	m_list_stats.SetColumnWidth(11, 48);

	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);

	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);

	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);

	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);

	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
	m_list_stats.DeleteColumn(12);
}

void CGameView::CalculateCurrentPayroll()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	avg.CalculateCurrentPayroll(m_off_season);

}

void CGameView::OnButtonHtml()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CString headers[27];
	CString label = " Season Stats";
	if (m_category == 2) label = " Actual Stats";
	else if (m_category == 3) label = " Ratings";
	else if (m_category == 4) label = " Playoff Stats";
	else if (m_category == 5) label = " Contracts";


	for (int j = 0; j <= 26; j++)
	{
		int col = j;
		if (m_main_category != 2 && j == 2) headers[col] = "Team";
		else
		{

			if (m_main_category != 2 && j > 2)
				col = j - 1;

			if (m_category <= 2)
				headers[j] = m_column_headers[0][col];
			else if (m_category == 3)
				headers[j] = m_column_headers[1][col];
			else if (m_category == 4)
				headers[j] = m_column_headers[0][col];
			else if (m_category == 5)
				headers[j] = m_column_headers[2][col];

		}

	}


	CHtmlMsc* html = new CHtmlMsc;

	CString team_name, html_string;


	for (int i = 0; i <= 1600; i++)
	{
		for (int j = 0; j <= 26; j++)
		{

			int col = j;

			if (m_main_category != 2 && j > 2) col = j - 1;

			html_string = m_print_strings[i][col];



			int pointer = m_player_pointer[i];
			int team_index = avg.m_actual[pointer].m_team_index - 1;
			if (team_index >= 0) team_name = avg.m_settings.m_leagueTeamNames[team_index]; else team_name = "-";


			if (m_main_category != 2 && j == 2)
				html_string = team_name;


			if (col <= 21 && html_string == "")
				html_string = "-";
			html->m_strings[i][j] = html_string;
			if (i == 0) html->m_headers[col] = headers[col];
		}
	}
	html->m_path = avg.m_settings.m_path;
	html->m_league_name = avg.m_settings.m_league_name;
	html->m_label = label;
	int items = m_list_stats.GetItemCount();
	if (m_main_category != 2) items = items + 1;
	if (items < 0) items = 0;
	html->m_items = items;
	html->DoModal();
	delete html;

}

void CGameView::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO: Add your message handler code here	

}

void CGameView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CGameView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

void CGameView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

/*void CGameView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
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


void CGameView::OnButtonAwards()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here



	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CString award_file = avg.m_settings.m_path + avg.m_settings.m_league_name;



	CAwards* aw = new CAwards;
	//		aw->m_save = false;
	aw->avg = avg;
	aw->m_current_year = avg.m_settings.m_currentYear;
	aw->ChooseRings(award_file);
	aw->ChooseAwards();
	//		aw->SaveAwards(award_file);
	//		aw->WriteAwardHistoryFile(award_file);


	int mvp[11], sth[11], defense[11], rookie[11];
	int pts[11], reb[11], ast[11], stl[11], blk[11];
	int all_league[6][4], all_defense[6][4], all_rookie[6][4];
	int po_mvp = aw->m_po_mvp;
	for (int i = 0; i <= 10; i++)
	{
		mvp[i] = aw->m_mvp[i];
		sth[i] = aw->m_6th[i];
		defense[i] = aw->m_defense[i];
		rookie[i] = aw->m_rookie[i];
		pts[i] = aw->m_pts[i];
		reb[i] = aw->m_reb[i];
		ast[i] = aw->m_ast[i];
		stl[i] = aw->m_stl[i];
		blk[i] = aw->m_blk[i];
	}
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			all_league[i][j] = aw->m_all_league[i][j];
			all_defense[i][j] = aw->m_all_defense[i][j];
			all_rookie[i][j] = aw->m_all_rookie[i][j];
		}
	}
	delete aw;

	CAwardsDlg* award = new CAwardsDlg;
	award->m_po_mvp = po_mvp;
	award->m_path = avg.m_settings.m_path;
	award->m_league_name = avg.m_settings.m_league_name;
	for (int i = 0; i <= 10; i++)
	{
		award->m_mvp[i] = mvp[i];
		award->m_6th[i] = sth[i];
		award->m_defense[i] = defense[i];
		award->m_rookie[i] = rookie[i];
		award->m_pts[i] = pts[i];
		award->m_reb[i] = reb[i];
		award->m_ast[i] = ast[i];
		award->m_stl[i] = stl[i];
		award->m_blk[i] = blk[i];
	}

	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			award->m_all_league[i][j] = all_league[i][j];
			award->m_all_defense[i][j] = all_defense[i][j];
			award->m_all_rookie[i][j] = all_rookie[i][j];
		}
	}

	award->avg = avg;
	award->DoModal();
	delete award;


}

void CGameView::OnButtonLeaders()
{

	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CLeadersDlg* leadersDlg = new CLeadersDlg;
	leadersDlg->avg = pDoc->avg;
	//	for(int i=0; i<=480; i++)
	//	{
	//		leadersDlg->m_actual[i] = avg.m_actual[i];
	//	}
	for (int i = 0; i <= 32; i++)
	{
		leadersDlg->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
	}

	leadersDlg->m_path = avg.m_settings.m_path;
	leadersDlg->m_leagueName = avg.m_settings.m_league_name;
	leadersDlg->m_statType = PLAYERS;
	leadersDlg->m_statStyle = SIMULATED;
	leadersDlg->m_hiGames = avg.m_hi_g[0];
	leadersDlg->m_checkCareer = avg.m_settings.m_checkCareer;

	if (pDoc->m_game_type == PLAYOFF) leadersDlg->m_statStyle = PLAYOFF;

	int result = leadersDlg->DoModal();
	delete leadersDlg;

}

void CGameView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CGameView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CGameView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CGameView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

HBRUSH CGameView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	/*if (pWnd->GetDlgCtrlID() == IDC_STATIC_G1);
	{
		pDC->SetTextColor(RGB(255,0,0));
		return hbr;
	}*/
	//m_button_schedule.SetButtonFontSize(4);


	// TODO: Change any attributes of the DC here
	switch (nCtlColor)
	{
		//Edit controls need white background and black text
		//Note the 'return hbr' which is needed to draw the Edit
		//control's internal background (as opposed to text background)
	case WM_CTLCOLORBTN:
		pDC->SetTextColor(RGB(192,192,192));
		pDC->SetBkColor(RGB(64,64,64));
		return hbr;
	case CTLCOLOR_EDIT:
		pDC->SetTextColor(EDITCOLOR);
		pDC->SetBkColor(EDITBKCOLOR);
		return hbr;
		//Static controls need black text and same background as myBrush
	case CTLCOLOR_STATIC:
		LOGBRUSH logbrush;
		myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(WHITE);
		pDC->SetBkColor(BLACK);
		return hbr;
	case WM_CTLCOLORSTATIC:
		myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(WHITE);
		pDC->SetBkColor(BLACK);
		return hbr;
	case CTLCOLOR_BTN:
		//          pDC->SetTextColor(RGB(0,255,255));
		  //        pDC->SetBkColor(RGB(255,128,128));
		return hbr;
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




void CGameView::OnCheckRookies()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	if (m_rookie_view == false)
	{
		m_rookie_view = true;
		m_check_rookies.SetWindowText("Rookies Only: On");
	}
	else
	{
		m_check_rookies.SetWindowText("Rookies Only: Off");
		m_rookie_view = false;
	}

	OnSelchangeComboTeamNames();

}



void CGameView::OnTeamRoster()
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

}

void CGameView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CGameView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}













void CGameView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CGameView::OnEditCopy()
{
	// TODO: Add your command handler code here

}

void CGameView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CGameView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}


BOOL CGameView::OnEraseBkgnd(CDC* pDC)
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

//	bitmapBkgnd.Detach();
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




					//return CView::OnEraseBkgnd(pDC);


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




void CGameView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rc;

	/*CWnd* pW = this->GetDlgItem(IDC_STATIC_G1);
	pW->GetClientRect(&rc);
	pW->ClientToScreen(&rc);
	this->ScreenToClient(&rc);

	dc.FillSolidRect(&rc, RGB(255, 0, 0));*/


	// TODO: Add your message handler code here

//	Graphics graphics(dc.m_hDC);
//	CString image = "stats.jpg";
//	CString image = "coach.jpg";
//	Bitmap bitmap(image.AllocSysString());
//	graphics.DrawImage(&bitmap, 1, 1);
//	graphics.ReleaseHDC(dc.m_hDC);

	// Do not call CFormView::OnPaint() for painting messages
}


void CGameView::OnItemclickListControlStats(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	m_column = phdr->iItem;
	QuickSort();
	m_row = 0;
	m_list_stats.SetItemState(m_row, LVIS_SELECTED, LVIS_SELECTED);
	m_list_stats.EnsureVisible(m_row, TRUE);


	*pResult = 0;
}


//void CGameView::OnBnClickedStaticG1()
//{
	// TODO: Add your control notification handler code here
//}
