#include "stdafx.h"
#ifndef Transactions_h
#include "Transactions.h"
#define Transactions_h
#endif 
//#ifndef Disk_h
//#include "Disk.h"
//#define Disk_h
//#endif 


CTransactions::CTransactions()
{
	m_injury_desc = "";
	m_month = 0;
	m_day = 0;
	m_year = 0;
	m_type = 0;
	m_signing_team = 0;
	m_signing_yr = 0;
	m_signing_sa = 0;
	m_signing_id = 0;
	m_injury_team = 0;
	m_injury_id = 0;
	m_injury_games = 0;


	for(int i=0; i<=5; i++)
	{

		m_team1[i] = 0;
		m_team2[i] = 0;
		m_id[i] = 0;
		m_pick_yr[i] = 0;
		m_pick_rd[i] = 0;
		m_pick_te[i] = 0;	
		m_pic[i] = 0;
	}

}

CTransactions::~CTransactions()
{
}






