// BBallCoachView.cpp : implementation file
//

#include "stdafx.h"
//#include "BBall.h"
#ifndef bball_h
#include "bball.h"
#define bball_h
#endif 
#include "BBallCoachView.h"
#include "BBallDoc.h"
#include "Disk.h"
#include "StatsDlg.h"
#include "TimeoutDlg.h"
#include "DefenseDlg.h"
#include "ReportDlg.h"
#include "PlayerCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBBallCoachView

IMPLEMENT_DYNCREATE(CBBallCoachView, CFormView)

CBBallCoachView::CBBallCoachView()
	: CFormView(CBBallCoachView::IDD)
{
	//{{AFX_DATA_INIT(CBBallCoachView)
	//}}AFX_DATA_INIT
//itmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
//                  MAKEINTRESOURCE(IDB_BITMAP_BK)));

	m_auto_sub[0] = TRUE;
	m_auto_sub[1] = TRUE;
	m_auto_sub[2] = TRUE;
	m_sim_remainder = false;
	m_engine_created = false;
	m_pbp_lines = 0;
	for (int i = 0; i <= 2; i++)
	{
		m_score[i] = 0;
		for (int j = 0; j <= 5; j++)
		{
			m_quarter_score[i][j] = 0;
		}
	}
	m_quarter = 0;


	for (int i = 0; i <= 60; i++)
	{
		m_playing_players_list[i] = 0;
	}


	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */



}

CBBallCoachView::~CBBallCoachView()
{
	delete m_bmp;
}

void CBBallCoachView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBBallCoachView)
	DDX_Control(pDX, IDC_BUTTON_HOMEPLAN, m_buttonplan);
	DDX_Control(pDX, IDC_BUTTON_VISITORPLAN, m_buttonvplan);
	DDX_Control(pDX, IDC_BUTTON_VISITOR_CARD, m_button_road_card);
	DDX_Control(pDX, IDC_BUTTON_HOME_CARD, m_button_home_card);
	DDX_Control(pDX, IDC_STATIC_VLABEL, m_vlabel);
	DDX_Control(pDX, IDC_STATIC_TLABEL, m_tlabel);
	DDX_Control(pDX, IDC_STATIC_HLABEL, m_hlabel);
	DDX_Control(pDX, IDC_STATIC_HOMESCORE, m_static_homescore);
	DDX_Control(pDX, IDC_STATIC_HOME, m_static_home);
	DDX_Control(pDX, IDC_STATIC_VISITORSCORE, m_static_visitorscore);
	DDX_Control(pDX, IDC_STATIC_VISITOR, m_static_visitor);
	DDX_Control(pDX, IDC_STATIC_TIME, m_static_time);
	DDX_Control(pDX, IDC_STATIC_SUB, m_static_sub);
	DDX_Control(pDX, IDC_BUTTON_TO, m_buttonTo);
	DDX_Control(pDX, IDC_SLIDER_SPEED, m_sim_speed);
	DDX_Control(pDX, IDC_BUTTON_END, m_button_end);
	DDX_Control(pDX, IDC_LIST_VISITOR_LINEUP, m_list_visitor_lineup);
	DDX_Control(pDX, IDC_LIST_VISITOR_SHOT, m_list_visitor_shot);
	DDX_Control(pDX, IDC_LIST_VISITOR_ROSTER, m_list_visitor_roster);
	DDX_Control(pDX, IDC_LIST_SCOREBOARD, m_list_scoreboard);
	DDX_Control(pDX, IDC_LIST_HOME_SHOT, m_list_home_shot);
	DDX_Control(pDX, IDC_LIST_HOME_ROSTER, m_list_home_roster);
	DDX_Control(pDX, IDC_LIST_HOME_LINEUP, m_list_home_lineup);
	DDX_Control(pDX, IDC_BUTTON_SIM, m_button_sim);
	DDX_Control(pDX, IDC_BUTTON_PLAY, m_button_play);
	DDX_Control(pDX, IDC_LIST_PBP, m_list_pbp);
	//}}AFX_DATA_MAP
	DDX_Check(pDX, IDC_CHECK_AUTO_VISITOR, m_auto_sub[1]);
	DDX_Check(pDX, IDC_CHECK_AUTO_HOME, m_auto_sub[2]);
}


