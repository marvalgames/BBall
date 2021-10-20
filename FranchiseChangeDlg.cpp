// FranchiseChangeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"

#include "FranchiseChangeDlg.h"
#include "CityProfileDlg.h"

//#ifndef BBallFile_h
#include "BBallFile.h"
//#define BBallFile_h
//#endif 


#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 

#ifndef Financial_h
#include "Financial.h"
#define Financial_h
#endif 



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFranchiseChangeDlg dialog


CFranchiseChangeDlg::CFranchiseChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFranchiseChangeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFranchiseChangeDlg)
	m_edit_capacity = 0;
	m_edit_club = 0;
	m_edit_pct = 0;
	m_edit_cost = 0;
	m_edit_suites = 0;
	m_edit_team_cost = 0;
	//}}AFX_DATA_INIT
}


void CFranchiseChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFranchiseChangeDlg)
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_list_teams);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDC_LIST_CONTROL_MOVE, m_list_control);
	DDX_Control(pDX, IDC_BUTTON_END, m_button_end);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
	DDX_Control(pDX, IDC_BUTTON_MOVE, m_button_move);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_list_ctrl);
	DDX_Text(pDX, IDC_EDIT_CAPACITY, m_edit_capacity);
	DDV_MinMaxUInt(pDX, m_edit_capacity, 8000, 40000);
	DDX_Text(pDX, IDC_EDIT_CLUB, m_edit_club);
	DDV_MinMaxUInt(pDX, m_edit_club, 0, 5000);
	DDX_Text(pDX, IDC_EDIT_CONTRIBUTION, m_edit_pct);
	DDV_MinMaxUInt(pDX, m_edit_pct, 50, 100);
	DDX_Text(pDX, IDC_EDIT_COST, m_edit_cost);
	DDV_MinMaxUInt(pDX, m_edit_cost, 0, 400);
	DDX_Text(pDX, IDC_EDIT_SUITES, m_edit_suites);
	DDV_MinMaxUInt(pDX, m_edit_suites, 0, 400);
	DDX_Text(pDX, IDC_EDIT_TEAM_COST, m_edit_team_cost);
	DDV_MinMaxUInt(pDX, m_edit_team_cost, 0, 400);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFranchiseChangeDlg, CDialog)
	//{{AFX_MSG_MAP(CFranchiseChangeDlg)
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_MOVE, OnButtonMove)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CONTROL, OnClickListControl)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_EN_KILLFOCUS(IDC_EDIT_CAPACITY, OnKillfocusEditCapacity)
	ON_EN_KILLFOCUS(IDC_EDIT_CLUB, OnKillfocusEditClub)
	ON_EN_KILLFOCUS(IDC_EDIT_CONTRIBUTION, OnKillfocusEditContribution)
	ON_EN_KILLFOCUS(IDC_EDIT_SUITES, OnKillfocusEditSuites)
	ON_EN_KILLFOCUS(IDC_EDIT_TEAM_COST, OnKillfocusEditTeamCost)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL_MOVE, OnSelchangeListControlMove)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTROL, OnDblclkListControl)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CONTROL, OnColumnclickListControl)
	ON_EN_KILLFOCUS(IDC_EDIT_COST, OnKillfocusEditCost)
	ON_EN_SETFOCUS(IDC_EDIT_CAPACITY, OnSetfocusEditCapacity)
	ON_EN_SETFOCUS(IDC_EDIT_CLUB, OnSetfocusEditClub)
	ON_EN_SETFOCUS(IDC_EDIT_SUITES, OnSetfocusEditSuites)
	ON_EN_SETFOCUS(IDC_EDIT_COST, OnSetfocusEditCost)
	ON_EN_SETFOCUS(IDC_EDIT_CONTRIBUTION, OnSetfocusEditContribution)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFranchiseChangeDlg message handlers

BOOL CFranchiseChangeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	if(m_ok == false)
	{
		m_button_ok.EnableWindow(FALSE);
		m_button_ok.ShowWindow(FALSE);
		
		m_button_end.EnableWindow(FALSE);
		m_button_end.ShowWindow(FALSE);
		
		m_button_move.EnableWindow(FALSE);
		m_button_move.ShowWindow(FALSE);

		m_button_cancel.SetWindowText("Exit");
	}
	InitVariables();
	InitListCtrl();
	SetColumnHeaders();
	ListData();
	m_list_teams.SetCurSel(m_default_team);
	CheckButton();
	ListArenaData();
	ListControl();
	ListMovement();
	m_button_ok.EnableWindow(FALSE);


