// ProgressView.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "MyComboBox.h"
#include "ProgressView.h"
#include "bballdoc.h"
#include "FranchiseChangeDlg.h"
#include "BudgetSheetDlg.h"
#include "LeagueTeamsDlg.h"
#include "CampDlg.h"
#include "RegisterDlg.h"
#include "AwardsDlg.h"
#include "Awards.h"
#include "Disk.h"
#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 
//#include "high.h"
#ifndef High_h
#include "High.h"
#define High_h
#endif 
#include "BBallFile.h"
#include "Playoff.h"
#include "FreeAgentDlg.h"
#include "RookieDlg.h"
#include "StaffDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressView

IMPLEMENT_DYNCREATE(CProgressView, CFormView)

CProgressView::CProgressView()
	: CFormView(CProgressView::IDD)
{
	//{{AFX_DATA_INIT(CProgressView)
		// NOTE: the ClassWizard will add member initialization here
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




}

CProgressView::~CProgressView()
{
	delete m_bmp;

}

void CProgressView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressView)
	DDX_Control(pDX, IDC_BUTTON_EXPAND, m_button_expand);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_STAFFS, m_button_staffs);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_ROOKIES, m_button_rookies);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_FA, m_button_fa);
	DDX_Control(pDX, IDC_BUTTON_END, m_button_end);
	DDX_Control(pDX, IDC_BUTTON_CAMP, m_button_camp);
	DDX_Control(pDX, IDC_BUTTON_BUDGET_SHEET, m_button_budget);
	DDX_Control(pDX, IDC_BUTTON_ARENA, m_button_arena);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressView, CFormView)
	//{{AFX_MSG_MAP(CProgressView)
	ON_WM_ERASEBKGND()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_ARENA, OnButtonArena)
	ON_BN_CLICKED(IDC_BUTTON_BUDGET_SHEET, OnButtonBudgetSheet)
	ON_BN_CLICKED(IDC_BUTTON_CAMP, OnButtonCamp)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_FA, OnButtonFa)
	ON_BN_CLICKED(IDC_BUTTON_ROOKIES, OnButtonRookies)
	ON_BN_CLICKED(IDC_BUTTON_STAFFS, OnButtonStaffs)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_EXPAND, OnButtonExpand)
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
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressView diagnostics

#ifdef _DEBUG
void CProgressView::AssertValid() const
{
	CFormView::AssertValid();
}

void CProgressView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgressView message handlers

void CProgressView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	//UpdateWindow();
	if (bShow == TRUE) InitControls();
}

void CProgressView::OnInitialUpdate()
{
	//	CFormView::OnInitialUpdate();

		// TODO: Add your specialized code here and/or call the base class
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();




	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	CFormView::OnInitialUpdate();




	myBrush.CreateSolidBrush(DLGCOLOR);

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









	CheckButtons();


	// Resize parent to fit dialog template exactly    
	// while not resizing beyond size of screen
	VERIFY(pFrame = GetParentFrame());
	pFrame->GetClientRect(rectFrame);
	GetClientRect(rectView);
	//    if ( rectFrame.Width() < rectView.Width()
	  //       || rectFrame.Height() < rectView.Height() )
	   // {        
			// Resize so can be refit to any template that fits the screen
	//        pFrame->MoveWindow( 0, 0, GetSystemMetrics(SM_CXSCREEN), 
	//                        GetSystemMetrics(SM_CYSCREEN), FALSE ); 

	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);
	//if(w > 1023) w = 1023;
	//if(h > 750) h = 750;
//        pFrame->MoveWindow( 0, 0, w, h, FALSE ); 


	//pFrame->SetWindowPos(NULL, 0, 0, w, h, FALSE);



	// }
	//pFrame->RecalcLayout();
	////ResizeParentToFit(TRUE);    // Shrink to fit template 







	if (pDoc->m_program_started == false && pDoc->avg.m_settings.m_leagueTeamNames[1] == "")
	{
		pDoc->m_program_started = true;
		CString str1 = pDoc->m_default_path;
		CString str2 = pDoc->m_default_league;
		pDoc->OpenGameData(str1, str2);


	}

}

BOOL CProgressView::SetToDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	// Allow for data validation    
	if (!UpdateData(TRUE))
		return FALSE;



	return TRUE;

}

