#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef Awards_h
#include "Awards.h"
#define Awards_h
#endif 


#include "ProgressDlg1.h"


class CHtml : public CObject
{
// Construction
public:
	int m_stage;
	CString m_bk_color;
	CString m_text_color;
	CString m_link_color;
	CString m_vlink_color;
	CString m_html_font;
	void CreateMiscReport(CString label, CString labels[28], CString strings[581][28], int r1, int r2, CString name);
	void GenerateReports();
	void GenerateMainPage();
	void GenerateBudgetPage();
	CString m_path;
	CString m_league_name;
	int m_current_year;
	int m_box_index;
	int m_player_page_index;

	CAverage avg;
	CHtml();
	~CHtml();




protected:


private:
	void FillList(CString strings[33], CString heading);
	void GenerateFaPreview();
	void WriteTableHeader(int colspan, CString string);
	CString CreateStringWithPlayerIdTag(CString name, int id);
	void GenerateAwardsHistory();
	void GenerateRookiePreview();
	void GenerateTransactionPage();
	void GenerateTeamSchedules();

	void GenerateBoxScores();
	void GenerateSchedulePage();
	CString GetPlayerPageName(CPlayer m_player);
	void WriteBoldRow(CString strings[], int index);
	void SetHeading(CString string);
	void WriteRow(CString strings[], int items, bool start_table, int use_class);
	void SetRowString(CString string);
	CString m_font;
	void GenerateInjuryPage();
	void CreateAwardsPage();
	void AddLine(CString str);
	CString m_car_string[64];
	void CreateCareerStatsReport(CPlayer m_player);
	int CreateAwardReport(CPlayer m_player);
	CString m_lines[5000];
	void CreateScoutingReport(CPlayer m_player);
	void InitData();
	void GeneratePlayerPages();
	void GenerateTeamPages();
	void WritePage(CString title);
	void SortStandings();
	void EndPage();
	void BeginPage(CString heading);
	void GenerateStandings();
	void CreatePlayoffTree();
	void GenerateScoutPage();
	void GenerateCoachPage();
	void GenerateGmPage();

	int m_current_line;
	CString m_strings[5000];
	CString awards[256];


};




