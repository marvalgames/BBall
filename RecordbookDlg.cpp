// RecordbookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "RecordbookDlg.h"
#include "CareerStatsCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordbookDlg dialog


CRecordbookDlg::CRecordbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordbookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecordbookDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_season_leaders = true;
	for(int i=0; i<=50; i++)
	{
		m_id_list[i] = 0;
	}
}


void CRecordbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordbookDlg)
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_LIST_RECORDS, m_list_records);
	DDX_Control(pDX, IDC_RADIO_PPG, m_button[0]);
	DDX_Control(pDX, IDC_RADIO_RPG, m_button[1]);
	DDX_Control(pDX, IDC_RADIO_APG, m_button[2]);
	DDX_Control(pDX, IDC_RADIO_SPG, m_button[3]);
	DDX_Control(pDX, IDC_RADIO_BPG, m_button[4]);
	DDX_Control(pDX, IDC_RADIO_FGP, m_button[5]);
	DDX_Control(pDX, IDC_RADIO_TGP, m_button[6]);
	DDX_Control(pDX, IDC_RADIO_FTP, m_button[7]);
	DDX_Control(pDX, IDC_RADIO_SEASON, m_button[8]);
	DDX_Control(pDX, IDC_RADIO_CAREER, m_button[9]);
	DDX_Control(pDX, IDOK, m_button[10]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordbookDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordbookDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_RADIO_SEASON, OnRadioSeason)
	ON_BN_CLICKED(IDC_RADIO_CAREER, OnRadioCareer)
	ON_BN_CLICKED(IDC_RADIO_APG, OnRadioApg)
	ON_BN_CLICKED(IDC_RADIO_SPG, OnRadioSpg)
	ON_BN_CLICKED(IDC_RADIO_BPG, OnRadioBpg)
	ON_BN_CLICKED(IDC_RADIO_FGP, OnRadioFgp)
	ON_BN_CLICKED(IDC_RADIO_FTP, OnRadioFtp)
	ON_BN_CLICKED(IDC_RADIO_TGP, OnRadioTgp)
	ON_BN_CLICKED(IDC_RADIO_PPG, OnRadioPpg)
	ON_BN_CLICKED(IDC_RADIO_RPG, OnRadioRpg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_RECORDS, OnDblclkListRecords)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordbookDlg message handlers

BOOL CRecordbookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	InitControls();
	ListPointsPerGameLeaders();

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRecordbookDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyrecordbook.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

BOOL CRecordbookDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyrecordbook.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
	//return CDialog::OnHelpInfo(pHelpInfo);
}

void CRecordbookDlg::ListPointsPerGameLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_ppg_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_ppg_te[te][i] - 1;
		
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];

		m_id_list[n] = m_recordbook.m_ppg_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_ppg_ye[te][i];
		double pts = m_recordbook.m_ppg[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}

void CRecordbookDlg::InitControls()
{
	m_category = 1;
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_records.SetBkColor(BK_COLOR);
	m_list_records.SetTextBkColor(TEXT_BK_COLOR);

	m_list_records.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);

    m_list_records.SetTextColor(RGB(0,0,0));
	m_list_records.SetFont(&m_font);

	SetHeaders();
	FillComboBox(1);


	CheckDlgButton(IDC_RADIO_PPG, 1);	
	CheckDlgButton(IDC_RADIO_SEASON, 1);	

	

}

void CRecordbookDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	SetHeaders();

	if(m_season_leaders == true && m_category == 1)
		ListPointsPerGameLeaders();	
	else if(m_season_leaders == true && m_category == 2)
		ListReboundsPerGameLeaders();	
	else if(m_season_leaders == true && m_category == 3)
		ListAssistsPerGameLeaders();	
	else if(m_season_leaders == true && m_category == 4)
		ListStealsPerGameLeaders();	
	else if(m_season_leaders == true && m_category == 5)
		ListBlocksPerGameLeaders();	
	else if(m_season_leaders == true && m_category == 6)
		ListFieldGoalPctLeaders();	
	else if(m_season_leaders == true && m_category == 7)
		ListFreeThrowPctLeaders();	
	else if(m_season_leaders == true && m_category == 8)
		ListThreeGoalPctLeaders();	
	else if(m_season_leaders == false && m_category == 1)
		ListCareerPointsPerGameLeaders();	
	else if(m_season_leaders == false && m_category == 2)
		ListCareerReboundsPerGameLeaders();	
	else if(m_season_leaders == false && m_category == 3)
		ListCareerAssistsPerGameLeaders();	
	else if(m_season_leaders == false && m_category == 4)
		ListCareerStealsPerGameLeaders();	
	else if(m_season_leaders == false && m_category == 5)
		ListCareerBlocksPerGameLeaders();	
	else if(m_season_leaders == false && m_category == 6)
		ListCareerFieldGoalPctLeaders();	
	else if(m_season_leaders == false && m_category == 7)
		ListCareerFreeThrowPctLeaders();	
	else if(m_season_leaders == false && m_category == 8)
		ListCareerThreeGoalPctLeaders();	
}

void CRecordbookDlg::OnRadioSeason() 
{
	// TODO: Add your control notification handler code here
	FillComboBox(1);
		m_season_leaders = true;
		SetHeaders();
		OnSelchangeComboTeams();
			
}

void CRecordbookDlg::OnRadioCareer() 
{
	// TODO: Add your control notification handler code here
	FillComboBox(2);
	m_season_leaders = false;
	SetHeaders();
	OnSelchangeComboTeams();
	
}

void CRecordbookDlg::ListCareerPointsPerGameLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_ppg_name[te][i];
    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_ppg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];

		m_id_list[n] = m_recordbook.m_car_ppg_id[te][i];
		m_names_list[n] = name;
		int pts = m_recordbook.m_car_pts[te][i];
		double pg = m_recordbook.m_car_ppg[te][i];
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);

		double f_pt = (double)pts;
		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_ppg_id[te][i]);
			points = "";
			f_pt=f_pt/100;
			ppg.Format("%.2f", f_pt);
		}


    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}

void CRecordbookDlg::OnRadioApg() 
{
	// TODO: Add your control notification handler code here
	m_category = 3;
	SetHeaders();
	if(m_season_leaders == true)
		ListAssistsPerGameLeaders();	
	else
		ListCareerAssistsPerGameLeaders();	

	//m_category = 3;


	
}

void CRecordbookDlg::OnRadioSpg() 
{
	// TODO: Add your control notification handler code here
	m_category = 4;
	SetHeaders();
	if(m_season_leaders == true)
		ListStealsPerGameLeaders();	
	else
		ListCareerStealsPerGameLeaders();	

	//m_category = 4;

	
}

void CRecordbookDlg::OnRadioBpg() 
{
	// TODO: Add your control notification handler code here
	m_category = 5;
	SetHeaders();
	if(m_season_leaders == true)
		ListBlocksPerGameLeaders();	
	else
		ListCareerBlocksPerGameLeaders();	

	//m_category = 5;
	
}

void CRecordbookDlg::OnRadioFgp() 
{
	// TODO: Add your control notification handler code here
	m_category = 6;
	SetHeaders();
	if(m_season_leaders == true)
		ListFieldGoalPctLeaders();	
	else
		ListCareerFieldGoalPctLeaders();
	
	//m_category = 6;


	
}

void CRecordbookDlg::OnRadioFtp() 
{
	// TODO: Add your control notification handler code here
	m_category = 7;
	SetHeaders();
	if(m_season_leaders == true)
		ListFreeThrowPctLeaders();	
	else
		ListCareerFreeThrowPctLeaders();	

	//m_category = 7;
	
}

void CRecordbookDlg::OnRadioTgp() 
{
	// TODO: Add your control notification handler code here
	m_category = 8;
	SetHeaders();
	if(m_season_leaders == true)
		ListThreeGoalPctLeaders();	
	else
		ListCareerThreeGoalPctLeaders();	
		
	
}

