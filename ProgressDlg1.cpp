// ProgressDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"

#include "ProgressDlg1.h"	// Added by ClassView

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
	//}}AFX_DATA_INIT
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
	DDX_Control(pDX, IDC_EDIT_TEXT, m_editText);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	//}}AFX_MSG_MAP
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

BOOL CProgressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
    myBrush.CreateSolidBrush(DLGCOLOR);

	// TODO: Add extra initialization here
//	m_progress.SetRange(1, 1000);
	m_editText.SetWindowText(m_text);
//	m_listText.AddString("Shitfkfkf");
//    UpdateData(TRUE);
  //  UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CProgressDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
        return myBrush;
        //Static controls need black text and same background as myBrush
    case CTLCOLOR_STATIC:
        LOGBRUSH logbrush;
        myBrush.GetLogBrush(&logbrush);
        pDC->SetTextColor(STATICCOLOR);
        pDC->SetBkColor(DLGCOLOR);
        return myBrush;
    case CTLCOLOR_BTN:
        pDC->SetTextColor(RGB(0, 255, 255));
        pDC->SetBkColor(RGB(255, 128, 128));
        return myBrush;
    case CTLCOLOR_LISTBOX:
        pDC->SetBkColor(LISTBOXCOLOR);
        pDC->SetTextColor(LISTBOXTEXTCOLOR);
        return myBrush;

    case CTLCOLOR_SCROLLBAR:
        pDC->SetTextColor(RGB(0, 0, 0));
        pDC->SetBkColor(LISTBOXCOLOR);
        return myBrush;

    case CTLCOLOR_MSGBOX:
        pDC->SetTextColor(RGB(255, 255, 255));
        pDC->SetBkColor(RGB(255, 128, 128));
        return myBrush;

    case CTLCOLOR_DLG:
        pDC->SetBkColor(DLGCOLOR);
        return myBrush;
        //This shouldn't occurr since we took all the cases, but
        //JUST IN CASE, return the new brush
    default:
        return hbr;
    }
    // TODO: Return a different brush if the default is not desired
//	return hbr;

}
