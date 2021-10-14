// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "bballsettings.h"
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_checkBox = FALSE;
	m_checkPbp = FALSE;
	m_checkOffers = FALSE;
	m_checkScout = FALSE;
	m_checkActual = FALSE;
	m_checkCoach = FALSE;
	m_check3ft = FALSE;
	m_check3pt = FALSE;
	m_checkControl = FALSE;
	m_check_player_gm = FALSE;
	m_checkComputerTrading = FALSE;
	m_check_injury = FALSE;
	m_edit_games = 0;
	m_ast_gm = FALSE;
	m_check_finances = FALSE;
	m_check_show = FALSE;
	m_check_finances_on = FALSE;
	m_check_free_agency_on = FALSE;
	m_edit_cap = 0.0;
	m_check_deadline = FALSE;
	m_buttons[0].SetButtonFontSize(20);
	m_buttons[1].SetButtonFontSize(20);
	m_button_toggle_control.SetButtonFontSize(20);



	//}}AFX_DATA_INIT
//bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //               MAKEINTRESOURCE(IDB_BITMAP_BK)));

}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Control(pDX, IDOK, m_buttons[0]);
	DDX_Control(pDX, IDCANCEL, m_buttons[1]);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_BUTTON_SWITCH_ALL, m_button_toggle_control);
	DDX_Control(pDX, IDC_SLIDER_PACE, m_slider_pace);
	DDX_Check(pDX, IDC_CHECK_BOX, m_checkBox);
	DDX_Check(pDX, IDC_CHECK_SAVEPBP, m_checkPbp);
	DDX_Check(pDX, IDC_CHECK_OFFERS, m_checkOffers);
	DDX_Check(pDX, IDC_CHECK_SCOUT, m_checkScout);
	DDX_Check(pDX, IDC_CHECK_COACH, m_checkCoach);
	DDX_Check(pDX, IDC_CHECK_ACTUAL, m_checkActual);
	DDX_Check(pDX, IDC_CHECK_3FT, m_check3ft);
	DDX_Check(pDX, IDC_CHECK_3PT, m_check3pt);
	DDX_Check(pDX, IDC_CHECK_CONTROL, m_checkControl);
	DDX_Check(pDX, IDC_CHECK_GM_ON, m_check_player_gm);
	DDX_Check(pDX, IDC_CHECK_TRADING, m_checkComputerTrading);
	DDX_Check(pDX, IDC_CHECK_INJ, m_check_injury);
	DDX_Text(pDX, IDC_EDIT_GAMES, m_edit_games);
	DDV_MinMaxUInt(pDX, m_edit_games, 0, 99);
	DDX_Check(pDX, IDC_CHECK_ASST_GM, m_ast_gm);
	DDX_Check(pDX, IDC_CHECK_FINANCES, m_check_finances);
	DDX_Check(pDX, IDC_CHECK_SHOW, m_check_show);
	DDX_Check(pDX, IDC_CHECK_FINANCES_ON, m_check_finances_on);
	DDX_Check(pDX, IDC_CHECK_FREE_AGENCY_ON, m_check_free_agency_on);
	DDX_Text(pDX, IDC_EDIT_CAP, m_edit_cap);
	DDV_MinMaxDouble(pDX, m_edit_cap, 35.5, 9999.);
	DDX_Check(pDX, IDC_CHECK_DEADLINE, m_check_deadline);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	ON_BN_CLICKED(IDC_CHECK_BOX, OnCheckBox)
	ON_BN_CLICKED(IDC_CHECK_SAVEPBP, OnCheckSavepbp)
	ON_BN_CLICKED(IDC_CHECK_OFFERS, OnCheckOffers)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_CHECK_SCOUT, OnCheckScout)
	ON_BN_CLICKED(IDC_CHECK_ACTUAL, OnCheckActual)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_3FT, OnCheck3ft)
	ON_BN_CLICKED(IDC_CHECK_3PT, OnCheck3pt)
	ON_BN_CLICKED(IDC_CHECK_CONTROL, OnCheckControl)
	ON_BN_CLICKED(IDC_CHECK_GM_ON, OnCheckGmOn)
	ON_BN_CLICKED(IDC_CHECK_TRADING, OnCheckTrading)
	ON_BN_CLICKED(IDC_CHECK_INJ, OnCheckInj)
	ON_BN_CLICKED(IDC_CHECK_ASST_GM, OnCheckAsstGm)
	ON_BN_CLICKED(IDC_CHECK_FINANCES, OnCheckFinances)
	ON_BN_CLICKED(IDC_CHECK_SHOW, OnCheckShow)
	ON_BN_CLICKED(IDC_CHECK_FINANCES_ON, OnCheckFinancesOn)
	ON_BN_CLICKED(IDC_CHECK_FREE_AGENCY_ON, OnCheckFreeAgencyOn)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	ON_BN_CLICKED(IDC_BUTTON_SWITCH_ALL, OnButtonSwitchAll)
	ON_BN_CLICKED(IDC_CHECK_DEADLINE, OnCheckDeadline)
	ON_WM_PAINT()
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_CHECK_COACH, OnCheckCoaches)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

