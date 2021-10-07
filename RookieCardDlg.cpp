// RookieCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#include "MyComboBox.h"
#include "RookieCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRookieCardDlg dialog


CRookieCardDlg::CRookieCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRookieCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRookieCardDlg)
	m_edit_owner = _T("");
	//}}AFX_DATA_INIT

	m_pl_index_start = 1;
	m_pl_index_end = 1440;
}


void CRookieCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRookieCardDlg)
	DDX_Control(pDX, IDC_BUTTON_SCOUT, m_buttonScout);
	DDX_Control(pDX, IDC_LIST_CTRL, m_listctrlskill);
	DDX_Control(pDX, IDC_LIST_FUTURE2, m_listFuture);
	DDX_Control(pDX, IDC_LIST_CTRL_STATS2, m_listCtrlStats);
	DDX_Control(pDX, IDC_LIST_CTRL_SHOT2, m_listCtrlShot);
	DDX_Control(pDX, IDC_LIST_REPORT2, m_list_report);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRookieCardDlg, CDialog)
	//{{AFX_MSG_MAP(CRookieCardDlg)
	//ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_FORWARD, OnButtonForward)
	ON_BN_CLICKED(IDC_BUTTON_SCOUT, OnButtonScout)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_LBN_SELCHANGE(IDC_LIST_REPORT2, &CRookieCardDlg::OnLbnSelchangeListReport2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRookieCardDlg message handlers

BOOL CRookieCardDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 myBrush.CreateSolidBrush(DLGCOLOR); 
 myBrush2.CreateSolidBrush(LISTBOXCOLOR); 

	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, USERFONT);    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.

	m_pointer = avg.m_actual[m_player_index].m_id;

	
	CPlayer m_player = avg.m_actual[m_player_index];
	

	bool singleScout = false;
	int leadScout = 0;
	for(int  i=0; i<=32; i++)
	{
		if( avg.m_settings.m_scouts[i] == 1 && i<32)
		{
			singleScout = true;
			leadScout = i;
		}
	}

	int index = 0;
	if(singleScout == true) index = leadScout;



		if(avg.m_settings.m_scouts[32] == 1 || index < 0)
		{
			CStaff m_avgStaff;
			m_avgStaff.InitVariables();	
			m_scout = m_avgStaff;
		}
		else if(m_title == "Coach")
			m_scout = avg.m_coach[index];
		else if(m_title == "GM")
			m_scout = avg.m_gm[index];
		else  if(m_title == "Scout")
			m_scout = avg.m_scout[index];


	InitListCtrl();
	Player();
	

//	GetCurrentID();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CRookieCardDlg::Player() 
{
	// TODO: Add your control notification handler code here
	CString name = avg.m_actual[m_player_index].m_pos + " " + avg.m_actual[m_player_index].m_name;
	SetWindowText(name);
	DisplayRating();

}

