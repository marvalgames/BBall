// CampDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "CampDlg.h"
//#ifndef Display_h
//#include "Display.h"
//#define Display_h
//#endif 
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
#include "ProgressDlg1.h"
#include "PlayerCardDlg.h"
//#include "Constants.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCampDlg dialog


CCampDlg::CCampDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCampDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCampDlg)
	//}}AFX_DATA_INIT
	m_standings = new CRecord[34];
	Rookies = new CPlayer[1601];
	//Player = new CPlayer[1601];
	FA = new CPlayer[481];



	m_fa_count = 0;
	m_ratings_view = 1;
}


void CCampDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCampDlg)
	DDX_Control(pDX, IDC_COMBO_DRAFTTEAMS, m_listTeams);
	DDX_Control(pDX, IDC_BUTTON_RELEASE, m_buttonRelease);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_buttonSave);
	DDX_Control(pDX, IDC_BUTTON_HOF, m_buttonHOF);
	DDX_Control(pDX, IDC_LIST_DISPLAY_HALLOFFAME, m_listHallOfFame);
	DDX_Control(pDX, IDC_LIST_PLAYERS, m_listPlayers);
	DDX_Control(pDX, IDC_LIST_DISPLAY_RETIREMENTS, m_listRetired);
	DDX_Control(pDX, IDOK, m_saveDraft);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listControl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCampDlg, CDialog)
	//{{AFX_MSG_MAP(CCampDlg)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_PLAYERS, OnColumnclickListPlayers)
	ON_NOTIFY(HDN_ITEMDBLCLICK, IDC_LIST_PLAYERS, OnItemdblclickListPlayers)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_HOF, OnButtonHof)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_RELEASE, OnButtonRelease)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PLAYERS, OnDblclkListPlayers)
	ON_CBN_SELCHANGE(IDC_COMBO_DRAFTTEAMS, OnSelchangeComboDraftteams)
	ON_BN_CLICKED(IDC_RADIO_COACH, OnRadioCoach)
	ON_BN_CLICKED(IDC_RADIO_SCOUT, OnRadioScout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCampDlg message handlers

BOOL CCampDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
#if 0  // -----------------------------------------------------------
	DWORD dwStyle = LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS |
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP;

	CRect rect, rectbutton;
	GetClientRect(&rect);
	GetDlgItem(IDC_BUTTON1)->GetClientRect(&rectbutton);
	rect.DeflateRect(5, 5);
	rect.top = rectbutton.bottom + 15;

	TRACE("   calling CreateEx\n");

	// you may also use Create(), but I prefer WS_EX_CLIENTEDGE style
	m_listTeams.Create(WS_EX_CLIENTEDGE, _T("SysListView32"), _T(""),
						dwStyle, rect, this, IDC_LIST_TEAMS, NULL);
	CFont *pFont = GetFont();
	if (pFont)
		m_listTeams.SetFont(pFont);
#endif // -----------------------------------------------------------





	myBrush.CreateSolidBrush(DLGCOLOR); 	
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 	
	ClearRatings();
	InitListCtrl();
	SetCursors();
	
	OpenPlayers();
	
	SetRatings();
	Retirements();
	//SortAllPlayers();
	SortByTrue();
	ListRookies();
	ListTeams();
	m_listTeams.SetCurSel(m_default_team);
	ListControl();
	DisplayRoster();
	m_currentSelection = 1;

	// TODO: Add extra initialization here
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCampDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	CString control = m_control[index];
	if(control == "Player") control = "Computer"; else if(control == "Computer") control = "Player";
	m_control[index] = control;
	ListControl();
}




void CCampDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/progresscamp.htm", HH_DISPLAY_TOPIC, 0);
}

BOOL CCampDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_CAREER_CAMP);	

//	HtmlHelp(NULL, "jumpshot.chm::/html/budgetsheet.htm", HH_DISPLAY_TOPIC, 0);
//	HtmlHelp(NULL, "jumpshot.chm::/html/progresscamp.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);


}

void CCampDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CCampDlg::OnOK() 
{
	// TODO: Add extra validation here
	SortAllPlayers();
	CreateFaList();
	SortFaList();
//	SetNextSeasonData();
	WriteNextSeasonData(); //added sep 26
	//WriteHallOfFameFile(); // added sept 26

	m_buttonRelease.EnableWindow(FALSE);
	m_saveDraft.EnableWindow(FALSE);
	m_buttonHOF.EnableWindow(TRUE);
}

void CCampDlg::OpenPlayers()
{
//	AdjustData();
	for(int i=0; i<=1600; i++)
	{
		Rookies[i] = avg.m_actual[i];
	}

}

