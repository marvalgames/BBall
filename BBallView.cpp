// BBallView.cpp : implementation of the CBBallView class
//

#include "stdafx.h"
#include "MyComboBox.h"
#include "BBall.h"

#include "SplashScreenEx.H"
#include "BBallDoc.h"
#include "BBallFile.h"
#include "BBallView.h"
#include "LeagueTeamsDlg.h"
#include "OptionsDlg.h"
#include "AboutDlg1.h"
#include "ProgressDlg1.h"
//#include "EditDlg.h"
//#include "ScoutEditDlg.h"
//#include "FranchiseEdit.h"

#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
//#include "Disk.h"

#include "DraftDlg.h"
#include "Retirement.h"
#include <afxtoolbarimages.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBBallView

IMPLEMENT_DYNCREATE(CBBallView, CFormView)

BEGIN_MESSAGE_MAP(CBBallView, CFormView)
	//{{AFX_MSG_MAP(CBBallView)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_QUICK, OnButtonQuick)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SETTINGS, OnButtonSettings)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_OPTIONS, OnButtonOptions)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(ID_SETUP_LOAD, OnUpdateSetupLoad)
	ON_UPDATE_COMMAND_UI(ID_SETUP_SETGAMEPLAN, OnUpdateSetupSetgameplan)
	ON_UPDATE_COMMAND_UI(ID_SETUP_PROPOSETRADE, OnUpdateSetupProposetrade)
	ON_UPDATE_COMMAND_UI(ID_SETUP_SETTINGS, OnUpdateSetupSettings)
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
	ON_UPDATE_COMMAND_UI(ID_TEAM_BUDGET, OnUpdateTeamBudget)
	ON_UPDATE_COMMAND_UI(ID_TEAM_DRAFTPREVIEW, OnUpdateTeamDraftpreview)
	ON_UPDATE_COMMAND_UI(ID_TEAM_FREEAGENTS, OnUpdateTeamFreeagents)
	ON_UPDATE_COMMAND_UI(ID_TEAM_HISTORY, OnUpdateTeamHistory)
	ON_UPDATE_COMMAND_UI(ID_TEAM_LINEUP, OnUpdateTeamLineup)
	ON_UPDATE_COMMAND_UI(ID_TEAM_RECORDS, OnUpdateTeamRecords)
	ON_UPDATE_COMMAND_UI(ID_TEAM_RESULTS, OnUpdateTeamResults)
	ON_UPDATE_COMMAND_UI(ID_TEAM_ROSTER, OnUpdateTeamRoster)
	ON_UPDATE_COMMAND_UI(ID_TEAM_STAFF, OnUpdateTeamStaff)
	ON_UPDATE_COMMAND_UI(ID_TEAM_TRADE, OnUpdateTeamTrade)
	ON_UPDATE_COMMAND_UI(ID_TEAM_TRANSACTIONS, OnUpdateTeamTransactions)
	ON_COMMAND(ID_EDIT_PLAYERS, OnEditPlayers)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PLAYERS, OnUpdateEditPlayers)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_UPDATE_COMMAND_UI(ID_EDIT_STAFF, OnUpdateEditStaff)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CITIES, OnUpdateEditCities)
	ON_BN_CLICKED(IDC_BUTTON_QUICKSTART, OnButtonQuickstart)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBallView construction/destruction

CBBallView::CBBallView()
	: CFormView(CBBallView::IDD)
{
	//{{AFX_DATA_INIT(CBBallView)

	m_edit_quickname = _T("MY_NEW_LEAGUE");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
//	bitmapBkgnd.Attach (LoadBitmap (Af.xGetInstanceHandle(), 0
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));
  // 
  // 
	//CBitmap bitmap;



	m_program_started = false;

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */



	int fontSize = 28;
	m_button_options.SetButtonFontSize(fontSize);
	m_button_delete.SetButtonFontSize(fontSize);
	m_button_load.SetButtonFontSize(fontSize);
	m_button_new.SetButtonFontSize(fontSize);
	m_button_save.SetButtonFontSize(fontSize);
	m_button_quickstart.SetButtonFontSize(fontSize);
	m_button_go.SetButtonFontSize(fontSize);


	//m_button_setup.SetFaceColor(RGB(39,64,139));
	//m_button_setup.SetTextColor(RGB(245,245,245));


}

CBBallView::~CBBallView()
{
	delete m_bmp;
}

