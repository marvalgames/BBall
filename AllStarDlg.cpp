// AllStarDlg.cpp : implementation file
//

#include "stdafx.h"
//#include "constants.h"
//#include "resource.h"
#ifndef bball_h
#include "bball.h"
#define bball_h
#endif 
//#include "bball.h"
#include "MyComboBox.h"
#include "label.h"
#include "AllStarDlg.h"
#include "PlayerCardDlg.h"
#ifndef AllStarWeekend_h
#include "AllStarWeekend.h"	// Added by ClassView
#define AllStarWeekend_h
#endif


//#include "AllStarWeekend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllStarDlg dialog


CAllStarDlg::CAllStarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllStarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllStarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	asw = new CAllStarWeekend;
	for (int i = 0; i <= 80; i++)
	{
		m_index[i] = 0;
	}
	for (int i = 0; i <= 30; i++)
	{
		m_scores[i] = 0;
	}
	m_asw_over = false;
	m_default_team = 0;
	m_dunk_finished = false;
	m_three_finished = false;

}


void CAllStarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllStarDlg)
	DDX_Control(pDX, IDC_COMBO_ASWSELECT, m_combo_aswselect);
	DDX_Control(pDX, IDC_LIST_ROOKIES, m_list_rookies);
	DDX_Control(pDX, IDC_LIST_ALLSTARS, m_list_allstars);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDC_BUTTON_D2, m_button_d2);
	DDX_Control(pDX, IDC_BUTTON_D1, m_button_d1);
	DDX_Control(pDX, IDC_BUTTON_T3, m_button_t3);
	DDX_Control(pDX, IDC_BUTTON_T2, m_button_t2);
	DDX_Control(pDX, IDC_BUTTON_T1, m_button_t1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_STATIC_R1, m_name_r[1]);
	DDX_Control(pDX, IDC_STATIC_R2, m_name_r[2]);
	DDX_Control(pDX, IDC_STATIC_R3, m_name_r[3]);
	DDX_Control(pDX, IDC_STATIC_R4, m_name_r[4]);
	DDX_Control(pDX, IDC_STATIC_R5, m_name_r[5]);
	DDX_Control(pDX, IDC_STATIC_R6, m_name_r[6]);
	DDX_Control(pDX, IDC_STATIC_R7, m_name_r[7]);
	DDX_Control(pDX, IDC_STATIC_R8, m_name_r[8]);
	DDX_Control(pDX, IDC_STATIC_R9, m_name_r[9]);
	DDX_Control(pDX, IDC_STATIC_R10, m_name_r[10]);
	DDX_Control(pDX, IDC_STATIC_R11, m_name_r[11]);
	DDX_Control(pDX, IDC_STATIC_R12, m_name_r[12]);
	DDX_Control(pDX, IDC_STATIC_R13, m_name_r[13]);
	DDX_Control(pDX, IDC_STATIC_R14, m_name_r[14]);
	DDX_Control(pDX, IDC_STATIC_R15, m_name_r[15]);
	DDX_Control(pDX, IDC_STATIC_R16, m_name_r[16]);
	DDX_Control(pDX, IDC_STATIC_R17, m_name_r[17]);
	DDX_Control(pDX, IDC_STATIC_R18, m_name_r[18]);
	DDX_Control(pDX, IDC_STATIC_R19, m_name_r[19]);
	DDX_Control(pDX, IDC_STATIC_R20, m_name_r[20]);
	DDX_Control(pDX, IDC_STATIC_R21, m_name_r[21]);
	DDX_Control(pDX, IDC_STATIC_R22, m_name_r[22]);
	DDX_Control(pDX, IDC_STATIC_R23, m_name_r[23]);
	DDX_Control(pDX, IDC_STATIC_R24, m_name_r[24]);
	DDX_Control(pDX, IDC_STATIC_R25, m_name_r[25]);
	DDX_Control(pDX, IDC_STATIC_R26, m_name_r[26]);
	DDX_Control(pDX, IDC_STATIC_R27, m_name_r[27]);

}