void CCampDlg::ListRookies()
{
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = 0;
	int offset = team*30;
	int pl = 0;
for(int l = 0; l <= 29; l++)
{
	int player = offset +  l;
	CPlayer* m_player = new CPlayer;
	*m_player = Rookies[player];
	CString pos = m_player->GetPos();
	CString name = m_player->GetName();
	if(name == "") continue;
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD, Age;
	int ag = m_player->GetAge();
	Age.Format("%d", ag);
	int o = m_player->GetMovOff();
	OutO.Format("%d", o);
	int p = m_player->GetPenOff();
	PenO.Format("%d", p);
	int i = m_player->GetPostOff();
	PostO.Format("%d", i);
	int f = m_player->GetTransOff();
	TransO.Format("%d", f);
	int od = m_player->GetMovDef();
	OutD.Format("%d", od);
	int pd = m_player->GetPenDef();
	PenD.Format("%d", pd);
	int id = m_player->GetPostDef();
	PostD.Format("%d", id);
	int fd = m_player->GetTransDef();
	TransD.Format("%d", fd);


	m_listPlayers.InsertItem(pl,pos);
	m_listPlayers.SetItemText(pl,1,name);
	m_listPlayers.SetItemText(pl,2,Age);
	
    Rookies[player].SetAdjTrueRatingSimple(m_player->GetFgm(), m_player->GetFga(), m_player->GetTfgm(), m_player->GetTfga(), m_player->GetFtm(),  m_player->GetFta(), m_player->GetOreb(),  m_player->GetReb(), m_player->GetAst(), m_player->GetStl(), m_player->GetTo(), m_player->GetBlk(), avg.m_coach[team].m_scoring, avg.m_coach[team].m_shooting, avg.m_coach[team].m_rebounding, avg.m_coach[team].m_passing, avg.m_coach[team].m_defense);
	Rookies[player].SetTradeTrueRating(0);
	Rookies[player].SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);


	int r = m_player->GetPrFga();
	CString s;
    int rating = m_player->PrRating(false, r, avg.m_coach[team].m_scoring);
	Rookies[player].SetAdjPrFga(rating);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,3,s);


	r = m_player->GetPrFgp();
    rating = m_player->PrRating(true, r, avg.m_coach[team].m_shooting);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,4,s);


	
	r = m_player->GetPrFta();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_scoring);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,5,s);

	r = m_player->GetPrFtp();
    rating = m_player->PrRating(true, r, avg.m_coach[team].m_shooting);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,6,s);


	r = m_player->GetPrTga();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_scoring);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,7,s);


	r = m_player->GetPrTgp();
    rating = m_player->PrRating(true, r, avg.m_coach[team].m_shooting);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,8,s);

	
	r = m_player->GetPrOrb();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_rebounding);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,9,s);

	r = m_player->GetPrDrb();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_rebounding);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,10,s);

	r = m_player->GetPrAst();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_passing);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,11,s);

	r = m_player->GetPrStl();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_defense);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,12,s);

	r = m_player->GetPrTo();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_passing);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,13,s);

	r = m_player->GetPrBlk();
    rating = m_player->PrRating(false, r, avg.m_coach[team].m_defense);
	s.Format("%d", rating);
	m_listPlayers.SetItemText(pl,14,s);
	
	m_listPlayers.SetItemText(pl,15,OutO);
	m_listPlayers.SetItemText(pl,16,PenO);
	m_listPlayers.SetItemText(pl,17,PostO);
	m_listPlayers.SetItemText(pl,18,TransO);
	m_listPlayers.SetItemText(pl,19,OutD);
	m_listPlayers.SetItemText(pl,20,PenD);
	m_listPlayers.SetItemText(pl,21,PostD);
	m_listPlayers.SetItemText(pl,22,TransD);
	pl = pl + 1;	


	delete m_player;
}
    m_listPlayers.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);

}

void CCampDlg::ListTeams()
{
	for(int i=1; i<=m_numberteams; i++)
	{
		int team = i;
		m_listTeams.AddString(m_leagueTeamNames[team-1]);
	}
}


void CCampDlg::ListControl()
{
	int index = m_listTeams.GetCurSel();
	CString control = m_control[index];
	m_listControl.ResetContent();
	m_listControl.AddString(control);

}

void CCampDlg::SetCursors()
{
	m_listTeams.SetCurSel(m_default_team);
	UpdateData(FALSE);
}


void CCampDlg::InitListCtrl()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

//	m_listPlayers.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listPlayers.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listPlayers.SetBkColor(BK_COLOR);
	m_listPlayers.SetTextBkColor(TEXT_BK_COLOR);

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
  
  
	
    m_listPlayers.SetColumnWidth( 0, 32);
    m_listPlayers.SetColumnWidth( 1, 99);
    m_listPlayers.SetColumnWidth( 2, 32);
    m_listPlayers.SetColumnWidth( 3, 32);
    m_listPlayers.SetColumnWidth( 4, 31);
    m_listPlayers.SetColumnWidth( 5, 31);
    m_listPlayers.SetColumnWidth( 6, 32);
    m_listPlayers.SetColumnWidth( 7, 32);
    m_listPlayers.SetColumnWidth( 8, 31);
    m_listPlayers.SetColumnWidth( 9, 29);
    m_listPlayers.SetColumnWidth( 10, 31);
    m_listPlayers.SetColumnWidth( 11, 31);
    m_listPlayers.SetColumnWidth( 12, 31);
    m_listPlayers.SetColumnWidth( 13, 31);
    m_listPlayers.SetColumnWidth( 14, 31);
    m_listPlayers.SetColumnWidth( 15, 22);
    m_listPlayers.SetColumnWidth( 16, 22);
    m_listPlayers.SetColumnWidth( 17, 22);
    m_listPlayers.SetColumnWidth( 18, 22);
    m_listPlayers.SetColumnWidth( 19, 22);
    m_listPlayers.SetColumnWidth( 20, 22);
    m_listPlayers.SetColumnWidth( 21, 22);
    m_listPlayers.SetColumnWidth( 22, 22);
    //m_listPlayers.SetTextColor(RGB(0,0,0));
	m_listPlayers.SetFont(&m_font);

	CheckDlgButton(IDC_RADIO_COACH, 1);

}


