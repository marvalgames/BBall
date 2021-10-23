// TransactionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bball.h"
//#include "constants.h"
//#include "resource.h"
//#include "MyComboBox.h"
#include "TransactionsDlg.h"
//#include "PlayerCardDlg.h"
//#include "Transactions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransactionsDlg dialog


CTransactionsDlg::CTransactionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransactionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransactionsDlg)
	//}}AFX_DATA_INIT
}


CTransactionsDlg::~CTransactionsDlg()
{

}



void CTransactionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransactionsDlg)
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_list_teams);
	DDX_Control(pDX, IDC_LIST_TRADES, m_listTrades);
	//DDX_Control(pDX, IDOK, m_button[0]);
	//DDX_Control(pDX, IDC_RADIO_TRADES, m_button[1]);
	//DDX_Control(pDX, IDC_RADIO_INJURIES, m_button[2]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTransactionsDlg, CDialog)
	//{{AFX_MSG_MAP(CTransactionsDlg)
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_RADIO_TRADES, OnRadioTrades)
	ON_BN_CLICKED(IDC_RADIO_INJURIES, OnRadioInjuries)
	//ON_NOTIFY(NM_DBLCLK, IDC_LIST_TRADES, OnDblclkListTrades)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_TRADES, &CTransactionsDlg::OnDblclkListTrades)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransactionsDlg message handlers

BOOL CTransactionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitControls();


 myBrush.CreateSolidBrush(DLGCOLOR); 
	CString string;
//	char s[129];
//	CString pFileName = m_league;
//	CFile file(	pFileName, CFile::modeRead);
	
//	int bytes = file.Read(s, 16);
//	s[bytes] = 0;
	int n = avg.m_settings.m_number_transactions;
    int t1 = 0, t2 = 0;

	m_number = n;

	for(int i=0; i<=4095; i++)
	{
		m_id_list[i] = 0;
	}
		
	for(int i=1; i<=n; i++)
	{
//		int seek = (i-1)*128+17;
//		file.Seek( seek, CFile::begin );
//		int bytes = file.Read(s, 128);
//		s[bytes] = 0;
		string = avg.m_trans_str[i];
		//string = string + "                                                                            ";
		m_trans_list[i].m_month = atoi(string.Mid(0,2));
		m_trans_list[i].m_day = atoi(string.Mid(2,2));
		m_trans_list[i].m_year = atoi(string.Mid(4,4));
		int ty = atoi(string.Mid(8,2));
		if(ty == 2) ReadTrades(i, string);
		else if(ty >= 3 && ty <= 4) ReadSignings(i, string);
		else if(ty == 1) ReadInjuries(i, string);
		else if(ty >= 5) ReadFaSignings(i, string);
		m_trans_list[i].m_type = ty;
		m_id_list[i] = 0;

	}
    
	//file.Close();		
	ListTransactions();


	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CTransactionsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/transactions.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

//	WinHelp(HID_LEAGUE_TRANSACTIONS);	
//	return TRUE;
}

HBRUSH CTransactionsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
		  //return hbr;
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
//	return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 
}

void CTransactionsDlg::ReadTrades(int index, CString string)
{

	int col = 0;
	for(int seek = 0; seek <= 76; seek = seek + 19)
	{

		int pic = atoi(string.Mid(seek+10,1));
		if(seek == 76 && string.GetLength() <= 95) continue;

		if(pic == 0)
		{
			int team1 = atoi(string.Mid(seek+11,6));
			int team2 = atoi(string.Mid(seek+17,6));
			int id = atoi(string.Mid(seek+23,6));
			m_trans_list[index].m_team1[col] = team1;
			m_trans_list[index].m_team2[col] = team2;
			m_trans_list[index].m_id[col] = id;					
			m_trans_list[index].m_pic[col] = 0;					

		}
		else
		{
			int yr = atoi(string.Mid(seek+11,6));
			int rd = atoi(string.Mid(seek+17,6));
			int tm = atoi(string.Mid(seek+23,6));
			m_trans_list[index].m_pick_yr[col] = yr;
			m_trans_list[index].m_pick_rd[col] = rd;
			m_trans_list[index].m_pick_te[col] = tm;					
			m_trans_list[index].m_pic[col] = 1;					
		}
		col = col + 1;

	}
}


void CTransactionsDlg::ReadSignings(int index, CString string)
{

	int team = atoi(string.Mid(10,2));
	int id = atoi(string.Mid(12,6));
	m_trans_list[index].m_signing_team = team;
	m_trans_list[index].m_signing_id = id;

}

