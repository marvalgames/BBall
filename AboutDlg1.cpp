// AboutDlg1.cpp : implementation file
//

#include "stdafx.h"


#ifndef bball_h
#include "bball.h"
#define bball_h
#endif 

//#include "Constants.h"

#include "AboutDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg1 dialog


CAboutDlg1::CAboutDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAboutDlg1::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg1)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
    DDX_Control(pDX, IDC_BUTTON_WEB, m_btnWeb);
    DDX_Control(pDX, IDOK, m_btnOk);
}


BEGIN_MESSAGE_MAP(CAboutDlg1, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_WEB, OnButtonWeb)
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDOK, &CAboutDlg1::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg1 message handlers

HBRUSH CAboutDlg1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
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
          return myBrush;
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
          return myBrush;
     } 



//	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
//	return hbr;

//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}

BOOL CAboutDlg1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    //(CMFCButton*)GetDlgItem(IDOK)->Set
    //CMFCButton* pButton = (CMFCButton*)GetDlgItem(IDOK);

    //pButton->SetTextColor(RGB(0, 0, 255));


	myBrush.CreateSolidBrush(DLGCOLOR);
	
    m_btnOk.m_useImage = false;
    m_btnOk.SetFaceColor(BUTTONCOLOR);
    m_btnOk.SetTextColor(BUTTONTEXTCOLOR);

    m_btnWeb.m_useImage = false;
    m_btnWeb.SetFaceColor(BUTTONCOLOR);
    m_btnWeb.SetTextColor(BUTTONTEXTCOLOR);

    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAboutDlg1::OnButtonWeb() 
{
	// TODO: Add your control notification handler code here
    ShellExecute(*this, "open", "http://www.shotsports.com", NULL, NULL, SW_SHOWNORMAL);
}


void CAboutDlg1::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialog::OnOK();
}
