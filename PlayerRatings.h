#include <afxtempl.h>
class CPlayerRatings: public CObject
{
private:

public:
	void SetOriginalAdjustedRatings();

	double m_MinPerGame;
	int m_FgPct;
	int m_adjustedFgPct;
	int m_FtPct;
	double m_FoulsDrawnPer48Min;
	double m_AdjustedFoulsDrawnPer48Min;
	int m_TfgPct;
	double m_FgaPer48Min;
	double m_AdjustedFgaPer48Min;
	double m_coachFgaPer48Min;
	double m_coachTfgaPer48Min;
	double m_TfgaPer48Min;
	double m_AdjustedTfgaPer48Min;

	double m_OrebPer48Min;
	double m_DrebPer48Min;
	double m_AstPer48Min;
	double m_StlPer48Min;
	double m_ToPer48Min;
	double m_AdjustedToPer48Min;
	double m_BlkPer48Min;
	double m_PfPer48Min;
	int m_injuryRating;
	int m_stamina;

	double m_OriginalAdjustedFoulsDrawnPer48Min;
	double m_OriginalAdjustedFgaPer48Min;
	double m_OriginalAdjustedTfgaPer48Min;
	double m_OriginalStlPer48Min;
	double m_OriginalBlkPer48Min;


	CPlayerRatings()
	{	
	m_MinPerGame = 0;
	m_FgPct = 0;
	m_adjustedFgPct = 0;
	m_FtPct = 0;
	m_FoulsDrawnPer48Min = 0;
	m_AdjustedFoulsDrawnPer48Min = 0;
	m_TfgPct = 0;
	m_FgaPer48Min = 0;
	m_AdjustedFgaPer48Min = 0;
	m_coachFgaPer48Min = 0;
	m_coachTfgaPer48Min = 0;
	m_TfgaPer48Min = 0;
	m_AdjustedTfgaPer48Min = 0;
	m_OrebPer48Min = 0;
	m_DrebPer48Min = 0;
	m_AstPer48Min = 0;
	m_StlPer48Min = 0;
	m_ToPer48Min = 0;
	m_AdjustedToPer48Min = 0;
	m_BlkPer48Min = 0;
	m_PfPer48Min = 0;
	m_injuryRating = 0;
	m_stamina = 0;

	m_OriginalAdjustedFoulsDrawnPer48Min = 0;
	m_OriginalAdjustedFgaPer48Min = 0;
	m_OriginalAdjustedTfgaPer48Min = 0;
	m_OriginalStlPer48Min = 0;
	m_OriginalBlkPer48Min = 0;

	}
	
	~CPlayerRatings(){}


	void SetMinPerGame(int Games, int Min)
	{
		m_MinPerGame = double(Min) / double(Games);
	}

	void SetFgPct(int Fgm, int Fga)
	{
		double FgPct = 0;
		if(Fga > 0) FgPct = double(Fgm) / double(Fga) * 1000;
		m_FgPct = Round(FgPct);
	}

	void SetAdjustedFgPct()
	{
		double adjustedFg = double(GetFgPct()) * (4 * GetAdjustedFgaPer48Min() - GetFgaPer48Min()) / 3000;
		double Fga = GetAdjustedFgaPer48Min();
		double FgPct = 0;
		if(Fga > 0) FgPct = adjustedFg / Fga * 1000;
		m_adjustedFgPct = Round(FgPct);
	}

	void SetFtPct(int Ftm, int Fta)
	{
		double FtPct = 0;
		if(Fta > 0) FtPct = double(Ftm) / double(Fta) * 1000;
		m_FtPct = Round(FtPct);
	}

	void SetFoulsDrawnPer48Min(int Fta, int Min, double foulRatio)
	{
		if(Min > 0)
			m_FoulsDrawnPer48Min = Fta * foulRatio / double(Min) * 48;
		else
			m_FoulsDrawnPer48Min = 0;
	}