void CRecordbookDlg::OnRadioPpg() 
{
	// TODO: Add your control notification handler code here
	m_category = 1;
	SetHeaders();


	if(m_season_leaders == true)
		ListPointsPerGameLeaders();	
	else
		ListCareerPointsPerGameLeaders();

	
}









void CRecordbookDlg::ListCareerReboundsPerGameLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_rpg_name[te][i];
    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_rpg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_car_rpg_id[te][i];
		m_names_list[n] = name;

		int pts = m_recordbook.m_car_reb[te][i];
		double pg = m_recordbook.m_car_rpg[te][i];

		double f_pt = (double)pts;
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);
		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_rpg_id[te][i]);
			points = "";
			f_pt=f_pt/100;
			ppg.Format("%.2f", f_pt);
		}



    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerAssistsPerGameLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_apg_name[te][i];
    if(name == "") continue;
		
		CString team = "";

		m_id_list[n] = m_recordbook.m_car_apg_id[te][i];
		m_names_list[n] = name;

		int tm = m_recordbook.m_car_apg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];

		int pts = m_recordbook.m_car_ast[te][i];
		double pg = m_recordbook.m_car_apg[te][i];

		ppg.Format("%.2f", pg);
		points.Format("%d", pts);

		double f_pt = (double)pts;
		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_apg_id[te][i]);
			points = "";
			f_pt=f_pt/100;
			ppg.Format("%.2f", f_pt);
		}

    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerStealsPerGameLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_spg_name[te][i];
    if(name == "") continue;
		
		CString team = "";
		m_id_list[n] = m_recordbook.m_car_spg_id[te][i];
		m_names_list[n] = name;

		int tm = m_recordbook.m_car_spg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];

		int pts = m_recordbook.m_car_stl[te][i];
		double pg = m_recordbook.m_car_spg[te][i];
		double f_pt = (double)pts;
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);
		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_ppg_id[te][i]);
			points = "";
			f_pt=f_pt/100;
			ppg.Format("%.2f", f_pt);
		}

    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerBlocksPerGameLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_bpg_name[te][i];
    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_bpg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_car_bpg_id[te][i];
		m_names_list[n] = name;

		int pts = m_recordbook.m_car_blk[te][i];
		double pg = m_recordbook.m_car_bpg[te][i];
		double f_pt = (double)pts;
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);
		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_ppg_id[te][i]);
			points = "";
			f_pt=f_pt/100;
			ppg.Format("%.2f", f_pt);
		}

    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerFieldGoalPctLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
		CString name = m_recordbook.m_car_fgp_name[te][i];
		int id = m_recordbook.m_car_fgp_id[te][i];	
		if(name == "" || id==0) continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_fgp_te[te][i] - 1;
		if(te>0)
		{
			tm=-1;
			team.Format("%d", m_recordbook.m_car_fgp_id[te][i]);
			m_id_list[n] = 0;
		}
		else
		{
			m_id_list[n] = m_recordbook.m_car_fgp_id[te][i];
		}

		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];



		m_names_list[n] = name;

		int pts = m_recordbook.m_car_fgm[te][i];
		double pg = m_recordbook.m_car_fgp[te][i];
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);

		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_fgp_id[te][i]);
			points = "";
			ppg.Format("%.2f", pg);
		}

    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerFreeThrowPctLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_ftp_name[te][i];
//    if(name == "") continue;
		int id = m_recordbook.m_car_ftp_id[te][i];	
		if(name == "" || id==0) continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_ftp_te[te][i] - 1;
//		if(te>0) tm=-1;

		if(te>0)
		{
			tm=-1;
			team.Format("%d", m_recordbook.m_car_ftp_id[te][i]);
			m_id_list[n] = 0;
		}
		else
		{
			m_id_list[n] = m_recordbook.m_car_ftp_id[te][i];
		}


		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
