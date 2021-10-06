// DraftDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "DraftDlg.h"
//#ifndef Display_h
//#include "Display.h"
//#define Display_h
//#endif 
//#include "Display.h"
#include "TradeDlg.h"
//#include "ScoutDlg.h"
#include "PlayerCardDlg.h"


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
// CDraftDlg dialog


CDraftDlg::CDraftDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDraftDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDraftDlg)
	m_checkReverse = FALSE;
	m_checkConfirmed = FALSE;
	//}}AFX_DATA_INIT
	Player = new CPlayer[481];
	Rating = new CPlayer[2881];
	m_scout = new CStaff[101];
}


void CDraftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDraftDlg)
	DDX_Control(pDX, IDC_BUTTON_RANDOM, m_buttonRandom);
	DDX_Control(pDX, IDC_BUTTON_SG, m_buttonSg);
	DDX_Control(pDX, IDC_BUTTON_SF, m_buttonSf);
	DDX_Control(pDX, IDC_BUTTON_PG, m_buttonPg);
	DDX_Control(pDX, IDC_BUTTON_PF, m_buttonPf);
	DDX_Control(pDX, IDC_BUTTON_C, m_buttonC);
	DDX_Control(pDX, IDC_BUTTON_RATINGS, m_buttonRatings);
	DDX_Control(pDX, IDC_BUTTON_DRAFT, m_buttonDraft);
	DDX_Control(pDX, IDC_LIST_SELECTION, m_selection);
	DDX_Control(pDX, IDC_LIST_SG, m_listSg);
	DDX_Control(pDX, IDC_LIST_SF, m_listSf);
	DDX_Control(pDX, IDC_LIST_ROSTER, m_listRoster);
	DDX_Control(pDX, IDC_LIST_PG, m_listPg);
	DDX_Control(pDX, IDC_LIST_PF, m_listPf);
	DDX_Control(pDX, IDC_LIST_ORDER, m_listOrder);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listControl);
	DDX_Control(pDX, IDC_LIST_C, m_listC);
	DDX_Control(pDX, IDC_LIST_ALL, m_listAll);
	DDX_Check(pDX, IDC_CHECK_REVERSE, m_checkReverse);
	DDX_Check(pDX, IDC_CHECK_CONFIRMED, m_checkConfirmed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDraftDlg, CDialog)
	//{{AFX_MSG_MAP(CDraftDlg)
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_LBN_SELCHANGE(IDC_LIST_ORDER, OnSelchangeListOrder)
	ON_BN_CLICKED(IDC_BUTTON_DRAFT, OnButtonDraft)
	ON_LBN_DBLCLK(IDC_LIST_PG, OnDblclkListPg)
	ON_LBN_DBLCLK(IDC_LIST_SG, OnDblclkListSg)
	ON_LBN_DBLCLK(IDC_LIST_C, OnDblclkListC)
	ON_LBN_DBLCLK(IDC_LIST_SF, OnDblclkListSf)
	ON_LBN_DBLCLK(IDC_LIST_PF, OnDblclkListPf)
	ON_LBN_DBLCLK(IDC_LIST_ALL, OnDblclkListAll)
	ON_LBN_DBLCLK(IDC_LIST_ORDER, OnDblclkListOrder)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_RATINGS, OnButtonRatings)
	ON_WM_CTLCOLOR()
	ON_LBN_DBLCLK(IDC_LIST_ROSTER, OnDblclkListRoster)
	ON_BN_CLICKED(IDC_BUTTON_C, OnButtonC)
	ON_BN_CLICKED(IDC_BUTTON_PF, OnButtonPf)
	ON_BN_CLICKED(IDC_BUTTON_PG, OnButtonPg)
	ON_BN_CLICKED(IDC_BUTTON_SF, OnButtonSf)
	ON_BN_CLICKED(IDC_BUTTON_SG, OnButtonSg)
	ON_BN_CLICKED(IDC_BUTTON_RANDOM, OnButtonRandom)
	//}}AFX_MSG_MAP
	ON_LBN_SELCHANGE(IDC_LIST_ROSTER, &CDraftDlg::OnLbnSelchangeListRoster)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDraftDlg message handlers

BOOL CDraftDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	myBrush.CreateSolidBrush(DLGCOLOR); 
	draftOver = false;
	m_checkReverse = TRUE;
	m_checkConfirmed = FALSE;
	m_buttonDraft.SetWindowText("Begin Draft");

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.
	m_listRoster.SetFont(&m_font);
	m_selection.SetFont(&m_font);
	m_listSg.SetFont(&m_font);
	m_listSf.SetFont(&m_font);
	m_listRoster.SetFont(&m_font);
	m_listPg.SetFont(&m_font);
	m_listPf.SetFont(&m_font);
	m_listOrder.SetFont(&m_font);
	m_listControl.SetFont(&m_font);
	m_listC.SetFont(&m_font);
	m_listAll.SetFont(&m_font);




