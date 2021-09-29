// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "MyComboBox.h"
//#include "constants.h"
//#include "resource.h"

#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
	m_active = TRUE;
	m_edityearspro = 0;
	m_edityearsteam = 0;
	m_edityear1 = 0;
	m_edityear2 = 0;
	m_edityear3 = 0;
	m_edityear4 = 0;
	m_edityear5 = 0;
	m_edityear6 = 0;
	m_editcoach = 0;
	m_editloyalty = 0;
	m_editpt = 0;
	m_editsecurity = 0;
	m_edittradition = 0;
	m_editwinning = 0;



	m_edit_3ga = 0;
	m_edit_tgp = 0;
	m_edit_ast = 0;
	m_edit_blk = 0;
	m_edit_drb = 0;
	m_edit_fta = 0;
	m_edit_ftp = 0;
	m_edit_name = _T("");
	m_edit_orb = 0;
	m_edit_fga = 0;
	m_edit_fgp = 0;
	m_edit_stl = 0;
	m_edit_to = 0;
	m_edit_min = 1;
	m_edit_g = 0;
	m_edit_age = 0;
	m_edit_ht = 78;
	m_edit_wt = 200;
	m_edit_age = 0;
	m_edit_clutch = 0;
	m_edit_consistency = 0;
	m_edit_f = 0;
	m_edit_fd = 0;
	m_edit_i = 0;
	m_edit_id = 0;
	m_edit_o = 0;
	m_edit_od = 0;
	m_edit_p = 0;
	m_edit_pd = 0;
	m_edit_pot1 = 0;
	m_edit_pot2 = 0;
	m_edit_effort = 0;
	m_edit_athlete = 0;
	m_edit_1 = 1;
	m_edit_2 = 0;
	m_edit_3 = 0;
	m_edit_4 = 0;
	m_edit_5 = 0;
	m_edit_6 = 0;
	m_edit_7 = 0;
	m_edit_8 = 0;
	m_edit_9 = 0;
	m_edit_10 = 0;
	m_edit_11 = 0;
	m_edit_12 = 0;
	m_edit_13 = 0;
	m_edit_14 = 0;
	//}}AFX_DATA_INIT

	m_id_count = 0;
	m_teamindex = 0;
	m_posindex = 1;
	m_rookie_edit = false;
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)

	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);



	DDX_Control(pDX, IDC_LIST_AVG, m_listAvg);
	DDX_Control(pDX, IDC_COMBO_POS, m_combo_pos);
	DDX_Control(pDX, IDC_COMBO_COMP, m_combo_comp);
	DDX_Control(pDX, IDC_COMBO_TEAM, m_combo_team);
	DDX_Control(pDX, IDC_COMBOTEAMS, m_comboteams);
	DDX_Control(pDX, IDC_COMBOPOS, m_combopos);
	DDX_Control(pDX, IDC_COMBO_DURABLE, m_combo_durability);
	DDX_Control(pDX, IDC_COMBO_CURRENT_CONTRACT_YEAR, m_combo_current_contract_year);
	DDX_Text(pDX, IDC_EDIT_YRS_PRO, m_edityearspro);
	DDV_MinMaxInt(pDX, m_edityearspro, 0, 25);

	DDX_Text(pDX, IDC_EDIT_YRS_TEAM, m_edityearsteam);
	DDV_MinMaxInt(pDX, m_edityearsteam, 0, 25);


	DDX_Text(pDX, IDC_EDIT_YEAR_1, m_edityear1);
	DDV_MinMaxInt(pDX, m_edityear1, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_YEAR_2, m_edityear2);
	DDV_MinMaxInt(pDX, m_edityear2, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_YEAR_3, m_edityear3);
	DDV_MinMaxInt(pDX, m_edityear3, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_YEAR_4, m_edityear4);
	DDV_MinMaxInt(pDX, m_edityear4, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_YEAR_5, m_edityear5);
	DDV_MinMaxInt(pDX, m_edityear5, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_YEAR_6, m_edityear6);
	DDV_MinMaxInt(pDX, m_edityear6, 0, 3000);

	DDX_Text(pDX, IDC_EDIT_COACH, m_editcoach);
	DDV_MinMaxInt(pDX, m_editcoach, 1, 5);

	DDX_Text(pDX, IDC_EDIT_LOYALTY, m_editloyalty);
	DDV_MinMaxInt(pDX, m_editloyalty, 1, 5);

	DDX_Text(pDX, IDC_EDIT_PT, m_editpt);
	DDV_MinMaxInt(pDX, m_editpt, 1, 5);

	DDX_Text(pDX, IDC_EDIT_SECURITY, m_editsecurity);
	DDV_MinMaxInt(pDX, m_editsecurity, 1, 5);

	DDX_Text(pDX, IDC_EDIT_TRADITION, m_edittradition);
	DDV_MinMaxInt(pDX, m_editsecurity, 1, 5);

	DDX_Text(pDX, IDC_EDIT_WINNING, m_editwinning);
	DDV_MinMaxInt(pDX, m_editsecurity, 1, 5);




	DDX_Text(pDX, IDC_EDIT_3PT_SCORING, m_edit_3ga);
	DDV_MinMaxInt(pDX, m_edit_3ga, 0, 100);
	DDX_Text(pDX, IDC_EDIT_3PT_SHOOTING, m_edit_tgp);
	DDV_MinMaxInt(pDX, m_edit_tgp, 0, 100);
	DDX_Text(pDX, IDC_EDIT_AST, m_edit_ast);
	DDV_MinMaxInt(pDX, m_edit_ast, 0, 100);
	DDX_Text(pDX, IDC_EDIT_BLK, m_edit_blk);
	DDV_MinMaxInt(pDX, m_edit_blk, 0, 100);
	DDX_Text(pDX, IDC_EDIT_DRB, m_edit_drb);
	DDV_MinMaxInt(pDX, m_edit_drb, 0, 100);
	DDX_Text(pDX, IDC_EDIT_FT_SCORING, m_edit_fta);
	DDV_MinMaxInt(pDX, m_edit_fta, 0, 100);
	DDX_Text(pDX, IDC_EDIT_FT_SHOOTING, m_edit_ftp);
	DDV_MinMaxInt(pDX, m_edit_ftp, 0, 100);
	DDX_Text(pDX, IDC_EDIT_NAME, m_edit_name);
	DDV_MaxChars(pDX, m_edit_name, 32);
	DDX_Text(pDX, IDC_EDIT_ORB, m_edit_orb);
	DDV_MinMaxInt(pDX, m_edit_orb, 0, 100);
	DDX_Text(pDX, IDC_EDIT_SCORING, m_edit_fga);
	DDV_MinMaxInt(pDX, m_edit_fga, 0, 100);
	DDX_Text(pDX, IDC_EDIT_SHOOTING, m_edit_fgp);
	DDV_MinMaxInt(pDX, m_edit_fgp, 0, 100);
	DDX_Text(pDX, IDC_EDIT_STL, m_edit_stl);
	DDV_MinMaxInt(pDX, m_edit_stl, 0, 100);
	DDX_Text(pDX, IDC_EDIT_TO, m_edit_to);
	DDV_MinMaxInt(pDX, m_edit_to, 0, 100);
	DDX_Text(pDX, IDC_EDIT_MIN, m_edit_min);
	DDV_MinMaxInt(pDX, m_edit_min, 1, 48);
	DDX_Text(pDX, IDC_EDIT_G, m_edit_g);
	DDV_MinMaxInt(pDX, m_edit_g, 0, 99);
	DDX_Text(pDX, IDC_EDIT_AGE, m_edit_age);
	DDV_MinMaxInt(pDX, m_edit_age, 1, 99);
	DDX_Text(pDX, IDC_EDIT_HT, m_edit_ht);
	DDV_MinMaxInt(pDX, m_edit_ht, 0, 91);
	DDX_Text(pDX, IDC_EDIT_WT, m_edit_wt);
	DDV_MinMaxInt(pDX, m_edit_wt, 0, 395);
	DDX_Text(pDX, IDC_EDIT_CLUTCH, m_edit_clutch);
	DDV_MinMaxInt(pDX, m_edit_clutch, 1, 3);
	DDX_Text(pDX, IDC_EDIT_CONSISTENCY, m_edit_consistency);
	DDV_MinMaxInt(pDX, m_edit_consistency, 1, 3);
	DDX_Text(pDX, IDC_EDIT_F, m_edit_f);
	DDV_MinMaxInt(pDX, m_edit_f, 1, 9);
	DDX_Text(pDX, IDC_EDIT_FD, m_edit_fd);
	DDV_MinMaxInt(pDX, m_edit_fd, 1, 9);
	DDX_Text(pDX, IDC_EDIT_I, m_edit_i);
	DDV_MinMaxInt(pDX, m_edit_i, 1, 9);
	DDX_Text(pDX, IDC_EDIT_ID, m_edit_id);
	DDV_MinMaxInt(pDX, m_edit_id, 1, 9);
	DDX_Text(pDX, IDC_EDIT_O, m_edit_o);
	DDV_MinMaxInt(pDX, m_edit_o, 1, 9);
	DDX_Text(pDX, IDC_EDIT_OD, m_edit_od);
	DDV_MinMaxInt(pDX, m_edit_od, 1, 9);
	DDX_Text(pDX, IDC_EDIT_P, m_edit_p);
	DDV_MinMaxInt(pDX, m_edit_p, 1, 9);
	DDX_Text(pDX, IDC_EDIT_PD, m_edit_pd);
	DDV_MinMaxInt(pDX, m_edit_pd, 1, 9);
	DDX_Text(pDX, IDC_EDIT_POT1, m_edit_pot1);
	DDV_MinMaxInt(pDX, m_edit_pot1, 1, 5);
	DDX_Text(pDX, IDC_EDIT_POT2, m_edit_pot2);
	DDV_MinMaxInt(pDX, m_edit_pot2, 1, 5);
	DDX_Text(pDX, IDC_EDIT_EFFORT, m_edit_effort);
	DDV_MinMaxInt(pDX, m_edit_effort, 1, 5);
	DDX_Text(pDX, IDC_EDIT_ATHLETE, m_edit_athlete);
	DDV_MinMaxInt(pDX, m_edit_athlete, 50, 150);
	DDX_Text(pDX, IDC_EDIT1, m_edit_1);
	DDV_MinMaxInt(pDX, m_edit_1, 1, 9999);
	DDX_Text(pDX, IDC_EDIT2, m_edit_2);
	DDV_MinMaxInt(pDX, m_edit_2, 0, 9999);
	DDX_Text(pDX, IDC_EDIT3, m_edit_3);
	DDV_MinMaxInt(pDX, m_edit_3, 0, 9999);
	DDX_Text(pDX, IDC_EDIT4, m_edit_4);
	DDV_MinMaxInt(pDX, m_edit_4, 0, 9999);
	DDX_Text(pDX, IDC_EDIT5, m_edit_5);
	DDV_MinMaxInt(pDX, m_edit_5, 0, 9999);
	DDX_Text(pDX, IDC_EDIT6, m_edit_6);
	DDV_MinMaxInt(pDX, m_edit_6, 0, 9999);
	DDX_Text(pDX, IDC_EDIT7, m_edit_7);
	DDV_MinMaxInt(pDX, m_edit_7, 0, 9999);
	DDX_Text(pDX, IDC_EDIT8, m_edit_8);
	DDV_MinMaxInt(pDX, m_edit_8, 0, 9999);
	DDX_Text(pDX, IDC_EDIT9, m_edit_9);
	DDV_MinMaxInt(pDX, m_edit_9, 0, 9999);
	DDX_Text(pDX, IDC_EDIT10, m_edit_10);
	DDV_MinMaxInt(pDX, m_edit_10, 0, 9999);
	DDX_Text(pDX, IDC_EDIT11, m_edit_11);
	DDV_MinMaxInt(pDX, m_edit_11, 0, 999);
	DDX_Text(pDX, IDC_EDIT12, m_edit_12);
	DDV_MinMaxInt(pDX, m_edit_12, 0, 9999);
	DDX_Text(pDX, IDC_EDIT13, m_edit_13);
	DDV_MinMaxInt(pDX, m_edit_13, 0, 9999);
	DDX_Text(pDX, IDC_EDIT14, m_edit_14);
	DDV_MinMaxInt(pDX, m_edit_14, 0, 9999);
	DDX_Check(pDX, IDC_CHECK_ACTIVE, m_active);
	DDX_Control(pDX, IDC_LIST_SG, m_sgrot);
	DDX_Control(pDX, IDC_LIST_SF, m_sfrot);
	DDX_Control(pDX, IDC_LIST_PG, m_pgrot);
	DDX_Control(pDX, IDC_LIST_PF, m_pfrot);
	DDX_Control(pDX, IDC_LIST_C, m_crot);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_WM_CTLCOLOR()
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_AVG, OnButtonAvg)
	ON_CBN_SELCHANGE(IDC_COMBO_POS, OnSelchangeComboPos)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, OnButtonCalculate)
	ON_EN_CHANGE(IDC_EDIT_SCORING, OnChangeEditScoring)
	ON_EN_KILLFOCUS(IDC_EDIT_SCORING, OnKillfocusEditScoring)
	ON_EN_KILLFOCUS(IDC_EDIT_3PT_SCORING, OnKillfocusEdit3ptScoring)
	ON_EN_KILLFOCUS(IDC_EDIT_3PT_SHOOTING, OnKillfocusEdit3ptShooting)
	ON_EN_KILLFOCUS(IDC_EDIT_AGE, OnKillfocusEditAge)
	ON_EN_KILLFOCUS(IDC_EDIT_HT, OnKillfocusEditHt)
	ON_EN_KILLFOCUS(IDC_EDIT_WT, OnKillfocusEditWt)
	ON_EN_KILLFOCUS(IDC_EDIT_AST, OnKillfocusEditAst)
	ON_EN_KILLFOCUS(IDC_EDIT_BLK, OnKillfocusEditBlk)
	ON_EN_KILLFOCUS(IDC_EDIT_CLUTCH, OnKillfocusEditClutch)
	ON_EN_KILLFOCUS(IDC_EDIT_CONSISTENCY, OnKillfocusEditConsistency)
	ON_EN_KILLFOCUS(IDC_EDIT_DRB, OnKillfocusEditDrb)
	ON_EN_KILLFOCUS(IDC_EDIT_EFFORT, OnKillfocusEditEffort)
	ON_EN_KILLFOCUS(IDC_EDIT_F, OnKillfocusEditF)
	ON_EN_KILLFOCUS(IDC_EDIT_FD, OnKillfocusEditFd)
	ON_EN_KILLFOCUS(IDC_EDIT_FT_SCORING, OnKillfocusEditFtScoring)
	ON_EN_KILLFOCUS(IDC_EDIT_FT_SHOOTING, OnKillfocusEditFtShooting)
	ON_EN_KILLFOCUS(IDC_EDIT_G, OnKillfocusEditG)
	ON_EN_KILLFOCUS(IDC_EDIT_I, OnKillfocusEditI)
	ON_EN_KILLFOCUS(IDC_EDIT_ID, OnKillfocusEditId)
	ON_EN_KILLFOCUS(IDC_EDIT_MIN, OnKillfocusEditMin)
	ON_EN_KILLFOCUS(IDC_EDIT_NAME, OnKillfocusEditName)
	ON_EN_KILLFOCUS(IDC_EDIT_O, OnKillfocusEditO)
	ON_EN_KILLFOCUS(IDC_EDIT_OD, OnKillfocusEditOd)
	ON_EN_KILLFOCUS(IDC_EDIT_ORB, OnKillfocusEditOrb)
	ON_EN_KILLFOCUS(IDC_EDIT_P, OnKillfocusEditP)
	ON_EN_KILLFOCUS(IDC_EDIT_PD, OnKillfocusEditPd)
	ON_EN_KILLFOCUS(IDC_EDIT_POT1, OnKillfocusEditPot1)
	ON_EN_KILLFOCUS(IDC_EDIT_POT2, OnKillfocusEditPot2)
	ON_EN_KILLFOCUS(IDC_EDIT_SHOOTING, OnKillfocusEditShooting)
	ON_EN_KILLFOCUS(IDC_EDIT_STL, OnKillfocusEditStl)
	ON_EN_KILLFOCUS(IDC_EDIT_TO, OnKillfocusEditTo)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT10, OnKillfocusEdit10)
	ON_EN_KILLFOCUS(IDC_EDIT11, OnKillfocusEdit11)
	ON_EN_KILLFOCUS(IDC_EDIT12, OnKillfocusEdit12)
	ON_EN_KILLFOCUS(IDC_EDIT13, OnKillfocusEdit13)
	ON_EN_KILLFOCUS(IDC_EDIT14, OnKillfocusEdit14)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEdit4)
	ON_EN_KILLFOCUS(IDC_EDIT5, OnKillfocusEdit5)
	ON_EN_KILLFOCUS(IDC_EDIT6, OnKillfocusEdit6)
	ON_EN_KILLFOCUS(IDC_EDIT7, OnKillfocusEdit7)
	ON_EN_KILLFOCUS(IDC_EDIT8, OnKillfocusEdit8)
	ON_EN_KILLFOCUS(IDC_EDIT9, OnKillfocusEdit9)
	ON_BN_CLICKED(IDC_BUTTON_ADJUST, OnButtonAdjust)
	ON_CBN_SELCHANGE(IDC_COMBOTEAMS, OnSelchangeComboteams)
	ON_CBN_SELCHANGE(IDC_COMBOPOS, OnSelchangeCombopos)
	ON_BN_CLICKED(IDC_CHECK_ACTIVE, OnCheckActive)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE_RATINGS, OnButtonCalculateRatings)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE_STATS, OnButtonCalculateStats)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers

HBRUSH CEditDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CEditDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	return TRUE;		
//	return CDialog::OnHelpInfo(pHelpInfo);

//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsplayeredit.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);

}

void CEditDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	return TRUE;		
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolsplayeredit.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

BOOL CEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here


	
myBrush.CreateSolidBrush(DLGCOLOR); 
myBrush2.CreateSolidBrush(LISTBOXCOLOR); 

	InitCtrl();
	Initialize();
//	OnButtonAvg();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditDlg::OnOK() 
{
	// TODO: Add extra validation here
	SetStats();	
	SavePlayer();
	//m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	SavePlayer();

		int	result = AfxMessageBox("Are you sure you want to save the changes?", MB_YESNO);		
		if(result == IDYES)
		{
			WriteID();
			CDialog::OnOK();
		}


//	CDialog::OnOK();
}

void CEditDlg::DisplayRatings()
{
	m_combo_pos.SetCurSel(m_po-1);
	m_edit_name = m_actual.GetName();
	int g = m_actual.GetGames();
	int min = m_actual.GetMin();
	if(g != 0 && min != 0)
	{
		m_edit_min = m_actual.GetMin()/g;
		m_edit_g = g;
	}
	else
	{
		m_edit_min = 24;
		m_edit_g = 72;
	}
	SetEditVariables();
}



	

