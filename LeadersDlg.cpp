// LeadersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "playercarddlg.h"
//#include "constants.h"
//#include "resource.h"

#include "LeadersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeadersDlg dialog


CLeadersDlg::CLeadersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLeadersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeadersDlg)
	//}}AFX_DATA_INIT
	m_playersSelected = TRUE;
	m_teamOffenseSelected = FALSE;
	m_teamDefenseSelected = FALSE;
	m_playersSelected = TRUE;
	m_simulatedSelected = TRUE;
	m_statStyle = SIMULATED;
	m_sortPosition = "All";		
	for(int i=0; i<=1600; i++)
	{
		m_id_list[i] = 0;
	}
}


void CLeadersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeadersDlg)
	DDX_Control(pDX, IDC_LIST_CTRL_LEADERS, m_listLeaders);
	DDX_Control(pDX, IDC_BUTTON_REPORT, m_buttonLeaders);
	DDX_Control(pDX, IDC_LIST_STATS, m_listStats);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeadersDlg, CDialog)
	//{{AFX_MSG_MAP(CLeadersDlg)
	ON_LBN_SELCHANGE(IDC_LIST_STATS, OnSelchangeListStats)
	ON_BN_CLICKED(IDC_RADIO_TEAMS, OnRadioTeams)
	ON_BN_CLICKED(IDC_RADIO_PLAYERS, OnRadioPlayers)
	ON_BN_CLICKED(IDC_RADIO_ACTUAL, OnRadioActual)
	ON_BN_CLICKED(IDC_RADIO_SIMULATED, OnRadioSimulated)
	ON_BN_CLICKED(IDC_RADIO_ALL, OnRadioAll)
	ON_BN_CLICKED(IDC_RADIO_SG, OnRadioSg)
	ON_BN_CLICKED(IDC_RADIO_SF, OnRadioSf)
	ON_BN_CLICKED(IDC_RADIO_PG, OnRadioPg)
	ON_BN_CLICKED(IDC_RADIO_PF, OnRadioPf)
	ON_BN_CLICKED(IDC_RADIO_C, OnRadioC)
	ON_BN_CLICKED(IDC_RADIO_TEAM_DEFENSE, OnRadioTeamsDefense)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_PLAYOFF, OnRadioPlayoff)
	ON_BN_CLICKED(IDC_BUTTON_REPORT, OnButtonReport)
	ON_BN_DOUBLECLICKED(IDC_BUTTON_REPORT, OnDoubleclickedButtonReport)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_LEADERS, OnDblclkListCtrlLeaders)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_LEADERS, &CLeadersDlg::OnLvnItemchangedListCtrlLeaders)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeadersDlg message handlers

