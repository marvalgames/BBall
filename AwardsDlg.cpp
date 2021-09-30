// AwardsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "AwardsDlg.h"
#include "PlayerCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAwardsDlg dialog


CAwardsDlg::CAwardsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAwardsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAwardsDlg)
	//}}AFX_DATA_INIT
}


void CAwardsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAwardsDlg)
	DDX_Control(pDX, IDC_LIST_ALL_ROOKIE, m_list_all_rookie);
	DDX_Control(pDX, IDC_LIST_ALL_LEAGUE, m_list_all_league);
	DDX_Control(pDX, IDC_LIST_ALL_DEFENSE, m_list_all_defense);
	DDX_Control(pDX, IDC_LIST_6TH, m_list_6th);
	DDX_Control(pDX, IDC_LIST_LEADERS, m_list_leaders);
	DDX_Control(pDX, IDC_LIST_ROOKIES, m_list_rookie);
	DDX_Control(pDX, IDC_LIST_DEFENSE, m_list_defense);
	DDX_Control(pDX, IDC_LIST_MVP, m_list_mvp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAwardsDlg, CDialog)
	//{{AFX_MSG_MAP(CAwardsDlg)
	ON_BN_CLICKED(IDC_RADIO_POINTS, OnRadioPoints)
	ON_BN_CLICKED(IDC_RADIO_REBOUNDS, OnRadioRebounds)
	ON_BN_CLICKED(IDC_RADIO_BLOCKS, OnRadioBlocks)
	ON_BN_CLICKED(IDC_RADIO_ASSISTS, OnRadioAssists)
	ON_BN_CLICKED(IDC_RADIO_STEALS, OnRadioSteals)
	ON_BN_CLICKED(IDC_RADIO_MVP, OnRadioMvp)
	ON_BN_CLICKED(IDC_RADIO_PLAYOFF, OnRadioPlayoff)
	ON_BN_CLICKED(IDC_RADIO_ALL_LEAGUE_1, OnRadioAllLeague1)
	ON_BN_CLICKED(IDC_RADIO_ALL_LEAGUE_2, OnRadioAllLeague2)
	ON_BN_CLICKED(IDC_RADIO_ALL_LEAGUE_3, OnRadioAllLeague3)
	ON_BN_CLICKED(IDC_RADIO_ALL_DEFENSE_1, OnRadioAllDefense1)
	ON_BN_CLICKED(IDC_RADIO_ALL_DEFENSE_2, OnRadioAllDefense2)
	ON_BN_CLICKED(IDC_RADIO_ALL_DEFENSE_3, OnRadioAllDefense3)
	ON_BN_CLICKED(IDC_RADIO_ALL_ROOKIE_7, OnRadioAllRookie7)
	ON_BN_CLICKED(IDC_RADIO_ALL_ROOKIE_8, OnRadioAllRookie8)
	ON_BN_CLICKED(IDC_RADIO_ALL_ROOKIE_9, OnRadioAllRookie9)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_6TH, OnDblclkList6th)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ALL_DEFENSE, OnDblclkListAllDefense)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ALL_LEAGUE, OnDblclkListAllLeague)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ALL_ROOKIE, OnDblclkListAllRookie)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DEFENSE, OnDblclkListDefense)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_LEADERS, OnDblclkListLeaders)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_MVP, OnDblclkListMvp)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ROOKIES, OnDblclkListRookies)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ALL_ROOKIE, &CAwardsDlg::OnLvnItemchangedListAllRookie)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAwardsDlg message handlers

