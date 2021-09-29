// MyDraw.h: interface for the CMyDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYDRAW_H__B48ECBC0_AD94_476B_9F8B_752AEB1970EE__INCLUDED_)
#define AFX_MYDRAW_H__B48ECBC0_AD94_476B_9F8B_752AEB1970EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyDraw : public CObject  
{
	public:
	void SetEditableNamesMainView(CString div1, CString div2, CString div3, CString div4, CString con1, CString con2);
	void SetPlayerNameMainView(CString name);
	int m_old_item;
	int GetItemWhereDragLanded(CPoint point, int *valid_items, int items, int item1, int item2, int width, int height);
	int GetHoveredItemWhenDragging(CPoint point, int items, int width, int height);
	BOOL DragAndDropInRange(CRect rect, CPoint point);
	bool PointClicked(int points, int width, int height, int x_clicked, int y_clicked, int &point_clicked);
	CPoint m_points[124];
	CString m_labels[124];
	void SetPointsForCoachView(int items);
	void SetPointsForMainView(int items);
	void SetLabelsForMainView(int items);
	void InitMainView(int items);
	void SetPointsTeamDisplayMainView();
	void SetTeamDisplayControlView();

	CMyDraw();
	virtual ~CMyDraw();
};

#endif // !defined(AFX_MYDRAW_H__B48ECBC0_AD94_476B_9F8B_752AEB1970EE__INCLUDED_)
