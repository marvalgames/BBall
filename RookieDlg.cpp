// RookieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "RookieDlg.h"
#include "TradeDlg.h"
#include "RookieCardDlg.h"
//#ifndef Display_h
//#include "Display.h"
//#define Display_h
//#endif 

#include "RegisterDlg.h"

#include "BBallFile.h"
//#include "Display.h"
//#include "PropSheet.h"
#include "EditDlg.h"
#include "PlayerCardDlg.h"
#include "HtmlMsc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRookieDlg dialog


CRookieDlg::CRookieDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRookieDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRookieDlg)
	//}}AFX_DATA_INIT
	m_orig_standings = new CRecord[33];
	Rookies = new CPlayer[97];
//	Player = new CPlayer[1601];
	New = new CPlayer[1601];
//	FA = new CPlayer[481];
	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
                    MAKEINTRESOURCE(IDB_BITMAP_BK)));

	for(int i=0; i<=32; i++)
	{
		m_orig_win[i] = 0;
		m_orig_loss[i] = 0;
	}

	m_draftOver = false;
}


void CRookieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRookieDlg)
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button[0]);
	DDX_Control(pDX, IDC_BUTTON_HTML, m_button[1]);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_button_next);
	DDX_Control(pDX, IDC_BUTTON_TRADE, m_button_trade);
	DDX_Control(pDX, IDC_BUTTON_EDIT, m_button_edit);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDC_COMBO_LIST_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_BUTTON_REPORT, m_button_report);
	DDX_Control(pDX, IDC_BUTTON_LOTTERY, m_button_lottery);
	DDX_Control(pDX, IDC_LIST_DRAFT_ORDER, m_list_draft_order);
	DDX_Control(pDX, IDC_BUTTON_RANDOM, m_buttonRandom);
	DDX_Control(pDX, IDOK, m_saveDraft);
	DDX_Control(pDX, IDC_LIST_DISPLAYDRAFT, m_listDisplayDraft);
	DDX_Control(pDX, IDC_LIST_ROSTERS, m_listRosters);
	DDX_Control(pDX, IDC_LIST_PLAYERS, m_listPlayers);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listControl);
	DDX_Control(pDX, IDC_BUTTON_DRAFT, m_buttonDraft);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRookieDlg, CDialog)
	//{{AFX_MSG_MAP(CRookieDlg)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_PLAYERS, OnColumnclickListPlayers)
	ON_NOTIFY(HDN_ITEMDBLCLICK, IDC_LIST_PLAYERS, OnItemdblclickListPlayers)
	ON_BN_CLICKED(IDC_BUTTON_DRAFT, OnButtonDraft)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PLAYERS, OnDblclkListPlayers)
	ON_BN_CLICKED(IDC_BUTTON_RANDOM, OnButtonRandom)
	ON_BN_CLICKED(IDC_BUTTON_REPORT, OnButtonReport)
	ON_WM_CTLCOLOR()
	ON_LBN_DBLCLK(IDC_LIST_ROSTERS, OnDblclkListRosters)
	ON_BN_CLICKED(IDC_BUTTON_LOTTERY, OnButtonLottery)
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAMS, OnSelchangeComboListTeams)
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnButtonEdit)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_TRADE, OnButtonTrade)
	ON_BN_CLICKED(IDC_BUTTON_HTML, OnButtonHtml)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_PLAYERS, &CRookieDlg::OnLvnItemchangedListPlayers)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRookieDlg message handlers

BOOL CRookieDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR); 	
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 	
	m_buttonDraft.SetWindowText("Begin Draft");
	m_button_trade.EnableWindow(FALSE);
	InitLotteryOdds();
	ClearRatings();
	SortDraftSlots();
	ListTeams();
	ListDraftOrder();
	m_list_draft_order.SetCurSel(0);
	ReadNewID();
	initNewRoster();
	InitListCtrl();
	OpenRookies();
	SetRatings();
	SetCursors();
	ListControl();
	DisplayRoster();
	m_currentSelection = 1;
	SortByTrue();
	ListRookies();
//	if(m_shareware == true) 
//	{
//		CRegisterDlg reg;
//		reg.DoModal();
//		CDialog::OnOK();
//	}
	// TODO: Add extra initialization here	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}

void CRookieDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int team = m_listTeams.GetCurSel();

//	int team = m_initDraftSlot[m_currentRound][index+1];
	CString control = m_control[team];
	if(control == "Player") control = "Computer"; else if(control == "Computer") control = "Player";
	m_control[team] = control;
	ListControl();
}




void CRookieDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_CAREER_ROOKIE);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/draftpreview.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL CRookieDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/draftpreview.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
//	WinHelp(HID_CAREER_ROOKIE);	
//	return TRUE;	
}

void CRookieDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CRookieDlg::OnOK() 
{
	// TODO: Add extra validation here


	CreateCampRosterFile();
	WriteDraftFile();
	WriteNewID();	
	CDialog::OnOK();
}

void CRookieDlg::OpenRookies()
{
	
	
	CString current_file_name = m_path + m_leagueName + ".roo";
	CString old_file_name = m_path + m_leagueName + ".kie";
	if(avg.m_settings.m_current_stage != 3)
	{
		SetWindowText("Rookie Draft Preview");
		m_button_next.ShowWindow(FALSE);
		m_buttonDraft.ShowWindow(FALSE);
		m_saveDraft.ShowWindow(FALSE);
		m_button_lottery.ShowWindow(FALSE);
		m_button_report.ShowWindow(FALSE);
		m_buttonRandom.ShowWindow(FALSE);
		m_button_cancel.SetWindowText("Exit");
	}
	else
		SetWindowText("Rookie Draft");

	//	pFileName = old_file_name;


	CBBallFile* disk = new CBBallFile;
	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name;
	if(disk->FileExists(file_name + ".roo") == true)
		file_name = current_file_name;
	else
		file_name = old_file_name;

	disk->OpenRookies(file_name, Rookies);
	delete disk;

}