//	int j = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED); CListCtrl
	m_list_ctrl.SetItemState(m_default_team, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(m_default_team, TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFranchiseChangeDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	//WinHelp(HID_FINANCES_FRANCHISECHANGE);	
	//return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/progressproposals.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

HBRUSH CFranchiseChangeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
//     case CTLCOLOR_LISTBOX:
          //pDC->SetBkColor(LISTBOXCOLOR);
          //pDC->SetTextColor(LISTBOXTEXTCOLOR);
          //return myBrush;
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
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
}

void CFranchiseChangeDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_FINANCES_FRANCHISECHANGE);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/progressproposals.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

	
}

void CFranchiseChangeDlg::InitListCtrl()
{

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_ctrl.SetBkColor(BK_COLOR);
	m_list_ctrl.SetTextBkColor(TEXT_BK_COLOR);
    m_list_ctrl.SetTextColor(RGB(0,0,0));
	m_list_ctrl.SetFont(&m_font);
	m_list_ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


	for(int i=0; i<=32; i++)
	{
		CString team = m_finance[i].m_team_name;
		if(team != "") m_list_teams.AddString(team);
	}

	m_list_teams.SetCurSel(0);	
	
}

void CFranchiseChangeDlg::ListData()
{

//	int j = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int slot = 0;
	int j = m_list_teams.GetCurSel();
	for(int k=0; k<=100; k++)
	{
		if(j == m_finance[k].m_original_slot) slot = k;
	}


	int co = 0;
	m_list_ctrl.DeleteAllItems();
	for(int  index = 0; index < 100; index++)
	{
		int i=index;
		CTeamFinancial fin = m_finance[index];
		CString Stats[33];
		
		Stats[0] = fin.m_city_name;
		Stats[1] = fin.m_team_name;		


		int r = fin.m_fan_support;
		Stats[2].Format("%d", r);

		r = fin.m_political_support;
		Stats[3].Format("%d", r);

		r = fin.m_interest;
		Stats[4].Format("%d", r);

		r = fin.m_competition;
		Stats[5].Format("%d", r);

		r = fin.m_economy;
		Stats[6].Format("%d", r);

		r = fin.m_cost_of_living;
		Stats[7].Format("%d", r);

		r = fin.m_population;
		Stats[8].Format("%d", r);


		if(Stats[0] == "") continue;
		m_list_ctrl.InsertItem(co,Stats[0]);
		
		for(int s=0; s<=7; s++)
		{	
			m_list_ctrl.SetItemText(co,s+1,Stats[s+1]);
		}
		co = co + 1;		
			
	}



	m_list_ctrl.SetItemState(slot, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(slot, TRUE);


}

void CFranchiseChangeDlg::SetColumnHeaders()
{
    m_list_ctrl.InsertColumn(0,"City");    
    m_list_ctrl.InsertColumn(1,"Team");    
    m_list_ctrl.InsertColumn(2,"Fan");    
    m_list_ctrl.InsertColumn(3,"Pol");    
    m_list_ctrl.InsertColumn(4,"Int");    
    m_list_ctrl.InsertColumn(5,"Comp");    
    m_list_ctrl.InsertColumn(6,"Eco");    
    m_list_ctrl.InsertColumn(7,"Cost");    
    m_list_ctrl.InsertColumn(8,"Pop");    
    m_list_ctrl.SetColumnWidth( 0, 120);
    m_list_ctrl.SetColumnWidth( 1, 120);
    m_list_ctrl.SetColumnWidth( 2, 50);
    m_list_ctrl.SetColumnWidth( 3, 50);
    m_list_ctrl.SetColumnWidth( 4, 50);
    m_list_ctrl.SetColumnWidth( 5, 50);
    m_list_ctrl.SetColumnWidth( 6, 50);
    m_list_ctrl.SetColumnWidth( 7, 50);
    m_list_ctrl.SetColumnWidth( 8, 50);

	
	//	m_list_ctrl.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
}


void CFranchiseChangeDlg::OnButtonMove() 
{
	// TODO: Add your control notification handler code here
	if(m_stage_end == false)
	{
	int i = m_list_teams.GetCurSel();
	int j = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	i = m_finance[i].m_original_slot;
//	j = m_finance[j].m_original_slot;


	if(i < 0)  i = 0;
	m_current_team = i;
	m_current_city = j;

	m_finance[m_current_team].PossibleMoveCity( 
			m_finance[m_current_city].m_political_support, m_finance[m_current_city].m_economy,
			m_finance[m_current_city].m_fan_support, m_finance[m_current_city].m_cost_of_living,
			m_finance[m_current_city].m_population, m_finance[m_current_city].m_interest,
			m_finance[m_current_city].m_competition, m_future[m_current_team].m_city_cost);

	m_future[m_current_team].m_proposal_made = true;
	ListResult();
	CheckButton();
	}
}

void CFranchiseChangeDlg::OnClickListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CheckButton();
	*pResult = 0;
}

