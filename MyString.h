class CMyString: public CObject
{

private:


public:
	
	CMyString()
	{
	}
	~CMyString(){}


	
CString SetPrintString(CString s[], int columns)
{
	CString string;
	for(int i=0; i < columns; i++)
	{
		string = string + s[i] + " ";
	}
	return string;
}



/*CString GetTeam(){return m_team;}*/

};