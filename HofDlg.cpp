// HofDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "HofDlg.h"
#include "CareerStatsCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHofDlg dialog


CHofDlg::CHofDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHofDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHofDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHofDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHofDlg)
	DDX_Control(pDX, IDC_LIST_HOF, m_listHof);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHofDlg, CDialog)
	//{{AFX_MSG_MAP(CHofDlg)
	ON_BN_CLICKED(IDC_BUTTON_PROFILE, OnButtonProfile)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_LBN_DBLCLK(IDC_LIST_HOF, OnDblclkListHof)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHofDlg message handlers

BOOL CHofDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 


	bool exists = true;
	CFileStatus status;
	CString pFileName = m_path + m_leagueName + ".hof";
	if( CFile::GetStatus( pFileName, status ) == 0) exists = 0;


	if(exists == true)
		ListHofPlayers();
	else
		m_listHof.AddString("No players selected");


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHofDlg::ListHofPlayers()
{
	CString pFileName = m_path + m_leagueName + ".hof";
    CStdioFile file( pFileName, CFile::modeRead);
	int seek = 0;
	int length = (int)file.GetLength();
	
	file.Seek(seek, CFile::begin );
	CString string;
	int count = 0;
	do
	{
	file.ReadString(string);
	string.TrimRight();
	string.TrimLeft();
	if(string != "")
	{
	CString po = string.Mid(0, 2);
	CString player = string.Mid(3, 16);
	CString id = string.Mid(19, 5);
	CString yr = string.Mid(24, 5);
	if(po == "C ")
	{
		player = string.Mid(2, 16);
		id = string.Mid(18, 5);
		yr = string.Mid(23, 5);
	}
//	yr.TrimRight();
//	yr.TrimLeft();
	int year = atoi(yr);
	int pointer = atoi(id);
	int currentYear = year;
	m_pointer[count] = pointer;
	m_names_list[count] = player;
	count = count + 1;
	player.TrimRight();
	m_listHof.AddString(po + " " + player + " was elected in " + yr + ".");
	}
	}
	while(string != "");
	count = m_listHof.GetCount() - 1;
	m_listHof.SetCurSel(count);

}

void CHofDlg::OnButtonProfile() 
{
	// TODO: Add your control notification handler code here

}

void CHofDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_HISTORY_HALL);	
//	return TRUE;		

//	HtmlHelp(NULL, "jumpshot.chm::/html/historyhof.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL CHofDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_HISTORY_HALL);	
//	return TRUE;		

//	HtmlHelp(NULL, "jumpshot.chm::/html/historyhof.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CHofDlg::OnDblclkListHof() 
{
	// TODO: Add your control notification handler code here
//	int i = m_listBox.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	int i = m_listHof.GetCurSel();
	int items = m_listHof.GetCount();
	CString m_fileName = m_path + m_leagueName;

	if(i>=0)
	{
		CCareerStatsCardDlg* card = new CCareerStatsCardDlg;
		int last = 0;
		for(int j=0; j<=items-1; j++)
		{
			card->m_pointer[j] = m_pointer[j];	
			card->m_names_list[j] = m_names_list[j];
			if(m_pointer[j] > 0) last = j;
		}
		card->m_leagueName = m_fileName;
		card->m_player_index = i;
		card->m_pl_index_start = 0;
		card->m_pl_index_end = last;
		card->DoModal();
		delete card;
	}

}

HBRUSH CHofDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
     //case CTLCOLOR_LISTBOX:
//
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
