// HistoryAwardsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "CareerStatsCardDlg.h"
#include "HistoryAwardsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryAwardsDlg dialog


CHistoryAwardsDlg::CHistoryAwardsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryAwardsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryAwardsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHistoryAwardsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryAwardsDlg)
	DDX_Control(pDX, IDC_LIST_PLAYERS, m_list_players);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryAwardsDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryAwardsDlg)
	ON_BN_CLICKED(IDC_RADIO_MVP, OnRadioMvp)
	ON_BN_CLICKED(IDC_RADIO_DEFENSE, OnRadioDefense)
	ON_BN_CLICKED(IDC_RADIO_ROOKIES, OnRadioRookies)
	ON_BN_CLICKED(IDC_RADIO_ASSISTS, OnRadioAssists)
	ON_BN_CLICKED(IDC_RADIO_BLOCKS, OnRadioBlocks)
	ON_BN_CLICKED(IDC_RADIO_POINTS, OnRadioPoints)
	ON_BN_CLICKED(IDC_RADIO_REBOUNDS, OnRadioRebounds)
	ON_BN_CLICKED(IDC_RADIO_STEALS, OnRadioSteals)
	ON_BN_CLICKED(IDC_RADIO_PLAYOFF, OnRadioPlayoff)
	ON_BN_CLICKED(IDC_RADIO_6TH, OnRadio6th)
	ON_BN_CLICKED(IDC_RADIO_CHAMPION, OnRadioChampion)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PLAYERS, OnDblclkListPlayers)
	ON_BN_CLICKED(IDC_RADIO_ALLSTAR, OnRadioAllstar)
	ON_BN_CLICKED(IDC_RADIO_ROOKIESTAR, OnRadioRookiestar)
	ON_BN_CLICKED(IDC_RADIO_THREE, OnRadioThree)
	ON_BN_CLICKED(IDC_RADIO_DUNK, OnRadioDunk)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryAwardsDlg message handlers

BOOL CHistoryAwardsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	InitControls();
	ReadAwards();
	ListMvp();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHistoryAwardsDlg::OnRadioMvp() 
{
	// TODO: Add your control notification handler code here
	ListMvp();
}

void CHistoryAwardsDlg::InitControls()
{

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_players.SetBkColor(BK_COLOR);
	m_list_players.SetTextBkColor(TEXT_BK_COLOR);

	m_list_players.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_players.SetTextColor(RGB(0,0,0));
	m_list_players.SetFont(&m_font);


    m_list_players.DeleteColumn(0);
    m_list_players.InsertColumn(0,"year");    
	m_list_players.DeleteColumn(1);
    m_list_players.InsertColumn(1,"po");    
	m_list_players.DeleteColumn(2);
    m_list_players.InsertColumn(2,"name");    
	m_list_players.DeleteColumn(3);
    m_list_players.InsertColumn(3,"team");    
	m_list_players.DeleteColumn(4);
    m_list_players.InsertColumn(4,"");    
  
    m_list_players.SetColumnWidth( 0, 60);
    m_list_players.SetColumnWidth( 1, 30);
    m_list_players.SetColumnWidth( 2, 90);
    m_list_players.SetColumnWidth( 3, 90);
    m_list_players.SetColumnWidth( 4, 60);



	CFileStatus status;

	m_current_exp_count = 0;


	if( CFile::GetStatus( m_path + m_league_name + ".exp", status ) != FALSE) 
	{
	CFile file(	m_path + m_league_name + ".exp", CFile::modeRead);	
	CString buffer;
	char s[33];
	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	m_current_exp_count = atoi(s);

	}

	ReadOriginalNames();


	CheckDlgButton(IDC_RADIO_MVP, 1);

}

void CHistoryAwardsDlg::ListMvp()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{

		if(m_mvp_team_index[i] < 0 || m_mvp[i] < 0) continue;

		long int seek = m_mvp[i]*2500 + 8; 
	
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_mvp_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_mvp[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}

	SetCursor();
	
}

