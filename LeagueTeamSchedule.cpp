// LeagueTeamSchedule.cpp : implementation file
//

#include "stdafx.h"
//#include "bball.h"
#ifndef BBall_h
#include "BBall.h"
#define BBall_h
#endif // Added by ClassView
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "LeagueTeamSchedule.h"
#include "StatsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamSchedule dialog


CLeagueTeamSchedule::CLeagueTeamSchedule(CWnd* pParent /*=NULL*/)
	: CDialog(CLeagueTeamSchedule::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeagueTeamSchedule)
	//}}AFX_DATA_INIT

}


void CLeagueTeamSchedule::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeagueTeamSchedule)
	DDX_Control(pDX, IDC_LIST_CTRL_TEAM_SCH, m_listSchedule);
	DDX_Control(pDX, IDC_COMBO_LIST_TEAM, m_listTeam);
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button[0]);
	DDX_Control(pDX, IDOK, m_button[1]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeagueTeamSchedule, CDialog)
	//{{AFX_MSG_MAP(CLeagueTeamSchedule)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAM, OnSelchangeComboListTeam)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_TEAM_SCH, OnDblclkListCtrlTeamSch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamSchedule message handlers

BOOL CLeagueTeamSchedule::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	InitControls();

	myBrush.CreateSolidBrush(DLGCOLOR);

	for (int i = 0; i < 32; i++)
	{
		if (avg.m_settings.m_leagueTeamNames[i] != "") m_listTeam.AddString(avg.m_settings.m_leagueTeamNames[i]);
	}

	m_listTeam.SetCurSel(m_default_team);


	OnSelchangeComboListTeam();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



void CLeagueTeamSchedule::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
//	WinHelp(HID_LEAGUE_TEAMS);	
}

BOOL CLeagueTeamSchedule::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_LEAGUE_TEAMS);
//	return TRUE;
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsscheduler.htm", HH_DISPLAY_TOPIC, 0);

	return CDialog::OnHelpInfo(pHelpInfo);

}

void CLeagueTeamSchedule::OnButtonPrint()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	//initialize a structure for my font

	CString pBuf;
	CString teamName = avg.m_settings.m_leagueTeamNames[m_listTeam.GetCurSel()];
	HDC    hdcPrn;
	// Instantiate a CPrintDialog.
	CPrintDialog* printDlg = new CPrintDialog(FALSE, PD_ALLPAGES | PD_RETURNDC, NULL);
	// Initialize some of the fields in PRINTDLG structure.
	printDlg->m_pd.nMinPage = printDlg->m_pd.nMaxPage = 1;
	printDlg->m_pd.nFromPage = printDlg->m_pd.nToPage = 1;
	// Display Windows print dialog box.       
	printDlg->DoModal();
	// Obtain a handle to the device context.
	hdcPrn = printDlg->GetPrinterDC();
	if (hdcPrn != NULL)
	{
		CDC* pDC = new CDC;
		pDC->Attach(hdcPrn);      // attach a printer DC
		pDC->StartDoc("Playoff Results");  // begin a new print job
								// for Win32 use
								// CDC::StartDoc(LPDOCINFO) override
		pDC->StartPage();          // begin a new page
		SetPrintAlign(pDC, hdcPrn);// set the printing alignment

		LOGFONT logFont;
		logFont.lfHeight = 30;
		logFont.lfWidth = 0;
		logFont.lfEscapement = 0;
		logFont.lfOrientation = 0;
		logFont.lfWeight = 500;
		logFont.lfItalic = 0;
		logFont.lfUnderline = 0;
		logFont.lfStrikeOut = 0;
		logFont.lfCharSet = ANSI_CHARSET;
		logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
		logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		logFont.lfQuality = PROOF_QUALITY;
		logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
		strcpy_s(logFont.lfFaceName, USERFONT);

		CFont font;
		font.CreateFontIndirect(&logFont);
		CFont* oldFont = pDC->SelectObject(&font);

		//		pBuf = "Name               g  mpg  fgm  fga   fg% 3gm  3ga   3g%  ftm  fta   ft%   ppg";
		//		pBuf = "Name               pos  2ga  2g%  fta  ft%  3ga  3g%  orb  drb  ast  stl  to   blk";
		pBuf = teamName + " Schedule Results";
		pDC->TextOut(-900, 1000, pBuf);// write the string in pbuf
		int items = m_listSchedule.GetItemCount();
		int row = 950;
		int col = -900;
		int onePage = 0;
		for (int i = 1; i <= items; i++)
		{
			pBuf = m_strings[i - 1];
			//			m_listSchedule.GetText(i-1, pBuf);
			pDC->TextOut(col, row, pBuf);// write the string in pbuf
			row = row - 25;
			onePage = onePage + 1;
			if (onePage == 76)
			{
				col = col + 600;
				if (col == 900)
				{
					col = -900;
					pDC->EndPage();            // end a page
					pDC->StartPage();            // end a page
				}
				pBuf = teamName + " Schedule Results";
				pDC->TextOut(col, 1000, pBuf);// write the string in pbuf
				row = 950;
				onePage = 0;
			}

		}

		pDC->EndPage();            // end a page
		pDC->EndDoc();             // end a print job
		pDC->Detach();             // detach the printer DC
		delete pDC;
	}
	delete printDlg;

}

