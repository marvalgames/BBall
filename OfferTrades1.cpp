// COfferTrades.cpp : implementation file
//

#include "stdafx.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"
#include "MyComboBox.h"
#ifndef OfferTrades1_h
#include "OfferTrades1.h"
#define OfferTrades1_h
#endif 


#include "PlayerCardDlg.h"
#include "TradeDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COfferTrades dialog


COfferTrades::COfferTrades(CWnd* pParent /*=NULL*/)
	: CDialog(COfferTrades::IDD, pParent)
{
	//{{AFX_DATA_INIT(COfferTrades)
	m_team1Name = _T("");
	m_team2Name = _T("");
	m_teamOffering = _T("");
	//}}AFX_DATA_INIT
}


void COfferTrades::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COfferTrades)
	DDX_Control(pDX, IDC_LIST_CTRL_VISITOR_ROSTER, m_listVisitor);
	DDX_Control(pDX, IDC_LIST_CTRL_TEAM2, m_listTeam2);
	DDX_Control(pDX, IDC_LIST_CTRL_TEAM1, m_listTeam1);
	DDX_Control(pDX, IDC_LIST_CTRL_HOME_ROSTER, m_listHome);
	DDX_Control(pDX, IDC_BUTTON_SCOUT_VISITOR, m_buttonScoutVisitor);
	DDX_Control(pDX, IDC_BUTTON_SCOUT_HOME, m_buttonScoutHome);
	DDX_Text(pDX, IDC_EDIT_TEAM1, m_team1Name);
	DDV_MaxChars(pDX, m_team1Name, 32);
	DDX_Text(pDX, IDC_EDIT_TEAM2, m_team2Name);
	DDV_MaxChars(pDX, m_team2Name, 32);
	DDX_Text(pDX, IDC_EDIT_TEAM, m_teamOffering);
	DDV_MaxChars(pDX, m_teamOffering, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COfferTrades, CDialog)
	//{{AFX_MSG_MAP(COfferTrades)
	ON_BN_CLICKED(IDC_BUTTON_SCOUT_VISITOR, OnButtonScoutVisitor)
	ON_BN_CLICKED(IDC_BUTTON_SCOUT_HOME, OnButtonScoutHome)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_HOME_ROSTER, OnDblclkListCtrlHomeRoster)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_VISITOR_ROSTER, OnDblclkListCtrlVisitorRoster)
	ON_BN_CLICKED(IDC_BUTTON_TRADE, OnButtonTrade)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COfferTrades message handlers

