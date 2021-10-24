// CareerStatsCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "CareerStatsCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCareerStatsCardDlg dialog


CCareerStatsCardDlg::CCareerStatsCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCareerStatsCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCareerStatsCardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pl_index_start = 0;
	m_pl_index_end = 14;
	
	m_leagueName = "";
	m_path = "";
	for(int i=0; i<=1000; i++)
	{
		m_pointer[i] = 0;
		m_names_list[i] = "";
	}
	m_player_index = 0;


}


void CCareerStatsCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCareerStatsCardDlg)
	DDX_Control(pDX, IDC_LIST_POSITION, m_listPosition);
	DDX_Control(pDX, IDC_LIST_AWARDS, m_list_awards);
	DDX_Control(pDX, IDC_LIST_CTRL_STATS, m_listCtrl);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_button[0]);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_button[1]);
	DDX_Control(pDX, IDOK, m_button[2]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCareerStatsCardDlg, CDialog)
	//{{AFX_MSG_MAP(CCareerStatsCardDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CTRL_STATS, OnColumnclickListCtrlStats)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_STATS, &CCareerStatsCardDlg::OnLvnItemchangedListCtrlStats)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCareerStatsCardDlg message handlers

BOOL CCareerStatsCardDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CCareerStatsCardDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}

BOOL CCareerStatsCardDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR); 
	myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	InitListCtrl();
	Player();
	ListPlayerAwards();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CCareerStatsCardDlg::Player() 
{
	// TODO: Add your control notification handler code here
	CString name = m_names_list[m_player_index];	
	SetWindowText(name);

	m_listPosition.ShowWindow(TRUE);
	m_listPosition.ResetContent();

	int yrsPro = 0;
	CString buffer;
	CString pFileName = m_leagueName + ".car";
	CFile file(	pFileName, CFile::modeRead);	

	char s[17];
	int slot = m_pointer[m_player_index];


for(int y=0; y<=23; y++)
{
	long int seek = slot*2500 + 24 + y*100; 
	file.Seek( seek, CFile::begin);
	int bytes = file.Read(s, 4);
	s[bytes] = 0;
	int number = atoi(s);
	m_stats[y].SetRosterNumber(number);//set year

	bytes = file.Read(s, 16);
	s[bytes] = 0;
	m_stats[y].SetTeam(CString(s));//set team

	file.Seek( seek+40, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetGames(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetMin(number);
	if(number > 0) yrsPro = yrsPro + 1;

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFtm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFta(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTfgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTfga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetOreb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetReb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetAst(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetStl(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTo(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetBlk(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetPf(number);
}
	long int seek = slot*2500 + 26 + 24*100; 
	file.Seek( seek, CFile::begin);

	int bytes = file.Read(s, 1);
	s[bytes] = 0;
	int round = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int pos = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	int overall = atoi(s);


    file.Close();

	if(round > 0)
	{
		m_listPosition.AddString("Draft Selection");
		buffer.Format("Round: %d", round);
		m_listPosition.AddString(buffer);
		buffer.Format("Pick: %d", pos);
		m_listPosition.AddString(buffer);
		buffer.Format("Overall: %d", overall);
		m_listPosition.AddString(buffer);
		buffer.Format("Years Pro: %d", yrsPro);
		m_listPosition.AddString(buffer);
	}
	else
		m_listPosition.ShowWindow(FALSE);


	ListStats();

}



void CCareerStatsCardDlg::ListPlayerAwards()
{
	CString awards[512];

	CFile file(	m_leagueName + ".sal", CFile::modeReadWrite);	
	CString buffer;
	char s[33];

	int count = 0;
	int id = m_pointer[m_player_index];
 	
	int seek = 2000 + id*500 + 676; 	
	file.Seek( seek, CFile::begin);
 	int bytes = file.Read(s, 4);
	s[bytes] = 0; 
	int start_yr = atoi(s);

	CString place[6] = {"", "1st", "2nd", "3rd", "4th", "5th"};

	for(int y=0; y<=20; y++)
	{

		int mvp_seek = 2000 + id*500 + 680 + (y*15);
		file.Seek( mvp_seek, CFile::begin);
 		int bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int mvp = atoi(s);
		if(mvp > 0 && mvp <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d most valuable player (%s)", yr, place[mvp]);
//			string.Format("%d mvp  %d", yr, mvp);
			awards[count] = string;
			count = count + 1;
		}

		int defense_seek = 2000 + id*500 + 681 + (y*15);
		file.Seek( defense_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int defense = atoi(s);
		if(defense > 0 && defense <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d defensive player of the year  (%s)", yr, place[defense]);
//			string.Format("%d defense - %d", yr, defense);
			awards[count] = string;
			count = count + 1;
		}

		int rookie_seek = 2000 + id*500 + 682 + (y*15);
		file.Seek( rookie_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int rookie = atoi(s);
		if(rookie > 0 && rookie <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d rookie - %d", yr, rookie);
			string.Format("%d rookie of the year (%s)", yr, place[rookie]);
			awards[count] = string;
			count = count + 1;
		}

		int pts_seek = 2000 + id*500 + 683 + (y*15);
		file.Seek( pts_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int pts = atoi(s);
		if(pts > 0 && pts <= 5)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d scoring (%s)", yr, place[pts]);
//			string.Format("%d pts - %d", yr, pts);
			awards[count] = string;
			count = count + 1;
		}

		int reb_seek = 2000 + id*500 + 684 + (y*15);
		file.Seek( reb_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int reb = atoi(s);
		if(reb > 0 && reb <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d reb - %d", yr, reb);
			string.Format("%d rebounds (%s)", yr, place[reb]);
			awards[count] = string;
			count = count + 1;
		}

		int ast_seek = 2000 + id*500 + 685 + (y*15);
		file.Seek( ast_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ast = atoi(s);
		if(ast > 0 && ast <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d ast - %d", yr, ast);
			string.Format("%d assists (%s)", yr, place[ast]);
			awards[count] = string;
			count = count + 1;
		}

		int stl_seek = 2000 + id*500 + 686 + (y*15);
		file.Seek( stl_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int stl = atoi(s);
		if(stl > 0 && stl <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d stl - %d", yr, stl);
			string.Format("%d steals (%s)", yr, place[stl]);
			awards[count] = string;
			count = count + 1;
		}

		int blk_seek = 2000 + id*500 + 687 + (y*15);
		file.Seek( blk_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int blk = atoi(s);
		if(blk > 0 && blk <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d blk - %d", yr, blk);
			string.Format("%d blocks (%s)", yr, place[blk]);
			awards[count] = string;
			count = count + 1;
		}

		int ring_seek = 2000 + id*500 + 688 + (y*15);
		file.Seek( ring_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int ring = atoi(s);
		if(ring > 0)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d championship", yr);
//			string.Format("%d mvp (%s)", yr, place[mvp]);

			awards[count] = string;
			count = count + 1;
		}

		int po_mvp_seek = 2000 + id*500 + 689 + (y*15);
		file.Seek( po_mvp_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int po_mvp = atoi(s);
		if(po_mvp > 0 )
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d playoff mvp", yr);
			awards[count] = string;
			count = count + 1;
		}

		int sth_seek = 2000 + id*500 + 690 + (y*15);
		file.Seek( sth_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int sth = atoi(s);
		if(sth > 0 && sth <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d 6th - %d", yr, sth);
			string.Format("%d 6th man (%s)", yr, place[sth]);
			awards[count] = string;
			count = count + 1;
		}

		int seek = 2000 + id*500 + 691 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all league - %d", yr, all);
			string.Format("%d all league %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}

		seek = 2000 + id*500 + 692 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all defense - %d", yr, all);
			string.Format("%d all defense %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}

		seek = 2000 + id*500 + 693 + (y*15);
		file.Seek( seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		all = atoi(s);
		if(all > 0 && all <= 5)
		{
			CString string;
			int yr = start_yr + y;
//			string.Format("%d all rookie - %d", yr, all);
			string.Format("%d all rookie %s team", yr, place[all]);
			awards[count] = string;
			count = count + 1;
		}



	long int asw_seek = 2000 + id*500 + 694 + (y*15);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		int asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d all star mvp", yr);
			awards[count] = string;
			count = count + 1;
		}


		asw_seek = 2000 + id*500 + 995 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d rookie game mvp", yr);
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 996 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d three contest champ", yr);
			awards[count] = string;
			count = count + 1;
		}

		asw_seek = 2000 + id*500 + 997 + (y*3);
		file.Seek( asw_seek, CFile::begin);
 		bytes = file.Read(s, 1);
		s[bytes] = 0; 
		asw = atoi(s);
		if(asw == 1)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest", yr);
			awards[count] = string;
			count = count + 1;
		}
		else if(asw == 2)
		{
			CString string;
			int yr = start_yr + y;
			string.Format("%d dunk contest champ", yr);
			awards[count] = string;
			count = count + 1;
		}


	}

	m_list_awards.ResetContent();

	if(count > 0)
	{
	m_list_awards.ResetContent();
	for(int y=0; y<=(count-1); y++)
	{
		m_list_awards.AddString(awards[y]);
	}
	m_list_awards.SetCurSel(count-1);
	
	}
	else
	{
		m_list_awards.AddString("no awards");
	}
}

void CCareerStatsCardDlg::InitListCtrl()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


    m_listCtrl.InsertColumn(0,"Year");    
    m_listCtrl.InsertColumn(1,"Team");
	m_listCtrl.InsertColumn(2,"g");    
	m_listCtrl.InsertColumn(3,"min");    
	m_listCtrl.InsertColumn(4,"fgm");    
	m_listCtrl.InsertColumn(5,"fga");    
    m_listCtrl.InsertColumn(6,"fg%");
    m_listCtrl.InsertColumn(7,"ftm");
    m_listCtrl.InsertColumn(8,"fta");
    m_listCtrl.InsertColumn(9,"ft%");
    m_listCtrl.InsertColumn(10,"3gm");
    m_listCtrl.InsertColumn(11,"3ga");
    m_listCtrl.InsertColumn(12,"3g%");
    m_listCtrl.InsertColumn(13,"orb");
    m_listCtrl.InsertColumn(14,"reb");
    m_listCtrl.InsertColumn(15,"ast");
    m_listCtrl.InsertColumn(16,"stl");
    m_listCtrl.InsertColumn(17,"to");
    m_listCtrl.InsertColumn(18,"blk");
    m_listCtrl.InsertColumn(19,"pf");
    m_listCtrl.InsertColumn(20,"ppg");
  
	  
	float scale = 1.5;
    m_listCtrl.SetColumnWidth( 0, 45 * scale );
    m_listCtrl.SetColumnWidth( 1, 68 * scale );
    m_listCtrl.SetColumnWidth( 2, 30 * scale );
    m_listCtrl.SetColumnWidth( 3, 31 * scale );
    m_listCtrl.SetColumnWidth( 4, 31 * scale );
    m_listCtrl.SetColumnWidth( 5, 31 * scale );
    m_listCtrl.SetColumnWidth( 6, 31 * scale );
    m_listCtrl.SetColumnWidth( 7, 31 * scale );
    m_listCtrl.SetColumnWidth( 8, 31 * scale );
    m_listCtrl.SetColumnWidth( 9, 31 * scale );
    m_listCtrl.SetColumnWidth( 10, 30 * scale );
    m_listCtrl.SetColumnWidth( 11, 31 * scale );
    m_listCtrl.SetColumnWidth( 12, 33 * scale );
    m_listCtrl.SetColumnWidth( 13, 27 * scale );
    m_listCtrl.SetColumnWidth( 14, 31 * scale );
    m_listCtrl.SetColumnWidth( 15, 30 * scale );
    m_listCtrl.SetColumnWidth( 16, 25 * scale );
    m_listCtrl.SetColumnWidth( 17, 26 * scale );
    m_listCtrl.SetColumnWidth( 18, 25 * scale );
    m_listCtrl.SetColumnWidth( 19, 25 * scale );
    m_listCtrl.SetColumnWidth( 20, 31 * scale );
    m_listCtrl.SetTextColor(RGB(0,0,0));
    m_listCtrl.SetTextBkColor(TEXT_BK_COLOR);
    m_listCtrl.SetBkColor(BK_COLOR);
//    m_listCtrlShot.SetTextColor(RGB(0,0,0));

	m_listCtrl.SetFont(&m_font);

}

void CCareerStatsCardDlg::OnButtonBack() 
{
	// TODO: Add your control notification handler code here
		m_player_index = m_player_index - 1;
		//if(m_player_index < 1) m_player_index = 1440;
		if(m_player_index < m_pl_index_start) m_player_index = m_pl_index_end;


	
	Player();
	ListPlayerAwards();	
	
}

void CCareerStatsCardDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
		m_player_index = m_player_index + 1;
		//if(m_player_index > 1440) m_player_index = 1;
		if(m_player_index > m_pl_index_end) m_player_index = m_pl_index_start;

		Player();
		ListPlayerAwards();
	
}

void CCareerStatsCardDlg::ListStats()
{
	m_listCtrl.DeleteAllItems();
	int g=0, min=0, fgm=0, fga=0, ftm=0, fta=0, tgm=0, tga=0, orb=0, reb=0, ast=0, stl=0, to=0, blk=0, pf=0;
	int yearsPro = 0; 
	for(int i=0; i<=24; i++)
	{
		if(m_stats[i].GetGames() == 0 && i != 24) continue;
		int s1 = m_stats[i].GetGames();
		int s2 = m_stats[i].GetMin();
		int s3 = m_stats[i].GetFgm() + m_stats[i].GetTfgm();
		int s4 = m_stats[i].GetFga() + m_stats[i].GetTfga();
		int s5 = m_stats[i].GetFtm();
		int s6 = m_stats[i].GetFta();
		int s7 = m_stats[i].GetTfgm();
		int s8 = m_stats[i].GetTfga();
		int s9 = m_stats[i].GetOreb();
		int s10 =m_stats[i].GetReb() + s9;
		int s11 =m_stats[i].GetAst();
		int s12 =m_stats[i].GetStl();
		int s13 =m_stats[i].GetTo();
		int s14 =m_stats[i].GetBlk();
		int s15 =m_stats[i].GetPf();


		g = g + s1;
		if(g == 0) continue;
		min = min + s2;
		fgm = fgm + s3;
		fga = fga + s4;
		ftm = ftm + s5;
		fta = fta + s6;
		tgm = tgm + s7;
		tga = tga + s8;
		orb = orb + s9;
		reb = reb + s10;
		ast = ast + s11;
		stl = stl + s12;
		to =  to + s13;
		blk = blk + s14;
		pf = pf + s15;
		if(i == 24)
		{
			s1 = g; s2 = min; s3 = fgm; s4 = fga; s5 = ftm;
			s6 = fta; s7 = tgm; s8 = tga; s9 = orb; s10 = reb;
			s11 = ast; s12 = stl; s13 = to; s14 = blk; s15 = pf;
		}
		CString string;
		if(i != 24)
			string.Format("%d", m_stats[i].GetRosterNumber());
		else 
			string = "------";
		
	    m_listCtrl.InsertItem(yearsPro, string);
	    m_listCtrl.SetItemText(yearsPro,1,m_stats[i].GetTeam());

	    string.Format("%d", s1);
	    m_listCtrl.SetItemText(yearsPro,2,string);
			
	    string.Format("%.1f", double(s2) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,3,string);
			
	    string.Format("%.1f", double(s3) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,4,string);
			
	    string.Format("%.1f", double(s4) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,5,string);
			
		if(s4 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s3)/double(s1))/ (double(s4) / double(s1)) *100);
	    m_listCtrl.SetItemText(yearsPro,6,string);
			
	    string.Format("%.1f", double(s5) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,7,string);
			
	    string.Format("%.1f", double(s6) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,8,string);
		
		if(s6 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s5)/double(s1))/ (double(s6) / double(s1)) *100);
	    m_listCtrl.SetItemText(yearsPro,9,string);

			
	    string.Format("%.1f", double(s7) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,10,string);
			
	    string.Format("%.1f", double(s8) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,11,string);
			
		if(s8 == 0)
			string = "-----";
		else
	    string.Format("%.1f", (double(s7)/double(s1))/ (double(s8) / double(s1)) *100);
	    
		m_listCtrl.SetItemText(yearsPro,12,string);

	    string.Format("%.1f", double(s9) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,13,string);
			
	    string.Format("%.1f", double(s10) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,14,string);
			
	    string.Format("%.1f", double(s11) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,15,string);
			
	    string.Format("%.1f", double(s12) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,16,string);
			
	    string.Format("%.1f", double(s13) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,17,string);
			
	    string.Format("%.1f", double(s14) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,18,string);
			
	    string.Format("%.1f", double(s15) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,19,string);

	    string.Format("%.1f", double(s3*2+s5+s7) / double(s1) );
	    m_listCtrl.SetItemText(yearsPro,20,string);

		yearsPro = yearsPro + 1;
			
	}

	int items = m_listCtrl.GetItemCount() - 1;
	if(items >= 0)
	{
	m_listCtrl.SetItemState(items, LVIS_SELECTED,LVIS_SELECTED);
	m_listCtrl.SetItemState(items, LVIS_FOCUSED,LVIS_FOCUSED);
	m_listCtrl.EnsureVisible(items, TRUE);
	}


}

void CCareerStatsCardDlg::OnColumnclickListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	int index = m_listCtrl.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	int m_column = pNMListView->iSubItem;


CPlayer m_player_i, m_player_j;




for(int i=0; i<=23; i++)
{
for(int j=0; j<=23; j++)
{


bool swap = false;

m_player_i = m_stats[i];
m_player_j = m_stats[j];

		double s1_i = (double) m_stats[i].GetGames();
		double s1_j = (double) m_stats[j].GetGames();
		if(s1_i == 0 || s1_j == 0) continue;
		double s2_i = (double) m_stats[i].GetMin() / s1_i;
		double s3_i = ((double) m_stats[i].GetFgm() + (double) m_stats[i].GetTfgm()) / s1_i;
		double s4_i = ((double) m_stats[i].GetFga() + (double) m_stats[i].GetTfga()) / s1_i;
		double s5_i = (double) m_stats[i].GetFtm() / s1_i;
		double s6_i = (double) m_stats[i].GetFta() / s1_i;
		double s7_i = (double) m_stats[i].GetTfgm() / s1_i;
		double s8_i = (double) m_stats[i].GetTfga() / s1_i;
		double s9_i = (double) m_stats[i].GetOreb() / s1_i;
		double s10_i =((double) m_stats[i].GetReb() + (double) m_stats[i].GetOreb()) / s1_i;
		double s11_i =(double) m_stats[i].GetAst() / s1_i;
		double s12_i =(double) m_stats[i].GetStl() / s1_i;
		double s13_i =(double) m_stats[i].GetTo() / s1_i;
		double s14_i =(double) m_stats[i].GetBlk() / s1_i;
		double s15_i =(double) m_stats[i].GetPf() / s1_i;

		double p1_i = s3_i / s4_i;
		double p2_i = s5_i / s6_i;
		double p3_i = s7_i / s8_i;
		double pt_i = (s3_i*2+s5_i+s7_i) ;

		double s2_j = (double) m_stats[j].GetMin() / s1_j;
		double s3_j = ((double) m_stats[j].GetFgm() + (double) m_stats[j].GetTfgm()) / s1_j;
		double s4_j = ((double) m_stats[j].GetFga() + (double) m_stats[j].GetTfga()) / s1_j;
		double s5_j = (double) m_stats[j].GetFtm() / s1_j;
		double s6_j = (double) m_stats[j].GetFta() / s1_j;
		double s7_j = (double) m_stats[j].GetTfgm() / s1_j;
		double s8_j = (double) m_stats[j].GetTfga() / s1_j;
		double s9_j = (double) m_stats[j].GetOreb() / s1_j;
		double s10_j =((double) m_stats[j].GetReb() + (double) m_stats[j].GetOreb()) / s1_j;
		double s11_j =(double) m_stats[j].GetAst() / s1_j;
		double s12_j =(double) m_stats[j].GetStl() / s1_j;
		double s13_j =(double) m_stats[j].GetTo() / s1_j;
		double s14_j =(double) m_stats[j].GetBlk() / s1_j;
		double s15_j =(double) m_stats[j].GetPf() / s1_j;

		double p1_j = s3_j / s4_j;
		double p2_j = s5_j / s6_j;
		double p3_j = s7_j / s8_j;
		double pt_j = (s3_j*2+s5_j+s7_j) ;



switch(m_column) 
{

    case 0:
		swap = m_player_i.GetRosterNumber() < m_player_j.GetRosterNumber();
        break;
    case 1:
		swap = m_player_i.m_team < m_player_j.m_team;
        break;
    case 2:        
		swap = s1_i > s1_j;
        break;
    case 3:
		swap = s2_i > s2_j;
        break;
    case 4:
		swap = s3_i > s3_j;
        break;
    case 5:
		swap = s4_i > s4_j;
        break;
    case 6:
		swap = p1_i > p1_j;
        break;
    case 7:
		swap = s5_i > s5_j;
        break;
    case 8:
		swap = s6_i > s6_j;
        break;
    case 9:
		swap = p2_i > p2_j;
        break;
    case 10:
		swap = s7_i > s7_j;
        break;
    case 11:
		swap = s8_i > s8_j;
        break;
    case 12:
		swap = p3_i > p3_j;
        break;
    case 13:
		swap = s9_i > s9_j;
        break;
    case 14:
		swap = s10_i > s10_j;
        break;
    case 15:
		swap = s11_i > s11_j;
        break;
    case 16:
		swap = s12_i > s12_j;
        break;
    case 17:
		swap = s13_i > s13_j;
        break;
    case 18:
		swap = s14_i > s14_j;
        break;
    case 19:
		swap = s15_i > s15_j;
        break;
    case 20:
		swap = pt_i > pt_j;
        break;


}

	if(swap == true)
	{//swap
		CPlayer temp = m_stats[i];
		m_stats[i] = m_stats[j];
		m_stats[j] = temp;
	}


}

}

	ListStats();
	int items = 0;
	m_listCtrl.SetItemState(items, LVIS_SELECTED,LVIS_SELECTED);
	m_listCtrl.SetItemState(items, LVIS_FOCUSED,LVIS_FOCUSED);
	m_listCtrl.EnsureVisible(items, TRUE);
	*pResult = 0;











}

HBRUSH CCareerStatsCardDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
 //         pDC->SetBkColor(LISTBOXCOLOR);
  //        pDC->SetTextColor(LISTBOXTEXTCOLOR);
   //       return myBrush;

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
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}


void CCareerStatsCardDlg::OnLvnItemchangedListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