void CRookieCardDlg::InitListCtrl()
{
/*    LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 100;
	lf.lfHeight = 12;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font.*/
	

	m_listCtrlStats.SetFont(&m_font);
	m_listCtrlShot.SetFont(&m_font);
	m_listctrlskill.SetFont(&m_font);
	m_listFuture.SetFont(&m_font);
	m_list_report.SetFont(&m_font);

    m_listCtrlStats.InsertColumn(0,"Pos");    
    m_listCtrlStats.InsertColumn(1,"Player");
    m_listCtrlStats.InsertColumn(2,"Age");
    m_listCtrlStats.InsertColumn(3,"Ht");
    m_listCtrlStats.InsertColumn(4,"Wt");



    m_listCtrlStats.InsertColumn(5,"Offense");
    m_listCtrlStats.InsertColumn(6,"O");
    m_listCtrlStats.InsertColumn(7,"D");
    m_listCtrlStats.InsertColumn(8,"P");
    m_listCtrlStats.InsertColumn(9,"T");
    m_listCtrlStats.InsertColumn(10,"Defense");
    m_listCtrlStats.InsertColumn(11,"O");
    m_listCtrlStats.InsertColumn(12,"D");
    m_listCtrlStats.InsertColumn(13,"P");
    m_listCtrlStats.InsertColumn(14,"T");
  
	
    m_listCtrlStats.SetColumnWidth( 0, 32);
    m_listCtrlStats.SetColumnWidth( 1, 128);
    m_listCtrlStats.SetColumnWidth( 2, 33);
    m_listCtrlStats.SetColumnWidth( 3, 33);
    m_listCtrlStats.SetColumnWidth( 4, 33);
    
	
	
	m_listCtrlStats.SetColumnWidth( 5, 55);
    m_listCtrlStats.SetColumnWidth( 6, 20);
    m_listCtrlStats.SetColumnWidth( 7, 20);
    m_listCtrlStats.SetColumnWidth( 8, 20);
    m_listCtrlStats.SetColumnWidth( 9, 20);
    m_listCtrlStats.SetColumnWidth(10, 55);
    m_listCtrlStats.SetColumnWidth(11, 20);
    m_listCtrlStats.SetColumnWidth( 12,20);
    m_listCtrlStats.SetColumnWidth( 13, 20);
    m_listCtrlStats.SetColumnWidth( 14, 20);
    m_listCtrlStats.SetBkColor(BK_COLOR);
    m_listCtrlStats.SetTextBkColor(TEXT_BK_COLOR);
    m_listCtrlStats.SetTextColor(RGB(0,0,0));
	
	m_listCtrlShot.InsertColumn(0,"2ga");    
    m_listCtrlShot.InsertColumn(1,"2g%");
    m_listCtrlShot.InsertColumn(2,"fta");
    m_listCtrlShot.InsertColumn(3,"ft%");
    m_listCtrlShot.InsertColumn(4,"3ga");
    m_listCtrlShot.InsertColumn(5,"3g%");
    m_listctrlskill.InsertColumn(0,"oreb");
    m_listctrlskill.InsertColumn(1,"dreb");
    m_listctrlskill.InsertColumn(2,"ast");
    m_listctrlskill.InsertColumn(3,"stl");
    m_listctrlskill.InsertColumn(4,"to");
    m_listctrlskill.InsertColumn(5,"blk");
  
	
    m_listCtrlShot.SetColumnWidth( 0, 40);
    m_listCtrlShot.SetColumnWidth( 1, 40);
    m_listCtrlShot.SetColumnWidth( 2, 40);
    m_listCtrlShot.SetColumnWidth( 3, 39);
    m_listCtrlShot.SetColumnWidth( 4, 39);
    m_listCtrlShot.SetColumnWidth( 5, 39);
    m_listctrlskill.SetColumnWidth( 0, 40);
    m_listctrlskill.SetColumnWidth( 1, 40);
    m_listctrlskill.SetColumnWidth( 2, 40);
    m_listctrlskill.SetColumnWidth( 3, 39);
    m_listctrlskill.SetColumnWidth( 4, 39);
    m_listctrlskill.SetColumnWidth( 5, 39);
	
	m_listFuture.InsertColumn(0,"Talent");    
    m_listFuture.InsertColumn(1,"Skill");
    m_listFuture.InsertColumn(2,"Intangibles");
    m_listFuture.SetColumnWidth( 0, 69);
    m_listFuture.SetColumnWidth( 1, 69);
    m_listFuture.SetColumnWidth( 2, 69);

    m_listCtrlShot.SetBkColor(BK_COLOR);
    m_listCtrlShot.SetTextBkColor(TEXT_BK_COLOR);
    m_listCtrlShot.SetTextColor(RGB(0,0,0));
    m_listFuture.SetTextBkColor(TEXT_BK_COLOR);
    m_listFuture.SetBkColor(BK_COLOR);
    m_listFuture.SetTextColor(RGB(0,0,0));

}





void CRookieCardDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}