void CRookieDlg::ListRookies()
{

	int co = 0;
	int rating = 0, r = 0; //1st and last digit 
	int team = m_listTeams.GetCurSel();
	m_listPlayers.DeleteAllItems();
	if(team < 0) team = 0;
	

	CString str[33];

for(int pl=0; pl<=95; pl++)
{
	CPlayer m_player = Rookies[pl+1];
	CString pos = m_player.GetPos();
	CString name = m_player.GetName();
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD, Age;
	int ag = m_player.GetAge();
	Age.Format("%d", ag);
	int o = m_player.GetMovOff();
	OutO.Format("%d", o);
	int p = m_player.GetPenOff();
	PenO.Format("%d", p);
	int i = m_player.GetPostOff();
	PostO.Format("%d", i);
	int f = m_player.GetTransOff();
	TransO.Format("%d", f);
	int od = m_player.GetMovDef();
	OutD.Format("%d", od);
	int pd = m_player.GetPenDef();
	PenD.Format("%d", pd);
	int id = m_player.GetPostDef();
	PostD.Format("%d", id);
	int fd = m_player.GetTransDef();
	TransD.Format("%d", fd);
	if(name == "") continue;

	m_listPlayers.InsertItem(co,pos);
	m_listPlayers.SetItemText(co,1,name);
	m_listPlayers.SetItemText(co,2,Age);
	
	str[0] = pos;
	str[1] = name;
	str[2] = Age;

	
    Rookies[pl+1].SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_scout[team].m_scoring, avg.m_scout[team].m_shooting, avg.m_scout[team].m_rebounding, avg.m_scout[team].m_passing, avg.m_scout[team].m_defense);
	Rookies[pl+1].SetTradeTrueRating(0);
//	int index = m_list_team_names.GetCurSel();
	Rookies[pl+1].SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);


	r = m_player.GetPrFga();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_scoring);
	Rookies[pl+1].SetAdjPrFga(rating);
	CString s;
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,3,s);

	str[3] = s;



	r = m_player.GetPrFgp();
    rating = m_player.PrRating(true, r, avg.m_scout[team].m_shooting);
	Rookies[pl+1].SetAdjPrFgp(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,4,s);
	str[4] = s;

	r = m_player.GetPrFta();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_scoring);
	Rookies[pl+1].SetAdjPrFta(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,5,s);
	str[5] = s;

	r = m_player.GetPrFtp();
    rating = m_player.PrRating(true, r, avg.m_scout[team].m_shooting);
	Rookies[pl+1].SetAdjPrFtp(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,6,s);
	str[6] = s;


	r = m_player.GetPrTga();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_scoring);
	Rookies[pl+1].SetAdjPrTga(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,7,s);
	str[7] = s;


	r = m_player.GetPrTgp();
    rating = m_player.PrRating(true, r, avg.m_scout[team].m_shooting);
	Rookies[pl+1].SetAdjPrTgp(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,8,s);
	str[8] = s;

	r = m_player.GetPrOrb();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_rebounding);
	Rookies[pl+1].SetAdjPrOrb(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,9,s);
	str[9] = s;

	r = m_player.GetPrDrb();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_rebounding);
	Rookies[pl+1].SetAdjPrDrb(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,10,s);
	str[10] = s;

	r = m_player.GetPrAst();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_passing);
	Rookies[pl+1].SetAdjPrAst(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,11,s);
	str[11] = s;

	r = m_player.GetPrStl();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_defense);
	Rookies[pl+1].SetAdjPrStl(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,12,s);
	str[12] = s;

	r = m_player.GetPrTo();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_passing);
	Rookies[pl+1].SetAdjPrTo(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,13,s);
	str[13] = s;

	r = m_player.GetPrBlk();
    rating = m_player.PrRating(false, r, avg.m_scout[team].m_defense);
	Rookies[pl+1].SetAdjPrBlk(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(co,14,s);
	str[14] = s;
	
	m_listPlayers.SetItemText(co,15,OutO);
	m_listPlayers.SetItemText(co,16,PenO);
	m_listPlayers.SetItemText(co,17,PostO);
	m_listPlayers.SetItemText(co,18,TransO);
	m_listPlayers.SetItemText(co,19,OutD);
	m_listPlayers.SetItemText(co,20,PenD);
	m_listPlayers.SetItemText(co,21,PostD);
	m_listPlayers.SetItemText(co,22,TransD);

	str[15] = OutO;;
	str[16] = PenO;
	str[17] = PostO;
	str[18] = TransO;
	str[19] = OutD;
	str[20] = PenD;
	str[21] = PostD;
	str[22] = TransD;

		for(int j=0; j<=26; j++)
		{
			m_print_strings[co][j] = str[j];
		}

    co = co + 1;	

}


	int slot = (m_currentRound-1)*m_numberteams + m_currentSelection - 1;
	if(m_currentRound == 2) slot = slot + 2;
	if(slot >= 0) m_list_draft_order.SetCurSel(slot);

    m_listPlayers.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
}

void CRookieDlg::ListTeams()
{
	m_listTeams.ResetContent();
	for(int i=1; i<=m_numberteams; i++)
	{
//		int team = m_initDraftSlot[m_currentRound][i];
		m_listTeams.AddString(m_leagueTeamNames[i-1]);
	}
}


void CRookieDlg::ListControl()
{
	int index = m_listTeams.GetCurSel();
//	int team = m_initDraftSlot[m_currentRound][index+1];
	CString control = m_control[index];
	m_listControl.ResetContent();
	m_listControl.AddString(control);

}

void CRookieDlg::SetCursors()
{
	m_listTeams.SetCurSel(m_default_team);
	m_listRosters.SetCurSel(0);
	m_list_draft_order.SetCurSel(0);
	UpdateData(FALSE);
}


