#if !defined(AFX_CREATEDLG_H__00C849D4_E7B4_11D0_8C1C_44455354616F__INCLUDED_)
#define AFX_CREATEDLG_H__00C849D4_E7B4_11D0_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define HID_PLAYERS_CREATE 5

// CreateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCreateDlg dialog

//#include "NbaDoc.h"
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 


class CCreateDlg : public CDialog
{
// Construction
public:
	CCreateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateDlg)
	enum { IDD = IDD_CREATEBOX };
	CMyComboBox	m_listTeams;
	CListBox	m_sgrot;
	CListBox	m_sfrot;
	CListBox	m_pgrot;
	CListBox	m_pfrot;
	CListBox	m_crot;
	CListBox	m_listSlot;
	int		m_games;
	CString	m_name;
	int		m_fga;
	int		m_ast;
	int		m_blk;
	int		m_fgm;
	int		m_fta;
	int		m_ftm;
	int		m_min;
	int		m_oreb;
	int		m_pf;
	int		m_reb;
	int		m_stl;
	int		m_tfga;
	int		m_tfgm;
	int		m_to;
	CString	m_current;
	CString	m_pos;
	UINT	m_movdef;
	UINT	m_movoff;
	UINT	m_pendef;
	UINT	m_penoff;
	UINT	m_postdef;
	UINT	m_postoff;
	UINT	m_transdef;
	UINT	m_transoff;
	UINT	m_clutch;
	UINT	m_consistency;
	BOOL	m_active;
	CString	m_leagueName;
	int		m_age;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:		
	CAverage avg;
	bool m_resetDefault;
	CString data[72001];
	double m_factor;
//	bool m_shareware;
	CString m_path;
	CString m_leagueTeamNames[33];

	
protected:

	// Generated message map functions
	//{{AFX_MSG(CCreateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListSlot();
	afx_msg void OnClear();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonCalculate();
	afx_msg void OnCheckActive();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnButtonDefault();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonMiscRatings();
	afx_msg void OnSelchangeComboListTeams();
	afx_msg void OnSetfocusComboListTeams();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ReadMiscRatings();
	bool m_misc_data_changed;//if contract info changed then save contract file
	int facount;
	bool m_calculate;
	BOOL EditValidate();
	CBrush myBrush;
	int m_currentTeam;
	int m_currentSlot;
	int m_hi_id;
	void OnView();
	void OnSave();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDLG_H__00C849D4_E7B4_11D0_8C1C_44455354616F__INCLUDED_)
