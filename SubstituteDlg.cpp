// SubstituteDlg.cpp : implementation file
//

#include "stdafx.h"
//#include "BBall.h"
#include "constants.h"
#include "resource.h"

#include "SubstituteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubstituteDlg dialog


CSubstituteDlg::CSubstituteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubstituteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubstituteDlg)
	m_teamName = _T("");
	m_autoSubHome = FALSE;
	m_autoSubVisitor = FALSE;
	m_displayString = _T("");
	//}}AFX_DATA_INIT
//	PlayerArray.SetSize(31);
	m_currentTeam = VISITOR;
	m_slot = 1;
}


void CSubstituteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubstituteDlg)
	DDX_Control(pDX, IDC_BUTTON_HOME, m_buttonHome);
	DDX_Control(pDX, IDC_BUTTON_VISITOR, m_buttonVisitor);
	DDX_Control(pDX, IDC_LIST_CTRL_GAME, m_listCtrlGame);
	DDX_Control(pDX, IDC_LIST_CTRL, m_listCtrl);
	DDX_Control(pDX, IDC_LIST_CTRL_SHOT, m_listCtrlShot);
	DDX_Control(pDX, IDC_LIST_CTRL_STATS, m_listCtrlStats);
	DDX_Control(pDX, IDC_LIST_ROSTER, m_listRoster);
	DDX_Control(pDX, IDC_LIST_LINEUP, m_listLineup);
	DDX_Text(pDX, IDC_EDIT_TEAM_NAME, m_teamName);
	DDV_MaxChars(pDX, m_teamName, 32);
	DDX_Check(pDX, IDC_CHECK_AUTO_HOME, m_autoSubHome);
	DDX_Check(pDX, IDC_CHECK_AUTO_VISITOR, m_autoSubVisitor);
	DDX_Text(pDX, IDC_EDIT_STRING, m_displayString);
	DDV_MaxChars(pDX, m_displayString, 768);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubstituteDlg, CDialog)
	//{{AFX_MSG_MAP(CSubstituteDlg)
	ON_BN_CLICKED(IDC_BUTTON_VISITOR, OnButtonVisitor)
	ON_BN_CLICKED(IDC_BUTTON_HOME, OnButtonHome)
	ON_LBN_DBLCLK(IDC_LIST_ROSTER, OnDblclkListRoster)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_LBN_SELCHANGE(IDC_LIST_ROSTER, OnSelchangeListRoster)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubstituteDlg message handlers

void CSubstituteDlg::OnButtonVisitor() 
{
	// TODO: Add your control notification handler code here
	m_currentTeam = VISITOR;
	m_teamName = m_visitor;
	UpdateData(FALSE);
	CPlayer m_player;
	CPlayerStats m_playerStats;
	int player;
	int i;
	m_listLineup.ResetContent();
	m_listRoster.ResetContent();
	for( i=1; i<=12; i++)
	{
			m_player = PlayerArray[i];
			m_playerStats = PlayerStats[i];
			
			CString name = m_player.GetName();
			name = m_player.GetPos() +	" " + m_player.GetName();

			if(m_playerStats.GetStamina() < 0) name = name + " t";
			else if(m_playerStats.GetPf() >= 6) name = name + " *";
			else if(m_playerStats.GetInjury() >= 1) name = name + " i";
			
			if(m_player.GetName() != "") m_listRoster.AddString(name);
	}	
		

 	CString PositionNames[6] = {"", "PG ", "SG ", "SF ", "PF ", " C "};
	for( i=1; i<6; i++)
		{
			
			player = Lineup[1][i];
			CPlayerStats m_playerStats = PlayerStats[player];
			CPlayer m_player = PlayerArray[player];

			CString name = PositionNames[i] + m_player.GetName();
			
			if(m_playerStats.GetStamina() < 0) name = name + " t";

			m_listLineup.AddString(name);

		}

		
//		int index = SetCur();
		m_listLineup.SetCurSel(m_index); 		
		m_listRoster.SetCurSel(m_roster_index);

		OnSelchangeListRoster();

}

