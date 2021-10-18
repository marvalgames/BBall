// AutoSchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"

#include "AutoSchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoSchDlg dialog


CAutoSchDlg::CAutoSchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoSchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoSchDlg)
	//}}AFX_DATA_INIT
	//#include <time.h>
	srand( (unsigned)time( NULL ) );
	for(int i=0; i<=3650; i++)
	{
		m_schedule[i] = 0;
	}
}


void CAutoSchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoSchDlg)
	DDX_Control(pDX, IDC_LIST_OTHER_CONFERENCE, m_listOtherConf);
	DDX_Control(pDX, IDC_LIST_DIVISION, m_listDiv);
	DDX_Control(pDX, IDC_LIST_OTHER, m_listOther);
	DDX_Control(pDX, IDC_LIST_CONFERENCE, m_listConf);
	DDX_Control(pDX, IDC_BUTTON_CREATE, m_button[0]);
	DDX_Control(pDX, IDCANCEL, m_button[1]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutoSchDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoSchDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoSchDlg message handlers

BOOL CAutoSchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	LoadLeagueFormat();
	SetListBoxes();
	CreateTables();
//	m_currentGame = 0;
//	UpdateData(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAutoSchDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_AUTO_SCHEDULE);	
//	return TRUE;		


	


}

BOOL CAutoSchDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/afxc3ant.htm", HH_DISPLAY_TOPIC, 0);
	
//	WinHelp(HID_AUTO_SCHEDULE);	
//	return TRUE;		
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CAutoSchDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CAutoSchDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CAutoSchDlg::LoadLeagueFormat()
{
		if(m_divisionName1 == "") m_divisionName1 = "Atlantic";
		if(m_divisionName2 == "") m_divisionName2 = "Central";
		if(m_divisionName3 == "") m_divisionName3 = "Midwest";
		if(m_divisionName4 == "") m_divisionName4 = "Pacific";
		if(m_conferenceName1 == "") m_conferenceName1 = "Eastern";
		if(m_conferenceName2 == "") m_conferenceName2 = "Western";
	
}	




void CAutoSchDlg::SetListBoxes()
{
	m_listConf.AddString("0");
	m_listConf.AddString("2");
	m_listConf.AddString("4");
	m_listConf.AddString("6");
	m_listConf.AddString("8");


	m_listDiv.AddString("0");
	m_listDiv.AddString("2");
	m_listDiv.AddString("4");
	m_listDiv.AddString("6");
	m_listDiv.AddString("8");

	m_listOtherConf.AddString("0");
	m_listOtherConf.AddString("2");
	m_listOtherConf.AddString("4");
	m_listOtherConf.AddString("6");
	m_listOtherConf.AddString("8");

	for(int i=2; i<=98; i=i+2)
	{
		CString number;
		number.Format("%d", i);
		m_listOther.AddString(number);
	}
	m_listDiv.SetCurSel(2);
	m_listConf.SetCurSel(1);
	m_listOtherConf.SetCurSel(1);
	m_listOther.SetCurSel(40);

}

void CAutoSchDlg::CreateTables()
{
	m_division1Teams = 0;
	m_division2Teams = 0;
	m_division3Teams = 0;
	m_division4Teams = 0;
	m_conference1Teams = 0;
	m_conference2Teams = 0;

	for(int i=0; i<=4; i++)
	{
		for(int j=0; j<=32; j++)
		{
			m_divisionTable[i][j] = 0;
		}
	}
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=32; j++)
		{
			m_conferenceTable[i][j] = 0;
		}
	}
	for(int i=1; i<=32; i++)
	{
		if(m_division[i] == m_divisionName1)
		{
			m_division1Teams = m_division1Teams + 1;
			m_divisionTable[1][m_division1Teams] = i;
		}
		else if(m_division[i] == m_divisionName2)
		{
			m_division2Teams = m_division2Teams + 1;
			m_divisionTable[2][m_division2Teams] = i;
		}
		else if(m_division[i] == m_divisionName3)
		{
			m_division3Teams = m_division3Teams + 1;
			m_divisionTable[3][m_division3Teams] = i;
		}
		else if(m_division[i] == m_divisionName4)
		{
			m_division4Teams = m_division4Teams + 1;
			m_divisionTable[4][m_division4Teams] = i;
		}


		if(m_conference[i] == m_conferenceName1)
		{
			m_conference1Teams = m_conference1Teams + 1;
			m_conferenceTable[1][m_conference1Teams] = i;
		}
		else if(m_conference[i] == m_conferenceName2)
		{
			m_conference2Teams = m_conference2Teams + 1;
			m_conferenceTable[2][m_conference2Teams] = i;
		}

	}
}


