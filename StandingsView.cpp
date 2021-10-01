// StandingsView.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"

#include "MyComboBox.h"

#include "StandingsView.h"
#include "BBallDoc.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStandingsView

IMPLEMENT_DYNCREATE(CStandingsView, CFormView)

CStandingsView::CStandingsView()
	: CFormView(CStandingsView::IDD)
{

	//m_bmp = new CBitmap;
	//m_bmp->LoadBitmap(IDB_BITMAPSCREEN);
	//m_bmp->SetBitmapDimension(182, 240); /* if the size of bitmap is 50 by 40 */
	//m_bmp->SetBitmapDimension(1680, 1050); /* if the size of bitmap is 50 by 40 */
	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */




	//{{AFX_DATA_INIT(CStandingsView)
	//}}AFX_DATA_INIT

//bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
//                    MAKEINTRESOURCE(IDB_BITMAP_BK)));





//bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
//			"Test.bmp"));

	m_default_team = 0;
	m_standings_default_team = 0;

	//	RECORD record;
}

CStandingsView::~CStandingsView()
{
	delete m_bmp;
}

void CStandingsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStandingsView)
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button_print);
	DDX_Control(pDX, IDC_LIST_CTRL_VS_OPP, m_listVsOpponents);
	DDX_Control(pDX, IDC_LIST_CTRL_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_LIST_CHOICES, m_listChoices);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_STATIC_G3, g3);
	DDX_Control(pDX, IDC_STATIC_G2, g2);
	DDX_Control(pDX, IDC_STATIC_G1, g1);

}


BEGIN_MESSAGE_MAP(CStandingsView, CFormView)
	//{{AFX_MSG_MAP(CStandingsView)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_LBN_SELCHANGE(IDC_LIST_CHOICES, OnSelchangeListChoices)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_LBN_DBLCLK(IDC_LIST_CHOICES, OnDblclkListChoices)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_TEAMS, OnDblclkListCtrlTeams)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_TEAMS, OnClickListCtrlTeams)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_TEAM_ROSTER, OnTeamRoster)
	ON_COMMAND(ID_TEAM_BUDGET, OnTeamBudget)
	ON_COMMAND(ID_TEAM_DRAFTPREVIEW, OnTeamDraftpreview)
	ON_COMMAND(ID_TEAM_FREEAGENTS, OnTeamFreeagents)
	ON_COMMAND(ID_TEAM_HISTORY, OnTeamHistory)
	ON_COMMAND(ID_TEAM_LINEUP, OnTeamLineup)
	ON_COMMAND(ID_TEAM_RECORDS, OnTeamRecords)
	ON_COMMAND(ID_TEAM_RESULTS, OnTeamResults)
	ON_COMMAND(ID_TEAM_STAFF, OnTeamStaff)
	ON_COMMAND(ID_TEAM_TRADE, OnTeamTrade)
	ON_COMMAND(ID_TEAM_TRANSACTIONS, OnTeamTransactions)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_PLAYERS, OnEditPlayers)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_WM_MOVE()
	ON_WM_PAINT()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStandingsView diagnostics

#ifdef _DEBUG
void CStandingsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStandingsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStandingsView message handlers

void CStandingsView::OnInitialUpdate()
{
	// TODO: Add your specialized code here and/or call the base class
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();



	COLORREF	crBtnColor;

	// Calculate a color effect for hilighting the button
	crBtnColor = ::GetSysColor(COLOR_BTNFACE) + RGB(30, 30, 30);


	myBrush.CreateSolidBrush(DLGCOLOR);
	//CBrush m_tbrush;
	m_tbrush.CreateSolidBrush(LISTBOXCOLOR);
	SetWindowText(pDoc->avg.m_settings.m_league_name + " Standings");

	//	LOGFONT lf;                        // Used to create the CFont.
	//	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	//	lf.lfWeight = 100;
	//	lf.lfHeight = 12;
	//	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	//	m_font1.CreateFontIndirect(&lf);    // Create the font.


								// Used to create the CFont.
	//	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	//	lf.lfWeight = 500;
	//	lf.lfHeight = 14;
	//	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".

	//		strcpy_s(lf.lfFaceName, "Courier New");    //    with face name "Arial".

	//	m_font.CreateFontIndirect(&lf);    // Create the font.







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

BOOL CStandingsView::SetToDoc()
{

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    





	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;


	UpdateData(FALSE);    // Set controls to these
}

void CStandingsView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	if (bShow == TRUE)
	{
		InitView();
	}
}