BEGIN_MESSAGE_MAP(CAllStarDlg, CDialog)
	//{{AFX_MSG_MAP(CAllStarDlg)
	ON_BN_CLICKED(IDC_BUTTON_T1, OnButtonT1)
	ON_BN_CLICKED(IDC_BUTTON_D1, OnButtonD1)
	ON_BN_CLICKED(IDC_BUTTON_D2, OnButtonD2)
	ON_BN_CLICKED(IDC_BUTTON_T2, OnButtonT2)
	ON_BN_CLICKED(IDC_BUTTON_T3, OnButtonT3)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ALLSTARS, OnDblclkListAllstars)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ROOKIES, OnDblclkListRookies)
	ON_BN_CLICKED(IDC_BUTTON_ALLSTARSELECT, OnButtonAllstarselect)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CAllStarDlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllStarDlg message handlers

BOOL CAllStarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".asw";
	m_button_ok.EnableWindow(FALSE);
	myBrush.CreateSolidBrush(DLGCOLOR);


	CFileStatus status;
	CString user_file_name = avg.m_settings.m_path + "allstar.ini";
	bool user_file = false;




	m_button_d1.EnableWindow(TRUE);
	m_button_d2.EnableWindow(FALSE);
	m_button_t1.EnableWindow(TRUE);
	m_button_t2.EnableWindow(FALSE);
	m_button_t3.EnableWindow(FALSE);





	if (CFile::GetStatus(user_file_name, status) == TRUE) user_file = true;



	if (CFile::GetStatus(file_name, status) == TRUE)
	{

		GetDlgItem(IDC_COMBO_ASWSELECT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ALLSTARSELECT)->ShowWindow(FALSE);

		m_asw_over = true;
		m_button_d1.EnableWindow(FALSE);
		m_button_d2.EnableWindow(FALSE);
		m_button_t1.EnableWindow(FALSE);
		m_button_t2.EnableWindow(FALSE);
		m_button_t3.EnableWindow(FALSE);
		m_button_ok.ShowWindow(FALSE);
		m_button_cancel.SetWindowText("Exit");
		CStdioFile file(file_name, CFile::modeRead);
		CString str;
		int player = 0;
		for (int i = 0; i <= 80; i++)
		{


			file.ReadString(str);
			str.TrimRight();
			CString na = str.Mid(0, 6);
			m_index[i] = atoi(na);

			for (int j = 1; j <= 1440; j++)
			{
				if (avg.m_actual[j].m_id == m_index[i] && avg.m_actual[j].m_name != "")
					asw->m_actual[i] = avg.m_actual[j];
			}




		}
		for (int i = 0; i <= 30; i++)
		{


			file.ReadString(str);
			str.TrimRight();
			CString na = str.Mid(0, 4);
			m_scores[i] = atoi(na);
		}

	}

	else
	{

		int co = 0;
		for (int i = 1; i <= 1440; i++)
		{
			m_id_list[i - 1] = 0;
			if (avg.m_actual[i].m_name != "")
			{
				m_combo_aswselect.AddString(avg.m_actual[i].m_name);
				m_id_list[co] = i;
				co = co + 1;
			}


		}

		m_combo_aswselect.SetCurSel(0);


		asw->avg = avg;
		if (user_file == false)
		{
			asw->SelectThreePointContestants();
			asw->SelectDunkContestants();
			asw->SelectAllStarTeams();


			for (int i = 1; i <= 12; i++)
			{
				m_index[i] = asw->m_actual[i].m_id;
			}
			for (int i = 1; i <= 12; i++)
			{
				m_index[15 + i] = asw->m_actual[30 + i].m_id;
				//if (m_index[15 + i] == 0)
				//{
				//	m_index[15 + i] = 14 + i;//when no games played WEST can't be zero
				//}
			}


			asw->SelectRookieTeams();

			for (int i = 1; i <= 10; i++)
			{
				m_index[30 + i] = asw->m_actual[i].m_id;
			}
			for (int i = 1; i <= 10; i++)
			{
				m_index[45 + i] = asw->m_actual[30 + i].m_id;
			}

			for (int i = 1; i <= 8; i++)
			{
				m_index[60 + i] = asw->m_actual[60 + i].m_id;
			}



			for (int i = 1; i <= 8; i++)
			{
				m_index[70 + i] = asw->m_actual[70 + i].m_id;
			}

		}
		else if (user_file == true)
		{

			asw->ReadUserSelections(m_index, user_file_name);
		}


	}





	for (int i = 0; i <= 80; i++)
	{
		bool found = false;
		for (int j = 1; j <= 1440; j++)
		{
			if (avg.m_actual[j].m_id == m_index[i] && avg.m_actual[j].m_name != "" && found == false)
			{
				m_index[i] = j;
				found = true;
			}
		}
	}



	DisplayThreeField();
	if (m_asw_over == true)
	{
		DisplayThreeRound1();
		DisplayThreeRound2();
		DisplayThreeRound3();
	}
	DisplayDunkField();
	if (m_asw_over == true)
	{
		DisplayDunkRound1();
		DisplayDunkRound2();
	}

	InitCtrl();
	ListAswRosters();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllStarDlg::DisplayThreeRound1()
{
	for (int i = 1; i <= 4; i++)
	{
		CString na = asw->m_actual[60 + i].m_name;
		//int sc = asw->m_actual[60+i].m_3ptscore[1];
		int sc = m_scores[23 + i];
		CString str;
		str.Format(" %d", sc);
		na = asw->m_actual[60 + i].m_pos + " " + na + str;
		m_name_r[8 + i].SetWindowText(na);
	}

}