void CAutoSchDlg::CreateDivisionMatchups(int m_divisionTeams, int division)
{
	int times = m_listDiv.GetCurSel();
	for(int t=1; t<=times; t++)
	{
		for(int i=1; i<=m_divisionTeams; i++)
		{
			for(int j=1; j<=m_divisionTeams; j++)
			{
				if(i==j) continue;
				m_currentGame = m_currentGame + 1;
				int tempi = m_divisionTable[division][i];
				int tempj = m_divisionTable[division][j];
				m_schedule[m_currentGame] = tempi*100 + tempj;
				m_gamesPlayed[tempi] = m_gamesPlayed[tempi] + 1;
				m_gamesPlayed[tempj] = m_gamesPlayed[tempj] + 1;

			}
		}
	}
}

void CAutoSchDlg::CreateOtherDivisionMatchups(int division1Teams, int division2Teams, int division1, int division2)
{
	int times = m_listConf.GetCurSel();
	for(int t=1; t<=times; t++)
	{

		for(int i=1; i<=division1Teams; i++)
		{
			for(int j=1; j<=division2Teams; j++)
			{
				m_currentGame = m_currentGame + 1;;
				int tempi = m_divisionTable[division1][i];
				int tempj = m_divisionTable[division2][j];
				m_schedule[m_currentGame] = tempi*100 + tempj;
				m_gamesPlayed[tempi] = m_gamesPlayed[tempi] + 1;
				m_gamesPlayed[tempj] = m_gamesPlayed[tempj] + 1;
			}
		}
	}
}

void CAutoSchDlg::CreateOtherConferenceMatchups(int division1Teams, int division2Teams, int division1, int division2)
{
	int times = m_listOtherConf.GetCurSel();
	for(int t=1; t<=times; t++)
	{

		for(int i=1; i<=division1Teams; i++)
		{
			for(int j=1; j<=division2Teams; j++)
			{
				m_currentGame = m_currentGame + 1;;
				int tempi = m_conferenceTable[division1][i];
				int tempj = m_conferenceTable[division2][j];
				m_schedule[m_currentGame] = tempi*100 + tempj;
				m_gamesPlayed[tempi] = m_gamesPlayed[tempi] + 1;
				m_gamesPlayed[tempj] = m_gamesPlayed[tempj] + 1;
				m_schedule[m_currentGame] = tempi*100 + tempj;
			}
		}
	}
}