void CStandingsView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(0);


}

void CStandingsView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here

	((CBBallApp*)AfxGetApp())->SwitchView(1);
	//	RedrawWindow( ); 	


}

void CStandingsView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(4);

}

void CStandingsView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}




void CStandingsView::OnSelchangeListChoices()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	if (m_listChoices.GetCurSel() >= 0)
	{
		m_selection_row = 0;


		m_listTeams.DeleteAllItems();
		//m_listChoices.ResetContent();
		CString choice;
		m_listChoices.GetText(m_listChoices.GetCurSel(), choice);

		//	RECORD temp[33];
		BOOL swap = FALSE;
		for (int t = 0; t <= 31; t++)
		{
			CString divisionOfTeam = standing[t].m_division + " Division";
			CString conferenceOfTeam = standing[t].m_conference + " Conference";
			if (standing[t].m_leagueTeamNames == "") continue;
			if (divisionOfTeam == choice || conferenceOfTeam == choice)
			{
				for (int j = 0; j <= 31; j++)
				{
					swap = FALSE;
					if (standing[j].m_leagueTeamNames == "") continue;
					CString divisionOfTeam = standing[j].m_division + " Division";
					CString conferenceOfTeam = standing[j].m_conference + " Conference";
					if (divisionOfTeam == choice || conferenceOfTeam == choice)
					{
						if (standing[j].m_leaguePct < standing[t].m_leaguePct) swap = TRUE;
						else if (standing[j].m_leaguePct == standing[t].m_leaguePct)
						{
							if (standing[j].m_leagueGamesBack < standing[t].m_leagueGamesBack) swap = TRUE;
							else if (standing[j].m_leagueGamesBack == standing[t].m_leagueGamesBack)
							{
								if (divisionOfTeam == choice)//division tiebreakers
								{
									if (standing[j].m_divisionPct < standing[t].m_divisionPct) swap = TRUE;
									else if (standing[j].m_divisionPct == standing[t].m_divisionPct)
									{
										if (standing[j].m_conferencePct < standing[t].m_conferencePct) swap = TRUE;
									}
								}
								if (conferenceOfTeam == choice)//conference tiebreakers
								{
									if (standing[j].m_conferencePct < standing[t].m_conferencePct) swap = TRUE;
								}
							}

						}
						if (swap == TRUE)
						{
							swap = FALSE;
							CRecord temp = standing[t];
							standing[t] = standing[j];
							standing[j] = temp;
						}
					}
				}
			}
		}
		BOOL FirstPlace = TRUE;
		double gb = 0;
		int FirstPlaceWin = 0;
		int FirstPlaceLoss = 0;
		int row = 0;
		for (int t = 0; t <= 31; t++)
		{
			m_strings[t] = "";
			CString divisionOfTeam = standing[t].m_division + " Division";
			CString conferenceOfTeam = standing[t].m_conference + " Conference";
			if (divisionOfTeam == choice || conferenceOfTeam == choice)
			{
				CString result;
				CString leagueWin;
				CString leagueLoss;
				CString gamesBack;
				CString leaguePct;
				CString divisionWin;
				CString divisionLoss;
				CString conferenceWin;
				CString conferenceLoss;
				CString homeWin;
				CString homeLoss;
				CString visitorWin;
				CString visitorLoss;
				int w = standing[t].m_leagueRecord / 100;
				int l = standing[t].m_leagueRecord - w * 100;
				if (t < pDoc->avg.m_settings.m_numberteams)//break 2 team ties with head to head results
				{
					int wn = standing[t + 1].m_leagueRecord / 100;
					int ln = standing[t + 1].m_leagueRecord - w * 100;
					if (w == wn && l == ln)
					{
						int init = standing[t].m_initialNumber + 1;
						int initn = standing[t + 1].m_initialNumber + 1;
						if (standing[t].m_vsOpponentPct[initn] < standing[t + 1].m_vsOpponentPct[init])
						{
							CRecord temp = standing[t];//swap
							standing[t] = standing[t + 1];
							standing[t + 1] = temp;
						}
					}
				}

				if (FirstPlace == TRUE)
				{
					//save 1st place teams numbers
					FirstPlace = FALSE;
					gb = 0;
					FirstPlaceWin = w;
					FirstPlaceLoss = l;
				}
				else
				{
					//calculate Games Back
					gb = (double(FirstPlaceWin) - double(w) + double(l) - double(FirstPlaceLoss)) / 2;
				}
				int games = w + l;
				if (games == 0) games = 1;
				double pct = double(w) / double(games);
				leagueWin.Format("%d", w);
				leagueLoss.Format("%d", l);
				leaguePct.Format("%.3f", pct);
				gamesBack.Format("%.1f", gb);

				w = standing[t].m_conferenceRecord / 100;
				l = standing[t].m_conferenceRecord - w * 100;
				conferenceWin.Format("%d", w);
				conferenceLoss.Format("%d", l);

				w = standing[t].m_divisionRecord / 100;
				l = standing[t].m_divisionRecord - w * 100;
				divisionWin.Format("%d", w);
				divisionLoss.Format("%d", l);

				w = standing[t].m_homeRecord / 100;
				l = standing[t].m_homeRecord - w * 100;
				homeWin.Format("%d", w);
				homeLoss.Format("%d", l);

				w = standing[t].m_visitorRecord / 100;
				l = standing[t].m_visitorRecord - w * 100;
				visitorWin.Format("%d", w);
				visitorLoss.Format("%d", l);

				CString teamName = standing[t].m_leagueTeamNames;
				CString cityName = standing[t].m_city_name;
				result.Format
				("%-16s %3s %3s %3s % 4s %3s %3s %3s %3s %3s %3s %3s %3s",
					teamName, leagueWin, leagueLoss, leaguePct, gamesBack, conferenceWin, conferenceLoss,
					divisionWin, divisionLoss, homeWin, homeLoss, visitorWin, visitorLoss);


				//			m_listTeams.InsertItem(row,cityName + " " + teamName, RGB(128,128,128), RGB(128,255,255));
				//			m_listTeams.SetItemText(row,1,leagueWin + "-" + leagueLoss, RGB(128,128,128), RGB(128,255,255));
				m_listTeams.InsertItem(row, cityName + " " + teamName);
				m_listTeams.SetItemText(row, 1, leagueWin + "-" + leagueLoss);
				m_listTeams.SetItemText(row, 2, leaguePct);
				m_listTeams.SetItemText(row, 3, gamesBack);
				m_listTeams.SetItemText(row, 4, conferenceWin + "-" + conferenceLoss);
				m_listTeams.SetItemText(row, 5, divisionWin + "-" + divisionLoss);
				m_listTeams.SetItemText(row, 6, homeWin + "-" + homeLoss);
				m_listTeams.SetItemText(row, 7, visitorWin + "-" + visitorLoss);


				//			m_listTeams.AddString(result);
				m_strings[row] = result;
				if (standing[t].m_initialNumber == m_default_team)
					m_selection_row = row;
				row = row + 1;
			}
		}

		HighlightRow();

	}


}





