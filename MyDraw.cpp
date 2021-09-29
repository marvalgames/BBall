// MyDraw.cpp: implementation of the CMyDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bball.h"
#include "MyDraw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyDraw::CMyDraw()
{
	for(int i=0; i<=64; i++)
	{
		m_points[i].x = 0;
		m_points[i].y = 0;
	}

	m_old_item = 0;
}

CMyDraw::~CMyDraw()
{

}


void CMyDraw::InitMainView(int items)
{
	SetPointsForMainView(items);
	SetLabelsForMainView(items);

}

void CMyDraw::SetPointsForMainView(int items)
{
	m_points[1].x = 250;
	m_points[1].y = 50;
	m_points[2].x = 250;
	m_points[2].y = 75;
	m_points[3].x = 250;
	m_points[3].y = 100;
	m_points[4].x = 275;
	m_points[4].y = 325;

}

void CMyDraw::SetPointsTeamDisplayMainView()
{
//points  5 to 36 to show 32 teams?
int offset = 4;


for(int d=1; d<=4; d++)
{
	for(int x=1; x<=8; x++)
	{
		offset = offset + 1;
		m_points[offset].x = 325 + (d-1)*130;
		m_points[offset].y = 460+x*20;
	}
}

}

void CMyDraw::SetLabelsForMainView(int items)
{
//	m_labels[1] = "Player Name";
//	m_labels[2] = "League Name";
//	m_labels[3] = "Choose Your Team";
//	m_labels[4] = "Star Player";

}


void CMyDraw::SetPointsForCoachView(int items)
{
	//vis roster	
	m_points[1].x = 20;
	m_points[1].y = 240;
	m_points[2].x = 20;
	m_points[2].y = 255;
	m_points[3].x = 20;
	m_points[3].y = 270;
	m_points[4].x = 20;
	m_points[4].y = 285;

	m_points[5].x = 20;
	m_points[5].y = 300;
	m_points[6].x = 20;
	m_points[6].y = 315;
	m_points[7].x = 20;
	m_points[7].y = 330;
	m_points[8].x = 20;
	m_points[8].y = 345;

	m_points[9].x = 20;
	m_points[9].y = 360;
	m_points[10].x = 20;
	m_points[10].y = 375;
	m_points[11].x = 20;
	m_points[11].y = 390;
	m_points[12].x = 20;
	m_points[12].y = 405;



	//home roster

	m_points[13].x = 320;
	m_points[13].y = 240;
	m_points[14].x = 320;
	m_points[14].y = 255;
	m_points[15].x = 320;
	m_points[15].y = 270;
	m_points[16].x = 320;
	m_points[16].y = 285;

	m_points[17].x = 320;
	m_points[17].y = 300;
	m_points[18].x = 320;
	m_points[18].y = 315;
	m_points[19].x = 320;
	m_points[19].y = 330;
	m_points[20].x = 320;
	m_points[20].y = 345;

	m_points[21].x = 320;
	m_points[21].y = 360;
	m_points[22].x = 320;
	m_points[22].y = 375;
	m_points[23].x = 320;
	m_points[23].y = 390;
	m_points[24].x = 320;
	m_points[24].y = 405;


	//float rows[] = {0, 550, 550, 550, 550, 550};
	//float cols[] = {0, 20, 120, 220, 320, 420};	
	
	//matchup pg
	m_points[25].x = 20;
	m_points[25].y = 550;

	m_points[26].x = 20;
	m_points[26].y = 600;

	//matchup sg
	m_points[27].x = 120;
	m_points[27].y = 550;

	m_points[28].x = 120;
	m_points[28].y = 600;


	//matchup sf
	m_points[29].x = 220;
	m_points[29].y = 550;


	m_points[30].x = 220;
	m_points[30].y = 600;


	//matchup pf
	m_points[31].x = 320;
	m_points[31].y = 550;


	m_points[32].x = 320;
	m_points[32].y = 600;


	//matchup c
	m_points[33].x = 420;
	m_points[33].y = 550;


	m_points[34].x = 420;
	m_points[34].y = 600;

	//vis starters

	m_points[35].x = 20;
	m_points[35].y = 450;

	m_points[36].x = 20;
	m_points[36].y = 465;

	m_points[37].x = 20;
	m_points[37].y = 480;

	m_points[38].x = 20;
	m_points[38].y = 495;

	m_points[39].x = 20;
	m_points[39].y = 510;

	//home starters
	m_points[40].x = 320;
	m_points[40].y = 450;

	m_points[41].x = 320;
	m_points[41].y = 465;

	m_points[42].x = 320;
	m_points[42].y = 480;

	m_points[43].x = 320;
	m_points[43].y = 495;

	m_points[44].x = 320;
	m_points[44].y = 510;

}