void CCampDlg::OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	m_column = pNMListView->iSubItem;
	if(m_column >= 0 && m_ratings_view == 1) SortByPosition();
	else if(m_column >= 0 && m_ratings_view == 2) SortByProgress();


}

void CCampDlg::SortByPosition()
{
	//switch
m_listPlayers.DeleteAllItems();


int team = m_listTeams.GetCurSel();
if(team < 0) team = 0;
int offset = team*30 + 1;





for(int i=offset; i<=offset+29; i++)
{
for(int j=offset; j<=offset+29; j++)
{
bool swap = false;
BOOL career = FALSE;
if(Rookies[i].m_name == "" || Rookies[j].m_name == "") continue;
switch(m_column) 
{
    case 0:
        swap = Rookies[i].GetPos() < Rookies[j].GetPos();
        break;
    case 1:
//        swap = Rookies[i].GetTradeTrueRating(career)  > Rookies[j].GetTradeTrueRating(career);
        swap = Rookies[i].GetRosterNumber()  < Rookies[j].GetRosterNumber();
        break;
    case 2:
        swap = Rookies[i].GetAge() > Rookies[j].GetAge();
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

ListRookies();
}

void CCampDlg::SortByTrue()
{
	m_column = 1;
	SortByPosition();
}

void CCampDlg::ClearRatings()
{
	m_gone = 0;
	m_buttonSave.EnableWindow(FALSE);
	m_buttonHOF.EnableWindow(FALSE);
}

void CCampDlg::SetRatings()
{

int team = m_listTeams.GetCurSel();
if(team < 0) team = 0;


for(int i=1; i<=1600; i++)
{
	Rookies[i] = avg.m_actual[i];
	CPlayer m_player = Rookies[i];
	CString pos = m_player.GetPos();
	CString name = m_player.GetName();

	//m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	
	//m_player.SetAdjustedRatings(avg.avg.m_coach[team]);	


	
	Rookies[i] = m_player;	
}


}

void CCampDlg::OnItemdblclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	*pResult = 0;
}






void CCampDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] m_standings;
	delete [] Rookies;
	delete [] FA;
//	delete [] Player;
}





void CCampDlg::DisplayRoster()
{
	SortByTrue();

}







void CCampDlg::WriteNextSeasonData()
{



for(int i=0; i<=960; i++)
{
	avg.m_actual[i] = Rookies[i];
}
for(int i=1; i<=480; i++)
{
	avg.m_actual[960+i] = FA[i];
}


AdjustData();


for(int i=0; i<=960; i++)
{
	Rookies[i] = avg.m_actual[i] ;
}
for(int i=1; i<=480; i++)
{
	if(i > 360)
	{
		CPlayer m_player;
		FA[i] = m_player;
	}
	else
	{
		FA[i] = avg.m_actual[960+i];
	}
}



if(m_ratings_view == 1)
{
	m_listPlayers.DeleteAllItems();
	ListRookies();
}
else if(m_ratings_view == 2)
{
	m_listPlayers.DeleteAllItems();
	ListProgress();
}




}




//void CCampDlg::SetNextSeasonData()
//{
//	for(int i=1; i<=960; i++)
//	{
//		Player[i] = Rookies[i];
//	}
//}

void CCampDlg::CreateFaList()
{

	int p=1;
	int t=0;
	for(int i=1; i<=1440; i++)
	{

		if(p > 15 && Rookies[i].GetName() != "" && i <= 960)
		{
			m_retired[m_gone] = Rookies[i];
			CString string = m_leagueTeamNames[t] + ": " + m_retired[m_gone].GetName() + " is released";
			m_gone = m_gone + 1;
			m_listRetired.AddString(string);
		}


		if((p>15 || i>960 && m_fa_count < 360) && Rookies[i].GetName() != "")
		{
			m_fa_count = m_fa_count + 1;
			FA[m_fa_count] = Rookies[i];
			CPlayer m_player;
			Rookies[i] = m_player;//clear players released to FA
		}
		p=p+1;
		if(p==31)
		{
			p=1;
			t=t+1;
		}
	}
	int index = m_listRetired.GetCount();
	m_listRetired.SetCurSel(index);
	UpdateData(FALSE);


}

