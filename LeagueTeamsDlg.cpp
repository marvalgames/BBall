// LeagueTeamsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
#include "LeagueTeamsDlg.h"
#include "AutoSchDlg.h"
#include "ImportPlayersDlg.h"
#include "DraftDlg.h"
#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamsDlg dialog


CLeagueTeamsDlg::CLeagueTeamsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLeagueTeamsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeagueTeamsDlg)
	m_leagueName = _T("Default_20-21");
	m_conferenceName1 = _T("");
	m_conferenceName2 = _T("");
	m_divisionName1 = _T("");
	m_divisionName2 = _T("");
	m_divisionName3 = _T("");
	m_divisionName4 = _T("");
	m_computerTrades = TRUE;
	m_checkCareer = FALSE;
	m_editYear = 0;
	m_fra_file_name = _T("");
	m_check_contracts = FALSE;
	m_check_import_data = FALSE;
	m_check_attributes = FALSE;
	m_check_staffs = FALSE;
	//}}AFX_DATA_INIT
	FA = new CPlayer[481];
	m_newLeague = true;
//	m_askAboutDraft = false;
	m_leagueSaved = false;
	m_data_saved = false;
	m_expand = false;
	m_expansion_occured = false;
	for(int i=0; i<=32; i++)
	{
		m_franchise_slot[i] = 0;
	}

}


void CLeagueTeamsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeagueTeamsDlg)
	DDX_Control(pDX, IDC_COMBO_ADDTEAM, m_comboaddteam);
	DDX_Control(pDX, IDC_COMBO_LIST_TEAMS, m_leagueTeamsBox);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_buttonSave);
	DDX_Control(pDX, IDC_BUTTON_DELETE_TEAM, m_buttonDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD_TEAM, m_buttonAdd);
	DDX_Control(pDX, IDC_LIST_RD4, m_rd4);
	DDX_Control(pDX, IDC_LIST_RD3, m_rd3);
	DDX_Control(pDX, IDC_LIST_RD2, m_rd2);
	DDX_Control(pDX, IDC_LIST_RD1, m_rd1);
	DDX_Control(pDX, IDC_LIST_PLAYOFF, m_playoff);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_teamControl);
	DDX_Control(pDX, IDC_LIST_DIVISION4, m_division4);
	DDX_Control(pDX, IDC_LIST_DIVISION3, m_division3);
	DDX_Control(pDX, IDC_LIST_DIVISION2, m_division2);
	DDX_Control(pDX, IDC_LIST_DIVISION1, m_division1);
	DDX_Text(pDX, IDC_EDIT_LEAGUE_NAME, m_leagueName);
	DDV_MaxChars(pDX, m_leagueName, 32);
	DDX_CBString(pDX, IDC_COMBO_CONFERENCE_1, m_conferenceName1);
	DDV_MaxChars(pDX, m_conferenceName1, 32);
	DDX_CBString(pDX, IDC_COMBO_CONFERENCE_2, m_conferenceName2);
	DDV_MaxChars(pDX, m_conferenceName2, 32);
	DDX_CBString(pDX, IDC_COMBO_DIVISION_1, m_divisionName1);
	DDV_MaxChars(pDX, m_divisionName1, 32);
	DDX_CBString(pDX, IDC_COMBO_DIVISION_2, m_divisionName2);
	DDV_MaxChars(pDX, m_divisionName2, 32);
	DDX_CBString(pDX, IDC_COMBO_DIVISION_3, m_divisionName3);
	DDV_MaxChars(pDX, m_divisionName3, 32);
	DDX_CBString(pDX, IDC_COMBO_DIVISION_4, m_divisionName4);
	DDV_MaxChars(pDX, m_divisionName4, 32);
	DDX_Check(pDX, IDC_CHECK_COMPUTER, m_computerTrades);
	DDX_Check(pDX, IDC_CHECK_CAREER, m_checkCareer);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_editYear);
	DDV_MinMaxInt(pDX, m_editYear, 1000, 4999);
	DDX_Text(pDX, IDC_EDIT_FRA_FILE_NAME, m_fra_file_name);
	DDV_MaxChars(pDX, m_fra_file_name, 32);
	DDX_Check(pDX, IDC_CHECK_RANDOM_CONTRACTS, m_check_contracts);
	DDX_Check(pDX, IDC_CHECK_IMPORT_DATA, m_check_import_data);
	DDX_Check(pDX, IDC_CHECK_RANDOM_ATTRIBUTES, m_check_attributes);
	DDX_Check(pDX, IDC_CHECK_RANDOMSTAFFS, m_check_staffs);
	//}}AFX_DATA_MAP
}

BOOL CLeagueTeamsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	m_data_imported = FALSE;
	m_seasonStarted = FALSE;
	m_skip_ages = TRUE;
	m_skip_contracts = FALSE;
	m_checkCareer = avg.m_settings.m_checkCareer;
	m_league_style = 1;
	m_imported_arena = false;
	m_comboIndex = 0;
	m_teamsInLeague = 0;
	m_addToDivision = 0; //can add to divisions when you click a team name on team list box
	m_originalNumberOfTeams = 0;
	m_originalLeagueName = avg.m_settings.m_league_name;
	m_button_ok.SetWindowText("Create");
	m_check_contracts = TRUE;
	m_check_attributes = TRUE;
	m_check_staffs = TRUE;


	facount = 0;
	m_conferenceName1 = avg.m_settings.m_conferenceName1;
	m_conferenceName2 = avg.m_settings.m_conferenceName2;
	m_divisionName1 = avg.m_settings.m_divisionName1;
	m_divisionName2 = avg.m_settings.m_divisionName2;
	m_divisionName3 = avg.m_settings.m_divisionName3;
	m_divisionName4 = avg.m_settings.m_divisionName4;

	//load defaults if file is blank
	if(m_conferenceName1 == "") m_conferenceName1 = "Eastern";
	if(m_conferenceName2 == "") m_conferenceName2 = "Western";
	if(m_divisionName1 == "") m_divisionName1 = "Atlantic";
	if(m_divisionName2 == "") m_divisionName2 = "Central";
	if(m_divisionName3 == "") m_divisionName3 = "Midwest";
	if(m_divisionName4 == "") m_divisionName4 = "Pacific";

	m_seasonStarted = TRUE;

	CString le =  m_originalLeagueName;
	le.MakeUpper();
	CString str, def;
	def = le.Mid(0, 7);
	def.MakeUpper();
	if (def == "DEFAULT") m_seasonStarted = FALSE;
	m_newLeague = false;
	for(int t=1; t<=32; t++)
	{
		CString team;
		int number = 15;
		if(t<33) 
		{
			team = avg.m_settings.m_leagueTeamNames[t-1];
			Team[t] = team;
		}

	}





	


	InitPlayoffStrings();							
	SetCursors();

	CheckDlgButton(IDC_RADIO_EXISITING, 1);	
	m_buttonSave.EnableWindow(TRUE);


	if(m_seasonStarted == TRUE && m_expand == FALSE)
	{
		m_buttonAdd.EnableWindow(FALSE);
		m_buttonDelete.EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_EXISITING)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_FICTIONAL)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_DRAFT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_YEAR)->EnableWindow(FALSE);
		m_button_ok.SetWindowText("Finished");
		GetDlgItem(IDC_EDIT_LEAGUE_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOM_CONTRACTS)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOMSTAFFS)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOM_ATTRIBUTES)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_IMPORT_DATA)->EnableWindow(FALSE);