BOOL CAwardsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR); 
	InitControls();
	ListMvp();
	List6th();
	ListDefense();
	ListRookie();
	ListLeaders();
	ListAllLeague();
	ListAllDefense();
	ListAllRookie();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAwardsDlg::InitControls()
{

	for(int i=0; i<=10; i++)
	{
	m_defense_pointer[i] = 0;
	m_mvp_pointer[i] = 0;
	m_rookie_pointer[i] = 0;
	m_6th_pointer[i]= 0;
	m_leaders_pointer[i] = 0;
	m_all_league_pointer[i] = 0;
	m_all_defense_pointer[i] = 0;
	m_all_rookie_pointer[i] = 0;
	}

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_6th.SetBkColor(BK_COLOR);
	m_list_6th.SetTextBkColor(TEXT_BK_COLOR);

	m_list_6th.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_6th.SetTextColor(RGB(0,0,0));
	m_list_6th.SetFont(&m_font);

	m_list_all_defense.SetBkColor(BK_COLOR);
	m_list_all_defense.SetTextBkColor(TEXT_BK_COLOR);

	m_list_all_defense.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_all_defense.SetTextColor(RGB(0,0,0));
	m_list_all_defense.SetFont(&m_font);

	m_list_all_league.SetBkColor(BK_COLOR);
	m_list_all_league.SetTextBkColor(TEXT_BK_COLOR);

	m_list_all_league.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_all_league.SetTextColor(RGB(0,0,0));
	m_list_all_league.SetFont(&m_font);

	m_list_all_rookie.SetBkColor(BK_COLOR);
	m_list_all_rookie.SetTextBkColor(TEXT_BK_COLOR);

	m_list_all_rookie.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_all_rookie.SetTextColor(RGB(0,0,0));
	m_list_all_rookie.SetFont(&m_font);

	m_list_defense.SetBkColor(BK_COLOR);
	m_list_defense.SetTextBkColor(TEXT_BK_COLOR);

	m_list_defense.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_defense.SetTextColor(RGB(0,0,0));
	m_list_defense.SetFont(&m_font);

	m_list_leaders.SetBkColor(BK_COLOR);
	m_list_leaders.SetTextBkColor(TEXT_BK_COLOR);

	m_list_leaders.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_leaders.SetTextColor(RGB(0,0,0));
	m_list_leaders.SetFont(&m_font);

	m_list_mvp.SetBkColor(BK_COLOR);
	m_list_mvp.SetTextBkColor(TEXT_BK_COLOR);

	m_list_mvp.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_mvp.SetTextColor(RGB(0,0,0));
	m_list_mvp.SetFont(&m_font);

	m_list_rookie.SetBkColor(BK_COLOR);
	m_list_rookie.SetTextBkColor(TEXT_BK_COLOR);

	m_list_rookie.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_rookie.SetTextColor(RGB(0,0,0));
	m_list_rookie.SetFont(&m_font);



	m_list_6th.DeleteColumn(0);
    m_list_6th.InsertColumn(0,"po");    
	m_list_6th.DeleteColumn(1);
    m_list_6th.InsertColumn(1,"6th man");    
	m_list_6th.DeleteColumn(2);
    m_list_6th.InsertColumn(2,"team");    
    m_list_6th.SetColumnWidth( 0, 30);
    m_list_6th.SetColumnWidth( 1, 120);
    m_list_6th.SetColumnWidth( 2, 90);

	m_list_mvp.DeleteColumn(0);
    m_list_mvp.InsertColumn(0,"po");    
	m_list_mvp.DeleteColumn(1);
    m_list_mvp.InsertColumn(1,"most valuable player");    
	m_list_mvp.DeleteColumn(2);
    m_list_mvp.InsertColumn(2,"team");    
    m_list_mvp.SetColumnWidth( 0, 30);
    m_list_mvp.SetColumnWidth( 1, 120);
    m_list_mvp.SetColumnWidth( 2, 90);

	m_list_defense.DeleteColumn(0);
    m_list_defense.InsertColumn(0,"po");    
	m_list_defense.DeleteColumn(1);
    m_list_defense.InsertColumn(1,"defensive player");    
	m_list_defense.DeleteColumn(2);
    m_list_defense.InsertColumn(2,"team");    
    m_list_defense.SetColumnWidth( 0, 30);
    m_list_defense.SetColumnWidth( 1, 120);
    m_list_defense.SetColumnWidth( 2, 90);

	m_list_rookie.DeleteColumn(0);
    m_list_rookie.InsertColumn(0,"po");    
	m_list_rookie.DeleteColumn(1);
    m_list_rookie.InsertColumn(1,"rookie of the year");    
	m_list_rookie.DeleteColumn(2);
    m_list_rookie.InsertColumn(2,"team");    
    m_list_rookie.SetColumnWidth( 0, 30);
    m_list_rookie.SetColumnWidth( 1, 120);
    m_list_rookie.SetColumnWidth( 2, 90);

	m_list_all_league.DeleteColumn(0);
    m_list_all_league.InsertColumn(0,"po");    
	m_list_all_league.DeleteColumn(1);
    m_list_all_league.InsertColumn(1,"all league");    
	m_list_all_league.DeleteColumn(2);
    m_list_all_league.InsertColumn(2,"team");    
    m_list_all_league.SetColumnWidth( 0, 30);
    m_list_all_league.SetColumnWidth( 1, 120);
    m_list_all_league.SetColumnWidth( 2, 90);

	m_list_all_defense.DeleteColumn(0);
    m_list_all_defense.InsertColumn(0,"po");    
	m_list_all_defense.DeleteColumn(1);
    m_list_all_defense.InsertColumn(1,"all defense");    
	m_list_all_defense.DeleteColumn(2);
    m_list_all_defense.InsertColumn(2,"team");    
    m_list_all_defense.SetColumnWidth( 0, 30);
    m_list_all_defense.SetColumnWidth( 1, 120);
    m_list_all_defense.SetColumnWidth( 2, 90);

	m_list_all_rookie.DeleteColumn(0);
    m_list_all_rookie.InsertColumn(0,"po");    
	m_list_all_rookie.DeleteColumn(1);
    m_list_all_rookie.InsertColumn(1,"all rookie");    
	m_list_all_rookie.DeleteColumn(2);
    m_list_all_rookie.InsertColumn(2,"team");    
    m_list_all_rookie.SetColumnWidth( 0, 30);
    m_list_all_rookie.SetColumnWidth( 1, 120);
    m_list_all_rookie.SetColumnWidth( 2, 90);

	m_list_leaders.DeleteColumn(0);
    m_list_leaders.InsertColumn(0,"po");    
	m_list_leaders.DeleteColumn(1);
    m_list_leaders.InsertColumn(1,"leader");    
	m_list_leaders.DeleteColumn(2);
    m_list_leaders.InsertColumn(2,"team");    
	m_list_leaders.DeleteColumn(3);
    m_list_leaders.InsertColumn(3,"avg");    
    m_list_leaders.SetColumnWidth( 0, 30);
    m_list_leaders.SetColumnWidth( 1, 90);
    m_list_leaders.SetColumnWidth( 2, 60);
    m_list_leaders.SetColumnWidth( 3, 60);

	CheckDlgButton(IDC_RADIO_POINTS, 1);
	CheckDlgButton(IDC_RADIO_MVP, 1);
	CheckDlgButton(IDC_RADIO_ALL_LEAGUE_1, 1);
	CheckDlgButton(IDC_RADIO_ALL_DEFENSE_1, 1);
	CheckDlgButton(IDC_RADIO_ALL_ROOKIE_7, 1);
	m_category = 1;
	m_mvp_category = 1;
	m_all_league_category = 1;
	m_all_defense_category = 1;
	m_all_rookie_category = 1;

}