void CCampDlg::SortFaList()
{
	BOOL career = FALSE;
	int count = m_fa_count;
	if(count > 360) count = 360;
	for(int i=1; i<=count; i++)
	{
		for(int j=1; j<=count; j++)
		{
			if(FA[i].GetTradeTrueRating(career) > FA[j].GetTradeTrueRating(career))
			{
				CPlayer temp = FA[i];
				FA[i] = FA[j];
				FA[j] = temp;
			}
		}
	}
		
}

void CCampDlg::SortAllPlayers()
{
	avg.SortTeamRosters(Rookies, true);

}

void CCampDlg::Retirements()
{
	CRetirement* ret = new CRetirement;
	ret->m_path = m_path;
	ret->m_league_name = m_leagueName;
	for(int i=0; i<=1600; i++)
	{
		ret->avg.m_actual[i] = Rookies[i];
	}
	ret->ReadRetirements();
	ret->UpdatePlayerClass();
	for(int i=0; i<=1600; i++)
	{
		Rookies[i] = ret->avg.m_actual[i];
	}
	delete ret;




	int n=0;
	int t=0;
	int p=1;
	
	for(int i=0; i<=1440; i++)
	{
		int age = Rookies[i].GetAge();
        CPlayer m_player = Rookies[i];

		//bool ok = (m_player.GetPrFga() >= 3 && m_player.GetPrFta() >= 3 && m_player.GetPrFgp() >= 25);
        bool ok = (m_player.GetPrFga() >= 5 && m_player.GetPrFta() >= 5 && m_player.GetPrFgp() > 4/14 && m_player.GetFgm() > 4 && m_player.GetFtm() > 2);

		
		if((Rookies[i].GetName() != "" && ok == false) || (Rookies[i].GetName() != "" && Rookies[i].m_retired == true)) 
		{
			//SetRetiredPlayer
			m_retired[n] = Rookies[i];
			CPlayer m_player;
			Rookies[i] = m_player;//blank so screws up the player cards - fix!!!
			CString ret = m_retired[n].GetName();
			CString team;
			if(t > 32) { t = 32; team = "";}
			else team = m_leagueTeamNames[t];
			CString string;
			bool premature = m_retired[n].GetAge() < m_retired[n].GetPrime();
			if(team != "" && team !="Computer" && ok == true && premature == false) string = team + ": " + ret + " retires ";
			else if(ok == true && premature == false) string = ret + " retires";

			else if(team != "" && team !="Computer" && ok == true && premature == true) string = team + ": "  + ret + " retires ";
			else if(ok == true && premature == true) string = ret + " retires";

			else if(team != "" && team !="Computer" && ok == false) string = team + ": " + ret + " is no longer available";
			else string = " " + ret + " is no longer available";
			CString ag;
			ag.Format(" at the age of %d", age);
			m_listRetired.AddString(string + ag);
			n = n+1;
		}
		p = p+1;
		if(p > 30){p=1; t=t+1;}

	}
//	delete rnd;
	m_gone = n;
	m_listRetired.SetCurSel(0);
	UpdateData(FALSE);

}

void CCampDlg::SelectHallOfFame()
{

	int n=0;
	int p=1;
	do
	{
		bool found = false;
		for(int i=0; i<=360; i++)
		{
			if(FA[i].GetName() != "" && FA[i].GetName() == m_retired[n].GetName())
			{
				found = true;
			}
		}
	int id = m_retired[n].GetID();


	CString sal_file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".sal";

	int major_points = 0;
	int awa_pts = m_retired[n].GetAwardPoints(sal_file_name, major_points);
	bool hall = m_retired[n].HallofFamer(awa_pts, major_points);

	if(found == false && hall == true)
		{
			m_hall[p] = m_retired[n];
			CString string = m_hall[p].GetName();
			string  = "Congratulations to " + string;
			m_listHallOfFame.AddString(string);

		
			p = p + 1;
		}
		n = n+1;
	}
	while(m_retired[n].GetName() != "");


	m_listHallOfFame.SetCurSel(0);

}

void CCampDlg::OnButtonHof() 
{
	// TODO: Add your control notification handler code here
	if(m_retired[1].GetName() != "") SelectHallOfFame();
	m_buttonSave.EnableWindow(TRUE);
	m_buttonHOF.EnableWindow(FALSE);
	
}

void CCampDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here




//	WriteNextSeasonData(); sept 26
	WriteHallOfFameFile(); 


	CFile fil;
	CFileStatus status;
	CString pFileName = m_path + m_leagueName + ".kie";
	// remove rookie file
	if( CFile::GetStatus( pFileName, status )) fil.Remove(pFileName);
			
	CDialog::OnOK();
}