void CLeagueTeamSchedule::SetPrintAlign(CDC* pDC, HDC hdcPrn)
{
	short cxPage, cyPage;
	cxPage = ::GetDeviceCaps(hdcPrn, HORZRES);
	cyPage = ::GetDeviceCaps(hdcPrn, VERTRES);

	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(1000, 1000);

	pDC->SetViewportExt(cxPage / 2, -cyPage / 2);
	pDC->SetViewportOrg(cxPage / 2, cyPage / 2);
	pDC->SetTextAlign(TA_BASELINE);
}



HBRUSH CLeagueTeamSchedule::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		 //This shouldn't occurr since we took all the cases, but
		 //JUST IN CASE, return the new brush
		 default:
		      return hbr;
		 } 


	return hbr;
}

void CLeagueTeamSchedule::OnSelchangeComboListTeam()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CString
		months[] = { "Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep" };
	int t = m_listTeam.GetCurSel() + 1;
	m_listSchedule.DeleteAllItems();
	int win = 0;
	int loss = 0;
	int lines = 1;
	int row = 0;
	for (int i = 0; i <= 100; i++)
	{
		m_mo_list[i] = 0;
		m_da_list[i] = 0;
		m_ga_list[i] = 0;
		m_v_list[i] = 0;
	}

	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			CString month = months[i];
			int d = j + 1;
			CString day;
			day.Format("%d", d);
			CString date;
			CString Opponent;
			CString result;
			CString other;
			CString sc;
			CString rs;
			CString res;
			date = month + "" + day;

			for (int k = 0; k <= 15; k++)
			{
				int road = 1;
				CString visitor;
				CString home;
				CString visitorScore;
				CString homeScore;
				Opponent = "";
				result = "";
				int v = 0, h = 0, vs = 0, hs = 0, game = 0, score = 0;
				v = avg.m_sched.m_schedule[i][j][k] / 100;
				h = avg.m_sched.m_schedule[i][j][k] - v * 100;
				vs = avg.m_sched.m_game_score[i][j][k] / 1000;
				hs = avg.m_sched.m_game_score[i][j][k] - vs * 1000;
				visitorScore.Format("%d", vs);
				homeScore.Format("%d", hs);
				if (vs == 0 && hs == 0 && v >= 1 && h >= 1 && (v == t || h == t))
				{
					visitorScore = "";
					homeScore = "";
					visitor = avg.m_settings.m_leagueTeamNames[v - 1];
					home = avg.m_settings.m_leagueTeamNames[h - 1];
					result = date + "  " + "@" + home;
					other = "@" + home;
					if (v != t)
					{
						result = date + " " + visitor;
						other = visitor;
						road = 0;
					}
					Opponent.Format("%s", result);

				}
				else if (v >= 1 && h >= 1 && v == t)
				{
					visitor = avg.m_settings.m_leagueTeamNames[v - 1];
					home = avg.m_settings.m_leagueTeamNames[h - 1];
					result = date + "  " + "@" + home + "  " +
						visitorScore + "-" + homeScore;
					other = "@" + home;
					sc = visitorScore + "-" + homeScore;
					if (vs < hs)
					{
						loss = loss + 1;
						result = result + "  L";
						res = "loss";
					}
					else if (vs > hs)
					{
						win = win + 1;
						result = result + "  W";
						res = "win";

					}
					Opponent.Format("%s (%d-%d)", result, win, loss);
				}
				else if (v >= 1 && h >= 1 && h == t)
				{
					visitor = avg.m_settings.m_leagueTeamNames[v - 1];
					home = avg.m_settings.m_leagueTeamNames[h - 1];
					result = date + "  " + visitor + "  " +
						homeScore + "-" + visitorScore;
					other = visitor;
					sc = homeScore + "-" + visitorScore;
					if (vs < hs)
					{
						result = result + "  W";
						res = "win";
						win = win + 1;
					}
					else if (vs > hs)
					{
						result = result + "  L";
						res = "loss";
						loss = loss + 1;
					}
					Opponent.Format("%s (%d-%d)", result, win, loss);
					road = 0;
				}

				if (Opponent != "")
				{
					CString r = "";
					if (sc != "") r.Format("%d-%d", win, loss);
					m_listSchedule.InsertItem(row, date);
					m_listSchedule.SetItemText(row, 1, other);
					m_listSchedule.SetItemText(row, 2, sc);
					m_listSchedule.SetItemText(row, 3, res);
					m_listSchedule.SetItemText(row, 4, r);
					m_mo_list[row] = i;
					m_da_list[row] = j;
					m_ga_list[row] = k;
					m_v_list[row] = road;
					m_strings[row] = Opponent;
					row = row + 1;
				}
			}
		}
	}
	//_listSchedule.SetCurSel(lines-1);
	m_listSchedule.SetItemState(lines - 1, LVIS_SELECTED, LVIS_SELECTED);
	m_listSchedule.SetItemState(lines - 1, LVIS_FOCUSED, LVIS_FOCUSED);
	m_listSchedule.EnsureVisible(lines, TRUE);

	int ga_left = m_listSchedule.GetItemCount() - (win + loss);
	CString h_team = avg.m_settings.m_leagueTeamNames[t - 1];
	CString head;
	if (ga_left <= 0) head.Format("%s schedule", h_team);
	else if (ga_left == 1) head.Format("%s schedule (%d game remaining)", h_team, ga_left);
	else head.Format("%s schedule (%d games remaining)", h_team, ga_left);

	SetWindowText(head);
	UpdateData(FALSE);
}

