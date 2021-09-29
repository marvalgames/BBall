// BudgetSheetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "BudgetSheetDlg.h"
#include "CityProfileDlg.h"

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
// CBudgetSheetDlg dialog


CBudgetSheetDlg::CBudgetSheetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBudgetSheetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBudgetSheetDlg)
	m_edit_ticket_price = 0;
	m_edit_suite_price = 0;
	m_edit_con_price = 0;
	m_edit_club_price = 0;
	//}}AFX_DATA_INIT
}


void CBudgetSheetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBudgetSheetDlg)
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDOK, m_edit_ok);
	DDX_Control(pDX, IDC_LIST_CONTROL_TEAMS, m_list_control);
	DDX_Control(pDX, IDC_LIST_STATS, m_list_stats);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_list_ctrl);
	DDX_Text(pDX, IDC_EDIT_TICKET_PRICE, m_edit_ticket_price);
	DDV_MinMaxUInt(pDX, m_edit_ticket_price, 5, 250);
	DDX_Text(pDX, IDC_EDIT_SUITE_PRICE, m_edit_suite_price);
	DDV_MinMaxUInt(pDX, m_edit_suite_price, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_CON_PRICE, m_edit_con_price);
	DDV_MinMaxUInt(pDX, m_edit_con_price, 5, 100);
	DDX_Text(pDX, IDC_EDIT_CLUB_PRICE, m_edit_club_price);
	DDV_MinMaxUInt(pDX, m_edit_club_price, 0, 500);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBudgetSheetDlg, CDialog)
	//{{AFX_MSG_MAP(CBudgetSheetDlg)
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTROL, OnDblclkListControl)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CONTROL, OnClickListControl)
	ON_BN_CLICKED(IDC_RADIO_EXPENSES, OnRadioExpenses)
	ON_BN_CLICKED(IDC_RADIO_REVENUES, OnRadioRevenues)
	ON_BN_CLICKED(IDC_RADIO_CITY, OnRadioCity)
	ON_BN_CLICKED(IDC_RADIO_ARENA, OnRadioArena)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL_TEAMS, OnSelchangeListControlTeams)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CONTROL, OnColumnclickListControl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBudgetSheetDlg message handlers

HBRUSH CBudgetSheetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CBudgetSheetDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_FINANCES_BUDGETSHEET);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/budgetsheet.htm", HH_DISPLAY_TOPIC, 0);
//	return TRUE;
	
}

BOOL CBudgetSheetDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_FINANCES_BUDGETSHEET);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/seasonawards.htm", HH_DISPLAY_TOPIC, 0);
//	HtmlHelp(NULL, "jumpshot.chm::/html/budgetsheet.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

BOOL CBudgetSheetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
myBrush.CreateSolidBrush(DLGCOLOR); 
	m_co = 0;
	CheckDlgButton(IDC_RADIO_EXPENSES, 1);	
	PassMembers();
	InitListCtrl();
	SetColumnHeaders();
	SetListBoxHeaders();
	ListControl();
	ListData();
	ListStats();
	ListEditableData();
//	if(m_ok == false)
//	{
//		m_edit_ok.EnableWindow(FALSE);
//		m_edit_ok.ShowWindow(FALSE);
//		m_button_cancel.SetWindowText("Exit");
//	}


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBudgetSheetDlg::InitListCtrl()
{
	m_current_choice = m_default_team;
	m_category = 1;

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_ctrl.SetBkColor(BK_COLOR);
	m_list_ctrl.SetTextBkColor(TEXT_BK_COLOR);

//	m_list_ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list_ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);

    m_list_ctrl.SetTextColor(RGB(0,0,0));
	m_list_ctrl.SetFont(&m_font);
//	m_list_ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_stats.SetBkColor(BK_COLOR);
	m_list_stats.SetTextBkColor(TEXT_BK_COLOR);

	m_list_stats.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    m_list_stats.SetTextColor(RGB(0,0,0));
	m_list_stats.SetFont(&m_font);
//	m_list_stats.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	InitLabels();

}