void CEditDlg::SetAverages()
{
//	for(int i=0; i<=580; i++)
//	{
//	
//		avg.m_actual[i] = m_player[i];
//	}
	
	avg.SetHighs(false);
}

void CEditDlg::SetPlayerRatings()
{
	for(int i=0; i<=1440; i++)
	{
		avg.m_actual[i].SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
	}

	
	
	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);

	orig_g = m_actual.GetGames();
	

	orig_fga = m_actual.GetPrFga();
	orig_fgp = m_actual.GetPrFgp();

	orig_fta = m_actual.GetPrFta();
	orig_ftp = m_actual.GetPrFtp();

	orig_tga = m_actual.GetPrTga();
	orig_tgp = m_actual.GetPrTgp();

	orig_orb = m_actual.GetPrOrb();
	orig_drb = m_actual.GetPrDrb();

	orig_ast = m_actual.GetPrAst();
	orig_stl = m_actual.GetPrStl();
	orig_to  = m_actual.GetPrTo(); 
	orig_blk = m_actual.GetPrBlk();



}

void CEditDlg::InitVariables()
{
	orig_g = 0;
	orig_min = 0;

	orig_fga = 0;
	orig_fgp = 0;

	orig_fta = 0;
	orig_ftp = 0;

	orig_tga = 0;
	orig_tgp = 0;

	orig_orb = 0;
	orig_drb = 0;

	orig_ast = 0;
	orig_stl = 0;
	orig_to = 0; 
	orig_blk = 0;


	if(m_actual.GetPos() == "PG") m_po = 1;
	else if(m_actual.GetPos() == "SG") m_po = 2;
	else if(m_actual.GetPos() == "SF") m_po = 3;
	else if(m_actual.GetPos() == "PF") m_po = 4;
	else if(m_actual.GetPos() == " C") m_po = 5;


}

