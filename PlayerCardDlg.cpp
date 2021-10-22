// PlayerCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "PlayerCardDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerCardDlg dialog


CPlayerCardDlg::CPlayerCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayerCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayerCardDlg)
	m_edit_owner = _T("");
	//}}AFX_DATA_INIT
	m_extension_allowed = false;
	m_pl_index_start = 1;
	m_pl_index_end = 1440;
	m_default_scout = 0;
	m_data_slot = 0;

}


CPlayerCardDlg::~CPlayerCardDlg(void)
{

}


void CPlayerCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayerCardDlg)
	DDX_Control(pDX, IDC_BUTTON_EXTEND, m_button_extend);
	DDX_Control(pDX, IDC_LIST_HIGHS, m_list_highs);
	DDX_Control(pDX, IDC_LIST6, m_list_ctrl_3);
	DDX_Control(pDX, IDC_LIST5, m_list_ctrl_2);
	DDX_Control(pDX, IDC_LIST4, m_list_ctrl_1);
	DDX_Control(pDX, IDC_BUTTON_SCOUT, m_buttonScout);
	DDX_Control(pDX, IDC_LIST_CTRL, m_listctrlskill);
	DDX_Control(pDX, IDC_LIST_FUTURE2, m_listFuture);
	DDX_Control(pDX, IDC_LIST_CTRL_STATS2, m_listCtrlStats);
	DDX_Control(pDX, IDC_LIST_CTRL_SHOT2, m_listCtrlShot);
	DDX_Control(pDX, IDC_LIST_REPORT2, m_list_report);
	DDX_Control(pDX, IDC_LIST_CTRL_SEASON_STATS, m_listctrlstats);
	DDX_Control(pDX, IDC_LIST_POSITION, m_listPosition);
	DDX_Control(pDX, IDC_LIST_CTRL_STATS, m_listCtrl);
	DDX_Control(pDX, IDC_LIST_AWARDS, m_list_awards);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_edit_owner);
	DDV_MaxChars(pDX, m_edit_owner, 64);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MFCBUTTON1, m_buttonPng);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_button[0]);
	DDX_Control(pDX, IDC_BUTTON_FORWARD, m_button[1]);
	DDX_Control(pDX, IDOK, m_button[2]);
}


BEGIN_MESSAGE_MAP(CPlayerCardDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayerCardDlg)
	//ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CTRL_STATS, OnColumnclickListCtrlStats)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_FORWARD, OnButtonForward)
	ON_BN_CLICKED(IDC_BUTTON_SCOUT, OnButtonScout)
	ON_BN_CLICKED(IDC_BUTTON_EXTEND, OnButtonExtend)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerCardDlg message handlers

