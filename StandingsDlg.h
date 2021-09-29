#if !defined(AFX_STANDINGSDLG_H__566CC321_7845_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_STANDINGSDLG_H__566CC321_7845_11D1_8C1C_44455354616F__INCLUDED_

#ifndef Record_h
#include "Record.h"
#define Record_h
#endif // Added by ClassView

#ifndef MyListCtrl_h
#include "MyListCtrl.h"
#define MyListCtrl_h
#endif // Added by ClassView

//#ifndef Record_h
#include "LeagueTeamSchedule.h"
#include "ShadeButtonST.h"
#include "Label.h"

#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif

//#define Record_h
//#endif // Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define HID_LEAGUE_STANDINGS 10
// StandingsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStandingsDlg dialog

class CStandingsDlg : public CDialog
{
// Construction
public:
	int m_current_year;
	int m_default_team;
	CString m_leagueName;
	int m_teamsInLeague;
	CString m_path;
	CStandingsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStandingsDlg)
	enum { IDD = IDD_STANDINGSBOX };
	CLabel	m_monty2;
	CLabel	m_monty1;
	CLabel	m_monty;
	CButton	m_button_ok;
	CButton	m_button_print;
	CMyListCtrl	m_listVsOpponents;
	CMyListCtrl	m_listTeams;
	CListBox	m_listChoices;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStandingsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStandingsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListChoices();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnButtonPrint();
	afx_msg void OnDblclkListChoices();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void HighlightRow();
	int m_selection_row;
	CString m_strings[33];
	void SelectChange();
	CFont m_font;
	void InitControls();

	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
	CString m_playoffFormat;
	CString m_rd1Format;
	CString m_rd2Format;
	CString m_rd3Format;
	CString m_rd4Format;
	CString m_conferenceName1;
	CString m_conferenceName2;
	CString m_divisionName1;
	CString m_divisionName2;
	CString m_divisionName3;
	CString m_divisionName4;
	int m_gameScore[13][32][17];
	int m_schedule[13][32][17];
	CBrush myBrush;
	CString m_initialLeagueTeamNames[33];
	CString	m_initialCityNames[33];

CBitmap bitmapBkgnd;

public:
	CAverage avg;
	//change to structure later
	struct RECORD
	{
		CString m_leagueTeamNames;
		CString m_control;
		CString m_conference;
		CString m_division;
		CString m_city_name;
		int m_leagueRecord;
		int m_divisionRecord;
		int m_conferenceRecord;
		int m_homeRecord;
		int m_visitorRecord;
		double m_leaguePct;
		double m_divisionPct;
		double m_conferencePct;
		int m_leagueGamesBack;
		int m_vsOpponent[33];
		int m_initialNumber;
		double m_vsOpponentPct[33];
	};
	RECORD record[34];

	private:
		
	
	CStatic m_static;




};


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STANDINGSDLG_H__566CC321_7845_11D1_8C1C_44455354616F__INCLUDED_)
