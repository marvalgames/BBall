// SearchDlg.cpp : implementation file
//

#include "stdafx.h"
//#include "constants.h"
//#include "resource.h"

#include "bball.h"
#include "MyComboBox.h"
#include "SearchDlg.h"
#include "PlayerCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog


CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDlg)
	//}}AFX_DATA_INIT
	m_count = 0;
	for(int i=0; i<=1600; i++)
	{
		m_pointers[i] = 0;
	}
}


void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDlg)
	DDX_Control(pDX, IDC_COMBO182, m_combo_oo);
	DDX_Control(pDX, IDC_COMBO183, m_combo_do);
	DDX_Control(pDX, IDC_COMBO184, m_combo_poo);
	DDX_Control(pDX, IDC_COMBO185, m_combo_tro);
	DDX_Control(pDX, IDC_COMBO186, m_combo_od);
	DDX_Control(pDX, IDC_COMBO187, m_combo_dd);
	DDX_Control(pDX, IDC_COMBO188, m_combo_pd);
	DDX_Control(pDX, IDC_COMBO189, m_combo_td);
	DDX_Control(pDX, IDC_COMBO181, m_combo_fayrs);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDC_COMBO90, m_combo_age);
	DDX_Control(pDX, IDC_COMBO20, m_combo_ppg);
	DDX_Control(pDX, IDC_COMBO19, m_combo_blkpg);
	DDX_Control(pDX, IDC_COMBO18, m_combo_stlpg);
	DDX_Control(pDX, IDC_COMBO17, m_combo_astpg);
	DDX_Control(pDX, IDC_COMBO16, m_combo_rpg);
	DDX_Control(pDX, IDC_COMBO89, m_combo_ftppg);
	DDX_Control(pDX, IDC_COMBO88, m_combo_tgppg);
	DDX_Control(pDX, IDC_COMBO87, m_combo_fgppg);
	DDX_Control(pDX, IDC_COMBO86, m_combo_mpg);
	DDX_Control(pDX, IDC_COMBO85, m_combo_teams);
	DDX_Control(pDX, IDC_COMBO15, m_combo_pos);
	DDX_Control(pDX, IDC_COMBO14, m_combo_blk);
	DDX_Control(pDX, IDC_COMBO13, m_combo_to);
	DDX_Control(pDX, IDC_COMBO12, m_combo_stl);
	DDX_Control(pDX, IDC_COMBO11, m_combo_ast);
	DDX_Control(pDX, IDC_COMBO10, m_combo_drb);
	DDX_Control(pDX, IDC_COMBO9, m_combo_orb);
	DDX_Control(pDX, IDC_COMBO8, m_combo_ftp);
	DDX_Control(pDX, IDC_COMBO7, m_combo_fta);
	DDX_Control(pDX, IDC_COMBO6, m_combo_tgp);
	DDX_Control(pDX, IDC_COMBO5, m_combo_tga);
	DDX_Control(pDX, IDC_COMBO4, m_combo_fgp);
	DDX_Control(pDX, IDC_LIST_PLAYERS, m_list_players);
	DDX_Control(pDX, IDC_BUTTON_FIND, m_button_find);
	DDX_Control(pDX, IDC_COMBO2, m_combo_max_sal);
	DDX_Control(pDX, IDC_COMBO1, m_combo_min_sal);
	DDX_Control(pDX, IDC_COMBO3, m_combo_fga);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnButtonFind)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PLAYERS, OnDblclkListPlayers)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_PLAYERS, OnColumnclickListPlayers)
	ON_NOTIFY(NM_CLICK, IDC_LIST_PLAYERS, OnClickListPlayers)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg message handlers

BOOL CSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR);
	SetScoutRatings();
	InitControls();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CSearchDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	
//	HtmlHelp(NULL, "jumpshot.chm::/html/search.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CSearchDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/search.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