//	UpdateData(FALSE);

	// TODO: Add extra initialization here
	for(int t=0; t<=32; t++)		
	{
		for(int v=0; v<=15; v++)		
		{
			PlayerSlot[t][v] = 0;
		}
	}	
	for(int p=0; p<=2880; p++)		
	{
		Chosen[p] = false;
	}
	for(int p=0; p<=5; p++)		
	{
		players[p] = 0;
	}
	for(int p=0; p<=32; p++)		
	{
		m_originalDraftOrder[p] = 0;
	}
	m_draftStarted = false;
	m_currentTeam = 1;
	m_currentRound = 1;
	m_teamsInLeague = 0;
	m_gm = false;
	m_orderClicked = false;

	for(int  i=0; i<32; i++)
		{
			if(m_leagueTeamNames[i] != "")
			{
				m_originalDraftOrder[i] = i;
				m_listOrder.AddString(m_leagueTeamNames[i]);
				m_teamsInLeague = m_teamsInLeague + 1;
				m_listControl.AddString(m_control[i]);
			}
		}

	CString temp = m_leagueName;
	
	m_leagueName = temp;
		for(int i=1; i<=480; i++)
		{

			if(Player[i].GetName() != "")
			{
				Player[i].SetJustSignedContracts();
				players[0] = players[0] + 1;
				Rating[2400+players[0]] = Player[i];//all players 
			}
			if(Player[i].GetPos() == "PG" && Player[i].GetName() != "")
			{
				players[1] = players[1] + 1;
				Rating[players[1]] = Player[i];
			}
			else if(Player[i].GetPos() == "SG" && Player[i].GetName() != "")
			{
				players[2] = players[2] + 1;
				Rating[480 + players[2]] = Player[i];
			}
			else if(Player[i].GetPos() == "SF" && Player[i].GetName() != "")
			{
				players[3] = players[3] + 1;
				Rating[960 + players[3]]= Player[i];
			}
			else if(Player[i].GetPos() == "PF" && Player[i].GetName() != "")
			{
				players[4] = players[4] + 1;
				Rating[1440 + players[4]] = Player[i];
			}
			else if(Player[i].GetPos() == " C" && Player[i].GetName() != "")
			{
				players[5] = players[5] + 1;
				Rating[1920 + players[5]] = Player[i];
			}
		}
		for(int k=0; k<=5; k++)		
		{
		for(int i=1; i<=players[k]; i++)
				{
					for(int j=1; j<=i; j++)
					{
						int index1 = (k-1)*480+i;
						int index2 = (k-1)*480+j;
						if(k == 0)
						{
							index1 = 2400 + i;
							index2 = 2400 + j;
						}
						double r1 = Rating[index1].GetTradeTrueRating(m_checkCareer);
						double r2 = Rating[index2].GetTradeTrueRating(m_checkCareer);
						if(m_checkCareer == TRUE)
						{
							r1 = Rating[index1].GetTradeValue();
							r2 = Rating[index2].GetTradeValue();
						}
						if(r1 >= r2)
						{
							CPlayer temp = Rating[index2];
							Rating[index2] = Rating[index1];
							Rating[index1] = temp;
						}
					}
				}			
		}

	for(int i=1; i<=players[0]; i++)
	{
			CString name = Rating[2400+i].GetName();
			CString pos = Rating[2400+i].GetPos();
			if(pos == "PG")
				m_listPg.AddString(name);
			else if(pos == "SG")
				m_listSg.AddString(name);
			else if(pos == "SF")
				m_listSf.AddString(name);
			else if(pos == "PF")
				m_listPf.AddString(name);
			else if(pos == " C")
				m_listC.AddString(name);	
			m_listAll.AddString(name);
	}
	m_listOrder.SetCurSel(0);
	OnSelchangeListOrder(); 
	m_listAll.SetCurSel(0);
	UpdateData(FALSE);
	//OnSelchangeListAll(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDraftDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] Player;
	delete [] Rating;
	delete [] m_scout;


}

void CDraftDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_listOrder.GetCurSel();
	if(index >= 0)
	{
		CString TeamControl;
  		TeamControl = m_control[index];
		if(TeamControl == "Computer") TeamControl = "Player";
		else	TeamControl = "Computer";
		m_control[index] = TeamControl;
		m_listControl.ResetContent();
		m_listControl.AddString(TeamControl);
	}		
}