void CBBallView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBBallView)
	DDX_Control(pDX, IDC_BUTTON_QUICKSTART, m_button_quickstart);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_OPTIONS, m_button_options);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_button_delete);
	DDX_Control(pDX, IDC_BUTTON_LOAD, m_button_load);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_button_new);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_button_save);
	DDX_Control(pDX, IDC_BUTTON_QUICK, m_button_quick);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Text(pDX, IDC_EDIT_QUICKNAME, m_edit_quickname);
	DDV_MaxChars(pDX, m_edit_quickname, 16);
	//}}AFX_DATA_MAP
}

BOOL CBBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	//cs.style = WS_OVERLAPPED | WS_BORDER | WS_SYSMENU |
	//	WS_MAXIMIZE | WS_MINIMIZEBOX |
	//	WS_MAXIMIZEBOX;
	return true;
}

void CBBallView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	GetParentFrame()->ShowWindow(SW_SHOWMAXIMIZED);


	CBBallDoc* pDoc = GetDocument();

	//myBrush.CreateSolidBrush(SCREENCOLOR); 
	m_tbrush.CreateSolidBrush(LISTBOXCOLOR);




	CSplashScreenEx* pSplash = new CSplashScreenEx();
	pSplash->Create(this, NULL, 2000, CSS_FADE | CSS_CENTERSCREEN | CSS_SHADOW);
	pSplash->SetBitmap(IDB_SPLASH, 255, 0, 255);
	pSplash->Show();


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 28;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 600;
	lf.lfHeight = 28;
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


#ifdef _DEBUG
void CBBallView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBBallView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBBallDoc* CBBallView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBBallDoc)));
	return (CBBallDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBBallView message handlers

void CBBallView::OnButtonLoad()
{
	// TODO: Add your control notification handler code here



	CBBallDoc* pDoc = GetDocument();
	CString name = pDoc->avg.m_settings.m_league_name;
	//CString text;
	//text.Format("Save the %s league files before continuing?",name);
	//int result = MessageBox(text, "Save League", MB_YESNO);
	int result = IDYES;
	if (result == IDYES) OnButtonSave();



	CFileDialog fil(true, ".lge", "Default_20-21", OFN_HIDEREADONLY,
		"League Files (*.lge)|*.lge|", NULL);
	result = fil.DoModal();
	if (result == IDOK)
	{

		CString Name = fil.GetFileTitle();
		CString Path = fil.GetPathName();

		CBBallFile* disk = new CBBallFile;
		bool exists = disk->FileExists(Path);
		delete disk;
		if (exists == false)
		{
			AfxMessageBox("League Selected Does Not Exist", MB_OK);
		}
		else
		{


			int length = Path.GetLength() - Name.GetLength() - 4;
			Path = Path.Left(length);

			pDoc->OpenGameData(Path, Name);

		}

		if (pDoc->m_default_opened == false)
		{
			//			GetDlgItem(IDC_BUTTON_EDIT)->EnableWindow(FALSE);
			((CBBallApp*)AfxGetApp())->SwitchView(3);

		}
		else
		{
			//			GetDlgItem(IDC_BUTTON_EDIT)->EnableWindow(TRUE);
			m_combo_teams.ShowWindow(FALSE);
			m_button_go.ShowWindow(FALSE);
			m_button_schedule.EnableWindow(FALSE);
			m_button_setup.EnableWindow(FALSE);
			m_button_standings.EnableWindow(FALSE);
			m_button_progress.EnableWindow(FALSE);
			m_button_tools.EnableWindow(FALSE);
			m_button_history.EnableWindow(FALSE);
		}

		ResetComboTeamList();

	}



	CString le = pDoc->avg.m_settings.m_league_name;
	//le.MakeUpper();
	CString str, def;
	def = le.Mid(0, 7);
	//	str.Format("%s SETTINGS", le);
	str = "League Settings";
	GetDlgItem(IDC_BUTTON_OPTIONS)->SetWindowText(str);
	str.Format("Save %s FILES", le);
	GetDlgItem(IDC_BUTTON_SAVE)->SetWindowText(str);
	def.MakeUpper();



	if (def == "DEFAULT")
	{
		//		str.Format("CREATE CUSTOM LEAGUE BASED ON DEFAULT LEAGUE: %s", le);
		str = "Create Custom League";
		GetDlgItem(IDC_BUTTON_NEW)->SetWindowText(str);
		GetDlgItem(IDC_BUTTON_QUICKSTART)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_QUICKNAME)->ShowWindow(TRUE);
		//		str.Format("CREATE QUICK LEAGUE BASED ON DEFAULT LEAGUE: %s", le);
		str = "Create Quick League";
		GetDlgItem(IDC_BUTTON_QUICKSTART)->SetWindowText(str);

	}
	else
	{
		str.Format("Modify %s", le);
		GetDlgItem(IDC_BUTTON_NEW)->SetWindowText(str);
		GetDlgItem(IDC_BUTTON_QUICKSTART)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_QUICKNAME)->ShowWindow(FALSE);
	}


	RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);



	//Invalidate(TRUE);/
	//UpdateWindow();
	//ShowWindow(SW_SHOW);
}

