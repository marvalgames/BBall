// NegotiateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "NegotiateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNegotiateDlg dialog


CNegotiateDlg::CNegotiateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNegotiateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNegotiateDlg)
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 0;
	m_edit6 = 0;
	m_edit_choice_1 = _T("");
	m_edit_choice_2 = _T("");
	m_edit_choice_3 = _T("");
	m_edit_bird = _T("");
	m_check_allow = FALSE;
	m_edit_payroll = _T("");
	m_edit_owner_cap = _T("");
	//}}AFX_DATA_INIT
	m_seeking_factor = 0;
	m_negotiate_extension = false;
	m_offer_cleared = false;
	m_content_changed = false;
	m_pointer_id = 0;
}






void CNegotiateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNegotiateDlg)
	DDX_Control(pDX, IDC_COMBO_MID_YEARS, m_combo_mid_years);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_button_clear);
	DDX_Control(pDX, IDC_LIST_BID, m_list_ctrl_bid);
	DDX_Control(pDX, IDC_STATICY6, m_static_y6);
	DDX_Control(pDX, IDC_LIST_RATINGS, m_list_ctrl);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDV_MinMaxUInt(pDX, m_edit1, 0, 3000);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDV_MinMaxUInt(pDX, m_edit2, 0, 3000);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDV_MinMaxUInt(pDX, m_edit3, 0, 3000);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDV_MinMaxUInt(pDX, m_edit4, 0, 3000);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDV_MinMaxUInt(pDX, m_edit5, 0, 3000);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	DDV_MinMaxUInt(pDX, m_edit6, 0, 3000);
	DDX_Text(pDX, IDC_EDIT7, m_edit_choice_1);
	DDV_MaxChars(pDX, m_edit_choice_1, 16);
	DDX_Text(pDX, IDC_EDIT8, m_edit_choice_2);
	DDV_MaxChars(pDX, m_edit_choice_2, 16);
	DDX_Text(pDX, IDC_EDIT9, m_edit_choice_3);
	DDV_MaxChars(pDX, m_edit_choice_3, 16);
	DDX_Text(pDX, IDC_EDIT10, m_edit_bird);
	DDV_MaxChars(pDX, m_edit_bird, 32);
	DDX_Check(pDX, IDC_CHECK_ALLOW, m_check_allow);
	DDX_Text(pDX, IDC_EDIT_PAYROLL, m_edit_payroll);
	DDV_MaxChars(pDX, m_edit_payroll, 32);
	DDX_Text(pDX, IDC_EDIT_OWNER_CAP, m_edit_owner_cap);
	DDV_MaxChars(pDX, m_edit_owner_cap, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNegotiateDlg, CDialog)
	//{{AFX_MSG_MAP(CNegotiateDlg)
	ON_WM_CTLCOLOR()
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_RADIO_MIN_EXC, OnRadioMinExc)
	ON_BN_CLICKED(IDC_RADIO_MIN, OnRadioMin)
	ON_BN_CLICKED(IDC_RADIO_MID, OnRadioMid)
	ON_BN_CLICKED(IDC_RADIO_EDIT, OnRadioEdit)
	ON_BN_CLICKED(IDC_RADIO_MAX, OnRadioMax)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_CBN_SELCHANGE(IDC_COMBO_MID_YEARS, OnSelchangeComboMidYears)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNegotiateDlg message handlers

BOOL CNegotiateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	myBrush.CreateSolidBrush(DLGCOLOR); 
	if(m_negotiate_extension == true)
	{
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		m_static_y6.ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO_MIN_EXC)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMBO_MID_YEARS)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO_MID)->ShowWindow(FALSE);		
		m_player.m_previous_team = m_player.m_current_team;//insure same team for negotiating
		SetExtensionRequest();
	}
	InitControls();
	InitLabels();
	SetListCtrlHeaders();
	ListStats();
	CheckDlgButton(IDC_RADIO_EDIT, 1);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CNegotiateDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CNegotiateDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_FINANCES_FRANCHISENEGOTIATE);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/offercontract.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

	
}