void CStandingsView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	WinHelp(HID_LEAGUE_STANDINGS);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/standingsoverview.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

}

BOOL CStandingsView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/standingsoverview.htm", HH_DISPLAY_TOPIC, 0);

	return CFormView::OnHelpInfo(pHelpInfo);
	//	WinHelp(HID_LEAGUE_STANDINGS);		
	//	return TRUE;
}


void CStandingsView::OnButtonPrint()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	//initialize a structure for my font
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

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
		pDC->StartDoc("Standings");  // begin a new print job
								// for Win32 use
								// CDC::StartDoc(LPDOCINFO) override
		pDC->StartPage();          // begin a new page
		SetPrintAlign(pDC, hdcPrn);// set the printing alignment

		LOGFONT logFont;
		logFont.lfHeight = 40;
		logFont.lfWidth = 0;
		logFont.lfEscapement = 0;
		logFont.lfOrientation = 0;
		logFont.lfWeight = 420;
		logFont.lfItalic = 0;
		logFont.lfUnderline = 0;
		logFont.lfStrikeOut = 0;
		logFont.lfCharSet = ANSI_CHARSET;
		logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
		logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		logFont.lfQuality = PROOF_QUALITY;
		logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
		strcpy_s(logFont.lfFaceName, "Courier New");

		CFont font;
		font.CreateFontIndirect(&logFont);
		CFont* oldFont = pDC->SelectObject(&font);

		CString ch;
		if (m_listChoices.GetCurSel() >= 0) m_listChoices.GetText(m_listChoices.GetCurSel(), ch);
		CString heading = pDoc->avg.m_settings.m_league_name + " " + ch + " Standings";


		//		pBuf = "Name               g  mpg  fgm  fga   fg% 3gm  3ga   3g%  ftm  fta   ft%   ppg";
		//		pBuf = "Name               pos  2ga  2g%  fta  ft%  3ga  3g%  orb  drb  ast  stl  to   blk";
		pBuf = "team                w   l  pct   gb    conf    div     home    away";
		pDC->TextOut(-900, 1000, heading);// write the string in pbuf
		pDC->TextOut(-900, 900, pBuf);// write the string in pbuf
		int items = m_listTeams.GetItemCount();
		int row = 800;
		for (int i = 1; i <= items; i++)
		{
			//			pBuf = m_listTeams.GetItemText(i-1, 0);
			pBuf = m_strings[i - 1];
			pDC->TextOut(-900, row, pBuf);// write the string in pbuf
			row = row - 50;
		}

		pDC->EndPage();            // end a page
		pDC->EndDoc();             // end a print job
		pDC->Detach();             // detach the printer DC
		delete pDC;
	}
	delete printDlg;

}

