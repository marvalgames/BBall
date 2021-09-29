// ReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"

#include "ReportDlg.h"
#include "ImpExp.h"
#include "PlayerCardDlg.h"
#include "EditRatings.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog


CReportDlg::CReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReportDlg)
	//}}AFX_DATA_INIT

//	m_actual = new CPlayer[581];
bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
                    MAKEINTRESOURCE(IDB_BITMAP_BK)));
	m_in_game = false;

}


void CReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReportDlg)
	DDX_Control(pDX, IDC_TAB_MENU, m_tab);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_listTeams);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_STATIC19, m_edit[19]);
	DDX_Control(pDX, IDC_STATIC18, m_edit[18]);
	DDX_Control(pDX, IDC_STATIC17, m_edit[17]);
	DDX_Control(pDX, IDC_STATIC16, m_edit[16]);
	DDX_Control(pDX, IDC_STATIC15, m_edit[15]);
	DDX_Control(pDX, IDC_STATIC9, m_edit[9]);
	DDX_Control(pDX, IDC_STATIC8, m_edit[8]);
	DDX_Control(pDX, IDC_STATIC7, m_edit[7]);
	DDX_Control(pDX, IDC_STATIC6, m_edit[6]);
	DDX_Control(pDX, IDC_STATIC5, m_edit[5]);
	DDX_Control(pDX, IDC_STATIC4, m_edit[4]);
	DDX_Control(pDX, IDC_STATIC3, m_edit[3]);
	DDX_Control(pDX, IDC_STATIC2, m_edit[2]);
	DDX_Control(pDX, IDC_STATIC14, m_edit[14]);
	DDX_Control(pDX, IDC_STATIC13, m_edit[13]);
	DDX_Control(pDX, IDC_STATIC12, m_edit[12]);
	DDX_Control(pDX, IDC_STATIC11, m_edit[11]);
	DDX_Control(pDX, IDC_STATIC10, m_edit[10]);
	DDX_Control(pDX, IDC_STATIC1, m_edit[1]);
	DDX_Control(pDX, IDC_STATIC20, m_edit[20]);
	DDX_Control(pDX, IDC_STATIC21, m_edit[21]);

	DDX_Control(pDX, IDC_COMBO9, m_combo[9]);
	DDX_Control(pDX, IDC_COMBO8, m_combo[8]);
	DDX_Control(pDX, IDC_COMBO7, m_combo[7]);
	DDX_Control(pDX, IDC_COMBO6, m_combo[6]);
	DDX_Control(pDX, IDC_COMBO5, m_combo[5]);
	DDX_Control(pDX, IDC_COMBO4, m_combo[4]);
	DDX_Control(pDX, IDC_COMBO3, m_combo[3]);
	DDX_Control(pDX, IDC_COMBO2, m_combo[2]);
	DDX_Control(pDX, IDC_COMBO1, m_combo[1]);
	DDX_Control(pDX, IDC_COMBO10, m_combo[10]);
	DDX_Control(pDX, IDC_COMBO11, m_combo[11]);
	DDX_Control(pDX, IDC_COMBO12, m_combo[12]);
	DDX_Control(pDX, IDC_COMBO13, m_combo[13]);
	DDX_Control(pDX, IDC_COMBO25, m_combo[19]);
	DDX_Control(pDX, IDC_COMBO24, m_combo[18]);
	DDX_Control(pDX, IDC_COMBO23, m_combo[17]);
	DDX_Control(pDX, IDC_COMBO22, m_combo[16]);
	DDX_Control(pDX, IDC_COMBO15, m_combo[15]);
	DDX_Control(pDX, IDC_COMBO14, m_combo[14]);
	DDX_Control(pDX, IDC_COMBO35, m_combo[29]);
	DDX_Control(pDX, IDC_COMBO34, m_combo[28]);
	DDX_Control(pDX, IDC_COMBO33, m_combo[27]);
	DDX_Control(pDX, IDC_COMBO32, m_combo[26]);
	DDX_Control(pDX, IDC_COMBO31, m_combo[25]);
	DDX_Control(pDX, IDC_COMBO30, m_combo[24]);
	DDX_Control(pDX, IDC_COMBO29, m_combo[23]);
	DDX_Control(pDX, IDC_COMBO28, m_combo[22]);
	DDX_Control(pDX, IDC_COMBO27, m_combo[21]);
	DDX_Control(pDX, IDC_COMBO26, m_combo[20]);
	DDX_Control(pDX, IDC_COMBO45, m_combo[39]);
	DDX_Control(pDX, IDC_COMBO44, m_combo[38]);
	DDX_Control(pDX, IDC_COMBO43, m_combo[37]);
	DDX_Control(pDX, IDC_COMBO42, m_combo[36]);
	DDX_Control(pDX, IDC_COMBO41, m_combo[35]);
	DDX_Control(pDX, IDC_COMBO40, m_combo[34]);
	DDX_Control(pDX, IDC_COMBO39, m_combo[33]);
	DDX_Control(pDX, IDC_COMBO38, m_combo[32]);
	DDX_Control(pDX, IDC_COMBO37, m_combo[31]);
	DDX_Control(pDX, IDC_COMBO36, m_combo[30]);
	DDX_Control(pDX, IDC_COMBO55, m_combo[49]);
	DDX_Control(pDX, IDC_COMBO54, m_combo[48]);
	DDX_Control(pDX, IDC_COMBO53, m_combo[47]);
	DDX_Control(pDX, IDC_COMBO52, m_combo[46]);
	DDX_Control(pDX, IDC_COMBO51, m_combo[45]);
	DDX_Control(pDX, IDC_COMBO50, m_combo[44]);
	DDX_Control(pDX, IDC_COMBO49, m_combo[43]);
	DDX_Control(pDX, IDC_COMBO48, m_combo[42]);
	DDX_Control(pDX, IDC_COMBO47, m_combo[41]);
	DDX_Control(pDX, IDC_COMBO46, m_combo[40]);
	DDX_Control(pDX, IDC_COMBO65, m_combo[59]);
	DDX_Control(pDX, IDC_COMBO64, m_combo[58]);
	DDX_Control(pDX, IDC_COMBO63, m_combo[57]);
	DDX_Control(pDX, IDC_COMBO62, m_combo[56]);
	DDX_Control(pDX, IDC_COMBO61, m_combo[55]);
	DDX_Control(pDX, IDC_COMBO60, m_combo[54]);
	DDX_Control(pDX, IDC_COMBO59, m_combo[53]);
	DDX_Control(pDX, IDC_COMBO58, m_combo[52]);
	DDX_Control(pDX, IDC_COMBO57, m_combo[51]);
	DDX_Control(pDX, IDC_COMBO56, m_combo[50]);
	DDX_Control(pDX, IDC_COMBO145,m_combo[69]);
	DDX_Control(pDX, IDC_COMBO144,m_combo[68]);
	DDX_Control(pDX, IDC_COMBO143,m_combo[67]);
	DDX_Control(pDX, IDC_COMBO142,m_combo[66]);
	DDX_Control(pDX, IDC_COMBO141,m_combo[65]);
	DDX_Control(pDX, IDC_COMBO140,m_combo[64]);
	DDX_Control(pDX, IDC_COMBO139,m_combo[63]);
	DDX_Control(pDX, IDC_COMBO138,m_combo[62]);
	DDX_Control(pDX, IDC_COMBO137,m_combo[61]);
	DDX_Control(pDX, IDC_COMBO66, m_combo[60]);
	DDX_Control(pDX, IDC_COMBO146,m_combo[70]);
	DDX_Control(pDX, IDC_COMBO147,m_combo[71]);
	DDX_Control(pDX, IDC_COMBO148,m_combo[72]);
	DDX_Control(pDX, IDC_COMBO149,m_combo[73]);
	DDX_Control(pDX, IDC_COMBO150,m_combo[74]);
	DDX_Control(pDX, IDC_COMBO151,m_combo[75]);
	DDX_Control(pDX, IDC_COMBO167,m_combo[76]);
	DDX_Control(pDX, IDC_COMBO168,m_combo[77]);
	DDX_Control(pDX, IDC_COMBO169,m_combo[78]);
	DDX_Control(pDX, IDC_COMBO170,m_combo[79]);
	DDX_Control(pDX, IDC_COMBO171,m_combo[80]);
	DDX_Control(pDX, IDC_COMBO172,m_combo[81]);
	DDX_Control(pDX, IDC_COMBO173,m_combo[82]);
	DDX_Control(pDX, IDC_COMBO174,m_combo[83]);
	DDX_Control(pDX, IDC_COMBO175,m_combo[84]);
	DDX_Control(pDX, IDC_COMBO176,m_combo[85]);
	DDX_Control(pDX, IDC_COMBO177,m_combo[86]);
	DDX_Control(pDX, IDC_COMBO178,m_combo[87]);
	DDX_Control(pDX, IDC_COMBO179,m_combo[88]);
	DDX_Control(pDX, IDC_COMBO180,m_combo[89]);
	DDX_Control(pDX, IDC_COMBO71, m_combo[90]);


}