void CFranchiseChangeDlg::ListResult()
{
	CString string, string1;
	CString city_name = m_finance[m_current_city].m_city_name;
	CString team = m_finance[m_current_team].m_team_name;
	bool move = m_finance[m_current_team].m_possible_move_city;
	int yrs = m_finance[m_current_team].m_possible_move_years;

//	m_current_team = m_list_teams.GetCurSel();
	int sel_city = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);

    m_finance[m_current_team].m_possible_new_city = sel_city;

    int possible_city = m_finance[m_current_team].m_possible_new_city;

	if(possible_city != m_current_team && possible_city >= 0) 
	{
		m_finance[m_current_team].m_possible_new_city = m_current_city;
		string.Format("%s propose move to %s", team, city_name);
	}
	else if(possible_city == m_current_team) 
	{
		m_finance[m_current_team].m_possible_new_city = m_current_city;
		string.Format("%s propose new arena construction", team);
	}
	
	
	if(move != true)
		string1.Format("%s rejects %s proposal", city_name, team);
	else
		string1.Format("%s to consider %s proposal", city_name, team);

	m_list_result.AddString(string);
	m_list_result.AddString(string1);



}

void CFranchiseChangeDlg::InitVariables()
{
	CBBallFile* disk = new CBBallFile;
	disk->ReadFutureFile(m_future, m_file_name + ".fut");
	for(int i=0; i<=100; i++)
	{


//		m_future[i] = disk->m_future[i];
		m_future[i].m_original_slot = i;
//		m_finance[i].m_possible_new_city = m_future[i].m_new_city;
		m_finance[i].m_possible_new_city = -1;
		m_finance[i].m_possible_move_years = m_future[i].m_move_year;
		m_finance[i].m_possible_capacity = m_finance[i].m_capacity;
		m_finance[i].m_possible_suites = m_finance[i].m_suites;
		m_finance[i].m_possible_club_seats = m_finance[i].m_club_seats;
		m_finance[i].m_possible_parking_spots = m_finance[i].m_parking_spots;


//		if(m_future[i].m_move_year == 1)
//		{
//			m_finance[i].m_capacity = m_future[i].m_capacity;
//			m_finance[i].m_club_seats = m_future[i].m_club_seats;
//			m_finance[i].m_suites = m_future[i].m_suites;
			
//		}

//		m_future[i].SetGameNewArenaExpense();


	}
	delete disk;
	m_edit_pct = 50;
	m_current_team = m_default_team;
	m_current_city = m_default_team;
	m_edit_capacity = 15000;
	m_edit_club = 2000;
	m_edit_suites = 100;
	m_edit_cost = 150;
	m_stage_end = false;
	m_column = 0;
	UpdateData(FALSE);
}

void CFranchiseChangeDlg::OnButtonEnd() 
{
	// TODO: Add your control notification handler code here
	if(m_stage_end == false)
	{

	m_list_result.ResetContent();
	ComputerProposals();
	for(int i=0; i<=100; i++)
	{

		if(	m_future[i].m_yrs_since_move > 0
			|| m_future[i].m_move_year > 0) continue;
		

		int hi_sc = 0;
		int hi_te = 0;
		for(int j=0; j<=32; j++)
		{
			if(m_finance[j].m_possible_new_city == i && m_finance[j].m_possible_move_score > hi_sc)
			{
				hi_sc = m_finance[j].m_possible_move_score;
				hi_te = j;
			}
		}

	
	
		if(hi_sc > 0)
		{
			
			m_future[hi_te].m_move_year = m_finance[hi_te].m_possible_move_years;
			m_future[hi_te].m_new_city = i;
			m_future[hi_te].m_capacity = m_finance[hi_te].m_possible_capacity;
			m_future[hi_te].m_suites = m_finance[hi_te].m_possible_suites;
			m_future[hi_te].m_club_seats = m_finance[hi_te].m_possible_club_seats;	
			m_future[hi_te].m_parking_spots = m_finance[hi_te].m_possible_parking_spots;	
			m_finance[hi_te].m_move_city = true;

		}

	}
	DisplayComputerProposals();
	ListFinalResult();	
	m_button_ok.EnableWindow(TRUE);

	}
}