void CCampDlg::OnButtonRelease() 
{
	// TODO: Add your control notification handler code here
	int currentChoice = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(currentChoice >= 0)
	{
	int currentTeam = m_listTeams.GetCurSel();
	int playerIndex = currentTeam*30+currentChoice + 1;
	if(m_control[currentTeam] == "Computer")
		AfxMessageBox("Team releasing a player must be player controlled.", MB_OK);
	else if(playerIndex >= 0)
	{
	CString playerCut = m_leagueTeamNames[currentTeam] + ": " + Rookies[playerIndex].GetName() + " is released";
	m_listRetired.AddString(playerCut);
	
	m_fa_count = m_fa_count + 1;
	FA[m_fa_count] = Rookies[playerIndex];
	int i=0;
	for(i=playerIndex; i<=currentTeam*30+29; i++)
	{
		Rookies[i] = Rookies[i+1]; 
	}
	CPlayer* m_player = new CPlayer;
	Rookies[i-1] = *m_player;



	m_listPlayers.DeleteAllItems();
	ListRookies();
	delete m_player;

	}
	}
}


void CCampDlg::WriteHallOfFameFile()
{
	if(m_hall[1].GetName() != "")
	{
	CFileStatus status;
	CString fileName = m_path + m_leagueName + ".hof";
	char buffer[1001];
	int seek = 0;
//	int len = f.GetLength();
	if( CFile::GetStatus( fileName, status ) == FALSE) // create file for hall of fame
	{
		CFile f( fileName, CFile::modeCreate | CFile::modeWrite );
		memset( buffer, ' ', 1000);		
		f.Write( buffer, 1000);
		f.Close();
	}
	else // increase file size
	{
	    CStdioFile f( fileName, CFile::modeWrite );
		seek =(int) f.GetLength();
		f.SetLength(seek + 1000);
		f.Seek( seek, CFile::begin);
		memset( buffer, ' ', 1000);		
		f.Write( buffer, 1000);	
		f.Close();
	}
	CStdioFile fi( fileName, CFile::modeWrite );
	fi.Seek( seek, CFile::begin);

	
	int p=1;
	do
	{
			CString string = m_hall[p].GetName();
			string.TrimLeft();
			string.TrimRight();
			CString po = m_hall[p].GetPos();
			CString pick;
			pick.Format("%-2s %-16s%-5d%-5d", po, string, m_hall[p].GetID(), m_currentYear);
			fi.WriteString(pick+"\n");		
			p = p + 1;
	}
	while(m_hall[p].GetName() != "");
	fi.Close(); 
	}
}

