// FreeAgentOfferDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BBall.h"
#include "FreeAgentOfferDlg.h"
#include "NegotiateDlg.h"
#include "ScheduleDlg.h"

// CFreeAgentOfferDlg dialog

IMPLEMENT_DYNAMIC(CFreeAgentOfferDlg, CDialog)
CFreeAgentOfferDlg::CFreeAgentOfferDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFreeAgentOfferDlg::IDD, pParent)
{


bitmapBkgnd.Attach (LoadBitmap (AfxGetInstanceHandle(), 
                    MAKEINTRESOURCE(IDB_BITMAP_FA)));

	myBrush.CreateSolidBrush(RGB(0,0,0));


	//bitmapBkgnd.Attach ( LoadImage( NULL, "default.bmp", IMAGE_BITMAP, 0, 0,
	//	LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE ));

}

CFreeAgentOfferDlg::~CFreeAgentOfferDlg()
{
}

void CFreeAgentOfferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FA, m_list_fa);
	DDX_Control(pDX, IDOK, m_radio[0]);
	DDX_Control(pDX, IDC_BUTTON_RECOMMEND, m_radio[1]);
	DDX_Control(pDX, IDC_BUTTON_STANDARD, m_radio[2]);
	DDX_Control(pDX, IDC_BUTTON_CONTRACT, m_radio[3]);
	DDX_Control(pDX, IDC_BUTTON_PERSONALITY, m_radio[4]);
	DDX_Control(pDX, IDC_BUTTON_SCOUT, m_radio[5]);
	DDX_Control(pDX, IDC_BUTTON_WATCH, m_radio[6]);
	DDX_Control(pDX, IDC_BUTTON_CONTACT, m_radio[7]);
	DDX_Control(pDX, IDC_BUTTON_OFFER, m_radio[8]);
	DDX_Control(pDX, IDC_BUTTON_TEAM, m_radio[9]);
	DDX_Control(pDX, IDC_BUTTON_HTML, m_radio[10]);
	DDX_Control(pDX, IDC_BUTTON_REPORT, m_radio[11]);
}


BEGIN_MESSAGE_MAP(CFreeAgentOfferDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_STANDARD, OnBnClickedButtonStandard)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_REPORT, OnBnClickedButtonReport)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_WATCH, OnBnClickedButtonWatch)
	ON_BN_CLICKED(IDC_BUTTON_TEAM, OnBnClickedButtonTeam)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FA, OnNMClickListFa)
	ON_BN_CLICKED(IDC_BUTTON_OFFER, OnBnClickedButtonOffer)
END_MESSAGE_MAP()


// CFreeAgentOfferDlg message handlers

BOOL CFreeAgentOfferDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	InitListCtrl();
	FillStaticCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}







void CFreeAgentOfferDlg::FillStaticCtrl()
{
	CString s1,s2,s3,s4;

	int te = avg.m_settings.m_default_team;
	int cap_space = 0;
	int lux_space = 0;
	
//	int *current_payroll = avg.m_owner[te].CurrentPayrollCC(avg.m_actual, te);
	int *current_payroll = avg.CurrentPayrollCC(te, cap_space, lux_space);

//	s1 = "12.89 million";
//	s2 = "25.78 million";

	s1.Format("%.2f million", (float)cap_space / 100);
	s2.Format("%.2f million", (float)lux_space / 100);
	s3 = "NO";
	s4 = "NO";
	if(avg.m_owner[te].m_mid_exception_used == false) s3 = "YES";
	if(avg.m_owner[te].m_million_exception_used == false) s4 = "YES";

	GetDlgItem(IDC_STATIC1)->SetWindowText(s1);
	GetDlgItem(IDC_STATIC2)->SetWindowText(s2);
	GetDlgItem(IDC_STATIC3)->SetWindowText(s3);
	GetDlgItem(IDC_STATIC4)->SetWindowText(s4);

}