//		GetDlgItem(IDC_CHECK_CAREER)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FRANCHISE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_YEAR)->EnableWindow(FALSE);

		GetDlgItem(IDC_BUTTON_ADD_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ADD_NEW2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ADD_NEW3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ADD_NEW4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FRA_FILE_NAME)->EnableWindow(FALSE);

		GetDlgItem(IDC_COMBO_CONFERENCE_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_CONFERENCE_2)->EnableWindow(FALSE);

		GetDlgItem(IDC_COMBO_DIVISION_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_DIVISION_2)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_DIVISION_3)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_DIVISION_4)->EnableWindow(FALSE);

		//GetDlgItem(IDC_EDIT_NAME)->EnableWindow(FALSE);
		//m_buttonSave.EnableWindow(FALSE);

		GetDlgItem(IDC_COMBO_ADDTEAM)->EnableWindow(FALSE);
		//GetDlgItem(IDC_COMBO_LIST_TEAMS)->EnableWindow(FALSE);
		GetDlgItem(IDC_LIST_CONTROL)->EnableWindow(FALSE);
	}


	

	for(int i=0; i<32; i++)
		{
			if(avg.m_settings.m_leagueTeamNames[i] != "")
			{
				m_leagueTeamsBox.AddString(avg.m_settings.m_leagueTeamNames[i]);
				m_originalNumberOfTeams = m_originalNumberOfTeams + 1;
			}
			if(avg.m_standings[i].m_division == m_divisionName1 && m_divisionName1 != "") 
				m_division1.AddString(avg.m_settings.m_leagueTeamNames[i]);
			else if(avg.m_standings[i].m_division == m_divisionName2 && m_divisionName2 != "") 
				m_division2.AddString(avg.m_settings.m_leagueTeamNames[i]);
			else if(avg.m_standings[i].m_division == m_divisionName3 && m_divisionName3 != "") 
				m_division3.AddString(avg.m_settings.m_leagueTeamNames[i]);
			else if(avg.m_standings[i].m_division == m_divisionName4 && m_divisionName4 != "") 
				m_division4.AddString(avg.m_settings.m_leagueTeamNames[i]);
		}
	if(avg.m_settings.m_leagueTeamNames[0] != "")  m_teamControl.AddString(avg.m_settings.m_player_gm[0]);				
	m_leagueTeamsBox.SetCurSel(0); 

	m_checkInjury = avg.m_settings.m_injury;


	OnSelchangeListLeagueTeams();
	if(m_editYear <= 0) m_editYear = 2000;
	if(m_checkInjury == 0) CheckDlgButton(IDC_RADIO_INJOFF, 1);	
	else if(m_checkInjury == 1) CheckDlgButton(IDC_RADIO_INJNORM, 1);	
	else if(m_checkInjury == 2) CheckDlgButton(IDC_RADIO_INJRND, 1);	
	else 
	{
		m_checkInjury = 1;
		CheckDlgButton(IDC_RADIO_INJNORM, 1);
	}

	//m_checkCareer = TRUE;

	//m_leagueName = "new_league";
	if(m_seasonStarted == true) m_leagueName = m_originalLeagueName;
	m_fra_file_name =  m_originalLeagueName;


	if(m_expand == true)
	{
		m_buttonAdd.EnableWindow(TRUE);
		m_buttonDelete.EnableWindow(FALSE);
		m_button_ok.SetWindowText("Finished");
		m_leagueName = m_originalLeagueName;
		GetDlgItem(IDC_EDIT_LEAGUE_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOM_CONTRACTS)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOMSTAFFS)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_RANDOM_ATTRIBUTES)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_IMPORT_DATA)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_CAREER)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FRANCHISE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_YEAR)->EnableWindow(FALSE);
		SetWindowText("Expansion / Realignment");
		GetDlgItem(IDC_RADIO_EXISITING)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_FICTIONAL)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_DRAFT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FRA_FILE_NAME)->EnableWindow(FALSE);
	}


	ListTeamCount();

	UpdateData(FALSE);


	return TRUE;
}




BEGIN_MESSAGE_MAP(CLeagueTeamsDlg, CDialog)
	//{{AFX_MSG_MAP(CLeagueTeamsDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD_TEAM, OnButtonAddTeam)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_TEAM, OnButtonDeleteTeam)
	ON_LBN_SELCHANGE(IDC_LIST_LEAGUE_TEAMS, OnSelchangeListLeagueTeams)
	ON_LBN_SETFOCUS(IDC_LIST_LEAGUE_TEAMS, OnSetfocusListLeagueTeams)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_BN_CLICKED(IDC_BUTTON_DRAFT, OnButtonDraft)
	ON_BN_DOUBLECLICKED(IDC_BUTTON_DRAFT, OnDoubleclickedButtonDraft)
	ON_WM_DESTROY()
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_RADIO_INJNORM, OnRadioInjnorm)
	ON_BN_CLICKED(IDC_RADIO_INJOFF, OnRadioInjoff)
	ON_BN_CLICKED(IDC_RADIO_INJRND, OnRadioInjrnd)
	ON_WM_CTLCOLOR()
	ON_EN_SETFOCUS(IDC_EDIT_NAME, OnSetfocusEditName)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_FRANCHISE, OnButtonFranchise)
	ON_BN_CLICKED(IDC_RADIO_DRAFT, OnRadioDraft)
	ON_BN_CLICKED(IDC_RADIO_FICTIONAL, OnRadioFictional)
	ON_BN_CLICKED(IDC_RADIO_EXISITING, OnRadioExisiting)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW, OnButtonAddNew)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW2, OnButtonAddNew2)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW3, OnButtonAddNew3)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW4, OnButtonAddNew4)
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAMS, OnSelchangeComboListTeams)
	ON_BN_CLICKED(IDC_CHECK_RANDOMSTAFFS, OnCheckRandomstaffs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamsDlg message handlers

void CLeagueTeamsDlg::OnButtonAddTeam() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE || m_expand == true)
	{
	UpdateData(TRUE);	
	BOOL NoAdd = FALSE;
	int count = m_leagueTeamsBox.GetCount();
	// Check if team selected is in list already
	//m_comboTeamNames.GetWindowText(m_leagueTeam);//team name
	
	//CString comboTeam;
	//int comboIndex = m_comboTeamNames.GetCurSel();

	CString tmp;
	GetDlgItem(IDC_COMBO_ADDTEAM)->GetWindowText(tmp);

	//GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);


	m_leagueTeam = tmp;

	int listIndex = m_leagueTeamsBox.GetCurSel();

	//if(comboIndex >= 0)m_comboTeamNames.GetLBText( comboIndex, comboTeam );

	int i=0;
	for(i=0; i < count; i++)
	{
		CString TeamName;
		m_leagueTeamsBox.GetLBText(i, TeamName);
		if(TeamName == m_leagueTeam) NoAdd = TRUE; 
	}
	
	if(NoAdd == FALSE)
	{
		int index = m_leagueTeamsBox.GetCurSel();
		if(index < 0) index = 0;
		if(count < 32 && m_leagueTeam != "")
		{
			avg.m_settings.m_player_gm[i] = "Computer";
			m_leagueTeamsBox.AddString(m_leagueTeam);
			m_teamControl.AddString("Computer");
		}	
		m_leagueTeam = "";
		//m_addToDivision = -1;
//		CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
//		CLeagueTeamsDlg::OnSelchangeListPlayoff(); 
		UpdateData(FALSE);	
		int co = m_leagueTeamsBox.GetCount();
		if(co >= 1) m_leagueTeamsBox.SetCurSel(co-1);
		OnSelchangeComboListTeams();
	}


	ListTeamCount();

	}
}

