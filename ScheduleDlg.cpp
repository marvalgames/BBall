// ScheduleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "ScheduleDlg.h"
//#include "LeagueTeamsDlg.h"
#include "AutoSchDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScheduleDlg dialog


CScheduleDlg::CScheduleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScheduleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScheduleDlg)
	m_leagueName = _T("");
	m_edit_text = _T("");
	//}}AFX_DATA_INIT
	month = 0;//Oct
	day = 30;//31
	m_resetStats = FALSE;
	m_seasonStarted = FALSE;
	m_playoffJustStarted = false;
//	m_seasonOver = false;
}


void CScheduleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScheduleDlg)
	DDX_Control(pDX, IDC_BUTTON_RESET, m_button_reset);
	DDX_Control(pDX, IDOK, m_button[0]);
	DDX_Control(pDX, IDCANCEL, m_button[1]);
	DDX_Control(pDX, IDC_LIST_MONTH, m_scheduleMonth);
	DDX_Control(pDX, IDC_LIST_DAY, m_scheduleDay);
	DDX_Control(pDX, IDC_BUTTON_AUTOSCH, m_buttonAuto);
	DDX_Control(pDX, IDC_BUTTON_REMOVE, m_buttonRemove);
	DDX_Control(pDX, IDC_BUTTON_ADD_VISITOR, m_buttonAddVisitor);
	DDX_Control(pDX, IDC_BUTTON_ADD_HOME, m_buttonAddHome);
	DDX_Control(pDX, IDC_LIST_VISITOR, m_scheduleVisitor);
	DDX_Control(pDX, IDC_LIST_TEAMS, m_scheduleTeam);
	DDX_Control(pDX, IDC_LIST_HOME, m_scheduleHome);
	DDX_Text(pDX, IDC_EDIT_LEAGUENAME, m_leagueName);
	DDV_MaxChars(pDX, m_leagueName, 32);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_edit_text);
	DDV_MaxChars(pDX, m_edit_text, 511);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScheduleDlg, CDialog)
	//{{AFX_MSG_MAP(CScheduleDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD_HOME, OnButtonAddHome)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_LBN_SELCHANGE(IDC_LIST_HOME, OnSelchangeListHome)
	ON_LBN_SELCHANGE(IDC_LIST_VISITOR, OnSelchangeListVisitor)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_ADD_VISITOR, OnButtonAddVisitor)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_AUTOSCH, OnButtonAutosch)
	ON_WM_CTLCOLOR()
	ON_LBN_DBLCLK(IDC_LIST_CONTROL, OnDblclkListControl)
	ON_CBN_SELCHANGE(IDC_LIST_MONTH, OnSelchangeListMonth)
	ON_CBN_SELCHANGE(IDC_LIST_DAY, OnSelchangeListDay)
	ON_LBN_DBLCLK(IDC_LIST_VISITOR_SCORE, OnDblclkListVisitorScore)
	ON_LBN_DBLCLK(IDC_LIST_HOME_SCORE, OnDblclkListHomeScore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScheduleDlg message handlers

BOOL CScheduleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
// myBrush.CreateSolidBrush(LISTBOXCOLOR); 
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	UpdateData(TRUE);
	//initialize a structure for my font

	
	CString string;
	CString 
		months[] = {"Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Post"}; 
	m_scheduleTeam.SetCurSel(0); 
	for(int i=1; i<=31; i++)
	{
		string.Format("%d", i);
		m_scheduleDay.AddString(string);//display days
	}
	for(int i=1; i<=13; i++)
	{
		m_scheduleMonth.AddString(months[i-1]);//display months
	}


	m_buttonAuto.EnableWindow(TRUE);



	
	if(avg.m_settings.m_current_stage > 0)
	{
		m_button_reset.EnableWindow(FALSE);
		m_buttonAuto.EnableWindow(FALSE);
	}




	for(int i=0; i<32; i++)
		{
		if(m_leagueTeamNames[i] != "")			
			{
				CString text = m_leagueTeamNames[i];
				m_scheduleTeam.AddString(text);
				m_leagueTeam[i+1].Name = m_leagueTeamNames[i];
				m_leagueTeam[i+1].Number = i+1;
			}
		}

	m_scheduleDay.SetCurSel(0);
	m_scheduleMonth.SetCurSel(1);
	CScheduleDlg::OnSelchangeListMonth(); 	
	UpdateData(FALSE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CScheduleDlg::OnButtonAddHome() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	CString team;
	int index = m_scheduleTeam.GetCurSel();
	if(index >= 0) // do if team list not blank
	{

	m_scheduleTeam.GetText(index, team);
	BOOL NoAdd = FALSE;
	int count = m_scheduleVisitor.GetCount();
	// Check if team selected is in list (home or visitor) already

	for(int i=0; i < count; i++)
	{
		CString visitor;
		m_scheduleVisitor.GetText(i, visitor);
		if(team == visitor) NoAdd = TRUE;
	}

	count = m_scheduleHome.GetCount();
	for(int i=0; i < count; i++)
	{
		CString home;
		m_scheduleHome.GetText(i, home);
		if(team == home) NoAdd = TRUE;
	}

	if(NoAdd == FALSE)
	{
		m_scheduleHome.AddString(team);
		UpdateData(FALSE);	
	}
	}
	}

	int index = m_scheduleTeam.GetCurSel();
	m_scheduleTeam.DeleteString(index);

}