void CFranchiseChangeDlg::ListFinalResult()
{

	for(int i=0; i<=32; i++)
	{
		bool move = m_finance[i].m_move_city;
		CString team = m_finance[i].m_team_name;
		CString string;

		if(m_future[i].m_proposal_made == true && move == false && m_control[i] == "Player") 
		{
			string.Format("%s proposal is denied", team);
			m_list_result.AddString(string);	
			m_list_result.AddString("");
		}


		if(move == false) continue;


		int city = m_future[i].m_new_city;		
		CString city_name = m_finance[city].m_city_name;
		int yrs = m_future[i].m_move_year;

		int city_cost = m_future[i].m_city_cost;
		int team_cost = m_future[i].m_team_cost;
		int stadium_cost = city_cost + team_cost;
//		int capacity = m_finance[i].m_capacity;
		int capacity = m_future[i].m_capacity;
		m_future[i].m_initial_move_year = m_future[i].m_move_year;
		CString arena;
		arena.Format("city cost: %d  team cost: %d capacity: %d", city_cost, team_cost, capacity);

		if(city != i)
			string.Format("%s welcomes %s in %d years", city_name, team, yrs-1);
		else
			string.Format("%s %s arena construction will be completed in %d years", city_name, team, yrs-1);

		m_list_result.AddString(string);	
		m_list_result.AddString(arena);
		m_list_result.AddString("");
	}

	int count = m_list_result.GetCount()-1;
	m_list_result.SetCurSel(count);

	m_stage_end = true;
	m_button_end.EnableWindow(FALSE);
	m_button_move.EnableWindow(FALSE);



	EnableEditBoxes(FALSE);


}

void CFranchiseChangeDlg::ListArenaData()
{
	UpdateData(TRUE);

	
//	m_edit_cost = 0;


	int i = m_list_teams.GetCurSel();
	if(i < 0)  i = 0;
	m_current_team = i;

	m_edit_team_cost = m_future[m_current_team].m_team_cost;
	m_edit_capacity = m_finance[m_current_team].m_possible_capacity;
	m_edit_club = m_finance[m_current_team].m_possible_club_seats;
	m_edit_suites = m_finance[m_current_team].m_possible_suites;
	m_edit_cost = m_future[m_current_team].m_total_cost;

	int cost = m_edit_capacity  + m_edit_club * 4 + m_edit_suites * 100;
	double tmp = (double)cost / 200;
	int temp_cost = (int) tmp;


	if((UINT)m_edit_cost < (UINT)temp_cost) m_edit_cost = temp_cost;

	double tmp_city_cost = (double) m_edit_pct / 100 * (double) m_edit_cost;
	double tmp_team_cost = m_edit_cost - tmp_city_cost;

	m_edit_team_cost = (int) tmp_team_cost;
	

	m_future[m_current_team].m_team_cost = (int)tmp_team_cost;
	m_future[m_current_team].m_city_cost = (int)tmp_city_cost;
	m_future[m_current_team].m_total_cost = m_edit_cost;
	
	UpdateData(FALSE);
}

void CFranchiseChangeDlg::OnKillfocusEditCapacity() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	m_finance[m_current_team].m_possible_capacity = m_edit_capacity;
	ListArenaData();
}


void CFranchiseChangeDlg::OnKillfocusEditClub() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_finance[m_current_team].m_possible_club_seats = m_edit_club;
	ListArenaData();
	
}

void CFranchiseChangeDlg::OnKillfocusEditContribution() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ListArenaData();
	
}

void CFranchiseChangeDlg::OnKillfocusEditSuites() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_finance[m_current_team].m_possible_suites = m_edit_suites;
	ListArenaData();
	
}

