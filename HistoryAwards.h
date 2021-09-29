// HistoryAwardsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryAwardsDlg dialog

class CHistoryAwards : public CObject
{
// Construction
public:

	CString m_file_name, m_path , m_league_name;
    CString m_league_team_names[33];
	void InitClass();
	CHistoryAwards()
	{
		m_lines = 0;
		m_start_year = 0;

		for(int i=0; i<=4999; i++)
		{
			m_pointer[i] = 0;

			m_mvp[i] = 0;
			m_mvp_team_index[i]= 0;
			m_mvp_po[i] = "";
			m_mvp_team[i] = "";
			m_mvp_name[i] = "";

			m_6th[i]= 0;
			m_6th_po[i] = "";
			m_6th_name[i] = "";
			m_6th_team[i] = "";
			m_6th_team_index[i] = 0;

			m_po_mvp_team_index[i] = 0;
			m_po_mvp[i] = 0;
			m_po_mvp_team[i] = "";
			m_po_mvp_po[i] = "";
			m_po_mvp_name[i] = "";

			m_defense[i] = 0;
			m_defense_name[i] = "";
			m_defense_team[i] = "";
			m_defense_team_index[i] = 0;
			m_defense_po[i] = "";

			m_rookie[i] = 0;
			m_rookie_name[i] = "";
			m_rookie_team[i] = "";
			m_rookie_po[i] = "";
			m_rookie_team_index[i] = 0;

			m_allstar[i] = 0;
			m_allstar_name[i] = "";
			m_allstar_team[i] = "";
			m_allstar_po[i] = "";
			m_allstar_team_index[i] = 0;

			m_rookiestar[i] = 0;
			m_rookiestar_name[i] = "";
			m_rookiestar_team[i] = "";
			m_rookiestar_po[i] = "";
			m_rookiestar_team_index[i] = 0;

			m_3contest[i] = 0;
			m_3contest_name[i] = "";
			m_3contest_team[i] = "";
			m_3contest_po[i] = "";
			m_3contest_team_index[i] = 0;

			m_dunkcontest[i] = 0;
			m_dunkcontest_po[i] = "";
			m_dunkcontest_team[i] = "";
			m_dunkcontest_name[i] = "";
			m_dunkcontest_team_index[i] = 0;

			m_pts[i] = 0;
			m_pts_name[i] = "";
			m_pts_po[i] = "";
			m_pts_team[i] = "";
			m_pts_team_index[i] = 0;
			m_pts_avg[i] = 0;

			m_reb[i] = 0;
			m_reb_name[i] = "";
			m_reb_po[i] = "";
			m_reb_team[i] = "";
			m_reb_team_index[i] = 0;
			m_reb_avg[i] = 0;

			m_ast[i] = 0;
			m_ast_name[i] = "";
			m_ast_po[i] = "";
			m_ast_team[i] = "";
			m_ast_team_index[i] = 0;
			m_ast_avg[i] = 0;

			m_stl[i] = 0;
			m_stl_name[i] = "";
			m_stl_po[i] = "";
			m_stl_team[i] = "";
			m_stl_team_index[i] = 0;
			m_stl_avg[i] = 0;

			m_blk[i] = 0;
			m_blk_name[i] = "";
			m_blk_po[i] = "";
			m_blk_team[i] = "";
			m_blk_team_index[i] = 0;
			m_blk_avg[i] = 0;

			m_champ[i] = 0;
			m_champ_team[i] = "";

			m_exp_count[i] = 0;




		}

//		InitClass();

	}// standard constructor

	~CHistoryAwards()
	{
		
	
	}

	//copy constructor
	CHistoryAwards( const CHistoryAwards& a ) 
	{ 
		
	}

	const CHistoryAwards& operator=( const CHistoryAwards& a )
    {
		return *this;
	}



	void Listdunkcontest();
	void ListThreecontest();
	void ListRookiestarMVP();
	void ListAllstarMVP();
	int m_current_exp_count;
	void ReadOriginalNames();
	CString m_original_names[33][33];
	CFont m_font;
	int m_lines;
	int m_start_year;
	int m_pointer[5000];

	int m_mvp[5000];
    int m_mvp_team_index[5000];
	CString m_mvp_po[5000];
	CString m_mvp_team[5000];
	CString m_mvp_name[5000];

	int m_6th[5000];
	CString m_6th_po[5000];
	CString m_6th_name[5000];
	CString m_6th_team[5000];
    int m_6th_team_index[5000];

    int m_po_mvp_team_index[5000];
	int m_po_mvp[5000];
	CString m_po_mvp_team[5000];
	CString m_po_mvp_po[5000];
	CString m_po_mvp_name[5000];

	int m_defense[5000];
	CString m_defense_name[5000];
	CString m_defense_team[5000];
    int m_defense_team_index[5000];
	CString m_defense_po[5000];

	int m_rookie[5000];
	CString m_rookie_name[5000];
	CString m_rookie_team[5000];
	CString m_rookie_po[5000];
    int m_rookie_team_index[5000];

	int m_allstar[5000];
	CString m_allstar_name[5000];
	CString m_allstar_team[5000];
	CString m_allstar_po[5000];
	int m_allstar_team_index[5000];

	int m_rookiestar[5000];
	CString m_rookiestar_name[5000];
	CString m_rookiestar_team[5000];
	CString m_rookiestar_po[5000];
	int m_rookiestar_team_index[5000];

	int m_3contest[5000];
	CString m_3contest_name[5000];
	CString m_3contest_team[5000];
	CString m_3contest_po[5000];
	int m_3contest_team_index[5000];

	int m_dunkcontest[5000];
	CString m_dunkcontest_po[5000];
	CString m_dunkcontest_team[5000];
	CString m_dunkcontest_name[5000];
	int m_dunkcontest_team_index[5000];

	int m_pts[5000];
	CString m_pts_name[5000];
	CString m_pts_po[5000];
	CString m_pts_team[5000];
    int m_pts_team_index[5000];
	double m_pts_avg[5000];

	int m_reb[5000];
	CString m_reb_name[5000];
	CString m_reb_po[5000];
	CString m_reb_team[5000];
    int m_reb_team_index[5000];
	double m_reb_avg[5000];

	int m_ast[5000];
	CString m_ast_name[5000];
    CString m_ast_po[5000];
	CString m_ast_team[5000];
    int m_ast_team_index[5000];
	double m_ast_avg[5000];

	int m_stl[5000];
	CString m_stl_name[5000];
	CString m_stl_po[5000];
	CString m_stl_team[5000];
    int m_stl_team_index[5000];
	double m_stl_avg[5000];

	int m_blk[5000];
	CString m_blk_name[5000];
	CString m_blk_po[5000];
	CString m_blk_team[5000];
    int m_blk_team_index[5000];
	double m_blk_avg[5000];

	int m_champ[5000];
	CString m_champ_team[5000];

	int m_exp_count[5000];

	void ReadAwards();
	void ListMvp();
	void List6th();
	void ListPoMvp();
	void ListDefense();
	void ListRookie();
	void ListPts();
	void ListReb();
	void ListAst();
	void ListStl();
	void ListBlk();
	void ListChampion();



};

