// ScoutEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"

#ifndef ScoutEditDlg_h
#include "ScoutEditDlg.h"
#define ScoutEditDlg_h
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoutEditDlg dialog


CScoutEditDlg::CScoutEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoutEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoutEditDlg)
	m_edit_name = _T("");
	m_edit_age = 0;
	//}}AFX_DATA_INIT
	m_index = 0;
}


void CScoutEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoutEditDlg)
	DDX_Control(pDX, IDC_STATIC24, m_teamname);
	DDX_Text(pDX, IDC_EDIT_NAME, m_edit_name);
	DDV_MaxChars(pDX, m_edit_name, 32);
	DDX_Text(pDX, IDC_EDIT_AGE, m_edit_age);
	DDV_MinMaxUInt(pDX, m_edit_age, 18, 80);
	//}}AFX_DATA_MAP

DDX_Control(pDX, IDC_COMBOBOXEX1, m_value[1]);
	DDX_Control(pDX, IDC_COMBOBOXEX2, m_value[2]);
	DDX_Control(pDX, IDC_COMBOBOXEX3, m_value[3]);
	DDX_Control(pDX, IDC_COMBOBOXEX4, m_value[4]);
	DDX_Control(pDX, IDC_COMBOBOXEX5, m_value[5]);
	DDX_Control(pDX, IDC_COMBOBOXEX6, m_value[6]);
	DDX_Control(pDX, IDC_COMBOBOXEX7, m_value[7]);
	DDX_Control(pDX, IDC_COMBOBOXEX8, m_value[8]);
	DDX_Control(pDX, IDC_COMBOBOXEX9, m_value[9]);
	DDX_Control(pDX, IDC_COMBOBOXEX10, m_value[10]);
	DDX_Control(pDX, IDC_COMBOBOXEX11, m_value[11]);
	DDX_Control(pDX, IDC_COMBOBOXEX12, m_value[12]);
	DDX_Control(pDX, IDC_COMBOBOXEX13, m_value[13]);
	DDX_Control(pDX, IDC_COMBOBOXEX14, m_value[14]);
	DDX_Control(pDX, IDC_COMBOBOXEX15, m_value[15]);
	DDX_Control(pDX, IDC_COMBOBOXEX16, m_value[16]);
	DDX_Control(pDX, IDC_COMBOBOXEX17, m_value[17]);
	DDX_Control(pDX, IDC_COMBOBOXEX18, m_value[18]);
	DDX_Control(pDX, IDC_COMBOBOXEX19, m_value[19]);
	DDX_Control(pDX, IDC_COMBOBOXEX20, m_value[20]);
	DDX_Control(pDX, IDC_COMBOBOXEX21, m_value[21]);
	DDX_Control(pDX, IDC_COMBOBOXEX22, m_value[22]);
	DDX_Control(pDX, IDC_COMBOBOXEX23, m_value[23]);
	DDX_Control(pDX, IDC_COMBOBOXEX24, m_value[24]);
	DDX_Control(pDX, IDC_COMBOBOXEX25, m_value[25]);
	DDX_Control(pDX, IDC_COMBOBOXEX26, m_value[26]);
	DDX_Control(pDX, IDC_COMBOBOXEX27, m_value[27]);
	DDX_Control(pDX, IDC_COMBOBOXEX28, m_value[28]);
	DDX_Control(pDX, IDC_COMBOBOXEX29, m_value[29]);
	DDX_Control(pDX, IDC_COMBOBOXEX30, m_value[30]);
	DDX_Control(pDX, IDC_COMBOBOXEX31, m_value[31]);
	DDX_Control(pDX, IDC_COMBOBOXEX32, m_value[32]);
	DDX_Control(pDX, IDC_COMBOBOXEX33, m_value[33]);
	DDX_Control(pDX, IDC_COMBOBOXEX34, m_value[34]);
	DDX_Control(pDX, IDC_COMBOBOXEX35, m_value[35]);
	DDX_Control(pDX, IDC_COMBOBOXEX36, m_value[36]);
	DDX_Control(pDX, IDC_COMBOBOXEX37, m_value[37]);
	DDX_Control(pDX, IDC_COMBOBOXEX38, m_value[38]);
	DDX_Control(pDX, IDC_COMBOBOXEX39, m_value[39]);
	DDX_Control(pDX, IDC_COMBOBOXEX40, m_value[40]);
	DDX_Control(pDX, IDC_COMBOBOXEX41, m_value[41]);
	DDX_Control(pDX, IDC_COMBOBOXEX42, m_value[42]);
	DDX_Control(pDX, IDC_COMBOBOXEX43, m_value[43]);
	DDX_Control(pDX, IDC_COMBOBOXEX44, m_value[44]);
	DDX_Control(pDX, IDC_COMBOBOXEX45, m_value[45]);
	DDX_Control(pDX, IDC_COMBOBOXEX46, m_value[46]);
	DDX_Control(pDX, IDC_COMBOBOXEX47, m_value[47]);
	DDX_Control(pDX, IDC_COMBOBOXEX48, m_value[48]);
	DDX_Control(pDX, IDC_COMBOBOXEX49, m_value[49]);
	DDX_Control(pDX, IDC_COMBOBOXEX50, m_value[50]);
	DDX_Control(pDX, IDC_COMBOBOXEX51, m_value[51]);
	DDX_Control(pDX, IDC_COMBOBOXEX52, m_value[52]);
	DDX_Control(pDX, IDC_COMBOBOXEX53, m_value[53]);
	DDX_Control(pDX, IDC_COMBOBOXEX54, m_value[54]);
	DDX_Control(pDX, IDC_COMBOBOXEX55, m_value[55]);
	DDX_Control(pDX, IDC_COMBOBOXEX56, m_value[56]);
	DDX_Control(pDX, IDC_COMBOBOXEX57, m_value[57]);
	DDX_Control(pDX, IDC_COMBOBOXEX58, m_value[58]);
	DDX_Control(pDX, IDC_COMBOBOXEX59, m_value[59]);
	DDX_Control(pDX, IDC_COMBOBOXEX60, m_value[60]);
	DDX_Control(pDX, IDC_COMBOBOXEX61, m_value[61]);
	DDX_Control(pDX, IDC_COMBOBOXEX62, m_value[62]);


}


