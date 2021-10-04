// ToolsView.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "bballdoc.h"
#include "MyComboBox.h"
#include "ToolsView.h"
#include "EditDlg.h"
#include "HtmlDlg.h"
#include "Disk.h"
#include "ImportDlg.h"
#include "BoxDlg.h"
#include "PbpDlg.h"
#include "ScoutEditDlg.h"
#include "ScheduleDlg.h"
#include "FranchiseEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolsView

IMPLEMENT_DYNCREATE(CToolsView, CFormView)

CToolsView::CToolsView()
	: CFormView(CToolsView::IDD)
{
	//{{AFX_DATA_INIT(CToolsView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	//m_bmp = new CBitmap;
	//m_bmp->LoadBitmap(IDB_BITMAPSCREEN);
	//m_bmp->SetBitmapDimension(182,240); /* if the size of bitmap is 50 by 40 */
	//m_bmp->SetBitmapDimension(1680, 1050); /* if the size of bitmap is 50 by 40 */

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */



//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));
}

CToolsView::~CToolsView()
{
	delete m_bmp;
}

void CToolsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolsView)
	DDX_Control(pDX, IDC_BUTTON_EDITSTAFF, m_button_staff);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_PBP, m_button_pbp);
	DDX_Control(pDX, IDC_BUTTON_BOX, m_button_box);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULER, m_button_scheduler);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_PLAYER_EDIT, m_button_player_edit);
	DDX_Control(pDX, IDC_BUTTON_IMPORT, m_button_import);
	DDX_Control(pDX, IDC_BUTTON_HTML, m_button_html);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_CITY_EDIT, m_button_city_edit);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolsView, CFormView)
	//{{AFX_MSG_MAP(CToolsView)
	ON_WM_ERASEBKGND()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_PLAYER_EDIT, OnButtonPlayerEdit)
	ON_BN_CLICKED(IDC_BUTTON_CITY_EDIT, OnButtonCityEdit)
	ON_BN_CLICKED(IDC_BUTTON_HTML, OnButtonHtml)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImport)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULER, OnButtonScheduler)
	ON_BN_CLICKED(IDC_BUTTON_BOX, OnButtonBox)
	ON_BN_CLICKED(IDC_BUTTON_PBP, OnButtonPbp)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
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
	ON_BN_CLICKED(IDC_BUTTON_EDITSTAFF, OnButtonEditstaff)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_PLAYERS, OnEditPlayers)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolsView diagnostics

#ifdef _DEBUG
void CToolsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CToolsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolsView message handlers

void CToolsView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	if (bShow == TRUE) InitControls();

}

void CToolsView::OnInitialUpdate()
{
	//	CFormView::OnInitialUpdate();

		// TODO: Add your specialized code here and/or call the base class
		//RedrawWindow( NULL, NULL,  RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE ); 
		//Invalidate();
		//UpdateWindow();

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();


	//OnPaint();


	// Update form's data from document
	SetFromDoc();




	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 550;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.





	myBrush.CreateSolidBrush(DLGCOLOR);
	//myBrush.CreateSysColorBrush(HS_CROSS); 






//	m_font.DeleteObject();



	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 550;
	lf.lfHeight = 14;
	lf.lfUnderline = TRUE;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font1.CreateFontIndirect(&lf);    // Create the font.
//	m_font.DeleteObject();





//
//
//	// Resize parent to fit dialog template exactly    
//	// while not resizing beyond size of screen
//	VERIFY(pFrame = GetParentFrame());
//	pFrame->GetClientRect(rectFrame);
//	GetClientRect(rectView);
//	//    if ( rectFrame.Width() < rectView.Width()
//	 //        || rectFrame.Height() < rectView.Height() )
//	 //   {        
//			// Resize so can be refit to any template that fits the screen
//	//        pFrame->MoveWindow( 0, 0, GetSystemMetrics(SM_CXSCREEN), 
//	//                        GetSystemMetrics(SM_CYSCREEN), FALSE ); 
//
//	/*int w = GetSystemMetrics(SM_CXSCREEN);
//	int h = GetSystemMetrics(SM_CYSCREEN);
//
//	if (w > WIDTH) w = WIDTH;
//	if (h > HEIGHT) h = HEIGHT;
//	pFrame->SetWindowPos(NULL, 0, 0, w, h, SWP_NOSIZE);
//	pFrame->RecalcLayout();
//	GetParentFrame()->RecalcLayout();*/
//	//ResizeParentToFit();
//
//	//if(w > 1023) w = 1023;
//	//if(h > 750) h = 750;
////        pFrame->MoveWindow( 0, 0, w, h, FALSE ); 
//
//
//	//pFrame->SetWindowPos(NULL, 0, 0, w, h, FALSE);
//
//
//	//   }
//	//pFrame->RecalcLayout();
//	////ResizeParentToFit(TRUE);    // Shrink to fit template 
//
//
////	InitControls();



}

BOOL CToolsView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;

}

void CToolsView::SetFromDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	UpdateData(FALSE);    // Set controls to these
}

void CToolsView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CToolsView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

void CToolsView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CToolsView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(0);

}

void CToolsView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(1);

}

void CToolsView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(4);

}

