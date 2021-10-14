// StatsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
//#include "constants.h"
//#include "resource.h"

#include "StatsDlg.h"
#include "BoxScore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatsDlg dialog



CStatsDlg::CStatsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatsDlg)
	m_edit_att = 0;
	m_edit_cap = 0;
	//}}AFX_DATA_INIT
	//int m_quarter_score[3][6];
	//int m_running_total[3][6];
	//int m_score[3];
	//m_avg = NULL;


	for(int i=0; i<=2; i++)
	{
		m_score[i] = 0;
	for(int j=0; j<=5; j++)
	{
		m_running_total[i][j] = 0;
		m_quarter_score[i][j] = 0;

	}
	}

	for(int j=0; j<=60; j++)
	{
		m_playing_players_list[j] = 0;
	}


	m_game_type = LEAGUE;
}


void CStatsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatsDlg)
	DDX_Control(pDX, IDC_BUTTON_PBP, m_button_pbp);
	DDX_Control(pDX, IDC_LIST_PCT, m_list_pct);
	DDX_Control(pDX, IDC_LIST_SCORES, m_list_scores);
	DDX_Control(pDX, IDC_LIST_STATS, m_list_stats);
	DDX_Control(pDX, IDH_BUTTON_VISITOR, m_buttonVisitor);
	DDX_Control(pDX, IDH_BUTTON_HOME, m_buttonHome);
	DDX_Control(pDX, IDOK, m_buttonOk);
	DDX_Control(pDX, IDC_BUTTON_PRNT, m_buttonPrint);
	DDX_Text(pDX, IDC_EDIT_ATT, m_edit_att);
	DDV_MinMaxUInt(pDX, m_edit_att, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_CAP, m_edit_cap);
	DDV_MinMaxUInt(pDX, m_edit_cap, 0, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatsDlg, CDialog)
	//{{AFX_MSG_MAP(CStatsDlg)
	ON_BN_CLICKED(IDH_BUTTON_HOME, OnButtonHome)
	ON_BN_CLICKED(IDH_BUTTON_VISITOR, OnButtonVisitor)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_PBP, OnButtonPbp)
	ON_BN_CLICKED(IDC_BUTTON_PRNT, OnButtonPrnt)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_STATS, OnDblclkListStats)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_STATS, OnColumnclickListStats)
	ON_BN_CLICKED(IDC_RADIO_RUNNING, OnRadioRunning)
	ON_BN_CLICKED(IDC_RADIO_NORMAL, OnRadioNormal)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_STATS, &CStatsDlg::OnLvnItemchangedListStats)
	ON_BN_CLICKED(IDOK, &CStatsDlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatsDlg message handlers

BOOL CStatsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	m_buttonHome.EnableWindow(FALSE);
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 



	if(m_saved_box != true)
	{
		m_saved_box = false;
		ConvertStats();
	}
	else if(m_saved_box == true)
	{
		ReadSavedBox();
		m_button_pbp.ShowWindow(FALSE);
	}

	InitControls();

	if(m_saved_box == false) ListScores();

	if(m_saved_box == false) OnButtonHome();
	else if(m_saved_box == true && m_v_click == true) OnButtonVisitor();
	else if(m_saved_box == true) OnButtonHome();

	ListPct();

	CPlayer m_player = PlayerStats[15];
	int visitor_score = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 + m_player.GetGameFtm();
	m_player = PlayerStats[30];
	int home_score = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 + m_player.GetGameFtm();
	if(m_saved_box == true) m_score[1] = visitor_score;
	if(m_saved_box == true) m_score[2] = home_score;
	if(m_saved_box == true) ListScores();

	int v_w = avg.m_standings[m_visitor_index].m_win;
	int v_l = avg.m_standings[m_visitor_index].m_loss;
	int h_w = avg.m_standings[m_home_index].m_win;
	int h_l = avg.m_standings[m_home_index].m_loss;

	CString visitor;
	if(m_visitor == avg.m_settings.m_conferenceName1)
		visitor.Format("%s %d", m_visitor, visitor_score);
	else
		visitor.Format("%s(%d-%d) %d", m_visitor, v_w, v_l, visitor_score);

	CString home;
	if(m_home == avg.m_settings.m_conferenceName2)
		home.Format("%s %d", m_home, home_score);
	else
		home.Format("%s(%d-%d) %d", m_home, h_w, h_l, home_score);

	m_buttonHome.SetWindowText(home);
	m_buttonVisitor.SetWindowText(visitor);
	m_edit_att = m_att;
	m_edit_cap = m_cap;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStatsDlg::OnButtonHome() 
{
	// TODO: Add your control notification handler code here
	int player = 0;
	CPlayer m_player;
	int row = 0;
	for(int i=0; i<= 32; i++)
	{
		m_stats_pointer[i] = 0;
	}
	m_team_index = m_home_index;
	m_list_stats.DeleteAllItems();
		for(int i = 16; i <= 30; ++i)
		{
			m_print_strings[i-16] = "";

			player = i;
			m_player = PlayerStats[player];
			CString Stats;
			CString Pos,Name,Min,Fgm,Fga,Tfgm,Tfga,Ftm,Fta,
				Oreb,Reb,Ast,Stl,To,Blk,Pf,Pts,Rate;
			Name = m_player.GetName();
			Pos = m_player.GetPos();
			if(player == 30) Name = m_home;
			if(Name == "" || (player > 27 && player < 30)) continue;
			int min = round(m_player.GetGameMin() / 60);
			if (m_player.m_game_Min > 0 && min == 0) min = 1;

			if(player == 30){min = 240; Min = "";}
			else Min.Format( "%d", min );
			int fgm = m_player.GetGameFgm() + m_player.GetGameTfgm();
			Fgm.Format( "%d", fgm );
			int fga = m_player.GetGameFga() + m_player.GetGameTfga();
			Fga.Format( "%d", fga );
			Tfgm.Format( "%d", m_player.GetGameTfgm() );
			Tfga.Format( "%d", m_player.GetGameTfga() );
			Ftm.Format( "%d", m_player.GetGameFtm() );
			Fta.Format( "%d", m_player.GetGameFta() );
			Oreb.Format( "%d", m_player.GetGameOreb() );
			int reb = m_player.GetGameOreb() + m_player.GetGameDreb();
			Reb.Format( "%d", reb );
			Ast.Format( "%d", m_player.GetGameAst() );
			Stl.Format( "%d", m_player.GetGameStl() );
			To.Format( "%d", m_player.GetGameTo() );
			Blk.Format( "%d", m_player.GetGameBlk() );
			Pf.Format( "%d", m_player.GetGamePf() );
			int pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 + m_player.GetGameFtm();
			Pts.Format( "%d", pts );

		fgm = m_player.GetGameFgm() + m_player.GetGameTfgm();
		fga = m_player.GetGameFga() + m_player.GetGameTfga();
		reb = m_player.GetGameOreb() + m_player.GetGameDreb();

  		double gun = double(fgm) + double(m_player.GetGameTfgm()) - ((double(fga) - double(fgm)) * 2/3);
  		gun = gun + double(m_player.GetGameFtm()) - (double(m_player.GetGameFta()) / 2); 
		gun = gun + ( double(m_player.GetGameFta()) - double(m_player.GetGameFtm())) * 1/6;
  		double skill = double(m_player.GetGameOreb()) * 2/3 + (double(reb) - double(m_player.GetGameOreb())) * 1/3;
		skill = skill + double(m_player.GetGameStl()) -  double(m_player.GetGameTo()) + double(m_player.GetGameBlk());
  		skill = skill + double(m_player.GetGameAst()) * 4 / 5;
		double tru = gun + skill;
		tru = tru - m_factor / 48 * min;
		Rate.Format( "%.1f", tru );

		PlayerStats[player].m_trueRating = tru;


			Stats.Format
				("%-16s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %5s",
				Name,Min,Fgm,Fga,Tfgm,Tfga,Ftm,Fta,Oreb,Reb,Ast,Stl,To,Blk,Pf,Pts,Rate);



			m_list_stats.InsertItem(row,Pos);
			m_list_stats.SetItemText(row,1,Name);
			m_list_stats.SetItemText(row,2,Min);
			m_list_stats.SetItemText(row,3,Fgm);
			m_list_stats.SetItemText(row,4,Fga);
			m_list_stats.SetItemText(row,5,Tfgm);
			m_list_stats.SetItemText(row,6,Tfga);
			m_list_stats.SetItemText(row,7,Ftm);
			m_list_stats.SetItemText(row,8,Fta);
			m_list_stats.SetItemText(row,9,Oreb);
			m_list_stats.SetItemText(row,10,Reb);
			m_list_stats.SetItemText(row,11,Ast);
			m_list_stats.SetItemText(row,12,Stl);
			m_list_stats.SetItemText(row,13,To);
			m_list_stats.SetItemText(row,14,Blk);
			m_list_stats.SetItemText(row,15,Pf);
			m_list_stats.SetItemText(row,16,Pts);
			m_list_stats.SetItemText(row,17,Rate);
		


			m_print_strings[row] = Stats;
			
			m_stats_pointer[row] = player;
			row = row + 1;
		}
}

void CStatsDlg::OnButtonVisitor() 
{
	// TODO: Add your control notification handler code here
//	m_buttonHome.EnableWindow(TRUE);
//	m_listStats.ResetContent();
	m_list_stats.DeleteAllItems();

	int player = 0;
	CPlayer m_player;
	int row = 0;
	for(int i=0; i<= 32; i++)
	{
		m_stats_pointer[i] = 0;
	}
	m_team_index = m_visitor_index;
	
	for(int i = 1; i <= 15; ++i)
		{
			m_print_strings[i] = "";
			player = i;
			m_player = PlayerStats[player];
			m_player = PlayerStats[player];
			CString Stats;
			CString Pos,Name,Min,Fgm,Fga,Tfgm,Tfga,Ftm,Fta,Oreb,Reb,Ast,Stl,To,Blk,Pf,Pts,Rate;
			Name = m_player.GetName();
			Pos = m_player.GetPos();
			if(player == 15) Name = m_visitor;
			if(Name == "" || (player > 12 && player < 15)) continue;
			int min = round(m_player.GetGameMin() / 60);
			if (m_player.m_game_Min > 0 && min == 0) min = 1;


			if(player == 15){min = 240; Min = "";}
			else Min.Format( "%d", min );
			int fgm = m_player.GetGameFgm() + m_player.GetGameTfgm();
			Fgm.Format( "%d", fgm );
			int fga = m_player.GetGameFga() + m_player.GetGameTfga();
			Fga.Format( "%d", fga );
			Tfgm.Format( "%d", m_player.GetGameTfgm() );
			Tfga.Format( "%d", m_player.GetGameTfga() );
			Ftm.Format( "%d", m_player.GetGameFtm() );
			Fta.Format( "%d", m_player.GetGameFta() );
			Oreb.Format( "%d", m_player.GetGameOreb() );
			int reb = m_player.GetGameOreb() + m_player.GetGameDreb();
			Reb.Format( "%d", reb );
			Ast.Format( "%d", m_player.GetGameAst() );
			Stl.Format( "%d", m_player.GetGameStl() );
			To.Format( "%d", m_player.GetGameTo() );
			Blk.Format( "%d", m_player.GetGameBlk() );
			Pf.Format( "%d", m_player.GetGamePf() );
			int pts = m_player.GetGameFgm() * 2 + m_player.GetGameTfgm() * 3 + m_player.GetGameFtm();
			Pts.Format( "%d", pts );
			//Set game true
		fgm = m_player.GetGameFgm() + m_player.GetGameTfgm();
		fga = m_player.GetGameFga() + m_player.GetGameTfga();
		reb = m_player.GetGameOreb() + m_player.GetGameDreb();

  		double gun = double(fgm) + double(m_player.GetGameTfgm()) - ((double(fga) - double(fgm)) * 2/3);
  		gun = gun + double(m_player.GetGameFtm()) - (double(m_player.GetGameFta()) / 2); 
		gun = gun + ( double(m_player.GetGameFta()) - double(m_player.GetGameFtm())) * 1/6;
//		gun = gun * 3/2;//fix this shit maybe
  		double skill = double(m_player.GetGameOreb()) * 2/3 + (double(reb) - double(m_player.GetGameOreb())) * 1/3;
		skill = skill + double(m_player.GetGameStl()) -  double(m_player.GetGameTo()) + double(m_player.GetGameBlk());
  		skill = skill + double(m_player.GetGameAst()) * 4 / 5;
//		skill = skill * 3/4;//fix this shit maybe
		double tru = gun + skill;
		tru = tru - m_factor / 48 * min;
		PlayerStats[player].m_trueRating = tru;
		Rate.Format( "%.1f", tru );



			Stats.Format
				("%-16s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %5s",
				Name,Min,Fgm,Fga,Tfgm,Tfga,Ftm,Fta,Oreb,Reb,Ast,Stl,To,Blk,Pf,Pts,Rate);


			m_list_stats.InsertItem(row,Pos);
			m_list_stats.SetItemText(row,1,Name);
			m_list_stats.SetItemText(row,2,Min);
			m_list_stats.SetItemText(row,3,Fgm);
			m_list_stats.SetItemText(row,4,Fga);
			m_list_stats.SetItemText(row,5,Tfgm);
			m_list_stats.SetItemText(row,6,Tfga);
			m_list_stats.SetItemText(row,7,Ftm);
			m_list_stats.SetItemText(row,8,Fta);
			m_list_stats.SetItemText(row,9,Oreb);
			m_list_stats.SetItemText(row,10,Reb);
			m_list_stats.SetItemText(row,11,Ast);
			m_list_stats.SetItemText(row,12,Stl);
			m_list_stats.SetItemText(row,13,To);
			m_list_stats.SetItemText(row,14,Blk);
			m_list_stats.SetItemText(row,15,Pf);
			m_list_stats.SetItemText(row,16,Pts);
			m_list_stats.SetItemText(row,17,Rate);
					

//			m_listStats.AddString(Stats);
			m_print_strings[row] = Stats;
			m_stats_pointer[row] = player;
			row = row + 1;
		}	


}


BOOL CStatsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsscheduler.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

  //	WinHelp(HID_STATS_GAME);	
	//return TRUE;
}

void CStatsDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
  	//WinHelp(HID_STATS_GAME);		
}

void CStatsDlg::OnButtonPbp() 
{
	// TODO: Add your control notification handler code here
	CBoxscore box;
	for(int i=0; i<=m_lines; i++)
	{
		box.m_playByPlay[i] = m_playByPlay[i];
	}
	box.DoModal();
}

void CStatsDlg::OnButtonPrnt() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	//initialize a structure for my font

	CString pBuf;
       HDC    hdcPrn ;
       // Instantiate a CPrintDialog.
       CPrintDialog *printDlg = new CPrintDialog(FALSE, PD_ALLPAGES | PD_RETURNDC, NULL);
		// Initialize some of the fields in PRINTDLG structure.
       printDlg->m_pd.nMinPage = printDlg->m_pd.nMaxPage = 1;
       printDlg->m_pd.nFromPage = printDlg->m_pd.nToPage = 1;
       // Display Windows print dialog box.       
	   printDlg->DoModal();
       // Obtain a handle to the device context.
       hdcPrn = printDlg->GetPrinterDC();
       if (hdcPrn != NULL)           
	   {
           CDC *pDC = new CDC;
           pDC->Attach (hdcPrn);      // attach a printer DC
           pDC->StartDoc("Game Stats");  // begin a new print job
                                   // for Win32 use
                                   // CDC::StartDoc(LPDOCINFO) override
           pDC->StartPage();          // begin a new page
           SetPrintAlign(pDC, hdcPrn);// set the printing alignment

	LOGFONT logFont;
	logFont.lfHeight = 40;
	//logFont.lfWidth = 0;
	//logFont.lfEscapement = 0;
	//logFont.lfOrientation = 0;
	logFont.lfWeight = 420;
	//logFont.lfItalic = 0;
	//logFont.lfUnderline = 0;
	//logFont.lfStrikeOut = 0;
	//logFont.lfCharSet = ANSI_CHARSET;
	//logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	//logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	//logFont.lfQuality = PROOF_QUALITY;
	//logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	strcpy_s(logFont.lfFaceName, "Courier New");

	CFont font;
	font.CreateFontIndirect(&logFont);
	CFont* oldFont = pDC->SelectObject(&font);


	OnButtonVisitor();

	CString heading = m_visitor + " vs " + m_home + " Game Stats";

	pBuf = "Name              min fgm fga 3gm 3ga ftm fta orb reb ast stl  to blk  pf pts  true";
        pDC->TextOut(-900, 1000, heading);// write the string in pbuf
        pDC->TextOut(-900, 900, pBuf);// write the string in pbuf
//		int items = m_listStats.GetCount();
		int row = 800;
		for(int i = 1; i<=15; i++)
		{
			//m_listStats.GetText(i-1, pBuf);
			pBuf = m_print_strings[i-1];
			pDC->TextOut(-900, row, pBuf);// write the string in pbuf
			row = row - 50;
		}
	OnButtonHome();
//		items = m_listStats.GetCount();
		row = -100;
		pBuf = "Name              min fgm fga 3gm 3ga ftm fta orb reb ast stl  to blk  pf pts  true";
        pDC->TextOut(-900, 0, pBuf);// write the string in pbuf
		for(int i = 1; i<=15; i++)
		{
//			m_listStats.GetText(i-1, pBuf);
			pBuf = m_print_strings[i-1];
			pDC->TextOut(-900, row, pBuf);// write the string in pbuf
			row = row - 50;
		}



           pDC->EndPage();            // end a page
           pDC->EndDoc();             // end a print job
           pDC->Detach();             // detach the printer DC
           delete pDC;           
	   }       
	   delete printDlg;       	
}

