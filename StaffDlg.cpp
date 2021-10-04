// StaffDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "StaffDlg.h"
#include "ScoutProfileDlg.h"
//#include "Record.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaffDlg dialog


CStaffDlg::CStaffDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaffDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaffDlg)
	//}}AFX_DATA_INIT
	names = new CCareer;
}


void CStaffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaffDlg)
	DDX_Control(pDX, IDC_RADIO_SCOUT, m_radioScout);
	DDX_Control(pDX, IDC_RADIO_COACH_SCOUT, m_radioCoachScout);
	DDX_Control(pDX, IDC_RADIO_COACH_GAME, m_radioCoachGame);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDC_COMBO_STAFF_TEAMS, m_listTeams);
	DDX_Control(pDX, IDOK, m_buttonOK);
	DDX_Control(pDX, IDC_BUTTON_END, m_buttonEnd);
	DDX_Control(pDX, IDC_LIST_FIRINGS, m_lisFirings);
	DDX_Control(pDX, IDC_BUTTON_FIRINGS, m_buttonFirings);
	DDX_Control(pDX, IDC_LIST_ACCEPT, m_listAccept);
	DDX_Control(pDX, IDC_LIST_OFFERS, m_listOffers);
	DDX_Control(pDX, IDC_BUTTON_OFFER, m_buttonOffer);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listControl);
	DDX_Control(pDX, IDC_LIST_CTRL_STAFF, m_listCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStaffDlg, CDialog)
	//{{AFX_MSG_MAP(CStaffDlg)
	ON_LBN_SELCHANGE(IDC_LIST_CONTROL, OnSelchangeListControl)
	ON_BN_CLICKED(IDC_RADIO_COACH, OnRadioCoach)
	ON_BN_CLICKED(IDC_RADIO_GM, OnRadioGm)
	ON_BN_CLICKED(IDC_RADIO_SCOUT, OnRadioScout)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CTRL_STAFF, OnColumnclickListCtrlStaff)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_STAFF, OnDblclkListCtrlStaff)
	ON_BN_CLICKED(IDC_BUTTON_OFFER, OnButtonOffer)
	ON_BN_CLICKED(IDC_BUTTON_FIRINGS, OnButtonFirings)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_STAFF, OnClickListCtrlStaff)
	ON_BN_CLICKED(IDC_RADIO_COACH_SCOUT, OnRadioCoachScout)
	ON_BN_CLICKED(IDC_RADIO_COACH_GAME, OnRadioCoachGame)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO_STAFF_TEAMS, OnSelchangeComboStaffTeams)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_STAFF, &CStaffDlg::OnLvnItemchangedListCtrlStaff)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaffDlg message handlers


void CStaffDlg::OnSelchangeListControl() 
{
	// TODO: Add your control notification handler code here
	int index = m_listTeams.GetCurSel();
	CString control = m_control[index];
	if(control == "Player") control = "Computer"; else if(control == "Computer") control = "Player";
	m_control[index] = control;

	ListControl();
	EnableOfferButton();
}

void CStaffDlg::OnRadioCoach() 
{
	// TODO: Add your control notification handler code here
//	SetCoachListCtrl();	
	m_radioCoachScout.EnableWindow(TRUE);
	m_radioCoachGame.EnableWindow(TRUE);
	m_category = 2;
	if(m_coachCategory == 1)
	{
        StaffColumns();
	    SortStaff();
//	    ListCoach();
	}
	else
	{
		CoachColumns();
		SortCoach();
//		ListGameCoach();
	}
//	SetCoachListCtrl();
}

void CStaffDlg::OnRadioGm() 
{
	// TODO: Add your control notification handler code here
//	SetGmListCtrl();	
	m_radioCoachScout.EnableWindow(FALSE);
	m_radioCoachGame.EnableWindow(FALSE);
	if(m_coachCategory == 2 )
	{
		m_changeHeading = true;
		m_coachCategory = 1;
		CheckDlgButton(IDC_RADIO_COACH_SCOUT, 1);	
		CheckDlgButton(IDC_RADIO_COACH_GAME, 0);	
//		UpdateData(FALSE);
	}
	m_category = 3;
	StaffColumns();
	SortStaff();
	
}

void CStaffDlg::OnRadioScout() 
{
	// TODO: Add your control notification handler code here
//	SetScoutListCtrl();	
	m_radioCoachScout.EnableWindow(FALSE);
	m_radioCoachGame.EnableWindow(FALSE);
	if(m_coachCategory == 2 )
	{
		m_changeHeading = true;
		m_coachCategory = 1;
		CheckDlgButton(IDC_RADIO_COACH_SCOUT, 1);	
		CheckDlgButton(IDC_RADIO_COACH_GAME, 0);	
//		UpdateData(FALSE);
	}

	m_category = 1;
	StaffColumns();
	SortStaff();
}

void CStaffDlg::OnOK() 
{
	// TODO: Add extra validation here
		

	
	OrderList();
	m_hiring_ok = false;
	CDialog::OnOK();
}

BOOL CStaffDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/search.htm", HH_DISPLAY_TOPIC, 0);
//	HtmlHelp(NULL, "jumpshot.chm::/html/staffs.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
	return CDialog::OnHelpInfo(pHelpInfo);

//	WinHelp(HID_CAREER_STAFF);
//	return TRUE;	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CStaffDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_CAREER_STAFF);
//	HtmlHelp(NULL, "jumpshot.chm::/html/staffs.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CStaffDlg::SetGmListCtrl()
{
	m_listCtrl.DeleteColumn(0);
    m_listCtrl.InsertColumn(0,"GM");    
}

void CStaffDlg::SetScoutListCtrl()
{	
	m_listCtrl.DeleteColumn(0);
    m_listCtrl.InsertColumn(0,"Scout");    

}

void CStaffDlg::SetCoachListCtrl()
{
	m_listCtrl.DeleteColumn(0);
    m_listCtrl.InsertColumn(0,"Coach");    

}

BOOL CStaffDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	m_buttonOK.EnableWindow(FALSE);
	m_buttonEnd.SetWindowText("Check Hirings");


	if(avg.m_settings.m_scouts[32] == 1 && avg.m_settings.m_coaches[32] == 0)
	{
		CheckDlgButton(IDC_RADIO_COACH, 1);	
		GetDlgItem(IDC_RADIO_SCOUT)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO_GM)->ShowWindow(FALSE);
		m_category = 2;
	}
	else
	{
		CheckDlgButton(IDC_RADIO_SCOUT, 1);	
		m_category = 1;
	}


	m_firingsCompleted = false;
	m_buttonOffer.EnableWindow(FALSE);
	m_buttonEnd.EnableWindow(FALSE);
	PassMembers();
	SetInterest();
	SetVariables();
	InitListCtrl();


	if(avg.m_settings.m_scouts[32] == 1 && avg.m_settings.m_coaches[32] == 0)
	{
		OnRadioCoach();
	}
	else
	{
		OnRadioScout();
	}




	//m_hiring_ok = true;
	if(m_hiring_ok == false) 
	{
		m_firingsCompleted = true;
		m_buttonEnd.EnableWindow(FALSE);
		m_buttonFirings.EnableWindow(FALSE);
		m_buttonOffer.EnableWindow(FALSE);
		m_buttonOK.EnableWindow(FALSE);

		m_buttonEnd.ShowWindow(FALSE);
		m_buttonFirings.ShowWindow(FALSE);
		m_buttonOffer.ShowWindow(FALSE);
		m_buttonOK.ShowWindow(FALSE);

		m_button_cancel.SetWindowText("Exit");

	}
	
	ListControl();
