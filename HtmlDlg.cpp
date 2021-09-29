// HtmlDlg.cpp : implementation file
//

#include "stdafx.h"
//#include "bball.h"
#include "MyComboBox.h"
//#include "bball.h"
//#ifndef BBall_h
//#include "BBall.h"
//#define BBall_h
//#endif // Added by ClassView
//#include "constants.h"
//#include "resource.h"


#ifndef ColorStaticST_h
#include "ColorStaticST.h"
#define ColorStaticST_h
#endif

#include "HtmlDlg.h"

//#ifndef Html_h
#include "Html.h"
//#define Html_h
//#endif 
#include <direct.h>






#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlDlg dialog


CHtmlDlg::CHtmlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHtmlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHtmlDlg)
	//}}AFX_DATA_INIT
	m_scout = new CStaff[101];
}


void CHtmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHtmlDlg)
	DDX_Control(pDX, IDC_BUTTON_FONT, m_button_font);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_button_delete);
	DDX_Control(pDX, IDC_BUTTON_VIEW, m_button_view);
	DDX_Control(pDX, IDC_COMBO_PLAYER, m_combo_player);
	DDX_Control(pDX, IDC_COMBO_BOX, m_combo_box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHtmlDlg, CDialog)
	//{{AFX_MSG_MAP(CHtmlDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, OnButtonView)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_PAGE_COLOR, OnButtonPageColor)
	ON_BN_CLICKED(IDC_BUTTON_TEXT_COLOR, OnButtonTextColor)
	ON_BN_CLICKED(IDC_BUTTON_LINK_COLOR, OnButtonLinkColor)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_TEST, OnButtonViewTest)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_FONT, OnButtonFont)
	ON_BN_CLICKED(IDC_BUTTON_VLINK_COLOR, OnButtonVlinkColor)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlDlg message handlers

void CHtmlDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolshtmlexport.htm", HH_DISPLAY_TOPIC, 0);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
	
}

BOOL CHtmlDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
//	HtmlHelp(NULL, "jumpshot.chm::/html/toolshtmlexport.htm", HH_DISPLAY_TOPIC, 0);
	
	return CDialog::OnHelpInfo(pHelpInfo);
	
//	return CDialog::OnHelpInfo(pHelpInfo);
}

BOOL CHtmlDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 //m_stcDanger.SubclassDlgItem(IDC_DANGER, this
	myBrush.CreateSolidBrush(DLGCOLOR); 

	m_static_lc.SubclassDlgItem(IDC_STATIC_LC, this);
	m_static_vl.SubclassDlgItem(IDC_STATIC_VL, this);
	m_static_tc.SubclassDlgItem(IDC_STATIC_TC, this);
	m_static_bg.SubclassDlgItem(IDC_STATIC_BG, this);

	InitData();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHtmlDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete [] m_scout;
	
	// TODO: Add your message handler code here
	
}

void CHtmlDlg::OnButtonCreate() 
{
	// TODO: Add your control notification handler code here

	int result = AfxMessageBox("Are you sure you want to Create HTML files for the current league?",
						   MB_YESNO);

	if(result == IDYES)
	{

	m_button_view.EnableWindow(TRUE);

	CHtml* html = new CHtml;
	html->m_stage = m_stage;
	html->m_path = m_path;
	html->m_league_name = m_league_name;
	html->avg = avg;
	html->m_bk_color = "\"" + m_bk_color + "\"";
	html->m_text_color = "\"" + m_text_color + "\"";
	html->m_link_color = "\"" + m_link_color + "\"";
	html->m_vlink_color = "\"" + m_vlink_color + "\"";
	html->m_html_font = m_html_font;


	int box_index = m_combo_box.GetCurSel();
	int player_page_index = m_combo_player.GetCurSel();

	html->m_box_index = box_index;
	html->m_player_page_index = player_page_index;
	html->GenerateReports();

	delete html;
	
	}
}

