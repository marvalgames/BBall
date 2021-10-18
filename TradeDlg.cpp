// TradeDlg.cpp : implementation file
#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
//#include "MyComboBox.h"
#include "TradeDlg.h"
#include "SearchDlg.h"
#include "PlayerCardDlg.h"

#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CTradeDlg dialog


CTradeDlg::CTradeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTradeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTradeDlg)
	m_edit_salary_1 = _T("");
	m_edit_salary_2 = _T("");
	m_edit_salary_fit = _T("");
	m_edit_payroll1 = _T("");
	m_edit_payroll2 = _T("");
	//}}AFX_DATA_INIT
//	m_standings = new CRecord[33];
}


void CTradeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTradeDlg)
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDC_LIST_CTRL_TEAM1_DRAFT, m_list_team1_draft);
	DDX_Control(pDX, IDC_LIST_CTRL_ROSTER3, m_listroster3);
	DDX_Control(pDX, IDC_LIST_CTRL_ROSTER2, m_listroster2);
	DDX_Control(pDX, IDC_LIST_CTRL_PLAYERS2, m_listplayers2);
	DDX_Control(pDX, IDC_LIST_CTRL_PLAYERS1, m_listplayers1);
	DDX_Control(pDX, IDC_LIST_CTRL_TEAM2_DRAFT, m_list_team2_draft);
	DDX_Control(pDX, IDC_LIST_CTRL_FA, m_listfa);
	DDX_Control(pDX, IDC_LIST_CTRL_ROSTER1, m_listroster1);
	DDX_Control(pDX, IDC_COMBO3, m_listteams3);
	DDX_Control(pDX, IDC_COMBO2, m_listteams2);
	DDX_Control(pDX, IDC_COMBO1, m_listteams1);
	DDX_Control(pDX, IDC_BUTTON_SEARCH, m_button_search);
	DDX_Control(pDX, IDC_BUTTON_ADD_PICK2, m_button_add_pick2);
	DDX_Control(pDX, IDC_BUTTON_ADD_PICK1, m_button_add_pick1);
	DDX_Control(pDX, IDC_BUTTON_TEAM2, m_button_team2);
	DDX_Control(pDX, IDC_BUTTON_TEAM1, m_button_team1);
	DDX_Control(pDX, IDOK, m_buttonOk);
	DDX_Control(pDX, IDC_BUTTON_RELEASE, m_button_release);
	DDX_Control(pDX, IDC_BUTTON_SIGN, m_button_sign);
	DDX_Control(pDX, IDC_BUTTON_TRADE, m_button_trade);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listcontrol);
	DDX_Text(pDX, IDC_EDIT_SALARY_1, m_edit_salary_1);
	DDV_MaxChars(pDX, m_edit_salary_1, 6);
	DDX_Text(pDX, IDC_EDIT_SALARY_2, m_edit_salary_2);
	DDV_MaxChars(pDX, m_edit_salary_2, 6);
	DDX_Text(pDX, IDC_EDIT_SALARY_FIT, m_edit_salary_fit);
	DDV_MaxChars(pDX, m_edit_salary_fit, 32);
	DDX_Text(pDX, IDC_EDIT1, m_edit_payroll1);
	DDV_MaxChars(pDX, m_edit_payroll1, 16);
	DDX_Text(pDX, IDC_EDIT2, m_edit_payroll2);
	DDV_MaxChars(pDX, m_edit_payroll2, 16);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTradeDlg, CDialog)
	//{{AFX_MSG_MAP(CTradeDlg)
	ON_BN_CLICKED(IDC_BUTTON_TRADE, OnButtonTrade)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_BN_CLICKED(IDC_BUTTON_RELEASE, OnButtonRelease)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, OnButtonSign)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_TEAM1, OnButtonTeam1)
	ON_BN_CLICKED(IDC_BUTTON_TEAM2, OnButtonTeam2)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_ADD_PICK1, OnButtonAddPick1)
	ON_BN_CLICKED(IDC_BUTTON_ADD_PICK2, OnButtonAddPick2)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_ROSTER1, OnClickListCtrlRoster1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_ROSTER1, OnDblclkListCtrlRoster1)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_ROSTER2, OnClickListCtrlRoster2)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_FA, OnClickListCtrlFa)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_PLAYERS1, OnDblclkListCtrlPlayers1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_PLAYERS2, OnDblclkListCtrlPlayers2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_ROSTER2, OnDblclkListCtrlRoster2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_FA, OnDblclkListCtrlFa)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_ROSTER3, OnClickListCtrlRoster3)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_ROSTER3, OnDblclkListCtrlRoster3)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_PLAYERS1, OnClickListCtrlPlayers1)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_PLAYERS2, OnClickListCtrlPlayers2)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_FA, &CTradeDlg::OnLvnItemchangedListCtrlFa)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_TEAM2_DRAFT, &CTradeDlg::OnLvnItemchangedListCtrlTeam2Draft)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTradeDlg message handlers

BOOL CTradeDlg::OnInitDialog() 
{
	
	// TODO: Add extra initialization here


   CDialog::OnInitDialog();           // Call default ::OnInitDialog



   InitControls();

   m_cap_1 = 0;
   m_cap_2 = 0;

 myBrush.CreateSolidBrush(DLGCOLOR); 
	
	m_salaries_match = avg.m_settings.m_salary_matching;
	facount = 0;
	m_seek = avg.m_settings.m_number_transactions;

	m_team1index = 0;
	m_team2index = 1;
	for(int i=0; i<32; i++)
		{
			if(m_leagueTeamNames[i] != "")
			{
				m_listteams1.AddString(m_leagueTeamNames[i]);
				m_listteams2.AddString(m_leagueTeamNames[i]);
				m_listteams3.AddString(m_leagueTeamNames[i]);
				
				m_listcontrol.AddString(m_control[i]);
			}
		}


	m_listteams1.SetCurSel(m_default_team);
	m_listteams2.SetCurSel(0);
	m_listteams3.SetCurSel(m_default_team);

	CString m_currentSelection;
	int cou = 0;
	for(int i=1; i<=480; i++)
	{
		CString Po = FA[i].GetPos();
		CString Na = FA[i].GetName();
		int age = FA[i].m_age;
		CString Sa = DisplayFaSalarySeeking(i);
		int inj = FA[i].GetInjury();
		CString Ag, In;
		Ag.Format("%d", age);
		In.Format("%d", inj);
	


		if(Na != "")
		{
			m_listfa.InsertItem(cou,Po);
			m_listfa.SetItemText(cou,1,Na);			
			m_listfa.SetItemText(cou,2,Ag);			
			m_listfa.SetItemText(cou,3,Sa);			
			m_listfa.SetItemText(cou,4,In);			
			
			m_listfa.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
			m_listfa.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
			m_listfa.EnsureVisible(0, TRUE);			

			facount=facount+1;
			cou = cou + 1;
		}
	}

	ClearDraftPickData(1, 32, 0, 1,2);



	OnSelchangeCombo1(); 
	OnSelchangeCombo2(); 
	OnSelchangeCombo3(); 
	m_listroster3.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster3.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster3.EnsureVisible(0, TRUE);


	if(m_player_list[1] > 0) ListPlayersInTradeOffer();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}










