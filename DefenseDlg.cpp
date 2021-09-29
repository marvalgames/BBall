// DefenseDlg.cpp : implementation file
//



#include "stdafx.h"
#include "bball.h"
#include "DefenseDlg.h"
#include "PlayerCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDefenseDlg dialog


CDefenseDlg::CDefenseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDefenseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDefenseDlg)
	m_teamName = _T("");
	//}}AFX_DATA_INIT
}


void CDefenseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDefenseDlg)
	DDX_Control(pDX, IDC_LIST_SG, m_listSg);
	DDX_Control(pDX, IDC_LIST_SF, m_listSf);
	DDX_Control(pDX, IDC_LIST_PF, m_listPf);
	DDX_Control(pDX, IDC_LIST_C, m_listC);
	DDX_Control(pDX, IDC_LIST_PG, m_listPg);
	DDX_Control(pDX, IDC_LIST_CTRL_OFFENSE, m_listCtrlDef);
	DDX_Control(pDX, IDC_LIST_CTRL_DEFENSE, m_listCtrlOff);
	DDX_Control(pDX, IDC_LIST_DEFENSE, m_listDefense);
	DDX_Control(pDX, IDC_LIST_OFFENSE, m_listOffense);
	DDX_Control(pDX, IDC_BUTTON_VISITOR, m_buttonVisitor);
	DDX_Control(pDX, IDC_BUTTON_HOME, m_buttonHome);
	DDX_Text(pDX, IDC_EDIT_TEAM_NAME, m_teamName);
	DDV_MaxChars(pDX, m_teamName, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDefenseDlg, CDialog)
	//{{AFX_MSG_MAP(CDefenseDlg)
	ON_BN_CLICKED(IDC_BUTTON_HOME, OnButtonHome)
	ON_BN_CLICKED(IDC_BUTTON_VISITOR, OnButtonVisitor)
	ON_LBN_DBLCLK(IDC_LIST_DEFENSE, OnDblclkListDefense)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_OFFENSE, OnDblclkListCtrlOffense)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_DEFENSE, OnDblclkListCtrlDefense)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDefenseDlg message handlers

BOOL CDefenseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	myBrush.CreateSolidBrush(DLGCOLOR); 
	FillLists();
	m_buttonHome.SetWindowText(m_home);
	m_buttonVisitor.SetWindowText(m_visitor);
	

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 20;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font1.CreateFontIndirect(&lf);    // Create the font.


	m_listPg.SetFont(&m_font1);
	m_listSg.SetFont(&m_font1);
	m_listSf.SetFont(&m_font1);
	m_listPf.SetFont(&m_font1);
	m_listC.SetFont(&m_font1);

	m_listCtrlOff.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listCtrlDef.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listCtrlOff.SetFont(&m_font);
	m_listCtrlDef.SetFont(&m_font);

    m_listCtrlOff.InsertColumn(0,"Pos");    
    m_listCtrlOff.InsertColumn(1,"Offense");
    m_listCtrlOff.InsertColumn(2,"O");
    m_listCtrlOff.InsertColumn(3,"D");
    m_listCtrlOff.InsertColumn(4,"P");
    m_listCtrlOff.InsertColumn(5,"T");
  
    m_listCtrlDef.InsertColumn(0,"Pos");    
    m_listCtrlDef.InsertColumn(1,"Defense");
    m_listCtrlDef.InsertColumn(2,"O");
    m_listCtrlDef.InsertColumn(3,"D");
    m_listCtrlDef.InsertColumn(4,"P");
    m_listCtrlDef.InsertColumn(5,"T");
  
	
    m_listCtrlOff.SetColumnWidth( 0, 42);
    m_listCtrlOff.SetColumnWidth( 1, 96);
    m_listCtrlOff.SetColumnWidth( 2, 28);
    m_listCtrlOff.SetColumnWidth( 3, 28);
    m_listCtrlOff.SetColumnWidth( 4, 28);
    m_listCtrlOff.SetColumnWidth( 5, 28);
    m_listCtrlDef.SetColumnWidth( 0, 42);
    m_listCtrlDef.SetColumnWidth( 1, 96);
    m_listCtrlDef.SetColumnWidth( 2, 28);
    m_listCtrlDef.SetColumnWidth( 3, 28);
    m_listCtrlDef.SetColumnWidth( 4, 28);
    m_listCtrlDef.SetColumnWidth( 5, 28);
    
	m_listCtrlOff.SetBkColor(BK_COLOR);
    m_listCtrlOff.SetTextBkColor(TEXT_BK_COLOR);
    m_listCtrlOff.SetTextColor(RGB(0,0,0));

	m_listCtrlDef.SetBkColor(BK_COLOR);
    m_listCtrlDef.SetTextBkColor(TEXT_BK_COLOR);
    m_listCtrlDef.SetTextColor(RGB(0,0,0));

	m_listCtrlOff.SetFont(&m_font);
	m_listCtrlDef.SetFont(&m_font);


	m_team = m_possesion;
	if(m_possesion == 2) 
	{
		MatchupSelections(6);
		OnButtonHome();
	}
	else
	{
		MatchupSelections(1);	
		OnButtonVisitor();	
	}
	DisplayReport();
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDefenseDlg::OnButtonHome() 
{
	// TODO: Add your control notification handler code here
	m_team = 2;
	m_teamName = m_visitor;
	DisplayMatchups();	
	DisplayReport();
	MatchupSelections(6);
	SetMatchArray(6);
	m_buttonHome.SetFocus();  		
}

