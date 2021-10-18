// FreeAgentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "FreeAgentDlg.h"
#include "HtmlMsc.h"
#include "PlayerCardDlg.h"
#include "NegotiateDlg.h"
#include "ImpExp.h"
//#include "Disk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFreeAgentDlg dialog


CFreeAgentDlg::CFreeAgentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFreeAgentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFreeAgentDlg)
	m_edit_cap = 0.0;
	//}}AFX_DATA_INIT
//	avg.m_finance = new CTeamFinancial[101];
//	m_record = new CRecord[33];
//	avg.m_owner = new CHireStaff[33];
//	avg.m_scout = new CStaff[33];
//	m_coach = new CStaff[33];
//	avg.m_gm = new CStaff[33];
	m_copy_actual = new CPlayer[1441];
//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));


}


void CFreeAgentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFreeAgentDlg)
	DDX_Control(pDX, IDC_BUTTON_TOGGLE, m_button_toggle);
	DDX_Control(pDX, IDC_BUTTON_EXPORT, m_button_export);
	DDX_Control(pDX, IDC_BUTTON_IMPORT, m_button_import);
	DDX_Control(pDX, IDC_BUTTON_FREE_AGENCY_PERIOD, m_button_free_agency_period);
	DDX_Control(pDX, IDC_BUTTON_SAVE_FA, m_button_save_fa);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, IDC_BUTTON_OFFER, m_button_offer);
	DDX_Control(pDX, IDC_BUTTON_SORT, m_button_sort);
	DDX_Control(pDX, IDC_BUTTON_HTML, m_btn[0]);
	DDX_Control(pDX, IDC_RADIO_SIGNED_PLAYERS, m_btn[1]);
	DDX_Control(pDX, IDC_RADIO_UNSIGNED_PLAYERS, m_btn[2]);
	DDX_Control(pDX, IDC_RADIO_ALL, m_btn[3]);
	DDX_Control(pDX, IDC_RADIO_FREE_AGENTS, m_btn[4]);
	//DDX_Control(pDX, IDC_RADIO_FREE_AGENTS, m_radio_free_agents);
	DDX_Control(pDX, IDC_RADIO_ALL_PLAYERS, m_btn[5]);
	DDX_Control(pDX, IDC_RADIO_PG, m_btn[6]);
	DDX_Control(pDX, IDC_RADIO_SG, m_btn[7]);
	DDX_Control(pDX, IDC_RADIO_SF, m_btn[8]);
	DDX_Control(pDX, IDC_RADIO_PF, m_btn[9]);
	DDX_Control(pDX, IDC_RADIO_C, m_btn[10]);
	DDX_Control(pDX, IDC_COMBO_LIST_TEAM_NAMES, m_list_team_names);
	DDX_Control(pDX, IDC_LIST_OFFERS, m_list_offers);
	DDX_Control(pDX, IDC_LIST_CAP, m_list_cap);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_LIST_SIGNINGS, m_list_signings);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_list_control);
	DDX_Control(pDX, IDC_LIST_FREE_AGENTS, m_list_free_agents);
	DDX_Text(pDX, IDC_EDIT_CAP, m_edit_cap);
	//}}AFX_DATA_MAP
}
//
//
//MyButton	m_button_toggle;
//MyButton	m_button_export;
//MyButton	m_button_import;
//MyButton	m_button_save_fa;
//MyButton	m_radio_free_agents;
//MyButton	m_radio_all_players;
//
//
//MyButton	m_button_offer;
//MyButton	m_button_free_agency_period;
//
//MyButton	m_button_sort;
//MyButton	m_cancel;
//MyButton	m_ok;
//MyButton	m_btn[11];



BEGIN_MESSAGE_MAP(CFreeAgentDlg, CDialog)
	//{{AFX_MSG_MAP(CFreeAgentDlg)
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_OFFER, OnButtonOffer)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_BN_CLICKED(IDC_BUTTON_FREE_AGENCY_PERIOD, OnButtonFreeAgencyPeriod)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_FREE_AGENTS, OnColumnclickListFreeAgents)
	ON_BN_CLICKED(IDC_RADIO_FREE_AGENTS, OnRadioFreeAgents)
	ON_BN_CLICKED(IDC_RADIO_ALL, OnRadioAll)
	ON_BN_CLICKED(IDC_RADIO_PG, OnRadioPg)
	ON_BN_CLICKED(IDC_RADIO_SF, OnRadioSf)
	ON_BN_CLICKED(IDC_RADIO_SG, OnRadioSg)
	ON_BN_CLICKED(IDC_RADIO_PF, OnRadioPf)
	ON_BN_CLICKED(IDC_RADIO_C, OnRadioC)
	ON_BN_CLICKED(IDC_RADIO_ALL_PLAYERS, OnRadioAllPlayers)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_RADIO_SIGNED_PLAYERS, OnRadioSignedPlayers)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_FREE_AGENTS, OnDblclkListFreeAgents)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SORT, OnButtonSort)
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAM_NAMES, OnSelchangeComboListTeamNames)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_FA, OnButtonSaveFa)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FREE_AGENTS, OnClickListFreeAgents)
	ON_BN_CLICKED(IDC_BUTTON_HTML, OnButtonHtml)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT, OnButtonExport)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImport)
	ON_LBN_SELCHANGE(IDC_LIST_OFFERS, OnSelchangeListOffers)
	ON_LBN_DBLCLK(IDC_LIST_OFFERS, OnDblclkListOffers)
	ON_BN_CLICKED(IDC_RADIO_UNSIGNED_PLAYERS, OnRadioUnsignedPlayers)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_TOGGLE, OnButtonToggle)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FREE_AGENTS, &CFreeAgentDlg::OnLvnItemchangedListFreeAgents)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFreeAgentDlg message handlers

BOOL CFreeAgentDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/afxc3ant.htm", HH_DISPLAY_TOPIC, 0);

	//HtmlHelp(NULL, "jumpshot.chm::/html/freeagency.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);


//html/afxc6bc5.htm

	return TRUE;	
}

BOOL CFreeAgentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_offer_list_count = 0;
	m_show_ratings = false;

	for(int j=0; j<=3000; j++)
	{
		m_offer_list[j].id = 0;
		m_offer_list[j].team_index = 0;
		m_offer_list[j].shown_id = 0;
	}

	m_players_listed = 0;
	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	m_edit_cap = (double)m_cap/100;
	m_display = true;
	m_ok.EnableWindow(FALSE);


	m_reset_signings = true;
	m_reset_list = true;		
	m_row = 0;
	m_category = 1;
	m_pos_category = 0;
	m_combo_index = 0;
	m_free_agency_started = false;
	m_free_agency_over = false;
	m_league_salary_cap = m_cap;
	for(int i=0; i<=1440; i++)
	{
		m_player_pointer[i] = i;
		avg.m_actual[i].m_accept_factor = 0;
		avg.m_actual[i].m_signed = false;

	}
	CheckDlgButton(IDC_RADIO_FREE_AGENTS, 1);	
	CheckDlgButton(IDC_RADIO_ALL_PLAYERS, 1);	

	if(m_signing_ok == false)
	{
		m_button_free_agency_period.EnableWindow(FALSE);
		m_button_offer.EnableWindow(FALSE);
		m_ok.EnableWindow(FALSE);

		m_button_free_agency_period.ShowWindow(FALSE);
		m_button_offer.ShowWindow(FALSE);
		m_button_import.ShowWindow(FALSE);
		m_button_export.ShowWindow(FALSE);
		m_button_save_fa.ShowWindow(FALSE);
		m_ok.ShowWindow(FALSE);

		SetWindowText("Free Agent Pool Preview");
		m_cancel.SetWindowText("Exit");
	}

	InitListCtrl();


	for(int t=1; t<=m_number_teams; t++)
	{

		avg.m_owner[t-1].m_mid_exception_used = false;
		avg.m_owner[t-1].m_mid_exception_offered = -1;
		avg.m_owner[t-1].m_million_exception_used = false;
		avg.m_owner[t-1].m_million_exception_offered = -1;
		avg.m_owner[t].m_offers_this_round = 0;


		avg.m_finance[t-1].SetEndOfSeasonSalaryCap(avg.m_owner[t-1].m_player_spending);
		avg.m_finance[t-1].m_owner_salary_cap = avg.m_finance[t-1].m_owner_salary_cap / 1000;
		if(m_check_finances_on == FALSE) 
			avg.m_finance[t-1].m_owner_salary_cap = 355000;

		long owner_cap = avg.m_finance[t-1].m_owner_salary_cap;
		avg.m_owner[t-1].SetLeagueSalaryCap(m_cap);
		avg.m_owner[t-1].SetOwnerSalaryCap(owner_cap);
	}

	if(m_signing_ok == true)
	{
		Retirements();
	}
	SetSeasonAverages();
	SetAdjustedRatings();
	InitVariables();
	AutoSignRookies(); 
	CalculateCurrentPayroll();
	InitPlayerRequests();
	SetColumns();
	OnButtonSort();
	//ListFreeAgents();

	CString capt;
	capt.Format("Ranked by %s staff",m_league_team_names[m_default_team]);
	m_button_sort.SetWindowText(capt);

	m_list_team_names.SetCurSel(m_default_team);

	//LoadFaOffers(false);
	ListTeamCap();
	ListControl();

	CString stri;
	stri.Format("Free Agency Stage - Stage %d", m_stage + 1);
	SetWindowText(stri);


	UpdateData(FALSE);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CFreeAgentDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
	

	
	
	
	
	
}

void CFreeAgentDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	// TODO: Add your message handler code here
	//WinHelp(HID_FINANCES_FREEAGENCY);		

	//HtmlHelp(NULL, "jumpshot.chm::/html/freeagency.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

void CFreeAgentDlg::InitListCtrl()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 16;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	LOGFONT lf0;                        // Used to create the CFont.
	memset(&lf0, 0, sizeof(LOGFONT));   // Clear out structure.
	lf0.lfWeight = 100;
	lf0.lfHeight = 10;
	strcpy_s(lf0.lfFaceName, "Arial");    //    with face name "Arial".
	m_fontHeader.CreateFontIndirect(&lf0);    // Create the font.


	m_list_free_agents.SetBkColor(BK_COLOR);
	m_list_free_agents.SetTextBkColor(BK_COLOR);
	//m_list_free_agents.SetHeaderFont(&m_fontHeader);