BOOL CLeadersDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetWindowText(m_leagueName + " League Leaders");

    myBrush.CreateSolidBrush(DLGCOLOR); 
    myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	// TODO: Add extra initialization here
	CString Stats[31] = {"games","minutes per game","rebounds per game","assists per game",
		"steals per game","blocks per game","points per game","fg pct","ft pct","3pt fg pct", "mvp",
	"makes players better","assist/turnover","defense",
	"shooting*","driving*",
	"low post*","transition*","outside defense*","perimeter defense*",
	"post defense*","transition defense*",
	"shooting","driving",
	"low post","transition","outside defense","perimeter defense",
	"post defense","transition defense","true ratings mvp"};


	InitControls();


	for(int i = 0; i <= 30; i++)
	{
		m_listStats.AddString(Stats[i]);
	}

	for(int i = 0; i <= 1600; i++)
	{
		avg.m_actual[i].m_original_number = 0;
	}

	for(int i = 0; i <= 32; i++)
	{
		m_team_hi_g[i] = avg.m_actual[1440 + i].m_sim_games; 		
		m_po_team_hi_g[i] = avg.m_actual[1440 + i].m_po_games; 		
	}

	CString TeamName;

	int players = 15;
	for(int t = 0; t <= 33; t++)
	{
	if(t==32) players = 480;
	else if(t==33) players = 64;
	for(int n = 1; n <= players; n++ )
	{
		double total = 0;
		int slot = t*30+n;
		if(t == 33) slot = 1440 + n;
		CPlayer m_player = avg.m_actual[slot]; 		

		m_player.m_original_number = slot;		
		if(t <= 32)
		{
			m_player.m_team_index = t+1;//set to team stats offset for use in hi games stats eligible check
			m_player.SetTeam(m_leagueTeamNames[t]);
		}
		m_player.SetMinPerGame(m_player.GetGames(), m_player.GetMin());
		m_player.SetTotalGames(m_player.GetGames());
		m_player.SetPointsPerGame(m_player.GetGames(), m_player.GetFgm() - m_player.GetTfgm(), m_player.GetFtm(), m_player.GetTfgm());
		m_player.SetReboundsPerGame(m_player.GetGames(), m_player.GetReb());
		m_player.SetAssistsPerGame(m_player.GetGames(), m_player.GetAst());
		m_player.SetStealsPerGame(m_player.GetGames(), m_player.GetStl());
		m_player.SetBlocksPerGame(m_player.GetGames(), m_player.GetBlk());
		m_player.SetFgPct(m_player.GetFgm(), m_player.GetFga());
		m_player.SetFtPct(m_player.GetFtm(), m_player.GetFta());
		m_player.SetTfgPct(m_player.GetTfgm(), m_player.GetTfga());


		m_player.SetSimMinPerGame(m_player.m_sim_games, m_player.m_sim_min);
		m_player.SetSimPointsPerGame(m_player.m_sim_games, m_player.m_sim_fgm, m_player.m_sim_ftm, m_player.m_sim_tfgm);
		m_player.SetSimReboundsPerGame(m_player.m_sim_games, m_player.m_sim_oreb + m_player.m_sim_reb);
		m_player.SetSimAssistsPerGame(m_player.m_sim_games, m_player.m_sim_ast);
		m_player.SetSimStealsPerGame(m_player.m_sim_games, m_player.m_sim_stl);
		m_player.SetSimBlocksPerGame(m_player.m_sim_games, m_player.m_sim_blk);
		m_player.SetSimFgPct(m_player.m_sim_fgm + m_player.m_sim_tfgm, m_player.m_sim_fga + m_player.m_sim_tfga);
		m_player.SetSimFtPct(m_player.m_sim_ftm, m_player.m_sim_fta);
		m_player.SetSimTfgPct(m_player.m_sim_tfgm, m_player.m_sim_tfga);


		m_player.SetPoMinPerGame(m_player.m_po_games, m_player.m_po_min);
		m_player.SetPoPointsPerGame(m_player.m_po_games, m_player.m_po_fgm, m_player.m_po_ftm, m_player.m_po_tfgm);
		m_player.SetPoReboundsPerGame(m_player.m_po_games, m_player.m_po_oreb + m_player.m_po_reb);
		m_player.SetPoAssistsPerGame(m_player.m_po_games, m_player.m_po_ast);
		m_player.SetPoStealsPerGame(m_player.m_po_games, m_player.m_po_stl);
		m_player.SetPoBlocksPerGame(m_player.m_po_games, m_player.m_po_blk);
		m_player.SetPoFgPct(m_player.m_po_fgm + m_player.m_po_tfgm, m_player.m_po_fga + m_player.m_po_tfga);
		m_player.SetPoFtPct(m_player.m_po_ftm, m_player.m_po_fta);
		m_player.SetPoTfgPct(m_player.m_po_tfgm, m_player.m_po_tfga);

		m_player.SetTrueRating(avg.m_avg_tru[0], false);
		m_player.SetTeammatesBetterRating(avg.m_avg_fga[0], avg.m_avg_fta[0], avg.m_avg_tga[0],
			avg.m_avg_tru[0], avg.m_avg_orb[0], avg.m_avg_drb[0],
			avg.m_avg_ast[0], avg.m_avg_stl[0], avg.m_avg_to[0], avg.m_avg_blk[0]);

		m_player.SetAstTo();
		m_player.SetDefense();
		m_player.SetOutside();
		m_player.SetDriving();
		m_player.SetPost();
		m_player.SetTransition();
		m_player.SetOutsideDefense();
		m_player.SetDrivingDefense();
		m_player.SetPostDefense();
		m_player.SetTransitionDefense();
		m_player.SetOutsidePer48Min( m_hiGames);
		m_player.SetDrivingPer48Min( m_hiGames);
		m_player.SetPostPer48Min( m_hiGames);
		m_player.SetTransitionPer48Min( m_hiGames);
		m_player.SetOutsideDefensePer48Min( m_hiGames);
		m_player.SetDrivingDefensePer48Min( m_hiGames);
		m_player.SetPostDefensePer48Min( m_hiGames);
		m_player.SetTransitionDefensePer48Min( m_hiGames);
		m_player.SetMvp( avg.m_avg_tru[0]);


		avg.m_actual[t*30+n] = m_player;; 
	
	}
	}


	if(m_checkCareer == TRUE)
	{
		GetDlgItem(IDC_RADIO_ACTUAL)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_ACTUAL)->ShowWindow(FALSE);
	}
	if(m_statType == PLAYERS) CheckDlgButton(IDC_RADIO_PLAYERS, 1);	
	if(m_statType == TEAMS) CheckDlgButton(IDC_RADIO_TEAMS, 1);	
	if(m_statType == TEAMDEFENSE) CheckDlgButton(IDC_RADIO_TEAM_DEFENSE, 1);	
	if(m_statStyle == SIMULATED) CheckDlgButton(IDC_RADIO_SIMULATED, 1);	
	if(m_statStyle == ACTUAL && m_checkCareer == TRUE) CheckDlgButton(IDC_RADIO_ACTUAL, 1);	
	if(m_statStyle == PLAYOFF) CheckDlgButton(IDC_RADIO_PLAYOFF, 1);	
	CheckDlgButton(IDC_RADIO_ALL, 1);	
	m_listStats.SetCurSel(6);




	OnSelchangeListStats();

	UpdateData(FALSE);	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLeadersDlg::OnSelchangeListStats() 
{
	// TODO: Add your control notification handler code here
	QuickSort();
	ChooseStatsToList();
}


void CLeadersDlg::OnRadioTeams() 
{
	// TODO: Add your control notification handler code here
	m_buttonLeaders.EnableWindow(FALSE);
	if(m_playersSelected == TRUE || m_teamOffenseSelected == TRUE || m_teamDefenseSelected == FALSE)
	{
		
		m_playersSelected = FALSE;
		m_teamDefenseSelected = TRUE;
		m_teamOffenseSelected = FALSE;
		OnSelchangeListStats();
	}
	
}

void CLeadersDlg::OnRadioPlayers() 
{
	// TODO: Add your control notification handler code here
	m_buttonLeaders.EnableWindow(TRUE);
	if(m_playersSelected == FALSE || m_teamOffenseSelected == TRUE || m_teamDefenseSelected == TRUE)
	{
		m_playersSelected = TRUE;
		m_teamDefenseSelected = FALSE;
		m_teamOffenseSelected = FALSE;
		OnSelchangeListStats();
	}
}

void CLeadersDlg::OnRadioActual() 
{
	// TODO: Add your control notification handler code here
		m_statStyle = ACTUAL;	
		OnSelchangeListStats();		
}

void CLeadersDlg::OnRadioSimulated() 
{
	// TODO: Add your control notification handler code here
		m_statStyle = SIMULATED;
		OnSelchangeListStats();
}

void CLeadersDlg::OnRadioAll() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != "All")
	{
		m_sortPosition = "All";
		OnSelchangeListStats();
	}
}

void CLeadersDlg::OnRadioSg() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != "SG")
	{
		m_sortPosition = "SG";
		OnSelchangeListStats();
	}
}

