#include "stdafx.h"
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 





void CStaff::InitVariables()
{
	m_points = 0;
	m_record = 0;
	m_win = 0;
	m_loss = 0;
	m_playoffs = 0;
	m_rings = 0;
	m_scoutJob = -1;
	m_coachJob = -1;
	m_gmJob = -1;
	m_currentScout = -1;
	m_currentCoach = -1;
	m_currentGM = -1;
	m_fired = false;
	m_pot1Rating = 4;
	m_pot2Rating = 4;
	m_effortRating = 4;
	m_scoringRating = 4;
	m_shootingRating = 4;
	m_reboundingRating = 4;
	m_passingRating = 4;
	m_defenseRating = 4;
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


void CStaff::ChooseScoutJob(int topScout[101], int index, int numberTeams)
{
	int topTeam = -1;
	double topInterest = -1.;
	for(int i=0; i<numberTeams; i++)
	{
		if(topScout[i] == index && m_interested[i] > topInterest && m_status != "retires" && m_status != "hired")
		{
			topInterest = m_interested[i];
			topTeam = i;
		}
	}
	m_scoutJob = topTeam;
}

void CStaff::ChooseCoachJob(int topCoach[101], int index, int numberTeams)
{
	int topTeam = -1;
	double topInterest = -1.;
	for(int i=0; i<numberTeams; i++)
	{
		if(topCoach[i] == index && m_interested[i] > topInterest && m_status != "retires" && m_status != "hired")
		{
			topInterest = m_interested[i];
			topTeam = i;
		}
	}
	m_coachJob = topTeam;
}

void CStaff::ChooseGmJob(int topGM[101], int index, int numberTeams)
{
	int topTeam = -1;
	double topInterest = -1.;
	for(int i=0; i<numberTeams; i++)
	{
		if(topGM[i] == index && m_interested[i] > topInterest && m_status != "retires" && m_status != "hired")
		{
			topInterest = m_interested[i];
			topTeam = i;
		}
	}
	m_gmJob = topTeam;
}


void CStaff::CreateNewMember()
{


		int chart[6] = {0,0,0,0,0,0};
		for(int n=1; n<=8; n++)
		{
			bool exception = false;
			do
			{
				exception = false;
				for(int j=0; j<=5; j++){chart[j] = 0;}
				bool used[6] = {false,false,false,false,false,false};
				for(int o=1; o<=5; o++)
				{
					int r = 0;
					do
					{
						r =         IntRandom(5);
					}
					while(used[r] == true);
					used[r] = true;
					chart[o] = r;
				}
				if(chart[1] == 5 || chart[5] == 1) exception = true;
			}
			while(exception == true);
			if(n==1)
			{
				m_scoring[1] = chart[1];
				m_scoring[2] = chart[2];
				m_scoring[3] = chart[3];
				m_scoring[4] = chart[4];
				m_scoring[5] = chart[5];
			}
			else if(n==2)
			{
				m_shooting[1] = chart[1];
				m_shooting[2] = chart[2];
				m_shooting[3] = chart[3];
				m_shooting[4] = chart[4];
				m_shooting[5] = chart[5];
			}
			else if(n==3)
			{
				m_rebounding[1] = chart[1];
				m_rebounding[2] = chart[2];
				m_rebounding[3] = chart[3];
				m_rebounding[4] = chart[4];
				m_rebounding[5] = chart[5];
			}
			else if(n==4)
			{
				m_passing[1] = chart[1];
				m_passing[2] = chart[2];
				m_passing[3] = chart[3];
				m_passing[4] = chart[4];
				m_passing[5] = chart[5];
			}
			else if(n==5)
			{
				m_defense[1] = chart[1];
				m_defense[2] = chart[2];
				m_defense[3] = chart[3];
				m_defense[4] = chart[4];
				m_defense[5] = chart[5];
			}
			else if(n==6)
			{
				m_pot1[1] = chart[1];
				m_pot1[2] = chart[2];
				m_pot1[3] = chart[3];
				m_pot1[4] = chart[4];
				m_pot1[5] = chart[5];
			}
			else if(n==7)
			{
				m_pot2[1] = chart[1];
				m_pot2[2] = chart[2];
				m_pot2[3] = chart[3];
				m_pot2[4] = chart[4];
				m_pot2[5] = chart[5];
			}
			else if(n==8)
			{
				m_effort[1] = chart[1];
				m_effort[2] = chart[2];
				m_effort[3] = chart[3];
				m_effort[4] = chart[4];
				m_effort[5] = chart[5];
			}


		}

	SetRatings();

	m_status = "";
	m_record = 0;
	m_win = 0;
	m_loss = 0;
	m_playoffs = 0;
	m_rings = 0;
	m_points = 0;
	m_age = 0;
	int age = IntRandom(32)+32;
	if(Random(1) < .01) age = IntRandom(59) + 20;
	m_age = age;

	m_pot1Rating = IntRandom(5);
	m_pot2Rating = IntRandom(5);
	m_effortRating = IntRandom(5);
	m_scoringRating = IntRandom(5);
	m_shootingRating = IntRandom(5);
	m_reboundingRating = IntRandom(5);
	m_passingRating = IntRandom(5);
	m_defenseRating = IntRandom(5);
	m_power = IntRandom(5);
	m_power1 = IntRandom(5);
	m_power2 = IntRandom(5);
	m_coachPot1 = IntRandom(5);
	m_coachPot2 = IntRandom(5);
	m_coachEffort = IntRandom(5);
	m_coachScoring = IntRandom(5);
	m_coachShooting = IntRandom(5);
	m_coachRebounding = IntRandom(5);
	m_coachPassing = IntRandom(5);
	m_coachDefense = IntRandom(5);
	m_coachO = IntRandom(5);
	m_coachP = IntRandom(5);
	m_coachI = IntRandom(5);
	m_coachF = IntRandom(5);
	m_coachOD = IntRandom(5);
	m_coachPD = IntRandom(5);
	m_coachID = IntRandom(5);
	m_coachFD = IntRandom(5);
	m_coachEndurance = IntRandom(5);
	m_loyalty = IntRandom(5);
	m_personality = IntRandom(5);
	m_power20 = IntRandom(5);

}

double CStaff::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}