BEGIN_MESSAGE_MAP(CScoutEditDlg, CDialog)
	//{{AFX_MSG_MAP(CScoutEditDlg)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX57, OnSelchangeComboboxex57)
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX58, OnSelchangeComboboxex58)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoutEditDlg message handlers

BOOL CScoutEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	myBrush.CreateSolidBrush(DLGCOLOR); 
	m_value[57].SetCurSel(0);
	m_index = 0;
	FillList();
	ReadMember(m_index);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScoutEditDlg::ReadMember(int index)
{
	if(index < 0) index = 0;
	CStaff member = m_member[index];
	m_edit_name = member.m_name;
	m_edit_age = member.m_age;
	UpdateData(FALSE);
	CString te = member.m_team;
	if(te == "") te = "none";
	m_teamname.SetWindowText(te);
	m_value[1].SetCurSel(member.m_pot1[1]- 1);
	m_value[2].SetCurSel(member.m_pot1[2]- 1);
	m_value[3].SetCurSel(member.m_pot1[3]- 1);
	m_value[4].SetCurSel(member.m_pot1[4]- 1);
	m_value[5].SetCurSel(member.m_pot1[5]- 1);

	m_value[6].SetCurSel(member.m_pot2[1]- 1);
	m_value[7].SetCurSel(member.m_pot2[2]- 1);
	m_value[8].SetCurSel(member.m_pot2[3]- 1);
	m_value[9].SetCurSel(member.m_pot2[4]- 1);
	m_value[10].SetCurSel(member.m_pot2[5]- 1);

	m_value[11].SetCurSel(member.m_effort[1]- 1);
	m_value[12].SetCurSel(member.m_effort[2]- 1);
	m_value[13].SetCurSel(member.m_effort[3]- 1);
	m_value[14].SetCurSel(member.m_effort[4]- 1);
	m_value[15].SetCurSel(member.m_effort[5]- 1);

	m_value[16].SetCurSel(member.m_scoring[1]- 1);
	m_value[17].SetCurSel(member.m_scoring[2]- 1);
	m_value[18].SetCurSel(member.m_scoring[3]- 1);
	m_value[19].SetCurSel(member.m_scoring[4]- 1);
	m_value[20].SetCurSel(member.m_scoring[5]- 1);

	m_value[21].SetCurSel(member.m_shooting[1]- 1);
	m_value[22].SetCurSel(member.m_shooting[2]- 1);
	m_value[23].SetCurSel(member.m_shooting[3]- 1);
	m_value[24].SetCurSel(member.m_shooting[4]- 1);
	m_value[25].SetCurSel(member.m_shooting[5]- 1);

	m_value[26].SetCurSel(member.m_rebounding[1]- 1);
	m_value[27].SetCurSel(member.m_rebounding[2]- 1);
	m_value[28].SetCurSel(member.m_rebounding[3]- 1);
	m_value[29].SetCurSel(member.m_rebounding[4]- 1);
	m_value[30].SetCurSel(member.m_rebounding[5]- 1);

	m_value[31].SetCurSel(member.m_passing[1]- 1);
	m_value[32].SetCurSel(member.m_passing[2]- 1);
	m_value[33].SetCurSel(member.m_passing[3]- 1);
	m_value[34].SetCurSel(member.m_passing[4]- 1);
	m_value[35].SetCurSel(member.m_passing[5]- 1);

	m_value[36].SetCurSel(member.m_defense[1]- 1);
	m_value[37].SetCurSel(member.m_defense[2]- 1);
	m_value[38].SetCurSel(member.m_defense[3]- 1);
	m_value[39].SetCurSel(member.m_defense[4]- 1);
	m_value[40].SetCurSel(member.m_defense[5]- 1);

	m_value[41].SetCurSel(member.m_coachPot1- 1);
	m_value[42].SetCurSel(member.m_coachPot2- 1);
	m_value[43].SetCurSel(member.m_coachEffort- 1);
	m_value[44].SetCurSel(member.m_coachScoring- 1);
	m_value[45].SetCurSel(member.m_coachShooting- 1);
	m_value[46].SetCurSel(member.m_coachRebounding- 1);
	m_value[47].SetCurSel(member.m_coachPassing- 1);
	m_value[48].SetCurSel(member.m_coachDefense- 1);

	m_value[49].SetCurSel(member.m_coachO- 1);
	m_value[50].SetCurSel(member.m_coachP- 1);
	m_value[51].SetCurSel(member.m_coachI- 1);
	m_value[52].SetCurSel(member.m_coachF- 1);

	m_value[53].SetCurSel(member.m_coachOD- 1);
	m_value[54].SetCurSel(member.m_coachPD- 1);
	m_value[55].SetCurSel(member.m_coachID- 1);
	m_value[56].SetCurSel(member.m_coachFD- 1);

	m_value[59].SetCurSel(member.m_coachEndurance - 1);
	m_value[60].SetCurSel(member.m_loyalty - 1);
	m_value[61].SetCurSel(member.m_power2 - 1);
	m_value[62].SetCurSel(member.m_personality - 1);

}