void CEditDlg::SetEditedRatings()
{
	UpdateData(TRUE);
	GetPlayerPosition();
	SetRatings();

}

void CEditDlg::InitCtrl()
{

	char s[129];
	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".car";
	CFile file(	pFileName, CFile::modeReadWrite);	
 	int bytes = file.Read(s, 5);
  	s[bytes] = 0;
	m_id_count = atoi(s) + 1;
	file.Close();


	if(m_rookie_edit == true)
	{
		m_comboteams.ShowWindow(FALSE);
		m_combopos.ShowWindow(FALSE);
		m_static1.ShowWindow(FALSE);
		m_static2.ShowWindow(FALSE);
	}

	m_listAvg.SetBkColor(BK_COLOR);
	m_listAvg.SetTextBkColor(TEXT_BK_COLOR);
    m_listAvg.SetTextColor(RGB(0,0,0));

    m_listAvg.InsertColumn(0,"rating");    
    m_listAvg.InsertColumn(1, "all");    
    m_listAvg.InsertColumn(2,"pg");    
    m_listAvg.InsertColumn(3,"sg");    
    m_listAvg.InsertColumn(4,"sf");    
    m_listAvg.InsertColumn(5,"pf");    
    m_listAvg.InsertColumn(6," c");    

    m_listAvg.SetColumnWidth( 0, 48);
    m_listAvg.SetColumnWidth( 1, 26);
    m_listAvg.SetColumnWidth( 2, 24);
    m_listAvg.SetColumnWidth( 3, 24);
    m_listAvg.SetColumnWidth( 4, 24);
    m_listAvg.SetColumnWidth( 5, 24);
    m_listAvg.SetColumnWidth( 6, 24);

	CString string;
	CString label[99];
	label[0] = "g";
	label[1] = "min";
	label[2] = "2ga";
	label[3] = "2g%";
	label[4] = "fta";
	label[5] = "ft%";
	label[6] = "3ga";
	label[7] = "3g%";
	label[8] = "orb";
	label[9] = "drb";
	label[10] = "ast";
	label[11] = "stl";
	label[12] = "to ";
	label[13] = "blk";



	for(int i=0; i<=13; i++)
	{
	    m_listAvg.InsertItem(i, label[i]);

	for(int po=0; po<=5; po++)
	{

	if(i == 0) string.Format("%d", int(avg.m_avg_g[po]));
	else if(i == 1) 
	string.Format("%d", int(avg.m_avg_min[po]));
	else if(i == 2) 
	string.Format("%d", avg.r_fga[po]);
	else if(i == 3) 
	string.Format("%d", int(avg.m_avg_fgp[po]));
	else if(i == 4) 
	string.Format("%d", avg.r_fta[po]);
	else if(i == 5) 
	string.Format("%d", int(avg.m_avg_ftp[po]));
	else if(i == 6) 
	string.Format("%d", avg.r_tga[po]);
	else if(i == 7) 
	string.Format("%d", int(avg.m_avg_tgp[po]));
	else if(i == 8) 
	string.Format("%d", avg.r_orb[po]);
	else if(i == 9) 
	string.Format("%d", avg.r_drb[po]);
	else if(i == 10) 
	string.Format("%d", avg.r_ast[po]);
	else if(i == 11) 
	string.Format("%d", avg.r_stl[po]);
	else if(i == 12) 
	string.Format("%d", avg.r_to[po]);
	else if(i == 13) 
	string.Format("%d", avg.r_blk[po]);

	m_listAvg.SetItemText(i, po + 1, string);

	}

    }

	m_combo_comp.SetCurSel(3);
	m_combo_team.SetCurSel(3);
	m_combo_durability.SetCurSel(2);
	m_edit_athlete = 80;
	m_teamindex = m_default_team;

	for(int i=0; i<=32; i++)
	{
		if(avg.m_settings.m_leagueTeamNames[i] != "")
			m_comboteams.AddString(avg.m_settings.m_leagueTeamNames[i]);
	}
	m_comboteams.AddString("Free Agents");




	for(int i=0; i<=5; i++)
	{
		CString str;
		str.Format("%d", i+1);
		m_combo_current_contract_year.AddString(str);
	}

	CString Names[6] = {"-----","1st","2nd","3rd","4th","ok"};
	for(int i=0; i<=5; i++) 
	{
		m_pgrot.AddString(Names[i]);
		m_sgrot.AddString(Names[i]);
		m_sfrot.AddString(Names[i]);
		m_pfrot.AddString(Names[i]);
		m_crot.AddString(Names[i]);
	}

	m_combopos.SetCurSel(0);
	m_comboteams.SetCurSel(m_default_team);
	m_combo_current_contract_year.SetCurSel(0);

	m_pgrot.SetCurSel(0);
	m_sgrot.SetCurSel(0);
	m_sfrot.SetCurSel(0);
	m_pfrot.SetCurSel(0);
	m_crot.SetCurSel(0);

	FillSlotsWithPlayerNames();


	UpdateData(FALSE);

}

void CEditDlg::OnButtonAvg() 
{
	// TODO: Add your control notification handler code here

//	set new stats
	SetPlayerToAverage();
	SetRatings();
	
	m_actual.ConvertRatingsToStats(
					m_edit_g, m_edit_min, 
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);


	m_actual.m_pf = int(avg.m_avg_pf[m_po] * m_actual.m_min / 48) + 1;
	SetEditVariables();
}