//	:.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
//	m_listTeams.EnsureVisible(0, TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStaffDlg::ListCoach()
{
	int co = 0;
	CString string[99];

//	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};

	CString lbl[] = {"", "F", "D", "C-", "C", "C+", "B", "A"};

for(int pl=0; pl<=99; pl++)
{
	CStaff m_player = m_coachCopy[pl];
	CString name = m_player.m_name;
	CString team = m_player.m_team;
	if(name == "") continue;
	if(team == "") team = "none";
	m_listCtrl.InsertItem(co,name);
	m_listCtrl.SetItemText(co,1,team);

	string[0].Format("%d", m_player.m_age);
	string[1].Format("%s", lbl[m_player.m_pot1Rating]);
	string[2].Format("%s", lbl[m_player.m_pot2Rating]);
	string[3].Format("%s", lbl[m_player.m_effortRating]);
	string[4].Format("%s", lbl[m_player.m_scoringRating]);
	string[5].Format("%s", lbl[m_player.m_shootingRating]);
	string[6].Format("%s", lbl[m_player.m_reboundingRating]);
	string[7].Format("%s", lbl[m_player.m_passingRating]);
	string[8].Format("%s", lbl[m_player.m_defenseRating]);

	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[9].Format("%d", win);
	string[10].Format("%d", loss);
	string[11].Format("%d", m_player.m_playoffs);
	string[12].Format("%d", m_player.m_rings);

	for(int i=0; i<=12; i++)
	{
		m_listCtrl.SetItemText(co,i+2,string[i]);
	}
	
	CString status = m_player.m_status;
	m_listCtrl.SetItemText(co,15,status);

	co = co + 1;
}

m_listCtrl.SetItemState(m_row,LVIS_SELECTED,LVIS_SELECTED);

	EnableOfferButton();


}

void CStaffDlg::ListGM()
{
//	StaffColumns();
	int co = 0;
	CString string[99];
//	CString lbl[] = {"", "very low", "poor", "below average", "average", "good", "very good", "excellent"};
	CString lbl[] = {"", "F", "D", "C-", "C", "C+", "B", "A"};

for(int pl=0; pl<=99; pl++)
{
	CStaff m_player = m_gmCopy[pl];
	CString name = m_player.m_name;
	CString team = m_player.m_team;
	if(name == "") continue;
	if(team == "") team = "none";
	m_listCtrl.InsertItem(co,name);
	m_listCtrl.SetItemText(co,1,team);

	string[0].Format("%d", m_player.m_age);
	string[1].Format("%s", lbl[m_player.m_pot1Rating]);
	string[2].Format("%s", lbl[m_player.m_pot2Rating]);
	string[3].Format("%s", lbl[m_player.m_effortRating]);
	string[4].Format("%s", lbl[m_player.m_scoringRating]);
	string[5].Format("%s", lbl[m_player.m_shootingRating]);
	string[6].Format("%s", lbl[m_player.m_reboundingRating]);
	string[7].Format("%s", lbl[m_player.m_passingRating]);
	string[8].Format("%s", lbl[m_player.m_defenseRating]);
	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[9].Format("%d", win);
	string[10].Format("%d", loss);
	string[11].Format("%d", m_player.m_playoffs);
	string[12].Format("%d", m_player.m_rings);

	for(int i=0; i<=12; i++)
	{
		m_listCtrl.SetItemText(co,i+2,string[i]);
	}
	
	CString status = m_player.m_status;
	m_listCtrl.SetItemText(co,15,status);

	co = co + 1;
}

m_listCtrl.SetItemState(m_row,LVIS_SELECTED,LVIS_SELECTED);

	EnableOfferButton();

}

void CStaffDlg::ListScout()
{
//    StaffColumns();
	int co = 0;
	CString string[99];

	CString lbl[] = {"", "F", "D", "C-", "C", "C+", "B", "A"};


for(int pl=0; pl<=99; pl++)
{
	CStaff m_player = m_scoutCopy[pl];
	CString name = m_player.m_name;
	CString team = m_player.m_team;
	if(name == "") continue;
	if(team == "") team = "none";
	m_listCtrl.InsertItem(co,name);
	m_listCtrl.SetItemText(co,1,team);
	string[0].Format("%d", m_player.m_age);
	string[1].Format("%s", lbl[m_player.m_pot1Rating]);
	string[2].Format("%s", lbl[m_player.m_pot2Rating]);
	string[3].Format("%s", lbl[m_player.m_effortRating]);
	string[4].Format("%s", lbl[m_player.m_scoringRating]);
	string[5].Format("%s", lbl[m_player.m_shootingRating]);
	string[6].Format("%s", lbl[m_player.m_reboundingRating]);
	string[7].Format("%s", lbl[m_player.m_passingRating]);
	string[8].Format("%s", lbl[m_player.m_defenseRating]);
	int win = m_player.m_win;
	int loss = m_player.m_loss;
	string[9].Format("%d", win);
	string[10].Format("%d", loss);
	string[11].Format("%d", m_player.m_playoffs);
	string[12].Format("%d", m_player.m_rings);

//	m_listCtrl.InsertItem(co,name);
	for(int i=0; i<=12; i++)
	{
		m_listCtrl.SetItemText(co,i+2,string[i]);
	}
	
	CString status = m_player.m_status;
	m_listCtrl.SetItemText(co,15,status);

	co = co + 1;
}

m_listCtrl.SetItemState(m_row,LVIS_SELECTED,LVIS_SELECTED);

	EnableOfferButton();


}

void CStaffDlg::InitListCtrl()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listCtrl.SetBkColor(BK_COLOR);
	m_listCtrl.SetTextBkColor(BK_COLOR);

	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
//    StaffColumns();

    m_listCtrl.SetTextColor(RGB(0,0,0));
	m_listCtrl.SetFont(&m_font);

	m_numberTeams = 0;
	for(int i=0; i<=32; i++)
	{
		if(m_leagueTeamNames[i] != "")
		{
			m_listTeams.AddString(m_leagueTeamNames[i]);
			m_numberTeams = m_numberTeams + 1;
		}
	}
	m_listTeams.SetCurSel(m_default_team);
//	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);

}

void CStaffDlg::SetVariables()
{

	m_set_cursor = true;
	m_row = 0;
	int count = 0;
	CString nm[101];
	nm[0] = "Jack Johnson";
	nm[1] = "Cassius Clay";
	nm[2] = "Rocky Marciano";
	nm[3] = "Mike Tyson";
	nm[4] = "Evander Holyfield";
	nm[5] = "Joe Louis";
	nm[6] = "Joe Frazier";
	nm[7] = "Larry Holmes";
	nm[8] = "Jack Dempsey";
	nm[9] = "Ima Messup";
	nm[10] = "Uma Tryin";
	for(int i=0; i<= 99; i++)
	{
		if(i<=32 && m_owner[i].m_hiredScoutOnce != false) 
			m_owner[i].m_hiredScoutOnce = false;
		if(i<=32 && m_owner[i].m_hiredCoachOnce != false) 
			m_owner[i].m_hiredCoachOnce = false;
		if(i<=32 && m_owner[i].m_hiredGmOnce != false) 
			m_owner[i].m_hiredGmOnce = false;


		if(m_scout[i].m_name == "")
		{
			m_scout[i].m_name = nm[count];
			m_scout[i].m_age = 50;
			count = count + 1;
			if(count == 11) count = 0;
		}
		if(m_coach[i].m_name == "")
		{
			m_coach[i].m_name = nm[count];
			m_scout[i].m_age = 50;
			count = count + 1;
			if(count == 11) count = 0;
		}
		if(m_gm[i].m_name == "")
		{
			m_gm[i].m_name = nm[count];
			m_scout[i].m_age = 50;
			count = count + 1;
			if(count == 11) count = 0;
		}

		m_scoutCopy[i] = m_scout[i];
		m_coachCopy[i] = m_coach[i];
		m_gmCopy[i] = m_gm[i];
		m_owner[i].m_madeScoutOffer = false;
		m_owner[i].m_madeCoachOffer = false;
		m_owner[i].m_madeGmOffer = false;
	}
	m_coachCategory = 1;
	m_changeHeading = true;
}