void CLeadersDlg::OnRadioSf() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != "SF")
	{
		m_sortPosition = "SF";
		OnSelchangeListStats();
	}
}

void CLeadersDlg::OnRadioPg() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != "PG")
	{
		m_sortPosition = "PG";
		OnSelchangeListStats();
	}	
}

void CLeadersDlg::OnRadioPf() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != "PF")
	{
		m_sortPosition = "PF";
		OnSelchangeListStats();
	}
}

void CLeadersDlg::OnRadioC() 
{
	// TODO: Add your control notification handler code here
	if(m_sortPosition != " C")
	{
		m_sortPosition = " C";	
		OnSelchangeListStats();

	}
}

void CLeadersDlg::OnRadioTeamsDefense() 
{
	// TODO: Add your control notification handler code here
	m_buttonLeaders.EnableWindow(FALSE);
	if(m_playersSelected == TRUE || m_teamOffenseSelected == FALSE || m_teamDefenseSelected == TRUE)
	{
		m_teamOffenseSelected = TRUE;
		m_teamDefenseSelected = FALSE;
		m_playersSelected = FALSE;
		OnSelchangeListStats();
	}	
}

void CLeadersDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_LEAGUE_LEADERS);		
//	HtmlHelp(NULL, "jumpshot.chm::/html/leagueleaders.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL CLeadersDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/leagueleaders.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
//	WinHelp(HID_LEAGUE_LEADERS);
//	return TRUE;
}

void CLeadersDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
}

void CLeadersDlg::OnRadioPlayoff() 
{
	// TODO: Add your control notification handler code here
		m_statStyle = PLAYOFF;	
		OnSelchangeListStats();	
}


void CLeadersDlg::OnButtonReport() 
{

}

void CLeadersDlg::OnDoubleclickedButtonReport() 
{
}



HBRUSH CLeadersDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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


//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	
//	// TODO: Change any attributes of the DC here
//		pDC->SetTextColor(RGB(0,0,0));
//	if (nCtlColor == CTLCOLOR_LISTBOX)
//	{
//		pDC->SetBkMode(TRANSPARENT);
//		pDC->SetBkColor(RGB(255,255,226));	
//		return HBRUSH(myBrush);
//	}
//	return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 
}

bool CLeadersDlg::SortActualStats(CPlayer m_actual_j, CPlayer m_actual_i)
{

//m_buttonLeaders.EnableWindow(FALSE);
	m_listLeaders.DeleteAllItems();
	int choice = m_listStats.GetCurSel(); 

//	for(int i = 1; i <= 480; i++)
//	{
//			for(int j = 1; j <= 480; j++)
//			{
				bool swap = FALSE;

				if(choice == 1)
				{
					if( m_actual_j.m_minPerGame <  m_actual_i.m_minPerGame) swap = TRUE;
				}
				else if(choice == 0)
				{
					if( m_actual_j.m_games <  m_actual_i.m_games) swap = TRUE;
				}
				else if(choice == 2)
				{
					if( m_actual_j.m_reboundsPerGame <  m_actual_i.m_reboundsPerGame) swap = TRUE;
				}
				else if(choice == 3)
				{
					if( m_actual_j.m_assistsPerGame <  m_actual_i.m_assistsPerGame) swap = TRUE;
				}
				else if(choice == 4)
				{
					if( m_actual_j.m_stealsPerGame <  m_actual_i.m_stealsPerGame) swap = TRUE;
				}
				else if(choice == 5)
				{
					if( m_actual_j.m_blocksPerGame <  m_actual_i.m_blocksPerGame) swap = TRUE;
				}
				else if(choice == 6)
				{
					if( m_actual_j.m_pointsPerGame <  m_actual_i.m_pointsPerGame) swap = TRUE;
				}
				else if(choice == 7)
				{
					if( m_actual_j.m_fgPct <  m_actual_i.m_fgPct) swap = TRUE;
				}
				else if(choice == 8)
				{
					if( m_actual_j.m_ftPct <  m_actual_i.m_ftPct) swap = TRUE;
				}
				else if(choice == 9)
				{
					if( m_actual_j.m_tfgPct <  m_actual_i.m_tfgPct) swap = TRUE;
				}
				else if(choice == 10)
				{
						if( m_actual_j.m_trueRating <  m_actual_i.m_trueRating) swap = TRUE;
				}
				else if(choice == 11)
				{
					if( m_actual_j.m_teammatesBetterRating <  m_actual_i.m_teammatesBetterRating) swap = TRUE;
				}
				else if(choice == 12)
				{
					if( m_actual_j.m_astTo <  m_actual_i.m_astTo) swap = TRUE;
				}
				else if(choice == 13)
				{
					if( m_actual_j.m_defense <  m_actual_i.m_defense) swap = TRUE;
				}
				else if(choice == 14)
				{
					if( m_actual_j.m_outside <  m_actual_i.m_outside) swap = TRUE;
				}
				else if(choice == 15)
				{
					if( m_actual_j.m_driving <  m_actual_i.m_driving) swap = TRUE;
				}
				else if(choice == 16)
				{
					if( m_actual_j.m_post <  m_actual_i.m_post) swap = TRUE;
				}
				else if(choice == 17)
				{
					if( m_actual_j.m_transition <  m_actual_i.m_transition) swap = TRUE;
				}
				else if(choice == 18)
				{
					if( m_actual_j.m_outsideDefense <  m_actual_i.m_outsideDefense) swap = TRUE;
				}
				else if(choice == 19)
				{
					if( m_actual_j.m_drivingDefense <  m_actual_i.m_drivingDefense) swap = TRUE;
				}
				else if(choice == 20)
				{
					if( m_actual_j.m_postDefense <  m_actual_i.m_postDefense) swap = TRUE;
				}
				else if(choice == 21)
				{
					if( m_actual_j.m_transitionDefense <  m_actual_i.m_transitionDefense) swap = TRUE;
				}
				else if(choice == 22)
				{
					if( m_actual_j.m_outsidePer48Min <  m_actual_i.m_outsidePer48Min) swap = TRUE;
				}
				else if(choice == 23)
				{
					if( m_actual_j.m_drivingPer48Min <  m_actual_i.m_drivingPer48Min) swap = TRUE;
				}
				else if(choice == 24)
				{
					if( m_actual_j.m_postPer48Min <  m_actual_i.m_postPer48Min) swap = TRUE;
				}
				else if(choice == 25)
				{
					if( m_actual_j.m_transitionPer48Min <  m_actual_i.m_transitionPer48Min) swap = TRUE;
				}
				else if(choice == 26)
				{
					if( m_actual_j.m_outsideDefensePer48Min <  m_actual_i.m_outsideDefensePer48Min) swap = TRUE;
				}
				else if(choice == 27)
				{
					if( m_actual_j.m_drivingDefensePer48Min <  m_actual_i.m_drivingDefensePer48Min) swap = TRUE;
				}
				else if(choice == 28)
				{
					if( m_actual_j.m_postDefensePer48Min <  m_actual_i.m_postDefensePer48Min) swap = TRUE;
				}
				else if(choice == 29)
				{
					if( m_actual_j.m_transitionDefensePer48Min <  m_actual_i.m_transitionDefensePer48Min) swap = TRUE;
				}
				else if(choice == 30)
				{
					if( m_actual_j.m_mvp <  m_actual_i.m_mvp) swap = TRUE;
				}

//				if(swap == TRUE)
//				{
//					CPlayer temp = avg.m_actual[i];
//					avg.m_actual[i] =  avg.m_actual[j];
//					avg.m_actual[j] = temp;
//				}
//			}
//			
//	}	
	return swap;

		
}