void CStatsDlg::SetPrintAlign(CDC *pDC, HDC hdcPrn)
{
	short cxPage, cyPage;
	cxPage = ::GetDeviceCaps (hdcPrn, HORZRES) ;
	cyPage = ::GetDeviceCaps (hdcPrn, VERTRES) ;

    pDC->SetMapMode (MM_ISOTROPIC) ;
	pDC->SetWindowExt ( 1000, 1000) ;

	pDC->SetViewportExt (cxPage / 2, -cyPage / 2) ;
    pDC->SetViewportOrg (cxPage / 2,  cyPage / 2) ;
    pDC->SetTextAlign (TA_BASELINE) ;
}
HBRUSH CStatsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

}


void CStatsDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
	
}

void CStatsDlg::InitControls()
{

	m_buttonOk.m_useImage = false;
	m_buttonOk.SetFaceColor(BUTTONCOLOR);
	m_buttonOk.SetTextColor(BUTTONTEXTCOLOR);

	m_buttonPrint.m_useImage = false;
	m_buttonPrint.SetFaceColor(BUTTONCOLOR);
	m_buttonPrint.SetTextColor(BUTTONTEXTCOLOR);



	m_column = 0;
	CheckDlgButton(IDC_RADIO_NORMAL, 1);	

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 18;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.


	m_list_stats.SetFont(&m_font);
	m_list_stats.SetBkColor(BK_COLOR);
	m_list_stats.SetTextBkColor(TEXT_BK_COLOR);

//	m_list_stats.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list_stats.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


	m_list_stats.SetItemState(0 ,LVIS_SELECTED,LVIS_SELECTED);


	m_list_scores.SetBkColor(BK_COLOR);
	m_list_scores.SetTextBkColor(TEXT_BK_COLOR);

	m_list_scores.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


	m_list_scores.SetItemState(0 ,LVIS_SELECTED,LVIS_SELECTED);

	m_list_pct.SetBkColor(BK_COLOR);
	m_list_pct.SetTextBkColor(TEXT_BK_COLOR);
//	m_list_pct.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list_pct.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
	m_list_pct.SetItemState(0 ,LVIS_SELECTED,LVIS_SELECTED);








 m_list_stats.InsertColumn(0,"pos");    
    m_list_stats.InsertColumn(1,"player");    
    m_list_stats.InsertColumn(2,"min");    
    m_list_stats.InsertColumn(3,"fgm");    
    m_list_stats.InsertColumn(4,"fga");    
    m_list_stats.InsertColumn(5,"tgm");
    m_list_stats.InsertColumn(6,"tga");    

    m_list_stats.InsertColumn(7,"ftm");    
    m_list_stats.InsertColumn(8,"fta");    
	m_list_stats.InsertColumn(9,"orb");    
	m_list_stats.InsertColumn(10,"reb");    
    m_list_stats.InsertColumn(11,"ast");    
    m_list_stats.InsertColumn(12,"stl");    
    m_list_stats.InsertColumn(13,"to");    
    m_list_stats.InsertColumn(14,"blk");    
    m_list_stats.InsertColumn(15,"pf");    
    m_list_stats.InsertColumn(16,"pts");    
    m_list_stats.InsertColumn(17,"true");    


	double scale = 1.5;
  
    m_list_stats.SetColumnWidth( 0, 30 * scale );
    m_list_stats.SetColumnWidth( 1, 120 * scale );
    m_list_stats.SetColumnWidth( 2, 28 * scale );
    m_list_stats.SetColumnWidth( 3, 30 * scale );
    m_list_stats.SetColumnWidth( 4, 30 * scale );
    m_list_stats.SetColumnWidth( 5, 30 * scale );
    m_list_stats.SetColumnWidth( 6, 28 * scale );
    m_list_stats.SetColumnWidth( 7, 28 * scale );
    m_list_stats.SetColumnWidth( 8, 28 * scale );
    m_list_stats.SetColumnWidth( 9, 28 * scale );
    m_list_stats.SetColumnWidth( 10, 28 * scale );
    m_list_stats.SetColumnWidth( 11, 28 * scale );
    m_list_stats.SetColumnWidth( 12, 28 * scale );
    m_list_stats.SetColumnWidth( 13, 28 * scale );
    m_list_stats.SetColumnWidth( 14, 28 * scale );
    m_list_stats.SetColumnWidth( 15, 28 * scale );
    m_list_stats.SetColumnWidth( 16, 33 * scale );
    m_list_stats.SetColumnWidth( 17, 40 * scale );


	m_list_scores.InsertColumn(0,"team");    
    m_list_scores.InsertColumn(1,"1");    
    m_list_scores.InsertColumn(2,"2");    
    m_list_scores.InsertColumn(3,"3");    
    m_list_scores.InsertColumn(4,"4");    
    m_list_scores.InsertColumn(5,"");
    m_list_scores.InsertColumn(6,"T");    
    	
	m_list_scores.SetColumnWidth( 0, 60 * scale );
    m_list_scores.SetColumnWidth( 1, 30 * scale );
    m_list_scores.SetColumnWidth( 2, 30 * scale );
    m_list_scores.SetColumnWidth( 3, 30 * scale );
    m_list_scores.SetColumnWidth( 4, 30 * scale );
    m_list_scores.SetColumnWidth( 5, 30 * scale );
    m_list_scores.SetColumnWidth( 6, 30 * scale );


	m_list_pct.InsertColumn(0,"team");    
    m_list_pct.InsertColumn(1,"fg%");    
    m_list_pct.InsertColumn(2,"tfg%");    
    m_list_pct.InsertColumn(3,"ft%");    
    	
	m_list_pct.SetColumnWidth( 0, 72 * scale );
    m_list_pct.SetColumnWidth( 1, 48 * scale );
    m_list_pct.SetColumnWidth( 2, 48 * scale );
    m_list_pct.SetColumnWidth( 3, 48 * scale );


	m_running_total[0][0] = 0;
	m_running_total[0][1] = 0;
	m_running_total[1][0] = 0;
	m_running_total[2][0] = 0;

	m_running_total[1][1] = m_quarter_score[1][1];
	m_running_total[1][2] = m_quarter_score[1][1] + m_quarter_score[1][2];
	m_running_total[1][3] = m_quarter_score[1][1] + m_quarter_score[1][2] + m_quarter_score[1][3];
	m_running_total[1][4] = m_quarter_score[1][1] + m_quarter_score[1][2] + m_quarter_score[1][3] + m_quarter_score[1][4];
	m_running_total[1][5] = m_quarter_score[1][1] + m_quarter_score[1][2] + m_quarter_score[1][3] + m_quarter_score[1][4] +
		m_quarter_score[1][5];
	
	
	m_running_total[2][1] = m_quarter_score[2][1];
	m_running_total[2][2] = m_quarter_score[2][1] + m_quarter_score[2][2];
	m_running_total[2][3] = m_quarter_score[2][1] + m_quarter_score[2][2] + m_quarter_score[2][3];
	m_running_total[2][4] = m_quarter_score[2][1] + m_quarter_score[2][2] + m_quarter_score[2][3] + m_quarter_score[2][4];
	m_running_total[2][5] = m_quarter_score[2][1] + m_quarter_score[2][2] + m_quarter_score[2][3] + m_quarter_score[2][4] +
		m_quarter_score[2][5];

	if(m_running_total[1][5] == m_running_total[1][4]) m_running_total[1][5] = 0;
	if(m_running_total[2][5] == m_running_total[2][4]) m_running_total[2][5] = 0;

	
}


