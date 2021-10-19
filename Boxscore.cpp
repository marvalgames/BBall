// Boxscore.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "Boxscore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBoxscore dialog


CBoxscore::CBoxscore(CWnd* pParent /*=NULL*/)
	: CDialog(CBoxscore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBoxscore)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBoxscore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBoxscore)
	DDX_Control(pDX, IDC_LIST_PBP, m_listPBP);
	DDX_Control(pDX, IDC_BUTTON_PRINT, m_button[0]);
	DDX_Control(pDX, IDOK, m_button[1]);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBoxscore, CDialog)
	//{{AFX_MSG_MAP(CBoxscore)
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBoxscore message handlers

void CBoxscore::DisplayPBP()
{

for(int i=0; i<=3200; i++)
{
	if(m_playByPlay[i] == "") continue;
	CString str = m_playByPlay[i];	
//	CString s1, s2;
    int offset = 0;
	int n = 0;

//	do
//	{
//	n = m_playByPlay[i].Find("\n" , offset);
  //  if(n-offset>0)
	//{
	//	CString result = str.Mid(offset, n-offset);
	  //  m_listPBP.AddString(result);
	//}

	//offset = n + 1; 
	//} 
    //while(n > -1);
	

    m_listPBP.AddString(str);
}

}

BOOL CBoxscore::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	DisplayPBP();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CBoxscore::OnButtonPrint() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	//initialize a structure for my font

	CString pBuf;

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
           pDC->StartDoc("Game Play by Play");  // begin a new print job
                                   // for Win32 use
                                   // CDC::StartDoc(LPDOCINFO) override
           pDC->StartPage();          // begin a new page
           SetPrintAlign(pDC, hdcPrn);// set the printing alignment

	LOGFONT logFont;
	logFont.lfHeight = 16;
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
	strcpy_s(logFont.lfFaceName, USERFONT);

	CFont font;
	font.CreateFontIndirect(&logFont);
	CFont* oldFont = pDC->SelectObject(&font);

//		pBuf = "Name               g  mpg  fgm  fga   fg% 3gm  3ga   3g%  ftm  fta   ft%   ppg";
//		pBuf = "Name               pos  2ga  2g%  fta  ft%  3ga  3g%  orb  drb  ast  stl  to   blk";
		pBuf = "Game Play by Play";
        pDC->TextOut(-900, 1000, pBuf);// write the string in pbuf
		int items = m_listPBP.GetCount();
		int row = 950;
		int col = -900;
		int onePage = 0;
		for(int i = 1; i<=items; i++)
		{
			m_listPBP.GetText(i-1, pBuf);
			pDC->TextOut(col, row, pBuf);// write the string in pbuf
			row = row - 25;
			onePage = onePage + 1;
			if(onePage == 76)
			{
				pBuf = "Game Play by Play";
				col = col + 600;
				if(col == 900)
				{
				    pDC->EndPage();            // end a page
				    pDC->StartPage();            // start a page			
					col = -900;
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

void CBoxscore::SetPrintAlign(CDC *pDC, HDC hdcPrn)
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



BOOL CBoxscore::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	//WinHelp(HID_STATS_GAME_PBP);	
	//return TRUE;
	
	return CDialog::OnHelpInfo(pHelpInfo);
}

void CBoxscore::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_STATS_GAME_PBP);	
//	return TRUE;
	
}

HBRUSH CBoxscore::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
          //pDC->SetBkColor(LISTBOXCOLOR);
         // pDC->SetTextColor(LISTBOXTEXTCOLOR);
         // return myBrush;

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
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