void COptionsDlg::OnOK()
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	int slot = m_slider_pace.GetPos();
	m_settings.m_scoring_factor = .75 + double(slot) * .05;
	slot = int(m_settings.m_scoring_factor * 100);
	m_settings.m_scoring_factor = (double)slot / 100;
	m_settings.m_injury_prompt = m_edit_games;


	m_settings.m_check3ft = m_check3ft;
	m_settings.m_check3pt = m_check3pt;
	m_settings.m_computerTrades = m_checkComputerTrading;
	m_settings.m_injury_prompt = m_edit_games;
	m_settings.m_ast_gm = m_ast_gm;
	m_settings.m_financial_on = m_check_finances_on;
	if (m_check_deadline == TRUE)
		m_settings.m_deadline_on = 1;
	else
		m_settings.m_deadline_on = 0;

	m_settings.m_salary_matching = m_check_finances;
	m_settings.m_free_agency_on = m_check_free_agency_on;
	m_settings.m_cap = int(m_edit_cap * 100.);


	//		pDoc->avg.m_settings = options.m_settings;
	//		pDoc->avg.m_settings.m_injury_prompt = options.m_edit_games; 
	//		pDoc->avg.m_settings.m_computerTrades = options.m_checkComputerTrading;


	CDialog::OnOK();
}

