#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGamePlan : public CObject
{
public:
//	void ComputerAdjustsGamePlan(CString control[33]);
	void CreateDataForSavingGamePlans();
	CString m_save_plan[65];
	void InitGamePlans(CString plan_file_name);
	CAverage avg;
	
	CGamePlan();
	void GenerateGamePlans();
	virtual ~CGamePlan();


	const CGamePlan& operator=( const CGamePlan& a )
    {
		for(int i=0; i<=64; i++)
		{
			m_save_plan[i] = a.m_save_plan[i];
		}
		return *this;

	}
private:
	void ReadGamePlan(CString file_name);
};