void CLeagueTeamsDlg::OnOK() 
{
	// TODO: Add extra validation here	
	CFileStatus status;
	ListTeamCount();

	BOOL SaveOk = TRUE;
	BOOL ExitOk = TRUE;
	//if names left blank fill with defaults
	m_teamsInLeague = 
		m_division1.GetCount() +
		m_division2.GetCount() +
		m_division3.GetCount() +
		m_division4.GetCount();
	UpdateData(TRUE);	

	avg.m_settings.m_league_name = m_leagueName;

		CString leagueFileName = avg.m_settings.m_path + m_leagueName + ".lge";
		bool writeOverExisting = true;
		BOOL newLeague = (CFile::GetStatus( leagueFileName, status ) == FALSE);
	
	if(((m_seasonStarted == FALSE || m_originalLeagueName != m_leagueName)
		&& newLeague == FALSE) && m_expand == false)
	{
		    CString message;
		    AfxFormatString1( message, IDS_STRING_MESSAGE_NEW_LEAGUE,
			   m_leagueName); 
		    MessageBox(message, "League Exists", MB_OK);
		    writeOverExisting = false;
		    SaveOk = FALSE;
		    ExitOk = FALSE;
		
	}


	if((m_seasonStarted == FALSE || m_originalLeagueName != m_leagueName)
		&& writeOverExisting == true && m_expand == false)
	{
	if(m_leagueTeamsBox.GetCount() != m_teamsInLeague)
	{
		SaveOk = FALSE;
		int r = AfxMessageBox("All teams have not been assigned to divisions.\n Do you still want to exit?", MB_YESNO);
		if(r == IDNO) ExitOk = FALSE;
	}	
	else if(m_leagueTeamsBox.GetCount() < 2)
	{
		SaveOk = FALSE;
		ExitOk = FALSE;
		int r = AfxMessageBox("A league must contain at least two teams.\n", MB_OK);
	}
	else
	{
		CString message;
		AfxFormatString1( message, IDS_STRING_MESSAGE, m_leagueName); 
		int Result = MessageBox(message, "Create League", MB_YESNO);
		if(Result == IDNO)
		{
			SaveOk = FALSE; 
			ExitOk = FALSE;
		}
		else
		{
			SaveOk = TRUE; 
			ExitOk = TRUE;
			m_leagueSaved = true;
		}
	}
	}

	if(SaveOk == TRUE && m_leagueTeamsBox.GetCount() > 0)
	{
		//UpdateData(TRUE);		
		CString string;
		m_rd1.GetText(m_rd1.GetCurSel(),string);
		avg.m_settings.m_rd1Format = string;
		m_rd2.GetText(m_rd2.GetCurSel(),string);
		avg.m_settings.m_rd2Format = string;
		m_rd3.GetText(m_rd3.GetCurSel(),string);
		avg.m_settings.m_rd3Format = string;
		m_rd4.GetText(m_rd4.GetCurSel(),string);
		avg.m_settings.m_rd4Format = string;
		m_playoff.GetText(m_playoff.GetCurSel(),string);
		avg.m_settings.m_playoffFormat = string;

	}
	if(SaveOk == TRUE && m_leagueTeamsBox.GetCount() > 0 && (m_seasonStarted == FALSE || m_expand == true))
	{

//		m_askAboutDraft = true;
		UpdateData(TRUE);	
				
		
		CString team_list[33];
		int co = 1;
		int x = m_division1.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division1.GetText(i-1, string);
			if(string != "")
			{
				team_list[co] = string;
				co = co + 1;
			}

		}


		x = m_division2.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division2.GetText(i-1, string);
			if(string != "")
			{
				team_list[co] = string;
				co = co + 1;
			}

		}

		x = m_division3.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division3.GetText(i-1, string);
			if(string != "")
			{
				team_list[co] = string;
				co = co + 1;
			}

		}

		x = m_division4.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division4.GetText(i-1, string);
			if(string != "")
			{
				team_list[co] = string;
				co = co + 1;
			}

		}

		int new_slots[33];
		new_slots[0] = 0;
		for(int i=1; i<=32; i++)
		{
			//new_team_list[i] = Team[i+1];
			if(Team[i] != "") 
			{
				new_slots[i] = i;
			}
			else
				new_slots[i] = 0;
		}


		for(int i=1; i<=32; i++)
		{
			bool found = false;
			for(int j=1; j<=32; j++)
			{
				if(Team[i] == team_list[j] && Team[i] != "")
				{
					found = true;
					m_franchise_slot[j] = i;
				}

			}

			if(found == false)
			{
				CRecord* rec = new CRecord;
				avg.m_standings[i-1] = *rec;
				delete rec;
				new_slots[i] = 0;
				Team[i] = "";
			}
		}


			int team_count = 1;
			for(int i=1; i<=32; i++)
			{
				if(new_slots[i] > 0)
				{
					
					new_slots[team_count] = new_slots[i];
					//new_team_list[team_count] = Team[i+1];
					avg.m_standings[team_count-1] = avg.m_standings[i-1];
					team_count = team_count + 1;
				}
			}
					
			for(int i=team_count; i<=32; i++)
			{
				CRecord* rec = new CRecord;
				avg.m_standings[i-1] = *rec;
				delete rec;
				new_slots[i] = 0;
			}

			
			for(int i=0; i<=32; i++)
			{
				bool in_original_list  = false;
				for(int j=0; j<=32; j++)
				{
					if(Team[j] == team_list[i] && Team[j] != "")
						in_original_list  = true;
				}
				if(in_original_list == false && team_list[i] != "")//new team added
				{
					new_slots[team_count] = 0;//0 slot means blank players
					avg.m_standings[team_count-1].m_leagueTeamNames = team_list[i];
					team_count = team_count + 1;
				}

			}	