void CHistoryAwardsDlg::List6th()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_6th_team_index[i] < 0 || m_6th[i] < 0) continue;
		long int seek = m_6th[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_6th_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_6th_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_6th[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
	
}

void CHistoryAwardsDlg::ListPoMvp()
{

CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_po_mvp_team_index[i] < 0 || m_po_mvp[i] < 0) continue;
		long int seek = m_po_mvp[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_po_mvp_team_index[i]][exp_co];
		//CString team;
    
    if(name == "") continue;
	m_pointer[n] = m_po_mvp[i];
	m_names_list[n] = name;
	n = n + 1;

	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);



}
	SetCursor();
	
}

void CHistoryAwardsDlg::ReadAwards()
{
 CFile file(	m_file_name + ".awa", CFile::modeRead);	
	long size = (long)file.GetLength();
	long tmp = size / 1000;
	int lines = (int)tmp - 16;
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 5);
	s[bytes] = 0; 
	int start_yr = atoi(s);
 	

    for(int i=0; i< lines; i++)
	{


	int aw_seek = 1000 + i*1000;//starts at index 1000 for history (996 bytes unused)
	file.Seek( aw_seek, CFile::begin);

 	int bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_mvp[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_mvp_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_6th[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_6th_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_defense[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_defense_team_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_rookie[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_rookie_team_index[i] = atoi(s);
    if(m_rookie_team_index[i] < 0) m_rookie_team_index[i] = 0;


 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_pts[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_pts_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_pts_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_reb[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_reb_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_reb_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_ast[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_ast_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_ast_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_stl[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_stl_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_stl_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_blk[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_blk_team_index[i] = atoi(s);

 	bytes = file.Read(s, 4);
	s[bytes] = 0; 
    m_blk_avg[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_po_mvp[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_po_mvp_team_index[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_champ[i] = atoi(s);


 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_allstar[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_allstar_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_rookiestar[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_rookiestar_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_3contest[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_3contest_index[i] = atoi(s);

 	bytes = file.Read(s, 6);
	s[bytes] = 0; 
    m_dunkcontest[i] = atoi(s);

 	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    m_dunkcontest_index[i] = atoi(s);





	aw_seek = 1000 + i*1000 + 995;
 	file.Seek( aw_seek, CFile::begin);

 		
	bytes = file.Read(s, 3);
	s[bytes] = 0; 
    CString check = CString(s);
	bytes = file.Read(s, 2);
	s[bytes] = 0; 
    if(check == "clr") 
		m_exp_count[i] = atoi(s);
	else
		m_exp_count[i] = 0;

	if(m_exp_count[i] > m_current_exp_count) m_exp_count[i] = m_current_exp_count;

	}

	m_lines = lines;
    m_start_year = start_yr;	
}

void CHistoryAwardsDlg::OnRadioDefense() 
{
	// TODO: Add your control notification handler code here
    ListDefense();	
} 

void CHistoryAwardsDlg::ListDefense()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_defense_team_index[i] < 0 || m_defense[i] < 0) continue;
		long int seek = m_defense[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_defense_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_defense_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_defense[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListRookie()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_rookie_team_index[i] < 0 || m_rookie[i] < 0) continue;
		long int seek = m_rookie[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_rookie_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_rookie_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_rookie[i];
	m_names_list[n] = name;

	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListPts()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_pts_team_index[i] < 0 || m_pts[i] < 0) continue;
		long int seek = m_pts[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_pts_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_pts_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_pts[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

	CString av;
	double f = (double)m_pts_avg[i] / 100;
	av.Format("%.2f", f);
    m_list_players.SetItemText(n-1,4,av);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListReb()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_reb_team_index[i] < 0 || m_reb[i] < 0) continue;
		long int seek = m_reb[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_reb_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_reb_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_reb[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

	CString av;
	double f = (double)m_reb_avg[i] / 100;
	av.Format("%.2f", f);
    m_list_players.SetItemText(n-1,4,av);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListAst()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_ast_team_index[i] < 0 || m_ast[i] < 0) continue;
		long int seek = m_ast[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_ast_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_ast_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_ast[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

	CString av;
	double f = (double)m_ast_avg[i] / 100;
	av.Format("%.2f", f);
    m_list_players.SetItemText(n-1,4,av);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListStl()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_stl_team_index[i] < 0 || m_stl[i] < 0) continue;
		long int seek = m_stl[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_stl_team_index[i]];
    		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_stl_team_index[i]][exp_co];

    if(name == "") continue;
	m_pointer[n] = m_stl[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

	CString av;
	double f = (double)m_stl_avg[i] / 100;
	av.Format("%.2f", f);
    m_list_players.SetItemText(n-1,4,av);

}
	SetCursor();
}

void CHistoryAwardsDlg::ListBlk()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_blk_team_index[i] < 0 || m_blk[i] < 0) continue;
		long int seek = m_blk[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

		//CString team = m_league_team_names[m_blk_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_blk_team_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_blk[i];
	m_names_list[n] = name;
	n = n + 1;
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

	CString av;
	double f = (double)m_blk_avg[i] / 100;
	av.Format("%.2f", f);
    m_list_players.SetItemText(n-1,4,av);

}
	SetCursor();
}


void CHistoryAwardsDlg::ListChampion()
{

CString team;

m_list_players.DeleteAllItems();
int n=0;


for(int i=0; i < m_lines; i++)
{
	if(m_champ[i] <= 0) team = "";
	else
	{
		//team = m_league_team_names[m_champ[i] - 1];
		int exp_co = m_exp_count[i];
		team = m_original_names[m_champ[i] - 1][exp_co];
	}
	if(team == "") continue;
	n = n + 1;
    CString yr;
	yr.Format("%d", m_start_year + i);

    
	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,"");
    m_list_players.SetItemText(n-1,2,"");
    m_list_players.SetItemText(n-1,3,team);


}

	SetCursor();
}


void CHistoryAwardsDlg::OnRadioRookies() 
{
	// TODO: Add your control notification handler code here
    ListRookie();	
}

void CHistoryAwardsDlg::OnRadioAssists() 
{
	// TODO: Add your control notification handler code here
	ListAst();
}

void CHistoryAwardsDlg::OnRadioBlocks() 
{
	// TODO: Add your control notification handler code here
	ListBlk();
	
}

void CHistoryAwardsDlg::OnRadioPoints() 
{
	// TODO: Add your control notification handler code here
	ListPts();
	
}

void CHistoryAwardsDlg::OnRadioRebounds() 
{
	// TODO: Add your control notification handler code here
	ListReb();
	
}

void CHistoryAwardsDlg::OnRadioSteals() 
{
	// TODO: Add your control notification handler code here
	ListStl();
	
}

void CHistoryAwardsDlg::OnRadioPlayoff() 
{
	// TODO: Add your control notification handler code here
	ListPoMvp();
	
}

void CHistoryAwardsDlg::OnRadio6th() 
{
	// TODO: Add your control notification handler code here
	List6th();
}

void CHistoryAwardsDlg::OnRadioChampion() 
{
	// TODO: Add your control notification handler code here
	ListChampion();
	
}

void CHistoryAwardsDlg::OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

int i = m_list_players.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
int items = m_list_players.GetItemCount();
	if(i>=0)
	{
		CString m_fileName = m_path + m_league_name;
		CCareerStatsCardDlg* card = new CCareerStatsCardDlg;
		int last = 0;
		for(int j=0; j<=items-1; j++)
		{
			card->m_pointer[j] = m_pointer[j];	
			card->m_names_list[j] = m_names_list[j];
			if(m_pointer[j] > 0) last = j;
		}
		card->m_leagueName = m_fileName;
		card->m_player_index = i;
		card->m_pl_index_start = 0;
		card->m_pl_index_end = last;
		card->DoModal();
		delete card;
	}

	*pResult = 0;

}

void CHistoryAwardsDlg::SetCursor()
{
	int count = m_list_players.GetItemCount() - 1;
if(count >= 0)
{
	m_list_players.SetItemState(count,LVIS_SELECTED,LVIS_SELECTED);
	m_list_players.SetItemState(count,LVIS_FOCUSED,LVIS_FOCUSED);
	m_list_players.EnsureVisible(count, TRUE);
}
}

void CHistoryAwardsDlg::ReadOriginalNames()
{
	for(int i=0; i<=32; i++)
	{
		m_original_names[i][m_current_exp_count] = m_league_team_names[i];
	}

	CString exp_name = m_path + m_league_name + ".exp";



	CFileStatus status;
	if( CFile::GetStatus( exp_name, status ) != FALSE) 
	{


	CFile file(	exp_name, CFile::modeRead);	
	CString buffer;
	char s[33];


	int seek = 0; 
 	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 2);
	s[bytes] = 0; 
	int exp_count = atoi(s);
	if(exp_count > 27) exp_count = 28;

	for(int t=1; t <= exp_count; t++)
	{
 	
	seek = 1100*t;//starts at index 1100 for expansion list team names
	file.Seek( seek, CFile::begin);

	for(int i=0; i<=32; i++)
	{
 		int bytes = file.Read(s, 32);
		s[bytes] = 0; 
		m_original_names[i][t-1] = CString(s);
	}

	}

	}
}

void CHistoryAwardsDlg::OnRadioAllstar() 
{
	// TODO: Add your control notification handler code here
	ListAllstarMVP();
	
}

void CHistoryAwardsDlg::OnRadioRookiestar() 
{
	// TODO: Add your control notification handler code here
	ListRookiestarMVP();
	
}

void CHistoryAwardsDlg::OnRadioThree() 
{
	// TODO: Add your control notification handler code here
	ListThreecontest();
	
}

void CHistoryAwardsDlg::OnRadioDunk() 
{
	// TODO: Add your control notification handler code here
	Listdunkcontest();
	
}

void CHistoryAwardsDlg::ListAllstarMVP()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{


		if(m_allstar[i] < 0 || m_allstar_index[i] < 0) continue;

	long int seek = m_allstar[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_allstar_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_allstar[i];
	m_names_list[n] = name;
	n = n + 1;

	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
	
}

void CHistoryAwardsDlg::ListRookiestarMVP()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_rookiestar[i] < 0 || m_rookiestar_index[i] < 0) continue;
	long int seek = m_rookiestar[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_rookiestar_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_rookiestar[i];
	m_names_list[n] = name;
	n = n + 1;

	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
	

}

void CHistoryAwardsDlg::ListThreecontest()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_3contest[i] < 0 || m_3contest_index[i] < 0) continue;
	long int seek = m_3contest[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_3contest_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_3contest[i];
	m_names_list[n] = name;
	n = n + 1;

	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);

}
	SetCursor();
	

}

void CHistoryAwardsDlg::Listdunkcontest()
{
CString buffer;
CString file_name = m_file_name + ".car";
CFile file(	file_name, CFile::modeRead);	


char s[17];
int n=0;
m_list_players.DeleteAllItems();

for(int i=0; i < m_lines; i++)
{
		if(m_dunkcontest_index[i] < 0 || m_dunkcontest[i] < 0) continue;
	long int seek = m_dunkcontest[i]*2500 + 8; 
		file.Seek( seek, CFile::begin);
		int bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();
		
		file.Seek(seek + 52, CFile::begin);

		bytes = file.Read(s, 2);
		s[bytes] = 0;
		CString pos = CString(s);
		pos.TrimRight();


        CString yr;
		yr.Format("%d", m_start_year + i);

//		CString team = m_league_team_names[m_po_mvp_team_index[i]];
		int exp_co = m_exp_count[i];
		CString team = m_original_names[m_dunkcontest_index[i]][exp_co];
    
    if(name == "") continue;
	m_pointer[n] = m_dunkcontest[i];
	m_names_list[n] = name;

	m_list_players.InsertItem(n-1, yr);
	m_list_players.SetItemText(n-1,1,pos);
    m_list_players.SetItemText(n-1,2,name);
    m_list_players.SetItemText(n-1,3,team);
	n = n + 1;

}
	SetCursor();
	

}

BOOL CHistoryAwardsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyawards.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

	
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CHistoryAwardsDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/historyawards.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

HBRUSH CHistoryAwardsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
