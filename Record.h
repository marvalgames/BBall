class CRecord: public CObject
{

public:
	void ClearTeamStandings(int i);

		CString m_leagueTeamNames;
		CString m_control;
		CString m_conference;
		CString m_division;
		CString m_city_name;
		int m_leagueRecord;
		int m_win;
		int m_loss;
		int m_divisionRecord;
		int m_conferenceRecord;
		int m_homeRecord;
		int m_visitorRecord;
		double m_leaguePct;
		double m_divisionPct;
		double m_conferencePct;
		int m_leagueGamesBack;
		int m_vsOpponent[33];
		int m_initialNumber;
		double m_vsOpponentPct[33];
		bool m_playoff_team;
		bool m_divisionChamps;
		bool m_playoff;
		bool m_ring;
		int m_points;
		CRecord()
		{
			m_points = 0;
			m_leagueTeamNames = "";
			m_control = "";
			m_conference = "";
			m_division = "";
			m_city_name = "";

		    m_leagueRecord = 0;
			m_win = 0;
			m_loss = 0;
			m_divisionRecord = 0;
			m_conferenceRecord = 0;
		    m_homeRecord = 0;
			m_visitorRecord = 0;
			m_leaguePct = 0;
			m_divisionPct = 0;
			m_conferencePct = 0;
			m_leagueGamesBack = 0;
			for(int i=0; i<=32; i++)
			{
				m_vsOpponent[i] = 0;
			}
			m_playoff_team = false;
			m_initialNumber = 0;
			for(int i=0; i<=32; i++)
			{
				m_vsOpponentPct[i] = 0;
			}
			m_divisionChamps = false;
			m_playoff = false;
			m_ring = false;


		
		};
		~CRecord(){};
	CRecord( const CRecord& a ) 
	{ 
		m_points = a.m_points;
		m_leagueTeamNames = a.m_leagueTeamNames;
		m_control = a.m_control;
		m_conference = a.m_conference;
		m_division = a.m_division;
		m_city_name = a.m_city_name;
		m_leagueRecord = a.m_leagueRecord;
		m_win = a.m_win;
		m_loss = a.m_loss;
		m_divisionRecord = a.m_divisionRecord;
		m_conferenceRecord = a.m_conferenceRecord;
		m_homeRecord = a.m_homeRecord;
		m_visitorRecord = a.m_visitorRecord;
		m_leaguePct = a.m_leaguePct;
		m_divisionPct = a.m_divisionPct;
		m_conferencePct = a.m_conferencePct;
		m_leagueGamesBack = a.m_leagueGamesBack;
		for(int i=0; i<=32; i++)
		{
			m_vsOpponent[i] = a.m_vsOpponent[i];

		}
		m_playoff_team = a.m_playoff_team;
		m_initialNumber = a.m_initialNumber;
		for(int i=0; i<=32; i++)
		{
			m_vsOpponentPct[i] = a.m_vsOpponentPct[i];
		}
		m_divisionChamps = a.m_divisionChamps;
		m_playoff = a.m_playoff;
		m_ring = a.m_ring;

	} 


	const CRecord& operator=( const CRecord& a )
    {
		m_points = a.m_points;
		m_leagueTeamNames = a.m_leagueTeamNames;
		m_control = a.m_control;
		m_conference = a.m_conference;
		m_division = a.m_division;
		m_city_name = a.m_city_name;
		m_leagueRecord = a.m_leagueRecord;
		m_win = a.m_win;
		m_loss = a.m_loss;
		m_divisionRecord = a.m_divisionRecord;
		m_conferenceRecord = a.m_conferenceRecord;
		m_homeRecord = a.m_homeRecord;
		m_visitorRecord = a.m_visitorRecord;
		m_leaguePct = a.m_leaguePct;
		m_divisionPct = a.m_divisionPct;
		m_conferencePct = a.m_conferencePct;
		m_leagueGamesBack = a.m_leagueGamesBack;
		for(int i=0; i<=32; i++)
		{
			m_vsOpponent[i] = a.m_vsOpponent[i];
		}
		m_playoff_team = a.m_playoff_team;
		m_initialNumber = a.m_initialNumber;
		for(int i=0; i<=32; i++)
		{
			m_vsOpponentPct[i] = a.m_vsOpponentPct[i];
		}
		m_divisionChamps = a.m_divisionChamps;
		m_playoff = a.m_playoff;
		m_ring = a.m_ring;


		return *this;
    }



};