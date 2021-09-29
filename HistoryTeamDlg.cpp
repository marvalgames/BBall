// HistoryTeamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "HistoryTeamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryTeamDlg dialog


CHistoryTeamDlg::CHistoryTeamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryTeamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryTeamDlg)
	//}}AFX_DATA_INIT
}


void CHistoryTeamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryTeamDlg)
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_LIST_RINGS, m_listRings);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_listHistory);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryTeamDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryTeamDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryTeamDlg message handlers


void CHistoryTeamDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_HISTORY_TEAM);	
//	return TRUE;		
	
}

BOOL CHistoryTeamDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_HISTORY_TEAM);	
//	return TRUE;		
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

BOOL CHistoryTeamDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
 myBrush.CreateSolidBrush(DLGCOLOR); 
myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	bool exists = true;
	CFileStatus status;
	CString pFileName = m_path + m_leagueName + ".his";

	if( CFile::GetStatus( pFileName, status ) == 0) exists = 0;

	if(exists == true)
		ListTeams();
	else
		m_listRings.AddString("No seasons completed");
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHistoryTeamDlg::ListTeams()
{
	for(int i=0; i<=32; i++)
	{
		if(m_leagueTeamNames[i] != "")
			m_listTeams.AddString(m_leagueTeamNames[i]);
	}
	m_listTeams.SetCurSel(m_default_team);
	FillHistory();
}

void CHistoryTeamDlg::FillHistory()
{
    int rings = 0;
    int finals = 0;
	int playoffs = 0;
	m_listHistory.ResetContent();
	CString selectedTeam;
	int index = m_listTeams.GetCurSel();
	m_listTeams.GetLBText(index, selectedTeam);

	CString pFileName = m_path + m_leagueName + ".his";
	CString string;
  	CStdioFile file(pFileName, CFile::modeRead);
	int t_w = 0;
	int t_l = 0;
	do
	{
		file.ReadString(string);
		string.TrimLeft();
		string.TrimRight();
	

		int pos = string.Find('(');
		int pos1 = string.Find(')');
		int pos2 = -1;
		do
		{

			pos2 = string.Find('-');

		}
		while(pos2 <= pos && pos > 0);

		CString team = string.Left(pos-1);
		if(team == selectedTeam)
		{

		if(pos2 > 2)
		{
			
			CString wins = string.Mid(pos+1,pos2-pos-1);
			CString losses = string.Mid(pos2+1,pos1-pos2-1);
			t_w = t_w + atoi(wins);
			t_l = t_l + atoi(losses);

		}
		}

		if(team == selectedTeam)
		{
			m_listHistory.AddString(string);
			int pos1 = string.Find("championship");
			if(pos1 >= 0) finals = finals + 1;

			int pos2 = string.Find("lose");
			int pos3 = string.Find("defeat");
			if(pos2 >= 0 || pos3 >= 0) playoffs = playoffs + 1;
			if(pos3 >= 0) rings = rings + 1;
		}
	}
	while(string != "");
	file.Close();
	int count = m_listHistory.GetCount()-1;
	m_listHistory.SetCurSel(count);
	CString ringString;
	ringString.Format("Championships: %d", rings);
	CString playoffString;
	playoffString.Format("Playoffs: %d", playoffs);
	CString finalsString;
	finalsString.Format("Finals: %d", finals);
	m_listRings.ResetContent();
	m_listRings.AddString(ringString);
	m_listRings.AddString(finalsString);
	m_listRings.AddString(playoffString);

	CString winString;
	winString.Format("Wins:  %d", t_w);
	CString lossString;
	lossString.Format("Losses:  %d", t_l);

	double win_pct = 0;
	if((t_w + t_l) > 0) 
		win_pct = double(t_w) / (double(t_l) + double(t_w)) * 100;
	CString pctString;
	pctString.Format("Win Pct:  %.2f", win_pct);

	double grade = 0;
	grade = win_pct * ((double)playoffs * 1) + ((double)finals * 4) + ((double)rings * 16) ;
	CString gradeString;
	gradeString.Format("Franchise Score:  %.2f", grade);

	m_listRings.AddString("");
	m_listRings.AddString(winString);
	m_listRings.AddString(lossString);
	m_listRings.AddString(pctString);
	m_listRings.AddString(gradeString);

}

HBRUSH CHistoryTeamDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CHistoryTeamDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	FillHistory();		
}