void CBBallView::OnButtonQuick()
{
	// TODO: Add your control notification handler code here
	CAboutDlg1 about;
	about.DoModal();

}



void CBBallView::OnButtonBuy()
{
	// TODO: Add your control notification handler code here
//	ShellExecute(*this, "open", "http://www.regnow.com/softsell/nph-softsell.cgi?items=1546-1", NULL, NULL, SW_SHOWNORMAL);
	ShellExecute(*this, "open", "http://www.shotsports.com", NULL, NULL, SW_SHOWNORMAL);
	//	ShellExecute(*this, "open", "http://www.shotsports.com", NULL, NULL, SW_SHOWNORMAL);
}


void CBBallView::OnButtonNew()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	CString previous_league_name = pDoc->avg.m_settings.m_league_name;
	double prev_true = pDoc->avg.m_avg_tru[0];
	bool staff_file_already_written = false;

	CLeagueTeamsDlg* league;
	league = new CLeagueTeamsDlg;


	league->avg = pDoc->avg;
	for (int i = 0; i <= 32; i++)
	{
		league->m_pre_league_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
	}
	league->m_pick_list = pDoc->avg.m_own[0];
	league->m_editYear = pDoc->avg.m_settings.m_currentYear;
	league->m_leagueName = m_edit_quickname;

	int result = league->DoModal();
	int rs = 0;
	int fic = 0;
	BOOL data_imported = league->m_data_imported;
	//	bool m_ask = league->m_askAboutDraft;//m_ask & m_saved probablt the same but be safe for now
	bool m_saved = league->m_leagueSaved;//
	bool m_data_saved = league->m_data_saved;
	CString m_originalLeague = league->m_originalLeagueName;
	int m_originalTeams = league->m_originalNumberOfTeams;



	BOOL random_contracts = FALSE;
	BOOL skip_ages = FALSE;
	BOOL skip_contracts = FALSE;
	BOOL random_attributes = FALSE;
	if (result == IDOK)
	{//set new league and write empty files if needed and load new player data



		//if(pDoc->avg.m_sched.m_season_started == false)
		//{
		CString league_name = previous_league_name;
		CString path = pDoc->avg.m_settings.m_path;
		pDoc->SaveGameData(path, league_name);
		//}


		pDoc->avg = league->avg;
		skip_ages = league->m_skip_ages;
		skip_contracts = league->m_skip_contracts;
		fic = league->m_league_style;
		random_contracts = league->m_check_contracts;
		random_attributes = league->m_check_attributes;
		pDoc->avg.m_settings.m_checkCareer = league->m_checkCareer;
		pDoc->avg.m_settings.m_currentYear = league->m_editYear;
		pDoc->avg.m_settings.m_computerTrades = league->m_computerTrades;
		pDoc->avg.m_settings.m_league_name = league->avg.m_settings.m_league_name;
		pDoc->avg.m_settings.m_path = league->avg.m_settings.m_path;

		CString name_of_league = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;

		if (pDoc->avg.m_scout[0].m_name == "") league->m_check_staffs = TRUE;//force new staff file to be written if current league scouts are blank (means league had "no scouts" , eventhough the file has them
		pDoc->CreateRandomFiles(name_of_league, league->m_check_staffs);//staffs as well
		ResetComboTeamList();

	}

	delete league;

	if (m_saved == true && fic == 3)
	{

		CDisk* disk = new CDisk;
		disk->avg = pDoc->avg;
		CString f_file_name = pDoc->avg.m_settings.m_path + "fnames.txt";
		CString l_file_name = pDoc->avg.m_settings.m_path + "lnames.txt";

		disk->ReadNames(f_file_name, l_file_name);
		disk->CreateFictionalPool();
		pDoc->avg = disk->avg;
		delete disk;
	}


	if (m_saved == true)
	{

		BOOL skip_pot = FALSE;
		for (int i = 0; i <= 1600; i++)
		{
			if (random_attributes == TRUE || fic == 3)
			{
				pDoc->avg.m_actual[i].GenerateRandomOffCourtData();
				//pDoc->avg.SetStartSeasonAttributes(false)
			}
		}
		pDoc->avg.SetHighs(true);
		if (random_contracts == TRUE || fic == 3)
		{
			if (random_attributes == FALSE) skip_pot = TRUE;
			pDoc->avg.GenerateRandomContracts(skip_ages, skip_contracts, skip_pot);
		}

	}

	if (m_saved == true)
	{
		pDoc->avg.m_settings.m_current_stage = 0;
		if (fic >= 2)
		{
			//pDoc->OpenStaff();

			CDraftDlg* draft;
			draft = new CDraftDlg;
			for (int i = 0; i <= 31; i++)
			{
				draft->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
				draft->m_control[i] = pDoc->avg.m_settings.m_player_gm[i];
			}
			for (int i = 0; i <= 99; i++)
			{
				draft->m_scout[i] = pDoc->avg.m_scout[i];
			}

			draft->avg = pDoc->avg;
			draft->m_checkCareer = pDoc->avg.m_settings.m_checkCareer;
			draft->m_leagueName = pDoc->avg.m_settings.m_league_name;
			draft->m_path = pDoc->avg.m_settings.m_path;
			draft->m_originalLeagueName = m_originalLeague;
			draft->m_originalNumberOfTeams = m_originalTeams;

			int index = 1;
			for (int i = 1; i <= 1440; i++)
			{
				if (pDoc->avg.m_actual[i].GetName() != "" && index <= 480)
				{
					if (pDoc->avg.m_actual[i].m_height == 0 ||
						pDoc->avg.m_actual[i].m_weight == 0)
						pDoc->avg.m_actual[i].GenerateRandomHeightWeight(false);


					draft->Player[index] = pDoc->avg.m_actual[i];
					draft->Player[index].SetRosterNumber(index);
					index = index + 1;
				}
			}


			rs = draft->DoModal();
			pDoc->avg = draft->avg;
			delete draft;


		}

	}
	if ((rs != IDOK && result == IDOK) || (rs == IDOK))
	{
		if (m_saved == true)
		{



			CProgressDlg dlgProgress;
			dlgProgress.m_text = "Creating League";
			dlgProgress.Create(IDD_PROGRESSDLG, NULL);        // change these parameters
			dlgProgress.ShowWindow(SW_SHOW);
			dlgProgress.m_progress.SetRange(1, 5);
			dlgProgress.m_progress.SetPos(1);

			CDisk* disk = new CDisk;
			disk->CreateCleanLeagueFiles(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name);
			CString kie_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".kie";
			if (disk->FileExists(kie_file_name) == false)
			{
				disk->avg = pDoc->avg;
				disk->CreateBlankFile(kie_file_name, 110000);
				CString f_file_name = pDoc->avg.m_settings.m_path + "fnames.txt";
				CString l_file_name = pDoc->avg.m_settings.m_path + "lnames.txt";
				disk->ReadNames(f_file_name, l_file_name);
				disk->CreateRookies(kie_file_name, true);
				dlgProgress.m_progress.SetPos(2);

			}


			if (disk->FileExists(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".ret") == false)
			{
				CRetirement* ret = new CRetirement;
				ret->m_path = pDoc->avg.m_settings.m_path;
				ret->m_league_name = pDoc->avg.m_settings.m_league_name;

				for (int i = 0; i <= 1440; i++)
				{
					ret->avg.m_actual[i] = pDoc->avg.m_actual[i];
				}

				ret->SetRetirements(pDoc->avg.m_hi_fga[0], pDoc->avg.m_hi_fta[0], pDoc->avg.m_hi_tga[0], pDoc->avg.m_hi_orb[0], pDoc->avg.m_hi_drb[0],
					pDoc->avg.m_hi_ast[0], pDoc->avg.m_hi_stl[0], pDoc->avg.m_hi_to[0], pDoc->avg.m_hi_blk[0]);
				ret->WriteRetirements();
				dlgProgress.m_progress.SetPos(3);
				delete ret;
			}

			delete disk;

			for (int i = 0; i <= 1600; i++)
			{
				pDoc->avg.m_actual[i].ClearSeasonStats();
			}

			dlgProgress.m_progress.SetPos(64);

			pDoc->m_recordbook.ClearSeasonHighs(0, 1);
			pDoc->avg.m_settings.m_current_stage = 0;
			pDoc->avg.SetHighs(true);
			//int days_elapsed = pDoc->avg.m_sched.DaysSinceSeasonEnd();
			//pDoc->HealInjury(days_elapsed);
			pDoc->avg.m_sched.ClearSchedule();
			pDoc->avg.SetStartSeasonAttributes(false);
			pDoc->avg.SortTeamRosters(pDoc->avg.m_actual, false);
			pDoc->avg.ComputerSetsRotation();
			pDoc->avg.CalculateBetter(FALSE);

			dlgProgress.m_progress.SetPos(5);



			CString tmp = pDoc->avg.m_settings.m_league_name.Mid(0, 7);
			tmp.MakeLower();
			if (tmp == "default") pDoc->m_default_opened = true; else pDoc->m_default_opened = false;




			((CBBallApp*)AfxGetApp())->SwitchView(1);


		}
	}


}

