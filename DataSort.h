#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 



#ifndef Transactions_h
#include "Transactions.h"
#define Transactions_h
#endif 


class CDataSort: public CObject
{

	
public:
	void SortStandings(CRecord *standing);
	void GetScheduleStrings(CString *list);
	void GetTransactions(CString *string, int type, CTransactions m_trans_list[], int *m_id_list, int *ids);
	void TeamStrengths(int *strong);
	CString m_history_strings[33];
	void FillTeamHistoryStrings();
	int m_starters[6];
	void GetStarters(int team);
	int m_scout_team;
	void SetRatings(int count);
	void SortRookies();
	void SortFA();
	bool SortFunction(CPlayer m_contract_i, CPlayer m_contract_j);
	void QuickSort(int items);

	CAverage avg;

	CDataSort()
	{
		m_scout_team = 0;
		for(int i=0; i<=5; i++)
		{
			m_starters[i] = 0;
		}
		for(int i=0; i<=32; i++)
		{
			m_history_strings[i] = "";
		}

	}
	~CDataSort(){}

	//copy constructor
	CDataSort( const CDataSort& a ) 
	{ 
		m_scout_team = a.m_scout_team;
		for(int i=0; i<=5; i++)
		{
			m_starters[i] = a.m_starters[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_history_strings[i] = a.m_history_strings[i];
		}
	}

	const CDataSort& operator=( const CDataSort& a )
    {
		m_scout_team = a.m_scout_team;
		for(int i=0; i<=5; i++)
		{
			m_starters[i] = a.m_starters[i];
		}
		for(int i=0; i<=32; i++)
		{
			m_history_strings[i] = a.m_history_strings[i];
		}
		return *this;
	}
	
private:


};