if(m_seasonStarted == FALSE || m_originalLeagueName != m_leagueName || m_expand == true)
{


//	if(m_check_import_data == TRUE) ImportCsvData();

	m_data_saved = true;

	int id_count = 0;




	UpdateData(TRUE);

	CString import_file_name = avg.m_settings.m_path + m_fra_file_name + ".frn";
	CDisk* disk = new CDisk;
	bool city_file = disk->FileExists(import_file_name);


	if(city_file == true && m_expand == false) 
	{
		disk->ReadFranchiseData(import_file_name);
		for(int i=0; i<=99; i++)
		{
			avg.m_finance[i] = disk->avg.m_finance[i];
			avg.m_finance[i].SetEndOfSeasonSalaryCap(avg.m_owner[i].m_player_spending);
		}

	}
	else if(m_expand == false)
	{

		for(int i=0; i<=99; i++)
		{	
			avg.m_finance[i].GenerateRandomArenas();
			avg.m_finance[i].GenerateRandomCities();
			avg.m_finance[i].GenerateRandomFinances();
			avg.m_finance[i].SetEndOfSeasonSalaryCap(avg.m_owner[i].m_player_spending);

		}
	}

	delete disk;


CTeamFinancial* copy = new CTeamFinancial[33];

for(int t=1; t<=32; t++)
{
	copy[t-1] = avg.m_finance[t-1];

	int slot = new_slots[t];
	CString te = avg.m_standings[t-1].m_leagueTeamNames;
	CString div, con;
	FindDivision(te, div, con);
	avg.m_standings[t-1].m_division = div;
	avg.m_standings[t-1].m_conference = con;
	avg.m_settings.m_leagueTeamNames[t-1] = te;

	if(slot == 0 && t<32) continue;

	if(slot > 0) copy[t-1] = avg.m_finance[slot-1];


	int players = 480;
	if(t<32)
	{
		players = 30;
	}
	
	for(int  i = 1; i <= players; i++ )
	{
		CPlayer m_player;
		if(t<32 && i<30)
		{
			int ptr = (slot-1)*30+i;
			Player[t][i] = avg.m_actual[ptr];
			Player[t][i].m_team_paying = t+1;
			m_player = Player[t][i];
		}
		else if(t == 32 && FA[i].GetName() == "")
		{
			FA[i] = avg.m_actual[960 + i];
			FA[i].m_team_paying = 0;
			m_player = FA[i];
		}

		if(m_player.GetName() != "")
		{
			if(m_expand == false) id_count = id_count + 1;
			if(m_expand == false) m_player.m_id = id_count;
			if(m_expand == false) m_player.m_salary_id = id_count;

			if(m_expand == true) id_count = m_player.m_id;
			if(m_expand == true) m_player.m_id = id_count;
			if(m_expand == true) m_player.m_salary_id = id_count;
		}
		else
		{
			m_player.m_id = 0;
			m_player.m_salary_id = 0;
		}
	    


		if(t<32)
			Player[t][i] = m_player;
		else if(t == 32)
		{
			FA[i] = m_player;
		}

	}
}

for(int t=0; t<=31; t++)
{
	avg.m_finance[t] = copy[t];
	
}

delete [] copy;


if(m_league_style != 2)
{

for(int i=1; i<=960; i++)
{
	int t = 1 + (i-1)/30;
	int p = i - (t-1)*30;
	avg.m_actual[i] = Player[t][p];
	avg.m_actual[i].SetActive(1);
	avg.m_actual[i].m_team_paying_name = avg.m_settings.m_leagueTeamNames[t-1];
//	avg.m_actual[i].m_team_paying_name = avg.m_standings[t-1].m_leagueTeamNames;
	avg.m_actual[i].m_team_paying = t;
}
for(int i=1; i<=480; i++)
{
	avg.m_actual[960+i] = FA[i];
	avg.m_actual[960+i].SetActive(1);
	avg.m_actual[960+i].m_team_paying_name = "";
	avg.m_actual[960+i].m_team_paying = 0;
}

}

}




	if(m_league_style == 3)
	{
		m_check_contracts = TRUE;
		m_check_attributes = TRUE;
	}




	UpdateFranchiseFile();



	}
//	else m_askAboutDraft = false;




	
		if(m_originalLeagueName != m_leagueName && SaveOk == TRUE && m_leagueTeamsBox.GetCount() > 0 && m_expand == false)
		{
			bool CopySchedule = false;
			if(m_teamsInLeague == m_originalNumberOfTeams && m_originalLeagueName != m_leagueName)
			{
				CString message;
				AfxFormatString2( message, IDS_STRING_SCHEDULE_MAKER, m_leagueName, m_originalLeagueName); 
				int r = MessageBox(message, "Generate Schedule", MB_YESNO);
				if(r == IDYES)
					CopySchedule = true;
				else CopySchedule = false;
			}	
			else if(m_teamsInLeague == m_originalNumberOfTeams) 
				CopySchedule = true;

			if(CopySchedule == true)
			{
			}
			else
			{
				CallAutoScheduler();
			}
		}

	if(ExitOk == TRUE) 
	{		


		SaveOptions();
		if(m_expand == true && m_expansion_occured == true)
		{
			avg.m_settings.m_expanding = 1;
		}
		else
		{
			avg.m_settings.m_expanding = 0;
		}



		if(m_check_import_data == TRUE) ImportCsvData();




	for(int  t=1; t<=32; t++)//have to do this to ensure they are both the same / sucks but used both so to late to changed
	{
		avg.m_settings.m_leagueTeamNames[t-1] = avg.m_standings[t-1].m_leagueTeamNames;
	}

	CDialog::OnOK();	
	}
}
	