BOOL COptionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.
//	SetFont(&m_font, TRUE);
	m_brush.CreateSolidBrush(DLGCOLOR);
	//Handle the WM_CTLCOLOR message in your dialog and in the OnCtlColor function, add this code.     m_brush.CreateSolidBrush(RGB(150,50,100));






	int bytes = 0;
	m_number_teams = 0;
	for (int i = 0; i <= 31; i++)
	{
		if (m_leagueTeamNames[i] != "")
		{
			m_listTeams.AddString(m_leagueTeamNames[i]);
			m_number_teams = m_number_teams + 1;
			m_original_control[i] = m_settings.m_control[i];
		}
	}





	m_slider_pace.SetRangeMin(1, FALSE);
	m_slider_pace.SetRangeMax(9, FALSE);
	int slot = int(m_settings.m_scoring_factor * 10);
	if (slot == 0) slot = 10;
	slot = 1 + 2 * (slot - 8);
	m_slider_pace.SetPos(slot);

	m_edit_cap = m_settings.m_cap / 100;
	m_edit_games = m_settings.m_injury_prompt;
	m_checkComputerTrading = m_settings.m_computerTrades;
	m_check3ft = m_settings.m_check3ft;
	m_check3pt = m_settings.m_check3pt;
	m_check_finances = m_settings.m_salary_matching;
	m_check_finances_on = m_settings.m_financial_on;
	if (m_settings.m_deadline_on == 1)
		m_check_deadline = TRUE;
	else
		m_check_deadline = FALSE;

	m_check_free_agency_on = m_settings.m_free_agency_on;
	m_ast_gm = m_settings.m_ast_gm;

	int row = m_default_team;
	m_listTeams.SetCurSel(row);
	if (m_settings.m_show_box[row] == 0) m_check_show = FALSE; else m_check_show = TRUE;
	if (m_settings.m_save_box[row] == 0) m_checkBox = FALSE; else m_checkBox = TRUE;
	if (m_settings.m_save_pbp[row] == 0) m_checkPbp = FALSE; else m_checkPbp = TRUE;
	if (m_settings.m_get_offers[row] == 0) m_checkOffers = FALSE; else m_checkOffers = TRUE;
	if (m_settings.m_control[row] == "Computer") m_checkControl = FALSE; else m_checkControl = TRUE;

	if (m_settings.m_scouts[row] == 0) m_checkScout = FALSE; else m_checkScout = TRUE;
	//if(m_settings.m_coaches[row] == 0) m_checkCoach = TRUE; else m_checkCoach = FALSE;
	//if(m_settings.m_scouts[32] == 0) m_checkActual = FALSE; else m_checkActual = TRUE;
	if (m_settings.m_coaches[32] == 0 && m_settings.m_scouts[32] == 0)
	{
		m_checkCoach = FALSE;
		m_checkActual = FALSE;
	}
	else if (m_settings.m_coaches[32] == 0 && m_settings.m_scouts[32] == 1)
	{
		m_checkCoach = TRUE;
		m_checkActual = FALSE;
	}
	else if (m_settings.m_coaches[32] == 1 && m_settings.m_scouts[32] == 0)
	{
		m_checkCoach = FALSE;
		m_checkActual = TRUE;
	}
	else
	{
		m_checkCoach = FALSE;
		m_checkActual = TRUE;
	}



	if (m_settings.m_player_gm[row] == "" || m_settings.m_player_gm[row] != "Player")
		m_check_player_gm = FALSE; else m_check_player_gm = TRUE;


	if (m_settings.m_scouts[32] == 0)
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(FALSE);

	//if(m_settings.m_coaches[32] == 0)
		//GetDlgItem(IDC_CHECK_COACH)->EnableWindow(TRUE);		
	//else
	  //  GetDlgItem(IDC_CHECK_COACH)->EnableWindow(FALSE);		

	if (m_edit_games == 0)
	{
		m_check_injury = FALSE;
		GetDlgItem(IDC_EDIT_GAMES)->EnableWindow(FALSE);
	}
	else
	{
		m_check_injury = TRUE;
		GetDlgItem(IDC_EDIT_GAMES)->EnableWindow(TRUE);
	}


	m_all_player_controlled = true;
	for (int i = 0; i <= 31; i++)
	{
		if (m_settings.m_player_gm[i] != "Player") m_all_player_controlled = false;
	}

	if (m_all_player_controlled == true)
		m_button_toggle_control.SetWindowText("Set All Teams to Computer Controlled");
	else
		m_button_toggle_control.SetWindowText("Set All Teams to Player Controlled");

	UpdateButtons();


	UpdateData(FALSE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsDlg::OnCheckBox()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_save_box[index] == 0)
	{
		m_settings.m_save_box[index] = 1;
		m_checkBox = TRUE;
	}
	else
	{
		m_settings.m_save_box[index] = 0;
		m_checkBox = FALSE;
	}
	UpdateData(FALSE);


}

void COptionsDlg::OnCheckSavepbp()
{
	// TODO: Add your control notification handler code here

	int index = m_listTeams.GetCurSel();
	if (m_settings.m_save_pbp[index] == 0)
	{
		m_settings.m_save_pbp[index] = 1;
		m_checkPbp = TRUE;
	}
	else
	{
		m_settings.m_save_pbp[index] = 0;
		m_checkPbp = FALSE;
	}
	UpdateData(FALSE);

}

void COptionsDlg::OnCheckOffers()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_get_offers[index] == 0)
	{
		m_settings.m_get_offers[index] = 1;
		m_checkOffers = TRUE;
	}
	else
	{
		m_settings.m_get_offers[index] = 0;
		m_checkOffers = FALSE;
	}
	UpdateData(FALSE);
}

void COptionsDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/setupsettings.htm", HH_DISPLAY_TOPIC, 0);

//	return CDialog::OnHelpInfo(pHelpInfo);

}

BOOL COptionsDlg::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//return TRUE;

//	HtmlHelp(NULL, "jumpshot.chm::/html/setupsettings.htm", HH_DISPLAY_TOPIC, 0);

	return CDialog::OnHelpInfo(pHelpInfo);


}

void COptionsDlg::OnCheckScout()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_scouts[index] == 0)
	{
		m_settings.m_scouts[index] = 1;
		m_checkScout = TRUE;
	}
	else
	{
		m_settings.m_scouts[index] = 0;
		m_checkScout = FALSE;
	}
	for (int i = 0; i <= 31; i++)
	{
		if (i != index) { m_settings.m_scouts[i] = 0; }
	}

	//	if(m_settings.m_coaches[index] == 0)
	//	{
	//		m_settings.m_coaches[index] = 1;
	//		m_checkCoach = FALSE;
	//	}
	//	else
	//	{
	//		m_settings.m_coaches[index] = 0;
	//		m_checkCoach = TRUE;
	//	}
	//	for(int i=0; i<=31; i++)
	//	{
	//		if(i != index) m_settings.m_coaches[i] = 0;
	//	}
	UpdateData(FALSE);

}