//	m_list_free_agents.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list_free_agents.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);

    m_list_free_agents.SetTextColor(RGB(0,0,0));
	m_list_free_agents.SetFont(&m_font);

	m_combo_teams.ResetContent();

	m_combo_teams.AddString(avg.m_settings.m_league_name);

	for(int i=0; i<=32; i++)
	{
		if(m_league_team_names[i] != "")
		{
			m_list_team_names.AddString(m_league_team_names[i]);
			m_combo_teams.AddString(m_league_team_names[i]);
		}
	}



	m_list_team_names.SetCurSel(m_row);
	m_combo_teams.SetCurSel(m_row);
	m_list_free_agents.SetItemState(m_row ,LVIS_SELECTED,LVIS_SELECTED);


	m_column_headers[0] = "pos";
	m_column_headers[1] = "Player";
	m_column_headers[2] = "yrs pro";
	m_column_headers[3] = "Bird";
	m_column_headers[4] = "contract yrs";
	m_column_headers[5] = "yrs left";
	m_column_headers[6] = "amt";
	m_column_headers[7] = "yrs sought";
	m_column_headers[8] = "amt";
	m_column_headers[9] = "yrs agreed";
	m_column_headers[10] = "amt";
	m_column_headers[11] = "status";
	m_column_headers[12] = "from";
  


	ListControl();
	EnableOfferButton();

}



void CFreeAgentDlg::ListFreeAgents()
{

	int ro = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);


	int co = 0;
	m_players_listed = 0;
	m_list_free_agents.DeleteAllItems();

	for(int i=0; i<=1440; i++)
	{
		m_player_pointer[i] = 0;
	}

for(int pl=0; pl<=1440; pl++)
{

	CString string[99];
	CPlayer m_player = avg.m_actual[pl];
	CString name = m_player.m_name;
	CString pos = m_player.m_pos;
	if(name == "" || pos == "") continue;

	string[2].Format("%d", m_player.m_contract_yrs);
	int yrs_remaining = m_player.m_contract_yrs - m_player.m_current_contract_yr + 1;
	string[3].Format("%d", yrs_remaining);
	string[4].Format("%.2f", (double)m_player.m_remaining_salary/100);


	if(m_player.m_just_signed == true)
	{
		string[3] = "";
		string[4] = "";
	}

	if(m_player.m_is_free_agent == false)
	{
		//string[2] = "";
		//string[3] = "";
		//string[4] = "";
		string[5] = "";
		string[6] = "";
	}
	else
	{
		string[5].Format("%d", m_player.m_qualifying_offer_years);
		string[6].Format("%.2f", (double)m_player.m_total_salary_seeking/100);
	}

	if(string[5] == "0"){ string[5] = ""; string[6] = "";}
	if(string[4] == "0.00"){ string[4] = ""; string[3] = ""; string[2] = "";}


	bool list = true;
	bool on_current_roster = false;
	int best_offer = m_player.m_current_team;
	CString offering_team;
	if(best_offer >= 0) offering_team = m_league_team_names[best_offer];

	string[9] = offering_team;

	if(m_player.m_is_free_agent == false)
	{
		string[7].Format("%d", m_player.m_contract_yrs);
		string[8].Format("%.2f", (double)m_player.m_total_salary/100);
		if(m_player.m_previous_team != best_offer)
		{
			avg.m_actual[pl].m_yrs_on_team = 0;
			m_player.m_yrs_on_team = 0;
		}
	}
	else if(m_player.m_is_free_agent == true)
	{
		string[9] = "unsigned";
	}
	//else if(m_player.m_is_free_agent == false)
	//{
	//	on_current_roster = true;
	//	string[9] = "signed";
	//}


	string[0].Format("%d", m_player.m_yrs_of_service);
	string[1].Format("%d", m_player.m_yrs_on_team);
	//check team selected
	int combo_index = m_combo_teams.GetCurSel();

	if(combo_index <= 0)
	{
		list = true;
		on_current_roster = true;
	}
	else if(m_category != 3)
	{
		int team_index = combo_index - 1;
		int team = m_player.m_previous_team;
		if(team_index != team) list = false;


		if(team_index == m_player.m_current_team && m_category == 2)  
		{
			list = true;
			on_current_roster = true;
		}
	}


	//check pos selected
	bool pos_ok = true;
	if( ((pos == "PG" && m_pos_category != 1) ||
		(pos == "SG" && m_pos_category != 2) ||
		(pos == "SF" && m_pos_category != 3) ||
		(pos == "PF" && m_pos_category != 4) ||
		(pos == " C" && m_pos_category != 5)) && m_pos_category != 0) pos_ok = false;
		
	//check if free agent or all players selected
	

	if(m_category == 1 && m_player.m_just_signed == true && on_current_roster == true)
		list = true;
	else if(m_category == 1 && m_player.m_end_season_fa == false)
		list = false;
	else if(m_category == 4 && m_player.m_just_signed == true && on_current_roster == true)
		list = false;
	else if(m_category == 4 && m_player.m_end_season_fa == false)
		list = false;
	else if(m_category == 3)
	{
		int combo_index = m_combo_teams.GetCurSel() - 1;
		if(combo_index < 0 && m_player.m_signed == true) list = true;
		else if(best_offer != combo_index || m_player.m_signed == false) list = false;
	}

	
	if(on_current_roster == false && m_category == 2) list = false;

if(list == true && pos_ok == true)
{
	if(m_player.m_previous_team >= 0) 
		string[10] = m_league_team_names[m_player.m_previous_team];

	if(string[9] == string[10]) string[10] = "";


	if(m_player.m_retired == true)
	{
		string[5] = "";
		string[6] = "retired";
	}


	if(m_show_ratings == false)
	{
		m_list_free_agents.InsertItem(co,pos);
		m_list_free_agents.SetItemText(co,1,name);

		for(int i=0; i<=10; i++)
		{
			m_list_free_agents.SetItemText(co,i+2,string[i]);
		}


	}
	else
	{
		//this instead of string[] crap eventhough this is stored above to lazy to do over

		CString Stats[99];
		Stats[1] = name;
		Stats[0] = pos;

		int r = m_player.GetAdjPrFga();
		Stats[2].Format("%d", r);


		r = m_player.GetAdjPrFgp();
		Stats[3].Format("%d", r);


	
		r = m_player.GetAdjPrFta();
		Stats[4].Format("%d", r);

		r = m_player.GetAdjPrFtp();
		Stats[5].Format("%d", r);


		r = m_player.GetAdjPrTga();
		Stats[6].Format("%d", r);


		r = m_player.GetAdjPrTgp();
		Stats[7].Format("%d", r);

	
		r = m_player.GetAdjPrOrb();
		Stats[8].Format("%d", r);

		r = m_player.GetAdjPrDrb();
		Stats[9].Format("%d", r);

		r = m_player.GetAdjPrAst();
		Stats[10].Format("%d", r);

		r = m_player.GetAdjPrStl();
		Stats[11].Format("%d", r);

		r = m_player.GetAdjPrTo();
		Stats[12].Format("%d", r);

		r = m_player.GetAdjPrBlk();
		Stats[13].Format("%d", r);

		int rating = m_player.GetMovOff();
		Stats[14].Format("%d", rating);

		rating = m_player.GetMovDef();
		Stats[18].Format("%d", rating);

		rating = m_player.GetPenOff();
		Stats[15].Format("%d", rating);

		rating = m_player.GetPenDef();
		Stats[19].Format("%d", rating);

		rating = m_player.GetPostOff();
		Stats[16].Format("%d", rating);

		rating = m_player.GetPostDef();
		Stats[20].Format("%d", rating);

		rating = m_player.GetTransOff();
		Stats[17].Format("%d", rating);

		rating = m_player.GetTransDef();
		Stats[21].Format("%d", rating);

		rating = m_player.GetAdjPot1();
		Stats[22].Format("%d", rating);

		rating = m_player.GetAdjPot2();
		Stats[23].Format("%d", rating);

		rating = m_player.GetAdjEffort();
		Stats[24].Format("%d", rating);

		m_list_free_agents.InsertItem(co,Stats[0]);
		for(int s=0; s<=23; s++)
		{	
			m_list_free_agents.SetItemText(co,s+1,Stats[s+1]);
		}

	}

		m_player_pointer[co] = pl;
		m_print_strings[co][0] = pos;
		m_print_strings[co][1] = name;




	BuildString(string, co, 33);
	co = co + 1;

}



}

	m_players_listed = co;




m_list_free_agents.SetItemState(ro ,LVIS_SELECTED,LVIS_SELECTED);
m_list_free_agents.EnsureVisible(ro, TRUE);

EnableOfferButton();

}