void CProgressView::SetFromDoc()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();


	UpdateData(FALSE);    // Set controls to these
}

void CProgressView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}

void CProgressView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);
}

void CProgressView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CProgressView::OnButtonSetup()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(0);

}

void CProgressView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(1);

}

void CProgressView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
//	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(4);

}

void CProgressView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::InitControls()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();




	//	m_default_team  = pDoc->m_combo_team_index;
	//UpdateWindow();




	m_combo_teams.ResetContent();

	m_combo_teams.AddString("All Teams");

	for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
	{
		CString team_name = pDoc->avg.m_settings.m_leagueTeamNames[i];
		if (team_name != "")
			//	m_combo_teams.AddString(team_name);
			m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
	}

	m_combo_teams.SetCurSel(pDoc->m_combo_team_index);

	//			result.Format
	//				("%-16s %3s %3s %3s % 4s %3s %3s %3s %3s %3s %3s %3s %3s",
	//				teamName,leagueWin,leagueLoss,leaguePct,gamesBack,conferenceWin,conferenceLoss,
	//				divisionWin,divisionLoss,homeWin,homeLoss,visitorWin,visitorLoss);

	CheckButtons();

	RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);


	//	Invalidate(TRUE);


}

void CProgressView::OnButtonArena()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CFranchiseChangeDlg* change = new CFranchiseChangeDlg;

	///if(m_current_stage == 0)
	//	change->m_ok = false;
	//else
	change->m_ok = true;

	for (int i = 0; i <= 1600; i++)
	{
		change->m_actual[i] = pDoc->avg.m_actual[i];
	}


	change->m_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;
	//change->avg = pDoc->avg;
	change->m_number_teams = pDoc->avg.m_settings.m_numberteams;
	change->m_path = pDoc->avg.m_settings.m_path;
	change->m_league_name = pDoc->avg.m_settings.m_league_name;
	change->m_tru = pDoc->avg.m_team_avg_tru[0];
	int hi_g = pDoc->avg.m_sched.m_games_in_season;
	change->m_hi_games = hi_g;


	for (int i = 0; i <= 200; i++)
	{
		change->m_finance[i] = pDoc->avg.m_finance[i];
		change->m_finance[i].m_original_slot = i;
	}

	for (int i = 0; i <= 32; i++)
	{
		change->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
		change->m_standings[i] = pDoc->avg.m_standings[i];
		change->m_coach[i] = pDoc->avg.m_coach[i];
	}

	//	change->m_default_team = pDoc->m_combo_team_index;
	change->m_default_team = pDoc->m_combo_team_index - 1;
	if (change->m_default_team < 0) change->m_default_team = 0;


	int result = change->DoModal();
	if (result == IDOK)
	{
		//		m_current_stage = 7;			
		for (int i = 0; i <= 200; i++)
		{
			pDoc->avg.m_finance[i] = change->m_finance[i];
		}
		pDoc->avg.m_settings.m_current_stage = 7;



		CString file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".frn";
		CString future_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".fut";


		//CDisk* disk = new CDisk;
		//for(int i=0; i<=99; i++)
		//{
		//	disk->avg.m_finance[i] = pDoc->avg.m_finance[i];		
		//}
		//disk->WriteFranchiseData(file_name,0,100);
		//delete disk;

		CBBallFile* file = new CBBallFile;
		file->WriteFutureFile(change->m_future, future_file_name);
		delete file;


		CheckButtons();

		//		m_programStarted = false;
	}
	delete change;
}

void CProgressView::OnButtonBudgetSheet()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CBudgetSheetDlg* bud = new CBudgetSheetDlg;
	bud->m_ok = true;



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


	//	bud->m_default_team = pDoc->m_combo_team_index;
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
		pDoc->avg.m_settings.m_current_stage = 6;
		CheckButtons();

	}
	delete bud;


}