void CCampDlg::AdjustData()
{

	CDisk* disk = new CDisk;
	CString avg_file_name = m_path + m_leagueName + ".avg";
	disk->GetSavedAverages(avg_file_name);
	




	tMin = 0; tFgm = 0; tFga = 0; tFtm = 0; tFta = 0; tTfgm = 0; tTfga = 0; tOreb = 0; treb = 0; tAst = 0; tStl = 0; tTo = 0; tBlk = 0; tPf = 0; tTru = 0;
	
	double t_min_players_on_roster = 0;
	double t_g_players_on_roster = 0;
	double avgG = 0, avgMin = 0, hiG = 0, count = 0;
	double t_fgm = 0, t_fga = 0, t_ftm = 0, t_fta = 0, t_tfgm = 0, t_tfga = 0;
	int players = 1440;

	CPlayer* m_player = new CPlayer;

	for(int  i = 1; i <= players; ++i )
	{
			*m_player = avg.m_actual[i];


	if(m_player->GetName() != "" && m_player->GetMin() > (m_player->GetGames()*2))
	{
	
		m_player->SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	

		if(i <= 960)
		{
			t_min_players_on_roster = t_min_players_on_roster + double(m_player->GetMin());
			t_g_players_on_roster = t_g_players_on_roster + double(m_player->GetGames());
		

		
		tMin = tMin + double(m_player->GetMin());
		tFga = tFga + double(m_player->GetFga());
		tFta = tFta + double(m_player->GetFta());
		tTfga = tTfga + double(m_player->GetTfga());
		tOreb = tOreb + double(m_player->GetOreb());
		treb = treb + double(m_player->GetReb());
		tAst = tAst + double(m_player->GetAst());
		tStl = tStl + double(m_player->GetStl());
		tTo = tTo + double(m_player->GetTo());
		tBlk = tBlk + double(m_player->GetBlk());
		tPf = tPf + double(m_player->GetPf());
		m_player->SetTrueRatingSimple(ACTUAL);
		tTru = tTru + m_player->GetTrueRatingSimple();
		if(m_player->GetGames() > hiG) hiG = m_player->GetGames();
		count = count + 1;
		avgG = avgG + double(m_player->GetGames());
		avgMin = avgMin + double(m_player->GetMin());
		t_fgm = t_fgm + double(m_player->GetFgm());
		t_fga = t_fga + double(m_player->GetFga());
		t_ftm = t_ftm + double(m_player->GetFtm());
		t_fta = t_fta + double(m_player->GetFta());
		t_tfgm = t_tfgm + double(m_player->GetTfgm());
		t_tfga = t_tfga + double(m_player->GetTfga());
		}

		}

	}

	delete m_player;

	if(t_fga == 0) t_fga = 1;
	if(t_fta == 0) t_fta = 1;
	if(t_tfga == 0) t_tfga = 1;

	double old_fgp = disk->avg.m_avg_fgp_t[0];
	double old_ftp = disk->avg.m_avg_ftp[0];
	double old_tgp = disk->avg.m_avg_tgp[0];

	double t_g = avgG;
	avgG = (double)t_g / (double)count;

	//avgMin = double(tMin) / double(t_g); //? put back
	avgMin = t_min_players_on_roster / t_g_players_on_roster;

	
	double avgFgPct = old_fgp / (t_fgm / t_fga * 100);
	double avgFtPct = old_ftp / (t_ftm / t_fta * 100);
	double avgTfgPct = old_tgp / (t_tfgm / t_tfga * 100);
	double avgGameFactor = 70 / avgG;


	tFga = disk->avg.m_avg_fga_t[0] / (tFga/tMin*48);
	tFta = disk->avg.m_avg_fta[0] / (tFta/tMin*48);
	tTfga = disk->avg.m_avg_tga[0] / (tTfga/tMin*48);
	tOreb = disk->avg.m_avg_orb[0] / (tOreb/tMin*48);
	treb = (disk->avg.m_avg_orb[0] + disk->avg.m_avg_drb[0])/ (treb/tMin*48);
	tAst  = disk->avg.m_avg_ast[0] / (tAst /tMin*48);
	tStl  = disk->avg.m_avg_stl[0] / (tStl /tMin*48);
	tTo   = disk->avg.m_avg_to[0] / (tTo  /tMin*48);
	tBlk  = disk->avg.m_avg_blk[0] / (tBlk /tMin*48);
	tPf   = disk->avg.m_avg_pf[0] / (tPf  /tMin*48);

	avgMin = disk->avg.m_avg_min[0] / avgMin;

	delete disk;

	//avgMin = 1;//temp
	double orig_avg_min = avgMin;
	double fgPct = 0, ftPct = 0, tfgPct = 0;
	for(int i=1; i<=players; i++)
	{
		bool hasName = (avg.m_actual[i].GetName() != "");
		int pot = avg.m_actual[i].GetPot1();
		int g = avg.m_actual[i].GetGames();
		int min = avg.m_actual[i].GetMin();
		int fgm = avg.m_actual[i].GetFgm();
		int fga = avg.m_actual[i].GetFga();
		int ftm = avg.m_actual[i].GetFtm();
		int fta = avg.m_actual[i].GetFta();
		int tfgm = avg.m_actual[i].GetTfgm();
		int tfga = avg.m_actual[i].GetTfga();
		int oreb = avg.m_actual[i].GetOreb();
		int reb = avg.m_actual[i].GetReb();
		int ast = avg.m_actual[i].GetAst();
		int stl = avg.m_actual[i].GetStl();
		int to = avg.m_actual[i].GetTo();
		int blk = avg.m_actual[i].GetBlk();
		int pf = avg.m_actual[i].GetPf();
		if(fga == 0) fgPct = 0; else
		fgPct = double(fgm)/double(fga) * avgFgPct;
		if(fta == 0) ftPct = 0; else
		ftPct = double(ftm)/double(fta) * avgFtPct;
		if(tfga == 0) tfgPct = 0; else
		tfgPct = double(tfgm)/double(tfga) * avgTfgPct;
	    if(tfgPct>.45) tfgPct = double(450 + avg.IntRandom(10*int(pot))) / 1000.;



		g = int(double(g*avgGameFactor)) + avg.IntRandom(2) - 1;
		if(g > 82) g = 82;

		avgMin = 	orig_avg_min * avgGameFactor;

        if(hasName == true)
		{
			min = int(min*avgMin) + avg.IntRandom(2) - 1;
		}

        if(hasName == true) fga = int((double)fga*tFga*avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) fta = int((double)fta*tFta*avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) tfga = int((double)tfga*tTfga*avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) fgm = int(fgPct*(double)fga) + avg.IntRandom(2) - 1;
        if(hasName == true) ftm = int(ftPct*(double)fta) + avg.IntRandom(2) - 1;
        if(hasName == true) tfgm = int(tfgPct*(double)tfga) + avg.IntRandom(2) - 1;
        if(hasName == true) oreb = int((double)oreb*tOreb*avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) reb = int((double)reb*treb*avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) ast = int((double)ast *tAst *avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) stl = int((double)stl *tStl *avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) to  = int((double)to  *tTo  *avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) blk = int((double)blk *tBlk *avgMin) + avg.IntRandom(2) - 1;
        if(hasName == true) pf  = int((double)pf  *tPf *avgMin ) + avg.IntRandom(2) - 1;

		if(tfga <= 2 && t_fgm >= 1) tfgm = 0;

		int min_orb = int(double(avg.m_actual[i].GetMin())*1/120);
		if(min_orb > oreb) oreb = min_orb;
		int min_dreb = int(double(avg.m_actual[i].GetMin())*1/60);
		if(min_dreb > (reb - oreb)) reb = min_dreb + oreb;
		int min_stl = int(double(avg.m_actual[i].GetMin())*1/100);
		if(min_stl > stl) stl = min_stl;
		int min_ast = int(double(avg.m_actual[i].GetMin())*1/240);
		if(min_ast > ast) ast = min_stl;
		int min_to = int(double(avg.m_actual[i].GetMin())*1/48);
		if(min_to > to) ast = min_to;
		int min_blk = int(double(avg.m_actual[i].GetMin())*1/1200);
		if(min_blk > blk) blk = min_blk;

		avg.m_actual[i].SetGames(g);
		avg.m_actual[i].SetMin(min);
		avg.m_actual[i].SetFgm(fgm);
		avg.m_actual[i].SetFga(fga);
		avg.m_actual[i].SetFtm(ftm);
		avg.m_actual[i].SetFta(fta);
		avg.m_actual[i].SetTfgm(tfgm);
		avg.m_actual[i].SetTfga(tfga);
		

		avg.m_actual[i].SetOreb(oreb);
		avg.m_actual[i].SetReb(reb);
		avg.m_actual[i].SetAst(ast);
		avg.m_actual[i].SetStl(stl);
		avg.m_actual[i].SetTo(to);
		avg.m_actual[i].SetBlk(blk);
		avg.m_actual[i].SetPf(pf);
		avg.m_actual[i].SetGames(g);
		avg.m_actual[i].SetMin(min);
		
		avg.m_actual[i].SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	

	
	}

}

