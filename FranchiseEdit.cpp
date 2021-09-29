// FranchiseEdit.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "FranchiseEdit.h"

#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFranchiseEdit dialog


CFranchiseEdit::CFranchiseEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CFranchiseEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFranchiseEdit)
	m_edit_capacity = 0;
	m_edit_club_seats = 0;
	m_edit_suites = 0;
	m_edit_city_name = _T("");
//	m_edit_team_name = _T("");
	m_edit_arena = _T("");
	m_edit_comp = 0;
	m_edit_cost = 0;
	m_edit_eco = 0;
	m_edit_fan = 0;
	m_edit_int = 0;
	m_edit_pol = 0;
	m_edit_pop = 0;
	m_edit_spots = 0;
	m_edit_arena_value = 0;
	m_edit_club_price = 0;
	m_edit_con_price = 0;
	m_edit_current_value = 0;
	m_edit_suite_price = 0;
	m_edit_ticket_price = 0;
//	m_edit_city = _T("");
	//}}AFX_DATA_INIT
}


void CFranchiseEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFranchiseEdit)
	DDX_Control(pDX, IDC_COMBO_LIST_TEAMS, m_list_teams);
	DDX_Control(pDX, IDC_COMBO_LIST_CITIES2, m_list_arena);
	DDX_Control(pDX, IDC_COMBO_LIST_CITIES, m_list_franchise);
	DDX_Text(pDX, IDC_EDIT_CAPACITY, m_edit_capacity);
	DDV_MinMaxUInt(pDX, m_edit_capacity, 3200, 48000);
	DDX_Text(pDX, IDC_EDIT_CLUB_SEATS, m_edit_club_seats);
	DDV_MinMaxUInt(pDX, m_edit_club_seats, 0, 5000);
	DDX_Text(pDX, IDC_EDIT_SUITES, m_edit_suites);
	DDV_MinMaxUInt(pDX, m_edit_suites, 0, 500);
	DDX_Text(pDX, IDC_EDIT_CITY_NAME, m_edit_city_name);
	DDV_MaxChars(pDX, m_edit_city_name, 32);
//	DDX_Text(pDX, IDC_EDIT_TEAM, m_edit_team_name);
//	DDV_MaxChars(pDX, m_edit_team_name, 32);
	DDX_Text(pDX, IDC_EDIT_ARENA_NAME, m_edit_arena);
	DDV_MaxChars(pDX, m_edit_arena, 32);
	DDX_Text(pDX, IDC_EDIT_COMP, m_edit_comp);
	DDV_MinMaxUInt(pDX, m_edit_comp, 1, 7);
	DDX_Text(pDX, IDC_EDIT_COST, m_edit_cost);
	DDV_MinMaxUInt(pDX, m_edit_cost, 1, 7);
	DDX_Text(pDX, IDC_EDIT_ECO, m_edit_eco);
	DDV_MinMaxUInt(pDX, m_edit_eco, 1, 7);
	DDX_Text(pDX, IDC_EDIT_FAN, m_edit_fan);
	DDV_MinMaxUInt(pDX, m_edit_fan, 1, 7);
	DDX_Text(pDX, IDC_EDIT_INT, m_edit_int);
	DDV_MinMaxUInt(pDX, m_edit_int, 1, 7);
	DDX_Text(pDX, IDC_EDIT_POL, m_edit_pol);
	DDV_MinMaxUInt(pDX, m_edit_pol, 1, 7);
	DDX_Text(pDX, IDC_EDIT_POP, m_edit_pop);
	DDV_MinMaxUInt(pDX, m_edit_pop, 1, 7);
	DDX_Text(pDX, IDC_EDIT_SPOTS, m_edit_spots);
	DDV_MinMaxUInt(pDX, m_edit_spots, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_ARENA_VALUE, m_edit_arena_value);
	DDV_MinMaxUInt(pDX, m_edit_arena_value, 50, 500);
	DDX_Text(pDX, IDC_EDIT_CLUB_PRICE, m_edit_club_price);
	DDV_MinMaxUInt(pDX, m_edit_club_price, 0, 500);
	DDX_Text(pDX, IDC_EDIT_CON_PRICE, m_edit_con_price);
	DDV_MinMaxUInt(pDX, m_edit_con_price, 1, 100);
	DDX_Text(pDX, IDC_EDIT_CURRENT_VALUE, m_edit_current_value);
	DDV_MinMaxUInt(pDX, m_edit_current_value, 50, 750);
	DDX_Text(pDX, IDC_EDIT_SUITE_PRICE, m_edit_suite_price);
	DDV_MinMaxUInt(pDX, m_edit_suite_price, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_TICKET_PRICE, m_edit_ticket_price);
	DDV_MinMaxUInt(pDX, m_edit_ticket_price, 5, 250);