void CStaff::SetImprovement(int prime)
{
	m_age = m_age + 1;
	m_pot1Rating = AdjustRating(m_pot1Rating,prime, 7);
	m_pot2Rating = AdjustRating(m_pot2Rating,prime, 7);
	m_effortRating = AdjustRating(m_effortRating,prime, 7);
	m_scoringRating = AdjustRating(m_scoringRating, prime, 7);
	m_shootingRating = AdjustRating(m_shootingRating, prime, 7);
	m_reboundingRating = AdjustRating(m_reboundingRating, prime, 7);
	m_passingRating = AdjustRating(m_passingRating, prime, 7);
	m_defenseRating = AdjustRating(m_defenseRating, prime, 7);

    m_power = AdjustRating(m_power, prime, 5);
	m_power1 = AdjustRating(m_power1, prime, 5);
	m_power2 = AdjustRating(m_power2, prime, 5);
	m_coachPot1 = AdjustRating(m_coachPot1, prime, 5);
	m_coachPot2 = AdjustRating(m_coachPot2, prime, 5);
	m_coachEffort = AdjustRating(m_coachEffort, prime, 5);
	m_coachScoring = AdjustRating(m_coachScoring, prime, 5);
	m_coachShooting = AdjustRating(m_coachShooting, prime, 5);
	m_coachRebounding = AdjustRating(m_coachRebounding, prime, 5);
	m_coachPassing = AdjustRating(m_coachPassing, prime, 5);
	m_coachDefense = AdjustRating(m_coachDefense, prime, 5);
	m_coachO = AdjustRating(m_coachO, prime, 5);
	m_coachP = AdjustRating(m_coachP, prime, 5);
	m_coachI = AdjustRating(m_coachI, prime, 5);
	m_coachF = AdjustRating(m_coachF, prime, 5);
	m_coachOD = AdjustRating(m_coachOD, prime, 5);
	m_coachPD = AdjustRating(m_coachPD, prime, 5);
	m_coachID = AdjustRating(m_coachID, prime, 5);
	m_coachFD = AdjustRating(m_coachFD, prime, 5);
	m_coachEndurance = AdjustRating(m_coachEndurance, prime, 5);
	m_loyalty = AdjustRating(m_loyalty, prime, 5);

for(int r=1; r<=8; r++)
{ 

int wanted = 0;
if(r==1) wanted = m_pot1Rating;
else if(r==2) wanted = m_pot2Rating;
else if(r==3) wanted = m_effortRating;
else if(r==4) wanted = m_scoringRating;
else if(r==5) wanted = m_shootingRating;
else if(r==6) wanted = m_reboundingRating;
else if(r==7) wanted = m_passingRating;
else if(r==8) wanted = m_defenseRating;


bool chart_set = false;
int chart[6] = {0,0,0,0,0,0};

do
{

	bool exception = false;
			do
			{
				exception = false;
				for(int j=0; j<=5; j++){chart[j] = 0;}
				bool used[6] = {false,false,false,false,false,false};
				for(int o=1; o<=5; o++)
				{
					int r = 0;
					do
					{
						r = IntRandom(5);
					}
					while(used[r] == true);
					used[r] = true;
					chart[o] = r;
				}
				if(chart[1] == 5 || chart[5] == 1) exception = true;
			}
			while(exception == true);

//check chart see if it matces required newe number
			if(r==4)
			{
				m_scoring[1] = chart[1];
				m_scoring[2] = chart[2];
				m_scoring[3] = chart[3];
				m_scoring[4] = chart[4];
				m_scoring[5] = chart[5];
			}
			else if(r==5)
			{
				m_shooting[1] = chart[1];
				m_shooting[2] = chart[2];
				m_shooting[3] = chart[3];
				m_shooting[4] = chart[4];
				m_shooting[5] = chart[5];
			}
			else if(r==6)
			{
				m_rebounding[1] = chart[1];
				m_rebounding[2] = chart[2];
				m_rebounding[3] = chart[3];
				m_rebounding[4] = chart[4];
				m_rebounding[5] = chart[5];
			}
			else if(r==7)
			{
				m_passing[1] = chart[1];
				m_passing[2] = chart[2];
				m_passing[3] = chart[3];
				m_passing[4] = chart[4];
				m_passing[5] = chart[5];
			}
			else if(r==8)
			{
				m_defense[1] = chart[1];
				m_defense[2] = chart[2];
				m_defense[3] = chart[3];
				m_defense[4] = chart[4];
				m_defense[5] = chart[5];
			}
			else if(r==1)
			{
				m_pot1[1] = chart[1];
				m_pot1[2] = chart[2];
				m_pot1[3] = chart[3];
				m_pot1[4] = chart[4];
				m_pot1[5] = chart[5];
			}
			else if(r==2)
			{
				m_pot2[1] = chart[1];
				m_pot2[2] = chart[2];
				m_pot2[3] = chart[3];
				m_pot2[4] = chart[4];
				m_pot2[5] = chart[5];
			}
			else if(r==3)
			{
				m_effort[1] = chart[1];
				m_effort[2] = chart[2];
				m_effort[3] = chart[3];
				m_effort[4] = chart[4];
				m_effort[5] = chart[5];
			}





if(r==1)
{
	SetPot1Rating();
	if(m_pot1Rating == wanted) chart_set = true;
}
else if(r==2)
{
	SetPot2Rating();
	if(m_pot2Rating == wanted) chart_set = true;
}
else if(r==3)
{
	SetEffortRating();
	if(m_effortRating == wanted) chart_set = true;
}
else if(r==4)
{
	SetScoringRating();
	if(m_scoringRating == wanted) chart_set = true;
}
else if(r==5)
{
	SetShootingRating();
	if(m_shootingRating == wanted) chart_set = true;
}
else if(r==6)
{
	SetReboundingRating();
	if(m_reboundingRating == wanted) chart_set = true;
}
else if(r==7)
{
	SetPassingRating();
	if(m_passingRating == wanted) chart_set = true;
}
else if(r==8)
{
	SetDefenseRating();
	if(m_defenseRating == wanted) chart_set = true;
}


}
while(chart_set == false);
}
}

