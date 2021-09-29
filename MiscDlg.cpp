// MiscDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "MiscDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMiscDlg dialog


CMiscDlg::CMiscDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMiscDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMiscDlg)
	m_check_random_yrs = FALSE;
	m_edit_yrs_pro = 0;
	m_edit_yrs_team = 0;
	m_edit_intangibles = 0;
	m_edit_skill = 0;
	m_edit_talent = 0;
	m_check_career_projections = FALSE;
	m_check_contract = FALSE;
	m_check_ratings = FALSE;
	m_edit_coach = 0;
	m_edit_loyalty = 0;
	m_edit_pt = 0;
	m_edit_security = 0;
	m_edit_tradition = 0;
	m_edit_winning = 0;
	m_edit_year_1 = 0;
	m_edit_year_2 = 0;
	m_edit_year_3 = 0;
	m_edit_year_4 = 0;
	m_edit_year_5 = 0;
	m_edit_year_6 = 0;
	//}}AFX_DATA_INIT
}


void CMiscDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMiscDlg)
	DDX_Control(pDX, IDC_COMBO_CURRENT_CONTRACT_YEAR, m_combo_current_contract_yr);
	DDX_Check(pDX, IDC_CHECK_RANDOM_YRS_PRO, m_check_random_yrs);
	DDX_Text(pDX, IDC_EDIT_YRS_PRO, m_edit_yrs_pro);
	DDV_MinMaxUInt(pDX, m_edit_yrs_pro, 0, 20);
	DDX_Text(pDX, IDC_EDIT_YRS_TEAM, m_edit_yrs_team);
	DDV_MinMaxUInt(pDX, m_edit_yrs_team, 0, 20);
	DDX_Text(pDX, IDC_EDIT_INTANGIBLES, m_edit_intangibles);
	DDV_MinMaxUInt(pDX, m_edit_intangibles, 1, 5);
	DDX_Text(pDX, IDC_EDIT_SKILL, m_edit_skill);
	DDV_MinMaxUInt(pDX, m_edit_skill, 1, 5);
	DDX_Text(pDX, IDC_EDIT_TALENT, m_edit_talent);
	DDV_MinMaxUInt(pDX, m_edit_talent, 1, 5);
	DDX_Check(pDX, IDC_CHECK_RANDOM_CAREER_PROJECTIONS, m_check_career_projections);
	DDX_Check(pDX, IDC_CHECK_CONTRACT, m_check_contract);
	DDX_Check(pDX, IDC_CHECK_RATINGS, m_check_ratings);
	DDX_Text(pDX, IDC_EDIT_COACH, m_edit_coach);
	DDV_MinMaxUInt(pDX, m_edit_coach, 1, 5);
	DDX_Text(pDX, IDC_EDIT_LOYALTY, m_edit_loyalty);
	DDV_MinMaxUInt(pDX, m_edit_loyalty, 1, 5);
	DDX_Text(pDX, IDC_EDIT_PT, m_edit_pt);
	DDV_MinMaxUInt(pDX, m_edit_pt, 1, 5);
	DDX_Text(pDX, IDC_EDIT_SECURITY, m_edit_security);
	DDV_MinMaxUInt(pDX, m_edit_security, 1, 5);
	DDX_Text(pDX, IDC_EDIT_TRADITION, m_edit_tradition);
	DDV_MinMaxUInt(pDX, m_edit_tradition, 1, 5);
	DDX_Text(pDX, IDC_EDIT_WINNING, m_edit_winning);
	DDV_MinMaxUInt(pDX, m_edit_winning, 1, 5);
	DDX_Text(pDX, IDC_EDIT_YEAR_1, m_edit_year_1);
	DDV_MinMaxUInt(pDX, m_edit_year_1, 0, 3000);
	DDX_Text(pDX, IDC_EDIT_YEAR_2, m_edit_year_2);
	DDV_MinMaxUInt(pDX, m_edit_year_2, 0, 3000);
	DDX_Text(pDX, IDC_EDIT_YEAR_3, m_edit_year_3);
	DDV_MinMaxUInt(pDX, m_edit_year_3, 0, 3000);
	DDX_Text(pDX, IDC_EDIT_YEAR_4, m_edit_year_4);
	DDV_MinMaxUInt(pDX, m_edit_year_4, 0, 3000);
	DDX_Text(pDX, IDC_EDIT_YEAR_5, m_edit_year_5);
	DDV_MinMaxUInt(pDX, m_edit_year_5, 0, 3000);
	DDX_Text(pDX, IDC_EDIT_YEAR_6, m_edit_year_6);
	DDV_MinMaxUInt(pDX, m_edit_year_6, 0, 3000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMiscDlg, CDialog)
	//{{AFX_MSG_MAP(CMiscDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiscDlg message handlers

BOOL CMiscDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	DisplayRatings();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CMiscDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	WinHelp(HID_EDIT_OFF_COURT_RATINGS);	
	return TRUE;	
}

void CMiscDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	WinHelp(HID_EDIT_OFF_COURT_RATINGS);	
//	return TRUE;
	
}

HBRUSH CMiscDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMiscDlg::DisplayRatings()
{

	CString head;
	head.Format("Edit Contract and Off Court Ratings for %s", m_contract.m_name);
	SetWindowText(head);

	m_check_random_yrs = TRUE;
	m_check_career_projections = TRUE;
	m_check_contract = TRUE;
	m_check_ratings = TRUE;
	if(m_contract.m_random_yrs_service == false) m_check_random_yrs = FALSE;
	if(m_contract.m_random_projections == false) m_check_career_projections = FALSE;
	if(m_contract.m_random_contracts == false) m_check_contract = FALSE;
	if(m_contract.m_random_contract_ratings == false) m_check_ratings = FALSE;
	m_edit_yrs_pro = m_contract.m_yrs_of_service;
	m_edit_yrs_team = m_contract.m_yrs_on_team;
	m_edit_talent = m_contract.m_pot1;
	m_edit_skill = m_contract.m_pot2;
	m_edit_intangibles = m_contract.m_effort;

	m_edit_coach = m_contract.m_coach_factor;
	m_edit_loyalty = m_contract.m_loyalty_factor;
	m_edit_pt = m_contract.m_playing_time_factor;
	m_edit_security = m_contract.m_security_factor;
	m_edit_tradition = m_contract.m_tradition_factor;
	m_edit_winning = m_contract.m_winning_factor;

	m_edit_year_1 = m_contract.m_contract_salaries[1];
	m_edit_year_2 = m_contract.m_contract_salaries[2];
	m_edit_year_3 = m_contract.m_contract_salaries[3];
	m_edit_year_4 = m_contract.m_contract_salaries[4];
	m_edit_year_5 = m_contract.m_contract_salaries[5];
	m_edit_year_6 = m_contract.m_contract_salaries[6];

	int i = m_contract.m_current_contract_yr;
	m_combo_current_contract_yr.SetCurSel(i);

	UpdateData(FALSE);
}

void CMiscDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if(m_check_random_yrs == FALSE) m_contract.m_random_yrs_service = false;
	else if(m_check_random_yrs == TRUE) m_contract.m_random_yrs_service = true;

	if(m_check_career_projections == FALSE) m_contract.m_random_projections = false;
	else if(m_check_career_projections == TRUE) m_contract.m_random_projections = true;

	if(m_check_contract == FALSE) m_contract.m_random_contracts = false;
	else if(m_check_contract == TRUE) m_contract.m_random_contracts = true;

	if(m_check_ratings == FALSE) m_contract.m_random_contract_ratings = false;
	else if(m_check_ratings == TRUE) m_contract.m_random_contract_ratings = true;

	m_contract.m_yrs_of_service = m_edit_yrs_pro;
	m_contract.m_yrs_on_team = m_edit_yrs_team;
	m_contract.m_pot1 = m_edit_talent;
	m_contract.m_pot2 = m_edit_skill;
	m_contract.m_effort = m_edit_intangibles;

		m_contract.m_coach_factor = m_edit_coach;
		m_contract.m_loyalty_factor = m_edit_loyalty;
		m_contract.m_playing_time_factor = m_edit_pt;
		m_contract.m_security_factor = m_edit_security;
		m_contract.m_tradition_factor = m_edit_tradition;
		m_contract.m_winning_factor = m_edit_winning;

	m_contract.m_pot1 = m_edit_talent;
	m_contract.m_pot2 = m_edit_skill;
	m_contract.m_effort = m_edit_intangibles;



	m_contract.m_contract_salaries[1] = m_edit_year_1;
	m_contract.m_contract_salaries[2] = m_edit_year_2;
	m_contract.m_contract_salaries[3] = m_edit_year_3;
	m_contract.m_contract_salaries[4] = m_edit_year_4;
	m_contract.m_contract_salaries[5] = m_edit_year_5;
	m_contract.m_contract_salaries[6] = m_edit_year_6;

	m_contract.m_current_contract_yr = m_combo_current_contract_yr.GetCurSel();
	m_contract.m_contract_yrs = 0;

	int salary = 0;
	int remaining_salary = 0;
	for(int y=1; y<=6; y++)
	{
		int i = m_contract.m_contract_salaries[y];			
		if(i > 0) m_contract.m_contract_yrs = y;
		salary = salary + i;
		if(y >= m_contract.m_current_contract_yr) remaining_salary = remaining_salary + i;		
	}

	m_contract.m_total_salary = salary;
	m_contract.m_remaining_salary = remaining_salary;	
	if(m_contract.m_contract_yrs == m_contract.m_current_contract_yr) m_contract.m_is_free_agent = true;
	m_contract.m_current_yr_salary = m_contract.m_contract_salaries[m_contract.m_current_contract_yr]; 
	
	CDialog::OnOK();
}