void COptionsDlg::OnCheckActual()
{
	// TODO: Add your control notification handler code here
	if (m_checkActual == FALSE)
	{
		m_settings.m_scouts[32] = 1;
		m_settings.m_coaches[32] = 1;
		m_checkActual = TRUE;
		m_checkCoach = FALSE;
		//m_settings.m_coaches[32] = 1;}
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(FALSE);
		//GetDlgItem(IDC_CHECK_COACH)->EnableWindow(FALSE);		
		for (int i = 0; i <= 31; i++)
		{
			m_settings.m_scouts[i] = 0;
			m_checkScout = FALSE;
		}
	}
	else if (m_settings.m_scouts[32] == 0)
	{
		m_settings.m_scouts[32] = 1;
		m_settings.m_coaches[32] = 1;
		m_checkActual = TRUE;
		if (m_checkCoach == TRUE) { m_checkCoach = FALSE; m_settings.m_coaches[32] = 1; }
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(FALSE);
		//GetDlgItem(IDC_CHECK_COACH)->EnableWindow(FALSE);		
		for (int i = 0; i <= 31; i++)
		{
			m_settings.m_scouts[i] = 0;
			m_checkScout = FALSE;
		}
	}
	else
	{
		m_settings.m_scouts[32] = 0;
		m_checkActual = FALSE;
		m_settings.m_coaches[32] = 0;
		m_checkCoach = FALSE;
		//m_checkCoach = TRUE;
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(TRUE);
		//if(m_checkCoach == TRUE) {m_checkCoach = FALSE; m_settings.m_coaches[32] = 1;}
		//GetDlgItem(IDC_CHECK_COACH)->EnableWindow(TRUE);		
	}
	UpdateData(FALSE);

}

HBRUSH COptionsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	//	Invalidate(FALSE);
		//Default();

	switch (nCtlColor)
	{
		//Edit controls need white background and black text
		//Note the 'return hbr' which is needed to draw the Edit
		//control's internal background (as opposed to text background)
	case CTLCOLOR_LISTBOX:
		//pDC->SetBkColor(RGB(69,94,137);
		//pDC -> SetDCBrushColor(RGB(255, 0, 0));
		//pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return hbr;

		//pDC->SetBkColor(LISTBOXCOLOR);
		//pDC->SetBkColor(DARKBLUE);
		//pDC->SetTextColor(LISTBOXTEXTCOLOR);

	case CTLCOLOR_EDIT:
		pDC->SetTextColor(EDITCOLOR);
		pDC->SetBkColor(EDITBKCOLOR);
		//pDC->SetBkColor(BUTTONFACECOLOR2);
		return hbr;
		//Static controls need black text and same background as m_brush
	case CTLCOLOR_STATIC:
		LOGBRUSH logbrush;
		m_brush.GetLogBrush(&logbrush);
		pDC->SetTextColor(STATICCOLOR);
		pDC->SetBkColor(logbrush.lbColor);
		return m_brush;
	case CTLCOLOR_BTN:
		pDC->SetTextColor(RGB(0, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return m_brush;
	case CTLCOLOR_SCROLLBAR:
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(LISTBOXCOLOR);
		return m_brush;

	case CTLCOLOR_MSGBOX:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return m_brush;

	case CTLCOLOR_DLG:
		return m_brush;
		//This shouldn't occurr since we took all the cases, but
		//JUST IN CASE, return the new brush
	default:
		return hbr;
	}


}

void COptionsDlg::OnCheck3ft()
{
	// TODO: Add your control notification handler code here
	if (m_check3ft == FALSE)
		m_check3ft = TRUE;
	else
		m_check3ft = FALSE;

	UpdateData(FALSE);

}

void COptionsDlg::OnCheck3pt()
{
	// TODO: Add your control notification handler code here
	if (m_check3pt == FALSE)
	{
		m_check3pt = TRUE;
		GetDlgItem(IDC_CHECK_3FT)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_CHECK_3FT)->EnableWindow(TRUE);
		m_check3pt = FALSE;
		m_check3ft = FALSE;
	}

	UpdateData(FALSE);


}