BOOL CNegotiateDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_FINANCES_FRANCHISENEGOTIATE);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/offercontract.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CNegotiateDlg::InitControls()
{
	m_combo_mid_years.SetCurSel(0);
	m_category = 0;
	m_signed_extension = false;
	CString name = m_player.m_name;
	CString pos = m_player.m_pos;
	CString ca;
	if(m_salary_cap < 256000)
	{
		double max = (double)m_salary_cap / 1000.;
		ca.Format("%.2f owner cap", max);
		m_edit_owner_cap = ca;
	}

	double payroll = (double)m_owner.m_temp_payroll[1] / 100.;
	m_edit_payroll.Format("%.2f team payroll", payroll); 
	if(m_negotiate_extension == false)
		m_edit_payroll.Format("%.2f payroll + offers", payroll); 

	for(int i=0; i<=6; i++)
	{
		m_yr_salary[i] = 0;
		min[i] = 0;
		max[i] = 0;
	}



			m_minimum[0] = MIN0;
			m_minimum[1] = MIN1;
			m_minimum[2] = MIN2;
			m_minimum[3] = MIN3;
			m_minimum[4] = MIN4;
			m_minimum[5] = MIN5;
			m_minimum[6] = MIN6;
			m_minimum[7] = MIN7;
			m_minimum[8] = MIN8;
			m_minimum[9] = MIN9;
			m_minimum[10] = MIN10;


		int yrs_service = m_player.m_yrs_of_service;
			if(yrs_service > 10) yrs_service = 10;		
			
			for(int y=1; y<=6; y++)//change to 0-5?
			{
				int yr = yrs_service - 1 + y;
				if(yr > 10) yr = 10;
				min[y] = m_minimum[yr];
			}

		m_maximum[0] =MAX0;
		m_maximum[1] =MAX1;
		m_maximum[2] =MAX2;
		m_maximum[3] =MAX3;
		m_maximum[4] =MAX4;
		m_maximum[5] =MAX5;
		m_maximum[6] =MAX6;
		m_maximum[7] =MAX7;
		m_maximum[8] =MAX8;
		m_maximum[9] =MAX9;
		m_maximum[10] =MAX10;

		int yrs = m_player.m_qualifying_offer_years;
		if(yrs >= 1) m_edit1 = m_player.m_qualifying_salaries[1];
		if(yrs >= 2) m_edit2 = m_player.m_qualifying_salaries[2];
		if(yrs >= 3) m_edit3 = m_player.m_qualifying_salaries[3];
		if(yrs >= 4) m_edit4 = m_player.m_qualifying_salaries[4];
		if(yrs >= 5) m_edit5 = m_player.m_qualifying_salaries[5];
		if(yrs >= 6) m_edit6 = m_player.m_qualifying_salaries[6];

		double seeking = double(m_edit1 + m_edit2 + m_edit3 + m_edit4 + m_edit5 + m_edit6)/100.;
		if(m_negotiate_extension == true)
		{
			CString see; 
			see.Format("%s %s contract negotiation (Seeking %d year %.2f million)", pos, name, yrs, seeking);
			SetWindowText(see);
		}

		
		if(m_owner.m_million_exception_used == true
			|| m_owner.m_million_exception_offered	>= 0		
			)
			GetDlgItem(IDC_RADIO_MIN_EXC)->EnableWindow(FALSE);
		if(m_owner.m_mid_exception_used == true
			|| m_owner.m_mid_exception_offered >= 0
			)
		{
			GetDlgItem(IDC_COMBO_MID_YEARS)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO_MID)->EnableWindow(FALSE);
		}

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_ctrl.SetBkColor(BK_COLOR);
	m_list_ctrl.SetTextBkColor(TEXT_BK_COLOR);
	m_list_ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_list_ctrl.SetTextColor(RGB(0,0,0));
	m_list_ctrl.SetFont(&m_font);

	m_list_ctrl_bid.SetBkColor(BK_COLOR);
	m_list_ctrl_bid.SetTextBkColor(TEXT_BK_COLOR);
	m_list_ctrl_bid.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_list_ctrl_bid.SetTextColor(RGB(0,0,0));
	m_list_ctrl_bid.SetFont(&m_font);


	//Top 3

	int hi = 65535;
	int choice_1 = 0;
	for(int i=0; i<=32; i++)
	{
		if(m_player.m_seeking[i] < hi && m_player.m_seeking[i] > 0)
		{
			hi = m_player.m_seeking[i];
			choice_1 = i;
		}
	}

	hi = 65535;
	int choice_2 = 0;
	for(int i=0; i<=32; i++)
	{
		if(m_player.m_seeking[i] < hi && i != choice_1 && m_player.m_seeking[i] > 0)
		{
			hi = m_player.m_seeking[i];
			choice_2 = i;
		}
	}

	hi = 65535;
	int choice_3 = 0;
	for(int i=0; i<=32; i++)
	{
		if(m_player.m_seeking[i] < hi && i != choice_1 && i != choice_2 && m_player.m_seeking[i] > 0)
		{
			hi = m_player.m_seeking[i];
			choice_3 = i;
		}
	}

	m_edit_choice_1 = m_league_team_names[choice_1];
	m_edit_choice_2 = m_league_team_names[choice_2];
	m_edit_choice_3 = m_league_team_names[choice_3];

	


	if(m_player.m_loyalty_factor == 0 || m_negotiate_extension == true)
	{
		m_edit_choice_1 = "n/a";
		m_edit_choice_2 = "n/a";
		m_edit_choice_3 = "n/a";
	}

	if(m_player.m_yrs_on_team >= 3)
		m_edit_bird = "Bird Rights: yes";
	else
		m_edit_bird = "Bird Rights: no";



	UpdateData(FALSE);

}

void CNegotiateDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	for(int i=0; i<=6; i++)
	{
		m_yr_salary[i] = 0;
	}


	m_total_yrs = 6;
	if(m_edit1 == 0)
		m_total_yrs = 0;
	else if(m_edit2 == 0)
		m_total_yrs = 1;
	else if(m_edit3 == 0)
		m_total_yrs = 2;
	else if(m_edit4 == 0)
		m_total_yrs = 3;
	else if(m_edit5 == 0)
		m_total_yrs = 4;
	else if(m_edit6 == 0)
		m_total_yrs = 5;


	if(m_edit1 == 0)
	{
		m_edit2 = 0;
		m_edit3 = 0;
		m_edit4 = 0;
		m_edit5 = 0;
		m_edit6 = 0;
	}
	else if(m_edit2 == 0)
	{
		m_edit3 = 0;
		m_edit4 = 0;
		m_edit5 = 0;
		m_edit6 = 0;
	}
	else if(m_edit3 == 0)
	{
		m_edit4 = 0;
		m_edit5 = 0;
		m_edit6 = 0;
	}
	else if(m_edit4 == 0)
	{
		m_edit5 = 0;
		m_edit6 = 0;
	}
	else if(m_edit5 == 0)
	{
		m_edit6 = 0;
	}



	
	if(m_total_yrs > 0)
		m_yr_salary[0] = m_edit1;
	if(m_total_yrs > 1)
		m_yr_salary[1] = m_edit2;
	if(m_total_yrs > 2)
		m_yr_salary[2] = m_edit3;
	if(m_total_yrs > 3)
		m_yr_salary[3] = m_edit4;
	if(m_total_yrs > 4)
		m_yr_salary[4] = m_edit5;
	if(m_total_yrs > 5)
		m_yr_salary[5] = m_edit6;
	
	m_total_salary = m_edit1 + m_edit2 + m_edit3 + m_edit4 + m_edit5 + m_edit6;

	bool allow_min = AllowMinimum();
	if(m_check_allow == FALSE)
		SetMinMaxSalaries(m_edit1);	
	bool ok = false;
	if(m_check_allow == FALSE)
		ok = DataOK();
	else ok = true;

	bool afford = false;
	if(m_check_allow == FALSE)
		afford = AffordContract();
	else afford = true;

	if(((ok == true && afford == true) || allow_min == true || m_category > 0 && m_category <= 3) && m_negotiate_extension == true)
	{
		EvaluateExtensionOffer();
		Analyze();
	}
	else if((ok == true && afford == true) || allow_min == true || m_category > 0 && m_category <= 3)
	{
		if(m_category == 2)
			m_owner.m_million_exception_offered = m_pointer_id;
		else if(m_category == 3)
			m_owner.m_mid_exception_offered = m_pointer_id;

		Analyze();
	}
	else if (afford == false && m_over_owner_cap == true && ok == true)
 		AfxMessageBox("Contract offer does not qualify under the owner designated salary cap", MB_OK);
	else if (afford == false && ok == true)
 		AfxMessageBox("Contract offer does not qualify under the league salary cap", MB_OK);
	else if (ok == false && afford == true)
 		AfxMessageBox("Contract offer does not qualify.\nOffer has been changed to a qualifying offer", MB_OK);
	else
 		AfxMessageBox("Contract offer does not qualify under the league salary cap", MB_OK);
}

