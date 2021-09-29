#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 


class CImpExp: public CObject
{

	
public:
	CString m_game_plan_strings[16];
	void ExportGamePlan(CString file_name);
	void ImportGamePlan(CString file_name);
	void CreateGamePlanString(CPlayer m_player, int index);
	void WriteDirectory(CString file_name);
	void ConvertGamePlanString(CPlayer &m_player, int index);
	void ExportOffers(CString file_name, CString *m_offer_strings);
	bool ImportFaOffers(CString file_name, CString *strings);



CImpExp()
{

}






~CImpExp()
{
}	
	

};