// BBallDoc.h : interface of the CBBallDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BBALLDOC_H__6670D490_047A_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_BBALLDOC_H__6670D490_047A_11D6_9B5D_444553540000__INCLUDED_


#ifndef BBall_h
#include "BBall.h"
#define BBall_h
#endif // Added by ClassView

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef GamePlan_h
#include "GamePlan.h"
#define GamePlan_h
#endif 

#ifndef BBallSettings_h
#include "BBallSettings.h"
#define BBallSettings_h
#endif 

#ifndef BBallSchedule_h
#include "BBallSchedule.h"
#define BBallSchedule_h
#endif 

#ifndef High_h
#include "High.h"
#define High_h
#endif 

#ifndef InjuryTable_h
#include "InjuryTable.h"
#define InjuryTable_h
#endif 

//#include "High.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBBallDoc : public CDocument
{
protected: // create from serialization only
	CBBallDoc();
	DECLARE_DYNCREATE(CBBallDoc)

// Attributes
public:
	int m_coach_visitor_index;
	int m_coach_home_index;//passed to coach game so I know teams
	int m_coach_score[3];//passed by coach games so I know score
	int m_page;
	CString m_bk_color;
	CString	m_text_color;
	CString m_link_color;
	CString m_vlink_color;
	CString m_html_font;



// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBBallDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_shareware;
	bool m_draw_bk;
	void CallAutoScheduler();
	bool m_sim_ok;
	void OffSeasonInjuries();
	void SetTitleBar();
	CInjuryTable m_injury_table[307];
	bool m_default_opened;
	void ResetSeason();
	int ComputerManager();
	CString m_default_league;
	CString m_default_path;
	int m_default_team;
	CString m_original_dir;
	int ProposeTrade();
	int GamePlan();
	void Options();
	bool m_program_started;
	int m_game_type;
	bool m_coached_game_underway;
	CHigh m_recordbook;
	void CreateRandomFiles(CString name_of_league, BOOL random_staff);
	void SaveGameData(CString path , CString league_name);
	void PumpMessages();
	int m_combo_team_index;
	void OpenGameData(CString LeaguePath, CString LeagueName);
	void HealInjury(int days);
	void EditPlayers();
	void EditStaffs();
	void EditCities();

	CAverage avg;

	

//	CGamePlan m_game_plan;

	virtual ~CBBallDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBBallDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfMyButton2();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALLDOC_H__6670D490_047A_11D6_9B5D_444553540000__INCLUDED_)