void CAutoSchDlg::OnButtonCreate() 
{
	// TODO: Add your control notification handler code here
	for(int i=0; i<=32; i++)
	{
		m_gamesPlayed[i] = 0;
	}
	m_currentGame = 0;
	CreateDivisionMatchups(m_division1Teams, 1);
	CreateDivisionMatchups(m_division2Teams, 2);
	CreateDivisionMatchups(m_division3Teams, 3);
	CreateDivisionMatchups(m_division4Teams, 4);
	CreateOtherDivisionMatchups(m_division1Teams, m_division2Teams, 1, 2);
	CreateOtherDivisionMatchups(m_division2Teams, m_division1Teams, 2, 1);
	CreateOtherDivisionMatchups(m_division3Teams, m_division4Teams, 3, 4);
	CreateOtherDivisionMatchups(m_division4Teams, m_division3Teams, 4, 3);
	CreateOtherConferenceMatchups(m_conference1Teams, m_conference2Teams, 1, 2);
	CreateOtherConferenceMatchups(m_conference2Teams, m_conference1Teams, 2, 1);
	SetOtherGames();
if(m_unable == false)
{	
	ScrambleTeams();
	SetSchedule();

	if(m_unable == false)
	{
		CString message, string;
		string.Format("%d", m_seasonGames);
		AfxFormatString1( message, IDS_STRING_MESSAGE_AUTO_SCHEDULE, string); 
 		MessageBox(message, MB_OK);		
		CDialog::OnOK();
	}
}


if(m_unable == true)
 		MessageBox("Computer is unable to generate a schedule for the current setup.", MB_OK);		

}



int CAutoSchDlg::IntRandom(int n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return (int)number + 1;
}




void CAutoSchDlg::SetOtherGames()
{
	int playedOnce[33];
	bool played[33][33];
	int homeGamesLeft[33];
	int roadGamesLeft[33];
	int gamesLeft[33];
	
	int seasonGames = (m_listOther.GetCurSel() + 1) * 2;

	int hiG = 0;
	teams = 0;
	for(int i=1; i<=32; i++)
	{
		for(int j=1; j<=32; j++)
		{
			played[i][j] = false;
		}
	}
	for(int  i=1; i<=32; i++)
	{
		if(m_gamesPlayed[i] > hiG) hiG = m_gamesPlayed[i];
		playedOnce[i] = 0;
	}
	if(hiG > seasonGames) seasonGames = hiG;
	for(int i=1; i<=32; i++)
	{
		if(m_leagueTeamNames[i] == "")
		{
			gamesLeft[i] = 0;
			roadGamesLeft[i] = 0;
			homeGamesLeft[i] = 0;
		}
		else
		{
			gamesLeft[i] = seasonGames - m_gamesPlayed[i];
			roadGamesLeft[i] = gamesLeft[i]/2;
			homeGamesLeft[i] = roadGamesLeft[i];
			teams = teams + 1;
		}
	}
	bool ok = false;
	if(seasonGames > 98) seasonGames = 98;
	int totalGames = seasonGames*teams/2;
	m_seasonGames = seasonGames;
	int conf1t = 0, conf2t = 0;
	for(int i=1; i<=m_conference1Teams; i++)
	{
		if(m_gamesPlayed[i] < seasonGames) conf1t = conf1t + 1;
	}
	for(int i=m_conference1Teams+1; i<= teams; i++)
	{
		if(m_gamesPlayed[i] < seasonGames) conf2t = conf2t + 1;
	}

	int last_games = 0;

	for(int x=1; x<=5000; x++)
	{
//		if(m_currentGame == totalGames) continue;
	for(int tt1=1; tt1<=teams; tt1++)
		{
			for(int tt2=1; tt2<=teams; tt2++)
			{
				ok = true;





				int t1 = tt1;
				int t2 = tt2;



				int cur1 = 0;//current conf
				int cur2 = 0;//current conf
				int factor1 = 0;
				int factor2 = 0;
				int d1 = m_division1Teams;
				int d2 = d1 + m_division2Teams;
				int d3 = d2 + m_division3Teams;
				int d4 = d3 + m_division4Teams;

				if(tt1 <= d1)
				{
					cur1 = 1;
					factor1 = 0;
				}
				else if(tt1 <= d2)
				{
					cur1 = 2;
					factor1 = d1;
				}
				else if(tt1 <= d3)
				{
					cur1 = 3;
					factor1 = d2;
				}
				else if(tt1 <= d4)
				{
					cur1 = 4;
					factor1 = d3;
				}


				if(tt2 <= d1)
				{
					cur2 = 1;
					factor2 = 0;
				}
				else if(tt2 <= d2)
				{
					cur2 = 2;
					factor2 = d1;
				}
				else if(tt2 <= d3)
				{
					cur2 = 3;
					factor2 = d2;
				}
				else if(tt2 <= d4)
				{
					cur2 = 4;
					factor2 = d3;
				}





				t1 = m_divisionTable[cur1][tt1 - factor1];
				t2 = m_divisionTable[cur2][tt2 - factor2];

				if(t1 == t2) ok = false;
				if(roadGamesLeft[t1] == 0 || homeGamesLeft[t2] == 0)
					ok = false;
				else if(m_conference[t1] != m_conference[t2])
					ok = false;
				else if(played[t1][t2] == true || played[t2][t1] == true)
					ok = false;
				if(ok == true && m_currentGame < totalGames)
				{
					int conf1 = conf1t - 1;
					int conf2 = conf2t - 1;
					if(tt1 > m_conference1Teams) conf1 = conf2;
					if(tt2 <= m_conference1Teams) conf2 = conf1;
					roadGamesLeft[t1] = roadGamesLeft[t1] - 1;
					homeGamesLeft[t2] = homeGamesLeft[t2] - 1;
					m_currentGame = m_currentGame + 1;

				



					m_schedule[m_currentGame] = t1*100+t2;
					m_gamesPlayed[t1] = m_gamesPlayed[t1] + 1;
					m_gamesPlayed[t2] = m_gamesPlayed[t2] + 1;
					playedOnce[t1] = playedOnce[t1] + 1;
					playedOnce[t2] = playedOnce[t2] + 1;
					played[t1][t2] = true;
					played[t2][t1] = true;

					if(playedOnce[t1] == conf1)
					{
			 			playedOnce[t1] = 0;
						for(int t=1; t<=32; t++)
						{
							played[t1][t] = false;
						}
					}
					if(playedOnce[t2] == conf2)
					{
						playedOnce[t2] = 0;
						for(int t=1; t<=32; t++)
						{
							played[t2][t] = false;
						}
					}
				}
			}
//		
	}


	if(m_currentGame == last_games)
	{
		for(int i=1; i<=32; i++)
		{
			for(int j=1; j<=32; j++)
			{
				played[i][j] = false;
			}
		}
		for(int  i=1; i<=32; i++)
		{
			playedOnce[i] = 0;
		}
	}

	last_games = m_currentGame;


	}
	if(m_currentGame != totalGames) m_unable = true; else m_unable = false;
	
	
//	while (m_currentGame != totalGames)
}

