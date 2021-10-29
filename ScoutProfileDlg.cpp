// ScoutProfileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"

#include "ScoutProfileDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoutProfileDlg dialog


CScoutProfileDlg::CScoutProfileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoutProfileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoutProfileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScoutProfileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoutProfileDlg)
	DDX_Control(pDX, IDC_LIST_SCOUTING, m_list_scouting);
	DDX_Control(pDX, IDC_LIST_DEVELOPMENT, m_list_development);
	DDX_Control(pDX, IDC_LIST_DATA, m_list_data);
	DDX_Control(pDX, IDC_LIST_COACHING, m_list_coaching);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoutProfileDlg, CDialog)
	//{{AFX_MSG_MAP(CScoutProfileDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnButtonEdit)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_COACHING, &CScoutProfileDlg::OnLvnItemchangedListCoaching)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoutProfileDlg message handlers


BOOL CScoutProfileDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	CString string;
	string.Format("%s of the %s  age: %d", m_scout.m_name, m_scout.m_team, m_scout.m_age);
	if(m_scout.m_team == "")
		string.Format("%s age: %d", m_scout.m_name, m_scout.m_age);
	SetWindowText(string);
	InitListCtrl();
	ListData();
	ListScouting();
	if(m_type == 2)
	{
		ListDevelopment();
		ListCoaching();
	}
	else
	{
		m_list_coaching.ShowWindow(FALSE);
		m_list_development.ShowWindow(FALSE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScoutProfileDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_SCOUT_PROFILE);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/staffprofiles.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

BOOL CScoutProfileDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_SCOUT_PROFILE);
//	return TRUE;	
//	return CDialog::OnHelpInfo(pHelpInfo);

//	HtmlHelp(NULL, "jumpshot.chm::/html/staffprofiles.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

}



void CScoutProfileDlg::InitListCtrl()
{
LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_data.SetBkColor(BK_COLOR);
	m_list_data.SetTextBkColor(TEXT_BK_COLOR);
    m_list_data.SetTextColor(RGB(0,0,0));
	m_list_data.SetFont(&m_font);

	m_list_scouting.SetBkColor(BK_COLOR);
	m_list_scouting.SetTextBkColor(TEXT_BK_COLOR);
    m_list_scouting.SetTextColor(RGB(0,0,0));
	m_list_scouting.SetFont(&m_font);

	m_list_development.SetBkColor(BK_COLOR);
	m_list_development.SetTextBkColor(TEXT_BK_COLOR);
    m_list_development.SetTextColor(RGB(0,0,0));
	m_list_development.SetFont(&m_font);

	m_list_coaching.SetBkColor(BK_COLOR);
	m_list_coaching.SetTextBkColor(TEXT_BK_COLOR);
    m_list_coaching.SetTextColor(RGB(0,0,0));
	m_list_coaching.SetFont(&m_font);
}

void CScoutProfileDlg::ListData()
{

	m_list_data.InsertColumn(0,"category");    
    m_list_data.InsertColumn(1,"rating");    

    m_list_data.SetColumnWidth( 0, 78);
    m_list_data.SetColumnWidth( 1, 112);

	CString string[99];
	CString label[99];
	label[0] = "win";
	label[1] = "loss";
	label[2] = "pct";
	label[3] = "playoffs";
	label[4] = "rings";
	label[5] = "loyalty";
	label[6] = "personality";


	CStaff m_player = m_scout;
	int win = m_player.m_win;
	int loss = m_player.m_loss;
	int games = win + loss;
	double pct = double(win)/double(games);



	if(games == 0)
		string[2] = "---";
	else 
		string[2].Format("%.3f", pct);

//	CString display[8] = {"", "Very Low", "Poor", "Below Avg","Average", "Above Avg","Good", "Excellent"};
CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};

	string[0].Format("%d", m_player.m_win);
	string[1].Format("%d", m_player.m_loss);
	string[3].Format("%d", m_player.m_playoffs);
	string[4].Format("%d", m_player.m_rings);
	string[5].Format("%s", display[m_player.m_loyalty]);
	string[6].Format("%s", display[m_player.m_personality]);

	for(int i=0; i<=6; i++)
	{
		m_list_data.InsertItem(i,label[i]);
		m_list_data.SetItemText(i,1,string[i]);
	}

}