bool CLeadersDlg::SortSimulatedStats(CPlayer m_actual_j, CPlayer m_actual_i)
{
//	m_buttonLeaders.EnableWindow(FALSE);
	m_listLeaders.DeleteAllItems();
	int choice = m_listStats.GetCurSel(); 

	//for(int i = 1; i <= 480; i++)
	//{
	//		for(int j = 1; j <= 480; j++)
	//		{
				bool swap = FALSE;

				if(choice == 1)
				{
					if( m_actual_j.m_sim_minPerGame <  m_actual_i.m_sim_minPerGame) swap = TRUE;
				}
				else if(choice == 0)
				{
					if( m_actual_j.m_sim_games <  m_actual_i.m_sim_games) swap = TRUE;
				}
				else if(choice == 2)
				{
					if( m_actual_j.m_sim_reboundsPerGame <  m_actual_i.m_sim_reboundsPerGame) swap = TRUE;
				}
				else if(choice == 3)
				{
					if( m_actual_j.m_sim_assistsPerGame <  m_actual_i.m_sim_assistsPerGame) swap = TRUE;
				}
				else if(choice == 4)
				{
					if( m_actual_j.m_sim_stealsPerGame <  m_actual_i.m_sim_stealsPerGame) swap = TRUE;
				}
				else if(choice == 5)
				{
					if( m_actual_j.m_sim_blocksPerGame <  m_actual_i.m_sim_blocksPerGame) swap = TRUE;
				}
				else if(choice == 6)
				{
					if( m_actual_j.m_sim_pointsPerGame <  m_actual_i.m_sim_pointsPerGame) swap = TRUE;
				}
				else if(choice == 7)
				{
					if( m_actual_j.m_sim_fgPct <  m_actual_i.m_sim_fgPct) swap = TRUE;
				}
				else if(choice == 8)
				{
					if( m_actual_j.m_sim_ftPct <  m_actual_i.m_sim_ftPct) swap = TRUE;
				}
				else if(choice == 9)
				{
					if( m_actual_j.m_sim_tfgPct <  m_actual_i.m_sim_tfgPct) swap = TRUE;
				}
				else if(choice == 10)
				{
						if( m_actual_j.m_sim_trueRating <  m_actual_i.m_sim_trueRating) swap = TRUE;
				}
				else if(choice == 11)
				{
					if( m_actual_j.m_sim_teammatesBetterRating <  m_actual_i.m_sim_teammatesBetterRating) swap = TRUE;
				}
				else if(choice == 12)
				{
					if( m_actual_j.m_sim_astTo <  m_actual_i.m_sim_astTo) swap = TRUE;
				}
				else if(choice == 13)
				{
					if( m_actual_j.m_sim_defense <  m_actual_i.m_sim_defense) swap = TRUE;
				}
				else if(choice == 14)
				{
					if( m_actual_j.m_sim_outside <  m_actual_i.m_sim_outside) swap = TRUE;
				}
				else if(choice == 15)
				{
					if( m_actual_j.m_sim_driving <  m_actual_i.m_sim_driving) swap = TRUE;
				}
				else if(choice == 16)
				{
					if( m_actual_j.m_sim_post <  m_actual_i.m_sim_post) swap = TRUE;
				}
				else if(choice == 17)
				{
					if( m_actual_j.m_sim_transition <  m_actual_i.m_sim_transition) swap = TRUE;
				}
				else if(choice == 18)
				{
					if( m_actual_j.m_sim_outsideDefense <  m_actual_i.m_sim_outsideDefense) swap = TRUE;
				}
				else if(choice == 19)
				{
					if( m_actual_j.m_sim_drivingDefense <  m_actual_i.m_sim_drivingDefense) swap = TRUE;
				}
				else if(choice == 20)
				{
					if( m_actual_j.m_sim_postDefense <  m_actual_i.m_sim_postDefense) swap = TRUE;
				}
				else if(choice == 21)
				{
					if( m_actual_j.m_sim_transitionDefense <  m_actual_i.m_sim_transitionDefense) swap = TRUE;
				}
				else if(choice == 22)
				{
					if( m_actual_j.m_sim_outsidePer48Min <  m_actual_i.m_sim_outsidePer48Min) swap = TRUE;
				}
				else if(choice == 23)
				{
					if( m_actual_j.m_sim_drivingPer48Min <  m_actual_i.m_sim_drivingPer48Min) swap = TRUE;
				}
				else if(choice == 24)
				{
					if( m_actual_j.m_sim_postPer48Min <  m_actual_i.m_sim_postPer48Min) swap = TRUE;
				}
				else if(choice == 25)
				{
					if( m_actual_j.m_sim_transitionPer48Min <  m_actual_i.m_sim_transitionPer48Min) swap = TRUE;
				}
				else if(choice == 26)
				{
					if( m_actual_j.m_sim_outsideDefensePer48Min <  m_actual_i.m_sim_outsideDefensePer48Min) swap = TRUE;
				}
				else if(choice == 27)
				{
					if( m_actual_j.m_sim_drivingDefensePer48Min <  m_actual_i.m_sim_drivingDefensePer48Min) swap = TRUE;
				}
				else if(choice == 28)
				{
					if( m_actual_j.m_sim_postDefensePer48Min <  m_actual_i.m_sim_postDefensePer48Min) swap = TRUE;
				}
				else if(choice == 29)
				{
					if( m_actual_j.m_sim_transitionDefensePer48Min <  m_actual_i.m_sim_transitionDefensePer48Min) swap = TRUE;
				}
				else if(choice == 30)
				{
					if( m_actual_j.m_sim_mvp <  m_actual_i.m_sim_mvp) swap = TRUE;
				}

//				if(swap == FALSE)
//				{
//					CPlayer temp = avg.m_actual[i];
//					avg.m_actual[i] =  avg.m_actual[j];
//					avg.m_actual[j] = temp;
//				}


				return swap;
//			}
			
//	}	
	
		
}

