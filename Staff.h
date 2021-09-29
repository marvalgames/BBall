

class CStaff: public CObject
{
private:
	int AdjustRating(int rating, int prime, int max);
	void SetPot1Rating();
	void SetPot2Rating();
	void SetEffortRating();
	void SetScoringRating();
	void SetShootingRating();
	void SetReboundingRating();
	void SetPassingRating();
	void SetDefenseRating();




	
public:
//	void CreateReport(CPlayer m_player);

	int IntRandom(int n)
	{
		double number = rand();
		number /= RAND_MAX + 1;
		number *= n;
		return (int)number + 1;
	}


	double Random(double n);
	//int Random(int n);
	void SetImprovement(int prime);
	void CreateNewMember();
	void ChooseScoutJob(int topScout[101], int index, int numberTeams);
	void ChooseCoachJob(int topCoach[101], int index, int numberTeams);
	void ChooseGmJob(int topGM[101], int index, int numberTeams);
	CString m_lines[33];
	int m_record;
	int m_win;
	int m_loss;
	int m_playoffs;
	int m_rings;
	int m_points;
	int m_scoutJob;
	int m_coachJob;
	int m_gmJob;
	int m_currentScout;
	int m_currentCoach;
	int m_currentGM;
	bool m_fired;
	void InitVariables();
	void SetRatings();
	CString m_name;
	CString m_status;
	int m_age;
	int m_id;
	int m_slot;
	CString m_team;
	int m_pot1Rating;
	int m_pot2Rating;
	int m_effortRating;
	int m_scoringRating;
	int m_shootingRating;
	int m_reboundingRating;
	int m_passingRating;
	int m_defenseRating;
	int m_power;
	int m_power1;
	int m_power2;
	int m_coachPot1;
	int m_coachPot2;
	int m_coachEffort;
	int m_coachScoring;
	int m_coachShooting;
	int m_coachRebounding;
	int m_coachPassing;
	int m_coachDefense;
	int m_coachO;
	int m_coachP;
	int m_coachI;
	int m_coachF;
	int m_coachOD;
	int m_coachPD;
	int m_coachID;
	int m_coachFD;
	int m_coachEndurance;
	int m_loyalty;
	int m_personality;
	int m_power20;
	int m_pot1[6];
	int m_pot2[6];
	int m_effort[6];
	int m_scoring[6];
	int m_shooting[6];
	int m_rebounding[6];
	int m_passing[6];
	int m_defense[6];
	int m_originalCoach;
	int m_originalScout;
	int m_originalGM;
	bool m_retiredCoach;
	bool m_retiredScout;
	bool m_retiredGM;
	bool m_resignedCoach;
	bool m_resignedScout;
	bool m_resignedGM;

