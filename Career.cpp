#include "stdafx.h"
//#include "constants.h"
//#include "constants.h"
//#include "resource.h"
#include "bball.h"



#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 

#include <time.h>

CCareer::CCareer()
{
	m_actual = new CPlayer[1441];
	for(int i=0; i<=1440; i++)
	{
		PrimeAge[i] = 0;
		Pot1[i] = 0;
		Pot2[i] = 0;
		Effort[i] = 0;
	}
	m_path = "";
	m_leagueName = "";
}

CCareer::~CCareer()
{
	delete [] m_actual;
}



int CCareer::GetCurrentID() //ID tracks number of players in career file
{
	char s[129];
	CString pFileName = m_path + m_leagueName + ".car";
	CFile file(	pFileName, CFile::modeRead);	
 	int bytes = file.Read(s, 5);
  	s[bytes] = 0;
	int id = atoi(s);
	file.Close();  
 	return id; 
}  
 
void CCareer::SetupID() //ID tracks number of players in career file
{   

   	
 
	int currentID = 0;
	int id = 0;
	for(int i=0; i<=1440; i++)
	{ 
	 	  
		CString name =  m_actual[i].m_name;

		if(name != "")
		{
			currentID = currentID + 1;
			id = currentID;
		}
		else id = 0;
		m_actual[i].SetID(id);

	}
    
	WriteCurrentID(currentID);

}

void CCareer::WriteCareerStats() 
{
      
char s[129];
CString buffer;
CString pFileName = m_path + m_leagueName + ".car";
CFile file(	pFileName, CFile::modeReadWrite);	
for(int i=1; i<=1440; i++)
{ 
//	dlgProgress.m_progress.SetPos(i/29 + 1);
 	int id = m_actual[i].GetID();
	if(id<1) continue;
	CString actual_name = m_actual[i].GetName();

	int current_age = m_actual[i].GetAge();
			long int seek = id*2500 + 1; 
			file.Seek( seek, CFile::begin);
			int bytes = file.Read(s, 2);
			s[bytes] = 0;
			//write current year
			int year = atoi(s)+1;
			if(year > 24) year = 24;


			file.Seek( seek, CFile::begin);
			buffer.Format("%d", year);
			buffer = buffer + "                ";
			file.Write(buffer, 2);
		

			int pt1 = m_actual[i].m_pot1;
			int pt2 = m_actual[i].m_pot2;
			int eff = m_actual[i].m_effort;
			int prime = m_actual[i].m_prime;


		    PrimeAge[i] = prime;
			Pot1[i] = pt1;
			Pot2[i] = pt2;
			Effort[i] = eff;

			buffer.Format("%d", prime);
			buffer = buffer + "                ";
			file.Write(buffer, 2);

			buffer.Format("%d", pt1);
			buffer = buffer + "                ";
			file.Write(buffer, 1);
			
			buffer.Format("%d", pt2);
			buffer = buffer + "                ";
			file.Write(buffer, 1);

			buffer.Format("%d", eff);
			buffer = buffer + "                ";
			file.Write(buffer, 1);
			
			actual_name = actual_name + "                 ";
			file.Write(actual_name, 16);


			//write stats

		
		seek = id*2500 + 24 + (year-1)*100;
		file.Seek( seek, CFile::begin);
	
		buffer.Format("%d", m_currentYear);
		buffer = buffer + "    ";
		file.Write(buffer, 4);

		file.Write(m_actual[i].GetTeam() + "                ", 16); 
		file.Write(m_actual[i].GetName() + "                ", 16); 
		file.Write(m_actual[i].GetPos() + "  ", 2); 
		int injury = m_actual[i].GetInjury();
		buffer.Format("%d", injury);
		buffer = buffer + "    ";
		file.Write( buffer, 2);		
		int games = m_actual[i].m_sim_games;
		buffer.Format("%d", games);
		buffer = buffer + "    ";
		file.Write( buffer, 2);
		int min = m_actual[i].m_sim_min;
		buffer.Format("%d", min);
		buffer = buffer + "    ";
		file.Write( buffer, 4);		
		int fgm = m_actual[i].m_sim_fgm;
		buffer.Format("%d", fgm);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int fga = m_actual[i].m_sim_fga;
		buffer.Format("%d", fga);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int ftm = m_actual[i].m_sim_ftm;		
		buffer.Format("%d", ftm);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int fta = m_actual[i].m_sim_fta;		
		buffer.Format("%d", fta);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int tfgm = m_actual[i].m_sim_tfgm;		
		buffer.Format("%d", tfgm);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int tfga = m_actual[i].m_sim_tfga;		
		buffer.Format("%d", tfga);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int oreb = m_actual[i].m_sim_oreb;		
		buffer.Format("%d", oreb);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int reb = m_actual[i].m_sim_reb;		
		buffer.Format("%d", reb);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int ast = m_actual[i].m_sim_ast;		
		buffer.Format("%d", ast);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int stl = m_actual[i].m_sim_stl;		
		buffer.Format("%d", stl);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int to = m_actual[i].m_sim_to; 		
		buffer.Format("%d", to);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int blk = m_actual[i].m_sim_blk;		
		buffer.Format("%d", blk);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
		int pf = m_actual[i].m_sim_pf;		
		buffer.Format("%d", pf);
		buffer = buffer + "    ";
		file.Write( buffer, 4);
}
}