void CStatsDlg::OnDblclkListStats(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int i = m_list_stats.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	int pointer = m_stats_pointer[i];
	CPlayer m_player = PlayerStats[pointer];

	CAverage temp_avg;
	temp_avg = avg;

	int ctr = 1;
	for(int i=1; i<=30; i++)
	{
		for(int p=1; p<=1600; p++)
		{
			CPlayer m_temp;
			if(avg.m_actual[p].m_name.Left(16) == PlayerStats[i].m_name.Left(16) && PlayerStats[i].m_name != "" && ctr <= 30)
			{
				temp_avg.m_actual[ctr] = avg.m_actual[p];
				if(temp_avg.m_actual[ctr].m_name.Left(16) == m_player.m_name.Left(16))
				{
					m_player = temp_avg.m_actual[ctr];
					pointer = ctr;
				}
				ctr = ctr + 1;
			}
		}
						
	}

	for(int i=ctr; i<=1600; i++)
	{
		CPlayer m_temp;
		temp_avg.m_actual[i] = m_temp;
	}


	CPlayerCardDlg *scout = new CPlayerCardDlg;
	int tm = m_player.m_team_index - 1;
	CString team = avg.m_settings.m_leagueTeamNames[tm];
	CString string = m_player.GetPos() + " " + m_player.GetName() + " - "  + team;

	scout->m_path = avg.m_settings.m_path;
	scout->m_leagueName = avg.m_settings.m_league_name;
	scout->m_player_index = pointer;
	scout->m_title = "Scout";
	scout->avg = temp_avg;
	
	scout->DoModal();

	delete scout;

	*pResult = 0;


	
}

