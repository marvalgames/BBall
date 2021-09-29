#if !defined(AFX_EDITRATINGS_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_)
#define AFX_EDITRATINGS_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef XListCtrl_h
#include "XListCtrl.h"
#define XListCtrl_h
#endif 


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_PLAYERS_EDITRATINGS 41


// EditRatings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditRatings dialog

class CEditRatings : public CDialog
{
// Construction
public:
//	CPlayer m_player[581];
	CAverage avg;
	CPlayer m_actual;
	CEditRatings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditRatings)
	enum { IDD = IDD_DIALOG_EDIT_RATINGS };
	CListCtrl	m_listAvg;
	CMyComboBox	m_combo_pos;//myc
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
	int		m_edit_min;
	int		m_edit_g;
	int		m_edit_age;
	int		m_edit_clutch;
	int		m_edit_consistency;
	int		m_edit_f;
	int		m_edit_fd;
	int		m_edit_i;
	int		m_edit_id;
	int		m_edit_o;
	int		m_edit_od;
	int		m_edit_p;
	int		m_edit_pd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditRatings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditRatings)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonAvg();
	afx_msg void OnSelchangeComboPos();
	afx_msg void OnButtonCalculate();
	afx_msg void OnButtonCalculateRatings();
	afx_msg void OnButtonCalculateTotals();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
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

#endif // !defined(AFX_EDITRATINGS_H__4A081B40_967D_11D3_8E70_444553540000__INCLUDED_)
