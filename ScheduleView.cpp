// ScheduleView.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
#include "MyComboBox.h"
#include "ScheduleView.h"
#include "BBallDoc.h"
#include "StatsDlg.h"
#include "PlayoffDlg.h"
#include "TypeGameDlg.h"
#ifndef AllStarWeekend_h
#include "AllStarWeekend.h"	// Added by ClassView
#define AllStarWeekend_h
#endif


//#include "Disk.h"
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
#ifndef Engine_h
#include "Engine.h"
#define Engine_h
#endif 

#ifndef Computer_h
#include "Computer.h"
#define Computer_h
#endif 



#ifndef ShadeButtonST_h
#include "ShadeButtonST.h"
#define ShadeButtonST_h
#endif 

//#include "Constants.h"
//#include "Playoff.h"
#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 



#ifndef AllStarWeekend_h
#include "AllStarWeekend.h"	// Added by ClassView
#define AllStarWeekend_h
#endif
//#include "AllStarWeekend.h"
#include "AllStarDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScheduleView

IMPLEMENT_DYNCREATE(CScheduleView, CFormView)

CScheduleView::CScheduleView()
	: CFormView(CScheduleView::IDD)
{
	//{{AFX_DATA_INIT(CScheduleView)
	//}}AFX_DATA_INIT
	
	m_sim_season = false;
	m_xdays = 15;
	m_sim_ok = false;
	m_asw_button_pressed = false;
//	bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
  //                  MAKEINTRESOURCE(IDB_BITMAP_BK)));

	m_single_team = 0;

	m_days_in_month[0] = 31;
	m_days_in_month[1] = 30;
	m_days_in_month[2] = 31;
	m_days_in_month[3] = 31;
	m_days_in_month[4] = 29;
	m_days_in_month[5] = 31;
	m_days_in_month[6] = 30;
	m_days_in_month[7] = 31;
	m_days_in_month[8] = 30;
	m_days_in_month[9] = 31;
	m_days_in_month[10] = 31;
	m_days_in_month[11] = 30;
	m_days_in_month[12] = 28;

	CPngImage pngImage;
	pngImage.Load(IDB_PNG_BK, AfxGetResourceHandle());
	m_bmp = new CBitmap;
	m_bmp->Attach(pngImage.Detach());
	m_bmp->SetBitmapDimension(512, 512); /* if the size of bitmap is 50 by 40 */



	//m_pDropBtn = new CDropButton();
	//m_pDropBtn->Create("Options", CRect(100,100,280,120), this, ID_DROP_BUTTON);
}

CScheduleView::~CScheduleView()
{
//	delete m_pDropBtn;

	delete m_bmp;


}

void CScheduleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScheduleView)
	DDX_Control(pDX, IDC_SLIDER_DAYS, m_slider_days);
	DDX_Control(pDX, IDC_BUTTON_SIMDAYS, m_sim_x);
	DDX_Control(pDX, IDC_BUTTON_GO, m_button_go);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_button_previous);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_button_next);
	DDX_Control(pDX, IDC_BUTTON_GAMETYPE, m_button_gametype);
	DDX_Control(pDX, IDC_BUTTON_SIMTILASW, m_button_sim_til_asw);
	DDX_Control(pDX, IDC_COMBO_TEAMS, m_combo_teams);
	DDX_Control(pDX, IDC_BUTTON_TOOLS, m_button_tools);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_button_history);
	DDX_Control(pDX, IDC_BUTTON_PROGRESS, m_button_progress);
	DDX_Control(pDX, IDC_BUTTON_SIM_MONTH, m_sim_month);
	DDX_Control(pDX, IDC_BUTTON_SIM_WEEK, m_sim_week);
	DDX_Control(pDX, IDC_BUTTON_SIMDAY, m_sim_day);
	DDX_Control(pDX, IDC_COMBO_MONTH, m_combo_month);
	DDX_Control(pDX, IDC_COMBO_DAY, m_combo_day);
	DDX_Control(pDX, IDC_BUTTON_STANDINGS, m_button_standings);
	DDX_Control(pDX, IDC_BUTTON_SCHEDULE, m_button_schedule);
	DDX_Control(pDX, IDC_BUTTON_SETUP, m_button_setup);
	DDX_Control(pDX, IDC_BUTTON_ASW, m_button_asw);
	DDX_Control(pDX, IDC_BUTTON_SIM_PLAYOFFS, m_button_sim_season);
	DDX_Control(pDX, IDC_BUTTON_START_PLAYOFF, m_button_start_playoff);
	DDX_Control(pDX, IDC_BUTTON_STOP_SIM, m_button_stop_sim);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_STATIC_V1, m_static_score[1]);
	DDX_Control(pDX, IDC_STATIC_H1, m_static_score[2]);
	DDX_Control(pDX, IDC_STATIC_V2, m_static_score[3]);
	DDX_Control(pDX, IDC_STATIC_H2, m_static_score[4]);
	DDX_Control(pDX, IDC_STATIC_V3, m_static_score[5]);
	DDX_Control(pDX, IDC_STATIC_H3, m_static_score[6]);
	DDX_Control(pDX, IDC_STATIC_V4, m_static_score[7]);
	DDX_Control(pDX, IDC_STATIC_H4, m_static_score[8]);
	DDX_Control(pDX, IDC_STATIC_V5, m_static_score[9]);
	DDX_Control(pDX, IDC_STATIC_H5, m_static_score[10]);
	DDX_Control(pDX, IDC_STATIC_V6, m_static_score[11]);
	DDX_Control(pDX, IDC_STATIC_H6, m_static_score[12]);
	DDX_Control(pDX, IDC_STATIC_V7, m_static_score[13]);
	DDX_Control(pDX, IDC_STATIC_H7, m_static_score[14]);
	DDX_Control(pDX, IDC_STATIC_V8, m_static_score[15]);
	DDX_Control(pDX, IDC_STATIC_H8, m_static_score[16]);
	DDX_Control(pDX, IDC_STATIC_V9, m_static_score[17]);
	DDX_Control(pDX, IDC_STATIC_H9, m_static_score[18]);
	DDX_Control(pDX, IDC_STATIC_V10,m_static_score[19]);
	DDX_Control(pDX, IDC_STATIC_H10,m_static_score[20]);
	DDX_Control(pDX, IDC_STATIC_V11,m_static_score[21]);
	DDX_Control(pDX, IDC_STATIC_H11,m_static_score[22]);
	DDX_Control(pDX, IDC_STATIC_V12,m_static_score[23]);
	DDX_Control(pDX, IDC_STATIC_H12,m_static_score[24]);
	DDX_Control(pDX, IDC_STATIC_V13,m_static_score[25]);
	DDX_Control(pDX, IDC_STATIC_H13,m_static_score[26]);
	DDX_Control(pDX, IDC_STATIC_V14,m_static_score[27]);
	DDX_Control(pDX, IDC_STATIC_H14,m_static_score[28]);
	DDX_Control(pDX, IDC_STATIC_V15,m_static_score[29]);
	DDX_Control(pDX, IDC_STATIC_H15,m_static_score[30]);
	DDX_Control(pDX, IDC_STATIC_V16,m_static_score[31]);
	DDX_Control(pDX, IDC_STATIC_H16,m_static_score[32]);

	DDX_Control(pDX, IDC_BUTTON1, m_buttons[1]);
	DDX_Control(pDX, IDC_BUTTON9, m_buttons[9]);
	DDX_Control(pDX, IDC_BUTTON8, m_buttons[8]);
	DDX_Control(pDX, IDC_BUTTON7, m_buttons[7]);
	DDX_Control(pDX, IDC_BUTTON6, m_buttons[6]);
	DDX_Control(pDX, IDC_BUTTON5, m_buttons[5]);
	DDX_Control(pDX, IDC_BUTTON4, m_buttons[4]);
	DDX_Control(pDX, IDC_BUTTON32, m_buttons[32]);
	DDX_Control(pDX, IDC_BUTTON31, m_buttons[31]);
	DDX_Control(pDX, IDC_BUTTON30, m_buttons[30]);
	DDX_Control(pDX, IDC_BUTTON3, m_buttons[3]);
	DDX_Control(pDX, IDC_BUTTON29, m_buttons[29]);
	DDX_Control(pDX, IDC_BUTTON28, m_buttons[28]);
	DDX_Control(pDX, IDC_BUTTON27, m_buttons[27]);
	DDX_Control(pDX, IDC_BUTTON26, m_buttons[26]);
	DDX_Control(pDX, IDC_BUTTON25, m_buttons[25]);
	DDX_Control(pDX, IDC_BUTTON24, m_buttons[24]);
	DDX_Control(pDX, IDC_BUTTON23, m_buttons[23]);
	DDX_Control(pDX, IDC_BUTTON22, m_buttons[22]);
	DDX_Control(pDX, IDC_BUTTON21, m_buttons[21]);
	DDX_Control(pDX, IDC_BUTTON20, m_buttons[20]);
	DDX_Control(pDX, IDC_BUTTON2, m_buttons[2]);
	DDX_Control(pDX, IDC_BUTTON19, m_buttons[19]);
	DDX_Control(pDX, IDC_BUTTON18, m_buttons[18]);
	DDX_Control(pDX, IDC_BUTTON17, m_buttons[17]);
	DDX_Control(pDX, IDC_BUTTON16, m_buttons[16]);
	DDX_Control(pDX, IDC_BUTTON15, m_buttons[15]);
	DDX_Control(pDX, IDC_BUTTON14, m_buttons[14]);
	DDX_Control(pDX, IDC_BUTTON13, m_buttons[13]);
	DDX_Control(pDX, IDC_BUTTON12, m_buttons[12]);
	DDX_Control(pDX, IDC_BUTTON11, m_buttons[11]);
	DDX_Control(pDX, IDC_BUTTON10, m_buttons[10]);

	DDX_Control(pDX, IDC_BUTTON_COACH1, m_buttons[33]);
	DDX_Control(pDX, IDC_BUTTON_COACH2, m_buttons[34]);
	DDX_Control(pDX, IDC_BUTTON_COACH3, m_buttons[35]);
	DDX_Control(pDX, IDC_BUTTON_COACH4, m_buttons[36]);
	DDX_Control(pDX, IDC_BUTTON_COACH5, m_buttons[37]);
	DDX_Control(pDX, IDC_BUTTON_COACH6, m_buttons[38]);
	DDX_Control(pDX, IDC_BUTTON_COACH7, m_buttons[39]);
	DDX_Control(pDX, IDC_BUTTON_COACH8, m_buttons[40]);
	DDX_Control(pDX, IDC_BUTTON_COACH9, m_buttons[41]);
	DDX_Control(pDX, IDC_BUTTON_COACH10, m_buttons[42]);
	DDX_Control(pDX, IDC_BUTTON_COACH11, m_buttons[43]);
	DDX_Control(pDX, IDC_BUTTON_COACH12, m_buttons[44]);
	DDX_Control(pDX, IDC_BUTTON_COACH13, m_buttons[45]);
	DDX_Control(pDX, IDC_BUTTON_COACH14, m_buttons[46]);
	DDX_Control(pDX, IDC_BUTTON_COACH15, m_buttons[47]);
	DDX_Control(pDX, IDC_BUTTON_COACH16, m_buttons[48]);

	DDX_Control(pDX, IDC_BUTTON_BOX1, m_buttons[49]);
	DDX_Control(pDX, IDC_BUTTON_BOX2, m_buttons[50]);
	DDX_Control(pDX, IDC_BUTTON_BOX3, m_buttons[51]);
	DDX_Control(pDX, IDC_BUTTON_BOx4, m_buttons[52]);
	DDX_Control(pDX, IDC_BUTTON_BOX5, m_buttons[53]);
	DDX_Control(pDX, IDC_BUTTON_BOX6, m_buttons[54]);
	DDX_Control(pDX, IDC_BUTTON_BOX7, m_buttons[55]);
	DDX_Control(pDX, IDC_BUTTON_BOX8, m_buttons[56]);
	DDX_Control(pDX, IDC_BUTTON_BOX9, m_buttons[57]);
	DDX_Control(pDX, IDC_BUTTON_BOX10, m_buttons[58]);
	DDX_Control(pDX, IDC_BUTTON_BOX11, m_buttons[59]);
	DDX_Control(pDX, IDC_BUTTON_BOX12, m_buttons[60]);
	DDX_Control(pDX, IDC_BUTTON_BOX13, m_buttons[61]);
	DDX_Control(pDX, IDC_BUTTON_BOX14, m_buttons[62]);
	DDX_Control(pDX, IDC_BUTTON_BOX15, m_buttons[63]);
	DDX_Control(pDX, IDC_BUTTON_BOX16, m_buttons[64]);


	DDX_Control(pDX, IDC_BUTTON_SIM_1, m_buttons[65]);
	DDX_Control(pDX, IDC_BUTTON_SIM_2, m_buttons[66]);
	DDX_Control(pDX, IDC_BUTTON_SIM_3, m_buttons[67]);
	DDX_Control(pDX, IDC_BUTTON_SIM_4, m_buttons[68]);
	DDX_Control(pDX, IDC_BUTTON_SIM_5, m_buttons[69]);
	DDX_Control(pDX, IDC_BUTTON_SIM_6, m_buttons[70]);
	DDX_Control(pDX, IDC_BUTTON_SIM_7, m_buttons[71]);
	DDX_Control(pDX, IDC_BUTTON_SIM_8, m_buttons[72]);
	DDX_Control(pDX, IDC_BUTTON_SIM_9, m_buttons[73]);
	DDX_Control(pDX, IDC_BUTTON_SIM_10, m_buttons[74]);
	DDX_Control(pDX, IDC_BUTTON_SIM_11, m_buttons[75]);
	DDX_Control(pDX, IDC_BUTTON_SIM_12, m_buttons[76]);
	DDX_Control(pDX, IDC_BUTTON_SIM_13, m_buttons[77]);
	DDX_Control(pDX, IDC_BUTTON_SIM_14, m_buttons[78]);
	DDX_Control(pDX, IDC_BUTTON_SIM_15, m_buttons[79]);
	DDX_Control(pDX, IDC_BUTTON_SIM_16, m_buttons[80]);




}