void CHtmlDlg::InitData()
{
	if(m_bk_color == "")
		m_bk_color = "#FFFFFF";
	if(m_text_color == "")
		m_text_color = "#000000";
	if(m_link_color == "")
		m_link_color = "#804040";
	if(m_vlink_color == "")
		m_vlink_color = "#0080FF";

	if(m_html_font == "")
	{
		int size = 8;
		CString face = "Arial";
		m_html_font.Format("font-size: %dpt; font-family:%s", size, face);
	}


	m_save_selection = false;

	// CString m_bk_color = "#FFFFFF";
    //unsigned int u = strtoul(m_bk_color, NULL, 16);
    //COLORREF c = RGB((u>>16)&0xff, (u>>8)&0xff, u&0xff);


	
	m_combo_box.AddString("No teams");
	m_combo_player.AddString("No teams");
	m_combo_box.AddString("All teams");
	m_combo_player.AddString("All teams");
	m_button_view.SetWindowText(m_league_name + " Web Site Preview");
	for(int i=0; i<=32; i++)
	{
		CString team = avg.m_finance[i].m_team_name;
		if(team != "")
		{
			m_combo_box.AddString(team);
			m_combo_player.AddString(team);
		}
	}

	m_combo_box.SetCurSel(0);
	m_combo_player.SetCurSel(0);
	CString file_name = m_path + m_league_name + "\\index.htm";
	CFileStatus status;
	if(CFile::GetStatus(file_name, status) == FALSE)
	{
		m_button_view.EnableWindow(FALSE);
		m_button_delete.EnableWindow(FALSE);
	}

	SetButtonColors();
	m_button_font.SetWindowText(m_html_font);


}

void CHtmlDlg::OnButtonView() 
{
	// TODO: Add your control notification handler code here
	CString path = m_path + m_league_name + "\\";	
	path = path + "index.htm";

	ShellExecute(*this, "open", path, NULL, NULL, SW_SHOWNORMAL);	
	
}

void CHtmlDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int result = AfxMessageBox("Are you sure you want to delete all HTML files for the current league?",
						   MB_YESNO);
	CString path = m_path + m_league_name + "\\"; 
	SetCurrentDirectory(path);

	if(result == IDYES)
	{

	m_button_view.EnableWindow(FALSE);
	m_button_delete.EnableWindow(FALSE);




	CFileFind finder;
	BOOL bWorking = finder.FindFile("*.htm");
	while (bWorking)
	{	
		bWorking = finder.FindNextFile();
		CString file_name = finder.GetFileName();
		CFile::Remove(path + file_name);
	}

	}

}

void CHtmlDlg::OnButtonPageColor() 
{
	// TODO: Add your control notification handler code here

	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{

	m_b = color.GetColor();

//	unsigned int u = strtoul(m_bk_color, NULL, 16);
  //  COLORREF c = RGB((u>>16)&0xff, (u>>8)&0xff, u&0xff);



	m_bk_color.Format(_T("#%X%X%X"), GetRValue(m_b),
           GetGValue(m_b), GetBValue(m_b));
//   m_static_vl.SetTextColor(m_v);
//   m_static_vl.SetBkColor(m_v);
//   m_static_lc.SetTextColor(m_l);
//   m_static_lc.SetBkColor(m_l);
//   m_static_tc.SetTextColor(m_t);
//   m_static_tc.SetBkColor(m_t);
   m_static_bg.SetTextColor(m_b);
   m_static_bg.SetBkColor(m_b);
	}
	
}

void CHtmlDlg::OnButtonTextColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{

//	COLORREF c = color.GetColor();
	m_t = color.GetColor();


	m_text_color.Format(_T("#%X%X%X"), GetRValue(m_t),
           GetGValue(m_t), GetBValue(m_t));

//   m_static_vl.SetTextColor(m_v);
//   m_static_vl.SetBkColor(m_v);
//   m_static_lc.SetTextColor(m_l);
//   m_static_lc.SetBkColor(m_l);
   m_static_tc.SetTextColor(m_t);
   m_static_tc.SetBkColor(m_t);
	}	
}

void CHtmlDlg::OnButtonLinkColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{
	//COLORREF m_cref = color.GetColor();
	m_l = color.GetColor();


	m_link_color.Format(_T("#%X%X%X"), GetRValue(m_l),
           GetGValue(m_l), GetBValue(m_l));

//   m_static_vl.SetTextColor(m_v);
//   m_static_vl.SetBkColor(m_v);
   m_static_lc.SetTextColor(m_l);
   m_static_lc.SetBkColor(m_l);
	}	
}

void CHtmlDlg::OnButtonViewTest() 
{
	// TODO: Add your control notification handler code here
	m_button_view.EnableWindow(TRUE);

	CHtml* html = new CHtml;
	html->m_path = m_path;
	html->m_league_name = m_league_name;
	html->m_bk_color = "\"" + m_bk_color + "\"";
	html->m_text_color = "\"" + m_text_color + "\"";
	html->m_link_color = "\"" + m_link_color + "\"";
	html->m_vlink_color = "\"" + m_vlink_color + "\"";
	html->m_html_font = m_html_font;
	_mkdir(m_path + m_league_name);
	html->GenerateMainPage();


	delete html;

	CString path = m_path + m_league_name + "\\";	
	path = path + "index.htm";

	ShellExecute(*this, "open", path, NULL, NULL, SW_SHOWNORMAL);	

	
}