void CRookieDlg::InitListCtrl()
{
	m_button[0].SetFaceColor(BUTTONFACECOLOR2);
	m_button[1].SetFaceColor(BUTTONFACECOLOR2);
	m_button_lottery.SetFaceColor(BUTTONFACECOLOR2);
	m_buttonDraft.SetFaceColor(BUTTONFACECOLOR2);

	m_column_headers[0] = "pos";
	m_column_headers[1] = "player";
	m_column_headers[2] = "age";
	m_column_headers[3] = "2ga";
	m_column_headers[4] = "2%";
	m_column_headers[5] = "fta";
	m_column_headers[6] = "ft%";
	m_column_headers[7] = "3ga";
	m_column_headers[8] = "3%";
	m_column_headers[9] = "orb";
	m_column_headers[10] = "drb";
	m_column_headers[11] = "ast";
	m_column_headers[12] = "stl";
	m_column_headers[13] = "to";
	m_column_headers[14] = "blk";
	m_column_headers[15] = "o-o";
	m_column_headers[16] = "d-o";
	m_column_headers[17] = "p-o";
	m_column_headers[18] = "t-o";
	m_column_headers[19] = "o-d";
	m_column_headers[20] = "d-d";
	m_column_headers[21] = "p-d";
	m_column_headers[22] = "t-d";


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listPlayers.SetBkColor(BK_COLOR);
	m_listPlayers.SetTextBkColor(TEXT_BK_COLOR);

	m_listPlayers.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


    m_listPlayers.InsertColumn(0,"Pos");    
    m_listPlayers.InsertColumn(1,"Player");
	m_listPlayers.InsertColumn(2,"age");    
	m_listPlayers.InsertColumn(3,"2ga");    
    m_listPlayers.InsertColumn(4,"2%");
    m_listPlayers.InsertColumn(6,"fta");
    m_listPlayers.InsertColumn(7,"ft%");
    m_listPlayers.InsertColumn(8,"3ga");
    m_listPlayers.InsertColumn(9,"3%");
    m_listPlayers.InsertColumn(9,"orb");
    m_listPlayers.InsertColumn(10,"drb");
    m_listPlayers.InsertColumn(11,"ast");
    m_listPlayers.InsertColumn(12,"stl");
    m_listPlayers.InsertColumn(13,"to");
    m_listPlayers.InsertColumn(14,"blk");
    m_listPlayers.InsertColumn(15,"o");
    m_listPlayers.InsertColumn(16,"d");
    m_listPlayers.InsertColumn(17,"p");
    m_listPlayers.InsertColumn(18,"t");
    m_listPlayers.InsertColumn(19,"o");
    m_listPlayers.InsertColumn(20,"d");
    m_listPlayers.InsertColumn(21,"p");
    m_listPlayers.InsertColumn(22,"t");
  


	double scale = 1.5f;
	
    m_listPlayers.SetColumnWidth( 0, 30 * scale );
    m_listPlayers.SetColumnWidth( 1, 90 * scale );
    m_listPlayers.SetColumnWidth( 2, 28 * scale );
    m_listPlayers.SetColumnWidth( 3, 28 * scale );
    m_listPlayers.SetColumnWidth( 4, 28 * scale );
    m_listPlayers.SetColumnWidth( 5, 28 * scale );
    m_listPlayers.SetColumnWidth( 6, 28 * scale );
    m_listPlayers.SetColumnWidth( 7, 28 * scale );
    m_listPlayers.SetColumnWidth( 8, 28 * scale );
    m_listPlayers.SetColumnWidth( 9, 28 * scale );
    m_listPlayers.SetColumnWidth( 10, 28 * scale );
    m_listPlayers.SetColumnWidth( 11, 28 * scale );
    m_listPlayers.SetColumnWidth( 12, 28 * scale );
    m_listPlayers.SetColumnWidth( 13, 28 * scale );
    m_listPlayers.SetColumnWidth( 14, 28 * scale );
    m_listPlayers.SetColumnWidth( 15, 18 * scale );
    m_listPlayers.SetColumnWidth( 16, 18 * scale );
    m_listPlayers.SetColumnWidth( 17, 18 * scale );
    m_listPlayers.SetColumnWidth( 18, 18 * scale );
    m_listPlayers.SetColumnWidth( 19, 18 * scale );
    m_listPlayers.SetColumnWidth( 20, 18 * scale );
    m_listPlayers.SetColumnWidth( 21, 18 * scale);
    m_listPlayers.SetColumnWidth( 22, 18 * scale);
    m_listPlayers.SetTextColor(RGB(0,0,0));
	m_listPlayers.SetFont(&m_font);
	CString string;

	for(int i=1; i<=m_lottery_teams; i++)
	{
		int chances = m_lottery_odds[i] - m_lottery_odds[i-1]; 		
		CString team = m_leagueTeamNames[m_initDraftSlot[1][i].pick-1];
		string.Format("%s (%d) chances", team, chances);
		m_listDisplayDraft.AddString(string);

	}


	CBBallFile* disk = new CBBallFile;
	CString file_name = m_path + m_leagueName + ".roo";
	if(disk->FileExists(file_name) == true) m_button_edit.ShowWindow(FALSE);
	delete disk;
//	string.Format("* Start Round %d *",m_currentRound);
//	m_listDisplayDraft.AddString("");
//	m_listDisplayDraft.AddString(string);



	m_saveDraft.EnableWindow(FALSE);

}


void CRookieDlg::OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	m_column = pNMListView->iSubItem;
	if(m_column >= 0) 
	{
		SortByPosition();
		ListRookies();
	}
}

void CRookieDlg::SortByPosition()
{
	int co = 0;
	int rating = 0, r = 0; //1st and last digit 
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = 0;
	


for(int pl=0; pl<=95; pl++)
{
    Rookies[pl+1].SetAdjustedRatings(avg.m_scout[team]);
}
	//switch
m_listPlayers.DeleteAllItems();

for(int i=1; i<=96; i++)
{
for(int j=1; j<=96; j++)
{
bool swap = false;
double trade_i = Rookies[i].GetTradeValue() + 50;//insure > 0
double trade_j = Rookies[j].GetTradeValue() + 50;//insure > 0
int age_i = Rookies[i].GetAge();
int age_j = Rookies[j].GetAge();
if(Rookies[i].GetName() == ""){ trade_i = 0; age_i = 0;}
if(Rookies[j].GetName() == ""){ trade_j = 0; age_j = 0;}

switch(m_column) 
{
    case 0:
        swap = Rookies[i].GetPos() < Rookies[j].GetPos();
        break;
    case 1:
        swap = trade_i > trade_j;
        break;
    case 2:
        swap = age_i > age_j;
        break;
    case 3:
        swap = Rookies[i].GetAdjPrFga() > Rookies[j].GetAdjPrFga();
        break;
    case 4:
        swap = Rookies[i].GetAdjPrFgp() > Rookies[j].GetAdjPrFgp();
        break;
    case 5:
        swap = Rookies[i].GetAdjPrFta() > Rookies[j].GetAdjPrFta();
        break;
    case 6:
        swap = Rookies[i].GetAdjPrFtp() > Rookies[j].GetAdjPrFtp();
        break;
    case 7:
        swap = Rookies[i].GetAdjPrTga() > Rookies[j].GetAdjPrTga();
        break;
    case 8:
        swap = Rookies[i].GetAdjPrTgp() > Rookies[j].GetAdjPrTgp();
        break;
    case 9:
        swap = Rookies[i].GetAdjPrOrb() > Rookies[j].GetAdjPrOrb();
        break;
    case 10:
        swap = Rookies[i].GetAdjPrDrb() > Rookies[j].GetAdjPrDrb();
        break;
    case 11:
        swap = Rookies[i].GetAdjPrAst() > Rookies[j].GetAdjPrAst();
        break;
    case 12:
        swap = Rookies[i].GetAdjPrStl() > Rookies[j].GetAdjPrStl();
        break;
    case 13:
        swap = Rookies[i].GetAdjPrTo() > Rookies[j].GetAdjPrTo();
        break;
    case 14:
        swap = Rookies[i].GetAdjPrBlk() > Rookies[j].GetAdjPrBlk();
        break;
    case 15:
        swap = Rookies[i].GetMovOff() > Rookies[j].GetMovOff();
        break;
    case 19:
        swap = Rookies[i].GetMovDef() > Rookies[j].GetMovDef();
        break;
    case 16:
        swap = Rookies[i].GetPenOff() > Rookies[j].GetPenOff();
        break;
    case 20:
        swap = Rookies[i].GetPenDef() > Rookies[j].GetPenDef();
        break;
    case 17:
        swap = Rookies[i].GetPostOff() > Rookies[j].GetPostOff();
        break;
    case 21:
        swap = Rookies[i].GetPostDef() > Rookies[j].GetPostDef();
        break;
    case 18:
        swap = Rookies[i].GetTransOff() > Rookies[j].GetTransOff();
        break;
    case 22:
        swap = Rookies[i].GetTransDef() > Rookies[j].GetTransDef();
        break;
}



	if(swap == true)
	{//swap
		CPlayer temp = Rookies[i];
		Rookies[i] = Rookies[j];
		Rookies[j] = temp;
	}

}
}
//ListRookies();
}