BEGIN_MESSAGE_MAP(CReportDlg, CDialog)
	//{{AFX_MSG_MAP(CReportDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_STATIC1, OnStatic1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MENU, OnSelchangeTabMenu)
	ON_BN_CLICKED(IDC_STATIC10, OnStatic10)
	ON_BN_CLICKED(IDC_STATIC11, OnStatic11)
	ON_BN_CLICKED(IDC_STATIC12, OnStatic12)
	ON_BN_CLICKED(IDC_STATIC13, OnStatic13)
	ON_BN_CLICKED(IDC_STATIC14, OnStatic14)
	ON_BN_CLICKED(IDC_STATIC15, OnStatic15)
	ON_BN_CLICKED(IDC_STATIC2, OnStatic2)
	ON_BN_CLICKED(IDC_STATIC3, OnStatic3)
	ON_BN_CLICKED(IDC_STATIC4, OnStatic4)
	ON_BN_CLICKED(IDC_STATIC5, OnStatic5)
	ON_BN_CLICKED(IDC_STATIC6, OnStatic6)
	ON_BN_CLICKED(IDC_STATIC7, OnStatic7)
	ON_BN_CLICKED(IDC_STATIC8, OnStatic8)
	ON_BN_CLICKED(IDC_STATIC9, OnStatic9)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_EXPORT, OnButtonExport)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImport)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_EXPORTALL, OnButtonExportall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportDlg message handlers