void CDraftDlg::OnSelchangeListOrder() 
{
	// TODO: Add your control notification handler code here
	int index = m_listOrder.GetCurSel();
	m_listControl.ResetContent();
	m_listControl.AddString(m_control[index]);

	int m_currentSelection;
	if(m_listOrder.GetCurSel() >= 0 )
	{
	m_currentSelection = m_listOrder.GetCurSel();
	m_listRoster.ResetContent();
	for(int  i = 1; i <= 15; ++i)
	{
		CPlayer m_player;
		int player = PlayerSlot[m_currentSelection+1][i];
		m_player = Rating[player];
		CString Stats;
		CString Name;
		Name = m_player.GetName();
		if(Name == "") continue;
		CString Pos = m_player.GetPos();
		Stats.Format
			("%3s %-16s",Pos, Name);
		m_listRoster.AddString(Stats);
	}
	}
	
}

void CDraftDlg::OnButtonDraft() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_buttonDraft.EnableWindow(FALSE);
	m_buttonRandom.EnableWindow(FALSE);

	if(draftOver == false)
	{
	m_draftStarted = true;
	bool roundOver = false;
	bool m_alternate = false;
	int evenI = m_currentRound/2;

	double evenD = double(m_currentRound)/2;
	if(evenI == evenD && m_checkReverse == TRUE) m_alternate = true;
	
	CString string;	
	if(m_currentTeam == 1 || (m_alternate == TRUE && m_currentTeam == m_teamsInLeague))
	{
		string.Format("* Start Round %d *",m_currentRound);
		m_selection.AddString(string);
	}

	
	
//	CDisplay* pick;
//	pick = new CDisplay();
	if(m_control[m_currentTeam-1] == "Computer")
	{
	do
	{
	bool allChosen = true;
	for(int p=2401; p<=2400+players[0]; p++)		
	{
		if(Rating[p].GetName() != "" && Chosen[p]  == false) allChosen = false;
	}	
	
	if(allChosen == false)
	{
		bool starters_picked = true;
		bool bench_picked = true;
		int slot = 0;
	for(int i=1; i<=5; i++)	
	{
		if(PlayerSlot[m_currentTeam][i] == 0) starters_picked = false;
	}

	for(int i=6; i<=10; i++)	
	{
		if(PlayerSlot[m_currentTeam][i] == 0) bench_picked = false;
	}
	
	if(starters_picked == false)
	{
		do
		{
			slot = Rating[0].IntRandom(5);
		} while (PlayerSlot[m_currentTeam][slot] > 0);
	}
	else if(bench_picked == false)
	{
		do
		{
			slot = Rating[0].IntRandom(5) + 5;
		} while (PlayerSlot[m_currentTeam][slot] > 0);
	}
	else
	{
		for(int i=11; i<=14; i++)	
		{
			if(slot == 0)
			{
				if(PlayerSlot[m_currentTeam][i] == 0) slot = i;
			}
		}
	}
	int pick = 0;
	int pos = slot;
	if(slot <= 10)
	{
		if(slot > 5) pos = pos - 5;
		pick = 0;
		for(int i=1; i<=players[pos]; i++)
		{
			//find player in complete player list in Rating[2401-2880] 
			int choose = 0;
			int index = (pos-1)*480+i;
			for(int j=2401; j<=2400+players[0]; j++)
			{
				if(Rating[index].GetName() != "" && 
					Rating[index].GetName() == Rating[j].GetName() &&
					choose == 0) choose = j;
			}

			if(pick == 0 && Chosen[choose] == false)
			{
				pick = choose;
				Chosen[choose] = true;
			}
		}
				
		PlayerSlot[m_currentTeam][slot] = pick;
		CString round;
		int turn = m_currentTeam;
		if(m_alternate == true) turn = m_teamsInLeague + 1 - turn;
		round.Format("Round %d Pick %d",m_currentRound, turn);
		m_selection.AddString(round);
		CString name = Rating[pick].GetName();
		CString po = Rating[pick].GetPos();
		int original = m_originalDraftOrder[m_currentTeam-1];
		CString teamName = m_leagueTeamNames[original];
		CString str = teamName + ": " + po + " " + name;
		m_selection.AddString(str);

		if(m_alternate == true) turn = m_teamsInLeague + 1 - turn;

		if(m_alternate == false) 
			m_currentTeam = m_currentTeam + 1;
		else
			m_currentTeam = m_currentTeam - 1;
		bool all = false;
		int i = 1;
		int player = m_listAll.GetCount();
		do
		{
			CString string;
			m_listAll.GetText(i-1, string);
			if(name == string)
			{
				m_listAll.DeleteString(i-1);
				all = true;
			}
			i = i+1;
		}
		while(i<=player && all == false);
		bool position = false;
		i = 1;
		if(pos == 1) 
			player = m_listPg.GetCount();
		else if(pos == 2) 
			player = m_listSg.GetCount();
		else if(pos == 3) 
			player = m_listSf.GetCount();
		else if(pos == 4) 
			player = m_listPf.GetCount();
		else if(pos == 5) 
			player = m_listC.GetCount();
		do
		{
			CString string;
			if(pos == 1)
				m_listPg.GetText(i-1, string);
			else if(pos == 2)
				m_listSg.GetText(i-1, string);
			else if(pos == 3)
				m_listSf.GetText(i-1, string);
			else if(pos == 4)
				m_listPf.GetText(i-1, string);
			else if(pos == 5)
				m_listC.GetText(i-1, string);
			if(name == string)
			{
				if(pos == 1)
					m_listPg.DeleteString(i-1);
				else if(pos == 2)
					m_listSg.DeleteString(i-1);
				else if(pos == 3)
					m_listSf.DeleteString(i-1);
				else if(pos == 4)
					m_listPf.DeleteString(i-1);
				else if(pos == 5)
					m_listC.DeleteString(i-1);
				position = true;
			}
			i = i+1;
		}
		while(i<=player && position == false);

		if(m_currentTeam > m_teamsInLeague || m_currentTeam < 1)
		{
			m_currentRound = m_currentRound + 1;
			roundOver = true;
			if(m_checkReverse == FALSE && m_alternate == false)
				m_currentTeam = 1;
			else if(m_checkReverse == TRUE && m_alternate == false)
			{
				m_currentTeam = m_teamsInLeague;
				m_alternate = true;
			}
			else if(m_checkReverse == TRUE && m_alternate == true)
			{
				m_currentTeam = 1;
				m_alternate = false;
			}

			if(m_currentRound > 14) draftOver = true;
		}



	}

	else if(slot>10)
	{
		pick = 0;
		for(int i=1; i<=players[0]; i++)
		{
			//find player in complete player list in Rating[2401-2880] 
			if(Chosen[i] == true || pick > 0) continue;
			int choose = 0;
			int index = 2400+i;
			for(int j=2401; j<=2400+players[0]; j++)
			{
				if(Rating[index].GetName() != "" && 
					Rating[index].GetName() == Rating[j].GetName() &&
					choose == 0) choose = j;
			}

			if(pick == 0 && Chosen[choose] == false)
			{
				pick = choose;
				Chosen[choose] = true;
			}
		}
				
		int tm = m_currentTeam;
		PlayerSlot[tm][slot] = pick;

		CString round;
		int turn = m_currentTeam;
		if(m_alternate == true) turn = m_teamsInLeague + 1 - turn;
		round.Format("Round %d Pick %d",m_currentRound, turn);
		m_selection.AddString(round);
		CString name = Rating[pick].GetName();
		CString p = Rating[pick].GetPos();
		if(p=="PG") pos = 1;
		else if(p=="SG") pos = 2;
		else if(p=="SF") pos = 3;
		else if(p=="PF") pos = 4;
		else if(p==" C") pos = 5;
		int original = m_originalDraftOrder[tm-1];
		CString teamName = m_leagueTeamNames[original];
		CString str = teamName + ": " + p + " " + name;
		m_selection.AddString(str);

		turn = m_currentTeam;
		if(m_alternate == true) turn = m_teamsInLeague + 1 - turn;

		if(m_alternate == false) 
			m_currentTeam = m_currentTeam + 1;
		else
			m_currentTeam = m_currentTeam - 1;


//		m_currentTeam = m_currentTeam + 1;
		bool all = false;
		int i = 1;
		int player = m_listAll.GetCount();
		do
		{
			CString string;
			m_listAll.GetText(i-1, string);
			if(name == string)
			{
				m_listAll.DeleteString(i-1);
				all = true;
			}
			i = i+1;
		}
		while(i<=player && all == false);
		bool position = false;
		i = 1;
		if(pos == 1) 
			player = m_listPg.GetCount();
		else if(pos == 2) 
			player = m_listSg.GetCount();
		else if(pos == 3) 
			player = m_listSf.GetCount();
		else if(pos == 4) 
			player = m_listPf.GetCount();
		else if(pos == 5) 
			player = m_listC.GetCount();
		do
		{
			CString string;
			if(pos == 1)
				m_listPg.GetText(i-1, string);
			else if(pos == 2)
				m_listSg.GetText(i-1, string);
			else if(pos == 3)
				m_listSf.GetText(i-1, string);
			else if(pos == 4)
				m_listPf.GetText(i-1, string);
			else if(pos == 5)
				m_listC.GetText(i-1, string);
			if(name == string)
			{
				if(pos == 1)
					m_listPg.DeleteString(i-1);
				else if(pos == 2)
					m_listSg.DeleteString(i-1);
				else if(pos == 3)
					m_listSf.DeleteString(i-1);
				else if(pos == 4)
					m_listPf.DeleteString(i-1);
				else if(pos == 5)
					m_listC.DeleteString(i-1);
				position = true;
			}
			i = i+1;
		}
		while(i<=player && position == false);
		if(m_currentTeam > m_teamsInLeague || m_currentTeam < 1)
		{
			m_currentRound = m_currentRound + 1;
			roundOver = true;
			if(m_checkReverse == FALSE && m_alternate == false)
				m_currentTeam = 1;
			else if(m_checkReverse == TRUE && m_alternate == false)
			{
				m_currentTeam = m_teamsInLeague;
				m_alternate = true;
			}
			else if(m_checkReverse == TRUE && m_alternate == true)
			{
				m_currentTeam = 1;
				m_alternate = false;
			}

			if(m_currentRound > 14) draftOver = true;
		}

	}
	}
	else
	{
		roundOver = true;
		draftOver = true;
	}

	} while (m_control[m_currentTeam-1] == "Computer" && draftOver == false && roundOver == false);
	}
	
//	UpdateData(FALSE);
	m_listOrder.SetCurSel(m_currentTeam-1);
	OnSelchangeListOrder(); 
	if(draftOver == true)
	{
		string = "* End of Draft *";	
		m_selection.AddString(string);
	}
	else if(roundOver == true)
	{
		string.Format("* End of Round %d *",m_currentRound-1);	
		m_selection.AddString(string);
	}

	int co = m_selection.GetCount();
	if(co>=1) m_selection.SetCurSel(co-1);

//	delete pick;
	if(m_control[m_currentTeam-1] == "Player" && m_currentRound < 15)
	{
		CString message;
		int original = m_originalDraftOrder[m_currentTeam-1];
		AfxFormatString1( message, IDS_STRING_MESSAGE_DRAFT, m_leagueTeamNames[original]); 
		AfxMessageBox(message, MB_OK);	
		m_gm = true;
	}

	m_buttonDraft.SetWindowText("Continue Draft");
	m_buttonDraft.EnableWindow(TRUE);
	}
	if(m_currentRound == 15) draftOver = true;
	if(draftOver == true) m_buttonDraft.EnableWindow(FALSE);
	m_listAll.SetCurSel(0);
	UpdateData(FALSE);
}