BOOL CPlayerCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	myBrush.CreateSolidBrush(DLGCOLOR);
	myBrush2.CreateSolidBrush(LISTBOXCOLOR);
	//_mkdir(avg.m_settings.m_path + "Pictures");


	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 16;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	LOGFONT lf2;                        // Used to create the CFont.
	memset(&lf2, 0, sizeof(LOGFONT));   // Clear out structure.
	lf2.lfWeight = 100;
	lf2.lfHeight = 12;
	strcpy_s(lf2.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font2.CreateFontIndirect(&lf2);    // Create the font.

	m_pointer = avg.m_actual[m_player_index].m_id;


	CPlayer m_player = avg.m_actual[m_player_index];



	if (m_default_scout < 0) m_default_scout = 0;


	int leadScout = -1;
	for (int i = 0; i <= 31; i++)
	{
		if (avg.m_settings.m_scouts[i] == 1)
		{
			leadScout = i;
		}
	}

	int index = 0;
	if (leadScout >= 0)
		index = leadScout;
	else
		index = avg.m_actual[m_player_index].m_current_team;

	if (index < 0) index = m_default_scout;

	if (avg.m_settings.m_scouts[32] == 1)
	{
		CStaff m_avgStaff;
		m_avgStaff.InitVariables();
		m_scout = m_avgStaff;
	}
	else if (m_title == "Coach")
		m_scout = avg.m_coach[index];
	else if (m_title == "GM")
		m_scout = avg.m_gm[index];
	else  if (m_title == "Scout")
		m_scout = avg.m_scout[index];



	InitListCtrl();
	Player();
	ListPlayerAwards();



	//	GetCurrentID();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPlayerCardDlg::Player()
{
	// TODO: Add your control notification handler code here



	CString na = avg.m_actual[m_player_index].GetName();
	na.MakeLower();
	na.Replace("jr. ", "");
	na.Remove('.');
	na.Replace(_T("-"), _T(" "));



	CString test1 = avg.m_settings.m_path + "Pictures\\" + na + ".png";
	test1.MakeLower();
	CString test2 = avg.m_settings.m_path + "Pictures\\" + na +  " Jr" + ".png";
	test2.MakeLower();

	CString img = test1;
	img.MakeLower();


	//bool jr = (img.Right(3) == "Jr.");//if file name has Jr. at end
	//if (jr) na = na + " Jr.";//then add to player name

	bool exists = false;
	CFileStatus status1;
	//CFileStatus status2;
	if (CFile::GetStatus(test1, status1))
	{
		exists = true;
		img = test1;
	}
	else if (CFile::GetStatus(test2, status1))
	{
		exists = true;
		img = test2;
	}
	//img = test2;
	//exists = true;
	CPngImage pngImage;
	CBitmap bmp;
	if (exists == true)
	{
		pngImage.Load(img);
		bmp.Attach(pngImage.Detach());
		CImage png;
		png.Load(img);
		m_buttonPng.SetImage(png);
	}
	else
	{
		m_buttonPng.SetImage(IDB_BITMAP);
	}
	m_buttonPng.SetFaceColor(BLACK);


	CString team;
	int ind = avg.m_actual[m_player_index].m_current_team;
	if (ind >= 0) team = avg.m_settings.m_leagueTeamNames[ind];
	CString name = avg.m_actual[m_player_index].m_pos + " " + avg.m_actual[m_player_index].m_name + " - " + team;
	SetWindowText(name);
	m_listPosition.ShowWindow(TRUE);

	int yrsPro = 0;
	CString buffer;
	CString pFileName = m_path + m_leagueName + ".car";


	exists = true;
	CFileStatus status;
	if (CFile::GetStatus(pFileName, status) == 0) exists = false;




	if (exists == true)
	{



		CFile file(pFileName, CFile::modeRead);


		char s[17];
		//int index = m_listPlayers.GetCurSel();
		//int slot = m_player.GetID();
		//if(m_useCPlayer == false) slot = m_pointer;
		int slot = m_pointer;


		for (int y = 0; y <= 23; y++)
		{
			long int seek = slot * 2500 + 24 + y * 100;
			file.Seek(seek, CFile::begin);
			int bytes = file.Read(s, 4);
			s[bytes] = 0;
			int number = atoi(s);
			m_stats[y].SetRosterNumber(number);//set year

			bytes = file.Read(s, 16);
			s[bytes] = 0;
			m_stats[y].SetTeam(CString(s));//set team

			file.Seek(seek + 40, CFile::begin);
			bytes = file.Read(s, 2);
			s[bytes] = 0;
			number = atoi(s);
			m_stats[y].SetGames(number);

			bytes = file.Read(s, 4);
			s[bytes] = 0;
			number = atoi(s);
			m_stats[y].SetMin(number);
			if (number > 0) yrsPro = yrsPro + 1;

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
		//	long int seek = slot*2500 + 26 + 24*100; 
		//	file.Seek( seek, CFile::begin);

		//	int bytes = file.Read(s, 1);
		//	s[bytes] = 0;
		//	int round = atoi(s);

		//	bytes = file.Read(s, 2);
		//	s[bytes] = 0;
		//	int pos = atoi(s);
		//
		//	bytes = file.Read(s, 2);
		//	s[bytes] = 0;
		//	int overall = atoi(s);
		CPlayer m_player = avg.m_actual[m_player_index];

		int round = m_player.m_round_selected;
		int pos = m_player.m_pick_selected;

		file.Close();

		m_listPosition.ResetContent();


		if (round > 0)
		{
			m_listPosition.AddString("Draft Selection");
			buffer.Format("Round: %d", round);
			m_listPosition.AddString(buffer);
			buffer.Format("Pick: %d", pos);
			m_listPosition.AddString(buffer);
			//		buffer.Format("Overall: %d", overall);
			//		m_listPosition.AddString(buffer);
			buffer.Format("Years Pro: %d", yrsPro);
			m_listPosition.AddString(buffer);
		}
		else
			m_listPosition.ShowWindow(FALSE);

	}

	ListStats();
	ListHighs();
	ListSeasonStats();
	DisplayRating();

}

void CPlayerCardDlg::InitListCtrl()
{
	/*    LOGFONT lf;                        // Used to create the CFont.
		memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
		lf.lfWeight = 100;
		lf.lfHeight = 12;
		strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
		m_font.CreateFontIndirect(&lf);    // Create the font.*/



	m_listPosition.SetFont(&m_font);
	m_list_awards.SetFont(&m_font);




	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_listCtrl.DeleteAllItems();

	m_listCtrl.InsertColumn(0, "Year");
	m_listCtrl.InsertColumn(1, "Team");
	m_listCtrl.InsertColumn(2, "g");
	m_listCtrl.InsertColumn(3, "min");
	m_listCtrl.InsertColumn(4, "fgm");
	m_listCtrl.InsertColumn(5, "fga");
	m_listCtrl.InsertColumn(6, "fg%");
	m_listCtrl.InsertColumn(7, "ftm");
	m_listCtrl.InsertColumn(8, "fta");
	m_listCtrl.InsertColumn(9, "ft%");
	m_listCtrl.InsertColumn(10, "3gm");
	m_listCtrl.InsertColumn(11, "3ga");
	m_listCtrl.InsertColumn(12, "3g%");
	m_listCtrl.InsertColumn(13, "orb");
	m_listCtrl.InsertColumn(14, "reb");
	m_listCtrl.InsertColumn(15, "ast");
	m_listCtrl.InsertColumn(16, "stl");
	m_listCtrl.InsertColumn(17, "to");
	m_listCtrl.InsertColumn(18, "blk");
	m_listCtrl.InsertColumn(19, "pf");
	m_listCtrl.InsertColumn(20, "ppg");


	//double scale = 1.5;
	m_listCtrl.SetColumnWidth(0, 51);
	m_listCtrl.SetColumnWidth(1, 62);
	m_listCtrl.SetColumnWidth(2, 46);
	m_listCtrl.SetColumnWidth(3, 46);
	m_listCtrl.SetColumnWidth(4, 46);
	m_listCtrl.SetColumnWidth(5, 46);
	m_listCtrl.SetColumnWidth(6, 46);
	m_listCtrl.SetColumnWidth(7, 46);
	m_listCtrl.SetColumnWidth(8, 46);
	m_listCtrl.SetColumnWidth(9, 46);
	m_listCtrl.SetColumnWidth(10, 46);
	m_listCtrl.SetColumnWidth(11, 46);
	m_listCtrl.SetColumnWidth(12, 49);
	m_listCtrl.SetColumnWidth(13, 42);
	m_listCtrl.SetColumnWidth(14, 46);
	m_listCtrl.SetColumnWidth(15, 46);
	m_listCtrl.SetColumnWidth(16, 37);
	m_listCtrl.SetColumnWidth(17, 40);
	m_listCtrl.SetColumnWidth(18, 39);
	m_listCtrl.SetColumnWidth(19, 37);
	m_listCtrl.SetColumnWidth(20, 46);
	m_listCtrl.SetTextColor(RGB(0, 0, 0));
	m_listCtrl.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrl.SetBkColor(BK_COLOR);
	//    m_listCtrlShot.SetTextColor(RGB(0,0,0));

	m_listCtrl.SetFont(&m_font2);



	//m_list_highs.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_highs.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_highs.InsertColumn(0, "cat");
	m_list_highs.InsertColumn(1, "season");
	m_list_highs.InsertColumn(2, "playoff");
	m_list_highs.InsertColumn(3, "season");
	m_list_highs.InsertColumn(4, "playoff");

	m_list_highs.SetColumnWidth(0, 75);
	m_list_highs.SetColumnWidth(1, 75);
	m_list_highs.SetColumnWidth(2, 75);
	m_list_highs.SetColumnWidth(3, 75);
	m_list_highs.SetColumnWidth(4, 75);
	m_list_highs.SetTextColor(RGB(0, 0, 0));
	m_list_highs.SetTextBkColor(TEXT_BK_COLOR);
	m_list_highs.SetBkColor(BK_COLOR);
	m_list_highs.SetFont(&m_font);


	m_listctrlstats.SetExtendedStyle(LVS_EX_FULLROWSELECT);


	//  m_listctrlstats.InsertColumn(0,"Year");    
	m_listctrlstats.InsertColumn(0, "Team");
	m_listctrlstats.InsertColumn(1, "g");
	m_listctrlstats.InsertColumn(2, "gs");
	m_listctrlstats.InsertColumn(3, "min");
	m_listctrlstats.InsertColumn(4, "fgm");
	m_listctrlstats.InsertColumn(5, "fga");
	m_listctrlstats.InsertColumn(6, "fg%");
	m_listctrlstats.InsertColumn(7, "ftm");
	m_listctrlstats.InsertColumn(8, "fta");
	m_listctrlstats.InsertColumn(9, "ft%");
	m_listctrlstats.InsertColumn(10, "3gm");
	m_listctrlstats.InsertColumn(11, "3ga");
	m_listctrlstats.InsertColumn(12, "3g%");
	m_listctrlstats.InsertColumn(13, "orb");
	m_listctrlstats.InsertColumn(14, "reb");
	m_listctrlstats.InsertColumn(15, "ast");
	m_listctrlstats.InsertColumn(16, "stl");
	m_listctrlstats.InsertColumn(17, "to");
	m_listctrlstats.InsertColumn(18, "blk");
	m_listctrlstats.InsertColumn(19, "pf");
	m_listctrlstats.InsertColumn(20, "ppg");



	m_listctrlstats.SetColumnWidth(0, 1);
	//    m_listctrlstats.SetColumnWidth( 1, 40  );
	m_listctrlstats.SetColumnWidth(1, 33 );
	m_listctrlstats.SetColumnWidth(2, 33 );
	m_listctrlstats.SetColumnWidth(3, 45 );
	m_listctrlstats.SetColumnWidth(4, 45 );
	m_listctrlstats.SetColumnWidth(5, 45 );
	m_listctrlstats.SetColumnWidth(6, 45 );
	m_listctrlstats.SetColumnWidth(7, 45 );
	m_listctrlstats.SetColumnWidth(8, 45 );
	m_listctrlstats.SetColumnWidth(9, 45 );
	m_listctrlstats.SetColumnWidth(10, 45 );
	m_listctrlstats.SetColumnWidth(11, 45 );
	m_listctrlstats.SetColumnWidth(12, 48 );
	m_listctrlstats.SetColumnWidth(13, 40 );
	m_listctrlstats.SetColumnWidth(14, 45 );
	m_listctrlstats.SetColumnWidth(15, 45 );
	m_listctrlstats.SetColumnWidth(16, 37 );
	m_listctrlstats.SetColumnWidth(17, 37 );
	m_listctrlstats.SetColumnWidth(18, 39 );
	m_listctrlstats.SetColumnWidth(19, 37 );
	m_listctrlstats.SetColumnWidth(20, 46 );
	m_listctrlstats.SetTextColor(RGB(0, 0, 0));
	m_listctrlstats.SetTextBkColor(TEXT_BK_COLOR);
	m_listctrlstats.SetBkColor(BK_COLOR);

	m_listctrlstats.SetFont(&m_font2);



	m_listCtrlStats.SetFont(&m_font);
	m_listCtrlShot.SetFont(&m_font);
	m_listctrlskill.SetFont(&m_font);
	m_listFuture.SetFont(&m_font);

	m_listCtrlStats.InsertColumn(0, "Pos");
	m_listCtrlStats.InsertColumn(1, "Player");
	m_listCtrlStats.InsertColumn(2, "Ht");
	m_listCtrlStats.InsertColumn(3, "Wt");
	m_listCtrlStats.InsertColumn(4, "Age");
	m_listCtrlStats.InsertColumn(5, "Offense");
	m_listCtrlStats.InsertColumn(6, "O");
	m_listCtrlStats.InsertColumn(7, "D");
	m_listCtrlStats.InsertColumn(8, "P");
	m_listCtrlStats.InsertColumn(9, "T");
	m_listCtrlStats.InsertColumn(10, "Defense");
	m_listCtrlStats.InsertColumn(11, "O");
	m_listCtrlStats.InsertColumn(12, "D");
	m_listCtrlStats.InsertColumn(13, "P");
	m_listCtrlStats.InsertColumn(14, "T");


	m_listCtrlStats.SetColumnWidth(0, 48 );
	m_listCtrlStats.SetColumnWidth(1, 192 );
	m_listCtrlStats.SetColumnWidth(2, 60 );
	m_listCtrlStats.SetColumnWidth(3, 49 );
	m_listCtrlStats.SetColumnWidth(4, 49 );
	m_listCtrlStats.SetColumnWidth(5, 81 );
	m_listCtrlStats.SetColumnWidth(6, 30 );
	m_listCtrlStats.SetColumnWidth(7, 30 );
	m_listCtrlStats.SetColumnWidth(8, 30 );
	m_listCtrlStats.SetColumnWidth(9, 30 );
	m_listCtrlStats.SetColumnWidth(10, 82 );
	m_listCtrlStats.SetColumnWidth(11, 30 );
	m_listCtrlStats.SetColumnWidth(12, 30 );
	m_listCtrlStats.SetColumnWidth(13, 30 );
	m_listCtrlStats.SetColumnWidth(14, 30 );
	m_listCtrlStats.SetBkColor(BK_COLOR);
	m_listCtrlStats.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlStats.SetTextColor(RGB(0, 0, 0));

	m_listCtrlShot.InsertColumn(0, "2ga");
	m_listCtrlShot.InsertColumn(1, "2g%");
	m_listCtrlShot.InsertColumn(2, "fta");
	m_listCtrlShot.InsertColumn(3, "ft%");
	m_listCtrlShot.InsertColumn(4, "3ga");
	m_listCtrlShot.InsertColumn(5, "3g%");
	m_listctrlskill.InsertColumn(0, "oreb");
	m_listctrlskill.InsertColumn(1, "dreb");
	m_listctrlskill.InsertColumn(2, "ast");
	m_listctrlskill.InsertColumn(3, "stl");
	m_listctrlskill.InsertColumn(4, "to");
	m_listctrlskill.InsertColumn(5, "blk");


	m_listCtrlShot.SetColumnWidth(0, 60 );
	m_listCtrlShot.SetColumnWidth(1, 60 );
	m_listCtrlShot.SetColumnWidth(2, 60 );
	m_listCtrlShot.SetColumnWidth(3, 58 );
	m_listCtrlShot.SetColumnWidth(4, 58 );
	m_listCtrlShot.SetColumnWidth(5, 58 );
	m_listctrlskill.SetColumnWidth(0, 60 );
	m_listctrlskill.SetColumnWidth(1, 60 );
	m_listctrlskill.SetColumnWidth(2, 60 );
	m_listctrlskill.SetColumnWidth(3, 58 );
	m_listctrlskill.SetColumnWidth(4, 58 );
	m_listctrlskill.SetColumnWidth(5, 58 );

	m_listFuture.InsertColumn(0, "Talent");
	m_listFuture.InsertColumn(1, "Skill");
	m_listFuture.InsertColumn(2, "Intangibles");
	m_listFuture.SetColumnWidth(0, 103 );
	m_listFuture.SetColumnWidth(1, 103 );
	m_listFuture.SetColumnWidth(2, 103 );

	m_listctrlskill.SetBkColor(BK_COLOR);
	m_listctrlskill.SetTextBkColor(TEXT_BK_COLOR);
	m_listctrlskill.SetTextColor(RGB(0, 0, 0));
	m_listCtrlShot.SetBkColor(BK_COLOR);
	m_listCtrlShot.SetTextBkColor(TEXT_BK_COLOR);
	m_listCtrlShot.SetTextColor(RGB(0, 0, 0));
	m_listFuture.SetTextBkColor(TEXT_BK_COLOR);
	m_listFuture.SetBkColor(BK_COLOR);
	m_listFuture.SetTextColor(RGB(0, 0, 0));


	m_list_ctrl_1.SetBkColor(BK_COLOR);
	m_list_ctrl_1.SetTextBkColor(TEXT_BK_COLOR);

	m_list_ctrl_1.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_ctrl_1.SetTextColor(RGB(0, 0, 0));
	m_list_ctrl_1.SetFont(&m_font);
	m_list_ctrl_1.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_ctrl_2.SetBkColor(BK_COLOR);
	m_list_ctrl_2.SetTextBkColor(TEXT_BK_COLOR);

	m_list_ctrl_2.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_ctrl_2.SetTextColor(RGB(0, 0, 0));
	m_list_ctrl_2.SetFont(&m_font);
	m_list_ctrl_2.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_ctrl_3.SetBkColor(BK_COLOR);
	m_list_ctrl_3.SetTextBkColor(TEXT_BK_COLOR);

	m_list_ctrl_3.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_list_ctrl_3.SetTextColor(RGB(0, 0, 0));
	m_list_ctrl_3.SetFont(&m_font);
	m_list_ctrl_3.SetExtendedStyle(LVS_EX_FULLROWSELECT);


	m_label[0] = "free agent";
	m_label[1] = "years";
	m_label[2] = "Bird years";
	m_label[3] = "Bird rights";

	m_label[4] = "loyalty";
	m_label[5] = "winner";
	m_label[6] = "play time";
	m_label[7] = "security";
	m_label[8] = "coach";
	m_label[9] = "tradition";

	m_label[10] = "happiness";
	m_label[11] = "health";

	m_label[21] = "year 1";
	m_label[22] = "year 2";
	m_label[23] = "year 3";
	m_label[24] = "year 4";
	m_label[25] = "year 5";
	m_label[26] = "year 6";

	m_list_ctrl_1.DeleteAllItems();
	m_list_ctrl_1.InsertColumn(0, "factor");
	m_list_ctrl_1.InsertColumn(1, "importance");
	m_list_ctrl_1.SetColumnWidth(0, 112);
	m_list_ctrl_1.SetColumnWidth(1, 112);

	m_list_ctrl_2.DeleteAllItems();
	m_list_ctrl_2.InsertColumn(0, "");
	m_list_ctrl_2.InsertColumn(1, "salary");
	m_list_ctrl_2.SetColumnWidth(0, 126);
	m_list_ctrl_2.SetColumnWidth(1, 126);

	m_list_ctrl_3.DeleteAllItems();
	m_list_ctrl_3.InsertColumn(0, "");
	m_list_ctrl_3.InsertColumn(1, "status");
	m_list_ctrl_3.SetColumnWidth(0, 112);
	m_list_ctrl_3.SetColumnWidth(1, 112);




}

void CPlayerCardDlg::ListStats()
{
	m_listCtrl.DeleteAllItems();
	m_list_ctrl_3.DeleteAllItems();
	m_list_ctrl_2.DeleteAllItems();
	m_list_ctrl_1.DeleteAllItems();
	m_listctrlskill.DeleteAllItems();
	m_listFuture.DeleteAllItems();
	m_listCtrlStats.DeleteAllItems();
	m_listCtrlShot.DeleteAllItems();
	m_listctrlstats.DeleteAllItems();
	m_listCtrl.DeleteAllItems();






	int g = 0, min = 0, fgm = 0, fga = 0, ftm = 0, fta = 0, tgm = 0, tga = 0, orb = 0, reb = 0, ast = 0, stl = 0, to = 0, blk = 0, pf = 0;
	int yearsPro = 0;
	for (int i = 0; i <= 24; i++)
	{
		if (m_stats[i].GetGames() == 0 && i != 24) continue;
		int s1 = m_stats[i].GetGames();
		int s2 = m_stats[i].GetMin();
		int s3 = m_stats[i].GetFgm() + m_stats[i].GetTfgm();
		int s4 = m_stats[i].GetFga() + m_stats[i].GetTfga();
		int s5 = m_stats[i].GetFtm();
		int s6 = m_stats[i].GetFta();
		int s7 = m_stats[i].GetTfgm();
		int s8 = m_stats[i].GetTfga();
		int s9 = m_stats[i].GetOreb();
		int s10 = m_stats[i].GetReb() + s9;
		int s11 = m_stats[i].GetAst();
		int s12 = m_stats[i].GetStl();
		int s13 = m_stats[i].GetTo();
		int s14 = m_stats[i].GetBlk();
		int s15 = m_stats[i].GetPf();


		g = g + s1;
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
		to = to + s13;
		blk = blk + s14;
		pf = pf + s15;
		if (i == 24 && avg.m_settings.m_current_stage == 0)//in season career stats not saved yet
		{
			s1 = g + avg.m_actual[m_player_index].m_sim_games;
			s2 = min + avg.m_actual[m_player_index].m_sim_min - 1;
			s3 = fgm + avg.m_actual[m_player_index].m_sim_fgm + avg.m_actual[m_player_index].m_sim_tfgm;
			s4 = fga + avg.m_actual[m_player_index].m_sim_fga + avg.m_actual[m_player_index].m_sim_tfga;
			s5 = ftm + avg.m_actual[m_player_index].m_sim_ftm;
			s6 = fta + avg.m_actual[m_player_index].m_sim_fta;
			s7 = tgm + avg.m_actual[m_player_index].m_sim_tfgm;
			s8 = tga + avg.m_actual[m_player_index].m_sim_tfga;
			s9 = orb + avg.m_actual[m_player_index].m_sim_oreb;
			s10 = reb + avg.m_actual[m_player_index].m_sim_oreb + avg.m_actual[m_player_index].m_sim_reb;
			s11 = ast + avg.m_actual[m_player_index].m_sim_ast;
			s12 = stl + avg.m_actual[m_player_index].m_sim_stl;
			s13 = to + avg.m_actual[m_player_index].m_sim_to;
			s14 = blk + avg.m_actual[m_player_index].m_sim_blk;
			s15 = pf + +avg.m_actual[m_player_index].m_sim_pf;
		}
		else if (i == 24)//in season career stats saved 
		{
			s1 = g;
			s2 = min;
			s3 = fgm;
			s4 = fga;
			s5 = ftm;
			s6 = fta;
			s7 = tgm;
			s8 = tga;
			s9 = orb;
			s10 = reb;
			s11 = ast;
			s12 = stl;
			s13 = to;
			s14 = blk;
			s15 = pf;
		}

		if (s1 == 0) continue;

		CString string;
		if (i != 24)
			string.Format("%d", m_stats[i].GetRosterNumber());
		else
			string = "------";

		m_listCtrl.InsertItem(yearsPro, (LPCTSTR)string);
		m_listCtrl.SetItemText(yearsPro, 1, (LPCTSTR)m_stats[i].GetTeam());

		string.Format("%d", s1);
		m_listCtrl.SetItemText(yearsPro, 2, (LPCTSTR)string);

		string.Format("%.1f", double(s2) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 3, (LPCTSTR)string);

		string.Format("%.1f", double(s3) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 4, (LPCTSTR)string);

		string.Format("%.1f", double(s4) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 5, (LPCTSTR)string);

		if (s4 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s3) / double(s1)) / (double(s4) / double(s1)) * 100);
		m_listCtrl.SetItemText(yearsPro, 6, (LPCTSTR)string);

		string.Format("%.1f", double(s5) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 7, (LPCTSTR)string);

		string.Format("%.1f", double(s6) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 8, (LPCTSTR)string);

		if (s6 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s5) / double(s1)) / (double(s6) / double(s1)) * 100);
		m_listCtrl.SetItemText(yearsPro, 9, (LPCTSTR)string);


		string.Format("%.1f", double(s7) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 10, (LPCTSTR)string);

		string.Format("%.1f", double(s8) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 11, (LPCTSTR)string);

		if (s8 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s7) / double(s1)) / (double(s8) / double(s1)) * 100);

		m_listCtrl.SetItemText(yearsPro, 12, (LPCTSTR)string);

		string.Format("%.1f", double(s9) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 13, (LPCTSTR)string);

		string.Format("%.1f", double(s10) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 14, (LPCTSTR)string);

		string.Format("%.1f", double(s11) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 15, (LPCTSTR)string);

		string.Format("%.1f", double(s12) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 16, (LPCTSTR)string);

		string.Format("%.1f", double(s13) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 17, (LPCTSTR)string);

		string.Format("%.1f", double(s14) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 18, (LPCTSTR)string);

		string.Format("%.1f", double(s15) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 19, (LPCTSTR)string);

		string.Format("%.1f", double(s3 * 2 + s5 + s7) / double(s1));
		m_listCtrl.SetItemText(yearsPro, 20, (LPCTSTR)string);

		yearsPro = yearsPro + 1;

	}

	int items = m_listCtrl.GetItemCount() - 1;
	if (items >= 0)
	{
		m_listCtrl.SetItemState(items, LVIS_SELECTED, LVIS_SELECTED);
		m_listCtrl.SetItemState(items, LVIS_FOCUSED, LVIS_FOCUSED);
		m_listCtrl.EnsureVisible(items, TRUE);
	}



}