void CBudgetSheetDlg::SetColumnHeadersRevenues()
{

	m_list_ctrl.DeleteAllItems();





	m_list_ctrl.DeleteColumn(0);
//	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(2);
	m_list_ctrl.DeleteColumn(3);
	m_list_ctrl.DeleteColumn(4);
	m_list_ctrl.DeleteColumn(5);
	m_list_ctrl.DeleteColumn(6);
	m_list_ctrl.DeleteColumn(7);
	m_list_ctrl.DeleteColumn(8);
	m_list_ctrl.DeleteColumn(9);
	m_list_ctrl.DeleteColumn(10);
	m_list_ctrl.DeleteColumn(11);
	m_list_ctrl.DeleteColumn(12);
	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);



    m_list_ctrl.InsertColumn(0,"Team");    


	m_list_ctrl.DeleteColumn(1);
    m_list_ctrl.InsertColumn(1,"tick$");    
	m_list_ctrl.DeleteColumn(2);
    m_list_ctrl.InsertColumn(2,"att rev");    
	m_list_ctrl.DeleteColumn(3);
    m_list_ctrl.InsertColumn(3,"ste$");    
	m_list_ctrl.DeleteColumn(4);
    m_list_ctrl.InsertColumn(4,"suite");    
	m_list_ctrl.DeleteColumn(5);
    m_list_ctrl.InsertColumn(5,"clb$");    
	m_list_ctrl.DeleteColumn(6);
    m_list_ctrl.InsertColumn(6,"club");    
	m_list_ctrl.DeleteColumn(7);
    m_list_ctrl.InsertColumn(7,"con$");    
	m_list_ctrl.DeleteColumn(8);
    m_list_ctrl.InsertColumn(8,"concess");    
	m_list_ctrl.DeleteColumn(9);
    m_list_ctrl.InsertColumn(9,"park$");    
	m_list_ctrl.DeleteColumn(10);
    m_list_ctrl.InsertColumn(10,"park");    
	m_list_ctrl.DeleteColumn(11);
    m_list_ctrl.InsertColumn(11,"rev");    
	m_list_ctrl.DeleteColumn(12);
    m_list_ctrl.InsertColumn(12,"arena");    
	m_list_ctrl.DeleteColumn(13);
    m_list_ctrl.InsertColumn(13,"team");    
	m_list_ctrl.DeleteColumn(14);
    m_list_ctrl.InsertColumn(14,"profit");    
  
    m_list_ctrl.SetColumnWidth( 0, 45);
    m_list_ctrl.SetColumnWidth( 1, 44);
    m_list_ctrl.SetColumnWidth( 2, 44);
    m_list_ctrl.SetColumnWidth( 3, 44);
    m_list_ctrl.SetColumnWidth( 4, 44);
    m_list_ctrl.SetColumnWidth( 5, 44);
    m_list_ctrl.SetColumnWidth( 6, 44);
    m_list_ctrl.SetColumnWidth( 7, 44);
    m_list_ctrl.SetColumnWidth( 8, 44);
    m_list_ctrl.SetColumnWidth( 9, 44);
	m_list_ctrl.SetColumnWidth( 10,44);
    m_list_ctrl.SetColumnWidth( 11,44);
    m_list_ctrl.SetColumnWidth( 12, 37);
    m_list_ctrl.SetColumnWidth( 13, 37);
    m_list_ctrl.SetColumnWidth( 14, 44);



}