//	DDX_Text(pDX, IDC_EDIT_CITY, m_edit_city);
//	DDV_MaxChars(pDX, m_edit_city, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFranchiseEdit, CDialog)
	//{{AFX_MSG_MAP(CFranchiseEdit)
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_CITIES, OnSelchangeComboListCities)
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_CITIES2, OnSelchangeComboListCities2)
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAMS, OnSelchangeComboListTeams)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFranchiseEdit message handlers

BOOL CFranchiseEdit::OnInitDialog() 
{

	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	((CEdit*) (GetDlgItem(IDC_EDIT_ARENA_NAME)))->SetFocus();
	myBrush.CreateSolidBrush(DLGCOLOR); 
	
	m_current_selection = m_default_team;	
	m_current_selection1 = m_default_team;	
	m_current_selection2 = m_default_team;	

	ListFranchises();
	ListFranchiseProfile(true, true, m_default_team, m_default_team);
	m_list_franchise.SetCurSel(m_default_team);
	m_list_arena.SetCurSel(m_default_team);
	m_list_teams.SetCurSel(m_default_team);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CFranchiseEdit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
	


//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
}

void CFranchiseEdit::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here

//	HtmlHelp(NULL, "jumpshot.chm::/html/progressproposals.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

//	HtmlHelp(NULL, "jumpshot.chm::/html/toolscityeditor.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

//	WinHelp(HID_FINANCES_FRANCHISEEDIT);	
//	return TRUE;
	
}

BOOL CFranchiseEdit::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_FINANCES_FRANCHISEEDIT);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolscityeditor.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CFranchiseEdit::OnOK() 
{
	// TODO: Add extra validation here
	m_current_selection = m_list_teams.GetCurSel();
	UpdateFranchiseData(true, true,  m_current_selection, m_current_selection);
	CDisk* disk = new CDisk;
	CString file_name = m_path + m_league_name + ".frn";

	for(int i=0; i<=99; i++)
	{
		disk->avg.m_finance[i] = m_finance[i];		
	}

	disk->WriteFranchiseData(file_name,0,100);
	delete disk;
	CDialog::OnOK();
}


void CFranchiseEdit::ListFranchiseProfile(bool update_city, bool update_arena, int current_selection, int current_selection1)
{



if(update_city == true)
{
	m_edit_city_name = m_finance[current_selection].m_city_name;
	double n = (double)m_finance[current_selection].m_current_value/10;
	m_edit_current_value = (int)n;
	m_edit_comp = m_finance[current_selection].m_competition;
	m_edit_cost = m_finance[current_selection].m_cost_of_living;
	m_edit_eco = m_finance[current_selection].m_economy;
	m_edit_fan = m_finance[current_selection].m_fan_support;
	m_edit_int = m_finance[current_selection].m_interest;
	m_edit_pol = m_finance[current_selection].m_political_support;
	m_edit_pop = m_finance[current_selection].m_population;

}

if(update_arena == true)
{
	m_edit_arena = m_finance[current_selection1].m_arena_name;
	if(m_edit_arena == "") m_edit_arena == "None";
	m_edit_arena_value = m_finance[current_selection1].m_stadium_value;
	m_edit_capacity = m_finance[current_selection1].m_capacity;
	m_edit_club_seats = m_finance[current_selection1].m_club_seats;
	m_edit_spots = m_finance[current_selection1].m_parking_spots;
	m_edit_suites = m_finance[current_selection1].m_suites;
	double n = (double)m_finance[current_selection1].m_ticket_price/10;
	m_edit_ticket_price = (int)n;
	m_edit_club_price = m_finance[current_selection1].m_club_price;
	m_edit_suite_price = m_finance[current_selection1].m_suite_price;
	n = (double)m_finance[current_selection1].m_concessions/10;
	m_edit_con_price = (int)n;
}		


//	if(current_selection <= 32)
//		m_edit_team_name = m_league_team_names[current_selection];
//	else
//		m_edit_team_name = "None";

//	if(current_selection1 <= 32)
//		m_edit_city = m_finance[current_selection1].m_city_name;
//	else
//		m_edit_city = "None";

	UpdateData(FALSE);
}