BOOL CPlayerCardDlg::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/playercard.htm", HH_DISPLAY_TOPIC, 0);

	return CDialog::OnHelpInfo(pHelpInfo);

	//	return CPlayerCardDlg::OnHelpInfo(pHelpInfo);
}

void CPlayerCardDlg::ListPlayerAwards()
{



	CString pFileName = m_path + m_leagueName + ".sal";


	bool exists = true;
	CFileStatus status;
	if (CFile::GetStatus(pFileName, status) == 0) exists = false;




	if (exists == true)
	{

		CString awards[512];


		CFile file(pFileName, CFile::modeReadWrite);
		CString buffer;
		char s[33];

		int count = 0;
		//	int id = m_player.m_id;
		//	if(m_useCPlayer == false) id = m_pointer;
		int id = m_pointer;

		int seek = 2000 + id * 500 + 676;
		file.Seek(seek, CFile::begin);
		int bytes = file.Read(s, 4);
		s[bytes] = 0;
		int start_yr = atoi(s);
		int rings = 0;

		CString place[6] = { "", "1st", "2nd", "3rd", "4th", "5th" };

		for (int y = 0; y <= 20; y++)
		{

			int mvp_seek = 2000 + id * 500 + 680 + (y * 15);
			file.Seek(mvp_seek, CFile::begin);
			int bytes = file.Read(s, 1);
			s[bytes] = 0;
			int mvp = atoi(s);
			if (mvp > 0 && mvp <= 5)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d most valuable player (%s)", yr, place[mvp]);
				//			string.Format("%d mvp  %d", yr, mvp);
				awards[count] = string;
				count = count + 1;
			}

			int defense_seek = 2000 + id * 500 + 681 + (y * 15);
			file.Seek(defense_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int defense = atoi(s);
			if (defense > 0 && defense <= 5)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d defensive player of the year  (%s)", yr, place[defense]);
				//			string.Format("%d defense - %d", yr, defense);
				awards[count] = string;
				count = count + 1;
			}

			int rookie_seek = 2000 + id * 500 + 682 + (y * 15);
			file.Seek(rookie_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int rookie = atoi(s);
			if (rookie > 0 && rookie <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d rookie - %d", yr, rookie);
				string.Format("%d rookie of the year (%s)", yr, place[rookie]);
				awards[count] = string;
				count = count + 1;
			}

			int pts_seek = 2000 + id * 500 + 683 + (y * 15);
			file.Seek(pts_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int pts = atoi(s);
			if (pts > 0 && pts <= 5)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d scoring (%s)", yr, place[pts]);
				//			string.Format("%d pts - %d", yr, pts);
				awards[count] = string;
				count = count + 1;
			}

			int reb_seek = 2000 + id * 500 + 684 + (y * 15);
			file.Seek(reb_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int reb = atoi(s);
			if (reb > 0 && reb <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d reb - %d", yr, reb);
				string.Format("%d rebounds (%s)", yr, place[reb]);
				awards[count] = string;
				count = count + 1;
			}

			int ast_seek = 2000 + id * 500 + 685 + (y * 15);
			file.Seek(ast_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int ast = atoi(s);
			if (ast > 0 && ast <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d ast - %d", yr, ast);
				string.Format("%d assists (%s)", yr, place[ast]);
				awards[count] = string;
				count = count + 1;
			}

			int stl_seek = 2000 + id * 500 + 686 + (y * 15);
			file.Seek(stl_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int stl = atoi(s);
			if (stl > 0 && stl <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d stl - %d", yr, stl);
				string.Format("%d steals (%s)", yr, place[stl]);
				awards[count] = string;
				count = count + 1;
			}

			int blk_seek = 2000 + id * 500 + 687 + (y * 15);
			file.Seek(blk_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int blk = atoi(s);
			if (blk > 0 && blk <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d blk - %d", yr, blk);
				string.Format("%d blocks (%s)", yr, place[blk]);
				awards[count] = string;
				count = count + 1;
			}

			int ring_seek = 2000 + id * 500 + 688 + (y * 15);
			file.Seek(ring_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int ring = atoi(s);
			//rings = 0;
			if (ring > 0)
			{
				rings = rings + 1;
				CString string;
				int yr = start_yr + y;
				string.Format("%d championship", yr);
				//			string.Format("%d mvp (%s)", yr, place[mvp]);

				awards[count] = string;
				count = count + 1;
			}

			int po_mvp_seek = 2000 + id * 500 + 689 + (y * 15);
			file.Seek(po_mvp_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int po_mvp = atoi(s);
			if (po_mvp > 0)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d playoff mvp", yr);
				awards[count] = string;
				count = count + 1;
			}

			int sth_seek = 2000 + id * 500 + 690 + (y * 15);
			file.Seek(sth_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int sth = atoi(s);
			if (sth > 0 && sth <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d 6th - %d", yr, sth);
				string.Format("%d 6th man (%s)", yr, place[sth]);
				awards[count] = string;
				count = count + 1;
			}

			int seek = 2000 + id * 500 + 691 + (y * 15);
			file.Seek(seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int all = atoi(s);
			if (all > 0 && all <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d all league - %d", yr, all);
				string.Format("%d all league %s team", yr, place[all]);
				awards[count] = string;
				count = count + 1;
			}

			seek = 2000 + id * 500 + 692 + (y * 15);
			file.Seek(seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			all = atoi(s);
			if (all > 0 && all <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d all defense - %d", yr, all);
				string.Format("%d all defense %s team", yr, place[all]);
				awards[count] = string;
				count = count + 1;
			}

			seek = 2000 + id * 500 + 693 + (y * 15);
			file.Seek(seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			all = atoi(s);
			if (all > 0 && all <= 5)
			{
				CString string;
				int yr = start_yr + y;
				//			string.Format("%d all rookie - %d", yr, all);
				string.Format("%d all rookie %s team", yr, place[all]);
				awards[count] = string;
				count = count + 1;
			}



			long int asw_seek = 2000 + id * 500 + 694 + (y * 15);
			file.Seek(asw_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			int asw = atoi(s);
			if (asw == 1)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d all star", yr);
				awards[count] = string;
				count = count + 1;
			}
			else if (asw == 2)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d all star mvp", yr);
				awards[count] = string;
				count = count + 1;
			}


			asw_seek = 2000 + id * 500 + 995 + (y * 3);
			file.Seek(asw_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			asw = atoi(s);
			if (asw == 1)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d rookie game", yr);
				awards[count] = string;
				count = count + 1;
			}
			else if (asw == 2)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d rookie game mvp", yr);
				awards[count] = string;
				count = count + 1;
			}

			asw_seek = 2000 + id * 500 + 996 + (y * 3);
			file.Seek(asw_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			asw = atoi(s);
			if (asw == 1)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d three contest", yr);
				awards[count] = string;
				count = count + 1;
			}
			else if (asw == 2)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d three contest champ", yr);
				awards[count] = string;
				count = count + 1;
			}

			asw_seek = 2000 + id * 500 + 997 + (y * 3);
			file.Seek(asw_seek, CFile::begin);
			bytes = file.Read(s, 1);
			s[bytes] = 0;
			asw = atoi(s);
			if (asw == 1)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d dunk contest", yr);
				awards[count] = string;
				count = count + 1;
			}
			else if (asw == 2)
			{
				CString string;
				int yr = start_yr + y;
				string.Format("%d dunk contest champ", yr);
				awards[count] = string;
				count = count + 1;
			}


		}

		m_list_awards.ResetContent();


		CPlayer m_stats = avg.m_actual[m_player_index];
		int asw = m_stats.m_all_star;
		if (asw == 1)
		{
			awards[count] = "all star";
			count = count + 1;
		}
		else if (asw == 2)
		{
			awards[count] = "all star mvp";
			count = count + 1;
		}

		asw = m_stats.m_rookie_star;
		if (asw == 1)
		{
			awards[count] = "rookie game";
			count = count + 1;
		}
		else if (asw == 2)
		{
			awards[count] = "rookie game mvp";
			count = count + 1;
		}

		asw = m_stats.m_3contest;
		if (asw == 1)
		{
			awards[count] = "three contest";
			count = count + 1;
		}
		else if (asw == 2)
		{
			awards[count] = "three contest champ";
			count = count + 1;
		}


		asw = m_stats.m_dunkcontest;
		if (asw == 1)
		{
			awards[count] = "dunk contest";
			count = count + 1;
		}
		else if (asw == 2)
		{
			awards[count] = "slam dunk champ";
			count = count + 1;
		}








		if (rings > 0)
		{
			CString string;
			string.Format("titles: %d", rings);
			awards[count] = string;
			count = count + 1;
		}


		if (count > 0)
		{
			m_list_awards.ResetContent();
			for (int y = 0; y <= (count - 1); y++)
			{
				m_list_awards.AddString(awards[y]);
			}
			m_list_awards.SetCurSel(count - 1);

		}
		else
		{
			m_list_awards.AddString("no awards");
		}



	}

}
//
//void CPlayerCardDlg::OnColumnclickListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult)
//{
//
//	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
//	// TODO: Add your control notification handler code here
//
//	int index = m_listCtrl.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
//	int m_column = pNMListView->iSubItem;
//
//
//	CPlayer m_player_i, m_player_j;
//
//
//
//
//	for (int i = 0; i <= 23; i++)
//	{
//		for (int j = 0; j <= 23; j++)
//		{
//
//
//			bool swap = false;
//
//			m_player_i = m_stats[i];
//			m_player_j = m_stats[j];
//
//			double s1_i = (double)m_stats[i].GetGames();
//			double s1_j = (double)m_stats[j].GetGames();
//			if (s1_i == 0 || s1_j == 0) continue;
//			double s2_i = (double)m_stats[i].GetMin() / s1_i;
//			double s3_i = ((double)m_stats[i].GetFgm() + (double)m_stats[i].GetTfgm()) / s1_i;
//			double s4_i = ((double)m_stats[i].GetFga() + (double)m_stats[i].GetTfga()) / s1_i;
//			double s5_i = (double)m_stats[i].GetFtm() / s1_i;
//			double s6_i = (double)m_stats[i].GetFta() / s1_i;
//			double s7_i = (double)m_stats[i].GetTfgm() / s1_i;
//			double s8_i = (double)m_stats[i].GetTfga() / s1_i;
//			double s9_i = (double)m_stats[i].GetOreb() / s1_i;
//			double s10_i = ((double)m_stats[i].GetReb() + (double)m_stats[i].GetOreb()) / s1_i;
//			double s11_i = (double)m_stats[i].GetAst() / s1_i;
//			double s12_i = (double)m_stats[i].GetStl() / s1_i;
//			double s13_i = (double)m_stats[i].GetTo() / s1_i;
//			double s14_i = (double)m_stats[i].GetBlk() / s1_i;
//			double s15_i = (double)m_stats[i].GetPf() / s1_i;
//
//			double p1_i = s3_i / s4_i;
//			double p2_i = s5_i / s6_i;
//			double p3_i = s7_i / s8_i;
//			double pt_i = (s3_i * 2 + s5_i + s7_i);
//
//			double s2_j = (double)m_stats[j].GetMin() / s1_j;
//			double s3_j = ((double)m_stats[j].GetFgm() + (double)m_stats[j].GetTfgm()) / s1_j;
//			double s4_j = ((double)m_stats[j].GetFga() + (double)m_stats[j].GetTfga()) / s1_j;
//			double s5_j = (double)m_stats[j].GetFtm() / s1_j;
//			double s6_j = (double)m_stats[j].GetFta() / s1_j;
//			double s7_j = (double)m_stats[j].GetTfgm() / s1_j;
//			double s8_j = (double)m_stats[j].GetTfga() / s1_j;
//			double s9_j = (double)m_stats[j].GetOreb() / s1_j;
//			double s10_j = ((double)m_stats[j].GetReb() + (double)m_stats[j].GetOreb()) / s1_j;
//			double s11_j = (double)m_stats[j].GetAst() / s1_j;
//			double s12_j = (double)m_stats[j].GetStl() / s1_j;
//			double s13_j = (double)m_stats[j].GetTo() / s1_j;
//			double s14_j = (double)m_stats[j].GetBlk() / s1_j;
//			double s15_j = (double)m_stats[j].GetPf() / s1_j;
//
//			double p1_j = s3_j / s4_j;
//			double p2_j = s5_j / s6_j;
//			double p3_j = s7_j / s8_j;
//			double pt_j = (s3_j * 2 + s5_j + s7_j);
//
//
//
//			switch (m_column)
//			{
//
//			case 0:
//				swap = m_player_i.GetRosterNumber() < m_player_j.GetRosterNumber();
//				break;
//			case 1:
//				swap = m_player_i.m_team < m_player_j.m_team;
//				break;
//			case 2:
//				swap = s1_i > s1_j;
//				break;
//			case 3:
//				swap = s2_i > s2_j;
//				break;
//			case 4:
//				swap = s3_i > s3_j;
//				break;
//			case 5:
//				swap = s4_i > s4_j;
//				break;
//			case 6:
//				swap = p1_i > p1_j;
//				break;
//			case 7:
//				swap = s5_i > s5_j;
//				break;
//			case 8:
//				swap = s6_i > s6_j;
//				break;
//			case 9:
//				swap = p2_i > p2_j;
//				break;
//			case 10:
//				swap = s7_i > s7_j;
//				break;
//			case 11:
//				swap = s8_i > s8_j;
//				break;
//			case 12:
//				swap = p3_i > p3_j;
//				break;
//			case 13:
//				swap = s9_i > s9_j;
//				break;
//			case 14:
//				swap = s10_i > s10_j;
//				break;
//			case 15:
//				swap = s11_i > s11_j;
//				break;
//			case 16:
//				swap = s12_i > s12_j;
//				break;
//			case 17:
//				swap = s13_i > s13_j;
//				break;
//			case 18:
//				swap = s14_i > s14_j;
//				break;
//			case 19:
//				swap = s15_i > s15_j;
//				break;
//			case 20:
//				swap = pt_i > pt_j;
//				break;
//
//
//			}
//
//			if (swap == true)
//			{//swap
//				CPlayer temp = m_stats[i];
//				m_stats[i] = m_stats[j];
//				m_stats[j] = temp;
//			}
//
//
//		}
//
//	}
//
//	ListStats();
//	ListSeasonStats();
//	DisplayRating();
//	int items = 0;
//	m_listCtrl.SetItemState(items, LVIS_SELECTED, LVIS_SELECTED);
//	m_listCtrl.SetItemState(items, LVIS_FOCUSED, LVIS_FOCUSED);
//	m_listCtrl.EnsureVisible(items, TRUE);
//	*pResult = 0;
//}













void CPlayerCardDlg::OnButtonForward()
{
	// TODO: Add your control notification handler code here

	do
	{
		m_player_index = m_player_index + 1;
		//if(m_player_index > 1440) m_player_index = 1;
		if (m_player_index > m_pl_index_end) m_player_index = m_pl_index_start;
	} while (avg.m_actual[m_player_index].m_name == "" || avg.m_actual[m_player_index].m_id == 0);

	m_pointer = avg.m_actual[m_player_index].m_id;

	if (m_pointer > 0)
	{
		Player();
		ListPlayerAwards();
	}

}

void CPlayerCardDlg::OnButtonBack()
{
	// TODO: Add your control notification handler code here
	do
	{
		m_player_index = m_player_index - 1;
		//if(m_player_index < 1) m_player_index = 1440;
		if (m_player_index < m_pl_index_start) m_player_index = m_pl_index_end;


	} while (avg.m_actual[m_player_index].m_name == "" || avg.m_actual[m_player_index].m_id == 0);



	m_pointer = avg.m_actual[m_player_index].m_id;

	if (m_pointer > 0)
	{

		Player();
		ListPlayerAwards();
	}
}

void CPlayerCardDlg::ListSeasonStats()
{

	CPlayer m_stats = avg.m_actual[m_player_index];

	if (m_stats.m_current_team < 0 || m_stats.m_current_contract_yr != m_stats.m_contract_yrs)
		m_button_extend.EnableWindow(FALSE);
	else
		m_button_extend.EnableWindow(TRUE);

	//	if(m_stats.m_current_contract_yr < 4)
	//		m_button_extend.EnableWindow(FALSE);



	if (m_stats.m_current_contract_yr == 3 && m_stats.m_yrs_of_service == 3)
		m_button_extend.EnableWindow(TRUE);

	if (m_extension_allowed != true || avg.m_settings.m_current_stage > 0) m_button_extend.EnableWindow(FALSE);


	m_listctrlstats.DeleteAllItems();
	int yearsPro = 0;
	if (m_stats.m_sim_games != 0)
	{
		int s1 = m_stats.m_sim_games;
		int sg = m_stats.m_starter;
		int s2 = m_stats.m_sim_min;
		int s3 = m_stats.m_sim_fgm + m_stats.m_sim_tfgm;
		int s4 = m_stats.m_sim_fga + m_stats.m_sim_tfga;
		int s5 = m_stats.m_sim_ftm;
		int s6 = m_stats.m_sim_fta;
		int s7 = m_stats.m_sim_tfgm;
		int s8 = m_stats.m_sim_tfga;
		int s9 = m_stats.m_sim_oreb;
		int s10 = m_stats.m_sim_reb + s9;
		int s11 = m_stats.m_sim_ast;
		int s12 = m_stats.m_sim_stl;
		int s13 = m_stats.m_sim_to;
		int s14 = m_stats.m_sim_blk;
		int s15 = m_stats.m_sim_pf;


		CString string = m_stats.GetTeam();
		m_listctrlstats.InsertItem(yearsPro, (LPCTSTR)string);

		string.Format("%d", s1);
		m_listctrlstats.SetItemText(yearsPro, 1, (LPCTSTR)string);

		string.Format("%d", sg);
		m_listctrlstats.SetItemText(yearsPro, 2, (LPCTSTR)string);

		string.Format("%.1f", double(s2) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 3, (LPCTSTR)string);

		string.Format("%.1f", double(s3) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 4, (LPCTSTR)string);

		string.Format("%.1f", double(s4) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 5, (LPCTSTR)string);

		if (s4 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s3) / double(s1)) / (double(s4) / double(s1)) * 100);
		m_listctrlstats.SetItemText(yearsPro, 6, (LPCTSTR)string);

		string.Format("%.1f", double(s5) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 7, (LPCTSTR)string);

		string.Format("%.1f", double(s6) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 8, (LPCTSTR)string);

		if (s6 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s5) / double(s1)) / (double(s6) / double(s1)) * 100);
		m_listctrlstats.SetItemText(yearsPro, 9, (LPCTSTR)string);


		string.Format("%.1f", double(s7) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 10, (LPCTSTR)string);

		string.Format("%.1f", double(s8) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 11, (LPCTSTR)string);

		if (s8 == 0)
			string = "-----";
		else
			string.Format("%.1f", (double(s7) / double(s1)) / (double(s8) / double(s1)) * 100);

		m_listctrlstats.SetItemText(yearsPro, 12, (LPCTSTR)string);

		string.Format("%.1f", double(s9) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 13, (LPCTSTR)string);

		string.Format("%.1f", double(s10) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 14, (LPCTSTR)string);

		string.Format("%.1f", double(s11) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 15, (LPCTSTR)string);

		string.Format("%.1f", double(s12) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 16, (LPCTSTR)string);

		string.Format("%.1f", double(s13) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 17, (LPCTSTR)string);

		string.Format("%.1f", double(s14) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 18, (LPCTSTR)string);

		string.Format("%.1f", double(s15) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 19, (LPCTSTR)string);

		string.Format("%.1f", double(s3 * 2.0 + s5 + s7) / double(s1));
		m_listctrlstats.SetItemText(yearsPro, 20, (LPCTSTR)string);

		//int inj = m_stats.GetInjury();
		//   if(inj != 1)
		//	string.Format("injury: %d games",  inj);
		//else
		//	string.Format("injury: %d game",  inj);
		//   m_listctrlstats.InsertItem(yearsPro+1, string);





				//season playoffstats







		int yearsPro = 1;
		if (m_stats.m_po_games != 0)
		{
			int s1 = m_stats.m_po_games;
			int s2 = m_stats.m_po_min;
			int s3 = m_stats.m_po_fgm + m_stats.m_po_tfgm;
			int s4 = m_stats.m_po_fga + m_stats.m_po_tfga;
			int s5 = m_stats.m_po_ftm;
			int s6 = m_stats.m_po_fta;
			int s7 = m_stats.m_po_tfgm;
			int s8 = m_stats.m_po_tfga;
			int s9 = m_stats.m_po_oreb;
			int s10 = m_stats.m_po_reb + s9;
			int s11 = m_stats.m_po_ast;
			int s12 = m_stats.m_po_stl;
			int s13 = m_stats.m_po_to;
			int s14 = m_stats.m_po_blk;
			int s15 = m_stats.m_po_pf;


			CString string;
			m_listctrlstats.InsertItem(yearsPro, (LPCTSTR)m_stats.GetTeam());


			string.Format("%d", s1);
			m_listctrlstats.SetItemText(yearsPro, 1, (LPCTSTR)string);

			// string.Format("%d", sg);
			m_listctrlstats.SetItemText(yearsPro, 2, (LPCTSTR)"-");

			string.Format("%.1f", double(s2) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 3, (LPCTSTR)string);

			string.Format("%.1f", double(s3) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 4, (LPCTSTR)string);

			string.Format("%.1f", double(s4) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 5, (LPCTSTR)string);

			if (s4 == 0)
				string = "-----";
			else
				string.Format("%.1f", (double(s3) / double(s1)) / (double(s4) / double(s1)) * 100);
			m_listctrlstats.SetItemText(yearsPro, 6, (LPCTSTR)string);

			string.Format("%.1f", double(s5) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 7, (LPCTSTR)string);

			string.Format("%.1f", double(s6) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 8, (LPCTSTR)string);

			if (s6 == 0)
				string = "-----";
			else
				string.Format("%.1f", (double(s5) / double(s1)) / (double(s6) / double(s1)) * 100);
			m_listctrlstats.SetItemText(yearsPro, 9, (LPCTSTR)string);


			string.Format("%.1f", double(s7) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 10, (LPCTSTR)string);

			string.Format("%.1f", double(s8) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 11, (LPCTSTR)string);

			if (s8 == 0)
				string = "-----";
			else
				string.Format("%.1f", (double(s7) / double(s1)) / (double(s8) / double(s1)) * 100);

			m_listctrlstats.SetItemText(yearsPro, 12, (LPCTSTR)string);

			string.Format("%.1f", double(s9) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 13, (LPCTSTR)string);

			string.Format("%.1f", double(s10) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 14, (LPCTSTR)string);

			string.Format("%.1f", double(s11) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 15, (LPCTSTR)string);

			string.Format("%.1f", double(s12) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 16, (LPCTSTR)string);

			string.Format("%.1f", double(s13) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 17, (LPCTSTR)string);

			string.Format("%.1f", double(s14) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 18, (LPCTSTR)string);

			string.Format("%.1f", double(s15) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 19, (LPCTSTR)string);


			string.Format("%.1f", double(s3 * 2.0 + s5 + s7) / double(s1));
			m_listctrlstats.SetItemText(yearsPro, 20, (LPCTSTR)string);

		}

	}
}

void CPlayerCardDlg::DisplayRating()
{
	CPlayer m_player = avg.m_actual[m_player_index];

	CString string = m_scout.m_name;
	if (string != "") string = "Scouting Report by " + m_title + " " + string;
	else m_buttonScout.ShowWindow(FALSE);
	m_buttonScout.SetWindowText(string);


	m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(), m_player.GetFta(), m_player.GetOreb(), m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_scout.m_scoring, m_scout.m_shooting, m_scout.m_rebounding, m_scout.m_passing, m_scout.m_defense);
	m_player.SetTradeTrueRating(0);
	m_player.SetAdjTradeValue(m_scout.m_pot1, m_scout.m_pot2, m_scout.m_effort);




	CString pos = m_player.GetPos();
	CString name = m_player.GetName();
	//SetWindowText(pos + " " + name);
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD, Age, Ht, Wt;

	int ht = m_player.m_height;
	int ft = m_player.m_height / 12;
	int in = m_player.m_height - ft * 12;
	Ht.Format("%d' %d", ft, in);

	int wt = m_player.m_weight;
	Wt.Format("%d", wt);


	int ag = m_player.GetAge();
	Age.Format("%d", ag);
	int o = m_player.GetMovOff();
	OutO.Format("%d", o);
	int p = m_player.GetPenOff();
	PenO.Format("%d", p);
	int i = m_player.GetPostOff();
	PostO.Format("%d", i);
	int f1 = m_player.GetTransOff();
	TransO.Format("%d", f1);
	int od = m_player.GetMovDef();
	OutD.Format("%d", od);
	int pd = m_player.GetPenDef();
	PenD.Format("%d", pd);
	int id = m_player.GetPostDef();
	PostD.Format("%d", id);
	int fd = m_player.GetTransDef();
	TransD.Format("%d", fd);


	m_listCtrlStats.InsertItem(0, (LPCTSTR)pos);
	m_listCtrlStats.SetItemText(0, 1, (LPCTSTR)name);
	m_listCtrlStats.SetItemText(0, 2, (LPCTSTR)Ht);
	m_listCtrlStats.SetItemText(0, 3, (LPCTSTR)Wt);


	m_listCtrlStats.SetItemText(0, 4, (LPCTSTR)Age);
	m_listCtrlStats.SetItemText(0, 6, (LPCTSTR)OutO);
	m_listCtrlStats.SetItemText(0, 7, (LPCTSTR)PenO);
	m_listCtrlStats.SetItemText(0, 8, (LPCTSTR)PostO);
	m_listCtrlStats.SetItemText(0, 9, (LPCTSTR)TransO);
	m_listCtrlStats.SetItemText(0, 11, (LPCTSTR)OutD);
	m_listCtrlStats.SetItemText(0, 12, (LPCTSTR)PenD);
	m_listCtrlStats.SetItemText(0, 13, (LPCTSTR)PostD);
	m_listCtrlStats.SetItemText(0, 14, (LPCTSTR)TransD);

	m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);



	int r = m_player.GetPrFga();
	CString s;
	int rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrFga(rating);

	s.Format("%d", rating);
	m_listCtrlShot.InsertItem(0, (LPCTSTR)s);


	r = m_player.GetPrFgp();
	rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrFgp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0, 1, (LPCTSTR)s);




	r = m_player.GetPrFta();
	rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrFta(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0, 2, (LPCTSTR)s);



	r = m_player.GetPrFtp();
	rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrFtp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0, 3, (LPCTSTR)s);



	r = m_player.GetPrTga();
	rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrTga(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0, 4, (LPCTSTR)s);



	r = m_player.GetPrTgp();
	rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrTgp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0, 5, (LPCTSTR)s);



	r = m_player.GetPrOrb();
	rating = m_player.PrRating(false, r, m_scout.m_rebounding);
	m_player.SetAdjPrOrb(rating);
	s.Format("%d", rating);
	m_listctrlskill.InsertItem(0, (LPCTSTR)s);


	r = m_player.GetPrDrb();
	rating = m_player.PrRating(false, r, m_scout.m_rebounding);
	m_player.SetAdjPrDrb(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0, 1, (LPCTSTR)s);


	r = m_player.GetPrAst();
	rating = m_player.PrRating(false, r, m_scout.m_passing);
	m_player.SetAdjPrAst(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0, 2, (LPCTSTR)s);


	r = m_player.GetPrStl();
	rating = m_player.PrRating(false, r, m_scout.m_defense);
	m_player.SetAdjPrStl(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0, 3, (LPCTSTR)s);

	r = m_player.GetPrTo();

	rating = m_player.PrRating(false, r, m_scout.m_passing);
	m_player.SetAdjPrTo(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0, 4, (LPCTSTR)s);


	r = m_player.GetPrBlk();
	rating = m_player.PrRating(false, r, m_scout.m_defense);
	m_player.SetAdjPrBlk(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0, 5, (LPCTSTR)s);
	CString display[6] = { "", "Very Low", "Poor", "Average", "Good", "Excellent" };
	CString h_display[10] = { "", "Disgruntled", "Mad", "Unhappy", "So So", "Ok", "Good", "Pleased", "Happy", "Grateful" };

	rating = m_player.PrRating(false, m_player.GetPot1() + 200, m_scout.m_pot1);
	m_listFuture.InsertItem(0, (LPCTSTR)display[rating]);
	rating = m_player.PrRating(false, m_player.GetPot2() + 200, m_scout.m_pot2);
	m_listFuture.SetItemText(0, 1, (LPCTSTR)display[rating]);
	rating = m_player.PrRating(false, m_player.GetEffort() + 200, m_scout.m_effort);
	m_listFuture.SetItemText(0, 2, (LPCTSTR)display[rating]);




	CString m_lines[33];
	m_player.CreateReport(m_lines, avg.r_ast, avg.r_fta, avg.r_tga, avg.m_avg_tgp, avg.r_orb, avg.r_drb, avg.r_stl, avg.r_to, avg.r_blk,
		avg.r_fga, avg.m_avg_fgp, avg.m_avg_fga, avg.m_avg_ftp, avg.m_avg_trade_tru);

	m_list_report.ResetContent();
	if (m_lines[32] != "") m_list_report.AddString((LPCTSTR)m_lines[32]);
	for (int i = 0; i <= 31; i++)
	{
		if (m_lines[i] != "") m_list_report.AddString((LPCTSTR)m_lines[i]);
	}




	m_list_ctrl_1.DeleteAllItems();
	CString Stats[33];
	CString Name;

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

	n = m_player.m_content;
	Stats[6] = h_display[n];

	n = m_player.m_health;
	Stats[7].Format("%d percent", n);
	if (m_player.m_injury > 1)
		Stats[7].Format("out %d days", m_player.m_injury);
	else if (m_player.m_injury == 1)
		Stats[7].Format("out %d day", m_player.m_injury);



	for (int index = 0; index < 19; index++)
	{
		if (Stats[index] == "") continue;
		m_list_ctrl_1.InsertItem(index, (LPCTSTR)m_label[index + 4]);
		m_list_ctrl_1.SetItemText(index, 1, (LPCTSTR)Stats[index]);
		Stats[index] = "";
	}


	m_list_ctrl_3.DeleteAllItems();

	bool f = m_player.m_is_free_agent;
	if (f == true) Stats[0] = "yes"; else Stats[0] = "no";

	n = m_player.m_yrs_of_service;
	Stats[1].Format("%d", n);

	n = m_player.m_yrs_on_team;
	Stats[2].Format("%d", n);

	if (m_player.m_yrs_on_team >= 3) Stats[3] = "yes"; else Stats[3] = "no";

	for (int index = 0; index < 19; index++)
	{
		if (Stats[index] == "") continue;
		m_list_ctrl_3.InsertItem(index, (LPCTSTR)m_label[index]);
		m_list_ctrl_3.SetItemText(index, 1, (LPCTSTR)Stats[index]);
	}


	m_list_ctrl_2.DeleteAllItems();


	double fn = (double)m_player.m_contract_salaries[1] / 100;
	Stats[0].Format("%.2f", fn);

	fn = (double)m_player.m_contract_salaries[2] / 100;
	Stats[1].Format("%.2f", fn);

	fn = (double)m_player.m_contract_salaries[3] / 100;
	Stats[2].Format("%.2f", fn);

	fn = (double)m_player.m_contract_salaries[4] / 100;
	Stats[3].Format("%.2f", fn);

	fn = (double)m_player.m_contract_salaries[5] / 100;
	Stats[4].Format("%.2f", fn);

	fn = (double)m_player.m_contract_salaries[6] / 100;
	Stats[5].Format("%.2f", fn);



	int count = 0;
	for (int index = 0; index < 19; index++)
	{
		if (Stats[index] == "" || Stats[index] == "0.00") continue;
		m_list_ctrl_2.InsertItem(count, m_label[21 + index]);
		m_list_ctrl_2.SetItemText(count, 1, Stats[index]);
		count = count + 1;
	}

	int mo = m_player.m_contract_salaries[1] +
		m_player.m_contract_salaries[2] +
		m_player.m_contract_salaries[3] +
		m_player.m_contract_salaries[4] +
		m_player.m_contract_salaries[5] +
		m_player.m_contract_salaries[6];

	int yrs = m_player.m_current_contract_yr;
	CString yr = "";
	yr.Format("%d", yrs);

	double mon = (double)mo / 100;

	CString  money;
	string.Format("%d year", count);
	money.Format("%.2f", mon);

	if (count > 0)
	{
		m_list_ctrl_2.InsertItem(count, (LPCTSTR)string);
		m_list_ctrl_2.SetItemText(count, 1, (LPCTSTR)money);
		m_list_ctrl_2.InsertItem(count + 1, (LPCTSTR)"current year");
		m_list_ctrl_2.SetItemText(count + 1, 1, (LPCTSTR)yr);
	}
	else
	{
		m_list_ctrl_2.InsertItem(count, (LPCTSTR)"");
		m_list_ctrl_2.SetItemText(count, 1, (LPCTSTR)"");
		m_list_ctrl_2.InsertItem(count + 1, (LPCTSTR)"");
		m_list_ctrl_2.SetItemText(count + 1, 1, (LPCTSTR)"");
	}



	CString str;
	int amt = m_player.m_current_yr_salary;

	if (m_player.m_team_paying_name != "")
		str.Format("contract owned by: %s", m_player.m_team_paying_name);
	else str = "not under contract";

	if (amt == 0) str = "not under contract";
	if (amt == 0 && m_player.m_team_paying_name != "")
	{
		str.Format("rights owned by: %s", m_player.m_team_paying_name);
	}

	m_edit_owner = str;
	UpdateData(FALSE);

}