void CFreeAgentDlg::OnButtonOffer() 
{
	// TODO: Add your control notification handler code here
	int t = m_list_team_names.GetCurSel();
	m_row = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int pointer = m_player_pointer[m_row];
	CPlayer* m_player = new CPlayer;
	*m_player = avg.m_actual[pointer];
	
	
	if(avg.m_owner[t].m_offers_this_round == 0)
	{
		for(int i=0; i<=6; i++)
		{
			avg.m_owner[t].m_temp_payroll[i] = avg.m_owner[t].m_current_payroll[i];
		}	
	}
	
	
	CNegotiateDlg* neg = new CNegotiateDlg;
	neg->game_season = avg.m_sched.m_games_in_season;
	neg->m_tru = avg.m_avg_tru[0];
	neg->m_player_pointer = pointer;
	neg->m_pointer_id = m_player->m_id;
	neg->m_negotiate_extension = false;
	neg->m_coach_rating = 0;
	
	neg->m_cap = m_cap;
	neg->m_player = *m_player;
	neg->m_salary_cap = avg.m_finance[t].m_owner_salary_cap;

	neg->m_team_negotiating = t;
	neg->m_owner = avg.m_owner[t];
	neg->m_pointer = pointer;
	for(int i=0; i<=32; i++)
	{
		neg->m_league_team_names[i] = m_league_team_names[i];
	}

	neg->m_number_teams = avg.m_settings.m_numberteams;
	int result = neg->DoModal();

	if(result == IDOK)
	{

		int choice = pointer;

		bool qualify = true;
		//double number = (double) avg.m_actual[choice].m_seeking[t] * (1. - avg.m_actual[choice].m_accept_factor);
		double number = 0;
		if(neg->m_yr_salary[0] < number || (m_counter[t]) > 15 || avg.m_owner[t].m_offers_this_round >= 15) qualify = false;

			for(int i=0; i<=1440; i++)
			{


				if(avg.m_actual[i].m_signed == true || avg.m_owner[t].m_offers_this_round > 0) continue;
				avg.m_actual[i].m_top_offer[t] = false;
				avg.m_actual[i].m_year_offer[t] = 0;
				avg.m_actual[i].m_total_salary_offer[t] = 0;
				for(int j=0; j<=6; j++)
				{
					avg.m_actual[i].m_salary_offer[t][j] = 0;
				}
			
			}


		if(qualify == true)
		{

			avg.m_actual[choice].m_top_offer[t] = true;
			avg.m_actual[choice].m_year_offer[t] = neg->m_total_yrs;
			avg.m_actual[choice].m_total_salary_offer[t] = neg->m_total_salary;
			double ts = 0;
			avg.m_actual[choice].m_salary_offer[t][0] = 0;
			for(int j=0; j<=5; j++)
			{
				avg.m_actual[choice].m_salary_offer[t][j+1] = neg->m_yr_salary[j];
				ts = ts + (double)neg->m_yr_salary[j];
			}
			ts = ts / 100;
			avg.m_owner[t] = neg->m_owner;
			int off = avg.m_owner[t].m_offers_this_round + 1;
			avg.m_actual[choice].m_offer_slot[t] = off;
			for(int j=0; j<=5; j++)
			{
				avg.m_owner[t].m_top_free_agent_salaries[off][j+1] = neg->m_yr_salary[j];
			}
			avg.m_owner[t].m_top_free_agent_total_salary[off] = neg->m_total_salary;
			avg.m_owner[t].m_top_free_agent_years[off]  = neg->m_total_yrs;
			avg.m_owner[t].m_top_free_agent[off] = choice;
			avg.m_owner[t].m_mid_exception_offered = neg->m_owner.m_mid_exception_offered;
			avg.m_owner[t].m_million_exception_offered = neg->m_owner.m_million_exception_offered;


		}

			for(int j=0; j<=5; j++)
			{
				avg.m_owner[t].m_temp_payroll[j+1] = avg.m_owner[t].m_temp_payroll[j+1] + neg->m_yr_salary[j];
			}

			avg.m_owner[t].m_offers_this_round = avg.m_owner[t].m_offers_this_round + 1;

			CString str;
			CString na = avg.m_actual[pointer].m_name;
			str.Format("%s offer %s: %d year %.2f million", m_league_team_names[t], na, neg->m_total_yrs, (double)neg->m_total_salary/100);
			if(m_reset_list == true)
			{
				m_offer_list_count = 0;
				m_reset_list = false;
			}

			m_list_offers.AddString(str);
			int slot = m_list_offers.GetCount()-1;
			m_list_offers.SetCurSel(slot);
			m_offer_list[m_offer_list_count].id = avg.m_actual[pointer].m_id;
			m_offer_list[slot].shown_id = m_offer_list[m_offer_list_count].id;
			m_offer_list[m_offer_list_count].offer_string = str;
			m_offer_list[m_offer_list_count].team_index = t;
			m_offer_list_count = m_offer_list_count + 1;
		
	}
	else if(neg->m_offer_cleared == true)
	{
		avg.m_owner[t] = neg->m_owner;
		avg.m_actual[pointer] = neg->m_player;
		int off = avg.m_owner[t].m_offers_this_round;
	}

	delete neg;	
	delete m_player;

	CreateFaOffersString();
	FillOffersList();
	ListTeamCap();
}

//void CFreeAgentDlg::OnSelchangeListTeamNames() 
//{

	
//}

void CFreeAgentDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_list_team_names.GetCurSel();
	CString control = m_control[index];
	if(control == "Player") control = "Computer"; else if(control == "Computer") control = "Player";
	m_control[index] = control;
	ListControl();
	EnableOfferButton();		
}

void CFreeAgentDlg::ListControl()
{
	int index = m_list_team_names.GetCurSel();
	CString control = m_control[index];
	m_list_control.ResetContent();
	m_list_control.AddString(control);
}

void CFreeAgentDlg::EnableOfferButton()
{
	int t = m_list_team_names.GetCurSel();
	int i = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(m_row < 0) m_row = 0;

	int pointer = m_player_pointer[m_row];

	bool free =  avg.m_actual[pointer].m_is_free_agent;

	int best_offer = avg.m_actual[pointer].m_best_contract;

	//if(avg.m_actual[pointer].m_top_offer[best_offer] == true) free = false;

	if(m_control[t] == "Player" && i>=0 && m_free_agency_over == false && free == true) 
		m_button_offer.EnableWindow(TRUE);
	else
		m_button_offer.EnableWindow(FALSE);
}

void CFreeAgentDlg::InitVariables()
{




	m_resume_save = avg.FileExists(m_path + m_league_name + ".sav");

	m_count_signings = 0;
	m_stage = 0;
	m_button_save_fa.EnableWindow(FALSE);

	if(m_resume_save == true)
	{
		CString pFileName = m_path + m_league_name + ".sav";
  		CStdioFile file(pFileName, CFile::modeRead);
		CString st;
		file.ReadString(st);
		st.TrimRight();
		m_stage = atoi(st);
		for(int i = 1; i<=480; i++)
		{
			file.ReadString(m_string_load[i]);
			m_string_load[i].TrimRight();
			if(m_string_load[i] != "" && m_string_load[i] != " " && m_string_load[i] != "  ") m_count_signings = m_count_signings + 1;
			CString string = m_string_load[i];

		}
		
		file.Close();
		m_ok.EnableWindow(TRUE);
		m_button_save_fa.EnableWindow(TRUE);
		m_button_free_agency_period.SetWindowText("Continue Free Agency Period");
		m_free_agency_started = true;
		ListSignings();
	}
	
	

}

void CFreeAgentDlg::OnButtonFreeAgencyPeriod() 
{
	// TODO: Add your control notification handler code here
	m_ok.EnableWindow(TRUE);
	m_button_save_fa.EnableWindow(TRUE);
	m_stage = m_stage + 1;


	bool end = EndStage();
	CString stri;
	stri.Format("Free Agency Stage - Stage %d", m_stage + 1);
	SetWindowText(stri);

	if(end == true)
	{
		CString stri = "Free Agent Signings Completed";
		SetWindowText(stri);
		m_button_free_agency_period.SetWindowText("End Free Agency Period");
		m_button_free_agency_period.EnableWindow(FALSE);
		m_button_save_fa.EnableWindow(FALSE);
		m_free_agency_over = true;

	}
	else if(m_free_agency_started == false)
	{
		m_button_free_agency_period.SetWindowText("Continue Free Agency Period");
		m_free_agency_started = true;

	}

	InitGmOffers();
	ListFreeAgents();
	ListTeamCap();


//	if(m_stage <= m_stop_loading) m_reset_list = false;
	//m_reset_list = true;

	int count = m_list_signings.GetCount() - 1;
	if(count >= 0) m_list_signings.SetCurSel(count);

	if(end == true)
	{
		CString stri = "Free Agent Signings Completed";
		SetWindowText(stri);
	}



}

void CFreeAgentDlg::InitPlayerRequests()
{
	int co = 0;

	int franchise_win[33], franchise_loss[33];
	double pos_value[33][6];
	double avg_pv[6] = {0,0,0,0,0,0};
	double t_pv[6] = {0,0,0,0,0,0};

	for(int t=0; t<=32; t++)
	{
		avg.m_owner[t].SetPositionValues(avg.m_actual, (t)*30+1, avg.m_coach[t]);
		franchise_win[t] = 0;
		franchise_loss[t] = 0;
		franchise_win[t] = avg.m_owner[t].m_win;
		franchise_loss[t] = avg.m_owner[t].m_loss;
	

		for(int i=1; i<=5; i++)
		{
			pos_value[t][i] = avg.m_owner[t].m_position_values[i];
			t_pv[i] = t_pv[i] + avg.m_owner[t].m_position_values[i];
		}

	}

	for(int i=1; i<=5; i++)
	{
		avg_pv[i] = t_pv[i] / m_number_teams;
	}



for(int pl=0; pl<=1440; pl++)
{
	avg.m_actual[pl].m_player_pointer = pl;
	avg.m_actual[pl].m_end_season_fa = 	avg.m_actual[pl].m_is_free_agent;
	CPlayer m_player = avg.m_actual[pl];
	m_copy_actual[pl] = m_player;//copy presorted original data
	CString name = m_player.m_name;
	if(name == "") continue;

	if(m_player.m_is_free_agent == true)
	{
		m_player.m_current_team = -1;
		m_player.SetTrueRating(avg.m_avg_tru[0], true);
		m_player.SetRequests(franchise_win, franchise_loss, avg.m_standings, avg.m_coach, avg_pv, pos_value);
	}
		
	avg.m_actual[pl] = m_player;
	
}


}