void CDraftDlg::OnDblclkListPg() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(1);

}


void CDraftDlg::OnDblclkListSg() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(2);


	
}

void CDraftDlg::OnDblclkListC() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(5);
	

}

void CDraftDlg::OnDblclkListSf() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(3);

	
}

void CDraftDlg::OnDblclkListPf() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(4);

}

void CDraftDlg::OnDblclkListAll() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(0);
}

void CDraftDlg::SelectPlayer(CString string, bool roundOver, bool draftOver)
{
if(draftOver == false)
{
		m_draftStarted = true;
		int pick = 0;
		int choose = 0;
		for(int j=2401; j<=2400+players[0]; j++)
		{
			if(Rating[j].GetName() != "" && 
			Rating[j].GetName() == string &&
			choose == 0) choose = j;
		}

		if(pick == 0 && Chosen[choose] == false)
		{
			pick = choose;
			Chosen[choose] = true;
		}			

		bool m_alternate = false;
		int evenI = m_currentRound/2;
		double evenD = double(m_currentRound)/2;
		if(evenI == evenD && m_checkReverse == TRUE) m_alternate = true;
				
		PlayerSlot[m_currentTeam][m_currentRound] = pick;
		
		CString round;
		int turn = m_currentTeam;
		if(m_alternate == true) turn = m_teamsInLeague + 1 - turn;
		round.Format("Round %d Pick %d",m_currentRound, turn);
		
		m_selection.AddString(round);
		CString name = Rating[pick].GetName();
		CString po = Rating[pick].GetPos();
		int pos = 0;
		if(po=="PG") pos = 1;
		else if(po=="SG") pos = 2;
		else if(po=="SF") pos = 3;
		else if(po=="PF") pos = 4;
		else if(po==" C") pos = 5;
		int original = m_originalDraftOrder[m_currentTeam-1];
		CString teamName = m_leagueTeamNames[original];
		CString str = teamName + " select " + name;
		m_selection.AddString(str);
		int m_tempTeam = m_currentTeam;//save position for displaying roster after selection
		
		if(m_alternate == false) 
			m_currentTeam = m_currentTeam + 1;
		else
			m_currentTeam = m_currentTeam - 1;
		
		bool all = false;
		int i = 1;
		int player = m_listAll.GetCount();
		do
		{
			CString string;
			m_listAll.GetText(i-1, string);
			if(name == string)
			{
				m_listAll.DeleteString(i-1);
				all = true;
			}
			i = i+1;
		}
		while(i<=player && all == false);
		bool position = false;
		i = 1;
		if(pos == 1) 
			player = m_listPg.GetCount();
		else if(pos == 2) 
			player = m_listSg.GetCount();
		else if(pos == 3) 
			player = m_listSf.GetCount();
		else if(pos == 4) 
			player = m_listPf.GetCount();
		else if(pos == 5) 
			player = m_listC.GetCount();
		do
		{
			CString string;
			if(pos == 1)
				m_listPg.GetText(i-1, string);
			else if(pos == 2)
				m_listSg.GetText(i-1, string);
			else if(pos == 3)
				m_listSf.GetText(i-1, string);
			else if(pos == 4)
				m_listPf.GetText(i-1, string);
			else if(pos == 5)
				m_listC.GetText(i-1, string);
			if(name == string)
			{
				if(pos == 1)
					m_listPg.DeleteString(i-1);
				else if(pos == 2)
					m_listSg.DeleteString(i-1);
				else if(pos == 3)
					m_listSf.DeleteString(i-1);
				else if(pos == 4)
					m_listPf.DeleteString(i-1);
				else if(pos == 5)
					m_listC.DeleteString(i-1);
				position = true;
			}
			i = i+1;
			}
			while(i<=player && position == false);

			if(m_currentTeam > m_teamsInLeague || m_currentTeam < 1)
			{
				m_currentRound = m_currentRound + 1;
				roundOver = true;
				if(m_checkReverse == FALSE && m_alternate == false)
					m_currentTeam = 1;
				else if(m_checkReverse == TRUE && m_alternate == false)
				{
					m_currentTeam = m_teamsInLeague;
					m_alternate = true;
				}
				else if(m_checkReverse == TRUE && m_alternate == true)
				{
					m_currentTeam = 1;
					m_alternate = false;
				}

				if(m_currentRound > 15) draftOver = true;
			}


		m_listOrder.SetCurSel(m_tempTeam-1);
		OnSelchangeListOrder(); 
}
		if(draftOver == true)
		{
			string = "* End of Draft *";	
			m_selection.AddString(string);
		}
		else if(roundOver == true)
		{
			string.Format("* End of Round %d *",m_currentRound-1);	
			m_selection.AddString(string);
		}
		int co = m_selection.GetCount();
		if(co>=1) m_selection.SetCurSel(co-1);
		m_listAll.SetCurSel(0);
		UpdateData(FALSE);
}