void CNegotiateDlg::SetMinMaxSalaries(int player_max_money)
{
//			OnRadioMax();	
			int yrs_service = m_player.m_yrs_of_service;
			if(yrs_service > 10) yrs_service = 10;		
			
			for(int y=1; y<=6; y++)//change to 0-5?
			{
				int yr = yrs_service - 1 + y;
				if(yr > 10) yr = 10;
				min[y] = m_minimum[yr];
			}


			int payroll = m_owner.m_temp_payroll[1];
			int pr = payroll + m_edit1;
			double owner_cap = (double)m_salary_cap / 10;
			double d_pr = (double)pr;
			int i_oc = (int)owner_cap;
			if(d_pr > owner_cap) m_edit1 = (i_oc - payroll);

			double factor = 1.1;

			double money = 0;
//			int yr = yrs_service - 1 + y;
			if(yrs_service >= 10)
				money = MAX10;
			else if(yrs_service >= 7)
				money = MAX7;
			else 
				money = MAX0;

			bool bird = m_player.m_bird_player;


			if(bird == true && m_player.m_previous_team == m_team_negotiating) factor = 1.125;

			if(money > m_edit1) money = m_edit1;


			if(money < min[1]) money = min[1];
			double last_check = money;
			max[1] = (int)money;
			double raise = last_check * factor - last_check;

			for(int y=2; y<=6; y++)//change to 0-5?
			{

				money = last_check + raise;		
				if(money < min[y]) money = (double) min[y];
				last_check = money;
				max[y] = (int)money;
		
			}


}

bool CNegotiateDlg::DataOK()
{
	UpdateData(TRUE);
	bool ok = true;
	if(m_edit1 < min[1])
	{
		ok = false;
		m_edit1 = min[1];
	}
	if(m_edit1 > max[1])
	{
		ok = false;
		m_edit1 = max[1];
	}
	if(m_edit2 < min[2] && m_edit2 > 0)
	{
		ok = false;
		m_edit2 = min[2];
	}
	if(m_edit2 > max[2])
	{
		ok = false;
		m_edit2 = max[2];
	}
	if(m_edit3 < min[3] && m_edit3 > 0)
	{
		ok = false;
		m_edit3 = min[3];
	}
	if(m_edit3 > max[3])
	{
		ok = false;
		m_edit3 = max[3];
	}
	if(m_edit4 < min[4] && m_edit4 > 0)
	{
		ok = false;
		m_edit4 = min[4];
	}
	if(m_edit4 > max[4])
	{
		ok = false;
		m_edit4 = max[4];
	}
	if(m_edit5 < min[5] && m_edit5 > 0)
	{
		ok = false;
		m_edit5 = min[5];
	}
	if(m_edit5 > max[5])
	{
		ok = false;
		m_edit5 = max[5];
	}
	if(m_edit6 < min[6] && m_edit6 > 0)
	{
		ok = false;
		m_edit6 = min[6];
	}
	if(m_edit6 > max[6])
	{
		ok = false;
		m_edit6 = max[6];
	}


	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}

	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}


	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}


	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}


	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}


	if(m_edit6 < m_edit5 && m_edit6 > 0)
	{
		m_edit6 = m_edit5;
		ok = false;
	}
	if(m_edit5 < m_edit4 && m_edit5 > 0)
	{
		m_edit5 = m_edit4;
		ok = false;
	}
	if(m_edit4 < m_edit3 && m_edit4 > 0)
	{
		m_edit4 = m_edit3;
		ok = false;
	}
	if(m_edit3 < m_edit2 && m_edit3 > 0)
	{
		m_edit3 = m_edit2;
		ok = false;
	}
	if(m_edit2 < m_edit1 && m_edit2 > 0)
	{
		m_edit2 = m_edit1;
		ok = false;
	}


	
	UpdateData(FALSE);


	return ok;
}


