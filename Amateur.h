// Amateur.h: interface for the CAmateur class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMATEUR_H__1A5CFB45_7C06_4C21_97B9_E7CB53BCD6DD__INCLUDED_)
#define AFX_AMATEUR_H__1A5CFB45_7C06_4C21_97B9_E7CB53BCD6DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "Player.h"
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

class CAmateur : public CObject  
{
public:
	void ScoutRookies400Bureau(CStaff scout, CPlayer *actual);
	void CreateRookies(CString *fname, CString *lname, CPlayer *actual, int hi_g);
	void ReadNames(CString f_file_name, CString l_file_name, CString *fname, CString *lname);
	CAmateur();
	virtual ~CAmateur();



	int IntRandom(int n)
	{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return (int)number + 1;
	}



	int Random(int n)
	{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return (int)number + 1;
	}

	double Random(double n)
	{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
	}


};

#endif // !defined(AFX_AMATEUR_H__1A5CFB45_7C06_4C21_97B9_E7CB53BCD6DD__INCLUDED_)