void CRookieDlg::SortByTrue()
{
	m_column = 1;
	SortByPosition();
}

void CRookieDlg::ClearRatings()
{
	m_currentSelection = 1;
	m_currentRound = 1;
    m_draftStarted = false;
	m_selection = 0;
	for(int i=0; i<=99; i++)
	{
		m_choices[i] = 0;
	}
	for(int i=0; i<=32; i++)
	{
		m_orig_standings[i] = avg.m_standings[i];
	}
}

void CRookieDlg::SetRatings()
{


for(int i=1; i<=96; i++)
{
	CPlayer m_player = Rookies[i];
	CString pos = m_player.GetPos();
	CString name = m_player.GetName();

	m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	

	Rookies[i] = m_player;
	
	
}


}

void CRookieDlg::OnItemdblclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CRookieDlg::OnButtonDraft() 
{
	// TODO: Add your control notification handler code here
	int te = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
    if(m_draftStarted == false)
	{
		m_button_trade.EnableWindow(TRUE);
		CString string;
		string.Format("* Start Round %d *",m_currentRound);
		m_listDisplayDraft.ResetContent();
		m_listDisplayDraft.AddString(string);

		m_draftStarted = true;
		m_buttonRandom.EnableWindow(FALSE);
		m_button_lottery.EnableWindow(FALSE);
		m_buttonDraft.SetWindowText(" Draft All");
	}
	if(m_control[te-1] == "Player" && m_draftOver == false)
		GmChoiceBox();
	
	else
	{
	SortByTrue();
	do
	{
		int p = GetComputerSelection();
		SelectionMade(p);
        if(m_draftOver == false)
			te = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
		else te = 1;//ensure leaving loop after draft
	}
	while(m_control[te-1] == "Computer" && m_draftOver == false);
	m_listPlayers.DeleteAllItems();
	SortByPosition();
	ListRookies();
	if(m_draftOver == false) GmChoiceBox();
	}	
}

int CRookieDlg::GetComputerSelection()
{

	int picked = 1, elig1 = 0, elig2 = 0, elig3 = 0, elig4 = 0, elig5 = 0;
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = 0;
	int pi = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
    int slot = pi*30 - 29;
	
	bool needPg = true, needSg = true, needSf = true, needPf = true, needC = true;



	bool star_pg = false;
	bool star_sg = false;
	bool star_sf = false;
	bool star_pf = false;
	bool star_c = false;


	for(int i = 0; i <= 29; i++)
	{

		CPlayer m_player = New[slot + i];
        if(m_player.GetName() == "") continue;


		//avg.m_owner[team].SetPositionValues(avg.m_actual, team*30+1, avg.m_coach[team]);



		m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), avg.m_scout[team].m_scoring, avg.m_scout[team].m_shooting, avg.m_scout[team].m_rebounding, avg.m_scout[team].m_passing, avg.m_scout[team].m_defense);
		m_player.SetTradeTrueRating(0);
		int need = avg.m_gm[team].m_power1;
		int beforePrime = m_player.GetPrime() - m_player.GetAge();//base wether or not you pick by need on random, need rating, and years before prime
		bool draft_based_on_need = 
			(beforePrime > 0 && (avg.IntRandom(12) > (4+beforePrime+(6-need))));
		m_player.SetAdjTradeValue(avg.m_scout[team].m_pot1, avg.m_scout[team].m_pot2, avg.m_scout[team].m_effort);

		if(m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1) && draft_based_on_need == true)
		{
			CString pos = m_player.GetPos();
			if(pos == "PG" ) needPg = false;
			else if(pos == "SG") needSg = false;
			else if(pos == "SF") needSf = false;
			else if(pos == "PF") needPf = false;
			else if(pos == " C") needC = false;
		}




		m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	




        bool ok = (m_player.GetPrFga() >= 5 && m_player.GetPrFta() >= 5 && m_player.GetPrFgp() > 4/13);

        if(ok == true && m_player.GetPos() == "PG")
           elig1 = elig1 + 1;
        else if(ok == true && m_player.GetPos() == "SG")
           elig2 = elig2 + 1;
        else if(ok == true && m_player.GetPos() == "SF")
           elig3 = elig3 + 1;
        else if(ok == true && m_player.GetPos() == "PF")
           elig4 = elig4 + 1;
        else if(ok == true && m_player.GetPos() == " C")
           elig5 = elig5 + 1;




		if(beforePrime > 0 && m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1.375) && m_player.m_pos == "PG") star_pg = true;
		if(beforePrime > 0 && m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1.375) && m_player.m_pos == "SG") star_sg = true;
		if(beforePrime > 0 && m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1.375) && m_player.m_pos == "SF") star_sf = true;
		if(beforePrime > 0 && m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1.375) && m_player.m_pos == "PF") star_pf = true;
		if(beforePrime > 0 && m_player.GetTradeTrueRating(TRUE) > (avg.m_avg_trade_tru[0]*1.375) && m_player.m_pos == " C") star_c = true;


		
	}

    bool found = false;
	for(int i=1; i<=96; i++)
	{
		if(found == true || Rookies[i].GetName() == "") continue;
		if(elig1 < 1 && Rookies[i].GetPos() == "PG" && star_pg == false)
		{
			found = true;
			picked = i;
		}
		else if(elig2 < 1 && Rookies[i].GetPos() == "SG" && star_sg == false)
		{
			found = true;
			picked = i;
		}
		else if(elig3 < 1 && Rookies[i].GetPos() == "SF" && star_sf == false)
		{
			found = true;
			picked = i;
		}
		else if(elig4 < 1 && Rookies[i].GetPos() == "PF" && star_pf == false)
		{
			found = true;
			picked = i;
		}
		else if(elig5 < 1 && Rookies[i].GetPos() == " C" && star_c == false)
		{
			found = true;
			picked = i;
		}
	}	
	if(found == false)
	{
		int need = avg.m_gm[team].m_power1 + avg.IntRandom(5);
		for(int i=1; i<=need; i++)
		{
		    if(found == true || Rookies[i].GetName() == "") continue;

			CPlayer m_player = Rookies[i];
			if(m_player.GetPos() == "PG" && needPg == true && star_pg == false) {picked = i; found = true;}
			else if(m_player.GetPos() == " C" && needC == true && star_c == false) {picked = i; found = true;}
			else if(m_player.GetPos() == "SG" && needSg == true && star_sg == false) {picked = i; found = true;}
			else if(m_player.GetPos() == "SF" && needSf == true && star_sf == false) {picked = i; found = true;}
			else if(m_player.GetPos() == "PF" && needPf == true && star_pf == false) {picked = i; found = true;}
		}
	}

	if(found == false)//pick best player on board
	{
		for(int i=1; i<=96; i++)
		{
		    if(found == true || Rookies[i].GetName() == "") continue;
			CPlayer m_player = Rookies[i];
			picked = i; found = true;
		}
	}




	return picked;

}