void CEditDlg::SetPlayerToAverage()
{
	m_edit_g = int(avg.m_avg_g[m_po]);
	m_edit_min = int(avg.m_avg_min[m_po]);
	m_edit_fga = avg.r_fga[m_po];
	m_edit_fgp = int(avg.m_avg_fgp[m_po]);
	m_edit_fta = avg.r_fta[m_po];
	m_edit_ftp = int(avg.m_avg_ftp[m_po]);
	m_edit_3ga = avg.r_tga[m_po];
	m_edit_tgp = int(avg.m_avg_tgp[m_po]);
	m_edit_orb = avg.r_orb[m_po];
	m_edit_drb = avg.r_drb[m_po];
	m_edit_ast = avg.r_ast[m_po];
	m_edit_stl = avg.r_stl[m_po];
	m_edit_to = avg.r_to[m_po];
	m_edit_blk = avg.r_blk[m_po];


	m_edit_clutch = 2;
	m_edit_consistency = 2;

	m_edit_pot1 = 3;
	m_edit_pot2 = 3;
	m_edit_effort = 3;

	m_edit_1 = 1;
	m_edit_2 = 0;
	m_edit_3 = 0;
	m_edit_4 = 0;
	m_edit_5 = 0;
	m_edit_6 = 0;
	m_edit_7 = 0;
	m_edit_8 = 0;
	m_edit_9 = 0;
	m_edit_10 = 0;
	m_edit_11 = 0;
	m_edit_12 = 0;
	m_edit_13 = 0;
	m_edit_14 = 0;

	m_edit_o = 5;
	m_edit_p = 5;
	m_edit_i = 5;
	m_edit_f = 5;

	m_edit_od = 5;
	m_edit_pd = 5;
	m_edit_id = 5;
	m_edit_fd = 5;

	m_editcoach	= 3;
	m_editloyalty = 3;
	m_editpt = 3;
	m_editsecurity = 3;
	m_edittradition = 3;
	m_editwinning = 3;

	


	//OnButtonCalculate();
	
}

void CEditDlg::SetRatings()
{
	orig_min = m_edit_min;


	m_actual.SetGames(m_edit_g);
	m_actual.SetName(m_edit_name);
	m_actual.SetAge(m_edit_age);
	//if(m_edit_ht == 0) m_edit_ht = 78;
	//if(m_edit_wt == 0) m_edit_wt = 200;
	m_actual.m_height = m_edit_ht;
	m_actual.m_weight = m_edit_wt;
	m_actual.SetAge(m_edit_age);
	if(m_actual.GetBetter() == 0) m_actual.SetBetter(50);
    
	m_actual.SetPrTga(m_edit_3ga);
	m_actual.SetPrTgp(m_edit_tgp);
	m_actual.SetPrFga(m_edit_fga);
	m_actual.SetPrFgp(m_edit_fgp);
	m_actual.SetPrFta(m_edit_fta);
	m_actual.SetPrFtp(m_edit_ftp);

	m_actual.SetPrOrb(m_edit_orb);
	m_actual.SetPrDrb(m_edit_drb);
	m_actual.SetPrAst(m_edit_ast);
	m_actual.SetPrStl(m_edit_stl);
	m_actual.SetPrTo(m_edit_to);
	m_actual.SetPrBlk(m_edit_blk);

	m_actual.SetClutch(m_edit_clutch);
	m_actual.SetConsistency(m_edit_consistency);
	m_actual.SetMovOff(m_edit_o);
	m_actual.SetMovDef(m_edit_od);
	m_actual.SetPenOff(m_edit_p);
	m_actual.SetPenDef(m_edit_pd);
	m_actual.SetPostOff(m_edit_i);
	m_actual.SetPostDef(m_edit_id);
	m_actual.SetTransOff(m_edit_f);
	m_actual.SetTransDef(m_edit_fd);

	m_actual.SetPot1(m_edit_pot1);
	m_actual.SetPot2(m_edit_pot2);
	m_actual.SetEffort(m_edit_effort);

	m_actual.m_coach_factor = m_editcoach;
	m_actual.m_loyalty_factor = m_editloyalty;
	m_actual.m_playing_time_factor = m_editpt;
	m_actual.m_security_factor = m_editsecurity;
	m_actual.m_tradition_factor = m_edittradition;
	m_actual.m_winning_factor = m_editwinning;


	m_actual.m_yrs_of_service = m_edityearspro;
	m_actual.m_contract_salaries[0] = 0;
	m_actual.m_contract_salaries[1] = m_edityear1;
	m_actual.m_contract_salaries[2] = m_edityear2;
	m_actual.m_contract_salaries[3] = m_edityear3;
	m_actual.m_contract_salaries[4] = m_edityear4;
	m_actual.m_contract_salaries[5] = m_edityear5;
	m_actual.m_contract_salaries[6] = m_edityear6;
	
	
	
	m_actual.m_yrs_on_team = m_edityearsteam;



	m_actual.m_current_contract_yr = m_combo_current_contract_year.GetCurSel() + 1;
	m_actual.m_contract_yrs = 0;

	int salary = 0;
	int remaining_salary = 0;
	for(int y=1; y<=6; y++)
	{
		int i = m_actual.m_contract_salaries[y];			
		if(i > 0) m_actual.m_contract_yrs = y;
		salary = salary + i;
		if(y >= m_actual.m_current_contract_yr) remaining_salary = remaining_salary + i;		
	}

	m_actual.m_total_salary = salary;
	m_actual.m_remaining_salary = remaining_salary;	
	if(m_actual.m_contract_yrs == m_actual.m_current_contract_yr) m_actual.m_is_free_agent = true;
	m_actual.m_current_yr_salary = m_actual.m_contract_salaries[m_actual.m_current_contract_yr]; 


	int pg = m_pgrot.GetCurSel();
	int sg = m_sgrot.GetCurSel();
	int sf = m_sfrot.GetCurSel();
	int pf = m_pfrot.GetCurSel();
	int c = m_crot.GetCurSel();
	m_actual.SetPgRot(pg);
	m_actual.SetSgRot(sg);
	m_actual.SetSfRot(sf);
	m_actual.SetPfRot(pf);
	m_actual.SetCRot(c);
	m_actual.SetActive(m_active);

	
}