void CProgressView::OnButtonCamp()
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();





	CCampDlg* roo;
	roo = new CCampDlg;
	roo->avg = pDoc->avg;
	roo->m_finances_on = pDoc->avg.m_settings.m_financial_on;
	for (int i = 0; i <= 32; i++)
	{
		roo->m_standings[i] = pDoc->avg.m_standings[i];
	}

	for (int i = 0; i <= (pDoc->avg.m_settings.m_numberteams - 1); i++)
	{
		roo->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		roo->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
	}
	roo->m_numberteams = pDoc->avg.m_settings.m_numberteams;
	roo->m_path = pDoc->avg.m_settings.m_path;
	roo->m_leagueName = pDoc->avg.m_settings.m_league_name;
	roo->m_currentYear = pDoc->avg.m_settings.m_currentYear;

	roo->m_default_team = pDoc->m_combo_team_index - 1;
	if (roo->m_default_team < 0) roo->m_default_team = 0;

	roo->avgTru = pDoc->avg.m_avg_trade_tru[0];

	int r = roo->DoModal();


	if (r == IDOK)
	{

		//make budget file copy





		for (int i = 0; i <= 99; i++)
		{
			if (i <= 31) roo->avg.m_standings[i].ClearTeamStandings(i);
			roo->avg.m_finance[100 + i] = roo->avg.m_finance[i];
			roo->avg.m_finance[i].ClearBudgetData();
		}

		CString league_name = pDoc->avg.m_settings.m_league_name;
		CString path = pDoc->avg.m_settings.m_path;
		pDoc->avg = roo->avg;


		pDoc->avg.SetHighs(false);
		//int days_elapsed = pDoc->avg.m_sched.DaysSinceSeasonEnd();
		//pDoc->HealInjury(days_elapsed);
		pDoc->avg.m_sched.ClearSchedule();

		CBBallFile* fi = new CBBallFile;
		fi->ResetSeasonFiles(path + league_name);
		delete fi;

		CDisk* disk = new CDisk;
		disk->avg = pDoc->avg;
		CString kie_file_name = path + league_name + ".kie";
		if (disk->FileExists(kie_file_name) == false)
		{
			disk->CreateBlankFile(kie_file_name, 110000);
			CString f_file_name = path + "fnames.txt";
			CString l_file_name = path + "lnames.txt";
			disk->ReadNames(f_file_name, l_file_name);
			disk->CreateRookies(kie_file_name, true);
		}
		delete disk;

		pDoc->avg.m_settings.m_current_stage = 0;
		pDoc->avg.SetStartSeasonAttributes(true);
		pDoc->avg.ComputerSetsRotation();
		pDoc->m_recordbook.ClearSeasonHighs(0, 0);
		pDoc->SaveGameData(path, league_name);
		CheckButtons();
		if (pDoc->avg.m_settings.m_expanding == 1)
		{
			pDoc->CallAutoScheduler();
			pDoc->avg.m_settings.m_expanding = 0;
			pDoc->avg.m_sched.m_currentMonth = 1;
			pDoc->avg.m_sched.m_currentDay = 1;
		}


	}


	delete roo;

	((CBBallApp*)AfxGetApp())->SwitchView(1);

}
void CProgressView::OnButtonEnd()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	int result = MessageBox("Ratings will increase or decrease based on age, prime age, career projections and coach's development abilities\nAre you sure you want to age all players by one year and change their abilities?", "End Season", MB_YESNO);




	if (result == IDYES)
	{

		int days_elapsed = pDoc->avg.m_sched.DaysSinceSeasonEnd();
		pDoc->HealInjury(days_elapsed);

		//retirements
		CRetirement* ret = new CRetirement;
		ret->m_path = pDoc->avg.m_settings.m_path;
		ret->m_league_name = pDoc->avg.m_settings.m_league_name;

		for (int i = 0; i <= 1440; i++)
		{
			pDoc->avg.m_actual[i].m_rookie = false;
			ret->avg.m_actual[i] = pDoc->avg.m_actual[i];
		}


		ret->SetRetirements(pDoc->avg.m_hi_fga[0], pDoc->avg.m_hi_fta[0], pDoc->avg.m_hi_tga[0], pDoc->avg.m_hi_orb[0], pDoc->avg.m_hi_drb[0],
			pDoc->avg.m_hi_ast[0], pDoc->avg.m_hi_stl[0], pDoc->avg.m_hi_to[0], pDoc->avg.m_hi_blk[0]);
		ret->WriteRetirements();
		delete ret;
		//awards section
		CString award_file = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;



		CAwards* aw = new CAwards;
		aw->avg = pDoc->avg;
		aw->m_current_year = pDoc->avg.m_settings.m_currentYear;
		aw->ChooseRings(award_file);
		aw->ChooseAwards();
		aw->SaveAwards(award_file);
		aw->WriteAwardHistoryFile(award_file);


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
		award->m_path = pDoc->avg.m_settings.m_path;
		award->m_league_name = pDoc->avg.m_settings.m_league_name;
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

		award->avg = pDoc->avg;
		award->DoModal();
		delete award;
		//end awards section


		//start record book
		for (int i = 0; i <= 1440; i++)
		{
			if (pDoc->avg.m_actual[i].m_name != "")
				pDoc->avg.m_actual[i].UpdateCareerStats();
		}

		//pDoc->m_recordbook.avg = pDoc->avg;
		pDoc->m_recordbook.SetAllTimeSeasonHighs(pDoc->avg.m_actual, pDoc->avg.m_settings.m_currentYear, pDoc->avg.m_sched.m_games_in_season);
		//end record book









		long last_year_total_revenue[33];
		for (int i = 0; i <= 32; i++)
		{
			last_year_total_revenue[i] = pDoc->avg.m_finance[i + 100].m_season_total_revenue;//need to keep to adjust stuff
		}

		//	for(int i=100; i<=199; i++)
		//	{
		//		pDoc->avg.m_finance[i] = pDoc->avg.m_finance[i-100];
		//	}

		for (int i = 0; i < pDoc->avg.m_settings.m_numberteams; i++)
		{
			pDoc->avg.m_finance[i].SetEndOfSeasonValue();
			pDoc->avg.m_finance[i].SetEndOfSeasonSalaryCap(pDoc->avg.m_owner[i].m_player_spending);
			pDoc->avg.m_finance[i].SetEndOfSeasonCityAdjustments(last_year_total_revenue[i]);
			pDoc->avg.m_finance[i].SetEndOfSeasonMiscExpenses();
			pDoc->avg.m_finance[i].SetEndOfSeasonMiscRevenues();
		}



		CDisk* disk = new CDisk;
		disk->avg = pDoc->avg;


		for (int i = 1; i <= 1440; i++)
		{
			pDoc->avg.m_actual[i].SetRatings(pDoc->avg.m_hi_fga[0], pDoc->avg.m_hi_fta[0], pDoc->avg.m_hi_tga[0], pDoc->avg.m_hi_orb[0], pDoc->avg.m_hi_drb[0], pDoc->avg.m_hi_ast[0], pDoc->avg.m_hi_stl[0], pDoc->avg.m_hi_to[0], pDoc->avg.m_hi_blk[0]);
			//pDoc->avg.m_actual[i].SetOldRatings();//previous
			pDoc->avg.m_actual[i].SetOldRatings();
			int team = pDoc->avg.m_actual[i].m_current_team;
			if (team == -1) team = 99;
			pDoc->avg.m_actual[i].SetAdjustedOldRatings(pDoc->avg.m_coach[team], false);


		}


		CString avg_file = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".avg";
		if (disk->FileExists(avg_file) == false)
		{
			disk->CreateBlankFile(avg_file, 1024);
			disk->WriteLeagueAverages(avg_file);
		}
		delete disk;





		CCareer* career;
		career = new CCareer;

		career->m_path = pDoc->avg.m_settings.m_path;
		career->m_leagueName = pDoc->avg.m_settings.m_league_name;


		career->avg_tru = pDoc->avg.m_avg_tru[0];

		for (int i = 1; i <= 960; i++)
		{
			int team = (i - 1) / 30;
			pDoc->avg.m_actual[i].SetTeam(pDoc->avg.m_settings.m_leagueTeamNames[team]);
			pDoc->avg.m_actual[i].SetRatings(pDoc->avg.m_hi_fga[0], pDoc->avg.m_hi_fta[0], pDoc->avg.m_hi_tga[0], pDoc->avg.m_hi_orb[0], pDoc->avg.m_hi_drb[0], pDoc->avg.m_hi_ast[0], pDoc->avg.m_hi_stl[0], pDoc->avg.m_hi_to[0], pDoc->avg.m_hi_blk[0]);
			career->m_actual[i] = pDoc->avg.m_actual[i];
			career->m_actual[i].m_age = career->m_actual[i].m_age + 1;
		}
		for (int i = 0; i <= 31; i++)
		{
			career->m_coach[i] = pDoc->avg.m_coach[i];
			career->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		}

		for (int i = 1; i <= 480; i++)
		{
			career->m_actual[960 + i] = pDoc->avg.m_actual[960 + i];
			career->m_actual[960 + i].m_age = career->m_actual[960 + i].m_age + 1;
		}

		career->ReadNames();
		career->m_currentYear = pDoc->avg.m_settings.m_currentYear;
		career->m_numberteams = pDoc->avg.m_settings.m_numberteams;
		career->WriteCareerStats();
		career->m_hiG = pDoc->avg.m_hi_g[0];
		career->m_numberteams = pDoc->avg.m_settings.m_numberteams;


		career->AdjustScoring();

		for (int i = 1; i <= 1440; i++)
		{
			pDoc->avg.m_actual[i] = career->m_actual[i];
		}

		delete career;

		CPlayoff* po;
		po = new CPlayoff;
		int old_roster_values[] = { 0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 ,0,0,0 };
		for (int i = 0; i < 32; i++)
		{
			po->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
			pDoc->avg.m_owner[i].SetRosterValue(pDoc->avg.m_actual, i * 30 + 1);//after player aging need to recalculate the roster value of each franchise
			old_roster_values[i] = pDoc->avg.m_owner[i].m_rosterValue;
			po->m_owner[i] = pDoc->avg.m_owner[i];
			po->record[i] = pDoc->avg.m_standings[i];
		}
		po->m_path = pDoc->avg.m_settings.m_path;
		po->m_leagueName = pDoc->avg.m_settings.m_league_name;
		po->m_currentYear = pDoc->avg.m_settings.m_currentYear;
		po->WriteCareerTeamHistory();

		pDoc->avg.UpdateStaffStats(old_roster_values, po->record);

		delete po;


		disk = new CDisk;
		CString file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".roo";
		CString old_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".kie";

		if (disk->FileExists(file_name) == false)//copies preview rookie file to actual rookie file for draft
		{
			disk->OpenRookies(old_file_name);
			disk->CreateBlankFile(file_name, 110000);
			disk->CreateRookies(file_name, false);
		}

		delete disk;

		pDoc->avg.m_settings.m_current_stage = 2;



		CheckButtons();
		CString league_name = pDoc->avg.m_settings.m_league_name;
		CString path = pDoc->avg.m_settings.m_path;
		pDoc->SaveGameData(path, league_name);

	}

}