BOOL CReportDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR); 	
	InitControls();
	ViewRoster();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CReportDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_PLAYERS_EDITDEPTH);
//	return TRUE;			
//	return CDialog::OnHelpInfo(pHelpInfo);

//	HtmlHelp(NULL, "jumpshot.chm::/html/gameplan.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

}

void CReportDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
//	WinHelp(HID_PLAYERS_EDITDEPTH);
	// TODO: Add your message handler code here	
//	HtmlHelp(NULL, "jumpshot.chm::/html/gameplan.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

HBRUSH CReportDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CReportDlg::InitControls()
{

	if(m_in_game == true)
	{
		GetDlgItem(IDC_COMBO_TEAMS)->EnableWindow(FALSE);
	}

	InitDepthChartCombos();
	m_category = 1;
	m_tab.InsertItem(0, "Depth");
	m_tab.InsertItem(1, "Plan");

	UpdateData();




	for(int i=0; i<=32; i++)
	{
		if(m_leagueTeamNames[i] != "")
			m_listTeams.AddString(m_leagueTeamNames[i]);
	}

	m_listTeams.SetCurSel(m_default_team);
}

void CReportDlg::ViewRoster()
{
	int i = m_listTeams.GetCurSel();
	m_current = i;
	int index = i*30 + 1;
	int point[10] = {0,1,2,3,4,5,5, 255, 255,0};
	int pt[2] = {0,1};
		
	for(int c=0; c<=14; c++)
	{

		int r = index + c;

		CString string;

		string.Format("%s %s", avg.m_actual[r].GetPos(), avg.m_actual[r].GetName());
		if(avg.m_actual[r].GetName() == "") string = "empty";

		m_edit[c+1].SetWindowText(string);

		i = avg.m_actual[r].GetPgRot();
		m_combo[c+1].SetCurSel(point[i]);

		i = avg.m_actual[r].GetSgRot();
		m_combo[c+16].SetCurSel(point[i]);

		i = avg.m_actual[r].GetSfRot();
		m_combo[c+31].SetCurSel(point[i]);

		i = avg.m_actual[r].GetPfRot();
		m_combo[c+46].SetCurSel(point[i]);

		i = avg.m_actual[r].GetCRot();
		m_combo[c+61].SetCurSel(point[i]);

		i = avg.m_actual[r].GetActive();
		m_combo[c+76].SetCurSel(pt[i]);

	}

		GetDlgItem(IDC_BUTTON_RESET)->SetWindowText("Reset Depth Chart");

		m_edit[16].SetWindowText("pg");
		m_edit[17].SetWindowText("sg");
		m_edit[18].SetWindowText("sf");
		m_edit[19].SetWindowText("pf");
		m_edit[20].SetWindowText(" c");
		m_edit[21].SetWindowText("active");

}