void CEditDlg::SetEditVariables()
{
	m_edit_3ga = m_actual.GetPrTga();
	m_edit_tgp = m_actual.GetPrTgp();
	m_edit_fga = m_actual.GetPrFga();
	m_edit_fgp = m_actual.GetPrFgp();
	m_edit_fta = m_actual.GetPrFta();
	m_edit_ftp = m_actual.GetPrFtp();

	m_edit_orb = m_actual.GetPrOrb();
	m_edit_drb = m_actual.GetPrDrb();
	m_edit_ast = m_actual.GetPrAst();
	m_edit_stl = m_actual.GetPrStl();
	m_edit_to = m_actual.GetPrTo();
	m_edit_blk = m_actual.GetPrBlk();
	
	m_edit_o = m_actual.GetMovOff();
	m_edit_p = m_actual.GetPenOff();
	m_edit_i = m_actual.GetPostOff();
	m_edit_f = m_actual.GetTransOff();

	m_edit_od = m_actual.GetMovDef();
	m_edit_pd = m_actual.GetPenDef();
	m_edit_id = m_actual.GetPostDef();
	m_edit_fd = m_actual.GetTransDef();

	m_edit_clutch = m_actual.GetClutch();
	m_edit_consistency = m_actual.GetConsistency();
	m_edit_age = m_actual.GetAge();
	m_edit_ht = m_actual.m_height;
	m_edit_wt = m_actual.m_weight;

	m_edit_pot1 = m_actual.GetPot1();
	m_edit_pot2 = m_actual.GetPot2();
	m_edit_effort = m_actual.GetEffort();

	m_edit_1 = m_actual.GetMin();
	m_edit_2 = m_actual.GetFgm();
	m_edit_3 = m_actual.GetFga();
	m_edit_4 = m_actual.GetFtm();
	m_edit_5 = m_actual.GetFta();
	m_edit_6 = m_actual.GetTfgm();
	m_edit_7 = m_actual.GetTfga();
	m_edit_8 = m_actual.GetOreb();
	m_edit_9 = m_actual.GetReb();
	m_edit_10= m_actual.GetAst();
	m_edit_11= m_actual.GetStl();
	m_edit_12= m_actual.GetTo();
	m_edit_13= m_actual.GetBlk();
	m_edit_14= m_actual.GetPf();


	m_editcoach = m_actual.m_coach_factor; 
	m_editloyalty = m_actual.m_loyalty_factor; 
	m_editpt = m_actual.m_playing_time_factor; 
	m_editsecurity = m_actual.m_security_factor; 
	m_edittradition = m_actual.m_tradition_factor; 
	m_editwinning = m_actual.m_winning_factor;

	m_edityearspro = m_actual.m_yrs_of_service;
	m_edityearsteam = m_actual.m_yrs_on_team;
	m_edityear1 = m_actual.m_contract_salaries[1]; 
	m_edityear2 = m_actual.m_contract_salaries[2]; 
	m_edityear3 = m_actual.m_contract_salaries[3]; 
	m_edityear4 = m_actual.m_contract_salaries[4]; 
	m_edityear5 = m_actual.m_contract_salaries[5]; 
	m_edityear6 = m_actual.m_contract_salaries[6]; 


	m_combo_current_contract_year.SetCurSel(m_actual.m_current_contract_yr-1);


	m_pgrot.SetCurSel(m_actual.GetPgRot());
	m_sgrot.SetCurSel(m_actual.GetSgRot());
	m_sfrot.SetCurSel(m_actual.GetSfRot());
	m_pfrot.SetCurSel(m_actual.GetPfRot());
	m_crot.SetCurSel(m_actual.GetCRot());
	m_active = m_actual.GetActive();	


	UpdateData(FALSE);
}

void CEditDlg::OnSelchangeComboPos() 
{
	// TODO: Add your control notification handler code here
	GetPlayerPosition();
	
}

void CEditDlg::GetPlayerPosition()
{
	CString string;
	if(m_combo_pos.GetCurSel() < 1) m_combo_pos.SetCurSel(0);
	m_combo_pos.GetLBText(m_combo_pos.GetCurSel(), string);
	string.MakeUpper();
	m_actual.SetPos(string);
	if(m_actual.GetPos() == "PG") m_po = 1;
	else if(m_actual.GetPos() == "SG") m_po = 2;
	else if(m_actual.GetPos() == "SF") m_po = 3;
	else if(m_actual.GetPos() == "PF") m_po = 4;
	else if(m_actual.GetPos() == " C") m_po = 5;
}

void CEditDlg::OnButtonCalculate() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
//	SetRatings();

/*	m_actual.ConvertRatingsToStats(
					m_edit_g, m_edit_min, 
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);*/

/*	m_actual.ConvertRatings(
					orig_g, orig_min, 
					orig_fga, orig_fgp,
					orig_fta, orig_ftp,
					orig_tga, orig_tgp,
					orig_orb, orig_drb, orig_ast,
					orig_stl, orig_to,  orig_blk,
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);*/

	SetStats();	
//	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
//	Initialize();

		m_actual.SetOutside();
		m_actual.SetDriving();
		m_actual.SetPost();
		m_actual.SetTransition();
		m_actual.SetOutsideDefense();
		m_actual.SetDrivingDefense();
		m_actual.SetPostDefense();
		m_actual.SetTransitionDefense();

	int outside = Round(m_actual.GetOutside());
	int outsideDefense = Round(m_actual.GetOutsideDefense());
	int driving = Round(m_actual.GetDriving());
	int drivingDefense = Round(m_actual.GetDrivingDefense());
	int post = Round(m_actual.GetPost());
	int postDefense = Round(m_actual.GetPostDefense());
	int transition = Round(m_actual.GetTransition());
	int transitionDefense = Round(m_actual.GetTransitionDefense());

	if(outside > 9) outside = 9; else if(outside < 1) outside = 1;
	if(outsideDefense > 9) outsideDefense = 9; else if(outsideDefense < 1) outsideDefense = 1;
	if(driving > 9) driving = 9; else if(driving < 1) driving = 1;
	if(drivingDefense > 9) drivingDefense = 9; else if(drivingDefense < 1) drivingDefense = 1;
	if(post > 9) post = 9; else if(post < 1) post = 1;
	if(postDefense > 9) postDefense = 9; else if(postDefense < 1) postDefense = 1;
	if(transition > 9) transition = 9; else if(transition < 1) transition = 1;
	if(transitionDefense > 9) transitionDefense = 9; else if(transitionDefense < 1) transitionDefense = 1;

	m_actual.SetMovOff(outside);
	m_actual.SetMovDef(outsideDefense);
	m_actual.SetPenOff(driving);
	m_actual.SetPenDef(drivingDefense);
	m_actual.SetPostOff(post);
	m_actual.SetPostDef(postDefense);
	m_actual.SetTransOff(transition);
	m_actual.SetTransDef(transitionDefense);

	m_edit_o = outside;
	m_edit_p = driving;
	m_edit_i = post;
	m_edit_f = transition;

	m_edit_od = outsideDefense;
	m_edit_pd = drivingDefense;
	m_edit_id = postDefense;
	m_edit_fd = transitionDefense;

	if(m_actual.m_name == "")
	{
		m_actual.m_name = "Franciso Ramos";
		m_edit_name = "Franciso Ramos";
	}

	UpdateData(FALSE);

