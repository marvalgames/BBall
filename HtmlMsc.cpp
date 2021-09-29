// HtmlMsc.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"

#include "HtmlMsc.h"
#include "Html.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlMsc dialog


CHtmlMsc::CHtmlMsc(CWnd* pParent /*=NULL*/)
	: CDialog(CHtmlMsc::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHtmlMsc)
	m_edit_1 = 0;
	m_edit_2 = 0;
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CHtmlMsc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHtmlMsc)
	DDX_Control(pDX, IDC_BUTTON_FONT, m_button_font);
	DDX_Control(pDX, IDC_BUTTON_VIEW, m_button_preview);
	DDX_Text(pDX, IDC_EDIT1, m_edit_1);
	DDV_MinMaxUInt(pDX, m_edit_1, 1, 999);
	DDX_Text(pDX, IDC_EDIT2, m_edit_2);
	DDV_MinMaxUInt(pDX, m_edit_2, 1, 999);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHtmlMsc, CDialog)
	//{{AFX_MSG_MAP(CHtmlMsc)
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, OnButtonView)
	ON_BN_CLICKED(IDC_BUTTON_PAGE_COLOR, OnButtonPageColor)
	ON_BN_CLICKED(IDC_BUTTON_LINK_COLOR, OnButtonLinkColor)
	ON_BN_CLICKED(IDC_BUTTON_TEXT_COLOR, OnButtonTextColor)
	ON_BN_CLICKED(IDC_BUTTON_VLINK_COLOR, OnButtonVlinkColor)
	ON_BN_CLICKED(IDC_BUTTON_FONT, OnButtonFont)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlMsc message handlers

BOOL CHtmlMsc::OnInitDialog() 
{
	CDialog::OnInitDialog();


	m_static_lc.SubclassDlgItem(IDC_STATIC_LC, this);
	m_static_vl.SubclassDlgItem(IDC_STATIC_VL, this);
	m_static_tc.SubclassDlgItem(IDC_STATIC_TC, this);
	m_static_bg.SubclassDlgItem(IDC_STATIC_BG, this);

	myBrush.CreateSolidBrush(DLGCOLOR); 


	m_button_preview.EnableWindow(FALSE);
	
	// TODO: Add extra initialization here
	InitData();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHtmlMsc::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CHtmlMsc::OnButtonCreate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_name == "" || m_edit_1 < 1 || m_edit_2 < 1 || m_edit_1 > m_items || m_edit_2 > m_items || m_edit_2 < m_edit_1)
	{
		InitData();
	}
	else
	{



	CHtml* html = new CHtml;
	html->m_path = m_path;
	html->m_league_name = m_league_name;
	html->m_bk_color = m_bk_color;
	html->m_link_color = m_link_color;
	html->m_vlink_color = m_vlink_color;
	html->m_text_color = m_text_color;
	html->m_html_font = m_html_font;
	html->CreateMiscReport(m_label, m_headers, m_strings, m_edit_1, m_edit_2, m_name);
	m_button_preview.EnableWindow(TRUE);

	delete html;

	CString path = m_path + m_league_name + "\\";	
	path = path + m_name + ".htm";
	m_file_name = path;
	int result = AfxMessageBox("HTML Creation Complete", MB_OK);

	}
	
}

void CHtmlMsc::OnButtonView() 
{
	// TODO: Add your control notification handler code here

	ShellExecute(*this, "open", m_file_name, NULL, NULL, SW_SHOWNORMAL);	
	
}

void CHtmlMsc::InitData()
{
	TCHAR	szProgPath[MAX_PATH * 2];
	::GetCurrentDirectory(sizeof(szProgPath)/sizeof(TCHAR), szProgPath);

	CString default_path = (CString) szProgPath + "\\";//default name

	CString file_name = default_path + "settings.txt";// writes blank settings in not created 
	CString str1, str2, str3, str4, str5, str6, str7;

  	CStdioFile fil(file_name, CFile::modeRead);//read last league
	fil.ReadString(str1);
	str1.TrimRight();
	fil.ReadString(str2);
	str2.TrimRight();
	fil.ReadString(str3);
	str3.TrimRight();
	fil.ReadString(str4);
	str4.TrimRight();
	fil.ReadString(str5);
	str5.TrimRight();
	fil.ReadString(str6);
	str6.TrimRight();
	fil.ReadString(str7);
	str7.TrimRight();
	fil.Close();

	if(str1 != "")
	{
		m_bk_color = str3;
		m_text_color = str4;
		m_link_color = str5;
		m_vlink_color = str6;
		m_html_font = str7;

	}



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



	SetButtonColors();


	m_edit_1 = 1;
	m_edit_2 = m_items;
	m_name = m_label;
	m_name.Remove(' ');
	UpdateData(FALSE);
	
}

void CHtmlMsc::OnButtonPageColor() 
{
	// TODO: Add your control notification handler code here

	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{

	COLORREF c = color.GetColor();


	m_bk_color.Format(_T("#%X%X%X"), GetRValue(c),
           GetGValue(c), GetBValue(c));



   m_static_bg.SetTextColor(c);
   m_static_bg.SetBkColor(c);

	}
	
}

void CHtmlMsc::OnButtonLinkColor() 
{
	// TODO: Add your control notification handler code here

	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{
	COLORREF c = color.GetColor();


	m_link_color.Format(_T("#%X%X%X"), GetRValue(c),
           GetGValue(c), GetBValue(c));

   m_static_lc.SetTextColor(c);
   m_static_lc.SetBkColor(c);

	}
	

}

void CHtmlMsc::OnButtonTextColor() 
{
	// TODO: Add your control notification handler code here

	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{
	COLORREF c = color.GetColor();


	m_text_color.Format(_T("#%X%X%X"), GetRValue(c),
           GetGValue(c), GetBValue(c));

   m_static_tc.SetTextColor(c);
   m_static_tc.SetBkColor(c);

	}
	
}

void CHtmlMsc::OnButtonVlinkColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog color;
	int result = color.DoModal();
	if(result == IDOK)
	{
	COLORREF c = color.GetColor();


	m_vlink_color.Format(_T("#%X%X%X"), GetRValue(c),
           GetGValue(c), GetBValue(c));

   m_static_vl.SetTextColor(c);
   m_static_vl.SetBkColor(c);
	}

	
}

void CHtmlMsc::OnButtonFont() 
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

void CHtmlMsc::SetButtonColors()
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


HBRUSH CHtmlMsc::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
