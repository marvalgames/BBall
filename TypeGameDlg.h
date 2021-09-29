#if !defined(AFX_TYPEGAMEDLG_H__D246B402_4D26_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_TYPEGAMEDLG_H__D246B402_4D26_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//#define HIDD_EXHIBITION_GAME 1
//#define HIDD_LEAGUE 2
//#define HIDD_TEAM_GAME 3
#define HID_PLAY_TYPE 1

// TypeGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTypeGameDlg dialog

class CTypeGameDlg : public CDialog
{
// Construction
private:
	CBrush myBrush;


public:
	int m_default_team;
	CString m_team_names[33];

	int m_exhteam1;
	int m_exhteam2;
	int m_singleteam;


	CString m_home;
	CString m_visitor;
	CString m_path;
//	int m_auto_speed;
	int m_gameType;
	CTypeGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTypeGameDlg)
	enum { IDD = IDD_TYPEBOX };
	CMyComboBox	m_combo_singleteam;
	CMyComboBox	m_combo_exhteam2;
	CMyComboBox	m_combo_exhteam1;
	CSliderCtrl	m_slider_speed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTypeGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLeague();
	afx_msg void OnExhibitionGame();
	afx_msg void OnTeamGame();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboSingleteam();
	afx_msg void OnSelchangeComboExhteam1();
	afx_msg void OnSelchangeComboExhteam2();
	virtual void OnOK();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TYPEGAMEDLG_H__D246B402_4D26_11D1_8C1C_44455354616F__INCLUDED_)