void CBBallView::OnButtonSave()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = GetDocument();
	CString league_name = pDoc->avg.m_settings.m_league_name;
	CString path = pDoc->avg.m_settings.m_path;
	pDoc->SaveGameData(path, league_name);
}

void CBBallView::OnButtonDelete()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = GetDocument();

	CFileDialog fil(true, ".lge", "2004-2005", OFN_HIDEREADONLY,
		"League Files (*.lge)|*.lge|", NULL);
	int result = fil.DoModal();
	CString file_name;
	if (result == IDOK)
	{
		CString league_name = fil.GetFileTitle();
		CString league_path = fil.GetPathName();
		int length = league_path.GetLength() - league_name.GetLength() - 4;
		league_path = league_path.Left(length);

		if (pDoc->avg.m_settings.m_league_name == league_name)
			AfxMessageBox("currently open league cannot be deleted", MB_OK);
		else if (league_name == "default")
			AfxMessageBox("default league cannot be deleted", MB_OK);
		else
		{
			int r = AfxMessageBox("Are you absolutely sure you want to delete all league files?", MB_YESNO);
			if (r == IDYES)
			{
				CDisk* disk = new CDisk;
				disk->DeleteAllFiles(league_path + league_name);
				delete disk;
			}
		}
	}
}

void CBBallView::OnButtonSettings()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(0);
}