void CAwardsDlg::ListMvp()
{

	m_list_mvp.DeleteAllItems();

	int co = 0;

for(int row=1; row<=5; row++)
{

	CPlayer m_player;

	if(m_mvp_category == 1)
	{
		m_player = avg.m_actual[m_mvp[row]];
		m_mvp_pointer[co] = m_mvp[row];
		co = co + 1;
		m_list_mvp.InsertItem(row-1,m_player.m_pos);
		m_list_mvp.SetItemText(row-1,1,m_player.m_name);
		m_list_mvp.SetItemText(row-1,2,m_player.m_team_paying_name);
	}
	else if(row == 1)
	{
		m_player = avg.m_actual[m_po_mvp];
		m_mvp_pointer[co] = m_po_mvp;
		co = co + 1;
		m_list_mvp.InsertItem(row-1,m_player.m_pos);
		m_list_mvp.SetItemText(row-1,1,m_player.m_name);
		m_list_mvp.SetItemText(row-1,2,m_player.m_team_paying_name);
	}

}

}

void CAwardsDlg::ListAllLeague()
{

	m_list_all_league.DeleteAllItems();
	int co = 0;

for(int row=1; row<=5; row++)
{

	CPlayer m_player;

		m_player = avg.m_actual[m_all_league[row][m_all_league_category]];
		m_all_league_pointer[co] = m_all_league[row][m_all_league_category];
		co = co + 1;
		m_list_all_league.InsertItem(row-1,m_player.m_pos);
		m_list_all_league.SetItemText(row-1,1,m_player.m_name);
		m_list_all_league.SetItemText(row-1,2,m_player.m_team_paying_name);

}


}