void CFreeAgentOfferDlg::InitListCtrl()
{



	LOGFONT lf;                        // Used to create the CFont.
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 800;
	lf.lfHeight = 13;
	strcpy(lf.lfFaceName, "Arial");
	m_font.CreateFontIndirect(&lf);    // Create the font.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfWeight = 600;
	lf.lfHeight = 13;
	strcpy(lf.lfFaceName, "Arial");
	m_font1.CreateFontIndirect(&lf);    // Create the font.




	for(int i=0; i<=1; i++)
	{
		//m_radio[i].m_image = "button8.png";//2021
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_IN, DARKRED);
		//m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_OUT, MYCOLOR1);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_IN, YELLOW);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_OUT, WHITE);
		m_radio[i].SetFont(&m_font1);
	}

	for(int i=2; i<=5; i++)
	{
		//m_radio[i].m_image = "button9.png";
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_IN, DARKRED);
		//m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_OUT, MYCOLOR1);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_IN, YELLOW);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_OUT, WHITE);
		m_radio[i].SetFont(&m_font1);
	}
	for(int i=6; i<=11; i++)
	{
		//m_radio[i].m_image = "button8.png";
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_IN, DARKRED);
		//m_radio[i].SetColor(CButtonST::BTNST_COLOR_BK_OUT, MYCOLOR1);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_IN, YELLOW);
		m_radio[i].SetColor(CButtonST::BTNST_COLOR_FG_OUT, WHITE);
		m_radio[i].SetFont(&m_font1);
	}


	m_list_fa.SetBkColor(BK_COLOR);
	m_list_fa.SetTextBkColor(BK_COLOR);
	m_list_fa.SetTextColor(WHITE);
	m_list_fa.SetFont(&m_font);
	m_list_fa.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FLATSB);


	CRect rect;
	m_list_fa.GetClientRect(&rect);
	int size = (rect.Width()-15)/12;
	m_list_fa.InsertColumn(0, _T("Player"), LVCFMT_CENTER, size*3);
	m_list_fa.InsertColumn(1, _T("Pos"), LVCFMT_CENTER, size*1);
	m_list_fa.InsertColumn(2, _T("HT"), LVCFMT_CENTER, size*1);
	m_list_fa.InsertColumn(3, _T("WT"), LVCFMT_CENTER, size*1);
	m_list_fa.InsertColumn(4, _T("Exp"), LVCFMT_CENTER, size*1);
	m_list_fa.InsertColumn(5, _T("Age"), LVCFMT_CENTER, size*1);
	m_list_fa.InsertColumn(6, _T("Team"), LVCFMT_CENTER, size*4);
	

}






void CFreeAgentOfferDlg::OnBnClickedButtonStandard()
{
	// TODO: Add your control notification handler code here
}

// List Current Team Roster (remember FA yes/no column)
void CFreeAgentOfferDlg::ListTeam(int list_type)
{
	m_list_fa.DeleteAllItems();
	int start = 0;
	int end = 0;

	if(list_type == TEAM)
	{
		start = avg.m_settings.m_default_team*30 + 1;
		end = start + 29;
	}
	else if(list_type == WATCH)
	{
		start = 0;
		end = 50;
	}
	int co = 0;
	for(int i=start; i<=end; i++)
	{

		int index = 0;
		if(list_type == TEAM)
		{
			index = i;
		}
		else if(list_type == WATCH)
		{
			int team = avg.m_settings.m_default_team;
			int id = avg.m_standings[team].m_watch_list[i];
			CString na = avg.FindID(id, index);
			//temp for screen
			index = avg.IntRandom(960);
		}



		CPlayer m_player = avg.m_actual[index];
		CString Stats[33];
		CString Name = m_player.GetName();
		CString Pos = m_player.GetPos();

		int team = m_player.m_current_team;
		CString te_na;
		if(team >= 0) 
		{
			te_na = m_player.GetFullTeamName(avg.m_standings[team].m_city_name, avg.m_standings[team].m_team_name);
		}

		if(Name == "") continue;
		m_pointer[co] = index;
		Stats[0] = Name;
		Stats[1] = m_player.GetPos();
		CString height  = m_player.GetHeight(m_player.m_height);
		Stats[2] = height;
		Stats[3].Format("%d", m_player.m_weight);
		Stats[4].Format("%d", m_player.m_yrs_of_service);
		Stats[5].Format("%d", m_player.m_age);
		Stats[6] = te_na;





// Insert the first item
	LVITEM lvi;		
	lvi.mask =  LVIF_IMAGE | LVIF_TEXT;
	lvi.iItem = co;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(Stats[0]);
	m_list_fa.InsertItem(&lvi);

// Set subitems

		for(int s=0; s<=5; s++)
		{

		lvi.mask =  LVIF_TEXT;
		lvi.iImage = -1;		// There are 8 images in the image list
		lvi.iSubItem = s+1;
		lvi.pszText = (LPTSTR)(LPCTSTR)(Stats[s+1]);
		m_list_fa.SetItemText(co,s+1, Stats[s+1], WHITE, BK_COLOR);

		}


		//m_list_fa.InsertItem(co,Stats[0]);
		//for(int s=0; s<=5; s++)
		//{
		//	m_list_fa.SetItemText(co,s+1,Stats[s+1]);
		//}
		co = co + 1;
	}






	









}