void CAllStarDlg::DisplayThreeRound2()
{
	for (int i = 1; i <= 2; i++)
	{
		CString na = asw->m_actual[60 + i].m_name;
		//int sc = asw->m_actual[60+i].m_3ptscore[2];
		int sc = m_scores[27 + i];
		CString str;
		str.Format(" %d", sc);
		//		na = na + str;
		na = asw->m_actual[60 + i].m_pos + " " + na + str;
		m_name_r[12 + i].SetWindowText(na);
	}

}

void CAllStarDlg::DisplayThreeRound3()
{
	for (int i = 1; i <= 1; i++)
	{
		CString na = asw->m_actual[60 + i].m_name;
		//int sc = asw->m_actual[60+i].m_3ptscore[3];
		int sc = m_scores[28];
		CString str;
		str.Format(" %d", sc);
		//		na = na + str;
		na = asw->m_actual[60 + i].m_pos + " " + na + str;
		m_name_r[14 + i].SetWindowText(na);
	}


	//	for(int i=1; i<=8; i++)
	//	{
	//		m_index[60+i] = asw->m_actual[60+i].m_id;
	//	}

}



void CAllStarDlg::DisplayThreeField()
{
	for (int i = 1; i <= 8; i++)
	{
		CString na = asw->m_actual[60 + i].m_name;
		//int sc = asw->m_actual[60+i].m_3ptscore[1];
		int sc = m_scores[15 + i];
		CString str;
		str.Format(" %d", sc);
		//		na = na + str;
		na = asw->m_actual[60 + i].m_pos + " " + na + str;
		m_name_r[i].SetWindowText(na);
	}


}

void CAllStarDlg::DisplayDunkRound1()
{
	for (int i = 1; i <= 3; i++)
	{
		CString na = asw->m_actual[70 + i].m_name;
		//double sc = (double)asw->m_actual[70+i].m_dunkscore[1]/10;
		double sc = (double)m_scores[8 + i] / 10;
		CString str;
		str.Format(" %.1f", sc);
		//		na = na + str;
		na = asw->m_actual[70 + i].m_pos + " " + na + str;
		m_name_r[23 + i].SetWindowText(na);
	}
}