//		m_id_list[n] = m_recordbook.m_car_ftp_id[te][i];
		m_names_list[n] = name;

		int pts = m_recordbook.m_car_ftm[te][i];
		double pg = m_recordbook.m_car_ftp[te][i];
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);

		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_ftp_id[te][i]);
			points = "";
			ppg.Format("%.2f", pg);
		}
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}


void CRecordbookDlg::ListCareerThreeGoalPctLeaders()
{
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, ppg;
	

		CString name = m_recordbook.m_car_tgp_name[te][i];
		int id = m_recordbook.m_car_tgp_id[te][i];	
		if(name == "" || id==0) continue;

//    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_car_tgp_te[te][i] - 1;
//		if(te>0) tm=-1;
		if(te>0)
		{
			tm=-1;
			team.Format("%d", m_recordbook.m_car_tgp_id[te][i]);
			m_id_list[n] = 0;
		}
		else
		{
			m_id_list[n] = m_recordbook.m_car_tgp_id[te][i];
		}

		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
//		m_id_list[n] = m_recordbook.m_car_tgp_id[te][i];
		m_names_list[n] = name;

		int pts = m_recordbook.m_car_tgm[te][i];
		double pg = m_recordbook.m_car_tgp[te][i];
		ppg.Format("%.2f", pg);
		points.Format("%d", pts);

		if(te>0)
		{
			m_id_list[n] = 0;
			team.Format("%d", m_recordbook.m_car_ftp_id[te][i]);
			points = "";
			ppg.Format("%.2f", pg);
		}
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,ppg);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}


}




void CRecordbookDlg::ListReboundsPerGameLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_rpg_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_rpg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];

		m_id_list[n] = m_recordbook.m_rpg_id[te][i];
		m_names_list[n] = name;


		int yr = m_recordbook.m_rpg_ye[te][i];
		double pts = m_recordbook.m_rpg[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}

void CRecordbookDlg::ListAssistsPerGameLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_apg_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_apg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_apg_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_apg_ye[te][i];
		double pts = m_recordbook.m_apg[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}


void CRecordbookDlg::ListStealsPerGameLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_spg_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_spg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_spg_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_spg_ye[te][i];
		double pts = m_recordbook.m_spg[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}


void CRecordbookDlg::ListBlocksPerGameLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_bpg_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_bpg_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_bpg_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_bpg_ye[te][i];
		double pts = m_recordbook.m_bpg[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}


void CRecordbookDlg::ListFieldGoalPctLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_fgp_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_fgp_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_fgp_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_fgp_ye[te][i];
		double pts = m_recordbook.m_fgp[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}


void CRecordbookDlg::ListFreeThrowPctLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_ftp_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_ftp_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_ftp_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_ftp_ye[te][i];
		double pts = m_recordbook.m_ftp[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}


void CRecordbookDlg::ListThreeGoalPctLeaders()
{
	
	m_list_records.DeleteAllItems();

	int te = m_combo_teams.GetCurSel();
	
		int n=0;

for(int i=1; i <= 50; i++)
{
		
		CString points, year;
	

		CString name = m_recordbook.m_tgp_name[te][i];

    if(name == "") continue;
		
		CString team = "";

		int tm = m_recordbook.m_tgp_te[te][i] - 1;
		if(tm >= 0) team = avg.m_settings.m_leagueTeamNames[tm];
		m_id_list[n] = m_recordbook.m_tgp_id[te][i];
		m_names_list[n] = name;

		int yr = m_recordbook.m_tgp_ye[te][i];
		double pts = m_recordbook.m_tgp[te][i];
		year.Format("%d", yr);
		points.Format("%.2f", pts);
    
	m_list_records.InsertItem(n, name);
	m_list_records.SetItemText(n,1,team);
    m_list_records.SetItemText(n,2,year);
    m_list_records.SetItemText(n,3,points);
	n = n + 1;

}

}

void CRecordbookDlg::OnRadioRpg() 
{
	// TODO: Add your control notification handler code here
	m_category = 2;
	SetHeaders();
	if(m_season_leaders == true)
		ListReboundsPerGameLeaders();	
	else
		ListCareerReboundsPerGameLeaders();	

	
}



