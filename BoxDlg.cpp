// BoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"

#include "BoxDlg.h"
#include "CareerStatsCardDlg.h"
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBoxDlg dialog


CBoxDlg::CBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBoxDlg)
	//}}AFX_DATA_INIT

	m_player = new CPlayer[15];
	for(int i=0; i<=15; i++)
	{
		m_id_list[i] = 0;
		m_names_list[i] = "";

	}
	
}


void CBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBoxDlg)
	DDX_Control(pDX, IDC_LIST_CTRL_GAMES, m_listGames);
	DDX_Control(pDX, IDC_LIST_CTRL_SAVED_BOX, m_listBox);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_BUTTON_VISITOR, m_buttonVisitor);
	DDX_Control(pDX, IDC_BUTTON_HOME, m_buttonHome);
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button[0]);
	DDX_Control(pDX, IDOK, m_button[1]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CBoxDlg)
	ON_BN_CLICKED(IDC_BUTTON_VISITOR, OnButtonVisitor)
	ON_BN_CLICKED(IDC_BUTTON_HOME, OnButtonHome)
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_SAVED_BOX, OnClickListCtrlSavedBox)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CTRL_SAVED_BOX, OnColumnclickListCtrlSavedBox)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_GAMES, OnClickListCtrlGames)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_SAVED_BOX, OnDblclkListCtrlSavedBox)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CTRL_SAVED_BOX, &CBoxDlg::OnLvnItemchangedListCtrlSavedBox)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBoxDlg message handlers
BOOL CBoxDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
	m_start = 1;

	for(int i=0; i<=31; i++)
	{
		if(m_leagueTeamNames[i] != "") m_listTeams.AddString(m_leagueTeamNames[i]);
	}

	m_listTeams.SetCurSel(m_default_team);
//	m_listGames.SetCurSel(0);
	m_listGames.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listGames.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listGames.EnsureVisible(0, TRUE);
	InitGameStats();	
	InitControls();

	UpdateData(FALSE);
//	OnSelchangeListTeams();
	OnSelchangeComboTeams(); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}