void CPlayerCardDlg::OnButtonScout()
{
	// TODO: Add your control notification handler code here
	CScoutProfileDlg* scout = new CScoutProfileDlg;
	scout->m_scout = m_scout;

	scout->m_type = 1;
	if (m_title == "Coach")
	{
		scout->m_type = 2;
	}

	scout->DoModal();
	delete scout;
}

void CPlayerCardDlg::ListHighs()
{
	CPlayer m_player = avg.m_actual[m_player_index];
	m_list_highs.DeleteAllItems();
	CString string[32];
	m_player.ListHighs(string);

	int co = 0;
	for (int i = 1; i <= 5; i++)
	{
		m_list_highs.InsertItem(i - 1, (LPCTSTR)string[co]);
		co = co + 1;
		for (int j = 1; j <= 4; j++)
		{
			m_list_highs.SetItemText(i - 1, j, (LPCTSTR)string[co]);
			co = co + 1;
		}
	}

	for (int i = 5; i <= 6; i++)
	{
		m_list_highs.InsertItem(i, (LPCTSTR)string[25 + (i - 5) * 3]);
		m_list_highs.SetItemText(i, 1, (LPCTSTR)string[26 + (i - 5) * 3]);
		m_list_highs.SetItemText(i, 2, (LPCTSTR)"-");
		m_list_highs.SetItemText(i, 3, (LPCTSTR)string[27 + (i - 5) * 3]);
	}



}