	double m_offered[33];
	double m_interested[33];
	CStaff()
	{
	m_name = "";
	m_status = "";
	m_record = 0;
	m_win = 0;
	m_loss = 0;
	m_playoffs = 0;
	m_rings = 0;
	m_points = 0;
	m_scoutJob = -1;
	m_coachJob = -1;
	m_gmJob = -1;
	m_currentScout = -1;
	m_currentCoach = -1;
	m_currentGM = -1;
	m_fired = false;
	m_id = 0;
	m_slot = 0;
	m_age = 0;
	m_pot1Rating = 3;
	m_pot2Rating = 3;
	m_effortRating = 3;
	m_scoringRating = 3;
	m_shootingRating = 3;
	m_reboundingRating = 3;
	m_passingRating = 3;
	m_defenseRating = 3;
	m_power = 3;
	m_power1 = 3;
	m_power2 = 3;
	m_coachPot1 = 3;
	m_coachPot2 = 3;
	m_coachEffort = 3;
	m_coachScoring = 3;
	m_coachShooting = 3;
	m_coachRebounding = 3;
	m_coachPassing = 3;
	m_coachDefense = 3;
	m_coachO = 3;
	m_coachP = 3;
	m_coachI = 3;
	m_coachF = 3;
	m_coachOD = 3;
	m_coachPD = 3;
	m_coachID = 3;
	m_coachFD = 3;

	m_coachEndurance = 3;
	m_loyalty = 3;
	m_personality = 3;
	m_power20 = 3;


	for(int i=0; i<=5; i++)
	{
		m_pot1[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_pot2[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_effort[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_scoring[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_shooting[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_rebounding[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_passing[i] = i;
	}

	for(int i=0; i<=5; i++)
	{
		m_defense[i] = i;
	}

	for(int i=0; i<=32; i++)
	{
		m_offered[i] = 0;
		m_interested[i] = 0;
		m_lines[i] = "";
	}
	    m_originalCoach = 0;
	    m_originalScout = 0;
	    m_originalGM = 0;
		m_retiredCoach = false;
		m_retiredScout = false;
		m_retiredGM = false;
		m_resignedCoach = false;
		m_resignedScout = false;
		m_resignedGM = false;

	}
	~CStaff()
	{
	}

	//copy constructor
	CStaff( const CStaff& a ) 
	{ 
		m_points = a.m_points;
		m_record = a.m_record;
		m_win = a.m_win;
		m_loss = a.m_loss;
		m_playoffs = a.m_playoffs;
		m_rings = a.m_rings;
		m_scoutJob = a.m_scoutJob;
		m_coachJob = a.m_coachJob;
		m_gmJob = a.m_gmJob;
		m_currentScout = a.m_currentScout;
		m_currentCoach = a.m_currentCoach;
		m_currentGM = a.m_currentGM;
		m_fired = a.m_fired;
		m_name = a.m_name;
		m_team = a.m_team;
		m_status = a.m_status;

		int i=0;
		for(int i=0; i<=5; i++)
		{
			m_pot1[i] = a.m_pot1[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_pot2[i] = a.m_pot2[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_effort[i] = a.m_effort[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_scoring[i] = a.m_scoring[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_shooting[i] = a.m_shooting[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_passing[i] = a.m_passing[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_rebounding[i] = a.m_rebounding[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_defense[i] = a.m_defense[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_offered[i] = a.m_offered[i];
			m_interested[i] = a.m_interested[i];
			m_lines[i] = a.m_lines[i];
		}


		m_pot1Rating = a.m_pot1Rating;
		m_pot2Rating = a.m_pot2Rating;
		m_effortRating = a.m_effortRating;
		m_scoringRating = a.m_scoringRating;
		m_shootingRating = a.m_shootingRating;
		m_reboundingRating = a.m_reboundingRating;
		m_passingRating = a.m_passingRating;
		m_defenseRating = a.m_defenseRating;
		m_age = a.m_age;
		m_id = a.m_id;
		m_slot = a.m_slot;
		m_power = a.m_power;
		m_power1 = a.m_power1;
		m_power2 = a.m_power2;
		m_coachPot1 = a.m_coachPot1;
		m_coachPot2 = a.m_coachPot2;
		m_coachEffort = a.m_coachEffort;
		m_coachScoring = a.m_coachScoring;
		m_coachShooting = a.m_coachShooting;
		m_coachRebounding = a.m_coachRebounding;
		m_coachPassing = a.m_coachPassing;
		m_coachDefense = a.m_coachDefense;
		m_coachO = a.m_coachO;
		m_coachP = a.m_coachP;
		m_coachI = a.m_coachI;
		m_coachF = a.m_coachF;
		m_coachOD= a.m_coachOD;
		m_coachPD= a.m_coachPD;
		m_coachID= a.m_coachID;
		m_coachFD= a.m_coachFD;
		m_coachEndurance = a.m_coachEndurance;
		m_loyalty = a.m_loyalty;
		m_personality = a.m_personality;
		m_power20 = a.m_power20;
	    m_originalCoach = a.m_originalCoach;
	    m_originalScout = a.m_originalScout;
	    m_originalGM = a.m_originalGM;
		m_retiredCoach = a.m_retiredCoach;
		m_retiredScout = a.m_retiredScout;
		m_retiredGM = a.m_retiredGM;
		m_resignedCoach = a.m_resignedCoach;
		m_resignedScout = a.m_resignedScout;
		m_resignedGM = a.m_resignedGM;

	} 
	const CStaff& operator=( const CStaff& a )
    {
		m_points = a.m_points;
		m_record = a.m_record;
		m_win = a.m_win;
		m_loss = a.m_loss;
		m_playoffs = a.m_playoffs;
		m_rings = a.m_rings;
		m_scoutJob = a.m_scoutJob;
		m_coachJob = a.m_coachJob;
		m_gmJob = a.m_gmJob;
//		m_current = a.m_current;
		m_currentScout = a.m_currentScout;
		m_currentCoach = a.m_currentCoach;
		m_currentGM = a.m_currentGM;
		m_fired = a.m_fired;
		m_name = a.m_name;
		m_team = a.m_team;
		m_status = a.m_status;
	
		for(int i=0; i<=5; i++)
		{
			m_pot1[i] = a.m_pot1[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_pot2[i] = a.m_pot2[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_effort[i] = a.m_effort[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_scoring[i] = a.m_scoring[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_shooting[i] = a.m_shooting[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_passing[i] = a.m_passing[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_rebounding[i] = a.m_rebounding[i];
		}

		for(int i=0; i<=5; i++)
		{
			m_defense[i] = a.m_defense[i];
		}

		for(int i=0; i<=32; i++)
		{
			m_offered[i] = a.m_offered[i];
			m_interested[i] = a.m_interested[i];
			m_lines[i] = a.m_lines[i];
		}

		m_pot1Rating = a.m_pot1Rating;
		m_pot2Rating = a.m_pot2Rating;
		m_effortRating = a.m_effortRating;
		m_scoringRating = a.m_scoringRating;
		m_shootingRating = a.m_shootingRating;
		m_reboundingRating = a.m_reboundingRating;
		m_passingRating = a.m_passingRating;
		m_defenseRating = a.m_defenseRating;

		m_id = a.m_id;
		m_slot = a.m_slot;
		m_age = a.m_age;

		m_power = a.m_power;
		m_power1 = a.m_power1;
		m_power2 = a.m_power2;
		m_coachPot1 = a.m_coachPot1;
		m_coachPot2 = a.m_coachPot2;
		m_coachEffort = a.m_coachEffort;
		m_coachScoring = a.m_coachScoring;
		m_coachShooting = a.m_coachShooting;
		m_coachRebounding = a.m_coachRebounding;
		m_coachPassing = a.m_coachPassing;
		m_coachDefense = a.m_coachDefense;
		m_coachO = a.m_coachO;
		m_coachP = a.m_coachP;
		m_coachI = a.m_coachI;
		m_coachF = a.m_coachF;
		m_coachOD= a.m_coachOD;
		m_coachPD= a.m_coachPD;
		m_coachID= a.m_coachID;
		m_coachFD= a.m_coachFD;
		m_coachEndurance = a.m_coachEndurance;
		m_loyalty = a.m_loyalty;
		m_personality = a.m_personality;
		m_power20 = a.m_power20;
	    m_originalCoach = a.m_originalCoach;
	    m_originalScout = a.m_originalScout;
	    m_originalGM = a.m_originalGM;
		m_retiredCoach = a.m_retiredCoach;
		m_retiredScout = a.m_retiredScout;
		m_retiredGM = a.m_retiredGM;
		m_resignedCoach = a.m_resignedCoach;
		m_resignedScout = a.m_resignedScout;
		m_resignedGM = a.m_resignedGM;
		return *this;
    }	
};