bool CNegotiateDlg::AffordContract()
{
	int team = m_team_negotiating; 
	m_over_owner_cap = false;
	bool afford = false;
	m_exception = false;
	bool bird = m_player.m_bird_player;
		
		if(bird == true && team == m_player.m_previous_team)
		{
			afford = true;
			m_exception = true;
		}
		bool ok = true;
		for(int y=1; y<=1; y++)
		{

			int projected_payroll = m_owner.m_temp_payroll[y] + m_yr_salary[y-1];
			if(projected_payroll*10 > m_salary_cap)
			{
				ok = false;
				m_over_owner_cap = true;
				afford = false;
			}
			else if((bird != true || team != m_player.m_previous_team) && projected_payroll > m_cap) ok = false;
		}
		if(ok == true) afford = true;
		return afford;	
}

bool CNegotiateDlg::AllowMinimum()
{
	bool ok = false;
	if(
		m_edit1 == min[1] && (m_edit2 == min[2] || m_edit2 == 0) &&
		(m_edit3 == min[3] || m_edit2 == 0) && (m_edit4 == min[4] || m_edit4 == 0) &&
		(m_edit5 == min[5] || m_edit5 == 0) && (m_edit6 == min[6] || m_edit6 == 0)
		)
	ok = true;
	return ok;
}		

void CNegotiateDlg::OnRadioMinExc() 
{
	// TODO: Add your control notification handler code here
	m_category = 2;


	m_edit1 = MINEX;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 0;
	m_edit6 = 0;

	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);

	UpdateData(FALSE);
}

void CNegotiateDlg::OnRadioMin() 
{
	// TODO: Add your control notification handler code here
	m_category = 1;

	int yrs_service = m_player.m_yrs_of_service;
	if(yrs_service > 10) yrs_service = 10;		
			
	m_edit1 = m_minimum[yrs_service];
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 0;
	m_edit6 = 0;

	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);

	UpdateData(FALSE);
}

void CNegotiateDlg::OnRadioMid() 
{
	// TODO: Add your control notification handler code here
	m_category = 3;

	//m_edit1 = MIDEX;
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 0;
	m_edit6 = 0;


	int yr = m_combo_mid_years.GetCurSel() + 1;
	int raise = MIDEX / 10;

	if(yr >= 1) 
		m_edit1 = MIDEX;
	if(yr >= 2) 
		m_edit2 = MIDEX + raise;
	if(yr >= 3) 
		m_edit3 = MIDEX + raise*2;
	if(yr >= 4) 
		m_edit4 = MIDEX + raise*3;
	if(yr >= 5) 
		m_edit5 = MIDEX + raise*4;
	if(yr >= 6) 
		m_edit6 = MIDEX + raise*5;


	
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	
	UpdateData(FALSE);	
}

void CNegotiateDlg::OnRadioEdit() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
    m_category = 0;
	m_owner.m_million_exception_offered = -1;
	m_owner.m_mid_exception_offered = -1;

}

void CNegotiateDlg::InitLabels()
{
	m_label[0] = "loyalty";
	m_label[1] = "winner";
	m_label[2] = "play time";
	m_label[3] = "security";
	m_label[4] = "coach";
	m_label[5] = "tradition";
}