void CStatsDlg::OnColumnclickListStats(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	int index = m_list_stats.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	m_column = pNMListView->iSubItem;


CPlayer m_player_stats_i, m_player_stats_j;

//			Stats.Format
//				("%-16s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %5s",
//				Name,Min,Fgm,Fga,Tfgm,Tfga,Ftm,Fta,Oreb,Reb,Ast,Stl,To,Blk,Pf,Pts,Rate);

int p1 = 0, p2 = 12;

if(m_team_index == m_home_index)
{
	p1 = 16; p2 = 28;
}



for(int i=p1; i<=p2; i++)
{
for(int j=p1; j<=p2; j++)
{


bool swap = false;

	m_player_stats_i = PlayerStats[i];
	m_player_stats_j = PlayerStats[j];
	if(m_player_stats_i.m_name == "" || m_player_stats_j.m_name == "") continue;

	int fgm_i = m_player_stats_i.GetGameFgm() + m_player_stats_i.GetGameTfgm();
	int fgm_j = m_player_stats_j.GetGameFgm() + m_player_stats_j.GetGameTfgm();
	int fga_i = m_player_stats_i.GetGameFga() + m_player_stats_i.GetGameTfga();
	int fga_j = m_player_stats_j.GetGameFga() + m_player_stats_j.GetGameTfga();
	int tgm_i = m_player_stats_i.GetGameTfgm();
	int tgm_j = m_player_stats_j.GetGameTfgm();
	int tga_i = m_player_stats_i.GetGameTfga();
	int tga_j = m_player_stats_j.GetGameTfga();
	int ftm_i = m_player_stats_i.GetGameFtm();
	int ftm_j = m_player_stats_j.GetGameFtm();
	int fta_i = m_player_stats_i.GetGameFta();
	int fta_j = m_player_stats_j.GetGameFta();

	int orb_i = m_player_stats_i.GetGameOreb();
	int orb_j = m_player_stats_j.GetGameOreb();
	int reb_i = m_player_stats_i.GetGameOreb() + m_player_stats_i.GetGameDreb();
	int reb_j = m_player_stats_j.GetGameOreb() + m_player_stats_j.GetGameDreb();
	int ast_i = m_player_stats_i.GetGameAst();
	int ast_j = m_player_stats_j.GetGameAst();
	int stl_i = m_player_stats_i.GetGameStl();
	int stl_j = m_player_stats_j.GetGameStl();
	int to_i = m_player_stats_i.GetGameTo();
	int to_j = m_player_stats_j.GetGameTo();
	int blk_i = m_player_stats_i.GetGameBlk();
	int blk_j = m_player_stats_j.GetGameBlk();
	int pf_i = m_player_stats_i.GetGamePf();
	int pf_j = m_player_stats_j.GetGamePf();
	int pts_i = m_player_stats_i.GetGameFgm() * 2 + m_player_stats_i.GetGameTfgm() * 3 + m_player_stats_i.GetGameFtm();
	int pts_j = m_player_stats_j.GetGameFgm() * 2 + m_player_stats_j.GetGameTfgm() * 3 + m_player_stats_j.GetGameFtm();
	double tru_i = m_player_stats_i.m_trueRating;
	double tru_j = m_player_stats_j.m_trueRating;

switch(m_column) 
{

    case 0:
		swap = m_player_stats_i.m_pos < m_player_stats_j.m_pos;
        break;
    case 1:
		swap = m_player_stats_i.m_name < m_player_stats_j.m_name;
        break;
    case 2:        
		swap = m_player_stats_i.GetGameMin() > m_player_stats_j.GetGameMin();
        break;
    case 3:
		swap = fgm_i > fgm_j;
        break;
    case 4:
		swap = fga_i > fga_j;
        break;
    case 5:
		swap = tgm_i > tgm_j;
        break;
    case 6:
		swap = tga_i > tga_j;
        break;
    case 7:
		swap = ftm_i > ftm_j;
        break;
    case 8:
		swap = fta_i > fta_j;
        break;
    case 9:
		swap = orb_i > orb_j;
        break;
    case 10:
		swap = reb_i > reb_j;
        break;
    case 11:
		swap = ast_i > ast_j;
        break;
    case 12:
		swap = stl_i > stl_j;
        break;
    case 13:
		swap = to_i > to_j;
        break;
    case 14:
		swap = blk_i > blk_j;
        break;
    case 15:
		swap = pf_i > pf_j;
        break;
    case 16:
		swap = pts_i > pts_j;
        break;
    case 17:
		swap = tru_i > tru_j;
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;


}

	if(swap == true)
	{//swap
		CPlayer temp = PlayerStats[i];
		PlayerStats[i] = PlayerStats[j];
		PlayerStats[j] = temp;
	}



}
}


	if(m_team_index == m_visitor_index) OnButtonVisitor();
	else OnButtonHome();

	
	*pResult = 0;
}