void CReportDlg::SaveRoster()
{
	
	int index = m_current*30 + 1;
	int point[10] = {0,1,2,3,4,5,255, 255, 255,0};
	int pt[2] = {0,1};
		
	for(int c=0; c<=14; c++)
	{

		int r = index + c;
		int i = m_combo[c+1].GetCurSel();
		avg.m_actual[r].SetPgRot(point[i]);

		i = m_combo[c+16].GetCurSel();
		avg.m_actual[r].SetSgRot(point[i]);

		i = m_combo[c+31].GetCurSel();
		avg.m_actual[r].SetSfRot(point[i]);

		i = m_combo[c+46].GetCurSel();
		avg.m_actual[r].SetPfRot(point[i]);

		i = m_combo[c+61].GetCurSel();
		avg.m_actual[r].SetCRot(point[i]);

		i = m_combo[c+76].GetCurSel();
		avg.m_actual[r].SetActive(pt[i]);

	}

}

void CReportDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_category == 1)
	{
		SaveRoster();
	}
	else
	{
		SavePlan();
	}

	CDialog::OnOK();
}



void CReportDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	if(m_category == 1)
	{
		SaveRoster();
		ViewRoster();		
	}
	else
	{
		SavePlan();
		ViewPlan();
	}
	UpdateData();
}

void CReportDlg::OnStatic1() 
{
	// TODO: Add your control notification handler code here

	DisplayReport(1);
}

void CReportDlg::UpdateData()
{
	/*for(int i=1; i<=21; i++)
	{
		m_edit[i].SetFontName(USERFONT);
		m_edit[i].SetFontSize(8);
		m_edit[i].SetBkColor(RGB(255, 255, 255));
		m_edit[i].SetBorder(TRUE);
	}*/

}


void CReportDlg::InitDepthChartCombos()
{

for(int i=1; i<=75; i++)
{
	m_combo[i].ResetContent();	
	m_combo[i].AddString("no");
	m_combo[i].AddString("1st");
	m_combo[i].AddString("2nd");
	m_combo[i].AddString("3rd");
	m_combo[i].AddString("4th");
	m_combo[i].AddString("ok");
}

for(int i=76; i<=90; i++)
{
	m_combo[i].ResetContent();	
	m_combo[i].AddString("no");
	m_combo[i].AddString("yes");
}


}