BEGIN_MESSAGE_MAP(CBBallCoachView, CFormView)
	//{{AFX_MSG_MAP(CBBallCoachView)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SIM, OnButtonSim)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_NOTIFY(HDN_BEGINDRAG, IDC_LIST_VISITOR_ROSTER, OnBegindragListVisitorRoster)
	ON_NOTIFY(HDN_ENDDRAG, IDC_LIST_VISITOR_ROSTER, OnEnddragListVisitorRoster)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_VISITOR_ROSTER, OnColumnclickListVisitorRoster)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_LIST_HOME_ROSTER, OnBegindragListHomeRoster)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_VISITOR_ROSTER, OnDblclkListVisitorRoster)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_HOME_ROSTER, OnDblclkListHomeRoster)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_BOX, OnButtonBox)
	ON_BN_CLICKED(IDC_CHECK_AUTO_HOME, OnCheckAutoHome)
	ON_BN_CLICKED(IDC_CHECK_AUTO_VISITOR, OnCheckAutoVisitor)
	ON_BN_CLICKED(IDC_BUTTON_DEFENSE, OnButtonDefense)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_SPEED, OnReleasedcaptureSliderSpeed)
	ON_BN_CLICKED(IDC_BUTTON_TO, OnButtonTo)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_VISITOR_CARD, OnButtonVisitorCard)
	ON_BN_CLICKED(IDC_BUTTON_HOME_CARD, OnButtonHomeCard)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_UPDATE_COMMAND_UI(ID_SETUP_LOAD, OnUpdateSetupLoad)
	ON_UPDATE_COMMAND_UI(ID_SETUP_PROPOSETRADE, OnUpdateSetupProposetrade)
	ON_UPDATE_COMMAND_UI(ID_SETUP_SETTINGS, OnUpdateSetupSettings)
	ON_BN_CLICKED(IDC_BUTTON_VISITORPLAN, OnButtonVisitorplan)
	ON_BN_CLICKED(IDC_BUTTON_HOMEPLAN, OnButtonHomeplan)
	ON_UPDATE_COMMAND_UI(ID_SETUP_SETGAMEPLAN, OnUpdateSetupSetgameplan)
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
	ON_NOTIFY(LVN_BEGINDRAG, IDC_LIST_VISITOR_ROSTER, OnBegindragListVisitorRoster)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_STN_CLICKED(IDC_STATIC_HOME, &CBBallCoachView::OnStnClickedStaticHome)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SCOREBOARD, &CBBallCoachView::OnLvnItemchangedListScoreboard)
	ON_STN_CLICKED(IDC_STATIC_TLABEL, &CBBallCoachView::OnStnClickedStaticTlabel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_HOME_SHOT, &CBBallCoachView::OnLvnItemchangedListHomeShot)
	ON_LBN_SELCHANGE(IDC_LIST_PBP, &CBBallCoachView::OnLbnSelchangeListPbp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBallCoachView diagnostics

#ifdef _DEBUG
void CBBallCoachView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBBallCoachView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBBallCoachView message handlers

void CBBallCoachView::OnInitialUpdate()
{
	//CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	//CFrameWnd* pFrame;
	//CRect rectFrame, rectView;
	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(BUTTONCOLOR); 



	// Update form's data from document
	SetFromDoc();


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




	m_button_play.EnableWindow(FALSE);
	m_button_sim.EnableWindow(FALSE);


	if (pDoc->m_coached_game_underway == false)
	{
		if (pDoc->avg.m_settings.m_control[pDoc->m_coach_home_index - 1] != "Player")
			m_auto_sub[1] = TRUE;
		if (pDoc->avg.m_settings.m_control[pDoc->m_coach_visitor_index - 1] != "Player")
			m_auto_sub[2] = TRUE;

	}

	SetMyFont(200, 14, USERFONT);
	SetMyFontStarters(500, 14, "Arial");
	SetMyFontScores(800, 16, "Courier New");



	m_vlabel.SetWindowText("Visitor");
	m_hlabel.SetWindowText("Home");
	m_tlabel.SetWindowText("Time");
	m_vlabel.SetFont(&m_font_scores);
	m_hlabel.SetFont(&m_font_scores);
	m_tlabel.SetFont(&m_font_scores);

	m_static_homescore.SetFont(&m_font_scores);
	m_static_home.SetFont(&m_font_scores);
	m_static_visitorscore.SetFont(&m_font_scores);
	m_static_visitor.SetFont(&m_font_scores);
	m_static_time.SetFont(&m_font_scores);



	/*
		m_vlabel.SetColor(DARKRED, LIGHTRED);
		m_vlabel.SetBkColor(DARKRED);

		m_tlabel.SetColor(DARKRED, LIGHTRED);
		m_tlabel.SetBkColor(DARKRED);
		m_tlabel.SetText("Time");

		m_hlabel.SetColor(DARKRED, LIGHTRED);
		m_hlabel.SetBkColor(DARKRED);
		*/


		/*	m_.SetText(m_LedEdit);
			m_Digistring.SetTransparent(TRUE);
			VERIFY(m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14 | CDigiStatic::DS_SZ_PROP | CDigiStatic::DS_NO_OFF));

			m_ScrollText.SetScrollText(_T(" Show must go on -"));
			m_ScrollText.SetColor(DARKCYAN, LIGHTCYAN);
			VERIFY(m_ScrollText.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14));
			m_ScrollText.SetSpeed(500);
			m_ScrollText.SetTextLength(12);
			m_ScrollText.Scroll(TRUE);

			m_Text2.SetBkColor(LIGHTBLUE);
			m_Text2.SetColor(LIGHTBLUE, WHITE);
			VERIFY(m_Text2.ModifyDigiStyle(0, CDigiStatic::DS_NO_OFF));
			m_Text2.Format(_T("%6.3lf"), 56.873);*/











	m_list_visitor_roster.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_visitor_roster.InsertColumn(0, "player");
	m_list_visitor_roster.InsertColumn(1, "pt");
	m_list_visitor_roster.InsertColumn(2, "fg");
	m_list_visitor_roster.InsertColumn(3, "fa");
	m_list_visitor_roster.InsertColumn(4, "r");
	m_list_visitor_roster.InsertColumn(5, "a");
	m_list_visitor_roster.InsertColumn(6, "f");
	m_list_visitor_roster.InsertColumn(7, "en");
	m_list_visitor_roster.InsertColumn(8, "o");
	m_list_visitor_roster.InsertColumn(9, "d");
	m_list_visitor_roster.SetColumnWidth(0, 120);
	m_list_visitor_roster.SetColumnWidth(1, 39);
	m_list_visitor_roster.SetColumnWidth(2, 42);
	m_list_visitor_roster.SetColumnWidth(3, 39);
	m_list_visitor_roster.SetColumnWidth(4, 40);
	m_list_visitor_roster.SetColumnWidth(5, 39);
	m_list_visitor_roster.SetColumnWidth(6, 30);
	m_list_visitor_roster.SetColumnWidth(7, 42);
	m_list_visitor_roster.SetColumnWidth(8, 39);
	m_list_visitor_roster.SetColumnWidth(9, 39);

	m_list_home_roster.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_home_roster.InsertColumn(0, "player");
	m_list_home_roster.InsertColumn(1, "pt");
	m_list_home_roster.InsertColumn(2, "fg");
	m_list_home_roster.InsertColumn(3, "fa");
	m_list_home_roster.InsertColumn(4, "r");
	m_list_home_roster.InsertColumn(5, "a");
	m_list_home_roster.InsertColumn(6, "f");
	m_list_home_roster.InsertColumn(7, "en");
	m_list_home_roster.InsertColumn(8, "o");
	m_list_home_roster.InsertColumn(9, "d");
	m_list_home_roster.SetColumnWidth(0, 120);
	m_list_home_roster.SetColumnWidth(1, 39);
	m_list_home_roster.SetColumnWidth(2, 42);
	m_list_home_roster.SetColumnWidth(3, 39);
	m_list_home_roster.SetColumnWidth(4, 40);
	m_list_home_roster.SetColumnWidth(5, 39);
	m_list_home_roster.SetColumnWidth(6, 30);
	m_list_home_roster.SetColumnWidth(7, 42);
	m_list_home_roster.SetColumnWidth(8, 39);
	m_list_home_roster.SetColumnWidth(9, 39);

	m_list_visitor_lineup.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_visitor_lineup.InsertColumn(0, "Pos");
	m_list_visitor_lineup.InsertColumn(1, "Player");
	m_list_visitor_lineup.InsertColumn(2, "Defender");
	m_list_visitor_lineup.SetColumnWidth(0, 54);
	m_list_visitor_lineup.SetColumnWidth(1, 144);
	m_list_visitor_lineup.SetColumnWidth(2, 144);

	m_list_scoreboard.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_scoreboard.InsertColumn(0, "Visitor");
	m_list_scoreboard.InsertColumn(1, "Quarter  Time");
	m_list_scoreboard.InsertColumn(2, "Home");
	m_list_scoreboard.SetColumnWidth(0, 128);
	m_list_scoreboard.SetColumnWidth(1, 128);
	m_list_scoreboard.SetColumnWidth(2, 128);

	m_list_home_lineup.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_home_lineup.InsertColumn(0, "Pos");
	m_list_home_lineup.InsertColumn(1, "Player");
	m_list_home_lineup.InsertColumn(2, "Defender");
	m_list_home_lineup.SetColumnWidth(0, 54);
	m_list_home_lineup.SetColumnWidth(1, 144);
	m_list_home_lineup.SetColumnWidth(2, 144);

	m_list_home_shot.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_home_shot.InsertColumn(0, "Shoot");
	m_list_home_shot.SetColumnWidth(0, 76);
	m_list_home_shot.InsertItem(0, "Auto");
	m_list_home_shot.InsertItem(1, "Three");
	m_list_home_shot.InsertItem(2, "Outside");
	m_list_home_shot.InsertItem(3, "Drive");
	m_list_home_shot.InsertItem(4, "Post");

	m_list_visitor_shot.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_visitor_shot.InsertColumn(0, "Shoot");
	m_list_visitor_shot.SetColumnWidth(0, 76);
	m_list_visitor_shot.InsertItem(0, "Auto");
	m_list_visitor_shot.InsertItem(1, "Three");
	m_list_visitor_shot.InsertItem(2, "Outside");
	m_list_visitor_shot.InsertItem(3, "Drive");
	m_list_visitor_shot.InsertItem(4, "Post");


	//InitControls();

}

void CBBallCoachView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code her
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	if (bShow == TRUE)
	{
		InitControls();
		OnButtonStart();
		UpdateData(FALSE);
		m_sim_speed.SetRangeMin(1, FALSE);
		m_sim_speed.SetRangeMax(100, FALSE);
		m_sim_speed.SetPos(pDoc->avg.m_settings.m_sim_speed);
	}


}

BOOL CBBallCoachView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;
}