void CTradeDlg::OnButtonTrade() 
{
	// TODO: Add your control notification handler code here
	double team1true = 0;
	double team2true = 0;
	double originalteam1true = 0;//team1 rating before
	double originalteam2true = 0;//team2

	int team1 = m_listteams1.GetCurSel();
	int team2 = m_listteams2.GetCurSel();
	m_team1 = team1;
	m_team2 = team2;

	CString team1control = m_control[team1];
	CString team2control = m_control[team2];
	CString team1name = avg.m_finance[team1].m_city_name + " " + m_leagueTeamNames[team1];
	CString team2name = avg.m_finance[team2].m_city_name + " " + m_leagueTeamNames[team2];
	CString computerTeamName;

	int active1 = 0;
	int active2 = 0;
	double starter[] = {0,0,0,0,0,0,0,0,0,0,0};	
	
	
	
	CPlayer* Player;
	Player = new CPlayer[61];
	CPlayer* PlayerUpdate;
	PlayerUpdate = new CPlayer[961];
	CPlayer* NewFA;
	NewFA = new CPlayer[481];
	
	CPlayer* OrigFA;
	OrigFA = new CPlayer[481];
	int Signed[481];
	int temp_facount = 0;
	for(int i=0; i<=480; i++)
	{	
		Signed[i] = 0;
		OrigFA[i] = FA[i];//set original fa list to be restored if trade is cancelled
		if(OrigFA[i].GetName() != "") temp_facount = temp_facount + 1;
	}
	CPlayer* NewRoster;
	NewRoster = new CPlayer[101];

	for(int i=0; i<=31; i++)
	{	
		for(int j=1; j<=m_slots; j++)
		{	
			PlayerUpdate[i*m_slots+j] = PlayerList[i][j];//all league players

		}
	}
	
	avg.SortTeamRosters(PlayerUpdate, false);



	
	for(int i=1; i<=(m_slots*2); i++)
	{	
		if(i<=m_slots)
		{

//			CPlayer m_player = PlayerList[m_team1index][i];//team1 players
			CPlayer m_player = PlayerUpdate[m_team1index*30+i];//team1 players
			Player[i] = m_player;

		}
		else
		{
//			CPlayer m_player = PlayerList[m_team2index][i-m_slots];//team2 players
			CPlayer m_player = PlayerUpdate[m_team2index*30+i-m_slots];//team1 players
			Player[i] = m_player;
		}

	}


	CPlayer* temp_player = new CPlayer[61];
	double true_values[61];
	for(int tmp=0; tmp<=60; tmp++)
	{
		true_values[tmp] = 0;
		temp_player[tmp] = Player[tmp];
	}
	avg.ComputerRotationForTrades(temp_player, true_values, 30, team1, team2);
	delete [] temp_player;

	for(int i=1; i<=m_slots*2; i++)//start from here
	{

		CPlayer m_player = Player[i];
		if(m_player.m_games == 0) continue;
		double mn = double(m_player.GetMin()) / double(m_player.GetGames());
		double add = 0;
		if(i<=m_slots && m_player.GetActive() > 0 && m_player.GetName() != "")
		{
			active1 = active1 + 1;

			add = true_values[i];

			if(active1 <= 15) originalteam1true = originalteam1true + add;
			

		}
		else if(m_player.GetActive() > 0 && m_player.GetName() != "")
		{
			active2 = active2 + 1;

			add = true_values[i];

			if(active2 <= 15) originalteam2true = originalteam2true + add;
		}

	}


	if(active1 < 8) originalteam1true = 12 * avg.m_avg_tru[0];
	if(active2 < 8) originalteam2true = 12 * avg.m_avg_tru[0];

	int team1players = 0;
	int team2players = 0;
	bool tradeok = false;
	bool invalid = false;
	bool injury = false;
	for(int j=1; j<=m_slots*2; j++)
	{
		int i = 1;
		if(j >= (m_slots+1)) i = 2;
		slots[j] = i;
	}
	for(int i=1; i<=m_slots; i++)
	{
	
		CString name = Player[i].GetName();
		if(m_listplayers1.GetItemCount() > 0)
		{
			for(int j=1; j<= m_listplayers1.GetItemCount(); j++)
			{
				CString currentSelection1 = m_listplayers1.GetItemText(j-1, 1);
				if(currentSelection1 == name)
				{
					slots[i] = 2;
				if(Player[i].GetInjury() >= 5) injury = true;
				}
			}
		}
	
	}

	for(int i=m_slots+1; i<=m_slots*2; i++)
	{	
	if(m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
		CString name = Player[i].GetName();
		if(m_listplayers2.GetItemCount() > 0)
		{
			for(int j=1; j<= m_listplayers2.GetItemCount(); j++)
			{
				CString currentSelection1 = m_listplayers2.GetItemText(j-1, 1);
				if(currentSelection1 == name)
				{
					slots[i] = 1;
					if(Player[i].GetInjury() >= 5) injury = true;
				}
			}
		}
	}
	}
	int teamslots[3] = {0,1,1};
	bool roster_full = false;
	for(int i=1; i<=m_slots*2; i++)
	{
		if(teamslots[1] > 30 || teamslots[2] > 30) roster_full = true;
		if(roster_full == true) continue;
		int team = slots[i];
		if(Player[i].GetName() == "") continue;
		NewRoster[team*30+teamslots[team]] = Player[i];
		teamslots[team] = teamslots[team] + 1;
	}
	bool playerTrade = false;
	int computer = 1;
	if( (m_own[m_team1 + 1].m_number_picks_year[1]    + m_own[m_team2+1].m_number_proposed_picks_year[1] - m_own[m_team1+1].m_number_proposed_picks_year[1] ) > 6 ||
		(m_own[m_team1 + 1].m_number_picks_year[2]    + m_own[m_team2+1].m_number_proposed_picks_year[2] - m_own[m_team1+1].m_number_proposed_picks_year[2] ) > 6 ||
		(m_own[m_team1 + 1].m_number_picks_year[3]    + m_own[m_team2+1].m_number_proposed_picks_year[3] - m_own[m_team1+1].m_number_proposed_picks_year[3] ) > 6 ||
		(m_own[m_team2 + 1].m_number_picks_year[1]    + m_own[m_team1+1].m_number_proposed_picks_year[1] - m_own[m_team2+1].m_number_proposed_picks_year[1] ) > 6 ||
		(m_own[m_team2 + 1].m_number_picks_year[2]    + m_own[m_team1+1].m_number_proposed_picks_year[2] - m_own[m_team2+1].m_number_proposed_picks_year[2] ) > 6 ||
		(m_own[m_team2 + 1].m_number_picks_year[3]    + m_own[m_team1+1].m_number_proposed_picks_year[3] - m_own[m_team2+1].m_number_proposed_picks_year[3] ) > 6)
	{
		AfxMessageBox("Trade exceeds maximum draft picks allowed per year (6).", MB_OK);
		invalid = true;
	}
	else if(roster_full == true)
	{
		AfxMessageBox("Roster exceeds the maximum allowed.", MB_OK);
		invalid = true;
	}
	else if(m_salary_fit == false && m_salaries_match == TRUE)
	{
		AfxMessageBox("Trade does not qualify under salary cap rules.", MB_OK);
		invalid = true;
	}
	else if(m_listplayers1.GetItemCount() == 0 && m_listplayers2.GetItemCount() == 0)
	{
		AfxMessageBox("No players are involved in the trade.", MB_OK);
		invalid = true;
	}
	else if(team1control == "Computer" && team2control == "Computer")
	{
		AfxMessageBox("At least one team involved in a trade must be player controlled.", MB_OK);
		invalid = true;
	}
	else if(team1name == team2name)
		invalid = true;
	else if(team1control == "Player" && team2control == "Computer")
	{
		computerTeamName = team2name;
		computer = 2;
	}
	else if(team2control == "Player" && team1control == "Computer")
	{
		computerTeamName = team1name;
		computer = 1;
	}
	else if(team2control == "Player" && team1control == "Player")
		playerTrade = true;
	for(int team=1; team<=2; team++)
	{
		int ast_team = m_team1;
		if(team == 2) ast_team = m_team2;
	if(invalid == false)
	{
		for(int i=1; i<=480; i++)
		{
			int t = team1;
			if(team == 2) t = team2;
	        CPlayer m_player = FA[i];
            FA[i].SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_gm[t].m_scoring, m_gm[t].m_shooting, m_gm[t].m_rebounding, m_gm[t].m_passing, m_gm[t].m_defense);
	        FA[i].SetTradeTrueRating(0);
	        FA[i].SetAdjTradeValue(m_gm[t].m_pot1, m_gm[t].m_pot2, m_gm[t].m_effort);
		}

		int pg=2,sg=2,sf=2,pf=2,c=2;

		for(int i=1; i<teamslots[team]; i++)
		{
			if(NewRoster[team*30+i].GetPos() == "PG" && NewRoster[team*30+i].GetInjury() == 0) pg=pg-1;
			else if(NewRoster[team*30+i].GetPos() == "SG" && NewRoster[team*30+i].GetInjury() == 0) sg=sg-1;
			else if(NewRoster[team*30+i].GetPos() == "SF" && NewRoster[team*30+i].GetInjury() == 0) sf=sf-1;
			else if(NewRoster[team*30+i].GetPos() == "PF" && NewRoster[team*30+i].GetInjury() == 0) pf=pf-1;
			else if(NewRoster[team*30+i].GetPos() == " C" && NewRoster[team*30+i].GetInjury() == 0) c=c-1;
		}
		//if(m_slots == 20) {pg=0; sg=0; sf=0; pf=0; c=0;} //insure signings not needed nor allowed in offseason
		if( ((pg > 0 && m_control[ast_team] == "Computer") || (pg > 0 && m_ast_gm == TRUE) && playerTrade == false) && avg.m_settings.m_current_stage == 0)
		{
			int temp = pg;
			if(pg > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
				
					if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
						&& FA[n].GetPos() == "PG"
						&& Signed[n] == 0
						&& FA[n].GetName() != "" && m_checkCareer == FALSE) high = n;
					else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
						&& FA[n].GetPos() == "PG"
						&& Signed[n] == 0
						&& FA[n].GetName() != "" && m_checkCareer != FALSE) high = n;
				}
				if(high > 0 && pg>0)
				{
					NewRoster[team*30+teamslots[team]] = FA[high];
					NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
					NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
					NewRoster[team*30+teamslots[team]].SetJustSignedContracts();
					teamslots[team]=teamslots[team]+1;
					
					Signed[high] = team;
					pg = pg-1;
				}
			}
			}
		}
		if( ((sg > 0 && m_control[ast_team] == "Computer") || (sg > 0 && m_ast_gm == TRUE) && playerTrade == false ) && avg.m_settings.m_current_stage == 0)
		{
			int temp = sg;
			if(sg > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
						&& FA[n].GetPos() == "SG"
						&& Signed[n] == 0 && m_checkCareer == FALSE) high = n;
					else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
						&& FA[n].GetPos() == "SG"
						&& Signed[n] == 0 && m_checkCareer != FALSE) high = n;

				}
				if(high > 0 && sg>0)
				{
					NewRoster[team*30+teamslots[team]] = FA[high];
					NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
					NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
					NewRoster[team*30+teamslots[team]].SetJustSignedContracts();		
					teamslots[team]=teamslots[team]+1;
					Signed[high] = team;
					sg = sg-1;
				}
			}
			}
		}
		if( ((sf > 0 && m_control[ast_team] == "Computer") || (sf > 0 && m_ast_gm == TRUE) && playerTrade == false) && avg.m_settings.m_current_stage == 0)
		{
			int temp = sf;
			if(sf > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
						&& FA[n].GetPos() == "SF"
						&& Signed[n] == 0 && m_checkCareer == FALSE) high = n;
					else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
						&& FA[n].GetPos() == "SF"
						&& Signed[n] == 0 && m_checkCareer != FALSE) high = n;

				}
				if(high > 0 && sf>0)
				{
					NewRoster[team*30+teamslots[team]] = FA[high];
					NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
					NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
					NewRoster[team*30+teamslots[team]].SetJustSignedContracts();
					Signed[high] = team;
					teamslots[team]=teamslots[team]+1;
					sf = sf-1;
				}
			}
			}
		}
		if( ((pf > 0 && m_control[ast_team] == "Computer") || (pf > 0 && m_ast_gm == TRUE) && playerTrade == false) && avg.m_settings.m_current_stage == 0)
		{
			int temp = pf;
			if(pf > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
						&& FA[n].GetPos() == "PF"
						&& Signed[n] == 0 && m_checkCareer == FALSE) high = n;
					else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
						&& FA[n].GetPos() == "PF"
						&& Signed[n] == 0 && m_checkCareer != FALSE) high = n;
				}
				if(high > 0 && pf>0)
				{
					NewRoster[team*30+teamslots[team]] = FA[high];
					NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
					NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
					NewRoster[team*30+teamslots[team]].SetJustSignedContracts();
					Signed[high] = team;
					teamslots[team]=teamslots[team]+1;
					pf = pf-1;
				}
			}
			}
		}
		if( ((c > 0 && m_control[ast_team] == "Computer") || (c > 0 && m_ast_gm == TRUE) && playerTrade == false) && avg.m_settings.m_current_stage == 0)
		{
			int temp = c;
			if(c > 0)
			{
			for(int i=1; i<=temp; i++)
			{
				int high = 0;
				for(int n=1; n<=480; n++)
				{
					if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
						&& FA[n].GetPos() == " C"
						&& Signed[n] == 0 && m_checkCareer == FALSE) high = n;
					else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
						&& FA[n].GetPos() == " C"
						&& Signed[n] == 0 && m_checkCareer != FALSE) high = n;
				}
				if(high > 0 && c>0)
				{
					NewRoster[team*30+teamslots[team]] = FA[high];
					NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
					NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
					NewRoster[team*30+teamslots[team]].SetJustSignedContracts();
					Signed[high] = team;
					teamslots[team]=teamslots[team]+1;
					c = c-1;
				}
			}
			}

		}
		if((pg>0 || sg>0 || sf>0 || pf>0 || c>0) && playerTrade == false)//here
			tradeok = false;
		else if(playerTrade == false)
		{
			int sign = 12 - (teamslots[team]-1);
			if(sign > 0)
			{
				int temp = sign;
				if(sign > 0)
				{
				for(int i=1; i<=temp; i++)
				{
					int high = 0;
					for(int n=1; n<=480; n++)
					{
						if(FA[n].GetTradeTrueRating(m_checkCareer) >= FA[high].GetTradeTrueRating(m_checkCareer)
							&& FA[n].GetName()!=""
							&& Signed[n] == 0 && m_checkCareer == FALSE) high = n;
						else if(FA[n].GetTradeValue() >= FA[high].GetTradeValue()
							&& FA[n].GetName()!=""
							&& Signed[n] == 0 && m_checkCareer != FALSE) high = n;
					}
					if(high > 0 && sign>0)
					{
						NewRoster[team*30+teamslots[team]] = FA[high];
						NewRoster[team*30+teamslots[team]].m_previous_team = FA[high].m_current_team;
						NewRoster[team*30+teamslots[team]].m_current_team = ast_team;
						NewRoster[team*30+teamslots[team]].SetJustSignedContracts();
						Signed[high] = team;
						teamslots[team]=teamslots[team]+1;
						sign = sign-1;
					}
				}
				}
			}
		}
			

				
			
			for(int player=team*30+1; player<=team*30+30; player++)
			{
				int inj = NewRoster[player].GetInjury();//reset injuries
				NewRoster[player].SetTradeTrueRating(inj);//reset injuries
			}


			int scout = m_team1;
			if(team == 2) scout = m_team2;
			avg.SortTeamRoster(scout, team*30+1, team*30+30, NewRoster, false);

					//cut 15-20 slot
					for(int i=16;i<=20;i++)
					{
						//(m_slots == 15) continue;
						bool ok = true;//if already fa don't add again
						for(int p=1; p<=480; p++)
						{
							if(FA[p].GetName() == NewRoster[team*30+i].GetName() &&
								FA[p].GetMin() == NewRoster[team*30+i].GetMin()
								&& FA[p].GetName() != "")
							{
								ok = false;
								Signed[p] = 0;
							}
						}
						if(ok == true && NewRoster[team*30+i].GetName() != "")
						{
							//CPlayer m_player;
							temp_facount = temp_facount + 1;
							FA[temp_facount] = NewRoster[team*30+i];
							CPlayer tmp_player;
							NewRoster[team*30+i] = tmp_player;


							if(team == 1)
							{
								FA[temp_facount].m_team_paying = team1 + 1;
								FA[temp_facount].m_team_paying_name = m_leagueTeamNames[team1];
								FA[temp_facount].m_current_team = -1;
							}
							else
							{
								FA[temp_facount].m_team_paying = team2 + 1;
								FA[temp_facount].m_team_paying_name = m_leagueTeamNames[team2];
								FA[temp_facount].m_current_team = -1;
							}
							Signed[temp_facount] = team + 2;//player cut
						}
					}


	}
    }	

	active1 = 0;
	CPlayer* tmp_player = new CPlayer[61];
	double new_true_values[61];
	for(int tmp=0; tmp<=60; tmp++)
	{
		new_true_values[tmp] = 0;
		tmp_player[tmp] = NewRoster[30+tmp];
	}
	avg.ComputerRotationForTrades(tmp_player, new_true_values, 30, team1, team2);
	delete [] tmp_player;

	for(int i=1; i<=m_slots; i++)
	{

		CPlayer m_player = NewRoster[30 + i];
		if(m_player.m_games == 0) continue;
		double mn = double(m_player.GetMin()) / double(m_player.GetGames());
		double add = 0;


         
			add = new_true_values[i];

			if(m_player.GetActive() == 0 || active1 >= 15)
				add = 0;
			else
				active1 = active1 + 1;

			team1true = team1true + add;
	}


	active2 = 0;


	for(int i=1; i<=m_slots; i++)
	{

		CPlayer m_player = NewRoster[60 + i];
		if(m_player.m_games == 0) continue;
		double mn = double(m_player.GetMin()) / double(m_player.GetGames());
		double add = 0;


			add = new_true_values[30+i];

			if(m_player.GetActive() == 0 || active2 >= 15)
				add = 0;
			else
				active2 = active2 + 1;

			team2true = team2true + add;
	}





	//pick value adjust for team quality , better teams crave picks less


	if(active1 < 8) team1true = 12 * avg.m_avg_tru[0] +  m_own[m_team2+1].m_total_true_in_trade / m_own[m_team2+1].m_total_years_in_trade;
	if(active2 < 8) team2true = 12 * avg.m_avg_tru[0] +  m_own[m_team1+1].m_total_true_in_trade / m_own[m_team1+1].m_total_true_in_trade;




	double rating1 = avg.m_avg_tru[0] / avg.m_team_avg_tru[m_team1+1];	
   	if(rating1 > 1) rating1 = 1;

	double rating2 = avg.m_avg_tru[0] / avg.m_team_avg_tru[m_team2+1];	
	if(rating2 > 2) rating2 = 1; 



	
	double pick_diff = m_own[m_team1+1].m_draft_pick_addition * rating2 - m_own[m_team2+1].m_draft_pick_addition * rating1;
	double tru_factor_1 = m_own[m_team1+1].m_total_true_in_trade;
	double tru_factor_2 = m_own[m_team2+1].m_total_true_in_trade;





	double under_paid_1 =	tru_factor_1 - (double)m_own[m_team1+1].m_total_salary_in_trade / 100;
	double under_paid_2 =	tru_factor_2 - (double)m_own[m_team2+1].m_total_salary_in_trade / 100;

	double value_factor_1 = 0;
	double value_factor_2 = 0;
	double value = 0;

	value_factor_1 = under_paid_1*400 / (double)avg.m_finance[m_team2].m_current_value;
	value_factor_2 = under_paid_2*400 / (double)avg.m_finance[m_team1].m_current_value;
	value = (value_factor_1 - value_factor_2) / 2;



	bool pick_only = false;//giving away picks!
	bool picks_only = false;//picks only
	if(team1true == originalteam1true &&
		team2true == originalteam2true && pick_diff != 0) 
	{
		originalteam1true = originalteam1true * (1 + pick_diff*3 / 100);
		originalteam2true = originalteam2true * (1 - pick_diff*3 / 100);
		picks_only = true;

	}

	team1true = team1true - (pick_diff/2) - value;
	team2true = team2true + (pick_diff/2) + value;

	double d1 = fabs(team1true - originalteam1true); 
	double d2 = fabs(team2true - originalteam2true);

	if(tru_factor_1 == 0 && tru_factor_2 == 0 && pick_diff > 0 && team1control == "Player" 
		&& m_own[m_team2+1].m_draft_pick_addition == 0
		&& m_own[m_team1+1].m_draft_pick_addition != 0	 
		) pick_only = true;
	else if(tru_factor_1 == 0 && tru_factor_2 == 0 && pick_diff < 0 && team2control == "Player"
		&& m_own[m_team1+1].m_draft_pick_addition == 0
		&& m_own[m_team2+1].m_draft_pick_addition != 0
		) pick_only = true;

	if(tru_factor_1 == 0 && tru_factor_2 == 0 && pick_diff > 15) pick_only = true;//lopsided trade involving just picks must be ok 


	
	double fa1=1.02,fa2=.98;

	if(pick_diff != 0) {fa1=1.05; fa2=.97;}


	if(picks_only == true) 
	{
		fa1= 1.15;
		fa2=.90;
	}

	if(team1control == "Player" && team2control == "Player")
		tradeok = true;
	else if(pick_only == true)
		tradeok = true;
	else if(team1control == "Player" && team2control == "Computer" && team2true >= (originalteam2true * fa1) && team1true <= (originalteam1true * fa2))
		tradeok = true;
	else if(team1control == "Player" && team2control == "Computer" && team2true >= originalteam2true  && team1true <= originalteam1true && d2 > d1*2)
		tradeok = true;
	else if(team2control == "Player" && team1control == "Computer" && team1true >= (originalteam1true * fa1) && team2true <= (originalteam2true * fa2))
		tradeok = true;
	else if(team2control == "Player" && team1control == "Computer" && team1true >= originalteam1true && team2true <= originalteam2true && d1 > d2*2)
		tradeok = true;


	int result  = 0;

	int response = 0;// reaction by computer
	if(team1control == "Player")
	{
		double imp = team2true / originalteam2true;
		if(imp > 1.20) response = 6;
		else if(imp > 1.04) response = 1;
		else if(imp > .98) response = 2;
		else if(imp > .94) response = 3;
		else if(imp > .90) response = 4;
		else response = 5;

	}
	else if(team2control == "Player")
	{
		double imp = team1true / originalteam1true;
		if(imp > 1.20) response = 6;
		else if(imp > 1.03) response = 1;
		else if(imp > .98) response = 2;
		else if(imp > .94) response = 3;
		else if(imp > .90) response = 4;
		else response = 5;

	}


	if(tradeok == true && invalid == false)
	{
		if(team1control == "Player" && team2control == "Player")
		{
			CString message;
			AfxFormatString2( message, IDS_STRING_MESSAGE_PLAYER_TRADEOK, team1name, team2name); 
 			result = MessageBox(message, "", MB_OKCANCEL);		
		}
		else if(injury == true)
		{
			CString message = "Trade refused because of player injury of more than four games.";
 			result = MessageBox(message, "", MB_OK);		
			result = IDCANCEL;//trade not OK
		}
		else
		{
		CString message, str;
		if(response == 6) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELG, str); 
		else AfxFormatString1( message, IDS_STRING_MESSAGE_TRADEOK, computerTeamName); 
		result = MessageBox(message, "", MB_OKCANCEL);		
		}
	}
	else if(invalid == false)
	{
		CString message, str;
		if(response == 1) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELA, str); 
		else if(response == 2) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELB, str); 
		else if(response == 3) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELC, str); 
		else if(response == 4) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELD, str); 
		else if(response >= 5) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELF, str); 