void CStandingsView::SetPrintAlign(CDC* pDC, HDC hdcPrn)
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


void CStandingsView::OnDblclkListChoices()
{
	// TODO: Add your control notification handler code here

}




void CStandingsView::InitControls()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();




	m_default_team = pDoc->m_combo_team_index - 1;
	m_standings_default_team = m_default_team;
	if (m_default_team < 1) m_default_team = 0;


	m_listChoices.ResetContent();

	m_combo_teams.ResetContent();

	m_combo_teams.AddString("All Teams");

	for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
	{
		CString team_name = pDoc->avg.m_settings.m_leagueTeamNames[i];
		if (team_name != "")
			//m_combo_teams.AddString(team_name);
			m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
	}

	m_combo_teams.SetCurSel(m_standings_default_team + 1);

	//			result.Format
	//				("%-16s %3s %3s %3s % 4s %3s %3s %3s %3s %3s %3s %3s %3s",
	//				teamName,leagueWin,leagueLoss,leaguePct,gamesBack,conferenceWin,conferenceLoss,
	//				divisionWin,divisionLoss,homeWin,homeLoss,visitorWin,visitorLoss);



}

void CStandingsView::OnDblclkListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CLeagueTeamSchedule* team;
	team = new CLeagueTeamSchedule;
	team->avg = pDoc->avg;
	int row = m_listTeams.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (row < 0) row = 0;

	CString string = m_listTeams.GetItemText(row, 0);
	CString currentTeam = string;
	currentTeam.TrimRight();
	int index = 0;
	for (int i = 0; i <= 32; i++)
	{
		if (m_initialCityNames[i] + " " + m_initialLeagueTeamNames[i] == currentTeam && currentTeam != "") index = i;
	}

	team->m_default_team = index;

	team->DoModal();
	delete team;


}

void CStandingsView::OnClickListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here

	SelectChange();





	*pResult = 0;
}

void CStandingsView::SelectChange()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int in = m_listTeams.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (in >= 0)
	{
		m_listVsOpponents.DeleteAllItems();
		CString choice = m_listTeams.GetItemText(in, 0);
		int index = 0;
		for (int t = 0; t <= 31; t++)
		{
			//		int length = standing[t].m_city_name.GetLength();
			CString city1 = choice;
			CString city2 = standing[t].m_city_name + " " + standing[t].m_leagueTeamNames;


			if (city1 == city2 && city1 != "") index = t;
		}

		int row = 0;
		for (int t = 1; t <= 32; t++)
		{
			CString win;
			CString loss;
			CString teamName = m_initialLeagueTeamNames[t - 1];
			if (teamName == "") continue;
			CString result;
			int w = standing[index].m_vsOpponent[t] / 100;
			int l = standing[index].m_vsOpponent[t] - w * 100;
			win.Format("%d", w);
			loss.Format("%d", l);
			//		result.Format("%-16s %3s %3s",teamName,win,loss);
			//		m_listVsOpponents.AddString(result);

			m_listVsOpponents.InsertItem(row, teamName);
			m_listVsOpponents.SetItemText(row, 1, win);
			m_listVsOpponents.SetItemText(row, 2, loss);

			row = row + 1;

		}


	}
}

