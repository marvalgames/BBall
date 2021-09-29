#if !defined(AFX_EDITDLG_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_)
#define AFX_EDITDLG_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



// EditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditRatings dialog

class CEditDlg : public CDialog
{
// Construction
public:
	int m_default_team;
	bool m_rookie_edit;
	int m_posindex;
	int m_teamindex;
//	CPlayer m_player[581];
	CAverage avg;
	CPlayer m_actual;
	CEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditRatings)
	enum { IDD = IDD_DIALOG_PLAYER_EDIT };
	CListCtrl	m_listAvg;
	CMyComboBox	m_combo_pos;
	CMyComboBox	m_combo_comp;
	CMyComboBox	m_combo_team;
	CMyComboBox	m_comboteams;
	CMyComboBox	m_combopos;
	CMyComboBox   m_combo_durability;
	CMyComboBox   m_combo_current_contract_year;
	int	m_edit_3ga;
	int	m_edit_tgp;
	int	m_edit_ast;
	int	m_edit_blk;
	int	m_edit_drb;
	int	m_edit_fta;
	int	m_edit_ftp;
	CString	m_edit_name;
	int	m_edit_orb;
	int	m_edit_fga;
	int	m_edit_fgp;
	int	m_edit_stl;
	int	m_edit_to;
	int	m_edit_min;
	int	m_edit_g;
	int	m_edit_age;
	int	m_edit_ht;
	int	m_edit_wt;
	int	m_edit_clutch;
	int	m_edit_consistency;
	int	m_edit_f;
	int	m_edit_fd;
	int	m_edit_i;
	int	m_edit_id;
	int	m_edit_o;
	int	m_edit_od;
	int	m_edit_p;
	int	m_edit_pd;
	int	m_edit_1;
	int	m_edit_2;
	int	m_edit_3;
	int	m_edit_4;
	int	m_edit_5;
	int	m_edit_6;
	int	m_edit_7;
	int	m_edit_8;
	int	m_edit_9;
	int	m_edit_10;
	int	m_edit_11;
	int	m_edit_12;
	int	m_edit_13;
	int	m_edit_14;
	int m_edit_pot1;
	int m_edit_pot2;
	int m_edit_effort;
	int m_edit_athlete;
	int m_edityearspro;
	int m_edityearsteam;
	int m_edityear1;
	int m_edityear2;
	int m_edityear3;
	int m_edityear4;
	int m_edityear5;
	int m_edityear6;
	int m_editcoach;
	int m_editloyalty;
	int m_editpt;
	int m_editsecurity;
	int m_edittradition;
	int m_editwinning;
	CListBox m_sgrot;
	CListBox m_sfrot;
	CListBox m_pgrot;
	CListBox m_pfrot;
	CListBox m_crot;
	CListBox m_listSlot;
	BOOL m_active;
	CStatic m_static1;
	CStatic m_static2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonAvg();
	afx_msg void OnSelchangeComboPos();
	afx_msg void OnButtonCalculate();
	afx_msg void OnChangeEditScoring();
	afx_msg void OnKillfocusEditScoring();
	afx_msg void OnKillfocusEdit3ptScoring();
	afx_msg void OnKillfocusEdit3ptShooting();
	afx_msg void OnKillfocusEditAge();
	afx_msg void OnKillfocusEditHt();
	afx_msg void OnKillfocusEditWt();
	afx_msg void OnKillfocusEditAst();
	afx_msg void OnKillfocusEditBlk();
	afx_msg void OnKillfocusEditClutch();
	afx_msg void OnKillfocusEditConsistency();
	afx_msg void OnKillfocusEditDrb();
	afx_msg void OnKillfocusEditEffort();
	afx_msg void OnKillfocusEditF();
	afx_msg void OnKillfocusEditFd();
	afx_msg void OnKillfocusEditFtScoring();
	afx_msg void OnKillfocusEditFtShooting();
	afx_msg void OnKillfocusEditG();
	afx_msg void OnKillfocusEditI();
	afx_msg void OnKillfocusEditId();
	afx_msg void OnKillfocusEditMin();
	afx_msg void OnKillfocusEditName();
	afx_msg void OnKillfocusEditO();
	afx_msg void OnKillfocusEditOd();
	afx_msg void OnKillfocusEditOrb();
	afx_msg void OnKillfocusEditP();
	afx_msg void OnKillfocusEditPd();
	afx_msg void OnKillfocusEditPot1();
	afx_msg void OnKillfocusEditPot2();
	afx_msg void OnKillfocusEditShooting();
	afx_msg void OnKillfocusEditStl();
	afx_msg void OnKillfocusEditTo();
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnKillfocusEdit10();
	afx_msg void OnKillfocusEdit11();
	afx_msg void OnKillfocusEdit12();
	afx_msg void OnKillfocusEdit13();
	afx_msg void OnKillfocusEdit14();
	afx_msg void OnKillfocusEdit2();
	afx_msg void OnKillfocusEdit3();
	afx_msg void OnKillfocusEdit4();
	afx_msg void OnKillfocusEdit5();
	afx_msg void OnKillfocusEdit6();
	afx_msg void OnKillfocusEdit7();
	afx_msg void OnKillfocusEdit8();
	afx_msg void OnKillfocusEdit9();
	afx_msg void OnButtonAdjust();
	afx_msg void OnSelchangeComboteams();
	afx_msg void OnSelchangeCombopos();
	afx_msg void OnCheckActive();
	afx_msg void OnButtonCalculateRatings();
	afx_msg void OnButtonCalculateStats();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush; 
	CBrush myBrush2; 
	int m_id_count;
	void WriteID();
	void FillSlotsWithPlayerNames();
	void SavePlayer();
	void SetStatsAdjComp();
	void Initialize();
	void SetStats();
	void GetPlayerPosition();
	void SetEditVariables();
	void SetRatings();
	void SetPlayerToAverage();
	void InitCtrl();
	void SetEditedRatings();
	int m_po;
	void InitVariables();
	
	void SetAverages();
	void SetPlayerRatings();
	void DisplayRatings();
	int Round(double number)
	{
		double diff = number - int(number);
		int integer = 0;
		if(diff > .5)
			integer = int(number + 1);
		else
			integer = int(number);
		return integer;
	}

	int orig_g;
	int orig_min;

	int orig_fga;
	int orig_fgp;

	int orig_fta;
	int orig_ftp;

	int orig_tga;
	int orig_tgp;

	int orig_orb;
	int orig_drb;

	int orig_ast;
	int orig_stl;
	int orig_to; 
	int orig_blk;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_)







