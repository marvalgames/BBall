// ImportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "ImportDlg.h"

#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImportDlg dialog


CImportDlg::CImportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImportDlg)
	m_check_adjust = FALSE;
	m_check_random = FALSE;
	m_check_database = TRUE;
	m_draft_year = 0;
	//}}AFX_DATA_INIT
}


void CImportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImportDlg)
	DDX_Check(pDX, IDC_CHECK_ADJUST, m_check_adjust);
	DDX_Check(pDX, IDC_CHECK_RANDOM, m_check_random);
	DDX_Check(pDX, IDC_CHECK_DATABASE, m_check_database);
	DDX_Text(pDX, IDC_EDIT_YR, m_draft_year);
	DDV_MinMaxUInt(pDX, m_draft_year, 1900, 2100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImportDlg, CDialog)
	//{{AFX_MSG_MAP(CImportDlg)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImport)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImportDlg message handlers

BOOL CImportDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR); 	
	// TODO: Add extra initialization here
//        GetDlgItem(IDC_CHECK_ADJUST)->EnableWindow(TRUE);		
  //      GetDlgItem(IDC_CHECK_RANDOM)->EnableWindow(TRUE);		
	m_check_adjust = true;
	m_check_random = false;
	m_draft_year = m_year;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CImportDlg::OnOK() 
{
	// TODO: Add extra validation here	
	CDialog::OnOK();
}

int CImportDlg::ReadDraftSpreadSheet()
{

	int players_loaded = 0;
	UpdateData(TRUE);
	CDisk* disk = new CDisk;
	CString file_name = m_full_path;
	CString kie_file_name = m_path + m_league_name + ".kie";
	if(avg.m_settings.m_current_stage > 1)
	{
		kie_file_name = m_path + m_league_name + ".roo";
	}

	

	//if(disk->FileExists(kie_file_name) == false)
	//{
	//	AfxMessageBox("Current Rookie File Does Not Exist", MB_OK);
	//}
	if(m_check_database == TRUE)
	{
		players_loaded = disk->CreatePlayerObjectFromDataBase(file_name, m_draft_year, true);
	}
	else
	{
		players_loaded = disk->CreatePlayerObjectFromSpreadSheet(file_name, m_check_adjust, m_check_random, 96);
	}



	bool valid = true;
		int count = 0;
		for(int i=0; i<=960; i++)
		{
			if(disk->avg.m_actual[i].m_name != "" && disk->avg.m_actual[i].m_games > 0 && disk->avg.m_actual[i].m_min > 0)
				count = count + 1;
		}	
		if(count < 32) valid = false;

		if(valid == true)
		{
			disk->WriteRookieFile(kie_file_name, m_check_database);

		}

	delete disk;

	return players_loaded;
}


void CImportDlg::OnButtonImport() 
{
	// TODO: Add your control notification handler code here


	CFileDialog fil(true, ".csv", "historical", OFN_HIDEREADONLY,
		"Files (*.csv)|*.csv|", NULL);
	int result = fil.DoModal();	
	if(result == IDOK)
	{
		m_full_path = fil.GetPathName();
		int r = AfxMessageBox("Click Yes to overwite the existing draft file and import the selection.", MB_YESNO);
		if(r == IDYES)
		{
		int players_loaded = ReadDraftSpreadSheet();
		CString str;
		str.Format("Draft file import completed: %d players", players_loaded); 
		AfxMessageBox(str, MB_OK);
		}

	}

}





BOOL CImportDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	//HtmlHelp(NULL, "jumpshot.chm::/html/toolsdraftfiles.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CImportDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	//HtmlHelp(NULL, "jumpshot.chm::/html/toolsdraftfiles.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

HBRUSH CImportDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