void CStaff::SetRatings()
{
	SetPot1Rating();
	SetPot2Rating();
	SetEffortRating();
	SetScoringRating();
	SetShootingRating();
	SetReboundingRating();
	SetPassingRating();
	SetDefenseRating();
}

void CStaff::SetPot1Rating()
{
	m_pot1Rating = 0;
	for(int i=1; i<=5; i++)
	{
		m_pot1Rating = m_pot1Rating + abs(m_pot1[i] - i);
	}

	m_pot1Rating = 8 - (m_pot1Rating + 2) / 2;
}

void CStaff::SetPot2Rating()
{
	m_pot2Rating = 0;
	for(int i=1; i<=5; i++)
	{
		m_pot2Rating = m_pot2Rating + abs(m_pot2[i] - i);
	}
	m_pot2Rating = 8 - (m_pot2Rating + 2) / 2;
}

void CStaff::SetEffortRating()
{
	m_effortRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_effortRating = m_effortRating + abs(m_effort[i] - i);
	}
	m_effortRating = 8 - (m_effortRating + 2) / 2;
}


void CStaff::SetScoringRating()
{
	m_scoringRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_scoringRating = m_scoringRating + abs(m_scoring[i] - i);
	}
	m_scoringRating = 8 - (m_scoringRating + 2) / 2;
}