void CFranchiseChangeDlg::OnOK() 
{
	// TODO: Add extra validation here
	CTeamFinancial* m_copy_finance = new CTeamFinancial[201];


	for(int i=0; i<=99; i++)
	{
		int orig = m_finance[i].m_original_slot;
		m_finance[i] = m_finance[orig];		
	}


	delete [] m_copy_finance;

	CFuture* m_copy_future = new CFuture[201];

	for(int i=0; i<=99; i++)
	{
		int orig = m_future[i].m_original_slot;
		m_future[i] = m_future[orig];		
	}


	delete [] m_copy_future;

	double ttl = 0;
	for(int i=0; i<m_number_teams; i++)
	{
		for(int j=1; j<=30; j++)
		{
			CPlayer m_player = m_actual[i * 30 + j];
			m_finance[i].m_contract[j] = m_player; 
		}

		m_finance[i].SetTeamRosterValue();
		ttl = ttl + m_finance[i].m_team_roster_value;
	}
	double avg_roster_value = ttl / m_number_teams;


		for(int i=0; i<m_number_teams; i++)
		{
			if(m_control[i] != "Player")
			{

				//double avg_roster_value = m_tru * 15;
				//m_finance[i].SetTeamRosterValue();
				int w = m_standings[i].m_win;
				int l = m_standings[i].m_loss;
				int hi_g = m_hi_games;
				m_finance[i].SetEndOfSeasonTicketPrice(m_coach[i].m_personality, avg_roster_value, w, l, hi_g);
				m_finance[i].SetEndOfSeasonSuitePrice(m_coach[i].m_personality, avg_roster_value, w, l, hi_g);
				m_finance[i].SetEndOfSeasonClubPrice(m_coach[i].m_personality, avg_roster_value, w, l, hi_g);
				m_finance[i].SetEndOfSeasonConcessionPrice(avg_roster_value);
				m_finance[i].SetEndOfSeasonParkingPrice(avg_roster_value);
			}
		}


		for(int i=0; i<=99; i++)
		{
			m_future[i].UpdateFutureData(i);	
			m_future[i].SetGameNewArenaExpense();
			m_finance[i].SetEndOfSeasonArenaValue();
			m_finance[i].m_possible_move_score = 0;
			m_finance[i].m_possible_move_city = false;
			m_finance[i].m_move_city = false;
			m_finance[i].m_move_years = 0;
			m_finance[i].m_new_city = 0;
		}	


	
		//ReSortFranchiseData();//teams that move are changed to set up write to file (franchise file)
	for(int i=0; i<=99; i++)
	{
		m_finance[i].m_arena = int( (double) m_finance[i].m_current_value * 1000 / 100 / 82);
		if(m_future[i].m_paying_for_arena == true)
		{
			m_finance[i].m_arena = m_finance[i].m_arena + m_future[i].m_game_new_arena_expense;
		}
		if(m_future[i].m_moving == true)
		{
			int new_city = m_future[i].m_new_city;



			//swap sity name


			CTeamFinancial temp_f = m_finance[i];
			m_finance[i] = m_finance[new_city];
			m_finance[new_city] = temp_f;

			CString temp = m_finance[i].m_team_name;
			m_finance[i].m_team_name = m_finance[new_city].m_team_name;
			m_finance[new_city].m_team_name = temp;

			CString temp_a = m_finance[i].m_arena_name;
			m_finance[i].m_arena_name = m_finance[new_city].m_arena_name;
			m_finance[new_city].m_arena_name = temp;


			m_finance[i].m_capacity = m_future[i].m_capacity;
			m_finance[i].m_club_seats = m_future[i].m_club_seats;
			m_finance[i].m_suites = m_future[i].m_suites;
			m_finance[i].m_parking_spots = m_future[i].m_parking_spots;


		}
	}

	for(int i=0; i<=99; i++)
	{
		if(m_future[i].m_moving == true) m_future[i].m_new_city = 0;
	}



		for(int i=0; i<=99; i++)
		{
			if(m_future[i].m_moving == true)
			{
				m_finance[i].m_stadium_value = m_future[i].m_team_cost + m_future[i].m_city_cost;
			}
			//m_finance[i] = m_finance[i];
		}	



	
		
	CDialog::OnOK();

}

void CFranchiseChangeDlg::OnKillfocusEditTeamCost() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ListArenaData();	
}

