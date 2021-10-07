// TradeBlockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "TradeBlockDlg.h"
#include "PlayerCardDlg.h"


#ifndef Computer_h
#include "Computer.h"
#define Computer_h
#endif 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTradeBlockDlg dialog


CTradeBlockDlg::CTradeBlockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTradeBlockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTradeBlockDlg)
	m_checkoffers = FALSE;
	//}}AFX_DATA_INIT
//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));

}


void CTradeBlockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTradeBlockDlg)
	DDX_Control(pDX, IDC_BUTTON_GETOFFERS, m_button_getoffers);
	DDX_Control(pDX, IDC_COMBO_MAXOFFERS, m_maxoffers);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_comboteams);
	DDX_Control(pDX, IDC_LIST_BLOCK, m_listblock);
	DDX_Control(pDX, IDC_LIST_ROSTER, m_listroster);
	DDX_Check(pDX, IDC_CHECK_OFFERS, m_checkoffers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTradeBlockDlg, CDialog)
	//{{AFX_MSG_MAP(CTradeBlockDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_CHECK_OFFERS, OnCheckOffers)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_GETOFFERS, OnButtonGetoffers)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ROSTER, OnDblclkListRoster)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_BLOCK, OnDblclkListBlock)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ROSTER, &CTradeBlockDlg::OnLvnItemchangedListRoster)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTradeBlockDlg message handlers

BOOL CTradeBlockDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 

	InitData();	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTradeBlockDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/tradingblock.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

BOOL CTradeBlockDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/tradingblock.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CTradeBlockDlg::OnCheckOffers() 
{
	// TODO: Add your control notification handler code here
	
}

void CTradeBlockDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int sl = m_comboteams.GetCurSel();
	int index = m_listroster.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int slot = sl*30 + index + 1;
	avg.m_actual[slot].m_on_block = true;
	if(avg.IntRandom(20) <= (6-avg.m_actual[slot].m_effort) && avg.m_actual[slot].m_content > 1) 
		avg.m_actual[slot].m_content = avg.m_actual[slot].m_content - 1;
	ListBlock();

	
}

void CTradeBlockDlg::OnButtonRemove() 
{
	// TODO: Add your control notification handler code here
	int ind = m_listblock.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int sl = m_comboteams.GetCurSel();

	CString str = m_listblock.GetItemText( ind, 1);

	int index = 0;
	int slot = sl*30;

	for(int i=slot+1; i<=slot+30; i++)
	{
		if(avg.m_actual[i].m_name == str) index = i;

	}

	avg.m_actual[index].m_on_block = false;
	ListBlock();
	
}

void CTradeBlockDlg::InitData()
{

//myBrush.CreateSolidBrush(DLGCOLOR); 

	bool deadline = false;
	if(avg.m_sched.m_currentMonth > avg.m_sched.m_dead_mo || 
		(avg.m_sched.m_currentMonth == avg.m_sched.m_dead_mo && 
			avg.m_sched.m_currentDay > avg.m_sched.m_dead_da) &&
				avg.m_settings.m_deadline_on == 1			
			) deadline = true;

	if(deadline == true && avg.m_settings.m_current_stage == 0) 
	{
		m_button_getoffers.SetWindowText("Trade Deadline Passed");
		m_button_getoffers.EnableWindow(FALSE);
	}


	for(int i=0; i<=32; i++)
	{
		if(avg.m_settings.m_leagueTeamNames[i] != "")
			m_comboteams.AddString(avg.m_settings.m_leagueTeamNames[i]);
	}
	m_players_on_block = 0;
	m_getoffersforteam = -1;


	m_maxoffers.SetCurSel(2);


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listroster.SetBkColor(BK_COLOR);
	m_listroster.SetTextBkColor(TEXT_BK_COLOR);

	m_listroster.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listroster.SetTextColor(RGB(0,0,0));
	m_listroster.SetFont(&m_font);


    m_listroster.DeleteColumn(0);
    m_listroster.InsertColumn(0,"po");    
	m_listroster.DeleteColumn(1);
    m_listroster.InsertColumn(1,"player");    
	m_listroster.DeleteColumn(2);
    m_listroster.InsertColumn(2,"age");    
	m_listroster.DeleteColumn(3);
    m_listroster.InsertColumn(3,"salary");    
	m_listroster.DeleteColumn(4);
    m_listroster.InsertColumn(4,"inj");    
  
    m_listroster.SetColumnWidth( 0, 30);
    m_listroster.SetColumnWidth( 1, 90);
    m_listroster.SetColumnWidth( 2, 30);
    m_listroster.SetColumnWidth( 3, 60);
    m_listroster.SetColumnWidth( 4, 30);


	m_listblock.SetBkColor(BK_COLOR);
	m_listblock.SetTextBkColor(TEXT_BK_COLOR);

	m_listblock.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listblock.SetTextColor(RGB(0,0,0));
	m_listblock.SetFont(&m_font);


   m_listblock.DeleteColumn(0);
    m_listblock.InsertColumn(0,"po");    
	m_listblock.DeleteColumn(1);
    m_listblock.InsertColumn(1,"player");    
	m_listblock.DeleteColumn(2);
    m_listblock.InsertColumn(2,"age");    
	m_listblock.DeleteColumn(3);
    m_listblock.InsertColumn(3,"salary");    
	m_listblock.DeleteColumn(4);
    m_listblock.InsertColumn(4,"inj");    
  
    m_listblock.SetColumnWidth( 0, 30);
    m_listblock.SetColumnWidth( 1, 90);
    m_listblock.SetColumnWidth( 2, 30);
    m_listblock.SetColumnWidth( 3, 60);
    m_listblock.SetColumnWidth( 4, 30);  

	if(m_default_team < 0) m_default_team = 0;
	m_comboteams.SetCurSel(m_default_team);
	ListRoster();
	ListBlock();

}