void CLeagueTeamsDlg::OnButtonDeleteTeam() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	int i = m_leagueTeamsBox.GetCurSel();
	if(i >= 0)
	{

	CString TeamNameDivision;
	CString TeamNameLeague;
	if(m_division1.GetCount() > 0)		
	{
	for(int j = 1; j <= m_division1.GetCount(); j++)
	{
		m_division1.GetText(j-1, TeamNameDivision);
		m_leagueTeamsBox.GetLBText(i, TeamNameLeague);
		if(TeamNameDivision == TeamNameLeague && TeamNameLeague != "")
			m_division1.DeleteString(j-1);

	}
	}
	if(m_division2.GetCount() > 0)		
	{
	for(int j = 1; j <= m_division2.GetCount(); j++)
	{
		m_division2.GetText(j-1, TeamNameDivision);
		m_leagueTeamsBox.GetLBText(i, TeamNameLeague);
		if(TeamNameDivision == TeamNameLeague  && TeamNameLeague != "")
			m_division2.DeleteString(j-1);
	}
	}
	if(m_division3.GetCount() > 0)		
	{
	for(int j = 1; j <= m_division3.GetCount(); j++)
	{
		m_division3.GetText(j-1, TeamNameDivision);
		m_leagueTeamsBox.GetLBText(i, TeamNameLeague);
		if(TeamNameDivision == TeamNameLeague && TeamNameLeague != "")
			m_division3.DeleteString(j-1);

	}
	}
	if(m_division4.GetCount() > 0)		
	{
	for(int j = 1; j <= m_division4.GetCount(); j++)
	{
		m_division4.GetText(j-1, TeamNameDivision);
		m_leagueTeamsBox.GetLBText(i, TeamNameLeague);
		if(TeamNameDivision == TeamNameLeague && TeamNameLeague != "")
			m_division4.DeleteString(j-1);

	}
	}

	CString tmp;
	m_leagueTeamsBox.GetLBText(i,tmp);
	if(tmp != "") m_comboaddteam.InsertString(-1, tmp);


	m_leagueTeamsBox.DeleteString(i);
	m_leagueTeamsBox.SetCurSel(0); 
	m_teamControl.DeleteString(i);
	m_teamControl.SetCurSel(0); 
//	CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
//	CLeagueTeamsDlg::OnSelchangeListPlayoff(); 
	UpdateData(FALSE);	
	}

	i=m_leagueTeamsBox.GetCurSel();
	if(i >= 0)
	{
	CString TeamName;
	m_leagueTeamsBox.GetLBText(i, TeamName);
	m_editName.SetWindowText(TeamName);
	}
	ListTeamCount();
	}
}

void CLeagueTeamsDlg::OnSelchangeListLeagueTeams() 
{
	// TODO: Add your control notification handler code here
	m_addToDivision = m_leagueTeamsBox.GetCurSel();
	if(m_addToDivision >= 0)
	{
	m_teamControl.ResetContent();
	m_teamControl.AddString(avg.m_settings.m_player_gm[m_addToDivision]);
	CString name;
	m_leagueTeamsBox.GetLBText(m_addToDivision, name);
	m_editName.SetWindowText(name);
	}
}



void CLeagueTeamsDlg::OnSetfocusListLeagueTeams() 
{
	// TODO: Add your control notification handler code here
}


void CLeagueTeamsDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_leagueTeamsBox.GetCurSel();
	if(index >= 0)
	{
		CString TeamControl;
  		TeamControl = avg.m_settings.m_player_gm[index];
		if(TeamControl == "Computer") TeamControl = "Player";
		else	TeamControl = "Computer";
		avg.m_settings.m_player_gm[index] = TeamControl;
		m_teamControl.ResetContent();
		m_teamControl.AddString(TeamControl);
	}
}

void CLeagueTeamsDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_seasonStarted == FALSE || m_expand == true)
	{
	int result = AfxMessageBox("Are you sure you want to cancel?", MB_YESNO);
	if(result == IDYES) CDialog::OnCancel();
	}
	else
		CDialog::OnCancel();
}


BOOL CLeagueTeamsDlg::CheckForDuplicateLeagueTeam()
{
	BOOL NOADD = FALSE;
	CString team;
	m_leagueTeamsBox.GetLBText(m_addToDivision, team);
	for(int i=1; i <= m_division1.GetCount(); i++)
	{
		CString t;
		m_division1.GetText(i-1, t);
		if(t == team) 
		{
			NOADD = TRUE;
			m_division1.DeleteString(i-1);
		}
	}
	for(int i=1; i <= m_division2.GetCount(); i++)
	{
		CString t;
		m_division2.GetText(i-1, t);
//		if(t == team) NOADD = TRUE;
		if(t == team) 
		{
			NOADD = TRUE;
			m_division2.DeleteString(i-1);
		}
	}	
	for(int i=1; i <= m_division3.GetCount(); i++)
	{
		CString t;
		m_division3.GetText(i-1, t);
//		if(t == team) NOADD = TRUE;
		if(t == team) 
		{
			NOADD = TRUE;
			m_division3.DeleteString(i-1);
		}

	}	
	for(int i=1; i <= m_division4.GetCount(); i++)
	{
		CString t;
		m_division4.GetText(i-1, t);
//		if(t == team) NOADD = TRUE;
		if(t == team) 
		{
			NOADD = TRUE;
			m_division4.DeleteString(i-1);
		}

	}	
	return NOADD;
}

void CLeagueTeamsDlg::InitPlayoffStrings() 
{
	// TODO: Add your control notification handler code here
		CString string = "1 team per division";
		m_playoff.AddString(string);
		string = "2 teams per division";
		m_playoff.AddString(string);
		string = "4 teams per division";
		m_playoff.AddString(string);
		string = "1 team per conference";
		m_playoff.AddString(string);
		string = "2 teams per conference";
		m_playoff.AddString(string);
		string = "4 teams per conference";
		m_playoff.AddString(string);
		string = "8 teams per conference";
		m_playoff.AddString(string);

		m_rd1.AddString("1 of 1");
		m_rd1.AddString("2 of 3");
		m_rd1.AddString("3 of 5");
		m_rd1.AddString("4 of 7");
		m_rd2.AddString("1 of 1");
		m_rd2.AddString("2 of 3");
		m_rd2.AddString("3 of 5");
		m_rd2.AddString("4 of 7");
		m_rd3.AddString("1 of 1");
		m_rd3.AddString("2 of 3");
		m_rd3.AddString("3 of 5");
		m_rd3.AddString("4 of 7");
		m_rd4.AddString("1 of 1");
		m_rd4.AddString("2 of 3");
		m_rd4.AddString("3 of 5");
		m_rd4.AddString("4 of 7");


		m_playoff.SetCurSel(0);
		m_rd1.SetCurSel(0);
		m_rd2.SetCurSel(0);
		m_rd3.SetCurSel(0);
		m_rd4.SetCurSel(0);


}