void COptionsDlg::OnCheckControl()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_control[index] == "Computer")
	{
		m_settings.m_control[index] = "Player";
		m_checkControl = TRUE;
	}
	else
	{
		m_settings.m_control[index] = "Computer";
		m_checkControl = FALSE;
	}
	UpdateData(FALSE);
}

void COptionsDlg::OnCheckGmOn()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_player_gm[index] != "Player")
	{
		m_settings.m_player_gm[index] = "Player";
		m_check_player_gm = TRUE;
	}
	else
	{
		m_settings.m_player_gm[index] = "Computer";
		m_check_player_gm = FALSE;
	}
	UpdateData(FALSE);

}

void COptionsDlg::OnCheckTrading()
{
	// TODO: Add your control notification handler code here
	if (m_checkComputerTrading == FALSE)
		m_checkComputerTrading = TRUE;
	else
		m_checkComputerTrading = FALSE;

	UpdateData(FALSE);
}

void COptionsDlg::OnCheckInj()
{
	// TODO: Add your control notification handler code here

	if (m_check_injury == TRUE)
	{
		m_check_injury = FALSE;
		m_edit_games = 0;
		GetDlgItem(IDC_EDIT_GAMES)->EnableWindow(FALSE);
	}
	else if (m_check_injury == FALSE)
	{
		m_check_injury = TRUE;
		m_edit_games = 5;
		GetDlgItem(IDC_EDIT_GAMES)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}

void COptionsDlg::OnCheckAsstGm()
{
	// TODO: Add your control notification handler code here
	if (m_ast_gm == FALSE)
		m_ast_gm = TRUE;
	else
		m_ast_gm = FALSE;

}

void COptionsDlg::OnCheckFinances()
{
	// TODO: Add your control notification handler code here
	if (m_check_finances == FALSE)
		m_check_finances = TRUE;
	else
		m_check_finances = FALSE;
	UpdateData(FALSE);

}

void COptionsDlg::OnCheckShow()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_show_box[index] == 0)
	{
		m_settings.m_show_box[index] = 1;
		m_check_show = TRUE;
	}
	else
	{
		m_settings.m_show_box[index] = 0;
		m_check_show = FALSE;
	}
	UpdateData(FALSE);

}

void COptionsDlg::OnCheckFinancesOn()
{
	// TODO: Add your control notification handler code here
	if (m_check_finances_on == FALSE)
		m_check_finances_on = TRUE;
	else
		m_check_finances_on = FALSE;

	UpdateData(FALSE);

}

void COptionsDlg::OnCheckFreeAgencyOn()
{
	// TODO: Add your control notification handler code here
	if (m_check_free_agency_on == FALSE)
		m_check_free_agency_on = TRUE;
	else
		m_check_free_agency_on = FALSE;

	UpdateData(FALSE);

}

void COptionsDlg::OnSelchangeComboTeams()
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	if (m_settings.m_save_box[index] == 0) m_checkBox = FALSE;
	else m_checkBox = TRUE;

	if (m_settings.m_show_box[index] == 0) m_check_show = FALSE;
	else m_check_show = TRUE;

	if (m_settings.m_save_pbp[index] == 0) m_checkPbp = FALSE;
	else m_checkPbp = TRUE;

	if (m_settings.m_get_offers[index] == 0) m_checkOffers = FALSE;
	else m_checkOffers = TRUE;

	if (m_settings.m_control[index] == "Computer") m_checkControl = FALSE;
	else m_checkControl = TRUE;

	if (m_settings.m_scouts[index] == 0) m_checkScout = FALSE;
	else m_checkScout = TRUE;

	//	if(m_settings.m_coaches[index] == 0) m_checkCoach = FALSE;
	//	else m_checkCoach = TRUE;

	if (m_settings.m_player_gm[index] == "" || m_settings.m_player_gm[index] != "Player")
		m_check_player_gm = FALSE;
	else m_check_player_gm = TRUE;

	if (m_settings.m_scouts[32] == 0) m_checkActual = FALSE;
	else m_checkActual = TRUE;

	//	if(m_settings.m_coaches[32] == 0) m_checkCoach = FALSE;
	//	else m_checkCoach = TRUE;
	UpdateData(FALSE);
}