void CCareer::WriteCurrentID(int id) 
{
	CString buffer;
	CString pFileName = m_path + m_leagueName + ".car";
	CFile file(	pFileName, CFile::modeWrite);	
	buffer.Format("%d", id);
	buffer = buffer + "      ";
	file.Write( buffer, 5);
	file.Close();
}

void CCareer::AdjustScoring()
{
		double tG = 0, tMin = 0, tFgm = 0, tFga = 0, tTfga = 0, tTfgm = 0, tFtm = 0,
			tFta = 0, tOreb = 0, tDreb = 0, tAst = 0, tStl = 0, tTo = 0, tBlk = 0, tPf = 0;
		double avgG = 0, avgMin = 0, avgFga = 0, avgFgm = 0, avgFta = 0, avgFtm = 0, avgTfgm = 0, avgTfga = 0, avgTru = 0, avgOreb = 0, avgDreb = 0, avgAst = 0, avgStl = 0, avgTo = 0, avgBlk = 0, avgPf = 0;

	long int min_before_prime = 0, min_at_prime = 0, min_after_prime = 0;

	for(int i=0; i<=1440; i++)
	{

		CString name = m_actual[i].GetName();
		if(name == "") continue;


		int g = m_actual[i].GetGames();
		int min = m_actual[i].GetMin();
		int prime = m_actual[i].m_prime;

		double freak = 0;
		do
		{
			freak = Random(1);
			if(freak < .5) prime = prime + 1;
		}
		while ( freak < .5);

		
		int age = m_actual[i].m_age;
		if(prime == age) min_at_prime = min_at_prime + min;
		else if(prime < age) min_before_prime = min_before_prime + min;
		else if(prime > age) min_after_prime = min_after_prime + min;
		
		

		int fgm = m_actual[i].GetFgm() - m_actual[i].GetTfgm();
		int fga = m_actual[i].GetFga() - m_actual[i].GetTfga();
		int tgm = m_actual[i].GetTfgm();
		int tga = m_actual[i].GetTfga();
		int ftm = m_actual[i].GetFtm();
		int fta = m_actual[i].GetFta();
	    int orb = m_actual[i].GetOreb();
		int drb = m_actual[i].GetReb() - orb;
		int ast = m_actual[i].GetAst();
		int stl = m_actual[i].GetStl();
		int to = m_actual[i].GetTo();
		int blk = m_actual[i].GetBlk();
		int pf = m_actual[i].GetPf();
		
		if(m_actual[i].GetName() != "" && m_actual[i].GetMin() > (m_actual[i].GetGames()*2))
		{

		avgG = avgG + (double)g;
		avgMin = avgMin + double(min);
		/*avgFgm = avgFgm + double(fgm);
		avgFga = avgFga + double(fga);
		avgFtm = avgFtm + double(ftm);
		avgFta = avgFta + double(fta);
		avgTfgm= avgTfgm+ double(tgm);
		avgTfga= avgTfga+ double(tga);
		avgOreb= avgOreb+ double(orb);
		avgDreb= avgDreb+ double(drb) + double(orb);
		avgAst = avgAst + double(ast);
		avgStl = avgStl + double(stl);
		avgTo  = avgTo  + double(to );
		avgBlk = avgBlk + double(blk);
		avgPf  = avgPf  + double(pf );*/

		}

	}




	avgMin = avgMin / avgG;


	double factor_adj = double(min_before_prime) / double(min_after_prime);
	int current_team = 0;
	for(int i=0; i<=1440; i++)
	{
		current_team = (i-1)/30;
		if(current_team > (m_numberteams - 1)) current_team = IntRandom(m_numberteams) - 1;		

		CString name = m_actual[i].GetName();
		if(name == "") continue;
		CString pos = m_actual[i].GetPos();
		int po = 1;
		if(pos == "SG") po = 2;
		else if(pos == "SF") po = 3;
		else if(pos == "PF") po = 4;
		else if(pos == " C") po = 5;
		int g = m_actual[i].GetGames();
		int min = m_actual[i].GetMin();
		int orig_min = m_actual[i].GetMin();
		double mpg = double(min)/double(g);
	    int orb = m_actual[i].GetOreb();
		int fga = m_actual[i].GetFga() - m_actual[i].GetTfga();
		int fgm = m_actual[i].GetFgm() - m_actual[i].GetTfgm();
		double tmpPct = double(fgm)/double(fga)*1000;
		if(fga < orb)
		{
			fga = orb;
			fgm = int(tmpPct/1000.*double(fga));
		}
		double pct = double(fgm)/double(fga)*1000;
		int fgp = int(pct);
		int tgm = m_actual[i].GetTfgm();

		int tga = m_actual[i].GetTfga();
		int orig_tga = tga;
		
		pct = double(tgm)/double(tga)*1000;
		int tgp = int(pct);
		int fta = m_actual[i].GetFta();
		int ftm = m_actual[i].GetFtm();
		pct = double(ftm)/double(fta)*1000;
		int tmpOrb = int(double(orb)*.25);
		if(fta < tmpOrb)
		{
			fta = tmpOrb;
			ftm = int(pct/1000.*double(fta));
		}
		int ftp = int(pct);
	
		int drb = m_actual[i].GetReb() - orb;
		int ast = m_actual[i].GetAst();
		int stl = m_actual[i].GetStl();
		int to = m_actual[i].GetTo();
		int blk = m_actual[i].GetBlk();
		int pf = m_actual[i].GetPf();

		double before = m_actual[i].GetTrueRatingSimple();

		//temp stuff
		int prime = PrimeAge[i];




		double pt1 = double(Pot1[i]);
		double pt2 = double(Pot2[i]);  
		double eff = double(Effort[i]);

//		pt1 = 3;
//		pt2 = 3;
//		eff = 3;

		if(current_team <= 31)
		{
			pt1 = pt1 - 1 + (double(m_coach[current_team].m_coachPot1) - 1) / 2;
			pt2 = pt2 - 1 + (double(m_coach[current_team].m_coachPot2) - 1) / 2;
			eff = eff - 1 + (double(m_coach[current_team].m_coachEffort) - 1) / 2;
			if(pt1 > 5) pt1 = 5;
			else if(pt1 < 1) pt1 = 1;
			if(pt2 > 5) pt2 = 5;
			else if(pt2 < 1) pt2 = 1;
			if(eff > 5) eff = 5;
			else if(eff < 1) eff = 1;
		}
		

		int yrs_to_prime = prime - m_actual[i].GetAge();

		double coach_effect = 0;
		
		int intangible = m_actual[i].m_effort;
		double factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1)*(1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachScoring) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachScoring)) / 10);
		factor = 1 + coach_effect;
		fga = int(double(fga)*factor);
		
		factor = SetImprovementVariable(yrs_to_prime, 2, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		if(factor > 1.125) factor = 9/8;
		else if(factor < 7/8) factor = 7/8;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachShooting) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachShooting)) / 10);
		factor = 1 + coach_effect;
		fgp = fgp + int( (factor - 1)*(1000 - double(fgp)) );
		if(fgp>600) fgp = 600 + IntRandom(10*int(pt1));
		else if(fgp<275) fgp = 250 + IntRandom(50);
		fgm = int(double(fga) * (double(fgp)/1000));

		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1) * (1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachScoring) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachScoring)) / 10);
		factor = 1 + coach_effect;
		fta = int(double(fta)*factor);
		
		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachShooting) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachShooting)) / 10);
		factor = 1 + coach_effect;
		ftp = ftp + int( (factor - 1)*(1000 - double(ftp)) ) +  int(Random(eff*4) - 6);// effort counts
		if(ftp >= 950) ftp = 940 + IntRandom(20);
		else if(ftp < 333) ftp = 300 + IntRandom(50);
		ftm = int(double(fta) * (double(ftp)/1000));

		double prime_factor = 1;
		if(yrs_to_prime < 0) prime_factor = 2;//older players do not really lose that skill at 3's

		factor = SetImprovementVariable(yrs_to_prime, prime_factor, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1) * (1.0);
		bool exception = false;
		double tgaPer48 = double(tga) / double(min) * 48; 
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachScoring) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachScoring)) / 10);
		factor = 1 + coach_effect;
		tga = int(double(tga)*factor);
		if(tga > 0)
		{
			if( (min/tga) < 4)// too many 3's
			{
				double f = (double)min / 4 * ( .9 + Random(.2));
				tga = int(f);
			}
		}
		

		prime_factor = 1;
		if(yrs_to_prime < 0 || tgp > 350) prime_factor = 2;//older players do not really lose that skill at 3's
		factor = SetImprovementVariable(yrs_to_prime, prime_factor, pt1, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		int old_tgp = tgp;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachShooting) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachShooting)) / 10);
		factor = 1 + coach_effect;
		tgp =  tgp + int(350 * factor - 350);
		tgp = tgp + int(Random(eff*2) - 3);