void CRookieDlg::ResetRookieList(int p)
{
	for(int i=p; i<=95; i++)
	{
		Rookies[i] = Rookies[i+1]; 
	}
	CPlayer m_player;
	Rookies[96] = m_player;
}

void CRookieDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] Rookies;
//	delete [] Player;
	delete [] New;
//	delete [] FA;
	for(int i=0; i<=32; i++)
	{
		avg.m_standings[i] = m_orig_standings[i]; 
	}

	delete [] m_orig_standings;
	
}		

void CRookieDlg::SortDraftSlots()// sort later by record
{
	m_lottery_teams = 0;
	for(int r=1; r<=2; r++)
	{
		
		for(int i=1; i<=32; i++)
		{
			if(avg.m_own[0].m_draft_chart[1][r][i] == 0 && i <= avg.m_settings.m_numberteams)
				avg.m_own[0].m_draft_chart[1][r][i] = i;
			m_initDraftSlot[r][i].pick = avg.m_own[0].m_draft_chart[1][r][i];
			m_initDraftSlot[r][i].round = r;
			m_initDraftSlot[r][i].slot = i;

		}

	}
	

	for(int i=1; i<=m_numberteams; i++)
		{
			if(avg.m_standings[i-1].m_playoff_team == false) m_lottery_teams = m_lottery_teams + 1;

		}


	for(int i=1; i<=m_numberteams; i++)
	{
			

	
	for(int j=1; j<=m_numberteams; j++)
	{

		double score_i = avg.m_standings[i-1].m_leaguePct + avg.m_standings[i-1].m_playoff_team;
		double score_j = avg.m_standings[j-1].m_leaguePct + avg.m_standings[j-1].m_playoff_team;
		if(score_i <= score_j)
		{
			CRecord temp = avg.m_standings[i-1];
			avg.m_standings[i-1] = avg.m_standings[j-1];
			avg.m_standings[j-1] = temp;
			DRAFT tmp = m_initDraftSlot[1][i];
			m_initDraftSlot[1][i] = m_initDraftSlot[1][j];
			m_initDraftSlot[1][j] = tmp;

			tmp = m_initDraftSlot[2][i];
			m_initDraftSlot[2][i] = m_initDraftSlot[2][j];
			m_initDraftSlot[2][j] = tmp;
		}
	}
	}

	
	for(int j=1; j<=32; j++)
	{
		m_origslot[j] = avg.m_standings[j-1].m_initialNumber;
	}


}

void CRookieDlg::OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int currentChoice = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;	
	if(currentChoice >= 1)
	{
	CPlayer m_player = Rookies[currentChoice];

	CRookieCardDlg* scout = new CRookieCardDlg;



	scout->m_player_index = currentChoice;
	scout->m_title = "Scout";
	scout->avg = avg;
	for(int i=1; i<=96; i++)
	{
		scout->avg.m_actual[i] = Rookies[i];
	}
	scout->m_pl_index_end = 96;

	scout->DoModal();
	delete scout;

	}

	*pResult = 0;
}

void CRookieDlg::SelectionMade(int p)
{
	if(m_currentRound < 3)
	{

	CString round;
	round.Format("Round %d Pick %d",m_currentRound, m_currentSelection);
	Rookies[p].m_round_selected = m_currentRound;
	Rookies[p].m_pick_selected = m_currentSelection;
	
	m_listDisplayDraft.AddString(round);

	CString name = Rookies[p].GetName();
	CString pos = Rookies[p].GetPos();
	int original = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
	CString teamName = m_leagueTeamNames[original-1];
	CString str = teamName + ": " + pos + " " + name;
	m_listDisplayDraft.AddString(str);
	int pick = 1;//find 1st empty slot in teams draft list
	for(int i=1; i<=5; i++)
	{
		if(m_draft[original][i].GetName() != "") pick = i + 1;
	}
	m_draft[original][pick] = Rookies[p];
	

	CreateNewRoster(pick);

	ResetRookieList(p);
	m_currentSelection = m_currentSelection + 1;
	if(m_currentSelection > m_numberteams)
	{

		CString string;
		string.Format("* End of Round %d *",m_currentRound);	
		m_listDisplayDraft.AddString(string);
	
		m_currentSelection = 1;
		m_currentRound = m_currentRound + 1;
		if(m_currentRound == 3)
		{
			CString string;
			string = "* End of Draft *";	
			m_listDisplayDraft.AddString(string);
			m_draftOver = true;
			m_buttonDraft.EnableWindow(FALSE);
			m_buttonDraft.SetWindowText("End of Draft");
			m_saveDraft.EnableWindow(TRUE);
			m_button_next.EnableWindow(FALSE);
			FinalizeNewRosters();
		}
	}


	int items = m_listDisplayDraft.GetCount();
	m_listDisplayDraft.SetCurSel(items - 1);
	DisplayRoster();
	UpdateData(FALSE);

	}

}

void CRookieDlg::GmChoiceBox()
{
	CString message;
	int original = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
	AfxFormatString1( message, IDS_STRING_MESSAGE_DRAFT, m_leagueTeamNames[original-1]); 
	AfxMessageBox(message, MB_OK);	

	ListTeams();
	m_listTeams.SetCurSel(original-1);
	OnSelchangeComboListTeams(); 

}

void CRookieDlg::DisplayRoster()
{
	int team = m_listTeams.GetCurSel() + 1;
	m_listRosters.ResetContent();
	for(int i=1; i<=30; i++)
	{
//		int slot = m_initDraftSlot[m_currentRound][team]*20-20+i;
		int slot = team*30-30+i;
		if(New[slot].GetName() != "")
			m_listRosters.AddString(New[slot].GetPos() + " " + New[slot].GetName());
	}
	m_listRosters.SetCurSel(0);
	UpdateData(FALSE);
}

void CRookieDlg::CreateNewRoster(int pick)
{
	//ignore pick new format no need!
	int slot = m_initDraftSlot[m_currentRound][m_currentSelection].pick*30 - 30;
	m_idCount = m_idCount + 1;
	int co =  0;
	for(int i=1; i<=30; i++)
	{
		if(New[slot + i].m_name != "") co = co + 1;
	}

	New[slot + co + 1] = m_draft[m_initDraftSlot[m_currentRound][m_currentSelection].pick][pick];
	New[slot + co + 1].SetID(m_idCount);
	New[slot + co + 1].m_content = 5;
	m_selection = m_selection + 1;
	m_choices[m_selection] = m_idCount;
}

void CRookieDlg::initNewRoster()
{
	int t = 1, p = 1;
	for(int i=1; i<=960; i++)
	{

		int slot = t*30-30 + p;
		int new_slot = t*30-30+p;
		New[new_slot] = avg.m_actual[slot];
		p = p + 1;
		if(p == 30) { t=t+1; p = 1;}
	}

	for(int i=1; i<=480; i++)
	{
		New[960+i] = avg.m_actual[960+i];
	}

}