void CBBallView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFormView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here


	CBBallDoc* pDoc = GetDocument();

	//	UpdateWindow();
	//	Invalidate(TRUE);

		//else
		//	m_program_started = true;
				// no league open





	if (bShow == TRUE && m_program_started == true || pDoc->m_default_opened == true)
	{
		//m_button_tools.SetMyFont(800,20,"Courier New");
		m_button_tools.SetFont(&m_font1);
		//m_button_tools.SetWindowText("Shit");
		//m_button_tools.RedrawWindow();
		m_combo_teams.ResetContent();
		m_combo_teams.AddString("All Teams");
		for (int i = 0; i <= 32; i++)
		{
			if (pDoc->avg.m_settings.m_leagueTeamNames[i] != "")
				m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
		}
		m_combo_teams.SetCurSel(pDoc->m_combo_team_index);
		m_combo_teams.ShowWindow(TRUE);
		m_button_go.ShowWindow(TRUE);
		m_button_schedule.EnableWindow(TRUE);
		m_button_setup.EnableWindow(TRUE);
		m_button_standings.EnableWindow(TRUE);
		m_button_progress.EnableWindow(TRUE);
		m_button_tools.EnableWindow(TRUE);
		m_button_history.EnableWindow(TRUE);



		//		m_button_setup.Repaint(FALSE);
		//		m_button_schedule.Repaint(FALSE);
		//		m_button_go.Repaint(FALSE);


		if (pDoc->avg.m_settings.m_leagueTeamNames[0] != "" && m_program_started == true)//league open now we can make transparent
		{
			CString le = pDoc->avg.m_settings.m_league_name;
			//le.MakeUpper();
			CString str, def;
			def = le.Mid(0, 7);
			str.Format("%s Settings", le);
			str = "League Settings";
			GetDlgItem(IDC_BUTTON_OPTIONS)->SetWindowText(str);
			str.Format("Save %s", le);
			GetDlgItem(IDC_BUTTON_SAVE)->SetWindowText(str);

			def.MakeUpper();
			if (def == "DEFAULT")
			{
				//		str.Format("CREATE CUSTOM LEAGUE BASED ON DEFAULT LEAGUE: %s", le);
				str = "Create Custom League";
				GetDlgItem(IDC_BUTTON_NEW)->SetWindowText(str);
				GetDlgItem(IDC_BUTTON_QUICKSTART)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT_QUICKNAME)->ShowWindow(TRUE);
				//		str.Format("CREATE QUICK LEAGUE BASED ON DEFAULT LEAGUE: %s", le);
				str = "Create Quick League";
				GetDlgItem(IDC_BUTTON_QUICKSTART)->SetWindowText(str);
			}
			else
			{
				str.Format("Modify %s", le);
				GetDlgItem(IDC_BUTTON_NEW)->SetWindowText(str);
				GetDlgItem(IDC_BUTTON_QUICKSTART)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT_QUICKNAME)->ShowWindow(FALSE);
			}

			/*		m_button_quick.DrawTransparent(TRUE);
						m_button_quickstart.DrawTransparent(TRUE);
						m_button_load.DrawTransparent(TRUE);
						m_button_save.DrawTransparent(TRUE);
						m_button_new.DrawTransparent(TRUE);
						m_button_delete.DrawTransparent(TRUE);
						m_button_options.DrawTransparent(TRUE);*/



		}


	}

	m_program_started = true;



	/*
	 CClientDC dc(this);
		Graphics graphics(dc.m_hDC);
		CString image = "button.png";
		Bitmap bitmap(image.AllocSysString());
		graphics.DrawImage(&bitmap, 0, 0);
		graphics.ReleaseHDC(dc.m_hDC);
	*/


	//	USERFONT = "Courier New";
	RedrawWindow();


}