//		tgp = tgp + int( (factor - 1)*(1000 - double(tgp)) ) + int(Random(eff*2) - 3);
		tga = int(double(tgp)/double(old_tgp)*double(tga));
        if(tga <= 3) 
		{
			tga = IntRandom(3);
			if(tga == 1) {tga = IntRandom(6) + 3; tgm = IntRandom(2) - 1;}
			if(tga == 2) {tga = IntRandom(9) + 9; tgm = IntRandom(3);}
			if(tga == 3) {tga = IntRandom(3); tgm = 0;}
			if(((double)tga/2) > ((double)orig_tga))
			{
				tga = int((double)orig_tga*2);
				if(orig_tga == 0) tga = IntRandom(3);
			}
		    tgp = int(double(tgm)/double(tga)*1000.);
		}
        if(exception == true && tgp < 300) tgp = 300 + IntRandom(60);
		if(tgp>400) tgp = 400 + IntRandom(10*int(pt2));
		else if(tgp<0) tgp = 0;
	    if(double(tgp) < tgaPer48*12.)
		{
            tgp = int(tgaPer48*12.);
            if(tgp > 240) tgp = 230 + IntRandom(20);
		}
		tgm = int(double(tga) * (double(tgp)/1000));
		fga = fga + tga;
		fgm = fgm + tgm;

		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1) * (1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachRebounding) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachRebounding)) / 10);
		factor = 1 + coach_effect;
		orb = int(double(orb)*factor);
		
		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1) * (1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachRebounding) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachRebounding)) / 10);
		factor = 1 + coach_effect;
		drb = int(double(drb)*factor);
		double rebFactor = double(orb)/(double(drb)+double(orb));
		if(rebFactor < 1./12. && pos == "PG") orb = int( (double(drb)+double(orb))*1./12.);
		else if(rebFactor < 1./8. && (pos == "SG" || pos == "SF")) orb = int( (double(drb)+double(orb))*1./8.);
		else if(rebFactor < 1./6.) orb = int( (double(drb)+double(orb))*1./6.);

		double oldAst = double(ast);
        double ToAst = double(to)/oldAst;
		
		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1)* (1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachPassing) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachPassing)) / 10);
		factor = 1 + coach_effect;
		ast = int(double(ast)*factor);
		
		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1) * 1.2;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachDefense) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachDefense)) / 10);
		factor = 1 + coach_effect;

		double stl48 = double(stl)/double(min)*48;
		if(stl48 < .5)
		{
			stl48 = .5;
			stl = int(double(stl48) * double(min) / 48.);
			factor = .9 + Random(.2);
		}
		else if(stl48 > 4)
		{
			stl48 = 4;
			stl = int(double(stl48) * double(min) / 48.);
			factor = .9 + Random(.2);
		}
		stl = int(double(stl)*factor);
		
		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;



		double to48 = double(to)/double(min)*48;
		if(to48 < 1.)
		{
			to48 = 1.;
			to = int(double(to48) * double(min) / 48.);
			factor = .9 + Random(.2);
		}
		else if(to48 > 8.)
		{
			to48 = 8.;
			to = int(double(to48) * double(min) / 48.);
			factor = .9 + Random(.2);
		}

		double add = (double(ast) - oldAst)*ToAst;
		if(add < 0) add = 0;		
		double oldTo = double(to);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1)*50./100.;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachPassing) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachPassing)) / 10);
		factor = 1 + coach_effect;
		to = int( double(to)*(2- factor) + add);

		//adjust low assist
		if(to > 0)
		{
			double adj_lo_ast = double(ast)/double(to);
			if(adj_lo_ast < .1)
			{
				double adj_ast = double(to)/10;
				ast = int(adj_ast);
			}
		}

	
		factor = SetImprovementVariable(yrs_to_prime, 1, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		factor = 1 + (factor - 1)*(1.0);
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachDefense) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachDefense)) / 10);
		factor = 1 + coach_effect;
		blk = int(double(blk)*factor);

		factor = SetImprovementVariable(yrs_to_prime, 4, pt2, intangible);
		if(yrs_to_prime > 0) factor = 1 + (factor - 1)*factor_adj;
		if(factor >= 1)
			coach_effect = (factor - 1) *  ( 1 + (double(m_coach[current_team].m_coachDefense) - 3) / 10);
		else 
			coach_effect = (factor - 1) *  ( 1 + (3 - double(m_coach[current_team].m_coachDefense)) / 10);
		factor = 1 + coach_effect;
		pf = int(double(pf)*(2-factor));

		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(IntRandom(18) <= 3 && factor > 1) factor = 1;
		else if(IntRandom(18) <= 3 && factor <= 1) factor = -1;

		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)

		int o = int(double(m_actual[i].GetMovOff()) + factor);
		if(o > 9) o = 9; else if(o < 1) o = 1;

		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(IntRandom(18) <= (6 - po) && factor > 1) factor = 1;
		else if(IntRandom(18) <= (6 - po) && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int p = int(double(m_actual[i].GetPenOff()) + factor);
		if(p > 9) p = 9; else if(p < 1) p = 1;
						

		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(IntRandom(18) <= po && factor > 1) factor = 1;
		else if(IntRandom(18) <= po && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int io = int(double(m_actual[i].GetPostOff()) + factor);
		if(io > 9) io = 9; else if(io < 1) io = 1;

		if(factor > 0) m_actual[i].m_weight = m_actual[i].m_weight + 1;
		else m_actual[i].m_weight = m_actual[i].m_weight - 1;



		factor = SetImprovementVariable(yrs_to_prime, 1, pt1, intangible);
		if(IntRandom(18) <= (6 - po) && factor > 1) factor = 1;
		else if(IntRandom(18) <= (6 - po) && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int f = int(double(m_actual[i].GetTransOff()) + factor);
		if(f > 9) f = 9; else if(f < 1) f = 1;

		if(factor > 0) m_actual[i].m_weight = m_actual[i].m_weight - 1;
		else m_actual[i].m_weight = m_actual[i].m_weight + 1;


		factor = SetImprovementVariable(yrs_to_prime, 1, eff, intangible);
		if(IntRandom(18) <= 3 && factor > 1) factor = 1;
		else if(IntRandom(18) <= 3 && factor <= 1) factor = -1;		
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int od = int(double(m_actual[i].GetMovDef()) + factor);
		if(od> 9) od= 9; else if(od< 1) od= 1;

		factor = SetImprovementVariable(yrs_to_prime, 1, eff, intangible);
		if(IntRandom(18) <= (6 - po) && factor > 1) factor = 1;
		else if(IntRandom(18) <= (6 - po) && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int pd = int(double(m_actual[i].GetPenDef()) + factor);
		if(pd> 9) pd= 9; else if(pd< 1) pd= 1;

		factor = SetImprovementVariable(yrs_to_prime, 1, eff, intangible);
		if(IntRandom(18) <= po && factor > 1) factor = 1;
		else if(IntRandom(18) <= po && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// factor = -(-2*-1) or -(-2*1)
		int id = int(double(m_actual[i].GetPostDef()) + factor);
		if(id> 9) id= 9; else if(id< 1) id= 1;
		
		if(factor > 0) m_actual[i].m_weight = m_actual[i].m_weight + 1;
		else m_actual[i].m_weight = m_actual[i].m_weight - 1;




		factor = SetImprovementVariable(yrs_to_prime, 1, eff, intangible);
		if(IntRandom(18) <= (6 - po) && factor > 1) factor = 1;
		else if(IntRandom(18) <= (6 - po) && factor <= 1) factor = -1;
		if(factor != 1 && factor != -1) factor = 0;
		else if(IntRandom(18) <= 1) factor = -(-2*factor);// 
		int fd = int(double(m_actual[i].GetTransDef()) + factor);
		if(fd> 9) fd= 9; else if(fd< 1) fd= 1;

		if(factor > 0) m_actual[i].m_weight = m_actual[i].m_weight - 1;
		else m_actual[i].m_weight = m_actual[i].m_weight + 1;
		//players lose weight when trans improves and post drops


		m_actual[i].SetGames(g);
		m_actual[i].SetMin(min);
		m_actual[i].SetFgm(fgm);
		m_actual[i].SetFga(fga);
		m_actual[i].SetFtm(ftm);
		m_actual[i].SetFta(fta);
		m_actual[i].SetTfgm(tgm);
		m_actual[i].SetTfga(tga);
		m_actual[i].SetOreb(orb);
		m_actual[i].SetReb(orb+drb);
		m_actual[i].SetAst(ast);
		m_actual[i].SetStl(stl);
		m_actual[i].SetTo(to);
		m_actual[i].SetBlk(blk);
		m_actual[i].SetPf(pf);
		m_actual[i].SetMovOff(o);
		m_actual[i].SetPenOff(p);
		m_actual[i].SetPostOff(io);
		m_actual[i].SetTransOff(f);
		m_actual[i].SetMovDef(od);
		m_actual[i].SetPenDef(pd);
		m_actual[i].SetPostDef(id);
		m_actual[i].SetTransDef(fd);

		m_actual[i].m_weight = m_actual[i].m_weight - 2 + IntRandom(5);
		if(m_actual[i].m_age <= 21)
		{
			if(IntRandom(12) == 1) 
				m_actual[i].m_height = m_actual[i].m_height + 1;
		}
		
		


		m_actual[i].SetTransDef(fd);
		m_actual[i].SetTransDef(fd);
		
		m_actual[i].SetTrueRatingSimple(2);
		double after = m_actual[i].GetTrueRatingSimple();
		
		//mpg increase based on new tru48
			

		double tru48 = after / (double)m_actual[i].m_min * 48;

		//mpg increase based on improving
		double min_adj = 1;
		if(before != 0) min_adj = double(after)/double(before);
		if(after < 0 || before < 0)//neg requires special adjustment
		{
			if(after > before) min_adj = 1 + Random(.1);
			else min_adj = 1 - Random(.08);
		}
		double g_adj = min_adj;
		//min = int(double(min)*min_adj);
		double prev_mpg = double(min)/double(g);
		

		mpg = tru48*3 - 8;
		if (mpg >= 40)
		{
			mpg = 40;
		}
		else if (mpg < 6)
		{
			mpg = 6;
		}

		if(yrs_to_prime < -1 && mpg > prev_mpg) 
		{
				mpg = prev_mpg;// if past prime and minutes based on new tru went up then keep minutes same (so steve nash doesnt increase his minutes after prime)
				if(mpg < 6) mpg = 6;
		}
		mpg = mpg - 1 + Random(2);


		
		double temp = 82;
		if(m_hiG > 0) temp = double(g) / double(m_hiG) * 82; //adjust career mode games to 82 for 82 g season stats

		if(temp <= 70)
		{
			temp = 50 + mpg;
			if(temp >= 70) temp = 70;
		}
		
		
		g = int(double(temp)*g_adj*(.95 + Random(.10)));
		if(g>82) g=82;
		min = int(double(g)*mpg);
		if(min <= 0) min = 1;
		
		fgm = int(double(fgm)/double(orig_min)*min);
		fga = int(double(fga)/double(orig_min)*min);
		tgm = int(double(tgm)/double(orig_min)*min);
		tga = int(double(tga)/double(orig_min)*min);
		ftm = int(double(ftm)/double(orig_min)*min);
		fta = int(double(fta)/double(orig_min)*min);
		orb = int(double(orb)/double(orig_min)*min);
		drb = int(double(drb)/double(orig_min)*min);
		ast = int(double(ast)/double(orig_min)*min);
		stl = int(double(stl)/double(orig_min)*min);
		to  = int(double(to )/double(orig_min)*min);
		blk = int(double(blk)/double(orig_min)*min);
		pf  = int(double(pf )/double(orig_min)*min);
		if(fgm < 0) fgm=0;
		if(fga < 0) fga=0;
		if(tgm < 0) tgm=0;
		if(tga < 0) tga=0;
		if(ftm < 0) ftm=0;
		if(fta < 0) fta=0;
		m_actual[i].SetGames(g);
		m_actual[i].SetMin(min);
		m_actual[i].SetFgm(fgm);
		m_actual[i].SetFga(fga);
		m_actual[i].SetFtm(ftm);
		m_actual[i].SetFta(fta);
		m_actual[i].SetTfgm(tgm);
		m_actual[i].SetTfga(tga);
		m_actual[i].SetOreb(orb);
		m_actual[i].SetReb(orb+drb);
		m_actual[i].SetAst(ast);
		m_actual[i].SetStl(stl);
		m_actual[i].SetTo(to);
		m_actual[i].SetBlk(blk);
		m_actual[i].SetPf(pf);
		m_actual[i].SetGames(g);
		m_actual[i].SetMin(min);

		if(m_actual[i].GetName() != "" && m_actual[i].GetMin() > (m_actual[i].GetGames()*2))
		{

		tG = tG + double(g);
		tMin = tMin + double(min);
		tFgm = tFgm + double(fgm);
		tFga = tFga + double(fga);
		tFtm = tFtm + double(ftm);
		tFta = tFta + double(fta);
		tTfgm= tTfgm+ double(tgm);
		tTfga= tTfga+ double(tga);
		tOreb= tOreb+ double(orb);
		tDreb= tDreb+ double(drb) + double(orb);
		tAst = tAst + double(ast);
		tStl = tStl + double(stl);


		tTo  = tTo  + double(to );
		tBlk = tBlk + double(blk);
		tPf  = tPf  + double(pf );

		}

	}
	tMin = tMin / tG;//test
	tMin = avgMin / tMin;
	tMin = 1;
/*	tFga = avgFga / tFga;
	tFta = avgFta / tFta;
	tTfga = avgTfga / tTfga;
	tOreb = avgOreb / tOreb;
	tDreb = avgDreb / tDreb;
	tAst  = avgAst / tAst;
	tStl  = avgStl / tStl;
	tTo   = avgTo / tTo;
	tBlk  = avgBlk / tBlk;
	tPf   = avgPf / tPf;*/


	double fgPct = 0, ftPct = 0, tfgPct = 0;
	for(int i=0; i<=1440; i++)
	{
		int games = m_actual[i].m_games;
		int min = int((double)m_actual[i].GetMin()*tMin);
		int fgm = int((double)m_actual[i].GetFgm()*tMin);
		int fga = int((double)m_actual[i].GetFga()*tMin);
		int ftm = int((double)m_actual[i].GetFtm()*tMin);
		int fta = int((double)m_actual[i].GetFta()*tMin);
		int tfgm = int((double)m_actual[i].GetTfgm()*tMin);
		int tfga = int((double)m_actual[i].GetTfga()*tMin);
		int oreb = int((double)m_actual[i].GetOreb()*tMin);
		int reb = int((double)m_actual[i].GetReb()*tMin);
		int ast = int((double)m_actual[i].GetAst()*tMin);
		int stl = int((double)m_actual[i].GetStl()*tMin);
		int to = int((double)m_actual[i].GetTo()*tMin);
		int blk = int((double)m_actual[i].GetBlk()*tMin);
		int pf = int((double)m_actual[i].GetPf()*tMin);

		m_actual[i].SetMin(min);
		m_actual[i].SetFgm(fgm);
		m_actual[i].SetFga(fga);
		m_actual[i].SetFtm(ftm);
		m_actual[i].SetFta(fta);
		m_actual[i].SetTfgm(tfgm);
		m_actual[i].SetTfga(tfga);
		m_actual[i].SetOreb(oreb);
		m_actual[i].SetReb(reb);
		m_actual[i].SetAst(ast);
		m_actual[i].SetStl(stl);

		double to_per_48 = (double)to / (double) min * 48.;
		if(to_per_48 < .9) 
		{
			to_per_48 = (Random(1) + .5) / 48. * (double)min;
			to = int(to_per_48) + 1; 
		}


		m_actual[i].SetTo(to);
		m_actual[i].SetBlk(blk);
		m_actual[i].SetPf(pf);


	}

}

double CCareer::SetImprovementVariable(int yrs_to_prime, double adj, double pot, int intangible)
{
	if(pot==0) pot=3;
	double orig_adj = adj;

	yrs_to_prime = yrs_to_prime;
	if(yrs_to_prime == 0) yrs_to_prime = IntRandom(2) * 2 - 3;//change to 1 or -1

//	if(yrs_to_prime < 0) adj = adj*2./3.;
//	if(yrs_to_prime < 0) adj = adj*12./3.;
	if(yrs_to_prime < 0) adj = adj*12.;
	else if(yrs_to_prime > 0) adj = adj*2./3.;//lower adj is better for improving/more decline

	double major_change = Random(72);
	double temp_before = ((double)intangible+1.) / 4.;
	double temp_after = (7.-(double)intangible) / 4.;
	if(major_change <= (temp_before*1.) && yrs_to_prime > 0)
		adj = adj * 1/4;
	else if(major_change <= (temp_before*13) && yrs_to_prime > 0)
		adj = adj * 1/2;
	else if(major_change <= (temp_after*14) && yrs_to_prime < 0)
		adj = adj * 3/4;

	int tmp_yrs_to_prime = abs(yrs_to_prime);

	if(tmp_yrs_to_prime > 3)
	{
		tmp_yrs_to_prime = 8 - tmp_yrs_to_prime;
		if(tmp_yrs_to_prime < 1) tmp_yrs_to_prime = 1;

	}


	double float_yrs_to_prime = tmp_yrs_to_prime;

	if(yrs_to_prime == -1) 
		float_yrs_to_prime = 1./3.;
	else if(yrs_to_prime == -2) 
		float_yrs_to_prime = 2./3.;
	else if(yrs_to_prime == -3) 
		float_yrs_to_prime = 1.;
	else if(yrs_to_prime == -4) 
		float_yrs_to_prime = 4./3.;
	else if(yrs_to_prime == -5) 
		float_yrs_to_prime = 5./3.;
	else if(yrs_to_prime == -6) 
		float_yrs_to_prime = 2.;
	else if(yrs_to_prime < -6)
			//float_yrs_to_prime = Random(2);
			float_yrs_to_prime = 1 + Random(2);

	//temp
	//if(yrs_to_prime <= -1) 
		//float_yrs_to_prime = 1./3.;



	double factor = float_yrs_to_prime/adj;


	if(yrs_to_prime < 0) pot = (6 - pot);

	double p = (pot+1)/4.;
	
	factor = Random(factor*2*p);


		if(Random(1.) <= 1./12.*p)
		{
			factor = Random(24.) - 12.;
			if(yrs_to_prime < 0) factor = factor / 2.;
			factor = (100. + factor) / 100.;
		}
		else if(yrs_to_prime > 0)
		{
			factor = (100. + factor) / 100.;
		}
		else
		{
			factor = (100. - factor) / 100.;
		}

		
		return factor;
}

void CCareer::ReadNames()
{
	CString pFileName = m_path + "fnames.txt";
  	CStdioFile file(	pFileName, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		file.ReadString(fname[i]);
	}
	file.Close();
	pFileName = m_path + "lnames.txt";
  	CStdioFile f(pFileName, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		f.ReadString(lname[i]);
	}
	f.Close();

}




void CCareer::CreateRandomStaffProfiles()
{
	CString fileName = m_path + m_leagueName + ".fro";




	

	CFileStatus status;
	CFile f( fileName, CFile::modeWrite );

	//create staff names
	f.Seek(300033, CFile::begin ); 
	CString buffer = "0";
	f.Write(buffer, 1);
	CString rookieName[301];

	int n1 = 0, n2 = 0;

	for(int i = 1; i<=300; i++)//change to 96
	{
		do
		{
			n1=IntRandom(1000);
			n2=IntRandom(3000);
		}
		while(fname[n1] == "" || lname[n2] == "");
		rookieName[i] = fname[n1] + " " + lname[n2] + "                 ";
		f.Seek((i-1)*1000, CFile::begin ); 
		f.Write(	rookieName[i], 16);
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
						r = IntRandom(5);
					}
					while(used[r] == true);
					used[r] = true;
					chart[o] = r;
				}
				if(chart[1] == 5 || chart[5] == 1) exception = true;
			}
			while(exception == true);
			for(int o=1; o<=5; o++)
			{
				CString buffer;
				buffer.Format("%d", chart[o]);
				buffer = buffer + "  ";
				f.Write( buffer, 2);		
			}

		}
		CString buffer;
		int r = IntRandom(5);
		buffer.Format("%d", r);
		buffer = buffer + "  ";
		for(int tmp=1; tmp<=30; tmp++)
		{
		    int r = IntRandom(5);
		    buffer.Format("%d", r);
		    buffer = buffer + "  ";
			f.Write( buffer, 2);//control of staff member		
		}








			CString string;
	

			int seek = (i-1)*1000+151;
			f.Seek( seek, CFile::begin);
			for(r = 151; r<=200; r++)
			{
				int n = IntRandom(5);
				string.Format("%d", n);
				f.Write(string, 1);//write random ratings to be used later (151-152 used so far)
			}
			seek = (i-1)*1000+201;
			f.Seek( seek, CFile::begin);
			int id = i;
			string.Format("%d", id);
			string = string + "    ";
			f.Write(string, 5);//write staff id
			int age = IntRandom(32)+32;
			if(Random(1) < .01) age = IntRandom(59) + 20;
			string.Format("%d", age);
			string = string + "    ";
			f.Write(string, 2);//write age
			seek = (i-1)*1000+208;
			f.Seek( seek, CFile::begin);
			int score = 16;
			string.Format("%d", score);
			string = string + "    ";
			f.Write(string, 3);//write current status of member (default is 8)

			seek = (i-1)*1000+301;
			f.Seek( seek, CFile::begin);
			int roster = 0;
			if(i <= 32)//set owner only on first 100 members (owner stuff sorta hidden here)
			{
				avg.m_owner[i-1].SetRosterValue(avg.m_actual, (i-1)*30+1);
				roster = avg.m_owner[i-1].m_rosterValue;
			}
			string.Format("%d", roster);
			string = string + "    ";
			f.Write(string, 5);

			seek = (i-1)*1000+306;
			f.Seek( seek, CFile::begin);
			int patience = IntRandom(5);
			string.Format("%d", patience);
			string = string + "    ";
			f.Write(string, 1);

			seek = (i-1)*1000+307;
			f.Seek( seek, CFile::begin);
			int firing_scout = 8;
			string.Format("%d", firing_scout);
			string = string + "    ";
			f.Write(string, 3);

			seek = (i-1)*1000+310;
			f.Seek( seek, CFile::begin);
			int firing_coach = 8;
			string.Format("%d", firing_coach);
			string = string + "    ";
			f.Write(string, 3);

			seek = (i-1)*1000+313;
			f.Seek( seek, CFile::begin);
			int firing_gm = 8;
			string.Format("%d", firing_gm);
			string = string + "    ";
			f.Write(string, 3);

			seek = (i-1)*1000+316;
			f.Seek( seek, CFile::begin);
			int win = 0;
			string.Format("%d", win);
			string = string + "      ";
			f.Write(string, 6);

			seek = (i-1)*1000+322;
			f.Seek( seek, CFile::begin);
			int loss = 0;
			string.Format("%d", loss);
			string = string + "      ";
			f.Write(string, 6);

			







	}
	f.Close();
}