void CAutoSchDlg::SetSchedule()
{
	int sch[14][33];
	int t_sch[14][33][17];
	bool used[33], scramble[14][33];
	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=32; j++)
		{
				sch[i][j] = 0;
				scramble[i][j] = false;

			for(int k=0; k<=15; k++)
			{
				m_sch[i][j][k] = 0;
				t_sch[i][j][k] = 0;
			}
		}
	}


	bool played[3651];
	int temp[33];


	for(int g=0; g<=m_currentGame; g++)
	{
		played[g] = false;
	}
	
	for(int g=0; g<=32; g++)
	{
		temp[g] = 0;
		used[g] = false;
	}

    int games = teams/4;
	if(games<1)games = 1;
	int gamesPlayed = 0;
	int endMonth = 0; int endDay = 0; int endGame = 0;
	int last = 0, current = 0;
	bool invalid = false;
	int allstardays = 0;
	int allstarbreak = int(45. / 82. * (double) m_currentGame);

	int te_count = 0;
	do
	{
	
		for(int i=0; i<=12; i++){
				int mo = i + m_currentMonth;
				if(mo > 11) mo = 11;

			for(int j=0; j<=30; j++){


				int da = j;
				if(i == 0 && j < m_currentDay) continue; 				
				else if((mo==1 || mo==6 || mo==8 || mo==11) && da > 29) continue;
				else if(mo==4 && (da > 27 || da == 2)) continue;
				else if(invalid == true) continue;

				if(gamesPlayed > allstarbreak && allstardays == 0 && da < 24)
					allstardays = allstardays + 1;
				else if(gamesPlayed > allstarbreak && allstardays > 0)
					allstardays = allstardays + 1;

				if(allstardays >= 1 && allstardays <= 3) continue;

				
				int ga = 1;
	for(int g=1; g<=m_currentGame; g++)
	{
		int t1 = m_schedule[g]/100;
		int t2 = m_schedule[g] - t1*100;
		if(used[t1] == false && used[t2] == false &&
			gamesPlayed != m_currentGame && played[g] == false && ga <=games && temp[t1] < 100 && temp[t2] < 100)
		{
			endMonth = i; endGame = ga;
			endDay = j;
			used[t1] = true;
			used[t2] = true;
			temp[t1] = temp[t1]+1;
			temp[t2] = temp[t2]+1;
			gamesPlayed = gamesPlayed+1;
			t_sch[i][j][ga] = t1*100+t2;
			played[g] = true;
			ga = ga+1;
		}
	}

	for(int t=0; t<=32; t++)
	{
		used[t] = false;
	}
		
		current = gamesPlayed;
		if(current == last && gamesPlayed != m_currentGame) 
		{
			invalid = true;
			m_unable = true;
		}
		last = current;

		}



		}


	}while(gamesPlayed != m_currentGame && invalid == false);