void CBBallCoachView::SetFromDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	UpdateData(FALSE);    // Set controls to these
}

void CBBallCoachView::OnButtonSim()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//bool cont_simming = false;

	if (engine->m_must_sub[1] == 0 && engine->m_must_sub[2] == 0)
	{

		if (m_sim_remainder == false)
		{

			m_button_sim.SetWindowText("Stop Simming");
			m_button_end.EnableWindow(FALSE);
			m_sim_remainder = true;
			//	cont_simming = true;
		}
		else
		{
			m_button_end.EnableWindow(TRUE);
			m_button_sim.SetWindowText("Sim Game");
			m_sim_remainder = false;
			//	cont_simming = false;
		}

		do
		{


			MSG msg;
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{


				//m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
				//TranslateAccelerator(m_hWnd, m_hAccel, &msg);

				TranslateMessage(&msg);
				DispatchMessage(&msg);


			}



			engine->GamePlay();

			if (engine->m_sub_ok == true)
				m_static_sub.EnableWindow(TRUE);
			else
				m_static_sub.EnableWindow(FALSE);


			ListStrings();


		} while (engine->m_gameOver == false && m_sim_remainder == true && engine->m_must_sub[1] == false && engine->m_must_sub[2] == 0);

		if (engine->m_must_sub[1] > 0 || engine->m_must_sub[2] > 0)
		{
			m_button_sim.SetWindowText("Sim Game");
			m_sim_remainder = false;
			SubBox();
		}

		if (engine->m_gameOver == true) EndGame();

	}
	else
	{
		SubBox();
	}

}

void CBBallCoachView::OnButtonPlay()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (engine->m_must_sub[1] == 0 && engine->m_must_sub[2] == 0)
	{

		Coach();
		engine->GamePlay();
		if (engine->m_sub_ok == true)
			m_static_sub.EnableWindow(TRUE);
		else
			m_static_sub.EnableWindow(FALSE);

		ListStrings();
		if (engine->m_gameOver == true) EndGame();

	}
	else
	{
		SubBox();
	}

}

void CBBallCoachView::OnButtonStart()
{
	// TODO: Add your control notification handler code here



	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	m_sim_remainder = false;
	m_button_sim.SetWindowText("Sim Game");


	if (pDoc->m_coached_game_underway == false)
	{



		StartGame();

		engine->m_scoring_factor = pDoc->avg.m_settings.m_scoring_factor;
		engine->m_recordbook = pDoc->m_recordbook;
		engine->avg = pDoc->avg;



		int t1 = pDoc->m_coach_visitor_index;
		int t2 = pDoc->m_coach_home_index;

		if (engine->avg.m_sched.m_playoff_started == true && pDoc->m_game_type != EXHIBITION)
		{
			engine->Initialize(t1, t2);
			engine->m_gameType = PLAYOFF;
			if (pDoc->m_game_type == EXHIBITION)
				engine->m_gameType = EXHIBITION;
		}



		else if (pDoc->m_game_type == ROOKIE)
			engine->InitializeRookieGame();
		else if (pDoc->m_game_type == ALLSTAR)
			engine->InitializeAllStarGame();
		else
		{
			engine->Initialize(t1, t2);
			engine->m_gameType = LEAGUE;
			if (pDoc->m_game_type == EXHIBITION)
				engine->m_gameType = EXHIBITION;
		}


		engine->SetupComputerLineups();

		engine->GameStart();
		DisplayRosterNames();
		DisplayRosters();
		DisplayLineups();
		DisplayScore();
		m_list_visitor_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
		m_list_home_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);

	}
}

void CBBallCoachView::EndGame()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	m_button_end.EnableWindow(TRUE);


	int t1 = pDoc->m_coach_visitor_index;
	int t2 = pDoc->m_coach_home_index;


	m_over = true;
	pDoc->m_coached_game_underway = false;

	m_button_play.EnableWindow(FALSE);
	m_button_sim.EnableWindow(FALSE);

	int sc1 = engine->GetScore(1);
	int sc2 = engine->GetScore(2);

	pDoc->m_coach_score[1] = sc1;
	pDoc->m_coach_score[2] = sc2;


	if (engine->m_gameType != ROOKIE && engine->m_gameType != ALLSTAR && engine->m_gameType != EXHIBITION)
	{
		for (int i = 0; i <= 32; i++)
		{
			pDoc->avg.m_standings[i] = engine->avg.m_standings[i];
		}

		pDoc->m_recordbook = engine->m_recordbook;
		pDoc->avg = engine->avg;
	}


	if (pDoc->m_game_type != EXHIBITION)
		pDoc->avg.m_sched.m_game_score[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame] = sc1 * 1000 + sc2;

	if (pDoc->avg.m_sched.m_playoff_started == true)
	{
		CDisk* disk = new CDisk;

		CString	pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";


		disk->WritePlayoffResults(pFileName, pDoc->avg.m_sched.m_currentMonth,
			pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame,
			t1, sc1, pDoc->avg.m_sched.m_series_win1, t2, sc2, pDoc->avg.m_sched.m_series_win2);


		delete disk;



	}

	m_pbp_lines = engine->GetTotalPbpResults();
	for (int i = 0; i <= m_pbp_lines; i++)
	{
		engine->GetPbpStrings(m_playByPlay);
	}

	for (int i = 0; i <= 2; i++)
	{
		m_score[i] = engine->GetScore(i);
		for (int j = 0; j <= 5; j++)
		{
			m_quarter_score[i][j] = engine->m_quarter_score[i][j];
		}
	}


	for (int i = 0; i <= 60; i++)
	{
		m_playing_players_list[i] = engine->GetPlayingPlayersList(i);
	}


	m_quarter = engine->GetQuarter();

	pDoc->m_game_type = engine->m_gameType;
	delete engine;

	m_engine_created = false;

	GetDlgItem(IDC_BUTTON_VISITOR_CARD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_HOME_CARD)->EnableWindow(FALSE);


	int stop = pDoc->ComputerManager();


}

void CBBallCoachView::StartGame()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	m_button_end.EnableWindow(TRUE);

	engine = new CEngine;
	m_engine_created = true;
	GetDlgItem(IDC_BUTTON_VISITOR_CARD)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_HOME_CARD)->EnableWindow(TRUE);
	m_over = false;

	int t1 = pDoc->m_coach_visitor_index;
	if (pDoc->avg.m_settings.m_control[t1 - 1] == "Player")
		m_auto_sub[1] = false;
	else
		m_auto_sub[1] = true;

	int t2 = pDoc->m_coach_home_index;
	if (pDoc->avg.m_settings.m_control[t2 - 1] == "Player")
		m_auto_sub[2] = false;
	else
		m_auto_sub[2] = true;


	engine->m_auto_sub[0] = m_auto_sub[0];
	engine->m_auto_sub[1] = m_auto_sub[1];
	engine->m_auto_sub[2] = m_auto_sub[2];

	for (int i = 0; i <= 306; i++)
	{
		engine->m_injury_table[i] = pDoc->m_injury_table[i];

	}

	pDoc->m_coached_game_underway = true;
	m_static_sub.EnableWindow(TRUE);

	m_button_play.EnableWindow(TRUE);
	m_button_sim.EnableWindow(TRUE);
	m_list_pbp.ResetContent();
	m_list_home_roster.DeleteAllItems();
	m_list_visitor_roster.DeleteAllItems();



}