HBRUSH CSearchDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CSearchDlg::OnButtonFind() 
{
	// TODO: Add your control notification handler code here
		int min_sal_index = m_combo_min_sal.GetCurSel();
		int max_sal_index = m_combo_max_sal.GetCurSel();
		int fga_index = m_combo_fga.GetCurSel();
		int fgp_index = m_combo_fgp.GetCurSel();
		int tga_index = m_combo_tga.GetCurSel();
		int tgp_index = m_combo_tgp.GetCurSel();
		int fta_index = m_combo_fta.GetCurSel();
		int ftp_index = m_combo_ftp.GetCurSel();
		int orb_index = m_combo_orb.GetCurSel();
		int drb_index = m_combo_drb.GetCurSel();
		int ast_index = m_combo_ast.GetCurSel();
		int stl_index = m_combo_stl.GetCurSel();
		int  to_index = m_combo_to.GetCurSel();
		int blk_index = m_combo_blk.GetCurSel();
		int team_index = m_combo_teams.GetCurSel();
		int po_index = m_combo_pos.GetCurSel();
		int age_index = m_combo_age.GetCurSel();

		int mpg_index = m_combo_mpg.GetCurSel();
		int fgppg_index = m_combo_fgppg.GetCurSel();
		int tgppg_index = m_combo_tgppg.GetCurSel();
		int ftppg_index = m_combo_ftppg.GetCurSel();
		int rebpg_index = m_combo_rpg.GetCurSel();
		int astpg_index = m_combo_astpg.GetCurSel();
		int stlpg_index = m_combo_stlpg.GetCurSel();
		int blkpg_index = m_combo_blkpg.GetCurSel();
		int ppg_index = m_combo_ppg.GetCurSel();
		int fayrs_index = m_combo_fayrs.GetCurSel();

		m_search_oo = m_combo_oo.GetCurSel() + 1;
		m_search_do = m_combo_do.GetCurSel() + 1;
		m_search_poo = m_combo_poo.GetCurSel() + 1;
		m_search_tro = m_combo_tro.GetCurSel() + 1;

		m_search_od = m_combo_od.GetCurSel() + 1;
		m_search_dd = m_combo_dd.GetCurSel() + 1;
		m_search_pd = m_combo_pd.GetCurSel() + 1;
		m_search_td = m_combo_td.GetCurSel() + 1;


		
		m_min_sal = min_sal_index*100;
		m_max_sal = max_sal_index*100;
		if(m_min_sal >= m_max_sal)
		{
			int temp = m_max_sal;
			m_max_sal = m_min_sal;
			m_min_sal = temp;
		}


		m_search_fayrs = fayrs_index - 1;


		m_search_fga = fga_index * 10;		
		m_search_fgp = 25 + fgp_index * 5;		
		if(fgp_index == 0) m_search_fgp = 0;
		m_search_tga = tga_index * 10;		
		m_search_tgp = tgp_index * 5;		
		m_search_fta = fta_index * 10;		
		m_search_ftp = 45 + ftp_index * 5;	
		if(ftp_index == 0) m_search_ftp = 0;		

		m_search_orb = orb_index * 10;		
		m_search_drb = drb_index * 10;		
		m_search_ast = ast_index * 10;		
		m_search_stl = stl_index * 10;		
		m_search_to  =  to_index * 10;		
		m_search_blk = blk_index * 10;		

		m_search_age = 18 + (age_index*2);
		if(age_index == 0) m_search_age = 99;
		m_search_mpg = mpg_index*4;
		m_search_fgppg = 25 + fgppg_index * 5;		
		if(fgppg_index == 0) m_search_fgppg = 0;
		m_search_tgppg = tgppg_index * 5;		
		m_search_ftppg = 45 + ftppg_index * 5;	
		if(ftppg_index == 0) m_search_ftppg = 0;		
		m_search_rebpg = rebpg_index*1;
		m_search_astpg = astpg_index*1;
		m_search_stlpg = stlpg_index*.5;
		m_search_blkpg = blkpg_index*.5;
		m_search_ppg = ppg_index*3;

		m_search_team = m_league_name;
		if(team_index > 0) m_search_team = m_league_team_names[team_index-1];

		m_search_po = "any";
		if(po_index == 1) m_search_po = "PG";
		else if(po_index == 2) m_search_po = "SG";
		else if(po_index == 3) m_search_po = "SF";
		else if(po_index == 4) m_search_po = "PF";
		else if(po_index == 5) m_search_po = " C";

		m_column = 99;
		QuickSort();		
		ListPlayers();
	
}

