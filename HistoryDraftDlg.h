#if !defined(AFX_HISTORYDRAFTDLG_H__F33A7860_242D_11D3_8E70_444553540000__INCLUDED_)
#define AFX_HISTORYDRAFTDLG_H__F33A7860_242D_11D3_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_HISTORY_HALL 35
// HistoryDraftDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryDraftDlg dialog

class CHistoryDraftDlg : public CDialog
{
// Construction
public:
	
	CString m_leagueName;
	CString m_path;
	CHistoryDraftDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryDraftDlg)
	enum { IDD = IDD_DIALOG_HISTORYDRAFTS };
	CMyComboBox	m_listYears;
	CListBox	m_listDraft;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryDraftDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryDraftDlg)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboListTeams();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_exists;
	CBrush myBrush;
	CBrush myBrush2;
	void FillYears();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYDRAFTDLG_H__F33A7860_242D_11D3_8E70_444553540000__INCLUDED_)
