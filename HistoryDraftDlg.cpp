// HistoryDraftDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "HistoryDraftDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryDraftDlg dialog


CHistoryDraftDlg::CHistoryDraftDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryDraftDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryDraftDlg)
	//}}AFX_DATA_INIT
}


void CHistoryDraftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryDraftDlg)
	DDX_Control(pDX, IDC_COMBO_LIST_TEAMS, m_listYears);
	DDX_Control(pDX, IDC_LIST_DRAFT, m_listDraft);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryDraftDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryDraftDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAMS, OnSelchangeComboListTeams)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryDraftDlg message handlers

BOOL CHistoryDraftDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	//WinHelp(HID_HISTORY_HALL);	
	//return TRUE;		

//	HtmlHelp(NULL, "jumpshot.chm::/html/historydrafts.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CHistoryDraftDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_HISTORY_HALL);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/historydrafts.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

//	return TRUE;		
	
}

void CHistoryDraftDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL CHistoryDraftDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 


	m_exists = true;
	CFileStatus status;
	CString pFileName = m_path + m_leagueName + ".dra";
	if( CFile::GetStatus( pFileName, status ) == 0) m_exists = false;

	FillYears();
	OnSelchangeComboListTeams();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHistoryDraftDlg::FillYears()
{
	if(m_exists == true)
	{

	CString pFileName = m_path + m_leagueName + ".dra";
	CString string;
  	CStdioFile file(pFileName, CFile::modeRead);
	int size = (int)file.GetLength()-20000;
	for(int i=1; i<=size; i=i+20001)
	{
		file.Seek( i, CFile::begin);
		file.ReadString(string);
		m_listYears.AddString(string);
	}
	file.Close();


	}
	else
	{

		m_listYears.AddString("No Draft History");
		
	}
	int count = m_listYears.GetCount() - 1;
	m_listYears.SetCurSel(count);
}

HBRUSH CHistoryDraftDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CHistoryDraftDlg::OnSelchangeComboListTeams() 
{
	// TODO: Add your control notification handler code here

	if(m_exists == true)
	{

	m_listDraft.ResetContent();
	int offset = m_listYears.GetCurSel()*20000+1;
	CString pFileName = m_path + m_leagueName + ".dra";
	CString string;
  	CStdioFile file(pFileName, CFile::modeRead);
	file.Seek( offset, CFile::begin);
	bool cont = false;
	for(int i=1; i<=200; i++)
	{
		if(cont == true) continue;
		file.ReadString(string);
		if(string == "* End of Draft *") cont = true;
		if(string != "" && i>1) m_listDraft.AddString(string);
	}
	file.Close();

	}
	
}