void CReportDlg::OnSelchangeTabMenu(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index = m_tab.GetCurSel();

	if(m_category == 1)
	{
		SaveRoster();
	}
	else
	{
		SavePlan();
	}


	if(	index == 0) 
	{
		InitDepthChartCombos();
		m_category = 1;
		ViewRoster();
	}
	else
	{
		InitGamePlanCombos();
		m_category = 2;
		ViewPlan();
	}


	OnSelchangeComboTeams();
	
	*pResult = 0;
}

void CReportDlg::InitGamePlanCombos()
{
	for(int i=1; i<=90; i++)
	{
		m_combo[i].ResetContent();
	}



	for(int i=0; i<=48; i++)
	{
		CString fill;
		fill.Format("%d", i);
		if(i == 0) fill = "auto";
		for(int c=1; c<=15; c++)
		{
			m_combo[c].AddString(fill);
		}
	}

	CString data[] = {"auto", "outside", "drive", "post"};

	for(int i=0; i<=3; i++)
	{
		CString fill = data[i];
		for(int c=1; c<=15; c++)
		{

		m_combo[15+c].AddString(fill);
		m_combo[30+c].AddString(fill);

		}
	}



	CString data_1[] = {"-2", "-1", "-", "1", "2"};
	
	for(int i=0; i<=4; i++)
	{
		CString fill = data_1[i];
		for(int c=1; c<=15; c++)
		{

		m_combo[45+c].AddString(fill);
		m_combo[60+c].AddString(fill);
		m_combo[75+c].AddString(fill);

		}
	}

}

void CReportDlg::SavePlan()
{
	int index = m_current*30 + 1;
	int point[10] = {0,1,2,3,4,5,255, 255, 255,0};
	int pt[2] = {1,0};
		
	for(int c=0; c<=14; c++)
	{

		int r = index + c;

		int i = m_combo[c+1].GetCurSel();
		avg.m_actual[r].m_game_minutes = i;

		i = m_combo[c+16].GetCurSel();
		avg.m_actual[r].m_offensive_focus = i;

		i = m_combo[c+31].GetCurSel();
		avg.m_actual[r].m_defensive_focus = i;

		i = m_combo[c+46].GetCurSel();
		avg.m_actual[r].m_offensive_intensity = i-2;

		i = m_combo[c+61].GetCurSel();
		avg.m_actual[r].m_defensive_intensity = i-2;

		i = m_combo[c+76].GetCurSel();
		avg.m_actual[r].m_play_maker = i-2;

	}




}

void CReportDlg::ViewPlan()
{
	int i = m_listTeams.GetCurSel();
	m_current = i;
	int index = i*30 + 1;
	int point[10] = {0,1,2,3,4,5,255, 255, 255,0};
	int pt[2] = {1,0};
		
	for(int c=0; c<=14; c++)
	{
		
		CString string;
		int r = index + c;

		string.Format("%s %s", avg.m_actual[r].GetPos(), avg.m_actual[r].GetName());
		if(avg.m_actual[r].GetName() == "") string = "empty";

		m_edit[c+1].SetWindowText(string);


		i = avg.m_actual[r].m_game_minutes;
		m_combo[c+1].SetCurSel(i);

		i = avg.m_actual[r].m_offensive_focus;
		m_combo[c+16].SetCurSel(i);

		i = avg.m_actual[r].m_defensive_focus;
		m_combo[c+31].SetCurSel(i);

		i = avg.m_actual[r].m_offensive_intensity+2;
		m_combo[c+46].SetCurSel(i);

		i = avg.m_actual[r].m_defensive_intensity+2;
		m_combo[c+61].SetCurSel(i);

		i = avg.m_actual[r].m_play_maker+2;
		m_combo[c+76].SetCurSel(i);



	}


	
		GetDlgItem(IDC_BUTTON_RESET)->SetWindowText("Reset Game Plan");
		m_edit[16].SetWindowText("min");
		m_edit[17].SetWindowText("of");
		m_edit[18].SetWindowText("df");
		m_edit[19].SetWindowText("oi");
		m_edit[20].SetWindowText("di");
		m_edit[21].SetWindowText("bh");



}