void CHtmlDlg::OnButtonVlinkColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{
	//COLORREF m_cref = color.GetColor();
	m_v = color.GetColor();


	m_vlink_color.Format(_T("#%X%X%X"), GetRValue(m_v),
           GetGValue(m_v), GetBValue(m_v));

	//m_static_vl.SetColor(
   m_static_vl.SetTextColor(m_v);
   m_static_vl.SetBkColor(m_v);

	}
	
}

void CHtmlDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CHtmlDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	m_save_selection = true;
		m_bk_color = "#FFFFFF";
		m_text_color = "#000000";
		m_link_color = "#804040";
		m_vlink_color = "#0080FF";


		int size = 8;
		CString face = "Arial";
		m_html_font.Format("font-size: %dpt; font-family:%s", size, face);
		SetButtonColors();

	m_button_font.SetWindowText(m_html_font);

}

void CHtmlDlg::OnButtonFont() 
{
	// TODO: Add your control notification handler code here
	CFontDialog font;
	int result = font.DoModal();
	if(result == IDOK)
	{
	int size = font.GetSize()/10;
	CString face = font.GetFaceName();
	if(size == 0) size = 8;
	if(face == "") face = "Arial";
	//	font-size: 20pt; font-family:Arial; 
	m_html_font.Format("font-size: %dpt; font-family:%s", size, face);


	CString str;
	str.Format("font-size: %dpt; font-family:%s", size, face);
	m_button_font.SetWindowText(str);


	}
}


void CHtmlDlg::SetButtonColors()
{

//	CColorDialog color;
//	int result = color.DoModal();
//	m_b = color.GetColor();

//	unsigned int u = strtoul(m_bk_color, NULL, 16);
  //  COLORREF c = RGB((u>>16)&0xff, (u>>8)&0xff, u&0xff);


 //const char* color = "#FF80FF";
	CString col = m_vlink_color.Mid(1, 6);
    long temp = strtol(col, NULL, 16);
    unsigned red = temp / 0x10000;
    unsigned green = temp % 0x10000 / 0x100;
    unsigned blue = temp % 0x100;


   m_static_vl.SetTextColor(RGB(red, green, blue));
   m_static_vl.SetBkColor(RGB(red, green, blue));


	col = m_link_color.Mid(1, 6);
    temp = strtol(col, NULL, 16);
    red = temp / 0x10000;
    green = temp % 0x10000 / 0x100;
    blue = temp % 0x100;


   m_static_lc.SetTextColor(RGB(red, green, blue));
   m_static_lc.SetBkColor(RGB(red, green, blue));

	col = m_text_color.Mid(1, 6);
    temp = strtol(col, NULL, 16);
    red = temp / 0x10000;
    green = temp % 0x10000 / 0x100;
    blue = temp % 0x100;


   m_static_tc.SetTextColor(RGB(red, green, blue));
   m_static_tc.SetBkColor(RGB(red, green, blue));

	col = m_bk_color.Mid(1, 6);
    temp = strtol(col, NULL, 16);
    red = temp / 0x10000;
    green = temp % 0x10000 / 0x100;
    blue = temp % 0x100;

   m_static_bg.SetTextColor(RGB(red, green, blue));
   m_static_bg.SetBkColor(RGB(red, green, blue));



}

HBRUSH CHtmlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
//     case CTLCOLOR_STATIC:

//	if (pWnd->GetDlgCtrlID() == IDC_STATIC1 ||
//		pWnd->GetDlgCtrlID() == IDC_STATIC3 ||
//		pWnd->GetDlgCtrlID() == IDC_STATIC2 )
//	{


//	        LOGBRUSH logbrush;
//		    myBrush.GetLogBrush( &logbrush );
//			pDC->SetTextColor(STATICCOLOR);
//			pDC->SetBkColor(logbrush.lbColor);                                    
//			return myBrush;

//	}
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

     //case CTLCOLOR_MSGBOX:
       //   pDC->SetTextColor(RGB(255,255,255));
         // pDC->SetBkColor(RGB(255,128,128));
          //return myBrush;

     case CTLCOLOR_DLG:
          return myBrush;
     //This shouldn't occurr since we took all the cases, but
     //JUST IN CASE, return the new brush
     default:
          return hbr;
     } 	
	
          return hbr;

}