void CFreeAgentDlg::InitGmOffers()
{
	if(m_reset_list == true)
	{
		m_reset_list = false;
		m_list_offers.ResetContent();
		m_offer_list_count = 0;
		m_list_signings.ResetContent();
	}


	
	





		bool over = true;
		for(int t=1; t<=m_number_teams; t++)
		{


		if(m_control[t-1] == "Player") continue;

		long owner_cap = avg.m_finance[t-1].m_owner_salary_cap;
		if(owner_cap > m_league_salary_cap) owner_cap = m_league_salary_cap;
		if(avg.m_owner[t-1].m_current_payroll[1] < m_league_salary_cap) over = false;


		for(int i=0; i<=1440; i++)
		{
			avg.m_actual[i].m_top_offer[t-1] = false;
			avg.m_actual[i].m_year_offer[t-1] = 0;
			avg.m_actual[i].m_total_salary_offer[t-1] = 0;
			for(int j=0; j<=6; j++)
			{
				avg.m_actual[i].m_salary_offer[t-1][j] = 0;
			}
		}

	}

	CProgressDlg dlgProgress, dlgProgress1;
 	dlgProgress.m_text = "Making Offers";
    dlgProgress.Create(IDD_PROGRESSDLG,NULL);        // change these parameters
	dlgProgress.ShowWindow(SW_SHOW);     
	dlgProgress.m_progress.SetRange(1, m_number_teams);



	for(int t=1; t<=m_number_teams; t++)
	{
		dlgProgress.m_progress.SetPos(t);

		if(m_control[t-1] == "Player") continue;
		if(m_counter[t-1] >= m_count) continue;

		long owner_cap = avg.m_finance[t-1].m_owner_salary_cap;
		avg.m_owner[t-1].SetLeagueSalaryCap(m_cap);
		int choice = 0;
		
	



		avg.m_owner[t-1].m_million_exception_offered = -1;
		avg.m_owner[t-1].m_mid_exception_offered = -1;


		for(int i=0; i<=6; i++)
		{
			avg.m_owner[t-1].m_temp_payroll[i] = avg.m_owner[t-1].m_current_payroll[i];
		}	

		avg.m_owner[t-1].m_signed_players = m_counter[t-1];
		avg.m_owner[t-1].SetTopFreeAgent(avg.m_actual, avg.m_scout[t-1], avg.m_coach[t-1], avg.m_gm[t-1], t-1, m_stage);



		int off = avg.m_owner[t-1].m_offers_this_round;

		for(int ch=1; ch<=off; ch++)
		{
		
		int choice = avg.m_owner[t-1].m_top_free_agent[ch];

		if(choice < 0) continue;

		avg.m_actual[choice].m_top_offer[t-1] = true;
				
		avg.m_actual[choice].m_year_offer[t-1] = avg.m_owner[t-1].m_top_free_agent_years[ch];
		avg.m_actual[choice].m_total_salary_offer[t-1] = avg.m_owner[t-1].m_top_free_agent_total_salary[ch];
		double ts = 0;
		for(int j=0; j<=6; j++)
		{
			avg.m_actual[choice].m_salary_offer[t-1][j] = avg.m_owner[t-1].m_top_free_agent_salaries[ch][j];
			ts = ts + (double)avg.m_actual[choice].m_salary_offer[t-1][j];
		
		}

		
			ts = ts / 100;
			CString str;
			CString na = avg.m_actual[choice].GetName();
			str.Format("%s offer: %s %d year %.2f million", m_league_team_names[t-1], na, avg.m_actual[choice].m_year_offer[t-1], ts);
			if(m_reset_list == true)
			{
				m_list_offers.ResetContent();
				m_offer_list_count = 0;
				m_reset_list = false;
			}
			
			

			m_offer_list[m_offer_list_count].id = avg.m_actual[choice].m_id;
			m_offer_list[m_offer_list_count].offer_string = str;
			m_offer_list[m_offer_list_count].team_index = t-1;
			m_offer_list_count = m_offer_list_count + 1;

				
			//m_list_offers.AddString(str);
			//m_list_offers.SetCurSel(m_list_offers.GetCount()-1);
		}

	
	}

//	FillOffersList();




	for(int t=1; t<=m_number_teams; t++)
	{
		if(m_control[t-1] == "Player") continue;
		avg.m_owner[t-1].m_offers_this_round = 0;
	}




 	dlgProgress1.m_text = "Players Deciding";
    dlgProgress1.Create(IDD_PROGRESSDLG,NULL);        // change these parameters
	dlgProgress1.ShowWindow(SW_SHOW);     
	dlgProgress1.m_progress.SetRange(1, 1440);


	for(int i=0; i<=1440; i++)
	{

		dlgProgress1.m_progress.SetPos(i);

		avg.m_actual[i].ChooseBestContract(m_counter, m_count);
		int best_offer = avg.m_actual[i].m_best_contract;
		avg.m_actual[i].m_accept_factor = avg.m_actual[i].m_accept_factor + .1;
		if(avg.m_actual[i].m_accept_factor > 1) avg.m_actual[i].m_accept_factor = 1;

		if(avg.m_actual[i].m_is_free_agent == false ||
			m_counter[best_offer] >= m_count || best_offer == -1) continue;

		int item = 0;

		int yrs = avg.m_actual[i].m_yrs_of_service;
		CPlayer m_player = avg.m_actual[i];
		int cap[33], fav[33];
		for(int j=0; j<=32; j++)
		{
			cap[j] = avg.m_owner[j].m_temp_payroll[0];
			fav[j] = 0;
		}
		bool accept = false;
//		if(avg.m_actual[i].m_rookie == false)
		

		accept = avg.m_actual[i].AcceptOffer(m_stage, cap, m_number_teams, m_cap, fav, avg.m_avg_trade_tru[0]*2);
		if(accept == true)
		{
			if(avg.m_actual[i].m_content < 9)
				avg.m_actual[i].m_content = avg.m_actual[i].m_content + 1;
			//erases player team pending bid
			for(int x=0; x<=32; x++)
			{
				int off = avg.m_actual[i].m_offer_slot[x];				
				if(off > 0 && x != best_offer)
				{
					for(int y=0; y<=6; y++)
					{
						avg.m_owner[x].m_temp_payroll[y] =
							avg.m_owner[x].m_temp_payroll[y] - avg.m_owner[x].m_top_free_agent_salaries[off][y];
						//if(avg.m_owner[x].m_current_payroll[y] > avg.m_owner[x].m_temp_payroll[y])
						//	avg.m_owner[x].m_temp_payroll[y] = avg.m_owner[x].m_current_payroll[y];
					}
				}
			}	


				if(avg.m_owner[best_offer].m_mid_exception_offered == avg.m_actual[i].m_id)
					avg.m_owner[best_offer].m_mid_exception_used = true;
				if(avg.m_owner[best_offer].m_million_exception_offered == avg.m_actual[i].m_id)
					avg.m_owner[best_offer].m_million_exception_used = true;


			//erases mid ex offered and min ex offered	
			for(int x=0; x<=32; x++)
			{
				if(avg.m_owner[x].m_mid_exception_offered == avg.m_actual[i].m_id)
					avg.m_owner[x].m_mid_exception_offered = -1;
				if(avg.m_owner[x].m_million_exception_offered == avg.m_actual[i].m_id)
					avg.m_owner[x].m_million_exception_offered = -1;
			}

			avg.m_actual[i].m_signed = true;//if listed then player permanently signed
			avg.m_actual[i].m_current_team = best_offer;//if listed then player permanently signed
			avg.m_actual[i].InkedNewDeal(best_offer);


			AdjustSalaryCap(best_offer, i);
//			if(m_resume_save != true )
//			{
//			}

		
			//adjust position values after signing players (might want to add to a class)

			CString pos = avg.m_actual[i].m_pos;

			avg.m_actual[i].SetAdjTrueRatingSimple(avg.m_actual[i].GetFgm(), avg.m_actual[i].GetFga(), avg.m_actual[i].GetTfgm(), avg.m_actual[i].GetTfga(), avg.m_actual[i].GetFtm(),  avg.m_actual[i].GetFta(), avg.m_actual[i].GetOreb(),  avg.m_actual[i].GetReb(), avg.m_actual[i].GetAst(), avg.m_actual[i].GetStl(), avg.m_actual[i].GetTo(), avg.m_actual[i].GetBlk(), avg.m_coach[best_offer].m_scoring, avg.m_coach[best_offer].m_shooting, avg.m_coach[best_offer].m_rebounding, avg.m_coach[best_offer].m_passing, avg.m_coach[best_offer].m_defense);
			avg.m_actual[i].SetTradeTrueRating(0);
			avg.m_actual[i].SetAdjTradeValue(avg.m_coach[best_offer].m_pot1, avg.m_coach[best_offer].m_pot2, avg.m_coach[best_offer].m_effort);
			int value = 0;
			if(pos == "PG") value = 1;
			else if(pos == "SG") value = 2;
			else if(pos == "SF") value = 3;
			else if(pos == "PF") value = 4;
			else if(pos == " C") value = 5;
			avg.m_owner[best_offer].m_position_values[value] =
				avg.m_owner[best_offer].m_position_values[value] + avg.m_actual[i].GetTradeTrueRating(TRUE); 

			CString cont;
			int cn = avg.m_actual[i].m_best_contract;
			int ye = avg.m_actual[i].m_year_offer[cn];
			double ts = (double)avg.m_actual[i].m_total_salary_offer[cn] / 100;
			cont.Format("%s, %s, %d year %.2f million", avg.m_actual[i].GetName(), m_league_team_names[cn], ye, ts);
			
			CreateFaSaveString(m_stage, avg.m_actual[i]);
		
			AdjustPlayerRequests();

			m_list_signings.AddString(cont);

				avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;


				CString string;
				int mo = 13;
				int da = 32;
				int yr = avg.m_settings.m_currentYear;
				int ty = 6;
				int team = cn + 1;
				int id = avg.m_actual[i].m_id;
				int yr_ex = avg.m_actual[i].m_contract_yrs;
				int sa_ex = avg.m_actual[i].m_remaining_salary;

				string.Format("%2d%2d%4d%2d%2d%6d%d%5d", mo, da, yr, ty, team, id, yr_ex, sa_ex);                          			
				avg.m_trans_str[avg.m_settings.m_number_transactions] = string;


			int off = avg.m_owner[cn].m_offers_this_round;
			for(int co=1; co<=off; co++)
			{
				int selection = avg.m_owner[cn].m_top_free_agent[co];
				if(selection >= 1)
				{
					if(avg.m_actual[selection].m_id >= 0 && selection != i)
						avg.m_owner[cn].CheckOffers(co, cn, avg.m_actual[selection].m_id, avg.m_actual[selection]);
				}
			}

			
		}	

//		avg.m_actual[i].m_best_contract = -1;


	}

	FillOffersList();

}

bool CFreeAgentDlg::EndStage()
{

	for(int i=0; i<=32; i++)
	{
		m_counter[i] = 0;
	}

	for(int i=0; i<=1440; i++)		
	{
		int team = avg.m_actual[i].m_current_team;
		CString name = avg.m_actual[i].m_name;
		int pointer = avg.m_actual[i].m_player_pointer;
		if(name == "" || pointer == 0) continue;//what about unsigned free agents (team == -1 put back in?)
		if(team != -1)
		{
			m_counter[team] = m_counter[team] + 1;
		}
	}		

	bool end = true;
	bool all_human = true;

	for(int t=0; t<m_number_teams; t++)
	{
		if(m_control[t] != "Player") all_human = false;
		if(m_counter[t] < m_count && m_control[t] != "Player") end = false;
	}

	if(all_human == true)
	{
		end = true;
		for(int t=0; t<m_number_teams; t++)
		{
			if(m_counter[t] < (m_count-1) ) end = false;
		}
	}
		

	if(m_stage >= 12) end = true;

	return end;

}


void CFreeAgentDlg::SetCampRosters()
{
CPlayer* m_save_actual = new CPlayer[1441];


	int counter[33];
	for(int i=0; i<=32; i++)
	{
		counter[i] = 0;
	}
	int fa_offset = 961;

		
	for(int i=0; i<=1440; i++)		
	{
		int team = avg.m_actual[i].m_current_team;
		if(m_free_agency_over == false && team == -1 && avg.m_actual[i].m_is_free_agent == 
			true) team = avg.m_actual[i].m_previous_team;
		CString name = avg.m_actual[i].m_name;
		int pointer = avg.m_actual[i].m_player_pointer;



		if(team == -1 && fa_offset <= 1440 && name != "" && pointer > 0)//what about unsigned free agents 
		{
			m_save_actual[fa_offset] = avg.m_actual[i];
			fa_offset = fa_offset + 1;
		}
		else if(name != "" && pointer >= 0 && team <= 32 && team >= 0)
		{
			counter[team] = counter[team] + 1;
			int offset = team*30 + counter[team];
 			m_save_actual[offset] = avg.m_actual[i];
			m_save_actual[offset].m_team_paying = team + 1;
			m_save_actual[offset].m_team_index = team + 1;
		}
	}		

	for(int i=0; i<=1440; i++)
	{
		avg.m_actual[i] = m_save_actual[i];
	}		

delete [] m_save_actual;
}

