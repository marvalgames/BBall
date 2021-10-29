// HistoryView.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "bballdoc.h"
#include "MyComboBox.h"
#include "HistoryView.h"
#include "HistoryDraftDlg.h"
#include "RecordbookDlg.h"
#include "HofDlg.h"
#include "HistoryAwardsDlg.h"
#include "HistoryStats.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryView

IMPLEMENT_DYNCREATE(CHistoryView, CFormView)

CHistoryView::CHistoryView()
	: CFormView(CHistoryView::IDD)
{
	//{{AFX_DATA_INIT(CHistoryView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT


//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));

	//m_bmp = new CBitmap;
	//m_bmp->LoadBitmap(IDB_BITMAPSCREEN);
	//m_bmp->SetBitmapDimension(182,240); /* if the size of bitmap is 50 by 40 */
	//m_bmp->SetBitmapDimension(1680, 1050); /* if the size of bitmap is 50 by 40 */

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */




}

CHistoryView::~CHistoryView()
{
	delete m_bmp;
}


void CHistoryView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryView)
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_ROOKIE_DRAFTS, m_button_rookie_drafts);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_HOF, m_button_hof);
	DDX_Control(pDX, IDC_BUTTON_HISTORY_AWARDS, m_button_history_awards);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_CAREER_STATS, m_button_career_stats);
	DDX_Control(pDX, IDC_BUTTON_RECORDBOOK, m_button_recordbook);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryView, CFormView)
	//{{AFX_MSG_MAP(CHistoryView)
	ON_WM_ERASEBKGND()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_ROOKIE_DRAFTS, OnButtonRookieDrafts)
	ON_BN_CLICKED(IDC_BUTTON_HOF, OnButtonHof)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY_AWARDS, OnButtonHistoryAwards)
	ON_BN_CLICKED(IDC_BUTTON_CAREER_STATS, OnButtonCareerStats)
	ON_BN_CLICKED(IDC_BUTTON_RECORDBOOK, OnButtonRecordbook)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
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
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_ARENA, &CHistoryView::OnBnClickedButtonArena)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryView diagnostics

#ifdef _DEBUG
void CHistoryView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHistoryView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHistoryView message handlers

void CHistoryView::OnInitialUpdate()
{
	//	CFormView::OnInitialUpdate();

		// TODO: Add your specialized code here and/or call the base class
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	//CFrameWnd* pFrame;
	//CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();






	myBrush.CreateSolidBrush(SCREENCOLOR);
	// Update form's data from document
	SetFromDoc();

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 550;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 550;
	lf.lfHeight = 14;
	lf.lfUnderline = TRUE;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font1.CreateFontIndirect(&lf);    // Create the font.


	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	VERIFY(pFrame = GetParentFrame());
	GetClientRect(rectView);
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	if (w > WIDTH) w = WIDTH;
	if (h > HEIGHT) h = HEIGHT;
	pFrame->SetWindowPos(NULL, 0, 0, w, h, SWP_SHOWWINDOW);
	pFrame->RecalcLayout();
	GetParentFrame()->RecalcLayout();


}

void CHistoryView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	if (bShow == TRUE) InitControls();

}

BOOL CHistoryView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;

}

void CHistoryView::SetFromDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	UpdateData(FALSE);    // Set controls to these
}

void CHistoryView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CHistoryView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

void CHistoryView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CHistoryView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
	//CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	//pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(0);
}

void CHistoryView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(1);
}

void CHistoryView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
	//CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	//pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(4);
}

void CHistoryView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(3);
}

void CHistoryView::InitControls()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();




	//	m_default_team  = pDoc->m_combo_team_index;



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

	//			result.Format
	//				("%-16s %3s %3s %3s % 4s %3s %3s %3s %3s %3s %3s %3s %3s",
	//				teamName,leagueWin,leagueLoss,leaguePct,gamesBack,conferenceWin,conferenceLoss,
	//				divisionWin,divisionLoss,homeWin,homeLoss,visitorWin,visitorLoss);

	//Invalidate(TRUE);

	RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

}

void CHistoryView::OnButtonRookieDrafts()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CHistoryDraftDlg* draft = new CHistoryDraftDlg;
	draft->m_path = pDoc->avg.m_settings.m_path;
	draft->m_leagueName = pDoc->avg.m_settings.m_league_name;
	draft->DoModal();
	delete draft;
}

void CHistoryView::OnButtonHof()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CHofDlg* hof = new CHofDlg();;
	hof->m_path = pDoc->avg.m_settings.m_path;
	hof->m_leagueName = pDoc->avg.m_settings.m_league_name;
	hof->DoModal();
	delete hof;
}

void CHistoryView::OnButtonHistoryAwards()
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CHistoryAwardsDlg* award = new CHistoryAwardsDlg;
	for (int i = 0; i <= 32; i++)
	{
		award->m_league_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	award->m_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;
	award->m_path = pDoc->avg.m_settings.m_path;
	award->m_league_name = pDoc->avg.m_settings.m_league_name;
	award->DoModal();
	delete award;

}

void CHistoryView::OnButtonCareerStats()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CHistoryStats* stats = new CHistoryStats;
	stats->m_path = pDoc->avg.m_settings.m_path;
	stats->m_leagueName = pDoc->avg.m_settings.m_league_name;;
	stats->DoModal();
	delete stats;

}

/*void CHistoryView::OnDraw(CDC* pDC)
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

void CHistoryView::OnButtonRecordbook()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CRecordbookDlg* book = new CRecordbookDlg;
	book->avg = pDoc->avg;
	book->m_recordbook = pDoc->m_recordbook;
	book->DoModal();
	delete book;

}

void CHistoryView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);

}

void CHistoryView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CHistoryView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CHistoryView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CHistoryView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

BOOL CHistoryView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyhof.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

	return CFormView::OnHelpInfo(pHelpInfo);
}

void CHistoryView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyhof.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

}

HBRUSH CHistoryView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CHistoryView::OnTeamRoster()
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

void CHistoryView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CHistoryView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}



void CHistoryView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CHistoryView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}

void CHistoryView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}



BOOL CHistoryView::OnEraseBkgnd(CDC* pDC)
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



	//		return CView::OnEraseBkgnd(pDC);
}


void CHistoryView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

//	Graphics graphics(dc.m_hDC);
//	CString image = "roster.jpg";
//	Bitmap bitmap(image.AllocSysString());
//	graphics.DrawImage(&bitmap, 1, 1);
//	graphics.ReleaseHDC(dc.m_hDC);

	// Do not call CFormView::OnPaint() for painting messages
}


void CHistoryView::OnBnClickedButtonArena()
{
	// TODO: Add your control notification handler code here
}