BEGIN_MESSAGE_MAP(CScheduleView, CFormView)
	//{{AFX_MSG_MAP(CScheduleView)
	ON_WM_ERASEBKGND()
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH, OnSelchangeComboMonth)
	ON_CBN_SELCHANGE(IDC_COMBO_DAY, OnSelchangeComboDay)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, OnButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_STANDINGS, OnButtonStandings)
	ON_COMMAND(ID_SETUP_LOAD, OnSetupLoad)
	ON_BN_CLICKED(IDC_BUTTON_SETUP, OnButtonSetup)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAMS, OnSelchangeComboTeams)
	ON_BN_CLICKED(IDC_BUTTON_SIM_1, OnButtonSim1)
	ON_BN_CLICKED(IDC_BUTTON_SIM_10, OnButtonSim10)
	ON_BN_CLICKED(IDC_BUTTON_SIM_11, OnButtonSim11)
	ON_BN_CLICKED(IDC_BUTTON_SIM_12, OnButtonSim12)
	ON_BN_CLICKED(IDC_BUTTON_SIM_13, OnButtonSim13)
	ON_BN_CLICKED(IDC_BUTTON_SIM_14, OnButtonSim14)
	ON_BN_CLICKED(IDC_BUTTON_SIM_15, OnButtonSim15)
	ON_BN_CLICKED(IDC_BUTTON_SIM_16, OnButtonSim16)
	ON_BN_CLICKED(IDC_BUTTON_SIM_2, OnButtonSim2)
	ON_BN_CLICKED(IDC_BUTTON_SIM_3, OnButtonSim3)
	ON_BN_CLICKED(IDC_BUTTON_SIM_4, OnButtonSim4)
	ON_BN_CLICKED(IDC_BUTTON_SIM_5, OnButtonSim5)
	ON_BN_CLICKED(IDC_BUTTON_SIM_6, OnButtonSim6)
	ON_BN_CLICKED(IDC_BUTTON_SIM_7, OnButtonSim7)
	ON_BN_CLICKED(IDC_BUTTON_SIM_8, OnButtonSim8)
	ON_BN_CLICKED(IDC_BUTTON_SIM_9, OnButtonSim9)
	ON_BN_CLICKED(IDC_BUTTON_SIMDAY, OnButtonSimday)
	ON_BN_CLICKED(IDC_BUTTON_SIM_MONTH, OnButtonSimMonth)
	ON_BN_CLICKED(IDC_BUTTON_SIM_WEEK, OnButtonSimWeek)
	ON_BN_CLICKED(IDC_BUTTON_STOP_SIM, OnButtonStopSim)
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS, OnButtonProgress)
	ON_BN_CLICKED(IDC_BUTTON_HISTORY, OnButtonHistory)
	ON_BN_CLICKED(IDC_BUTTON_TOOLS, OnButtonTools)
	ON_BN_CLICKED(IDC_BUTTON_START_PLAYOFF, OnButtonStartPlayoff)
	ON_BN_CLICKED(IDC_BUTTON_SIM_PLAYOFFS, OnButtonSimPlayoffs)
	ON_BN_CLICKED(IDC_BUTTON_BOX1, OnButtonBox1)
	ON_BN_CLICKED(IDC_BUTTON_BOX2, OnButtonBox2)
	ON_BN_CLICKED(IDC_BUTTON_BOX10, OnButtonBox10)
	ON_BN_CLICKED(IDC_BUTTON_BOX11, OnButtonBox11)
	ON_BN_CLICKED(IDC_BUTTON_BOX12, OnButtonBox12)
	ON_BN_CLICKED(IDC_BUTTON_BOX13, OnButtonBox13)
	ON_BN_CLICKED(IDC_BUTTON_BOX14, OnButtonBox14)
	ON_BN_CLICKED(IDC_BUTTON_BOX15, OnButtonBox15)
	ON_BN_CLICKED(IDC_BUTTON_BOX16, OnButtonBox16)
	ON_BN_CLICKED(IDC_BUTTON_BOX3, OnButtonBox3)
	ON_BN_CLICKED(IDC_BUTTON_BOx4, OnBUTTONBOX4)
	ON_BN_CLICKED(IDC_BUTTON_BOX5, OnButtonBox5)
	ON_BN_CLICKED(IDC_BUTTON_BOX6, OnButtonBox6)
	ON_BN_CLICKED(IDC_BUTTON_BOX7, OnButtonBox7)
	ON_BN_CLICKED(IDC_BUTTON_BOX8, OnButtonBox8)
	ON_BN_CLICKED(IDC_BUTTON_BOX9, OnButtonBox9)
	ON_BN_CLICKED(IDC_BUTTON_COACH1, OnButtonCoach1)
	ON_BN_CLICKED(IDC_BUTTON_COACH10, OnButtonCoach10)
	ON_BN_CLICKED(IDC_BUTTON_COACH11, OnButtonCoach11)
	ON_BN_CLICKED(IDC_BUTTON_COACH12, OnButtonCoach12)
	ON_BN_CLICKED(IDC_BUTTON_COACH13, OnButtonCoach13)
	ON_BN_CLICKED(IDC_BUTTON_COACH14, OnButtonCoach14)
	ON_BN_CLICKED(IDC_BUTTON_COACH15, OnButtonCoach15)
	ON_BN_CLICKED(IDC_BUTTON_COACH16, OnButtonCoach16)
	ON_BN_CLICKED(IDC_BUTTON_COACH2, OnButtonCoach2)
	ON_BN_CLICKED(IDC_BUTTON_COACH3, OnButtonCoach3)
	ON_BN_CLICKED(IDC_BUTTON_COACH4, OnButtonCoach4)
	ON_BN_CLICKED(IDC_BUTTON_COACH5, OnButtonCoach5)
	ON_BN_CLICKED(IDC_BUTTON_COACH6, OnButtonCoach6)
	ON_BN_CLICKED(IDC_BUTTON_COACH7, OnButtonCoach7)
	ON_BN_CLICKED(IDC_BUTTON_COACH8, OnButtonCoach8)
	ON_BN_CLICKED(IDC_BUTTON_COACH9, OnButtonCoach9)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON21, OnButton21)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON_GAMETYPE, OnButtonGametype)
	ON_BN_CLICKED(IDC_BUTTON_SIMTILASW, OnButtonSimtilasw)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_ASW, OnButtonAsw)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_COMMAND(ID_SETUP_SETTINGS, OnSetupSettings)
	ON_COMMAND(ID_SETUP_SETGAMEPLAN, OnSetupSetgameplan)
	ON_COMMAND(ID_SETUP_PROPOSETRADE, OnSetupProposetrade)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_TEAM_ROSTER, OnTeamRoster)
	ON_COMMAND(ID_TEAM_RESULTS, OnTeamResults)
	ON_COMMAND(ID_TEAM_BUDGET, OnTeamBudget)
	ON_COMMAND(ID_TEAM_DRAFTPREVIEW, OnTeamDraftpreview)
	ON_COMMAND(ID_TEAM_FREEAGENTS, OnTeamFreeagents)
	ON_COMMAND(ID_TEAM_HISTORY, OnTeamHistory)
	ON_COMMAND(ID_TEAM_LINEUP, OnTeamLineup)
	ON_COMMAND(ID_TEAM_RECORDS, OnTeamRecords)
	ON_COMMAND(ID_TEAM_STAFF, OnTeamStaff)
	ON_COMMAND(ID_TEAM_TRADE, OnTeamTrade)
	ON_COMMAND(ID_TEAM_TRANSACTIONS, OnTeamTransactions)
	ON_BN_CLICKED(IDC_BUTTON_SIMDAYS, OnButtonSimdays)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_DAYS, OnReleasedcaptureSliderDays)
	ON_COMMAND(ID_EDIT_CITIES, OnEditCities)
	ON_COMMAND(ID_EDIT_PLAYERS, OnEditPlayers)
	ON_COMMAND(ID_EDIT_STAFF, OnEditStaff)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
		ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_DAYS, &CScheduleView::OnNMCustomdrawSliderDays)
		END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScheduleView diagnostics

#ifdef _DEBUG
void CScheduleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CScheduleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScheduleView message handlers

BOOL CScheduleView::SetToDoc()
{
   CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

    // Allow for data validation    
    if ( !UpdateData(TRUE) )
        return FALSE;

  
    
    return TRUE;
}




void CScheduleView::OnInitialUpdate() 
{

 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

	//avg = pDoc->avg;

//	pDoc->m_draw_bk = false;

	for(int i=1; i<=80; i++)
	{
	}




  //CFrameWnd * pFrame;
    //CRect rectFrame, rectView;

    CFormView::OnInitialUpdate();
    
	//COLORREF	crBtnColor;
	myBrush.CreateSolidBrush(DLGCOLOR);

	m_slider_days.SetRangeMin( 1, FALSE );
	m_slider_days.SetRangeMax( 60, FALSE );
	m_slider_days.SetPos(m_xdays);

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 14;
	strcpy_s(lf.lfFaceName, USERFONT);


	//strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.
//	SetBkColor(RGB(245,222,186));


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 12;
	lf.lfUnderline = TRUE;
	strcpy_s(lf.lfFaceName, USERFONT);
//	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font1.CreateFontIndirect(&lf);    // Create the font.

	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 13;
	strcpy_s(lf.lfFaceName, USERFONT);
//	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font2.CreateFontIndirect(&lf);    // Create the font.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 500;
	lf.lfHeight = 13;
	strcpy_s(lf.lfFaceName, USERFONT);
//	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font3.CreateFontIndirect(&lf);    // Create the font.




	for(int i=1; i<=32; i++)
	{
//		m_static_score[i].SetFontName(USERFONT);
//		m_static_score[i].SetFontSize(8);
//		m_static_score[i].SetTextColor(RGB(255,255,0));
//		m_static_score[i].SetFontUnderline(TRUE);
//		m_static_score[i].SetBkColor(RGB(0,0,0));
//		//m_static_score[i].SetFontItalic(TRUE);
//		m_static_score[i].SetFontBold(TRUE);
//		m_static_score[i].SetBorder(TRUE);
		m_static_score[i].SetFont(&m_font3);
//		m_static_score[i].DrawTransparent(TRUE);

	}


	


    // Update form's data from document
    SetFromDoc();

	CFrameWnd* pFrame;
	CRect rectFrame, rectView;

	VERIFY(pFrame = GetParentFrame());
	GetClientRect(rectView);
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	if (w > WIDTH) w = WIDTH;
	if (h > HEIGHT) h = HEIGHT;
	pFrame->SetWindowPos(NULL, 0, 0, w, h, SWP_SHOWWINDOW);
	pFrame->RecalcLayout();
	GetParentFrame()->RecalcLayout();




  
}

void CScheduleView::SetFromDoc()
{
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();


    
    
    UpdateData(FALSE);    // Set controls to these

}



void CScheduleView::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CFormView::OnShowWindow(bShow, nStatus);
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();



	if(bShow == TRUE)
	{	
	// TODO: Add your message handler code here
	InitControls();
	if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		DisplayAllStarSchedule();
	}
	else
		DisplaySchedule();	    

//	RedrawWindow( ); 	

	}	

//	RedrawWindow( NULL, NULL,  RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE ); 	
//	GetParent()->RedrawWindow();	

}

void CScheduleView::DisplaySchedule()
{
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

//	pDoc->ComputerManager();

	int day = m_combo_day.GetCurSel();
	int month = m_combo_month.GetCurSel();
	int next_da = 0;
	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);

//	int cur_mo  = pDoc->avg.m_sched.m_currentMonth;

	int cur_da  = pDoc->avg.m_sched.m_currentDay;