void CScoutEditDlg::WriteMember(int index)
{
	if(index < 0) index = 0;
	CStaff member = m_member[index];
	UpdateData(TRUE);
	member.m_name = m_edit_name;
	member.m_age = m_edit_age;
	member.m_pot1[1] = m_value[1].GetCurSel() + 1;
	member.m_pot1[2] = m_value[2].GetCurSel() + 1;
	member.m_pot1[3] = m_value[3].GetCurSel() + 1;
	member.m_pot1[4] = m_value[4].GetCurSel() + 1;
	member.m_pot1[5] = m_value[5].GetCurSel() + 1;

	member.m_pot2[1] = m_value[6].GetCurSel() + 1;
	member.m_pot2[2] = m_value[7].GetCurSel() + 1;
	member.m_pot2[3] = m_value[8].GetCurSel() + 1;
	member.m_pot2[4] = m_value[9].GetCurSel() + 1;
	member.m_pot2[5] = m_value[10].GetCurSel() + 1;

	member.m_effort[1] = m_value[11].GetCurSel() + 1;
	member.m_effort[2] = m_value[12].GetCurSel() + 1;
	member.m_effort[3] = m_value[13].GetCurSel() + 1;
	member.m_effort[4] = m_value[14].GetCurSel() + 1;
	member.m_effort[5] = m_value[15].GetCurSel() + 1;

	member.m_scoring[1] = m_value[16].GetCurSel() + 1;
	member.m_scoring[2] = m_value[17].GetCurSel() + 1;
	member.m_scoring[3] = m_value[18].GetCurSel() + 1;
	member.m_scoring[4] = m_value[19].GetCurSel() + 1;
	member.m_scoring[5] = m_value[20].GetCurSel() + 1;

	member.m_shooting[1] = m_value[21].GetCurSel() + 1;
	member.m_shooting[2] = m_value[22].GetCurSel() + 1;
	member.m_shooting[3] = m_value[23].GetCurSel() + 1;
	member.m_shooting[4] = m_value[24].GetCurSel() + 1;
	member.m_shooting[5] = m_value[25].GetCurSel() + 1;

	member.m_rebounding[1] = m_value[26].GetCurSel() + 1;
	member.m_rebounding[2] = m_value[27].GetCurSel() + 1;
	member.m_rebounding[3] = m_value[28].GetCurSel() + 1;
	member.m_rebounding[4] = m_value[29].GetCurSel() + 1;
	member.m_rebounding[5] = m_value[30].GetCurSel() + 1;

	member.m_passing[1] = m_value[31].GetCurSel() + 1;
	member.m_passing[2] = m_value[32].GetCurSel() + 1;
	member.m_passing[3] = m_value[33].GetCurSel() + 1;
	member.m_passing[4] = m_value[34].GetCurSel() + 1;
	member.m_passing[5] = m_value[35].GetCurSel() + 1;

	member.m_defense[1] = m_value[36].GetCurSel() + 1;
	member.m_defense[2]= m_value[37].GetCurSel() + 1;
	member.m_defense[3]	= m_value[38].GetCurSel() + 1;
	member.m_defense[4] = m_value[39].GetCurSel() + 1;
	member.m_defense[5] = m_value[40].GetCurSel() + 1;

	member.m_coachPot1 = m_value[41].GetCurSel() + 1;
	member.m_coachPot2 = m_value[42].GetCurSel() + 1;
	member.m_coachEffort = m_value[43].GetCurSel() + 1;
	member.m_coachScoring = m_value[44].GetCurSel() + 1;
	member.m_coachShooting = m_value[45].GetCurSel() + 1;
	member.m_coachRebounding = m_value[46].GetCurSel() + 1;
	member.m_coachPassing = m_value[47].GetCurSel() + 1;
	member.m_coachDefense = m_value[48].GetCurSel() + 1;

	member.m_coachO = m_value[49].GetCurSel() + 1;
	member.m_coachP = m_value[50].GetCurSel() + 1;
	member.m_coachI = m_value[51].GetCurSel() + 1;
	member.m_coachF = m_value[52].GetCurSel() + 1;

	member.m_coachOD = m_value[53].GetCurSel() + 1;
	member.m_coachPD = m_value[54].GetCurSel() + 1;
	member.m_coachID = m_value[55].GetCurSel() + 1;
	member.m_coachFD = m_value[56].GetCurSel() + 1;

	member.m_coachEndurance = m_value[59].GetCurSel() + 1;
	member.m_loyalty = m_value[60].GetCurSel() + 1;
	member.m_power2 = m_value[61].GetCurSel() + 1;
	member.m_personality = m_value[62].GetCurSel() + 1;



//	m_value[57].SetCurSel(member.m_coachEndurance - 1);
//	m_value[58].SetCurSel(member.m_loyalty - 1);
//	m_value[59].SetCurSel(member.m_power2 - 1);
//	m_value[60].SetCurSel(member.m_personality - 1);



	m_member[index] = member;

}