void CBudgetSheetDlg::ListData()
{
	m_list_ctrl.DeleteAllItems();
	int co = 0;
	for(int  i = 0; i <= 50; i++)
	{
		for(int  j = 0; j <= 25; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for(int  index = 0; index < m_number_teams; index++)
	{
		int i=index;
		CTeamFinancial fin = m_finance[index];
		CString Stats[33];
		
		Stats[0] = fin.m_team_name;

		if(Stats[0] == "") continue;
		double r = (double)fin.m_season_payroll/ 1000000;
		Stats[1].Format("%.2f", r);

		r = (double)fin.m_season_scout_expenses/ 1000000;
		Stats[2].Format("%.2f", r);

		r = (double)fin.m_season_coach_expenses/ 1000000;
		Stats[3].Format("%.2f", r);

		r = (double)fin.m_season_gm_expenses/ 1000000;
		Stats[4].Format("%.2f", r);

		r = (double)fin.m_season_operating_expenses/ 1000000;
		Stats[5].Format("%.2f", r);

		r = (double)fin.m_season_arena_expenses/ 1000000;
		Stats[6].Format("%.2f", r);

		r = (double)fin.m_season_marketing_expenses/ 1000000;
		Stats[7].Format("%.2f", r);

		r = (double)fin.m_season_total_expenses/ 1000000;
		Stats[8].Format("%.2f", r);


		r = ((double)fin.m_season_total_revenue - (double)fin.m_season_total_expenses) / 1000000;
		Stats[9].Format("%.2f", r);



		m_list_ctrl.InsertItem(co,Stats[0]);
		for(int s=0; s<=8; s++)
		{	
			m_list_ctrl.SetItemText(co,s+1,Stats[s+1]);
		}
		co = co + 1;
	}
	m_co = co;

	m_list_ctrl.SetItemState(m_current_choice, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(m_current_choice, TRUE);


}

void CBudgetSheetDlg::OnDblclkListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CCityProfileDlg* city = new CCityProfileDlg;
	for(int i=0; i<=199; i++)
	{
		city->m_finance[i] = m_finance[i];
	}
	city->m_finance[100] = m_finance[m_current_choice];
	city->m_finance[200] = m_finance[m_current_choice + 100];
	city->m_hi_games = m_hi_games;
	int result = city->DoModal();
	delete city;

	*pResult = 0;
}

void CBudgetSheetDlg::OnClickListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateFranchiseData();
	ClickListControlFunction();
	*pResult = 0;
}

void CBudgetSheetDlg::ListStats()
{
		m_list_stats.DeleteAllItems();
		int i = m_current_choice;
		CTeamFinancial fin = m_finance[i];
		CTeamFinancial fin_l = m_finance[i + 100];

		int orig = m_finance[i].m_original_slot;

		if(m_control[orig] == "Player")
		{
			GetDlgItem(IDC_EDIT_TICKET_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_SUITE_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CON_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CLUB_PRICE)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(IDC_EDIT_TICKET_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_SUITE_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CON_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CLUB_PRICE)->EnableWindow(FALSE);
		}


		CString Stats[33], Stats_l[33];
		CString Name;


		Stats[0] = fin.m_city_name;

		double exp = (double)fin.m_season_total_expenses / 1000000;
		double rev = (double)fin.m_season_total_revenue / 1000000;
		double pro = rev - exp;
		Stats[1].Format("%.2f", pro);


		double r = fin.m_current_value / 10;
		Stats[2].Format("%.f", r);

		r = fin.m_stadium_value;
		Stats[3].Format("%.f", r);

		r = (double)fin.m_season_payroll / 1000000;
		Stats[4].Format("%.2f", r);

		Stats[5].Format("%.2f", exp);

		Stats[6].Format("%.2f", rev);

		r = (double)fin.m_home_games;
		Stats[7].Format("%.f", r);


		int n = fin.m_fan_support;
		CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};


		Stats[8].Format("%s", lbl[n]);

//	    n = fin.m_ticket_price;
//		Stats[8].Format("%d", n);

		r = (double)fin.m_local_tv * (double)m_hi_games / 1000000;
		Stats[ 9].Format("%.2f", r);
	    r = (double)fin.m_local_radio * (double)m_hi_games / 1000000;
		Stats[10].Format("%.2f", r);
	    r = (double)fin.m_advertising * (double)m_hi_games / 1000000;
		Stats[11].Format("%.2f", r);
	    r = (double)fin.m_sponsorship * (double)m_hi_games / 1000000;
		Stats[12].Format("%.2f", r);

		r = (double)fin.m_arena * (double)m_hi_games / 10000;
		Stats[13].Format("%.2f", r);
	    r = (double)fin.m_marketing * (double)m_hi_games / 10000;
		Stats[14].Format("%.2f", r);


		exp = (double)fin_l.m_season_total_expenses / 1000000;
		rev = (double)fin_l.m_season_total_revenue / 1000000;
		pro = rev - exp;
		Stats_l[1].Format("%.2f", pro);

		r = fin_l.m_current_value / 10;
		Stats_l[2].Format("%.f", r);

		r = fin_l.m_stadium_value;
		Stats_l[3].Format("%.f", r);

		r = (double)fin_l.m_season_payroll/ 1000000;
		Stats_l[4].Format("%.2f", r);

		Stats_l[5].Format("%.2f", exp);

		Stats_l[6].Format("%.2f", rev);

		r = (double)fin_l.m_home_games;
		Stats_l[7].Format("%.f", r);

		n = fin_l.m_fan_support;
		Stats_l[8].Format("%s", lbl[n]);

//	    n = fin_l.m_ticket_price;
//		Stats_l[8].Format("%d", n);

		r = (double)fin_l.m_local_tv * (double)m_hi_games / 1000000;
		Stats_l[ 9].Format("%.2f", r);
	    r = (double)fin_l.m_local_radio * (double)m_hi_games / 1000000;
		Stats_l[10].Format("%.2f", r);
	    r = (double)fin_l.m_advertising * (double)m_hi_games / 1000000;
		Stats_l[11].Format("%.2f", r);
	    r = (double)fin_l.m_sponsorship * (double)m_hi_games / 1000000;
		Stats_l[12].Format("%.2f", r);

		r = (double)fin_l.m_arena * (double)m_hi_games / 10000;
		Stats_l[13].Format("%.2f", r);
	    r = (double)fin_l.m_marketing * (double)m_hi_games / 10000;
		Stats_l[14].Format("%.2f", r);




	for(int  index = 0; index <= 14; index++)
	{
		int i=index;
		if(Stats[index] == "") continue;
		m_list_stats.InsertItem(index, m_label[index]);
		m_list_stats.SetItemText(index, 1, Stats[index]);
		m_list_stats.SetItemText(index, 2, Stats_l[index]);
	}
}

void CBudgetSheetDlg::InitLabels()
{
	m_label[0] = "city";
	m_label[1] = "profit";
	m_label[2] = "team value";
	m_label[3] = "arena value";
	m_label[4] = "salaries";
	m_label[5] = "expenses";
	m_label[6] = "revenue";
	m_label[7] = "home games";
	m_label[8] = "fan support";
//_label[8] = "ticket price";
	m_label[9] = "local tv";
	m_label[10] = "local radio";
	m_label[11] = "arena advertising";
	m_label[12] = "arena sponsor";
	m_label[13] = "arena costs";
	m_label[14] = "marketing costs";

}

void CBudgetSheetDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateFranchiseData();

	CTeamFinancial* m_copy_finance = new CTeamFinancial[201];


	for(int i=0; i<=99; i++)
	{
		int orig = m_finance[i].m_original_slot;
		m_copy_finance[orig] = m_finance[i];		
	}

	CDisk* disk = new CDisk;
	CString file_name = m_path + m_league_name + ".frn";

	for(int i=0; i<=99; i++)
	{
		m_finance[i] = m_copy_finance[i];		
	}

	delete [] m_copy_finance;

//	UpdateFranchiseData();

	CDialog::OnOK();
}

void CBudgetSheetDlg::UpdateFranchiseData()
{
	UpdateData(TRUE);
	m_finance[m_current_choice].m_ticket_price = m_edit_ticket_price * 10;
	m_finance[m_current_choice].m_suite_price = m_edit_suite_price ; 
	m_finance[m_current_choice].m_concessions = m_edit_con_price * 10; 
	m_finance[m_current_choice].m_club_price = m_edit_club_price;
}

void CBudgetSheetDlg::ListEditableData()
{
	m_edit_ticket_price = m_finance[m_current_choice].m_ticket_price / 10;
	m_edit_suite_price = m_finance[m_current_choice].m_suite_price;
	m_edit_con_price = m_finance[m_current_choice].m_concessions / 10;
	m_edit_club_price = m_finance[m_current_choice].m_club_price;
	UpdateData(FALSE);
}