void CAllStarDlg::DisplayDunkRound2()
{
	for (int i = 1; i <= 1; i++)
	{
		CString na = asw->m_actual[70 + i].m_name;
		double sc = (double)m_scores[9] / 10;
		CString str;
		str.Format(" %.1f", sc);
		//na = na + str;
		na = asw->m_actual[70 + i].m_pos + " " + na + str;

		m_name_r[26 + i].SetWindowText(na);
	}

	//for(int i=1; i<=8; i++)
	//{
	//	m_index[70+i] = asw->m_actual[70+i].m_id;
	//}


}

void CAllStarDlg::OnButtonT1()
{
	// TODO: Add your control notification handler code here
	m_button_t1.EnableWindow(FALSE);
	m_button_t2.EnableWindow(TRUE);
	m_button_t3.EnableWindow(FALSE);



	asw->SimThreePointContestRoundOne();
	for (int i = 1; i <= 8; i++)
	{
		m_scores[15 + i] = asw->m_scores[15 + i];
	}
	DisplayThreeField();
	DisplayThreeRound1();
}

void CAllStarDlg::OnButtonD1()
{
	// TODO: Add your control notification handler code here


	m_button_d1.EnableWindow(FALSE);
	m_button_d2.EnableWindow(TRUE);
	asw->SimSlamDunkContestRoundOne();
	for (int i = 1; i <= 8; i++)
	{
		m_scores[i] = asw->m_scores[i];
	}

	DisplayDunkField();
	DisplayDunkRound1();

}

void CAllStarDlg::OnButtonD2()
{
	// TODO: Add your control notification handler code here
	m_button_d1.EnableWindow(FALSE);
	m_button_d2.EnableWindow(FALSE);
	m_dunk_finished = true;
	if (m_dunk_finished == true && m_three_finished == true)
		m_button_ok.EnableWindow(TRUE);
	asw->SimSlamDunkContestRoundTwo();
	for (int i = 9; i <= 11; i++)
	{
		m_scores[i] = asw->m_scores[i];
	}
	DisplayDunkRound1();
	DisplayDunkRound2();

}

void CAllStarDlg::OnButtonT2()
{
	// TODO: Add your control notification handler code here

	m_button_t1.EnableWindow(FALSE);
	m_button_t2.EnableWindow(FALSE);
	m_button_t3.EnableWindow(TRUE);

	asw->SimThreePointContestRoundTwo();

	for (int i = 1; i <= 4; i++)
	{
		m_scores[23 + i] = asw->m_scores[23 + i];
	}

	DisplayThreeRound1();
	DisplayThreeRound2();

}

void CAllStarDlg::OnButtonT3()
{
	// TODO: Add your control notification handler code here
	m_button_t1.EnableWindow(FALSE);
	m_button_t2.EnableWindow(FALSE);
	m_button_t3.EnableWindow(FALSE);


	m_three_finished = true;
	if (m_dunk_finished == true && m_three_finished == true)
		m_button_ok.EnableWindow(TRUE);

	asw->SimThreePointContestRoundThree();
	for (int i = 1; i <= 2; i++)
	{
		m_scores[27 + i] = asw->m_scores[27 + i];
	}

	DisplayThreeRound2();
	DisplayThreeRound3();

}

void CAllStarDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	delete asw;

}

void CAllStarDlg::DisplayDunkField()
{
	for (int i = 1; i <= 8; i++)
	{
		CString na = asw->m_actual[70 + i].m_name;
		//double sc = (double)asw->m_actual[70+i].m_dunkscore[1]/10;
		double sc = (double)m_scores[i] / 10;
		CString str;
		str.Format(" %.1f", sc);
		//na = na + str;
		na = asw->m_actual[70 + i].m_pos + " " + na + str;
		m_name_r[15 + i].SetWindowText(na);
	}


}

