#if !defined(AFX_TRANSACTIONSDLG_H__F2EF9A01_D1AA_11D2_8E70_444553540000__INCLUDED_)
#define AFX_TRANSACTIONSDLG_H__F2EF9A01_D1AA_11D2_8E70_444553540000__INCLUDED_

#ifndef Transactions_h
#include "Transactions.h"
#define Transactions_h
#endif 

//#include "MyListCtrl.h"
//#include "MyButton.h"
//#include "MyComboBox.h"
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#include "PlayerCardDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_LEAGUE_TRANSACTIONS 22

// TransactionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTransactionsDlg dialog

class CTransactionsDlg : public CDialog
{
// Construction
private:
	int m_category;
	CString FindName(int i);
	int m_row;
	void ListTrade(int row, int index);
	void ListSignings(int row, int index);
	void ListFaSignings(int row, int index);
	void ListInjuries(int row, int index);
	int m_number;
	void ListTransactions();
	CFont m_font;
	void InitControls();
	void ReadTrades(int index, CString string);
	void ReadSignings(int index, CString string);
	void ReadFaSignings(int index, CString string);
	void ReadInjuries(int index, CString string);
	CTransactions m_trans_list[4096];
	int m_id_list[4096];
	CBrush myBrush;

public:
	CString m_path;
	CString m_league_name;
	int m_default_team;
	CAverage avg;
	CString m_league_team_names[33];
	int m_current_year;
	CString m_league;
	CTransactionsDlg(CWnd* pParent = NULL);   // standard constructor
	~CTransactionsDlg();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTransactionsDlg)
	enum { IDD = IDD_DIALOG_TRANSACTIONS };
	CMyComboBox	m_list_teams;
	CMyListCtrl	m_listTrades;
	//MyButton m_button[3];
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransactionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTransactionsDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnRadioTrades();
	afx_msg void OnRadioInjuries();
	//afx_msg void OnDblclkListTrades(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDblclkListTrades(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSACTIONSDLG_H__F2EF9A01_D1AA_11D2_8E70_444553540000__INCLUDED_)