void CStatsDlg::ListScores()
{

	m_list_scores.DeleteAllItems();
	CString string;
	for(int i=1; i<=2; i++)
	{
		int j=0;	
		if(i == 1)
			m_list_scores.InsertItem(i-1,m_visitor);
		else
			m_list_scores.InsertItem(i-1,m_home);
		for(j=1; j<=5; j++)
		{
			if(j == m_quarter)
			{
				int s = m_score[i] - m_running_total[i][j-1];
				string.Format("%d", s);
			}
			else
				string.Format("%d", m_quarter_score[i][j]);

			if(string == "0") string = "";
			m_list_scores.SetItemText(i-1,j,string);
		}
		string.Format("%d", m_score[i]);
		m_list_scores.SetItemText(i-1,j,string);
	}
}

void CStatsDlg::OnRadioRunning() 
{
	// TODO: Add your control notification handler code here
	ListTally();
	
}

void CStatsDlg::OnRadioNormal() 
{
	// TODO: Add your control notification handler code here
	ListScores();
}

void CStatsDlg::ListTally()
{
	CString string;
	m_list_scores.DeleteAllItems();
	for(int i=1; i<=2; i++)
	{
		int j=0;
		if(i == 1)
			m_list_scores.InsertItem(i-1,m_visitor);
		else
			m_list_scores.InsertItem(i-1,m_home);
		for(j=1; j<=5; j++)
		{
			if(j == m_quarter && j < 5)
			{
				int s = m_score[i];
				string.Format("%d", s);
			}
			else if(j > m_quarter)
			{
				string = "";
			}
			else
				string.Format("%d", m_running_total[i][j]);

			if(string == "0") string = "";
			m_list_scores.SetItemText(i-1,j,string);
		}
		string.Format("%d", m_score[i]);
		m_list_scores.SetItemText(i-1,j,string);
	}

}