void CBoxDlg::SetGames()
{

	m_listGames.DeleteAllItems();
	CString team = m_leagueTeamNames[m_listTeams.GetCurSel()];

	CFile file( m_fileName + ".bxs", CFile::modeRead);
	char s[17];
	CString string;

	int bytes = file.Read(s, 16);
	s[bytes] = 0;
	int game = atoi(s);

    int g = 0;
	for(int i=0; i<=9999; i++)
	{
		m_games[g] = 0;
	}
	if(game > 9999) game = 9999;
	int row = 0;
	for(int i=1; i<=game; i++)
	{
		int seek = (i-1)*3000+17+32;
		file.Seek( seek, CFile::begin );	


		int bytes = file.Read(s, 4);
		s[bytes] = 0;
		int mo = atoi(s) + 10;
		if(mo > 12) mo = mo - 12;
		CString month = CString(s);
		month.TrimRight();

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int da = atoi(s) + 1;
		CString day = CString(s);
		day.TrimRight();

		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString vis = CString(s);
		vis.TrimRight();

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		CString score1 = CString(s);
		score1.TrimRight();
		
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString home = CString(s);
		home.TrimRight();

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		CString score2 = CString(s);
		score2.TrimRight();
		
		if(vis == team || home == team && team != "") 
		{
			m_games[g] = i;
			g = g + 1;
			CString date;
			date.Format("%d/%d", mo, da);

			string.Format("%6s %-16s %3s %-16s %3s", date, vis, score1, home, score2);
//			m_listGames.AddString(string);
			int s1 = atoi(score1);
			int s2 = atoi(score2);
			CString team = m_leagueTeamNames[m_listTeams.GetCurSel()];
			CString res = "win";
			if(vis == team && s1 < s2) res = "loss";
			else if(home == team && s2 < s1) res = "loss";


			m_listGames.InsertItem(row,date);
			m_listGames.SetItemText(row,1,vis);
			m_listGames.SetItemText(row,2, score1);
			m_listGames.SetItemText(row,3,home);
			m_listGames.SetItemText(row,4,score2);
			m_listGames.SetItemText(row,5,res);
			row = row + 1;
		}


	}
	file.Close();
	int count = m_listGames.GetItemCount() - 1;
//	m_listGames.SetCurSel(count);
	m_listGames.SetItemState(count,LVIS_SELECTED,LVIS_SELECTED);
	m_listGames.SetItemState(count,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listGames.EnsureVisible(count, TRUE);

	UpdateData(FALSE);
}

void CBoxDlg::DisplayBox()
{
	m_listBox.DeleteAllItems();

	//int index = m_listGames.GetCurSel();
	int index = m_listGames.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	if(index < 0) index = 0;
	int i = m_games[index];
	CFile file( m_fileName + ".bxs", CFile::modeRead);

	char s[33];
	if(i>0)
	{
	int seek = (i-1)*3000+17+46+32;

	m_buttonVisitor.SetFocus();

	if(m_start == 16)
	{
		seek = seek + 94*15;
		m_buttonHome.SetFocus();
	}
	file.Seek( seek, CFile::begin );	
	CString string;

	
	int row = 0;


	for(int i = 1; i <= 15; i++ )
	{
//CPlayerStats *m_playerStats;
//m_playerStats = new CPlayerStats;
//		*m_playerStats = pDoc->m_play->PlayerStats[i];

		m_id_list[i-1] = 0;
		m_names_list[i-1] = "";

		int bytes = file.Read(s, 32);
		s[bytes] = 0;
		CString name = CString(s);
		name.TrimRight();

		if(i == 15 && m_start == 1) name = m_visitor; else if(i==15) name = m_home;

		bytes = file.Read(s, 6);
		s[bytes] = 0;
		int id = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int min = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int fgm = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int fga = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int ftm = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int fta = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int tgm = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int tga = atoi(s);

		fgm = fgm + tgm;
		fga = fga + tga;

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int orb = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int reb = orb + atoi(s);


		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int ast = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int stl = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int to = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int blk = atoi(s);

		bytes = file.Read(s, 4);
		s[bytes] = 0;
		int pf = atoi(s);

		int pts = fgm*2 + ftm + tgm;
			


			CString Min,Fgm,Fga,Ftm,Fta,Tgm,Tga,Orb,Reb,Ast,Stl,To,Blk,Pf,Pts;
			Min.Format("%d", min);
			Fgm.Format("%d", fgm);
			Fga.Format("%d", fga);
			Ftm.Format("%d", ftm);
			Fta.Format("%d", fta);
			Tgm.Format("%d", tgm);
			Tga.Format("%d", tga);
			Orb.Format("%d", orb);
			Reb.Format("%d", reb);
			Ast.Format("%d", ast);
			Stl.Format("%d", stl);
			To.Format("%d", to);
			Blk.Format("%d", blk);
			Pf.Format("%d", pf );
			Pts.Format("%d", pts);
		
		
		
		m_print_strings[row + m_start] = "";
		if(name != "" && min > 0 || i==15)
		{
			string.Format("%-16s %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d",
				name, min, fgm, fga, ftm, fta, tgm, tga, orb, reb, ast, stl, to, blk, pf, pts);
//			m_listBox.AddString(string);
			m_id_list[row] = id;
			m_names_list[row] = name;
		

			m_listBox.InsertItem(row,name);
			m_listBox.SetItemText(row,1,Min);
			m_listBox.SetItemText(row,2, Fgm);
			m_listBox.SetItemText(row,3,Fga);
			m_listBox.SetItemText(row,6,Ftm);
			m_listBox.SetItemText(row,7,Fta);
			m_listBox.SetItemText(row,4,Tgm);
			m_listBox.SetItemText(row,5,Tga);
			m_listBox.SetItemText(row,8,Orb);
			m_listBox.SetItemText(row,9 ,Reb);
			m_listBox.SetItemText(row,10,Ast);
			m_listBox.SetItemText(row,11,Stl);
			m_listBox.SetItemText(row,12,To);
			m_listBox.SetItemText(row,13,Blk);
			m_listBox.SetItemText(row,14,Pf);
			m_listBox.SetItemText(row,15,Pts);

			m_player[i-1].m_name = name;
			m_player[i-1].m_min = min;
			m_player[i-1].m_fgm = fgm;
			m_player[i-1].m_fga = fga;
			m_player[i-1].m_ftm = ftm;
			m_player[i-1].m_fta = fta;
			m_player[i-1].m_tfgm = tgm;
			m_player[i-1].m_tfga = tga;
			m_player[i-1].m_oreb = orb;
			m_player[i-1].m_reb = reb;
			m_player[i-1].m_ast = ast;
			m_player[i-1].m_stl = stl;
			m_player[i-1].m_to = to; 
			m_player[i-1].m_blk = blk;
			m_player[i-1].m_pf = pf;
			m_player[i-1].m_total_salary = pts;//huh no choice I guess

//	m_listBox.SetItemText(row,16,Rate);
		


			m_print_strings[row + m_start] = string;
			row = row + 1;

		}

	}
	}
}

void CBoxDlg::OnButtonVisitor() 
{
	// TODO: Add your control notification handler code here
	m_start = 1;
	DisplayBox();
	
}

void CBoxDlg::OnButtonHome() 
{
	// TODO: Add your control notification handler code here
	m_start = 16;
	DisplayBox();
	
}


void CBoxDlg::OnButtonPrint() 
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
           pDC->StartDoc("Saved Box Score");  // begin a new print job
                                   // for Win32 use
                                   // CDC::StartDoc(LPDOCINFO) override
           pDC->StartPage();          // begin a new page
           SetPrintAlign(pDC, hdcPrn);// set the printing alignment

	LOGFONT logFont;
	logFont.lfHeight = 40;
	logFont.lfWidth = 0;
	logFont.lfEscapement = 0;
	logFont.lfOrientation = 0;
	logFont.lfWeight = 420;
	logFont.lfItalic = 0;
	logFont.lfUnderline = 0;
	logFont.lfStrikeOut = 0;
	logFont.lfCharSet = ANSI_CHARSET;
	logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logFont.lfQuality = PROOF_QUALITY;
	logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	strcpy_s(logFont.lfFaceName, "Courier New");

	CFont font;
	font.CreateFontIndirect(&logFont);
	CFont* oldFont = pDC->SelectObject(&font);


	OnButtonVisitor();
	int ro = m_listGames.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	



	CString heading = 
		m_listGames.GetItemText(ro, 0) + "" + 
		m_listGames.GetItemText(ro, 1) + "" + 
		m_listGames.GetItemText(ro, 2) + "" + 
		m_listGames.GetItemText(ro, 3);

	pBuf = "Name              min fgm fga ftm fta 3gm 3ga orb reb ast stl  to blk  pf pts";


        pDC->TextOut(-900, 1000, heading);// write the string in pbuf
        pDC->TextOut(-900, 900, pBuf);// write the string in pbuf
		int items = m_listBox.GetItemCount();
		int row = 800;
		for(int i = 1; i<=items; i++)
		{
//			m_listBox.GetText(i-1, pBuf);
			pBuf = m_print_strings[15 + i];
			pDC->TextOut(-900, row, pBuf);// write the string in pbuf
			row = row - 50;
		}
	OnButtonHome();
		items = m_listBox.GetItemCount();
		row = -100;
		pBuf = "Name              min fgm fga 3gm 3ga ftm fta orb reb ast stl  to blk  pf pts  true";
        pDC->TextOut(-900, 0, pBuf);// write the string in pbuf
		for(int i = 1; i<=items; i++)
		{
//			m_listBox.GetText(i-1, pBuf);
			pBuf = m_print_strings[i];
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

void CBoxDlg::SetPrintAlign(CDC *pDC, HDC hdcPrn)
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

void CBoxDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_VIEW_SAVEDBOXSCORE);	
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolssavedbox.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

BOOL CBoxDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolssavedbox.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	WinHelp(HID_VIEW_SAVEDBOXSCORE);	
//	return TRUE;
//	return CDialog::OnHelpInfo(pHelpInfo);
}