//		else if(response == 6) AfxFormatString1( message, IDS_STRING_MESSAGE_TRADECANCELG, str); 
		MessageBox(message, computerTeamName, MB_OK);		
	}


	if(result == IDOK)
	{

		for(int i=0; i<=32; i++)
		{
			m_future.m_own[i] = m_own[i];
		}
			m_future.SetDraftChart(m_team1+1, m_team2+1);
			m_future.SetDraftChart(m_team2+1, m_team1+1);

		for(int i=0; i<=32; i++)
		{
			m_own[i] = m_future.m_own[i];
		}

		WriteTransaction(Player, Signed);

			
		
		ClearDraftPickData(1, 32, 0, 1, 2);
		ListOwnDraftPicks(true, true);


		CPlayer* tm_player = new CPlayer[61];
		for(int tmp=0; tmp<=60; tmp++)
		{
			tm_player[tmp] = NewRoster[30+tmp];
		}
		avg.ComputerSortsRosterAfterTrades(tm_player, 30);


		for(int tm=1; tm<=2; tm++)
		{				
			int t = team1;//update team on left
			if(tm == 2) t = team2;//or right
			for(int  i=1; i<=30; i++)//set before adjusting
			{
				PlayerUpdate[t*m_slots+i] = tm_player[(tm-1)*30+i];
				PlayerUpdate[t*m_slots+i].m_current_team = t;
				PlayerUpdate[t*m_slots+i].SetTradeTrueRating(0);

			}
		}
		
		delete [] tm_player;






	for(int i=0; i<=31; i++)
	{	
		for(int j=1; j<=m_slots; j++)
		{	
			PlayerList[i][j] = PlayerUpdate[i*m_slots+j];
			PlayerList[i][j].m_team_paying = i + 1;
			PlayerList[i][j].m_team_paying_name = m_leagueTeamNames[i];
		}
	}
	m_listroster1.DeleteAllItems();
	m_listroster2.DeleteAllItems();
	for(int  i = 1; i <= 2; i++)
	{
	for(int  j = 1; j <= m_slots; j++)
	{
		
		int index = m_listteams1.GetCurSel();
		if(i == 2) index = m_listteams2.GetCurSel();
		CPlayer m_playerInjury = PlayerList[index][j];
		CString Po = m_playerInjury.GetPos();
		CString Na = m_playerInjury.GetName();
		int age = m_playerInjury.GetAge();
		CString Ag;
		Ag.Format("%d", age);
		int sal = m_playerInjury.m_current_yr_salary;
		CString Sa;
		Sa.Format("%.2f", (double)sal/100);
		int inj = m_playerInjury.GetInjury();
		CString In;
		In.Format("%d", inj);
		if(Na == "")
		{
			CPlayer m_player;// clear blank players
			Player[(i-1)*m_slots+j] = m_player;
			PlayerList[index][j] = m_player;
		}
		else
		{



		if(i == 1)
		{
				m_listroster1.InsertItem(j-1,Po);
				m_listroster1.SetItemText(j-1,1,Na);			
				m_listroster1.SetItemText(j-1,2,Ag);			
				m_listroster1.SetItemText(j-1,3,Sa);			
				m_listroster1.SetItemText(j-1,4,In);			
			
				m_listroster1.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
				m_listroster1.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
				m_listroster1.EnsureVisible(0, TRUE);			
		}

		else
		{
				m_listroster2.InsertItem(j-1,Po);
				m_listroster2.SetItemText(j-1,1,Na);			
				m_listroster2.SetItemText(j-1,2,Ag);			
				m_listroster2.SetItemText(j-1,3,Sa);			
				m_listroster2.SetItemText(j-1,4,In);			
			
				m_listroster2.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
				m_listroster2.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
				m_listroster2.EnsureVisible(0, TRUE);			
		}

		}
	}
	}
	m_listplayers1.DeleteAllItems();
	m_listplayers2.DeleteAllItems();
	m_listroster1.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster1.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster1.EnsureVisible(0, TRUE);

	m_listroster2.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster2.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster2.EnsureVisible(0, TRUE);


	m_listfa.DeleteAllItems();
  	int count = 0;
	
	for(int i=1; i<=480; i++)
	{
		if(Signed[i] == 0 || Signed[i] == 3 || Signed[i] == 4)
		{
			count = count + 1; 
			NewFA[count] = FA[i];
		}
	}

	for(int i=count+1; i<=480; i++)//clear the rest
	{	
		CPlayer m_player;
		NewFA[i] = m_player;
	}

	facount = temp_facount;
	int cou = 0;
	for(int i=1; i<=480; i++)
	{
		FA[i] = NewFA[i];
		if(FA[i].GetName() != "") 
		{
			temp_facount = temp_facount+1;
			CString Na = FA[i].GetName();
			CString Po = FA[i].GetPos();

			int age = FA[i].m_age;
			CString Sa = DisplayFaSalarySeeking(i);
			int inj = FA[i].GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listfa.InsertItem(cou,Po);
			m_listfa.SetItemText(cou,1,Na);			
			m_listfa.SetItemText(cou,2,Ag);			
			m_listfa.SetItemText(cou,3,Sa);			
			m_listfa.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;
		}

	}

			m_listfa.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
			m_listfa.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
			m_listfa.EnsureVisible(0, TRUE);			

	OnSelchangeCombo3(); 
	}
	else//restore fa list
	{
		for(int i=1; i<=480; i++)
		{
			FA[i] = OrigFA[i];
		}


	}
	m_listfa.SetItemState(0, LVIS_SELECTED,LVIS_SELECTED);
	m_listfa.SetItemState(0, LVIS_FOCUSED,LVIS_FOCUSED);
	m_listfa.EnsureVisible(0, TRUE);

	delete [] Player;
	delete [] PlayerUpdate;
	delete [] NewFA;
	delete [] OrigFA;
	delete [] NewRoster;


}
 

void CTradeDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_listteams3.GetCurSel();
	if(index >= 0)
	{
		CString TeamControl;
  		TeamControl = m_control[index];
		if(TeamControl == "Computer")
		{
			TeamControl = "Player";
		}
		else
		{
			TeamControl = "Computer";
		}

		m_control[index] = TeamControl;


		m_listcontrol.ResetContent();
		m_listcontrol.AddString(TeamControl);
	}	
}






void CTradeDlg::OnButtonRelease() 
{
	// TODO: Add your control notification handler code here
int player = m_listroster3.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;
if(m_control[m_team3index] == "Player" && player >=1)
{
	int team = m_team3index;
	CString teamName = m_leagueTeamNames[team];
	bool ok = true;
	for(int i = 1; i <= 480; ++i)
	{
		CString Name = FA[i].GetName();
		if(PlayerList[team][player].GetName() == Name && Name != "") ok = false;//can't sign from same team
	}

	if(facount<480 && ok == true) //free agent count < 96(agents allowed) so
	{
	//release from team roster
	facount = facount+1;
	FA[facount] = PlayerList[team][player];

	FA[facount].m_team_paying = team + 1;
	FA[facount].m_team_paying_name =m_leagueTeamNames[team];
	FA[facount].m_current_team = -1;


	CString playerRelease = FA[facount].GetPos() + " " + FA[facount].GetName();
	WriteSign(team, facount, false);
	CPlayer m_player;
	for(int i=player; i<=m_slots-1; i++)
	{
		PlayerList[team][i] = PlayerList[team][i+1];
	}
	PlayerList[team][m_slots] = m_player;

	m_listroster3.DeleteAllItems();
	//display newe roster
	for(int i = 1; i <= m_slots; ++i)
	{
		CPlayer m_player;
		m_player = PlayerList[team][i];
		CString Stats;
		CString Na = m_player.GetName();
		CString Po = m_player.GetPos();


		if(Na == "") continue;
			int age = m_player.m_age;
			int sal = m_player.m_current_yr_salary;
			CString Sa;
			Sa.Format("%.2f", (double)sal/100);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listroster3.InsertItem(i-1,Po);
			m_listroster3.SetItemText(i-1,1,Na);			
			m_listroster3.SetItemText(i-1,2,Ag);			
			m_listroster3.SetItemText(i-1,3,Sa);			
			m_listroster3.SetItemText(i-1,4,In);			
			
					
	

	}
	//display newe free agent list
	m_listfa.DeleteAllItems();
	int cou = 0;
	for(int i = 1; i <= 480; i++)
	{
		CPlayer m_player = FA[i];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
			CString Sa = DisplayFaSalarySeeking(i);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listfa.InsertItem(cou,Pos);
			m_listfa.SetItemText(cou,1,Name);			
			m_listfa.SetItemText(cou,2,Ag);			
			m_listfa.SetItemText(cou,3,Sa);			
			m_listfa.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;
		





	}

//	m_listroster3.SetCurSel(0);
	m_listroster3.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster3.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster3.EnsureVisible(0, TRUE);
	//display newe rosters used in trading
	OnSelchangeCombo1(); 
	OnSelchangeCombo2(); 
//	m_listfa.SetCurSel(0);
	m_listfa.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listfa.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listfa.EnsureVisible(0, TRUE);

	}

}
else if(m_control[m_team3index] != "Player")
	AfxMessageBox("Team releasing a player must be player controlled.", MB_OK);
}

void CTradeDlg::OnButtonSign() 
{
	// TODO: Add your control notification handler code here
int fa = m_listfa.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;

//DisplayFaSalarySeeking(fa);


if(m_control[m_team3index] == "Player" && facount >= 1 && fa >=1)
{



	int team = m_team3index;
	CString teamName = m_leagueTeamNames[team];
	int players = 0;
	for(int i = 1; i <= m_slots; i++)
	{
		CPlayer m_player;
 		m_player = PlayerList[team][i];
		CString Name;
		Name = m_player.GetName();
		if(Name != "") players = players + 1;
	}

	if(players < 15)
	{
	//sign player
	PlayerList[team][players + 1] = FA[fa];
	PlayerList[team][players + 1].SetActive(TRUE);
//	PlayerList[team][players + 1].m_previous_team = FA[high].m_current_team;
	PlayerList[team][players + 1].m_current_team = team;
	PlayerList[team][players + 1].m_team_paying = team + 1;
	PlayerList[team][players + 1].m_team_paying_name = m_leagueTeamNames[team];


	PlayerList[team][players + 1].SetJustSignedContracts();
	CString playerSign = FA[fa].GetPos() + " " + FA[fa].GetName();
	WriteSign(team, fa, true);
	facount = facount - 1;
	CPlayer m_player;
	for(int i=fa; i<=479; i++)
	{
		FA[i] = FA[i+1];
	}
	FA[480] = m_player;

	m_listfa.DeleteAllItems();
	m_listroster3.DeleteAllItems();

	int cou = 0;
	//display newe free agent list
	for(int i = 1; i <= 480; i++)
	{

	CPlayer m_player = FA[i];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
			CString Sa = DisplayFaSalarySeeking(i);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listfa.InsertItem(cou,Pos);
			m_listfa.SetItemText(cou,1,Name);			
			m_listfa.SetItemText(cou,2,Ag);			
			m_listfa.SetItemText(cou,3,Sa);			
			m_listfa.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;
		
	}











	//display newe team roster
	cou = 0;
	for(int i = 1; i <= 15; ++i)
	{
	//	CPlayer m_player = FA[i];
		CPlayer m_player = PlayerList[team][i];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
//			CString Sa = DisplayFaSalarySeeking(i);
			int sal = m_player.m_current_yr_salary;
			CString Sa;
			Sa.Format("%.2f", (double)sal/100);

			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listroster3.InsertItem(cou,Pos);
			m_listroster3.SetItemText(cou,1,Name);			
			m_listroster3.SetItemText(cou,2,Ag);			
			m_listroster3.SetItemText(cou,3,Sa);			
			m_listroster3.SetItemText(cou,4,In);			
			
			cou = cou + 1;
//			m_listroster3.AddString(Stats);
	}
//	m_listfa.SetCurSel(0);	
	m_listfa.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listfa.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listfa.EnsureVisible(0, TRUE);

		
	//display newe rosters used in trading
//	DisplayFaSalarySeeking(fa);


	OnSelchangeCombo1(); 
	OnSelchangeCombo2(); 


	}
}
else if(m_control[m_team3index] != "Player")
	AfxMessageBox("Team signing a free agent must be player controlled.", MB_OK);
}


void CTradeDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_LEAGUE_TRADE);
//	HtmlHelp(NULL, "jumpshot.chm::/html/proposetrades.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

	
}

BOOL CTradeDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_LEAGUE_TRADE);
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/proposetrades.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

}








void CTradeDlg::WriteTransaction(CPlayer NewTeam[31], int Signed[481])
{



	CString temp, temp1, string, string1;
	int mo = m_currentMonth + 10;
	if(mo > 12) mo = mo - 12;
	int da = m_currentDay + 1;
	int yr = m_current_year;
	int ty = 2;//trade
	int team1 = m_team1+1;
	int team2 = m_team2+1;
	
	string.Format("%2d%2d%4d%2d", mo, da, yr, ty);                          
	string1.Format("%2d%2d%4d%2d", mo, da, yr, ty);
	
	
	for(int i=1; i<=m_slots; i++)
	{
		int pic = 0;
		if(slots[i] == 2)
		{
			CString id;
			id.Format("%d%6d%6d%6d", pic, team1, team2, NewTeam[i].GetID());
			string = string + id;
		}
	}
	
	CString pick_string1, pick_string2;

//	int pick = value_picks1[0];
	for(int i=1; i<=m_own[m_team1+1].m_number_proposed_picks; i++)
	{
	int pick = m_own[m_team1+1].m_proposed_picks[i];
	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);
	int pic = 1;
    int te1 = p;
	if(y > 0 || r > 0 || te1 > 0)
		pick_string1.Format("%d%6d%6d%6d", pic, m_current_year - 1 + y, r, te1);

	string = string + pick_string1;
	}
	for(int i=(m_slots+1); i<=(m_slots*2); i++)
	{
		int pic = 0;
		if(slots[i] == 1)
		{
			CString id;
			id.Format("%d%6d%6d%6d", pic, team2, team1, NewTeam[i].GetID());
			string1 = string1 + id;
		}
	}
	
	//pick = value_picks2[0];
	for(int i=1; i<=m_own[m_team2+1].m_number_proposed_picks; i++)
	{

	int pick = m_own[m_team2+1].m_proposed_picks[i];
	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);
	int pic = 1;
    int te2 = p;
	if(y > 0 || r > 0 || te2 > 0)
		pick_string2.Format("%d%6d%6d%6d", pic, m_current_year - 1 + y, r, te2);

	string1 = string1 + pick_string2;
	}
	


//	int more = 0;
//	for(int i=1; i<=480; i++)
//	{
//		if(Signed[i] > 0) more = more + 1;
//	}
//	string1 = string1 + " to the " + team1;
	//char s[17];
	//CString pFileName = m_path + m_leagueName + ".tra";
	//CFile file(	pFileName, CFile::modeRead);
	//int bytes = file.Read(s, 16);
	//s[bytes] = 0;
//	i = atoi(s) + 2 + more;
//	file.Close();
//	CFile f(pFileName, CFile::modeWrite);
//	CString buffer;
//	buffer.Format("%d", i);
//	buffer = buffer + "                 ";
//	f.Write( buffer, 16);		
//	int seek = (i-2-more)*128+17;
//	f.Seek( seek, CFile::begin );	
//	string = string + "                                                                                                                                 ";
//	string1 = string1 + "                                                                                                                                 ";
//	f.Write( string, 128);
//	f.Write( string1, 128);

	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = string;

	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = string1;



	ty = 3;//sign
	for(int i=1; i<=480; i++)
	{
		CString moreString;
		CString nm = FA[i].GetPos() + " " + FA[i].GetName();
		int id = FA[i].GetID();
		if(Signed[i] == 1)
		{
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);
		}
		else if(Signed[i] == 2)
		{
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team2, id);
		}
		else if(Signed[i] == 3)
		{
			ty = 4;//release
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);

		}
		else if(Signed[i] == 4)
		{
			ty = 4;
			moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team2, id);

		}
		if(Signed[i] > 0)
		{
			//moreString = moreString + "                                                                                                                                ";
			//f.Write(moreString, 128);
		avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
		avg.m_trans_str[avg.m_settings.m_number_transactions] = moreString;


		}
	}
//	f.Close();

}

void CTradeDlg::OnOK() 
{
	// TODO: Add extra validation here


int result = AfxMessageBox("Are you sure you want to save the player transactions?",
						   MB_YESNO);
if(result == IDYES) CDialog::OnOK();



}

void CTradeDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	//(m_length <= 72000)
	//
	int result = AfxMessageBox("Any transactions made will be lost.\n Are you sure you want to cancel?",
						   MB_YESNO);
	if(result == IDYES) 
	{

	//if(m_seek != avg.m_settings.m_number_transactions)
	//{

		avg.m_settings.m_number_transactions = m_seek;//reset trans count
	//CString pFileName = m_path + m_leagueName + ".tra";
	//CFile f(pFileName, CFile::modeWrite);
	//CString buffer;
	//buffer.Format("%d", m_seek);
	//buffer = buffer + "                 ";
	//f.Write( buffer, 16);		
	//int seek = m_seek*128+17;
	//for(int i=seek; i<=64000; i=i+128)
	//{
	//	CString string = "                                                                                                                                 ";
	//	f.Seek( i, CFile::begin );	
	//	f.Write( string, 128);
	//}



	//}
		CDialog::OnCancel();
	}
	//
	//else
	  //  CDialog::OnCancel();

}