void CTransactionsDlg::ReadFaSignings(int index, CString string)
{

	int team = atoi(string.Mid(10,2));
	int id = atoi(string.Mid(12,6));
	int yr = atoi(string.Mid(18,1));
	int sa = atoi(string.Mid(19,5));
	m_trans_list[index].m_signing_team = team;
	m_trans_list[index].m_signing_id = id;
	m_trans_list[index].m_signing_yr = yr;
	m_trans_list[index].m_signing_sa = sa;


}

void CTransactionsDlg::ReadInjuries(int index, CString string)
{

	int id = atoi(string.Mid(10,6));
	int team = atoi(string.Mid(16,2));
	int games = atoi(string.Mid(18,4));
	CString desc = string.Mid(22, 32);
	desc.TrimLeft();
	desc.TrimRight();
	m_trans_list[index].m_injury_team = team;
	m_trans_list[index].m_injury_id = id;
	m_trans_list[index].m_injury_games = games;
	m_trans_list[index].m_injury_desc = desc;


}



void CTransactionsDlg::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listTrades.SetBkColor(BK_COLOR);
	m_listTrades.SetTextBkColor(TEXT_BK_COLOR);

	m_listTrades.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    m_listTrades.SetTextColor(RGB(0,0,0));
	m_listTrades.SetFont(&m_font);


    m_listTrades.DeleteColumn(0);
    m_listTrades.InsertColumn(0,"date");    
	m_listTrades.DeleteColumn(1);
    m_listTrades.InsertColumn(1,"team");    
	m_listTrades.DeleteColumn(2);
    m_listTrades.InsertColumn(2,"action");    
	m_listTrades.DeleteColumn(3);
    m_listTrades.InsertColumn(3,"player");    
	m_listTrades.DeleteColumn(4);
    m_listTrades.InsertColumn(4,"");    
	


	m_listTrades.SetColumnWidth(0,108);
	m_listTrades.SetColumnWidth(1,128);
	m_listTrades.SetColumnWidth(2,128);
	m_listTrades.SetColumnWidth(3,216);
	m_listTrades.SetColumnWidth(4,128);


	m_list_teams.AddString(m_league_name);
	for(int i=0; i<=32; i++)
	{
		if(m_league_team_names[i] != "") 
			m_list_teams.AddString(m_league_team_names[i]);
	}

	m_list_teams.SetCurSel(m_default_team+1);

	//CheckDlgButton(IDC_RADIO_TRADES, 0);
	m_category = 1;
	m_row = 0;
	m_id_list[0] = 0;
}

void CTransactionsDlg::ListTransactions()
{
	m_listTrades.DeleteAllItems();
	m_row = 0;

	int index = m_list_teams.GetCurSel();

	for(int i=1; i<=m_number; i++)
	{
		int ty = m_trans_list[i].m_type;
		if(ty == 2 && m_category == 1) ListTrade(m_row, i);
		else if(ty >= 3 && ty <= 4 && m_category == 1) ListSignings(m_row, i);
		else if(ty == 1 && m_category == 2) ListInjuries(m_row, i);
		else if((ty == 5 || ty == 6)&& m_category == 1) ListFaSignings(m_row, i);

	}
}

void CTransactionsDlg::ListTrade(int row, int index)
{
	
	int sel = m_list_teams.GetCurSel();

	int tr1 = m_trans_list[index].m_team1[0];
	int tr2 = m_trans_list[index].m_team2[0];


	
	for(int i=0; i <= 4; i++)
	{

	int team1 = m_trans_list[index].m_team1[i];
	int team2 = m_trans_list[index].m_team2[i];
	int pic = m_trans_list[index].m_pic[i];
	int tm = m_trans_list[index].m_pick_te[i];

	if((team1 > 0 && team2 > 0 && (sel == 0 || team1 == sel || team2 == sel)) ||    ((sel == 0 || tr1 == sel || tr2 == sel || tm == sel) &&  pic > 0))
	{
	

	int month = m_trans_list[index].m_month;
	int day = m_trans_list[index].m_day;
	int year = m_trans_list[index].m_year;
	CString date;
	date.Format("%d/%d/%d", month, day, year);
//	m_id_list[m_row] = 0;
	m_listTrades.InsertItem(m_row, (LPCTSTR)date);


			
//	for(int i = 0; i <= 4; i++)
//	{

		if(pic == 0)
		{
			int id = m_trans_list[index].m_id[i];
//			m_id_list[m_row] = id;
			CString name = FindName(id);
			CString te1 = m_league_team_names[team1-1];
			CString te2 = "to " + m_league_team_names[team2-1];
			m_listTrades.SetItemText(m_row,1, (LPCTSTR)te1);
			m_listTrades.SetItemText(m_row,2, (LPCTSTR)"trade");
			m_listTrades.SetItemText(m_row,3, (LPCTSTR)name);
			m_listTrades.SetItemText(m_row,4, (LPCTSTR)te2);


		}
		else
		{
			int yr = m_trans_list[index].m_pick_yr[i];
			int rd = m_trans_list[index].m_pick_rd[i];
			int tm = m_trans_list[index].m_pick_te[i];
			CString y, r, t, str, other_team;
			y.Format("%d", yr);
			r.Format("%d", rd);
			t = m_league_team_names[tm-1];
			int o_t = tr1;
			if(o_t == tm) o_t = tr2;
			str.Format((LPCTSTR)"%s round %s %s", y,r,t);

			if(o_t >= 1) other_team = "to " + m_league_team_names[o_t-1];

			m_listTrades.SetItemText(m_row,1, (LPCTSTR)t);
			m_listTrades.SetItemText(m_row,2, (LPCTSTR)"trade");
			m_listTrades.SetItemText(m_row,3, (LPCTSTR)str);
			m_listTrades.SetItemText(m_row,4, (LPCTSTR)other_team);


		}

//	}


	


	m_row = m_row + 1;
	}


	}
}