//	int cur_ga  = pDoc->avg.m_sched.m_currentGame;

	bool po_played = false;
	int last_day = 0;
	
	if(pDoc->avg.m_sched.m_playoff_started == true && month == 12 && m_sim_ok == true)
	{
		//int last_day = 0;
		cur_da = pDoc->avg.m_sched.GetCurrentPlayoffDay(last_day);
		m_combo_day.SetCurSel(last_day);
		if(cur_da == 0) cur_da = 1;
		po_played = true;
		day = last_day;
	}
	else if(pDoc->avg.m_sched.m_playoff_started == true && month == 12)
	{
		//int last_day = 0;
		cur_da = pDoc->avg.m_sched.GetCurrentPlayoffDay(last_day);
		if(cur_da == 0) cur_da = 1;
		po_played = true;
	}



	//if(day == 0 && month == 0) 
	//{
		//DisplayAllStarSchedule();
	//}
	//else
	//{



	CString team_names[33];

	for(int i=1; i<=32; i++)// index of team names set to 1 to allow for schedule reading
	{
		team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i-1];
	}

	
	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[month][day][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[month][day][i] - t1*100;

		int sc1 = pDoc->avg.m_sched.m_game_score[month][day][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[month][day][i] - sc1*1000;

		m_visitor_teams[i] = t1;
		m_home_teams[i] = t2;
	
		CString visitor = team_names[t1];
		CString home = team_names[t2];
//		visitor.MakeUpper();
//		home.MakeUpper();

		bool game_scheduled = false;
//		bool po_played = false;
//		if(month == 12 && day > 0 && cur_mo==12 && day < cur_da)//playoff view
//		{
//			for(int ga=0; ga<=15; ga++)
//			{
//				int sc = pDoc->avg.m_sched.m_game_score[month][day-1][ga];
//				if(sc > 0) po_played = true;
//			}
//
//		}
	
		if(visitor != "")
		{
			CString control_v = pDoc->avg.m_settings.m_player_gm[t1-1];
			if(control_v == "Computer")
			{

//				m_buttons[i+1].SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);


			}
			else
			{				
//				m_buttons[i+1].SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
			}
				game_scheduled = true;
				m_buttons[i+1].ShowWindow(TRUE);
				m_static_score[i*2+1].ShowWindow(TRUE);
				//m_buttons[i+1].Repaint(TRUE);
				m_buttons[i+1].SetWindowText(visitor);

		}
		else
		{
			m_buttons[i+1].ShowWindow(FALSE);
			m_static_score[i*2+1].ShowWindow(FALSE);

		}
		
		if(home != "")
		{
			CString control_v = pDoc->avg.m_settings.m_player_gm[t2-1];
			if(control_v == "Computer")
			{

				//m_buttons[i+17].SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
				//m_buttons[i+17].SetFont(&m_font1);


			}
			else
			{				
				//m_buttons[i+17].SetShade(CShadeButtonST::SHS_HARDBUMP,8,10,20,BUTTONCOLOR);
				//m_buttons[i+17].SetFont(&m_font1);
			}
			game_scheduled = true;
			m_buttons[i+17].ShowWindow(TRUE);
			m_static_score[i*2+2].ShowWindow(TRUE);
			//m_buttons[i+17].Repaint(TRUE);
			m_buttons[i+17].SetWindowText(home);
		}
		else
		{
			m_buttons[i+17].ShowWindow(FALSE);
			m_static_score[i*2+2].ShowWindow(FALSE);
			m_buttons[i+1].ShowWindow(FALSE);
			m_static_score[i*2+1].ShowWindow(FALSE);

		}
		

		


		if(game_scheduled == true)
		{
			DisplayScore(i+1, sc1, sc2);
			m_buttons[i+33].ShowWindow(TRUE);
			m_buttons[i+49].ShowWindow(TRUE);
			m_buttons[i+65].ShowWindow(TRUE);
		}
		else
		{
			m_buttons[i+33].ShowWindow(FALSE);
			m_buttons[i+49].ShowWindow(FALSE);
			m_buttons[i+65].ShowWindow(FALSE);
		}


		if(po_played == true && sc1==0 && sc2==0 && day-1 > last_day && last_day >= -1)
		{
			//m_buttons[i+1].ShowWindow(FALSE);
			//m_static_score[i*2+1].ShowWindow(FALSE);
			//m_buttons[i+17].ShowWindow(FALSE);
			//m_static_score[i*2+2].ShowWindow(FALSE);
			m_buttons[33+i].ShowWindow(FALSE);
			m_buttons[49+i].ShowWindow(FALSE);
			m_buttons[65+i].ShowWindow(FALSE);

		}


	}




		//}





		DisableButtons();
		pDoc->SetTitleBar();
//	RedrawWindow( ); 	

}

void CScheduleView::OnSelchangeComboMonth() 
{
	// TODO: Add your control notification handler code here
	int mon = m_combo_month.GetCurSel();
	RefillDaysInMonth(mon);
	DisplaySchedule();
	
}

void CScheduleView::OnSelchangeComboDay() 
{
	// TODO: Add your control notification handler code here
	DisplaySchedule();
	
}

void CScheduleView::InitControls()
{

CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

			//OnPaint();

	
	


			ListTeamNames();
			if(pDoc->m_coach_score[1] == 0) 
				pDoc->m_game_type = LEAGUE;
			int month = pDoc->avg.m_sched.m_currentMonth;
			int day = pDoc->avg.m_sched.m_currentDay;
			m_combo_day.SetCurSel(day);
			m_combo_month.SetCurSel(month);
			RefillDaysInMonth(month);
			m_combo_day.SetCurSel(day);
			m_combo_month.SetCurSel(month);
			m_sim_day.SetWindowText("Sim Day");

			m_sim_week.SetWindowText("Sim Week");
			m_sim_month.SetWindowText("Sim Month");
			m_button_start_playoff.SetWindowText("Start Playoff");
			m_button_sim_season.SetWindowText("Sim Season");
			m_button_sim_til_asw.SetWindowText("Sim To Allstar");

			CString months[] = {"Oct","Nov","Dec","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Post"}; 
			
			CString date;
			date.Format("All Star (%s %d)", months[pDoc->avg.m_sched.m_asw_mo], pDoc->avg.m_sched.m_asw_da+1);
			m_button_asw.SetWindowText(date);


			if(pDoc->m_coach_score[1] > 0)
			{
				int ga = pDoc->avg.m_sched.m_currentGame;
				DisplayCoachedGameScore(ga);
				pDoc->m_coach_score[1] = 0;
				pDoc->m_coach_score[2] = 0;
			}
			DisableButtons();


//Invalidate(TRUE);
	
//	RedrawWindow(); 


}

void CScheduleView::OnButtonSchedule() 
{
	// TODO: Add your control notification handler code here
((CBBallApp*)AfxGetApp())->SwitchView( 1 );		


}

void CScheduleView::OnButtonStandings() 
{
	// TODO: Add your control notification handler code here
((CBBallApp*)AfxGetApp())->SwitchView( 4 );		
	
}

void CScheduleView::OnSetupLoad() 
{
	((CBBallApp*)AfxGetApp())->SwitchView( 2 );	
	
}

void CScheduleView::OnButtonSetup() 
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView( 0 );			
	
}


void CScheduleView::OnSelchangeComboTeams() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView( 3 );			
}

void CScheduleView::OnButtonSim1() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[0], m_home_teams[0]);
		//int da = m_combo_day.GetCurSel();
		//int mo = m_combo_month.GetCurSel();
		//SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();


	}
	else if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		pDoc->m_game_type = ROOKIE;
		SimAllStarGame(1);
	}
	else
	{
	
	int t1 = m_visitor_teams[0];	
	int t2 = m_home_teams[0];	

	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 1);
	SimGame(t1, t2, 1);
	}
}




void CScheduleView::OnButtonSim10() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[9], m_home_teams[9]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[9];	
	int t2 = m_home_teams[9];
	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 10);
	SimGame(t1, t2, 10);
	}
}

void CScheduleView::OnButtonSim11() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[10], m_home_teams[10]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[10];	
	int t2 = m_home_teams[10];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 11);
	SimGame(t1, t2, 11);
	}	
}

void CScheduleView::OnButtonSim12() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[11], m_home_teams[11]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[11];	
	int t2 = m_home_teams[11];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 12);
	SimGame(t1, t2, 12);
	}	
}

void CScheduleView::OnButtonSim13() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[12], m_home_teams[12]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{

	int t1 = m_visitor_teams[12];	
	int t2 = m_home_teams[12];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 13);
	SimGame(t1, t2, 13);
	}	
}

void CScheduleView::OnButtonSim14() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[13], m_home_teams[13]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[13];	
	int t2 = m_home_teams[13];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 14);
	SimGame(t1, t2, 14);
	}	
}

void CScheduleView::OnButtonSim15() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[14], m_home_teams[14]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[14];	
	int t2 = m_home_teams[14];	

	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 15);

	SimGame(t1, t2, 15);
	}	
}

void CScheduleView::OnButtonSim16() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[15], m_home_teams[15]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[15];	
	int t2 = m_home_teams[15];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 16);


	SimGame(t1, t2, 16);
	}	
}

void CScheduleView::OnButtonSim2() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[1], m_home_teams[1]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		pDoc->m_game_type = ALLSTAR;
		SimAllStarGame(2);
	}
	else
	{
	int t1 = m_visitor_teams[1];	
	int t2 = m_home_teams[1];
	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 2);

	SimGame(t1, t2, 2);
	}	
}

void CScheduleView::OnButtonSim3() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[2], m_home_teams[2]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[2];	
	int t2 = m_home_teams[2];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 3);


	SimGame(t1, t2, 3);
	}	
}

void CScheduleView::OnButtonSim4() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[3], m_home_teams[3]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[3];	
	int t2 = m_home_teams[3];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 4);


	SimGame(t1, t2, 4);
	}	
}

void CScheduleView::OnButtonSim5() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[4], m_home_teams[4]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[4];	
	int t2 = m_home_teams[4];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 5);


	SimGame(t1, t2, 5);
	}	
}

void CScheduleView::OnButtonSim6() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[5], m_home_teams[5]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[5];	
	int t2 = m_home_teams[5];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 6);


	SimGame(t1, t2, 6);
	}	
}

void CScheduleView::OnButtonSim7() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[6], m_home_teams[6]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[6];	
	int t2 = m_home_teams[6];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 7);


	SimGame(t1, t2, 7);
	}	
}

void CScheduleView::OnButtonSim8() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[7], m_home_teams[7]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[7];	
	int t2 = m_home_teams[7];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 8);


	SimGame(t1, t2, 8);
	}	
}

void CScheduleView::OnButtonSim9() 
{
	// TODO: Add your control notification handler code here
 CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(true, false, false, false, m_visitor_teams[8], m_home_teams[8]);
//		int da = m_combo_day.GetCurSel();
//		int mo = m_combo_month.GetCurSel();
//		SetCurrentPlayoffGame(mo,da,1);
		UpdatePlayoffsAfterCoachedGame();

	}
	else
	{
	int t1 = m_visitor_teams[8];	
	int t2 = m_home_teams[8];	
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo, da, 9);


	SimGame(t1, t2, 9);
	}	
}

void CScheduleView::SimGame(int t1, int t2, int row)
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	
	
	pDoc->PumpMessages();

	
	
	


	if(pDoc->avg.m_sched.m_game_score[0][0][1] == 0 && m_sim_season == true && 
			(pDoc->avg.m_sched.m_currentMonth > pDoc->avg.m_sched.m_asw_mo ||
				(pDoc->avg.m_sched.m_currentMonth == pDoc->avg.m_sched.m_asw_mo
				&&
				pDoc->avg.m_sched.m_currentDay > pDoc->avg.m_sched.m_asw_da)) && pDoc->m_game_type == LEAGUE)


	//if(pDoc->avg.m_sched.m_currentMonth == pDoc->avg.m_sched.m_asw_mo && 
	//pDoc->avg.m_sched.m_currentDay == pDoc->avg.m_sched.m_asw_da && 
	//pDoc->avg.m_sched.m_game_score[0][0][1] == 0 && m_sim_season == true && pDoc->m_game_type == LEAGUE)
	{
		
		m_button_asw.EnableWindow(TRUE);
		SimAsw();

	}
	else if(t1 > 0 && t2 > 0)
	{
	
	
	bool stop = CheckForCoachControlledGame(t1, t2);

	if(stop == false)
	{

	CEngine* engine = new CEngine;
//	srand( (unsigned)time( NULL ) );	
	engine->m_recordbook = pDoc->m_recordbook;

	for(int i=0; i<=306; i++)
	{
		engine->m_injury_table[i] = pDoc->m_injury_table[i];

	}

	engine->avg = pDoc->avg;

	engine->Initialize(t1,t2);



	engine->m_scoring_factor = pDoc->avg.m_settings.m_scoring_factor;

	engine->SetupComputerLineups();


	if(engine->avg.m_sched.m_playoff_started == true)
		engine->m_gameType = PLAYOFF;
	else
		engine->m_gameType = LEAGUE;



	engine->GameStart();




	if(engine->m_simulate == TRUE)
	{

	int count = 0;

	do
	{



		engine->GamePlay();




	}
	while (engine->m_gameOver == false);


	int sc1 = engine->GetScore(1);
	int sc2 = engine->GetScore(2);




	for(int i=0; i <= 32; i++)
	{
		pDoc->avg.m_standings[i] = engine->avg.m_standings[i];
	}


	pDoc->avg = engine->avg;

	if(sc1 > 1) pDoc->avg.m_sched.m_season_started = true;
	pDoc->avg.m_sched.m_game_score[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame] = sc1*1000 + sc2;
	DisplayScore(row, sc1, sc2);

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{


	CString	pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";

	
	WritePlayoffResults(pFileName, pDoc->avg.m_sched.m_currentMonth,
		pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame,
		t1, sc1, pDoc->avg.m_sched.m_series_win1, t2, sc2, pDoc->avg.m_sched.m_series_win2);
	



	}

	pDoc->m_recordbook = engine->m_recordbook;

	if(engine->m_injury_notify >= 0)
	{
	    CString message;
		CString team = pDoc->avg.m_settings.m_leagueTeamNames[engine->m_injury_notify];
		AfxFormatString1( message, IDS_STRING_MESSAGE_INJURY, team); 
		AfxMessageBox(message, MB_OK);			
        engine->m_injury_notify = -1;
		m_sim_ok = false;
	}


	}
	delete engine;
	
	
	DisableButtons();

	if(pDoc->avg.m_settings.m_show_box[t1-1] == TRUE)
		ShowBox(row-1);
	else if(pDoc->avg.m_settings.m_show_box[t2-1] == TRUE)
		ShowBox(row-1);

	}

	int stp = pDoc->ComputerManager();
	if(stp >= 0 || stop == true)
	{
		m_sim_ok = false;
		m_sim_season = false;
	}

	if(pDoc->m_sim_ok == false)//stopped because of injury notify
	{
		m_sim_ok = false;
		m_sim_season = false;
		pDoc->m_sim_ok = true;
	}



	}





	

}