void CRookieDlg::FinalizeNewRosters()// add rookies to fa list
{


	int start = 0;//find 1st slot in fa list to slide down players to fill blank spots esp since the undrafted rookies are added to the end (1281-1440)
	for(int  i=961; i<=1440; i++)
	{
		if(New[i].m_name == "" && start == 0) start = i-1;
	}


	for(int i=1; i<=96; i++)
	{
		New[start + i] = Rookies[i];
		if(Rookies[i].GetName() != "")
		{
			m_idCount = m_idCount + 1;
			New[start + i].SetID(m_idCount);
		}
	}



}



void CRookieDlg::WriteNewID()
{
	
	CString pFileName = m_path + m_leagueName + ".car";
	CFile file(	pFileName, CFile::modeWrite);	
	int idCount = m_original_id_count + 100;
	CString string;
	string.Format("%d", idCount);
	string = string + "     ";
	int seek = 0;
	
	file.Seek( seek, CFile::begin);
	file.Write(string, 5);
	
	seek = (int)file.GetLength();
	file.SetLength(seek + 250000);
	char buffer[250001];
	file.Seek( seek, CFile::begin);
	memset( buffer, ' ', 250000);		
	file.Write( buffer, 250000);
	file.Close(); 
}





void CRookieDlg::CreateCampRosterFile()
{




	for(int i=1; i<=1440; i++)
	{
		avg.m_actual[i] = New[i];
		int te = 1 + (i-1)/30;
		if(avg.m_actual[i].m_name != "" && i <= 960)
		{
			avg.m_actual[i].m_current_team = te-1;

		}
		else
		{
			avg.m_actual[i].m_current_team = -1;
		}
		if(te >= 1 && te <= 32)
		{
			avg.m_actual[i].m_team_paying = te;
			avg.m_actual[i].m_team_paying_name = avg.m_settings.m_leagueTeamNames[te-1];
		}

	}
	
}


void CRookieDlg::OnButtonRandom() 
{
	// TODO: Add your control notification handler code here
	int draft_slot[3][34];
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=33; j++)
		{
			draft_slot[i][j] = m_initDraftSlot[i][j].pick;	

		}
	}




	
	bool used[35];
	for(int i=0; i<=34; i++)
	{

		used[i] = false;
	}

	for(int i=1; i<=m_numberteams; i++)
	{
		int j=0;
		do
		{
		 j = avg.IntRandom(m_numberteams); 
        }
		while(used[j] == true);
		used[j] = true;
		draft_slot[1][i] = m_initDraftSlot[1][j].pick;
		draft_slot[2][i] = m_initDraftSlot[2][j].pick;
	}


	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=33; j++)
		{
			m_initDraftSlot[i][j].pick = draft_slot[i][j];	
		}
	}


	ListTeams();
	m_listTeams.SetCurSel(0);
	OnSelchangeComboListTeams();

	ListDraftOrder();

}

void CRookieDlg::WriteDraftFile()
{
	CreateEmptyDraftFile();
	WritePlayerDraftPosition();

	CString pFileName = m_path + m_leagueName + ".dra";
  	CStdioFile file(pFileName, CFile::modeWrite);
	int size = (int)file.GetLength();
	int seek = size - 19999;
	file.Seek( seek, CFile::begin);
	CString year;
	year.Format("***** %d rookie draft *****", m_currentYear);
	file.WriteString(year + "\n");
	for(int i=0; i<=(m_listDisplayDraft.GetCount()-1); i++)
	{
		CString pick;
		m_listDisplayDraft.GetText(i, pick);
		if(pick != "") file.WriteString(pick+"\n");
	}
	file.SetLength(size + 20000);
	char buffer[20001];
	file.Seek( size + 1, CFile::begin);
	memset( buffer, ' ', 20000);		
	file.Write( buffer, 20000);
	file.Close();
	UpdateCareerYear();
	CFile fil;
	CFileStatus status;
	pFileName = m_path + m_leagueName + ".roo";
	// remove rookie file
	if( CFile::GetStatus( pFileName, status )) fil.Remove(pFileName);
}

void CRookieDlg::CreateEmptyDraftFile()
{
	CFileStatus status;
	CString pFileName = m_path + m_leagueName + ".dra";
	if( CFile::GetStatus( pFileName, status ) == FALSE) 
	{
		CFile file( pFileName, CFile::modeCreate | CFile::modeWrite );
		char buffer[20001];
		memset( buffer, ' ', 20000);
		file.Write( buffer, 20000);
		file.Close();
	}

}

void CRookieDlg::UpdateCareerYear()
{
//	CString pFileName = m_path + m_leagueName + ".lge";
//	CFile fi( pFileName, CFile::modeWrite );
//	fi.Seek(3992, CFile::begin);	
//	CString buffer;
	m_currentYear = m_currentYear + 1;
//	buffer.Format("%d", m_currentYear);
//	buffer = buffer + "    ";
//	fi.Write( buffer, 4);
//	fi.Close();
}

void CRookieDlg::OnButtonReport() 
{
	// TODO: Add your control notification handler code here
	int currentChoice = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	SelectionMade(currentChoice);
	m_listPlayers.DeleteAllItems();
	SortByPosition();
	ListRookies();


}

void CRookieDlg::WritePlayerDraftPosition()
{
CString pFileName = m_path + m_leagueName + ".car";
CFile file(	pFileName, CFile::modeWrite);	
int pos = 0, round = 1;
CString buffer;
for(int i=1; i<=m_selection; i++)
{ 
	pos = pos + 1; 
	if(pos > m_numberteams){ pos = 1; round = round + 1;}
 	int id = m_choices[i];
	if(id<1) continue;

    int seek = id*2500 + 26 + 24*100;	// draft selection where

	file.Seek( seek, CFile::begin);
	buffer.Format("%d", round);
	file.Write(buffer, 1);//write round
	
	buffer.Format("%d", pos);
	buffer = buffer + "  ";
	file.Write(buffer, 2);//write round

	buffer.Format("%d", i);
	buffer = buffer + "  ";
	file.Write(buffer, 2);//write selection
}

}


HBRUSH CRookieDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CRookieDlg::OnDblclkListRosters() 
{
//	int i = m_listTeams.GetCurSel();
//	int j = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;

	int team = m_listTeams.GetCurSel();
	int player = m_listRosters.GetCurSel();
	int offset = (team+1)*30-30;


	if(team >= 0)
	{


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = team;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=1; c<=20; c++)
	{
		int offset = team*30;
		scout->avg.m_actual[c] = New[offset+c];
	}
	scout->m_player_index = player+1;
	scout->m_pl_index_end = 15;
	scout->m_pl_index_start = 1;

	scout->DoModal();
	delete scout;
	}
}

void CRookieDlg::ListDraftOrder()
{
	m_list_draft_order.ResetContent();
	for(int r=1; r<=2; r++)
	{
		for(int i=1; i<=m_numberteams; i++)
		{
			int t = m_initDraftSlot[r][i].pick;
			if(t > 0)
			{
				if(m_leagueTeamNames[t-1] != "")
				{
					int sl = (r-1)*m_numberteams + i;
					CString str;
					str.Format("%d", sl);

					m_list_draft_order.AddString(str + ". " + m_leagueTeamNames[t-1]);
					m_origslot[i] = avg.m_standings[t-1].m_initialNumber;
				}
			}
		}
		if(r == 1)
		{
			m_list_draft_order.AddString("");
			m_list_draft_order.AddString("*Round 2*");
		}
	}

}