BOOL COfferTrades::OnInitDialog() 
{
	CDialog::OnInitDialog();
 myBrush.CreateSolidBrush(DLGCOLOR); 

	InitControls();
	m_player = new CPlayer[41];
//	m_buttonScoutHome.EnableWindow(FALSE);
	
	// TODO: Add extra initialization here
	int index = 1, co1 = 0, co2 = 0;
	int li1 = 1, li2 = 6;
	for(int i=1; i<=20; i++)
	{
		CString name = NewTeam[i].GetPos() + " " + NewTeam[i].GetName();
		CString Ag, Sa, In;
		Ag.Format("%d", NewTeam[i].m_age);
		Sa.Format("%.2f", (double)NewTeam[i].m_current_yr_salary / 100);
		In.Format("%d", NewTeam[i].m_injury);
		if(players[i] == 2)
		{
			
			m_listTeam1.InsertItem(co1, NewTeam[i].GetPos());
			m_listTeam1.SetItemText(co1, 1, NewTeam[i].GetName());
			m_listTeam1.SetItemText(co1, 2, Ag);
			m_listTeam1.SetItemText(co1, 3, Sa);
			m_listTeam1.SetItemText(co1, 4, In);
			m_player_list[li1] = NewTeam[i].m_id;
			li1 = li1 + 1;
			co1 = co1 + 1;
		}
		if(NewTeam[i].GetName() != "")
		{
			m_listVisitor.InsertItem(co2, NewTeam[i].GetPos());
			m_listVisitor.SetItemText(co2, 1, NewTeam[i].GetName());
			m_listVisitor.SetItemText(co2, 2, Ag);
			m_listVisitor.SetItemText(co2, 3, Sa);
			m_listVisitor.SetItemText(co2, 4, In);
			co2 = co2 + 1;
            m_player[index] = NewTeam[i];
			index = index + 1;
		}
		
	}	

	CString pick_string1, pick_string2;

	int pick = m_value_picks1[0];
	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);

	CString s1, s2, s3;

	if(m_team1 == (p-1))
	{
		s1.Format("%d round %d", m_current_year - 1 + y, r);
	}
	else if(p>0)
	{
		s1.Format("%d round %d", m_current_year - 1 + y, r);
		s2 = m_leagueTeamNames[p-1];
	}




	if(s1 != "" && r > 0)
	{
		m_player_list[5] = pick;//tracks pick for negotiating trades, 5,10 picks 1-4, 6-9 players
		m_listTeam1.InsertItem(co1, "");
		m_listTeam1.SetItemText(co1, 1, s1);
		m_listTeam1.SetItemText(co1, 2, s2);
		m_listTeam1.SetItemText(co1, 3, "");
		m_listTeam1.SetItemText(co1, 4, "");
	}



    index = 21;
	co1 = 0;
	co2 = 0;
	for(int i=21; i<=40; i++)
	{

	CString name = NewTeam[i].GetPos() + " " + NewTeam[i].GetName();
		CString Ag, Sa, In;
		Ag.Format("%d", NewTeam[i].m_age);
		Sa.Format("%.2f", (double)NewTeam[i].m_current_yr_salary / 100);
		In.Format("%d", NewTeam[i].m_injury);
		if(players[i] == 1)
		{
			
			m_listTeam2.InsertItem(co1, NewTeam[i].GetPos());
			m_listTeam2.SetItemText(co1, 1, NewTeam[i].GetName());
			m_listTeam2.SetItemText(co1, 2, Ag);
			m_listTeam2.SetItemText(co1, 3, Sa);
			m_listTeam2.SetItemText(co1, 4, In);
			co1 = co1 + 1;
			m_player_list[li2] = NewTeam[i].m_id;
			li2 = li2 + 1;
		}




		if(NewTeam[i].GetName() != "")
		{
			//m_listHome.AddString(name);
            //m_player[index] = NewTeam[i];
			//index = index + 1;
			m_listHome.InsertItem(co2, NewTeam[i].GetPos());
			m_listHome.SetItemText(co2, 1, NewTeam[i].GetName());
			m_listHome.SetItemText(co2, 2, Ag);
			m_listHome.SetItemText(co2, 3, Sa);
			m_listHome.SetItemText(co2, 4, In);

			co2 = co2 + 1;
            m_player[index] = NewTeam[i];
			index = index + 1;

		}

	}	

	pick = m_value_picks2[0];
	y = pick / 1000;
	r = (pick - y*1000) / 100;
	p = pick - (y*1000 + r*100);
	
	if(m_team2 == (p-1))
	{
		s1.Format("%d round %d", m_current_year - 1 + y, r);
	}
	else if(p>0)
	{
		s1.Format("%d round %d", m_current_year - 1 + y, r);
		s2 = m_leagueTeamNames[p-1];
	}

	if(s1 != "" && r > 0)
	{
		m_player_list[10] = pick;//tracks pick for negotiating trades, 5,10 picks 1-4, 6-9 players
		m_listTeam2.InsertItem(co1, "");
		m_listTeam2.SetItemText(co1, 1, s1);
		m_listTeam2.SetItemText(co1, 2, s2);
		m_listTeam2.SetItemText(co1, 3, "");
		m_listTeam2.SetItemText(co1, 4, "");
	}




	CString string;
    string.Format("The %s propose a trade", m_teamOffering);
	m_teamOffering = string;

	m_listVisitor.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listVisitor.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listVisitor.EnsureVisible(0, TRUE);

	m_listHome.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listHome.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listHome.EnsureVisible(0, TRUE);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COfferTrades::OnButtonScoutVisitor() 
{
	// TODO: Add your control notification handler code here

}

void COfferTrades::OnButtonScoutHome() 
{
	// TODO: Add your control notification handler code here

}

void COfferTrades::OnOK() 
{
	// TODO: Add extra validation here
int result = AfxMessageBox("Are you sure you want to accept the trade?", MB_YESNO);
if(result == IDYES)
{
	delete [] m_player;
	CDialog::OnOK();
}
}