void CScheduleView::DisplayScore(int row, int sc1, int sc2)
{
	CString s1, s2;
	s1.Format("%d", sc1);
	s2.Format("%d", sc2);
	m_static_score[row*2-1].SetWindowText(s1);
	m_static_score[row*2].SetWindowText(s2);
}

void CScheduleView::OnButtonSimday() 
{
	// TODO: Add your control notification handler code here



	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	//pDoc->PumpMessages();
	
	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();




	if(pDoc->m_coached_game_underway == true)
	{

		((CBBallApp*)AfxGetApp())->SwitchView( 5 );	

	}
	else
	{
		m_sim_ok = true;
	

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(false, true, false, false, m_visitor_teams[9], m_home_teams[9]);

	}
	else
	{

	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



//	bool stop = false;
	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[mo][da][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[mo][da][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[mo][da][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[mo][da][i] - sc1*1000;


//		if(sc1 == 0 && sc2 == 0)
//			stop = CheckForCoachControlledGame(t1, t2);

	


		if(sc1 == 0 && sc2 == 0 && m_sim_ok == true)
		{
			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{
				SetCurrentGame(mo, da, i+1);
				SimGame(t1, t2, i+1);
			}
		}
		
	}

	}



	}

	m_sim_ok = false;
	DisableButtons();

	
}

void CScheduleView::OnButtonSimMonth() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	
	m_sim_ok = true;



	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(false, false, false, true, 0, 0);

	}
	else
	{



	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



	int d=da;
	int m=mo; 

	int start_da = da;
	int start_mo = mo;
	int end_da = da;
	int end_mo = mo + 1;
	bool end = false;
	
	do
	{


  



	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);
	DisplaySchedule();

	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[m][d][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[m][d][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[m][d][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[m][d][i] - sc1*1000;
		if(sc1 == 0 && sc2 == 0 && t1 > 0 && t2 > 0 && m_sim_ok == true)
		{
			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{	
				SetCurrentGame(m,d,i+1);	
				SimGame(t1, t2, i+1);
			}
		}

	}

	d=d+1;
	if(d > m_days_in_month[m] - 1)
	{
		d=0;
		m=m+1;
	}

	if(m == end_mo && d == end_da) end = true;


	}
	while (m <= 11 && m_sim_ok == true && end == false);
	
	}	

	m_sim_ok = false;
	DisableButtons();



}

void CScheduleView::OnButtonSimWeek() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	m_sim_ok = true;

	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();

	

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(false, false, true, false,0 ,0 );

	}
	else
	{


	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



	int days_with_games = 0;
	int d=da;
	int m=mo; 


	do
	{



  



	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);
	DisplaySchedule();
	bool found_game = false;

	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[m][d][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[m][d][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[m][d][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[m][d][i] - sc1*1000;
		if(sc1 == 0 && sc2 == 0 && t1 > 0 && t2 > 0 && m_sim_ok == true)
		{

			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{
		
			SetCurrentGame(m,d,i+1);

			
			SimGame(t1, t2, i+1);
			if(found_game == false)
			{
				found_game = true;
				days_with_games = days_with_games + 1;
			}

			}
		}

	}

	d=d+1;
	
	if(d > m_days_in_month[m] - 1)
	{
		d=0;
		m=m+1;
	}



	}
	while (days_with_games < 7 && m <= 11 && m_sim_ok == true);

	

	}		


	m_sim_ok = false;
	DisableButtons();


}

void CScheduleView::OnButtonStopSim() 
{
	// TODO: Add your control notification handler code here
	m_sim_ok = false;
	m_sim_season = false;
	DisableButtons();


	
}

void CScheduleView::OnButtonProgress() 
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView( 8 );		
}

void CScheduleView::OnButtonHistory() 
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView( 6 );		
}

void CScheduleView::OnButtonTools() 
{
	// TODO: Add your control notification handler code here
	((CBBallApp*)AfxGetApp())->SwitchView( 7 );		
}

void CScheduleView::OnButtonStartPlayoff() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();

 	if(pDoc->avg.m_sched.m_playoff_started == false)
	{

	
	int result = MessageBox("Are you sure you want to end the current regular season and start the playoffs?", "It's Playoff time!", MB_YESNO);
	if(result == IDYES)
	{
		CPlayoff playoff;


	for(int i=0; i<=32; i++)
	{
		pDoc->avg.m_standings[i].m_divisionChamps = false;
		playoff.record[i] = pDoc->avg.m_standings[i];
	}



	CString po_format = pDoc->avg.m_settings.m_playoffFormat;
	
	if(po_format != "")
	{

	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
						playoff.m_gameScore[i][j][k] = pDoc->avg.m_sched.m_game_score[i][j][k]; 

						playoff.m_sched[i][j][k] = pDoc->avg.m_sched.m_schedule[i][j][k];
			}
		}
	}



	
	int teamsPer = 1;
	bool conferencePlayoff = playoff.ConferencePlayoff(teamsPer, po_format); 


	playoff.SortStandings(pDoc->avg.m_settings.m_divisionName1);
	playoff.SortStandings(pDoc->avg.m_settings.m_divisionName2);
	playoff.SortStandings(pDoc->avg.m_settings.m_divisionName3);
	playoff.SortStandings(pDoc->avg.m_settings.m_divisionName4);

	playoff.SetDivisionChamps(pDoc->avg.m_settings.m_divisionName1, pDoc->avg.m_settings.m_divisionName2, 
		pDoc->avg.m_settings.m_divisionName3, pDoc->avg.m_settings.m_divisionName4);

	if(conferencePlayoff == true)
	{
		playoff.SortStandings(pDoc->avg.m_settings.m_conferenceName1);
		playoff.SortStandings(pDoc->avg.m_settings.m_conferenceName2);
	}

	playoff.SetPlayoffRounds(pDoc->avg.m_settings.m_rd1Format, pDoc->avg.m_settings.m_rd2Format,
		pDoc->avg.m_settings.m_rd3Format, pDoc->avg.m_settings.m_rd4Format);

	playoff.SetPlayoffs(conferencePlayoff, teamsPer,
	        pDoc->avg.m_settings.m_conferenceName1,
			pDoc->avg.m_settings.m_conferenceName2,
			pDoc->avg.m_settings.m_divisionName1,
			pDoc->avg.m_settings.m_divisionName2,
			pDoc->avg.m_settings.m_divisionName3,
			pDoc->avg.m_settings.m_divisionName4);









	playoff.WriteFirstRound(pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch", 
		playoff.m_playoffRounds, pDoc->avg.m_settings.m_rd1Format,
		pDoc->avg.m_settings.m_rd2Format, pDoc->avg.m_settings.m_rd3Format, pDoc->avg.m_settings.m_rd4Format);

	CString format1, format2, format3, format4;
	int m_currentRound = 0, m_playoffRounds = 0, m_currentPlayoffDay = 0, m_currentPlayoffGame = 0;

	CString pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";
	BOOL CurrentGame = FALSE;

	BOOL m_seasonStarted = TRUE;

	bool round_complete = playoff.GetPlayoffResults(pFileName,format1, format2, format3, format4,
		m_currentRound, m_playoffRounds, m_currentPlayoffDay, m_currentPlayoffGame,
		 m_seasonStarted, pDoc->avg.m_sched.m_currentMonth, pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame, CurrentGame, 0, 0);

	pDoc->avg.m_sched.m_currentRound = m_currentRound;


	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
					pDoc->avg.m_sched.m_game_score[i][j][k] = playoff.m_gameScore[i][j][k];

					pDoc->avg.m_sched.m_schedule[i][j][k] = playoff.m_sched[i][j][k];
			}
		}
	}


	pDoc->avg.m_sched.m_playoff_started = true;

	m_combo_month.SetCurSel(12);
	m_combo_day.SetCurSel(0);
	DisplaySchedule();
	}






	}	

	}
	else
	{
		CPlayoffDlg* play;
		play = new CPlayoffDlg;
		play->m_leagueName = pDoc->avg.m_settings.m_league_name;
		play->m_path = pDoc->avg.m_settings.m_path;

		for(int i=0; i<=32; i++)
		{
			play->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
			play->m_record[i] = pDoc->avg.m_standings[i];
		}
		play->DoModal();
		delete play;	
	}
}

void CScheduleView::OnButtonSimPlayoffs() //sim season actually but oh well
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	
	m_sim_ok = true;
	m_sim_season = true;

	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();


	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(false, false, false, true, 0, 0);

	}
	else
	{



	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



	int d=da;
	int m=mo; 

	int start_da = da;
	int start_mo = mo;
	int end_da = da;
	int end_mo = mo + 1;
	bool end = false;
	
	do
	{


  



	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);
	DisplaySchedule();

	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[m][d][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[m][d][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[m][d][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[m][d][i] - sc1*1000;
		if(sc1 == 0 && sc2 == 0 && t1 > 0 && t2 > 0 && m_sim_ok == true)
		{
			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{	
				SetCurrentGame(m,d,i+1);	
				bool asw_simmed = m_simmed_asw;
				SimGame(t1, t2, i+1);//if asw simmed then go back and fill in the blank game before going on
				if(m_simmed_asw != asw_simmed){ d=0;m=0;i=0;}
			}
		}

	}

	d=d+1;
//	if(d > 30)
	if(d > m_days_in_month[m] - 1)
	{
		d=0;
		m=m+1;
	}

	//if(m == end_mo && d == end_da) end = true;


	}
	while (m <= 11 && m_sim_ok == true && end == false && pDoc->avg.m_sched.m_regular_season_ended == false);
	
	}	

	m_sim_ok = false;
	m_sim_season = false;
	DisableButtons();


}

void CScheduleView::OnButtonAsw() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	CAllStarDlg* all = new CAllStarDlg;
	all->avg = pDoc->avg;
	all->m_default_team = pDoc->m_combo_team_index - 1;
	if(all->m_default_team < 0) all->m_default_team = 0;
	int result = all->DoModal();
	if(result == IDOK)
	{
		for(int i=1; i<=30; i++)
		{
			int pointer = all->m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}

			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "") pDoc->avg.m_actual[pointer].m_all_star = 1;
		}
		for(int i=31; i<=60; i++)
		{
			int pointer = all->m_index[i];


			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}

			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "") pDoc->avg.m_actual[pointer].m_rookie_star = 1;
		}

		for(int i=61; i<=68; i++)
		{
			int pointer = all->m_index[i];


			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}



			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "")
			{
				pDoc->avg.m_actual[pointer].m_3contest = 1;
				if(i==61)
				{
					pDoc->avg.m_actual[pointer].m_3contest = 2;

					pDoc->avg.m_settings.m_3contest = pDoc->avg.m_actual[pointer].m_id;
					pDoc->avg.m_settings.m_3contest_index = pDoc->avg.m_actual[pointer].m_current_team;
									
				}
			}
		}

		for(int i=71; i<=78; i++)
		{
			int pointer = all->m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}



			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "")
			{
				pDoc->avg.m_actual[pointer].m_dunkcontest = 1;
				if(i==71)
				{
					pDoc->avg.m_actual[pointer].m_dunkcontest = 2;

					pDoc->avg.m_settings.m_dunkcontest = pDoc->avg.m_actual[pointer].m_id;
					pDoc->avg.m_settings.m_dunkcontest_index = pDoc->avg.m_actual[pointer].m_current_team;
									
					
				}

			}
		}



	m_asw_button_pressed = true;
	SaveAllStarWeekend(all->m_index, all->m_scores);


	}
	
	m_sim_ok = false;

	SetCurrentGame(0,0,1);
	DisplayAllStarSchedule();

	delete all;


	
}