void CTradeDlg::WriteSign(int team, int player_index, bool sign)
{
	int mo = m_currentMonth + 10;
	if(mo > 12) mo = mo - 12;
	int da = m_currentDay + 1;
	int yr = m_current_year;

	//char s[17];
	//CString pFileName = m_path + m_leagueName + ".tra";
	//CFile file(	pFileName, CFile::modeRead);
	//int bytes = file.Read(s, 16);
	//s[bytes] = 0;
	//int i = atoi(s) + 1;
	//file.Close();
	//CFile f(pFileName, CFile::modeWrite);
	//CString buffer;
	//buffer.Format("%d", i);
	//buffer = buffer + "                 ";
	//f.Write( buffer, 16);		
	//int seek = (i-1)*128+17;
	//f.Seek( seek, CFile::begin );	
	int ty = 3;
	if(sign != true) ty = 4;



	int team1 = team + 1;
	CString moreString;
	int id = FA[player_index].GetID();
	moreString.Format("%2d%2d%4d%2d%2d%6d", mo, da, yr, ty, team1, id);
	//moreString = moreString + "                                                                                                                                ";

	avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
	avg.m_trans_str[avg.m_settings.m_number_transactions] = moreString;


	//f.Write(moreString, 128);
	//f.Close();







}



void CTradeDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
//	delete [] m_standings;
}


void CTradeDlg::OnButtonTeam1() 
{
	int m_index = 0;
	if(m_listroster1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
		m_index = m_listroster1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;
		CPlayer m_player = PlayerList[m_team1index][m_index];


		CString name = m_player.GetName();
		int salary = m_player.m_current_yr_salary;
		bool OK = true;
		if(m_listplayers1.GetItemCount() > 0)
		{
			for(int i=1; i<= m_listplayers1.GetItemCount(); i++)
			{
				CString currentSelection = m_listplayers1.GetItemText(i-1, 1);
				if(currentSelection == name) OK = false;
			}
		}
		if(OK == true && m_listplayers1.GetItemCount() < 5)
		{
			//m_listplayers1.AddString(name);
			int cou = m_listplayers1.GetItemCount();
			m_listplayers1.InsertItem(cou,m_player.GetPos());
			m_listplayers1.SetItemText(cou,1,m_player.m_name);			



			m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_gm[m_team2index].m_scoring, m_gm[m_team2index].m_shooting, m_gm[m_team2index].m_rebounding, m_gm[m_team2index].m_passing, m_gm[m_team2index].m_defense);
			m_player.SetTradeTrueRating(0);
			m_player.SetAdjTradeValue(m_gm[m_team2index].m_pot1, m_gm[m_team2index].m_pot2, m_gm[m_team2index].m_effort);


				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

			int rem_sal = m_player.m_remaining_salary;
			if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;

			m_own[m_team1index+1].m_salary_in_trade = m_own[m_team1index+1].m_salary_in_trade + salary;

			m_own[m_team1index+1].m_total_salary_in_trade =
					m_own[m_team1index+1].m_total_salary_in_trade 
					+ rem_sal;

				m_own[m_team1index+1].m_total_years_in_trade =
					m_own[m_team1index+1].m_total_years_in_trade + yrs_left;


			m_own[m_team1index+1].m_total_true_in_trade = 
					m_own[m_team1index+1].m_total_true_in_trade 
					+  m_player.GetTradeTrueRating(m_checkCareer) * yrs_left; 
		}




	}

	DisplayTradeSalaries();

}

void CTradeDlg::OnButtonTeam2() 
{
	int m_index = 0;
	if(m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
		m_index = m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;
		CPlayer m_player = PlayerList[m_team2index][m_index];

		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_gm[m_team1index].m_scoring, m_gm[m_team1index].m_shooting, m_gm[m_team1index].m_rebounding, m_gm[m_team1index].m_passing, m_gm[m_team1index].m_defense);
		m_player.SetTradeTrueRating(0);
		m_player.SetAdjTradeValue(m_gm[m_team1index].m_pot1, m_gm[m_team1index].m_pot2, m_gm[m_team1index].m_effort);



		CString name = m_player.GetName();
		int salary = m_player.m_current_yr_salary;
		bool OK = true;
		if(m_listplayers2.GetItemCount() > 0)
		{
			for(int i=1; i<= m_listplayers2.GetItemCount(); i++)
			{
				CString currentSelection = m_listplayers2.GetItemText(i-1, 1);
				if(currentSelection == name) OK = false;
			}
		}
		if(OK == true && m_listplayers2.GetItemCount() < 5)
		{
//			m_listplayers2.AddString(name);
			//m_listplayers1.AddString(name);
			int cou = m_listplayers2.GetItemCount();
			m_listplayers2.InsertItem(cou,m_player.GetPos());
			m_listplayers2.SetItemText(cou,1,m_player.m_name);			


				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

	int rem_sal = m_player.m_remaining_salary;
			if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;

			m_own[m_team2index+1].m_salary_in_trade = m_own[m_team2index+1].m_salary_in_trade + salary;
			m_own[m_team2index+1].m_total_salary_in_trade =
					m_own[m_team2index+1].m_total_salary_in_trade 
					+ rem_sal;

				m_own[m_team2index+1].m_total_years_in_trade =
					m_own[m_team2index+1].m_total_years_in_trade + yrs_left;

			m_own[m_team2index+1].m_total_true_in_trade = 
					m_own[m_team2index+1].m_total_true_in_trade 
					+  m_player.GetTradeTrueRating(m_checkCareer) * yrs_left;
		}




	}

	DisplayTradeSalaries();		
}

HBRUSH CTradeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
          return hbr;
     } 


	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	//	pDC->SetTextColor(RGB(0,0,0));
	//if (nCtlColor == CTLCOLOR_LISTBOX)
	//{
	//pDC->SetBkMode(TRANSPARENT);
	//	pDC->SetBkColor(RGB(255,255,226));	
	// TODO: Return a different brush if the default is not desired
	//return HBRUSH(myBrush);
	//}
	//return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 
}



void CTradeDlg::ListOwnDraftPicks(bool t1 , bool t2)
{
	int team1 = m_listteams1.GetCurSel() + 1;
	int team2 = m_listteams2.GetCurSel() + 1;
	if(t1 == true) m_list_team1_draft.DeleteAllItems();
	if(t2 == true) m_list_team2_draft.DeleteAllItems();
		int cou1 = 0, cou2 = 0;
		for(int y=1; y<=3; y++)
		{
			for(int r=1; r<=2; r++)
			{
				for(int p=1; p<=32; p++)
				{
					if(y==1 && m_slot_used[r][p] > 0) continue;

					int t = m_own[0].m_draft_chart[y][r][p];

					if(t == 0) t = p;



					CString string1, string2;
					
					if(t == team1 && t > 0 && t1 == true)
					{
						string1.Format("%d round %d", m_current_year - 1 + y, r);

						//m_list_team1_draft.AddString(string1);
						m_list_team1_draft.InsertItem(cou1,string1);
						CString str;
						str.Format("%s (%d-%d)",m_leagueTeamNames[p-1], avg.m_standings[p-1].m_win, avg.m_standings[p-1].m_loss);
						m_list_team1_draft.SetItemText(cou1,1,str);			
						cou1 = cou1 + 1;
						m_own[team1].m_number_actual_picks = m_own[team1].m_number_actual_picks + 1;
						int count = m_own[team1].m_number_actual_picks;
						m_own[team1].m_actual_picks[count] = y*1000 + r*100+p;
						m_own[team1].m_number_picks_year[y] = m_own[team1].m_number_picks_year[y] + 1;

					}
					else if(t == team2 && t > 0 && t2 == true)
					{
						string2.Format("%d round %d", m_current_year - 1 + y, r);
						m_list_team2_draft.InsertItem(cou2,string2);
						CString str;
						str.Format("%s (%d-%d)",m_leagueTeamNames[p-1], avg.m_standings[p-1].m_win, avg.m_standings[p-1].m_loss);
						m_list_team2_draft.SetItemText(cou2,1,str);			
						cou2 = cou2 + 1;
						//m_list_team2_draft.AddString(string2);
						m_own[team2].m_number_actual_picks = m_own[team2].m_number_actual_picks + 1;
						int count = m_own[team2].m_number_actual_picks;
						m_own[team2].m_actual_picks[count] = y*1000 + r*100+p;
						m_own[team2].m_number_picks_year[y] = m_own[team2].m_number_picks_year[y] + 1;
					}




					
				}
			}
		}

}

void CTradeDlg::OnButtonAddPick1() 
{
	// TODO: Add your control notification handler code here
	int team1 = m_listteams1.GetCurSel() + 1;
	int team2 = m_listteams2.GetCurSel() + 1;

	if(m_list_team1_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
		int index = m_list_team1_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);

		CString string = m_list_team1_draft.GetItemText(index, 0);
		CString string2 = m_list_team1_draft.GetItemText(index, 1);
		

		bool OK = true;
		if(m_listplayers1.GetItemCount() > 0)
		{
			for(int i=1; i<= m_listplayers1.GetItemCount(); i++)
			{
				CString currentSelection = m_listplayers1.GetItemText(i-1, 0);
				CString currentSelection2 = m_listplayers1.GetItemText(i-1, 1);
				if((currentSelection + currentSelection2) == (string + string2)) OK = false;
			}
		}
		if(OK == true && m_listplayers1.GetItemCount() < 5)
		{
			int cou = m_listplayers1.GetItemCount();
			m_listplayers1.InsertItem(cou,string);
			m_listplayers1.SetItemText(cou,1,string2);			

			int index = m_list_team1_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
			int count = m_listteams1.GetCount();
			int count_proposed = m_listplayers1.GetItemCount();
			SetProposedPicks(index, team1, team2);
			m_draft_choice[1][count_proposed] = m_own[team1].m_actual_picks[index];
		}
	}


}

void CTradeDlg::OnButtonAddPick2() 
{
	// TODO: Add your control notification handler code here
	int team1 = m_listteams1.GetCurSel() + 1;
	int team2 = m_listteams2.GetCurSel() + 1;

	if(m_list_team2_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
		int index = m_list_team2_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);

		CString string = m_list_team2_draft.GetItemText(index, 0);
		CString string2 = m_list_team2_draft.GetItemText(index, 1);

		bool OK = true;
		if(m_listplayers2.GetItemCount() > 0)
		{
			for(int i=1; i<= m_listplayers2.GetItemCount(); i++)
			{
				CString currentSelection = m_listplayers2.GetItemText(i-1, 0);
				CString currentSelection2 = m_listplayers2.GetItemText(i-1, 1);
				if((currentSelection + currentSelection2) == (string + string2)) OK = false;

			}
		}
		if(OK == true && m_listplayers2.GetItemCount() < 5)
		{
			int cou = m_listplayers2.GetItemCount();
//			m_listplayers1.AddString(string);
			m_listplayers2.InsertItem(cou,string);
			m_listplayers2.SetItemText(cou,1,string2);			


//			m_listplayers1.InsertItem(0,string);
//			m_listplayers1.SetItemText(0,1,);			



			int index = m_list_team2_draft.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
			int count = m_listteams2.GetCount();
			int count_proposed = m_listplayers2.GetItemCount();


			SetProposedPicks(index, team2, team1);
			m_draft_choice[2][count_proposed] = m_own[team2].m_actual_picks[index];


		}
	}


	
}

void CTradeDlg::SetProposedPicks(int index, int i, int o_i)
{
	

	int pick = m_own[i].m_actual_picks[index];
	int y = pick / 1000;
	int r = (pick - y*1000) / 100;
	int p = pick - (y*1000 + r*100);
	double tru_f = avg.m_avg_tru[0] + (avg.m_team_avg_tru[p] - avg.m_avg_tru[0])*2;
	if(tru_f < 2) tru_f = 2;
	double ro = (double)r;
	if(r==2) ro = (double)3;
	double rating = avg.m_avg_tru[0] / tru_f / ro * (4/(3+(double)y));

	int total_g = avg.m_standings[p-1].m_win + avg.m_standings[p-1].m_loss;
	double pct = 1;
	if(total_g > 0)
		pct = (double)avg.m_standings[p-1].m_win / ((double) + avg.m_standings[p-1].m_win + (double)avg.m_standings[p-1].m_loss);
	int hi_g = avg.m_sched.m_games_in_season;
	double f = (double)total_g / (double)hi_g;
	if(f > 1) f=1;
	double nu = rating*(f*(1-pct)*2) + rating*(1-f);
	if(nu > 2) nu = 2;

	double pick_value = nu * avg.m_avg_tru[0];


	m_own[i].m_number_proposed_picks = m_own[i].m_number_proposed_picks + 1;
	m_own[i].m_number_proposed_picks_year[y] = m_own[i].m_number_proposed_picks_year[y] + 1;
	m_own[i].m_draft_pick_addition = m_own[i].m_draft_pick_addition + pick_value;	
	m_own[i].m_proposed_picks[m_own[i].m_number_proposed_picks] = m_own[i].m_actual_picks[index];
//	m_own[o_i].m_number_picks_year[y] = m_own[o_i].m_number_picks_year[y] + 1;
	
}