void CDefenseDlg::OnButtonVisitor() 
{
	// TODO: Add your control notification handler code here
	m_team = 1;
	m_teamName = m_home;
	DisplayMatchups();
	DisplayReport();
	MatchupSelections(1);
	SetMatchArray(1);
	m_buttonVisitor.SetFocus();
}

void CDefenseDlg::DisplayMatchups()
{
	CString posNames[6] = {"","PG ","SG ","SF ","PF "," C "};
	int opp = m_team;
	m_listOffense.ResetContent();
	m_listDefense.ResetContent();
	m_listCtrlOff.DeleteAllItems();
	m_listCtrlDef.DeleteAllItems();
	for(int p=1; p<=5; p++)
	{
		int player = Lineup[opp][p];
		int defender = Defense[opp][p];

		CString nameOff = avg.m_actual[player].GetName();
		CString nameDef = avg.m_actual[defender].GetName();
		CString posOff = avg.m_actual[player].GetPos();
		CString posDef = avg.m_actual[defender].GetPos();
		m_listOffense.AddString(posNames[p] + nameOff);
		m_listDefense.AddString(posNames[p] + nameDef);

	}
	m_listOffense.SetCurSel(m_index);
	m_listDefense.SetCurSel(m_other_index);
	UpdateData(FALSE);
}



void CDefenseDlg::OnDblclkListDefense() 
{
	// TODO: Add your control notification handler code here
	CString posNames[5] = {"PG ","SG ","SF ","PF "," C "};
	int p = m_listOffense.GetCurSel()+1;
	int d = m_listDefense.GetCurSel()+1;
	if(p >= 1 && d >= 1)
	{
		int temp1 = Defense[m_team][p];
		int temp2 = Defense[m_team][d];
		Defense[m_team][d] = temp1;
		Defense[m_team][p] = temp2;

		CString name1, name2;
		m_listDefense.GetText(p-1, name1);
		m_listDefense.GetText(d-1, name2);
		m_listDefense.DeleteString(p-1);
		m_listDefense.InsertString(p-1, name2);		
		m_listDefense.DeleteString(d-1);
		m_listDefense.InsertString(d-1, name1);
		m_listDefense.SetCurSel(d-1);
	}
	DisplayReport();
}

