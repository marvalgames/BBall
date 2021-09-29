// ImportPlayersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "ImportPlayersDlg.h"

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
// CImportPlayersDlg dialog


CImportPlayersDlg::CImportPlayersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImportPlayersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImportPlayersDlg)
	m_edit_nick_name = _T("");
	m_check_rookies = FALSE;
	m_check_swap = FALSE;
	//}}AFX_DATA_INIT
	m_current_yr = 2003;
}


void CImportPlayersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImportPlayersDlg)
	DDX_Control(pDX, IDC_BUTTON_IMPORT, m_button_import);
	DDX_Control(pDX, IDC_COMBO_TEAM_NAMES, m_combo_team_names);
	DDX_Text(pDX, IDC_EDIT_NICK_NAME, m_edit_nick_name);
	DDV_MaxChars(pDX, m_edit_nick_name, 32);
	DDX_Check(pDX, IDC_CHECK_ROOKIES, m_check_rookies);
	DDX_Check(pDX, IDC_CHECK_SWAP, m_check_swap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImportPlayersDlg, CDialog)
	//{{AFX_MSG_MAP(CImportPlayersDlg)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImport)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAM_NAMES, OnSelchangeComboTeamNames)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_RADIO_NONE, OnRadioNone)
	ON_BN_CLICKED(IDC_RADIO_CONTRACTS, OnRadioContracts)
	ON_BN_CLICKED(IDC_RADIO_AGES, OnRadioAges)
	ON_BN_CLICKED(IDC_CHECK_ROOKIES, OnCheckRookies)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImportPlayersDlg message handlers

void CImportPlayersDlg::OnButtonImport() 
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here

			CString yr;
			GetDlgItem(IDC_EDIT_YEAR)->GetWindowText(yr);
			m_current_yr = atoi(yr);

	
	CFileDialog fil(true, ".csv", m_league_name, OFN_HIDEREADONLY,
		"Files (*.csv)|*.csv|", NULL);
	int result = fil.DoModal();	
	if(result == IDOK)
	{
		CString m_full_path = fil.GetPathName();
		int r = AfxMessageBox("Click Yes to import the selection.", MB_YESNO);
		if(r == IDYES)
		{
		int players_loaded = 0;
		bool valid = ReadPlayersSpreadSheet(m_full_path, players_loaded);

		if(valid == true)
		{
			CString str;
			str.Format("Player Data file import completed: %d players", players_loaded); 
			AfxMessageBox(str, MB_OK);
		}
		else
			AfxMessageBox("Player Data file import UNSUCCESSFULL!!!", MB_OK);

		m_data_imported = valid;
		}
	}
}

BOOL CImportPlayersDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 	
	m_button_state = 1;
	m_check_ages = FALSE;
	m_check_contracts = FALSE;
	CheckDlgButton(IDC_RADIO_NONE, 1);	


	int co = 0;
	for(int i=0; i<=32; i++)
	{
		if(m_league_team_names[i] != "")
		{
			m_names_list[co] = m_league_team_names[i];
			m_combo_team_names.AddString(m_league_team_names[i]);
			co = co + 1;
		}
	}
	m_combo_team_names.SetTopIndex(0);
	m_combo_team_names.SetCurSel(0);
	m_edit_nick_name = m_names_list[0];
	FillEditBox();

	m_data_imported = false;	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool CImportPlayersDlg::ReadPlayersSpreadSheet(CString m_full_path, int &players_loaded)
{
	UpdateData(TRUE);
	CDisk* disk = new CDisk;
	CString file_name = m_full_path;
	disk->avg = avg;

	if(m_check_rookies == TRUE)	//historical on
		players_loaded = disk->CreatePlayerObjectFromDataBase(file_name, m_current_yr, false);
	else
	{
		players_loaded = disk->CreatePlayerObjectFromPlayerSpreadSheet(file_name, m_check_ages, m_check_contracts, m_current_yr, m_check_swap);
//		disk->MergeRosters("C:\\Program Files\\Jump Shot Basketball 5.0\\rosters.csv");//tmp
	}

									

	disk->SetUpTeamsFromImportedFile(m_names_list, m_league_style);



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
		avg = disk->avg;
	}


	delete disk;
	return valid;
	
}

void CImportPlayersDlg::OnSelchangeComboTeamNames() 
{
	// TODO: Add your control notification handler code here
	FillEditBox();
}

void CImportPlayersDlg::OnButtonChange() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int index = m_combo_team_names.GetCurSel();
	m_names_list[index] = m_edit_nick_name;	
}

void CImportPlayersDlg::FillEditBox()
{
	int index = m_combo_team_names.GetCurSel();
	m_edit_nick_name = m_names_list[index];

	CString yr;
	yr.Format("%d", m_current_yr);
	GetDlgItem(IDC_EDIT_YEAR)->SetWindowText(yr);
	UpdateData(FALSE);
}

void CImportPlayersDlg::OnRadioNone() 
{
	// TODO: Add your control notification handler code here
	m_check_ages = FALSE;
	m_check_contracts = FALSE;
	
}

void CImportPlayersDlg::OnRadioContracts() 
{
	// TODO: Add your control notification handler code here
	m_check_ages = TRUE;
	m_check_contracts = TRUE;
	
}

void CImportPlayersDlg::OnRadioAges() 
{
	// TODO: Add your control notification handler code here
	m_check_ages = TRUE;
	m_check_contracts = FALSE;
	
}


void CImportPlayersDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CImportPlayersDlg::OnCheckRookies() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL CImportPlayersDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsimport.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CImportPlayersDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsimport.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

HBRUSH CImportPlayersDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
