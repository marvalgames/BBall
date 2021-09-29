//#ifndef Contract_h
//#include "Contract.h"
//#define Contract_h
//#endif 


class COwn: public CObject
{

	
public:
	void SetEndOfSeasonDraftChart();
	int SetDraftPickAddition(int index, double avg_tru, double team_avg_tru, int *win, int *loss, double* pct, int hi_g);
//	void SetDraftChart(int trading_team);
	int m_number_proposed_picks;
	int m_number_actual_picks;
	int m_salary_in_trade;
	int m_total_salary_in_trade;
	double m_total_true_in_trade;
	int m_total_years_in_trade;
//	int m_salary_in_trade;
	int m_proposed_picks[8];
	int m_actual_picks[193];
	int m_number_picks_year[4];
	int m_number_proposed_picks_year[4];
	double m_draft_pick_addition;
	void ReadOwnData(CString file_name, int numberteams);
	void WriteOwnData(CString file_name);
	void InitOwnData();
	int m_draft_chart[4][3][33];

	COwn()
	{
		m_number_proposed_picks = 0;
		m_number_actual_picks = 0;
		m_salary_in_trade = 0;
		m_total_salary_in_trade = 0;
		m_total_true_in_trade = 0;
		m_total_years_in_trade = 0;

		for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					m_draft_chart[y][r][p] = p;
				}
			}
		}


		for(int n=0; n<=7; n++)
		{
			m_proposed_picks[n] = 0;
		}
		for(int n=0; n<=192; n++)
		{
			m_actual_picks[n] = 0;
		}
		for(int n=0; n<=3; n++)
		{
			m_number_picks_year[n] = 0;
			m_number_proposed_picks_year[n] = 0;
		}
		m_draft_pick_addition = 0;
	}
	~COwn(){}

	//copy constructor
	COwn( const COwn& a ) 
	{ 
	for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					m_draft_chart[y][r][p] = a.m_draft_chart[y][r][p];
				}
			}
		}

		m_number_proposed_picks = a.m_number_proposed_picks;
		m_number_actual_picks = a.m_number_actual_picks;
		m_salary_in_trade = a.m_salary_in_trade;
		m_total_salary_in_trade = a.m_total_salary_in_trade;
		m_total_true_in_trade = a.m_total_true_in_trade;
		m_total_years_in_trade = a.m_total_years_in_trade;

		for(int n=0; n<=7; n++)
		{
			m_proposed_picks[n] = a.m_proposed_picks[n];
		}

		for(int n=0; n<=192; n++)
		{
			m_actual_picks[n] = a.m_actual_picks[n];
		}
		for(int n=0; n<=3; n++)
		{
			m_number_picks_year[n] = a.m_number_picks_year[n];
			m_number_proposed_picks_year[n] = a.m_number_proposed_picks_year[n];
		}

		m_draft_pick_addition = a.m_draft_pick_addition;
		



	}

	const COwn& operator=( const COwn& a )
    {
	for(int y=0; y<=3; y++)
		{
			for(int r=0; r<=2; r++)
			{
				for(int p=0; p<=32; p++)
				{
					m_draft_chart[y][r][p] = a.m_draft_chart[y][r][p];
				}
			}
		}

		for(int n=0; n<=7; n++)
		{
			m_proposed_picks[n] = a.m_proposed_picks[n];
		}

		for(int n=0; n<=3; n++)
		{
			m_number_proposed_picks_year[n] = a.m_number_proposed_picks_year[n];
		}

		m_number_proposed_picks = a.m_number_proposed_picks;
		m_number_actual_picks = a.m_number_actual_picks;
		m_salary_in_trade = a.m_salary_in_trade;
		m_total_salary_in_trade = a.m_total_salary_in_trade;
		m_total_true_in_trade = a.m_total_true_in_trade;
		m_total_years_in_trade = a.m_total_years_in_trade;

		for(int n=0; n<=192; n++)
		{
			m_actual_picks[n] = a.m_actual_picks[n];
		}
		for(int n=0; n<=3; n++)
		{
			m_number_picks_year[n] = a.m_number_picks_year[n];
		}

		m_draft_pick_addition = a.m_draft_pick_addition;

		return *this;		
	}
	
private:

};