BOOL CSubstituteDlg::OnInitDialog() 
{
	CDialog::OnInitDialog(); //
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(LISTBOXCOLOR); 
//	m_listRoster.SetCurSel(0); 		
	if(m_toOk == false) m_listLineup.EnableWindow(FALSE);

	m_buttonHome.SetWindowText(m_home);
	m_buttonVisitor.SetWindowText(m_visitor);

    m_listCtrlGame.InsertColumn(0,"pts");    
    m_listCtrlGame.InsertColumn(1,"reb");
    m_listCtrlGame.InsertColumn(2,"ast");
    m_listCtrlGame.InsertColumn(3,"pf");
    m_listCtrlGame.InsertColumn(4,"stamina");
    m_listCtrlGame.SetColumnWidth( 0, 40);
    m_listCtrlGame.SetColumnWidth( 1, 40);
    m_listCtrlGame.SetColumnWidth( 2, 40);
    m_listCtrlGame.SetColumnWidth( 3, 40);
    m_listCtrlGame.SetColumnWidth( 4, 60);


    m_listCtrlStats.InsertColumn(0,"Pos");    
    m_listCtrlStats.InsertColumn(1,"Player");
    m_listCtrlStats.InsertColumn(2,"Offense");
    m_listCtrlStats.InsertColumn(3,"O");
    m_listCtrlStats.InsertColumn(4,"D");
    m_listCtrlStats.InsertColumn(5,"P");
    m_listCtrlStats.InsertColumn(6,"T");
    m_listCtrlStats.InsertColumn(7,"Defense");
    m_listCtrlStats.InsertColumn(8,"O");
    m_listCtrlStats.InsertColumn(9,"D");
    m_listCtrlStats.InsertColumn(10,"P");
    m_listCtrlStats.InsertColumn(11,"T");
  
	
    m_listCtrlStats.SetColumnWidth( 0, 32);
    m_listCtrlStats.SetColumnWidth( 1, 64);
    m_listCtrlStats.SetColumnWidth( 2, 64);
    m_listCtrlStats.SetColumnWidth( 3, 20);
    m_listCtrlStats.SetColumnWidth( 4, 20);
    m_listCtrlStats.SetColumnWidth( 5, 20);
    m_listCtrlStats.SetColumnWidth( 6, 20);
    m_listCtrlStats.SetColumnWidth( 7, 64);
    m_listCtrlStats.SetColumnWidth( 8, 20);
    m_listCtrlStats.SetColumnWidth( 9, 20);
    m_listCtrlStats.SetColumnWidth( 10, 20);
    m_listCtrlStats.SetColumnWidth( 11, 20);

    m_listCtrlStats.SetBkColor(RGB(253,236,170));
    m_listCtrlStats.SetTextBkColor(RGB(253,236,170));
    m_listCtrlStats.SetTextColor(RGB(0,0,0));
	
	m_listCtrlShot.InsertColumn(0,"2ga");    
    m_listCtrlShot.InsertColumn(1,"2g%");
    m_listCtrlShot.InsertColumn(2,"fta");
    m_listCtrlShot.InsertColumn(3,"ft%");
    m_listCtrlShot.InsertColumn(4,"3ga");
    m_listCtrlShot.InsertColumn(5,"3g%");
    m_listCtrl.InsertColumn(0,"oreb");
    m_listCtrl.InsertColumn(1,"dreb");
    m_listCtrl.InsertColumn(2,"ast");
    m_listCtrl.InsertColumn(3,"stl");
    m_listCtrl.InsertColumn(4,"to");
    m_listCtrl.InsertColumn(5,"blk");
  
	
    m_listCtrlShot.SetColumnWidth( 0, 40);
    m_listCtrlShot.SetColumnWidth( 1, 40);
    m_listCtrlShot.SetColumnWidth( 2, 40);
    m_listCtrlShot.SetColumnWidth( 3, 40);
    m_listCtrlShot.SetColumnWidth( 4, 40);
    m_listCtrlShot.SetColumnWidth( 5, 40);
    m_listCtrl.SetColumnWidth( 0, 40);
    m_listCtrl.SetColumnWidth( 1, 40);
    m_listCtrl.SetColumnWidth( 2, 40);
    m_listCtrl.SetColumnWidth( 3, 40);
    m_listCtrl.SetColumnWidth( 4, 40);
    m_listCtrl.SetColumnWidth( 5, 40);

	
    m_listCtrl.SetBkColor(RGB(253,236,170));
    m_listCtrl.SetTextBkColor(RGB(253,236,170));
    m_listCtrl.SetTextColor(RGB(0,0,0));
    m_listCtrlShot.SetBkColor(RGB(253,236,170));
    m_listCtrlShot.SetTextBkColor(RGB(253,236,170));
    m_listCtrlShot.SetTextColor(RGB(0,0,0));
    m_listCtrlGame.SetTextBkColor(RGB(253,236,170));
    m_listCtrlGame.SetBkColor(RGB(253,236,170));
	int len = m_displayString.GetLength();

	for(int length = 1; length < len; length++)
	{
		CString temp = m_displayString.GetAt(length);
		if((temp == "." || temp == "!") && (length < len-1) ) m_displayString.SetAt(length+1, ' ');
	}

	if(m_possesion == HOME) 
		OnButtonHome();
	else
		OnButtonVisitor();

	
	m_listLineup.SetCurSel(m_index); 		
	m_listRoster.SetCurSel(m_roster_index);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubstituteDlg::OnButtonHome() 
{
	// TODO: Add your control notification handler code here
	m_currentTeam = HOME;
	m_teamName = m_home;
	UpdateData(FALSE);
	CPlayer m_player;
	CPlayerStats m_playerStats;
	int player = 0;
	m_listLineup.ResetContent();
	m_listRoster.ResetContent();
		for( int i=1; i<=12; i++)
		{
			m_player = PlayerArray[i+15];
			m_playerStats = PlayerStats[i+15];
			
			CString name = m_player.GetPos() +	" " + m_player.GetName();

			if(m_playerStats.GetStamina() < 0) name = name + " t";
			else if(m_playerStats.GetPf() >= 6) name = name + " *";
			else if(m_playerStats.GetInjury() >= 1) name = name + " i";
			
			if(m_player.GetName() != "") m_listRoster.AddString(name);

		}


 	CString PositionNames[6] = {"", "PG ", "SG ", "SF ", "PF ", " C "};
	for( i=1; i<6; i++)
		{

			player = Lineup[2][i];
			CPlayerStats m_playerStats = PlayerStats[player];
			CPlayer m_player = PlayerArray[player];
			
			CString name = m_player.GetName();

			name = PositionNames[i] + m_player.GetName();
			
			if(m_playerStats.GetStamina() < 0) name = name + " t";

			m_listLineup.AddString(name);
		}
		
//		OnSelchangeListRoster();
		//int index = SetCur();
		m_listLineup.SetCurSel(m_index); 		
		m_listRoster.SetCurSel(m_roster_index);

		OnSelchangeListRoster();

}


void CSubstituteDlg::OnDblclkListRoster() 
{
	// TODO: Add your control notification handler code here
	CString PositionNames[6] = {"", "PG ", "SG ", "SF ", "PF ", " C "};
	CString player;
	BOOL NoSub = FALSE;
	int lineupIndex = m_listLineup.GetCurSel();
	int rosterIndex = m_listRoster.GetCurSel();
	
	CPlayerStats m_player;
	if(m_currentTeam == VISITOR) 
		m_player = PlayerStats[rosterIndex + 1];
	else 
		m_player = PlayerStats[rosterIndex + 16];
	if(m_player.GetPf() >= 6 || m_player.GetInjury() > 0) NoSub = TRUE;

	for(int i=1; i<=5; i++) //check for duplicate
	{
		if(m_currentTeam == VISITOR && Lineup[VISITOR][i] == rosterIndex + 1) NoSub = TRUE;
		if(m_currentTeam == HOME && Lineup[HOME][i] == rosterIndex + 16) NoSub = TRUE;

	}
	if(lineupIndex >= 0 && rosterIndex >= 0 && NoSub == FALSE)
	{
		m_listRoster.GetText(rosterIndex, player);
		m_listLineup.DeleteString(lineupIndex);
		int length = player.GetLength() - 3;
		player = player.Right(length);
		player = PositionNames[lineupIndex + 1] + player;
		m_listLineup.InsertString(lineupIndex, player);
		if(m_currentTeam == VISITOR)
			Lineup[VISITOR][lineupIndex + 1] = rosterIndex + 1;
		else
			Lineup[HOME][lineupIndex + 1] = rosterIndex + 16;
		m_listLineup.SetCurSel(lineupIndex);
	}
	
}

void CSubstituteDlg::OnOK() 
{
	// TODO: Add extra validation here
	BOOL NoSub = FALSE;
	int lineupIndex = m_listLineup.GetCurSel();
	
	CPlayerStats m_player;

	for(int t=1; t<=2; t++) //check for duplicate
	{
	for(int i=1; i<=5; i++) 
	{
		m_player = PlayerStats[Lineup[t][i]];
		if(m_player.GetPf() >= 6 || m_player.GetInjury() > 0) NoSub = TRUE;
	}	
	}
	if(NoSub == FALSE) 
		CDialog::OnOK();
	else
		MessageBox("Disqualified player in the lineup.");
}


BOOL CSubstituteDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	WinHelp(HID_PLAYERS_SUBSTITUTE);	
	return TRUE;
}

void CSubstituteDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	WinHelp(HID_PLAYERS_SUBSTITUTE);		
}

void CSubstituteDlg::OnSelchangeListRoster() 
{
	// TODO: Add your control notification handler code here
	m_listCtrlStats.DeleteAllItems();
	m_listCtrlShot.DeleteAllItems();
	m_listCtrl.DeleteAllItems();
	m_listCtrlGame.DeleteAllItems();
	m_slot = m_listRoster.GetCurSel()+1;
//	int index = SetCur();
//	m_listLineup.SetCurSel(index); 		
//	m_listRoster.SetCurSel(m_roster_index);
	DisplayStats();
}

void CSubstituteDlg::DisplayStats()
{
	int player = m_slot;
	int team = m_visitorIndex;
	if(m_currentTeam == HOME){ player = player + 15; team = m_homeIndex; }
	CString pos = PlayerArray[player].GetPos();
	CString name = PlayerArray[player].GetLastName();
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD;
	int o = PlayerArray[player].GetMovOff();
	OutO.Format("%d", o);
	int p = PlayerArray[player].GetPenOff();
	PenO.Format("%d", p);
	int i = PlayerArray[player].GetPostOff();
	PostO.Format("%d", i);
	int f = PlayerArray[player].GetTransOff();
	TransO.Format("%d", f);
	int od = PlayerArray[player].GetMovDef();
	OutD.Format("%d", od);
	int pd = PlayerArray[player].GetPenDef();
	PenD.Format("%d", pd);
	int id = PlayerArray[player].GetPostDef();
	PostD.Format("%d", id);
	int fd = PlayerArray[player].GetTransDef();
	TransD.Format("%d", fd);

	CString points, rebounds, assists, fouls, stamina;
	int pts = PlayerStats[player].GetFgm()*2 + PlayerStats[player].GetTfgm()*3 + PlayerStats[player].GetFtm();
	points.Format("%d", pts);
	int reb = PlayerStats[player].GetOreb() + PlayerStats[player].GetDreb();
	rebounds.Format("%d", reb);
	int ast = PlayerStats[player].GetAst();
	assists.Format("%d", ast);
	int pf = PlayerStats[player].GetPf();
	fouls.Format("%d", pf);
	int fat = PlayerStats[player].GetStamina();
	fat = (1000 + fat)/10;
	if(fat > 100) fat = 100;
	stamina.Format("%d",fat);
	
	m_listCtrlGame.InsertItem(0,points);
	m_listCtrlGame.SetItemText(0,1,rebounds);
	m_listCtrlGame.SetItemText(0,2,assists);
	m_listCtrlGame.SetItemText(0,3,fouls);
	m_listCtrlGame.SetItemText(0,4,stamina);
	
	m_listCtrlStats.InsertItem(0,pos);
	m_listCtrlStats.SetItemText(0,1,name);
	m_listCtrlStats.SetItemText(0,3,OutO);
	m_listCtrlStats.SetItemText(0,4,PenO);
	m_listCtrlStats.SetItemText(0,5,PostO);
	m_listCtrlStats.SetItemText(0,6,TransO);
	m_listCtrlStats.SetItemText(0,8,OutD);
	m_listCtrlStats.SetItemText(0,9,PenD);
	m_listCtrlStats.SetItemText(0,10,PostD);
	m_listCtrlStats.SetItemText(0,11,TransD);
	
    CPlayer m_player = PlayerArray[player];
	double g = double(PlayerArray[player].GetMin());
	double pen =
		1 + ((g / double(PlayerArray[player].GetGames()) - 24) / 2 / 48);
	
	if(pen > 1) pen = 1;
	double tmp = ((double(PlayerArray[player].GetFga()) - double(PlayerArray[player].GetTfga()))/g)*480;
	tmp = tmp * pen / double(hiFga)*100;
	int r = int(tmp);
    int rating = PlayerArray[player].PrRating(false, r, m_scout[team].m_scoring);
	CString s;
	s.Format("%d", rating);
	m_listCtrlShot.InsertItem(0,s);

	tmp = (double(PlayerArray[player].GetFgm()) - double(PlayerArray[player].GetTfgm()))/
		(double(PlayerArray[player].GetFga()) - double(PlayerArray[player].GetTfga())) * 100;
	r = int(tmp);

	double diff = tmp - int(tmp);
	if(diff > .5) r = int(tmp + 1);
    rating = m_player.PrRating(true, r, m_scout[team].m_shooting);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,1,s);


	
	tmp = double(PlayerArray[player].GetFta())/g*480;
	tmp = tmp * pen / double(hiFta)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_scoring);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,2,s);

	tmp = double(PlayerArray[player].GetFtm())/double(PlayerArray[player].GetFta())*100;
	r = int(tmp);
	diff = tmp - int(tmp);
	if(diff > .5) r = int(tmp + 1);
    rating = m_player.PrRating(true, r, m_scout[team].m_shooting);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,3,s);


	tmp = double(PlayerArray[player].GetTfga())/g*480;
	tmp = tmp * pen / double(hiTfga)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_scoring);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,4,s);

	tmp = double(PlayerArray[player].GetTfgm())/double(PlayerArray[player].GetTfga())*100;
	r = int(tmp);
	diff = tmp - int(tmp);
	if(diff > .5) r = int(tmp + 1);
    rating = m_player.PrRating(true, r, m_scout[team].m_shooting);

	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,5,s);

	tmp = double(PlayerArray[player].GetOreb())/g*480;
	tmp = tmp * pen / double(hiOreb)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_rebounding);
	s.Format("%d", rating);
	m_listCtrl.InsertItem(0,s);

	tmp = ((double(PlayerArray[player].GetReb()) - double(PlayerArray[player].GetOreb()))/g)*480;
	tmp = tmp * pen / double(hiDreb)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_rebounding);
	s.Format("%d", rating);
	m_listCtrl.SetItemText(0,1,s);

	tmp = double(PlayerArray[player].GetAst())/g*480;
	tmp = tmp * pen / double(hiAst)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_passing);
	s.Format("%d", rating);
	m_listCtrl.SetItemText(0,2,s);

	tmp = double(PlayerArray[player].GetStl())/g*480;
	tmp = tmp * pen / double(hiStl)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_defense);
	s.Format("%d", rating);
	m_listCtrl.SetItemText(0,3,s);

	tmp = double(PlayerArray[player].GetTo())/g*480;
	tmp = tmp * pen / double(hiTo)*100;
	r = 100 - int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_passing);
	s.Format("%d", rating);
	m_listCtrl.SetItemText(0,4,s);

	tmp = double(PlayerArray[player].GetBlk())/g*480;
	tmp = tmp * pen / double(hiBlk)*100;
	r = int(tmp);
    rating = m_player.PrRating(false, r, m_scout[team].m_defense);
	s.Format("%d", rating);
	m_listCtrl.SetItemText(0,5,s);
}

int CSubstituteDlg::SetCur()
{
	int p = m_index;
	return p;
}

HBRUSH CSubstituteDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
		pDC->SetTextColor(RGB(0,0,0));
	if (nCtlColor == CTLCOLOR_LISTBOX)
	{
	pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(RGB(255,255,226));	
	// TODO: Return a different brush if the default is not desired
	return HBRUSH(myBrush);
	}
	return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 
}