void CScoutProfileDlg::ListScouting()
{
	CString display[8] = {"", "Very Low", "Poor", "Below Avg","Average", "Above Avg","Good", "Excellent"};
	CString display1[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};
	m_list_scouting.InsertColumn(0,"scouting");    
    m_list_scouting.InsertColumn(1,"rating");    

    m_list_scouting.SetColumnWidth( 0, 96);
    m_list_scouting.SetColumnWidth( 1, 96);

	CString string[99];
	CString label[99];
	label[0] = "talent";
	label[1] = "skill";
	label[2] = "intangibles";
	label[3] = "scoring";
	label[4] = "shooting";
	label[5] = "rebounding";
	label[6] = "ball handling";
	label[7] = "defense";
	if(m_type == 3) label[8] = "drafts by need";
	CStaff m_player = m_scout;

	

	string[0].Format("%s", display[m_player.m_pot1Rating]);
	string[1].Format("%s", display[m_player.m_pot2Rating]);
	string[2].Format("%s", display[m_player.m_effortRating]);
	string[3].Format("%s", display[m_player.m_scoringRating]);
	string[4].Format("%s", display[m_player.m_shootingRating]);
	string[5].Format("%s", display[m_player.m_reboundingRating]);
	string[6].Format("%s", display[m_player.m_passingRating]);
	string[7].Format("%s", display[m_player.m_defenseRating]);
	string[8].Format("%s", display1[m_player.m_power1]);

	for(int i=0; i<=8; i++)
	{
		if(i != 8 || m_type == 3)
		{
			m_list_scouting.InsertItem(i,label[i]);
			m_list_scouting.SetItemText(i,1,string[i]);
		}
	}
}

void CScoutProfileDlg::ListCoaching()
{
//	CString display[8] = {"", "Very Low", "Poor", "Below Avg","Average", "Above Avg","Good", "Excellent"};
CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};
	m_list_coaching.InsertColumn(0,"coaching");    
    m_list_coaching.InsertColumn(1,"offense");    
    m_list_coaching.InsertColumn(2,"defense");    

    m_list_coaching.SetColumnWidth( 0, 105);
    m_list_coaching.SetColumnWidth( 1, 105);
    m_list_coaching.SetColumnWidth( 2, 105);

	CString string[99];
	CString label[99];
	label[0] = "outside";
	label[1] = "driving";
	label[2] = "post";
	label[3] = "transition";


	CStaff m_player = m_scout;

	string[0].Format("%s", display[m_player.m_coachO]);
	string[1].Format("%s", display[m_player.m_coachP]);
	string[2].Format("%s", display[m_player.m_coachI]);
	string[3].Format("%s", display[m_player.m_coachF]);
	string[4].Format("%s", display[m_player.m_coachOD]);
	string[5].Format("%s", display[m_player.m_coachPD]);
	string[6].Format("%s", display[m_player.m_coachID]);
	string[7].Format("%s", display[m_player.m_coachFD]);

	for(int i=0; i<=3; i++)
	{
		m_list_coaching.InsertItem(i,label[i]);
		m_list_coaching.SetItemText(i,1,string[i]);
		m_list_coaching.SetItemText(i,2,string[i+4]);
	}
}

void CScoutProfileDlg::ListDevelopment()
{
//	CString display[8] = {"", "Very Low", "Poor", "Below Avg","Average", "Above Avg","Good", "Excellent"};
CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};

	m_list_development.InsertColumn(0,"development");    
    m_list_development.InsertColumn(1,"rating");    

    m_list_development.SetColumnWidth( 0, 72);
    m_list_development.SetColumnWidth( 1, 64);

	CString string[99];
	CString label[99];
	label[0] = "talent";
	label[1] = "skill";
	label[2] = "intangibles";
	label[3] = "scoring";
	label[4] = "shooting";
	label[5] = "rebounding";
	label[6] = "ball handling";
	label[7] = "defense";
	label[8] = "conditioning";
	label[9] = "patience";
	CStaff m_player = m_scout;

	string[0].Format("%s", display[m_player.m_coachPot1]);
	string[1].Format("%s", display[m_player.m_coachPot2]);
	string[2].Format("%s", display[m_player.m_coachEffort]);
	string[3].Format("%s", display[m_player.m_coachScoring]);
	string[4].Format("%s", display[m_player.m_coachShooting]);
	string[5].Format("%s", display[m_player.m_coachRebounding]);
	string[6].Format("%s", display[m_player.m_coachPassing]);
	string[7].Format("%s", display[m_player.m_coachDefense]);
	string[8].Format("%s", display[m_player.m_coachEndurance]);
	string[9].Format("%s", display[m_player.m_power2]);

	for(int i=0; i<=9; i++)
	{
		m_list_development.InsertItem(i,label[i]);
		m_list_development.SetItemText(i,1,string[i]);
	}

}

HBRUSH CScoutProfileDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CScoutProfileDlg::OnButtonEdit() 
{
	// TODO: Add your control notification handler code here
	CScoutEditDlg sc;
	sc.m_index = 1;
	sc.m_member[1] = m_scout;
	int r = sc.DoModal();
	
}


void CScoutProfileDlg::OnLvnItemchangedListCoaching(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
