// AllTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "MyComboBox.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"

#include "AllTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllTimeDlg dialog


CAllTimeDlg::CAllTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllTimeDlg)
	//}}AFX_DATA_INIT
	m_offset = 0;
	m_default_team = 0;
}


void CAllTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllTimeDlg)
	DDX_Control(pDX, IDC_LIST7, m_listCtrlLeaders7);
	DDX_Control(pDX, IDC_LIST6, m_listCtrlLeaders6);
	DDX_Control(pDX, IDC_LIST5, m_listCtrlLeaders5);
	DDX_Control(pDX, IDC_LIST4, m_listCtrlLeaders4);
	DDX_Control(pDX, IDC_LIST3, m_listCtrlLeaders3);
	DDX_Control(pDX, IDC_LIST1, m_listCtrlLeaders2);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_LIST_LEADERS1, m_listCtrlLeaders1);
	DDX_Control(pDX, IDC_LIST_LEADERS, m_listCtrlLeaders);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CAllTimeDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_SEASON, OnRadioSeason)
	ON_BN_CLICKED(IDC_RADIO_PLAYOFF, OnRadioPlayoff)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_RADIO_PLAYOFF2, OnRadioPlayoff2)
	ON_BN_CLICKED(IDC_RADIO_SEASON2, OnRadioSeason2)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_LEADERS, OnDblclkListLeaders)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllTimeDlg message handlers

BOOL CAllTimeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitListCtrl();
 myBrush.CreateSolidBrush(DLGCOLOR); 


	m_listTeams.AddString(m_leagueName);
	for(int i=0; i<=31; i++)
	{
		if(m_leagueTeamNames[i] != "")
			m_listTeams.AddString(m_leagueTeamNames[i]);
	}

	m_listTeams.SetCurSel(m_default_team);


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 10;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
//	strcpy_s(lf.lfFaceName, "TAHOMA");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listCtrlLeaders.SetBkColor(BK_COLOR);
	m_listCtrlLeaders.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders.SetFont(&m_font);

	m_listCtrlLeaders1.SetBkColor(BK_COLOR);
	m_listCtrlLeaders1.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders1.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders1.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders1.SetFont(&m_font);

	m_listCtrlLeaders2.SetBkColor(BK_COLOR);
	m_listCtrlLeaders2.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders2.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders2.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders2.SetFont(&m_font);

	m_listCtrlLeaders3.SetBkColor(BK_COLOR);
	m_listCtrlLeaders3.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders3.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders3.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders3.SetFont(&m_font);

	m_listCtrlLeaders4.SetBkColor(BK_COLOR);
	m_listCtrlLeaders4.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders4.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders4.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders4.SetFont(&m_font);

	m_listCtrlLeaders5.SetBkColor(BK_COLOR);
	m_listCtrlLeaders5.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders5.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders5.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders5.SetFont(&m_font);

	m_listCtrlLeaders6.SetBkColor(BK_COLOR);
	m_listCtrlLeaders6.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders6.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders6.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders6.SetFont(&m_font);

	m_listCtrlLeaders7.SetBkColor(BK_COLOR);
	m_listCtrlLeaders7.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlLeaders7.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
    m_listCtrlLeaders7.SetTextColor(RGB(0,0,0));
	m_listCtrlLeaders7.SetFont(&m_font);



	SetHeaders();


	CheckDlgButton(IDC_RADIO_SEASON, 1);	
	//if(m_offset == 33000) CheckDlgButton(IDC_RADIO_PLAYOFF, 1);
	OnSelchangeComboTeams();




	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllTimeDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	

}

void CAllTimeDlg::OnRadioSeason() 
{
	// TODO: Add your control notification handler code here

	m_type = 0;
	ListSeasonHighs();

	
}

void CAllTimeDlg::OnRadioPlayoff() 
{
	// TODO: Add your control notification handler code here
	m_type = 0;
	ListPlayoffHighs();

	
}

BOOL CAllTimeDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/teamrecords.htm", HH_DISPLAY_TOPIC, 0);
	
	return TRUE;
}

void CAllTimeDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here

	//HtmlHelp(NULL, "jumpshot.chm::/html/teamrecords.htm", HH_DISPLAY_TOPIC, 0);


//	WinHelp(HID_STATS_RECORDS);	
}

void CAllTimeDlg::OnRadioPlayoff2() 
{
	// TODO: Add your control notification handler code here
	m_type = 1;
	ListPlayoffHighs();

	
	
}

void CAllTimeDlg::OnRadioSeason2() 
{
	// TODO: Add your control notification handler code here
	m_type = 1;
	ListSeasonHighs();

	
	
}

HBRUSH CAllTimeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
}

void CAllTimeDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	if(m_playoff == true)
		ListPlayoffHighs();
	else
		ListSeasonHighs();

	
}

void CAllTimeDlg::InitListCtrl()
{
		 // Set some color effect
        //COLORREF crStandard = ::GetSysColor(COLOR_BTNFACE);
		COLORREF InactiveButton = (RGB(235,182,101));
		COLORREF ActiveButton = (RGB(239,198,135));
		COLORREF InactiveFont = (RGB(0,0,0));
		COLORREF ActiveFont = (RGB(46,35,18));
	
		m_type = 0;
		m_playoff = false;
//		m_button_ok.SetInactiveBgColor(InactiveButton);
  //      m_button_ok.SetActiveBgColor(ActiveButton);
   //     m_button_ok.SetInactiveFgColor(InactiveFont);
    //    m_button_ok.SetActiveFgColor(ActiveFont);
     //   m_button_ok.SetBtnCursor(IDC_CURSOR);
     //   m_button_ok.SetTooltipText(IDS_TT_OK);
		//m_button_ok.SetIcon(IDI_ICON32);

}

void CAllTimeDlg::ListSeasonHighs()
{
	m_playoff = false;
	m_listCtrlLeaders.DeleteAllItems();
	m_listCtrlLeaders1.DeleteAllItems();
	m_listCtrlLeaders2.DeleteAllItems();
	m_listCtrlLeaders3.DeleteAllItems();
	m_listCtrlLeaders4.DeleteAllItems();
	m_listCtrlLeaders5.DeleteAllItems();
	m_listCtrlLeaders6.DeleteAllItems();
	m_listCtrlLeaders7.DeleteAllItems();
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = m_default_team; //whole league
	CString name;
	CString number;
	CString year;
	for(int p=0; p<=9; p++)
	{
		CString name = high.m_g_name[m_type][team][p][0];
		number.Format("%d", high.m_g_amt[m_type][team][p][0]);
		year.Format("%d", high.m_g_ye[m_type][team][p][0]);
		m_listCtrlLeaders.InsertItem(p,name);
		m_listCtrlLeaders.SetItemText(p,1,number);
		m_listCtrlLeaders.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][1];
		number.Format("%d", high.m_g_amt[m_type][team][p][1]);
		year.Format("%d", high.m_g_ye[m_type][team][p][1]);
		m_listCtrlLeaders1.InsertItem(p,name);
		m_listCtrlLeaders1.SetItemText(p,1,number);
		m_listCtrlLeaders1.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][2];
		number.Format("%d", high.m_g_amt[m_type][team][p][2]);
		year.Format("%d", high.m_g_ye[m_type][team][p][2]);
		m_listCtrlLeaders2.InsertItem(p,name);
		m_listCtrlLeaders2.SetItemText(p,1,number);
		m_listCtrlLeaders2.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][3];
		number.Format("%d", high.m_g_amt[m_type][team][p][3]);
		year.Format("%d", high.m_g_ye[m_type][team][p][3]);
		m_listCtrlLeaders3.InsertItem(p,name);
		m_listCtrlLeaders3.SetItemText(p,1,number);
		m_listCtrlLeaders3.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][4];
		number.Format("%d", high.m_g_amt[m_type][team][p][4]);
		year.Format("%d", high.m_g_ye[m_type][team][p][4]);
		m_listCtrlLeaders4.InsertItem(p,name);
		m_listCtrlLeaders4.SetItemText(p,1,number);
		m_listCtrlLeaders4.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][5];
		number.Format("%d", high.m_g_amt[m_type][team][p][5]);
		year.Format("%d", high.m_g_ye[m_type][team][p][5]);
		m_listCtrlLeaders5.InsertItem(p,name);
		m_listCtrlLeaders5.SetItemText(p,1,number);
		m_listCtrlLeaders5.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][6];
		number.Format("%d", high.m_g_amt[m_type][team][p][6]);
		year.Format("%d", high.m_g_ye[m_type][team][p][6]);
		m_listCtrlLeaders6.InsertItem(p,name);
		m_listCtrlLeaders6.SetItemText(p,1,number);
		m_listCtrlLeaders6.SetItemText(p,2,year);

		name = high.m_g_name[m_type][team][p][7];
		number.Format("%d", high.m_g_amt[m_type][team][p][7]);
		year.Format("%d", high.m_g_ye[m_type][team][p][7]);
		m_listCtrlLeaders7.InsertItem(p,name);
		m_listCtrlLeaders7.SetItemText(p,1,number);
		m_listCtrlLeaders7.SetItemText(p,2,year);


	}	
}