void CBBallView::OnButtonSchedule()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(1);
}

void CBBallView::OnButtonStandings()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(4);

}

void CBBallView::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = GetDocument();

	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();

	((CBBallApp*)AfxGetApp())->SwitchView(3);

}






void CBBallView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	// TODO: Add your specialized code here and/or call the base class
	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

int CBBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here


	return 0;
}

void CBBallView::OnButtonOptions()
{
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = GetDocument();
	pDoc->Options();

	//SetDialogBkColor(RGB(191,206,255), MAINTEXTCOLOR);


}

void CBBallView::OnButtonTools()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(7);
}

void CBBallView::OnButtonHistory()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(6);

}

void CBBallView::OnButtonProgress()
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(8);
}


BOOL CBBallView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default








	//m_button_schedule.SetFont(&m_font2);

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	if (pDoc->m_default_opened == true)
	{
		//GetDlgItem(IDC_BUTTON_EDIT)->ShowWindow(TRUE);
		m_combo_teams.ShowWindow(FALSE);
		m_button_go.ShowWindow(FALSE);
		m_button_schedule.EnableWindow(FALSE);
		m_button_setup.EnableWindow(FALSE);
		m_button_standings.EnableWindow(FALSE);
		m_button_progress.EnableWindow(FALSE);
		m_button_tools.EnableWindow(FALSE);
		m_button_history.EnableWindow(FALSE);
	}
	else
	{
		m_combo_teams.ShowWindow(TRUE);
		//GetDlgItem(IDC_BUTTON_EDIT)->ShowWindow(FALSE);
		m_button_go.ShowWindow(TRUE);


	}

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






	//return CView::OnEraseBkgnd(pDC);
}

//void CBBallView::OnDraw(CDC* pDC) 
//{
	// TODO: Add your specialized code here and/or call the base class
/*




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

	*/

	//}

void CBBallView::OnSetupLoad()
{
	// TODO: Add your command handler code here
	((CBBallApp*)AfxGetApp())->SwitchView(2);

}

void CBBallView::ResetComboTeamList()
{
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	m_combo_teams.ResetContent();
	pDoc->m_combo_team_index = 0;
	m_combo_teams.AddString("All Teams");
	for (int i = 0; i <= 32; i++)
	{
		if (pDoc->avg.m_settings.m_leagueTeamNames[i] != "")
			//m_combo_teams.AddString(pDoc->avg.m_settings.m_leagueTeamNames[i]);
			m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);
	}
	m_combo_teams.SetCurSel(pDoc->m_default_team);

}



void CBBallView::OnSetupSettings()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = GetDocument();
	pDoc->Options();


}

void CBBallView::OnSetupSetgameplan()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->GamePlan();
}

void CBBallView::OnSetupProposetrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	int result = pDoc->ProposeTrade();

}

void CBBallView::OnButtonGo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
	//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView(3);




}

void CBBallView::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO: Add your message handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();



	CString default_path = pDoc->m_original_dir;//default name
	CString file_name = default_path + "\\settings.txt";
	CFileStatus status;



	CStdioFile fi(file_name, CFile::modeWrite);
	CString string1 = pDoc->avg.m_settings.m_path;
	CString string2 = pDoc->avg.m_settings.m_league_name;
	CString string3 = pDoc->m_bk_color;
	CString string4 = pDoc->m_text_color;
	CString string5 = pDoc->m_link_color;
	CString string6 = pDoc->m_vlink_color;
	CString string7 = pDoc->m_html_font;



	fi.WriteString(string1 + "\n");
	fi.WriteString(string2 + "\n");
	fi.WriteString(string3 + "\n");
	fi.WriteString(string4 + "\n");
	fi.WriteString(string5 + "\n");
	fi.WriteString(string6 + "\n");
	fi.WriteString(string7 + "\n");
	fi.Close();

	//	CString name;
	//	name.Format("Click Yes to Save Franchise: %s", pDoc->avg.m_settings.m_league_name);

	//	int r = IDYES;
	//	if(pDoc->avg.m_settings.m_current_stage == 0)
	//	{
	//		r = MessageBox(name, "Save Franchise", MB_YESNO);
	//	}
	//	if(r == IDYES)
	//	{
	OnButtonSave();
	//	}	
}

