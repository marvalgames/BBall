// EditRatings.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
//#include "constants.h"
//#include "resource.h"

#include "EditRatings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditRatings dialog


CEditRatings::CEditRatings(CWnd* pParent /*=NULL*/)
	: CDialog(CEditRatings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditRatings)
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
	m_edit_min = 0;
	m_edit_g = 0;
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
	//}}AFX_DATA_INIT
}


void CEditRatings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditRatings)
	DDX_Control(pDX, IDC_LIST_AVG, m_listAvg);
	DDX_Control(pDX, IDC_COMBO_POS, m_combo_pos);
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
	DDV_MinMaxInt(pDX, m_edit_min, 0, 48);
	DDX_Text(pDX, IDC_EDIT_G, m_edit_g);
	DDV_MinMaxInt(pDX, m_edit_g, 0, 99);
	DDX_Text(pDX, IDC_EDIT_AGE, m_edit_age);
	DDV_MinMaxInt(pDX, m_edit_age, 1, 99);
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
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditRatings, CDialog)
	//{{AFX_MSG_MAP(CEditRatings)
	ON_WM_CTLCOLOR()
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON_AVG, OnButtonAvg)
	ON_CBN_SELCHANGE(IDC_COMBO_POS, OnSelchangeComboPos)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, OnButtonCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditRatings message handlers

HBRUSH CEditRatings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CEditRatings::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	WinHelp(HID_PLAYERS_EDITRATINGS);
	return TRUE;		
//	return CDialog::OnHelpInfo(pHelpInfo);
}

void CEditRatings::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	WinHelp(HID_PLAYERS_EDITRATINGS);
//	return TRUE;		
}

BOOL CEditRatings::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitVariables();
	SetAverages();
	InitCtrl();
	SetPlayerRatings();
	DisplayRatings();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditRatings::OnOK() 
{
	// TODO: Add extra validation here

	SetEditedRatings();
	
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

	CDialog::OnOK();
}

void CEditRatings::DisplayRatings()
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
		m_edit_min = 1;
		m_edit_g = 1;
	}
	SetEditVariables();
}



	

void CEditRatings::SetAverages()
{
//	for(int i=0; i<=580; i++)
//	{
//	
//		avg.m_actual[i] = m_player[i];
//	}
	
	avg.SetHighs();
}

void CEditRatings::SetPlayerRatings()
{
	for(int i=0; i<=580; i++)
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

void CEditRatings::InitVariables()
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

void CEditRatings::SetEditedRatings()
{
	UpdateData(TRUE);
	GetPlayerPosition();
	SetRatings();

}

void CEditRatings::InitCtrl()
{

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
}

void CEditRatings::OnButtonAvg() 
{
	// TODO: Add your control notification handler code here

	SetPlayerToAverage();
	SetRatings();
	SetEditVariables();
	int fg = int(double(m_edit_fgp)/100.*double(m_actual.GetFga()));
	m_actual.SetFgm(fg);
	int tg = int(double(m_edit_tgp)/100.*double(m_actual.GetTfga()));
	m_actual.SetTfgm(tg);
	int ft = int(double(m_edit_ftp)/100.*double(m_actual.GetFta()));
	m_actual.SetFtm(ft);
//	orig_tgp = m_edit_tgp;
//	orig_ftp = m_edit_ftp;
//	orig_fgp = m_edit_fgp;
}

void CEditRatings::SetPlayerToAverage()
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

	m_edit_o = 5;
	m_edit_p = 5;
	m_edit_i = 5;
	m_edit_f = 5;

	m_edit_od = 5;
	m_edit_pd = 5;
	m_edit_id = 5;
	m_edit_fd = 5;
	
}

void CEditRatings::SetRatings()
{
	orig_min = m_edit_min;


	m_actual.SetGames(m_edit_g);
	m_actual.SetName(m_edit_name);
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

}

void CEditRatings::SetEditVariables()
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

	UpdateData(FALSE);
}

void CEditRatings::OnSelchangeComboPos() 
{
	// TODO: Add your control notification handler code here
	GetPlayerPosition();
	
}

void CEditRatings::GetPlayerPosition()
{
	CString string;
	m_combo_pos.GetLBText(m_combo_pos.GetCurSel(), string);
	string.MakeUpper();
	m_actual.SetPos(string);
	if(m_actual.GetPos() == "PG") m_po = 1;
	else if(m_actual.GetPos() == "SG") m_po = 2;
	else if(m_actual.GetPos() == "SF") m_po = 3;
	else if(m_actual.GetPos() == "PF") m_po = 4;
	else if(m_actual.GetPos() == " C") m_po = 5;
}

void CEditRatings::OnButtonCalculate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetRatings();
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

	UpdateData(FALSE);
}

void CEditRatings::OnButtonCalculateRatings() 
{
	SetEditedRatings();
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

}