void CBBallCoachView::ListStrings()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int speed = m_sim_speed.GetPos();
	engine->m_play_over = true;
	engine->FillPbp("");
	engine->m_play_over = false;


	if (engine->m_gameOver == true || speed < 100)
	{



		CString pbp_strings[3201];
		engine->GetPbpStrings(pbp_strings);
		int i = 0;
		for (i = engine->m_before_pbp_lines; i <= engine->GetTotalPbpResults(); i++)
		{
			if (pbp_strings[i] != "") m_list_pbp.AddString(pbp_strings[i]);
			double ctr = (double)speed / 99.;
			do
			{
				ctr = ctr + .000005 / 99.;
			} while (ctr <= 1. && m_sim_remainder == true);


		}
		engine->m_before_pbp_lines = i;
		int lines = m_list_pbp.GetCount();
		if (lines > 0) m_list_pbp.SetCurSel(lines - 1);
		DisplayRosters();
		DisplayLineups();
		DisplayScore();

		UpdateData(FALSE);

	}
}

void CBBallCoachView::InitControls()
{


	m_list_pbp.SetCurSel(0);
	m_list_pbp.SetFont(&m_font);

	m_list_visitor_roster.SetBkColor(ROWCOLOR1);
	m_list_visitor_roster.SetTextBkColor(TEXT_BK_COLOR);
	m_list_visitor_roster.SetTextColor(TEXTCOLOR);
	m_list_visitor_roster.SetFont(&m_font);

	m_list_home_roster.SetBkColor(BK_COLOR);
	m_list_home_roster.SetTextBkColor(BK_COLOR);
	m_list_home_roster.SetTextColor(CTRL_TEXT);
	m_list_home_roster.SetFont(&m_font);

	m_list_visitor_lineup.SetBkColor(BK_COLOR);
	m_list_visitor_lineup.SetTextBkColor(BK_COLOR);
	m_list_visitor_lineup.SetTextColor(CTRL_TEXT);
	m_list_visitor_lineup.SetFont(&m_font);


	m_list_scoreboard.SetBkColor(BK_COLOR);
	m_list_scoreboard.SetTextBkColor(BK_COLOR);
	m_list_scoreboard.SetTextColor(CTRL_TEXT);

	m_list_home_lineup.SetBkColor(BK_COLOR);
	m_list_home_lineup.SetTextBkColor(BK_COLOR);
	m_list_home_lineup.SetTextColor(CTRL_TEXT);
	m_list_home_lineup.SetFont(&m_font);

	m_list_home_shot.SetBkColor(BK_COLOR);
	m_list_home_shot.SetTextBkColor(BK_COLOR);
	m_list_home_shot.SetTextColor(CTRL_TEXT);
	m_list_home_shot.SetFont(&m_font);

	m_list_visitor_shot.SetBkColor(BK_COLOR);
	m_list_visitor_shot.SetTextBkColor(BK_COLOR);
	m_list_visitor_shot.SetTextColor(CTRL_TEXT);
	m_list_visitor_shot.SetFont(&m_font);




	UpdateData(FALSE);
}
void CBBallCoachView::SetMyFont(int weight, int height, CString font)
{
	LOGFONT lf;                        // Used to create the CFont.   
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.              
	lf.lfWeight = weight;
	lf.lfHeight = height;
	strcpy_s(lf.lfFaceName, font);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

}

void CBBallCoachView::SetMyFontStarters(int weight, int height, CString font)
{
	LOGFONT lf;                        // Used to create the CFont.   
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.              
	lf.lfWeight = weight;
	lf.lfHeight = height;
	strcpy_s(lf.lfFaceName, font);    //    with face name "Arial".
	m_font_starters.CreateFontIndirect(&lf);    // Create the font.
}

void CBBallCoachView::SetMyFontScores(int weight, int height, CString font)
{
	LOGFONT lf;                        // Used to create the CFont.   
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.              
	lf.lfWeight = weight;
	lf.lfHeight = height;
	strcpy_s(lf.lfFaceName, font);    //    with face name "Arial".
	m_font_scores.CreateFontIndirect(&lf);    // Create the font.
}

void CBBallCoachView::DisplayRosters()
{




	//	int t1 = engine->GetVisitorIndex();
	//	int t2 = engine->GetHomeIndex();
	//	int t1_offset = engine->GetVisitorPlayerOffset();
	//	int t2_offset = engine->GetHomePlayerOffset();


//		int player = 0;
	CString fg, ga, pt, rb, as, pf, en, o, d, exFg, exGa, exPt, exRb, exAs, exPf, exEn, exO, exD;
	for (int t = 0; t <= 1; t++)
	{
		int i = 0;
		for (int p = 1; p <= 30; p++)
		{
			int slot = engine->GetPlayingPlayersList(t * 30 + p);
			CPlayer m_player = engine->avg.m_actual[slot];
			m_player.SetLastName(m_player.GetName());
			CString name = m_player.GetLastName();
			if (name == "") continue;

			int fgm = m_player.GetGameFgm() + m_player.GetGameTfgm();
			fg.Format("%d", fgm);
			int fga = m_player.GetGameFga() + m_player.GetGameTfga();
			ga.Format("%d", fga);
			int pts = fgm * 2 + m_player.GetGameTfgm() + m_player.GetGameFtm();
			pt.Format("%d", pts);
			int reb = m_player.GetGameOreb() + m_player.GetGameDreb();
			rb.Format("%d", reb);
			int ast = m_player.GetGameAst();
			as.Format("%d", ast);
			int fouls = m_player.GetGamePf();
			pf.Format("%d", fouls);
			int stamina = m_player.m_game_stamina;
			stamina = (1000 + stamina) / 10;
			if (stamina > 100) stamina = 100;
			en.Format("%d", stamina);
			if (en == "100") en = "ok";
			int off = m_player.GetMovOff() + m_player.GetPenOff() + m_player.GetPostOff() + m_player.GetTransOff();
			o.Format("%d", off);
			int def = m_player.GetMovDef() + m_player.GetPenDef() + m_player.GetTransDef() + m_player.GetPostDef();
			d.Format("%d", def);
			i = i + 1;
			if (t == 0)
			{
				exPt = m_list_visitor_roster.GetItemText(i - 1, 1);
				exFg = m_list_visitor_roster.GetItemText(i - 1, 2);
				exGa = m_list_visitor_roster.GetItemText(i - 1, 3);
				exRb = m_list_visitor_roster.GetItemText(i - 1, 4);
				exAs = m_list_visitor_roster.GetItemText(i - 1, 5);
				exPf = m_list_visitor_roster.GetItemText(i - 1, 6);
				exEn = m_list_visitor_roster.GetItemText(i - 1, 7);
				exO = m_list_visitor_roster.GetItemText(i - 1, 8);
				exD = m_list_visitor_roster.GetItemText(i - 1, 9);

				if (exPt != pt)
					m_list_visitor_roster.SetItemText(i - 1, 1, pt);
				if (exFg != fg)
					m_list_visitor_roster.SetItemText(i - 1, 2, fg);
				if (exGa != ga)
					m_list_visitor_roster.SetItemText(i - 1, 3, ga);
				if (exRb != rb)
					m_list_visitor_roster.SetItemText(i - 1, 4, rb);
				if (exAs != as)
					m_list_visitor_roster.SetItemText(i - 1, 5, as);
				if (exPf != pf)
					m_list_visitor_roster.SetItemText(i - 1, 6, pf);
				if (exEn != en)
					m_list_visitor_roster.SetItemText(i - 1, 7, en);
				if (exO != o)
					m_list_visitor_roster.SetItemText(i - 1, 8, o);
				if (exD != d)
					m_list_visitor_roster.SetItemText(i - 1, 9, d);
			}
			else
			{
				exPt = m_list_home_roster.GetItemText(i - 1, 1);
				exFg = m_list_home_roster.GetItemText(i - 1, 2);
				exGa = m_list_home_roster.GetItemText(i - 1, 3);
				exRb = m_list_home_roster.GetItemText(i - 1, 4);
				exAs = m_list_home_roster.GetItemText(i - 1, 5);
				exPf = m_list_home_roster.GetItemText(i - 1, 6);
				exEn = m_list_home_roster.GetItemText(i - 1, 7);
				exO = m_list_home_roster.GetItemText(i - 1, 8);
				exD = m_list_home_roster.GetItemText(i - 1, 9);

				if (exPt != pt)
					m_list_home_roster.SetItemText(i - 1, 1, pt);
				if (exFg != fg)
					m_list_home_roster.SetItemText(i - 1, 2, fg);
				if (exGa != ga)
					m_list_home_roster.SetItemText(i - 1, 3, ga);
				if (exRb != rb)
					m_list_home_roster.SetItemText(i - 1, 4, rb);
				if (exAs != as)
					m_list_home_roster.SetItemText(i - 1, 5, as);
				if (exPf != pf)
					m_list_home_roster.SetItemText(i - 1, 6, pf);
				if (exEn != en)
					m_list_home_roster.SetItemText(i - 1, 7, en);
				if (exO != o)
					m_list_home_roster.SetItemText(i - 1, 8, o);
				if (exD != d)
					m_list_home_roster.SetItemText(i - 1, 9, d);
			}
		}

	}

}