void CBudgetSheetDlg::OnRadioExpenses() 
{
	// TODO: Add your control notification handler code here
	if(m_category != 1)
	{
		m_category = 1;	
		SetColumnHeaders();
		ListData();
	}
}

void CBudgetSheetDlg::OnRadioRevenues() 
{
	// TODO: Add your control notification handler code here
	if(m_category != 2)
	{
		m_category = 2;	
		SetColumnHeadersRevenues();
		ListDataRevenue();
	}
	
}

void CBudgetSheetDlg::OnRadioCity() 
{
	// TODO: Add your control notification handler code here
	if(m_category != 4)
	{
		m_category = 4;	
		SetColumnHeadersCity();
		ListDataCity();
	}
}

void CBudgetSheetDlg::OnRadioArena() 
{
	// TODO: Add your control notification handler code here
	if(m_category != 3)
	{
		m_category = 3;	
		SetColumnHeadersArena();
		ListDataArena();
	}
}



void CBudgetSheetDlg::SetColumnHeadersCity()
{



	m_list_ctrl.DeleteAllItems();

	m_list_ctrl.DeleteColumn(0);
//	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(2);
	m_list_ctrl.DeleteColumn(3);
	m_list_ctrl.DeleteColumn(4);
	m_list_ctrl.DeleteColumn(5);
	m_list_ctrl.DeleteColumn(6);
	m_list_ctrl.DeleteColumn(7);
	m_list_ctrl.DeleteColumn(8);
	m_list_ctrl.DeleteColumn(9);
	m_list_ctrl.DeleteColumn(10);
	m_list_ctrl.DeleteColumn(11);
	m_list_ctrl.DeleteColumn(12);
	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);




    m_list_ctrl.InsertColumn(0,"Team");    

    m_list_ctrl.InsertColumn(1,"fan support");    
	m_list_ctrl.DeleteColumn(2);
    m_list_ctrl.InsertColumn(2,"population");    
	m_list_ctrl.DeleteColumn(3);
    m_list_ctrl.InsertColumn(3,"loyalty");    
	m_list_ctrl.DeleteColumn(4);
    m_list_ctrl.InsertColumn(4,"competition");    
	m_list_ctrl.DeleteColumn(5);
    m_list_ctrl.InsertColumn(5,"economy");    
	m_list_ctrl.DeleteColumn(6);
    m_list_ctrl.InsertColumn(6,"cost of living");    
	m_list_ctrl.DeleteColumn(7);
    m_list_ctrl.InsertColumn(7,"political support");    

	

	m_list_ctrl.SetColumnWidth( 0, 90);
    m_list_ctrl.SetColumnWidth( 1, 90);
	m_list_ctrl.SetColumnWidth( 2, 90);
    m_list_ctrl.SetColumnWidth( 3, 90);
	m_list_ctrl.SetColumnWidth( 4, 90);
    m_list_ctrl.SetColumnWidth( 5, 90);
	m_list_ctrl.SetColumnWidth( 6, 90);
    m_list_ctrl.SetColumnWidth( 7, 90);


//	m_list_ctrl.DeleteColumn(8);
//	m_list_ctrl.DeleteColumn(9);
//	m_list_ctrl.DeleteColumn(10);
//	m_list_ctrl.DeleteColumn(11);
//	m_list_ctrl.DeleteColumn(12);
//	m_list_ctrl.DeleteColumn(13);

}

void CBudgetSheetDlg::SetColumnHeaders()
{
	m_list_ctrl.DeleteAllItems();


//	m_list_ctrl.DeleteColumn(0);

	m_list_ctrl.DeleteColumn(0);
//	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(2);
	m_list_ctrl.DeleteColumn(3);
	m_list_ctrl.DeleteColumn(4);
	m_list_ctrl.DeleteColumn(5);
	m_list_ctrl.DeleteColumn(6);
	m_list_ctrl.DeleteColumn(7);
	m_list_ctrl.DeleteColumn(8);
	m_list_ctrl.DeleteColumn(9);
	m_list_ctrl.DeleteColumn(10);
	m_list_ctrl.DeleteColumn(11);
	m_list_ctrl.DeleteColumn(12);
	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);


    m_list_ctrl.InsertColumn(0,"Team");    


    m_list_ctrl.InsertColumn(1,"salary");    
	m_list_ctrl.DeleteColumn(2);
    m_list_ctrl.InsertColumn(2,"scout");    
	m_list_ctrl.DeleteColumn(3);
    m_list_ctrl.InsertColumn(3,"coach");    
	m_list_ctrl.DeleteColumn(4);
    m_list_ctrl.InsertColumn(4,"gm");    
	m_list_ctrl.DeleteColumn(5);
    m_list_ctrl.InsertColumn(5,"oper");    
	m_list_ctrl.DeleteColumn(6);
    m_list_ctrl.InsertColumn(6,"arena");    
	m_list_ctrl.DeleteColumn(7);
    m_list_ctrl.InsertColumn(7,"mark");    
	m_list_ctrl.DeleteColumn(8);
    m_list_ctrl.InsertColumn(8,"exp");    
	m_list_ctrl.DeleteColumn(9);
    m_list_ctrl.InsertColumn(9,"profit");    

  
    m_list_ctrl.SetColumnWidth( 0, 60);
    m_list_ctrl.SetColumnWidth( 1, 60);
    m_list_ctrl.SetColumnWidth( 2, 60);
    m_list_ctrl.SetColumnWidth( 3, 60);
    m_list_ctrl.SetColumnWidth( 4, 60);
    m_list_ctrl.SetColumnWidth( 5, 60);
    m_list_ctrl.SetColumnWidth( 6, 60);
    m_list_ctrl.SetColumnWidth( 7, 60);
    m_list_ctrl.SetColumnWidth( 8, 60);
    m_list_ctrl.SetColumnWidth( 9, 60);

	m_list_ctrl.DeleteColumn(10);
	m_list_ctrl.DeleteColumn(11);
	m_list_ctrl.DeleteColumn(12);
	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);


}