void CRookieDlg::OnButtonLottery() 
{
	// TODO: Add your control notification handler code here
	m_button_lottery.EnableWindow(FALSE);
	m_button_trade.EnableWindow(TRUE);
		
	

	int winner[] = {0, 0, 0, 0};
	int ro[] = {0,0,0,0};
	int sl[] = {0,0,0,0};

	int selected[33];
	for(int i=0; i<=32; i++)
	{
		selected[i] = 0;
	}

	int teams_picks[33];
	for(int i=0; i<=32; i++)
	{
		teams_picks[i] = 0;
	}

	for(int i=0; i<=32; i++)
	{
		if(m_initDraftSlot[1][i].pick >= 0 && m_initDraftSlot[1][i].pick <= 32)
			teams_picks[m_initDraftSlot[1][i].pick] = teams_picks[m_initDraftSlot[1][i].pick] + 1;
	}

	int n = 3;
	if(m_lottery_teams < 3) n = 2;

	for(int p=1; p<=n; p++)
	{
		int slot_winner = 0;
		do
		{



		int ball = avg.IntRandom(m_lottery_odds[m_lottery_teams]);
		winner[p] = 0;

		for(int i=1; i<=m_numberteams; i++)
		{
			if(winner[p] > 0) continue;
			if(ball <= m_lottery_odds[i])
			{
				winner[p] = m_initDraftSlot[1][i].pick;
				ro[p] = m_initDraftSlot[1][i].round;
				sl[p] = m_initDraftSlot[1][i].slot;
				slot_winner = i;
			}

		}
		
		}
		while ( selected[winner[p]] == teams_picks[winner[p]]);

		selected[winner[p]] = selected[winner[p]] + 1;

		for(int j=slot_winner; j<=31; j++)
		{			
			m_initDraftSlot[1][j] = m_initDraftSlot[1][j+1];
		}
		m_initDraftSlot[1][32].pick = 0;




		for(int j=32; j>=p+1; j--)
		{
			m_initDraftSlot[1][j] = m_initDraftSlot[1][j-1];
		}

		m_initDraftSlot[1][p].pick = winner[p];
		m_initDraftSlot[1][p].round = ro[p];
		m_initDraftSlot[1][p].slot = sl[p];
	}



	

	CString string;
	for(int i=m_lottery_teams; i>=1; i--)
	{

		CString team = m_leagueTeamNames[m_initDraftSlot[1][i].pick-1];
		string.Format("Pick %d : %s ", i, team);
		m_listDisplayDraft.AddString(string);
	}

	int index = m_listDisplayDraft.GetCount();
	m_listDisplayDraft.SetCurSel(index - m_lottery_teams);


	ListDraftOrder();
}

void CRookieDlg::InitLotteryOdds()
{
	int lottery_odds[] = {0,250,450,607,727,816,880,924,953,971,982,989,995,1000,1004,1007,1009,
		1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020,1021,1022,1023,1024,1025};
	for(int i=0; i<=32; i++)
	{
		m_lottery_odds[i] = lottery_odds[i];
	}

}



void CRookieDlg::OnSelchangeComboListTeams() 
{
	// TODO: Add your control notification handler code here
	ListControl();
	DisplayRoster();
	SortByPosition();	
	ListRookies();
}

void CRookieDlg::OnButtonPrint() 
{
	// TODO: Add your control notification handler code here
	CString m_headers[33];

    m_headers[0] = "Pos";    
    m_headers[1] = "Player";    
    m_headers[2] = "age";    
    m_headers[3] = "2ga";    
    m_headers[4] = "2%";    
    m_headers[5] = "fta";    
    m_headers[6] = "ft%";    
    m_headers[7] = "3ga";    
    m_headers[8] = "3%";    
    m_headers[9] = "orb";    
    m_headers[10] = "drb";    
    m_headers[11] = "ast";    
    m_headers[12] = "stl";    
    m_headers[13] = "to";    
    m_headers[14] = "blk";        
    m_headers[15] = "o-o";    
    m_headers[16] = "d-o";    
    m_headers[17] = "p-o";    
    m_headers[18] = "t-o";    

    m_headers[19] = "o-d";    
    m_headers[20] = "d-d";    
    m_headers[21] = "p-d";    
    m_headers[22] = "t-d";    

	CString pBuf[33];
	HDC    hdcPrn ;
	// Instantiate a CPrintDialog.
	CPrintDialog *printDlg = new CPrintDialog(FALSE, PD_ALLPAGES | PD_RETURNDC, NULL);
	// Initialize some of the fields in PRINTDLG structure.
	printDlg->m_pd.nMinPage = printDlg->m_pd.nMaxPage = 1;
	printDlg->m_pd.nFromPage = printDlg->m_pd.nToPage = 1;
    // Display Windows print dialog box.       
	printDlg->DoModal();
    // Obtain a handle to the device context.
	hdcPrn = printDlg->GetPrinterDC();
	if (hdcPrn != NULL)           
	{
		CDC *pDC = new CDC;
		pDC->Attach (hdcPrn);      // attach a printer DC
		pDC->StartDoc("Rookie Draft");  // begin a newe print job
        // for Win32 use
		// CDC::StartDoc(LPDOCINFO) override

		for(int page = 1; page <= 2; page++)
		{


		pDC->StartPage();          // begin a newe page
		SetPrintAlign(pDC, hdcPrn);// set the printing alignment
		LOGFONT lf;                        // Used to create the CFont.
		memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
		lf.lfWeight = 500;
		lf.lfHeight = 30;
		strcpy_s(lf.lfFaceName, "Courier New");
		CFont font;
		font.CreateFontIndirect(&lf);
		CFont* oldFont = pDC->SelectObject(&font);


		CString heading = "Rookie Draft List";


        pDC->TextOut(-900, 1000, heading);// write the string in pbuf
		int items = 48;
		int row = 950;

		for(int i = 0; i <= items; i++)
		{
			if(i == 1) row = 900;
			if(i == 0)
			{
				for(int j = 0; j <= 23; j++)
				{
					pBuf[j] = m_headers[j];
				}
			}
			else
			{
				for(int it=0; it<=23; it++)
				{
					pBuf[it] = m_listPlayers.GetItemText((page-1)*items + (i-1), it);
				}
			}
			

				for(int j=0; j<=23; j++)
				{
				int col = -900 + j*60;
				if(j == 0) col = -900;
				else if(j == 1) col = -850;
				else col = -700 + j*65;

				pDC->TextOut(col, row, pBuf[j]);// write the string in pbuf
				}
			
			row = row - 35;
		}
		pDC->EndPage();
		// end a page

		}
        pDC->EndDoc();             // end a print job
        pDC->Detach();             // detach the printer DC
        delete pDC;           
	}       
	delete printDlg;       
		
}