void CBBallView::OnUpdateSetupLoad(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateSetupSetgameplan(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);

}

void CBBallView::OnUpdateSetupProposetrade(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);

}

void CBBallView::OnUpdateSetupSettings(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	//	if(pDoc->m_default_opened == true) 
	//		pCmdUI->Enable(FALSE);
	//	else
	//		pCmdUI->Enable(TRUE);	

}

void CBBallView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: Add your specialized code here and/or call the base class

}

BOOL CBBallView::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
	//HtmlHelp(NULL, "jumpshot.chm::/html/play.htm", HH_DISPLAY_TOPIC, 0);
	//HtmlHelp(NULL, "jumpshot.chm::/html/play.htm", HH_DISPLAY_TOPIC, 0);
	//HtmlHelp(this->m_hWnd, "HelpSample.chm", HH_DISPLAY_TOPIC, NULL)
	//HtmlHelp(NULL, HH_DISPLAY_TOPIC);

//	return CFormView::OnHelpInfo(pHelpInfo);
	ShellExecute(NULL, "open", "html\\play.htm", NULL, NULL, SW_SHOWNORMAL);




	return CFormView::OnHelpInfo(pHelpInfo);
}

void CBBallView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/play.htm", HH_DISPLAY_TOPIC, 0);

//	return CFormView::OnHelpInfo(pHelpInfo);

}


/*void CBBallView::OnButtonEdit()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
		CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
		CEditDlg* edit = new CEditDlg;
		edit->avg = pDoc->avg;
//		edit->m_actual = pDoc->avg.m_actual[1];
		edit->m_rookie_edit = false;

		edit->m_default_team = pDoc->m_combo_team_index - 1;
		if(edit->m_default_team < 0) edit->m_default_team = 0;

		edit->m_actual = pDoc->avg.m_actual[edit->m_default_team*30 + 1];


		int result = edit->DoModal();

		if(result == IDOK)
		{
			pDoc->avg = edit->avg;
			bool started = pDoc->avg.m_sched.m_season_started;
			pDoc->avg.CalculateBetter(started);

			CDisk* disk = new CDisk;
			CString new_data_file = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".tmp";
			disk->WriteNewPlayerDataFile(new_data_file);
			delete disk;
		}

		delete edit;



}

*/

void CBBallView::OnTeamRoster()
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

void CBBallView::OnTeamResults()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamBudget()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamDraftpreview()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamFreeagents()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamHistory()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamLineup()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamRecords()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamStaff()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamTrade()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnTeamTransactions()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView(3);

}

void CBBallView::OnUpdateTeamBudget(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamDraftpreview(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);

	else
		pCmdUI->Enable(TRUE);




}