HBRUSH CCampDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
//          pDC->SetBkColor(LISTBOXCOLOR);
//          pDC->SetTextColor(LISTBOXTEXTCOLOR);
 //         return myBrush;

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

void CCampDlg::OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listTeams.GetCurSel();
	int j = m_listPlayers.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	if(i >= 0 && j > 0)
	{

	//CPlayer m_player = FA[i+1];


	//int players_listed = m_listfa.GetItemCount();
	//int tm = m_player.m_team_index - 1;
	
	//CString team = "";
	//if(tm < 0) team = "";
	//else team = avg.m_settings.m_leagueTeamNames[tm];


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = i;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Coach";
	scout->avg = avg;


	int count = 1;
	for(int c=0; c<=29; c++)
	{
		if(Rookies[i*30+c].m_name != "")
		{
			scout->avg.m_actual[count] = Rookies[i*30+c];
			count = count + 1;
		}
	}
		


	scout->m_player_index = j;
	scout->m_pl_index_end = 15;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}
	*pResult = 0;

}



void CCampDlg::OnSelchangeComboDraftteams() 
{

	// TODO: Add your control notification handler code here
	ListControl();
	if(m_ratings_view == 1) SortByPosition();	
	else if(m_ratings_view == 2) SortByProgress();	
	
}

void CCampDlg::OnRadioCoach() 
{
	// TODO: Add your control notification handler code here
	m_ratings_view = 1;
	m_listPlayers.DeleteAllItems();
	ListRookies();
	
}

void CCampDlg::OnRadioScout() 
{
	// TODO: Add your control notification handler code here
	m_ratings_view = 2;
	m_listPlayers.DeleteAllItems();
	ListProgress();
	
}