void CScheduleDlg::OnButtonRemove() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	int index = m_scheduleVisitor.GetCurSel();
	m_swapOk = FALSE;
	if(index >= 0)
	{
		CString team;
		m_scheduleVisitor.GetText(index, team);
		m_scheduleTeam.AddString(team);
		m_scheduleVisitor.DeleteString(index);
		int mo = m_scheduleMonth.GetCurSel();
		int dy = m_scheduleDay.GetCurSel();
		m_schedule[mo][dy][index] = 0;
		UpdateData(FALSE);
	}
	index = m_scheduleHome.GetCurSel();
	if(index >= 0)
	{
		CString team;
		m_scheduleHome.GetText(index, team);
		m_scheduleTeam.AddString(team);
		m_scheduleHome.DeleteString(index);
		UpdateData(FALSE);
	}
	}

	CScheduleDlg::OnSelchangeListMonth(); 
	m_scheduleVisitor.SetCurSel(0); 
	m_scheduleHome.SetCurSel(0); 
}

void CScheduleDlg::OnSelchangeListHome() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	int index = m_scheduleHome.GetCurSel();
	if(index >= 0)
	{
		CString team;
		m_scheduleHome.GetText(index, team);
		if(m_swapOk == TRUE)
		{
			m_scheduleHome.DeleteString(index);
			m_scheduleHome.InsertString(index, m_swapTeam);
			if(m_listHome == TRUE) // clicked from home list first
			{
				m_scheduleHome.DeleteString(m_swapIndex);
				m_scheduleHome.InsertString(m_swapIndex, team);
				m_scheduleHome.SetCurSel(index); 
			}
			else
			{
				m_scheduleVisitor.DeleteString(m_swapIndex);
				m_scheduleVisitor.InsertString(m_swapIndex, team);
				m_scheduleVisitor.SetCurSel(index); 
			}
			m_swapOk = FALSE;
		}
		else
		{		
			m_swapOk = TRUE;
			m_swapTeam = team;
			m_swapIndex = index;
			m_listHome = TRUE;
		}
		m_scheduleHome.SetCurSel(index);
		UpdateData(FALSE);
	}
	}	
}

void CScheduleDlg::OnSelchangeListVisitor() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	int index = m_scheduleVisitor.GetCurSel();
	if(index >= 0)
	{
		CString team;
		m_scheduleVisitor.GetText(index, team);
		if(m_swapOk == TRUE)
		{
			m_scheduleVisitor.DeleteString(index);
			m_scheduleVisitor.InsertString(index, m_swapTeam);
			if(m_listHome == TRUE) // clicked from home list first
			{
				m_scheduleHome.DeleteString(m_swapIndex);
				m_scheduleHome.InsertString(m_swapIndex, team);
				m_scheduleHome.SetCurSel(index); 
			}
			else
			{
				m_scheduleVisitor.DeleteString(m_swapIndex);
				m_scheduleVisitor.InsertString(m_swapIndex, team);
				m_scheduleVisitor.SetCurSel(index); 
			}
			m_swapOk = FALSE;
		}
		else
		{		
			m_swapOk = TRUE;
			m_swapTeam = team;
			m_swapIndex = index;
			m_listHome = FALSE;
		}
		m_scheduleVisitor.SetCurSel(index);
		UpdateData(FALSE);
	}
	}		
}