CString CCareer::CreateName()
{
	int n1 = 0, n2 = 0;
	do
	{
		n1=IntRandom(1000);
		n2=IntRandom(3000);
	}
	while((fname[n1] == "" || lname[n2] == "") || (fname[n1] == lname[n2]));

	CString name = fname[n1] + " " + lname[n2];
	return name;	
}

void CCareer::ReadCareerStats(CPlayer *m_stats, CString pFileName, int slot, int &round, int &pos, int &overall, int &yrs_pro)
{

CString buffer;
CFile file(	pFileName, CFile::modeRead);	
char s[17];
int yrsPro = 0;

for(int y=0; y<=23; y++)
{
	long int seek = slot*2500 + 24 + y*100; 
	file.Seek( seek, CFile::begin);
	int bytes = file.Read(s, 4);
	s[bytes] = 0;
	int number = atoi(s);
	m_stats[y].SetRosterNumber(number);//set year

	bytes = file.Read(s, 16);
	s[bytes] = 0;
	m_stats[y].SetTeam(CString(s));//set team

	file.Seek( seek+40, CFile::begin);
	bytes = file.Read(s, 2);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetGames(number);
	if(number > 0) yrsPro = yrsPro + 1;


	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetMin(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFtm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetFta(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTfgm(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTfga(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetOreb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetReb(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetAst(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetStl(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetTo(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetBlk(number);

	bytes = file.Read(s, 4);
	s[bytes] = 0;
	number = atoi(s);
	m_stats[y].SetPf(number);
}
	long int seek = slot*2500 + 26 + 24*100; 
	file.Seek( seek, CFile::begin);

	int bytes = file.Read(s, 1);
	s[bytes] = 0;
	round = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	pos = atoi(s);

	bytes = file.Read(s, 2);
	s[bytes] = 0;
	overall = atoi(s);


    file.Close();

	yrs_pro = yrsPro;
}


double CCareer::Random(double n)
{
	double number = rand();
	number /= RAND_MAX + 1;
	number *= n;
	return number;
}