void CNegotiateDlg::ListStats()
{
	
		CString display[6] = {"n/a", "Very Low", "Low", "Normal", "High", "Very High"};
		CString Stats[33];
				
		int n = m_player.m_loyalty_factor;
		Stats[0] = display[n];


		n = m_player.m_winning_factor;
		Stats[1] = display[n];

		n = m_player.m_playing_time_factor;
		Stats[2] = display[n];

		n = m_player.m_security_factor;
		Stats[3] = display[n];

		n = m_player.m_coach_factor;
		Stats[4] = display[n];

		n = m_player.m_tradition_factor;
		Stats[5] = display[n];




	for(int  index = 0; index < 19; index++)
	{
		if(Stats[index] == "") continue;
		m_list_ctrl.InsertItem(index, m_label[index]);
		m_list_ctrl.SetItemText(index, 1, Stats[index]);
	}


	CString Stats1[33];
	for(int j=1; j<=6; j++)
	{
		int sal = m_player.m_salary_offer[m_team_negotiating][j];
		if(sal == 0 && j==1) m_button_clear.EnableWindow(FALSE);
		Stats1[j-1].Format("%d", sal);
	}

	for(int index = 0; index < 19; index++)
	{
		if(Stats1[index] == "" || Stats1[index] == "0") continue;
		CString str;
		str.Format("%d", index+1);
		if(m_pointer_id == m_owner.m_mid_exception_offered)
			Stats1[index] = Stats1[index] + " mid X";


		m_list_ctrl_bid.InsertItem(index, str);
		m_list_ctrl_bid.SetItemText(index, 1, Stats1[index]);
		if(m_pointer_id == m_owner.m_million_exception_offered)
			Stats1[index] = Stats1[index] + " min X";

	}



}

void CNegotiateDlg::SetListCtrlHeaders()
{
	m_list_ctrl.DeleteAllItems();
	m_list_ctrl.DeleteColumn(0);
    m_list_ctrl.InsertColumn(0,"factor");    
	m_list_ctrl.DeleteColumn(1);
    m_list_ctrl.InsertColumn(1,"importance");    
    m_list_ctrl.SetColumnWidth( 0, 60);
    m_list_ctrl.SetColumnWidth( 1, 70);

    m_list_ctrl_bid.InsertColumn(0,"year");    
    m_list_ctrl_bid.InsertColumn(1,"salary");    
    m_list_ctrl_bid.SetColumnWidth( 0, 35);
    m_list_ctrl_bid.SetColumnWidth( 1, 95);

}

void CNegotiateDlg::OnRadioMax() 
{
	// TODO: Add your control notification handler code here

	int yrs_service = m_player.m_yrs_of_service;
	if(yrs_service > 10) yrs_service = 10;		
	int poss_max = m_minimum[yrs_service];



	m_category = 4;
	int team = m_team_negotiating; 

//	int yrs_service = m_player.m_yrs_of_service;
//	if(yrs_service > 10) yrs_service = 10;		
			
	bool bird = m_player.m_bird_player;
	if(m_player.m_yrs_on_team < 3) bird = false; else bird = true;
	double f = 1.10;

	if(bird == true && m_player.m_previous_team == m_team_negotiating) f = 1.125;

	if(m_negotiate_extension == true) f = 1.125;

	
	m_edit1 = m_maximum[yrs_service];


	bool ok = true;

		int payroll = m_owner.m_temp_payroll[1];
		int pr = payroll + m_edit1;
		double owner_cap = (double)m_salary_cap / 10;
		double d_pr = (double)pr;
		int i_oc = (int)owner_cap;
		if(d_pr > owner_cap) m_edit1 = (i_oc - payroll);
		if((team != m_player.m_previous_team || bird == false) && pr > m_cap) m_edit1 = (m_cap - payroll);
		if((int)m_edit1 < (int)poss_max)	
		{
			m_edit1 = (int)poss_max;
			m_category = 1;
			m_edit2 = 0;
			m_edit3 = 0;
			m_edit4 = 0;
			m_edit5 = 0;
			m_edit6 = 0;
		}
		else
		{

	double raise = (double)m_edit1 * f - (double)m_edit1;

	double n = (double) m_edit1 + raise;
	m_edit2 = (int)n;

	n = (double) m_edit2  + raise;
	m_edit3 = (int)n;

	n = (double) m_edit3  + raise;
	m_edit4 = (int)n;

	n = (double) m_edit4  + raise;
	m_edit5 = (int)n;

	n = (double) m_edit5  + raise;
	m_edit6 = (int)n;
	if(m_negotiate_extension == true) m_edit6 = 0;
		
	}
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);

	UpdateData(FALSE);
	
}