void CFranchiseChangeDlg::CheckButton()
{
	m_current_team = m_list_teams.GetCurSel();
	m_current_city = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(m_current_city < 0) m_current_city = 0;
	int i = m_current_city;
	int j = m_list_teams.GetCurSel();
	i = m_finance[i].m_original_slot;
//	j = m_finance[j].m_original_slot;

	if(	(m_finance[i].m_team_name != "" && i != j) || (m_future[j].m_yrs_since_move > 0))
	{
		m_button_move.EnableWindow(FALSE);
		EnableEditBoxes(FALSE);
	}
	else if(m_future[j].m_proposal_made == true)
	{
		m_button_move.EnableWindow(FALSE);
		EnableEditBoxes(FALSE);
	}
	else if(m_control[m_current_team] == "Computer")
	{
		m_button_move.EnableWindow(FALSE);
		EnableEditBoxes(FALSE);
	}
	else
	{
		m_button_move.EnableWindow(TRUE);
		EnableEditBoxes(TRUE);
	}


    j = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	m_list_ctrl.SetItemState(j, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(j, TRUE);

}

void CFranchiseChangeDlg::ComputerProposals()
{
	
	CFinancial* fin = new CFinancial;

		
	for(int i=0; i<=100; i++)
	{
		fin->m_finance[i] = m_finance[i];
		fin->m_future[i] = m_future[i];
	}
	fin->m_number_teams = m_number_teams;
	fin->GenerateComputerProposals(m_control);

	for(int i=0; i<=100; i++)
	{
			m_finance[i] = fin->m_finance[i]; 
			m_future[i] = fin->m_future[i]; 
	}


	delete fin;
}

void CFranchiseChangeDlg::DisplayComputerProposals()
{

	for(int i=0; i<m_number_teams; i++)
	{
	CString string;
	int possible_city = m_finance[i].m_possible_new_city;

	if(possible_city == -1) continue;

	CString city_name = m_finance[possible_city].m_city_name;
	CString team = m_finance[i].m_team_name;
	bool move = m_finance[i].m_possible_move_city;
	int yrs = m_finance[i].m_possible_move_years;
	int city_cost = m_future[i].m_city_cost;
	int team_cost = m_future[i].m_team_cost;
	int stadium_cost = city_cost + team_cost;
	int capacity = m_finance[i].m_possible_capacity;
	CString arena;
	arena.Format("city cost: %d  team cost: %d capacity: %d", city_cost, team_cost, capacity);
	if(move == true && possible_city != i) 
	{
		string.Format("%s propose move to %s", team, city_name);
	}
	else if(move == true && possible_city == i) 
	{
		string.Format("%s propose new arena", team);
	}


	if(string != "")
	{
		m_list_result.AddString(string);
		m_list_result.AddString(arena);
		m_list_result.AddString("");
	}


	}


}

void CFranchiseChangeDlg::OnSelchangeListControlMove() 
{
	// TODO: Add your control notification handler code here
	if(m_control[m_current_team] == "Player")
		m_control[m_current_team] = "Computer";
	else if(m_control[m_current_team] == "Computer")
		m_control[m_current_team] = "Player";
	ListControl();
	CheckButton();
	
}

void CFranchiseChangeDlg::ListControl()
{
	CString control = m_control[m_current_team];
	m_list_control.ResetContent();
	m_list_control.AddString(control);
}

void CFranchiseChangeDlg::OnDblclkListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	if(m_current_city < m_number_teams)
	{

	CCityProfileDlg* city = new CCityProfileDlg;
	for(int i=0; i<=199; i++)
	{
		city->m_finance[i] = m_finance[i];
	}
	city->m_finance[100] = m_finance[m_current_city];
	city->m_finance[200] = m_finance[m_current_city + 100];
	city->m_hi_games = m_hi_games;
	int result = city->DoModal();
	delete city;

	}
	
	*pResult = 0;
}

