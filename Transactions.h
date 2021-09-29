//#include "NbaDoc.h"
//#ifndef Average_h
//#include "Average.h"
//#define Average_h
//#endif 
//#ifndef PropSheet_h
//#include "PropSheet.h"
//#define PropSheet_h
//#endif 

class CTransactions : public CObject
{
// Construction
public:
	CTransactions();
	~CTransactions();

	CString m_injury_desc;
	int m_signing_team;
	int m_signing_yr;
	int m_signing_sa;
	int m_signing_id;
	int m_injury_team;
	int m_injury_id;
	int m_injury_games;
	int m_month;
	int m_day;
	int m_year;
	int m_type;
	int m_pic[6];
	int m_team1[6];
	int m_team2[6];
	int m_id[6];
	int m_pick_yr[6];
	int m_pick_rd[6];
	int m_pick_te[6];	

protected:


private:

	


};