void CSearchDlg::ListPlayers()
{
	m_list_players.DeleteAllItems();
	int co = 0;
	if(m_min_sal == 0) m_min_sal = -1;

	for(int  index = 0; index <= 1600; index++)
	{
		m_pointer[index] = 0;
		m_pointers[index] = 0;
	}
	for(int index = 0; index <= 1600; index++)
	{

		int i = index;
		CPlayer m_player = avg.m_actual[i];
		CString Stats[33];
		CString Name = m_player.GetName();
		int salary = m_player.m_current_yr_salary;
		bool valid = false;

		int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

		if(avg.m_settings.m_current_stage == 0 && yrs_left == 1 && salary == 0) yrs_left = 0;

		if(m_search_fayrs == -1) yrs_left = -1;

		if(salary > m_min_sal && salary <= m_max_sal && Name != "" && m_player.m_pos != ""
			&& m_player.m_adjPrFga >= m_search_fga
			&& m_player.m_adjPrFgp >= m_search_fgp
			&& m_player.m_adjPrTga >= m_search_tga
			&& m_player.m_adjPrTgp >= m_search_tgp
			&& m_player.m_adjPrFta >= m_search_fta
			&& m_player.m_adjPrFtp >= m_search_ftp
			&& m_player.m_adjPrOrb >= m_search_orb
			&& m_player.m_adjPrDrb >= m_search_drb
			&& m_player.m_adjPrAst >= m_search_ast
			&& m_player.m_adjPrStl >= m_search_stl
			&& m_player.m_adjPrTo >= m_search_to 
			&& m_player.m_adjPrBlk >= m_search_blk
			&&	((m_search_po == "any"  && m_player.GetPos() != "  ") ||
			(m_search_po == "PG" && m_player.GetPos() == "PG") ||
			(m_search_po == "SG" && m_player.GetPos() == "SG") ||
			(m_search_po == "SF" && m_player.GetPos() == "SF") ||
			(m_search_po == "PF" && m_player.GetPos() == "PF") ||
			(m_search_po == " C" && m_player.GetPos() == " C"))

	
			
		&&  (m_search_team == m_league_name	|| m_search_team == m_player.m_team)		
			
		&& m_player.m_age <= m_search_age
		&& m_player.m_sim_minPerGame >= m_search_mpg
		&& m_player.m_sim_fgPct >= m_search_fgppg
		&& m_player.m_sim_tfgPct >= m_search_tgppg
		&& m_player.m_sim_ftPct >= m_search_ftppg
		&& m_player.m_sim_reboundsPerGame >= m_search_rebpg
		&& m_player.m_sim_assistsPerGame >= m_search_astpg
		&& m_player.m_sim_stealsPerGame >= m_search_stlpg
		&& m_player.m_sim_blocksPerGame >= m_search_blkpg
		&& m_player.m_sim_pointsPerGame >= m_search_ppg

		&& m_player.m_movoff >= m_search_oo 
		&& m_player.m_penoff >= m_search_do 
		&& m_player.m_postoff >= m_search_poo 
		&& m_player.m_transoff >= m_search_tro 

		&& m_player.m_movdef >= m_search_od 
		&& m_player.m_pendef >= m_search_dd 
		&& m_player.m_postdef >= m_search_pd 
		&& m_player.m_transdef >= m_search_td 




		&& (yrs_left == m_search_fayrs)

			
			) valid = true;
		
		
		
		if(valid == false) continue;
		Stats[0] = m_player.GetPos();
		Stats[1] = Name;
		int te = m_player.m_team_paying-1;
		if(te >= 0)
			Stats[2] = m_league_team_names[m_player.m_team_paying-1];
		Stats[3].Format("%d", m_player.GetAge());
		double r = (double)salary / 100;
		Stats[4].Format("%.2f", r);

		m_list_players.InsertItem(co,Stats[0]);
		for(int s=0; s<=20; s++)
		{
			if(Stats[s+1] == "") continue;
			m_list_players.SetItemText(co,s+1,Stats[s+1]);
		}
		m_pointer[co] = m_player.GetID();
		co = co + 1;
		m_pointers[co] = index;
	}

	if(co == 0)
	{
		m_list_players.InsertItem(0,"");
		m_list_players.SetItemText(0,1,"No Players");
	}

	m_count = co;
}