//	Initialize();
}








void CEditDlg::SetStats()
{
	UpdateData(TRUE);



	m_actual.SetGames(m_edit_g);
	m_actual.SetMin(m_edit_1);
	m_actual.SetFgm(m_edit_2);
	m_actual.SetFga(m_edit_3);
	m_actual.SetFtm(m_edit_4);
	m_actual.SetFta(m_edit_5);
	m_actual.SetTfgm(m_edit_6);
	m_actual.SetTfga(m_edit_7);
	m_actual.SetOreb(m_edit_8);
	m_actual.SetReb(m_edit_9);
	m_actual.SetAst(m_edit_10);
	m_actual.SetStl(m_edit_11);
	m_actual.SetTo(m_edit_12);
	m_actual.SetBlk(m_edit_13);
	m_actual.SetPf(m_edit_14);

}

void CEditDlg::Initialize()
{
	InitVariables();
	SetAverages();
	SetPlayerRatings();
	DisplayRatings();
}

void CEditDlg::OnChangeEditScoring() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEditScoring() 
{
	// TODO: Add your control notification handler code here
/*	SetEditedRatings();
//	set new stats
	
	m_actual.ConvertRatings(
					orig_g, orig_min, 
					orig_fga, orig_fgp,
					orig_fta, orig_ftp,
					orig_tga, orig_tgp,
					orig_orb, orig_drb, orig_ast,
					orig_stl, orig_to,  orig_blk,
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);
	//set newer ratings
	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);

	Initialize();
*/	
}

void CEditDlg::OnKillfocusEdit3ptScoring() 
{
	// TODO: Add your control notification handler code here
/*	SetEditedRatings();
//	set new stats
	
	m_actual.ConvertRatings(
					orig_g, orig_min, 
					orig_fga, orig_fgp,
					orig_fta, orig_ftp,
					orig_tga, orig_tgp,
					orig_orb, orig_drb, orig_ast,
					orig_stl, orig_to,  orig_blk,
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);
	//set newer ratings
	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);

	Initialize();
*/	
}

void CEditDlg::OnKillfocusEdit3ptShooting() 
{
	// TODO: Add your control notification handler code here


	
}

void CEditDlg::OnKillfocusEditAge() 
{
	// TODO: Add your control notification handler code here
	
}


void CEditDlg::OnKillfocusEditHt() 
{
}

void CEditDlg::OnKillfocusEditWt() 
{
}

void CEditDlg::OnKillfocusEditAst() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditBlk() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditClutch() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditConsistency() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditDrb() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditEffort() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditF() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditFd() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditFtScoring() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditFtShooting() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditG() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditI() 
{

	
}

void CEditDlg::OnKillfocusEditId() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditMin() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditName() 
{
}

void CEditDlg::OnKillfocusEditO() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditOd() 
{
	// TODO: Add your control notification handler code here

	
}

void CEditDlg::OnKillfocusEditOrb() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditP() 
{

	
}

void CEditDlg::OnKillfocusEditPd() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditPot1() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEditPot2() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditShooting() 
{
	// TODO: Add your control notification handler code here

}

void CEditDlg::OnKillfocusEditStl() 
{
	// TODO: Add your control notification handler code here
}

void CEditDlg::OnKillfocusEditTo() 
{
	// TODO: Add your control notification handler code here

 }