void CBudgetSheetDlg::SetColumnHeadersArena()
{
	m_list_ctrl.DeleteAllItems();

	m_list_ctrl.DeleteColumn(0);
//	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(1);
	m_list_ctrl.DeleteColumn(2);
	m_list_ctrl.DeleteColumn(3);
	m_list_ctrl.DeleteColumn(4);
	m_list_ctrl.DeleteColumn(5);
	m_list_ctrl.DeleteColumn(6);
	m_list_ctrl.DeleteColumn(7);
	m_list_ctrl.DeleteColumn(8);
	m_list_ctrl.DeleteColumn(9);
	m_list_ctrl.DeleteColumn(10);
	m_list_ctrl.DeleteColumn(11);
	m_list_ctrl.DeleteColumn(12);
	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);



//	m_list_ctrl.DeleteColumn(0);
    m_list_ctrl.InsertColumn(0,"Team");    
	m_list_ctrl.DeleteColumn(1);
    m_list_ctrl.InsertColumn(1,"cap");    
	m_list_ctrl.DeleteColumn(2);
    m_list_ctrl.InsertColumn(2,"attend");    
	m_list_ctrl.DeleteColumn(3);
    m_list_ctrl.InsertColumn(3,"att%");    
	m_list_ctrl.DeleteColumn(4);
    m_list_ctrl.InsertColumn(4,"#ste");    
	m_list_ctrl.DeleteColumn(5);
    m_list_ctrl.InsertColumn(5,"suites");    
	m_list_ctrl.DeleteColumn(6);
    m_list_ctrl.InsertColumn(6,"ste%");    
	m_list_ctrl.DeleteColumn(7);
    m_list_ctrl.InsertColumn(7,"#clb"); 
	m_list_ctrl.DeleteColumn(8);
    m_list_ctrl.InsertColumn(8,"club");    
	m_list_ctrl.DeleteColumn(9);
    m_list_ctrl.InsertColumn(9,"clb%");    
	m_list_ctrl.DeleteColumn(10);
    m_list_ctrl.InsertColumn(10,"#park");    
	m_list_ctrl.DeleteColumn(11);
    m_list_ctrl.InsertColumn(11,"park");    
	m_list_ctrl.DeleteColumn(12);
    m_list_ctrl.InsertColumn(12,"park%");    

  
    m_list_ctrl.SetColumnWidth( 0, 48);
    m_list_ctrl.SetColumnWidth( 1, 48);
    m_list_ctrl.SetColumnWidth( 2, 48);
    m_list_ctrl.SetColumnWidth( 3, 48);
    m_list_ctrl.SetColumnWidth( 4, 48);
    m_list_ctrl.SetColumnWidth( 5, 48);
    m_list_ctrl.SetColumnWidth( 6, 48);
    m_list_ctrl.SetColumnWidth( 7, 48);
    m_list_ctrl.SetColumnWidth( 8, 48);
    m_list_ctrl.SetColumnWidth( 9, 48);
    m_list_ctrl.SetColumnWidth(10, 48);
    m_list_ctrl.SetColumnWidth(11, 48);
    m_list_ctrl.SetColumnWidth(12, 48);

	m_list_ctrl.DeleteColumn(13);
	m_list_ctrl.DeleteColumn(14);
	m_list_ctrl.DeleteColumn(15);


}

void CBudgetSheetDlg::SetListBoxHeaders()
{
	m_list_stats.DeleteAllItems();


	m_list_stats.DeleteColumn(0);
    m_list_stats.InsertColumn(0,"");    
	m_list_stats.DeleteColumn(1);
    m_list_stats.InsertColumn(1,"current");    
	m_list_stats.DeleteColumn(2);
    m_list_stats.InsertColumn(2,"last");    
    m_list_stats.SetColumnWidth( 0, 80);
    m_list_stats.SetColumnWidth( 1, 80);
    m_list_stats.SetColumnWidth( 2, 80);

}