void CFranchiseChangeDlg::OnColumnclickListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
/*	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_column = pNMListView->iSubItem;

CTeamFinancial m_i, m_j;

for(int i=0; i<m_number_teams; i++)
{
for(int j=0; j<m_number_teams; j++)
{

	bool swap = false;

	m_i = m_finance[i];
	m_j = m_finance[j];

switch(m_column) 
{

    case 0:
		swap = m_i.m_city_name < m_j.m_city_name;
        break;
    case 1:
		swap = m_i.m_team_name > m_j.m_team_name;
        break;
    case 2:
		swap = m_i.m_fan_support > m_j.m_fan_support;
        break;
    case 3:
		swap = m_i.m_political_support > m_j.m_political_support;
        break;
    case 4:        
		swap = m_i.m_interest > m_j.m_interest;
        break;
    case 5:
		swap = m_i.m_competition > m_j.m_competition;
        break;
    case 6:
		swap = m_i.m_economy > m_j.m_economy;
        break;
    case 7:
		swap = m_i.m_cost_of_living > m_j.m_cost_of_living;
        break;
    case 8:
		swap = m_i.m_population > m_j.m_population;
        break;
}



	if(swap == true)
	{//swap
		CTeamFinancial temp = m_finance[i];
		m_finance[i] = m_finance[j];
		m_finance[j] = temp;

		CFuture temp_f = m_future[i];
		m_future[i] = m_future[j];
		m_future[j] = temp_f;
	}
}

}
	
	ListData();

	*pResult = 0;*/
}

void CFranchiseChangeDlg::ListMovement()
{

	if(m_stage_end == false)
	{

		m_list_result.ResetContent();

		int i = m_list_teams.GetCurSel();

		CString string1, string2, string3;
		int yrs_since = m_future[i].m_yrs_since_move;
		int yrs = m_future[i].m_move_year;
		CString city = m_finance[i].m_city_name;

		CString arena = m_finance[i].m_arena_name;

		CString team = m_finance[i].m_team_name;


		int new_city = m_future[i].m_new_city;
		
		CString new_city_name = m_finance[new_city].m_city_name;		
		bool prop = false;
		
		if(m_future[i].m_proposal_made == true) prop = true;

		if(yrs_since == 0 && prop == false)
		{
			string1.Format("%s  proposal permission: yes", team);
		}
		else
		{
			string1.Format("%s  proposal permission: no", team);
		}

		if(yrs > 0)
		{
			string2.Format("construction site: %s", city);
			if(yrs >= 3)
				string3.Format("construction completion: %d years", yrs-1);
			else if(yrs == 2)
				string3.Format("construction completion: %d year", yrs-1);
			else if(yrs == 1)
				string3.Format("construction complete");
		}

		if(string1 != "") m_list_result.AddString(string1);	
		if(string2 != "") m_list_result.AddString(string2);	
		if(string3 != "") m_list_result.AddString(string3);	
		m_list_result.AddString("");	
	}
}

void CFranchiseChangeDlg::EnableEditBoxes(BOOL enable)
{
	GetDlgItem(IDC_EDIT_CAPACITY)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_CLUB)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_CONTRIBUTION)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_COST)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_SUITES)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_TEAM_COST)->EnableWindow(enable);

}

void CFranchiseChangeDlg::OnKillfocusEditCost() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_future[m_current_team].m_total_cost = m_edit_cost;
	ListArenaData();
	
}

void CFranchiseChangeDlg::OnSetfocusEditCapacity() 
{
	// TODO: Add your control notification handler code here
/*	GetDlgItem(IDC_EDIT_CAPACITY)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_CLUB)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_CONTRIBUTION)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_COST)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_SUITES)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_TEAM_COST)->EnableWindow(enable);*/
	((CEdit*) (GetDlgItem(IDC_EDIT_CAPACITY)))->SetSel(0, -1);
		
}

void CFranchiseChangeDlg::OnSetfocusEditClub() 
{
	// TODO: Add your control notification handler code here
	((CEdit*) (GetDlgItem(IDC_EDIT_CLUB)))->SetSel(0, -1);
	
}

void CFranchiseChangeDlg::OnSetfocusEditSuites() 
{
	// TODO: Add your control notification handler code here
	((CEdit*) (GetDlgItem(IDC_EDIT_SUITES)))->SetSel(0, -1);
	
}

void CFranchiseChangeDlg::OnSetfocusEditCost() 
{
	// TODO: Add your control notification handler code here
	((CEdit*) (GetDlgItem(IDC_EDIT_COST)))->SetSel(0, -1);
	
}

void CFranchiseChangeDlg::OnSetfocusEditContribution() 
{
	// TODO: Add your control notification handler code here
	((CEdit*) (GetDlgItem(IDC_EDIT_CONTRIBUTION)))->SetSel(0, -1);
		
}

void CFranchiseChangeDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	CheckButton();

	ListArenaData();

	ListControl();

	ListMovement();
	

	
}