void CRookieCardDlg::OnButtonForward() 
{
	// TODO: Add your control notification handler code here

	do
	{
		m_player_index = m_player_index + 1;
		//if(m_player_index > 1440) m_player_index = 1;
		if(m_player_index > m_pl_index_end) m_player_index = m_pl_index_start;
	}
	while (avg.m_actual[m_player_index].m_name == "");
	
	m_pointer = avg.m_actual[m_player_index].m_id;

	Player();
	
}

void CRookieCardDlg::OnButtonBack() 
{
	// TODO: Add your control notification handler code here
	do
	{
		m_player_index = m_player_index - 1;
		//if(m_player_index < 1) m_player_index = 1440;
		if(m_player_index < m_pl_index_start) m_player_index = m_pl_index_end;


	}
	while (avg.m_actual[m_player_index].m_name == "");



	m_pointer = avg.m_actual[m_player_index].m_id;

	
	Player();
	
}

void CRookieCardDlg::DisplayRating()
{

	m_listCtrlStats.DeleteAllItems();
	m_listCtrlShot.DeleteAllItems();
	m_listctrlskill.DeleteAllItems();
	m_listFuture.DeleteAllItems();
	CPlayer m_player = avg.m_actual[m_player_index];

	CString string = m_scout.m_name;
	if(string != "") string = "Scouting Report by " + m_title + " " + string;
	else m_buttonScout.ShowWindow(FALSE);
	m_buttonScout.SetWindowText(string);
	

	m_player.SetAdjTrueRatingSimple(m_player.GetFgm(), m_player.GetFga(), m_player.GetTfgm(), m_player.GetTfga(), m_player.GetFtm(),  m_player.GetFta(), m_player.GetOreb(),  m_player.GetReb(), m_player.GetAst(), m_player.GetStl(), m_player.GetTo(), m_player.GetBlk(), m_scout.m_scoring, m_scout.m_shooting, m_scout.m_rebounding, m_scout.m_passing, m_scout.m_defense);
	m_player.SetTradeTrueRating(0);
	m_player.SetAdjTradeValue(m_scout.m_pot1, m_scout.m_pot2, m_scout.m_effort);




	CString pos = m_player.GetPos();
	CString name = m_player.GetName();
	SetWindowText(pos + " " + name);
	CString OutO, PenO, PostO, TransO, OutD, PenD, PostD, TransD, Age, Ht, Wt;

	int ht = m_player.m_height;
	int ft = m_player.m_height / 12;
	int in = m_player.m_height - ft*12;
	Ht.Format("%d' %d", ft, in);

	int wt = m_player.m_weight;
	Wt.Format("%d", wt);


	int ag = m_player.GetAge();
	Age.Format("%d", ag);
	int o = m_player.GetMovOff();
	OutO.Format("%d", o);
	int p = m_player.GetPenOff();
	PenO.Format("%d", p);
	int i = m_player.GetPostOff();
	PostO.Format("%d", i);
	int f1 = m_player.GetTransOff();
	TransO.Format("%d", f1);
	int od = m_player.GetMovDef();
	OutD.Format("%d", od);
	int pd = m_player.GetPenDef();
	PenD.Format("%d", pd);
	int id = m_player.GetPostDef();
	PostD.Format("%d", id);
	int fd = m_player.GetTransDef();
	TransD.Format("%d", fd);


	m_listCtrlStats.InsertItem(0,pos);
	m_listCtrlStats.SetItemText(0,1,name);
	m_listCtrlStats.SetItemText(0,2,Age);
	m_listCtrlStats.SetItemText(0,3,Ht);
	m_listCtrlStats.SetItemText(0,4,Wt);
	
	
	
	m_listCtrlStats.SetItemText(0,6,OutO);
	m_listCtrlStats.SetItemText(0,7,PenO);
	m_listCtrlStats.SetItemText(0,8,PostO);
	m_listCtrlStats.SetItemText(0,9,TransO);
	m_listCtrlStats.SetItemText(0,11,OutD);
	m_listCtrlStats.SetItemText(0,12,PenD);
	m_listCtrlStats.SetItemText(0,13,PostD);
	m_listCtrlStats.SetItemText(0,14,TransD);
	
	m_player.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	



	int r = m_player.GetPrFga();
	CString s;
    int rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrFga(rating);

	s.Format("%d", rating);
	m_listCtrlShot.InsertItem(0,s);


	r = m_player.GetPrFgp();
    rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrFgp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,1,s);


	

	r = m_player.GetPrFta();
    rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrFta(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,2,s);



    r = m_player.GetPrFtp();
	rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrFtp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,3,s);



	r = m_player.GetPrTga();
    rating = m_player.PrRating(false, r, m_scout.m_scoring);
	m_player.SetAdjPrTga(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,4,s);



    r = m_player.GetPrTgp();
	rating = m_player.PrRating(true, r, m_scout.m_shooting);
	m_player.SetAdjPrTgp(rating);
	s.Format("%d", rating);
	m_listCtrlShot.SetItemText(0,5,s);

	

	r = m_player.GetPrOrb();
    rating = m_player.PrRating(false, r, m_scout.m_rebounding);
	m_player.SetAdjPrOrb(rating);
	s.Format("%d", rating);
	m_listctrlskill.InsertItem(0,s);


	r = m_player.GetPrDrb();
    rating = m_player.PrRating(false, r, m_scout.m_rebounding);
	m_player.SetAdjPrDrb(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0,1,s);


	r = m_player.GetPrAst();
    rating = m_player.PrRating(false, r, m_scout.m_passing);
	m_player.SetAdjPrAst(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0,2,s);


	r = m_player.GetPrStl();
    rating = m_player.PrRating(false, r, m_scout.m_defense);
	m_player.SetAdjPrStl(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0,3,s);

	r = m_player.GetPrTo();

    rating = m_player.PrRating(false, r, m_scout.m_passing);
	m_player.SetAdjPrTo(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0,4,s);


	r = m_player.GetPrBlk();
    rating = m_player.PrRating(false, r, m_scout.m_defense);
	m_player.SetAdjPrBlk(rating);
	s.Format("%d", rating);
	m_listctrlskill.SetItemText(0,5,s);
	CString display[6] = {"", "Very Low", "Poor", "Average", "Good", "Excellent"};
    rating = m_player.PrRating(false, m_player.GetPot1()+200, m_scout.m_pot1);
	m_listFuture.InsertItem(0,display[rating]);
    rating = m_player.PrRating(false, m_player.GetPot2()+200, m_scout.m_pot2);
	m_listFuture.SetItemText(0,1,display[rating]);
    rating = m_player.PrRating(false, m_player.GetEffort()+200, m_scout.m_effort);
	m_listFuture.SetItemText(0,2,display[rating]);




	CString m_lines[33];
	m_player.CreateReport(m_lines,  avg.r_ast, avg.r_fta, avg.r_tga, avg.m_avg_tgp, avg.r_orb, avg.r_drb, avg.r_stl, avg.r_to, avg.r_blk,
		avg.r_fga, avg.m_avg_fgp, avg.m_avg_fga, avg.m_avg_ftp, avg.m_avg_trade_tru);

	m_list_report.ResetContent();
	if(m_lines[32] != "") m_list_report.AddString(m_lines[32]);
	for(int i=0; i<=31; i++)
	{
		if(m_lines[i] != "") m_list_report.AddString(m_lines[i]);
	}





	UpdateData(FALSE);

}







void CRookieCardDlg::OnButtonScout() 
{
	// TODO: Add your control notification handler code here
	CScoutProfileDlg* scout = new CScoutProfileDlg;
	scout->m_scout = m_scout;

	scout->m_type = 1;
	if(m_title == "Coach")
	{
		scout->m_type = 2;
	}

	scout->DoModal();
	delete scout;	
}


























void CRookieCardDlg::OnButtonOk() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnOK();
	
}

HBRUSH CRookieCardDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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


void CRookieCardDlg::OnLbnSelchangeListReport2()
{
	// TODO: Add your control notification handler code here
}