void CPlayerCardDlg::OnButtonExtend()
{
	// TODO: Add your control notification handler code here
	CPlayer m_player = avg.m_actual[m_player_index];
	m_player.SetTradeTrueRating(0);
	int t = m_player.m_current_team;


	avg.m_owner[t].CurrentPayroll(avg.m_actual, t * 30 + 1, true);
	for (int i = 0; i <= 6; i++)
	{
		avg.m_owner[t].m_temp_payroll[i] = avg.m_owner[t].m_current_payroll[i];
	}



	CNegotiateDlg* neg = new CNegotiateDlg;
	neg->game_season = avg.m_sched.m_games_in_season;
	neg->m_tru = avg.m_avg_trade_tru[0];
	neg->m_negotiate_extension = true;
	neg->m_number_teams = avg.m_settings.m_numberteams;

	CStaff coach = avg.m_coach[t];
	int coach_rating1 = (coach.m_pot1Rating + coach.m_pot2Rating + coach.m_effortRating + coach.m_scoringRating + coach.m_shootingRating + coach.m_reboundingRating + coach.m_passingRating + coach.m_defenseRating) * 1;
	int coach_rating2 = (coach.m_coachPot1 + coach.m_coachPot2 + coach.m_coachEffort + coach.m_coachScoring + coach.m_coachShooting + coach.m_coachRebounding + coach.m_coachPassing + coach.m_coachDefense) * 3;
	int coach_rating3 = (coach.m_coachO + coach.m_coachP + coach.m_coachI + coach.m_coachF + coach.m_coachOD + coach.m_coachPD + coach.m_coachID + coach.m_coachFD) * 3;
	int coach_rating4 = (coach.m_personality) * 24;
	neg->m_coach_rating = coach_rating1 + coach_rating2 + coach_rating3 + coach_rating4;



	neg->m_cap = int(avg.m_settings.m_cap);
	neg->m_player = m_player;
	neg->m_salary_cap = avg.m_finance[t].m_owner_salary_cap;
	if (avg.m_settings.m_financial_on == false) neg->m_salary_cap = 256000;

	neg->m_team_negotiating = t;
	avg.m_owner[t].CurrentPayroll(avg.m_actual, t * 30 + 1, true);//set team payroll
	neg->m_owner = avg.m_owner[t];
	neg->m_owner.m_temp_payroll[1] = avg.m_owner[t].m_current_payroll[1];
	neg->m_owner.SetPositionValues(avg.m_actual, t * 30 + 1, avg.m_coach[t]);
	for (int i = 0; i <= 32; i++)
	{
		neg->m_league_team_names[i] = avg.m_settings.m_leagueTeamNames[i];
	}

	int result = neg->DoModal();

	if (neg->m_signed_extension == true)
	{
		avg.m_actual[m_player_index] = neg->m_player;
		int ptr = avg.m_actual[m_player_index].m_player_pointer;
		//		avg.m_actual[ptr] = neg->m_player;
		avg.m_actual[m_player_index] = neg->m_player;
		avg.m_owner[t].CurrentPayroll(avg.m_actual, t * 30 + 1, true);





		avg.m_actual[m_player_index].m_is_free_agent = false;
		avg.m_actual[m_player_index].m_signed = true;
		int sal = 0;
		for (int y = 1; y <= avg.m_actual[m_player_index].m_contract_yrs; y++)
		{
			sal = sal + avg.m_actual[m_player_index].m_contract_salaries[y];
		}
		avg.m_actual[m_player_index].m_remaining_salary = sal;
		avg.m_actual[m_player_index].m_total_salary = sal;

		avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;


		CString string;
		int mo = avg.m_sched.m_currentMonth + 10;
		if (mo > 12) mo = mo - 12;
		int da = avg.m_sched.m_currentDay + 1;
		int yr = avg.m_settings.m_currentYear;
		int ty = 5;
		int team = avg.m_actual[m_player_index].m_current_team + 1;
		int id = avg.m_actual[m_player_index].m_id;
		int yr_ex = avg.m_actual[m_player_index].m_contract_yrs - 1;
		int sa_ex = avg.m_actual[m_player_index].m_remaining_salary - avg.m_actual[m_player_index].m_current_yr_salary;

		string.Format("%2d%2d%4d%2d%2d%6d%d%5d", mo, da, yr, ty, team, id, yr_ex, sa_ex);
		avg.m_trans_str[avg.m_settings.m_number_transactions] = string;



		Player();
		ListPlayerAwards();

	}
	else if (neg->m_content_changed == true)
	{
		avg.m_actual[m_player_index] = neg->m_player;
		Player();
		ListPlayerAwards();
	}
	else
		avg.m_actual[m_player_index].m_stop_negotiating = neg->m_player.m_stop_negotiating;

	delete neg;

}






HBRUSH CPlayerCardDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		//LOGBRUSH logbrush;
		//myBrush.GetLogBrush(&logbrush);
		pDC->SetTextColor(STATICCOLOR);
		pDC->SetBkColor(BUTTONFACECOLOR2);
		return myBrush;
	/*case CTLCOLOR_BTN:
		pDC->SetTextColor(RGB(0, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return myBrush;*/

	case CTLCOLOR_LISTBOX:
		pDC->SetBkColor(LISTBOXCOLOR);
		pDC->SetTextColor(LISTBOXTEXTCOLOR);
		return myBrush2;

	//case CTLCOLOR_SCROLLBAR:
	//	pDC->SetTextColor(RGB(0, 0, 0));
	//	pDC->SetBkColor(LISTBOXCOLOR);
	//	return myBrush;

	/*case CTLCOLOR_MSGBOX:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(255, 128, 128));
		return myBrush;*/

	case CTLCOLOR_DLG:
		return myBrush;
		//This shouldn't occurr since we took all the cases, but
		//JUST IN CASE, return the new brush
	default:
		return hbr;
	}
}