void CDefenseDlg::DisplayReport()
{
	
	m_listCtrlOff.DeleteAllItems();
	m_listCtrlDef.DeleteAllItems();
	for(int p=1; p<=5; p++)
	{
		int player = Lineup[m_team][p];
		int defender = Defense[m_team][p];
		CString posOff = avg.m_actual[player].GetPos();
		CString posDef = avg.m_actual[defender].GetPos();

		CString lastNameOff = avg.m_actual[player].GetLastName();
		CString lastNameDef = avg.m_actual[defender].GetLastName();
	
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD;
	int o = avg.m_actual[player].GetMovOff();
	OutO.Format("%d", o);
	int pe = avg.m_actual[player].GetPenOff();
	PenO.Format("%d", pe);
	int i = avg.m_actual[player].GetPostOff();
	PostO.Format("%d", i);
	int f = avg.m_actual[player].GetTransOff();
	TransO.Format("%d", f);


	int od = avg.m_actual[defender].GetMovDef();
	OutD.Format("%d", od);

	int pd = avg.m_actual[defender].GetPenDef();
	PenD.Format("%d", pd);

	int id = avg.m_actual[defender].GetPostDef();
	PostD.Format("%d", id);

	int fd = avg.m_actual[defender].GetTransDef();
	TransD.Format("%d", fd);
	
	m_listCtrlOff.InsertItem(p-1,posOff);
	m_listCtrlOff.SetItemText(p-1,1,lastNameOff);
	m_listCtrlOff.SetItemText(p-1,2,OutO);
	m_listCtrlOff.SetItemText(p-1,3,PenO);
	m_listCtrlOff.SetItemText(p-1,4,PostO);
	m_listCtrlOff.SetItemText(p-1,5,TransO);

	m_listCtrlDef.InsertItem(p-1,posDef);
	m_listCtrlDef.SetItemText(p-1,1,lastNameDef);
	m_listCtrlDef.SetItemText(p-1,2,OutD);
	m_listCtrlDef.SetItemText(p-1,3,PenD);
	m_listCtrlDef.SetItemText(p-1,4,PostD);
	m_listCtrlDef.SetItemText(p-1,5,TransD);

	}

}

void CDefenseDlg::FillLists()
{

}


void CDefenseDlg::MatchupSelections(int start)
{
/*	m_listPg.SetTopIndex(m_match[start]);	
	m_listSg.SetTopIndex(m_match[start+1]);	
	m_listSf.SetTopIndex(m_match[start+2]);	
	m_listPf.SetTopIndex(m_match[start+3]);	
	m_listC.SetTopIndex(m_match[start+4]);	*/

	m_listPg.SetCurSel(m_match[start]);	
	m_listSg.SetCurSel(m_match[start+1]);	
	m_listSf.SetCurSel(m_match[start+2]);	
	m_listPf.SetCurSel(m_match[start+3]);	
	m_listC.SetCurSel(m_match[start+4]);	
}


void CDefenseDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_team == 2) SetMatchArray(6);
	else if(m_team == 1) SetMatchArray(1);
	
	CDialog::OnOK();
}

void CDefenseDlg::SetMatchArray(int start)
{
/*	m_match[start] = m_listPg.GetTopIndex();	
	m_match[start+1] = m_listSg.GetTopIndex();	
  	m_match[start+2] = m_listSf.GetTopIndex();	
    m_match[start+3] = m_listPf.GetTopIndex();	
 	m_match[start+4] = m_listC.GetTopIndex();*/

	m_match[start] = m_listPg.GetCurSel();	
	m_match[start+1] = m_listSg.GetCurSel();	
  	m_match[start+2] = m_listSf.GetCurSel();	
    m_match[start+3] = m_listPf.GetCurSel();	
 	m_match[start+4] = m_listC.GetCurSel();

}

void CDefenseDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_PLAYERS_DEFENSE);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/coachdefense.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

BOOL CDefenseDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default

//	HtmlHelp(NULL, "jumpshot.chm::/html/coachdefense.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);


//	WinHelp(HID_PLAYERS_DEFENSE);		
//	return TRUE;	
}

HBRUSH CDefenseDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CDefenseDlg::OnDblclkListCtrlOffense(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_listCtrlDef.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	
	if(i >= 0)
	{


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_visitor_index-1;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_title = "Coach";
	scout->avg = avg;

	for(int c=1; c<=5; c++)
	{

		int slot = Defense[m_team][c];
		CPlayer m_player = avg.m_actual[slot];
		scout->avg.m_actual[c] = m_player;
	}
	scout->m_player_index = i;
	scout->m_pl_index_end = 5;
	scout->m_pl_index_start = 1;

	scout->DoModal();
	delete scout;
	}
	
	*pResult = 0;
}

void CDefenseDlg::OnDblclkListCtrlDefense(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_listCtrlOff.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED) + 1;
	
	if(i >= 0)
	{


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = m_visitor_index-1;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_title = "Coach";
	scout->avg = avg;

	for(int c=1; c<=5; c++)
	{

		int slot = Lineup[m_team][c];
		CPlayer m_player = avg.m_actual[slot];
		scout->avg.m_actual[c] = m_player;
	}
	scout->m_player_index = i;
	scout->m_pl_index_end = 5;
	scout->m_pl_index_start = 1;

	scout->DoModal();
	delete scout;
	}
	
	*pResult = 0;
}
