//#include "bball.h"
//#include "constants.h"
//#include "resource.h"


#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif

#ifndef Own_h
#include "Own.h"	// Added by ClassView
#define Own_h
#endif

#ifndef Future_h
#include "Future.h"	// Added by ClassView
#define Future_h
#endif

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 


#ifndef OfferTrades1_h
#include "OfferTrades1.h"
#define OfferTrades1_h
#endif 


class CComputer: public CObject
{

private:
	bool m_trade_made;



	int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}

	//int Random(int n);
	double Random(double n);
	void SetOwnDraftPicks(int t1);
	void WriteReleaseToFile(int team, int id);
	void WriteSigningsToFile(int team, int player_index);
	void WriteSingleTeamData(int team);
	void AddFreeAgentToTeam(int team, int index);
	void RemoveFreeAgentFromList(int index);
	int BestFreeAgent(int team, CString pos);
	CString PositionNeeded(int team);
	int ReorderRoster(int team);




	bool t2_offered;
	bool t1_offered;
	void WriteTransaction(CPlayer NewTeam[41], int Signed[120], CPlayer NewFA[120], int value_picks1[4], int value_picks2[4]);
	int players[41];

public:
	int m_last_released_player_id;
	bool m_use_trading_block;
	int m_players_on_block;
	int m_getoffersforteam;
	BOOL m_free_agency_on;
	BOOL m_finances_on;
	int m_current_year;
	COwn* m_own;
	bool AvailableFA();
	BOOL m_ast_gm;
	bool m_receive_offers[33];
	bool ReleasePlayer(int team);
	CString m_player_gm[33];
	void SignFreeAgent(int team);
	CAverage avg;
	int m_team2;
	int m_team1;
	BOOL m_checkCareer;
	BOOL m_computerTrades;
	int m_currentDay;
	int m_currentMonth;
	bool OfferTrade(CPlayer NewTeam[41], int value_picks1[4], int value_picks2[4]);
	CString m_leagueName;
	CString m_path;
	int m_numberteams;
	CString m_control[33];
	CString m_leagueTeamNames[33];
	bool Trade(int offered[33], int loops, int max_offers, int stage);
	CFuture m_future;
	CComputer();
	~CComputer();
};


