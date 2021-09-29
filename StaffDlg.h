#if !defined(AFX_STAFFDLG_H__4F3BA140_6757_11D3_8E70_AE21E9FED56A__INCLUDED_)
#define AFX_STAFFDLG_H__4F3BA140_6757_11D3_8E70_AE21E9FED56A__INCLUDED_
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef HireStaff_h
#include "HireStaff.h"
#define HireStaff_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 


#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 


#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 

#include "MyButton.h"

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_CAREER_STAFF 38


// StaffDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaffDlg dialog

class CStaffDlg : public CDialog
{
// Construction
public:
	void PassMembers();
	CAverage avg;
	int m_default_team;
//	bool m_scouts_on;
	CRecord m_record[33];
	bool m_hiring_ok;
//	CHireStaff m_standing;
	CRecord m_standings[33];
	CString m_control[33];
	CStaff m_scout[101];
	CStaff m_coach[101];
	CStaff m_gm[101];
	CHireStaff m_owner[101];
	CStaff m_scoutCopy[101];
	CStaff m_coachCopy[101];
	CStaff m_gmCopy[101];	
	CString m_leagueTeamNames[33];
	//CString m_leagueName;
	//CString m_path;
	CCareer *names;
	CStaffDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStaffDlg)
	enum { IDD = IDD_DIALOG_STAFF };
	MyButton	m_radioScout;
	MyButton	m_radioCoachScout;
	MyButton	m_radioCoachGame;
	MyButton	m_button_cancel;
	CMyComboBox	m_listTeams;
	MyButton	m_buttonOK;
	MyButton	m_buttonEnd;
	CListBox	m_lisFirings;
	MyButton	m_buttonFirings;
	CListBox	m_listAccept;
	CListBox	m_listOffers;
	MyButton	m_buttonOffer;
	CListBox	m_listControl;
	CListCtrl	m_listCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaffDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStaffDlg)
	afx_msg void OnSelchangeListControl();
	afx_msg void OnRadioCoach();
	afx_msg void OnRadioGm();
	afx_msg void OnRadioScout();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnColumnclickListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonOffer();
	afx_msg void OnButtonFirings();
	afx_msg void OnButtonEnd();
	afx_msg void OnClickListCtrlStaff(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadioCoachScout();
	afx_msg void OnRadioCoachGame();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeComboStaffTeams();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_set_cursor;
	void SetCursorPosition(int category);
	int m_row;
	bool m_changeHeading;
	void DeleteColumns();
	void CoachColumns();
	void StaffColumns();
	void ListGameCoach();
	void SortCoach();
	void SetGameCoachListCtrl();
	int m_coachCategory;
	void OrderList();
	void EnableOfferButton();
	bool m_firingsCompleted;
	void ChooseJob();
	void GetTopCandidate();
	void Firings();
	void ListOffers();
	int m_numberTeams;
	void SetInterest();
	void ListControl();
	CBrush myBrush;
	CBrush myBrush2;
	int m_category;
	int m_column;
	void SortStaff();
	void SetVariables();
	void InitListCtrl();
	void ListCoach();
	void ListGM();
	void ListScout();
	CFont m_font;
	void SetGmListCtrl();
	void SetCoachListCtrl();
	void SetScoutListCtrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAFFDLG_H__4F3BA140_6757_11D3_8E70_AE21E9FED56A__INCLUDED_)