void CFreeAgentDlg::WriteCampRosters()//rewrite (written after rookie draft)
{
	CString title = m_path + m_league_name + ".sav";
	CFile fil;
	CFileStatus status;
	if( CFile::GetStatus( title, status )) fil.Remove(title);
}




void CFreeAgentDlg::CalculateCurrentPayroll()
{
	
	int f = 30;

	for(int t=0; t<=32; t++)
	{
		avg.m_owner[t].CurrentPayroll(avg.m_actual, t*f+1, m_signing_ok);
	}

	
}

void CFreeAgentDlg::AdjustSalaryCap(int best_offer, int pl)
{
	int total[7] = {0,0,0,0,0,0,0};
	int yr = avg.m_actual[pl].m_year_offer[best_offer];

	for(int y=0; y<=6; y++)
	{
		total[y] = total[y] + avg.m_actual[pl].m_salary_offer[best_offer][y];
		avg.m_actual[pl].m_new_contract_salaries[y] = 0;
		avg.m_actual[pl].m_new_contract_salaries[y] = avg.m_actual[pl].m_salary_offer[best_offer][y];
	}

	avg.m_actual[pl].InkedNewDeal(best_offer);

	for(int y=0; y<=6; y++)
	{
		avg.m_owner[best_offer].m_current_payroll[y] = avg.m_owner[best_offer].m_current_payroll[y] + total[y];
	}
}

void CFreeAgentDlg::AutoSignRookies()
{
	for(int i=1; i<=960; i++)
	{
		if(avg.m_actual[i].m_rookie == true || (avg.m_actual[i].m_yrs_of_service == 0 && avg.m_actual[i].m_round_selected > 0))
		{
			int team = (i-1)/30;
			avg.m_actual[i].SetRookieContract(avg.m_actual[i], team, m_number_teams);
		}
	}

}

void CFreeAgentDlg::WriteUpdatedContracts()//write contracts to salary file after FA is completed
{
//	CDisk* disk = new CDisk;
//	CString file_name = m_path + m_league_name + ".sal";
	for(int i=0; i<=1440; i++)
	{
		int best = avg.m_actual[i].m_best_contract;
		avg.m_actual[i].UpdateContracts(best);
//		disk->avg.m_actual[i] = avg.m_actual[i];
	}

//	double tru_factor = 1;
//	disk->WriteCareerContractFile(file_name, tru_factor);
//	disk->IncreaseFileSize(file_name, 50000);
//	delete disk;
}

void CFreeAgentDlg::OnColumnclickListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_column = pNMListView->iSubItem;

	SortColumns();

	m_list_row = 0;
	m_list_free_agents.SetItemState(m_list_row ,LVIS_SELECTED,LVIS_SELECTED);
	m_list_free_agents.EnsureVisible(m_list_row, TRUE);
	
	*pResult = 0;
}

void CFreeAgentDlg::SortColumns()
{
	m_list_free_agents.DeleteAllItems();
	QuickSort();
	ListFreeAgents();
}


void CFreeAgentDlg::OnRadioFreeAgents() 
{
	// TODO: Add your control notification handler code here
	m_category = 1;
	ListFreeAgents();
	
}

void CFreeAgentDlg::OnRadioAll() 
{
	// TODO: Add your control notification handler code here
	m_category = 2;
	ListFreeAgents();
}

void CFreeAgentDlg::OnRadioPg() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 1;
	ListFreeAgents();
		
}

void CFreeAgentDlg::OnRadioSf() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 3;
	ListFreeAgents();

}

void CFreeAgentDlg::OnRadioSg() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 2;
	ListFreeAgents();
	
}

void CFreeAgentDlg::OnRadioPf() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 4;
	ListFreeAgents();
	
}

void CFreeAgentDlg::OnRadioC() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 5;	
	ListFreeAgents();
}

void CFreeAgentDlg::OnRadioAllPlayers() 
{
	// TODO: Add your control notification handler code here
	m_pos_category = 0;		
	ListFreeAgents();
}

void CFreeAgentDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	m_combo_index = m_combo_teams.GetCurSel();	
	


	ListFreeAgents();
}

void CFreeAgentDlg::OnRadioSignedPlayers() 
{
	// TODO: Add your control notification handler code here
	m_category = 3;
	ListFreeAgents();
	
}


void CFreeAgentDlg::QuickSort ()
{

	int initial_increment = 4;
    int i=0, j=0;
	CPlayer temp;
    int inc = initial_increment;

    while ( inc > 0) 
	{
      for (i=0; i <= 1440; i++)
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
}

bool CFreeAgentDlg::SortFunction(CPlayer m_contract_i, CPlayer m_contract_j)
{

	int team = m_list_team_names.GetCurSel();

	bool swap = false;

	if(m_show_ratings == false)
	{

	m_contract_i.SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);
	double tru1 = m_contract_i.GetTradeValue();
	double tru2 = m_contract_j.GetTradeValue();
	m_contract_i.SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);
	double tru3 = m_contract_i.GetTradeValue();
	double tru4 = m_contract_j.GetTradeValue();
	m_contract_i.SetAdjTradeValue(avg.m_gm[team].m_pot1, avg.m_gm[team].m_pot2, avg.m_gm[team].m_effort);
	m_contract_j.SetAdjTradeValue(avg.m_gm[team].m_pot1, avg.m_gm[team].m_pot2, avg.m_gm[team].m_effort);
	double tru5 = m_contract_i.GetTradeValue();
	double tru6 = m_contract_j.GetTradeValue();

	tru1 = tru1 + tru3 + tru5;
	tru2 = tru2 + tru4 + tru6;

	switch(m_column) 
	{



	case 0:

		swap = m_contract_i.m_pos > m_contract_j.m_pos;
	    break;
    case 1:
		swap = m_contract_i.m_name > m_contract_j.m_name;
        break;
    case 2:
		swap = m_contract_i.m_yrs_of_service < m_contract_j.m_yrs_of_service;
        break;
    case 3:        
		swap = m_contract_i.m_yrs_on_team < m_contract_j.m_yrs_on_team;
        break;
    case 4:
		swap = m_contract_i.m_contract_yrs < m_contract_j.m_contract_yrs;
        break;
    case 5:
		swap = (m_contract_i.m_contract_yrs - m_contract_i.m_current_contract_yr + 1) <
			(m_contract_j.m_contract_yrs - m_contract_j.m_current_contract_yr + 1);
        break;
    case 6:
		swap = m_contract_i.m_total_salary < m_contract_j.m_total_salary;
        break;
    case 7:
		swap = m_contract_i.m_qualifying_offer_years < m_contract_j.m_qualifying_offer_years;
        break;
    case 8:
		swap = m_contract_i.m_total_salary_seeking < m_contract_j.m_total_salary_seeking;
        break;
    case 9:
		swap = m_contract_i.m_contract_yrs <
			m_contract_j.m_contract_yrs; 
        break;
    case 10:
		swap = m_contract_i.m_total_salary <
			m_contract_j.m_total_salary;
        break;
    case 11:
		swap = m_contract_i.m_player_pointer >
			m_contract_j.m_player_pointer;
       break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        break;
    case 17:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
    case 22:
		swap = tru1 < tru2;
        break;

}

	
	}


	else if(m_show_ratings == true)
	{

	


	switch(m_column) 
	{



	case 0:

		swap = m_contract_i.m_original_number > m_contract_j.m_original_number;
//		swap = m_contract_i.GetPos() < m_contract_j.GetPos();
	    break;
    case 1:
		
		swap = m_contract_i.GetName() > m_contract_j.GetName();
        break;
    case 2:
		swap = m_contract_i.GetAdjPrFga() < m_contract_j.GetAdjPrFga();
        break;
    case 3:        
		swap = m_contract_i.GetAdjPrFgp() < m_contract_j.GetAdjPrFgp();
        break;
    case 4:
		swap = m_contract_i.GetAdjPrFta() < m_contract_j.GetAdjPrFta();
        break;
    case 5:
		swap = m_contract_i.GetAdjPrFtp() < m_contract_j.GetAdjPrFtp();
        break;
    case 6:
		swap = m_contract_i.GetAdjPrTga() < m_contract_j.GetAdjPrTga();

        break;
    case 7:
		swap = m_contract_i.GetAdjPrTgp() < m_contract_j.GetAdjPrTgp();
        break;
    case 8:
		swap = m_contract_i.GetAdjPrOrb() < m_contract_j.GetAdjPrOrb();
        break;
    case 9:
		swap = m_contract_i.GetAdjPrDrb() < m_contract_j.GetAdjPrDrb();
        break;
    case 10:
		swap = m_contract_i.GetAdjPrAst() < m_contract_j.GetAdjPrAst();
        break;
    case 11:
		swap = m_contract_i.GetAdjPrStl() < m_contract_j.GetAdjPrStl();
        break;
    case 12:
		swap = m_contract_i.GetAdjPrTo() < m_contract_j.GetAdjPrTo();
        break;
    case 13:
		swap = m_contract_i.GetAdjPrBlk() < m_contract_j.GetAdjPrBlk();
        break;
    case 14:
		swap = m_contract_i.GetMovOff() < m_contract_j.GetMovOff();
        break;
    case 15:
		swap = m_contract_i.GetPenOff() < m_contract_j.GetPenOff();
        break;
    case 16:
		swap = m_contract_i.GetPostOff() < m_contract_j.GetPostOff();
        break;
    case 17:
		swap = m_contract_i.GetTransOff() < m_contract_j.GetTransOff();
        break;
    case 18:
		swap = m_contract_i.GetMovDef() < m_contract_j.GetMovDef();
        break;
    case 19:
 		swap = m_contract_i.GetPenDef() < m_contract_j.GetPenDef();
       break;
    case 20:
		swap = m_contract_i.GetPostDef() < m_contract_j.GetPostDef();
        break;
    case 21:
		swap = m_contract_i.GetTransDef() < m_contract_j.GetTransDef();
        break;
    case 22:
		swap = m_contract_i.GetAdjPot1() < m_contract_j.GetAdjPot1();
        break;
    case 23:
		swap = m_contract_i.GetAdjPot2() < m_contract_j.GetAdjPot2();
        break;
    case 24:
		swap = m_contract_i.GetAdjEffort() < m_contract_j.GetAdjEffort();
        break;

	}


	}

	