void CScheduleView::SimAllStarGame(int row)
{
	

			//m_combo_day.SetCurSel(0);
			//m_combo_month.SetCurSel(0);

	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();

	

	CEngine* engine = new CEngine;

	for(int i=0; i<=306; i++)
	{
		engine->m_injury_table[i] = pDoc->m_injury_table[i];

	}

	engine->avg = pDoc->avg;
	engine->m_recordbook = pDoc->m_recordbook;

	engine->avg.m_sched.m_currentMonth = 0; 
	engine->avg.m_sched.m_currentDay = 0; 

	if(row == 1)
		engine->avg.m_sched.m_currentGame = 0; 
	else if(row == 2)
		engine->avg.m_sched.m_currentGame = 1; 



	



	engine->m_all_star_weekend_game = m_asw_button_pressed;

	if(row == 2)
		engine->InitializeAllStarGame();
	else
		engine->InitializeRookieGame();


//	engine->m_scoring_factor = 1;
	engine->m_scoring_factor = pDoc->avg.m_settings.m_scoring_factor;


	engine->SetupComputerLineups();

	engine->m_gameType = pDoc->m_game_type;



	engine->GameStart();

	int count = 0;

	do
	{



		engine->GamePlay();




	}
	while (engine->m_gameOver == false);

	int pointer = engine->GameMvp();
	if(row == 2)
	{
		pDoc->avg.m_settings.m_all_star = pDoc->avg.m_actual[pointer].m_id;
		pDoc->avg.m_settings.m_all_star_index = pDoc->avg.m_actual[pointer].m_current_team;
		pDoc->avg.m_actual[pointer].m_all_star = 2;
	}
	else
	{
		pDoc->avg.m_settings.m_rookie_star = pDoc->avg.m_actual[pointer].m_id;
		pDoc->avg.m_settings.m_rookie_star_index = pDoc->avg.m_actual[pointer].m_current_team;
		pDoc->avg.m_actual[pointer].m_rookie_star = 2;
	}

	int sc1 = engine->GetScore(1);
	int sc2 = engine->GetScore(2);
	pDoc->avg.m_sched = engine->avg.m_sched;

	DisplayAllStarSchedule();
	DisplayScore(row, sc1, sc2);
	delete engine;

	
}

void CScheduleView::ShowBox(int game)
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();


	CStatsDlg stats ;

	int month = m_combo_month.GetCurSel();
	int day = m_combo_day.GetCurSel();

	CString string;
	m_buttons[1].GetWindowText(string);

	if(string == "Rookies")
	{
		month = 0;
		day = 0;
	}
	
	
	stats.m_saved_box = true;

	stats.m_mo = month;
	stats.m_da = day;
	stats.m_ga = game;

//	stats.avg = pDoc->avg;
	stats.SetPtr(pDoc->avg);
	stats.m_v_click = false;


	if(month == 0 && day == 0 && game == 0) stats.m_game_type = ROOKIE;
	else if(month == 0 && day == 0 && game == 1) stats.m_game_type = ALLSTAR;


	stats.DoModal();
	//delete stats;		
}

void CScheduleView::OnButtonBox1() 
{
	// TODO: Add your control notification handler code here
	ShowBox(0);
	
}

void CScheduleView::OnButtonBox2() 
{
	// TODO: Add your control notification handler code here
	ShowBox(1);
	
}


BOOL CScheduleView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default

/*

	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	if(pDoc->avg.m_settings.m_loadbmp == false)
//	{
//		CRect rc;
//		GetWindowRect(&rc);
//		ScreenToClient(&rc);
//		CBrush brush(SCREENCOLOR);
//		pDC->FillRect(rc, &brush);
//		pDC->SelectStockObject(ANSI_VAR_FONT);
//		pDC->DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);
//	}
//	else if(pDoc->avg.m_settings.m_loadbmp == true)
//	{

//	bitmapBkgnd.Detach();
//	bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");

	CRect rect;
   GetClientRect(&rect);
   CDC dc;
   dc.CreateCompatibleDC(pDC);
   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

   BITMAP bm;
   bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
   iBitmapWidth = bm.bmWidth;
   iBitmapHeight = bm.bmHeight;

   // If our bitmap is smaller than the background and tiling is
   // supported, tile it. Otherwise watch the efficiency - don't
   // spend time setting up loops you won't need.

   if (iBitmapWidth  >= rect.Width() &&
       iBitmapHeight >= rect.Height() )
   {
      pDC->BitBlt (rect.left, 
                   rect.top, 
                   rect.Width(),
                   rect.Height(),
                   &dc,
                   0, 0, SRCCOPY);
   }
   else
   {
      for (iyOrg = 0; iyOrg < rect.Height(); iyOrg += iBitmapHeight)
      {
         for (ixOrg = 0; ixOrg < rect.Width(); ixOrg += iBitmapWidth)
         {
            pDC->BitBlt (ixOrg, 
                         iyOrg, 
                         rect.Width(),
                         rect.Height(),
                         &dc,
                         0, 0, SRCCOPY);
         }
      }
   }

   dc.SelectObject(pOldBitmap);

//	}
   return TRUE;



  */

//	return 0;

//			return CView::OnEraseBkgnd(pDC);

	
CDC memdc;
memdc.CreateCompatibleDC(pDC);
CBitmap* pOldBitmap = memdc.SelectObject(m_bmp);
CRect rc;
GetClientRect(&rc);

const CSize sz = m_bmp->GetBitmapDimension();
for (int y=0; y <= rc.Height(); y += sz.cy)
{
for (int x=0; x <= rc.Width(); x += sz.cx)
{
pDC->BitBlt(x, y, sz.cx, sz.cy, &memdc, 0, 0, SRCCOPY);
}
}

memdc.SelectObject(pOldBitmap);
return TRUE;




}


/*void CScheduleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();


//	if(pDoc->m_draw_bk == false)
//	{

		pDoc->m_draw_bk = true;



	if(pDoc->avg.m_settings.m_loadbmp == false)
	{
	
		CRect rc;
		GetWindowRect(&rc);
		ScreenToClient(&rc);
		CBrush brush(SCREENCOLOR);
		pDC->FillRect(rc, &brush);
		pDC->SelectStockObject(ANSI_VAR_FONT);
		pDC->DrawText("", -1, rc, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX | DT_NOCLIP);
	}
	else if(pDoc->avg.m_settings.m_loadbmp == true)
	{
	bitmapBkgnd.Detach();
		bitmapBkgnd.LoadBitmap(pDoc->avg.m_settings.m_path + "default.bmp");

	
CRect rect;
   GetClientRect(&rect);
   CDC dc;
   dc.CreateCompatibleDC(pDC);
   CBitmap* pOldBitmap = dc.SelectObject(&bitmapBkgnd);
   int iBitmapWidth, iBitmapHeight ;
   int ixOrg, iyOrg;

	BITMAP bm;
	bitmapBkgnd.GetObject(sizeof(BITMAP),&bm);
	iBitmapWidth = bm.bmWidth;
	iBitmapHeight = bm.bmHeight;

   // If our bitmap is smaller than the background and tiling is
   // supported, tile it. Otherwise watch the efficiency - don't
   // spend time setting up loops you won't need.

   if (iBitmapWidth  >= rect.Width() &&
       iBitmapHeight >= rect.Height() )
   {
      pDC->BitBlt (rect.left, 
                   rect.top, 
                   rect.Width(),
                   rect.Height(),
                   &dc,
                   0, 0, SRCCOPY);
   }
   else
   {
      for (iyOrg = 0; iyOrg < rect.Height(); iyOrg += iBitmapHeight)
      {
         for (ixOrg = 0; ixOrg < rect.Width(); ixOrg += iBitmapWidth)
         {
            pDC->BitBlt (ixOrg, 
                         iyOrg, 
                         rect.Width(),
                         rect.Height(),
                         &dc,
                         0, 0, SRCCOPY);
         }
      }
   }

   dc.SelectObject(pOldBitmap);
   


	
	}

		

//	}	
	
}
*/

void CScheduleView::OnButtonBox10() 
{
	// TODO: Add your control notification handler code here
	ShowBox(9);
	
}

void CScheduleView::OnButtonBox11() 
{
	// TODO: Add your control notification handler code here
	ShowBox(10);
	
}

void CScheduleView::OnButtonBox12() 
{
	// TODO: Add your control notification handler code here
	ShowBox(11);
	
}

void CScheduleView::OnButtonBox13() 
{
	// TODO: Add your control notification handler code here
	ShowBox(12);
	
}

void CScheduleView::OnButtonBox14() 
{
	// TODO: Add your control notification handler code here
	ShowBox(13);
	
}

void CScheduleView::OnButtonBox15() 
{
	// TODO: Add your control notification handler code here
	ShowBox(14);
	
}

void CScheduleView::OnButtonBox16() 
{
	// TODO: Add your control notification handler code here
	ShowBox(15);
	
}

void CScheduleView::OnButtonBox3() 
{
	// TODO: Add your control notification handler code here
	ShowBox(2);
	
}

void CScheduleView::OnBUTTONBOX4() 
{
	// TODO: Add your control notification handler code here
	ShowBox(3);
	
}

void CScheduleView::OnButtonBox5() 
{
	// TODO: Add your control notification handler code here
	ShowBox(4);
	
}

void CScheduleView::OnButtonBox6() 
{
	// TODO: Add your control notification handler code here
	ShowBox(5);
	
}

void CScheduleView::OnButtonBox7() 
{
	// TODO: Add your control notification handler code here
	ShowBox(6);
	
}

void CScheduleView::OnButtonBox8() 
{
	// TODO: Add your control notification handler code here
	ShowBox(7);
	
}

void CScheduleView::OnButtonBox9() 
{
	// TODO: Add your control notification handler code here
	ShowBox(8);
	
}


void CScheduleView::OnButtonCoach1() 
{

	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[0];	
	int t2 = m_home_teams[0];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;

	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();

	if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		da = 0;
		mo = 0;
	}


	if(da == 0 && mo == 0)
		pDoc->m_game_type = ROOKIE;
	else
		pDoc->m_game_type = LEAGUE;

//	int da = m_combo_day.GetCurSel();
//	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,1);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		

	//if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	//{
	//	DisplayAllStarSchedule();
	//}


}

void CScheduleView::OnButtonCoach10() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[9];	
	int t2 = m_home_teams[9];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;


	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,10);



	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(10);

	
}

void CScheduleView::OnButtonCoach11() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[10];	
	int t2 = m_home_teams[10];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,11);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(11);

	
}

void CScheduleView::OnButtonCoach12() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[11];	
	int t2 = m_home_teams[11];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,12);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(12);

	
}

void CScheduleView::OnButtonCoach13() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[12];	
	int t2 = m_home_teams[12];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,13);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
//	DisplayCoachedGameScore(13);
	
}

void CScheduleView::OnButtonCoach14() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[13];	
	int t2 = m_home_teams[13];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,14);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	
//	DisplayCoachedGameScore(14);
	
}

void CScheduleView::OnButtonCoach15() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[14];	
	int t2 = m_home_teams[14];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,15);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	
//	DisplayCoachedGameScore(15);
	
}

void CScheduleView::OnButtonCoach16() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[15];	
	int t2 = m_home_teams[15];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,16);


	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
//	DisplayCoachedGameScore(16);
	
	
}

void CScheduleView::OnButtonCoach2() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[1];	
	int t2 = m_home_teams[1];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();

	if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		da = 0;
		mo = 0;
	}

	SetCurrentPlayoffGame(mo,da,2);

	if(da == 0 && mo == 0) pDoc->m_game_type = ALLSTAR;
	else pDoc->m_game_type = LEAGUE;

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
//	if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
//	{
//		DisplayAllStarSchedule();
//	}
//	else 
//		DisplayCoachedGameScore(2);
	
	
}

void CScheduleView::OnButtonCoach3() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[2];	
	int t2 = m_home_teams[2];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,3);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(3);
	
	
}

void CScheduleView::OnButtonCoach4() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[3];	
	int t2 = m_home_teams[3];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,4);

	

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(4);
	
	
}

void CScheduleView::OnButtonCoach5() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[4];	
	int t2 = m_home_teams[4];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,5);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(5);
	
	
}

void CScheduleView::OnButtonCoach6() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[5];	
	int t2 = m_home_teams[5];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,6);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(6);
	
	
}

void CScheduleView::OnButtonCoach7() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[6];	
	int t2 = m_home_teams[6];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,7);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	//DisplayCoachedGameScore(7);
	
	
}

void CScheduleView::OnButtonCoach8() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[7];	
	int t2 = m_home_teams[7];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,8);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	
	//DisplayCoachedGameScore(8);
	
}

void CScheduleView::OnButtonCoach9() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int t1 = m_visitor_teams[8];	
	int t2 = m_home_teams[8];	
	pDoc->m_coach_visitor_index = t1;
	pDoc->m_coach_home_index = t2;
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	SetCurrentPlayoffGame(mo,da,9);

	((CBBallApp*)AfxGetApp())->SwitchView( 5 );		
	
	//DisplayCoachedGameScore(9);
	
}