void CAllStarDlg::OnOK()
{
	// TODO: Add extra validation here

	for (int i = 1; i <= 8; i++)
	{
		m_index[60 + i] = asw->m_actual[60 + i].m_id;
	}

	for (int i = 1; i <= 8; i++)
	{
		m_index[70 + i] = asw->m_actual[70 + i].m_id;
	}


	for (int i = 0; i <= 60; i++)
	{
		//bool found = false;
		//for(int j=1; j<=1440; j++)
		//{
		//	if(avg.m_actual[j].m_id == m_index[i] && avg.m_actual[j].m_name != "" && found == false)
		//	{
		//		m_index[i] = avg.m_actual[j].m_id;
		//		found = true;
		//	}
		//	}
		m_index[i] = avg.m_actual[m_index[i]].m_id;
	}


	for (int i = 1; i <= 30; i++)
	{
		m_scores[i] = asw->m_scores[i];
	}

	CDialog::OnOK();
}

void CAllStarDlg::InitCtrl()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_list_rookies.SetBkColor(BK_COLOR);
	m_list_rookies.SetTextBkColor(BK_COLOR);

	m_list_rookies.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_list_rookies.SetTextColor(RGB(0, 0, 0));
	m_list_rookies.SetFont(&m_font);



	m_list_allstars.SetBkColor(BK_COLOR);
	m_list_allstars.SetTextBkColor(BK_COLOR);

	m_list_allstars.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_list_allstars.SetTextColor(RGB(0, 0, 0));
	m_list_allstars.SetFont(&m_font);


	m_list_allstars.InsertColumn(0, "po");
	m_list_allstars.InsertColumn(1, "player");
	m_list_allstars.InsertColumn(2, "team");
	m_list_allstars.InsertColumn(3, "");

	m_list_rookies.InsertColumn(0, "po");
	m_list_rookies.InsertColumn(1, "player");
	m_list_rookies.InsertColumn(2, "team");
	m_list_rookies.InsertColumn(3, "");

	m_list_allstars.SetColumnWidth(0, 30);
	m_list_allstars.SetColumnWidth(1, 90);
	m_list_allstars.SetColumnWidth(2, 76);
	m_list_allstars.SetColumnWidth(3, 70);

	m_list_rookies.SetColumnWidth(0, 30);
	m_list_rookies.SetColumnWidth(1, 90);
	m_list_rookies.SetColumnWidth(2, 76);
	m_list_rookies.SetColumnWidth(3, 70);

}

void CAllStarDlg::ListAswRosters()
{

	int co = 0;

	m_list_allstars.DeleteAllItems();

	for (int i = 1; i <= 30; i++)
	{
		m_player_list[i - 1] = 0;


		CString s1 = avg.m_actual[m_index[i]].m_pos;
		CString s2 = avg.m_actual[m_index[i]].m_name;
		CString s3 = avg.m_actual[m_index[i]].m_team_paying_name;
		CString s4 = avg.m_settings.m_conferenceName1;
		if (i > 15) s4 = avg.m_settings.m_conferenceName2;
		if (s2 == "") continue;

		m_list_allstars.InsertItem(co, s1);
		m_list_allstars.SetItemText(co, 1, s2);
		m_list_allstars.SetItemText(co, 2, s3);
		m_list_allstars.SetItemText(co, 3, s4);
		m_player_list[co] = i;
		co = co + 1;
	}


	m_list_allstars.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	m_list_allstars.EnsureVisible(0, TRUE);

	co = 0;
	for (int i = 1; i <= 30; i++)
	{
		CString s1 = avg.m_actual[m_index[30 + i]].m_pos;
		CString s2 = avg.m_actual[m_index[30 + i]].m_name;
		CString s3 = avg.m_actual[m_index[30 + i]].m_team_paying_name;
		int y = avg.m_actual[m_index[30 + i]].m_yrs_of_service;
		CString s4 = "Rookie";
		if (y == 2) s4 = "Soph";
		if (s2 == "") continue;
		m_list_rookies.InsertItem(co, s1);
		m_list_rookies.SetItemText(co, 1, s2);
		m_list_rookies.SetItemText(co, 2, s3);
		m_list_rookies.SetItemText(co, 3, s4);
		co = co + 1;
	}

}

