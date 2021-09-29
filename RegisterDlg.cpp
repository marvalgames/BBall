										// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "RegisterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog


CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisterDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterDlg)
	ON_BN_CLICKED(IDC_BUTTON_CREDIT, OnButtonCredit)
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_CREDIT2, OnButtonCredit2)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg message handlers


void CRegisterDlg::OnButtonCredit() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(*this, "open", "https://www.regnow.com/softsell/nph-softsell.cgi?item=1546-1", NULL, NULL, SW_SHOWNORMAL);
}


HBRUSH CRegisterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{

HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

//	Invalidate(FALSE);
	//Default();
     
     switch (nCtlColor)
     {
     //Edit controls need white background and black text
     //Note the 'return hbr' which is needed to draw the Edit
     //control's internal background (as opposed to text background)
 //    case CTLCOLOR_EDIT:
 //         pDC->SetTextColor(EDITCOLOR);
 //         pDC->SetBkColor(EDITBKCOLOR);
 //         return hbr;
     //Static controls need black text and same background as myBrush
     case CTLCOLOR_STATIC:
          LOGBRUSH logbrush;
          myBrush.GetLogBrush( &logbrush );
          pDC->SetTextColor(RGB(0,0,0));
          pDC->SetBkColor(logbrush.lbColor);
          return myBrush;
     case CTLCOLOR_BTN:
          pDC->SetTextColor(RGB(0,0,0));
         pDC->SetBkColor(RGB(255,255,224));
         return myBrush;
//     case CTLCOLOR_LISTBOX:
  //        pDC->SetBkColor(LISTBOXCOLOR);
    //      pDC->SetTextColor(LISTBOXTEXTCOLOR);
      //    return myBrush;

//     case CTLCOLOR_SCROLLBAR:
  //        pDC->SetTextColor(RGB(0,0,0));
    //      pDC->SetBkColor(LISTBOXCOLOR);
      //    return myBrush;

//     case CTLCOLOR_MSGBOX:
  //        pDC->SetTextColor(RGB(255,255,255));
    //      pDC->SetBkColor(RGB(255,128,128));
      //    return myBrush;

     case CTLCOLOR_DLG:
          return myBrush;
     //This shouldn't occurr since we took all the cases, but
     //JUST IN CASE, return the new brush
     default:
          return hbr;
     } 



}

BOOL CRegisterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect	rWnd;
	CRect	rClient;

	GetWindowRect(&rWnd);
	GetClientRect(&rClient);



	MoveWindow( rWnd.Width()/2 ,rWnd.Height()/2,420,420);


	myBrush.CreateSolidBrush(RGB(255,255,224)); 
//
//	ShellExecute(*this, "open", "http://www.nbapostup.com/content/alternate-paypal-free-2500", NULL, NULL, SW_SHOWNORMAL);

	ShellExecute(*this, "open", "http://www.regnow.com/softsell/nph-softsell.cgi?item=1546-1", NULL, NULL, SW_SHOWNORMAL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegisterDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CRegisterDlg::OnButtonCredit2() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(*this, "open", "http://www.shotsports.com", NULL, NULL, SW_SHOWNORMAL);

	
}

void CRegisterDlg::OnButton() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();	
}