void CAwardsDlg::ListAllDefense()
{

	m_list_all_defense.DeleteAllItems();
	int co = 0;
for(int row=1; row<=5; row++)
{

	CPlayer m_player;

		m_player = avg.m_actual[m_all_defense[row][m_all_defense_category]];
		m_all_defense_pointer[co] = m_all_defense[row][m_all_defense_category];
		co = co + 1;
		m_list_all_defense.InsertItem(row-1,m_player.m_pos);
		m_list_all_defense.SetItemText(row-1,1,m_player.m_name);
		m_list_all_defense.SetItemText(row-1,2,m_player.m_team_paying_name);

}


}

void CAwardsDlg::ListAllRookie()
{

	m_list_all_rookie.DeleteAllItems();
	int co = 0;

for(int row=1; row<=5; row++)
{

	CPlayer m_player;

		m_player = avg.m_actual[m_all_rookie[row][m_all_rookie_category]];
		m_all_rookie_pointer[co] = m_all_rookie[row][m_all_rookie_category];
		co = co + 1;

		m_list_all_rookie.InsertItem(row-1,m_player.m_pos);
		m_list_all_rookie.SetItemText(row-1,1,m_player.m_name);
		m_list_all_rookie.SetItemText(row-1,2,m_player.m_team_paying_name);

}


}

void CAwardsDlg::List6th()
{

	m_list_6th.DeleteAllItems();
	int co = 0;

for(int row=1; row<=5; row++)
{

		CPlayer m_player = avg.m_actual[m_6th[row]];
		m_6th_pointer[co] = m_6th[row];
		co = co + 1;
		m_list_6th.InsertItem(row-1,m_player.m_pos);
		m_list_6th.SetItemText(row-1,1,m_player.m_name);
		m_list_6th.SetItemText(row-1,2,m_player.m_team_paying_name);

}


}

void CAwardsDlg::ListDefense()
{

	int co = 0;
for(int row=1; row<=5; row++)
{

    CPlayer m_player = avg.m_actual[m_defense[row]];
		m_defense_pointer[co] = m_defense[row];
		co = co + 1;
	m_list_defense.InsertItem(row-1,m_player.m_pos);
	m_list_defense.SetItemText(row-1,1,m_player.m_name);
    m_list_defense.SetItemText(row-1,2,m_player.m_team_paying_name);
}

}

void CAwardsDlg::ListRookie()
{

	int co = 0;
for(int row=1; row<=5; row++)
{

    CPlayer m_player = avg.m_actual[m_rookie[row]];
		m_rookie_pointer[co] = m_rookie[row];
		co = co + 1;

	m_list_rookie.InsertItem(row-1,m_player.m_pos);
	m_list_rookie.SetItemText(row-1,1,m_player.m_name);
    m_list_rookie.SetItemText(row-1,2,m_player.m_team_paying_name);
}

}