bool CLeadersDlg::SortPlayoffStats(CPlayer m_actual_j, CPlayer m_actual_i)
{
//	m_buttonLeaders.EnableWindow(FALSE);
	m_listLeaders.DeleteAllItems();
	int choice = m_listStats.GetCurSel(); 

				bool swap = FALSE;

				if(choice == 1)
				{
					if( m_actual_j.m_po_minPerGame <  m_actual_i.m_po_minPerGame) swap = TRUE;
				}
				else if(choice == 0)
				{
					if( m_actual_j.m_po_games <  m_actual_i.m_po_games) swap = TRUE;
				}
				else if(choice == 2)
				{
					if( m_actual_j.m_po_reboundsPerGame <  m_actual_i.m_po_reboundsPerGame) swap = TRUE;
				}
				else if(choice == 3)
				{
					if( m_actual_j.m_po_assistsPerGame <  m_actual_i.m_po_assistsPerGame) swap = TRUE;
				}
				else if(choice == 4)
				{
					if( m_actual_j.m_po_stealsPerGame <  m_actual_i.m_po_stealsPerGame) swap = TRUE;
				}
				else if(choice == 5)
				{
					if( m_actual_j.m_po_blocksPerGame <  m_actual_i.m_po_blocksPerGame) swap = TRUE;
				}
				else if(choice == 6)
				{
					if( m_actual_j.m_po_pointsPerGame <  m_actual_i.m_po_pointsPerGame) swap = TRUE;
				}
				else if(choice == 7)
				{
					if( m_actual_j.m_po_fgPct <  m_actual_i.m_po_fgPct) swap = TRUE;
				}
				else if(choice == 8)
				{
					if( m_actual_j.m_po_ftPct <  m_actual_i.m_po_ftPct) swap = TRUE;
				}
				else if(choice == 9)
				{
					if( m_actual_j.m_po_tfgPct <  m_actual_i.m_po_tfgPct) swap = TRUE;
				}
				else if(choice == 10)
				{
						if( m_actual_j.m_po_trueRating <  m_actual_i.m_po_trueRating) swap = TRUE;
				}
				else if(choice == 11)
				{
					if( m_actual_j.m_po_teammatesBetterRating <  m_actual_i.m_po_teammatesBetterRating) swap = TRUE;
				}
				else if(choice == 12)
				{
					if( m_actual_j.m_po_astTo <  m_actual_i.m_po_astTo) swap = TRUE;
				}
				else if(choice == 13)
				{
					if( m_actual_j.m_po_defense <  m_actual_i.m_po_defense) swap = TRUE;
				}
				else if(choice == 14)
				{
					if( m_actual_j.m_po_outside <  m_actual_i.m_po_outside) swap = TRUE;
				}
				else if(choice == 15)
				{
					if( m_actual_j.m_po_driving <  m_actual_i.m_po_driving) swap = TRUE;
				}
				else if(choice == 16)
				{
					if( m_actual_j.m_po_post <  m_actual_i.m_po_post) swap = TRUE;
				}
				else if(choice == 17)
				{
					if( m_actual_j.m_po_transition <  m_actual_i.m_po_transition) swap = TRUE;
				}
				else if(choice == 18)
				{
					if( m_actual_j.m_po_outsideDefense <  m_actual_i.m_po_outsideDefense) swap = TRUE;
				}
				else if(choice == 19)
				{
					if( m_actual_j.m_po_drivingDefense <  m_actual_i.m_po_drivingDefense) swap = TRUE;
				}
				else if(choice == 20)
				{
					if( m_actual_j.m_po_postDefense <  m_actual_i.m_po_postDefense) swap = TRUE;
				}
				else if(choice == 21)
				{
					if( m_actual_j.m_po_transitionDefense <  m_actual_i.m_po_transitionDefense) swap = TRUE;
				}
				else if(choice == 22)
				{
					if( m_actual_j.m_po_outsidePer48Min <  m_actual_i.m_po_outsidePer48Min) swap = TRUE;
				}
				else if(choice == 23)
				{
					if( m_actual_j.m_po_drivingPer48Min <  m_actual_i.m_po_drivingPer48Min) swap = TRUE;
				}
				else if(choice == 24)
				{
					if( m_actual_j.m_po_postPer48Min <  m_actual_i.m_po_postPer48Min) swap = TRUE;
				}
				else if(choice == 25)
				{
					if( m_actual_j.m_po_transitionPer48Min <  m_actual_i.m_po_transitionPer48Min) swap = TRUE;
				}
				else if(choice == 26)
				{
					if( m_actual_j.m_po_outsideDefensePer48Min <  m_actual_i.m_po_outsideDefensePer48Min) swap = TRUE;
				}
				else if(choice == 27)
				{
					if( m_actual_j.m_po_drivingDefensePer48Min <  m_actual_i.m_po_drivingDefensePer48Min) swap = TRUE;
				}
				else if(choice == 28)
				{
					if( m_actual_j.m_po_postDefensePer48Min <  m_actual_i.m_po_postDefensePer48Min) swap = TRUE;
				}
				else if(choice == 29)
				{
					if( m_actual_j.m_po_transitionDefensePer48Min <  m_actual_i.m_po_transitionDefensePer48Min) swap = TRUE;
				}
				else if(choice == 30)
				{
					if( m_actual_j.m_po_mvp <  m_actual_i.m_po_mvp) swap = TRUE;
				}



				return swap;
		
}
	