void CBBallCoachView::DisplayRosterNames()
{




	for (int t = 0; t <= 1; t++)
	{
		int i = 0;
		for (int p = 1; p <= 30; p++)
		{
			int slot = engine->GetPlayingPlayersList(t * 30 + p);
			CPlayer m_player = engine->avg.m_actual[slot];
			m_player.SetLastName(m_player.m_name);
			CString name = m_player.GetLastName();
			if (name == "") continue;
			name = m_player.m_pos + " " + name;


			i = i + 1;
			if (t == 0)
				m_list_visitor_roster.InsertItem(i, name);
			else
				m_list_home_roster.InsertItem(i, name);
		}
	}
}

void CBBallCoachView::DisplayLineups()
{
	CString PositionNames[6] = { "", "PG", "SG", "SF", "PF", " C" };

	CPlayer m_player;

	//store initial players selected
	int v = m_list_visitor_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	int h = m_list_home_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	m_list_visitor_lineup.DeleteAllItems();
	m_list_home_lineup.DeleteAllItems();
	for (int team = 1; team <= 2; team++)
	{

		int otherTeam = 2;
		if (team == 2) otherTeam = 1;
		double factor = 1. / 4.;
		if (team == 1)
		{
			m_list_visitor_lineup.InsertItem(0, "Auto");
			m_list_visitor_lineup.SetItemText(0, 1, "");
		}
		else if (team == 2)
		{
			factor = 3. / 5.;
			m_list_home_lineup.InsertItem(0, "Auto");
			m_list_home_lineup.SetItemText(0, 1, "");
		}
		for (int i = 1; i <= 5; i++)
		{
			int player = engine->GetOffensiveLineup(team, i);
			//			int defender = engine->GetDefensiveLineup(otherTeam, i);
			int defender = engine->GetDefensiveLineup(team, i);
			CString name = engine->avg.m_actual[player].GetName();
			CString nameDef = engine->avg.m_actual[defender].GetName();




			CString position = PositionNames[i];

			if (name != "" && team == 1)
			{
				m_list_visitor_lineup.InsertItem(i, position);
				m_list_visitor_lineup.SetItemText(i, 1, name);
				m_list_visitor_lineup.SetItemText(i, 2, nameDef);
			}
			else if (name != "" && team == 2)
			{
				m_list_home_lineup.InsertItem(i, position);
				m_list_home_lineup.SetItemText(i, 1, name);
				m_list_home_lineup.SetItemText(i, 2, nameDef);
			}

		}

	}
	//restore initial selections
	if (v == -1) v = 0;
	if (h == -1) h = 0;
	m_list_visitor_lineup.SetItemState(v, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_home_lineup.SetItemState(h, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);





}

void CBBallCoachView::DisplayScore()
{
	CString PositionNames[6] = { "", "PG", "SG", "SF", "PF", " C" };
	//	SetMyFont(1050, 13, "Arial");
	//	CNbaDoc* pDoc = GetDocument();
	  //	ASSERT_VALID(pDoc); 

	CString m_visitorScore;
	CString m_homeScore;
	CString quarterString;
	CString minutesString;
	CString secondsString;
	CString time;
	CString v, h;
	minutesString = "";
	CString vi = engine->GetGameTeamNames(1);
	CString ho = engine->GetGameTeamNames(2);

	int minutes = engine->GetTime() / 60;
	int seconds = engine->GetTime() - minutes * 60;
	int quarter = engine->GetQuarter();

	minutesString.Format("%d", minutes);
	secondsString.Format("%d", seconds);
	quarterString.Format("%d", quarter);


	if (seconds < 10) secondsString = "0" + secondsString;
	if (quarter == 1) quarterString = "1st";
	else if (quarter == 2) quarterString = "2nd";
	else if (quarter == 3) quarterString = "3rd";
	else if (quarter == 4) quarterString = "4th";
	else quarterString = "OT ";

	if (minutes < 10)
		time = quarterString + "         " + minutesString + ":" + secondsString;
	else time = quarterString + "        " + minutesString + ":" + secondsString;

	m_visitorScore.Format("%d", engine->GetGameScore(1));
	m_homeScore.Format("%d", engine->GetGameScore(2));

	//	engine->m_scoreString =
	//		time + "\n" + pDoc->m_visitor + " " + m_visitorScore + " " +
	//		pDoc->m_home + " " + m_homeScore;



	int rec_win1 = engine->avg.m_standings[engine->GetGamePossessionTeamIndex(1) - 1].m_leagueRecord / 100;
	int rec_loss1 = engine->avg.m_standings[engine->GetGamePossessionTeamIndex(1) - 1].m_leagueRecord - rec_win1 * 100;
	int rec_win2 = engine->avg.m_standings[engine->GetGamePossessionTeamIndex(2) - 1].m_leagueRecord / 100;
	int rec_loss2 = engine->avg.m_standings[engine->GetGamePossessionTeamIndex(2) - 1].m_leagueRecord - rec_win2 * 100;
	v.Format("%s (%d-%d)", vi, rec_win1, rec_loss1);
	h.Format("%s (%d-%d)", ho, rec_win2, rec_loss2);

	if (engine->GetPossession() == 1) v = v + "*"; else h = h + "*";
	m_list_scoreboard.DeleteAllItems();
	m_list_scoreboard.InsertItem(0, v);
	m_list_scoreboard.SetItemText(0, 1, time);
	m_list_scoreboard.SetItemText(0, 2, h);
	m_list_scoreboard.InsertItem(1, m_visitorScore);
	m_list_scoreboard.SetItemText(1, 2, m_homeScore);

	/*
		m_static_visitor.SetBkColor(LIGHTBLUE);
		m_static_visitor.SetColor(LIGHTBLUE, WHITE);
		m_static_visitorscore.SetBkColor(BLACK);
		m_static_visitorscore.SetColor(BLACK, WHITE);
		m_static_home.SetBkColor(LIGHTBLUE);
		m_static_home.SetColor(LIGHTBLUE, WHITE);
		m_static_homescore.SetBkColor(BLACK);
		m_static_homescore.SetColor(BLACK, WHITE);
		m_static_time.SetBkColor(LIGHTBLUE);
		m_static_time.SetColor(LIGHTBLUE, WHITE);
		*/


	m_static_visitor.SetWindowText(v);
	m_static_visitorscore.SetWindowText(m_visitorScore);
	m_static_home.SetWindowText(h);
	m_static_homescore.SetWindowText(m_homeScore);
	m_static_time.SetWindowText(time);



	/*	m_Digistring.SetColor(DARKRED, LIGHTRED);
		m_Digistring.SetText(m_LedEdit);
		m_Digistring.SetTransparent(TRUE);
		VERIFY(m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14 | CDigiStatic::DS_SZ_PROP | CDigiStatic::DS_NO_OFF));

		m_ScrollText.SetScrollText(_T(" Show must go on -"));
		m_ScrollText.SetColor(DARKCYAN, LIGHTCYAN);
		VERIFY(m_ScrollText.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14));
		*/

		//	m_ScrollText.SetSpeed(500); 
		//	m_ScrollText.SetTextLength(12); 
		//	m_ScrollText.Scroll(TRUE); 

			//m_Text2.SetBkColor(LIGHTBLUE);
		//	m_Text2.SetColor(LIGHTBLUE, WHITE);
		//	VERIFY(m_Text2.ModifyDigiStyle(0, CDigiStatic::DS_NO_OFF));
			//m_Text2.Format(_T("%6.3lf"), 56.873);





}

void CBBallCoachView::OnBegindragListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	HD_NOTIFY* phdn = (HD_NOTIFY*)pNMHDR;
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void CBBallCoachView::OnEnddragListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	HD_NOTIFY* phdn = (HD_NOTIFY*)pNMHDR;
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void CBBallCoachView::OnColumnclickListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void CBBallCoachView::OnBegindragListHomeRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here




	*pResult = 0;
}