bool CDraftDlg::SortPlayers()
{
	CString string;	
	if(m_currentTeam == 1)
	{
		string.Format("* Start Round %d *",m_currentRound);
		m_selection.AddString(string);
	}


	
	bool allChosen = true;
	for(int p=2401; p<=2400+players[0]; p++)		
	{
		if(Rating[p].GetName() != "" && Chosen[p]  == false) allChosen = false;
	}	
		
	return allChosen;

}

void CDraftDlg::OnOK() 
{
	// TODO: Add extra validation here
int result = AfxMessageBox("Are you sure you want to save the player draft?",
						   MB_YESNO);


if(m_currentRound > 10 && result == IDYES)
{



CreateFreeAgentList();
for(int team=0; team< 32; team++)
{
	int index = 0;
	bool found = false;
	if(team < m_teamsInLeague)
	{
		index = m_originalDraftOrder[team];
		found = true;
	}

	for(int i = 1; i <= 15; i++)
	{
		int player = 0;
		int slot = 0;
		if(found == true)
		{
			player = PlayerSlot[team+1][i];
			slot = index*15+i;
		}

		CPlayer m_player;
		if(team < m_teamsInLeague) 
			Player[slot] = Rating[player];
		else 
			Player[slot] = m_player;

		if(i <= 15) Player[slot].SetActive(TRUE);
	}	
}

int start = m_teamsInLeague*15+1;//erase remaining players
if(start <= 466)
{
	for(int i=start; i<=480; i++)
	{
		CPlayer m_player;
		Player[i] = m_player;
	}
}

	int id_count = 0;

	for(int  i = 1; i <= 576; i++ )
	{
		int t = (i-1) / 15 + 1;
		if(i <= 480)
		{
			if(Player[i].GetName() != "")
			{
				id_count = id_count + 1;
				Player[i].SetID(id_count);
				Player[i].m_salary_id = id_count;				
				Player[i].m_team_paying = t;
			}
		}
		else if(FA[i-480].GetName() != "")
		{
			id_count = id_count + 1;
            FA[i-480].SetID(id_count);
            FA[i-480].m_salary_id = id_count;
			FA[i-480].m_team_paying = 0;
		}

	}


				for(int x=1; x<=480; x++)
				{
					avg.m_actual[x] = Player[x];
				}

				for(int x=1; x<=96; x++)
				{
					avg.m_actual[480+x] = FA[x];
				}

				for(int x=577; x<=1600; x++)
				{
					CPlayer m_player;
					avg.m_actual[x] = m_player;
				}
			

				avg.ConvertDataNewFormat();

			
			
		

CDialog::OnOK();

}
else if(m_currentRound < 10) AfxMessageBox("At least ten rounds must be completed before saving the league.",
						   MB_OK);





}

void CDraftDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	int result = AfxMessageBox("Any draft choices made will be lost.\n Are you sure you want to cancel?",
						   MB_YESNO);
	if(result == IDYES)
		CDialog::OnCancel();	
}

void CDraftDlg::OnDblclkListOrder() 
{
	// TODO: Add your control notification handler code here
	if(m_draftStarted == false)
	{
	if(m_orderClicked == false)
	{
		m_swap1 = m_listOrder.GetCurSel();
		m_orderClicked = true;
	}
	else
	{

		m_swap2 = m_listOrder.GetCurSel();
		m_orderClicked = false;
		int temp = m_originalDraftOrder[m_swap2]; 
		m_originalDraftOrder[m_swap2] = m_originalDraftOrder[m_swap1]; 
		m_originalDraftOrder[m_swap1] = temp; 
		CString tmp = m_control[m_swap2]; 
		m_control[m_swap2] = m_control[m_swap1]; 
		m_control[m_swap1] = tmp; 
	    OnSelchangeListOrder();
		CString team1;
		m_listOrder.GetText(m_swap1, team1);
		CString team2;
		m_listOrder.GetText(m_swap2, team2);
		m_listOrder.DeleteString(m_swap1);
		m_listOrder.InsertString(m_swap1, team2);
		m_listOrder.DeleteString(m_swap2);
		m_listOrder.InsertString(m_swap2, team1);
	}
	}
}