void CTradeBlockDlg::OnOK() 
{
	// TODO: Add extra validation here



	CDialog::OnOK();
}

void CTradeBlockDlg::OnButtonGetoffers() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	int slot = m_comboteams.GetCurSel();
	int m_max_offers = m_maxoffers.GetCurSel() + 1;

	if(m_checkoffers == FALSE)
	{
		m_getoffersforteam = slot;
	}
	
	
	
	CComputer* comp;
	comp = new CComputer;
	comp->m_getoffersforteam = m_getoffersforteam;
	if(m_checkoffers == FALSE) comp->m_use_trading_block = true;
	for(int i=0; i<=(avg.m_settings.m_numberteams-1); i++)
	{
		comp->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
		comp->m_control[i] = avg.m_settings.m_player_gm[i];
		comp->m_player_gm[i] = avg.m_settings.m_player_gm[i];
		comp->m_numberteams = avg.m_settings.m_numberteams;
		comp->m_own[i] = avg.m_own[i];
	}

	int orig = avg.m_settings.m_get_offers[slot];//this is saved 
	avg.m_settings.m_get_offers[slot] = 1;//get offers for this team no matter what

//	comp->m_players_on_block = m_listblock.GetItemCount();
	comp->m_path = avg.m_settings.m_path;
	comp->m_leagueName = avg.m_settings.m_league_name;
	comp->m_currentMonth = avg.m_sched.m_currentMonth;
	comp->m_currentDay = avg.m_sched.m_currentDay;
	comp->m_current_year = avg.m_settings.m_currentYear;
	comp->m_computerTrades = avg.m_settings.m_computerTrades;
	comp->m_computerTrades = TRUE;
	comp->m_checkCareer = avg.m_settings.m_checkCareer;
	comp->avg = avg;
	comp->m_ast_gm = avg.m_settings.m_ast_gm;
	comp->m_finances_on = avg.m_settings.m_financial_on;	
	comp->m_free_agency_on = avg.m_settings.m_free_agency_on;


	int loops = avg.m_settings.m_salary_matching*900 + 100;
	bool invalid = comp->Trade(avg.m_settings.m_get_offers, loops, m_max_offers, avg.m_settings.m_current_stage);

	if(invalid == false) 
	{	
		avg.m_settings.m_get_offers[slot] = orig;//pass back offer for teams to original since we turned it on no matter what

		avg = comp->avg;
		//CallSetGamePlans();
		avg.m_own[0] = comp->m_own[0];
		avg.ComputerSetsRotation();
		ListRoster();
		ListBlock();
	}

	delete comp;

	
}

void CTradeBlockDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	ListRoster();
	ListBlock();
	
}

void CTradeBlockDlg::ListRoster()
{

	m_listroster.DeleteAllItems();
	int sl = m_comboteams.GetCurSel();
	int co1 = 0;
	for(int i=1; i<=30; i++)
	{
		CPlayer m_player = avg.m_actual[sl*30+i];
		CString name = m_player.GetPos() + " " + m_player.GetName();
		if(m_player.m_name == "") continue;
		CString Ag, Sa, In;
		Ag.Format("%d", m_player.m_age);
		Sa.Format("%.2f", (double)m_player.m_current_yr_salary / 100);
		In.Format("%d", m_player.m_injury);
			
		m_listroster.InsertItem(co1, m_player.GetPos());
		m_listroster.SetItemText(co1, 1, m_player.GetName());
		m_listroster.SetItemText(co1, 2, Ag);
		m_listroster.SetItemText(co1, 3, Sa);
		m_listroster.SetItemText(co1, 4, In);
		co1 = co1 + 1;
		
	}	

}

void CTradeBlockDlg::ListBlock()
{
	int sl = m_comboteams.GetCurSel();
	int co1 = 0;
	m_listblock.DeleteAllItems();
	for(int i=1; i<=30; i++)
	{
		CPlayer m_player = avg.m_actual[sl*30+i];
		CString name = m_player.GetPos() + " " + m_player.GetName();
		if(m_player.m_name == "" || m_player.m_on_block == false) continue;
		CString Ag, Sa, In;
		Ag.Format("%d", m_player.m_age);
		Sa.Format("%.2f", (double)m_player.m_current_yr_salary / 100);
		In.Format("%d", m_player.m_injury);
			
		m_listblock.InsertItem(co1, m_player.GetPos());
		m_listblock.SetItemText(co1, 1, m_player.GetName());
		m_listblock.SetItemText(co1, 2, Ag);
		m_listblock.SetItemText(co1, 3, Sa);
		m_listblock.SetItemText(co1, 4, In);
		co1 = co1 + 1;
		
	}	
}



BOOL CTradeBlockDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
/*
		CRect rc;
		GetWindowRect(&rc);
		ScreenToClient(&rc);
		CBrush brush(DARKRED);
		pDC->FillRect(rc, &brush);
		pDC->SelectStockObject(ANSI_VAR_FONT);
		pDC->DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);

  */
	return CDialog::OnEraseBkgnd(pDC);
}



void CTradeBlockDlg::OnDblclkListRoster(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listroster.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	int sl = m_comboteams.GetCurSel();

	if(i > 0)
	{

	CPlayer m_player = avg.m_actual[sl*30+i];


	int players_listed = m_listroster.GetItemCount();
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = sl;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = avg.m_actual[sl*30+c+1];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	
	*pResult = 0;
}

void CTradeBlockDlg::OnDblclkListBlock(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

HBRUSH CTradeBlockDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
          return myBrush;
     } 


	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	//return hbr;
}


void CTradeBlockDlg::OnLvnItemchangedListRoster(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