void CAllTimeDlg::ListPlayoffHighs()
{
	m_playoff = true;
	m_listCtrlLeaders.DeleteAllItems();
	m_listCtrlLeaders1.DeleteAllItems();
	m_listCtrlLeaders2.DeleteAllItems();
	m_listCtrlLeaders3.DeleteAllItems();
	m_listCtrlLeaders4.DeleteAllItems();
	m_listCtrlLeaders5.DeleteAllItems();
	m_listCtrlLeaders6.DeleteAllItems();
	m_listCtrlLeaders7.DeleteAllItems();
	int team = m_listTeams.GetCurSel();
	if(team < 0) team = m_default_team; //whole league
	CString name;
	CString number;
	CString year;
	for(int p=0; p<=9; p++)
	{
		name = high.m_g_po_name[m_type][team][p][0];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][0]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][0]);
		m_listCtrlLeaders.InsertItem(p,name);
		m_listCtrlLeaders.SetItemText(p,1,number);
		m_listCtrlLeaders.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][1];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][1]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][1]);
		m_listCtrlLeaders1.InsertItem(p,name);
		m_listCtrlLeaders1.SetItemText(p,1,number);
		m_listCtrlLeaders1.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][2];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][2]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][2]);
		m_listCtrlLeaders2.InsertItem(p,name);
		m_listCtrlLeaders2.SetItemText(p,1,number);
		m_listCtrlLeaders2.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][3];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][3]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][3]);
		m_listCtrlLeaders3.InsertItem(p,name);
		m_listCtrlLeaders3.SetItemText(p,1,number);
		m_listCtrlLeaders3.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][4];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][4]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][4]);
		m_listCtrlLeaders4.InsertItem(p,name);
		m_listCtrlLeaders4.SetItemText(p,1,number);
		m_listCtrlLeaders4.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][5];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][5]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][5]);
		m_listCtrlLeaders5.InsertItem(p,name);
		m_listCtrlLeaders5.SetItemText(p,1,number);
		m_listCtrlLeaders5.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][6];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][6]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][6]);
		m_listCtrlLeaders6.InsertItem(p,name);
		m_listCtrlLeaders6.SetItemText(p,1,number);
		m_listCtrlLeaders6.SetItemText(p,2,year);

		name = high.m_g_po_name[m_type][team][p][7];
		number.Format("%d", high.m_g_po_amt[m_type][team][p][7]);
		year.Format("%d", high.m_g_po_ye[m_type][team][p][7]);
		m_listCtrlLeaders7.InsertItem(p,name);
		m_listCtrlLeaders7.SetItemText(p,1,number);
		m_listCtrlLeaders7.SetItemText(p,2,year);


	}		

}