void CSearchDlg::InitControls()
{

	SetWindowText(m_league_team_names[m_team_index] + " Scout: " + m_scout.m_name);
	m_button_ok.EnableWindow(FALSE);
	m_combo_teams.AddString(m_league_name);
	for(int i=1; i<=32; i++)
	{
		if(m_league_team_names[i-1] != "")
		{
			m_combo_teams.AddString(m_league_team_names[i-1]);
		}
	}

	m_selected_player_id = 0;
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_players.SetBkColor(BK_COLOR);
	m_list_players.SetTextBkColor(BK_COLOR);

	m_list_players.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    m_list_players.SetTextColor(RGB(0,0,0));
	m_list_players.SetFont(&m_font);
	m_list_players.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_players.DeleteAllItems();

	m_list_players.DeleteColumn(0);
    m_list_players.InsertColumn(0,"po");    
	m_list_players.DeleteColumn(1);
    m_list_players.InsertColumn(1,"name");    
	m_list_players.DeleteColumn(2);
    m_list_players.InsertColumn(2,"team");    
	m_list_players.DeleteColumn(3);
    m_list_players.InsertColumn(3,"age");    
	m_list_players.DeleteColumn(4);
    m_list_players.InsertColumn(4,"salary");    
	m_list_players.DeleteColumn(5);
  
    m_list_players.SetColumnWidth( 0, 30);
    m_list_players.SetColumnWidth( 1, 90);
    m_list_players.SetColumnWidth( 2, 90);
    m_list_players.SetColumnWidth( 3, 30);
    m_list_players.SetColumnWidth( 4, 60);


	m_combo_min_sal.SetCurSel(0);
	m_combo_max_sal.SetCurSel(20);

	m_combo_fayrs.SetCurSel(0);

	m_combo_fga.SetCurSel(0);
	m_combo_fgp.SetCurSel(0);
	m_combo_tga.SetCurSel(0);
	m_combo_tgp.SetCurSel(0);
	m_combo_fta.SetCurSel(0);
	m_combo_ftp.SetCurSel(0);
	m_combo_orb.SetCurSel(0);
	m_combo_drb.SetCurSel(0);
	m_combo_ast.SetCurSel(0);
	m_combo_stl.SetCurSel(0);
	m_combo_to.SetCurSel(0);
	m_combo_blk.SetCurSel(0);
	m_combo_teams.SetCurSel(0);
	m_combo_pos.SetCurSel(0);

	m_combo_age.SetCurSel(0);
	m_combo_mpg.SetCurSel(0);
	m_combo_fgppg.SetCurSel(0);
	m_combo_tgppg.SetCurSel(0);
	m_combo_ftppg.SetCurSel(0);
	m_combo_rpg.SetCurSel(0);
	m_combo_astpg.SetCurSel(0);
	m_combo_stlpg.SetCurSel(0);
	m_combo_blkpg.SetCurSel(0);
	m_combo_ppg.SetCurSel(0);

	m_combo_oo.SetCurSel(0);
	m_combo_do.SetCurSel(0);
	m_combo_poo.SetCurSel(0);
	m_combo_tro.SetCurSel(0);

	m_combo_od.SetCurSel(0);
	m_combo_dd.SetCurSel(0);
	m_combo_pd.SetCurSel(0);
	m_combo_td.SetCurSel(0);

}

