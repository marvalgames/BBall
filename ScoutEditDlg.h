#if !defined(AFX_SCOUTEDITDLG_H__082CB6F9_F881_4A5B_8E7C_4B4629AC8412__INCLUDED_)
#define AFX_SCOUTEDITDLG_H__082CB6F9_F881_4A5B_8E7C_4B4629AC8412__INCLUDED_

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif
#include "MyComboBox.h"
#include "MyButton.h"
#include "afxbutton.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoutEditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoutEditDlg dialog

class CScoutEditDlg : public CDialog
{
// Construction
public:
	int m_index;
	CStaff m_member[301];
	CScoutEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScoutEditDlg)
	enum { IDD = IDD_DIALOG_STAFFEDITOR };
	CStatic	m_teamname;
	CString	m_edit_name;
	UINT	m_edit_age;
	//}}AFX_DATA

	CComboBoxEx	m_value[101];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoutEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoutEditDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSave();
	afx_msg void OnSelchangeJobs();
	afx_msg void OnSelchangeMembers();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	void ReadMember(int index);
	void WriteMember(int index);
	void FillList();
public:
	afx_msg void OnStnClickedStatic6();
//	afx_msg void OnStnClickedStatic38();
	afx_msg void OnBnClickedOk();
private:
//	CMFCFontComboBox m_comboStaffList;
public:
	CComboBox m_comboStaffList;
	CComboBox m_comboJobsList;
	MyButton m_okBtn;
	MyButton m_cancelBtn;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOUTEDITDLG_H__082CB6F9_F881_4A5B_8E7C_4B4629AC8412__INCLUDED_)