return swap;

}






void CFreeAgentDlg::OnDblclkListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_row = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(m_row >= 0)
	{
	int scout_index = m_list_team_names.GetCurSel();
	int i = m_row;
	int pointer = m_player_pointer[i];
	CPlayer m_player = avg.m_actual[pointer];
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = m_league_team_names[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;

	scout->m_default_scout = scout_index;
	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=m_players_listed; c++)
	{
		scout->avg.m_actual[c] = avg.m_actual[m_player_pointer[c]];
	}
	scout->m_player_index = m_row;
	scout->m_pl_index_end = m_players_listed;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;
}

void CFreeAgentDlg::SetAdjustedRatings()
{
	CPlayer m_player;
	for(int i=0; i<=1440; i++)
	{
		m_player = avg.m_actual[i];
		CStaff scout;
		int team = m_player.m_team_index;
		if(team > 0) scout = avg.m_scout[team-1];		
		else scout.InitVariables();
		m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	
		m_player.SetAdjustedRatings(scout);
		avg.m_actual[i] = m_player;
	}
}

void CFreeAgentDlg::SetSeasonAverages()
{
	for(int i=0; i<=1440; i++)
	{
		avg.m_actual[i].SetSeasonAverages();
	}
}



void CFreeAgentDlg::ListTeamCap()
{




		int index = m_list_team_names.GetCurSel();
		m_list_cap.ResetContent();
		long owner_cap = avg.m_finance[index].m_owner_salary_cap;
		double cap = (double) owner_cap / 1000;

		int off = 0;
		if(m_signing_ok == true) off = 1;

		if(avg.m_owner[index].m_offers_this_round == 0)
		{
			for(int i=0; i<=6; i++)
			{
				avg.m_owner[index].m_temp_payroll[i] = avg.m_owner[index].m_current_payroll[i];
			}	
		}

		int salary_used_0 = avg.m_owner[index].m_current_payroll[off];
		double salary_0 = (double) salary_used_0 / 100;
		int salary_used_1 = avg.m_owner[index].m_current_payroll[off+1];
		double salary_1 = (double) salary_used_1 / 100;
		int salary_used_2 = avg.m_owner[index].m_current_payroll[off+2];
		double salary_2 = (double) salary_used_2 / 100;
		double cap_room = (m_cap - (double)salary_used_0) / 100;

		int t_salary_used_0 = avg.m_owner[index].m_temp_payroll[off];
		double t_salary_0 = (double) t_salary_used_0 / 100;


		double released_0 = (double) avg.m_owner[index].m_released_salaries[off] / 100;
		double released_1 = (double) avg.m_owner[index].m_released_salaries[off+1] / 100;
		double released_2 = (double) avg.m_owner[index].m_released_salaries[off+2] / 100;

		CString string1, string2, string3, string4, string5, string6;
		string1.Format("avalaible cap room: %.2f million", cap_room);
		string2.Format("owner salary cap: %.2f million", cap);

		string3.Format("team payroll: %.2f million (%.2f)", salary_0, released_0);

		string4.Format("next season: %.2f million (%.2f)", salary_1, released_1);

		string5.Format("two seasons: %.2f million (%.2f)", salary_2, released_2);

		string6.Format("payroll + offers: %.2f million", t_salary_0);

		if(m_signing_ok == false)
		{
			string3.Format("season end payroll: %.2f million (%.2f)", salary_0, released_0);
			string4.Format("after next season: %.2f million (%.2f)", salary_1, released_1);
			string5.Format("after two seasons: %.2f million (%.2f)", salary_2, released_2);
		}

		
		m_list_cap.AddString(string1);
		if(m_check_finances_on == TRUE) m_list_cap.AddString(string2);
		if(m_signing_ok == true && t_salary_0 > 0) m_list_cap.AddString(string6);
		m_list_cap.AddString(string3);
		m_list_cap.AddString(string4);
		m_list_cap.AddString(string5);
	
}

void CFreeAgentDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] m_copy_actual;

}

void CFreeAgentDlg::OnOK() 
{
	// TODO: Add extra validation here

	bool end = EndStage();
	

	if(end == true || m_stage >= 12)
	{
		m_free_agency_over = true;
		SetCampRosters();
		WriteUpdatedContracts();
		WriteCampRosters();
		CDialog::OnOK();	
	}

	
    m_reset_list = false;
	m_reset_signings = false;
	bool ok = true;
	do
	{
		bool end = EndStage();
		ok = true;
		for(int i=0; i<m_number_teams; i++)
		{
			if(m_counter[i] < m_count && m_control[i] != "Player") ok = false;
		}
		

		m_stage = m_stage + 1;
		InitGmOffers();
		ListTeamCap();
		
	}
	while (ok == false && m_stage <= 12);

	if(ok == true) m_button_free_agency_period.EnableWindow(FALSE);

	ListFreeAgents();

}

void CFreeAgentDlg::OnButtonSort() 
{
	// TODO: Add your control notification handler code here
	m_column = 22;

	SortColumns();

	m_list_row = 0;
	m_list_free_agents.SetItemState(m_list_row ,LVIS_SELECTED,LVIS_SELECTED);
	m_list_free_agents.EnsureVisible(m_list_row, TRUE);
	int t = m_list_team_names.GetCurSel();

	CString capt;
//	capt.Format("Scout: %s Rankings", avg.m_scout[t].m_name);
	capt.Format("Ranked by %s staff",m_league_team_names[t]);
	m_button_sort.SetWindowText(capt);

}

void CFreeAgentDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_signing_ok == true)
	{
		int	result = AfxMessageBox("Are you sure you want to cancel?\n(Any transactions made will not be saved)", MB_YESNO);		
		if(result == IDYES) CDialog::OnCancel();
	}
	else
		CDialog::OnCancel();

}

void CFreeAgentDlg::OnSelchangeComboListTeamNames() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	ListControl();
	EnableOfferButton();
	ListTeamCap();

	int t = m_list_team_names.GetCurSel();
	CString capt;
	capt.Format("Ranked by %s staff",m_league_team_names[t]);

	m_button_sort.SetWindowText(capt);
	if(m_column == 22) OnButtonSort();

	FillOffersList();
	
}

void CFreeAgentDlg::CreateFaSaveString(int stage, CPlayer m_player)
{
	CString string;
	int best = m_player.m_best_contract;
	int mid = (int)avg.m_owner[best].m_mid_exception_used;
	int min = (int)avg.m_owner[best].m_million_exception_used;


	string.Format("%2d%-32s%5d%2d%1d%5d%4d%4d", stage, m_player.m_name,m_player.m_id, best, 
		m_player.m_contract_yrs,
		m_player.m_total_salary, mid, min);
		
	m_count_signings = m_count_signings + 1;
	m_string_load[m_count_signings] = string;
	
}

void CFreeAgentDlg::OnButtonSaveFa() 
{
	// TODO: Add your control notification handler code here
	SaveSignings();
	SaveOffers(false);
	SetCampRosters();
	CDialog::OnOK();

}



void CFreeAgentDlg::Retirements()
{
	CRetirement* ret = new CRetirement;
	ret->m_path = m_path;
	ret->m_league_name = m_league_name;
	for(int i=0; i<=1440; i++)
	{
		ret->avg.m_actual[i] = avg.m_actual[i];
	}
	ret->ReadRetirements();
	ret->UpdatePlayerClass();
	for(int i=0; i<=1440; i++)
	{
		avg.m_actual[i] = ret->avg.m_actual[i];
	}
	delete ret;

}

void CFreeAgentDlg::ListSignings()
{

	m_list_team_names.SetCurSel(m_default_team);

	for(int i=1; i<=m_count_signings; i++)
	{

		CString string = m_string_load[i];		

		
		CString st = string.Mid(0, 2);
		int stage = atoi(st);

		
		CString name = string.Mid(2, 32);
		name.TrimLeft();
		name.TrimRight();

		CString s_id = string.Mid(34, 5);
		int id = atoi(s_id);

		CString be = string.Mid(39, 2);
		int best = atoi(be);

		CString ye = string.Mid(41, 1);
		int years = atoi(ye);

		CString sa = string.Mid(42, 5);
		int total_salary = atoi(sa);
		double ts = (double) total_salary / 100;
	
		CString mid = string.Mid(47, 4);
		int mid_i = atoi(mid);

		CString min = string.Mid(51, 4);
		int min_i = atoi(min);

		if(mid_i > 0)
		{
			avg.m_owner[best].m_mid_exception_used = true;
		}

		if(min_i > 0) avg.m_owner[best].m_million_exception_used = true;		

		CString cont;
		cont.Format("%s, %s, %d year %.2f million", name, m_league_team_names[best], years, ts);
		
		m_list_signings.AddString(cont);

		for(int c=0; c<=1440; c++)
		{
			if(avg.m_actual[c].m_id == id) 
			{
				avg.m_actual[c].m_just_signed = true;
				avg.m_actual[c].m_is_free_agent = false;
				avg.m_actual[c].m_signed = true;
				
			}

			avg.m_actual[c].m_accept_factor = (double)m_stage * .1;
			if(avg.m_actual[c].m_accept_factor > 1) avg.m_actual[c].m_accept_factor = 1;

		}
			
	}


	CString stri;
	stri.Format("Free Agency Stage - Stage %d", m_stage + 1);
	SetWindowText(stri);

	ListTeamCap();
}

void CFreeAgentDlg::SaveSignings()
{
	CString title = m_path + m_league_name + ".sav";

	CFileStatus status;
	long int size = 240000;
	if( CFile::GetStatus( title, status ) == 0) 
	{
		CFile file( title, CFile::modeCreate | CFile::modeWrite );
		char buffer[240001];
		memset( buffer, ' ', size);
		file.Write( buffer, size);
		file.Close();
	}

	CStdioFile fi( title, CFile::modeWrite );
	CString st;
	st.Format("%d", m_stage);
	fi.WriteString(st + "\n");
	for(int i=1; i<=480; i++)
	{
		CString string = m_string_load[i];
		string.TrimRight();
		string = string + "                                                  ";
		fi.WriteString( string + "\n");		
	}
	fi.Close(); 
}