void CTradeDlg::DisplayTradeSalaries()
{
	int s1 = m_own[m_team1index+1].m_salary_in_trade;
	int s2 = m_own[m_team2index+1].m_salary_in_trade;
	double sa1 = (double)s1;
	double sa2 = (double)s2;
	m_salary_fit = true;
	
	
	double min = sa1*.85 - 10;
	double max = sa1*1.15 + 10;


    sa1 = sa1 / 100;
	sa2 = sa2 / 100;




	CString sal1, sal2;
	sal1.Format("%.2f", sa1);
	sal2.Format("%.2f", sa2);



	CString pay1, pay2;

	int cap_1 = m_cap_1 + (s2 - s1);
	int cap_2 = m_cap_2 + (s1 - s2);

	if((s2 <  min) || (s2 > max)) m_salary_fit = false;
	if( (cap_1 < m_cap) && (cap_2 < m_cap)) m_salary_fit = true;


	double ca1 = (double) cap_1 / 100;
	double ca2 = (double) cap_2 / 100;
	pay1.Format("%.2f", ca1);
	pay2.Format("%.2f", ca2);
	m_edit_payroll1 = pay1;
	m_edit_payroll2 = pay2;

	m_edit_salary_1 = sal1;
	m_edit_salary_2 = sal2;
	m_edit_salary_fit = "Qualify: yes";
	if(m_salary_fit == false && m_salaries_match == TRUE) m_edit_salary_fit = "Qualify: no";


	UpdateData(FALSE);
}

void CTradeDlg::ClearDraftPickData(int t1, int t2, int o_t, int d1, int d2)
{
//	m_own[o_t].m_draft_pick_addition = 0;

	for(int i=t1; i<=t2; i++)
	{
		m_own[i].m_number_proposed_picks = 0;
		m_own[i].m_number_actual_picks = 0;
		m_own[i].m_salary_in_trade = 0;
		m_own[i].m_total_salary_in_trade = 0;
		m_own[i].m_total_years_in_trade = 0;
//		if(t1 != t2)
			m_own[i].m_draft_pick_addition = 0;

		m_own[i].m_total_true_in_trade = 0;

		for(int j=0; j<=5; j++)
		{
			m_own[i].m_proposed_picks[j] = 0;
		}
		for(int j=0; j<=18; j++)
		{
			m_own[i].m_actual_picks[j] = 0;
		}
		for(int j=0; j<=3; j++)
		{
			m_own[i].m_number_picks_year[j] = 0;
			m_own[i].m_number_proposed_picks_year[j] = 0;
		}
	}

	for(int i=d1; i<=d2; i++)
	{
		for(int j=0; j<=18; j++)
		{
			m_draft_choice[i][j] = 0;
		}
	}

	
	DisplayTradeSalaries();

}

void CTradeDlg::DeletePicks(bool t1, int t, int o_t)
{
	

	int slot = m_listplayers1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	

	int j = 1;

	if(t1 == false){ slot = m_listplayers2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1; j = 2;}
	
	if(slot >= 1)
	{

	bool found = false;
	for(int i=slot; i<=17; i++)
	{
		if(m_draft_choice[j][i] > 0 && found == false && i==slot)
		{
			found = true;
			int pick = m_draft_choice[j][i];

			int y = pick / 1000;
			int r = (pick - y*1000) / 100;
			int p = pick - (y*1000 + r*100);
			double tru_f = avg.m_avg_tru[0] + (avg.m_team_avg_tru[p] - avg.m_avg_tru[0])*2;
			if(tru_f < 2) tru_f = 2;
			double ro = (double)r;
			if(r==2) ro = (double)3;
			double rating = avg.m_avg_tru[0] / tru_f / ro * (4/(3+(double)y));

			int total_g = avg.m_standings[p-1].m_win + avg.m_standings[p-1].m_loss;

			double pct = 1;
			if(total_g > 0)
			pct = (double)avg.m_standings[p-1].m_win / ((double) + avg.m_standings[p-1].m_win + (double)avg.m_standings[p-1].m_loss);


			//double pct = (double)avg.m_standings[p-1].m_win / (double)avg.m_standings[p-1].m_loss;
			//double pct = (double)avg.m_standings[p-1].m_win / ((double) + avg.m_standings[p-1].m_win + (double)avg.m_standings[p-1].m_loss);

			int hi_g = avg.m_sched.m_games_in_season;
			double f = (double)total_g / (double)hi_g;
			if(f > 1) f=1;
			double nu = rating*(f*(1-pct)*2) + rating*(1-f);
			if(nu > 2) nu = 2;
			double pick_value = nu * avg.m_avg_tru[0];


			double temp =  100 * m_own[t].m_draft_pick_addition - pick_value * 100 ;
			m_own[t].m_draft_pick_addition = (double)temp / 100;	

			m_own[t].m_number_proposed_picks = m_own[t].m_number_proposed_picks - 1;
			m_own[t].m_number_proposed_picks_year[y] = m_own[t].m_number_proposed_picks_year[y] - 1;
//			m_own[o_t].m_number_picks_year[y] = m_own[o_t].m_number_picks_year[y] - 1;
			
		}

		m_draft_choice[j][i] = m_draft_choice[j][i+1];

	}

	m_draft_choice[j][18] = 0;

	
	}

}

void CTradeDlg::CheckButton()
{
	int team1index = m_listteams1.GetCurSel();
	int team2index = m_listteams2.GetCurSel();
	if(team1index == team2index)
	{
		m_button_add_pick1.EnableWindow(FALSE);
		m_button_add_pick2.EnableWindow(FALSE);
		m_button_team1.EnableWindow(FALSE);
		m_button_team2.EnableWindow(FALSE);
	}
	else
	{
		m_button_add_pick1.EnableWindow(TRUE);
		m_button_add_pick2.EnableWindow(TRUE);
		m_button_team1.EnableWindow(TRUE);
		m_button_team2.EnableWindow(TRUE);
	}
}

CString CTradeDlg::DisplayFaSalarySeeking(int fa)
{
	CString seeking = "";
	int m_minimum[11];
			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;

	

	int yr = FA[fa].m_yrs_of_service;
	if(yr > 10) yr = 10;
	double seek = (double) m_minimum[yr] / 100;
	yr = FA[fa].m_current_contract_yr;
	if(yr > 0 && FA[fa].m_contract_salaries[yr] > 0) seek = (double)FA[fa].m_contract_salaries[yr] / 100;//player is under contract on other team
	CString str;
	str.Format("%.2f", seek);
	seeking = str;
	UpdateData(FALSE);

	return seeking;
}



void CTradeDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	int slot = m_listteams3.GetCurSel();
	if(slot >= 0)
	{

	CSearchDlg* search = new CSearchDlg;
	search->m_path = m_path;
	search->m_league_name = m_leagueName;
	search->avg = avg;
	search->m_scout = m_scout[slot];
	search->m_team_index = slot;
	
	for(int i=0; i<=32; i++)
	{
		search->m_league_team_names[i] = m_leagueTeamNames[i];
	}
	int result = search->DoModal();

	if(result == IDOK)
	{

	int i = 0;
	int j = 0;
	bool found = false;


	for(int t=0; t<=32; t++)
	{
		for(int p=1; p<=m_slots; p++)
		{
			if(PlayerList[t][p].GetName() == "") continue;
			if(search->m_selected_player_id == PlayerList[t][p].GetID())
			{
				found = true;
				i = t;
				j = p - 1;
			}
		}
	}

		if(found == true)
		{
			int slot = m_listteams2.GetCurSel();
			m_listteams2.SetCurSel(i);
			m_team2index = i;
			if(i != slot) OnSelchangeCombo2();
//			m_listroster2.SetCurSel(j);
			m_listroster2.SetItemState(j,LVIS_SELECTED,LVIS_SELECTED);
			m_listroster2.SetItemState(j,LVIS_FOCUSED,LVIS_FOCUSED);
			m_listroster2.EnsureVisible(j, TRUE);

			OnButtonTeam2();
		}
		else
		{
			for(int i=1; i<=480; i++)
			{
				if(search->m_selected_player_id == FA[i].GetID())
				{
//					m_listfa.SetCurSel(i-1);
					m_listfa.SetItemState(i-1,LVIS_SELECTED,LVIS_SELECTED);
					m_listfa.SetItemState(i-1,LVIS_FOCUSED,LVIS_FOCUSED);
					m_listfa.EnsureVisible(i-1, TRUE);
					int fa = m_listfa.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;
//					OnSelchangeListFa();
				}
			}
		}

	}



	delete search;
	}
	
}

/*void CTradeDlg::DisplayPlayerSalaryVisitor()
{
	if(m_listteams1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0 && m_listroster1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
	int slot = m_listroster1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	CPlayer	m_player = PlayerList[m_team1index][slot+1];
	int salary = m_player.m_current_yr_salary;
	double sal = (double)salary/100;
	CString string;
	string.Format("salary: %.2f", sal);
	m_edit_visitor_salary = string;
	UpdateData(FALSE);
	}
}

void CTradeDlg::DisplayPlayerSalaryHome()
{
	if(m_listteams2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0 && m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) >= 0)
	{
	int slot = m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	CPlayer	m_player = PlayerList[m_team2index][slot+1];
	int salary = m_player.m_current_yr_salary;
	double sal = (double)salary/100;
	CString string;
	string.Format("salary: %.2f", sal);
	m_edit_home_salary = string;
	UpdateData(FALSE);
	}
}
*/



void CTradeDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CheckButton();
	int m_currentSelection = 0;
	if(m_listteams1.GetCurSel() >= 0)
	{
	m_currentSelection = m_listteams1.GetCurSel();
	m_team1index = m_currentSelection;
	m_listroster1.DeleteAllItems();
	m_cap_1 = 0;
	int cou = 0;
	for(int  i = 1; i <= m_slots; ++i)
	{
		CPlayer m_player = PlayerList[m_currentSelection][i];
		m_cap_1 = m_cap_1 + m_player.m_current_yr_salary;
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
			int sal = m_player.m_current_yr_salary;
			CString Sa;
			Sa.Format("%.2f", (double)sal/100);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listroster1.InsertItem(cou,Pos);
			m_listroster1.SetItemText(cou,1,Name);			
			m_listroster1.SetItemText(cou,2,Ag);			
			m_listroster1.SetItemText(cou,3,Sa);			
			m_listroster1.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;
	}
	for(int i = 1; i <= 480; ++i)
	{
		CPlayer m_player = FA[i];
		if(m_player.m_team_paying == (m_team1index+1))
			m_cap_1 = m_cap_1 + m_player.m_current_yr_salary;
	}
	m_listplayers1.DeleteAllItems();
//	m_listroster1.SetCurSel(0);
	m_listroster1.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster1.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster1.EnsureVisible(0, TRUE);

	ClearDraftPickData(m_team1index + 1, m_team1index + 1, m_team2index + 1, 1,1);
	ListOwnDraftPicks(true, false);
	m_own[m_team1index+1].m_salary_in_trade = 0;
	m_own[m_team1index+1].m_total_salary_in_trade = 0;
	m_own[m_team1index+1].m_total_years_in_trade = 0;
	m_own[m_team1index+1].m_total_true_in_trade = 0;

	if(m_listteams1.GetCurSel() == m_listteams2.GetCurSel())
	{
		m_listplayers2.DeleteAllItems();
		//m_listroster2.SetCurSel(0);
		m_listroster2.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
		m_listroster2.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
		m_listroster2.EnsureVisible(0, TRUE);

		ClearDraftPickData(m_team2index + 1, m_team2index + 1, m_team1index + 1, 2,2);
		ListOwnDraftPicks(false, true);
		m_own[m_team2index+1].m_salary_in_trade = 0;
		m_own[m_team2index+1].m_total_salary_in_trade = 0;
		m_own[m_team2index+1].m_total_years_in_trade = 0;
		m_own[m_team2index+1].m_total_true_in_trade = 0;
	}


	DisplayTradeSalaries();
//	DisplayPlayerSalaryVisitor();

	}

	//OnSelchangeCombo1();