void CCampDlg::ListProgress()
{
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = 0;
	int offset = team*30;
	int pl = 0;
for(int l = 0; l <= 29; l++)
{
	int change[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int player = offset +  l;
	CPlayer* m_player = new CPlayer;
	*m_player = Rookies[player];
	//player->SetOldRatings();
	m_player->SetAdjustedRatings(avg.m_coach[team]);	
	m_player->SetAdjustedOldRatings(avg.m_coach[team], true);	


//	m_player->SetRatingsChange(change);
	change[0] = m_player->m_oldprFga;
	change[1] = m_player->m_oldprFgp;
	change[2] = m_player->m_oldprFta;
	change[3] = m_player->m_oldprFtp;
	change[4] = m_player->m_oldprTga;
	change[5] = m_player->m_oldprTgp;
	change[6] = m_player->m_oldprOrb;
	change[7] = m_player->m_oldprDrb;
	change[8] = m_player->m_oldprAst;
	change[9] = m_player->m_oldprStl;
	change[10] = m_player->m_oldprTo;
	change[11] = m_player->m_oldprBlk;
	change[12] = m_player->m_oldmovoff;
	change[13] = m_player->m_oldpenoff;
	change[14] = m_player->m_oldpostoff;
	change[15] = m_player->m_oldtransoff;
	change[16] = m_player->m_oldmovdef;
	change[17] = m_player->m_oldpendef;
	change[18] = m_player->m_oldpostdef;
	change[19] = m_player->m_oldtransdef;


	



	CString pos = m_player->GetPos();
	CString name = m_player->GetName();
	if(name == "") continue;
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD, Age;
	int ag = m_player->GetAge();
	Age.Format("%d", ag);
	int o = m_player->GetMovOff();
	OutO.Format("%d", o);
	int p = m_player->GetPenOff();
	PenO.Format("%d", p);
	int i = m_player->GetPostOff();
	PostO.Format("%d", i);
	int f = m_player->GetTransOff();
	TransO.Format("%d", f);
	int od = m_player->GetMovDef();
	OutD.Format("%d", od);
	int pd = m_player->GetPenDef();
	PenD.Format("%d", pd);
	int id = m_player->GetPostDef();
	PostD.Format("%d", id);
	int fd = m_player->GetTransDef();
	TransD.Format("%d", fd);


	m_listPlayers.InsertItem(pl,pos);
	m_listPlayers.SetItemText(pl,1,name);
	m_listPlayers.SetItemText(pl,2,Age);
	
    Rookies[player].SetAdjTrueRatingSimple(m_player->GetFgm(), m_player->GetFga(), m_player->GetTfgm(), m_player->GetTfga(), m_player->GetFtm(),  m_player->GetFta(), m_player->GetOreb(),  m_player->GetReb(), m_player->GetAst(), m_player->GetStl(), m_player->GetTo(), m_player->GetBlk(), avg.m_coach[team].m_scoring, avg.m_coach[team].m_shooting, avg.m_coach[team].m_rebounding, avg.m_coach[team].m_passing, avg.m_coach[team].m_defense);
	Rookies[player].SetTradeTrueRating(0);
	Rookies[player].SetAdjTradeValue(avg.m_coach[team].m_pot1, avg.m_coach[team].m_pot2, avg.m_coach[team].m_effort);



	for(int x=0; x<=19; x++)
	{
		int r = change[x];
		CString s;
		s.Format("%d", r);
		if(Rookies[player].m_yrs_of_service == 0) s = "-";
		m_listPlayers.SetItemText(pl,x+3,s);
	}

	pl = pl + 1;	


	delete m_player;
}
    m_listPlayers.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
}

void CCampDlg::SortByProgress()
{
	//switch
	/*


int team = m_listTeams.GetCurSel();
if(team < 0) team = 0;
int offset = team*30 + 1;




for(int i=offset; i<=offset+29; i++)
{



for(int j=offset; j<=offset+29; j++)
{
bool swap = false;
BOOL career = FALSE;
if(Rookies[i].m_name == "" || Rookies[j].m_name == "") continue;
switch(m_column) 
{
    case 0:
        swap = Rookies[i].GetPos() < Rookies[j].GetPos();
        break;
    case 1:
//        swap = Rookies[i].GetTradeTrueRating(career)  > Rookies[j].GetTradeTrueRating(career);
        swap = Rookies[i].GetRosterNumber()  < Rookies[j].GetRosterNumber();
        break;
    case 2:
        swap = Rookies[i].GetAge() > Rookies[j].GetAge();
        break;
    case 3:
        swap = Rookies[i].m_oldprFga > Rookies[j].m_oldprFga;
        break;
    case 4:
        swap = Rookies[i].m_oldprFgp > Rookies[j].m_oldprFgp;
        break;
    case 5:
        swap = Rookies[i].m_oldprFta > Rookies[j].m_oldprFta;
        break;
    case 6:
        swap = Rookies[i].m_oldprFtp > Rookies[j].m_oldprFgp;
        break;
    case 7:
        swap = Rookies[i].m_oldprTga > Rookies[j].m_oldprTga;
        break;
    case 8:
        swap = Rookies[i].m_oldprTgp > Rookies[j].m_oldprTgp;
        break;
    case 9:
        swap = Rookies[i].m_oldprOrb > Rookies[j].m_oldprOrb;
        break;
    case 10:
        swap = Rookies[i].m_oldprDrb > Rookies[j].m_oldprDrb;
        break;
    case 11:
        swap = Rookies[i].m_oldprAst > Rookies[j].m_oldprAst;
        break;
    case 12:
        swap = Rookies[i].m_oldprStl > Rookies[j].m_oldprStl;
        break;
    case 13:
        swap = Rookies[i].m_oldprTo > Rookies[j].m_oldprTo;
        break;
    case 14:
        swap = Rookies[i].m_oldprBlk > Rookies[j].m_oldprBlk;
        break;
    case 15:
        swap = Rookies[i].m_oldmovoff > Rookies[j].m_oldmovoff;
        break;
    case 19:
        swap = Rookies[i].m_oldmovdef > Rookies[j].m_oldmovdef;
        break;
    case 16:
        swap = Rookies[i].m_oldpenoff > Rookies[j].m_oldpenoff;
        break;
    case 20:
        swap = Rookies[i].m_oldpendef > Rookies[j].m_oldpendef;
        break;
    case 17:
        swap = Rookies[i].m_oldpostoff > Rookies[j].m_oldpostoff;
        break;
    case 21:
        swap = Rookies[i].m_oldpostdef > Rookies[j].m_oldpostdef;
        break;
    case 18:
        swap = Rookies[i].m_oldtransoff > Rookies[j].m_oldtransoff;
        break;
    case 22:
        swap = Rookies[i].m_oldtransdef > Rookies[j].m_oldtransdef;
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
*/

m_listPlayers.DeleteAllItems();

ListProgress();
}