void CBBallView::OnUpdateTeamFreeagents(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamHistory(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamLineup(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamRecords(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamResults(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamRoster(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamStaff(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamTrade(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnUpdateTeamTransactions(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();

	if (pDoc->m_default_opened == true)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CBBallView::OnEditPlayers()
{
	// TODO: Add your command handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditPlayers();

}

void CBBallView::OnUpdateEditPlayers(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here



}

void CBBallView::OnEditStaff()
{
	// TODO: Add your command handler code here
	// TODO: Add your control notification handler code here
	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditStaffs();


}

void CBBallView::OnUpdateEditStaff(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here

}

void CBBallView::OnEditCities()
{
	// TODO: Add your command handler code here

	CBBallDoc* pDoc = (CBBallDoc*)GetDocument();
	pDoc->EditCities();
}

void CBBallView::OnUpdateEditCities(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here

}


void CBBallView::OnDoubleclickedButtonBuy()
{
	// TODO: Add your control notification handler code here

}

void CBBallView::OnButtonQuickstart()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	CBBallDoc* pDoc = GetDocument();
	CString league_name = pDoc->avg.m_settings.m_league_name;
	CString path = pDoc->avg.m_settings.m_path;
	CString new_leaguename = m_edit_quickname;

	pDoc->SaveGameData(path, league_name);
	pDoc->avg.m_settings.m_league_name = new_leaguename;
	CString str;
	str.Format("%s*.*", new_leaguename);

	//CFileFind finder;
	//BOOL bWorking = finder.FindFile(str);
	//while (bWorking)
	//{
	//	bWorking = finder.FindNextFile();
	//	CString file_name = finder.GetFileName();
	//	CFile::Remove(path + file_name);
	//}

	CProgressDlg dlgProgress;
	dlgProgress.m_text = "Creating League";
	dlgProgress.Create(IDD_PROGRESSDLG, NULL);        // change these parameters
	dlgProgress.ShowWindow(SW_SHOW);
	dlgProgress.m_progress.SetRange(1, 5);
	dlgProgress.m_progress.SetPos(1);

	CDisk* disk = new CDisk;
	disk->CreateCleanLeagueFiles(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name);
	CString kie_file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".kie";
	if (disk->FileExists(kie_file_name) == false)
	{
		disk->avg = pDoc->avg;
		disk->CreateBlankFile(kie_file_name, 110000);
		CString f_file_name = pDoc->avg.m_settings.m_path + "fnames.txt";
		CString l_file_name = pDoc->avg.m_settings.m_path + "lnames.txt";
		disk->ReadNames(f_file_name, l_file_name);
		disk->CreateRookies(kie_file_name, true);
		dlgProgress.m_progress.SetPos(2);

	}


	if (disk->FileExists(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".ret") == false)
	{
		CRetirement* ret = new CRetirement;
		ret->m_path = pDoc->avg.m_settings.m_path;
		ret->m_league_name = pDoc->avg.m_settings.m_league_name;

		for (int i = 0; i <= 1440; i++)
		{
			ret->avg.m_actual[i] = pDoc->avg.m_actual[i];
		}

		ret->SetRetirements(pDoc->avg.m_hi_fga[0], pDoc->avg.m_hi_fta[0], pDoc->avg.m_hi_tga[0], pDoc->avg.m_hi_orb[0], pDoc->avg.m_hi_drb[0],
			pDoc->avg.m_hi_ast[0], pDoc->avg.m_hi_stl[0], pDoc->avg.m_hi_to[0], pDoc->avg.m_hi_blk[0]);
		ret->WriteRetirements();
		dlgProgress.m_progress.SetPos(3);
		delete ret;
	}

	delete disk;



	CString name_of_league = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name;

	pDoc->CreateRandomFiles(name_of_league, TRUE);//staffs as well
	ResetComboTeamList();

	for (int i = 0; i <= 1600; i++)
	{
		pDoc->avg.m_actual[i].ClearSeasonStats();
	}

	dlgProgress.m_progress.SetPos(64);

	pDoc->m_recordbook.ClearSeasonHighs(0, 1);
	pDoc->avg.m_settings.m_current_stage = 0;
	pDoc->avg.SetHighs(true);
	//int days_elapsed = pDoc->avg.m_sched.DaysSinceSeasonEnd();
	//pDoc->HealInjury(days_elapsed);
	pDoc->avg.m_sched.ClearSchedule();
	pDoc->avg.SetStartSeasonAttributes(false);
	pDoc->avg.SortTeamRosters(pDoc->avg.m_actual, false);
	pDoc->avg.ComputerSetsRotation();
	pDoc->avg.CalculateBetter(FALSE);
	dlgProgress.m_progress.SetPos(5);

	//		pDoc->OpenGameData(	pDoc->avg.m_settings.m_path, 	pDoc->avg.m_settings.m_league_name)


	CString tmp = pDoc->avg.m_settings.m_league_name.Mid(0, 7);
	tmp.MakeLower();
	if (tmp == "default") pDoc->m_default_opened = true; else pDoc->m_default_opened = false;



	((CBBallApp*)AfxGetApp())->SwitchView(1);
	((CBBallApp*)AfxGetApp())->SwitchView(0);
}









HBRUSH CBBallView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		//pDC->SetTextColor(STATICCOLOR);
		pDC->SetTextColor(RGB(255, 215, 0));
		//pDC->SetBkColor(logbrush.lbColor);
		pDC->SetBkColor(BLACK);
		return hbr;
	case CTLCOLOR_LISTBOX:
		//pDC->SetBkColor(LISTBOXCOLOR);
		//pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return myBrush;
	case CTLCOLOR_BTN:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(0, 0, 0));
		return hbr;
		//     case CTLCOLOR_LISTBOX:
		   //       pDC->SetBkColor(LISTBOXCOLOR);
			  //    pDC->SetTextColor(LISTBOXTEXTCOLOR);
				 // return myBrush;

		//     case CTLCOLOR_SCROLLBAR:
			  //    pDC->SetTextColor(RGB(0,0,0));
				 // pDC->SetBkColor(LISTBOXCOLOR);
				  //return myBrush;

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


	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	 //return hbr;
}