void CScheduleView::DisplayCoachedGameScore(int row)
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();


	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();

	if(pDoc->avg.m_sched.m_currentMonth == 0 && pDoc->avg.m_sched.m_currentDay == 0)
	{
		da = 0;
		mo = 0;
	}

	

	pDoc->avg.m_sched.m_currentMonth = mo;
	pDoc->avg.m_sched.m_currentDay = da;
	pDoc->avg.m_sched.m_currentGame = row;




	int sc1 = pDoc->m_coach_score[1];
	int sc2 = pDoc->m_coach_score[2];
	int t1 = pDoc->m_coach_visitor_index;
	int t2 = pDoc->m_coach_home_index;

	if(pDoc->m_game_type != EXHIBITION)
	{
		pDoc->avg.m_sched.m_game_score[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame] = sc1*1000 + sc2;
		DisplayScore(row+1, sc1, sc2);

		if(pDoc->avg.m_sched.m_playoff_started == true)
		{
			UpdatePlayoffsAfterCoachedGame();
		}	
	}


}

void CScheduleView::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[0];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton10() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[9];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton11() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[10];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton12() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[11];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton13() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[12];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton14() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[13];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton15() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[14];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton16() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[15];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton17() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[0];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton18() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[1];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton19() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[2];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[1];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton20() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[3];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton21() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[4];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton22() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[5];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton23() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[6];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton24() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[7];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton25() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[8];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton26() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[9];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton27() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[10];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton28() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[11];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton29() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[12];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[2];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton30() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[13];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton31() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[14];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton32() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_home_teams[15];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[3];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[4];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[5];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[6];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton8() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[7];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::OnButton9() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_combo_team_index = m_visitor_teams[8];		
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );		
	
}

void CScheduleView::ListTeamNames()
{
	// Get the CListBox

//	m_combo_teams.ResetContent();
//	m_combo_teams.AddString("All Teams");

	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();





	//CDropList* pList = m_pDropBtn->GetList();


	// Set OPTIONAL paramters
	COLORREF crBkListColor = RGB(255,255,255);
	


	// Add default Items
	
	m_combo_teams.ResetContent();
	m_combo_teams.AddString("All Teams");



	for(int i=0; i<pDoc->avg.m_settings.m_numberteams; i++)
		{
			CString team_name = pDoc->avg.m_settings.m_leagueTeamNames[i];
			if(team_name != "") 
			//	m_combo_teams.AddString(team_name);
				m_combo_teams.AddString(pDoc->avg.m_finance[i].m_city_name + " " + pDoc->avg.m_settings.m_leagueTeamNames[i]);

		}	

			m_combo_teams.SetCurSel(pDoc->m_combo_team_index);





}

void CScheduleView::SetCurrentGame(int mo, int da, int ga)
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	if(pDoc->avg.m_sched.m_playoff_started == false)
	{
		pDoc->avg.m_sched.m_currentDay = da;
		pDoc->avg.m_sched.m_currentMonth = mo;
		pDoc->avg.m_sched.m_currentGame = ga-1;
	}

}

void CScheduleView::DisableButtons()
{
	
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	int mo = m_combo_month.GetCurSel();
	int da = m_combo_day.GetCurSel();


			BOOL button_stop_sim = FALSE;
			BOOL sim_day = TRUE;
			BOOL sim_week = TRUE;
			BOOL sim_month = TRUE;
			BOOL button_sim_season = TRUE;
			BOOL button_sim_til_asw = TRUE;
			BOOL button_next = TRUE;
			BOOL button_previous = TRUE;
			BOOL button_gametype = TRUE;
			BOOL button_start_playoff = FALSE;
			BOOL button_asw = FALSE;
			BOOL button_simx = TRUE;




	for(int i=1; i<=16; i++)
	{
		if(pDoc->avg.m_sched.m_game_score[mo][da][i-1] > 0)
		{
				m_buttons[32+i].EnableWindow(FALSE);
				m_buttons[48+i].EnableWindow(TRUE);
				m_buttons[64+i].EnableWindow(FALSE);

		}
		else
		{
				m_buttons[32+i].EnableWindow(TRUE);
				m_buttons[48+i].EnableWindow(FALSE);
				m_buttons[64+i].EnableWindow(TRUE);

		}

		if(pDoc->m_coached_game_underway == true)
		{
		}

	
	}

	int asw_mo = pDoc->avg.m_sched.m_asw_mo;
	int asw_da = pDoc->avg.m_sched.m_asw_da;
	int asw_ga = pDoc->avg.m_sched.m_asw_ga;








		if(pDoc->m_coached_game_underway == true)
		{
			m_sim_day.SetWindowText("BACK TO COACHING");

			button_stop_sim = FALSE;
			sim_day = TRUE;
			sim_week = FALSE;
			sim_month = FALSE;
			button_sim_season = FALSE;
			button_sim_til_asw = FALSE;
			button_next = TRUE;
			button_previous = TRUE;
			button_gametype = FALSE;
			button_start_playoff = FALSE;
			button_asw = FALSE;
			button_simx = FALSE;

		}
		else if(pDoc->avg.m_sched.m_playoff_started == true)
		{
			m_sim_day.SetWindowText("Sim Playoff Day");
			m_sim_week.SetWindowText("Sim Playoff Round");
			m_sim_month.SetWindowText("Sim Playoffs");
			m_button_start_playoff.SetWindowText("Playoff Results");

			button_stop_sim = FALSE;
			sim_day = TRUE;
			sim_week = TRUE;
			sim_month = TRUE;
			button_sim_season = FALSE;
			button_sim_til_asw = FALSE;
			button_next = TRUE;
			button_previous = TRUE;
			button_gametype = TRUE;
			button_start_playoff = FALSE;
			button_asw = TRUE;
			button_simx = FALSE;

		}
		else if(pDoc->avg.m_sched.m_game_score[0][0][1] == 0 && m_sim_season == false && 
			(pDoc->avg.m_sched.m_currentMonth > pDoc->avg.m_sched.m_asw_mo ||
				(pDoc->avg.m_sched.m_currentMonth == pDoc->avg.m_sched.m_asw_mo
				&&
				pDoc->avg.m_sched.m_currentDay > pDoc->avg.m_sched.m_asw_da))
			
			)	
		{
			m_sim_ok = false;
			button_stop_sim = FALSE;
			sim_day = TRUE;
			sim_week = TRUE;
			sim_month = TRUE;
			button_sim_season = TRUE;
			button_sim_til_asw = FALSE;
			button_next = TRUE;
			button_previous = TRUE;
			button_gametype = TRUE;
			button_start_playoff = FALSE;
			button_asw = TRUE;
			button_simx = TRUE;

		}



		if(pDoc->avg.m_sched.m_game_score[0][0][1] > 0)
		{
			button_asw = TRUE;
			button_sim_til_asw = FALSE;
		}




		int t1 = pDoc->avg.m_sched.m_game_score[pDoc->avg.m_sched.m_last_mo][pDoc->avg.m_sched.m_last_da][pDoc->avg.m_sched.m_last_ga];
		if(t1 == 0)
		{
			button_start_playoff = FALSE;
		}
		else 
		{
			if(pDoc->avg.m_sched.m_regular_season_ended == false)
			{
				pDoc->avg.m_sched.m_regular_season_ended = true;
				m_asw_button_pressed = false;
				m_simmed_asw = false;
				m_sim_ok = false;
				button_stop_sim = FALSE;
				sim_day = FALSE;
				sim_week = FALSE;
				sim_month = FALSE;
				button_sim_season = FALSE;
				button_simx = FALSE;
				button_sim_til_asw = FALSE;
				button_next = TRUE;
				button_previous = TRUE;
				button_gametype = TRUE;
				button_asw = TRUE;
			}
			button_start_playoff = TRUE;
			if(pDoc->avg.m_sched.m_playoff_started == false)
			{
				button_stop_sim = FALSE;
				sim_day = FALSE;
				sim_week = FALSE;
				sim_month = FALSE;
				button_sim_season = FALSE;
				button_sim_til_asw = FALSE;
				button_simx = FALSE;

			}

		}



		if(m_sim_ok == true)
		{
			button_stop_sim = TRUE;
			sim_day = FALSE;
			sim_week = FALSE;
			sim_month = FALSE;
			button_asw = FALSE;
			button_sim_season = FALSE;
			button_simx = FALSE;
			button_sim_til_asw = FALSE;
			button_next = FALSE;
			button_previous = FALSE;
			button_gametype = FALSE;
			button_start_playoff = FALSE;
		}


			//button_start_playoff = TRUE;
			CString dayx;
			dayx.Format("Sim %d day(s)", m_xdays);
//			dayx.MakeUpper();
			m_sim_x.SetWindowText(dayx);

			m_button_next.EnableWindow(button_next);
			m_button_previous.EnableWindow(button_previous);
			m_button_gametype.EnableWindow(button_gametype);

			m_button_start_playoff.EnableWindow(button_start_playoff);

			
			m_button_asw.EnableWindow(TRUE);






}

void CScheduleView::SimPlayoffGame(bool sim_po_game, bool sim_po_day, bool sim_po_round, bool sim_po_all, int visitor, int home)
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();

	bool all = false;
	if(sim_po_all == true)
	{
		all = true;
		sim_po_round = true;
		sim_po_all = false;
	}

	do
	{

		CPlayoff *po;
		po = new CPlayoff;
		CString pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";
		CString format1, format2, format3, format4;
		int m_currentRound = 0, m_playoffRounds = 0, m_currentPlayoffDay = 0, m_currentPlayoffGame = 0;
		int currentMonth = 0, currentDay = 0, currentGame = 0;
		BOOL m_seasonStarted = FALSE;


	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
						po->m_gameScore[i][j][k] = pDoc->avg.m_sched.m_game_score[i][j][k]; 

						po->m_sched[i][j][k] = pDoc->avg.m_sched.m_schedule[i][j][k];
			}
		}
	}


	for(int i=0; i<=32; i++)
	{
		//pDoc->avg.m_standings[i].m_divisionChamps = false;
		po->record[i] = pDoc->avg.m_standings[i];
	}

		

	bool condition = true;
	int orig_da = -1;
	int orig_ro = -1;

	bool show_po_screen = false;
	int start_day = pDoc->avg.m_sched.m_currentDay;
	
	do
	{
		BOOL Game = FALSE;

//		bool more_games = false;
//		for(int i=(pDoc->avg.m_sched.m_currentGame+1); i<=16; i++)
//		{
//			int game = pDoc->avg.m_sched.m_schedule[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][i];
//			if(game > 0) more_games = true;
//		}
//		if(more_games == false) pDoc->HealInjury(3);
		

		bool round_complete = false;

		if(sim_po_game == false)
			round_complete = po->GetPlayoffResults(pFileName,format1, format2, format3, format4,
		m_currentRound, m_playoffRounds, m_currentPlayoffDay, m_currentPlayoffGame,
		 m_seasonStarted, pDoc->avg.m_sched.m_currentMonth, pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame, Game, 0, 0);
		else
			round_complete = po->GetPlayoffResults(pFileName,format1, format2, format3, format4,
			m_currentRound, m_playoffRounds, m_currentPlayoffDay, m_currentPlayoffGame,
			m_seasonStarted, pDoc->avg.m_sched.m_currentMonth, pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame, Game, visitor, home);


	



		int current_day = pDoc->avg.m_sched.m_currentDay;
		pDoc->avg.m_sched.m_currentRound = m_currentRound;

		if(current_day != start_day)
		{

				for(int j=0; j<=30; j++)
				{
					for(int k=0; k<=15; k++)
					{
						pDoc->avg.m_sched.m_game_score[12][j][k] = po->m_gameScore[12][j][k];
						pDoc->avg.m_sched.m_schedule[12][j][k] = po->m_sched[12][j][k];
					}
				}
			
			int m = pDoc->avg.m_sched.m_currentMonth;
			int d = pDoc->avg.m_sched.m_currentDay;
			m_combo_month.SetCurSel(m);
			m_combo_day.SetCurSel(d);
			DisplaySchedule();
			//pDoc->HealInjury(3);
		}



		if(orig_da == -1) orig_da = pDoc->avg.m_sched.m_currentDay;
		if(orig_ro == -1) orig_ro = m_currentRound;

		pDoc->avg.m_sched.m_series_win1 = po->m_win1;
		pDoc->avg.m_sched.m_series_win2 = po->m_win2;
		
		int game = po->m_sched[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame];
		int score =	po->m_gameScore[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame];



		int v = game / 100;
		int h = game - v * 100;	
		if(v<1 || v>33) v = 1;
		if(h<1 || h>33) h = 2;




		if(sim_po_day == true && (pDoc->avg.m_sched.m_currentDay == orig_da + 1 || m_currentRound == orig_ro + 1))
		{
			if(m_currentRound == orig_ro + 1) show_po_screen = true;
			condition = false;
		}
		else if(sim_po_round == true  && m_currentRound == orig_ro + 1)
		{
			condition = false;
			show_po_screen = true;
		}

		if(po->m_champion == true)
		{
			condition = false;
			show_po_screen = true;
			if(pDoc->avg.m_settings.m_current_stage == 0)
				pDoc->avg.m_settings.m_current_stage = 1;
	//((CBBallApp*)AfxGetApp())->SwitchView( 8 );
		}

		if(po->m_champion == false && sim_po_all == true)  condition = true;

		if(condition == true && m_sim_ok == true && sim_po_game == false) SimGame(v,h,pDoc->avg.m_sched.m_currentGame+1);
		else condition = false;

		//else if(Game == FALSE) condition = false;
		if(sim_po_game == true)
		{
			condition = false;

			SimGame(v,h,pDoc->avg.m_sched.m_currentGame+1);

		}


		if(po->m_champion == false && all == true)
		{
			show_po_screen = false;
		}

	}
	while(condition == true);

	if(sim_po_game == false)
	{

	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
					pDoc->avg.m_sched.m_game_score[i][j][k] = po->m_gameScore[i][j][k];

					pDoc->avg.m_sched.m_schedule[i][j][k] = po->m_sched[i][j][k];
			}
		}
	}

	}

	int m = pDoc->avg.m_sched.m_currentMonth;
	int d = pDoc->avg.m_sched.m_currentDay;
	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);

	DisplaySchedule();
	delete po;	

	if(show_po_screen == true)
	{
		CPlayoffDlg* play;
		play = new CPlayoffDlg;
		play->m_leagueName = pDoc->avg.m_settings.m_league_name;
		play->m_path = pDoc->avg.m_settings.m_path;

		for(int i=0; i<=32; i++)
		{
			play->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
			play->m_record[i] = pDoc->avg.m_standings[i];
		}
		play->DoModal();
		delete play;	
	}

	DisableButtons();

	}
	while(pDoc->avg.m_settings.m_current_stage == 0 && all == true && m_sim_ok == true);

	m_sim_ok = false;


	if(pDoc->avg.m_settings.m_current_stage == 1)
		((CBBallApp*)AfxGetApp())->SwitchView( 8 );




}

