class CPlayerStats: public CObject
{
private:
//	int m_teamFouls;

public:
	int m_stat_slot;
	CString m_name;
	int m_injury;
	int m_Min;
	int m_Fgm;
	int m_Fga;
	int m_Ftm;
	int m_Fta;
	int m_Tfgm;
	int m_Tfga;
	int m_Oreb;
	int m_Dreb;
	int m_Ast;
	int m_Stl;
	int m_To;
	int m_Blk;
	int m_Pf;
	int m_stamina;
	int m_player_pointer; 


	CPlayerStats()
	{
	m_name = "";	
	m_injury = 0;
	m_Min = 0;
	m_Fgm = 0;
	m_Fga = 0;
	m_Ftm = 0;
	m_Fta = 0;
	m_Tfgm = 0;
	m_Tfga = 0;
	m_Oreb = 0;
	m_Dreb = 0;
	m_Ast = 0;
	m_Stl = 0;
	m_To = 0;
	m_Blk = 0;
	m_Pf = 0;
	m_stamina = 0;
	m_stat_slot = 0;
	m_player_pointer = 0; 

	}
	~CPlayerStats(){}
	
void SetName(CString n){m_name = n;}
void SetInjury(int i){m_injury = i;}
void SetMin(int time){m_Min = m_Min + time;}
void SetFgm(){m_Fgm = m_Fgm + 1;}
void SetFga(){m_Fga = m_Fga + 1;}
void SetTfgm(){m_Tfgm = m_Tfgm + 1;}
void SetTfga(){m_Tfga = m_Tfga + 1;}
void SetFtm(){m_Ftm = m_Ftm + 1;}
void SetFta(){m_Fta = m_Fta + 1;}
void SetOreb(){m_Oreb = m_Oreb + 1;}
void SetDreb(){m_Dreb = m_Dreb + 1;}
void SetAst(){m_Ast = m_Ast + 1;}
void SetStl(){m_Stl = m_Stl + 1;}
void SetTo(){m_To = m_To + 1;}
void SetBlk(){m_Blk = m_Blk + 1;}
void SetPf(){m_Pf = m_Pf + 1;}
void SetGameCurrentStamina(int stamina){m_stamina = stamina;}



//int GetTeamFouls(){return m_teamFouls;}
CString GetName(){return m_name;}
int GetInjury(){return m_injury;}
int GetMin(){return m_Min;}
int GetFgm(){return m_Fgm;}
int GetFga(){return m_Fga;}
int GetTfgm(){return m_Tfgm;}
int GetTfga(){return m_Tfga;}
int GetFtm(){return m_Ftm;}
int GetFta(){return m_Fta;}
int GetOreb(){return m_Oreb;}
int GetDreb(){return m_Dreb;}
int GetAst(){return m_Ast;}
int GetStl(){return m_Stl;}
int GetTo(){return m_To;}
int GetBlk(){return m_Blk;}
int GetPf(){return m_Pf;}
int GetStamina(){return m_stamina;}



//copy constructor
	CPlayerStats( const CPlayerStats& a ) 
	{ 
		m_name = a.m_name;
		m_injury = a.m_injury;
		m_Min = a.m_Min;
		m_Fgm = a.m_Fgm;
		m_Fga = a.m_Fga;
		m_Tfgm = a.m_Tfgm;
		m_Tfga = a.m_Tfga;
		m_Ftm = a.m_Ftm;
		m_Fta = a.m_Fta;
		m_Oreb = a.m_Oreb;
		m_Dreb = a.m_Dreb;
		m_Ast = a.m_Ast;
		m_Stl = a.m_Stl;
		m_To = a.m_To;
		m_Blk = a.m_Blk;
		m_Pf = a.m_Pf;
		m_stamina = a.m_stamina;
		m_stat_slot = a.m_stat_slot;
		m_player_pointer = a.m_player_pointer;

	} 
	
	const CPlayerStats& operator=( const CPlayerStats& a )
    {
		m_name = a.m_name;
		m_injury = a.m_injury;
		m_Min = a.m_Min;
		m_Fgm = a.m_Fgm;
		m_Fga = a.m_Fga;
		m_Tfgm = a.m_Tfgm;
		m_Tfga = a.m_Tfga;
		m_Ftm = a.m_Ftm;
		m_Fta = a.m_Fta;
		m_Oreb = a.m_Oreb;
		m_Dreb = a.m_Dreb;
		m_Ast = a.m_Ast;
		m_Stl = a.m_Stl;
		m_To = a.m_To;
		m_Blk = a.m_Blk;
		m_Pf = a.m_Pf;
		m_stamina = a.m_stamina;
		m_stat_slot = a.m_stat_slot;
		m_player_pointer = a.m_player_pointer;

		return *this;
    }
};