void CProgressView::OnButtonFa()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	CFreeAgentDlg* free = new CFreeAgentDlg;

	int cap = (int)pDoc->avg.m_settings.m_cap;
	free->m_cap = cap;
	free->m_default_team = pDoc->m_combo_team_index - 1;
	if (free->m_default_team < 0)	free->m_default_team = 0;
	free->m_signing_ok = true;
	free->avg = pDoc->avg;
	int count = 0;
	for (int i = 1; i <= 960; i++)
	{

		int te = pDoc->avg.m_actual[i].m_team_paying;
		if (te > 0) pDoc->avg.m_actual[i].m_team_paying_name = pDoc->avg.m_settings.m_leagueTeamNames[te - 1];

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
	if (result == IDOK)
	{
		pDoc->avg = free->avg;
		if (free->m_free_agency_over == true)
			pDoc->avg.m_settings.m_current_stage = 5;


		if (pDoc->avg.m_settings.m_financial_on == 0 && free->m_free_agency_over == true)
			pDoc->avg.m_settings.m_current_stage = 7;
		CheckButtons();
	}

	delete free;
}

void CProgressView::OnButtonRookies()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int orig_win[33], orig_loss[33];

	CString po_format = pDoc->avg.m_settings.m_playoffFormat;
	CPlayoff* playoff = new CPlayoff;

	if (po_format != "")
	{


		for (int i = 0; i <= 31; i++)
		{
			orig_win[i] = pDoc->avg.m_standings[i].m_win;
			orig_loss[i] = pDoc->avg.m_standings[i].m_loss;
			pDoc->avg.m_standings[i].m_initialNumber = i;
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

		for (int i = 0; i <= 31; i++)
		{
			int n = playoff->record[i].m_initialNumber;
			if (playoff->record[i].m_leagueTeamNames != "")
				pDoc->avg.m_standings[n] = playoff->record[i];
		}


	}






	CRookieDlg* roo;
	roo = new CRookieDlg;
	roo->m_shareware = pDoc->m_shareware;
	roo->avg = pDoc->avg;
	roo->m_currentYear = pDoc->avg.m_settings.m_currentYear;





	for (int i = 0; i <= (pDoc->avg.m_settings.m_numberteams - 1); i++)
	{
		roo->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
		roo->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
		roo->m_orig_win[i] = orig_win[i];
		roo->m_orig_loss[i] = orig_loss[i];
	}
	roo->m_numberteams = pDoc->avg.m_settings.m_numberteams;
	roo->m_path = pDoc->avg.m_settings.m_path;
	roo->m_leagueName = pDoc->avg.m_settings.m_league_name;

	roo->m_default_team = pDoc->m_combo_team_index - 1;
	if (roo->m_default_team < 0) roo->m_default_team = 0;


	int result = roo->DoModal();
	if (result == IDOK)
	{
		pDoc->avg = roo->avg;
		pDoc->avg.m_own[0].SetEndOfSeasonDraftChart();
		pDoc->avg.m_settings.m_currentYear = roo->m_currentYear;
		pDoc->avg.m_settings.m_current_stage = 4;

		if (pDoc->avg.m_settings.m_free_agency_on == 0 &&
			pDoc->avg.m_settings.m_financial_on == 1)
			pDoc->avg.m_settings.m_current_stage = 5;
		else if (pDoc->avg.m_settings.m_free_agency_on == 0 &&
			pDoc->avg.m_settings.m_financial_on == 0)
			pDoc->avg.m_settings.m_current_stage = 7;

		CheckButtons();
	}
	delete roo;

	for (int i = 0; i <= 31; i++)
	{
		int n = playoff->record[i].m_initialNumber;
		if (playoff->record[i].m_leagueTeamNames != "")
			pDoc->avg.m_standings[n] = playoff->record[i];
	}


	delete playoff;



}