void CBBallCoachView::Coach()
{
	int i = 0, t = 0, typeShot = OUTSIDE;
	if (engine->GetPossession() == 1)
		i = m_list_visitor_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	else
		i = m_list_home_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (engine->GetPossession() == 2)
		t = m_list_visitor_shot.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	else
		t = m_list_home_shot.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (t < 0) t = 0;

	if (t == 0)
		typeShot = AUTO;
	else if (t == 2)
		typeShot = OUTSIDE;
	else if (t == 3)
		typeShot = PENETRATION;
	else if (t == 4)
		typeShot = INSIDE;
	else if (t == 1)
		typeShot = THREE;

	engine->m_player_selected_ball_handler = i;

	engine->m_player_selected_type_shot = typeShot;
}

void CBBallCoachView::OnDblclkListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here

	if (m_engine_created == TRUE)
	{


		if (engine->m_sub_ok == true)
		{

			CString PositionNames[6] = { "", "PG ", "SG ", "SF ", "PF ", " C " };
			CString player;
			BOOL NoSub = FALSE;

			int lineupIndex = m_list_visitor_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
			int rosterIndex = m_list_visitor_roster.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

			//	int offset = engine->GetVisitorPlayerOffset() + rosterIndex + 1;
			int offset = engine->GetPlayingPlayersList(rosterIndex + 1);
			CPlayer m_player = engine->avg.m_actual[offset];
			if (m_player.GetGamePf() >= 6 || m_player.GetGameInjury() > 0 || lineupIndex <= 0) NoSub = TRUE;

			for (int i = 1; i <= 5; i++) //check for duplicate
			{
				if (engine->GetOffensiveLineup(VISITOR, i) == offset) NoSub = TRUE;

			}
			if (lineupIndex >= 0 && rosterIndex >= 0 && NoSub == FALSE)
			{
				engine->SetOffensiveLineup(VISITOR, lineupIndex, offset);
				engine->m_must_sub[1] = 0;
			}


			DisplayLineups();
			m_list_visitor_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
			m_list_home_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);


		}
	}
	*pResult = 0;
}

void CBBallCoachView::OnDblclkListHomeRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
//	if(!engine == NULL)
//	{
	if (m_engine_created == TRUE)
	{

		if (engine->m_sub_ok == true)
		{


			CString PositionNames[6] = { "", "PG ", "SG ", "SF ", "PF ", " C " };
			CString player;
			BOOL NoSub = FALSE;

			int lineupIndex = m_list_home_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
			int rosterIndex = m_list_home_roster.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

			//	int offset = engine->GetHomePlayerOffset() + rosterIndex + 1;
			int offset = engine->GetPlayingPlayersList(rosterIndex + 31);

			CPlayer m_player = engine->avg.m_actual[offset];
			if (m_player.GetGamePf() >= 6 || m_player.GetGameInjury() > 0 || lineupIndex <= 0) NoSub = TRUE;

			for (int i = 1; i <= 5; i++) //check for duplicate
			{
				if (engine->GetOffensiveLineup(HOME, i) == offset) NoSub = TRUE;
			}
			if (lineupIndex >= 0 && rosterIndex >= 0 && NoSub == FALSE)
			{
				engine->SetOffensiveLineup(HOME, lineupIndex, offset);
				engine->m_must_sub[2] = 0;
			}


			DisplayLineups();
			m_list_visitor_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
			m_list_home_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);

		}

	}
	*pResult = 0;
}




BOOL CBBallCoachView::OnEraseBkgnd(CDC* pDC)
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
//		bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");

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
   return TRUE;
   */


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





	//	return CDialog::OnEraseBkgnd(pDC);
}


void CBBallCoachView::OnButtonBack()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(1);
}



void CBBallCoachView::OnButtonEnd()
{
	// TODO: Add your control notification handler code here


	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	//	pDoc->m_game_type = engine->m_gameType;


	if (m_over != true)
	{
		delete engine;
		m_engine_created = false;
		pDoc->m_coached_game_underway = false;
	}

	((CBBallApp*)AfxGetApp())->SwitchView(1);

}