/*void CLeagueTeamsDlg::OnSelchangeListPlayoff() 
{
	// TODO: Add your control notification handler code here
	int playoffTeams = 0;
	int division1 = m_division1.GetCount();
	int division2 = m_division2.GetCount();
	int division3 = m_division3.GetCount();
	int division4 = m_division4.GetCount();
	int conference1 = division1 + division2;
	int conference2 = division3 + division4;
	int conferences = ((division1 + division2) > 0) +
						((division3 + division4) > 0);
	int divisions =
		(division1 > 0) + (division2 > 0) + (division3 > 0) + (division4 > 0);
	CString t;
	int index = m_playoff.GetCurSel();
	if(index >= 0) m_playoff.GetText(index, t);
	if(t == "1 team per conference") playoffTeams = conferences * 1;
	if(t == "2 teams per conference") playoffTeams = conferences * 2;
	if(t == "4 teams per conference") playoffTeams = conferences * 4;
	if(t == "8 teams per conference") playoffTeams = conferences * 8;
	if(t == "1 team per division") playoffTeams = divisions * 1;
	if(t == "2 teams per division") playoffTeams = divisions * 2;
	if(t == "4 teams per division") playoffTeams = divisions * 4;
	avg.m_settings.m_playoffFormat = t; 
	m_rd1.ResetContent();
	m_rd2.ResetContent();
	m_rd3.ResetContent();
	m_rd4.ResetContent();
	if(playoffTeams >= 2) 
	{
	}
	if(playoffTeams >= 4) 
	{
		m_rd2.AddString("1 of 1");
		m_rd2.AddString("2 of 3");
		m_rd2.AddString("3 of 5");
		m_rd2.AddString("4 of 7");
	}
	if(playoffTeams >= 8) 
	{
		m_rd3.AddString("1 of 1");
		m_rd3.AddString("2 of 3");
		m_rd3.AddString("3 of 5");
		m_rd3.AddString("4 of 7");
	}
	if(playoffTeams >= 16) 
	{
		m_rd4.AddString("1 of 1");
		m_rd4.AddString("2 of 3");
		m_rd4.AddString("3 of 5");
		m_rd4.AddString("4 of 7");
	}
	if(playoffTeams < 2) 
	{
		m_rd1.AddString("None");
		m_rd2.AddString("None");
		m_rd3.AddString("None");
		m_rd4.AddString("None");
	}
	if(playoffTeams == 2) 
	{
		m_rd2.AddString("None");
		m_rd3.AddString("None");
		m_rd4.AddString("None");
	}
	if(playoffTeams == 4) 
	{
		m_rd3.AddString("None");
		m_rd4.AddString("None");
	}
	if(playoffTeams == 8) m_rd4.AddString("None");
	m_rd1.SetCurSel(0);
	m_rd2.SetCurSel(0);
	m_rd3.SetCurSel(0);
	m_rd4.SetCurSel(0);
	m_playoff.SetCurSel(0);
}*/



void CLeagueTeamsDlg::OnButtonDraft() 
{
	// TODO: Add your control notification handler code here	
}

void CLeagueTeamsDlg::OnDoubleclickedButtonDraft() 
{
	// TODO: Add your control notification handler code here
}

void CLeagueTeamsDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] FA;
	
}

void CLeagueTeamsDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//  	WinHelp(HID_LEAGUE_EDIT);		
//	HtmlHelp(NULL, "jumpshot.chm::/html/setupnew.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL CLeagueTeamsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/setupnew.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
//  	WinHelp(HID_LEAGUE_EDIT);	
//	return TRUE;
}




void CLeagueTeamsDlg::OnRadioInjnorm() 
{
	// TODO: Add your control notification handler code here
	m_checkInjury = 1;
}

void CLeagueTeamsDlg::OnRadioInjoff() 
{
	// TODO: Add your control notification handler code here
	m_checkInjury = 0;
}

void CLeagueTeamsDlg::OnRadioInjrnd() 
{
	// TODO: Add your control notification handler code here
	m_checkInjury = 2;	
}

void CLeagueTeamsDlg::SaveOptions()
{
		UpdateData(TRUE);
		avg.m_settings.m_conferenceName1 = m_conferenceName1;
		avg.m_settings.m_conferenceName2 = m_conferenceName2;
		avg.m_settings.m_divisionName1 = m_divisionName1;
		avg.m_settings.m_divisionName2 = m_divisionName2;
		avg.m_settings.m_divisionName3 = m_divisionName3;
		avg.m_settings.m_divisionName4 = m_divisionName4;
		
		avg.m_settings.m_scouts[32] = 0;
		avg.m_settings.m_coaches[32] = 0;
		for(int i=0; i<=31; i++)
		{
			if(avg.m_settings.m_player_gm[i] == "Player")
			{
				avg.m_settings.m_save_box[i] = 1;
				avg.m_settings.m_save_pbp[i] = 1;
				avg.m_settings.m_get_offers[i] = 1;
			}
			else
				avg.m_settings.m_player_gm[i] = "Computer";

		}

//		if(m_computerTrades == false)
//			avg.m_settings.m_computerTrades = 0;
//		else
			avg.m_settings.m_computerTrades = 1;
	//avg.m_settings.m_current_stage = 0;
	

	avg.m_settings.m_currentYear = m_editYear;
	avg.m_settings.m_checkCareer = m_checkCareer;
	avg.m_settings.m_injury = m_checkInjury;
	avg.m_settings.m_numberteams = m_teamsInLeague;

	CDialog::OnOK();
}




HBRUSH CLeagueTeamsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

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
//     case CTLCOLOR_LISTBOX:
  //        pDC->SetBkColor(LISTBOXCOLOR);
    //      pDC->SetTextColor(LISTBOXTEXTCOLOR);
      //    return myBrush;

	case CTLCOLOR_LISTBOX:
		  //pDC->SetBkMode(TRANSPARENT);
          pDC->SetBkColor(LISTBOXCOLOR);
          pDC->SetTextColor(LISTBOXTEXTCOLOR);
          return myBrush2;

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
//	
//	// TODO: Change any attributes of the DC here
//		pDC->SetTextColor(RGB(0,0,0));
//	if (nCtlColor == CTLCOLOR_LISTBOX)
//	{
//		pDC->SetBkMode(TRANSPARENT);
//		pDC->SetBkColor(RGB(255,255,226));	
//		return HBRUSH(myBrush);
//	}
//	return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 
}

void CLeagueTeamsDlg::OnSetfocusEditName() 
{
	// TODO: Add your control notification handler code here
}

void CLeagueTeamsDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	CString string;
	m_editName.GetWindowText(string);
	int index = m_leagueTeamsBox.GetCurSel();
			

	CString oldString;
	m_leagueTeamsBox.GetLBText(index, oldString);

    for(int i=0; i<=32; i++)
	{
		if(oldString == Team[i] && oldString != "" && string != "")
		{
            Team[i] = string;
			avg.m_standings[i-1].m_leagueTeamNames = string;
		}
	}

	int slot = m_leagueTeamsBox.FindStringExact( -1, oldString);
	if(slot >= 0)
	{
		m_leagueTeamsBox.DeleteString(slot);
		m_leagueTeamsBox.InsertString(slot, string);
	}
	slot = m_division1.FindStringExact( -1, oldString);
	if(slot >= 0)
	{
		m_division1.DeleteString(slot);
		m_division1.InsertString(slot, string);
	}
	slot = m_division2.FindStringExact( -1, oldString);
	if(slot >= 0)
	{
		m_division2.DeleteString(slot);
		m_division2.InsertString(slot, string);
	}
	slot = m_division3.FindStringExact( -1, oldString);
	if(slot >= 0)
	{
		m_division3.DeleteString(slot);
		m_division3.InsertString(slot, string);
	}
	slot = m_division4.FindStringExact( -1, oldString);
	if(slot >= 0)
	{
		m_division4.DeleteString(slot);
		m_division4.InsertString(slot, string);
	}
	m_leagueTeamsBox.SetCurSel(index);
	OnSelchangeListLeagueTeams();
}




void CLeagueTeamsDlg::OnButtonFranchise() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fil(true, ".frn", "default", OFN_HIDEREADONLY,
		"Stadium Files (*.frn)|*.frn|", NULL);
	int result = fil.DoModal();	
	if(result == IDOK)
	{	
		m_imported_arena = true;
		m_fra_file_name  = fil.GetFileTitle();
	}	
	UpdateData(FALSE);
}

void CLeagueTeamsDlg::UpdateFranchiseFile()
{


	UpdateData(TRUE);



	if(m_expand == true)
	{

		int count = m_teamsInLeague;
		for(int i=m_originalNumberOfTeams; i < count; i++)
		{
			int slot = avg.IntRandom(67)+32;
			avg.m_finance[i] = avg.m_finance[slot];
			avg.m_finance[i].m_arena_name = avg.m_finance[i].m_city_name + " Arena";
		}

	}


	for(int i=0; i<=31; i++)
	{	
		avg.m_finance[i].m_team_name = avg.m_settings.m_leagueTeamNames[i];
	}
}

void CLeagueTeamsDlg::OnRadioDraft() 
{
	// TODO: Add your control notification handler code here
	m_league_style = 2;	
}

void CLeagueTeamsDlg::OnRadioFictional() 
{
	// TODO: Add your control notification handler code here
	m_league_style = 3;	
}

void CLeagueTeamsDlg::OnRadioExisiting() 
{
	// TODO: Add your control notification handler code here
	m_league_style = 1;	
}




void CLeagueTeamsDlg::ImportCsvData()
{
	UpdateData(TRUE);
	CImportPlayersDlg* imp = new CImportPlayersDlg;
	imp->m_league_style = m_league_style;
	imp->m_path = avg.m_settings.m_path;
	imp->m_league_name = m_leagueName;
	int counter = 0;
	for(int i=1; i<=32; i++)
	{
		for(int j=1; j<=30; j++)
		{
			counter = counter + 1;
			imp->avg.m_actual[counter] = Player[i][j];
		}
	}
	for(int j=1; j<=480; j++)
	{
		imp->avg.m_actual[960 + j] = FA[j];
	}
	CString team_names[33];
	for(int i=0; i<=32; i++)
	{
		imp->m_league_team_names[i] = avg.m_standings[i].m_leagueTeamNames;
	}
	imp->m_current_yr = m_editYear + 1;
	int result = imp->DoModal();
	if(imp->m_data_imported == true)
	{
		
	m_editYear = imp->m_current_yr - 1;
	int counter = 0;
    m_import_rookies = imp->m_check_rookies;

	for(int i=1; i<=32; i++)
	{
		for(int j=1; j<=30; j++)
		{
			counter = counter + 1;
//			Player[i][j] = imp->avg.m_actual[counter];
			avg.m_actual[(i-1)*30+j] = imp->avg.m_actual[counter];
		}
	}

	for(int j=1; j<=480; j++)
	{
//		FA[j] = imp->avg.m_actual[960 + j];
		avg.m_actual[960+j] = imp->avg.m_actual[960+j];
	}
	}
	if(imp->m_data_imported == true)
	{
		m_check_contracts = TRUE;	
		m_check_attributes = TRUE;

        if(m_import_rookies == TRUE)//historical import
		{
        m_skip_ages = FALSE;
		m_skip_contracts = FALSE;
		}
		else
		{
		m_skip_ages = imp->m_check_ages;
		m_skip_contracts = imp->m_check_contracts;
		}
		m_data_imported = TRUE;
	}
	delete imp;

	UpdateData(FALSE);

	GetDlgItem(IDC_CHECK_RANDOM_CONTRACTS)->EnableWindow(FALSE);
}

void CLeagueTeamsDlg::OnButtonAddNew() 
{

	// TODO: Add your control notification handler code here

		//OnButtonDeleteTeam();


		if(m_seasonStarted == FALSE || m_expand == true)
	{
	//used to check all divisions for duplicates
	m_addToDivision = m_leagueTeamsBox.GetCurSel();
	if(m_addToDivision >= 0 && m_division1.GetCount() < 8 && m_leagueTeamsBox.GetCount() > 0)
	{
		//add team selected in league team list to division list
		CString team;
		m_leagueTeamsBox.GetLBText(m_addToDivision, team);
		BOOL NOADD = CheckForDuplicateLeagueTeam(); 
		//if(NOADD == FALSE)
		//{
			m_division1.AddString(team);			
	//		m_addToDivision = m_leagueTeamsBox.GetCurSel();
			m_leagueTeamsBox.SetCurSel(m_addToDivision);
//			CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
		//}
		m_expansion_occured = true;
	}

	ListTeamCount();

	}

	
}

void CLeagueTeamsDlg::OnButtonAddNew2() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE || m_expand == true)
	{	
	BOOL NOADD = FALSE;
	m_addToDivision = m_leagueTeamsBox.GetCurSel();
	if(m_addToDivision >= 0 && m_division2.GetCount() < 8 && m_leagueTeamsBox.GetCount() > 0)
	{
		//add team selected in league team list to division list
		CString team;
		m_leagueTeamsBox.GetLBText(m_addToDivision, team);
		BOOL NOADD = CheckForDuplicateLeagueTeam(); 
	//	if(NOADD == FALSE)
	//	{
			m_division2.AddString(team);			
			m_leagueTeamsBox.SetCurSel(m_addToDivision);
//			CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
		m_expansion_occured = true;
	//	}
	}
	ListTeamCount();
	}

	
}

