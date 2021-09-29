#include "stdafx.h"
#include "bball.h"


#include "InjuryTable.h"


CInjuryTable::CInjuryTable()
{
	m_frequency = 0;
	m_injury = "";
	m_min = 0;
	m_max = 0;
}

CInjuryTable::~CInjuryTable()
{

}



void CInjuryTable::ReadInjuryTable(CString file_name, CString *strings)
{

	for(int i=0; i<=306; i++)
	{
		strings[i] = "";
	}

	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) != 0) 
	{
		CStdioFile file(file_name, CFile::modeRead);

		for(int i=0; i<=306; i++)
		{
			CString str;
			file.ReadString( str);	
			strings[i] = str + ",";
		}
		file.Close(); 
	}

}

void CInjuryTable::FillDataStructure(CString string)
{

		string.TrimLeft();
		string.TrimRight();

		int offset = 0;
		int index = string.Find(",", offset); 


	int chars = (index - offset);
	CString str = string.Mid(offset, chars); 
	str = str + "                                                ";
	m_injury = str.Mid(0,32);
	m_injury.TrimRight();

	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_frequency = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_min = atoi(str);


	offset = index + 1;
	index = string.Find(",", offset); 
	chars = (index - offset);
	str = string.Mid(offset, chars); 
	m_max = atoi(str);



}