//	OnSelchangeCombo3();
	
	
}



void CTradeDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CheckButton();
	int m_currentSelection = 0;
	if(m_listteams2.GetCurSel() >= 0)
	{
	m_currentSelection = m_listteams2.GetCurSel();
	m_team2index = m_currentSelection;
	m_listroster2.DeleteAllItems();
	m_cap_2 = 0;
	int cou = 0;
	for(int  i = 1; i <= m_slots; ++i)
	{
		CPlayer m_player = PlayerList[m_currentSelection][i];
		m_cap_2 = m_cap_2 + m_player.m_current_yr_salary;

		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
			int sal = m_player.m_current_yr_salary;
			CString Sa;
			Sa.Format("%.2f", (double)sal/100);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listroster2.InsertItem(cou,Pos);
			m_listroster2.SetItemText(cou,1,Name);			
			m_listroster2.SetItemText(cou,2,Ag);			
			m_listroster2.SetItemText(cou,3,Sa);			
			m_listroster2.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;

	
	}
	for( int i = 1; i <= 480; ++i)
	{
		CPlayer m_player = FA[i];
		if(m_player.m_team_paying == (m_team2index+1))
			m_cap_2 = m_cap_2 + m_player.m_current_yr_salary;
	}
	
	m_listplayers2.DeleteAllItems();
//	m_listroster2.SetCurSel(0);
	m_listroster2.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster2.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster2.EnsureVisible(0, TRUE);

	ClearDraftPickData(m_team2index+1, m_team2index+1, m_team1index+1, 2,2);
	ListOwnDraftPicks(false, true);
	m_own[m_team2index+1].m_salary_in_trade = 0;
	m_own[m_team2index+1].m_total_salary_in_trade = 0;
	m_own[m_team2index+1].m_total_years_in_trade = 0;
	m_own[m_team2index+1].m_total_true_in_trade = 0;

	if(m_listteams1.GetCurSel() == m_listteams2.GetCurSel())
	{
		m_listplayers1.DeleteAllItems();
//		m_listroster1.SetCurSel(0);
		m_listroster1.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
		m_listroster1.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
		m_listroster1.EnsureVisible(0, TRUE);
		ClearDraftPickData(m_team1index + 1, m_team1index + 1, m_team2index + 1, 1,1);
		ListOwnDraftPicks(true, false);
		m_own[m_team1index+1].m_salary_in_trade = 0;
		m_own[m_team1index+1].m_total_salary_in_trade = 0;
		m_own[m_team1index+1].m_total_years_in_trade = 0;
		m_own[m_team1index+1].m_total_true_in_trade = 0;
	}
	
	DisplayTradeSalaries();
//	DisplayPlayerSalaryHome();

	}	
//	OnSelchangeCombo3();
	//OnSelchangeCombo2();

}

	


void CTradeDlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	int index = m_listteams3.GetCurSel();
	m_listcontrol.ResetContent();
	m_listcontrol.AddString(m_control[index]);

	int m_currentSelection = 0;
	int cou = 0;
	if(m_listteams3.GetCurSel() >= 0 )
	{
	m_currentSelection = m_listteams3.GetCurSel();
	m_team3index = m_currentSelection;
	m_listteams1.SetCurSel(index);
	m_listroster3.DeleteAllItems();
	for(int  i = 1; i <= m_slots; ++i)
	{
		CPlayer m_player = PlayerList[m_currentSelection][i];

		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();
		if(Name == "") continue;

			int age = m_player.m_age;
			int sal = m_player.m_current_yr_salary;
			CString Sa;
			Sa.Format("%.2f", (double)sal/100);
			int inj = m_player.GetInjury();
			CString Ag, In;
			Ag.Format("%d", age);
			In.Format("%d", inj);

			m_listroster3.InsertItem(cou,Pos);
			m_listroster3.SetItemText(cou,1,Name);			
			m_listroster3.SetItemText(cou,2,Ag);			
			m_listroster3.SetItemText(cou,3,Sa);			
			m_listroster3.SetItemText(cou,4,In);			
			
			
			cou = cou + 1;





	}
//	m_listroster3.SetCurSel(0);
	m_listroster3.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listroster3.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listroster3.EnsureVisible(0, TRUE);

	UpdateData(FALSE);
	}

	OnSelchangeCombo1();
	OnSelchangeCombo2();

	
}

	


void CTradeDlg::OnClickListCtrlRoster1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
//	DisplayPlayerSalaryVisitor();		
	*pResult = 0;
}

void CTradeDlg::OnDblclkListCtrlRoster1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_listteams1.GetCurSel();
	int j = m_listroster1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(i >= 0 && j >= 1)
	{

	CPlayer m_player = PlayerList[i][j];


	int players_listed = m_listroster1.GetItemCount();
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_listteams1.GetCurSel();

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = PlayerList[i][c+1];
	}
	scout->m_player_index = j-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;


}

void CTradeDlg::OnClickListCtrlRoster2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	


}

void CTradeDlg::OnClickListCtrlFa(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int fa = m_listfa.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED)+1;
//	DisplayFaSalarySeeking(fa);

	
	*pResult = 0;
}

void CTradeDlg::OnDblclkListCtrlPlayers1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index = m_listplayers1.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int co = m_listplayers1.GetItemCount() - 1;
	if(index >= 0 && index <= co)
	{
		CString proposed = m_listplayers1.GetItemText(index, 1);
		for(int j=1; j<=m_slots; j++)
		{
			CPlayer m_player = PlayerList[m_team1index][j];
			m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_gm[m_team2index].m_scoring, m_gm[m_team2index].m_shooting, m_gm[m_team2index].m_rebounding, m_gm[m_team2index].m_passing, m_gm[m_team2index].m_defense);
			m_player.SetTradeTrueRating(0);
			m_player.SetAdjTradeValue(m_gm[m_team2index].m_pot1, m_gm[m_team2index].m_pot2, m_gm[m_team2index].m_effort);


			CString name = m_player.GetName();
			if(proposed == name)
			{
				int current_yr_salary = m_player.m_current_yr_salary;

				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

				int rem_sal = m_player.m_remaining_salary;
				if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;

				m_own[m_team1index+1].m_total_salary_in_trade =
					m_own[m_team1index+1].m_total_salary_in_trade 
					- rem_sal;



				m_own[m_team1index+1].m_total_years_in_trade =
					m_own[m_team1index+1].m_total_years_in_trade 
					- yrs_left;

				m_own[m_team1index+1].m_salary_in_trade = m_own[m_team1index+1].m_salary_in_trade - current_yr_salary;

				m_own[m_team1index+1].m_total_true_in_trade = 
					m_own[m_team1index+1].m_total_true_in_trade 
					-  m_player.GetTradeTrueRating(m_checkCareer) * yrs_left; 
					

				
			}
		}
	DeletePicks(true, m_team1index+1, m_team1index+1);
	

//	m_listplayers1.DeleteString(index);
	DeleteListCtrlRow(index, 1);

	DisplayTradeSalaries();		
	}

	
	*pResult = 0;
	
}

void CTradeDlg::OnDblclkListCtrlPlayers2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index = m_listplayers2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);

	int co = m_listplayers2.GetItemCount() - 1;
	if(index >= 0 && index <= co)
	{



	CString proposed = m_listplayers2.GetItemText(index, 1);
		for(int j=1; j<=m_slots; j++)
		{

			CPlayer m_player = PlayerList[m_team2index][j];

			m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_gm[m_team1index].m_scoring, m_gm[m_team1index].m_shooting, m_gm[m_team1index].m_rebounding, m_gm[m_team1index].m_passing, m_gm[m_team1index].m_defense);
			m_player.SetTradeTrueRating(0);
			m_player.SetAdjTradeValue(m_gm[m_team1index].m_pot1, m_gm[m_team1index].m_pot2, m_gm[m_team1index].m_effort);


			CString name = m_player.GetName();
			if(proposed == name)
			{
				int current_yr_salary = m_player.m_current_yr_salary;

				int yrs_left = 1 + m_player.m_contract_yrs 
					- m_player.m_current_contract_yr;

				int rem_sal = m_player.m_remaining_salary;
				if(rem_sal > (MAX10*yrs_left)) rem_sal = MAX10*yrs_left;

				m_own[m_team2index+1].m_total_salary_in_trade =
					m_own[m_team2index+1].m_total_salary_in_trade 
					- rem_sal;

				m_own[m_team2index+1].m_total_years_in_trade =
					m_own[m_team2index+1].m_total_years_in_trade 
					- yrs_left;
				

				m_own[m_team2index+1].m_total_true_in_trade = 
					m_own[m_team2index+1].m_total_true_in_trade 
					-  m_player.GetTradeTrueRating(m_checkCareer) * yrs_left; 

				m_own[m_team2index+1].m_salary_in_trade = m_own[m_team2index+1].m_salary_in_trade - current_yr_salary;


			}
		}

	DeletePicks(false, m_team2index+1, m_team2index+1);

//	m_listplayers2.DeleteString(index);	
	DeleteListCtrlRow(index, 2);

	DisplayTradeSalaries();		
	}

	
	*pResult = 0;
}

void CTradeDlg::OnDblclkListCtrlRoster2(NMHDR* pNMHDR, LRESULT* pResult) 
{

int i = m_listteams2.GetCurSel();
	int j = m_listroster2.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(i >= 0 && j >= 1)
	{

	CPlayer m_player = PlayerList[i][j];


	int players_listed = m_listroster2.GetItemCount();
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_listteams2.GetCurSel();

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = PlayerList[i][c+1];
	}
	scout->m_player_index = j-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;

}

void CTradeDlg::OnDblclkListCtrlFa(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listfa.GetSelectionMark();
	//int j = m_listroster.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(i >= 0)
	{

	CPlayer m_player = FA[i+1];


	int players_listed = m_listfa.GetItemCount();
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_listteams1.GetCurSel();

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = FA[c+1];
	}
	scout->m_player_index = i;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;


}

void CTradeDlg::OnClickListCtrlRoster3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CTradeDlg::OnDblclkListCtrlRoster3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listteams3.GetCurSel();
	int j = m_listroster3.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(i >= 0 && j >= 1)
	{

	CPlayer m_player = PlayerList[i][j];


	int players_listed = m_listroster3.GetItemCount();
	int tm = m_player.m_team_index - 1;
	
	CString team = "";
	if(tm < 0) team = "";
	else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_listteams3.GetCurSel();

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = PlayerList[i][c+1];
	}
	scout->m_player_index = j-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;




}

void CTradeDlg::OnClickListCtrlPlayers1(NMHDR* pNMHDR, LRESULT* pResult) 
{

}

void CTradeDlg::OnClickListCtrlPlayers2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CTradeDlg::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_team1_draft.SetBkColor(BK_COLOR);
	m_list_team1_draft.SetTextBkColor(TEXT_BK_COLOR);
	m_list_team1_draft.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_list_team1_draft.SetTextColor(RGB(0,0,0));
	m_list_team1_draft.SetFont(&m_font);

    m_list_team1_draft.InsertColumn(0,"pick");    
    m_list_team1_draft.InsertColumn(1,"team");    
//    m_list_team1_draft.InsertColumn(2,"");    
  //  m_list_team1_draft.InsertColumn(3,"");    
    //m_list_team1_draft.InsertColumn(4,"");    