void CScheduleDlg::OnSelchangeListMonth() 
{
	// TODO: Add your control notification handler code here

	BOOL DayOff[33] = {1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1};
	int game[17] = {0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0};
	int Vcount = m_scheduleVisitor.GetCount();
	int Hcount = m_scheduleHome.GetCount();
	int count = 0;
	if(Vcount > Hcount) count = Hcount; else count = Vcount;
	for(int i=0; i < count; i++)
	{
		CString visitor;
		CString home;
		m_scheduleVisitor.GetText(i, visitor);
		m_scheduleHome.GetText(i, home);
		for(int j=1; j <= 32; j++)
		{
			//find team to set schedule array
			//4 digits 1st 2 visitor number next 2 home number
			if(m_leagueTeam[j].Name == visitor)
				game[i] = game[i] + m_leagueTeam[j].Number * 100;
			if(m_leagueTeam[j].Name == home)
				game[i] = game[i] + m_leagueTeam[j].Number;
		}			
	m_schedule[month][day][i] = game[i];
	}	
	
	if(count > 0)
	{
		for(int i = count; i < 16; i++)
		{
			m_schedule[month][day][i] = 0;//zero out rest of day for unfilled games
		}
	}

	month = m_scheduleMonth.GetCurSel();
	day = m_scheduleDay.GetCurSel();
	//clear list boxes
	m_scheduleTeam.ResetContent();		
	m_scheduleVisitor.ResetContent();		
	m_scheduleHome.ResetContent();		
		
	for(int i=0; i < 16; i++)
	{
		CString visitor;
		CString home;
		CString visitorScore;
		CString homeScore;
	
		int v = m_schedule[month][day][i] / 100;
		int h = m_schedule[month][day][i] - v * 100;
		if(v >= 33) v = 0;
		if(h >= 33) h = 0;		
		visitor = m_leagueTeam[v].Name;
		home = m_leagueTeam[h].Name;
		if(visitor != "" && home != "")
		{
			

			m_scheduleVisitor.AddString(visitor);
			m_scheduleHome.AddString(home);
			if(visitorScore == "0") visitorScore = "";
			if(homeScore == "0") homeScore = "";
			DayOff[v] = FALSE;
			DayOff[h] = FALSE;
		}
	}
	for(int i=1; i <= 32; i++)
	{
		if(DayOff[i] == TRUE && m_leagueTeam[i].Name != "")
			m_scheduleTeam.AddString(m_leagueTeam[i].Name);
	}
	m_scheduleTeam.SetCurSel(0);
}

void CScheduleDlg::OnSelchangeListDay() 
{
	// TODO: Add your control notification handler code here
	CScheduleDlg::OnSelchangeListMonth(); 
}

void CScheduleDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_seasonStarted == FALSE)
	{
	CScheduleDlg::OnSelchangeListMonth(); 	
	int result = AfxMessageBox("Are you sure you want to save the schedule?", MB_YESNO);
	if(result == IDYES) CDialog::OnOK();
	}
	else
		CDialog::OnOK();
}


void CScheduleDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_seasonStarted == FALSE)
	{
	int result = AfxMessageBox("Are you sure you want to cancel?", MB_YESNO);
	if(result == IDYES) CDialog::OnCancel();	
	}
	else
		CDialog::OnCancel();
}

void CScheduleDlg::OnButtonReset() 
{
	// TODO: Add your control notification handler code here
	int result = AfxMessageBox("Are you sure you want to start the current season over again?\n",
						   MB_YESNO);
	if(result == IDYES)
	{
	m_resetStats = TRUE;
	m_seasonStarted = FALSE;
	m_seasonOver = false;
	m_buttonAddVisitor.EnableWindow(TRUE);
	m_buttonAddHome.EnableWindow(TRUE);
	m_buttonRemove.EnableWindow(TRUE);
	m_buttonAuto.EnableWindow(TRUE);

	OnSelchangeListMonth();
	}
	
}