BOOL CFreeAgentOfferDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
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
   return TRUE;	

	//return CDialog::OnEraseBkgnd(pDC);
}

void CFreeAgentOfferDlg::OnBnClickedButtonReport()
{
	// TODO: Add your control notification handler code here
	//CNegotiateDlg* neg = new CNe

	CNegotiateDlg* neg = new CNegotiateDlg;
	short pointer = m_list_fa.GetNextItem( -1, LVNI_ALL | LVNI_SELECTED);
	int te = avg.m_settings.m_default_team;
	CPlayer* m_player = new CPlayer;
	int index = m_pointer[pointer];
	*m_player = avg.m_actual[index];
	neg->m_player = *m_player;
	neg->m_player_pointer = pointer;
	neg->m_pointer_id = m_player->m_id;
	//neg->m_negotiate_extension = false;
	//neg->m_coach_rating = 0;
	
	neg->m_cap = avg.m_settings.m_cap;
	neg->m_salary_cap = avg.m_standings[te].m_owner_salary_cap;
	neg->m_team_negotiating = te;
	neg->m_owner = avg.m_owner[te];
	//neg->m_pointer = pointer;
	for(int i=0; i<=32; i++)
	{
		neg->m_league_team_names[i] = avg.m_standings[i].m_city_name;
	}
	neg->m_number_teams = avg.m_settings.m_numberteams;
	int result = neg->DoModal();
	*m_player = neg->m_player;
	int count = avg.m_standings[te].m_offer_count;
	avg.m_standings[te].m_offers[count] = neg->m_offer_string;
	m_player->m_offers[te] = neg->m_offer_string;



	delete m_player;
	delete neg;

}

void CFreeAgentOfferDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

HBRUSH CFreeAgentOfferDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
switch (nCtlColor)
     {
     //Edit controls need white background and black text
     //Note the 'return hbr' which is needed to draw the Edit
     //control's internal background (as opposed to text background)
     case CTLCOLOR_EDIT:
          pDC->SetTextColor(RGB(255,255,255));
          pDC->SetBkColor(RGB(0,0,0));
			return myBrush          ;
     //Static controls need black text and same background as myBrush
     case CTLCOLOR_STATIC:
          LOGBRUSH logbrush;
          myBrush.GetLogBrush( &logbrush );
          pDC->SetTextColor(RGB(255,255,255));
          pDC->SetBkColor(logbrush.lbColor);                                    
          return myBrush;
//     case CTLCOLOR_BTN:
  //        pDC->SetTextColor(RGB(0,255,255));
    //      pDC->SetBkColor(RGB(255,128,128));
      //    return myBrush;
   case CTLCOLOR_LISTBOX:
		  //pDC->SetBkMode(TRANSPARENT);
          pDC->SetBkColor(RGB(0,0,0));
          pDC->SetTextColor(RGB(255,255,255));
          return myBrush;

     case CTLCOLOR_SCROLLBAR:
          pDC->SetTextColor(RGB(255,255,255));
          pDC->SetBkColor(RGB(0,0,0));
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

	// TODO:  Return a different brush if the default is not desired

	return (CDialog::OnCtlColor(pDC, pWnd, nCtlColor)); 	
	
	
	//return hbr;
}

void CFreeAgentOfferDlg::OnBnClickedButtonWatch()
{
	// TODO: Add your control notification handler code here
	ListTeam(WATCH);
}

void CFreeAgentOfferDlg::OnBnClickedButtonTeam()
{
	// TODO: Add your control notification handler code here
	ListTeam(TEAM);
}

void CFreeAgentOfferDlg::OnNMClickListFa(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CFreeAgentOfferDlg::OnBnClickedButtonOffer()
{
	// TODO: Add your control notification handler code here
}