void CBBallCoachView::OnButtonBox()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	CStatsDlg* stats = new CStatsDlg;


	stats->m_factor = pDoc->avg.m_avg_tru[0];
	stats->m_game_type = pDoc->m_game_type;


	stats->m_visitor_index = pDoc->m_coach_visitor_index - 1;
	stats->m_home_index = pDoc->m_coach_home_index - 1;
	stats->m_visitor = pDoc->avg.m_settings.m_leagueTeamNames[stats->m_visitor_index];//pass visiting team name to stats dialog box
	stats->m_home = pDoc->avg.m_settings.m_leagueTeamNames[stats->m_home_index];//pass visiting team name to stats dialog box

	if (stats->m_game_type == ALLSTAR)
	{
		stats->m_visitor_index = 0;
		stats->m_home_index = 1;
		stats->m_visitor = pDoc->avg.m_settings.m_conferenceName1;
		stats->m_home = pDoc->avg.m_settings.m_conferenceName2;
	}
	else if (stats->m_game_type == ROOKIE)
	{
		stats->m_visitor_index = 0;
		stats->m_home_index = 1;
		stats->m_visitor = "Rookies";
		stats->m_home = "Sophomores";
	}


	stats->m_saved_box = false;

	stats->m_att = pDoc->avg.m_finance[stats->m_home_index].m_tickets_sold +
		pDoc->avg.m_finance[stats->m_home_index].m_clubs_sold +
		pDoc->avg.m_finance[stats->m_home_index].m_suites_sold * 20;

	stats->m_cap = pDoc->avg.m_finance[stats->m_home_index].m_capacity;




	//da = 30;
	//mo = 12;
	//ga = 0;

	if (pDoc->m_coached_game_underway == false && stats->m_game_type == EXHIBITION)
	{
		stats->m_saved_box = true;
		stats->m_mo = 12;
		stats->m_da = 30;
		stats->m_ga = 0;
		//		stats->SetPtr(pDoc->avg);
		stats->avg = pDoc->avg;
	}
	else if (pDoc->m_coached_game_underway == false && stats->m_game_type == ROOKIE)
	{
		stats->m_saved_box = true;
		stats->m_mo = 0;
		stats->m_da = 0;
		stats->m_ga = 0;
		//stats->SetPtr(pDoc->avg);
		stats->avg = pDoc->avg;
	}
	else if (pDoc->m_coached_game_underway == false && stats->m_game_type == ALLSTAR)
	{
		stats->m_saved_box = true;
		stats->m_mo = 0;
		stats->m_da = 0;
		stats->m_ga = 1;
		//stats->SetPtr(pDoc->avg);
		stats->avg = pDoc->avg;
	}
	else if (pDoc->m_coached_game_underway == false)
	{
		//stats->SetPtr(pDoc->avg);
		stats->avg = pDoc->avg;
		stats->m_lines = m_pbp_lines;
		for (int i = 0; i <= stats->m_lines; i++)
		{
			stats->m_playByPlay[i] = m_playByPlay[i];
		}
		for (int i = 0; i <= 2; i++)
		{
			stats->m_score[i] = m_score[i];
			for (int j = 0; j <= 5; j++)
			{
				stats->m_quarter_score[i][j] = m_quarter_score[i][j];
			}
		}


		for (int i = 0; i <= 60; i++)
		{
			stats->m_playing_players_list[i] = m_playing_players_list[i];
		}

		stats->m_quarter = m_quarter;

	}
	else
	{
		engine->SetMinutesPlayedStat();
		stats->avg = engine->avg;
		//tats->SetPtr(pDoc->avg);
		stats->m_lines = engine->GetTotalPbpResults();

		CString pbp_strings[3201];
		engine->GetPbpStrings(pbp_strings);
		for (int i = 0; i <= stats->m_lines; i++)
		{
			stats->m_playByPlay[i] = pbp_strings[i];
		}
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 5; j++)
			{
				stats->m_quarter_score[i][j] = engine->m_quarter_score[i][j];
			}
		}


		for (int i = 0; i <= 60; i++)
		{
			int j = engine->GetPlayingPlayersList(i);
			int k = engine->avg.m_actual[j].m_original_number;
			stats->m_playing_players_list[i] = k;
		}

		stats->m_score[0] = 0;
		stats->m_score[1] = engine->GetScore(1);
		stats->m_score[2] = engine->GetScore(2);
		stats->m_quarter = engine->GetQuarter();
	}

	stats->m_v_click = false;

	stats->DoModal();
	delete stats;
}

void CBBallCoachView::OnCheckAutoHome()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (m_auto_sub[2] == FALSE)
		m_auto_sub[2] = TRUE;
	else
		m_auto_sub[2] = FALSE;

	if (pDoc->m_coached_game_underway == TRUE)
		engine->m_auto_sub[2] = m_auto_sub[2];

	UpdateData(FALSE);

}

void CBBallCoachView::OnCheckAutoVisitor()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (m_auto_sub[1] == FALSE)
		m_auto_sub[1] = TRUE;
	else
		m_auto_sub[1] = FALSE;

	if (pDoc->m_coached_game_underway == TRUE)
		engine->m_auto_sub[1] = m_auto_sub[1];

	UpdateData(FALSE);
}

void CBBallCoachView::SubBox()
{
	CString str, name;
	if (engine->m_must_sub[1] > 0)
		name = engine->avg.m_actual[engine->m_must_sub[1]].m_name;
	else if (engine->m_must_sub[2] > 0)
		name = engine->avg.m_actual[engine->m_must_sub[2]].m_name;

	str = name + " must be removed from the lineup";
	engine->m_sub_ok = true;
	m_static_sub.EnableWindow(TRUE);
	AfxMessageBox(str, MB_OK);
}


void CBBallCoachView::OnButtonDefense()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	if (pDoc->m_coached_game_underway == true)
	{

		CDefenseDlg* def = new CDefenseDlg;
		def->m_visitor = engine->m_team_names[1];
		def->m_home = engine->m_team_names[2];
		def->m_possesion = engine->GetPossession();
		def->avg = pDoc->avg;

		for (int i = 1; i <= 10; ++i)
		{
			def->m_match[i] = engine->m_match[i];
		}
		for (int t = 1; t <= 2; t++)
		{
			for (int p = 1; p <= 5; p++)
			{
				def->Defense[t][p] = engine->GetDefensiveLineup(t, p);
				def->Lineup[t][p] = engine->GetOffensiveLineup(t, p);
			}
		}

		int	v_l = m_list_visitor_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		int h_l = m_list_home_lineup.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		if (def->m_possesion == 1)
		{
			def->m_index = v_l;
			def->m_other_index = h_l;
		}
		else
		{
			def->m_index = h_l;
			def->m_other_index = v_l;
		}



		if (def->m_index < 1) def->m_index = 0; else def->m_index = def->m_index - 1;
		if (def->m_other_index < 1) def->m_other_index = 0; else def->m_other_index = def->m_other_index - 1;
		def->m_visitor_index = engine->GetVisitorIndex();
		def->m_home_index = engine->GetHomeIndex();
		int result = def->DoModal();

		if (result == IDOK)
		{
			if (engine->GetPossession() == 1)
				m_list_visitor_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
			else if (engine->GetPossession() == 1)
				m_list_home_lineup.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);


			for (int t = 1; t <= 2; t++)
			{
				for (int p = 1; p <= 5; p++)
				{
					engine->SetDefensiveLineup(t, p, def->Defense[t][p]);
				}
			}
			for (int i = 1; i <= 10; ++i)
			{
				engine->m_match[i] = def->m_match[i];
			}
			DisplayLineups();
		}
		delete def;
	}

}

void CBBallCoachView::OnReleasedcaptureSliderSpeed(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->avg.m_settings.m_sim_speed = m_sim_speed.GetPos();

	*pResult = 0;
}

void CBBallCoachView::OnButtonTo()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	if (pDoc->m_coached_game_underway == true)
	{

		CTimeoutDlg to;
		to.m_visitor = engine->m_team_names[1];
		to.m_home = engine->m_team_names[2];
		to.m_toVisitor = engine->m_toVisitor;
		to.m_toHome = engine->m_toHome;
		to.m_toVisitor20 = engine->m_toVisitor20;
		to.m_toHome20 = engine->m_toHome20;
		to.m_pos = engine->GetPossession();
		to.m_toOk = engine->m_toOk;
		int result = to.DoModal();
		if (result == IDOK)
		{
			engine->m_sub_ok = true;
			engine->m_toVisitor = to.m_toVisitor;
			engine->m_toHome = to.m_toHome;
			engine->m_toVisitor20 = to.m_toVisitor20;
			engine->m_toHome20 = to.m_toHome20;
			engine->m_homeTo20 = to.m_homeTo20;
			engine->m_homeTo = to.m_homeTo;
			engine->m_visitorTo20 = to.m_visitorTo20;
			engine->m_visitorTo = to.m_visitorTo;

			for (int i = 1; i <= 60; i++)
			{
				int pl = engine->GetPlayingPlayersList(i);
				int staminaRating = engine->avg.m_actual[pl].m_stamina;
				int staminaGame = engine->avg.m_actual[pl].m_game_stamina;
				int rest = 0;
				if (engine->m_visitorTo == true || engine->m_homeTo == true) rest = 50;
				if (engine->m_visitorTo20 == true || engine->m_homeTo20 == true) rest = 20;
				engine->avg.m_actual[pl].SetGameCurrentStamina(staminaGame + rest);//time resting
				staminaGame = engine->avg.m_actual[pl].GetGameCurrentStamina();
				if (staminaGame > staminaRating) engine->avg.m_actual[pl].SetGameCurrentStamina(staminaRating);
			}

			DisplayRosters();


			//	if(engine->m_visitorTo == true || engine->m_visitorTo20 == true ||
			//		engine->m_homeTo == true || engine->m_visitorTo20 == true)
			//		{
			//			engine->m_toCalled = true;
			//			m_toButton->EnableWindow(FALSE);
			//		}
		}

	}

}