void CFranchiseEdit::ListFranchises()
{

	m_list_franchise.ResetContent();
	m_list_arena.ResetContent();
	m_list_teams.ResetContent();

	for(int i=0; i<=99; i++)
	{
		CString name = m_finance[i].m_city_name;
		CString arena_name = m_finance[i].m_arena_name;
		CString team_name = m_finance[i].m_team_name;
		m_list_franchise.AddString(name);
		m_list_arena.AddString(arena_name);
		if(team_name != "")
			m_list_teams.AddString(team_name);
	}
}

void CFranchiseEdit::UpdateFranchiseData(bool update_city, bool update_arena, int current_selection, int current_selection1)
{

	UpdateData(TRUE);

	if(update_arena == true)
	{

	double cap = (double) m_edit_capacity;
	double ste = (double) m_edit_suites;
	double clb = (double) m_edit_club_seats;
	double spt = (double) m_edit_spots;
	if(ste > (cap / 40)) m_edit_suites = int(cap / 40);
	if(clb > (cap / 2)) m_edit_club_seats = int(cap / 2);
	if(spt > (cap / 2)) m_edit_spots = int(cap / 2);
	m_finance[current_selection1].m_arena_name = m_edit_arena;
	m_finance[current_selection1].m_stadium_value = m_edit_arena_value;
	m_finance[current_selection1].m_capacity = m_edit_capacity;
	m_finance[current_selection1].m_club_seats = m_edit_club_seats;
	m_finance[current_selection1].m_parking_spots = m_edit_spots;
	m_finance[current_selection1].m_suites = m_edit_suites;
	double n = (double)m_edit_ticket_price * 10;
	m_finance[current_selection1].m_ticket_price = (int)n;
	m_finance[current_selection1].m_club_price = m_edit_club_price;
	m_finance[current_selection1].m_suite_price = m_edit_suite_price;
	n = (double)m_edit_con_price * 10;
	m_finance[current_selection1].m_concessions = (int)n;

	}

	if(update_city == true)
	{

	m_finance[current_selection].m_city_name = m_edit_city_name;
	m_finance[current_selection].m_competition = m_edit_comp;
	m_finance[current_selection].m_cost_of_living = m_edit_cost;
	double n = (double)m_edit_current_value * 10;
	m_finance[current_selection].m_current_value = int(n);
	m_finance[current_selection].m_economy = m_edit_eco;
	m_finance[current_selection].m_fan_support = m_edit_fan;
	m_finance[current_selection].m_interest = m_edit_int;
	m_finance[current_selection].m_political_support = m_edit_pol;
	m_finance[current_selection].m_population = m_edit_pop;
	
	}
}

//void CFranchiseEdit::OnViewPbp() 
//{
//	// TODO: Add your command handler code here
	
//}

