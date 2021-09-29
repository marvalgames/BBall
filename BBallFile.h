#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef Future_h
#include "Future.h"
#define Future_h
#endif 

class CBBallFile: public CObject
{

	
public:
	void CreateBlankFile(CString file_name, int size);
	bool FileExists(CString file_name);	
	void DeleteFile(CString file_name);
	void IncreaseFileSize(CString file_name, int size);
	void WriteAwardHistoryFile(CString file_name, CString exp_file_name, int current_year,
								  int mvp[11], int mvp_team_index[11],
								  int sth[11], int sth_team_index[11],
								  int defense[11], int defense_team_index[11],
								  int rookie[11], int rookie_team_index[11],
								  int pts[11], int pts_team_index[11], int pts_avg[11],
								  int reb[11], int reb_team_index[11], int reb_avg[11],
								  int ast[11], int ast_team_index[11], int ast_avg[11],
								  int stl[11], int stl_team_index[11], int stl_avg[11],
								  int blk[11], int blk_team_index[11], int blk_avg[11],
								  int po_mvp, int po_mvp_team_index,
								  int winner, int loser, int win, int loss,
									int allstar, int allstar_index, int rookiestar, int rookiestar_index, int three, int three_index, int dunk, int dunk_index
								  
								  );

	int ReadCurrentExpansionCount(CString file_name);

	void CreateHugeBlankFile(CString file_name, int times);

	void OpenRookies(CString file_name, CPlayer  *Rookies);

	void ReadFutureFile(CFuture *m_future, CString file_name);

	void WriteFutureFile(CFuture *m_future, CString file_name);

	void WriteRookieFile(CString file_name, CPlayer *Rookies);

	void ResetSeasonFiles(CString file_name);

CBBallFile()
{
}






~CBBallFile()
{
}	
	

};