void CStatsDlg::ListPct()
{


for(int i=0; i<=1; i++)
{

	CPlayer m_stats = PlayerStats[i*15 + 15];
	CString name = m_visitor;
	if(i == 1) name = m_home;
	CString fgp, tgp, ftp;
	double fg = 0, tg = 0, ft = 0;

	double shots_2 = (double)m_stats.GetGameFga() + (double)m_stats.GetGameTfga();

	if(shots_2 > 0)
		fg = ((double)m_stats.GetGameFgm() + (double)m_stats.GetGameTfgm()) / shots_2 * 10000;

	double shots_3 = (double)m_stats.GetGameTfga();

	if(shots_3 > 0) 
		tg = (double)m_stats.GetGameTfgm() / shots_3 * 10000;

	double shots_1 = (double)m_stats.GetGameFta();

	if(shots_1 > 0) 
		ft = (double)m_stats.GetGameFtm() / shots_1 * 10000;


	fgp.Format("%.2f", fg/100);
	tgp.Format("%.2f", tg/100);
	ftp.Format("%.2f", ft/100);


		m_list_pct.InsertItem(i,name);
		m_list_pct.SetItemText(i,1,fgp);
		m_list_pct.SetItemText(i,2,tgp);
		m_list_pct.SetItemText(i,3,ftp);


}	

}