BOOL CDraftDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default

//	HtmlHelp(NULL, "jumpshot.chm::/html/fantasydraft.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);


//  	WinHelp(HID_LEAGUE_DRAFT);	
//	return TRUE;
}

void CDraftDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
  	//WinHelp(HID_LEAGUE_DRAFT);		

//	HtmlHelp(NULL, "jumpshot.chm::/html/fantasydraft.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}



void CDraftDlg::OnButtonRatings() 
{
	// TODO: Add your control notification handler code here
//if(m_gm == true)
CString string;
int p = m_listAll.GetCurSel();
if(p >= 0)
{
	m_listAll.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
		
	}	
}


}


HBRUSH CDraftDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
     //case CTLCOLOR_LISTBOX:
       //   pDC->SetBkColor(LISTBOXCOLOR);
         // pDC->SetTextColor(LISTBOXTEXTCOLOR);
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
//	return hbr;
}

void CDraftDlg::OnDblclkListRoster() 
{
	// TODO: Add your control notification handler code here
	ShowPlayerCard(6);

}

void CDraftDlg::OnButtonC() 
{
	// TODO: Add your control notification handler code here

//if(m_gm == true)
CString string;
int p = m_listC.GetCurSel();
if(p >= 0)
{
	m_listC.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
	}	
}


}

void CDraftDlg::OnButtonPf() 
{
	// TODO: Add your control notification handler code here
//if(m_gm == true)
CString string;
int p = m_listPf.GetCurSel();
if(p >= 0)
{
	m_listPf.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
	}	
}

}

void CDraftDlg::OnButtonPg() 
{
	// TODO: Add your control notification handler code here
//if(m_gm == true)
CString string;
int p = m_listPg.GetCurSel();
if(p >= 0)
{
	m_listPg.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
	}	
}

	
}

void CDraftDlg::OnButtonSf() 
{
	// TODO: Add your control notification handler code here
//if(m_gm == true)
CString string;
int p = m_listSf.GetCurSel();
if(p >= 0)
{
	m_listSf.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
	}	
}



}

void CDraftDlg::OnButtonSg() 
{
	// TODO: Add your control notification handler code here
CString string;
int p = m_listSg.GetCurSel();
if(p >= 0)
{
	m_listSg.GetText(p, string);
	bool confirmed = GetConfirmation(string);
	if(m_gm == true && confirmed == true)
	{
		bool roundOver = false;
		bool draftOver = false;
		m_gm = false;
		bool allChosen = SortPlayers();
		if(allChosen == true) draftOver = true;
		SelectPlayer(string, roundOver, draftOver);
//		CheckButtons();
	}	
}


}


bool CDraftDlg::GetConfirmation(CString string)
{
	UpdateData(TRUE);
	int result = 0;
	bool confirm = true;
	if(m_checkConfirmed == TRUE && m_control[m_currentTeam-1] == "Player")
	{

		CString message;
	    int original = m_originalDraftOrder[m_currentTeam-1];
	    AfxFormatString2( message, IDS_STRING_MESSAGE_CONFIRM_PICK, m_leagueTeamNames[original], string); 
		result = AfxMessageBox(message, MB_OKCANCEL);	
		if(result == IDOK)
			confirm = true;
		else
			confirm = false;
	}
	return confirm;
}