void CLeadersDlg::ListStats()
{

}

void CLeadersDlg::QuickSort()
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
}

bool CLeadersDlg::SortFunction(CPlayer m_player, CPlayer temp)
{
	bool swap = false;

	if(m_statStyle == ACTUAL)
		swap = SortActualStats(m_player, temp);
	else if(m_statStyle == SIMULATED)
		swap = SortSimulatedStats(m_player, temp);
	else if(m_statStyle == PLAYOFF)
		swap = SortPlayoffStats(m_player, temp);

	return swap;
}

void CLeadersDlg::ChooseStatsToList()
{
	int choice = m_listStats.GetCurSel(); 
	if(m_statStyle == ACTUAL)
	{
	int rank = 0;
	int games =  avg.m_hi_g[0];
	if(games > 82) games = 82;
	int co = 0;
	for(int  i=0; i<=1600; i++)
	{
			BOOL Eligible = FALSE;
			CString name =  avg.m_actual[i].GetName();
			CString team =  avg.m_actual[i].GetTeam();
			CString result;
			CString string;
			CString ranking;
			if(choice == 1)
			{
				if(double( avg.m_actual[i].m_min )/double(games) >= 2000./82. || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_minPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 0)
			{
				string.Format("%d",  avg.m_actual[i].m_games);
				Eligible = TRUE;
			}
			else if(choice == 2)
			{
				if((double( avg.m_actual[i].m_oreb) + double( avg.m_actual[i].m_reb))/double(games) >= 800./82. || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_reboundsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 3)
			{
				if(double( avg.m_actual[i].m_ast)/double(games) >= 400./82. || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_assistsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 4)
			{
				if(double( avg.m_actual[i].m_stl)/double(games) >= 125./82. || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_stealsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 5)
			{
				if(double( avg.m_actual[i].m_blk)/double(games) >= 100./82. || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_blocksPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 6)
			{
				double x =  avg.m_actual[i].m_pointsPerGame * double( avg.m_actual[i].m_games)/double(games);
				double y = 1400./82.;
				if(x >= y || double( avg.m_actual[i].m_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_pointsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 7)
			{
				double x = (double( avg.m_actual[i].m_fgm) + double( avg.m_actual[i].m_tfgm))/double(games); 
				double y = 300./82.;
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_fgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 8)
			{
				double x = double( avg.m_actual[i].m_ftm)/double(games);
				double y = 125./82.;
				if(x >= y)  
				{
					string.Format("%.2f",  avg.m_actual[i].m_ftPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 9)
			{
				double x = double( avg.m_actual[i].m_tfgm)/double(games);
				double y = 55./82.; 
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_tfgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 10)
			{
				Eligible = TRUE;
				string.Format("%.2f",  avg.m_actual[i].m_trueRating);
			}
			else if(choice == 11)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_teammatesBetterRating);
			}
			else if(choice == 12)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_astTo);
			}
			else if(choice == 13)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_defense);
			}
			else if(choice == 14)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_outside);
			}
			else if(choice == 15)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_driving);
			}
			else if(choice == 16)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_post);
			}
			else if(choice == 17)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_transition);
			}
			else if(choice == 18)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_outsideDefense);
			}
			else if(choice == 19)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_drivingDefense);
			}
			else if(choice == 20)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_postDefense);
			}
			else if(choice == 21)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_transitionDefense);
			}
			else if(choice == 22)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_outsidePer48Min);
			}
			else if(choice == 23)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_drivingPer48Min);
			}
			else if(choice == 24)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_postPer48Min);
			}
			else if(choice == 25)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_transitionPer48Min);
			}
			else if(choice == 26)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_outsideDefensePer48Min);
			}
			else if(choice == 27)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_drivingDefensePer48Min);
			}
			else if(choice == 28)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_postDefensePer48Min);
			}
			else if(choice == 29)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_transitionDefensePer48Min);
			}
			else if(choice == 30)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_mvp);
			}

			if(Eligible == TRUE)// check if positions match
			{
				if( avg.m_actual[i].GetPos() == m_sortPosition ||
					m_sortPosition == "All") Eligible = TRUE;
				else
					Eligible = FALSE;
			}


			if(Eligible == TRUE)
			{
				if(name == team) team = "";//so it won't display team then team
				if(name != "" && string != "0.00")
				{
				rank = rank + 1;
				ranking.Format("%d", rank);
				result.Format("%3s %-16s %-16s %3s",ranking,name,team,string);

				m_listLeaders.InsertItem(co,ranking);
//				for(int s=0; s<=20; s++)
//				{
					m_listLeaders.SetItemText(co,1,name);
//				}
					m_listLeaders.SetItemText(co,2,team);
					m_listLeaders.SetItemText(co,3,string);


//				m_listLeaders.AddString(result);
				co = co + 1;
//				m_buttonLeaders.EnableWindow(TRUE);
				}

			}
	}
	}
	else if(m_statStyle == SIMULATED)
	{

	int rank = 0, co = 0;
	for(int  i=0; i<=1600; i++)
	{
			int index =  avg.m_actual[i].m_current_team + 1;
			int games = m_team_hi_g[index];
			if(index > 32)
				games = avg.m_hi_g[0];//free agents so use league games before eligible
			if(games > 82) games = 82;

			BOOL Eligible = FALSE;
			CString name =  avg.m_actual[i].GetName();
			CString team =  avg.m_actual[i].GetTeam();
			CString result;
			CString string;
			CString ranking;
			if(choice == 1)
			{
				if(double( avg.m_actual[i].m_sim_min )/double(games) >= 2000./82. || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_minPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 0)
			{
				string.Format("%d",  avg.m_actual[i].m_sim_games);
				Eligible = TRUE;
			}
			else if(choice == 2)
			{
				if((double( avg.m_actual[i].m_sim_oreb) + double( avg.m_actual[i].m_sim_reb))/double(games) >= 800./82. || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_reboundsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 3)
			{
				if(double( avg.m_actual[i].m_sim_ast)/double(games) >= 400./82. || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_assistsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 4)
			{
				if(double( avg.m_actual[i].m_sim_stl)/double(games) >= 125./82. || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_stealsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 5)
			{
				if(double( avg.m_actual[i].m_sim_blk)/double(games) >= 100./82. || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_blocksPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 6)
			{
				double x =  avg.m_actual[i].m_sim_pointsPerGame * double( avg.m_actual[i].m_sim_games)/double(games);
				double y = 1400./82.;
				if(x >= y || double( avg.m_actual[i].m_sim_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_pointsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 7)
			{
				double x = (double( avg.m_actual[i].m_sim_fgm) + double( avg.m_actual[i].m_sim_tfgm))/double(games); 
				double y = 300./82.;
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_fgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 8)
			{
				double x = double( avg.m_actual[i].m_sim_ftm)/double(games);
				double y = 125./82.;
				if(x >= y)  
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_ftPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 9)
			{
				double x = double( avg.m_actual[i].m_sim_tfgm)/double(games);
				double y = 55./82.; 
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_sim_tfgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 10)
			{
				Eligible = TRUE;
				string.Format("%.2f",  avg.m_actual[i].m_sim_trueRating);
			}
			else if(choice == 11)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_teammatesBetterRating);
			}
			else if(choice == 12)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_astTo);
			}
			else if(choice == 13)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_defense);
			}
			else if(choice == 14)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_outside);
			}
			else if(choice == 15)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_driving);
			}
			else if(choice == 16)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_post);
			}
			else if(choice == 17)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_transition);
			}
			else if(choice == 18)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_outsideDefense);
			}
			else if(choice == 19)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_drivingDefense);
			}
			else if(choice == 20)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_postDefense);
			}
			else if(choice == 21)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_transitionDefense);
			}
			else if(choice == 22)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_outsidePer48Min);
			}
			else if(choice == 23)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_drivingPer48Min);
			}
			else if(choice == 24)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_postPer48Min);
			}
			else if(choice == 25)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_transitionPer48Min);
			}
			else if(choice == 26)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_outsideDefensePer48Min);
			}
			else if(choice == 27)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_drivingDefensePer48Min);
			}
			else if(choice == 28)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_postDefensePer48Min);
			}
			else if(choice == 29)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_transitionDefensePer48Min);
			}
			else if(choice == 30)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_sim_mvp);
			}

			if(Eligible == TRUE)// check if positions match
			{
				if( avg.m_actual[i].GetPos() == m_sortPosition ||
					m_sortPosition == "All") Eligible = TRUE;
				else
					Eligible = FALSE;
			}

			if(m_teamDefenseSelected == TRUE && (avg.m_actual[i].m_original_number < 1441 ||
				avg.m_actual[i].m_original_number > 1472))
				Eligible = FALSE;
			else if(m_teamOffenseSelected == TRUE && (avg.m_actual[i].m_original_number < 1473 ||
				avg.m_actual[i].m_original_number > 1504))
				Eligible = FALSE;
			else if(m_playersSelected == TRUE && avg.m_actual[i].m_original_number >= 1441 &&
				avg.m_actual[i].m_original_number <= 1504)
				Eligible = FALSE;


			if(Eligible == TRUE)
			{
				if(name == team) team = "";//so it won't display team then team
				if(name != "" && avg.m_actual[i].m_original_number > 0 && string != "0.00")
				{
				rank = rank + 1;
				ranking.Format("%d", rank);
				result.Format("%3s %-16s %-16s %3s",ranking,name,team,string);

				m_listLeaders.InsertItem(co,ranking);
					m_listLeaders.SetItemText(co,1,name);
					m_listLeaders.SetItemText(co,2,team);
					m_listLeaders.SetItemText(co,3,string);

				co = co + 1;
				m_id_list[co] = i;

				}
			}
	}




	}
	else if(m_statStyle == PLAYOFF)
	{

	int rank = 0, co = 0;
	for(int  i=0; i<=1600; i++)
	{
			int index =  avg.m_actual[i].m_team_index;
			int games = m_po_team_hi_g[index];
			BOOL Eligible = FALSE;
			CString name =  avg.m_actual[i].GetName();
			CString team =  avg.m_actual[i].GetTeam();
			CString result;
			CString string;
			CString ranking;
			if(choice == 1)
			{
				if(double( avg.m_actual[i].m_po_min )/double(games) >= 2000./82. || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_minPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 0)
			{
				string.Format("%d",  avg.m_actual[i].m_po_games);
				Eligible = TRUE;
			}
			else if(choice == 2)
			{
				if((double( avg.m_actual[i].m_po_oreb) + double( avg.m_actual[i].m_po_reb))/double(games) >= 800./82. || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_reboundsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 3)
			{
				if(double( avg.m_actual[i].m_po_ast)/double(games) >= 400./82. || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_assistsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 4)
			{
				if(double( avg.m_actual[i].m_po_stl)/double(games) >= 125./82. || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_stealsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 5)
			{
				if(double( avg.m_actual[i].m_po_blk)/double(games) >= 100./82. || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_blocksPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 6)
			{
				double x =  avg.m_actual[i].m_po_pointsPerGame * double( avg.m_actual[i].m_po_games)/double(games);
				double y = 1400./82.;
				if(x >= y || double( avg.m_actual[i].m_po_games)/double(games) >= 70./82.) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_pointsPerGame);
					Eligible = TRUE;
				}
			}
			else if(choice == 7)
			{
				double x = (double( avg.m_actual[i].m_po_fgm) + double( avg.m_actual[i].m_po_tfgm))/double(games); 
				double y = 300./82.;
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_fgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 8)
			{
				double x = double( avg.m_actual[i].m_po_ftm)/double(games);
				double y = 125./82.;
				if(x >= y)  
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_ftPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 9)
			{
				double x = double( avg.m_actual[i].m_po_tfgm)/double(games);
				double y = 55./82.; 
				if(x >= y) 
				{
					string.Format("%.2f",  avg.m_actual[i].m_po_tfgPct);
					Eligible = TRUE;
				}
			}
			else if(choice == 10)
			{
				Eligible = TRUE;
				string.Format("%.2f",  avg.m_actual[i].m_po_trueRating);
			}
			else if(choice == 11)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_teammatesBetterRating);
			}
			else if(choice == 12)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_astTo);
			}
			else if(choice == 13)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_defense);
			}
			else if(choice == 14)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_outside);
			}
			else if(choice == 15)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_driving);
			}
			else if(choice == 16)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_post);
			}
			else if(choice == 17)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_transition);
			}
			else if(choice == 18)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_outsideDefense);
			}
			else if(choice == 19)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_drivingDefense);
			}
			else if(choice == 20)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_postDefense);
			}
			else if(choice == 21)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_transitionDefense);
			}
			else if(choice == 22)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_outsidePer48Min);
			}
			else if(choice == 23)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_drivingPer48Min);
			}
			else if(choice == 24)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_postPer48Min);
			}
			else if(choice == 25)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_transitionPer48Min);
			}
			else if(choice == 26)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_outsideDefensePer48Min);
			}
			else if(choice == 27)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_drivingDefensePer48Min);
			}
			else if(choice == 28)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_postDefensePer48Min);
			}
			else if(choice == 29)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_transitionDefensePer48Min);
			}
			else if(choice == 30)
			{
					Eligible = TRUE;
					string.Format("%.2f",  avg.m_actual[i].m_po_mvp);
			}

			if(Eligible == TRUE)// check if positions match
			{
				if( avg.m_actual[i].GetPos() == m_sortPosition ||
					m_sortPosition == "All") Eligible = TRUE;
				else
					Eligible = FALSE;
			}

			if(m_teamDefenseSelected == TRUE && (avg.m_actual[i].m_original_number < 1441 ||
				avg.m_actual[i].m_original_number > 1472))
				Eligible = FALSE;
			else if(m_teamOffenseSelected == TRUE && (avg.m_actual[i].m_original_number < 1473 ||
				avg.m_actual[i].m_original_number > 1504))
				Eligible = FALSE;
			else if(m_playersSelected == TRUE && avg.m_actual[i].m_original_number >= 1441 &&
				avg.m_actual[i].m_original_number <= 1504)
				Eligible = FALSE;


			if(Eligible == TRUE)
			{
				if(name == team) team = "";//so it won't display team then team
				if(name != "" && avg.m_actual[i].m_original_number > 0 && string != "0.00")
				{

				rank = rank + 1;
				ranking.Format("%d", rank);
				result.Format("%3s %-16s %-16s %3s",ranking,name,team,string);


					m_listLeaders.InsertItem(co,ranking);
					m_listLeaders.SetItemText(co,1,name);
					m_listLeaders.SetItemText(co,2,team);
					m_listLeaders.SetItemText(co,3,string);


				co = co + 1;

				m_id_list[co] = i;


//				if(name != "") m_listLeaders.AddString(result);
//				m_buttonLeaders.EnableWindow(TRUE);
				}
			}
	}




	}


}