void CStaffDlg::OnColumnclickListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_set_cursor = false;
	m_column = pNMListView->iSubItem;
	if(m_column >= 0 && m_firingsCompleted == true && m_category != 2) SortStaff();
	else if(m_column >= 0 && m_firingsCompleted == true && m_category == 2 && m_coachCategory == 2) SortCoach();
	else if(m_column >= 0 && m_firingsCompleted == true && m_category == 2 && m_coachCategory != 2) SortStaff();

	m_row = 0;
	m_listCtrl.SetItemState(m_row ,LVIS_SELECTED,LVIS_SELECTED);
	m_listCtrl.EnsureVisible(m_row, TRUE);


}

void CStaffDlg::SortStaff()
{
m_listCtrl.DeleteAllItems();
CStaff m_staff_i, m_staff_j;

for(int i=0; i<=99; i++)
{
for(int j=0; j<=99; j++)
{


bool swap = false;

if(m_category == 1)
{
	m_staff_i = m_scoutCopy[i];
	m_staff_j = m_scoutCopy[j];
}
else if(m_category == 2)
{
	m_staff_i = m_coachCopy[i];
	m_staff_j = m_coachCopy[j];
}
else if(m_category == 3)
{
	m_staff_i = m_gmCopy[i];
	m_staff_j = m_gmCopy[j];
}

int win_i = m_staff_i.m_win;
int loss_i = m_staff_i.m_loss;
int win_j = m_staff_j.m_win;
int loss_j = m_staff_j.m_loss;


switch(m_column) 
{

    case 0:
		swap = m_staff_i.m_name < m_staff_j.m_name;
        break;
    case 1:
		swap = m_staff_i.m_team < m_staff_j.m_team;
        break;
    case 2:        
		swap = m_staff_i.m_age > m_staff_j.m_age;
        break;
    case 3:
		swap = m_staff_i.m_pot1Rating > m_staff_j.m_pot1Rating;
        break;
    case 4:
		swap = m_staff_i.m_pot2Rating > m_staff_j.m_pot2Rating;
        break;
    case 5:
		swap = m_staff_i.m_effortRating > m_staff_j.m_effortRating;
        break;
    case 6:
		swap = m_staff_i.m_scoringRating > m_staff_j.m_scoringRating;
        break;
    case 7:
		swap = m_staff_i.m_shootingRating > m_staff_j.m_shootingRating;
        break;
    case 8:
		swap = m_staff_i.m_reboundingRating > m_staff_j.m_reboundingRating;
        break;
    case 9:
		swap = m_staff_i.m_passingRating > m_staff_j.m_passingRating;
        break;
    case 10:
		swap = m_staff_i.m_defenseRating > m_staff_j.m_defenseRating;
        break;
    case 11:
		swap = win_i > win_j;
        break;
    case 12:
		swap = loss_i > loss_j;
        break;
    case 13:
		swap = m_staff_i.m_playoffs > m_staff_j.m_playoffs;
        break;
    case 14:
		swap = m_staff_i.m_rings > m_staff_j.m_rings;
        break;
    case 15:
		swap = m_staff_i.m_status > m_staff_j.m_status;
        break;
    case 16:
//		swap = m_staff_i.m_loyalty > m_staff_j.m_loyalty;
        break;
    case 17:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
}



	if(swap == true && m_category == 1)
	{//swap
		CStaff temp = m_scoutCopy[i];
		m_scoutCopy[i] = m_scoutCopy[j];
		m_scoutCopy[j] = temp;
	}
	else if(swap == true && m_category == 2)
	{//swap
		CStaff temp = m_coachCopy[i];
		m_coachCopy[i] = m_coachCopy[j];
		m_coachCopy[j] = temp;
	}
	else if(swap == true && m_category == 3)
	{//swap
		CStaff temp = m_gmCopy[i];
		m_gmCopy[i] = m_gmCopy[j];
		m_gmCopy[j] = temp;
	}

}
}
if(m_category == 1) ListScout();
else if(m_category == 2) ListCoach();
else if(m_category == 3) ListGM();
}

HBRUSH CStaffDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CStaffDlg::ListControl()
{
	int index = m_listTeams.GetCurSel();
	CString control = m_control[index];
	m_listControl.ResetContent();
	m_listControl.AddString(control);
}

void CStaffDlg::OnDblclkListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CScoutProfileDlg scout;
//	m_set_cursor = false;
	int i = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(m_category == 1)
	{
		scout.m_type = 1;
		scout.m_scout = m_scoutCopy[i];
	}
	else if(m_category == 2)
	{
		scout.m_scout = m_coachCopy[i];
		scout.m_type = 2;
	}
	else if(m_category == 3)
	{
		scout.m_type = 3;
		scout.m_scout = m_gmCopy[i];
	}
	
	scout.DoModal();
	*pResult = 0;
}

void CStaffDlg::SetInterest()
{
	for(int i=0; i<=99; i++)
	{
		for(int t=1; t<=m_numberTeams; t++)
		{
			int w = m_owner[t].m_win;
			int l = m_owner[t].m_loss;
			if(l == 0) l=1;
			double pct = double(w)/double(l);
			double formulaScout = pct + double(m_owner[t].m_owner_patience) / 10 + double(m_owner[t].m_rosterValue) / 100 * 2;
			double formulaCoach = pct*2 + double(m_owner[t].m_owner_patience) / 20 + double(m_owner[t].m_rosterValue) / 100 * 3;
			double formulaGM = pct/2 + double(m_owner[t].m_owner_patience) / 5 + double(m_owner[t].m_rosterValue) / 100 * 4;
			if(formulaScout >= 0 || t==i) m_scout[i].m_interested[t] = formulaScout;
			if(formulaCoach >= 0 || t==i) m_coach[i].m_interested[t] = formulaCoach;
			if(formulaGM >= 0 || t==i) m_gm[i].m_interested[t] = formulaGM;
		}
	}
}

void CStaffDlg::OnButtonOffer() 
{
	// TODO: Add your control notification handler code here


	GetTopCandidate();
	ListOffers();
	EnableOfferButton();
}

void CStaffDlg::ListOffers()
{
    int i = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	CStaff m_staff = m_scoutCopy[i];
	if(m_category == 2) m_staff = m_coachCopy[i];
	else if(m_category == 3) m_staff = m_gmCopy[i];
	int index = m_listTeams.GetCurSel();
	CString currentTeam = m_leagueTeamNames[index];
	CString string;
        int t=index;//just added
		
		int top = m_owner[t].m_topScout;
		if(m_category == 2) top = m_owner[t].m_topCoach;
		else if(m_category == 3) top = m_owner[t].m_topGM;
		
		CString teamOffering = m_leagueTeamNames[t];
			if(m_category == 1)
				string.Format("%s receives an offer to scout the %s", m_staff.m_name, teamOffering);
			else if(m_category == 2)
				string.Format("%s receives an offer to coach the %s", m_staff.m_name, teamOffering);
			else if(m_category == 3)
				string.Format("%s receives an offer to GM the %s", m_staff.m_name, teamOffering);
			m_listOffers.AddString(string);

}

