// PlayoffDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "PlayoffDlg.h"
//#include "LeagueTeamsDlg.h"

#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 


//#include "Playoff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayoffDlg dialog


CPlayoffDlg::CPlayoffDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayoffDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayoffDlg)
	//}}AFX_DATA_INIT
}


void CPlayoffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayoffDlg)
	DDX_Control(pDX, IDC_LIST_RESULTS, m_list_results);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayoffDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayoffDlg)
	ON_WM_CTLCOLOR()
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayoffDlg message handlers

BOOL CPlayoffDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
myBrush2.CreateSolidBrush(LISTBOXCOLOR); 
	
	CPlayoff* po;
	po = new CPlayoff;
  	
	CString	m_playoffFormat,m_rd1Format,m_rd2Format,m_rd3Format,m_rd4Format,m_conferenceName1,
		m_conferenceName2,m_divisionName1,m_divisionName2,m_divisionName3,m_divisionName4;

  	CString file_name = m_path + m_leagueName;
	

	//po->LoadStandings(file_name, 
	//	m_playoffFormat,m_rd1Format,m_rd2Format,m_rd3Format,m_rd4Format,m_conferenceName1,
  	//	m_conferenceName2,m_divisionName1,m_divisionName2,m_divisionName3,m_divisionName4);
	
	for(int i=0; i<=31; i++)
	{
		po->record[i] = m_record[i];
	}


	
	CString pFileName = m_path + m_leagueName + ".sch";
	CString lines[1023];


	int num_lines = po->ReadPlayoffResults(pFileName, m_leagueTeamNames);






		for(int li=0; li<=num_lines; li++)
		{
			m_list_results.AddString(po->list[li]);
		}
		int items = m_list_results.GetCount();
		m_list_results.SetCurSel(items - 1);

		delete po;


		UpdateData(FALSE);
		return TRUE;
}


HBRUSH CPlayoffDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
          //pDC->SetTextColor(LISTBOXTEXTCOLOR);
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



BOOL CPlayoffDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	WinHelp(HID_LEAGUE_PLAYOFFS);	
	return TRUE;
}

void CPlayoffDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	WinHelp(HID_LEAGUE_PLAYOFFS);	
}


void CPlayoffDlg::OnButtonPrint() 
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
           pDC->StartDoc("Playoff Results");  // begin a newe print job
                                   // for Win32 use
                                   // CDC::StartDoc(LPDOCINFO) override
           pDC->StartPage();          // begin a newe page
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
	strcpy_s(logFont.lfFaceName, "Arial");

	CFont font;
	font.CreateFontIndirect(&logFont);
	CFont* oldFont = pDC->SelectObject(&font);

//		pBuf = "Name               g  mpg  fgm  fga   fg% 3gm  3ga   3g%  ftm  fta   ft%   ppg";
//		pBuf = "Name               pos  2ga  2g%  fta  ft%  3ga  3g%  orb  drb  ast  stl  to   blk";
		pBuf = m_leagueName + " Playoff Results";
        pDC->TextOut(-900, 1000, pBuf);// write the string in pbuf
		int items = m_list_results.GetCount();
		int row = 950;
		int col = -900;
		int onePage = 0;
		for(int i = 1; i<=items; i++)
		{
			m_list_results.GetText(i-1, pBuf);
			pDC->TextOut(col, row, pBuf);// write the string in pbuf
			row = row - 25;
			onePage = onePage + 1;
			if(onePage == 76)
			{
				pBuf = m_leagueName + " Playoff Results";
				col = col + 600;
				if(col == 900) 
				{
					col = -900;
					pDC->EndPage();            // end a page
					pDC->StartPage();            // end a page
				}

				row = 950;
				pDC->TextOut(col, 1000, pBuf);// write the string in pbuf
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

void CPlayoffDlg::SetPrintAlign(CDC *pDC, HDC hdcPrn)
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