	void SetAdjustedFoulsDrawnPer48Min()
	{
		m_AdjustedFoulsDrawnPer48Min = 0;

		if((m_FgaPer48Min + m_OrebPer48Min) > 0 && m_AdjustedFgaPer48Min > 0)
		{

		double factor =
			.25 + (GetFgaPer48Min() / (GetFgaPer48Min()
				+ GetOrebPer48Min())) / 2;

		double adj2 = GetFgaPer48Min() * (double(GetFgPct()) / 1000) * .05;
		double adj3 = GetTfgaPer48Min() * .02;
		double adj = adj2 + adj3;

		m_AdjustedFoulsDrawnPer48Min = 
			(GetFoulsDrawnPer48Min()
			- factor *
			(GetFoulsDrawnPer48Min()
			/ GetAdjustedFgaPer48Min() *
			GetOrebPer48Min())) - adj;
		}
	}


	void SetTfgPct(int Tfgm, int Tfga)
	{
		double TfgPct = 0;
		if(Tfga > 0) TfgPct = double(Tfgm) / double(Tfga) * 1000;
		m_TfgPct = Round(TfgPct);
	}

	void SetFgaPer48Min(int Fga, int Min)
	{
		m_FgaPer48Min = double(Fga) / double(Min) * 48;
	}

	void SetAdjustedFgaPer48Min(double fb)
	{
	

		if(fb > 0 && m_AdjustedFgaPer48Min > 0)//adjust for fast breaks
		{


			double fd = m_AdjustedFoulsDrawnPer48Min;
			double to = m_AdjustedToPer48Min;
			double tg = m_AdjustedTfgaPer48Min;
			double ga = m_AdjustedFgaPer48Min;
			double po = fd + to + tg + ga;
			double ratio = (po - fb) / po;
			m_AdjustedFgaPer48Min = ga*ratio;
			m_AdjustedFoulsDrawnPer48Min = fd*ratio;
			m_AdjustedToPer48Min = to*ratio;
			m_AdjustedTfgaPer48Min = tg*ratio;

		}
		else if((GetFgaPer48Min() + GetFoulsDrawnPer48Min()) > 0)
		{
		double factor =
			.25 + (GetFgaPer48Min() / (GetFgaPer48Min()
				+ GetOrebPer48Min())) / 2;

		m_AdjustedFgaPer48Min = 
			(GetFgaPer48Min()
			- factor *
			(GetFgaPer48Min()
			/ (GetFgaPer48Min() + GetFoulsDrawnPer48Min()) *
			GetOrebPer48Min()));
		}
	}

	void SetCoachFgaPer48Min()
	{
		m_coachFgaPer48Min = (m_AdjustedFgaPer48Min + m_AdjustedTfgaPer48Min + 
			m_AdjustedFoulsDrawnPer48Min + m_AdjustedToPer48Min) * 3;
	}

	void SetCoachTfgaPer48Min(bool team)
	{
		if(team == false)
			m_coachTfgaPer48Min = m_TfgaPer48Min*4;
		else
			m_coachTfgaPer48Min = 
				m_FgaPer48Min + m_TfgaPer48Min + m_FoulsDrawnPer48Min; 
	}

	void ReduceCoachFgaPer48Min()
	{
		m_coachFgaPer48Min = m_coachFgaPer48Min - 2;
		double min = (m_AdjustedFgaPer48Min + m_AdjustedTfgaPer48Min + 
			m_AdjustedFoulsDrawnPer48Min + m_AdjustedToPer48Min) * 1/2;
		if(m_coachFgaPer48Min < min) m_coachFgaPer48Min = min;
	}

	void ReduceCoachTfgaPer48Min(int factor)
	{
		m_coachTfgaPer48Min = m_coachTfgaPer48Min-factor;
		if(m_coachTfgaPer48Min < factor) m_coachTfgaPer48Min = factor;
	}

	void SetTfgaPer48Min(int Tfga, int Min)
	{
		m_TfgaPer48Min = double(Tfga) / double(Min) * 48;
	}

	void SetAdjustedTfgaPer48Min(int Tfga, int Min)
	{
		m_AdjustedTfgaPer48Min = double(Tfga) / double(Min) * 48;
	}

	
	void SetOrebPer48Min(int Oreb, int Min)
	{
		m_OrebPer48Min = double(Oreb) / double(Min) * 48;
	}

	void SetDrebPer48Min(int Oreb, int Reb, int Min)
	{
		m_DrebPer48Min = 
			( double(Reb) - double(Oreb) ) / double(Min) * 48;
	}