void CProgressView::OnButtonStaffs()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	CStaffDlg* staff = new CStaffDlg;
	staff->m_hiring_ok = true;
	//staff->m_default_team = pDoc->m_combo_team_index;
	staff->m_default_team = pDoc->m_combo_team_index - 1;
	if (staff->m_default_team < 0) staff->m_default_team = 0;

	staff->avg = pDoc->avg;

	int result = staff->DoModal();
	if (result == IDOK)
	{


		for (int i = 0; i <= 99; i++)
		{
			pDoc->avg.m_scout[i] = staff->avg.m_scout[i];
			pDoc->avg.m_coach[i] = staff->avg.m_coach[i];
			pDoc->avg.m_gm[i] = staff->avg.m_gm[i];
			pDoc->avg.m_owner[i] = staff->avg.m_owner[i];
		}
		pDoc->avg.m_settings.m_current_stage = 3;
		CheckButtons();
	}
	delete staff;
}

/*void CProgressView::OnDraw(CDC* pDC)
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

void CProgressView::CheckButtons()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//pDoc->avg.m_settings.m_current_stage = 2;

	m_button_expand.EnableWindow(FALSE);
	m_button_staffs.EnableWindow(FALSE);
	m_button_rookies.EnableWindow(FALSE);
	m_button_fa.EnableWindow(FALSE);
	m_button_end.EnableWindow(FALSE);
	m_button_camp.EnableWindow(FALSE);
	m_button_budget.EnableWindow(FALSE);
	m_button_arena.EnableWindow(FALSE);


	//pDoc->avg.m_settings.m_current_stage = 2;


	if (pDoc->avg.m_settings.m_scouts[32] == 1 && pDoc->avg.m_settings.m_scouts[32] == 1 && pDoc->avg.m_settings.m_current_stage == 2)
	{
		pDoc->avg.m_settings.m_current_stage = 3;
	}


	if (pDoc->avg.m_settings.m_scouts[32] == 1 && pDoc->avg.m_settings.m_scouts[32] == 1 && (pDoc->avg.m_settings.m_current_stage == 2 || pDoc->avg.m_settings.m_current_stage == 3))
	{
		m_button_expand.EnableWindow(TRUE);
	}



	if ((pDoc->avg.m_settings.m_current_stage == 4
		|| pDoc->avg.m_settings.m_current_stage == 5
		|| pDoc->avg.m_settings.m_current_stage == 6)
		&& pDoc->avg.m_settings.m_free_agency_on == 0 &&
		pDoc->avg.m_settings.m_financial_on == 0)
		pDoc->avg.m_settings.m_current_stage = 7;
	else if (pDoc->avg.m_settings.m_current_stage == 4 && pDoc->avg.m_settings.m_free_agency_on == 0)
		pDoc->avg.m_settings.m_current_stage = 5;




	if (pDoc->avg.m_settings.m_current_stage >= 2 && pDoc->m_shareware == true)
	{
		m_button_end.EnableWindow(FALSE);
		m_button_staffs.EnableWindow(FALSE);
		m_button_expand.EnableWindow(FALSE);
		m_button_rookies.EnableWindow(FALSE);
		m_button_fa.EnableWindow(FALSE);
		m_button_budget.EnableWindow(FALSE);
		m_button_arena.EnableWindow(FALSE);
		m_button_camp.EnableWindow(FALSE);
	}
	else if (pDoc->avg.m_settings.m_current_stage == 1)
		m_button_end.EnableWindow(TRUE);
	else if (pDoc->avg.m_settings.m_current_stage == 2)
	{
		m_button_staffs.EnableWindow(TRUE);
		m_button_expand.EnableWindow(TRUE);
	}
	else if (pDoc->avg.m_settings.m_current_stage == 3) m_button_rookies.EnableWindow(TRUE);
	else if (pDoc->avg.m_settings.m_current_stage == 4) m_button_fa.EnableWindow(TRUE);
	else if (pDoc->avg.m_settings.m_current_stage == 5) m_button_budget.EnableWindow(TRUE);
	else if (pDoc->avg.m_settings.m_current_stage == 6) m_button_arena.EnableWindow(TRUE);
	else if (pDoc->avg.m_settings.m_current_stage == 7) m_button_camp.EnableWindow(TRUE);







	if (pDoc->avg.m_settings.m_path != "")
	{
		CString buffer;//save stage here for recovery problems
		CFile fil(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".lge", CFile::modeWrite);
		fil.Seek(12002, CFile::begin);
		int stage = pDoc->avg.m_settings.m_current_stage;
		buffer.Format("%d", stage);
		buffer = buffer + "   ";
		fil.Write(buffer, 2);
		fil.Close();
	}

	pDoc->SetTitleBar();
}

void CProgressView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);

}

void CProgressView::OnSetupSettings()
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->Options();

}

void CProgressView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CProgressView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnButtonExpand()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	CString previous_league_name = pDoc->avg.m_settings.m_league_name;

	CLeagueTeamsDlg* league;
	league = new CLeagueTeamsDlg;


	league->avg = pDoc->avg;
	league->m_expand = true;
	league->m_editYear = pDoc->avg.m_settings.m_currentYear;
	for (int i = 0; i <= 32; i++)
	{
		league->m_pre_league_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	league->m_pick_list = pDoc->avg.m_own[0];



	int result = league->DoModal();



	if (result == IDOK)
	{//set new league and write empty files if needed and load new player data

		pDoc->avg = league->avg;
		pDoc->avg.m_settings.m_checkCareer = league->m_checkCareer;
		pDoc->avg.m_settings.m_currentYear = league->m_editYear;
		pDoc->avg.m_settings.m_computerTrades = league->m_computerTrades;
		pDoc->avg.m_settings.m_league_name = league->avg.m_settings.m_league_name;
		pDoc->avg.m_settings.m_path = league->avg.m_settings.m_path;

		CString name_of_league = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;
		pDoc->CreateRandomFiles(name_of_league, FALSE);//no need to write staffs

	}

	delete league;

}

BOOL CProgressView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/progressoverview.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

	return CFormView::OnHelpInfo(pHelpInfo);
}

void CProgressView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/progressoverview.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);


}

HBRUSH CProgressView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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



void CProgressView::OnTeamRoster()
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

void CProgressView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CProgressView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}


void CProgressView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();
}

void CProgressView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CProgressView::OnEditStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();

}


BOOL CProgressView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
/*	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
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

//	}*/

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


void CProgressView::OnPaint()
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