void CTransactionsDlg::ListSignings(int row, int index)
{

	int sel = m_list_teams.GetCurSel();	

	int team = m_trans_list[index].m_signing_team;


	if(team > 0 && (sel == 0 || team == sel))
	{

//	m_id_list[m_row] = 0;
	
	int month = m_trans_list[index].m_month;
	int day = m_trans_list[index].m_day;
	int year = m_trans_list[index].m_year;
	int ty = m_trans_list[index].m_type;
	CString date;
	date.Format("%d/%d/%d", month, day, year);

	m_listTrades.InsertItem(m_row, date);

	CString te = m_league_team_names[team-1];
	m_listTrades.SetItemText(m_row,1, (LPCTSTR)te);
	if(ty == 3)
		m_listTrades.SetItemText(m_row,2, (LPCTSTR)"sign");
	else if(ty == 4)
		m_listTrades.SetItemText(m_row,2, (LPCTSTR)"release");
			

	int id = m_trans_list[index].m_signing_id;
//	m_id_list[m_row] = id;
	CString name = FindName(id);
	m_listTrades.SetItemText(m_row,3, (LPCTSTR)name);
	m_row = m_row + 1;

	}
}

void CTransactionsDlg::ListInjuries(int row, int index)
{

	int sel = m_list_teams.GetCurSel();	

	int team = m_trans_list[index].m_injury_team;


	if(team > 0 && (sel == 0 || team == sel))
	{

	
	int month = m_trans_list[index].m_month;
	int day = m_trans_list[index].m_day;
	int year = m_trans_list[index].m_year;
	int ty = m_trans_list[index].m_type;
	int ga = m_trans_list[index].m_injury_games;
	CString desc = m_trans_list[index].m_injury_desc;
	CString date, inj;
	date.Format("%d/%d/%d", month, day, year);
//	m_id_list[m_row] = 0;

	m_listTrades.InsertItem(m_row, (LPCTSTR)date);

	CString te = m_league_team_names[team-1];
	m_listTrades.SetItemText(m_row,1, (LPCTSTR)te);
	m_listTrades.SetItemText(m_row,2, (LPCTSTR)desc);
			

	int id = m_trans_list[index].m_injury_id;
//	m_id_list[m_row] = id;
	CString name = FindName(id);
	inj.Format("%d", ga);
	if(ga == 1) inj = inj + " day";
	else inj = inj + " days";

	m_listTrades.SetItemText(m_row,3, (LPCTSTR)name);
	m_listTrades.SetItemText(m_row,4, (LPCTSTR)inj);
	m_row = m_row + 1;

	}
}

CString CTransactionsDlg::FindName(int id)
{
	CString name = "";
	int slot = -1;
	for(int i=0; i<=1440; i++)
	{
		if(avg.m_actual[i].m_id == id)
		{
			name = avg.m_actual[i].m_pos + " " + avg.m_actual[i].m_name;
			slot = i;
		}
	}

	if(slot >= 0) m_id_list[m_row] = slot;

	return name;
}

void CTransactionsDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	ListTransactions();	
}

void CTransactionsDlg::OnRadioTrades() 
{
	// TODO: Add your control notification handler code here
	if(m_category == 2)
	{
		m_category = 1;	
		ListTransactions();
	}
}

void CTransactionsDlg::OnRadioInjuries() 
{
	// TODO: Add your control notification handler code here
	if(m_category == 1)
	{
		m_category = 2;	
		ListTransactions();
	}
	
}