void CReportDlg::OnStatic10() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(10);
	
}

void CReportDlg::OnStatic11() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(11);
	
}

void CReportDlg::OnStatic12() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(12);
	
}

void CReportDlg::OnStatic13() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(13);
	
}

void CReportDlg::OnStatic14() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(14);
	
}

void CReportDlg::OnStatic2() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(2);
	
}

void CReportDlg::OnStatic3() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(3);
	
}

void CReportDlg::OnStatic4() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(4);
	
}

void CReportDlg::OnStatic5() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(5);
	
}

void CReportDlg::OnStatic6() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(6);
	
}

void CReportDlg::OnStatic7() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(7);
	
}

void CReportDlg::OnStatic8() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(8);
	
}

void CReportDlg::OnStatic9() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(9);
	
}

void CReportDlg::DisplayReport(int index)
{
	int i = index;
	int j = m_listTeams.GetCurSel();
	int sl = j*30 + i;
	if(i > 0)
	{

	CPlayer m_player = avg.m_actual[sl];


	int players_listed = 15;


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	scout->m_default_scout = j;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;

	scout->m_player_index = i;
	scout->m_title = "Scout";
	scout->avg = avg;

	for(int c=0; c<=players_listed-1; c++)
	{
		scout->avg.m_actual[c] = avg.m_actual[j*30+c+1];
	}
	scout->m_player_index = i-1;
	scout->m_pl_index_end = players_listed-1;
	scout->m_pl_index_start = 0;

	scout->DoModal();
	delete scout;
	}


}

BOOL CReportDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
/*	CRect rect;
   GetClientRect(&rect);
   CDC dc;
   dc.CreateCompatibleDC(pDC);
   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

   BITMAP bm;
   bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
   iBitmapWidth = bm.bmWidth;
   iBitmapHeight = bm.bmHeight;

   // If our bitmap is smaller than the background and tiling is
   // supported, tile it. Otherwise watch the efficiency - don't
   // spend time setting up loops you won't need.

   if (iBitmapWidth  >= rect.Width() &&
       iBitmapHeight >= rect.Height() )
   {
      pDC->BitBlt (rect.left, 
                   rect.top, 
                   rect.Width(),
                   rect.Height(),
                   &dc,
                   0, 0, SRCCOPY);
   }
   else
   {
      for (iyOrg = 0; iyOrg < rect.Height(); iyOrg += iBitmapHeight)
      {
         for (ixOrg = 0; ixOrg < rect.Width(); ixOrg += iBitmapWidth)
         {
            pDC->BitBlt (ixOrg, 
                         iyOrg, 
                         rect.Width(),
                         rect.Height(),
                         &dc,
                         0, 0, SRCCOPY);
         }
      }
   }

   dc.SelectObject(pOldBitmap);
   return TRUE;	*/
	return CDialog::OnEraseBkgnd(pDC);
}

void CReportDlg::OnStatic15() 
{
	// TODO: Add your control notification handler code here
	DisplayReport(15);
	
}

void CReportDlg::OnButtonExport() 
{
	// TODO: Add your control notification handler code here
	if(m_category == 1)
	{
		SaveRoster();
	}
	else
	{
		SavePlan();
	}




	CImpExp* exp = new CImpExp;
	int j = m_listTeams.GetCurSel();
	CString team = avg.m_settings.m_leagueTeamNames[j];
	CString league = m_league_name;
	league.Remove(' ');

	CString file_name = m_path + league;
	exp->WriteDirectory(file_name);
	file_name = m_path + league + "\\exp";
	exp->WriteDirectory(file_name);
	for(int i=1; i<=15; i++)
	{
		CPlayer m_player = avg.m_actual[j*30+i];
		exp->CreateGamePlanString(m_player, i);
	}
	file_name = file_name + "\\" + team + ".txt";

	exp->ExportGamePlan(file_name);
	delete exp;

	CString s1 = team + " Game Plan is saved as file name " + file_name;
	AfxMessageBox(s1, MB_OK);

}

