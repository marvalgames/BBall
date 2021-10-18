#if !defined(AFX_ALLSTARDLG_H__DA09A4C1_5110_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_ALLSTARDLG_H__DA09A4C1_5110_11D6_9B5D_444553540000__INCLUDED_


#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef AllStarWeekend_h
#include "AllStarWeekend.h"	// Added by ClassView
#define AllStarWeekend_h
#endif



#include "MyButton.h"
#include "MyListCtrl.h"
#include "afxlistctrl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllStarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllStarDlg dialog

class CAllStarDlg : public CDialog
{
// Construction
public:
	int m_id_list[1441];
	int m_default_team;
	int m_scores[31];
	int m_index[81];//tracks id of people in all star weekend
	CAverage avg;
	
	CAllStarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllStarDlg)
	enum { IDD = IDD_DIALOG_ASW };
	CMyComboBox	m_combo_aswselect;
	CMyListCtrl	m_list_rookies;
	CMyListCtrl	m_list_allstars;
	MyButton	m_button_cancel;
	MyButton	m_button_ok;
	MyButton	m_button_d2;
	MyButton	m_button_d1;
	MyButton	m_button_t3;
	MyButton	m_button_t2;
	MyButton	m_button_t1;
	//}}AFX_DATA

	CStatic	m_name_r[33];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllStarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllStarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonT1();
	afx_msg void OnButtonD1();
	afx_msg void OnButtonD2();
	afx_msg void OnButtonT2();
	afx_msg void OnButtonT3();
	afx_msg void OnDestroy();
	virtual void OnOK();
	afx_msg void OnDblclkListAllstars(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListRookies(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonAllstarselect();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	int m_player_list[61];
	bool m_dunk_finished;
	bool m_three_finished;
	CFont m_font;
	void ListAswRosters();
	void InitCtrl();
	bool m_asw_over;
	void DisplayDunkField();
	CAllStarWeekend *asw;
	void DisplayDunkRound2();
	void DisplayDunkRound1();
	void DisplayThreeField();
	void DisplayThreeRound3();
	void DisplayThreeRound2();
	void DisplayThreeRound1();
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLSTARDLG_H__DA09A4C1_5110_11D6_9B5D_444553540000__INCLUDED_)