void CScheduleView::WritePlayoffResults(CString pFileName, int m_currentMonth, int m_currentDay, int m_currentGame,
				int m_team1, int score1, int m_win1, int m_team2, int score2, int m_win2)
{
	
		if(score1 > score2) m_win1 = m_win1 + 1; else m_win2 = m_win2 + 1;
		CFile file(	pFileName, CFile::modeWrite	);
		int seek = 72046 + m_currentDay * 96 + m_currentGame * 12 ;
		file.Seek(seek, CFile::begin );
		
		CString buffer;
		buffer.Format("%d", m_team1);
		file.Write( buffer, 2);

		buffer.Format("%d", score1);
		file.Write( buffer, 3);

		buffer.Format("%d", m_win1);
		file.Write( buffer, 1);

		buffer.Format("%d", m_team2);
		file.Write( buffer, 2);

		buffer.Format("%d", score2);
		file.Write( buffer, 3);

		buffer.Format("%d", m_win2);
		file.Write( buffer, 1);
}

void CScheduleView::DisplayAllStarSchedule()
{
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

//	m_combo_month.SetCurSel(0);
//	m_combo_day.SetCurSel(0);


	CString team_names[33];
	team_names[3] = pDoc->avg.m_settings.m_conferenceName1;
	team_names[4] = pDoc->avg.m_settings.m_conferenceName2;
	team_names[1] = "Rookies";
	team_names[2] = "Sophomores";

	int day = 0;
	int month = 0;
	
	for(int i=0; i<=15; i++)
	{
	

		int sc1 = pDoc->avg.m_sched.m_game_score[month][day][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[month][day][i] - sc1*1000;

	
		CString visitor = team_names[1+i*2];
		CString home = team_names[2+i*2];
//		visitor.MakeUpper();
//		home.MakeUpper();

		bool game_scheduled = false;
	
		if(visitor != "")
		{
			game_scheduled = true;
			m_buttons[i+1].ShowWindow(TRUE);
			m_static_score[i*2+1].ShowWindow(TRUE);
			//m_buttons[i+1].Repaint(TRUE);
			m_buttons[i+1].SetWindowText(visitor);

		}
		else
		{
			m_buttons[i+1].ShowWindow(FALSE);
			m_static_score[i*2+1].ShowWindow(FALSE);

		}
		
		if(home != "")
		{
			game_scheduled = true;
			m_buttons[i+17].ShowWindow(TRUE);
			m_static_score[i*2+2].ShowWindow(TRUE);
			//m_buttons[i+17].Repaint(TRUE);
			m_buttons[i+17].SetWindowText(home);
		}
		else
		{
			m_buttons[i+17].ShowWindow(FALSE);
			m_static_score[i*2+2].ShowWindow(FALSE);

		}
		




		if(game_scheduled == true)
		{
			DisplayScore(i+1, sc1, sc2);
			m_buttons[i+33].ShowWindow(TRUE);
			m_buttons[i+49].ShowWindow(TRUE);
			m_buttons[i+65].ShowWindow(TRUE);
		}
		else
		{
			m_buttons[i+33].ShowWindow(FALSE);
			m_buttons[i+49].ShowWindow(FALSE);
			m_buttons[i+65].ShowWindow(FALSE);
		}


			



	}




	DisableButtons();


	for(int i=0; i<=1; i++)
	{
		int sc = pDoc->avg.m_sched.m_game_score[month][day][i];
		if(sc == 0)
		{
			m_buttons[33+i].EnableWindow(TRUE);
			m_buttons[49+i].EnableWindow(FALSE);
			m_buttons[65+i].EnableWindow(TRUE);

		}
		else 
		{
			m_buttons[33+i].EnableWindow(FALSE);
			m_buttons[49+i].EnableWindow(TRUE);
			m_buttons[65+i].EnableWindow(FALSE);

		}

	}

	m_combo_month.SetCurSel(0);
	m_combo_day.SetCurSel(0);


}

void CScheduleView::OnButtonGametype() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();

	CTypeGameDlg *type = new CTypeGameDlg;
	for(int i=0; i<=32; i++)
	{
		type->m_team_names[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];

	}
	m_single_team = 0;
	type->m_default_team = pDoc->m_combo_team_index - 1;
	if(type->m_default_team < 0) type->m_default_team = 0;

	type->m_gameType = EXHIBITION;
	int result = type->DoModal();
	if(result == IDOK)
	{
		if(type->m_gameType == SINGLE_TEAM)		
		{
			pDoc->m_game_type = SINGLE_TEAM;
			m_single_team = type->m_singleteam;
		}
		else if(type->m_gameType == EXHIBITION)		
		{
			pDoc->m_game_type = EXHIBITION;
			pDoc->m_coach_visitor_index = type->m_exhteam1;
			pDoc->m_coach_home_index = type->m_exhteam2;
			((CBBallApp*)AfxGetApp())->SwitchView( 5 );	
		}
	}


	delete type;
	
}

void CScheduleView::OnButtonSimtilasw() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	
	m_sim_ok = true;




	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();


	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		SimPlayoffGame(false, false, false, true, 0, 0);

	}
	else
	{



	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



	int d=da;
	int m=mo; 

	int start_da = da;
	int start_mo = mo;
	int end_da = da;
	int end_mo = mo + 1;
	bool end = false;
	
	do
	{


  



	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);
	DisplaySchedule();

	for(int i=0; i<=15; i++)
	{
	
		int t1 = pDoc->avg.m_sched.m_schedule[m][d][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[m][d][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[m][d][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[m][d][i] - sc1*1000;
		if(sc1 == 0 && sc2 == 0 && t1 > 0 && t2 > 0 && m_sim_ok == true)
		{
			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{	
				SetCurrentGame(m,d,i+1);	
				SimGame(t1, t2, i+1);
			}
		}

	}

	d=d+1;
//	if(d > 30)
	if(d > m_days_in_month[m] - 1)
	{
		d=0;
		m=m+1;
	}

	//if(m == end_mo && d == end_da) end = true;


	}
	while (m <= 11 && m_sim_ok == true && end == false && pDoc->avg.m_sched.m_regular_season_ended == false);
	
	}	


	m_sim_ok = false;
	DisableButtons();

	
}



void CScheduleView::OnButtonPrevious() 
{
	// TODO: Add your control notification handler code here
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();

	if(da > 0 || mo > 0) 
	{

	da = da - 1;
	if(da < 0)
	{
		if(mo < 12) mo = mo - 1;
		da = m_days_in_month[mo]-1;
		RefillDaysInMonth(mo);
	}
	m_combo_day.SetCurSel(da);
	m_combo_month.SetCurSel(mo);
	SetCurrentGame(mo, da, 1);
	DisplaySchedule();

	}
	


}

void CScheduleView::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();

	if(mo < 12 || da < 30) 
	{


	da = da + 1;
	if(da >= m_days_in_month[mo])
	{
		da = 0;
		if(mo < 12) mo = mo + 1;
		RefillDaysInMonth(mo);
	}
	m_combo_day.SetCurSel(da);
	m_combo_month.SetCurSel(mo);
	SetCurrentGame(mo, da, 1);
	DisplaySchedule();
	}
	



}

void CScheduleView::RefillDaysInMonth(int mon)
{
	m_combo_day.ResetContent();
	//int mo = m_combo_month.GetCurSel();
	for(int i=1; i<=m_days_in_month[mon]; i++)
	{
		CString str;
		str.Format("%d", i);
		m_combo_day.AddString(str);
	}

	m_combo_day.SetCurSel(0);
	m_combo_month.SetCurSel(mon);
}












void CScheduleView::SimAsw()
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();

	CString file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".asw";

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == 0) 
	{


	int m_index[81], scores[31];

	CAllStarWeekend* asw = new CAllStarWeekend;
	for(int i=0; i<=80; i++)
	{
		m_index[i] = 0;
	}
	for(int i=0; i<=30; i++)
	{
		scores[i] = 0;
	}

	asw->avg = pDoc->avg;
	asw->SelectThreePointContestants();
	asw->SelectDunkContestants();
	asw->SelectAllStarTeams();

	for(int i=1; i<=12; i++)
	{
		m_index[i] = asw->m_actual[i].m_id;
	}
	for(int i=1; i<=12; i++)
	{
		m_index[15+i] = asw->m_actual[30+i].m_id;
	}


	asw->SelectRookieTeams();

	for(int i=1; i<=10; i++)
	{
		m_index[30+i] = asw->m_actual[i].m_id;
	}
	for(int i=1; i<=10; i++)
	{
		m_index[45+i] = asw->m_actual[30+i].m_id;
	}




	for(int i=1; i<=8; i++)
	{
		m_index[60+i] = asw->m_actual[60+i].m_id;
	}



	for(int i=1; i<=8; i++)
	{
		m_index[70+i] = asw->m_actual[70+i].m_id;
	}



	asw->SimThreePointContestRoundOne();
	asw->SimThreePointContestRoundTwo();
	asw->SimThreePointContestRoundThree();

	asw->SimSlamDunkContestRoundOne();
	asw->SimSlamDunkContestRoundTwo();


	// TODO: Add extra validation here
	for(int i=61; i<=80; i++)
	{
		m_index[i] = asw->m_actual[i].m_id;
	}


		for(int i=1; i<=30; i++)
		{
			int pointer = m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}

			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "") pDoc->avg.m_actual[pointer].m_all_star = 1;
			scores[i] = asw->m_scores[i];
		}
		for(int i=31; i<=60; i++)
		{
			int pointer = m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}



			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "") pDoc->avg.m_actual[pointer].m_rookie_star = 1;
		}

		for(int i=61; i<=68; i++)
		{
			int pointer = m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}


			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "")
			{
				pDoc->avg.m_actual[pointer].m_3contest = 1;
				if(i==61)
				{
					pDoc->avg.m_actual[pointer].m_3contest = 2;

					pDoc->avg.m_settings.m_3contest = pDoc->avg.m_actual[pointer].m_id;
					pDoc->avg.m_settings.m_3contest_index = pDoc->avg.m_actual[pointer].m_current_team;
									
				}
			}
		}

		for(int i=71; i<=78; i++)
		{
			int pointer = m_index[i];

			bool found = false;
			for(int j=1; j<=1440; j++)
			{
				if(pDoc->avg.m_actual[j].m_id == pointer && pDoc->avg.m_actual[j].m_name != "" && found == false)
				{
					found = true;
					pointer = j;
				}

			}



			CString na = pDoc->avg.m_actual[pointer].m_name;
			if(na != "")
			{
				pDoc->avg.m_actual[pointer].m_dunkcontest = 1;
				if(i==71)
				{
					pDoc->avg.m_actual[pointer].m_dunkcontest = 2;

					pDoc->avg.m_settings.m_dunkcontest = pDoc->avg.m_actual[pointer].m_id;
					pDoc->avg.m_settings.m_dunkcontest_index = pDoc->avg.m_actual[pointer].m_current_team;
									
					
				}

			}
		}



	delete asw;
	m_asw_button_pressed = true;
	SetCurrentGame(0,0,1);
	DisplayAllStarSchedule();
	SimAllStarGame(1);
	SimAllStarGame(2);

	SaveAllStarWeekend(m_index, scores);
	m_simmed_asw = true;
	}
	
}