void COptionsDlg::OnButtonHelp()
{
	// TODO: Add your control notification handler code here
	//WinHelp(HID_PLAY_OPTIONS);


//	HtmlHelp(NULL, "jumpshot.chm::/html/setupsettings.htm", HH_DISPLAY_TOPIC, 0);

//html/afxc6bc5.htm

}


void COptionsDlg::OnButtonSwitchAll()
{
	// TODO: Add your control notification handler code here




	if (m_all_player_controlled == true)
	{
		m_all_player_controlled = false;
		m_check_player_gm = FALSE;
		m_button_toggle_control.SetWindowText("Set All Teams to Player Controlled");
		for (int i = 0; i <= 32; i++)
		{
			m_settings.m_player_gm[i] = "Computer";
		}
	}
	else
	{
		m_all_player_controlled = true;
		m_check_player_gm = TRUE;
		m_button_toggle_control.SetWindowText("Set All Teams to Computer Controlled");
		for (int i = 0; i <= 32; i++)
		{
			m_settings.m_player_gm[i] = "Player";
		}
	}

	UpdateData(FALSE);

}

void COptionsDlg::OnCheckDeadline()
{
	// TODO: Add your control notification handler code here
	if (m_check_deadline == FALSE)
		m_check_deadline = TRUE;
	else
		m_check_deadline = FALSE;

	UpdateButtons();
	UpdateData(FALSE);


}

void COptionsDlg::UpdateButtons()
{

	CString months[] = { "Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Post" };


	CString text = "Trade Deadline Off";
	if (m_check_deadline == TRUE)
		text.Format("Trade Deadline (%s %d)", months[m_dead_mo], m_dead_da + 1);


	for (int i = 0; i <= 1; i++)
	{
		m_buttons[i].SetFaceColor(BUTTONFACECOLOR2);
		m_buttons[i].SetTextColor(BUTTONTEXTCOLOR2);
	}


	GetDlgItem(IDC_CHECK_DEADLINE)->SetWindowText(text);
}

void COptionsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here



//	CRect rc;
//		GetWindowRect(&rc);
//		ScreenToClient(&rc);
//		CBrush brush(SCREENCOLOR);
//		dc.FillRect(rc, &brush);
//		dc.SelectStockObject(ANSI_VAR_FONT);
//		dc.DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);	



	// Do not call CDialog::OnPaint() for painting messages
}

void COptionsDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// TODO: Add your message handler code here

}

void COptionsDlg::OnCheckCoaches()
{
	// TODO: Add your control notification handler code here
	if (m_settings.m_coaches[32] == 0 && m_settings.m_scouts[32] == 0)
	{
		m_settings.m_coaches[32] = 0;
		m_settings.m_scouts[32] = 1;
		m_checkCoach = TRUE;
		m_checkActual = FALSE;
		//GetDlgItem(IDC_CHECK_ACTUAL)->EnableWindow(FALSE);	



//		for(int i=0; i<=31; i++)
//		{
//		   m_settings.m_coaches[i] = 0;
//		}
	}
	else if (m_settings.m_coaches[32] == 1 && m_settings.m_scouts[32] == 1)
	{
		m_settings.m_coaches[32] = 0;
		m_settings.m_scouts[32] = 1;
		m_checkCoach = TRUE;
		m_checkActual = FALSE;
		//GetDlgItem(IDC_CHECK_ACTUAL)->EnableWindow(FALSE);	



//		for(int i=0; i<=31; i++)
//		{
//		   m_settings.m_coaches[i] = 0;
//		}
	}
	else if (m_settings.m_coaches[32] == 0 && m_settings.m_scouts[32] == 1)
	{
		m_settings.m_coaches[32] = 0;
		m_settings.m_scouts[32] = 0;
		m_checkCoach = FALSE;
		//m_checkActual = TRUE;
		//GetDlgItem(IDC_CHECK_ACTUAL)->EnableWindow(FALSE);	



//		for(int i=0; i<=31; i++)
//		{
//		   m_settings.m_coaches[i] = 0;
//		}
	}
	else
	{
		m_settings.m_coaches[32] = 0;
		m_settings.m_scouts[32] = 1;
		m_checkCoach = TRUE;
		if (m_checkActual == TRUE) m_checkActual = FALSE;
		GetDlgItem(IDC_CHECK_SCOUT)->EnableWindow(FALSE);

		//m_checkActual = FALSE;
		//GetDlgItem(IDC_CHECK_ACTUAL)->EnableWindow(TRUE);		
	}
	UpdateData(FALSE);
}