void CAllStarDlg::OnDblclkListAllstars(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int j = m_list_allstars.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) + 1;
	CPlayer tmp[81];
	for (int i = 0; i <= 80; i++)
	{
		tmp[i] = avg.m_actual[m_index[i]];
	}


	if (j > 0)
	{


		//CPlayer m_player = FA[i+1];


		//int players_listed = m_listfa.GetItemCount();
		//int tm = m_player.m_team_index - 1;

		//CString team = "";
		//if(tm < 0) team = "";
		//else team = avg.m_settings.m_leagueTeamNames[tm];


		CPlayerCardDlg* scout = new CPlayerCardDlg;
		scout->m_default_scout = m_default_team;

		scout->m_path = avg.m_settings.m_path;
		scout->m_leagueName = avg.m_settings.m_league_name;

		scout->m_player_index = j;
		scout->m_title = "Scout";
		scout->avg = avg;

		int co = 1;
		for (int c = 0; c <= 30; c++)
		{
			if (tmp[c].m_name != "")
			{

				scout->avg.m_actual[co] = tmp[c];
				co = co + 1;
			}
		}
		scout->m_player_index = j;
		scout->m_pl_index_end = co;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;
	}
	*pResult = 0;

}

void CAllStarDlg::OnDblclkListRookies(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int j = m_list_rookies.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) + 1;
	if (j > 0)
	{

		//CPlayer m_player = FA[i+1];


		//int players_listed = m_listfa.GetItemCount();
		//int tm = m_player.m_team_index - 1;

		//CString team = "";
		//if(tm < 0) team = "";
		//else team = avg.m_settings.m_leagueTeamNames[tm];


		CPlayerCardDlg* scout = new CPlayerCardDlg;
		scout->m_default_scout = m_default_team;

		scout->m_path = avg.m_settings.m_path;
		scout->m_leagueName = avg.m_settings.m_league_name;

		scout->m_player_index = j;
		scout->m_title = "Scout";
		scout->avg = avg;


		int co = 1;

		for (int c = 0; c <= 30; c++)
		{
			if (avg.m_actual[m_index[30 + c]].m_name != "")
			{
				scout->avg.m_actual[co] = avg.m_actual[m_index[30 + c]];
				co = co + 1;
			}
		}
		scout->m_player_index = j;
		scout->m_pl_index_end = 30;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;
	}
	*pResult = 0;


	//*pResult = 0;
}

void CAllStarDlg::OnButtonAllstarselect()
{
	// TODO: Add your control notification handler code here
	int i = m_combo_aswselect.GetCurSel();
	int j = m_list_allstars.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	int k = m_player_list[j];

	m_index[k] = m_id_list[i];
	ListAswRosters();

}

BOOL CAllStarDlg::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/allstar.htm", HH_DISPLAY_TOPIC, 0);


	return CDialog::OnHelpInfo(pHelpInfo);
}

void CAllStarDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/allstar.htm", HH_DISPLAY_TOPIC, 0);

}

HBRUSH CAllStarDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(STATICCOLOR);
		pDC->SetBkColor(logbrush.lbColor);
		return myBrush;
	case CTLCOLOR_BTN:
		pDC->SetTextColor(RGB(0, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return myBrush;
	case CTLCOLOR_LISTBOX:
		pDC->SetBkColor(LISTBOXCOLOR);
		pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return myBrush;

	case CTLCOLOR_SCROLLBAR:
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(LISTBOXCOLOR);
		return myBrush;

	case CTLCOLOR_MSGBOX:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return myBrush;

	case CTLCOLOR_DLG:
		return myBrush;
		//This shouldn't occurr since we took all the cases, but
		//JUST IN CASE, return the new brush
	default:
		return hbr;
	}
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}


void CAllStarDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
