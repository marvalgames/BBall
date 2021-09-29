
class CInjuryTable: public CObject
{

private:


public:
	void ReadInjuryTable(CString file_name, CString *strings);
	void FillDataStructure(CString string);
	int m_frequency;
	CString m_injury;
	int m_min;
	int m_max;

	CInjuryTable();
	~CInjuryTable();

	CInjuryTable( const CInjuryTable& a ) 
	{ 
		m_frequency = a.m_frequency;
		m_injury = a.m_injury;
		m_min = a.m_min;
		m_max = a.m_max;

	}



	const CInjuryTable& operator=( const CInjuryTable& a )
    {
		m_frequency = a.m_frequency;
		m_injury = a.m_injury;
		m_min = a.m_min;
		m_max = a.m_max;
		return *this;
	}

};