void CScoutEditDlg::FillList()
{
	int type = m_value[57].GetCurSel();
	if (type == -1) return;
	m_value[58].ResetContent();
	//m_value[58].SetCurSel(0);
	for(int i=0; i<=99; i++)
	{
		CString str = m_member[i + type*100].m_name;
		if(str == "") continue;
		m_value[58].AddString(str);
	}
	m_value[58].SetCurSel(m_index);
}

void CScoutEditDlg::OnOK() 
{
	// TODO: Add extra validation here
	OnButtonSave();
	CDialog::OnOK();
}

void CScoutEditDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	m_index = m_value[58].GetCurSel();
	int type = m_value[57].GetCurSel();
	int slot = type*100 + m_index;
	WriteMember(slot);
	FillList();
}

void CScoutEditDlg::OnSelchangeComboboxex57() 
{
	// TODO: Add your control notification handler code here
	m_index = m_value[58].GetCurSel();
	int type = m_value[57].GetCurSel();
	int slot = type*100 + m_index;	
	ReadMember(slot);
	FillList();
	
}

void CScoutEditDlg::OnSelchangeComboboxex58() 
{
	// TODO: Add your control notification handler code here
	m_index = m_value[58].GetCurSel();
	int type = m_value[57].GetCurSel();
	int slot = type*100 + m_index;	
	ReadMember(slot);
}



HBRUSH CScoutEditDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

//	case CTLCOLOR_LISTBOX:
//		  //pDC->SetBkMode(TRANSPARENT);
  //        pDC->SetBkColor(LISTBOXCOLOR);
    //      pDC->SetTextColor(LISTBOXTEXTCOLOR);
      //    return myBrush2;
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
