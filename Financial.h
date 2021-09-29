#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 

#ifndef Future_h
#include "Future.h"
#define Future_h
#endif 

class CFinancial: public CObject
{

	
public:
	int m_number_teams;
	void GenerateComputerProposals(CString control[33]);

	CString m_path;
	CString m_league_name;
	CTeamFinancial m_finance[101];
	CFuture m_future[101];



	CFinancial()
	{
	}
	~CFinancial(){}

	//copy constructor
	CFinancial( const CFinancial& a ) 
	{ 
	}

	const CFinancial& operator=( const CFinancial& a )
    {
	}
	
private:
	//int Random(int n);
	double Random(double n);
	int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}

};