void CLeagueTeamsDlg::OnButtonAddNew3() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE || m_expand == true)
	{
	BOOL NOADD = FALSE;
	m_addToDivision = m_leagueTeamsBox.GetCurSel();
	if(m_addToDivision >= 0 && m_division3.GetCount() < 8 && m_leagueTeamsBox.GetCount() > 0)
	{
		//add team selected in league team list to division list
		CString team;
	//	m_addToDivision = m_leagueTeamsBox.GetCurSel();
		m_leagueTeamsBox.GetLBText(m_addToDivision, team);
		BOOL NOADD = CheckForDuplicateLeagueTeam(); 
		//if(NOADD == FALSE)
		//{
			m_division3.AddString(team);			
			m_leagueTeamsBox.SetCurSel(m_addToDivision);
//			CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
		m_expansion_occured = true;
		//}
	}
	ListTeamCount();
	}


}

	


void CLeagueTeamsDlg::OnButtonAddNew4() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE || m_expand == true)
	{
	BOOL NOADD = FALSE;
	m_addToDivision = m_leagueTeamsBox.GetCurSel();
	if(m_addToDivision >= 0 && m_division4.GetCount() < 8 && m_leagueTeamsBox.GetCount() > 0)
	{
		//add team selected in league team list to division list
		CString team;
	//	m_addToDivision = m_leagueTeamsBox.GetCurSel();
		m_leagueTeamsBox.GetLBText(m_addToDivision, team);
		BOOL NOADD = CheckForDuplicateLeagueTeam(); 
		//if(NOADD == FALSE)
		//{
			m_division4.AddString(team);			
			m_leagueTeamsBox.SetCurSel(m_addToDivision);
//			CLeagueTeamsDlg::OnSetfocusListPlayoff(); 
		m_expansion_occured = true;
		//}
	}
	ListTeamCount();
	}
	
}


void CLeagueTeamsDlg::FindDivision(CString tm, CString &division, CString &conference)
{
		int x = m_division1.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division1.GetText(i-1, string);
			if(string == tm && tm != "")
			{
				division = m_divisionName1;
				conference = m_conferenceName1;
			}
		}

		x = m_division2.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division2.GetText(i-1, string);
			if(string == tm && tm != "")
			{
				division = m_divisionName2;
				conference = m_conferenceName1;
			}
		}

		x = m_division3.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division3.GetText(i-1, string);
			if(string == tm && tm != "")
			{
				division = m_divisionName3;
				conference = m_conferenceName2;
			}
		}

		x = m_division4.GetCount();
		for(int i=1; i<=x; i++)
		{
			CString string;
			m_division4.GetText(i-1, string);
			if(string == tm && tm != "")
			{
				division = m_divisionName4;
				conference = m_conferenceName2;
			}
		}


}

void CLeagueTeamsDlg::CallAutoScheduler()
{
	CAutoSchDlg sch;
	sch.m_currentMonth = 1;
	sch.m_currentDay = 1;
	for(int i=0; i<=31; i++)
	{
		sch.m_leagueTeamNames[i+1] = avg.m_settings.m_leagueTeamNames[i];
		sch.m_conference[i+1] = avg.m_standings[i].m_conference;
		sch.m_division[i+1] = avg.m_standings[i].m_division;
		
	}
	sch.m_conferenceName1 = avg.m_settings.m_conferenceName1;
	sch.m_conferenceName2 = avg.m_settings.m_conferenceName2;
	sch.m_divisionName1 = avg.m_settings.m_divisionName1;
	sch.m_divisionName2 = avg.m_settings.m_divisionName2;
	sch.m_divisionName3 = avg.m_settings.m_divisionName3;
	sch.m_divisionName4 = avg.m_settings.m_divisionName4;
	sch.teams = avg.m_settings.m_numberteams;

	int result = sch.DoModal();
	if(result == IDOK)
	{

	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{

					avg.m_sched.m_schedule[i][j][k] = sch.m_sch[i][j][k];
			}
		}
	}
	}
}

void CLeagueTeamsDlg::OnSelchangeComboListTeams() 
{
	// TODO: Add your control notification handler code here
//	CString string;
//	m_editName.GetWindowText(string);	

	int i=m_leagueTeamsBox.GetCurSel();
	if(i >= 0)
	{
	CString TeamName;
	m_leagueTeamsBox.GetLBText(i, TeamName);
	m_editName.SetWindowText(TeamName);
	}

}

void CLeagueTeamsDlg::ListTeamCount()
{
	CString string;
	int c1 = m_leagueTeamsBox.GetCount();
	int c2 = m_division1.GetCount() +
		m_division2.GetCount() +
		m_division3.GetCount() +
		m_division4.GetCount();
	string.Format("%d teams in the Team List : %d teams have been assigned to divisions", c1, c2);
	GetDlgItem(IDC_STATIC_COUNT)->SetWindowText(string);
	
}

void CLeagueTeamsDlg::OnCheckRandomstaffs() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	
}

void CLeagueTeamsDlg::SetCursors()
{
	// TODO: Add your control notification handler code here


		CString string = "1 team per division";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(0);
		string = "2 teams per division";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(1);
		string = "4 teams per division";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(2);
		string = "1 team per conference";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(3);
		string = "2 teams per conference";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(4);
		string = "4 teams per conference";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(5);
		string = "8 teams per conference";
		if(avg.m_settings.m_playoffFormat == string) m_playoff.SetCurSel(6);


	
		if(avg.m_settings.m_rd1Format == "1 of 1")
			m_rd1.SetCurSel(0);
		else if(avg.m_settings.m_rd1Format == "2 of 3")
			m_rd1.SetCurSel(1);
		else if(avg.m_settings.m_rd1Format == "3 of 5")
			m_rd1.SetCurSel(2);
		else if(avg.m_settings.m_rd1Format == "4 of 7")
			m_rd1.SetCurSel(3);
			
		if(avg.m_settings.m_rd2Format == "1 of 1")
			m_rd2.SetCurSel(0);
		else if(avg.m_settings.m_rd2Format == "2 of 3")
			m_rd2.SetCurSel(1);
		else if(avg.m_settings.m_rd2Format == "3 of 5")
			m_rd2.SetCurSel(2);
		else if(avg.m_settings.m_rd2Format == "4 of 7")
			m_rd2.SetCurSel(3);
			
		if(avg.m_settings.m_rd3Format == "1 of 1")
			m_rd3.SetCurSel(0);
		else if(avg.m_settings.m_rd3Format == "2 of 3")
			m_rd3.SetCurSel(1);
		else if(avg.m_settings.m_rd3Format == "3 of 5")
			m_rd3.SetCurSel(2);
		else if(avg.m_settings.m_rd3Format == "4 of 7")
			m_rd3.SetCurSel(3);
			
		if(avg.m_settings.m_rd4Format == "1 of 1")
			m_rd4.SetCurSel(0);
		else if(avg.m_settings.m_rd4Format == "2 of 3")
			m_rd4.SetCurSel(1);
		else if(avg.m_settings.m_rd4Format == "3 of 5")
			m_rd4.SetCurSel(2);
		else if(avg.m_settings.m_rd4Format == "4 of 7")
			m_rd4.SetCurSel(3);
			
}