	void SetAstPer48Min(int Ast, int Min)
	{
		m_AstPer48Min = double(Ast) / double(Min) * 48;
	}

	void SetStlPer48Min(int Stl, int Min)
	{
		m_StlPer48Min = double(Stl) / double(Min) * 48 * 5/6*11/10;
	}

	void SetToPer48Min(int To, int Min)
	{
		m_ToPer48Min = double(To) / double(Min) * 48;
	}
	
	void SetAdjustedToPer48Min(int To, int Min)
	{
		m_AdjustedToPer48Min = double(To) / double(Min) * 48;
	}

	void SetBlkPer48Min(int Blk, int Min)
	{
		m_BlkPer48Min = double(Blk) / double(Min) * 48;
	}

	void SetPfPer48Min(int Pf, int Min)
	{
		m_PfPer48Min = double(Pf) / double(Min) * 48;
	}

  	void SetInjuryRating(int g, int min, int fga, int fta, int to, int injury, int m_hiGames)
	{
		
			if(m_hiGames > 82) m_hiGames = 82;	
			int plays = fga + fta + to;
			double playsPerGame = double(plays) / double(g);
			double plays82 = playsPerGame * m_hiGames;
			double playsMissed = plays82 - double(plays);
			double rating = playsMissed / 20;

			int g_missed = m_hiGames - g;
			rating = g_missed * 1000 / plays82;

			if(rating < 1) rating = 1;
//			else if(rating > 99) rating = m_hiGames + 1 - g;
			else if(rating > 27) rating = 27;
  			m_injuryRating = int(rating);
			if(injury == 2 && m_injuryRating > 5) m_injuryRating = 5;
			else if(injury == 2 && m_injuryRating < 2) m_injuryRating = 2;

	}
	
	void SetGameStamina(int g, int min, int coach_endurance_rating)
	{
		double stamina = double(min)/double(g)/3*60;
		double factor = 1 + double(coach_endurance_rating) / 50.;
		stamina = stamina * factor;
		if(stamina < 480) stamina = 480; //minimum stamina 8 minutes straight
		m_stamina = int(stamina);
	}

	double GetMinPerGame(){return m_MinPerGame;}
	int GetFgPct(){return m_FgPct;}
	int GetAdjustedFgPct(){return m_adjustedFgPct;}
	int GetFtPct(){return m_FtPct;}	
	double GetFoulsDrawnPer48Min(){return m_FoulsDrawnPer48Min;}
	double GetAdjustedFoulsDrawnPer48Min(){return m_AdjustedFoulsDrawnPer48Min;}
	int GetTfgPct(){return m_TfgPct;}
	double GetFgaPer48Min(){return m_FgaPer48Min;}
	double GetAdjustedFgaPer48Min(){return m_AdjustedFgaPer48Min;}
	double GetCoachFgaPer48Min(){return m_coachFgaPer48Min;}
	double GetCoachTfgaPer48Min(){return m_coachTfgaPer48Min;}
	double GetTfgaPer48Min(){return m_TfgaPer48Min;}
	double GetAdjustedTfgaPer48Min(){return m_AdjustedTfgaPer48Min;}
	double GetOrebPer48Min(){return m_OrebPer48Min;}
	double GetDrebPer48Min(){return m_DrebPer48Min;}
	double GetAstPer48Min(){return m_AstPer48Min;}
	double GetStlPer48Min(){return m_StlPer48Min;}
	double GetToPer48Min(){return m_ToPer48Min;}
	double GetAdjustedToPer48Min(){return m_AdjustedToPer48Min;}
	double GetBlkPer48Min(){return m_BlkPer48Min;}
	double GetPfPer48Min(){return m_PfPer48Min;}
  	int GetInjuryRating(){return m_injuryRating;}
	int GetStamina(){return m_stamina;}
	// Round off numbers function
	int Round(double number)
	{
		double diff = number - int(number);
		int integer = 0;
		if(diff > .5)
			integer = int(number + 1);
		else
			integer = int(number);
		return integer;
	}