void CStatsDlg::ReadSavedBox()
{
	CString file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".sco";

	CFile file( file_name, CFile::modeRead);
	char s[2001];
	int seek = (m_mo*500 + m_da*15 + m_ga) * 2000;
	//seek = 0;
	file.Seek(seek, CFile::begin );
	int bytes = file.Read(s, 2000);
	s[bytes] = 0;
	CString str = CString(s);
	//str = str + "                                                                                                "; 
	CString mo = str.Mid(0, 2);
	CString da = str.Mid(2, 2);
	CString ga = str.Mid(4, 2);


	CString buf;
	buf = str.Mid(6, 2);
	m_visitor_index = atoi(buf);
	buf = str.Mid(8,2);
	m_home_index = atoi(buf);

	buf = str.Mid(10,5);
	m_att = atoi(buf);

	buf = str.Mid(15,5);
	m_cap = atoi(buf);

	buf = str.Mid(20,4);
	int v_rec = atoi(buf);

	buf = str.Mid(24,4);
	int h_rec = atoi(buf);

	buf = str.Mid(28,3);
	m_quarter_score[1][1] = atoi(buf);

	buf = str.Mid(31,3);
	m_quarter_score[1][2] = atoi(buf);

	buf = str.Mid(34,3);
	m_quarter_score[1][3] = atoi(buf);

	buf = str.Mid(37,3);
	m_quarter_score[1][4] = atoi(buf);

	buf = str.Mid(40,3);
	m_quarter_score[1][5] = atoi(buf);

	buf = str.Mid(43,3);
	m_quarter_score[2][1] = atoi(buf);

	buf = str.Mid(46,3);
	m_quarter_score[2][2] = atoi(buf);

	buf = str.Mid(49,3);
	m_quarter_score[2][3] = atoi(buf);

	buf = str.Mid(52,3);
	m_quarter_score[2][4] = atoi(buf);

	buf = str.Mid(55,3);
	m_quarter_score[2][5] = atoi(buf);


	avg.m_standings[m_visitor_index].m_win = v_rec / 100;
	avg.m_standings[m_visitor_index].m_loss = v_rec - avg.m_standings[m_visitor_index].m_win * 100;

	avg.m_standings[m_home_index].m_win = h_rec / 100;
	avg.m_standings[m_home_index].m_loss = h_rec - avg.m_standings[m_home_index].m_win * 100;



	m_visitor = avg.m_settings.m_leagueTeamNames[m_visitor_index];
	m_home = avg.m_settings.m_leagueTeamNames[m_home_index];

	if(m_game_type == ALLSTAR)
	{
		m_visitor = avg.m_settings.m_conferenceName1;
		m_home = avg.m_settings.m_conferenceName2;
	}
	else if(m_game_type == ROOKIE)
	{
		m_visitor = "Rookies";
		m_home = "Sophomores";
	}



	m_factor = avg.m_avg_tru[0];
	m_quarter = 5;

	for(int i=0; i<=29; i++)
	{
		buf = str.Mid(58 + i*53,16);
		buf.TrimRight();
		PlayerStats[i+1].m_name = buf;

		buf = str.Mid(58 + i*53+16,2);
		buf.TrimRight();
		PlayerStats[i+1].m_pos = buf;

		buf = str.Mid(58 + i*53+18,6);
		int id = atoi(buf);
		PlayerStats[i+1].m_id = id;

		buf = str.Mid(58 + i*53+24,2);
		int min = atoi(buf) * 60;
		PlayerStats[i+1].SetGameMin(min);

		buf = str.Mid(58 + i*53+26,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Fgm = min;

		buf = str.Mid(58 + i*53+28,3);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Fga = min;

		buf = str.Mid(58 + i*53+31,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Ftm = min;

		buf = str.Mid(58 + i*53+33,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Fta = min;


		buf = str.Mid(58 + i*53+35,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Tfgm = min;

		buf = str.Mid(58 + i*53+37,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Tfga= min;

		buf = str.Mid(58 + i*53+39,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Oreb = min;

		buf = str.Mid(58 + i*53+41,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Dreb = min;

		buf = str.Mid(58 + i*53+43,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Ast = min;

		buf = str.Mid(58 + i*53+45,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Stl = min;

		buf = str.Mid(58 + i*53+47,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_To = min;

		buf = str.Mid(58 + i*53+49,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Blk = min;

		buf = str.Mid(58 + i*53+51,2);
		min = atoi(buf);
		PlayerStats[i+1].m_game_Pf = min;

	}
}


void CStatsDlg::ConvertStats()
{
	
	for(int i=1; i<=15; i++)
	{
		int slot = m_playing_players_list[i];
		PlayerStats[i] = avg.m_actual[slot];
		//PlayerStats[i] = avg.m_actual[m_visitor_index*30 + i];
	}

	for(int i=1; i<=15; i++)
	{
		int slot = m_playing_players_list[30 + i];
		PlayerStats[15+i] = avg.m_actual[slot];
		//PlayerStats[15+i] = avg.m_actual[m_home_index*30 + i];
	}

	PlayerStats[15] = avg.m_actual[1441 + m_visitor_index];
	PlayerStats[30] = avg.m_actual[1441 + m_home_index];

}

void CStatsDlg::SetPtr(CAverage &pAverageClass)
{
	avg = pAverageClass;
}


void CStatsDlg::OnLvnItemchangedListStats(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CStatsDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