void CStaff::SetShootingRating()
{
	m_shootingRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_shootingRating = m_shootingRating + abs(m_shooting[i] - i);
	}
	m_shootingRating = 8 - (m_shootingRating + 2) / 2;
}

void CStaff::SetReboundingRating()
{

	m_reboundingRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_reboundingRating = m_reboundingRating + abs(m_rebounding[i] - i);
	}
	m_reboundingRating = 8 - (m_reboundingRating + 2) / 2;
}

void CStaff::SetPassingRating()
{

	m_passingRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_passingRating = m_passingRating + abs(m_passing[i] - i);
	}
	m_passingRating = 8 - (m_passingRating + 2) / 2;
}
void CStaff::SetDefenseRating()
{
	m_defenseRating = 0;
	for(int i=1; i<=5; i++)
	{
		m_defenseRating = m_defenseRating + abs(m_defense[i] - i);
	}
	m_defenseRating = 8 - (m_defenseRating + 2) / 2;	
}




int CStaff::AdjustRating(int rating, int prime, int max)
{
	bool improve = false;
	bool decline = false;
	bool change = false;
	int f1 = 75, f2 = 600;
	if(m_status != "") { f1 = 60; f2 = 480; }
	int n = IntRandom(f1);
	if(m_age <= prime && n <= (2 + m_power)) {improve = true; change = true;}
	if(m_age > prime && n <= (2 + (6-m_power))) {decline = true; change = true;}

	n = IntRandom(f2);
	if(m_age <= prime && n <= (2 + (6-m_power))) {decline = true; change = true;}
	if(m_age > prime && n <= (2 + m_power)) {decline = false; change = true;}

	if(change == true && decline == true && rating > 1) rating = rating - 1;
	else if(change == true && decline == false && rating < max) rating = rating + 1;

	return rating;
}

//void CStaff::CreateReport(CPlayer m_player)
//{


//}