void CBudgetSheetDlg::ListDataArena()
{
	m_list_ctrl.DeleteAllItems();
	int co = 0;
	for(int  i = 0; i <= 50; i++)
	{
		for(int  j = 0; j <= 25; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for(int  index = 0; index < m_number_teams; index++)
	{
		int i=index;
		CTeamFinancial fin = m_finance[index];
		CString Stats[33];

		double g = (double)fin.m_home_games;
		if(g == 0) g = 1;
		Stats[0] = fin.m_team_name;

		if(Stats[0] == "") continue;

		double r = fin.m_capacity;
		Stats[1 ].Format("%.f", r);

		r = (fin.m_season_att + fin.m_season_suites_sold*20 + fin.m_season_clubs_sold) / g;
		Stats[2].Format("%.f", r);

		int pct = int((fin.m_season_att + fin.m_season_suites_sold*20 + fin.m_season_clubs_sold) / ((double)fin.m_capacity * g) * 1000);
		r = (double) pct / 10;
		Stats[3 ].Format("%.2f", r);

		r = fin.m_suites;
		Stats[4 ].Format("%.f", r);

		r = fin.m_season_suites_sold / g;
		Stats[5 ].Format("%.f", r);

		pct = int((double)fin.m_season_suites_sold / ((double)fin.m_suites * g) * 1000);
		r = (double) pct / 10;
		Stats[6 ].Format("%.2f", r);

		r = fin.m_club_seats;
		Stats[7 ].Format("%.f", r);

		r = fin.m_season_clubs_sold / g;
		Stats[8 ].Format("%.f", r);

		pct = int((double) fin.m_season_clubs_sold / ((double)fin.m_club_seats * g) * 1000);
		r = (double) pct / 10;
		Stats[9 ].Format("%.2f", r);

		int d = fin.m_parking_spots;
		Stats[10 ].Format("%d", d);

		if(fin.m_parking == 0) r = 0;
		else r = fin.m_season_parking_revenue / (double)fin.m_parking / g;
		Stats[11 ].Format("%.f", r);

		pct = int((double) fin.m_season_parking_revenue / (double) fin.m_parking / ((double)fin.m_parking_spots * g) * 1000);
		r = (double) pct / 10;
		Stats[12 ].Format("%.2f", r);	


		//r = fin.m_season_parking_sold / g;
		//Stats[11 ].Format("%.f", r);

		//pct = int((double) fin.m_season_parking_sold / ((double)fin.m_parking_spots * g) * 1000);
		//r = (double) pct / 10;
		//Stats[12 ].Format("%.2f", r);	


		m_list_ctrl.InsertItem(co,Stats[0]);
		for(int s=0; s<=11; s++)
		{	
			m_list_ctrl.SetItemText(co,s+1,Stats[s+1]);
		}
		co = co + 1;
	}
	m_co = co;

	m_list_ctrl.SetItemState(m_current_choice, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(m_current_choice, TRUE);
}

void CBudgetSheetDlg::ListDataCity()
{
	m_list_ctrl.DeleteAllItems();
	int co = 0;
	for(int  i = 0; i <= 50; i++)
	{
		for(int  j = 0; j <= 25; j++)
		{
			m_print_strings[i][j] = "";
		}
	}


	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};
	for(int  index = 0; index < m_number_teams; index++)
	{
		int i=index;
		CTeamFinancial fin = m_finance[index];
		CString Stats[33];
		
		Stats[0] = fin.m_team_name;

		if(Stats[0] == "") continue;
		int r = fin.m_fan_support;
		Stats[1].Format("%s", lbl[r]);

		r = fin.m_population;
		Stats[2].Format("%s", lbl[r]);

		r = fin.m_interest;
		Stats[3].Format("%s", lbl[r]);

		r = fin.m_competition;
		Stats[4].Format("%s", lbl[r]);

		r = fin.m_economy;
		Stats[5].Format("%s", lbl[r]);

		r = fin.m_cost_of_living;
		Stats[6].Format("%s", lbl[r]);

		r = fin.m_political_support;
		Stats[7].Format("%s", lbl[r]);


		m_list_ctrl.InsertItem(co,Stats[0]);
		for(int s=0; s<=6; s++)
		{	
			m_list_ctrl.SetItemText(co,s+1,Stats[s+1]);
		}
		co = co + 1;
	}
	m_co = co;

	m_list_ctrl.SetItemState(m_current_choice, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(m_current_choice, TRUE);
}

void CBudgetSheetDlg::ListDataRevenue()
{
	m_list_ctrl.DeleteAllItems();
	int co = 0;
	for(int  i = 0; i <= 50; i++)
	{
		for(int  j = 0; j <= 25; j++)
		{
			m_print_strings[i][j] = "";
		}
	}
	for(int  index = 0; index < m_number_teams; index++)
	{
		int i=index;
		CTeamFinancial fin = m_finance[index];
		CString Stats[33];
		
		Stats[0] = fin.m_team_name;

		if(Stats[0] == "") continue;

		double r = (double)fin.m_ticket_price / 10;
		Stats[1].Format("%.f", r);

		r = (double)fin.m_att_revenue/ 1000000;
		Stats[2].Format("%.2f", r);

		r = (double)fin.m_suite_price;
		Stats[3].Format("%.f", r);

		r = (double)fin.m_season_suite_revenue/ 1000000;
		Stats[4].Format("%.2f", r);

		r = (double)fin.m_club_price;
		Stats[5].Format("%.f", r);

		r = (double)fin.m_season_club_revenue/ 1000000;
		Stats[6].Format("%.2f", r);

		r = (double)fin.m_concessions / 10;
		Stats[7].Format("%.f", r);

		r = (double)fin.m_season_concession_revenue/ 1000000;
		Stats[8].Format("%.2f", r);

		r = (double)fin.m_parking;
		Stats[9].Format("%.f", r);

		r = (double)fin.m_season_parking_revenue/ 1000000;
		Stats[10].Format("%.2f", r);

		r = (double)fin.m_season_total_revenue / 1000000;
		Stats[11].Format("%.2f", r);

		r = (double)fin.m_stadium_value;
		Stats[12].Format("%.f", r);

		r = (double)fin.m_current_value / 10;
		Stats[13].Format("%.f", r);

		r = ((double)fin.m_season_total_revenue - (double)fin.m_season_total_expenses) / 1000000;
		Stats[14].Format("%.2f", r);


		m_list_ctrl.InsertItem(co,Stats[0]);
		for(int s=0; s<=13; s++)
		{	
			m_list_ctrl.SetItemText(co,s+1,Stats[s+1]);
		}
		co = co + 1;
	}
	m_co = co;

	m_list_ctrl.SetItemState(m_current_choice, LVIS_SELECTED,LVIS_SELECTED);
	m_list_ctrl.EnsureVisible(m_current_choice, TRUE);
}




void CBudgetSheetDlg::OnSelchangeListControlTeams() 
{
	// TODO: Add your control notification handler code here
	m_current_choice = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	

	int i = m_finance[m_current_choice].m_original_slot;

	if(m_control[i] == "Player")
		m_control[i] = "Computer";
	else if(m_control[i] == "Computer")
		m_control[i] = "Player";

	ListControl();
}

void CBudgetSheetDlg::ListControl()
{
	int i = m_finance[m_current_choice].m_original_slot;

	CString control = m_control[i];
	m_list_control.ResetContent();
	m_list_control.AddString(control);

		if(m_control[i] == "Player")
		{
			GetDlgItem(IDC_EDIT_TICKET_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_SUITE_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CON_PRICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CLUB_PRICE)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(IDC_EDIT_TICKET_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_SUITE_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CON_PRICE)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CLUB_PRICE)->EnableWindow(FALSE);
		}

}

void CBudgetSheetDlg::OnColumnclickListControl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;

	m_column = pNMListView->iSubItem;
	
	if(m_category == 1)
	{
		SortExpenses();
		ListData();
	}
	else if(m_category == 2)
	{
		SortRevenues();
		ListDataRevenue();
	}
	else if(m_category == 3)
	{
		SortArenas();
		ListDataArena();
	}
	else if(m_category == 4)
	{
		SortCities();
		ListDataCity();
	}
	ClickListControlFunction();
//	ListEditableData();
}

void CBudgetSheetDlg::SortExpenses()
{
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
		swap = m_i.m_team_name < m_j.m_team_name;
        break;
    case 1:
		swap = m_i.m_season_payroll > m_j.m_season_payroll;
        break;
    case 2:        
		swap = m_i.m_season_scout_expenses > m_j.m_season_scout_expenses;
        break;
    case 3:
		swap = m_i.m_season_coach_expenses > m_j.m_season_coach_expenses;
        break;
    case 4:
		swap = m_i.m_season_gm_expenses > m_j.m_season_gm_expenses;
        break;
    case 5:
		swap = m_i.m_season_operating_expenses > m_j.m_season_operating_expenses;
        break;
    case 6:
		swap = m_i.m_season_arena_expenses > m_j.m_season_arena_expenses;
        break;
    case 7:
		swap = m_i.m_season_marketing_expenses > m_j.m_season_marketing_expenses;
        break;
    case 8:
		swap = m_i.m_season_total_expenses > m_j.m_season_total_expenses;
        break;
    case 9:
		long f_i = m_i.m_season_total_revenue - m_i.m_season_total_expenses;
		long f_j = m_j.m_season_total_revenue - m_j.m_season_total_expenses;
		swap = f_i > f_j;
        break;
}



	if(swap == true)
	{//swap
		CTeamFinancial temp = m_finance[i];
		m_finance[i] = m_finance[j];
		m_finance[j] = temp;

		temp = m_finance[100+i];
		m_finance[100+i] = m_finance[100+j];
		m_finance[100+j] = temp;
	}
}

}

}

