#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#if !defined(AFX_LEAGUETEAMSDLG_H__0A33F601_3EE7_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_LEAGUETEAMSDLG_H__0A33F601_3EE7_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#define HID_LEAGUE_EDIT 8
// LeagueTeamsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamsDlg dialog


#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef Own_h
#include "Own.h"
#define Own_h
#endif 

#include "MyButton.h"



class CLeagueTeamsDlg : public CDialog
{
// Construction
public:
	CLeagueTeamsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeagueTeamsDlg)
	enum { IDD = IDD_EDIT_LEAGUE_TEAMS };
	CMyComboBox	m_comboaddteam;
	CMyComboBox	m_leagueTeamsBox;
	MyButton	m_button_ok;
	CEdit	m_editName;
	MyButton	m_buttonSave;
	MyButton	m_buttonDelete;
	MyButton	m_buttonAdd;
	CListBox	m_rd4;
	CListBox	m_rd3;
	CListBox	m_rd2;
	CListBox	m_rd1;
	CListBox	m_playoff;
	CListBox	m_teamControl;
	CListBox	m_division4;
	CListBox	m_division3;
	CListBox	m_division2;
	CListBox	m_division1;
	CString	m_leagueName;
	CString	m_conferenceName1;
	CString	m_conferenceName2;
	CString	m_divisionName1;
	CString	m_divisionName2;
	CString	m_divisionName3;
	CString	m_divisionName4;
	BOOL	m_computerTrades;
	BOOL	m_checkCareer;
	int		m_editYear;
	CString	m_fra_file_name;
	BOOL	m_check_contracts;
	BOOL	m_check_import_data;
	BOOL	m_check_attributes;
	BOOL	m_check_staffs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeagueTeamsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual BOOL OnInitDialog();

public:
	BOOL m_import_rookies;
	BOOL m_data_imported;
	BOOL m_skip_ages;
	BOOL m_skip_contracts;
	int m_stage;
	COwn m_pick_list;
	CString m_pre_league_team_names[33];
	CAverage avg;
	bool m_expand;
	bool m_data_saved;
	bool m_imported_arena;
	int m_league_style;
	int m_checkInjury;
	int m_teamsInLeague;
	int m_originalNumberOfTeams;
	CString m_originalLeagueName;
	bool m_leagueSaved;
//	bool m_askAboutDraft;
//	bool m_shareware;
	bool m_seasonStarted;
	CPlayer Player[33][31];
	CPlayer* FA;


protected:
	// Generated message map functions
	//{{AFX_MSG(CLeagueTeamsDlg)
	afx_msg void OnButtonAddTeam();
	virtual void OnOK();
	afx_msg void OnButtonDeleteTeam();
	afx_msg void OnSelchangeListLeagueTeams();
	afx_msg void OnSetfocusListLeagueTeams();
	afx_msg void OnSelchangeListControl();
	virtual void OnCancel();
	afx_msg void OnButtonDraft();
	afx_msg void OnDoubleclickedButtonDraft();
	afx_msg void OnDestroy();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnRadioInjnorm();
	afx_msg void OnRadioInjoff();
	afx_msg void OnRadioInjrnd();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSetfocusEditName();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonFranchise();
	afx_msg void OnRadioDraft();
	afx_msg void OnRadioFictional();
	afx_msg void OnRadioExisiting();
	afx_msg void OnButtonAddNew();
	afx_msg void OnButtonAddNew2();
	afx_msg void OnButtonAddNew3();
	afx_msg void OnButtonAddNew4();
	afx_msg void OnSelchangeComboListTeams();
	afx_msg void OnCheckRandomstaffs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetCursors();
	void InitPlayoffStrings(); 
	void ListTeamCount();
	bool m_expansion_occured;
	int m_franchise_slot[33];
	void CallAutoScheduler();
	void FindDivision(CString tm, CString &division, CString &conference);
	void ImportCsvData();
	void UpdateFranchiseFile();
	void SaveOptions();
	CString m_leagueTeam;
	CString m_editableTeamName;
	int facount;
	CString Team[33];
	int m_comboIndex;
	CBrush myBrush;
	CBrush myBrush2;
	bool m_newLeague;
	BOOL CheckForDuplicateLeagueTeam();
	int m_addToDivision;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAGUETEAMSDLG_H__0A33F601_3EE7_11D1_8C1C_44455354616F__INCLUDED_)