void CNegotiateDlg::SetExtensionRequest()
{
	int co = 0;

	double pos_value[6];
	double avg_pv[6] = {0,0,0,0,0,0};
	double t_pv[6] = {0,0,0,0,0,0};
	int t = m_team_negotiating;

		int franchise_win = m_owner.m_win;
		int franchise_loss = m_owner.m_loss;
	

		for(int i=1; i<=5; i++)
		{
			pos_value[i] = m_owner.m_position_values[i];
			t_pv[i] = t_pv[i] + m_owner.m_position_values[i];
		}

	

	for(int i=1; i<=5; i++)
	{
		avg_pv[i] = t_pv[i] / m_number_teams;
	}





	CString name = m_player.m_name;
	if(name != "")
	{
		m_player.SetTrueRating(m_tru, true);
		m_seeking_factor = m_player.SetExtensionRequests(franchise_win, franchise_loss, avg_pv, pos_value, m_coach_rating, true, game_season);

	}
		
	

}

void CNegotiateDlg::EvaluateExtensionOffer()
{
			int t = m_team_negotiating; 
			int y = m_total_yrs;
			int s = m_total_salary;
			double q = 0;
			if(y > 0) m_signed_extension = m_player.AcceptContract(m_seeking_factor, y, s, q);
			bool test = m_player.TestingMarket(m_signed_extension);
			if(m_player.m_stop_negotiating == 9) test = true;
			if(m_signed_extension == true && test == false)
			{
				int n = m_player.IntRandom(6);
				if(n <= m_player.m_effort)
				{
					AfxMessageBox("Thanks, I won't forget this!", MB_OK);
					if(m_player.m_loyalty_factor < 5)
					{
						m_player.m_loyalty_factor = m_player.m_loyalty_factor + 1;
						m_player.m_content = m_player.m_content + 4;
						if(m_player.m_content > 9) m_player.m_content = 9;
						m_content_changed = true;
					}
					if(m_player.Random(3) < (q*2))
					{
						if(m_player.m_content <  9)
						{
							m_player.m_content = m_player.m_content + 1;
							m_content_changed = true;
						}
					}
				}
				else 
				{
					AfxMessageBox("The contract extension is accepted.", MB_OK);
					m_player.m_content = m_player.m_content + 2;
					if(m_player.m_content > 9) m_player.m_content = 9;
				}




				

				m_player.m_contract_salaries[1] = m_player.m_contract_salaries[m_player.m_current_contract_yr];

				m_player.m_current_contract_yr = 1;
				m_player.m_contract_yrs = m_total_yrs+1;
				
				m_player.m_contract_salaries[2] = m_edit1;
				m_player.m_contract_salaries[3] = m_edit2;
				m_player.m_contract_salaries[4] = m_edit3;
				m_player.m_contract_salaries[5] = m_edit4;
				m_player.m_contract_salaries[6] = m_edit5;

				m_player.m_is_free_agent = false;
				m_player.m_signed = true;
				int sal = 0 ;
				for(y=1; y<=m_player.m_contract_yrs; y++)
				{
					sal = sal + m_player.m_contract_salaries[y];
				}
				m_player.m_remaining_salary = sal;
				m_player.m_total_salary = sal;

			}
			else if(test == false)
			{
				int n = m_player.IntRandom(10);
				int ne = 8-m_player.m_effort;
				if(n <= ne)
				{
					if(m_player.m_loyalty_factor > 1)
					{
						m_content_changed = true;

						m_player.m_loyalty_factor = m_player.m_loyalty_factor - 1;
					}
					if(m_player.Random(2) > (q*2))
					{
						if(m_player.m_content >  1)
						{
							m_player.m_content = m_player.m_content -1;
							m_content_changed = true;
						}
					}
				}
				
				if(m_player.m_stop_negotiating >= 3)
					MessageBox("The negotiation has not gone well so unless you are willing to overpay we are no longer willing to negotiate", "Player Response", MB_OK);			
				else if(q < .5)
					MessageBox("Are you kidding me?", "Player Response", MB_OK);			
 				else if(q < .75)
					MessageBox("I was expecting a better offer.", "Player Response", MB_OK);
 				else
					MessageBox("I was hoping for a little more than that.", "Player Response", MB_OK);

				double r=m_player.Random(2.6 - (double)m_player.m_loyalty_factor * 2 / 10);
				if(r > q)
				{
					m_player.m_stop_negotiating = m_player.m_stop_negotiating + 1;
					m_content_changed = true;
				}


				
			}
			else if(test == true)
			{
					MessageBox("We have decided to file for free agency at the end of the season rather than accept an extension", "Player Response", MB_OK);			
					m_player.m_stop_negotiating = 9;
					//reaches 9 when testing market or too many extension offers overpayed or not
			}
}

