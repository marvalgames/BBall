// BBall.cpp : Defines the class behaviors for the application.
//



#include "stdafx.h"


#include "BBall.h"

#include "mainfrm.h"
#include "bballdoc.h"
#include "bballview.h"

#include "scheduleview.h"
#include "gameview.h"
#include "teamview.h"
#include "standingsview.h"
#include "bballcoachview.h"
#include "historyview.h"
#include "toolsview.h"
#include "progressview.h"

#include "Splash1.h"
//#include "MyFormView.h"
//#include "FormViewX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBBallApp

BEGIN_MESSAGE_MAP(CBBallApp, CWinApp)
	//{{AFX_MSG_MAP(CBBallApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBallApp construction

CBBallApp::CBBallApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
    EnableHtmlHelp();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBBallApp object

CBBallApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBBallApp initialization

BOOL CBBallApp::InitInstance()
{
	// CG: The following block was added by the Splash Screen component.
\
	{
\
		CCommandLineInfo cmdInfo;
\
		ParseCommandLine(cmdInfo);
\

\
//		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
\
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

//	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

#ifdef _AFXDLL
//	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


//	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
//MyButton::EnableWindowsTheming();
	


	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBBallDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CBBallView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;


 /*** Begin modification of default InitInstance ***/

	m_nCmdShow = SW_SHOW;

	//SetDialogBkColor(RGB(191,206,255), RGB(0, 0, 0));

     m_pMainWnd->SetWindowText("JUMP SHOT BASKETBALL");	
    
    m_nCurView = 0;        // Save index of the currently active view class
    
    // Keep array of views as member of WinApp
    
    CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();

    m_pViews[0] = pActiveView;
    m_pViews[1] = (CView*) new CScheduleView;
	m_pViews[2] = (CView*) new CGameView;
	m_pViews[3] = (CView*) new CTeamView;
	m_pViews[4] = (CView*) new CStandingsView;
	m_pViews[5] = (CView*) new CBBallCoachView;
	m_pViews[6] = (CView*) new CHistoryView;
	m_pViews[7] = (CView*) new CToolsView;
	m_pViews[8] = (CView*) new CProgressView;
    
    
    CDocument* pCurrentDoc =
     ((CFrameWnd*) m_pMainWnd)->GetActiveDocument();
    
    // Initialize a CCreateContext to point to the active document.
    // With this context, the new view is added to the document
    // when the view is created in CView::OnCreate().
    CCreateContext newContext;
    newContext.m_pNewViewClass = NULL;
    newContext.m_pNewDocTemplate = NULL;
    newContext.m_pLastView = NULL;
    newContext.m_pCurrentFrame = NULL;
    newContext.m_pCurrentDoc = pCurrentDoc;
    
    // The ID of the initial active view is AFX_IDW_PANE_FIRST.
    // Incrementing this value by one for additional views works
    // in the standard document/view case but the technique cannot
    // be extended for the CSplitterWnd case.
    UINT viewID[9];
    viewID[1] = AFX_IDW_PANE_FIRST + 1;
    viewID[2] = AFX_IDW_PANE_FIRST + 2;    
    viewID[3] = AFX_IDW_PANE_FIRST + 3;    
    viewID[4] = AFX_IDW_PANE_FIRST + 4;    
    viewID[5] = AFX_IDW_PANE_FIRST + 5;    
    viewID[6] = AFX_IDW_PANE_FIRST + 6;    
    viewID[7] = AFX_IDW_PANE_FIRST + 7;    
    viewID[8] = AFX_IDW_PANE_FIRST + 8;    
    CRect rect(0, 0, 0, 0); // gets resized later
    
    // Need to cast pointers to have correct Create functions called
	// CForm2 is CFormView::Create
	for ( int nView=1; nView<NUMVIEWS; nView++ )
    {
        // Create the new view. In this example, the view persists for
        // the life of the application. The application automatically
        // deletes the view when the application is closed.
        m_pViews[nView]->Create(NULL, NULL,
				(AFX_WS_DEFAULT_VIEW & ~WS_VISIBLE),
			// views are created with the style of AFX_WS_DEFAULT_VIEW
			// In MFC 4.0, this is (WS_BORDER | WS_VISIBLE | WS_CHILD)
		                rect, m_pMainWnd,
				viewID[nView], &newContext);

//		CRect rectView;
//		GetClientRect(NULL, rectView );


       m_pViews[nView]->SetWindowPos(NULL ,0,0,0,0,NULL);
       //::SetWindowPos(pActiveView->m_hWnd, HWND_TOPMOST, 0, 0, 1366, 768, SWP_NOZORDER);

	

    }

    // When a document template creates a view, the WM_INITIALUPDATE
    // message is sent automatically. However, this code must
    // explicitly send the message, as follows.

	srand( (unsigned)time( NULL ) );	
	

    ((CScheduleView*)m_pViews[1])->OnInitialUpdate();
    ((CGameView*)m_pViews[2])->OnInitialUpdate();
    ((CTeamView*)m_pViews[3])->OnInitialUpdate();
    ((CStandingsView*)m_pViews[4])->OnInitialUpdate();
    ((CBBallCoachView*)m_pViews[5])->OnInitialUpdate();
    ((CHistoryView*)m_pViews[6])->OnInitialUpdate();
    ((CToolsView*)m_pViews[7])->OnInitialUpdate();
    ((CProgressView*)m_pViews[8])->OnInitialUpdate();


//	SwitchView(1);   
//	SwitchView(0);   
//	SwitchView(2);   
//	SwitchView(3);   
//	SwitchView(4);   
//	SwitchView(5);   
//	SwitchView(6);   
//	SwitchView(7);   
//	SwitchView(8);   


	SwitchView(0);   
//	SwitchView(1);   //now draw transparent
//	SwitchView(0);   


    
    /*** End modification of default InitInstance ***/


	return TRUE;


}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// App command to run the dialog
void CBBallApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBBallApp message handlers


CView* CBBallApp::SwitchView(UINT nIndex)
{


    ASSERT( nIndex >=0 && nIndex < NUMVIEWS );
    
    CView* pNewView = m_pViews[nIndex];
    
    CView* pActiveView =
    ((CFrameWnd*) m_pMainWnd)->GetActiveView();

	//pActiveView->Invalidate();
    
    if ( !pActiveView )    // No currently active view
        return NULL;

//	pNewView->Invalidate();


    if ( pNewView == pActiveView )    // Already there
        return pActiveView;
        
    // Update Doc's data if needed
    // Don't change view if data valiation fails
    if ( ! SaveActiveViewsData() )
    {
        return pActiveView;
    }

    m_nCurView = nIndex;    // Store the new current view's index
    
    // exchange view window ID's so RecalcLayout() works
    UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
    ::SetWindowLong(pActiveView->m_hWnd, GWL_ID,
          ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
    ::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);


    //::SetWindowPos(pActiveView->m_hWnd, HWND_TOPMOST, 0, 0, 1366, 768, SWP_NOZORDER);


    // Display and update the new current view - hide the old one    
    pActiveView->ShowWindow(SW_HIDE);
    pNewView->ShowWindow(SW_SHOW);
    ((CFrameWnd*) m_pMainWnd)->SetActiveView(pNewView);
    ((CFrameWnd*) m_pMainWnd)->RecalcLayout();
    return pActiveView;
}

BOOL CBBallApp::SaveActiveViewsData()
{
    CView* pActiveView =
    ((CFrameWnd*) m_pMainWnd)->GetActiveView();
    
    if ( !pActiveView )
        return TRUE;    // No active view TO save data from, so count as success

    // Update Doc's data
    // Don't exit if data valiation fails
    // This could be done with a base class to avoid mulitple if's.
    if ( pActiveView->IsKindOf( RUNTIME_CLASS(CScheduleView) ) )
    {
        if ( !((CScheduleView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CGameView) ) )
    {
        if ( !((CGameView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CTeamView) ) )
    {
        if ( !((CTeamView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CStandingsView) ) )
    {
        if ( !((CStandingsView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CBBallCoachView) ) )
    {
        if ( !((CBBallCoachView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CHistoryView) ) )
    {
        if ( !((CHistoryView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CToolsView) ) )
    {
        if ( !((CToolsView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    else if ( pActiveView->IsKindOf( RUNTIME_CLASS(CProgressView) ) )
    {
        if ( !((CProgressView*)pActiveView)->SetToDoc() )
            return FALSE;    // Validation failed
    }
    return TRUE;    // Not a view with data to save!
}


BOOL CBBallApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
//	if (CSplashWnd::PreTranslateAppMessage(pMsg))
//		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}



int CBBallApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
//	Gdiplus::GdiplusShutdown(m_gdiplusToken);	
	return CWinApp::ExitInstance();
}




HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{


	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
