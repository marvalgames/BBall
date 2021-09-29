// PbpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "PbpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPbpDlg dialog


CPbpDlg::CPbpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPbpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPbpDlg)
	//}}AFX_DATA_INIT
}


void CPbpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPbpDlg)
	DDX_Control(pDX, IDC_LIST_CTRL_GAMES, m_listGames);
	DDX_Control(pDX, IDC_COMBO_LIST_TEAMS, m_listTeams);
	DDX_Control(pDX, IDC_LIST_SAVEDPBP, m_listPbp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPbpDlg, CDialog)
	//{{AFX_MSG_MAP(CPbpDlg)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_CBN_SELCHANGE(IDC_COMBO_LIST_TEAMS, OnSelchangeComboListTeams)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_GAMES, OnClickListCtrlGames)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPbpDlg message handlers

BOOL CPbpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitControls();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	for(int i=0; i<=31; i++)
	{
		if(m_leagueTeamNames[i] != "") m_listTeams.AddString(m_leagueTeamNames[i]);
	}

	m_listTeams.SetCurSel(m_default_team);
//	m_listGames.SetCurSel(0);
	m_listGames.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	m_listGames.SetItemState(0,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listGames.EnsureVisible(0, TRUE);


	UpdateData(FALSE);
//	OnSelchangeListTeams();
	OnSelchangeComboListTeams(); 

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CPbpDlg::SetGames()
{

	m_listGames.DeleteAllItems();
	CString team = m_leagueTeamNames[m_listTeams.GetCurSel()];

	CFile file( m_fileName, CFile::modeRead);
	char s[17];
	CString string;

	int bytes = file.Read(s, 14);
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
		int seek = (i-1)*50000+17+32;
		file.Seek( seek, CFile::begin );	


		int bytes = file.Read(s, 4);
		s[bytes] = 0;
		CString month = CString(s);
		int mo = atoi(month) + 10;
		if(mo > 12) mo = mo - 12;


		bytes = file.Read(s, 4);
		s[bytes] = 0;
		CString day = CString(s);
		int da = atoi(day);

		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString vis = CString(s);
		vis.TrimRight();

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		CString score1 = CString(s);

		
		bytes = file.Read(s, 16);
		s[bytes] = 0;
		CString home = CString(s);
		home.TrimRight();

		bytes = file.Read(s, 3);
		s[bytes] = 0;
		CString score2 = CString(s);

		
		if(vis == team || home == team && team != "") 
		{
			m_games[g] = i;
			g = g + 1;
			string.Format("%d/%d %s %s %s %s", mo, da, vis, score1, home, score2);
			int s1 = atoi(score1);
			int s2 = atoi(score2);
			CString res = "win";
			if(s1 < s2 && vis == team) res = "loss";
			else if(s1 > s2 && vis == home) res = "loss";

			CString date;
			date.Format("%d/%d", mo, da);
			m_listGames.InsertItem(row,date);
			m_listGames.SetItemText(row,1,vis);
			m_listGames.SetItemText(row,2, score1);
			m_listGames.SetItemText(row,3,home);
			m_listGames.SetItemText(row,4,score2);
			m_listGames.SetItemText(row,5,res);
			row = row + 1;
//			m_listGames.AddString(string);
		}


	}
	file.Close();
	int count = m_listGames.GetItemCount() - 1;
	if(count >= 0)
	{
	m_listGames.SetItemState(count,LVIS_SELECTED,LVIS_SELECTED);
	m_listGames.SetItemState(count,LVIS_FOCUSED,LVIS_FOCUSED);
	m_listGames.EnsureVisible(count, TRUE);
	}

	UpdateData(FALSE);
}



HBRUSH CPbpDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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


	

void CPbpDlg::OnButtonPrint() 
{
	// TODO: Add your control notification handler code here
	//initialize a structure for my font

	CString pBuf;
	int index = m_listGames.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	CString gameName = m_listGames.GetItemText(index, 0) + " " +  
					m_listGames.GetItemText(index, 1) + " " +
					m_listGames.GetItemText(index, 2) + " " +
					m_listGames.GetItemText(index, 3) + " " +
					m_listGames.GetItemText(index, 4);

       HDC    hdcPrn;
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
           pDC->StartDoc("Saved Play by Play");  // begin a new print job
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

		pBuf = gameName + " play by play";
        pDC->TextOut(-900, 1000, pBuf);// write the string in pbuf
		int items = m_listPbp.GetCount();
		int row = 950;
		int col = -900;
		int onePage = 0;
		for(int i = 1; i<=items; i++)
		{
			m_listPbp.GetText(i-1, pBuf);
			pDC->TextOut(col, row, pBuf);// write the string in pbuf
			row = row - 25;
			onePage = onePage + 1;
			if(onePage == 76)
			{
				pBuf = gameName + " play by play";
				col = col + 600;
				if(col == 900)
				{
					col = -900;
					pDC->EndPage();            // end a page
					pDC->StartPage();            // end a page
				}
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

void CPbpDlg::SetPrintAlign(CDC *pDC, HDC hdcPrn)
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



void CPbpDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolssavedpbp.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

//	WinHelp(HID_VIEW_SAVEDPBP);	
	
}

BOOL CPbpDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolssavedpbp.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
//	WinHelp(HID_VIEW_SAVEDPBP);	
//	return TRUE;
	
}

void CPbpDlg::OnSelchangeComboListTeams() 
{
	// TODO: Add your control notification handler code here
	SetGames();
	OnChangeGames();
	
}

void CPbpDlg::InitControls()
{
	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.
//	SetBkColor(RGB(245,222,186));

	

	m_listGames.SetBkColor(BK_COLOR);
	m_listGames.SetTextBkColor(TEXT_BK_COLOR);
   m_listGames.SetTextColor(RGB(0,0,0));

	m_listGames.SetFont(&m_font);
	m_listGames.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	 m_listGames.InsertColumn(0,"date");    
    m_listGames.InsertColumn(1,"visitor");    
    m_listGames.InsertColumn(2,"pts");    
    m_listGames.InsertColumn(3,"home");    
    m_listGames.InsertColumn(4,"pts");
    m_listGames.InsertColumn(5,"w-l");    


    m_listGames.SetColumnWidth( 0, 36);
    m_listGames.SetColumnWidth( 1, 90);
    m_listGames.SetColumnWidth( 2, 31);
    m_listGames.SetColumnWidth( 3, 90);
    m_listGames.SetColumnWidth( 4, 31);
    m_listGames.SetColumnWidth( 5, 33);
}

void CPbpDlg::OnClickListCtrlGames(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnChangeGames();
	*pResult = 0;
}

void CPbpDlg::OnChangeGames()
{
	m_listPbp.ResetContent();
	int index = m_listGames.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	if(index >= 0) 
	{

	int i = m_games[index];
	CFile file( m_fileName, CFile::modeRead);

	char s[100001];
	if(i>0) 
	{
	
	int seek = (i-1)*50000+17+46+32;
	file.Seek( seek, CFile::begin );	
	CString string;

//for(int i=1; i<=250; i++)
//{
	
	int bytes = file.Read(s, 50000);
	s[bytes] = 0;
	string = CString(s);
    
	int offset = 0;
	int n = 0;

	do
	{
	n = string.Find("\n" , offset);
    if(n-offset>0)
	{
		CString result = string.Mid(offset, n-offset);
	    m_listPbp.AddString(result);
	}

	offset = n + 1; 
	} 
    while(n > -1);
    m_listPbp.AddString(" ");
//}
	


file.Close();	
	}


	}

}