void CLeadersDlg::OnDblclkListCtrlLeaders(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int count = m_listLeaders.GetItemCount();

	if(count > 0)
	{

	int j = m_listLeaders.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(j >= 1)
	{

	CPlayer m_player = avg.m_actual[m_id_list[j]];


	int players_listed = count;
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
		scout->avg.m_actual[c] = avg.m_actual[m_id_list[c]];
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




void CLeadersDlg::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listLeaders.SetBkColor(BK_COLOR);
	m_listLeaders.SetTextBkColor(TEXT_BK_COLOR);

	m_listLeaders.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    m_listLeaders.SetTextColor(RGB(0,0,0));
	m_listLeaders.SetFont(&m_font);


    m_listLeaders.DeleteColumn(0);
    m_listLeaders.InsertColumn(0,"rank");    
	m_listLeaders.DeleteColumn(1);
    m_listLeaders.InsertColumn(1,"player");    
	m_listLeaders.DeleteColumn(2);
    m_listLeaders.InsertColumn(2,"team");    
	m_listLeaders.DeleteColumn(3);
    m_listLeaders.InsertColumn(3,"");    

	m_listLeaders.SetColumnWidth(0,32);
	m_listLeaders.SetColumnWidth(1,92);
	m_listLeaders.SetColumnWidth(2,92);
	m_listLeaders.SetColumnWidth(3,42);

//	m_rows = 0;

}


void CLeadersDlg::OnLvnItemchangedListCtrlLeaders(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