void CBudgetSheetDlg::SortRevenues()
{
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
		swap = m_i.m_team_name < m_j.m_team_name;
        break;
    case 1:
		swap = m_i.m_ticket_price > m_j.m_ticket_price;
        break;
    case 2:        
		swap = m_i.m_att_revenue > m_j.m_att_revenue;
        break;
    case 3:
		swap = m_i.m_suite_price > m_j.m_suite_price;
        break;
    case 4:
		swap = m_i.m_season_suite_revenue > m_j.m_season_suite_revenue;
        break;
    case 5:
		swap = m_i.m_club_price > m_j.m_club_price;
        break;
    case 6:
		swap = m_i.m_season_club_revenue > m_j.m_season_club_revenue;
        break;
    case 7:
		swap = m_i.m_concessions > m_j.m_concessions;
        break;
    case 8:
		swap = m_i.m_season_concession_revenue > m_j.m_season_concession_revenue;
        break;
    case 9:
		swap = m_i.m_parking > m_j.m_parking;
        break;
    case 10:
		swap = m_i.m_season_parking_revenue > m_j.m_season_parking_revenue;
        break;
    case 11:
		swap = m_i.m_season_total_revenue > m_j.m_season_total_revenue;
        break;
    case 12:
		swap = m_i.m_stadium_value > m_j.m_stadium_value;
        break;
    case 13:
		swap = m_i.m_current_value > m_j.m_current_value;
        break;
    case 14:
		long f_i = m_i.m_season_total_revenue - m_i.m_season_total_expenses;
		long f_j = m_j.m_season_total_revenue - m_j.m_season_total_expenses;
		swap = f_i > f_j;
        break;
}



	if(swap == true)
	{//swap
		CTeamFinancial temp = m_finance[i];
		m_finance[i] = m_finance[j];
		m_finance[j] = temp;
		temp = m_finance[100+i];
		m_finance[100+i] = m_finance[100+j];
		m_finance[100+j] = temp;
	}
}

}

}

