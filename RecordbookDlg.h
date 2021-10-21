#if !defined(AFX_RECORDBOOKDLG_H__5F25E283_5138_47F3_8E06_C8D8CFEA1D18__INCLUDED_)
#define AFX_RECORDBOOKDLG_H__5F25E283_5138_47F3_8E06_C8D8CFEA1D18__INCLUDED_


#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#ifndef High_h
#include "High.h"
#define High_h
#endif 

#include "MyListCtrl.h"
#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordbookDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordbookDlg dialog

class CRecordbookDlg : public CDialog
{
// Construction
public:
	bool m_season_leaders;
	CHigh m_recordbook;
	CAverage avg;
	CRecordbookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRecordbookDlg)
	enum { IDD = IDD_DIALOG_RECORDBOOK };
	CMyComboBox	m_combo_teams;
	CMyListCtrl	m_list_records;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordbookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecordbookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnRadioSeason();
	afx_msg void OnRadioCareer();
	afx_msg void OnRadioApg();
	afx_msg void OnRadioSpg();
	afx_msg void OnRadioBpg();
	afx_msg void OnRadioFgp();
	afx_msg void OnRadioFtp();
	afx_msg void OnRadioTgp();
	afx_msg void OnRadioPpg();
	afx_msg void OnRadioRpg();
	afx_msg void OnDblclkListRecords(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FillComboBox(int style);
	void SetHeaders();
	MyButton m_button[11];
	CString m_names_list[51];
	CBrush myBrush; 
	int m_id_list[51];
	int m_category;
	void ListCareerPointsPerGameLeaders();
	void ListCareerReboundsPerGameLeaders();
	void ListCareerAssistsPerGameLeaders();
	void ListCareerStealsPerGameLeaders();
	void ListCareerBlocksPerGameLeaders();
	void ListCareerFieldGoalPctLeaders();
	void ListCareerFreeThrowPctLeaders();
	void ListCareerThreeGoalPctLeaders();
	
	void ListPointsPerGameLeaders();
	void ListReboundsPerGameLeaders();
	void ListAssistsPerGameLeaders();
	void ListStealsPerGameLeaders();
	void ListBlocksPerGameLeaders();
	void ListFieldGoalPctLeaders();
	void ListFreeThrowPctLeaders();
	void ListThreeGoalPctLeaders();
	
	
	CFont m_font;
	void InitControls();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDBOOKDLG_H__5F25E283_5138_47F3_8E06_C8D8CFEA1D18__INCLUDED_)