void CRookieDlg::SetPrintAlign(CDC *pDC, HDC hdcPrn)
{
	short cxPage, cyPage;
	cxPage = ::GetDeviceCaps (hdcPrn, HORZRES) ;
	cyPage = ::GetDeviceCaps (hdcPrn, VERTRES) ;

    pDC->SetMapMode (MM_ISOTROPIC) ;
	pDC->SetWindowExt ( 1000, 1000) ;

	pDC->SetViewportExt (cxPage / 2, -cyPage / 2) ;
    pDC->SetViewportOrg (cxPage / 2,  cyPage / 2) ;
    pDC->SetTextAlign (TA_BASELINE) ;
}

void CRookieDlg::OnButtonEdit() 
{
	// TODO: Add your control notification handler code here

	int currentChoice = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;	
	if(currentChoice >= 1)
	{
		CPlayer m_player = Rookies[currentChoice];
		CEditDlg* edit = new CEditDlg;
		edit->avg = avg;
		edit->m_actual = m_player;
		CString original_name = m_player.m_name;
		edit->m_rookie_edit = true;
		edit->m_default_team = 0;
		int result = edit->DoModal();
		if(result == IDOK)
		{
			CBBallFile* disk = new CBBallFile;
			CString file_name = m_path + m_leagueName + ".kie";
			if(disk->FileExists(file_name) == true)
			{
				Rookies[currentChoice] = edit->m_actual;
				disk->WriteRookieFile(file_name, Rookies);
			}
			delete disk;
			SetRatings();
			SortByTrue();
			ListRookies();
		}
		delete edit;
	}

}

void CRookieDlg::ReadNewID()
{
	char s[129];
	CString pFileName = m_path + m_leagueName + ".car";
	CFile file(	pFileName, CFile::modeRead);	
 	int bytes = file.Read(s, 5);
  	s[bytes] = 0;
	m_idCount = atoi(s);
	m_original_id_count = m_idCount;
}

BOOL CRookieDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return CDialog::OnEraseBkgnd(pDC);
}


void CRookieDlg::OnButtonTrade() 
{
	// TODO: Add your control notification handler code here

//	for(int r=1; r<=2; r++)
//	{
//		
//		for(int i=1; i<=32; i++)
//		{
//
//				avg.m_own[0].m_draft_chart[1][r][i] = m_initDraftSlot[r][i]; 
//
//		}
//
//	}




	CTradeDlg* trade;
	trade = new CTradeDlg;
	trade->m_draftround = 0;
	trade->m_draftpick = 0;
	trade->m_slots = 30;
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

	

	for(int r=1; r<=2; r++)
	{
		
		for(int i=1; i<=32; i++)
		{
			trade->m_slot_used[r][i] = 0;
		}

	}
	
	for(int r=1; r<=m_currentRound; r++)
	{
		int s = m_currentSelection-1;
		if(r != m_currentRound) s=32;
		for(int i=1; i<=s; i++)
		{
			//int o = m_origslot[n];
			int ro = m_initDraftSlot[r][i].round;
			int sl = m_initDraftSlot[r][i].slot;
			trade->m_slot_used[ro][sl] = ro*100 + sl;
		}

	}
	


	for(int i=0; i<=32; i++)
	{
//		trade->m_standings[i] = m_orig_standings[i];
		trade->m_scout[i] = avg.m_scout[i];
		trade->m_coach[i] = avg.m_coach[i];
		trade->m_gm[i] = avg.m_gm[i];
		trade->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
		trade->m_control[i] = avg.m_settings.m_player_gm[i];
		trade->m_own[i] = avg.m_own[i];
	}

	avg.SortTeamRosters(New, false);

	for(int t=0; t<=31; t++)
	{
		for(int p=1; p <= 30; p++)
		{
			trade->PlayerList[t][p] = New[t*30+p];
		}
	}


	trade->m_currentDay = avg.m_sched.m_currentDay;
	trade->m_currentMonth = avg.m_sched.m_currentMonth;


	int win[33], loss[33];
	for(int i=0; i<=32; i++)
	{
		win[i] = avg.m_standings[i].m_win;
		loss[i] = avg.m_standings[i].m_loss;
		trade->avg.m_standings[i].m_win = m_orig_win[i];
		trade->avg.m_standings[i].m_loss = m_orig_loss[i];
	}



	trade->m_default_team = m_default_team;
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
				New[t*30+p] = trade->PlayerList[t][p];
			}
		}

		avg.SortTeamRosters(New, false);
		DisplayRoster();



	for(int r=1; r<=2; r++)
	{
		
		for(int i=1; i<=32; i++)
		{
			//int o = m_origslot[n];
			int ro = m_initDraftSlot[r][i].round;
			int sl = m_initDraftSlot[r][i].slot;
			int n = avg.m_own[0].m_draft_chart[1][ro][sl];
			m_initDraftSlot[r][i].pick = n;

		}

	}
	
		ListDraftOrder();
	}


	for(int i=0; i<=32; i++)
	{
		avg.m_standings[i].m_win = win[i];
		avg.m_standings[i].m_loss = loss[i];
	}


	delete trade;	
}

void CRookieDlg::OnButtonHtml() 
{
	// TODO: Add your control notification handler code here
 CString headers[27];
		CString label = " Rookies";


			for(int j = 0; j <= 26; j++)
			{
				int col = j;

					headers[j] = m_column_headers[j];

			}


	CHtmlMsc* html = new CHtmlMsc;

	CString team_name, html_string;


	for(int i=0; i<=191; i++)
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
	html->m_league_name = m_leagueName;
	html->m_label = label;
	int items = m_listPlayers.GetItemCount();
	if(items < 0) items = 0;
	html->m_items = items;
	html->DoModal();
	delete html;
	
	
}

void CRookieDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	int te = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
    if(m_draftStarted == false)
	{
		CString string;
		string.Format("* Start Round %d *",m_currentRound);
		m_listDisplayDraft.ResetContent();
		m_listDisplayDraft.AddString(string);

		m_draftStarted = true;
		m_buttonRandom.EnableWindow(FALSE);
		m_button_lottery.EnableWindow(FALSE);
		m_buttonDraft.SetWindowText("Resume Draft");
	}
	if(m_control[te-1] == "Player" && m_draftOver == false)
		GmChoiceBox();
	
	else
	{
	SortByTrue();
//	do
//	{
		int p = GetComputerSelection();
		SelectionMade(p);
        if(m_draftOver == false)
			te = m_initDraftSlot[m_currentRound][m_currentSelection].pick;
		else te = 1;//ensure leaving loop after draft
//	}
//	while(m_control[te-1] == "Computer" && m_draftOver == false);
	m_listPlayers.DeleteAllItems();
	SortByPosition();
	ListRookies();
//	if(m_draftOver == false) GmChoiceBox();
	
	}

}


void CRookieDlg::OnLvnItemchangedListPlayers(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