void CScheduleDlg::OnButtonAddVisitor() 
{
	// TODO: Add your control notification handler code here
	if(m_seasonStarted == FALSE)
	{
	CString team;
	int index = m_scheduleTeam.GetCurSel();
	if(index >= 0) // do if team list not blank
	{

	m_scheduleTeam.GetText(index, team);
	BOOL NoAdd = FALSE;
	int count = m_scheduleVisitor.GetCount();
	// Check if team selected is in list (home or visitor) already

	for(int i=0; i < count; i++)
	{
		CString visitor;
		m_scheduleVisitor.GetText(i, visitor);
		if(team == visitor) NoAdd = TRUE;
	}

	count = m_scheduleHome.GetCount();
	for(int i=0; i < count; i++)
	{
		CString home;
		m_scheduleHome.GetText(i, home);
		if(team == home) NoAdd = TRUE;
	}

	if(NoAdd == FALSE)
	{
		m_scheduleVisitor.AddString(team);
		UpdateData(FALSE);	
	}
	}
	}

	int index = m_scheduleTeam.GetCurSel();
	m_scheduleTeam.DeleteString(index);
}
	


BOOL CScheduleDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_LEAGUE_SCHEDULE);	
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsscheduler.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

}

void CScheduleDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsscheduler.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
//	WinHelp(HID_LEAGUE_SCHEDULE);		
}




void CScheduleDlg::SeasonEnd()//not used here anymore
{
}

void CScheduleDlg::OnButtonAutosch() 
{
	// TODO: Add your control notification handler code here
	CAutoSchDlg sch;
	sch.m_currentMonth = 1;
	sch.m_currentDay = 1;
	for(int i=0; i<=31; i++)
	{
		sch.m_leagueTeamNames[i+1] = avg.m_settings.m_leagueTeamNames[i];
		sch.m_conference[i+1] = avg.m_standings[i].m_conference;
		sch.m_division[i+1] = avg.m_standings[i].m_division;
		
	}
	sch.m_conferenceName1 = avg.m_settings.m_conferenceName1;
	sch.m_conferenceName2 = avg.m_settings.m_conferenceName2;
	sch.m_divisionName1 = avg.m_settings.m_divisionName1;
	sch.m_divisionName2 = avg.m_settings.m_divisionName2;
	sch.m_divisionName3 = avg.m_settings.m_divisionName3;
	sch.m_divisionName4 = avg.m_settings.m_divisionName4;
	sch.teams = avg.m_settings.m_numberteams;

	int result = sch.DoModal();
	if(result == IDOK)
	{

	m_resetStats = TRUE;



		int temp[33];
		for(int t=0; t<=32; t++)
		{
			temp[t] = 0;

		}


	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{

					m_schedule[i][j][k] = sch.m_sch[i][j][k];

					int g=m_schedule[i][j][k];
					int vis = g/100;
					int hom = g - vis*100;
					temp[vis] = temp[vis] + 1;
					temp[hom] = temp[hom] + 1;

			}
		}
	}
	}
//reset list boxes so they can be refilled with auto sch changes
	m_scheduleTeam.ResetContent();		
	m_scheduleVisitor.ResetContent();		
	m_scheduleHome.ResetContent();		
	m_scheduleMonth.SetCurSel(1);
	m_scheduleDay.SetCurSel(1);

	OnSelchangeListMonth();
}

HBRUSH CScheduleDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

//	Invalidate(FALSE);
	//Default();
     
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


//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	
//	// TODO: Change any attributes of the DC here
//		pDC->SetTextColor(RGB(0,0,0));
//	if (nCtlColor == CTLCOLOR_LISTBOX)
//	{
//		pDC->SetBkMode(TRANSPARENT);
//		pDC->SetBkColor(RGB(255,255,226));	
//		return HBRUSH(myBrush);
//	}	
}

void CScheduleDlg::OnDblclkListControl() 
{
	// TODO: Add your control notification handler code here

}

void CScheduleDlg::OnDblclkListVisitorScore() 
{
	// TODO: Add your control notification handler code here
}

void CScheduleDlg::OnDblclkListHomeScore() 
{
	// TODO: Add your control notification handler code here


}