if(invalid == false)
{
	int n=0, o=0;
	for(int i=0; i<=11; i++)
	{
		int mo = i + m_currentMonth;
		if(mo > 11) mo = 11;

		if(i > endMonth) continue;
		for(int j=0; j<=30; j++)
		{
				int da = j;
			if(i == 0 && j < m_currentDay) continue; 				
			else if(endMonth == i && j > endDay) continue; 
			else if(t_sch[i][j][1] == 0) continue;//no games this day
			else if((mo==1 || mo==6 || mo==8 || mo==11) && da > 29) continue;
			else if(mo==4 && (da > 27 || da == 2)) continue;

			bool ok = true; int nm=0; int od = 0;
		do
		{
			nm= IntRandom(13)-1;
			od = IntRandom(31)-1;
			int nm = n + m_currentMonth;
			if(nm > 11) nm = 11;
			int od = o + m_currentDay;
			if(od > 30) od = 30;

			if((nm==1 || nm==6 || nm==8 || nm==11) && od > 29) ok = false;
			else if(nm == 0 && od < m_currentDay) continue; 				
			else if(nm==4 && od > 27) ok = false;
			else if(n > endMonth  || (n == endMonth && o > endDay)) ok = false;
		}
		while(scramble[nm][od] == true || t_sch[nm][od][1] == 0 || ok == false) ;
		scramble[nm][od] = true;
		sch[i][j] = nm*100+od;
	}
}




	for(int i=0; i<=11; i++)
	{
		if(i > endMonth) continue;
		for(int j=0; j<=30; j++)
		{
				int mo = i + m_currentMonth;
				if(mo > 11) mo = 11;
				int da = j;

			if(endMonth == i && j > endDay) continue; 
			else if(mo == 0 && da < m_currentDay) continue; 				
			else if((mo==1 || mo==6 || mo==8 || mo==11) && da > 29) continue;
			else if(mo==4 && da > 27) continue;

				int n = sch[i][j]/100;
				int o = sch[i][j] - n*100;
			for(int k=1; k<=games; k++)
			{
				m_sch[mo][da][k-1] = t_sch[n][o][k];
				//if(t_sch[n][o][k] > 0) te_count = te_count + 1;
				int t1 = t_sch[n][o][k]/100;
				int t2 = t_sch[n][o][k] - t1*100;
				temp[t1] = temp[t1]+1;
				temp[t2] = temp[t2]+1;
			}
		}
	}
}  
}