void CStandingsView::HighlightRow()
{
	m_listTeams.SetItemState(m_selection_row, LVIS_SELECTED, LVIS_SELECTED);
	m_listTeams.SetItemState(m_selection_row, LVIS_FOCUSED, LVIS_FOCUSED);
	m_listTeams.EnsureVisible(m_selection_row, TRUE);
	SelectChange();
}

BOOL CStandingsView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

//	m_button_setup.SetBk(pDC);

/*

//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();


//	bitmapBkgnd.Detach();
//	bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");




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


  //	return CView::OnEraseBkgnd(pDC);


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

void CStandingsView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CStandingsView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

void CStandingsView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CStandingsView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);
}

void CStandingsView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CStandingsView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CStandingsView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CStandingsView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::InitView()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	//m_list_stats.SetBkColor(RGB(215,235,255));
	//m_list_stats.SetTextBkColor(RGB(0,128,192));
   //m_list_stats.SetTextColor(RGB(0,0,0));


//	m_listTeams.SetBkColor(BK_COLOR);
//	m_listTeams.SetTextBkColor(TEXT_BK_COLOR);
	m_listTeams.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//    m_listTeams.SetTextColor(TEXT_COLOR);
	//	m_listTeams.SetFont(&m_font1);
	//m_listTeams.SetHeaderColors(YELLOW, RGB(64,64,64));

	m_listTeams.DeleteColumn(0);
	m_listTeams.InsertColumn(0, "team");
	m_listTeams.DeleteColumn(1);
	m_listTeams.InsertColumn(1, "league");
	m_listTeams.DeleteColumn(2);
	m_listTeams.InsertColumn(2, "pct");
	m_listTeams.DeleteColumn(3);
	m_listTeams.InsertColumn(3, "gb");
	m_listTeams.DeleteColumn(4);
	m_listTeams.InsertColumn(4, "conference");
	m_listTeams.DeleteColumn(5);
	m_listTeams.InsertColumn(5, "division");
	m_listTeams.DeleteColumn(6);
	m_listTeams.InsertColumn(6, "home");
	m_listTeams.DeleteColumn(7);
	m_listTeams.InsertColumn(7, "away");

	m_listTeams.SetColumnWidth(0, 120);
	m_listTeams.SetColumnWidth(1, 66);
	m_listTeams.SetColumnWidth(2, 40);
	m_listTeams.SetColumnWidth(3, 40);
	m_listTeams.SetColumnWidth(4, 66);
	m_listTeams.SetColumnWidth(5, 66);
	m_listTeams.SetColumnWidth(6, 66);
	m_listTeams.SetColumnWidth(7, 66);
	//m_listTeams.SetColumnWidth( 13, 30);
	//m_listTeams.SetColumnWidth( 14, 30);

	//m_listVsOpponents.SetBkColor(BK_COLOR);
	//m_listVsOpponents.SetTextBkColor(TEXT_BK_COLOR);
	m_listVsOpponents.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_listVsOpponents.SetTextColor(RGB(0,0,0));
//	m_listVsOpponents.SetFont(&m_font1);


	m_listVsOpponents.DeleteColumn(0);
	m_listVsOpponents.InsertColumn(0, "opponent");
	m_listVsOpponents.DeleteColumn(1);
	m_listVsOpponents.InsertColumn(1, "win");
	m_listVsOpponents.DeleteColumn(2);
	m_listVsOpponents.InsertColumn(2, "loss");

	m_listVsOpponents.SetColumnWidth(0, 90);
	m_listVsOpponents.SetColumnWidth(1, 30);
	m_listVsOpponents.SetColumnWidth(2, 30);


	//	m_button_schedule.SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
	//	m_button_schedule.SetIcon(IDI_IEDOCUMENT);


	//	m_button_setup.SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
	//	m_button_setup.SetIcon(IDI_IEDOCUMENT);

	//	m_button_standings.SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
	//	m_button_standings.SetIcon(IDI_IEDOCUMENT);
		//CSxLogFont Arial12b(80,FW_BOLD,false,USERFONT);
		//CSxLogFont Arial10b(80,FW_NORMAL,false,"Arial");  

	/*  for(int i=1; i<=3; i++)
	  {
		// set the custom font, text color, and alignment
		m_g[i].SetFont( &Arial10b );
		m_g[i].SetTextColor( MAINTEXTCOLOR );
		m_g[i].SetTextAlign( BS_CENTER );

	  // set the custom line colors, thickness, and style
	//	m_g[i].SetBoxColors( RGB(100,0,0), RGB(255,100,100) );
		m_g[i].SetBoxColors( RGB(255,255,224), RGB(255,255,224) );
		m_g[i].SetLineThickness(1);
		m_g[i].SetLineStyle( BS_3D );
	  }*/



	for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
	{
		pDoc->avg.m_standings[i].m_initialNumber = i;
		m_initialLeagueTeamNames[i] = pDoc->avg.m_standings[i].m_leagueTeamNames;
		pDoc->avg.m_standings[i].m_city_name = pDoc->avg.m_finance[i].m_city_name;
		m_initialCityNames[i] = pDoc->avg.m_standings[i].m_city_name;

	}


	for (int i = 0; i <= 32; i++)
	{
		standing[i] = pDoc->avg.m_standings[i];
	}






	InitControls();

	if (pDoc->avg.m_settings.m_conferenceName1 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_conferenceName1 + " Conference");
	if (pDoc->avg.m_settings.m_conferenceName2 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_conferenceName2 + " Conference");
	if (pDoc->avg.m_settings.m_divisionName1 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_divisionName1 + " Division");
	if (pDoc->avg.m_settings.m_divisionName2 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_divisionName2 + " Division");
	if (pDoc->avg.m_settings.m_divisionName3 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_divisionName3 + " Division");
	if (pDoc->avg.m_settings.m_divisionName4 != "") m_listChoices.AddString(pDoc->avg.m_settings.m_divisionName4 + " Division");
	m_listChoices.SetCurSel(0);

	int co = m_listChoices.GetCount();
	int fa = 0;
	if (co > 0)
	{
		for (int i = 1; i <= co; i++)
		{
			CString choice;
			m_listChoices.GetText(i - 1, choice);
			CString con = pDoc->avg.m_standings[m_default_team].m_conference + " Conference";
			if (choice != "" && choice == con) fa = i - 1;
		}
	}





	m_listChoices.SetCurSel(fa);
	OnSelchangeListChoices();
	//	m_listTeams.SetCurSel(0);
	//	OnSelchangeListTeams(); 
	//	m_selection_row = 0;
	HighlightRow();

	//	SelectChange();
	CString heading;
	heading.Format("%d %s Standings", pDoc->avg.m_settings.m_currentYear, pDoc->avg.m_settings.m_league_name);
	SetWindowText(heading);

	UpdateData(FALSE);
	//Invalidate(TRUE);	

	RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

	//m_listTeams.RedrawWindow();

}

void CStandingsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class
	InitView();

}

HBRUSH CStandingsView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	//		  CBrush m_tbrush;
	//		  m_tbrush.CreateSolidBrush(LISTBOXCOLOR); 

	switch (nCtlColor)
	{
	case CTLCOLOR_EDIT:
		pDC->SetTextColor(EDITCOLOR);
		pDC->SetBkColor(EDITBKCOLOR);
		return hbr;
	case CTLCOLOR_STATIC:
		LOGBRUSH logbrush;
		myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(STATICCOLOR);
		pDC->SetBkColor(logbrush.lbColor);
		return hbr;
	case CTLCOLOR_BTN:
		//          pDC->SetTextColor(RGB(0,255,255));
		  //        pDC->SetBkColor(RGB(255,128,128));
		return hbr;
	case CTLCOLOR_LISTBOX:
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(LISTBOXCOLOR);
		pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return m_tbrush;

	case CTLCOLOR_SCROLLBAR:
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(LISTBOXCOLOR);
		return hbr;


	case CTLCOLOR_MSGBOX:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return hbr;
	case CTLCOLOR_DLG:
		return hbr;
	default:
		return hbr;
	}



	return hbr;
}

void CStandingsView::OnTeamRoster()
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

void CStandingsView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CStandingsView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CStandingsView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CStandingsView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}

void CStandingsView::OnMove(int x, int y)
{
	CFormView::OnMove(x, y);

	// TODO: Add your message handler code here

}

void CStandingsView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	// Do not call CFormView::OnPaint() for painting messages

//	Graphics graphics(dc.m_hDC);
//	CString image = "roster.jpg";
//	Bitmap bitmap(image.AllocSysString());
//	graphics.DrawImage(&bitmap, 1, 1);
//	graphics.ReleaseHDC(dc.m_hDC);

}

void CStandingsView::OnCancelMode()
{
	CFormView::OnCancelMode();

	// TODO: Add your message handler code here

}