void CToolsView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::InitControls()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();



	if (pDoc->avg.m_settings.m_current_stage == 0)
	{
		m_button_scheduler.EnableWindow(TRUE);
	}
	else
	{
		m_button_scheduler.EnableWindow(FALSE);
	}




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

	//	RedrawWindow( NULL, NULL,  RDW_INVALIDATE | RDW_UPDATENOW | RDW_NOERASE   ); 

	//	RedrawWindow( NULL, NULL,  RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE ); 

}

void CToolsView::OnButtonPlayerEdit()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CToolsView::OnButtonCityEdit()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
	InitControls();
}

void CToolsView::OnButtonHtml()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CHtmlDlg* html = new CHtmlDlg;

	//	CHtml* html = new CHtml;
	html->m_path = pDoc->avg.m_settings.m_path;
	html->m_league_name = pDoc->avg.m_settings.m_league_name;
	html->m_stage = 0;
	html->m_bk_color = pDoc->m_bk_color;
	html->m_link_color = pDoc->m_link_color;
	html->m_vlink_color = pDoc->m_vlink_color;
	html->m_text_color = pDoc->m_text_color;
	html->m_html_font = pDoc->m_html_font;
	//	m_link_color = "#804040";
	//	m_vlink_color = "#0080FF";


	html->avg = pDoc->avg;


	int result = html->DoModal();
	if (result == IDOK)
	{
		pDoc->m_bk_color = html->m_bk_color;
		pDoc->m_text_color = html->m_text_color;
		pDoc->m_link_color = html->m_link_color;
		pDoc->m_vlink_color = html->m_vlink_color;
		pDoc->m_html_font = html->m_html_font;
	}

	delete html;

}

void CToolsView::OnButtonImport()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CImportDlg* imp = new CImportDlg;
	imp->m_year = pDoc->avg.m_settings.m_currentYear + 2;
	imp->m_path = pDoc->avg.m_settings.m_path;
	imp->m_league_name = pDoc->avg.m_settings.m_league_name;
	imp->avg.m_settings.m_current_stage = pDoc->avg.m_settings.m_current_stage;
	int result = imp->DoModal();
	delete imp;

}

/*void CToolsView::OnDraw(CDC* pDC)
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

void CToolsView::OnButtonScheduler()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CScheduleDlg* scheduleDlg;
	scheduleDlg = new CScheduleDlg;

	//clear games scores for saving to league file

	scheduleDlg->avg = pDoc->avg;

	for (int i = 0; i <= 31; i++)
	{
		scheduleDlg->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}




	for (int i = 0; i <= 12; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			for (int k = 0; k <= 15; k++)
			{
				scheduleDlg->m_schedule[i][j][k] = pDoc->avg.m_sched.m_schedule[i][j][k];
			}
		}
	}

	int result = scheduleDlg->DoModal();

	if (result == IDOK)
	{
		//save schedule and scores
		for (int i = 0; i <= 12; i++)
		{
			for (int j = 0; j <= 30; j++)
			{
				for (int k = 0; k <= 15; k++)
				{
					CString buffer;
					pDoc->avg.m_sched.m_schedule[i][j][k] = scheduleDlg->m_schedule[i][j][k];

					if (scheduleDlg->m_resetStats == TRUE)
						pDoc->avg.m_sched.m_game_score[i][j][k] = 0;

					if (scheduleDlg->m_resetStats == TRUE && i == 12)
						pDoc->avg.m_sched.m_schedule[i][j][k] = 0;
				}
			}
		}

		if (scheduleDlg->m_resetStats == TRUE) pDoc->ResetSeason();
	}
	delete scheduleDlg;

}

void CToolsView::OnButtonBox()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CBoxDlg box;
	for (int i = 0; i <= 31; i++)
	{
		box.m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	box.m_fileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;
	box.m_default_team = pDoc->m_combo_team_index - 1;
	if (box.m_default_team < 0) box.m_default_team = 0;
	box.DoModal();

}













void CToolsView::OnButtonPbp()
{
	// TODO: Add your control notification handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CPbpDlg pbp;
	for (int i = 0; i <= 31; i++)
	{
		pbp.m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	pbp.m_fileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".log";
	pbp.m_default_team = pDoc->m_combo_team_index - 1;
	if (pbp.m_default_team < 0) pbp.m_default_team = 0;
	pbp.DoModal();
}

void CToolsView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);

}

void CToolsView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CToolsView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CToolsView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CToolsView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

BOOL CToolsView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsplayeredit.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);


	return CFormView::OnHelpInfo(pHelpInfo);
}

void CToolsView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsplayeredit.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

}

HBRUSH CToolsView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	//	Invalidate(FALSE);
		//Default();

	switch (nCtlColor)
	{
		//Edit controls need white background and black text
		//Note the 'return hbr' which is needed to draw the Edit
		//control's internal background (as opposed to text background)
	case CTLCOLOR_EDIT:
		pDC->SetTextColor(EDITCOLOR);
		pDC->SetBkColor(EDITBKCOLOR);
		return myBrush;
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
		return myBrush;
	}


	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here

	// TODO: Return a different brush if the default is not desired
	//return hbr;



	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here

	// TODO: Return a different brush if the default is not desired
	//return hbr;
}


void CToolsView::OnTeamRoster()
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

void CToolsView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CToolsView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}


void CToolsView::OnButtonEditstaff()
{
	// TODO: Add your control notification handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}

void CToolsView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CToolsView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CToolsView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}






BOOL CToolsView::OnEraseBkgnd(CDC* pDC)
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
//   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

   BITMAP bm;
//   bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
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


void CToolsView::OnPaint()
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