void CStaffDlg::Firings()
{
	
	int coach_only = false;
	if(avg.m_settings.m_scouts[32] == 1 && avg.m_settings.m_coaches[32] == 0) coach_only = true;
	
//if(pDoc->avg.m_settings.m_scouts[32] == 0 || pDoc->avg.m_settings.m_coaches[32] == 0)//scouts on
//	{

	CString string;
	for(int i=0; i<m_numberTeams; i++)
	{
		bool human = (m_control[i] == "Player");
		m_coach[i].m_status = "active";
		m_scout[i].m_status = "active";
		m_gm[i].m_status = "active";
		m_owner[i].m_currentScout = i;
		m_owner[i].m_currentCoach = i;
		m_owner[i].m_currentGM = i;
		m_scout[i].m_currentScout = i;
		m_coach[i].m_currentCoach = i;
		m_gm[i].m_currentGM = i;
		m_scout[i].m_originalScout = i+1;
		m_coach[i].m_originalCoach = i+1;
		m_gm[i].m_originalGM = i+1;
		if(human != true)
		{
			m_coach[i].m_fired = m_owner[i].FireCoach(m_coach[i]);

			if(coach_only == false) m_scout[i].m_fired = m_owner[i].FireScout(m_scout[i]);
			if(coach_only == false) m_gm[i].m_fired = m_owner[i].FireGM(m_gm[i]);
		}	
			if(coach_only == false) m_scout[i].m_resignedScout = m_owner[i].ResignScout(m_scout[i], m_record[i].m_leaguePct);
			if(coach_only == false) m_scout[i].m_retiredScout = m_owner[i].RetireScout(m_scout[i]);
			m_coach[i].m_resignedCoach = m_owner[i].ResignCoach(m_coach[i], m_record[i].m_leaguePct);
			m_coach[i].m_retiredCoach = m_owner[i].RetireCoach(m_coach[i]);
			if(coach_only == false) m_gm[i].m_resignedGM = m_owner[i].ResignGM(m_gm[i], m_record[i].m_leaguePct);
			if(coach_only == false) m_gm[i].m_retiredGM = m_owner[i].RetireGM(m_gm[i]);
		
		if(m_coach[i].m_fired == true)
		{
//			m_owner[i].m_hireCoach = true;
			m_coach[i].m_currentCoach = -1;
			string.Format("%s is fired as the %s coach", m_coach[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_coach[i].m_status = "fired";
			
		}
		else if(m_coach[i].m_retiredCoach == true)
		{
			m_owner[i].m_hireCoach = true;
			m_coach[i].m_currentCoach = -1;
			m_coach[i].m_fired = true;
			string.Format("%s retires as the %s coach", m_coach[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_coach[i].m_status = "retires";
		}
		else if(m_coach[i].m_resignedCoach == true)
		{
			m_owner[i].m_hireCoach = true;
			m_coach[i].m_currentCoach = -1;
			m_coach[i].m_fired = true;
			string.Format("%s resigns as the %s coach", m_coach[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_coach[i].m_status = "quits";
		}

		if(m_scout[i].m_fired == true)
		{
//			m_owner[i].m_hireScout = true;
			string.Format("%s is fired as the %s scout", m_scout[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_scout[i].m_currentScout = -1;
			m_scout[i].m_status = "fired";
		}
		else if(m_scout[i].m_retiredScout == true)
		{
			m_owner[i].m_hireScout = true;
			m_scout[i].m_currentScout = -1;
			m_scout[i].m_fired = true;
			string.Format("%s retires as the %s scout", m_scout[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_scout[i].m_status = "retires";
		}
		else if(m_scout[i].m_resignedScout == true)
		{
			m_owner[i].m_hireScout = true;
			m_scout[i].m_currentScout = -1;
			m_scout[i].m_fired = true;
			string.Format("%s resigns as the %s scout", m_scout[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_scout[i].m_status = "quits";
		}


		if(m_gm[i].m_fired == true)
		{
//			m_owner[i].m_hireGM = true;
			string.Format("%s is fired as the %s GM", m_gm[i].m_name, m_leagueTeamNames[i] ); 
			m_lisFirings.AddString(string);
			m_gm[i].m_currentGM = -1;
			m_gm[i].m_status = "fired";
		}
		else if(m_gm[i].m_retiredGM == true)
		{
			m_owner[i].m_hireGM = true;
			m_gm[i].m_currentGM = -1;
			m_gm[i].m_fired = true;
			string.Format("%s retires as the %s GM", m_gm[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_gm[i].m_status = "retires";
		}
		else if(m_gm[i].m_resignedGM == true)
		{
			m_owner[i].m_hireGM = true;
			m_gm[i].m_currentGM = -1;
			m_gm[i].m_fired = true;
			string.Format("%s resigns as the %s GM", m_gm[i].m_name, m_leagueTeamNames[i]); 
			m_lisFirings.AddString(string);
			m_gm[i].m_status = "quits";
		}


	}

	for(int i=m_numberTeams; i<=99; i++)
	{
			m_scout[i].m_retiredScout = m_owner[i].RetireScout(m_scout[i]);
			m_coach[i].m_retiredCoach = m_owner[i].RetireCoach(m_coach[i]);
			m_gm[i].m_retiredGM = m_owner[i].RetireGM(m_gm[i]);

		if(m_coach[i].m_retiredCoach == true)
		{
			m_coach[i].m_currentCoach = -1;
			string.Format("Coach %s retires" , m_coach[i].m_name); 
			m_lisFirings.AddString(string);
			m_coach[i].m_status = "retires";
		}

		if(m_scout[i].m_retiredScout == true)
		{
			m_scout[i].m_currentScout = -1;
			string.Format("Scout %s retires", m_scout[i].m_name); 
			m_lisFirings.AddString(string);
			m_scout[i].m_status = "retires";
		}


		if(m_gm[i].m_retiredGM == true)
		{
			m_gm[i].m_currentCoach = -1;
			string.Format("GM %s retires", m_gm[i].m_name); 
			m_lisFirings.AddString(string);
			m_gm[i].m_status = "retires";
		}


	}
}

void CStaffDlg::GetTopCandidate()
{
	for(int t=0; t < m_numberTeams; t++)
	{
		int currentCoach = 0, currentScout = 0, currentGM = 0;

		if(m_owner[t].m_hireCoach == true) m_owner[t].SetTopCoach(m_coachCopy, t+1);

		if(m_owner[t].m_hireScout == true) m_owner[t].SetTopScout(m_scoutCopy, t+1);

		if(m_owner[t].m_hireGM == true) m_owner[t].SetTopGM(m_gmCopy, t+1);

	}
	int i = m_listTeams.GetCurSel();
    int index = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	if(m_control[i] == "Player")
	{
		if(m_coachCopy[index].m_currentCoach < 0 && m_category == 2)
		{
			m_owner[i].m_topCoach = index;
			m_owner[i].m_madeCoachOffer = true;
		}
		else if(m_scoutCopy[index].m_currentScout < 0 && m_category == 1)
		{
			m_owner[i].m_topScout = index;
			m_owner[i].m_madeScoutOffer = true;
		}
		else if(m_category == 3 && m_gmCopy[index].m_currentGM < 0)
		{
			m_owner[i].m_topGM = index;
			m_owner[i].m_madeGmOffer = true;
		}
	}
}

void CStaffDlg::ChooseJob()
{
}

void CStaffDlg::OnButtonFirings() 
{
	// TODO: Add your control notification handler code here
	m_buttonFirings.EnableWindow(FALSE);
	m_buttonEnd.EnableWindow(TRUE);
	m_firingsCompleted = true;
	Firings();
	SetInterest();
	SetVariables();




	if(avg.m_settings.m_scouts[32] == 1 && avg.m_settings.m_coaches[32] == 0)
	{
		CheckDlgButton(IDC_RADIO_SCOUT, 0);	
		CheckDlgButton(IDC_RADIO_COACH, 1);	
		CheckDlgButton(IDC_RADIO_COACH_SCOUT, 1);	
		m_category = 2;
		OnRadioCoach();
	}
	else
	{
		CheckDlgButton(IDC_RADIO_SCOUT, 1);	
		CheckDlgButton(IDC_RADIO_COACH, 0);	
		CheckDlgButton(IDC_RADIO_COACH_SCOUT, 1);	
		m_category = 1;
		OnRadioScout();
	}



	EnableOfferButton();
	ListControl();	  
}

void CStaffDlg::OnButtonEnd() 
{
	// TODO: Add your control notification handler code here
	m_hiring_ok = false;
	m_buttonEnd.SetWindowText("Check Latest Hirings");
	bool continue_hiring = false;
	continue_hiring = false;
	for(int index=0; index<=99; index++)
	{
	

	for(int t=0; t < m_numberTeams; t++)
	{
		int currentCoach = 0, currentScout = 0, currentGM = 0;
		
		if(m_owner[t].m_hireCoach == true && m_control[t] != "Player") m_owner[t].SetTopCoach(m_coachCopy, t+1);
		

		if(m_owner[t].m_hireScout == true && m_control[t] != "Player") m_owner[t].SetTopScout(m_scoutCopy, t+1);
		

		if(m_owner[t].m_hireGM == true && m_control[t] != "Player") m_owner[t].SetTopGM(m_gmCopy, t+1);
		

	}
	
	int top1[33], top2[33], top3[33];

	for(int i=0; i<=32; i++) 
	{
		top1[i] = 0;
		top2[i] = 0;
		top3[i] = 0;
	}

	for(int i=0; i<m_numberTeams; i++)
	{
		top1[i] = m_owner[i].m_topScout;
		top2[i] = m_owner[i].m_topCoach;
		top3[i] = m_owner[i].m_topGM;
	}

	CString string, name;
	int hiringTeam = -1;

			for(int s=0; s<m_numberTeams; s++)
			{
				if((m_owner[s].m_hireScout == false && m_control[s] != "Player") || (m_control[s] == "Player" && m_owner[s].m_madeScoutOffer == false)) top1[s] = -1;//no top candidate required
			}
			m_scoutCopy[index].ChooseScoutJob(top1, index, m_numberTeams);
			hiringTeam = m_scoutCopy[index].m_scoutJob;
			if(hiringTeam >= 0) 
			{
			bool list = (m_scoutCopy[index].m_currentScout == hiringTeam);
			name = m_scoutCopy[index].m_name;
			CString team = m_leagueTeamNames[hiringTeam];
			string.Format("%s accepts the %s offer to scout", name, team);

			if(list == false && m_owner[hiringTeam].m_hiredScoutOnce == false && (m_owner[hiringTeam].m_hireScout == true || m_control[hiringTeam] == "Player")) 
			{
				//rename team of fired and hired coach
				int slot = -1;
				for(int i=0; i<=99; i++)
				{
					if(m_scoutCopy[i].m_currentScout == hiringTeam) slot = i;
				}
				m_scoutCopy[index].m_currentScout = hiringTeam;
				m_owner[hiringTeam].m_hireScout = false;
				m_owner[hiringTeam].m_hiredScoutOnce = true;

				//player team has gotten offer accepted
				if(m_owner[hiringTeam].m_madeScoutOffer == true)
					m_listOffers.AddString(string);


				if(slot >= 0)
				{
					m_scoutCopy[slot].m_team = "";
					m_scoutCopy[slot].m_fired = true;
					m_scoutCopy[slot].m_status = "fired";
					m_scoutCopy[slot].m_currentScout = -1;
				}
				m_scoutCopy[index].m_team = team;
				m_scoutCopy[index].m_fired = false;
				m_scoutCopy[index].m_status = "hired";
				m_owner[hiringTeam].m_currentScout = index;
				m_listAccept.AddString(string);
			}
			}
			for(int  s=0; s<m_numberTeams; s++)
			{
				if((m_owner[s].m_hireCoach == false && m_control[s] != "Player") || (m_control[s] == "Player" && m_owner[s].m_madeCoachOffer == false)) top2[s] = -1;
			}
			m_coachCopy[index].ChooseCoachJob(top2, index, m_numberTeams);
			hiringTeam = m_coachCopy[index].m_coachJob;
			if(hiringTeam >= 0) 
			{

			bool list = (m_coachCopy[index].m_currentCoach == hiringTeam);
			name = m_coachCopy[index].m_name;
			CString team = m_leagueTeamNames[hiringTeam];
			string.Format("%s accepts the %s offer to coach", name, team);


			if(list == false && 
				m_owner[hiringTeam].m_hiredCoachOnce == false &&				
				(m_owner[hiringTeam].m_hireCoach == true || m_control[hiringTeam] == "Player")) 
			{
				//rename team of fired and hired coach
				int slot = -1;
				for(int i=0; i<=99; i++)
				{
					if(m_coachCopy[i].m_currentCoach == hiringTeam) slot = i;
				}
				m_coachCopy[index].m_currentCoach = hiringTeam;
				m_owner[hiringTeam].m_hireCoach = false;
				m_owner[hiringTeam].m_hiredCoachOnce = true;
				
				if(m_owner[hiringTeam].m_madeCoachOffer == true)
					m_listOffers.AddString(string);

				if(slot >= 0)
				{
					m_coachCopy[slot].m_team = "";
					m_coachCopy[slot].m_fired = true;
					m_coachCopy[slot].m_status = "fired";
					m_coachCopy[slot].m_currentCoach = -1;
				}
				m_coachCopy[index].m_team = team;
				m_coachCopy[index].m_fired = false;
				m_coachCopy[index].m_status = "hired";
				m_owner[hiringTeam].m_currentCoach = index;
				m_listAccept.AddString(string);
			}
			}
			for(int s=0; s<m_numberTeams; s++)
			{
				if((m_owner[s].m_hireGM == false && m_control[s] != "Player") || (m_control[s] == "Player" && m_owner[s].m_madeGmOffer == false)) top3[s] = -1;
			}
			m_gmCopy[index].ChooseGmJob(top3, index, m_numberTeams);
			hiringTeam = m_gmCopy[index].m_gmJob;
			if(hiringTeam >= 0) 
			{

			bool list = (m_gmCopy[index].m_currentGM == hiringTeam);
			name = m_gmCopy[index].m_name;
			CString team = m_leagueTeamNames[hiringTeam];
			string.Format("%s accepts the %s offer to GM", name, team);


			if(list == false && 
				m_owner[hiringTeam].m_hiredGmOnce == false &&				
				(m_owner[hiringTeam].m_hireGM == true || m_control[hiringTeam] == "Player")) 
			{
				//rename team of fired and hired coach
				int slot = -1;
				for(int i=0; i<=99; i++)
				{
					if(m_gmCopy[i].m_currentGM == hiringTeam) slot = i;
				}
				m_gmCopy[index].m_currentGM = hiringTeam;
				m_owner[hiringTeam].m_hireGM = false;
				m_owner[hiringTeam].m_hiredGmOnce = true;
				

				if(m_owner[hiringTeam].m_madeGmOffer == true)
					m_listOffers.AddString(string);
				
				
				if(slot >= 0)
				{
					m_gmCopy[slot].m_team = "";
					m_gmCopy[slot].m_fired = true;
					m_gmCopy[slot].m_status = "fired";
					m_gmCopy[slot].m_currentGM = -1;
				}
				m_gmCopy[index].m_team = team;
				m_gmCopy[index].m_fired = false;
				m_gmCopy[index].m_status = "hired";
				m_owner[hiringTeam].m_currentGM = index;
				m_listAccept.AddString(string);
			}
			}
		for(int t=0; t < m_numberTeams; t++)
		{
			if(m_owner[t].m_hireCoach == true ||
				m_owner[t].m_hireGM == true ||
				m_owner[t].m_hireScout == true) continue_hiring = true;
		
		}
	}
	if(continue_hiring == false)
	{
		m_buttonOffer.EnableWindow(FALSE);
		m_buttonOK.EnableWindow(TRUE);
		m_buttonEnd.EnableWindow(FALSE);
	}
	int count = m_listAccept.GetCount();
	m_listAccept.SetCurSel(count-1);

	for(int i=0; i<= 99; i++)
	{
		m_owner[i].m_madeScoutOffer = false;
		m_owner[i].m_madeCoachOffer = false;
		m_owner[i].m_madeGmOffer = false;
	}

    if(m_category == 2)
	{
		OnRadioCoach();
		m_changeHeading = true;	
	}
	else
		SortStaff();

	int co = m_listOffers.GetCount() - 1;
	m_listOffers.SetCurSel(co);
}


void CStaffDlg::EnableOfferButton()
{
	int t = m_listTeams.GetCurSel();
	
	if(m_firingsCompleted == true && m_control[t] == "Player") 
	{
    int i = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(m_category == 1 && m_scoutCopy[i].m_currentScout == -1 && m_owner[t].m_hiredScoutOnce == false && m_owner[t].m_madeScoutOffer == false && m_scoutCopy[i].m_status != "retires")
		m_buttonOffer.EnableWindow(TRUE);
	else if(m_category == 1)
		m_buttonOffer.EnableWindow(FALSE);
	else if(m_category == 2 && m_coachCopy[i].m_currentCoach == -1 && m_owner[t].m_hiredCoachOnce == false && m_owner[t].m_madeCoachOffer == false && m_coachCopy[i].m_status != "retires")
		m_buttonOffer.EnableWindow(TRUE);
	else if(m_category == 2)
		m_buttonOffer.EnableWindow(FALSE);
	else if(m_category == 3 && m_gmCopy[i].m_currentGM == -1 && m_owner[t].m_hiredGmOnce == false && m_owner[t].m_madeGmOffer == false && m_gmCopy[i].m_status != "retires")
		m_buttonOffer.EnableWindow(TRUE);
	else if(m_category == 3)
		m_buttonOffer.EnableWindow(FALSE);
	}
	else if(m_firingsCompleted == true)
		m_buttonOffer.EnableWindow(FALSE);

	if(m_set_cursor == true) SetCursorPosition(m_category); else m_set_cursor = true;
}

void CStaffDlg::OnClickListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_row = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	m_set_cursor = false;
	EnableOfferButton();	
	*pResult = 0;
}

void CStaffDlg::OrderList()
{		
	
	names->m_path = avg.m_settings.m_path;
	names->m_leagueName = avg.m_settings.m_league_name;
	names->ReadNames();
	int countScout = m_numberTeams;
	int countCoach = m_numberTeams;
	int countGM = m_numberTeams;
	CStaff m_new_scout[100], m_new_coach[100], m_new_gm[100];
	for(int i=0; i<=99; i++)
	{
		if(m_scoutCopy[i].m_status == "retires")
		{
			m_scoutCopy[i].m_name = names->CreateName();
			m_scoutCopy[i].CreateNewMember();
		}
		if(m_coachCopy[i].m_status == "retires")
		{
			m_coachCopy[i].m_name = names->CreateName();
			m_coachCopy[i].CreateNewMember();
		}
		if(m_gmCopy[i].m_status == "retires")
		{
			m_gmCopy[i].m_name = names->CreateName();
			m_gmCopy[i].CreateNewMember();
		}

		int currentScout = m_scoutCopy[i].m_currentScout;
		int currentCoach = m_coachCopy[i].m_currentCoach;
		int currentGM = m_gmCopy[i].m_currentGM;

		if(m_scoutCopy[i].m_points < 16 && m_scoutCopy[i].m_status == "hired") m_scoutCopy[i].m_points = 16;
		if(m_coachCopy[i].m_points < 16 && m_coachCopy[i].m_status == "hired") m_coachCopy[i].m_points = 16;
		if(m_gmCopy[i].m_points < 16 && m_gmCopy[i].m_status == "hired") m_gmCopy[i].m_points = 16;
		
		if(currentScout >= 0)
			m_new_scout[currentScout] = m_scoutCopy[i];
		else
		{
			m_new_scout[countScout] = m_scoutCopy[i];
			countScout = countScout + 1;
		}
		if(currentCoach >= 0)
			m_new_coach[currentCoach] = m_coachCopy[i];
		else
		{
			m_new_coach[countCoach] = m_coachCopy[i];
			countCoach = countCoach + 1;
		}
		if(currentGM >= 0)
			m_new_gm[currentGM] = m_gmCopy[i];
		else
		{
			m_new_gm[countGM] = m_gmCopy[i];
			countGM = countGM + 1;
		}
		
	}



	for(int i = 0; i<= 99; i++)
	{
		int prime_scout = 54 + m_new_scout[i].m_power;		
		int prime_coach = 50 + m_new_scout[i].m_power;		
		int prime_gm = 52 + m_new_scout[i].m_power;		
		m_new_scout[i].SetImprovement(prime_scout);
		m_new_coach[i].SetImprovement(prime_coach);
		m_new_gm[i].SetImprovement(prime_gm);

		avg.m_scout[i] = m_new_scout[i];
		avg.m_coach[i] = m_new_coach[i];
		avg.m_gm[i] = m_new_gm[i];
		
	}


	for(int i=0; i<m_numberTeams; i++)
	{
        m_owner[i].SetScoutFiringLine(avg.m_scout[i]);//pass staff member if rated high adjust chance of firing
        m_owner[i].SetCoachFiringLine(avg.m_coach[i]);
        m_owner[i].SetGmFiringLine(avg.m_gm[i]);
		avg.m_owner[i] = m_owner[i];
	}

}


void CStaffDlg::OnRadioCoachScout() 
{
	// TODO: Add your control notification handler code here
	if(m_coachCategory == 2 ) m_changeHeading = true;	
    m_coachCategory = 1;	
	OnRadioCoach();
}

void CStaffDlg::OnRadioCoachGame() 
{
	// TODO: Add your control notification handler code here
	if(m_coachCategory == 1 ) m_changeHeading = true;
	m_coachCategory = 2;
	OnRadioCoach();
	
}

void CStaffDlg::SetGameCoachListCtrl()
{

}

void CStaffDlg::SortCoach()
{
m_listCtrl.DeleteAllItems();
CStaff m_staff_i, m_staff_j;

for(int i=0; i<=99; i++)
{
for(int j=0; j<=99; j++)
{


bool swap = false;

	m_staff_i = m_coachCopy[i];
	m_staff_j = m_coachCopy[j];


switch(m_column) 
{

    case 0:
		swap = m_staff_i.m_name < m_staff_j.m_name;
        break;
    case 1:
		swap = m_staff_i.m_team < m_staff_j.m_team;
        break;
    case 2:        
		swap = m_staff_i.m_age > m_staff_j.m_age;
        break;
    case 3:
		swap = m_staff_i.m_coachPot1 > m_staff_j.m_coachPot1;
        break;
    case 4:
		swap = m_staff_i.m_coachPot1 > m_staff_j.m_coachPot2;
        break;
    case 5:
		swap = m_staff_i.m_coachEffort > m_staff_j.m_coachEffort;
        break;
    case 6:
		swap = m_staff_i.m_coachScoring > m_staff_j.m_coachScoring;
        break;
    case 7:
		swap = m_staff_i.m_coachShooting > m_staff_j.m_coachShooting;
        break;
    case 8:
		swap = m_staff_i.m_coachRebounding > m_staff_j.m_coachRebounding;
        break;
    case 9:
		swap = m_staff_i.m_coachPassing > m_staff_j.m_coachPassing;
        break;
    case 10:
		swap = m_staff_i.m_coachDefense > m_staff_j.m_coachDefense;
        break;
    case 11:
		swap = m_staff_i.m_coachO > m_staff_j.m_coachO;
        break;
    case 12:
		swap = m_staff_i.m_coachP > m_staff_j.m_coachP;
        break;
    case 13:
		swap = m_staff_i.m_coachI > m_staff_j.m_coachI;
        break;
    case 14:
		swap = m_staff_i.m_coachF > m_staff_j.m_coachF;
        break;
    case 15:
		swap = m_staff_i.m_coachOD > m_staff_j.m_coachOD;
        break;
    case 16:
		swap = m_staff_i.m_coachPD > m_staff_j.m_coachPD;
        break;
    case 17:
		swap = m_staff_i.m_coachID > m_staff_j.m_coachID;
        break;
    case 18:
		swap = m_staff_i.m_coachFD > m_staff_j.m_coachFD;
        break;
    case 19:
		swap = m_staff_i.m_coachEndurance > m_staff_j.m_coachEndurance;
        break;
    case 20:
//		swap = m_staff_i.m_loyalty > m_staff_j.m_loyalty;
        break;
}



	if(swap == true)
	{//swap
		CStaff temp = m_coachCopy[i];
		m_coachCopy[i] = m_coachCopy[j];
		m_coachCopy[j] = temp;
	}

}
}
ListGameCoach();
}

void CStaffDlg::ListGameCoach()
{
//    CoachColumns();
	int co = 0;
	CString string[99];
	CString lbl[] = {"", "F", "D", "C", "B", "A"};


for(int pl=0; pl<=99; pl++)
{
	CStaff m_player = m_coachCopy[pl];
	CString name = m_player.m_name;
	CString team = m_player.m_team;
	if(name == "") continue;
	if(team == "") team = "none";
	m_listCtrl.InsertItem(co,name);
	m_listCtrl.SetItemText(co,1,team);
	string[0].Format("%d", m_player.m_age);
	string[1].Format("%s", lbl[m_player.m_coachPot1]);
	string[2].Format("%s", lbl[m_player.m_coachPot2]);
	string[3].Format("%s", lbl[m_player.m_coachEffort]);
	string[4].Format("%s", lbl[m_player.m_coachScoring]);
	string[5].Format("%s", lbl[m_player.m_coachShooting]);
	string[6].Format("%s", lbl[m_player.m_coachRebounding]);
	string[7].Format("%s", lbl[m_player.m_coachPassing]);
	string[8].Format("%s", lbl[m_player.m_coachDefense]);
	string[9].Format("%s", lbl[m_player.m_coachO]);
	string[10].Format("%s", lbl[m_player.m_coachP]);
	string[11].Format("%s", lbl[m_player.m_coachI]);
	string[12].Format("%s", lbl[m_player.m_coachF]);
	string[13].Format("%s", lbl[m_player.m_coachOD]);
	string[14].Format("%s", lbl[m_player.m_coachPD]);
	string[15].Format("%s", lbl[m_player.m_coachID]);
	string[16].Format("%s", lbl[m_player.m_coachFD]);
	string[17].Format("%s", lbl[m_player.m_coachEndurance]);

	for(int i=0; i<=17; i++)
	{
		m_listCtrl.SetItemText(co,i+2,string[i]);
	}
	
	co = co + 1;
}

m_listCtrl.SetItemState(m_row,LVIS_SELECTED,LVIS_SELECTED);

	EnableOfferButton();




}

void CStaffDlg::StaffColumns()
{
//	DeleteColumns();
	if(m_changeHeading == true)
	{
	m_changeHeading = false;
	m_listCtrl.DeleteAllItems();
	m_listCtrl.DeleteColumn(0);
    if(m_category == 1) 
		m_listCtrl.InsertColumn(0,"Scout");    
    else if(m_category == 2) 
		m_listCtrl.InsertColumn(0,"Coach");    
    else if(m_category == 3) 
		m_listCtrl.InsertColumn(0,"GM");    
	
	m_listCtrl.DeleteColumn(16);
	m_listCtrl.DeleteColumn(17);
	m_listCtrl.DeleteColumn(18);
	m_listCtrl.DeleteColumn(19);
	m_listCtrl.DeleteColumn(20);
	m_listCtrl.DeleteColumn(21);

	m_listCtrl.DeleteColumn(1);
    m_listCtrl.InsertColumn(1,"Team");    
	m_listCtrl.DeleteColumn(2);
    m_listCtrl.InsertColumn(2,"age");    
	m_listCtrl.DeleteColumn(3);
    m_listCtrl.InsertColumn(3,"ta");    
	m_listCtrl.DeleteColumn(4);
    m_listCtrl.InsertColumn(4,"sk");    
	m_listCtrl.DeleteColumn(5);
    m_listCtrl.InsertColumn(5,"in");    
	m_listCtrl.DeleteColumn(6);
    m_listCtrl.InsertColumn(6,"sc");    
	m_listCtrl.DeleteColumn(7);
    m_listCtrl.InsertColumn(7,"sh");    
	m_listCtrl.DeleteColumn(8);
    m_listCtrl.InsertColumn(8,"re");    
	m_listCtrl.DeleteColumn(9);
    m_listCtrl.InsertColumn(9,"bh");    
	m_listCtrl.DeleteColumn(10);
    m_listCtrl.InsertColumn(10,"de");    
	m_listCtrl.DeleteColumn(11);
    m_listCtrl.InsertColumn(11,"win");    
	m_listCtrl.DeleteColumn(12);
    m_listCtrl.InsertColumn(12,"loss");    
	m_listCtrl.DeleteColumn(13);
    m_listCtrl.InsertColumn(13,"po");    
	m_listCtrl.DeleteColumn(14);
    m_listCtrl.InsertColumn(14,"ri");    
	m_listCtrl.DeleteColumn(15);
    m_listCtrl.InsertColumn(15,"status");    

	m_listCtrl.DeleteColumn(16);
	m_listCtrl.DeleteColumn(17);
	m_listCtrl.DeleteColumn(18);
	m_listCtrl.DeleteColumn(19);
	m_listCtrl.DeleteColumn(20);
	m_listCtrl.DeleteColumn(21);
	m_listCtrl.DeleteColumn(16);

	double scale = 1.5;
  
    m_listCtrl.SetColumnWidth( 0, 96 * scale );
    m_listCtrl.SetColumnWidth( 1, 64 * scale );
    m_listCtrl.SetColumnWidth( 2, 30 * scale );
    m_listCtrl.SetColumnWidth( 3, 24 * scale );
    m_listCtrl.SetColumnWidth( 4, 24 * scale );
    m_listCtrl.SetColumnWidth( 5, 24 * scale );
    m_listCtrl.SetColumnWidth( 6, 24 * scale );
    m_listCtrl.SetColumnWidth( 7, 24 * scale );
    m_listCtrl.SetColumnWidth( 8, 24 * scale );
    m_listCtrl.SetColumnWidth( 9, 27 * scale );
    m_listCtrl.SetColumnWidth( 10, 27 * scale );
    m_listCtrl.SetColumnWidth( 11, 37 * scale );
    m_listCtrl.SetColumnWidth( 12, 37 * scale );
    m_listCtrl.SetColumnWidth( 13, 27 * scale );
    m_listCtrl.SetColumnWidth( 14, 27 * scale );
    m_listCtrl.SetColumnWidth( 15, 66 * scale );
//    m_listCtrl.SetColumnWidth( 16, 66);
	}
	else
	{
		m_listCtrl.DeleteColumn(0);
	    if(m_category == 1) 
			m_listCtrl.InsertColumn(0,"Scout");    
		else if(m_category == 2) 
			m_listCtrl.InsertColumn(0,"Coach");    
		else if(m_category == 3) 
			m_listCtrl.InsertColumn(0,"GM");    

	    m_listCtrl.SetColumnWidth( 0, 96);
	}

}

void CStaffDlg::CoachColumns()
{
//	DeleteColumns();
	if(m_changeHeading == true)
	{
	m_changeHeading = false;

	m_listCtrl.DeleteAllItems();
	m_listCtrl.DeleteColumn(0);
    m_listCtrl.InsertColumn(0,"Coach");    

	m_listCtrl.DeleteColumn(1);
    m_listCtrl.InsertColumn(1,"Team");    
	m_listCtrl.DeleteColumn(2);
    m_listCtrl.InsertColumn(2,"age");    
	m_listCtrl.DeleteColumn(3);
    m_listCtrl.InsertColumn(3,"ta");    
	m_listCtrl.DeleteColumn(4);
    m_listCtrl.InsertColumn(4,"sk");    
	m_listCtrl.DeleteColumn(5);
    m_listCtrl.InsertColumn(5,"in");    
	m_listCtrl.DeleteColumn(6);
    m_listCtrl.InsertColumn(6,"sc");    
	m_listCtrl.DeleteColumn(7);
    m_listCtrl.InsertColumn(7,"sh");    
	m_listCtrl.DeleteColumn(8);
    m_listCtrl.InsertColumn(8,"re");    
	m_listCtrl.DeleteColumn(9);
    m_listCtrl.InsertColumn(9,"bh");    
	m_listCtrl.DeleteColumn(10);
    m_listCtrl.InsertColumn(10,"de");    
	m_listCtrl.DeleteColumn(11);
    m_listCtrl.InsertColumn(11,"o");    
	m_listCtrl.DeleteColumn(12);
    m_listCtrl.InsertColumn(12,"d");    
	m_listCtrl.DeleteColumn(13);
    m_listCtrl.InsertColumn(13,"p");    
	m_listCtrl.DeleteColumn(14);
    m_listCtrl.InsertColumn(14,"t");    
	m_listCtrl.DeleteColumn(15);
    m_listCtrl.InsertColumn(15,"od");    
	m_listCtrl.DeleteColumn(16);
    m_listCtrl.InsertColumn(16,"dd");    
	m_listCtrl.DeleteColumn(17);
    m_listCtrl.InsertColumn(17,"pd");    
	m_listCtrl.DeleteColumn(18);
    m_listCtrl.InsertColumn(18,"td");    
	m_listCtrl.DeleteColumn(19);
    m_listCtrl.InsertColumn(19,"co");    
	m_listCtrl.DeleteColumn(20);
  
	double scale = 1.5;
    m_listCtrl.SetColumnWidth( 0, 96 * scale );
    m_listCtrl.SetColumnWidth( 1, 64 * scale );
    m_listCtrl.SetColumnWidth( 2, 30 * scale );
    m_listCtrl.SetColumnWidth( 3, 24 * scale );
    m_listCtrl.SetColumnWidth( 4, 24 * scale );
    m_listCtrl.SetColumnWidth( 5, 24 * scale );
    m_listCtrl.SetColumnWidth( 6, 24 * scale );
    m_listCtrl.SetColumnWidth( 7, 24 * scale );
    m_listCtrl.SetColumnWidth( 8, 24 * scale );
    m_listCtrl.SetColumnWidth( 9, 27 * scale );
    m_listCtrl.SetColumnWidth( 10, 27 * scale );
    m_listCtrl.SetColumnWidth( 11, 24 * scale );
    m_listCtrl.SetColumnWidth( 12, 24 * scale );
    m_listCtrl.SetColumnWidth( 13, 24 * scale );
    m_listCtrl.SetColumnWidth( 14, 24 * scale );
    m_listCtrl.SetColumnWidth( 15, 27 * scale );
    m_listCtrl.SetColumnWidth( 16, 27 * scale );
    m_listCtrl.SetColumnWidth( 17, 27 * scale );
    m_listCtrl.SetColumnWidth( 18, 27 * scale );
    m_listCtrl.SetColumnWidth( 19, 27 * scale );
	}

}

void CStaffDlg::DeleteColumns()
{

}

void CStaffDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete names;
	
}

void CStaffDlg::SetCursorPosition(int category)
{
	int line = 0;
	CString selected_team = m_leagueTeamNames[m_listTeams.GetCurSel()];
	for(int p=0; p<=99; p++)
	{
		CStaff member;
		if(category == 1) member = m_scoutCopy[p];
		else if(category == 2) member = m_coachCopy[p];
		else if(category == 3) member = m_gmCopy[p];
		CString team = member.m_team;
		if(team == selected_team) line = p;
	}	
	m_listCtrl.SetItemState(line ,LVIS_SELECTED,LVIS_SELECTED);
	m_listCtrl.EnsureVisible(line, TRUE);
	m_row = line;
}

void CStaffDlg::OnSelchangeComboStaffTeams() 
{
	// TODO: Add your control notification handler code here
	ListControl();
	EnableOfferButton();
	
}

void CStaffDlg::PassMembers()
{
	for(int i=0; i<=99; i++)
	{
//		if(i < avg.m_settings.m_numberteams)
//		{
//			avg.m_scout[i].m_win = avg.m_standings[i].m_win;
//			avg.m_scout[i].m_loss = avg.m_standings[i].m_loss;

//		}
		m_scout[i] = avg.m_scout[i];
		m_coach[i] = avg.m_coach[i];
		m_gm[i] = avg.m_gm[i];
		m_owner[i] = avg.m_owner[i];
		if(i<=31)
		{
			m_standings[i] = avg.m_standings[i];
			m_control[i] = avg.m_settings.m_player_gm[i];
			m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
			m_scout[i].m_team = avg.m_settings.m_leagueTeamNames[i];
			m_coach[i].m_team = avg.m_settings.m_leagueTeamNames[i];
			m_gm[i].m_team = avg.m_settings.m_leagueTeamNames[i];
		}

	}

}


void CStaffDlg::OnLvnItemchangedListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