void CSearchDlg::SetScoutRatings()
{


	for(int i=0; i<=1600; i++)
	{


	CPlayer m_player = avg.m_actual[i];

	m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	

	m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_scout.m_scoring, m_scout.m_shooting, m_scout.m_rebounding, m_scout.m_passing, m_scout.m_defense);
	m_player.SetTradeTrueRating(0);
	m_player.SetAdjTradeValue(m_scout.m_pot1, m_scout.m_pot2, m_scout.m_effort);
	m_player.SetAdjustedRatings(m_scout);
	int in = m_player.m_current_team;
	if(in > 0) m_player.m_team = m_league_team_names[in];
		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);
		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		m_player.SetSimFgPct(m_player.m_sim_fgm + m_player.m_sim_tfgm, m_player.m_sim_fga + m_player.m_sim_tfga);
		m_player.SetSimFtPct(m_player.m_sim_ftm, m_player.m_sim_fta);
		m_player.SetSimTfgPct(m_player.m_sim_tfgm, m_player.m_sim_tfga);

	avg.m_actual[i] = m_player;

	}
}

void CSearchDlg::OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(m_count > 0)
	{

	int j = m_list_players.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(j >= 1)
	{

	CPlayer m_player = avg.m_actual[m_pointers[j]];


	int players_listed = m_count;
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = tm;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = j;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=1; c<=players_listed; c++)
	{
		scout->avg.m_actual[c] = avg.m_actual[m_pointers[c]];
	}
	scout->m_player_index = j;
	scout->m_pl_index_end = players_listed;
	scout->m_pl_index_start = 1;

	scout->DoModal();
	delete scout;
	}




	}
	*pResult = 0;


}

void CSearchDlg::OnOK() 
{
	// TODO: Add extra validation here

	int index = m_list_players.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	m_selected_player_id = m_pointer[index];
	CDialog::OnOK();
}

void CSearchDlg::OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_column = pNMListView->iSubItem;
	QuickSort();

	
	*pResult = 0;
}

void CSearchDlg::QuickSort()
{
	int initial_increment = 4;
    int i=0, j=0;
	CPlayer temp;
    int inc = initial_increment;

    while ( inc > 0) 
	{
      for (i=0; i <= 1600; i++)
	  {
		
        j = i;
        temp = avg.m_actual[i];
		bool swap =  false;

		if(j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

        while (swap == true)
		{
			swap = false;

			avg.m_actual[j] = avg.m_actual[j - inc];
			j = j - inc;

		if(j >= inc) swap = SortFunction(avg.m_actual[j - inc], temp);

        }
        avg.m_actual[j] = temp;
      }

      if (inc/2 != 0) inc = inc/2;
      else if (inc == 1) inc = 0;
      else inc = 1;

    }

	ListPlayers();
}

bool CSearchDlg::SortFunction(CPlayer m_player, CPlayer temp)
{
	bool swap = false;
	if(m_column >= 0) swap = SortStats(m_player, temp);
	return swap;
}

bool CSearchDlg::SortStats(CPlayer m_actual_i, CPlayer m_actual_j)
{
bool swap = false;

switch(m_column) 
{



	case 0:
		swap = m_actual_i.m_pos > m_actual_j.m_pos;
	    break;
    case 1:
		swap = m_actual_i.GetName() > m_actual_j.GetName();
        break;
    case 2:
		swap = m_actual_i.m_team > m_actual_j.m_team;
        break;
    case 3:
		swap = m_actual_i.m_age > m_actual_j.m_age;
        break;
    case 4:
		swap = m_actual_i.m_current_yr_salary < m_actual_j.m_current_yr_salary;
        break;
    case 99:
		swap = m_actual_i.m_tradeValue < m_actual_j.m_tradeValue;
        break;

}

return swap;

}

void CSearchDlg::OnClickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int index = m_list_players.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(index >= 0)
		m_button_ok.EnableWindow(TRUE);
	else
		m_button_ok.EnableWindow(FALSE);
	
	*pResult = 0;
}