void CFreeAgentDlg::AdjustPlayerRequests()
{
	int co = 0;
	int franchise_win[33], franchise_loss[33];
	double pos_value[33][6];
	double avg_pv[6] = {0,0,0,0,0,0};
	double t_pv[6] = {0,0,0,0,0,0};

	for(int t=0; t<=32; t++)
	{
		avg.m_owner[t].SetPositionValuesSortedList(avg.m_actual, avg.m_coach[t], t);
		franchise_win[t] = 0;
		franchise_loss[t] = 0;
		franchise_win[t] = avg.m_owner[t].m_win;
		franchise_loss[t] = avg.m_owner[t].m_loss;

	

		for(int i=1; i<=5; i++)
		{
			pos_value[t][i] = avg.m_owner[t].m_position_values[i];
			t_pv[i] = t_pv[i] + avg.m_owner[t].m_position_values[i];
		}

	}

	for(int i=1; i<=5; i++)
	{
		avg_pv[i] = t_pv[i] / m_number_teams;
	}



for(int pl=0; pl<=1440; pl++)
{
	avg.m_actual[pl].m_player_pointer = pl;
//	avg.m_actual[pl].m_best_contract = -1;
	CPlayer m_player = avg.m_actual[pl];
	m_copy_actual[pl] = m_player;//copy presorted original data
	CString name = m_player.m_name;
	if(name == "") continue;

	if(m_player.m_is_free_agent == true)
	{
		m_player.m_current_team = -1;
		m_player.SetAdjustedRequests(franchise_win, franchise_loss, avg.m_standings, avg.m_coach, avg_pv, pos_value);
	}
		
	avg.m_actual[pl] = m_player;
	
}

}

void CFreeAgentDlg::OnClickListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_row = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	EnableOfferButton();
	*pResult = 0;
}

void CFreeAgentDlg::OnButtonHtml() 
{
	// TODO: Add your control notification handler code here
  CString headers[27];
		CString label = " Free Agency";


			for(int j = 0; j <= 26; j++)
			{
				int col = j;

					headers[j] = m_column_headers[j];

			}


	CHtmlMsc* html = new CHtmlMsc;

	CString team_name, html_string;


	for(int i=0; i<=580; i++)
	{
	for(int j=0; j<=26; j++)
	{
		int col = j;
		html_string = m_print_strings[i][col];
		if(col <= 21 && html_string == "") 
			html_string = "-";

		html->m_strings[i][j] = html_string;
		html->m_headers[col] = headers[col];
	}
	}

	html->m_path = m_path;
	html->m_league_name = m_league_name;
	html->m_label = label;
	int items = m_list_free_agents.GetItemCount();
	if(items < 0) items = 0;
	html->m_items = items;
	html->DoModal();
	delete html;
	
}


void CFreeAgentDlg::BuildString(CString s[], int co, int columns)
{
if(co <= 580)
{
//	CMyString *my = new CMyString;
//	m_print_strings[co] = my->SetPrintString(s, columns);
	for(int j=2; j<=28; j++)
	{
		m_print_strings[co][j] = s[j-2];
	}
//	delete my;
}
}


void CFreeAgentDlg::SaveOffers(bool commish)
{
	CImpExp* exp = new CImpExp;
	CString offers[16];


	for(int j=0; j<=32; j++)
	{

	if(m_control[j] != "Player" || m_offer_strings[j][1] == "") continue;


	for(int k=1; k<=15; k++)
	{
		offers[k-1] = m_offer_strings[j][k];
	}

	CString team = avg.m_settings.m_leagueTeamNames[j];
	CString league = m_league_name;
	league.Remove(' ');
	CString file_name = m_path + league;
	exp->WriteDirectory(file_name);
	file_name = m_path + league + "\\exp";
	exp->WriteDirectory(file_name);
	file_name = file_name + "\\" + team + "_offers.txt";
	exp->ExportOffers(file_name, offers);


	if(commish == true)
	{

		CString s1 = team + " Free Agent Offers are saved as file name " + file_name;
		MessageBox(s1, "Export Free Agent Offers", MB_OK);
	}


	}
	delete exp;


}


void CFreeAgentDlg::CreateFaOffersString()
{

	//create string
			CString string[33];

		for(int t=0; t<=32; t++)
		{

			if(m_control[t] != "Player") continue;

			for(int x=1; x<=15; x++)
			{

			if(x > avg.m_owner[t].m_offers_this_round) continue;


			int off = x;
			int choice = avg.m_owner[t].m_top_free_agent[off];
			if(choice == -1) continue;

			string[0] = avg.m_actual[choice].m_name;

			if(avg.m_owner[t].m_top_free_agent_salaries[off][1] == 0) string[0] = "";
			for(int j=0; j<=5; j++)
			{
				string[j+1].Format("%d", avg.m_owner[t].m_top_free_agent_salaries[off][j+1]);
			}
			string[7] = "0";
			
			int m1 = avg.m_owner[t].m_mid_exception_offered;
			if(avg.m_actual[choice].m_id != m1) m1 = -1;
			
			int m2 = avg.m_owner[t].m_million_exception_offered;
			if(avg.m_actual[choice].m_id != m2) m2 = -1;
			
			string[8].Format("%d", m1);
			string[9].Format("%d", m2);

			m_offer_strings[t][off] = "";
			for(int j=0; j<=9; j++)
			{
				if(j<9) string[j] = string[j] + ",";
				m_offer_strings[t][off] = m_offer_strings[t][off]  + string[j];
			}

			}
	
		}

}

void CFreeAgentDlg::LoadFaOffers(bool commish)
{
	// TODO: Add your control notification handler code here
	CImpExp* exp = new CImpExp;


	CString league = m_league_name;
	league.Remove(' ');

	CString file_name = m_path + league;
	exp->WriteDirectory(file_name);
	file_name = m_path + league + "\\imp";
	exp->WriteDirectory(file_name);


	int plans_found = 0;
	for(int j=0; j<=31; j++)
	{
		CString strings[17];
		CString team = avg.m_settings.m_leagueTeamNames[j];
		if(m_control[j] != "Player") continue;

		file_name = m_path + league + "\\exp";
		if(commish == true) file_name = m_path + league + "\\imp";

		bool found = exp->ImportFaOffers(file_name + "\\" + team + "_offers.txt", strings);
		//do offers convert routine here?
		if(found == true) plans_found = plans_found + 1;
		if(found == false) continue;
		int last_offer_row = 0;


		for(int k=0; k<=6; k++)
		{
			avg.m_owner[j].m_temp_payroll[k] = avg.m_owner[j].m_current_payroll[k];
		}


		for(int i=0; i<=14; i++)
		{
			int choice = 0;
			CString string = strings[i];
			int off = i+1;

			string.TrimLeft();
			string.TrimRight();

			int offset = 0;
			int index = string.Find(",", offset); 


			int	chars = (index - offset);
			CString str = string.Mid(offset, chars); 
			CString name = str;//just read do not set
			if(name == "") continue;


			int player_id = -1;
			for(int c=0; c<=1440; c++)
			{
				if(avg.m_actual[c].m_name == name && name != "") 
				{
					player_id = avg.m_actual[c].m_id;
					choice = c;
					last_offer_row = off;
				}
			}
		
			avg.m_owner[j].m_top_free_agent_salaries[off][0] = 0;

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][1] = atoi(str);
		
			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][2] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][3] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][4] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][5] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			avg.m_owner[j].m_top_free_agent_salaries[off][6] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			//g.m_owner[j].m_top_free_agent_salaries[off][6] = atoi(str);

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			int m1 = atoi(str);


			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			int m2 = atoi(str);


			if(m1 > 0) avg.m_owner[j].m_mid_exception_offered = player_id;
			else if(m2 > 0) avg.m_owner[j].m_million_exception_offered = player_id;



			int total_yrs = 0;
			int total_salary = 0;
			for(int k=0; k<=5; k++)
			{
				int mon = avg.m_owner[j].m_top_free_agent_salaries[off][k+1];
				if(mon > 0)
				{
					total_yrs = total_yrs + 1;
					avg.m_owner[j].m_temp_payroll[k+1] = avg.m_owner[j].m_temp_payroll[k+1] + mon;
					total_salary = total_salary + mon;
				}
			}



			bool qualify = true;


			if(qualify == true && choice >= 0)
			{

				avg.m_actual[choice].m_top_offer[j] = true;
				avg.m_actual[choice].m_year_offer[j] = total_yrs;
				avg.m_actual[choice].m_total_salary_offer[j] = total_salary;
				double ts = 0;
				avg.m_actual[choice].m_salary_offer[j][0] = 0;
				for(int k=0; k<=5; k++)		
				{
					avg.m_actual[choice].m_salary_offer[j][k+1] = avg.m_owner[j].m_top_free_agent_salaries[off][k+1];
				}

				avg.m_actual[choice].m_offer_slot[j] = off;

				avg.m_owner[j].m_top_free_agent_total_salary[off] = total_salary;
				avg.m_owner[j].m_top_free_agent_years[off]  = total_yrs;

				avg.m_owner[j].m_top_free_agent[off] = choice;

				CString str;
				CString na = name;
				str.Format("%s offer %s: %d year %.2f million", m_league_team_names[j], na, total_yrs, (double)total_salary/100);
				m_reset_list = false;
		
				int index = m_list_team_names.GetCurSel();
				if(index == j || commish == true) 
				{

					if(index == j)
					{
						m_list_offers.AddString(str);
						int slot = m_list_offers.GetCount()-1;
						m_list_offers.SetCurSel(slot);
						m_offer_list[slot].shown_id = m_offer_list[m_offer_list_count].id;
					}
						m_offer_list[m_offer_list_count].id = avg.m_actual[choice].m_id;
						m_offer_list[m_offer_list_count].offer_string = str;
						m_offer_list[m_offer_list_count].team_index = j;
						m_offer_list_count = m_offer_list_count + 1;

				}





			}


		}

		avg.m_owner[j].m_offers_this_round = last_offer_row;
		//if(last_offer_row > 0) plans_found = plans_found + 1;

	}

	m_list_offers.SetCurSel(m_list_offers.GetCount()-1);


	if(commish == true)
	{
		CString s1;
		s1.Format("%d Free Agent Offer Files(s) imported from directory %s", plans_found, file_name);
		MessageBox(s1, "Import Free Agent Offers", MB_OK);
	}





	delete exp;
	


}

void CFreeAgentDlg::OnButtonExport() 
{
	// TODO: Add your control notification handler code here
	SaveOffers(true);
	
}

void CFreeAgentDlg::OnButtonImport() 
{
	// TODO: Add your control notification handler code here
	LoadFaOffers(true);	
	ListTeamCap();
}