bool CMyDraw::PointClicked(int points, int width, int height, int x_clicked, int y_clicked, int &point_clicked)
{
	bool clicked = false;
	for(int i=1; i<= points; i++)
	{
		if(x_clicked >= m_points[i].x && x_clicked <= (m_points[i].x + width)
			&& y_clicked >= m_points[i].y && y_clicked <= (m_points[i].y + height))		
		{
			clicked = true;
			point_clicked = i;
		}
	}
	return clicked;

}


BOOL CMyDraw::DragAndDropInRange(CRect rect, CPoint point)
{
	return rect.PtInRect(point); 

}

int CMyDraw::GetItemWhereDragLanded(CPoint point, int *valid_items, int items, int item1, int item2, int width, int height)
{
	int item = 0;
	int x_clicked = point.x;
	int y_clicked = point.y;
	for(int i=item1; i<= item2; i++)
	{

		for(int j=1; j<= items; j++)
		{

		if(x_clicked >= m_points[i].x && x_clicked <= (m_points[i].x + width)
			&& y_clicked >= m_points[i].y && y_clicked <= (m_points[i].y + height) &&
			valid_items[j] == i)		
		{
			item = i;
		}
		}
	}

	return item;

}

int CMyDraw::GetHoveredItemWhenDragging(CPoint point, int items, int width, int height)
{
	int item = 0;
	int x_clicked = point.x;
	int y_clicked = point.y;
	for(int i=1; i<= items; i++)
	{


		if(x_clicked >= m_points[i].x && x_clicked <= (m_points[i].x + width)
			&& y_clicked >= m_points[i].y && y_clicked <= (m_points[i].y + height))		
		{
			item = i;
		}
	}
	return item;




}

void CMyDraw::SetPlayerNameMainView(CString name)
{

	m_points[37].x = 535;
	m_points[37].y = 335;
	m_labels[37] = name;
}

void CMyDraw::SetEditableNamesMainView(CString div1, CString div2, CString div3, CString div4, CString con1, CString con2)
{
	m_points[38].x = 325;//col
	m_points[38].y = 460;
	m_labels[38] = div1;

	m_points[39].x = 455;//col
	m_points[39].y = 460;
	m_labels[39] = div2;

	m_points[40].x = 585;//col
	m_points[40].y = 460;
	m_labels[40] = div3;

	m_points[41].x = 715;//col
	m_points[41].y = 460;
	m_labels[41] = div4;

	m_points[42].x = 360;//col
	m_points[42].y = 435;
	m_labels[42] = con1;

	m_points[43].x = 620;//col
	m_points[43].y = 435;
	m_labels[43] = con2;

}

void CMyDraw::SetTeamDisplayControlView()
{
	for(int i=0; i<=15; i++)
	{
		m_points[44+i].x = 75;
		m_points[44+i].y = 100+i*32;
	}
	for(int i=16; i<=31; i++)
	{
		m_points[44+i].x = 375;
		m_points[44+i].y = 100+(i-16)*32;
	}

		m_points[44+32].x = 775;
		m_points[44+32].y = 100;
}
