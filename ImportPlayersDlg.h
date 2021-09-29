#if !defined(AFX_IMPORTPLAYERSDLG_H__2F25B140_786F_11D5_93C6_00E098785609__INCLUDED_)
#define AFX_IMPORTPLAYERSDLG_H__2F25B140_786F_11D5_93C6_00E098785609__INCLUDED_

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImportPlayersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImportPlayersDlg dialog

class CImportPlayersDlg : public CDialog
{
// Construction
public:
	BOOL m_check_ages;
	BOOL m_check_contracts;
	int m_current_yr;
	CString m_league_team_names[33];
	bool m_data_imported;
	CAverage avg;
	CString m_path;
	CString m_league_name;
	int m_league_style;
	CImportPlayersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImportPlayersDlg)
	enum { IDD = IDD_DIALOG_IMPORT_PLAYERS };
	MyButton	m_button_import;
	CMyComboBox	m_combo_team_names;
	CString	m_edit_nick_name;
	BOOL	m_check_rookies;//used for big file instead of rookies now
	BOOL	m_check_swap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImportPlayersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImportPlayersDlg)
	afx_msg void OnButtonImport();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboTeamNames();
	afx_msg void OnButtonChange();
	afx_msg void OnRadioNone();
	afx_msg void OnRadioContracts();
	afx_msg void OnRadioAges();
	virtual void OnOK();
	afx_msg void OnCheckRookies();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush; 	
	int m_button_state;
	void FillEditBox();
	CString m_names_list[33];
	bool ReadPlayersSpreadSheet(CString m_full_path, int &players_loaded);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMPORTPLAYERSDLG_H__2F25B140_786F_11D5_93C6_00E098785609__INCLUDED_)