void CNegotiateDlg::Analyze()
{
		bool qualify = true;
		double number = (double) m_player.m_seeking[m_team_negotiating] * (1. - m_player.m_accept_factor);
		//if(m_yr_salary[0] < number) qualify = false;

		if(m_negotiate_extension == false)
		{

		double f = m_yr_salary[0] / number;
		if(f < .3)
		{
			//AfxFormatString2( message, IDS_STRING_MESSAGE_PLAYER_TRADEOK, team1name, team2name); 
 			MessageBox("You have to be kidding me", "", MB_OK);		
		}
		else if(f < .6)
		{
			//AfxFormatString2( message, IDS_STRING_MESSAGE_PLAYER_TRADEOK, team1name, team2name); 
 			MessageBox("This is not much of an offer", "", MB_OK);		
		}
//			AfxMessageBox("Are you kidding me?", MB_OK);			
		else if(f > 1.2)
		{
			MessageBox("Thank you! This offer will receive strong consideration", "", MB_OK);			
			CDialog::OnOK();
		}
		else
		{
			CDialog::OnOK();
		}

		}
		else
		{
			CDialog::OnOK();
		}
}

void CNegotiateDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
			m_offer_cleared = true;
			m_player.m_top_offer[m_team_negotiating] = false;
			m_player.m_year_offer[m_team_negotiating] = 0;
			m_player.m_total_salary_offer[m_team_negotiating] = 0;

			for(int j=0; j<=6; j++)
			{
				m_player.m_salary_offer[m_team_negotiating][j] = 0;
			}

			int off = m_player.m_offer_slot[m_team_negotiating];


			for(int i=0; i<=6; i++)
			{
				m_owner.m_temp_payroll[i] = m_owner.m_temp_payroll[i] - m_owner.m_top_free_agent_salaries[off][i];

			}	
			
			for(int j=0; j<=5; j++)
			{
				m_owner.m_top_free_agent_salaries[off][j+1] = 0;
			}



			if(m_owner.m_mid_exception_offered == m_pointer_id)
			{
				GetDlgItem(IDC_COMBO_MID_YEARS)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO_MID)->ShowWindow(TRUE);

			}

			if(m_owner.m_million_exception_offered == m_pointer_id)
			{
				GetDlgItem(IDC_RADIO_MIN_EXC)->EnableWindow(TRUE);
			}



			m_owner.m_top_free_agent_total_salary[off] = 0;
			m_owner.m_top_free_agent_years[off]  = 0;
			m_owner.m_top_free_agent[off] = -1;
			if(m_owner.m_mid_exception_offered == m_player.m_id)
				m_owner.m_mid_exception_offered = -1;
			if(m_owner.m_million_exception_offered == m_player.m_id)
				m_owner.m_million_exception_offered = -1;
			m_list_ctrl.DeleteAllItems();
			m_list_ctrl_bid.DeleteAllItems();




			ListStats();

}

void CNegotiateDlg::OnSelchangeComboMidYears() 
{
	// TODO: Add your control notification handler code here


	
}