void CRecordbookDlg::OnDblclkListRecords(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
int i = m_list_records.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
int items = m_list_records.GetItemCount();

	if(i>=0)
	{
		CCareerStatsCardDlg* card = new CCareerStatsCardDlg;
		int last = 0;
		for(int j=0; j<=items-1; j++)
		{
			card->m_pointer[j] = m_id_list[j];	
			card->m_names_list[j] = m_names_list[j];
			if(m_id_list[j] > 0) last = j;
		}
		card->m_leagueName = avg.m_settings.m_path + avg.m_settings.m_league_name;
		card->m_player_index = i;
		card->m_pl_index_start = 0;
		card->m_pl_index_end = last;
		card->DoModal();
		delete card;
	}

	*pResult = 0;
}

void CRecordbookDlg::SetHeaders()
{

	int te = m_combo_teams.GetCurSel();

	if(m_season_leaders == true)
	{

    m_list_records.DeleteColumn(0);
    m_list_records.InsertColumn(0,"name");    
	m_list_records.DeleteColumn(1);
    m_list_records.InsertColumn(1,"team");    
	m_list_records.DeleteColumn(2);
    m_list_records.InsertColumn(2,"year");    
	m_list_records.DeleteColumn(3);
    m_list_records.InsertColumn(3,"avg");    
  
    m_list_records.SetColumnWidth( 0, 150);
    m_list_records.SetColumnWidth( 1, 150);
    m_list_records.SetColumnWidth( 2, 120);
    m_list_records.SetColumnWidth( 3, 100);
	}
	else
	{

	if(te == 0)
	{

    m_list_records.DeleteColumn(0);
    m_list_records.InsertColumn(0,"name");    
	m_list_records.DeleteColumn(1);
    m_list_records.InsertColumn(1,"team");    
	m_list_records.DeleteColumn(2);
    m_list_records.InsertColumn(2,"avg");    
	m_list_records.DeleteColumn(3);
    m_list_records.InsertColumn(3,"total");    
  
    m_list_records.SetColumnWidth( 0, 150);
    m_list_records.SetColumnWidth( 1, 150);
    m_list_records.SetColumnWidth( 2, 120);
    m_list_records.SetColumnWidth( 3, 100);

	}
	else 
	{

    m_list_records.DeleteColumn(0);
    m_list_records.InsertColumn(0,"team");    
	m_list_records.DeleteColumn(1);
    m_list_records.InsertColumn(1,"year");    
	m_list_records.DeleteColumn(2);
    m_list_records.InsertColumn(2,"avg");    
	m_list_records.DeleteColumn(3);
    m_list_records.InsertColumn(3,"");    
  
    m_list_records.SetColumnWidth( 0, 90);
    m_list_records.SetColumnWidth( 1, 90);
    m_list_records.SetColumnWidth( 2, 90);
    m_list_records.SetColumnWidth( 3, 90);

	}




	}

}

void CRecordbookDlg::FillComboBox(int style)
{
	if(style==1)
	{
	m_combo_teams.ResetContent();
	m_combo_teams.AddString(avg.m_settings.m_league_name);
	for(int i=0; i<=31; i++)
	{
		CString tm = avg.m_settings.m_leagueTeamNames[i];
		if(tm != "") m_combo_teams.AddString(avg.m_settings.m_leagueTeamNames[i]);

	}
	m_combo_teams.SetCurSel(0);
	}
	else
	{

	m_combo_teams.ResetContent();
	m_combo_teams.AddString("Career Leaders");
	m_combo_teams.AddString("Team Offense Bests");
	m_combo_teams.AddString("Team Defense Worsts");
	m_combo_teams.AddString("Team Offense Worsts");
	m_combo_teams.AddString("Team Defense Best");
	m_combo_teams.SetCurSel(0);

	}






}

HBRUSH CRecordbookDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
}