void CAllTimeDlg::OnDblclkListLeaders(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CAllTimeDlg::SetHeaders()
{
  m_listCtrlLeaders.InsertColumn(0,"Points");
    m_listCtrlLeaders.InsertColumn(1,"#");
    m_listCtrlLeaders.InsertColumn(2,"");
    //m_listCtrlLeaders.InsertColumn(3,"");
    m_listCtrlLeaders.SetColumnWidth( 0, 104);
    m_listCtrlLeaders.SetColumnWidth( 1, 32);
    m_listCtrlLeaders.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders.SetColumnWidth( 3, 32);

    m_listCtrlLeaders1.InsertColumn(0,"Rebounds");
    m_listCtrlLeaders1.InsertColumn(1,"#");
    m_listCtrlLeaders1.InsertColumn(2,"");
    //m_listCtrlLeaders1.InsertColumn(3,"");
    m_listCtrlLeaders1.SetColumnWidth( 0, 104);
    m_listCtrlLeaders1.SetColumnWidth( 1, 32);
    m_listCtrlLeaders1.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders1.SetColumnWidth( 3, 32);

    m_listCtrlLeaders2.InsertColumn(0,"Assists");
    m_listCtrlLeaders2.InsertColumn(1,"#");
    m_listCtrlLeaders2.InsertColumn(2,"");
    //m_listCtrlLeaders2.InsertColumn(3,"");
    m_listCtrlLeaders2.SetColumnWidth( 0, 104);
    m_listCtrlLeaders2.SetColumnWidth( 1, 32);
    m_listCtrlLeaders2.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders2.SetColumnWidth( 3, 32);

    m_listCtrlLeaders3.InsertColumn(0,"Steals");
    m_listCtrlLeaders3.InsertColumn(1,"#");
    m_listCtrlLeaders3.InsertColumn(2,"");
    //m_listCtrlLeaders3.InsertColumn(3,"");
    m_listCtrlLeaders3.SetColumnWidth( 0, 104);
    m_listCtrlLeaders3.SetColumnWidth( 1, 32);
    m_listCtrlLeaders3.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders3.SetColumnWidth( 3, 32);

    m_listCtrlLeaders4.InsertColumn(0,"Blocks");
    m_listCtrlLeaders4.InsertColumn(1,"#");
    m_listCtrlLeaders4.InsertColumn(2,"");
    //m_listCtrlLeaders4.InsertColumn(3,"");
    m_listCtrlLeaders4.SetColumnWidth( 0, 104);
    m_listCtrlLeaders4.SetColumnWidth( 1, 32);
    m_listCtrlLeaders4.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders4.SetColumnWidth( 3, 32);

    m_listCtrlLeaders5.InsertColumn(0,"Field Goals");
    m_listCtrlLeaders5.InsertColumn(1,"#");
    m_listCtrlLeaders5.InsertColumn(2,"");
    //m_listCtrlLeaders5.InsertColumn(3,"");
    m_listCtrlLeaders5.SetColumnWidth( 0, 104);
    m_listCtrlLeaders5.SetColumnWidth( 1, 32);
    m_listCtrlLeaders5.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders5.SetColumnWidth( 3, 32);

    m_listCtrlLeaders6.InsertColumn(0,"Threes");
    m_listCtrlLeaders6.InsertColumn(1,"#");
    m_listCtrlLeaders6.InsertColumn(2,"");
    //m_listCtrlLeaders6.InsertColumn(3,"");
    m_listCtrlLeaders6.SetColumnWidth( 0, 104);
    m_listCtrlLeaders6.SetColumnWidth( 1, 32);
    m_listCtrlLeaders6.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders6.SetColumnWidth( 3, 32);

    m_listCtrlLeaders7.InsertColumn(0,"Free Throws");
    m_listCtrlLeaders7.InsertColumn(1,"#");
    m_listCtrlLeaders7.InsertColumn(2,"");
    //m_listCtrlLeaders7.InsertColumn(3,"");
    m_listCtrlLeaders7.SetColumnWidth( 0, 104);
    m_listCtrlLeaders7.SetColumnWidth( 1, 32);
    m_listCtrlLeaders7.SetColumnWidth( 2, 64);
    //m_listCtrlLeaders7.SetColumnWidth( 3, 32);
}
