// TypeGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"

//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "TypeGameDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTypeGameDlg dialog
/*static DWORD aHelpIDs[] =
{
	IDC_EXHIBITION_GAME, HIDD_EXHIBITION_GAME,
	IDC_LEAGUE, HIDD_LEAGUE,
	IDC_TEAM_GAME, HIDD_TEAM_GAME,
};*/


CTypeGameDlg::CTypeGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTypeGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTypeGameDlg)
	//}}AFX_DATA_INIT
	m_exhteam1 = 0;
	m_exhteam2 = 0;
	m_singleteam = 0;

}


void CTypeGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTypeGameDlg)
	DDX_Control(pDX, IDC_COMBO_SINGLETEAM, m_combo_singleteam);
	DDX_Control(pDX, IDC_COMBO_EXHTEAM2, m_combo_exhteam2);
	DDX_Control(pDX, IDC_COMBO_EXHTEAM1, m_combo_exhteam1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTypeGameDlg, CDialog)
	//{{AFX_MSG_MAP(CTypeGameDlg)
	ON_BN_CLICKED(IDC_LEAGUE, OnLeague)
	ON_BN_CLICKED(IDC_EXHIBITION_GAME, OnExhibitionGame)
	ON_BN_CLICKED(IDC_TEAM_GAME, OnTeamGame)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_SINGLETEAM, OnSelchangeComboSingleteam)
	ON_CBN_SELCHANGE(IDC_COMBO_EXHTEAM1, OnSelchangeComboExhteam1)
	ON_CBN_SELCHANGE(IDC_COMBO_EXHTEAM2, OnSelchangeComboExhteam2)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTypeGameDlg message handlers

BOOL CTypeGameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(FALSE);
 myBrush.CreateSolidBrush(DLGCOLOR); 
	if(m_gameType == EXHIBITION) CheckDlgButton(IDC_EXHIBITION_GAME, 1);	
	else if(m_gameType == SINGLE_TEAM) CheckDlgButton(IDC_TEAM_GAME, 1);	
	else CheckDlgButton(IDC_LEAGUE, 1);	

	for(int i=0; i<=32; i++)
	{
		if(m_team_names[i] != "")
		{
			m_combo_exhteam1.AddString(m_team_names[i]);
			m_combo_exhteam2.AddString(m_team_names[i]);
			m_combo_singleteam.AddString(m_team_names[i]);
	
		}
	}

	m_combo_exhteam1.SetCurSel(m_default_team);
	m_combo_exhteam2.SetCurSel(0);
	m_combo_singleteam.SetCurSel(m_default_team);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTypeGameDlg::OnLeague() 
{
	// TODO: Add your control notification handler code here
	m_gameType = LEAGUE;	
}

void CTypeGameDlg::OnExhibitionGame() 
{
	// TODO: Add your control notification handler code here
	m_gameType = EXHIBITION;		
}

void CTypeGameDlg::OnTeamGame() 
{
	// TODO: Add your control notification handler code here	
	m_gameType = SINGLE_TEAM;	
}

BOOL CTypeGameDlg::OnHelpInfo(HELPINFO *lpHelpInfo) 
{
//	HtmlHelp(NULL, "jumpshot.chm::/html/gametype.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
//  	WinHelp(HID_PLAY_TYPE);
	return TRUE;
}

void CTypeGameDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
 // 	WinHelp(HID_PLAY_TYPE);
//	HtmlHelp(NULL, "jumpshot.chm::/html/gametype.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}



HBRUSH CTypeGameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CTypeGameDlg::OnSelchangeComboSingleteam() 
{
	// TODO: Add your control notification handler code here
	
}

void CTypeGameDlg::OnSelchangeComboExhteam1() 
{
	// TODO: Add your control notification handler code here
	
}

void CTypeGameDlg::OnSelchangeComboExhteam2() 
{
	// TODO: Add your control notification handler code here
	
}

void CTypeGameDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_exhteam1 = m_combo_exhteam1.GetCurSel() + 1;
	m_exhteam2 = m_combo_exhteam2.GetCurSel() + 1;
	m_singleteam = m_combo_singleteam.GetCurSel() + 1;
	
	CDialog::OnOK();
}

void CTypeGameDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();	
}