void CEditDlg::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit10() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit11() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit12() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit13() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit14() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit4() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit5() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit6() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit7() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit8() 
{
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnKillfocusEdit9() 
{
	// TODO: Add your control notification handler code here
	
}


void CEditDlg::SetStatsAdjComp()
{

	UpdateData(TRUE);
	int comp = m_combo_comp.GetCurSel() + 1;
	int team = m_combo_team.GetCurSel() + 1;
	int dur = m_combo_durability.GetCurSel() + 1;

	double athlete = (double)m_edit_athlete / 100.;
	double factor1 = (70 + (comp + team) * 2) / 100. * athlete;
	double factor2 = (85 + (comp + team) * 1) / 100. * athlete;
	double factor3 = (70 + comp * 4) / 100. * athlete;
	double factor4 = (86 + comp * 4 - team) / 100. * athlete;
	double factor7 = (82 + comp * 4 - team) / 100. * athlete;
	double factor5 = (50 + comp * 6) / 100. * athlete;
	double factor6 = 1 + (10-comp)/100;


	int old_touches = m_edit_3 + m_edit_5 + m_edit_10;



	double min_factor = 1; 



	double fgm = ((double)m_edit_2 - (double)m_edit_6) * factor1 * factor2;
	double fga = ((double)m_edit_3 - (double)m_edit_7) * factor1;

	double tgm = (double)m_edit_6 * factor1 * factor2;
	double tga = (double)m_edit_7 * factor1;

	
	m_actual.SetFgm((int)fgm + (int)tgm);
	m_actual.SetFga((int)fga + (int)tga);


	m_actual.SetFtm(int((double)m_edit_4 * factor1));
	m_actual.SetFta(int((double)m_edit_5 * factor1));

	m_actual.SetTfgm(int(tgm));
	m_actual.SetTfga(int(tga));


	m_actual.SetOreb(int((double)m_edit_8 * factor3));
	m_actual.SetReb(int((double)m_edit_9 * factor3));

	m_actual.SetAst(int((double)m_edit_10 * factor4));
	m_actual.SetStl(int((double)m_edit_11 * factor7));


	int new_touches = m_actual.GetFga() + m_actual.GetFta() + m_actual.GetAst();
	double factor = (double)new_touches / (double)old_touches;
	m_actual.SetTo(int((double)m_edit_12 * factor));
	m_actual.SetBlk(int((double)m_edit_13 * factor5));
	m_actual.SetPf(int((double)m_edit_14 * factor6));









	if(dur > 5) dur = 5;
	else if(dur < 1) dur = 1;

	int old_g = m_actual.m_games;
	int new_g = 60 + dur*4;
	double g_factor = (double) new_g / (double) old_g;

	double old_mpg = (double) m_actual.m_min / (double) m_actual.m_games;


	//ajdust mpg && games
//	double tru = GetRookieTrue(games, mpg, fgm, fga, tgm, tga, ftm, fta, orb, drb, ast, stl, to, blk, pf);
  	double gun = m_actual.m_fgm + m_actual.m_tfgm - (m_actual.m_fga - m_actual.m_fgm) * 2/3;
  	gun = gun + m_actual.m_ftm - m_actual.m_fta / 2; 
	gun = gun + (m_actual.m_fta - m_actual.m_ftm) * 1/6;
	gun = gun * 3/2;

 	double skill = m_actual.m_oreb * 2/3 + (m_actual.m_reb - m_actual.m_oreb)* 1/3;
	skill = skill + m_actual.m_stl -  m_actual.m_to + m_actual.m_blk;
	skill = skill + m_actual.m_ast * 4 / 5;
	skill = skill * 3/4;//fix this shit maybe
	double tru = gun + skill;
	if(m_actual.m_games == 0)
		tru = 0;
	else
		tru = tru / m_actual.m_min * 48;


	tru = tru*(old_mpg/48);
	double mpg2 = tru * 2.5 + 8;
	if(mpg2 <= 2) mpg2 = 2;
	if(mpg2 >= 45) mpg2 = 45;


min_factor = mpg2 / old_mpg;


	m_actual.m_games = new_g;
	m_actual.m_min = int((double)m_actual.m_min * g_factor * min_factor);






min_factor = g_factor * min_factor;




fgm = ((double)m_actual.m_fgm - (double)m_actual.m_tfgm)  * min_factor;
fga = ((double)m_actual.m_fga - (double)m_actual.m_tfga) * min_factor;

tgm = (double)m_actual.m_tfgm * min_factor;
tga = (double)m_actual.m_tfga * min_factor;

	
	m_actual.SetFgm((int)fgm + (int)tgm);
	m_actual.SetFga((int)fga + (int)tga);


	m_actual.SetFtm(int((double)m_actual.m_ftm  * min_factor));
	m_actual.SetFta(int((double)m_actual.m_fta  * min_factor));

	m_actual.SetTfgm(int(tgm));
	m_actual.SetTfga(int(tga));

	
	m_actual.SetOreb(int((double)m_actual.m_oreb * min_factor));
	m_actual.SetReb(int((double)m_actual.m_reb * min_factor));

	m_actual.SetAst(int((double)m_actual.m_ast *  min_factor));
	m_actual.SetStl(int((double)m_actual.m_stl *  min_factor));


new_touches = m_actual.GetFga() + m_actual.GetFta() + m_actual.GetAst();
factor = (double)new_touches / (double)old_touches;

	if(m_actual.m_pos != "PG") factor = (100. + (double)team - (double)comp) / 100.;


	m_actual.SetTo(int((double)m_actual.m_to *  min_factor));
	m_actual.SetBlk(int((double)m_actual.m_blk * min_factor));
	m_actual.SetPf(int(double(m_actual.m_pf) * min_factor));




}

void CEditDlg::OnButtonAdjust() 
{
	// TODO: Add your control notification handler code here
	SetStatsAdjComp();	
	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
	Initialize();

	
}


void CEditDlg::OnSelchangeComboteams() 
{
	// TODO: Add your control notification handler code here

	SetStats();	
	SavePlayer();
	
}

void CEditDlg::OnSelchangeCombopos() 
{
	// TODO: Add your control notification handler code here
	SetStats();	
	SavePlayer();
}

void CEditDlg::SavePlayer()
{
	SetEditedRatings();

	if(m_rookie_edit != true)
	{
	int slot = m_teamindex*30 + m_posindex;
	avg.m_actual[slot] = m_actual;
	m_teamindex = m_comboteams.GetCurSel();
	if(m_teamindex >= avg.m_settings.m_numberteams) m_teamindex = 32;
	m_posindex = m_combopos.GetCurSel() + 1;
	slot = m_teamindex*30 + m_posindex;
	m_actual = avg.m_actual[slot];
	if(m_actual.m_id == 0 && m_actual.m_name != "")
	{
		avg.m_actual[slot].m_id = m_id_count;
		m_id_count = m_id_count + 1;
		//ReadWriteID();//updates id & clears simmed stats
		avg.m_actual[slot].ClearSeasonStats();
		avg.m_actual[slot].m_content = 5;
		avg.m_actual[slot].m_current_team = m_teamindex;
	}


		Initialize();
		FillSlotsWithPlayerNames();

	}
}

void CEditDlg::OnCheckActive() 
{
	// TODO: Add your control notification handler code here
	if(m_active == TRUE) m_active = FALSE;
	else m_active = TRUE;	
}

void CEditDlg::OnButtonCalculateRatings() 
{
	// TODO: Add your control notification handler code here
	SetStats();	
	m_actual.SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
	Initialize();
	
}

void CEditDlg::FillSlotsWithPlayerNames()
{

	m_posindex = m_combopos.GetCurSel()+1;
	if(m_posindex <= 0) m_posindex = 1;
	m_combopos.ResetContent();
	int pl=25;
	int ind = m_teamindex;
	if(m_teamindex == 32)
	{
		pl=360;
		ind = 32;
	}
	CString str;
	for(int i=1; i<=pl; i++)
	{
		int slot =ind*30 + i;
		if(avg.m_actual[slot].m_name == "")
		{
			str.Format("slot %d is blank", i);
		}
		else
		{
			str = avg.m_actual[slot].m_name;
		}
		m_combopos.AddString(str);
	}
	m_combopos.SetCurSel(m_posindex-1);

}

void CEditDlg::WriteID()
{
	
	CString pFileName = avg.m_settings.m_path + avg.m_settings.m_league_name + ".car";
	CFile file(	pFileName, CFile::modeWrite);	

	CString string;
	string.Format("%d", m_id_count);
	string = string + "     ";
	file.Seek( 0, CFile::begin);
	file.Write(string, 5);
	file.Close();

	
}

void CEditDlg::OnButtonCalculateStats() 
{
	// TODO: Add your control notification handler code here

	// TODO: Add your control notification handler code here
//	SetEditedRatings();

UpdateData(TRUE);

//	set new stats
	

	SetRatings();
	
	m_actual.ConvertRatingsToStats(
					m_edit_g, m_edit_min, 
					avg.m_avg_g[m_po],  avg.m_avg_min[m_po],
					 avg.m_avg_fga[0],  avg.m_avg_fgp[0],
					 avg.m_avg_fta[0],  avg.m_avg_ftp[0],
					 avg.m_avg_tga[0],  avg.m_avg_tgp[0],
					 avg.m_avg_orb[0],  avg.m_avg_drb[0],  avg.m_avg_ast[0],
					 avg.m_avg_stl[0],  avg.m_avg_to[0],  avg.m_avg_blk[0],
					 avg.m_avg_pf[m_po],
					 avg.m_hi_fga[0],  avg.m_hi_fta[0],  avg.m_hi_tga[0], 
					 avg.m_hi_orb[0],  avg.m_hi_drb[0],  avg.m_hi_ast[0],
					 avg.m_hi_stl[0],  avg.m_hi_to[0],  avg.m_hi_blk[0]		
					);





	SetEditVariables();

}