void CFreeAgentDlg::FillOffersList()
{
	int index = m_list_team_names.GetCurSel();

	m_list_offers.ResetContent();


	if(index >= 0)
	{
		for(int i=0; i<=m_offer_list_count; i++)
		{


			if(m_offer_list[i].team_index == index && m_offer_list[i].offer_string != "")
			{
				bool list = false;
				for(int j=1; j<=1440; j++)
				{
					if(avg.m_actual[j].m_id == m_offer_list[i].id && 
						avg.m_actual[j].m_just_signed == false &&
							avg.m_actual[j].m_year_offer[index] > 0) list = true;
				}
						

				if(list == true)
				{
					m_list_offers.AddString(m_offer_list[i].offer_string);
					int slot = m_list_offers.GetCount() - 1;
					m_offer_list[slot].shown_id = m_offer_list[i].id;
				}
			
			}

		}
	}

	int slot = m_list_offers.GetCount();
	if(slot >= 0)
	{
		m_list_offers.SetCurSel(slot-1);
		avg.m_owner[index].m_offers_this_round = slot;
	}

}

void CFreeAgentDlg::OnSelchangeListOffers() 
{
	// TODO: Add your control notification handler code here
	
}

void CFreeAgentDlg::ClearOffer(int j, int id)
{

		int choice = -1;
		for(int c=0; c<=1440; c++)
		{
			if(avg.m_actual[c].m_id == id && avg.m_actual[c].m_name != "") 
			{
				choice = c;
			}
		}

		
		if(choice >= 0 && avg.m_actual[choice].m_signed == false)
		{

		int off = avg.m_actual[choice].m_offer_slot[j];

		for(int i=0; i<=6; i++)
		{
		
			avg.m_owner[j].m_top_free_agent_salaries[off][0] = 0;
		}

		if(avg.m_owner[j].m_mid_exception_offered == id)
			avg.m_owner[j].m_mid_exception_offered = -1;
		if(avg.m_owner[j].m_million_exception_offered == id)
			avg.m_owner[j].m_million_exception_offered = -1;


		for(int k=0; k<=6; k++)
		{
			int mon = avg.m_owner[j].m_top_free_agent_salaries[off][k];
			avg.m_owner[j].m_temp_payroll[k] = avg.m_owner[j].m_temp_payroll[k] - mon;
			avg.m_actual[choice].m_salary_offer[j][k] = 0;
			avg.m_owner[j].m_top_free_agent_salaries[off][k] = 0;
		}


		avg.m_actual[choice].m_top_offer[j] = true;
		avg.m_actual[choice].m_year_offer[j] = 0;
		avg.m_actual[choice].m_total_salary_offer[j] = 0;
		avg.m_actual[choice].m_offer_slot[j] = 0;

		avg.m_owner[j].m_top_free_agent_total_salary[off] = 0;
		avg.m_owner[j].m_top_free_agent_years[off]  = 0;
		avg.m_owner[j].m_top_free_agent[off] = -1;

		}

}

void CFreeAgentDlg::OnDblclkListOffers() 
{
	// TODO: Add your control notification handler code here
	int index = m_list_team_names.GetCurSel();
	int slot = m_list_offers.GetCurSel();
	ClearOffer(index, m_offer_list[slot].shown_id);	
	FillOffersList();
	ListTeamCap();
}

void CFreeAgentDlg::OnRadioUnsignedPlayers() 
{
	// TODO: Add your control notification handler code here
	m_category = 4;
	ListFreeAgents();
	

	
}

void CFreeAgentDlg::OnButtonToggle() 
{
	// TODO: Add your control notification handler code here
	if(m_show_ratings == false)
	{
		SetRatingsHeaders();	
		m_show_ratings = true;
		m_button_toggle.SetWindowText("Show Demands");
	}
	else
	{
		SetColumns();
		m_show_ratings = false;
		m_button_toggle.SetWindowText("Show Ratings");
	}

	ListFreeAgents();
	
}


void CFreeAgentDlg::SetRatingsHeaders()
{
	
	 m_list_free_agents.DeleteAllItems();




	 m_list_free_agents.DeleteColumn(0);
     m_list_free_agents.InsertColumn(0,"pos");    
	 m_list_free_agents.DeleteColumn(1);
     m_list_free_agents.InsertColumn(1,"Player");    
	 m_list_free_agents.DeleteColumn(2);
     m_list_free_agents.InsertColumn(2,"2ga");    
	 m_list_free_agents.DeleteColumn(3);
     m_list_free_agents.InsertColumn(3,"2g%");    
	 m_list_free_agents.DeleteColumn(4);
     m_list_free_agents.InsertColumn(4,"fta");    
	 m_list_free_agents.DeleteColumn(5);
     m_list_free_agents.InsertColumn(5,"ft%");    
	 m_list_free_agents.DeleteColumn(6);
     m_list_free_agents.InsertColumn(6,"3ga");    
	 m_list_free_agents.DeleteColumn(7);
     m_list_free_agents.InsertColumn(7,"3g%");    
	 m_list_free_agents.DeleteColumn(8);
     m_list_free_agents.InsertColumn(8,"orb");    
	 m_list_free_agents.DeleteColumn(9);
     m_list_free_agents.InsertColumn(9,"drb");    
	 m_list_free_agents.DeleteColumn(10);
     m_list_free_agents.InsertColumn(10,"ast");    
	 m_list_free_agents.DeleteColumn(11);
     m_list_free_agents.InsertColumn(11,"stl");    
	 m_list_free_agents.DeleteColumn(12);
     m_list_free_agents.InsertColumn(12,"to");    
	 m_list_free_agents.DeleteColumn(13);
     m_list_free_agents.InsertColumn(13,"blk");    
	 m_list_free_agents.DeleteColumn(14);
     m_list_free_agents.InsertColumn(14,"oo");    
	 m_list_free_agents.DeleteColumn(15);
     m_list_free_agents.InsertColumn(15,"do");    
	 m_list_free_agents.DeleteColumn(16);
     m_list_free_agents.InsertColumn(16,"po");    
	 m_list_free_agents.DeleteColumn(17);
     m_list_free_agents.InsertColumn(17,"to");    
	 m_list_free_agents.DeleteColumn(18);
     m_list_free_agents.InsertColumn(18,"od");    
	 m_list_free_agents.DeleteColumn(19);
     m_list_free_agents.InsertColumn(19,"dd");    
	 m_list_free_agents.DeleteColumn(20);
     m_list_free_agents.InsertColumn(20,"pd");    
	 m_list_free_agents.DeleteColumn(21);
     m_list_free_agents.InsertColumn(21,"td");    
	 m_list_free_agents.DeleteColumn(22);
     m_list_free_agents.InsertColumn(22,"ta");    
	 m_list_free_agents.DeleteColumn(23);
     m_list_free_agents.InsertColumn(23,"sk");    
	 m_list_free_agents.DeleteColumn(24);
     m_list_free_agents.InsertColumn(24,"in");    

  
     m_list_free_agents.SetColumnWidth( 0, 36);
     m_list_free_agents.SetColumnWidth( 1, 144);
     m_list_free_agents.SetColumnWidth( 2, 40);
     m_list_free_agents.SetColumnWidth( 3, 40);
     m_list_free_agents.SetColumnWidth( 4, 40);
     m_list_free_agents.SetColumnWidth( 5, 40);
     m_list_free_agents.SetColumnWidth( 6, 40);
     m_list_free_agents.SetColumnWidth( 7, 40);
     m_list_free_agents.SetColumnWidth( 8, 40);
     m_list_free_agents.SetColumnWidth( 9, 40);
     m_list_free_agents.SetColumnWidth( 10, 36);
     m_list_free_agents.SetColumnWidth( 11, 36);
     m_list_free_agents.SetColumnWidth( 12, 36);
     m_list_free_agents.SetColumnWidth( 13, 36);
     m_list_free_agents.SetColumnWidth( 14, 32);
     m_list_free_agents.SetColumnWidth( 15, 32);
     m_list_free_agents.SetColumnWidth( 16, 32);
     m_list_free_agents.SetColumnWidth( 17, 32);
     m_list_free_agents.SetColumnWidth( 18, 32);
     m_list_free_agents.SetColumnWidth( 19, 32);
     m_list_free_agents.SetColumnWidth( 20, 32);
     m_list_free_agents.SetColumnWidth( 21, 32);
     m_list_free_agents.SetColumnWidth( 22, 32);
     m_list_free_agents.SetColumnWidth( 23, 32);
     m_list_free_agents.SetColumnWidth( 24, 32);

}


void CFreeAgentDlg::SetColumns()
{

	m_list_free_agents.DeleteAllItems();



	m_list_free_agents.DeleteColumn(0);
    m_list_free_agents.InsertColumn(0,"pos");    
	m_list_free_agents.DeleteColumn(1);
    m_list_free_agents.InsertColumn(1,"Player");    
	m_list_free_agents.DeleteColumn(2);
    m_list_free_agents.InsertColumn(2,"yrs pro");    
	m_list_free_agents.DeleteColumn(3);
    m_list_free_agents.InsertColumn(3,"Bird");    
	m_list_free_agents.DeleteColumn(4);
    m_list_free_agents.InsertColumn(4,"contract yrs");    
	m_list_free_agents.DeleteColumn(5);
    m_list_free_agents.InsertColumn(5,"yrs left");
	m_list_free_agents.DeleteColumn(6);
    m_list_free_agents.InsertColumn(6,"amount");    
	m_list_free_agents.DeleteColumn(7);
    m_list_free_agents.InsertColumn(7,"yrs sought");    
	m_list_free_agents.DeleteColumn(8);
    m_list_free_agents.InsertColumn(8,"amount");    
	m_list_free_agents.DeleteColumn(9);
	m_list_free_agents.InsertColumn(9,"yrs agreed");    
	m_list_free_agents.DeleteColumn(10);
	m_list_free_agents.InsertColumn(10,"amount");    
	m_list_free_agents.DeleteColumn(11);
    m_list_free_agents.InsertColumn(11,"status");    
	m_list_free_agents.DeleteColumn(12);
    m_list_free_agents.InsertColumn(12,"from");    
  
    m_list_free_agents.SetColumnWidth( 0, 36);
    m_list_free_agents.SetColumnWidth( 1, 144);
    m_list_free_agents.SetColumnWidth( 2, 66);
    m_list_free_agents.SetColumnWidth( 3, 48);
    m_list_free_agents.SetColumnWidth( 4, 96);
    m_list_free_agents.SetColumnWidth( 5, 80);
    m_list_free_agents.SetColumnWidth( 6, 80);
    m_list_free_agents.SetColumnWidth( 7, 88);
    m_list_free_agents.SetColumnWidth( 8, 80);
    m_list_free_agents.SetColumnWidth( 9, 84);
    m_list_free_agents.SetColumnWidth( 10, 76);
    m_list_free_agents.SetColumnWidth( 11, 80);
    m_list_free_agents.SetColumnWidth( 12, 84);

	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	m_list_free_agents.DeleteColumn(13);
	
}


void CFreeAgentDlg::OnLvnItemchangedListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