void CLeagueTeamSchedule::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 15;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_listSchedule.SetBkColor(BK_COLOR);
	m_listSchedule.SetTextBkColor(TEXT_BK_COLOR);
	m_listSchedule.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listSchedule.SetTextColor(RGB(0, 0, 0));
	m_listSchedule.SetFont(&m_font);


	m_listSchedule.DeleteColumn(0);
	m_listSchedule.InsertColumn(0, "date");
	m_listSchedule.DeleteColumn(1);
	m_listSchedule.InsertColumn(1, "opponent");
	m_listSchedule.DeleteColumn(2);
	m_listSchedule.InsertColumn(2, "score");
	m_listSchedule.DeleteColumn(3);
	m_listSchedule.InsertColumn(3, "result");
	m_listSchedule.DeleteColumn(4);
	m_listSchedule.InsertColumn(4, "record");

	m_listSchedule.SetColumnWidth(0, 80);
	m_listSchedule.SetColumnWidth(1, 104);
	m_listSchedule.SetColumnWidth(2, 64);
	m_listSchedule.SetColumnWidth(3, 64);
	m_listSchedule.SetColumnWidth(4, 64);
}

void CLeagueTeamSchedule::OnDblclkListCtrlTeamSch(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int ro = m_listSchedule.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (ro < 0) ro = 0;

	CStatsDlg* stats = new CStatsDlg;
	int month = m_mo_list[ro];
	int day = m_da_list[ro];
	int game = m_ga_list[ro];
	int v = m_v_list[ro];
	stats->m_saved_box = true;
	stats->m_mo = month;
	stats->m_da = day;
	stats->m_ga = game;
	//stats->avg = avg;
	stats->SetPtr(avg);

	if (v == 1) stats->m_v_click = true;
	else stats->m_v_click = false;
	stats->DoModal();
	delete stats;
	*pResult = 0;
}