void CDraftDlg::OnButtonRandom() 
{
	// TODO: Add your control notification handler code here
	CString m_copy_control[33];
	//CDisplay* rnd;
	//rnd = new CDisplay;
	bool used[35];
	for(int i=0; i<=34; i++)
	{
		used[i] = false;
	}

	for(int i=0; i<m_teamsInLeague; i++)
	{
		int j=0;
		do
		{
			j = Rating[0].IntRandom(m_teamsInLeague) - 1; 
        }
		while(used[j] == true);
		m_copy_control[i] = m_control[j];
		used[j] = true;
		
		m_originalDraftOrder[i] = j;
	}
//	delete rnd;
	for(int i=0; i<=32; i++)
	{
		m_control[i] = m_copy_control[i];
	}

	m_buttonRandom.EnableWindow(FALSE);

	ListTeams();	
}

void CDraftDlg::ListTeams()
{
	m_listOrder.ResetContent();
	for(int  i=0; i<m_teamsInLeague; i++)
		{
			int original = m_originalDraftOrder[i];
			if(m_leagueTeamNames[original] != "")
			{
				m_listOrder.AddString(m_leagueTeamNames[original]);
				m_listControl.ResetContent();
				m_listControl.AddString(m_control[original]);
			}
		}
}

void CDraftDlg::CreateFreeAgentList()
{
	int count = 1;

	for(int j=2401; j<=2400+players[0]; j++)
	{
		if(Chosen[j] != true && count <= 96)
		{
			FA[count] = Rating[j];
			FA[count].m_previous_team = -1;
			count = count + 1;
		}
	}
}

void CDraftDlg::ShowPlayerCard(int pos)
{

	int off = 2400;
	if(pos >= 1 && pos <= 5) off = (pos-1)*480;

	CPlayerCardDlg *scout = new CPlayerCardDlg;
	CString string;
	scout->avg = avg;
	scout->m_default_scout = m_currentTeam - 1;

	if(m_currentTeam >= 0)
		avg.m_settings.m_scouts[m_currentTeam-1] = 1;//lead scout set

	int ind  = 0;
	if(pos == 0)
		ind = m_listAll.GetCurSel() + 1;
	else if(pos == 1)
		ind = m_listPg.GetCurSel() + 1;
	else if(pos == 2)
		ind = m_listSg.GetCurSel() + 1;
	else if(pos == 3)
		ind = m_listSf.GetCurSel() + 1;
	else if(pos == 4)
		ind = m_listPf.GetCurSel() + 1;
	else if(pos == 5)
		ind = m_listC.GetCurSel() + 1;
	else if(pos == 6)
		ind = m_listRoster.GetCurSel() + 1;

	scout->m_player_index = ind;


	int player = 0;
	int count = 0;
	if(pos == 0)
		count = m_listAll.GetCount();
	else if(pos == 1)
		count = m_listPg.GetCount();
	else if(pos == 2)
		count = m_listSg.GetCount();
	else if(pos == 3)
		count = m_listSf.GetCount();
	else if(pos == 4)
		count = m_listPf.GetCount();
	else if(pos == 5)
		count = m_listC.GetCount();
	else if(pos == 6)
		count = m_listRoster.GetCount();

	int pl = 0;


	for(int i=1; i<=count; i++)
	{
		if(pos == 0)
			m_listAll.GetText(i-1, string);
		else if(pos == 1)
			m_listPg.GetText(i-1, string);
		else if(pos == 2)
			m_listSg.GetText(i-1, string);
		else if(pos == 3)
			m_listSf.GetText(i-1, string);
		else if(pos == 4)
			m_listPf.GetText(i-1, string);
		else if(pos == 5)
			m_listC.GetText(i-1, string);
		else if(pos == 6)
			m_listRoster.GetText(i-1, string);
			
		string.TrimRight();
		string.TrimLeft();
			

		for(int j=1; j<=480; j++)
		{
			CString str = Rating[off + j].GetName();
			if(pos == 6) str = Rating[off + j].GetPos() + " " + str;

			if(str == string && string != "")
			{
				pl = pl + 1;
				scout->avg.m_actual[pl] = Rating[off + j];
			}
		}	
	}


	CPlayer m_player = scout->avg.m_actual[ind];
	//CString string = m_player.GetPos() + " " + m_player.GetName();
	scout->m_title = "Scout";
	scout->m_pl_index_start = 1;
	scout->m_pl_index_end = pl;
	scout->DoModal();
	delete scout;


}


void CDraftDlg::OnLbnSelchangeListRoster()
{
	// TODO: Add your control notification handler code here
}