void CAwardsDlg::ListLeaders()
{

	m_list_leaders.DeleteAllItems();
	int co = 0;
for(int row=1; row<=5; row++)
{

	CPlayer m_player;
	if(m_category == 1)
	{
		m_player = avg.m_actual[m_pts[row]];
		m_leaders_pointer[co] = m_pts[row];
		co = co + 1;
		m_list_leaders.InsertItem(row-1,m_player.m_pos);
		m_list_leaders.SetItemText(row-1,1,m_player.m_name);
		m_list_leaders.SetItemText(row-1,2,m_player.m_team_paying_name);
		CString av;

		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);
		double f = (double)m_player.m_sim_pointsPerGame;
		av.Format("%.2f", f);
		m_list_leaders.SetItemText(row-1,3,av);
	}
	else if(m_category == 2)
	{
		m_player = avg.m_actual[m_reb[row]];
		m_leaders_pointer[co] = m_reb[row];
		co = co + 1;

		m_list_leaders.InsertItem(row-1,m_player.m_pos);
		m_list_leaders.SetItemText(row-1,1,m_player.m_name);
		m_list_leaders.SetItemText(row-1,2,m_player.m_team_paying_name);
		CString av;
//		double f = (double)m_reb[row] / 100;
		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		double f = (double)m_player.m_sim_reboundsPerGame;
		av.Format("%.2f", f);
		m_list_leaders.SetItemText(row-1,3,av);
	}
	else if(m_category == 3)
	{
		m_player = avg.m_actual[m_ast[row]];
		m_leaders_pointer[co] = m_ast[row];
		co = co + 1;

		m_list_leaders.InsertItem(row-1,m_player.m_pos);
		m_list_leaders.SetItemText(row-1,1,m_player.m_name);
		m_list_leaders.SetItemText(row-1,2,m_player.m_team_paying_name);
		CString av;
//		double f = (double)m_ast[row] / 100;
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		double f = (double)m_player.m_sim_assistsPerGame;

		av.Format("%.2f", f);
		m_list_leaders.SetItemText(row-1,3,av);

	}
	else if(m_category == 4)
	{
		m_player = avg.m_actual[m_stl[row]];
		m_leaders_pointer[co] = m_stl[row];
		co = co + 1;
		m_list_leaders.InsertItem(row-1,m_player.m_pos);
		m_list_leaders.SetItemText(row-1,1,m_player.m_name);
		m_list_leaders.SetItemText(row-1,2,m_player.m_team_paying_name);
		CString av;
//		double f = (double)m_stl[row] / 100;
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		double f = (double)m_player.m_sim_stealsPerGame;

		av.Format("%.2f", f);
		m_list_leaders.SetItemText(row-1,3,av);

	}
	else if(m_category == 5)
	{
		m_player = avg.m_actual[m_blk[row]];
		m_leaders_pointer[co] = m_blk[row];
		co = co + 1;
		m_list_leaders.InsertItem(row-1,m_player.m_pos);
		m_list_leaders.SetItemText(row-1,1,m_player.m_name);
		m_list_leaders.SetItemText(row-1,2,m_player.m_team_paying_name);
		CString av;
//		double f = (double)m_blk[row] / 100;
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		double f = (double)m_player.m_sim_blocksPerGame;
		av.Format("%.2f", f);
		m_list_leaders.SetItemText(row-1,3,av);

	}
}

}

void CAwardsDlg::OnRadioPoints() 
{
	// TODO: Add your control notification handler code here
	m_category = 1;
	ListLeaders();
	
}

void CAwardsDlg::OnRadioRebounds() 
{
	// TODO: Add your control notification handler code here
	m_category = 2;
	ListLeaders();
	
}

