// TimeoutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "TimeoutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeoutDlg dialog


CTimeoutDlg::CTimeoutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeoutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeoutDlg)
	m_checkTo20 = FALSE;
	//}}AFX_DATA_INIT
}


void CTimeoutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeoutDlg)
	DDX_Control(pDX, IDC_BUTTON_VISITOR, m_buttonVisitor);
	DDX_Control(pDX, IDC_BUTTON_HOME, m_buttonHome);
	DDX_Check(pDX, IDC_CHECK_TO20, m_checkTo20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeoutDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeoutDlg)
	ON_BN_CLICKED(IDC_BUTTON_HOME, OnButtonHome)
	ON_BN_CLICKED(IDC_BUTTON_VISITOR, OnButtonVisitor)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeoutDlg message handlers

BOOL CTimeoutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	UpdateButtons();	
	if(m_toOk == false && m_pos == 1) m_buttonHome.EnableWindow(FALSE);	//disable one team if not an any team to situation
	else if(m_toOk == false && m_pos == 2) m_buttonVisitor.EnableWindow(FALSE);	


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTimeoutDlg::OnButtonHome() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_checkTo20 == TRUE && m_toHome20 > 0)
	{
		m_toHome20 = m_toHome20 - 1;
		m_homeTo20 = true;
		UpdateButtons();		
		DisableButtons();	
	}
	else if(m_toHome > 0 && m_checkTo20 == FALSE)
	{
		m_toHome = m_toHome - 1;
		m_homeTo = true;
		UpdateButtons();		
		DisableButtons();	
	}
	CDialog::OnOK();
}

void CTimeoutDlg::OnButtonVisitor() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_checkTo20 == TRUE && m_toVisitor20 > 0)
	{
		m_toVisitor20 = m_toVisitor20 - 1;
		m_visitorTo20 = true;
		UpdateButtons();
		DisableButtons();
	}	
	else if(m_toVisitor > 0 && m_checkTo20 == FALSE)
	{
		m_toVisitor = m_toVisitor - 1;
		m_visitorTo = true;
		UpdateButtons();
		DisableButtons();
	}
	CDialog::OnOK();
}

void CTimeoutDlg::UpdateButtons()
{
	CString visitor, home;
// TIMEOUTS TAKEN:   2 of 7-FULL,     1 of 2-20 second

	visitor.Format("%s timeouts remaining:  %d-FULL  %d-20 second", m_visitor, m_toVisitor, m_toVisitor20);
	home.Format("%s timeouts remaining:  %d-FULL  %d-20 second", m_home, m_toHome, m_toHome20);

	if(m_toVisitor <= 0 && m_toVisitor20 <= 0) m_buttonVisitor.EnableWindow(FALSE);

	if(m_toHome <= 0 && m_toHome20 <= 0) m_buttonHome.EnableWindow(FALSE);

		
	m_buttonVisitor.SetWindowText(visitor);
	m_buttonHome.SetWindowText(home);
	
}

void CTimeoutDlg::DisableButtons()
{
	m_buttonVisitor.EnableWindow(FALSE);
	m_buttonHome.EnableWindow(FALSE);	
}

void CTimeoutDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_GAME_TIMEOUTS);		
}

BOOL CTimeoutDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_GAME_TIMEOUTS);	
//	return TRUE;	
//	HtmlHelp(NULL, "jumpshot.chm::/html/staffs.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

HBRUSH CTimeoutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
