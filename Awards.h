//#include "NbaDoc.h"
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
//#ifndef PropSheet_h
//#include "PropSheet.h"
//#define PropSheet_h
//#endif 

class CAwards : public CObject
{
// Construction
public:
//	bool m_save;
	void ChooseRings(CString file_name);
	void WriteAwardHistoryFile(CString file_name);
	void SaveAwards(CString file_name);
	void ChooseAwards();
	CString m_path;
	CString m_league_name;
	int m_team_index;
	int m_visitor_index;
	int m_home_index;
	int m_current_year;
	CRecord* m_standings;
	CAverage avg;
	int m_mvp[11];
	int m_all_league[6][4];
	int m_all_defense[6][4];
	int m_all_rookie[6][4];
	int m_defense[11];
    int m_rookie[11];
    int m_pts[11];
    int m_reb[11];
    int m_ast[11];
    int m_stl[11];
    int m_blk[11];
	int m_ring[16];
	int m_6th[11];
	int m_po_mvp;

	
	CAwards();
	~CAwards();




protected:


private:
	void SeekAllstarContestants(CString file_name);
	//id of player, seek is offset of stat 694and up, str is "1" or "2" 2 is mvp 1 is participant
	void SaveAllstarWeekend(CString file_name, int id, int seek, CString str);

	void SaveDunkContest(CString file_name);
	void SaveThreeContest(CString file_name);
	void SaveRookiestarMVP(CString file_name);
	void SaveAllstarMVP(CString file_name);
	int m_winner;
	int m_loser;
	int m_win;
	int m_loss;//final results
	void SaveDefense(CString file_name);
	void ChooseDefense();
	void SaveMvp(CString file_name);
	void SavePoMvp(CString file_name);
	void ChooseMvp();
	void ChoosePoMvp();
	void SaveRookie(CString file_name);
	void ChooseRookie();
	void SavePts(CString file_name);
	void ChoosePts();
	void SaveReb(CString file_name);
	void ChooseReb();
	void SaveAst(CString file_name);
	void ChooseAst();
	void SaveStl(CString file_name);
	void ChooseStl();
	void SaveBlk(CString file_name);
	void ChooseBlk();
	void Save6th(CString file_name);
	void Choose6th();
	void SaveRing(CString file_name);
	void ChooseAllLeague();
	void ChooseAllDefense();
	void ChooseAllRookie();

	void SaveAllLeague(CString file_name);
	void SaveAllDefense(CString file_name);
	void SaveAllRookie(CString file_name);

	CBrush myBrush;
};