HBRUSH CBoxDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CBoxDlg::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	SetGames();
//	OnSelchangeListGames();
	ListGames();
	
}

void CBoxDlg::OnClickListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CBoxDlg::InitControls()
{
	m_column = 0;
	CheckDlgButton(IDC_RADIO_NORMAL, 1);	

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.
	m_listBox.SetFont(&m_font);
	m_listBox.SetBkColor(BK_COLOR);
	m_listBox.SetTextBkColor(TEXT_BK_COLOR);

//	m_listBox.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listBox.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


	m_listBox.SetItemState(0 ,LVIS_SELECTED,LVIS_SELECTED);



 m_listBox.InsertColumn(0,"player");    
//    m_listBox.InsertColumn(1,"player");    
    m_listBox.InsertColumn(1,"min");    
    m_listBox.InsertColumn(2,"fgm");    
    m_listBox.InsertColumn(3,"fga");    
    m_listBox.InsertColumn(4,"tgm");
    m_listBox.InsertColumn(5,"tga");    

    m_listBox.InsertColumn(6,"ftm");    
    m_listBox.InsertColumn(7,"fta");    
	m_listBox.InsertColumn(8,"orb");    
	m_listBox.InsertColumn( 9,"reb");    
    m_listBox.InsertColumn(10,"ast");    
    m_listBox.InsertColumn(11,"stl");    
    m_listBox.InsertColumn(12,"to");    
    m_listBox.InsertColumn(13,"blk");    
    m_listBox.InsertColumn(14,"pf");    
    m_listBox.InsertColumn(15,"pts");    
//  m_listBox.InsertColumn(17,"true");    

  
    m_listBox.SetColumnWidth( 0, 120);
    m_listBox.SetColumnWidth( 1, 33);
    m_listBox.SetColumnWidth( 2, 33);
    m_listBox.SetColumnWidth( 3, 33);
    m_listBox.SetColumnWidth( 4, 33);
    m_listBox.SetColumnWidth( 5, 33);
    m_listBox.SetColumnWidth( 6, 33);
    m_listBox.SetColumnWidth( 7, 33);
    m_listBox.SetColumnWidth( 8, 33);
    m_listBox.SetColumnWidth( 9, 33);
    m_listBox.SetColumnWidth( 10, 33);
    m_listBox.SetColumnWidth( 11, 33);
    m_listBox.SetColumnWidth( 12, 33);
    m_listBox.SetColumnWidth( 13, 33);
    m_listBox.SetColumnWidth( 14, 33);
    m_listBox.SetColumnWidth( 15, 33);




	m_listGames.SetBkColor(BK_COLOR);
	m_listGames.SetTextBkColor(TEXT_BK_COLOR);

//	m_listGames.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_listGames.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);


	m_listGames.SetItemState(0 ,LVIS_SELECTED,LVIS_SELECTED);


	 m_listGames.InsertColumn(0,"date");    
    m_listGames.InsertColumn(1,"visitor");    
    m_listGames.InsertColumn(2,"pts");
    m_listGames.InsertColumn(3,"home");    
    m_listGames.InsertColumn(4,"pts");
    m_listGames.InsertColumn(5,"w-l"); 

    m_listGames.SetColumnWidth( 0, 50);
    m_listGames.SetColumnWidth( 1, 99);
    m_listGames.SetColumnWidth( 2, 40);
    m_listGames.SetColumnWidth( 3, 99);
    m_listGames.SetColumnWidth( 4, 40);
    m_listGames.SetColumnWidth( 5, 40);


}

