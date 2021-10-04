#if !defined(AFX_FREEAGENTDLG_H__9E4DF600_F85E_11D3_A752_444553540000__INCLUDED_)
#define AFX_FREEAGENTDLG_H__9E4DF600_F85E_11D3_A752_444553540000__INCLUDED_

#ifndef Retirement_h
#include "Retirement.h"
#define Retirement_h
#endif 

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef HireStaff_h
#include "HireStaff.h"
#define HireStaff_h
#endif 

#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 


#ifndef ScoutProfileDlg
#include "ScoutProfileDlg.h"
#define ScoutProfileDlg_h
#endif 

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 


#include "MyButton.h"
#include "ProgressDlg1.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_FREEAGENCY 42
// FreeAgentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFreeAgentDlg dialog

class CFreeAgentDlg : public CDialog
{
// Construction


public:
	BOOL m_check_finances_on;
	bool m_free_agency_over;



	int m_cap;

	CAverage avg;

	int m_default_team;
	int m_count;
	int m_number_teams;
	bool m_signing_ok;
	void CalculateCurrentPayroll();
	CString m_path;
	CString m_league_name;

	//CTeamFinancial* m_finance;
	//CRecord* m_record;
	//CHireStaff* m_owner;
	//CStaff* m_scout;
	//CStaff* m_coach;
	//CStaff* m_gm;
	CPlayer* m_copy_actual;

	CString m_control[33];
	
	CString m_league_team_names[33];
	CFreeAgentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFreeAgentDlg)
	enum { IDD = IDD_DIALOG_FREE_AGENCY };
	MyButton	m_button_toggle;
	MyButton	m_button_export;
	MyButton	m_button_import;
	MyButton	m_button_save_fa;
	MyButton	m_radio_free_agents;
	MyButton	m_radio_all_players;
	CMyComboBox	m_list_team_names;
	MyButton	m_button_sort;
	CListBox	m_list_offers;
	CListBox	m_list_cap;
	MyButton	m_cancel;
	MyButton	m_ok;
	CMyComboBox	m_combo_teams;
	CListBox	m_list_signings;
	MyButton	m_button_free_agency_period;
	CListBox	m_list_control;
	MyButton	m_button_offer;
	CMyListCtrl	m_list_free_agents;
	double	m_edit_cap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFreeAgentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFreeAgentDlg)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonOffer();
	afx_msg void OnSelchangeListControl();
	afx_msg void OnButtonFreeAgencyPeriod();
	afx_msg void OnColumnclickListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadioFreeAgents();
	afx_msg void OnRadioAll();
	afx_msg void OnRadioPg();
	afx_msg void OnRadioSf();
	afx_msg void OnRadioSg();
	afx_msg void OnRadioPf();
	afx_msg void OnRadioC();
	afx_msg void OnRadioAllPlayers();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnRadioSignedPlayers();
	afx_msg void OnDblclkListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	virtual void OnOK();
	afx_msg void OnButtonSort();
	virtual void OnCancel();
	afx_msg void OnSelchangeComboListTeamNames();
	afx_msg void OnButtonSaveFa();
	afx_msg void OnClickListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonHtml();
	afx_msg void OnButtonExport();
	afx_msg void OnButtonImport();
	afx_msg void OnSelchangeListOffers();
	afx_msg void OnDblclkListOffers();
	afx_msg void OnRadioUnsignedPlayers();
	afx_msg void OnButtonToggle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ClearOffer(int j, int id);
	void FillOffersList();


	typedef struct OFFERLIST
	{
		int shown_id;//id of players that are actually listed
		int id;		
		int team_index;
		CString offer_string;
	} OFFERLIST;


	int m_offer_list_count;
	OFFERLIST m_offer_list[3001];

	bool m_show_ratings;

	void LoadFaOffers(bool commish);
	CString m_offer_strings[33][16];
	void CreateFaOffersString();
	void SaveOffers(bool commish);

	void BuildString(CString s[], int co, int columns);

	CString m_print_strings[1441][29];
	CString m_column_headers[27];
	void AdjustPlayerRequests();

	//CBitmap bitmapBkgnd;
	int m_players_listed;
	void SaveSignings();
	void ListSignings();
	void Retirements();
	int m_stop_loading;
	
	bool m_resume_save;
	int m_count_signings;
	
	void CreateFaSaveString(int stage, CPlayer m_player);
	CString m_string_load[481];
	bool m_reset_signings;
	bool m_reset_list;
	int m_counter[33];
	bool m_display;
	void ListTeamCap();
	CBrush myBrush;
	CBrush myBrush2;
	void SetSeasonAverages();
	void SetAdjustedRatings();
	int m_player_pointer[1441];
	int m_stage;
	bool SortFunction(CPlayer m_contract_i, CPlayer m_contract_j);
	void QuickSort();

	int m_combo_index;
	int m_pos_category;
	int m_category;
	int m_column;
	int m_list_row;
	void SortColumns();
	void WriteUpdatedContracts();
	void AutoSignRookies();
	int m_league_salary_cap;
	void AdjustSalaryCap(int best_offer, int pl);
	void WriteCampRosters();
	bool EndStage();
	void InitGmOffers();
	void InitPlayerRequests();
	bool m_free_agency_started;
	void InitVariables();
	int m_row;
	void EnableOfferButton();
	void ListControl();
	void SetColumns();
	void SetRatingsHeaders();

	void ListFreeAgents();
	CFont m_font;
	void InitListCtrl();
	void SetCampRosters();
public:
	afx_msg void OnLvnItemchangedListFreeAgents(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FREEAGENTDLG_H__9E4DF600_F85E_11D3_A752_444553540000__INCLUDED_)