void COfferTrades::OnCancel() 
{
	// TODO: Add extra cleanup here
int result = AfxMessageBox("Are you sure you want to decline the trade?", MB_YESNO);
if(result == IDYES)
{	
	CDialog::OnCancel();
}
}
void COfferTrades::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_OFFER_TRADE);		
//	HtmlHelp(NULL, "jumpshot.chm::/html/proposetrades.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL COfferTrades::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_OFFER_TRADE);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/proposetrades.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

HBRUSH COfferTrades::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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





void COfferTrades::OnDblclkListCtrlHomeRoster(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_listHome.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;


	if(i > 0)
	{

	int players_listed = m_listHome.GetItemCount();


	CPlayerCardDlg *scout = new CPlayerCardDlg;

	scout->m_path = m_path;
	scout->m_leagueName = m_leagueName;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = NewTeam[20+c+1];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	

	*pResult = 0;
}

void COfferTrades::OnDblclkListCtrlVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_listVisitor.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;


	if(i > 0)
	{

	int players_listed = m_listVisitor.GetItemCount();


	CPlayerCardDlg *scout = new CPlayerCardDlg;

	scout->m_path = m_path;
	scout->m_leagueName = m_leagueName;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = NewTeam[c+1];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	

	*pResult = 0;
	



}

void COfferTrades::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listTeam1.SetBkColor(BK_COLOR);
	m_listTeam1.SetTextBkColor(TEXT_BK_COLOR);

	m_listTeam1.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listTeam1.SetTextColor(RGB(0,0,0));
	m_listTeam1.SetFont(&m_font);


    m_listTeam1.DeleteColumn(0);
    m_listTeam1.InsertColumn(0,"po");    
	m_listTeam1.DeleteColumn(1);
    m_listTeam1.InsertColumn(1,"player");    
	m_listTeam1.DeleteColumn(2);
    m_listTeam1.InsertColumn(2,"age");    
	m_listTeam1.DeleteColumn(3);
    m_listTeam1.InsertColumn(3,"salary");    
	m_listTeam1.DeleteColumn(4);
    m_listTeam1.InsertColumn(4,"inj");    
  
    m_listTeam1.SetColumnWidth( 0, 30);
    m_listTeam1.SetColumnWidth( 1, 90);
    m_listTeam1.SetColumnWidth( 2, 30);
    m_listTeam1.SetColumnWidth( 3, 60);
    m_listTeam1.SetColumnWidth( 4, 30);


	m_listTeam2.SetBkColor(BK_COLOR);
	m_listTeam2.SetTextBkColor(TEXT_BK_COLOR);

	m_listTeam2.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listTeam2.SetTextColor(RGB(0,0,0));
	m_listTeam2.SetFont(&m_font);


   m_listTeam2.DeleteColumn(0);
    m_listTeam2.InsertColumn(0,"po");    
	m_listTeam2.DeleteColumn(1);
    m_listTeam2.InsertColumn(1,"player");    
	m_listTeam2.DeleteColumn(2);
    m_listTeam2.InsertColumn(2,"age");    
	m_listTeam2.DeleteColumn(3);
    m_listTeam2.InsertColumn(3,"salary");    
	m_listTeam2.DeleteColumn(4);
    m_listTeam2.InsertColumn(4,"inj");    
  
    m_listTeam2.SetColumnWidth( 0, 30);
    m_listTeam2.SetColumnWidth( 1, 90);
    m_listTeam2.SetColumnWidth( 2, 30);
    m_listTeam2.SetColumnWidth( 3, 60);
    m_listTeam2.SetColumnWidth( 4, 30);  


	m_listVisitor.SetBkColor(BK_COLOR);
	m_listVisitor.SetTextBkColor(TEXT_BK_COLOR);

	m_listVisitor.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listVisitor.SetTextColor(RGB(0,0,0));
	m_listVisitor.SetFont(&m_font);




	m_listHome.SetBkColor(BK_COLOR);
	m_listHome.SetTextBkColor(TEXT_BK_COLOR);

	m_listHome.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);

    m_listHome.SetTextColor(RGB(0,0,0));
	m_listHome.SetFont(&m_font);


    m_listHome.DeleteColumn(0);
    m_listHome.InsertColumn(0,"po");    
	m_listHome.DeleteColumn(1);
    m_listHome.InsertColumn(1,"player");    
	m_listHome.DeleteColumn(2);
    m_listHome.InsertColumn(2,"age");    
	m_listHome.DeleteColumn(3);
    m_listHome.InsertColumn(3,"salary");    
	m_listHome.DeleteColumn(4);
    m_listHome.InsertColumn(4,"inj");    
  
    m_listHome.SetColumnWidth( 0, 30);
    m_listHome.SetColumnWidth( 1, 90);
    m_listHome.SetColumnWidth( 2, 30);
    m_listHome.SetColumnWidth( 3, 60);
    m_listHome.SetColumnWidth( 4, 30);

    m_listVisitor.DeleteColumn(0);
    m_listVisitor.InsertColumn(0,"po");    
	m_listVisitor.DeleteColumn(1);
    m_listVisitor.InsertColumn(1,"player");    
	m_listVisitor.DeleteColumn(2);
    m_listVisitor.InsertColumn(2,"age");    
	m_listVisitor.DeleteColumn(3);
    m_listVisitor.InsertColumn(3,"salary");    
	m_listVisitor.DeleteColumn(4);
    m_listVisitor.InsertColumn(4,"inj");    
  
    m_listVisitor.SetColumnWidth( 0, 30);
    m_listVisitor.SetColumnWidth( 1, 90);
    m_listVisitor.SetColumnWidth( 2, 30);
    m_listVisitor.SetColumnWidth( 3, 60);
    m_listVisitor.SetColumnWidth( 4, 30);

	for(int i=0; i<=10; i++)
	{
		m_player_list[i] = 0;
	}

	m_trade_made_via_trading_screen = false;

}