void CBudgetSheetDlg::SortArenas()
{
CTeamFinancial m_i, m_j;

for(int i=0; i<m_number_teams; i++)
{
for(int j=0; j<m_number_teams; j++)
{

	bool swap = false;

	m_i = m_finance[i];
	m_j = m_finance[j];

	double g_i = (double)m_i.m_home_games;
	if(g_i == 0) g_i = 1;

	double g_j = (double)m_j.m_home_games;
	if(g_j == 0) g_j = 1;

		double r_i = (m_i.m_season_att + m_i.m_season_suites_sold*20 + m_i.m_season_clubs_sold) ;
		double r_j = (m_j.m_season_att + m_j.m_season_suites_sold*20 + m_j.m_season_clubs_sold) ;
		int p_i = int((m_i.m_season_att + m_i.m_season_suites_sold*20 + m_i.m_season_clubs_sold) / ((double)m_i.m_capacity * g_i) * 1000);
		int p_j = int((m_j.m_season_att + m_j.m_season_suites_sold*20 + m_j.m_season_clubs_sold) / ((double)m_j.m_capacity * g_j) * 1000);
		double f_i = (double)m_i.m_season_suites_sold / ((double)m_i.m_suites * g_i);
		double f_j = (double)m_j.m_season_suites_sold / ((double)m_j.m_suites * g_j);
		double cl_i = (double) m_i.m_season_clubs_sold / ((double)m_i.m_club_seats * g_i);
		double cl_j = (double) m_j.m_season_clubs_sold / ((double)m_j.m_club_seats * g_j);

		double pk_i = (double) m_i.m_season_parking_revenue / (double) m_i.m_parking / ((double)m_i.m_parking_spots * g_i);
		double pk_j = (double) m_j.m_season_parking_revenue / (double) m_j.m_parking / ((double)m_j.m_parking_spots * g_j);


switch(m_column) 
{

    case 0:
		swap = m_i.m_team_name < m_j.m_team_name;
        break;
    case 1:
		swap = m_i.m_capacity > m_j.m_capacity;
        break;
    case 2:        
		swap = r_i > r_j;
        break;
    case 3:
		swap = p_i > p_j;
        break;
    case 4:
		swap = m_i.m_suites > m_j.m_suites;
        break;
    case 5:
		swap = (m_i.m_season_suites_sold / g_i) > (m_j.m_season_suites_sold / g_j);
        break;
    case 6:
		swap = f_i > f_j;
        break;
    case 7:
		swap = m_i.m_club_seats > m_j.m_club_seats;
        break;
    case 8:
		swap = (m_i.m_season_clubs_sold / g_i) > (m_j.m_season_clubs_sold / g_j);
        break;
    case 9:
		swap = cl_i > cl_j;
        break;
    case 10:
		swap = m_i.m_parking_spots > m_j.m_parking_spots;
        break;
    case 11:
		swap = (m_i.m_season_parking_revenue / m_i.m_parking / g_i) > (m_j.m_season_parking_revenue / m_j.m_parking / g_j);
        break;
    case 12:
		swap = pk_i > pk_j;
        break;
}



	if(swap == true)
	{//swap
		CTeamFinancial temp = m_finance[i];
		m_finance[i] = m_finance[j];
		m_finance[j] = temp;
		temp = m_finance[100+i];
		m_finance[100+i] = m_finance[100+j];
		m_finance[100+j] = temp;
	}
}

}
}

void CBudgetSheetDlg::SortCities()
{

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
		swap = m_i.m_team_name < m_j.m_team_name;
        break;
    case 1:
		swap = m_i.m_fan_support > m_j.m_fan_support;
        break;
    case 2:        
		swap = m_i.m_population > m_j.m_population;
        break;
    case 3:
		swap = m_i.m_interest > m_j.m_interest;
        break;
    case 4:
		swap = m_i.m_competition > m_j.m_competition;
        break;
    case 5:
		swap = m_i.m_economy > m_j.m_economy;
        break;
    case 6:
		swap = m_i.m_cost_of_living > m_j.m_cost_of_living;
        break;
    case 7:
		swap = m_i.m_political_support > m_j.m_political_support;
        break;
}



	if(swap == true)
	{//swap
		CTeamFinancial temp = m_finance[i];
		m_finance[i] = m_finance[j];
		m_finance[j] = temp;
		temp = m_finance[100+i];
		m_finance[100+i] = m_finance[100+j];
		m_finance[100+j] = temp;
	}
}

}

}

void CBudgetSheetDlg::ClickListControlFunction()
{
	int choice = m_list_ctrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	

	if(choice >= 0) 
	{

		if(choice >= 0) 
		{
			m_current_choice = choice; 
			ListEditableData();
		}


		UpdateFranchiseData();

		if(choice >= 0) 
		{
			ListControl();
			ListStats();
		}
	}
}

void CBudgetSheetDlg::PassMembers()
{



}