void CFranchiseEdit::OnSelchangeComboListCities() 
{
	// TODO: Add your control notification handler code here
//	UpdateFranchiseData(true, false, m_current_selection, m_current_selection1);
	int current_selection = m_list_franchise.GetCurSel();
	int current_selection1 = m_list_arena.GetCurSel();
	ListFranchiseProfile(true, false, current_selection, current_selection1);
	((CEdit*) (GetDlgItem(IDC_EDIT_ARENA_NAME)))->SetFocus();

}
	


void CFranchiseEdit::OnSelchangeComboListCities2() 
{
	// TODO: Add your control notification handler code here
//	UpdateFranchiseData(false,true, m_current_selection, m_current_selection1);
	int current_selection = m_list_franchise.GetCurSel();
	int current_selection1 = m_list_arena.GetCurSel();
	ListFranchiseProfile(false, true, current_selection, current_selection1);
	
}

void CFranchiseEdit::OnSelchangeComboListTeams() 
{
	// TODO: Add your control notification handler code here
//	UpdateFranchiseData(true, true, m_current_selection, m_current_selection1);
	int current_selection = m_list_teams.GetCurSel();
	m_current_selection2 = m_list_teams.GetCurSel();

	m_list_franchise.SetCurSel(current_selection);
	m_list_arena.SetCurSel(current_selection);
	m_list_teams.SetCurSel(current_selection);

	ListFranchiseProfile(true, true, current_selection, current_selection);

	((CEdit*) (GetDlgItem(IDC_EDIT_ARENA_NAME)))->SetFocus();	
}

void CFranchiseEdit::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	int current_selection = m_list_teams.GetCurSel();
	int city_selection = m_list_franchise.GetCurSel();
	int arena_selection = m_list_arena.GetCurSel();

	m_finance[city_selection].m_city_name = m_finance[current_selection].m_city_name;//city data changed / swapped
	m_finance[city_selection].m_competition = m_finance[current_selection].m_competition;//city data changed / swapped
	m_finance[city_selection].m_current_value  = m_finance[current_selection].m_current_value ;//city data changed / swapped
	m_finance[city_selection].m_competition = m_finance[current_selection].m_competition;//city data changed / swapped
	m_finance[city_selection].m_economy = m_finance[current_selection].m_economy;//city data changed / swapped
	m_finance[city_selection].m_fan_support = m_finance[current_selection].m_fan_support;//city data changed / swapped
	m_finance[city_selection].m_interest  = m_finance[current_selection].m_interest ;//city data changed / swapped
	m_finance[city_selection].m_competition = m_finance[current_selection].m_competition;//city data changed / swapped
	m_finance[city_selection].m_population = m_finance[current_selection].m_population;//city data changed / swapped

	m_finance[arena_selection].m_arena_name = m_finance[current_selection].m_arena_name;//arena data changed / swapped
	m_finance[arena_selection].m_stadium_value = m_finance[current_selection].m_stadium_value;//arena data changed / swapped
	m_finance[arena_selection].m_capacity  = m_finance[current_selection].m_capacity ;//arena data changed / swapped
	m_finance[arena_selection].m_club_seats = m_finance[current_selection].m_club_seats;//arena data changed / swapped
	m_finance[arena_selection].m_parking_spots = m_finance[current_selection].m_parking_spots;//arena data changed / swapped
	m_finance[arena_selection].m_suites = m_finance[current_selection].m_suites;//arena data changed / swapped
	m_finance[arena_selection].m_ticket_price = m_finance[current_selection].m_ticket_price;//arena data changed / swapped
	m_finance[arena_selection].m_club_price = m_finance[current_selection].m_club_price;//arena data changed / swapped
	m_finance[arena_selection].m_suite_price = m_finance[current_selection].m_suite_price;//arena data changed / swapped
	m_finance[arena_selection].m_concessions = m_finance[current_selection].m_concessions;//arena data changed / swapped
	UpdateFranchiseData(true, true,  current_selection, current_selection);
	ListFranchises();
	m_list_teams.SetCurSel(current_selection);
	m_list_franchise.SetCurSel(current_selection);
	m_list_arena.SetCurSel(current_selection);

	//CDialog::OnOK();
}