	CPlayerRatings( const CPlayerRatings& a ) 
	{ 
		m_MinPerGame = a.m_MinPerGame;
	    m_FgPct = a.m_FgPct;
	    m_adjustedFgPct = a.m_adjustedFgPct;
	    m_FtPct = a.m_FtPct;
		m_FoulsDrawnPer48Min = a.m_FoulsDrawnPer48Min;
		m_AdjustedFoulsDrawnPer48Min = a.m_AdjustedFoulsDrawnPer48Min;
	    m_TfgPct = a.m_TfgPct;
	    m_FgaPer48Min = a.m_FgaPer48Min;
	    m_AdjustedFgaPer48Min = a.m_AdjustedFgaPer48Min;
	    m_coachFgaPer48Min = a.m_coachFgaPer48Min;
	    m_coachTfgaPer48Min = a.m_coachTfgaPer48Min;
	    m_TfgaPer48Min = a.m_TfgaPer48Min;
	    m_AdjustedTfgaPer48Min = a.m_AdjustedTfgaPer48Min;
	    m_OrebPer48Min = a.m_OrebPer48Min;
		m_DrebPer48Min = a.m_DrebPer48Min;
		m_AstPer48Min = a.m_AstPer48Min;
		m_StlPer48Min = a.m_StlPer48Min;
		m_ToPer48Min = a.m_ToPer48Min;
		m_AdjustedToPer48Min = a.m_AdjustedToPer48Min;
		m_BlkPer48Min = a.m_BlkPer48Min;
		m_PfPer48Min = a.m_PfPer48Min;
  		m_injuryRating = a.m_injuryRating;
		m_stamina = a.m_stamina;	

		m_OriginalAdjustedFoulsDrawnPer48Min = a.m_OriginalAdjustedFoulsDrawnPer48Min;
		m_OriginalAdjustedFgaPer48Min = a.m_OriginalAdjustedFgaPer48Min;
		m_OriginalAdjustedTfgaPer48Min = a.m_OriginalAdjustedTfgaPer48Min;
		m_OriginalStlPer48Min = a.m_OriginalStlPer48Min;
		m_OriginalBlkPer48Min = a.m_OriginalBlkPer48Min;

	} 

	const CPlayerRatings& operator=( const CPlayerRatings& a )
    {
		m_MinPerGame = a.m_MinPerGame;
	    m_FgPct = a.m_FgPct;
	    m_adjustedFgPct = a.m_adjustedFgPct;
	    m_FtPct = a.m_FtPct;
		m_FoulsDrawnPer48Min = a.m_FoulsDrawnPer48Min;
		m_AdjustedFoulsDrawnPer48Min = a.m_AdjustedFoulsDrawnPer48Min;
	    m_TfgPct = a.m_TfgPct;
	    m_FgaPer48Min = a.m_FgaPer48Min;
	    m_AdjustedFgaPer48Min = a.m_AdjustedFgaPer48Min;
	    m_coachFgaPer48Min = a.m_coachFgaPer48Min;
	    m_coachTfgaPer48Min = a.m_coachTfgaPer48Min;
	    m_TfgaPer48Min = a.m_TfgaPer48Min;
	    m_AdjustedTfgaPer48Min = a.m_AdjustedTfgaPer48Min;
	    m_OrebPer48Min = a.m_OrebPer48Min;
		m_DrebPer48Min = a.m_DrebPer48Min;
		m_AstPer48Min = a.m_AstPer48Min;
		m_StlPer48Min = a.m_StlPer48Min;
		m_ToPer48Min = a.m_ToPer48Min;
		m_AdjustedToPer48Min = a.m_AdjustedToPer48Min;
		m_BlkPer48Min = a.m_BlkPer48Min;
		m_PfPer48Min = a.m_PfPer48Min;
  		m_injuryRating = a.m_injuryRating;
		m_stamina = a.m_stamina;	

		m_OriginalAdjustedFoulsDrawnPer48Min = a.m_OriginalAdjustedFoulsDrawnPer48Min;
		m_OriginalAdjustedFgaPer48Min = a.m_OriginalAdjustedFgaPer48Min;
		m_OriginalAdjustedTfgaPer48Min = a.m_OriginalAdjustedTfgaPer48Min;
		m_OriginalStlPer48Min = a.m_OriginalStlPer48Min;
		m_OriginalBlkPer48Min = a.m_OriginalBlkPer48Min;

		return *this;
    }
};