void CAutoSchDlg::ScrambleTeams()
{
	
	bool scramble[33], scrambleGames[1651];
	int m_newTeams[33], m_newGames[1651];
	int n = 0;
	for(int t=0; t<=32; t++)
	{
		scramble[t] = false;
		m_newTeams[t] = 0;
	}

	
	for(int t=1; t<=m_division1Teams; t++)
	{
	
		do
		{
			n = IntRandom(m_division1Teams);
		}
		while(scramble[n] == true);
		scramble[n] = true;
		m_newTeams[t] = m_divisionTable[1][n];
//		m_newTeams[t] = n;
	}
	int start =  m_division1Teams + 1;
	for(int t=start; t<=start + (m_division2Teams-1); t++)
	{
	
		do
		{
			n = IntRandom(m_division2Teams) + (start-1);
		}
		while(scramble[n] == true);
		scramble[n] = true;
		m_newTeams[t] =  m_divisionTable[2][n - (start-1)];
	}
	start = start + m_division2Teams;
	for(int t=start; t<=start+(m_division3Teams-1); t++)
	{
	
		do
		{
			n = IntRandom(m_division3Teams) + (start-1);
		}
		while(scramble[n] == true);
		scramble[n] = true;
		m_newTeams[t] =  m_divisionTable[3][n - (start-1)];
	}
	start =  start + m_division3Teams;
	for(int t=start; t<=start + (m_division4Teams-1); t++)
	{
	
		do
		{
			n = IntRandom(m_division4Teams) + (start-1);
		}
		while(scramble[n] == true);
		scramble[n] = true;
		m_newTeams[t] =  m_divisionTable[4][n - (start-1)];
	}
    
	for(int t=0; t<=m_currentGame; t++)
	{
		scrambleGames[t] = false;
		m_newGames[t] = 0;
	}

    for(int t=1; t<=m_currentGame; t++)
	{
		do
		{
			n = IntRandom(m_currentGame);
		}
		while(scrambleGames[n] == true);
		scrambleGames[n] = true;
		m_newGames[t] = n;
	}


    int temp[33];
	for(int t=0; t<=32; t++)
	{
		temp[t] =0;
	}

    for(int t=1; t<=m_currentGame; t++)
	{
	
		int oldT1 = m_schedule[t]/100;
		int oldT2 = m_schedule[t] - oldT1*100;
//		int slot = m_newGames[t];
//		int t1 = m_newTeams[oldT1];
//		int t2 = m_newTeams[oldT2];
		int t1 = oldT1;
		int t2 = oldT2;
		m_schedule[t] = t1*100+t2;
	}
	int sch[1651];
	int co[33][33];
	for(int t=0; t<=32; t++)
	{
		for(int u=0; u<=32; u++)
		{

				co[t][u] = 0;
		}
	}


    for(int t=1; t<=m_currentGame; t++)
	{
	
		int slot = m_newGames[t];
		int t1 = m_schedule[slot]/100;
		int t2 = m_schedule[slot] - t1*100;
		temp[t1]=temp[t1]+1;
		temp[t2]=temp[t2]+1;
		sch[t] = t1*100+t2;
		co[t1][t2] = co[t1][t2] + 1;
		co[t2][t1] = co[t2][t1] + 1;
	}

	

    for(int t=1; t<=m_currentGame; t++)
	{
		m_schedule[t] = sch[t];
	}
}

HBRUSH CAutoSchDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

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
		  //pDC->SetTextColor(WHITE);
		  pDC->SetBkColor(logbrush.lbColor);
		  //pDC->SetBkColor(BLACK);
		  return myBrush;
     case CTLCOLOR_BTN:
          pDC->SetTextColor(RGB(0,255,255));
          pDC->SetBkColor(RGB(255,128,128));
          return myBrush;
     //case CTLCOLOR_LISTBOX:
       //   pDC->SetBkColor(LISTBOXCOLOR);
         // pDC->SetTextColor(LISTBOXTEXTCOLOR);
          //return myBrush;


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