void COfferTrades::OnButtonTrade() 
{
	// TODO: Add your control notification handler code here
	CTradeDlg* trade;
	trade = new CTradeDlg;

	trade->m_slots = 30;
	trade->m_draftround = 0;
	trade->m_draftpick = 0;
	for(int r=1; r<=2; r++)
	{
		
		for(int i=1; i<=32; i++)
		{
			trade->m_slot_used[r][i] = 0;
		}

	}
	

	trade->m_cap = int(avg.m_settings.m_cap);
	trade->m_current_stage = avg.m_settings.m_current_stage;
//	trade->m_finances_on = avg.m_settings.m_financial_on;
	trade->avg = avg;
	trade->m_checkCareer = avg.m_settings.m_checkCareer;
	trade->m_factor = avg.m_avg_tru[0];

	trade->m_leagueName = avg.m_settings.m_league_name;
	trade->m_path = avg.m_settings.m_path;
	trade->m_current_year = avg.m_settings.m_currentYear;
	trade->m_ast_gm = avg.m_settings.m_ast_gm;



	for(int i=1; i<=480; i++)
	{
		trade->FA[i] = avg.m_actual[960+i];
	}

//	OpenStandings(m_path, m_leagueName);//contains current date also
	

	for(int i=0; i<=32; i++)
	{
//		trade->m_standings[i] = avg.m_standings[i];
		trade->m_scout[i] = avg.m_scout[i];
		trade->m_coach[i] = avg.m_coach[i];
		trade->m_gm[i] = avg.m_gm[i];
		trade->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
		trade->m_control[i] = avg.m_settings.m_player_gm[i];
		trade->m_own[i] = avg.m_own[i];
	}


	for(int i=0; i<=10; i++)
	{
		trade->m_player_list[i] = m_player_list[i];
	}


	for(int t=0; t<=31; t++)
	{
		for(int p=1; p <= 30; p++)
		{
			trade->PlayerList[t][p] = avg.m_actual[t*30+p];
		}
	}


	trade->m_currentDay = avg.m_sched.m_currentDay;
	trade->m_currentMonth = avg.m_sched.m_currentMonth;


	trade->m_default_team = m_team1;
	int result = trade->DoModal();

	avg.m_settings.m_number_transactions = trade->avg.m_settings.m_number_transactions;
	
	if(result == IDOK)
	{ 
		for(int i=1; i<=480; i++)
		{
			avg.m_actual[960+i] = trade->FA[i];
		}
		for(int t=0; t<=31; t++)
		{
			avg.m_own[t] = trade->m_own[t];
			for(int p=1; p<=30; p++)
			{
				avg.m_actual[t*30+p] = trade->PlayerList[t][p];
			}
		}

		m_trade_made_via_trading_screen = true;
		avg.SortTeamRosters(avg.m_actual, false);
		avg.ComputerSetsRotation();

	}
	delete trade;

	if(m_trade_made_via_trading_screen == false)
		CDialog::OnCancel();
	else
		CDialog::OnOK();
	
}
