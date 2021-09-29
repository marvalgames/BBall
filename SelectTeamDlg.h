#if !defined(AFX_SELECTTEAMDLG_H__AB0D0481_4DED_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_SELECTTEAMDLG_H__AB0D0481_4DED_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SelectTeamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectTeamDlg dialog

class CSelectTeamDlg : public CDialog
{
// Construction
public:
	CString m_listTeam;
	CString m_leagueTeamNames[33];
	CString m_path;
	CString m_leagueName;
	CSelectTeamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectTeamDlg)
	enum { IDD = IDD_SELECT_TEAM_BOX };
	CMyComboBox	m_list_team;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectTeamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectTeamDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTTEAMDLG_H__AB0D0481_4DED_11D1_8C1C_44455354616F__INCLUDED_)
