#if !defined(AFX_OPTIONSDLG_H__B6AE43E0_E7B0_11D2_8E70_444553540000__INCLUDED_)
#define AFX_OPTIONSDLG_H__B6AE43E0_E7B0_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define HID_PLAY_OPTIONS 19

#include "MyComboBox.h"
#include "MyButton.h"

// OptionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
private:
	void UpdateButtons();
	bool m_all_player_controlled;
	int m_number_teams;
//	CBrush myBrush;
	CFont m_font;
	CBrush m_brush;
//	CBitmap bitmapBkgnd;

public:
	int m_dead_da;
	int m_dead_mo;
	CString m_original_control[33];
	
	
	int m_default_team;
	
	CBBallSettings m_settings;	
	
	
	
	
	CString m_leagueTeamNames[33];
	CString m_fileName;
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_DIALOG_OPTIONS };
	CMyComboBox	m_listTeams;
	MyButton	m_button_toggle_control;
	MyButton	m_buttons[2];
	CSliderCtrl	m_slider_pace;
	BOOL	m_checkBox;
	BOOL	m_checkPbp;
	BOOL	m_checkOffers;
	BOOL	m_checkScout;
	BOOL	m_checkActual;
	BOOL	m_checkCoach;
	BOOL	m_check3ft;
	BOOL	m_check3pt;
	BOOL	m_checkControl;
	BOOL	m_check_player_gm;
	BOOL	m_checkComputerTrading;
	BOOL	m_check_injury;
	UINT	m_edit_games;
	BOOL	m_ast_gm;
	BOOL	m_check_finances;
	BOOL	m_check_show;
	BOOL	m_check_finances_on;
	BOOL	m_check_free_agency_on;
	double	m_edit_cap;
	BOOL	m_check_deadline;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckBox();
	afx_msg void OnCheckSavepbp();
	afx_msg void OnCheckOffers();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnCheckScout();
	afx_msg void OnCheckActual();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCheck3ft();
	afx_msg void OnCheck3pt();
	afx_msg void OnCheckControl();
	afx_msg void OnCheckGmOn();
	afx_msg void OnCheckTrading();
	afx_msg void OnCheckInj();
	afx_msg void OnCheckAsstGm();
	afx_msg void OnCheckFinances();
	afx_msg void OnCheckShow();
	afx_msg void OnCheckFinancesOn();
	afx_msg void OnCheckFreeAgencyOn();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnButtonHelp();
	afx_msg void OnButtonSwitchAll();
	afx_msg void OnCheckDeadline();
	afx_msg void OnPaint();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnCheckCoaches();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDLG_H__B6AE43E0_E7B0_11D2_8E70_444553540000__INCLUDED_)