//    m_list_team1_draft.InsertColumn(5,"");    

    m_list_team1_draft.SetColumnWidth( 0, 120);
    m_list_team1_draft.SetColumnWidth( 1, 133);

	m_list_team2_draft.SetBkColor(BK_COLOR);
	m_list_team2_draft.SetTextBkColor(TEXT_BK_COLOR);
	m_list_team2_draft.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_list_team2_draft.SetTextColor(RGB(0,0,0));
	m_list_team2_draft.SetFont(&m_font);

    m_list_team2_draft.InsertColumn(0,"pick");    
    m_list_team2_draft.InsertColumn(1,"team");    

    m_list_team2_draft.SetColumnWidth( 0, 120);
    m_list_team2_draft.SetColumnWidth( 1, 133);

	m_listfa.SetBkColor(BK_COLOR);
	m_listfa.SetTextBkColor(TEXT_BK_COLOR);
	m_listfa.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listfa.SetTextColor(RGB(0,0,0));
	m_listfa.SetFont(&m_font);

    m_listfa.InsertColumn(0,"pos");    
    m_listfa.InsertColumn(1,"player");    
    m_listfa.InsertColumn(2,"age");    
    m_listfa.InsertColumn(3,"salary");    
    m_listfa.InsertColumn(4,"inj");    
    //m_listfa.InsertColumn(5,"");    

    m_listfa.SetColumnWidth( 0, 36);
    m_listfa.SetColumnWidth( 1, 112);
    m_listfa.SetColumnWidth( 2, 38);
    m_listfa.SetColumnWidth( 3, 55);
    m_listfa.SetColumnWidth( 4, 28);
    //m_listfa.SetColumnWidth( 5, 30);

	m_listplayers1.SetBkColor(BK_COLOR);
	m_listplayers1.SetTextBkColor(TEXT_BK_COLOR);
	m_listplayers1.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listplayers1.SetTextColor(RGB(0,0,0));
	m_listplayers1.SetFont(&m_font);

    m_listplayers1.InsertColumn(0,"pos");    
    m_listplayers1.InsertColumn(1,"player");    
//    m_listplayers1.InsertColumn(2,"");    
 //   m_listplayers1.InsertColumn(3,"");    
  //  m_listplayers1.InsertColumn(4,"");    
    //m_listplayers1.InsertColumn(5,"");    

    m_listplayers1.SetColumnWidth( 0, 120);
    m_listplayers1.SetColumnWidth( 1, 133);
    //m_listplayers1.SetColumnWidth( 2, 25);
    //m_listplayers1.SetColumnWidth( 3, 40);
    //m_listplayers1.SetColumnWidth( 4, 25);
    //m_listplayers1.SetColumnWidth( 5, 30);

	m_listplayers2.SetBkColor(BK_COLOR);
	m_listplayers2.SetTextBkColor(TEXT_BK_COLOR);
	m_listplayers2.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listplayers2.SetTextColor(RGB(0,0,0));
	m_listplayers2.SetFont(&m_font);

    m_listplayers2.InsertColumn(0,"pos");    
    m_listplayers2.InsertColumn(1,"player");    
    //m_listplayers2.InsertColumn(2,"");    
    //m_listplayers2.InsertColumn(3,"");    
    //m_listplayers2.InsertColumn(4,"");    
//    m_listplayers2.InsertColumn(5,"");    

    m_listplayers2.SetColumnWidth( 0, 120);
    m_listplayers2.SetColumnWidth( 1, 133);
    //m_listplayers2.SetColumnWidth( 2, 25);
    //m_listplayers2.SetColumnWidth( 3, 40);
    //m_listplayers2.SetColumnWidth( 4, 25);
  //  m_listplayers2.SetColumnWidth( 5, 30);

	m_listroster1.SetBkColor(BK_COLOR);
	m_listroster1.SetTextBkColor(TEXT_BK_COLOR);
	m_listroster1.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listroster1.SetTextColor(RGB(0,0,0));
	m_listroster1.SetFont(&m_font);

    m_listroster1.InsertColumn(0,"pos");    
    m_listroster1.InsertColumn(1,"player");    
    m_listroster1.InsertColumn(2,"age");    
    m_listroster1.InsertColumn(3,"salary");    
    m_listroster1.InsertColumn(4,"inj");    
    //m_listroster1.InsertColumn(5,"");    

    m_listroster1.SetColumnWidth( 0, 36);
    m_listroster1.SetColumnWidth( 1, 112);
    m_listroster1.SetColumnWidth( 2, 38);
    m_listroster1.SetColumnWidth( 3, 55);
    m_listroster1.SetColumnWidth( 4, 28);
    //m_listroster1.SetColumnWidth( 5, 30);

	m_listroster2.SetBkColor(BK_COLOR);
	m_listroster2.SetTextBkColor(TEXT_BK_COLOR);
	m_listroster2.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listroster2.SetTextColor(RGB(0,0,0));
	m_listroster2.SetFont(&m_font);

    m_listroster2.InsertColumn(0,"pos");    
    m_listroster2.InsertColumn(1,"player");    
    m_listroster2.InsertColumn(2,"age");    
    m_listroster2.InsertColumn(3,"salary");    
    m_listroster2.InsertColumn(4,"inj");    
    //m_listroster2.InsertColumn(5,"");    

    m_listroster2.SetColumnWidth( 0, 36);
    m_listroster2.SetColumnWidth( 1, 112);
    m_listroster2.SetColumnWidth( 2, 38);
    m_listroster2.SetColumnWidth( 3, 55);
    m_listroster2.SetColumnWidth( 4, 28);
    //m_listroster2.SetColumnWidth( 5, 30);

	m_listroster3.SetBkColor(BK_COLOR);
	m_listroster3.SetTextBkColor(TEXT_BK_COLOR);
	m_listroster3.SetExtendedStyle(LVS_EX_FULLROWSELECT |  LVS_EX_GRIDLINES);
    m_listroster3.SetTextColor(RGB(0,0,0));
	m_listroster3.SetFont(&m_font);

    m_listroster3.InsertColumn(0,"pos");    
    m_listroster3.InsertColumn(1,"player");    
    m_listroster3.InsertColumn(2,"age");    
    m_listroster3.InsertColumn(3,"salary");    
    m_listroster3.InsertColumn(4,"inj");    
    //m_listroster3.InsertColumn(5,"");    

    m_listroster3.SetColumnWidth( 0, 36);
    m_listroster3.SetColumnWidth( 1, 112);
    m_listroster3.SetColumnWidth( 2, 38);
    m_listroster3.SetColumnWidth( 3, 55);
    m_listroster3.SetColumnWidth( 4, 28);
    //m_listroster3.SetColumnWidth( 5, 30);

  
	int days_passed = (avg.m_sched.m_currentMonth - avg.m_sched.m_first_mo)*30 +
		(avg.m_sched.m_currentDay - avg.m_sched.m_first_da);



	bool deadline = false;
	if((avg.m_sched.m_currentMonth > avg.m_sched.m_dead_mo || 
		(avg.m_sched.m_currentMonth == avg.m_sched.m_dead_mo && 
			avg.m_sched.m_currentDay > avg.m_sched.m_dead_da)) &&
				avg.m_settings.m_deadline_on == 1			
			) deadline = true;


	if(deadline == true && avg.m_settings.m_current_stage == 0) 
	{
		m_button_trade.SetWindowText("Trade Deadline Passed");
		m_button_trade.EnableWindow(FALSE);
	}


	m_button_search.SetFaceColor(BUTTONFACECOLOR2);

}

void CTradeDlg::DeleteListCtrlRow(int row, int ctrl)
{
	CString items[5][2];

	if(ctrl == 1)
	{
		for(int i=0; i<=4; i++)
		{
			items[i][0] = m_listplayers1.GetItemText(i,0);
			items[i][1] = m_listplayers1.GetItemText(i,1);
		}
		m_listplayers1.DeleteAllItems();
		
		for(int i=0; i < row; i++)
		{
			CString Pos = items[i][0];
			CString Name = items[i][1];
			if(Pos == "" && Name == "") continue;
			m_listplayers1.InsertItem(i,Pos);
			m_listplayers1.SetItemText(i,1,Name);			
		}

		if(row < 4)
		{
			for(int i=row; i<=3; i++)
			{
				
				CString Pos = items[i+1][0];
				CString Name = items[i+1][1];
				if(Pos == "" && Name == "") continue;
				m_listplayers1.InsertItem(i,Pos);
				m_listplayers1.SetItemText(i,1,Name);			
			}


		}

	}
	else
	{
		for(int i=0; i<=4; i++)
		{
			items[i][0] = m_listplayers2.GetItemText(i,0);
			items[i][1] = m_listplayers2.GetItemText(i,1);
		}
		m_listplayers2.DeleteAllItems();
		
		for(int i=0; i < row; i++)
		{
			CString Pos = items[i][0];
			CString Name = items[i][1];
			if(Pos == "" && Name == "") continue;
			m_listplayers2.InsertItem(i,Pos);
			m_listplayers2.SetItemText(i,1,Name);			
		}

		if(row < 4)
		{
			for(int i=row; i<=3; i++)
			{
				
				CString Pos = items[i+1][0];
				CString Name = items[i+1][1];
				if(Pos == "" && Name == "") continue;
				m_listplayers2.InsertItem(i,Pos);
				m_listplayers2.SetItemText(i,1,Name);			
			}


		}






	}



}

void CTradeDlg::ListPlayersInTradeOffer()
{


	int i = 0;
	int j = 0;
	bool found = false;

for(int c=1; c<=10; c++)
{
	if(m_player_list[c]==0 || c==5 || c==10) continue;

	for(int t=0; t<=32; t++)
	{
		for(int p=1; p<=m_slots; p++)
		{
			if(PlayerList[t][p].GetName() == "") continue;
			if(m_player_list[c] == PlayerList[t][p].GetID())
			{
				found = true;
				i = t;
				j = p - 1;
			}
		}
	}

		if(found == true && c >= 5)
		{
			int slot = m_listteams2.GetCurSel();
			m_listteams2.SetCurSel(i);
			m_team2index = i;
			if(i != slot) OnSelchangeCombo2();
			m_listroster2.SetItemState(j,LVIS_SELECTED,LVIS_SELECTED);
			m_listroster2.SetItemState(j,LVIS_FOCUSED,LVIS_FOCUSED);
			m_listroster2.EnsureVisible(j, TRUE);

			OnButtonTeam2();
		}	
		else if(found == true)
		{
			int slot = m_listteams1.GetCurSel();
			m_listteams1.SetCurSel(i);
			m_team1index = i;
			if(i != slot) OnSelchangeCombo1();
			m_listroster1.SetItemState(j,LVIS_SELECTED,LVIS_SELECTED);
			m_listroster1.SetItemState(j,LVIS_FOCUSED,LVIS_FOCUSED);
			m_listroster1.EnsureVisible(j, TRUE);

			OnButtonTeam1();
		}	


}

	AddOfferedPicks();

}













void CTradeDlg::AddOfferedPicks()
{
// TODO: Add your control notification handler code here
	int team1 = m_listteams1.GetCurSel() + 1;
	int team2 = m_listteams2.GetCurSel() + 1;


		CString string;
		CString string2;


		int pick = m_player_list[5];
		if(pick > 0)
		{
		int y = pick / 1000;
		int r = (pick - y*1000) / 100;
		int p = pick - (y*1000 + r*100);

		string.Format("%d round %d", m_current_year - 1 + y, r);
		string2.Format("%s (%d-%d)",m_leagueTeamNames[p-1], avg.m_standings[p-1].m_win, avg.m_standings[p-1].m_loss);
		

		int cou = m_listplayers1.GetItemCount();
		m_listplayers1.InsertItem(cou,string);
		m_listplayers1.SetItemText(cou,1,string2);			

		int index = 1;
		
		int count_proposed = 1;
		SetProposedPicks(index, team1, team2);
		m_draft_choice[1][count_proposed] = m_own[team1].m_actual_picks[index];
		}

		pick = m_player_list[10];
		if(pick > 0)
		{
		int y = pick / 1000;
		int r = (pick - y*1000) / 100;
		int p = pick - (y*1000 + r*100);

		string.Format("%d round %d", m_current_year - 1 + y, r);
		string2.Format("%s (%d-%d)",m_leagueTeamNames[p-1], avg.m_standings[p-1].m_win, avg.m_standings[p-1].m_loss);
		

		int cou = m_listplayers2.GetItemCount();
		m_listplayers2.InsertItem(cou,string);
		m_listplayers2.SetItemText(cou,1,string2);			

		int index = 1;
		
		int count_proposed = 1;
		
		SetProposedPicks(index, team2, team1);
		m_draft_choice[2][count_proposed] = m_own[team2].m_actual_picks[index];
		
		
		}
}


void CTradeDlg::OnLvnItemchangedListCtrlFa(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CTradeDlg::OnLvnItemchangedListCtrlTeam2Draft(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