void CScheduleView::SaveAllStarWeekend(int pointer[], int scores[])
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();

	CString file_name = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".asw";

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) == 0) 
	{

		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[10001];
		memset( buffer, ' ', 10000);
		file.Write( buffer, 10000);
		file.Close();
	}

	CString buffer1;
	CStdioFile file( file_name, CFile::modeWrite );
	for(int i=0; i<=80; i++)
	{
		buffer1.Format("%6d", pointer[i]);	
		file.WriteString( buffer1 + "\n");			
	}		

	for(int i=0; i<=30; i++)
	{
		buffer1.Format("%4d", scores[i]);	
		file.WriteString( buffer1 + "\n");			
	}		

	file.Close(); 

}

void CScheduleView::OnButtonGo() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
//	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();
//	CDropList* pList = m_pDropBtn->GetList();
	pDoc->m_combo_team_index = m_combo_teams.GetCurSel();


	((CBBallApp*)AfxGetApp())->SwitchView( 3 );
	
}

void CScheduleView::OnSetupSettings() 
{
	// TODO: Add your command handler code here
//	CBBallDoc* pDoc = GetDocument();
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->Options();
	
}

void CScheduleView::OnSetupSetgameplan() 
{
	// TODO: Add your command handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	int result = pDoc->GamePlan();	
}

void CScheduleView::OnSetupProposetrade() 
{
	// TODO: Add your command handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();	
	int result = pDoc->ProposeTrade();
	
}

bool CScheduleView::CheckForCoachControlledGame(int t1, int t2)
{
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();	
	bool stop = false;
	CString coach_v, coach_h;
	
	
		if(t1 > 0)
			coach_v = pDoc->avg.m_settings.m_control[t1-1];
		if(t2 > 0)
			coach_h = pDoc->avg.m_settings.m_control[t2-1];

		if(coach_v == "Player")
		{
			CString str;
			str.Format("Do you want stop simming to allow you to coach your %s (Only click No if you prefer to simulate the game)", pDoc->avg.m_settings.m_leagueTeamNames[t1-1]);
			int result = MessageBox(str, "Head to Courtside", MB_YESNO);
			if(result == IDYES) stop = true;
		}
		else if(coach_h == "Player")
		{
			CString str;
			str.Format("Do you want to stop simming to allow you to coach your %s (Only click No if you prefer to simulate the game)", pDoc->avg.m_settings.m_leagueTeamNames[t2-1]);
			int result = MessageBox(str, "Head to Courtside", MB_YESNO);
			if(result == IDYES) stop = true;
		}
		return stop;

}

void CScheduleView::UpdatePlayoffsAfterCoachedGame()
{




		CBBallDoc *pDoc = (CBBallDoc*) GetDocument();







		CPlayoff *po;
		po = new CPlayoff;
		CString pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";
		CString format1, format2, format3, format4;
		int m_currentRound = 0, m_playoffRounds = 0, m_currentPlayoffDay = 0, m_currentPlayoffGame = 0;
		int currentMonth = 0, currentDay = 0, currentGame = 0;
		BOOL m_seasonStarted = FALSE;


	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{
						po->m_gameScore[i][j][k] = pDoc->avg.m_sched.m_game_score[i][j][k]; 

						po->m_sched[i][j][k] = pDoc->avg.m_sched.m_schedule[i][j][k];
			}
		}
	}
		
	for(int i=0; i<=32; i++)
	{
		//pDoc->avg.m_standings[i].m_divisionChamps = false;
		po->record[i] = pDoc->avg.m_standings[i];
	}


	bool show_po_screen = false;
	int start_day = pDoc->avg.m_sched.m_currentDay;
	
	
		BOOL Game = FALSE;


		

		bool round_complete = po->GetPlayoffResults(pFileName,format1, format2, format3, format4,
		m_currentRound, m_playoffRounds, m_currentPlayoffDay, m_currentPlayoffGame,
		 m_seasonStarted, pDoc->avg.m_sched.m_currentMonth, pDoc->avg.m_sched.m_currentDay, pDoc->avg.m_sched.m_currentGame, Game, 0, 0);

		int current_day = pDoc->avg.m_sched.m_currentDay;
		pDoc->avg.m_sched.m_currentRound = m_currentRound;

		

				for(int j=0; j<=30; j++)
				{
					for(int k=0; k<=15; k++)
					{
						pDoc->avg.m_sched.m_game_score[12][j][k] = po->m_gameScore[12][j][k];
						pDoc->avg.m_sched.m_schedule[12][j][k] = po->m_sched[12][j][k];
					}
				}
			
		




		

		pDoc->avg.m_sched.m_series_win1 = po->m_win1;
		pDoc->avg.m_sched.m_series_win2 = po->m_win2;
		
	
	//	int game = po->m_sched[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame];
	//	int score =	po->m_gameScore[pDoc->avg.m_sched.m_currentMonth][pDoc->avg.m_sched.m_currentDay][pDoc->avg.m_sched.m_currentGame];



	//	int v = game / 100;
	//	int h = game - v * 100;	
	//	if(v<1 || v>33) v = 1;
	//	if(h<1 || h>33) h = 2;



	
		if(round_complete == true)
		{
			show_po_screen = true;
		}

		if(po->m_champion == true)
		{
			show_po_screen = true;
			if(pDoc->avg.m_settings.m_current_stage == 0)
				pDoc->avg.m_settings.m_current_stage = 1;
		}



	delete po;	

	if(show_po_screen == true)
	{
		CPlayoffDlg* play;
		play = new CPlayoffDlg;
		play->m_leagueName = pDoc->avg.m_settings.m_league_name;
		play->m_path = pDoc->avg.m_settings.m_path;

		for(int i=0; i<=32; i++)
		{
			play->m_leagueTeamNames[i] = pDoc->avg.m_settings.m_leagueTeamNames[i];
			play->m_record[i] = pDoc->avg.m_standings[i];
		}
		play->DoModal();
		delete play;	
	}



}
























void CScheduleView::SetCurrentPlayoffGame(int mo, int da, int ga)//not really playoff just a unsafe version of SetCurrentGame, used by coach only buttons
{
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
		pDoc->avg.m_sched.m_currentDay = da;
		pDoc->avg.m_sched.m_currentMonth = mo;
		pDoc->avg.m_sched.m_currentGame = ga-1;

	if(pDoc->avg.m_sched.m_playoff_started == true)
	{
		int t1 = m_visitor_teams[ga-1];	
		int t2 = m_home_teams[ga-1];


		CPlayoff* po = new CPlayoff;
		CString pFileName = pDoc->avg.m_settings.m_path + pDoc->avg.m_settings.m_league_name + ".sch";
		po->GetPlayoffMatchupWins(pFileName, t1, t2);
		pDoc->avg.m_sched.m_series_win1 = po->m_win1;
		pDoc->avg.m_sched.m_series_win2 = po->m_win2;
		delete po;


	}

}

BOOL CScheduleView::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/scheduleoverview.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);

	
	return CFormView::OnHelpInfo(pHelpInfo);
}

void CScheduleView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/scheduleoverview.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHe
}

HBRUSH CScheduleView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
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
		  //pDC->SetTextColor(STATICCOLOR);
		  pDC->SetTextColor(RGB(255,215,0));
		  //pDC->SetBkColor(logbrush.lbColor);
		  pDC->SetBkColor(BLACK);
		  return myBrush;
		  //return hbr;
     case CTLCOLOR_BTN:
          //pDC->SetTextColor(RGB(0,255,255));
          //pDC->SetBkColor(RGB(255,128,128));
          return hbr;
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
          return hbr;

     //This shouldn't occurr since we took all the cases, but
     //JUST IN CASE, return the new brush
     default:
          return hbr;
	}	
	

}

void CScheduleView::OnTeamRoster() 
{
	// TODO: Add your command handler code here
	/*if(pDoc->m_page == 8) OpenRookieDlg();
	else if(pDoc->m_page == 9) OpenFreeAgentDlg();
	else if(pDoc->m_page == 10) OpenStaff();
	else if(pDoc->m_page == 11) OpenBudget();
	else if(pDoc->m_page == 5) OpenDepthChart();
	else if(pDoc->m_page == 7) OpenRecords();
	else if(pDoc->m_page == 6) OpenTeamHistory();
	else if(pDoc->m_page == 4) OpenTradeDlg();
	else if(pDoc->m_page == 3) OpenTransactionsDlg();
	else if(pDoc->m_page == 2) OpenTeamScheduleDlg();
	else if(pDoc->m_page == 1) ViewTeamRosters();*/
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 1;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamResults() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 2;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamBudget() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 11;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamDraftpreview() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 8;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamFreeagents() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 9;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamHistory() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 6;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamLineup() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 5;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamRecords() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 7;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamStaff() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 10;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamTrade() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 4;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnTeamTransactions() 
{
	// TODO: Add your command handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	pDoc->m_page = 3;
	((CBBallApp*)AfxGetApp())->SwitchView( 3 );	
	
}

void CScheduleView::OnButtonSimdays() 
{
	// TODO: Add your control notification handler code here
	CBBallDoc *pDoc = (CBBallDoc*) GetDocument();
	

	m_xdays = m_slider_days.GetPos();
	int xdays = m_xdays;
	m_sim_ok = true;
	m_sim_season = true;

	pDoc->avg.m_sched.GetNextGame(pDoc->avg.m_sched.m_playoff_started);
	m_combo_month.SetCurSel(pDoc->avg.m_sched.m_currentMonth);
	m_combo_day.SetCurSel(pDoc->avg.m_sched.m_currentDay);
	DisplaySchedule();


	//if(pDoc->avg.m_sched.m_playoff_started == true)
	//{
	//	SimPlayoffGame(false, false, false, true, 0, 0);

	//}
	if(pDoc->avg.m_sched.m_playoff_started != true)
	//else
	{



	int da = m_combo_day.GetCurSel();
	int mo = m_combo_month.GetCurSel();
	



	int d=da;
	int m=mo; 

	int start_da = da;
	int start_mo = mo;
	int end_da = da;
	int end_mo = mo + 1;
	bool end = false;
	
	do
	{


  



	m_combo_month.SetCurSel(m);
	m_combo_day.SetCurSel(d);
	DisplaySchedule();

	for(int i=0; i<=15; i++)
	{
		
		int t1 = pDoc->avg.m_sched.m_schedule[m][d][i] / 100;
		int t2 = pDoc->avg.m_sched.m_schedule[m][d][i] - t1*100;
		int sc1 = pDoc->avg.m_sched.m_game_score[m][d][i] / 1000;
		int sc2 = pDoc->avg.m_sched.m_game_score[m][d][i] - sc1*1000;
		if(sc1 == 0 && sc2 == 0 && t1 > 0 && t2 > 0 && m_sim_ok == true)
		{
			if(m_single_team == 0 || ( m_single_team > 0 && (m_single_team == t1 || m_single_team == t2)))
			{	
				SetCurrentGame(m,d,i+1);	
				bool asw_simmed = m_simmed_asw;
				SimGame(t1, t2, i+1);//if asw simmed then go back and fill in the blank game before going on
				if(m_simmed_asw != asw_simmed){ d=0;m=0;i=0;}
			}
		}

	}

	d=d+1;
//	if(d > 30)
	if(d > m_days_in_month[m] - 1)
	{
		d=0;
		m=m+1;
	}

	//if(m == end_mo && d == end_da) end = true;
	xdays = xdays - 1;
	
	}
	while (m <= 11 && m_sim_ok == true && end == false && pDoc->avg.m_sched.m_regular_season_ended == false && xdays > 0);
	
	}	

	m_sim_ok = false;
	DisableButtons();
	
}

void CScheduleView::OnReleasedcaptureSliderDays(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_xdays = m_slider_days.GetPos();

	CString dayx;
	dayx.Format("Sim %d day(s)", m_xdays);
//	dayx.MakeUpper();
	m_sim_x.SetWindowText(dayx);	
	*pResult = 0;
}

void CScheduleView::OnEditCities() 
{
	// TODO: Add your command handler code here

	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	pDoc->EditCities();	
}

void CScheduleView::OnEditPlayers() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	pDoc->EditPlayers();	
}

void CScheduleView::OnEditStaff() 
{
	// TODO: Add your command handler code here
	CBBallDoc * pDoc = (CBBallDoc*) GetDocument();
	pDoc->EditStaffs();
	
}

void CScheduleView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CFormView::OnPaint() for painting messages

//	Graphics graphics(dc.m_hDC);


//	CString image = "roster.jpg";
//	Bitmap bitmap(image.AllocSysString());
//	graphics.DrawImage(&bitmap, 1, 1);

//	Color blueColor(255, 0, 0, 255);
   // Clear the screen with a blue background.
  // graphics.Clear(blueColor);


//	graphics.ReleaseHDC(dc.m_hDC);


}


void CScheduleView::OnNMCustomdrawSliderDays(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