void CBBallCoachView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CBBallCoachView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);


}

void CBBallCoachView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here



}

void CBBallCoachView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CBBallCoachView::OnButtonVisitorCard()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int i = m_list_visitor_roster.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) + 1;
	int j = m_list_visitor_roster.GetItemCount();



	if (i > 0 && j > 0 && m_over == false)
	{


		CPlayerCardDlg* scout = new CPlayerCardDlg;
		scout->m_default_scout = pDoc->m_coach_visitor_index - 1;

		scout->m_path = pDoc->avg.m_settings.m_path;
		scout->m_leagueName = pDoc->avg.m_settings.m_league_name;

		scout->m_title = "Coach";
		scout->avg = engine->avg;

		for (int c = 0; c <= 15; c++)
		{

			int slot = engine->GetPlayingPlayersList(1 + c);
			CPlayer m_player = engine->avg.m_actual[slot];

			scout->avg.m_actual[c] = m_player;
		}
		scout->m_player_index = i - 1;
		scout->m_pl_index_end = 15;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;
	}


}

void CBBallCoachView::OnButtonHomeCard()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int i = m_list_home_roster.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) + 1;
	int j = m_list_home_roster.GetItemCount();



	if (i > 0 && j > 0 && m_over == false)
	{


		CPlayerCardDlg* scout = new CPlayerCardDlg;
		scout->m_default_scout = pDoc->m_coach_home_index - 1;

		scout->m_path = pDoc->avg.m_settings.m_path;
		scout->m_leagueName = pDoc->avg.m_settings.m_league_name;

		scout->m_title = "Coach";
		scout->avg = engine->avg;

		for (int c = 0; c <= 15; c++)
		{

			int slot = engine->GetPlayingPlayersList(31 + c);
			CPlayer m_player = engine->avg.m_actual[slot];

			scout->avg.m_actual[c] = m_player;
		}
		scout->m_player_index = i - 1;
		scout->m_pl_index_end = 15;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;
	}



}

BOOL CBBallCoachView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default

//	HtmlHelp(NULL, "jumpshot.chm::/html/coach.htm", HH_DISPLAY_TOPIC, 0);

//	return CDialog::OnHelpInfo(pHelpInfo);
	ShellExecute(NULL, "open", "html\\coach.htm", NULL, NULL, SW_SHOWNORMAL);

	return CFormView::OnHelpInfo(pHelpInfo);
}

void CBBallCoachView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	//HtmlHelp(NULL, "jumpshot.chm::/html/coach.htm", HH_DISPLAY_TOPIC, 0);

	//return CFormView::OnHelpInfo(pHelpInfo);

}

HBRUSH CBBallCoachView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		myBrush2.GetLogBrush(&logbrush);
		pDC->SetTextColor(RGB(255, 215, 0));
		pDC->SetBkColor(logbrush.lbColor);
		return myBrush2;

		


		//This shouldn't occurr since we took all the cases, but
		//JUST IN CASE, return the new brush
	default:
		return hbr;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CBBallCoachView::OnUpdateSetupLoad(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();	

//	if(pDoc->m_default_opened == true) 
	pCmdUI->Enable(FALSE);
	//	else


}

void CBBallCoachView::OnUpdateSetupProposetrade(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);

}

void CBBallCoachView::OnUpdateSetupSettings(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);

}

void CBBallCoachView::OnButtonVisitorplan()
{
	// TODO: Add your control notification handler code here
	CallGamePlan(1);
}

void CBBallCoachView::OnButtonHomeplan()
{
	// TODO: Add your control notification handler code here
	CallGamePlan(2);

}

void CBBallCoachView::CallGamePlan(int t)
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (m_engine_created == TRUE)
	{
		pDoc->m_combo_team_index = engine->m_possesion_team_index[t];

		if (pDoc->m_coached_game_underway == false && t == 1)
		{

			int t = pDoc->m_coach_visitor_index;
			pDoc->m_combo_team_index = t;
		}
		else if (pDoc->m_coached_game_underway == false && t == 2)
		{

			int t = pDoc->m_coach_home_index;
			pDoc->m_combo_team_index = t;
		}


		//int result = pDoc->GamePlan();

		CReportDlg* report = new CReportDlg;
		report->m_in_game = true;
		report->m_default_team = pDoc->m_combo_team_index - 1;
		if (report->m_default_team < 0) 	report->m_default_team = 0;

		report->m_path = pDoc->avg.m_settings.m_path;
		report->m_league_name = pDoc->avg.m_settings.m_league_name;

		report->avg = engine->avg;
		for (int i = 0; i <= 60; i++)
		{
			int slot = engine->GetPlayingPlayersList(i);
			report->avg.m_actual[slot] = engine->avg.m_actual[slot];
		}


		for (int i = 0; i <= 32; i++)
		{
			report->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		}

		//report->m_plan = m_game_plan;



		int result = report->DoModal();




		if (result == IDOK)
		{
			for (int i = 0; i <= 60; i++)
			{
				int slot = engine->GetPlayingPlayersList(i);
				engine->avg.m_actual[slot].SetPgRot(report->avg.m_actual[slot].GetPgRot());
				engine->avg.m_actual[slot].SetSgRot(report->avg.m_actual[slot].GetSgRot());
				engine->avg.m_actual[slot].SetSfRot(report->avg.m_actual[slot].GetSfRot());
				engine->avg.m_actual[slot].SetPfRot(report->avg.m_actual[slot].GetPfRot());
				engine->avg.m_actual[slot].SetCRot(report->avg.m_actual[slot].GetCRot());
				engine->avg.m_actual[slot].m_game_minutes = report->avg.m_actual[slot].m_game_minutes;
				engine->avg.m_actual[slot].m_offensive_focus = report->avg.m_actual[slot].m_offensive_focus;
				engine->avg.m_actual[slot].m_defensive_focus = report->avg.m_actual[slot].m_defensive_focus;
				engine->avg.m_actual[slot].m_offensive_intensity = report->avg.m_actual[slot].m_offensive_intensity;
				engine->avg.m_actual[slot].m_defensive_intensity = report->avg.m_actual[slot].m_defensive_intensity;
				engine->avg.m_actual[slot].m_play_maker = report->avg.m_actual[slot].m_play_maker;

			}

			engine->SetupComputerLineups();
		}

		delete report;

	}
}

void CBBallCoachView::OnUpdateSetupSetgameplan(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);

}


void CBBallCoachView::OnTeamRoster()
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

void CBBallCoachView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallCoachView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}






void CBBallCoachView::OnStnClickedStaticHome()
{
	// TODO: Add your control notification handler code here
}


void CBBallCoachView::OnLvnItemchangedListScoreboard(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CBBallCoachView::OnStnClickedStaticTlabel()
{
	// TODO: Add your control notification handler code here
}


void CBBallCoachView::OnLvnItemchangedListHomeShot(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CBBallCoachView::OnLbnSelchangeListPbp()
{
	// TODO: Add your control notification handler code here
}