void CBoxDlg::OnColumnclickListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	int index = m_listBox.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	m_column = pNMListView->iSubItem;


CPlayer player_i, player_j;

int p1 = 0, p2 = 12;

for(int i=p1; i<=p2; i++)
{
for(int j=p1; j<=p2; j++)
{


bool swap = false;

	player_i = m_player[i];
	player_j = m_player[j];
	if(player_i.m_name == "" || player_j.m_name == "") continue;

	int fgm_i = player_i.GetFgm();
	int fgm_j = player_j.GetFgm();
	int fga_i = player_i.GetFga();
	int fga_j = player_j.GetFga();
	int tgm_i = player_i.GetTfgm();
	int tgm_j = player_j.GetTfgm();
	int tga_i = player_i.GetTfga();
	int tga_j = player_j.GetTfga();
	int ftm_i = player_i.GetFtm();
	int ftm_j = player_j.GetFtm();
	int fta_i = player_i.GetFta();
	int fta_j = player_j.GetFta();

	int orb_i = player_i.GetOreb();
	int orb_j = player_j.GetOreb();
	int reb_i = player_i.GetOreb();
	int reb_j = player_j.GetOreb();
	int ast_i = player_i.GetAst();
	int ast_j = player_j.GetAst();
	int stl_i = player_i.GetStl();
	int stl_j = player_j.GetStl();
	int to_i = player_i.GetTo();
	int to_j = player_j.GetTo();
	int blk_i = player_i.GetBlk();
	int blk_j = player_j.GetBlk();
	int pf_i = player_i.GetPf();
	int pf_j = player_j.GetPf();
	int pts_i = player_i.m_total_salary;
	int pts_j = player_j.m_total_salary;
//ouble tru_i = player_i.m_trueRating;
//ouble tru_j = player_j.m_trueRating;

switch(m_column) 
{

    case 0:
		swap = player_i.m_name < player_j.m_name;
        break;
    case 1:        
		swap = player_i.GetMin() > player_j.GetMin();
        break;
    case 2:
		swap = fgm_i > fgm_j;
        break;
    case 3:
		swap = fga_i > fga_j;
        break;
    case 4:
		swap = tgm_i > tgm_j;
        break;
    case 5:
		swap = tga_i > tga_j;
        break;
    case 6:
		swap = ftm_i > ftm_j;
        break;
    case 7:
		swap = fta_i > fta_j;
        break;
    case 8:
		swap = orb_i > orb_j;
        break;
    case 9: 
		swap = reb_i > reb_j;
        break;
    case 10:
		swap = ast_i > ast_j;
        break;
    case 11:
		swap = stl_i > stl_j;
        break;
    case 12:
		swap = to_i > to_j;
        break;
    case 13:
		swap = blk_i > blk_j;
        break;
    case 14:
		swap = pf_i > pf_j;
        break;
    case 15:
		swap = pts_i > pts_j;
        break;
    case 16:
        break;
    case 17:
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
		CPlayer temp = m_player[i];
		m_player[i] = m_player[j];
		m_player[j] = temp;
	}


}
}

	DisplayBox();
	
	*pResult = 0;
}

void CBoxDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete [] m_player;
	
}

void CBoxDlg::InitGameStats()
{

}

void CBoxDlg::OnClickListCtrlGames(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	ListGames();





	
	*pResult = 0;
}

void CBoxDlg::ListGames()
{
//	int i = m_listGames.GetCurSel();
	int i = m_listGames.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	
	if(i>=0)
	{
	CString team = m_leagueTeamNames[m_listTeams.GetCurSel()];
	m_currentTeam = m_listGames.GetItemText(i, 1);
	m_visitor = m_currentTeam;
	if(m_visitor == team) m_start = 1; else m_start = 16;
	m_home = m_listGames.GetItemText(i, 3);
	DisplayBox();
	}
}

void CBoxDlg::OnDblclkListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listBox.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);	

	if(i>=0)
	{
		CCareerStatsCardDlg* card = new CCareerStatsCardDlg;
		int last = 0;
		for(int j=0; j<=14; j++)
		{
			card->m_pointer[j] = m_id_list[j];	
			card->m_names_list[j] = m_names_list[j];
			if(m_id_list[j] > 0) last = j;
		}
		card->m_leagueName = m_fileName;
		card->m_player_index = i;
		card->m_pl_index_start = 0;
		card->m_pl_index_end = last;
		card->DoModal();
		delete card;
	}

	*pResult = 0;
}


void CBoxDlg::OnLvnItemchangedListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