void CReportDlg::OnButtonImport() 
{
	// TODO: Add your control notification handler code here
	CImpExp* exp = new CImpExp;


	CString league = m_league_name;
	league.Remove(' ');

	CString file_name = m_path + league;
	exp->WriteDirectory(file_name);
	file_name = m_path + league + "\\imp";
	exp->WriteDirectory(file_name);



	int plans_found = 0;
	for(int j=0; j<=31; j++)
	{
		CString team = avg.m_settings.m_leagueTeamNames[j];

		file_name = m_path + league + "\\imp";
		exp->ImportGamePlan(file_name + "\\" + team + ".txt");
		CString tmp  = exp->m_game_plan_strings[1];
		tmp.TrimLeft();
		tmp.TrimRight();
		if(tmp == "") continue;//no plan found



		plans_found = plans_found + 1;

		for(int i=1; i<=15; i++)
		{
			CString tmp  = exp->m_game_plan_strings[i];
			int index = tmp.Find(",", 0); 
			CString str = tmp.Mid(0, index); 
			str.TrimLeft();
			str.TrimRight();

			for(int k=1; k<=15; k++)
			{
				if(str == avg.m_actual[j*30+k].m_name && 
					str != "")
						exp->ConvertGamePlanString(avg.m_actual[j*30+k], i);
			}
		}
	}



	CString s1;
	s1.Format("%d Game Plan(s) imported from directory %s", plans_found, file_name);
	AfxMessageBox(s1, MB_OK);


	if(m_category == 1)
		ViewRoster();		
	else
		ViewPlan();
	UpdateData();	
	delete exp;
	
}

void CReportDlg::OnButtonReset() 
{
	// TODO: Add your control notification handler code here
	int i = m_listTeams.GetCurSel();
	int index = i*30 + 1;

	if(m_category == 1)
	{

		for(int c=0; c<=14; c++)
		{

			int r = index + c;
			avg.m_actual[r].SetPgRot(0);
			avg.m_actual[r].SetSgRot(0);
			avg.m_actual[r].SetSfRot(0);
			avg.m_actual[r].SetPfRot(0);
			avg.m_actual[r].SetCRot(0);
			avg.m_actual[r].SetActive(1) ;

		}

		ViewRoster();		
	}
	else
	{

		for(int c=0; c<=14; c++)
		{

			int r = index + c;
			avg.m_actual[r].m_game_minutes = 0;
			avg.m_actual[r].m_offensive_focus = 0;
			avg.m_actual[r].m_defensive_focus = 0;
			avg.m_actual[r].m_offensive_intensity = 0;
			avg.m_actual[r].m_defensive_intensity = 0;
			avg.m_actual[r].m_play_maker = 0;

		}

		ViewPlan();		
	}

}

void CReportDlg::OnButtonExportall() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	if(m_category == 1)
	{
		SaveRoster();
	}
	else
	{
		SavePlan();
	}




	CImpExp* exp = new CImpExp;
	int pla = 0;
	for(int j=0; j<=32; j++)
	{
	CString team = avg.m_settings.m_leagueTeamNames[j];
	if(team == "") continue;
	CString league = m_league_name;
	league.Remove(' ');

	CString file_name = m_path + league;
	exp->WriteDirectory(file_name);
	file_name = m_path + league + "\\exp";
	exp->WriteDirectory(file_name);
	for(int i=1; i<=15; i++)
	{
		CPlayer m_player = avg.m_actual[j*30+i];
		exp->CreateGamePlanString(m_player, i);
	}
	file_name = file_name + "\\" + team + ".txt";

	exp->ExportGamePlan(file_name);
	pla = pla + 1;



	}
	delete exp;

	CString s1;
	CString s2 = m_path + m_league_name + "\\exp";
	s1.Format("%d game plans were saved in the folder %s", pla, s2);
	MessageBox(s1);
	
}
