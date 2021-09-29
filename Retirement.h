#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 


class CRetirement: public CObject
{

	
public:
	void ReadRetirements();
	void UpdatePlayerClass();
	CString m_path;
	CString m_league_name;
	void WriteRetirements();
	void SetRetirements(int hi_fga, int hi_fta, int hi_tga, int hi_orb, int hi_drb, int hi_ast, int hi_stl, int hi_to, int hi_blk);
	CAverage avg;


	CRetirement()
	{
		m_retirement_count = 0;
		for(int i=0; i<=191; i++)
		{
			m_retired_list_id[i] = 0;
			m_retired_list_name[i] = "";
			m_read_retirement_strings[i] = "";
		}

	}
	~CRetirement(){}

	//copy constructor
	
private:
	CString m_read_retirement_strings[192];
	int m_retired_list_id[192];
	CString m_retired_list_name[192];
	int m_retirement_count;



};