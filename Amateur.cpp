// Amateur.cpp: implementation of the CAmateur class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bball.h"
#include "Amateur.h"
//#include "Player.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAmateur::CAmateur()
{

}

CAmateur::~CAmateur()
{

}




void CAmateur::ReadNames(CString f_file_name, CString l_file_name, CString *fname, CString *lname)
{
	CStdioFile file(f_file_name, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		file.ReadString(fname[i]);
	}
	file.Close();
  	CStdioFile f(l_file_name, CFile::modeRead);
			

	for(int i = 1; i<=3000; i++)
	{
		f.ReadString(lname[i]);
	}
	f.Close();

	

}

void CAmateur::CreateRookies(CString *fname, CString *lname, CPlayer *actual, int hi_g)
{

	CString first, last;

	int n1=0, n2=0;


	CString rookieName[961];
	for(int i = 1; i<=400; i++)//change to 96
	{
		do
		{
			n1=IntRandom(1000);
			n2=IntRandom(3000);
		}
		while((fname[n1] == "" || lname[n2] == "") || (fname[n1] == lname[n2]));
		rookieName[i] = fname[n1] + " " + lname[n2];
	
	int p[21] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0};
	int pos = IntRandom(5);
	CString ps[6] = {"","PG","SG","SF","PF"," C"};

	for(int j=1; j<=20; j++)
	{
		int n = 0;
		int stat = j;
		bool ok = false;
		do
		{
			n = IntRandom(960);
			int min_games = int(double(hi_g)*1/4);
			if(actual[n].GetName() != "" && actual[n].GetGames() >= min_games && 
				actual[n].GetMin() > (hi_g*8)) ok = false;
			if(pos == 1 && actual[n].GetPos() == "PG") ok = true;
			else if(pos == 2 && actual[n].GetPos() == "SG") ok = true;
			else if(pos == 3 && actual[n].GetPos() == "SF") ok = true;
			else if(pos == 4 && actual[n].GetPos() == "PF") ok = true;
			else if(pos == 5 && actual[n].GetPos() == " C") ok = true;
			else if(pos == 4 && actual[n].GetPos() == " C" && (stat==3 || stat==4 || stat==2)) ok = true;
			else if(pos == 5 && actual[n].GetPos() == "PF" && (stat==3 || stat==4 || stat==2)) ok = true;
		}
		while (ok == false);
		p[j] = n;
	}

	int age = 20 + IntRandom(4);
	if(age == 24) age = 18 + IntRandom(6);
	if(age == 24) age = 17 + IntRandom(8);
	int tmp_age = age;
	if(tmp_age > 23) tmp_age = 23;

	double ageFactor = 40./100. + double(tmp_age)/100*2;


	double blow = .75;
	int n_blow = IntRandom(9);
	if(n_blow == 1) blow = 1.;

	double temp = (1. - ageFactor)*2.;
	ageFactor = 1. - temp + Random(temp*blow);


	int ga = actual[p[1]].GetGames();
	double gam = double(ga)/double(hi_g)*82.;
	int games = int(gam);
	double mpg = double(actual[p[1]].GetMin()) / double(games);
	if(mpg > 40) mpg = 38 + Random(2);
	double min = mpg*games;

	double fgm = double(actual[p[2]].GetFgm()) - double(actual[p[2]].GetTfgm());
	double fga = double(actual[p[2]].GetFga()) - double(actual[p[2]].GetTfga());
	double tgm = double(actual[p[3]].GetTfgm());
	double tga = double(actual[p[3]].GetTfga());


	double ftm = double(actual[p[4]].GetFtm());
	double fta = double(actual[p[4]].GetFta());


	double hi = (fga - fta/3/2);
	if(tga > hi && hi > 0)
	{
		double f1 = (fga - fta/3);
		if( f1 > 0)
		{
			double f2 = f1 / fga;
			double f3 = 1 - f2;
			double f4 = Random(f3);
			double f5 = f2 + f4;
			if(f5 < 1)
			{
				tgm = tgm * f5;
				tga = tga * f5;	
			}
		}
	}


	double orb = double(actual[p[5]].GetOreb());
	double drb = double(actual[p[5]].GetReb()) - double(actual[p[5]].GetOreb());
	double ast = double(actual[p[6]].GetAst());
	double stl = double(actual[p[7]].GetStl());
	double to = double(actual[p[8]].GetTo());
	double blk = double(actual[p[9]].GetBlk());
	double pf = double(actual[p[10]].GetPf());

	
	fgm = fgm * ageFactor;
	fga = fga *  ageFactor;
	tgm = tgm * ageFactor;
	tga = tga * ageFactor;
	double ftm_added = 1;
	double fta_added = 1;
	ftm = ftm * (ageFactor*ftm_added);
	fta = fta * (ageFactor*fta_added);
	orb = orb * ageFactor;
	drb = drb * ageFactor;
	ast = ast * ageFactor;
	stl = stl * (1 - (1 - ageFactor)/2);
	to = to  * (2-ageFactor);
	blk = blk * (1 - (1 - ageFactor)/2);
	pf = pf*1.00;
	
	fgm = fgm / double(actual[p[2]].GetMin())*mpg ;
	fga = fga / double(actual[p[2]].GetMin())*mpg ;
	tgm = tgm / double(actual[p[3]].GetMin())*mpg ;
	tga = tga / double(actual[p[3]].GetMin())*mpg ;
	ftm = ftm / double(actual[p[4]].GetMin())*mpg ;
	fta = fta / double(actual[p[4]].GetMin())*mpg ;
	double ftp = ftm/fta;
	
	if(fta > fga) {fta = fga; ftm = fta*ftp;}


	orb = orb / double(actual[p[5]].GetMin())*mpg ;
	drb = drb / double(actual[p[5]].GetMin())*mpg ;
	ast = ast / double(actual[p[6]].GetMin())*mpg ;
	stl = stl / double(actual[p[7]].GetMin())*mpg ;
	to = to / double(actual[p[8]].GetMin())*mpg  ;
	blk = blk / double(actual[p[9]].GetMin())*mpg ;
	pf = pf / double(actual[p[10]].GetMin())*mpg ;

	//ajdust mpg && games
	double tru = actual[i].GetRookieTrue(games, mpg, fgm, fga, tgm, tga, ftm, fta, orb, drb, ast, stl, to, blk, pf);
	double mpg2 = tru * 2.5 + 4 + IntRandom(7);
	if(mpg2 <= 2) mpg2 = 2;
	double factor = mpg2/mpg;
	double fgp = fgm/fga;

	double tgp = tgm/tga;
	fgp = fgp * (1 - (1 - ageFactor)/2) * 1.03;
	ftp = ftp * (1 - (1 - ageFactor)/2) * 1.05;
	tgp = tgp * (1 - (1 - ageFactor)/2) * 1.05;
	fga = fga * factor;
	tga = tga * factor;
	fta = fta * factor;
	orb = orb * factor;
	drb = drb * factor;
	ast = ast * factor;
	stl = stl * factor;
	to = to * factor;
	blk = blk * factor;
	pf = pf * factor;
	if(fgp > (5./9.)) fgm = double( fga * ( double(500 + IntRandom(75))/1000 ));
	else fgm = fga * fgp;
	if(ftp > (8./9.)) ftm = double( fta * ( double(825 + IntRandom(100))/1000 ));
	else ftm = fta * ftp;
	if(tgp > (4./9.)) tgm = double( tga * ( double(325 + IntRandom(100))/1000 ));
	else tgm = tga * tgp;

	if(pf>4) pf = 4 + Random(.5);
	if(to > 0 && ast > 0)
	{
		double at = ast/to;
		if(at > 3) at = 3 + Random(1.);
		to = ast/at;
	}

	double ft_ratio = fta / (fga+orb);
	if(ft_ratio < (1./6.))
	{
		ft_ratio = 1./6. + Random(1./30.);
		double ftp = ftm/fta;
		fta = ft_ratio*(fga+orb);
		ftm = fta*ftp;
	}
	if(to < 0) to = 1;
	actual[1600+i].SetName(rookieName[i]);
	actual[1600+i].SetPos(ps[pos]);
	actual[1600+i].SetAge(age);
	actual[1600+i].SetGames(games);
	actual[1600+i].SetMin(int(mpg2*games));
	actual[1600+i].SetFgm(int(games*(fgm+tgm)));
	actual[1600+i].SetFga(int(games*(fga+tga)));
	actual[1600+i].SetTfgm(int(games*tgm));
	actual[1600+i].SetTfga(int(games*tga));
	actual[1600+i].SetFtm(int(games*ftm));
	actual[1600+i].SetFta(int(games*fta));
	actual[1600+i].SetOreb(int(games*orb));
	actual[1600+i].SetReb(int(games*(orb+drb)));
	actual[1600+i].SetAst(int(games*ast));

	actual[1600+i].SetStl(int(games*stl));
	actual[1600+i].SetTo(int(games*to));

	if(blk == 0 && Random(1) < .5) actual[1600+i].SetBlk(1);
	else actual[1600+i].SetBlk(int(games*blk));

	actual[1600+i].SetPf(int(games*pf));
	actual[1600+i].SetOutside();
	actual[1600+i].SetOutsideDefense();
	actual[1600+i].SetDriving();
	actual[1600+i].SetDrivingDefense();
	actual[1600+i].SetPost();
	actual[1600+i].SetPostDefense();
	actual[1600+i].SetTransition();
	actual[1600+i].SetTransitionDefense();
	int oo = actual[1600+i].Round(actual[1600+i].GetOutside()) - 3 + IntRandom(3);
	int od = actual[1600+i].Round(actual[1600+i].GetOutsideDefense()) - 3 + IntRandom(3);
	int po = actual[1600+i].Round(actual[1600+i].GetDriving()) - 3 + IntRandom(3);
	int pd = actual[1600+i].Round(actual[1600+i].GetDrivingDefense()) - 3 + IntRandom(3);
	int io = actual[1600+i].Round(actual[1600+i].GetPost()) - 3 + IntRandom(3);
	int id = actual[1600+i].Round(actual[1600+i].GetPostDefense()) - 3 + IntRandom(3);
	int fo = actual[1600+i].Round(actual[1600+i].GetTransition()) - 3 + IntRandom(3);
	int fd = actual[1600+i].Round(actual[1600+i].GetTransitionDefense()) - 3 + IntRandom(3);
	if(oo > 9) oo = 9; else if(oo < 1) oo = 1;
	if(od > 9) od = 9; else if(od < 1) od = 1;
	if(po > 9) po = 9; else if(po < 1) po = 1;
	if(pd > 9) pd = 9; else if(pd < 1) pd = 1;
	if(io > 9) io = 9; else if(io < 1) io = 1;
	if(id > 9) id = 9; else if(id < 1) id = 1;
	if(fo > 9) fo = 9; else if(fo < 1) fo = 1;
	if(fd > 9) fd = 9; else if(fd < 1) fd = 1;
	
	
	actual[1600+i].SetMovOff(oo);
	actual[1600+i].SetMovDef(od);
	actual[1600+i].SetPenOff(po);
	actual[1600+i].SetPenDef(pd);
	actual[1600+i].SetPostOff(io);
	actual[1600+i].SetPostDef(id);
	actual[1600+i].SetTransOff(fo);
	actual[1600+i].SetTransDef(fd);

	int cl = 2;
	int co = 2;
	int r = IntRandom(8);
	if(r == 1) cl = IntRandom(3);
	r = IntRandom(8);
	if(r == 1) co = IntRandom(3);
	actual[1600+i].SetClutch(cl);
	actual[1600+i].SetConsistency(co);

	int better = 30 + IntRandom(40);
	if(better <= 35 || better >= 66) better = IntRandom(99);
	actual[1600+i].SetBetter(better);
	actual[1600+i].SetPgRot(0);
	actual[1600+i].SetSgRot(0);
	actual[1600+i].SetSfRot(0);
	actual[1600+i].SetPfRot(0);
	actual[1600+i].SetCRot(0);


	actual[1600+i].m_coach_factor = IntRandom(5);	
	actual[1600+i].m_loyalty_factor = IntRandom(5);	
	actual[1600+i].m_playing_time_factor = IntRandom(5);	
	actual[1600+i].m_winning_factor = IntRandom(5);	
	actual[1600+i].m_tradition_factor = IntRandom(5);	
	actual[1600+i].m_security_factor = IntRandom(5);	
	actual[1600+i].m_content = 2 + IntRandom(5);	
	actual[1600+i].m_uncertainty = IntRandom(11) - 6;



	actual[1600+i].GenerateRandomHeightWeight(true);
	r = IntRandom(6);
	if(r==1) actual[1600+i].m_clutch = 1;
	else if(r==2) actual[1600+i].m_clutch = 3;

	r = IntRandom(6);
	if(r==1) actual[1600+i].m_consistency = 1;
	else if(r==2) actual[1600+i].m_consistency = 3;

	actual[1600+i].m_pot1 = IntRandom(99);
	actual[1600+i].m_pot2 = IntRandom(99);
	actual[1600+i].m_effort = IntRandom(99);
	actual[1600+i].m_scoring_pot = IntRandom(99);
	actual[1600+i].m_shooting_pot = IntRandom(99);
	actual[1600+i].m_rebounding_pot = IntRandom(99);
	actual[1600+i].m_passing_pot = IntRandom(99);
	actual[1600+i].m_defense_pot = IntRandom(99);

	//adjustments for odd numbers
    int min_stl = int(double(actual[1600+i].GetMin())*.01);
	int stl_i = actual[1600+i].GetStl();
	if(stl_i < min_stl) stl_i = min_stl;
	int fgm_i = actual[1600+i].GetFgm();
	int fga_i = actual[1600+i].GetFga();
	fgp = (double)fgm_i/(double)fga_i;
	if(fga_i>=3 && fgp <= .25) fgm_i = fga_i/4;

	actual[1600+i].SetStl(stl_i);
	actual[1600+i].SetFgm(fgm_i);
	actual[1600+i].SetFga(fga_i);

	actual[1600+i].m_sort_index = 1600+i;


	}
}

void CAmateur::ScoutRookies400Bureau(CStaff scout, CPlayer *actual)
{
	for(int i=1; i<=400; i++)
	{
		actual[1600+i].SetAdjustedRatingsUncertain(scout);
	}
}