void CAwardsDlg::OnRadioBlocks() 
{
	// TODO: Add your control notification handler code here
	m_category = 5;
	ListLeaders();
	
}

void CAwardsDlg::OnRadioAssists() 
{
	// TODO: Add your control notification handler code here
	m_category = 3;
	ListLeaders();
	
}

void CAwardsDlg::OnRadioSteals() 
{
	// TODO: Add your control notification handler code here
	m_category = 4;
	ListLeaders();
	
}

void CAwardsDlg::OnRadioMvp() 
{
	// TODO: Add your control notification handler code here
	m_mvp_category = 1;
	ListMvp();
	
}

void CAwardsDlg::OnRadioPlayoff() 
{
	// TODO: Add your control notification handler code here
	m_mvp_category = 2;
	ListMvp();
	
}

void CAwardsDlg::OnRadioAllLeague1() 
{
	// TODO: Add your control notification handler code here
	m_all_league_category = 1;
	ListAllLeague();
	
}

void CAwardsDlg::OnRadioAllLeague2() 
{
	// TODO: Add your control notification handler code here
	m_all_league_category = 2;
	ListAllLeague();
	
}

void CAwardsDlg::OnRadioAllLeague3() 
{
	// TODO: Add your control notification handler code here
	m_all_league_category = 3;
	ListAllLeague();
	
}

void CAwardsDlg::OnRadioAllDefense1() 
{
	// TODO: Add your control notification handler code here
	m_all_defense_category = 1;
	ListAllDefense();
	
}

void CAwardsDlg::OnRadioAllDefense2() 
{
	// TODO: Add your control notification handler code here
	m_all_defense_category = 2;
	ListAllDefense();
	
}

void CAwardsDlg::OnRadioAllDefense3() 
{
	// TODO: Add your control notification handler code here
	m_all_defense_category = 3;
	ListAllDefense();
	
}

void CAwardsDlg::OnRadioAllRookie7() 
{
	// TODO: Add your control notification handler code here
	m_all_rookie_category = 1;
	ListAllRookie();
	
}

void CAwardsDlg::OnRadioAllRookie8() 
{
	// TODO: Add your control notification handler code here
	m_all_rookie_category = 2;
	ListAllRookie();
	
}

void CAwardsDlg::OnRadioAllRookie9() 
{
	// TODO: Add your control notification handler code here
	m_all_rookie_category = 3;
	ListAllRookie();
	
}

void CAwardsDlg::OnDblclkList6th(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_6th.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_6th_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;
	
}

void CAwardsDlg::OnDblclkListAllDefense(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_all_defense.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_all_defense_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;



}

void CAwardsDlg::OnDblclkListAllLeague(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_all_league.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_all_league_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;

}

void CAwardsDlg::OnDblclkListAllRookie(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_all_rookie.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_all_rookie_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;





}

void CAwardsDlg::OnDblclkListDefense(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_defense.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_defense_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;


}

void CAwardsDlg::OnDblclkListLeaders(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_leaders.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_leaders_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	







	*pResult = 0;
}

void CAwardsDlg::OnDblclkListMvp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_mvp.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_mvp_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}

	*pResult = 0;

	
}

void CAwardsDlg::OnDblclkListRookies(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_list_rookie.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	if(i > 0)
	{

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = 0;

	scout->m_path = m_path;
	scout->m_leagueName = m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=4; c++)
	{
		int pointer = m_rookie_pointer[c];
		scout->avg.m_actual[c] = avg.m_actual[pointer];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = 4;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;
}

BOOL CAwardsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/seasonawards.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CAwardsDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/seasonawards.htm", HH_DISPLAY_TOPIC, 0);
	
}

HBRUSH CAwardsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
		  myBrush.GetLogBrush(&logbrush);
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
          pDC->SetTextColor(WHITE);
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
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}


void CAwardsDlg::OnLvnItemchangedListAllRookie(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
