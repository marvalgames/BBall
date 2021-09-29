class CBBallSchedule: public CObject
{
private:

	
public:
	void GetNewSeasonAllstarDayEtc();
	int DaysElapsed(int team);
	int DaysSinceSeasonEnd();
	int m_asw_mo;
	int m_asw_da;
	int m_asw_ga;

	int m_dead_mo;
	int m_dead_da;

	void ClearSchedule();
	void GetNextGame(bool playoff);
	int GetCurrentPlayoffDay(int &last_day);

bool m_regular_season_ended;

int m_schedule[13][32][17];
int m_game_score[13][32][17];
int m_currentRound;
int m_currentMonth;
int m_currentDay;
int m_currentYear;
int m_currentGame;
int	m_days_in_season;
int m_games_in_season;
bool m_enable_asw_button;

int m_last_da;
int m_last_mo;
int m_last_ga;

int m_first_da;
int m_first_mo;
int m_first_ga;




int m_series_win1;//tracks wins of road team in currently played playoff series
int m_series_win2;//tracks wins of road team in currently played playoff series
bool m_playoff_started;
bool m_season_started;



CBBallSchedule()
{

		m_regular_season_ended = false;


		for(int i=0; i<=12; i++)
		{
			for(int j=0; j<=31; j++)
			{
				for(int k=0; k<=16; k++)
				{

					m_schedule[i][j][k] = 0;
					m_game_score[i][j][k] = 0;
				}
			}
		}

	m_games_in_season = 0;
	m_enable_asw_button = false;
	m_season_started = false;
	m_currentRound = 0;
	m_currentMonth = 0;
	m_currentDay = 0;
	m_currentYear = 0;
	m_currentGame = 0;
	m_playoff_started = false;
	m_series_win1 = 0;
	m_series_win2 = 0;
	m_last_da = 0;
	m_last_mo = 0;
	m_last_ga = 0;
	m_asw_mo = 0;
	m_asw_da = 0;
	m_asw_ga = 0;

	m_dead_mo = 0;
	m_dead_da = 0;




	m_first_da = 0;
	m_first_mo = 0;
	m_first_ga = 0;

	m_days_in_season = 0;



}






~CBBallSchedule()
{
	
}	
	

	const CBBallSchedule& operator=( const CBBallSchedule& a )
    {


		m_regular_season_ended = a.m_regular_season_ended;
		m_games_in_season = a.m_games_in_season;
		m_currentRound = a.m_currentRound;


		for(int i=0; i<=12; i++)
		{
			for(int j=0; j<=31; j++)
			{
				for(int k=0; k<=16; k++)
				{

					m_schedule[i][j][k] = a.m_schedule[i][j][k];
					m_game_score[i][j][k] = a.m_game_score[i][j][k];
				}
			}
		}

		m_enable_asw_button = a.m_enable_asw_button;
		m_season_started = a.m_season_started;
		m_currentMonth = a.m_currentMonth;
		m_currentDay = a.m_currentDay;
		m_currentYear = a.m_currentYear;
		m_currentGame = a.m_currentGame;

		m_last_da = a.m_last_da;
		m_last_mo = a.m_last_mo;
		m_last_ga = a.m_last_ga;

		m_playoff_started = a.m_playoff_started;
		m_series_win1 = a.m_series_win1;
		m_series_win2 = a.m_series_win2;

		m_asw_mo = a.m_asw_mo;
		m_asw_da = a.m_asw_da;
		m_asw_ga = a.m_asw_ga;

		m_dead_mo = a.m_dead_mo;
		m_dead_da = a.m_dead_da;

		m_first_da = a.m_first_da;
		m_first_mo = a.m_first_mo;
		m_first_ga = a.m_first_ga;
		m_days_in_season = a.m_days_in_season;

		return *this;
	}

	CBBallSchedule( const CBBallSchedule& a ) 
	{ 

		m_regular_season_ended = a.m_regular_season_ended;
		m_games_in_season = a.m_games_in_season;

		for(int i=0; i<=12; i++)
		{
			for(int j=0; j<=31; j++)
			{
				for(int k=0; k<=16; k++)
				{

					m_schedule[i][j][k] = a.m_schedule[i][j][k];
					m_game_score[i][j][k] = a.m_game_score[i][j][k];
				}
			}
		}

		m_enable_asw_button = a.m_enable_asw_button;
		m_season_started = a.m_season_started;
		m_currentRound = a.m_currentRound;
		m_currentMonth = a.m_currentMonth;
		m_currentDay = a.m_currentDay;
		m_currentYear = a.m_currentYear;
		m_currentGame = a.m_currentGame;
		m_playoff_started = a.m_playoff_started;
		m_series_win1 = a.m_series_win1;
		m_series_win2 = a.m_series_win2;

		m_last_da = a.m_last_da;
		m_last_mo = a.m_last_mo;
		m_last_ga = a.m_last_ga;

		m_asw_mo = a.m_asw_mo;
		m_asw_da = a.m_asw_da;
		m_asw_ga = a.m_asw_ga;

		m_dead_mo = a.m_dead_mo;
		m_dead_da = a.m_dead_da;

		m_first_da = a.m_first_da;
		m_first_mo = a.m_first_mo;
		m_first_ga = a.m_first_ga;
		m_days_in_season = a.m_days_in_season;

	}

};