//void CTransactionsDlg::OnDblclkListTrades(NMHDR* pNMHDR, LRESULT* pResult) 
//{
////	m_row = m_list_free_agents.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
//	int i = m_listTrades.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
//	if(i >= 0)
//	{
//	int players_listed = m_listTrades.GetItemCount();
//	int pointer = m_id_list[i];
//	CPlayer m_player = avg.m_actual[pointer];
//	int tm = m_player.m_team_index - 1;
//	
//	CString team = "";
//	if(tm < 0) team = "";
//	else team = m_league_team_names[tm];
//
//
//	CPlayerCardDlg *scout = new CPlayerCardDlg;
//	scout->m_default_scout = m_list_teams.GetCurSel();
//
//	scout->m_path = avg.m_settings.m_path;
//	scout->m_leagueName = avg.m_settings.m_league_name;
//
//	scout->m_player_index = i;
//	scout->m_title = "Scout";
//	scout->avg = avg;
//
//	for(int c=0; c<=players_listed-1; c++)
//	{
//		scout->avg.m_actual[c] = avg.m_actual[m_id_list[c]];
//	}
//	scout->m_player_index = i;
//	scout->m_pl_index_end = players_listed-1;
//	scout->m_pl_index_start = 0;
//
//	scout->DoModal();
//	delete scout;
//
//	//CPlayerCardDlg scout;
//	/*scout.m_default_scout = m_list_teams.GetCurSel();
//
//	scout.m_path = avg.m_settings.m_path;
//	scout.m_leagueName = avg.m_settings.m_league_name;
//
//	scout.m_player_index = i;
//	scout.m_title = "Scout";
//	scout.avg = avg;
//
//	for (int c = 0; c <= players_listed - 1; c++)
//	{
//		scout.avg.m_actual[c] = avg.m_actual[m_id_list[c]];
//	}
//	scout.m_player_index = i;
//	scout.m_pl_index_end = players_listed - 1;
//	scout.m_pl_index_start = 0;*/
//
//	//scout.DoModal();
//
//	//delete scout;
//
//
//
//
//
//	}
//	*pResult = 0;
//}

void CTransactionsDlg::ListFaSignings(int row, int index)
{

	int sel = m_list_teams.GetCurSel();	

	int team = m_trans_list[index].m_signing_team;


	if(team > 0 && (sel == 0 || team == sel))
	{

//	m_id_list[m_row] = 0;
	
	int month = m_trans_list[index].m_month;
	int day = m_trans_list[index].m_day;
	int year = m_trans_list[index].m_year;
	int ty = m_trans_list[index].m_type;
	int yr = m_trans_list[index].m_signing_yr;
	int sa = m_trans_list[index].m_signing_sa;
	CString date;
	date.Format("%d/%d/%d", month, day, year);

	m_listTrades.InsertItem(m_row, (LPCTSTR)date);

	CString te = m_league_team_names[team-1];
	m_listTrades.SetItemText(m_row,1, (LPCTSTR)te);
	if(ty == 5)
		m_listTrades.SetItemText(m_row,2, (LPCTSTR)"extend");
	else if(ty == 6)
		m_listTrades.SetItemText(m_row,2, (LPCTSTR)"sign");
			

	int id = m_trans_list[index].m_signing_id;
//	m_id_list[m_row] = id;
	CString name = FindName(id);
	CString tmp;
	double mo = (double)sa / 100.;
	tmp.Format(" (%d year %.2f)", yr, mo); 
	m_listTrades.SetItemText(m_row,3, (LPCTSTR)name + tmp);
	m_row = m_row + 1;

	}
}



void CTransactionsDlg::OnDblclkListTrades(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	int i = m_listTrades.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (i >= 0)
	{
		int players_listed = m_listTrades.GetItemCount();
		int pointer = m_id_list[i];
		CPlayer m_player = avg.m_actual[pointer];
		int tm = m_player.m_team_index - 1;

		CString team = "";
		if (tm < 0) team = "";
		else team = m_league_team_names[tm];


		CPlayerCardDlg* scout = new CPlayerCardDlg;
		scout->m_default_scout = m_list_teams.GetCurSel();

		scout->m_path = avg.m_settings.m_path;
		scout->m_leagueName = avg.m_settings.m_league_name;

		scout->m_player_index = i;
		scout->m_title = "Scout";
		scout->avg = avg;

		for (int c = 0; c <= players_listed - 1; c++)
		{
			scout->avg.m_actual[c] = avg.m_actual[m_id_list[c]];
		}
		scout->m_player_index = i;
		scout->m_pl_index_end = players_listed - 1;
		scout->m_pl_index_start = 0;

		scout->DoModal();
		delete scout;


		*pResult = 0;
	}
}
