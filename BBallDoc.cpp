// BBallDoc.cpp : implementation of the CBBallDoc class
//

#include "stdafx.h"
//#include "BBall.h"


#include "BBall.h"


#include "BBallDoc.h"
#ifndef Disk_h
#include "Disk.h"
#define Disk_h
#endif 
//#include "Disk.h"
#include "Retirement.h"
#include "ProgressDlg1.h"
#include "RegisterDlg.h"
#include "AutoSchDlg.h"
#include "OptionsDlg.h"
#include "ReportDlg.h"
#include "TradeDlg.h"
#include "Career.h"
#include "Computer.h"
#include "BBallFile.h"
#include "EditDlg.h"
#include "ScoutEditDlg.h"
#include "FranchiseEdit.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBBallDoc

IMPLEMENT_DYNCREATE(CBBallDoc, CDocument)

BEGIN_MESSAGE_MAP(CBBallDoc, CDocument)
	//{{AFX_MSG_MAP(CBBallDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBallDoc construction/destruction

CBBallDoc::CBBallDoc()
{
	// TODO: add one-time construction code here
	m_page = 0;
	m_sim_ok = true;
	m_default_opened = false;
	m_game_type = LEAGUE;
	m_combo_team_index = 0;
	m_coach_visitor_index = 0;
	m_coach_home_index = 0;
	m_coached_game_underway = false;
	m_program_started = false;
	m_shareware = false;
	for(int i=0;i<=2;i++)
	{
		m_coach_score[i] = 0;
	}


}

CBBallDoc::~CBBallDoc()
{
}

BOOL CBBallDoc::OnNewDocument()
{

    if (!CDocument::OnNewDocument())
        return FALSE;

if(m_program_started == false)
	{

	//m_program_started = true;
	TCHAR	szProgPath[MAX_PATH * 2];
	::GetCurrentDirectory(sizeof(szProgPath)/sizeof(TCHAR), szProgPath);

	TCHAR buff[MAX_PATH];
	memset(buff, 0, MAX_PATH);
	::GetModuleFileName(NULL, buff, sizeof(buff));
	CString strFolder = buff;
	strFolder = strFolder.Left(strFolder.ReverseFind(_T('\\')) + 1);

	//m_default_path = (CString)strFolder + "\\";//default name
	m_default_path = (CString)strFolder;//default name
	m_original_dir = m_default_path;
	m_default_league = "Default_04-05";
	CString str1, str2, str3, str4, str5, str6, str7;
	str1 = m_default_path;
	str2 = m_default_league;

	CString file_name = m_default_path + "settings.txt";// writes blank settings in not created 
	CFileStatus status;
	if( CFile::GetStatus( file_name, status ) != TRUE) 
	{
		CFile file( file_name, CFile::modeCreate | CFile::modeWrite );
		char buffer[60001];
		memset( buffer, ' ', 32000);
		file.Write( buffer, 32000);
		file.Close();
	}

  	CStdioFile fil(file_name, CFile::modeRead);//read last league
	fil.ReadString(str1);
	str1.TrimRight();
	fil.ReadString(str2);
	str2.TrimRight();
	fil.ReadString(str3);
	str3.TrimRight();
	fil.ReadString(str4);
	str4.TrimRight();
	fil.ReadString(str5);
	str5.TrimRight();
	fil.ReadString(str6);
	str6.TrimRight();
	fil.ReadString(str7);
	str7.TrimRight();
	fil.Close();





	if(str1 != "")
	{
		m_default_path = str1;
		m_default_league = str2;
		m_bk_color = str3;
		m_text_color = str4;
		m_link_color = str5;
		m_vlink_color = str6;
		m_html_font = str7;

	}


	CString look = m_default_path + m_default_league + ".lge";
	if( CFile::GetStatus( look, status ) != TRUE) 
	{
		m_default_league = "Default_04-05";
		CString look = m_default_path + m_default_league + ".lge";
			if( CFile::GetStatus( look, status ) != TRUE) 
			{
//				HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
				//MessageBox(hWnd,"", "Installation Error! Please ensure that the file Default_04-05.lge is located in the same folder as jumpshot.exe", MB_OK);
				//exit(0);
				m_default_league = "termination";
			}
	}






	// CString


	//read colors - move later

	CString color_file_name = m_default_path + "colors.ini";

		if(avg.FileExists(color_file_name) == true)
		{
			CString colors[16];
			COLORREF values[16];



			CStdioFile file(color_file_name, CFile::modeRead);

			for(int i=0; i<=15; i++)
			{
				CString str;
				file.ReadString( str);	
				colors[i] = str + ",";
			}
			file.Close(); 
			colors[13].MakeLower();
			colors[13].Remove(' ');
			colors[13].Remove(',');
			if(colors[13] == "bitmap=true")
				avg.m_settings.m_loadbmp = true;
			else
				avg.m_settings.m_loadbmp = false;


			for(int i=0; i<=15; i++)
			{
			CString string = colors[i];

			string.TrimLeft();
			string.TrimRight();

			int offset = 0;
			int index = string.Find(",", offset); 


			int chars = (index - offset);
			CString str = string.Mid(offset, chars); //read title

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			int r = atoi(str);
			int g = 0;
			int b = 0;
			if(i==14) colors[14] = str;

			if(i < 14)
			{

			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			g = atoi(str);

			}


			offset = index + 1;
			index = string.Find(",", offset); 
			chars = (index - offset);
			str = string.Mid(offset, chars); 
			b = atoi(str);




			values[i] = RGB(r,g,b);

			}

			ROWCOLOR1 = values[4];		 
			ROWCOLOR2 = values[5];
			HILITE = values[6];
			TEXTCOLOR = values[3]; 
			BK_COLOR = ROWCOLOR1;
			SCREENCOLOR = values[0];
			MAINTEXTCOLOR = values[1];
			BUTTONCOLOR = values[2];
			EDITCOLOR = values[11];
			EDITBKCOLOR = values[12];
			STATICCOLOR  = values[7];
			LISTBOXTEXTCOLOR = values[9];
			LISTBOXCOLOR = values[10];
			DLGCOLOR = values[8];
			USERFONT = colors[14];
			USERFONT.TrimLeft();


		}

		


		



	//	if(CFile::GetStatus(avg.m_settings.m_path + "default.bmp") == FALSE)
	//		avg.m_settings.m_loadbmp = false;


	}

	//BK_COLOR = ROWCOLOR1;



    return TRUE;

}



/////////////////////////////////////////////////////////////////////////////
// CBBallDoc serialization

void CBBallDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBBallDoc diagnostics

#ifdef _DEBUG
void CBBallDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBBallDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBBallDoc commands

void CBBallDoc::OpenGameData(CString LeaguePath, CString LeagueName)
{

		if(m_default_league == "termination")
		{
			AfxMessageBox("INSTALLATION ERROR: Please ensure the default league file: Default_04-05.lge is located in the same folder as jumpshot.exe", MB_OK);
				exit(0);
		}

		 //UpdateAllViews(NULL);
		

		CString tmp;
		tmp = LeagueName.Mid(0,7);
		tmp.MakeLower();
		if(tmp == "default") m_default_opened = true; else m_default_opened = false;


		CString player_data_name = LeaguePath + LeagueName + ".dta";
		CString new_data_name = LeaguePath + LeagueName + ".plr";
		CString dumb_file_name = LeaguePath + LeagueName + ".tmp";
		CString league_setup_name = LeaguePath + LeagueName + ".lge";
		CString schedule_name = LeaguePath + LeagueName + ".sch";
		CString staff_name = LeaguePath + LeagueName + ".fro";
		CString stats_name = LeaguePath + LeagueName + ".sta";
		CString tra_file = LeaguePath + LeagueName + ".trn";
		CString old_tra_file = LeaguePath + LeagueName + ".tra";
		CString contract_file_name = LeaguePath + LeagueName + ".sal";
		CString car_file_name = LeaguePath + LeagueName + ".car";
		CString sal_file_name = LeaguePath + LeagueName + ".sal";
		CString misc_ratings_file_name = LeaguePath + LeagueName + ".msc";
		CString recordbook_file = LeaguePath + LeagueName + ".rcb";


		CDisk* disk = new CDisk;

		//disk->DecreaseFileSize(schedule_name, -8718-8718);
		

	CProgressDlg dlgProgress;
 			dlgProgress.m_text = "Reading League File";
        dlgProgress.Create(IDD_PROGRESSDLG,NULL);        // change these parameters
		dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 7);




		disk->CreateCleanLeagueFiles(LeaguePath + LeagueName);
		

		disk->avg.m_settings = disk->ReadLeagueFile(league_setup_name);
	
	
	
		if(disk->FileExists(new_data_name) == true || disk->FileExists(dumb_file_name) == true )
		{
			dlgProgress.m_progress.SetPos(1);
			disk->ReadNewPlayerDataFile(new_data_name, dumb_file_name, disk->avg.m_settings.m_leagueTeamNames);
		}
		else
		{
			disk->ReadPlayerData(player_data_name);
			disk->ReadPlayerStats(stats_name, false);
			disk->ReadPlayoffStats(stats_name);
			disk->ReadTeamStats(stats_name);
			disk->ReadPlayoffTeamStats(stats_name);
			disk->ReadCareerContractFile(contract_file_name);			
			disk->avg.ConvertDataNewFormat();
			disk->avg.CalculateCareerStats(car_file_name);
			disk->avg.CalculateCareerAwards(sal_file_name);
		}

		CString engine_file = LeaguePath + LeagueName + ".eng";
		if(disk->FileExists(engine_file) == false)
		{
			disk->avg.SetHighs(true);	
			disk->CreateBlankFile(engine_file, 1000);
			disk->WriteLeagueHighs(engine_file);
		}
		else
		{
			disk->GetSavedHighs(engine_file);
			disk->avg.SetHighs(false);	
		}





		disk->avg.m_sched.GetNextGame(false);




		disk->avg.m_sched = disk->ReadSchedule(schedule_name);
		disk->avg.m_settings.SetLeagueNames(LeaguePath, LeagueName);
			dlgProgress.m_progress.SetPos(2);
		disk->ReadStandingsFile(league_setup_name, disk->avg.m_settings, disk->avg.m_sched, disk->avg.m_standings);


			dlgProgress.m_progress.SetPos(3);


			BOOL random_staff = TRUE;

		if(disk->FileExists(staff_name) == true)//may have not been created yet if new league just made
			//if so will be read later anyway when creating Random Files
		{
			random_staff = FALSE;
			bool bad_file = disk->ReadStaff(staff_name, disk->avg.m_settings.m_numberteams);
			if(bad_file == true) random_staff = TRUE;//read file but "" name created (fixes bad . fro files)
		}



		CString path = disk->avg.m_settings.m_path;
		CString league = disk->avg.m_settings.m_league_name;
		CString back_arena_file = path + league + ".arf";
		CString back_budget_file = path + league + ".dub";
		CString own_file = path + league + ".own";
		CString injury_file = path + "injuries.csv";


		dlgProgress.m_progress.SetPos(4);

		disk->ReadFranchiseData(back_arena_file);
		disk->ReadBudgetFile(back_budget_file);
		for(int i=0; i<=99; i++)
		{
			disk->avg.m_finance[i+100] = disk->avg.m_finance[i];
		}


		dlgProgress.m_progress.SetPos(5);

		CString arena_file = path + league + ".frn";
		CString budget_file = path + league + ".bud";
		disk->ReadFranchiseData(arena_file);
		disk->ReadBudgetFile(budget_file);
		disk->avg.m_own[0].ReadOwnData(own_file, disk->avg.m_settings.m_numberteams);

			dlgProgress.m_progress.SetPos(6);


		disk->ReadRecordBookFile(recordbook_file);
		m_recordbook = disk->m_high;



		CString strings[307];
		m_injury_table[0].ReadInjuryTable(injury_file, strings);

		for(int i=0; i<=306; i++)
		{
			m_injury_table[i].FillDataStructure(strings[i]);

		}




	

		//Create Rookies if they do not exist only for a league that doesn't have one for whatever reason probably not touched
		CString kie_file_name = path + league + ".kie";
		if(disk->FileExists(kie_file_name) == false)
		{
			disk->CreateBlankFile(kie_file_name, 110000);
			CString f_file_name = path + "fnames.txt";
			CString l_file_name = path + "lnames.txt";
			disk->ReadNames(f_file_name, l_file_name);
			disk->CreateRookies(kie_file_name, true);
		}

		if(disk->FileExists(old_tra_file) == true)
		{
			disk->ReadTransactionsFile(old_tra_file);
			disk->DeleteFile(old_tra_file);
		}
	

		disk->ReadTransactionsFile(tra_file);

		
	

		bool temp = avg.m_settings.m_loadbmp;
		avg = disk->avg;
		avg.m_settings.m_loadbmp = temp;

		CString season_hi = avg.m_settings.m_path + avg.m_settings.m_league_name + ".rec";
		CString career_hi = avg.m_settings.m_path + avg.m_settings.m_league_name + ".all";
		if(disk->FileExists(season_hi) == true)// old record files read and then deleted //coment out for now
		{

			m_recordbook.OpenHighs(season_hi);
			m_recordbook.OpenAllHighs(career_hi);
			disk->DeleteFile(season_hi);
			disk->DeleteFile(career_hi);
		}


	
		delete disk;


		if(avg.FileExists(avg.m_settings.m_path + avg.m_settings.m_league_name + ".ret") == false)
		{
			CRetirement* ret = new CRetirement;
			ret->m_path = avg.m_settings.m_path;
			ret->m_league_name = avg.m_settings.m_league_name;

			for(int i=0; i<=839; i++)
			{
				ret->avg.m_actual[i] = avg.m_actual[i];
			}

			ret->SetRetirements(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);
			ret->WriteRetirements();
			delete ret;
		}


		for(int i=1; i<=1600; i++)
		{
			if(avg.m_actual[i].m_name != "")
			{
				avg.m_actual[i].SetRatings(avg.m_hi_fga[0], avg.m_hi_fta[0], avg.m_hi_tga[0], avg.m_hi_orb[0], avg.m_hi_drb[0], avg.m_hi_ast[0], avg.m_hi_stl[0], avg.m_hi_to[0], avg.m_hi_blk[0]);	
//				int awa_pts = avg.m_actual[i].GetAwardPoints(sal_file_name);
//				bool hall = avg.m_actual[i].HallofFamer(awa_pts);
			}


		}

		CreateRandomFiles(avg.m_settings.m_path + avg.m_settings.m_league_name, random_staff);

		dlgProgress.m_progress.SetPos(7);


	CString plan_file_name = avg.m_settings.m_path + avg.m_settings.m_league_name + ".plb";
	CGamePlan *m_game_plan = new CGamePlan;
	m_game_plan->avg = avg;
	m_game_plan->InitGamePlans(plan_file_name);
	avg = m_game_plan->avg;
	delete m_game_plan;

	bool found = false;
	for(int i=0; i<32; i++)
	{
		if(avg.m_settings.m_player_gm[i] == "Player" && found == false && avg.m_settings.m_leagueTeamNames[i] != "")
		{
			found = true;
			m_default_team = i;
			m_combo_team_index = i+1;
		}
	}


	if(m_shareware == true) 
	{
		CRegisterDlg reg;
	    reg.DoModal();
	}
 


//(CBBallApp*)AfxGetApp())->SwitchView( 0 );			
	

	if(m_default_opened == false)
	{
		((CBBallApp*)AfxGetApp())->SwitchView( 0 );
		((CBBallApp*)AfxGetApp())->SwitchView( 1 );
	}
	else
	{
		((CBBallApp*)AfxGetApp())->SwitchView( 1 );
		((CBBallApp*)AfxGetApp())->SwitchView( 0 );
	}



	SetTitleBar();



}

void CBBallDoc::PumpMessages()
{
MSG msg;
while( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) 
{
TranslateMessage(&msg);
DispatchMessage(&msg);

}

}

void CBBallDoc::SaveGameData(CString path, CString league_name)
{
	CDisk* disk = new CDisk;
	CString recordbook_file = path + league_name + ".rcb";
	CString budget_file = path + league_name + ".bud";
	CString bak_budget_file = path + league_name + ".dub";
	CString back_arena_file = path + league_name + ".arf";
	CString lge_file = path + league_name;
	CString new_data_file = path + league_name + ".plr";


	
	CString sch_file = path + league_name + ".sch";
	CString staff_file = path + league_name + ".fro";
	CString plan_file = path + league_name + ".plb";
	CString own_file = path + league_name + ".own";
	CString fra_file = path + league_name + ".frn";
	CString tra_file = path + league_name + ".trn";

	disk->avg = avg;
	//disk->DeleteFile(sch_file);
	//disk->CreateBlankFile(sch_file, 80000);

	CProgressDlg dlgProgress;
 		dlgProgress.m_text = "Saving League File";
        dlgProgress.Create(IDD_PROGRESSDLG,NULL);        // change these parameters
		dlgProgress.ShowWindow(SW_SHOW);     
		dlgProgress.m_progress.SetRange(1, 8);
		dlgProgress.m_progress.SetPos(1);


	disk->m_high = m_recordbook;
	disk->WriteRecordBookFile(recordbook_file);
		dlgProgress.m_progress.SetPos(2);
	disk->WriteBudgetFile(budget_file, 0, 100);
	disk->WriteBudgetFile(bak_budget_file, 101, 200);
		dlgProgress.m_progress.SetPos(3);

	disk->WriteFranchiseData(fra_file,0,100);
	disk->WriteFranchiseData(back_arena_file,101,200);
		dlgProgress.m_progress.SetPos(4);
	disk->WriteNewPlayerDataFile(new_data_file);
		dlgProgress.m_progress.SetPos(5);
	disk->SaveSchedule(sch_file, avg.m_sched);
		dlgProgress.m_progress.SetPos(6);
	disk->WriteLeagueFile(lge_file, avg.m_settings);

	disk->SaveTransactionsFile(tra_file);

	disk->WriteCareerStaff(staff_file, avg.m_scout, avg.m_coach, avg.m_gm, avg.m_owner, avg.m_settings.m_scouts[32], avg.m_settings.m_coaches[32]);

		dlgProgress.m_progress.SetPos(7);

	double tru_factor = 1;


	CGamePlan* m_game_plan = new CGamePlan;
	m_game_plan->avg = avg;
	m_game_plan->CreateDataForSavingGamePlans();
	disk->WriteGamePlan(plan_file, m_game_plan->m_save_plan);
	delete m_game_plan;

		dlgProgress.m_progress.SetPos(8);


	delete disk;

	avg.m_own[0].WriteOwnData(own_file);

//	if(m_shareware == true) 
//	{
//		CRegisterDlg reg;
//		reg.DoModal();
//	}
}

void CBBallDoc::CreateRandomFiles(CString name_of_league, BOOL random_staff)
{

			CBBallFile* disk = new CBBallFile;
			bool fro_exists = disk->FileExists(name_of_league + ".fro");
			if(fro_exists == false) 
				disk->CreateBlankFile(name_of_league + ".fro", 600000);

			bool car_exists = disk->FileExists(name_of_league + ".car");
			if(car_exists == false)
				disk->CreateHugeBlankFile(name_of_league + ".car", 3);

			delete disk;

			if(car_exists == false)// new league
			{

				CCareer* car = new CCareer;
				car->m_path = avg.m_settings.m_path;
				car->m_leagueName = avg.m_settings.m_league_name;
				car->avg = avg;
				car->ReadNames();
/*				if(random_staff == TRUE) 
				{
					car->CreateRandomStaffProfiles();//write new staff if needed
				
					//else
					//disk->WriteCareerStaff(staff_file, avg.m_scout, avg.m_coach, avg.m_gm, avg.m_owner, avg.m_settings.m_scouts[32], avg.m_settings.m_coaches[32]);


					for(int i=0; i<=100; i++)
					{		
						avg.m_scout[i] = car->avg.m_scout[i];
						avg.m_coach[i] = car->avg.m_coach[i];
						avg.m_gm[i] = car->avg.m_gm[i];
						avg.m_owner[i] = car->avg.m_owner[i];

					}

				}*/

				for(int i=0; i<=1440; i++)
				{		
					car->m_actual[i] = avg.m_actual[i];
				}

				car->SetupID();

				for(int i=0; i<=1440; i++)
				{		
					avg.m_actual[i].m_id = car->m_actual[i].m_id;
				}
				delete car;

			}

			if(random_staff == TRUE)// new staff file needs to be made (new leagues only?)
			{
				CCareer* car = new CCareer;
				car->m_path = avg.m_settings.m_path;
				car->m_leagueName = avg.m_settings.m_league_name;
				car->avg = avg;
				car->ReadNames();
				car->CreateRandomStaffProfiles();//write new staff if needed
				delete car;


				CDisk* disk = new CDisk;
				bool bad_file = disk->ReadStaff(name_of_league + ".fro", avg.m_settings.m_numberteams);// read new staff 
				for(int i=0; i<=100; i++)
				{
					avg.m_scout[i] = disk->avg.m_scout[i];
					avg.m_coach[i] = disk->avg.m_coach[i];
					avg.m_gm[i] = disk->avg.m_gm[i];
					avg.m_owner[i] = disk->avg.m_owner[i];
				}
				delete disk;
			}

			/*	if(fro_exists == false && random_staff == TRUE) //staff file just made above so read
				{
					CDisk* disk = new CDisk;
					for(int i=0; i<=31; i++)
					{
						disk->avg.m_settings.m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
						disk->avg.m_settings.m_scouts[i] = avg.m_settings.m_scouts[i];
						disk->avg.m_settings.m_coaches[i] = avg.m_settings.m_coaches[i];
						//what the heck need the team names from here at least 
					}
					disk->ReadStaff(name_of_league + ".fro", avg.m_settings.m_numberteams);
					for(int i=0; i<=100; i++)
					{
						avg.m_scout[i] = disk->avg.m_scout[i];
						avg.m_coach[i] = disk->avg.m_coach[i];
						avg.m_gm[i] = disk->avg.m_gm[i];
						avg.m_owner[i] = disk->avg.m_owner[i];
					}
					delete disk;
				}*/

			
}

void CBBallDoc::Options()
{
	COptionsDlg options;

	options.m_default_team = m_combo_team_index - 1;
	if(options.m_default_team < 0) 
		options.m_default_team = 0;

	for(int i=0; i<=31; i++)
	{
		options.m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
	}
	options.m_fileName = avg.m_settings.m_path + avg.m_settings.m_league_name;
	options.m_settings = avg.m_settings;
	options.m_dead_mo = avg.m_sched.m_dead_mo;
	options.m_dead_da = avg.m_sched.m_dead_da;

	int result = options.DoModal();
	if(result == IDOK)
	{
		avg.m_settings = options.m_settings;
		CDisk* disk = new CDisk;
		disk->WriteLeagueFile(options.m_fileName, options.m_settings);
		for(int i=0; i<=32; i++)
		{
			disk->avg.m_settings.m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
			disk->avg.m_settings.m_scouts[i] = avg.m_settings.m_scouts[i];
			disk->avg.m_settings.m_coaches[i] = avg.m_settings.m_coaches[i];
		}

		bool bad_file = disk->ReadStaff(options.m_fileName + ".fro", avg.m_settings.m_numberteams);

		for(int i=0; i<100; i++)
		{
			avg.m_scout[i] = disk->avg.m_scout[i];
			avg.m_coach[i] = disk->avg.m_coach[i];
			avg.m_gm[i] = disk->avg.m_gm[i];
		}
		delete disk;
//		if(avg.m_settings.m_current_stage == 2 && avg.m_settings.m_scouts[32] == 1 && avg.m_settings.m_coaches[32] == 1)
//			avg.m_settings.m_current_stage = 2;

	}

}

int CBBallDoc::GamePlan()
{
	CReportDlg* report = new CReportDlg;
	report->m_default_team = m_combo_team_index - 1;
	if(report->m_default_team < 0) 	report->m_default_team = 0;

	report->m_path = avg.m_settings.m_path;
	report->m_league_name = avg.m_settings.m_league_name;
	report->avg = avg;
	for(int i=0; i<=32; i++)
	{
		report->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
	}

	//report->m_plan = m_game_plan;
	int result = report->DoModal();
	if(result == IDOK)
	{
		avg = report->avg;
		//avg.SetHighs();
	}
	delete report;	

	return result;

}

int CBBallDoc::ProposeTrade()
{
	CTradeDlg* trade;
	trade = new CTradeDlg;

//	if(m_current_stage >= 4) trade->m_off_season = true;
	trade->m_slots = 30;
	trade->m_draftround = 0;
	trade->m_draftpick = 0;
	for(int r=1; r<=2; r++)
	{
		
		for(int i=1; i<=32; i++)
		{
			trade->m_slot_used[r][i] = 0;
		}

	}
	

	trade->m_cap = int(avg.m_settings.m_cap);
	trade->m_current_stage = avg.m_settings.m_current_stage;
	//trade->m_finances_on = avg.m_settings.m_financial_on;
	trade->avg = avg;
	trade->m_checkCareer = avg.m_settings.m_checkCareer;
	trade->m_factor = avg.m_avg_tru[0];

	trade->m_leagueName = avg.m_settings.m_league_name;
	trade->m_path = avg.m_settings.m_path;
	trade->m_current_year = avg.m_settings.m_currentYear;
	trade->m_ast_gm = avg.m_settings.m_ast_gm;



	for(int i=1; i<=480; i++)
	{
		trade->FA[i] = avg.m_actual[960+i];
	}

//	OpenStandings(m_path, m_leagueName);//contains current date also
	

	for(int i=0; i<=32; i++)
	{
//		trade->m_standings[i] = avg.m_standings[i];
		trade->m_scout[i] = avg.m_scout[i];
		trade->m_coach[i] = avg.m_coach[i];
		trade->m_gm[i] = avg.m_gm[i];
		trade->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
		trade->m_control[i] = avg.m_settings.m_player_gm[i];
		trade->m_own[i] = avg.m_own[i];
	}
	for(int t=0; t<=31; t++)
	{
		for(int p=1; p <= 30; p++)
		{
			trade->PlayerList[t][p] = avg.m_actual[t*30+p];
		}
	}


	trade->m_currentDay = avg.m_sched.m_currentDay;
	trade->m_currentMonth = avg.m_sched.m_currentMonth;


	trade->m_default_team = m_combo_team_index - 1;
	if(trade->m_default_team < 0) trade->m_default_team = 0;
	int result = trade->DoModal();
	avg.m_settings.m_number_transactions = trade->avg.m_settings.m_number_transactions;
	
	if(result == IDOK)
	{ 
		for(int i=1; i<=480; i++)
		{
			avg.m_actual[960+i] = trade->FA[i];
		}
		for(int t=0; t<=31; t++)
		{
			avg.m_own[t] = trade->m_own[t];
			for(int p=1; p<=30; p++)
			{
				avg.m_actual[t*30+p] = trade->PlayerList[t][p];
			}
		}

		//OnButtonTrade();

		//avg.m_own[0].WriteOwnData(m_path + m_leagueName + ".own");

		//m_game_plan.avg = avg;
		//m_game_plan.ComputerAdjustsGamePlan(m_player_gm);
		//avg = m_game_plan.avg;
		for(int i=1; i<=trade->avg.m_settings.m_number_transactions; i++)
		{
			avg.m_trans_str[i] = trade->avg.m_trans_str[i];
		}

		avg.ComputerSetsRotation();
		avg.SortTeamRosters(avg.m_actual, false);
	}
	delete trade;
	return result;
}

int CBBallDoc::ComputerManager()
{
// POSITION pos = GetFirstViewPosition();
   //while (pos != NULL)
   //{
     // CView* pView = GetNextView(pos);
//      pView->UpdateWindow();
   //}   

//CMDIFrameWnd *pFrame = 
  //           (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

// Get the active MDI child window.
//CMDIChildWnd *pChild = 
  //           (CMDIChildWnd *) pFrame->GetActiveFrame();

// or CMDIChildWnd *pChild = pFrame->MDIGetActive();

// Get the active view attached to the active MDI child
// window.

//CView *pView = (CView *) pChild->GetActiveView();

//CView *pView = (CView *) pFrame->GetActiveView();


	int active_view = ((CBBallApp*)AfxGetApp())->m_nCurView;		


	int stop = -1;
	bool manage = false;
	
	int i = avg.m_sched.m_currentMonth;
	int j = avg.m_sched.m_currentDay;
	int k = avg.m_sched.m_currentGame + 1;
	if(k > 16 && avg.m_sched.m_playoff_started == false)
//	if(k > 16)
		manage = true;
	else
	{
		int game = avg.m_sched.m_schedule[i][j][k]; 
//		if(game == 0)
		if(game == 0 && avg.m_sched.m_playoff_started == false)
		{
			manage = true;

			if(active_view != 1) UpdateAllViews(NULL);

		}
	}


	bool deadline = false;
	if(avg.m_sched.m_currentMonth > avg.m_sched.m_dead_mo || 
		(avg.m_sched.m_currentMonth == avg.m_sched.m_dead_mo && 
			avg.m_sched.m_currentDay > avg.m_sched.m_dead_da) &&
				avg.m_settings.m_deadline_on == 1			
			) deadline = true;









	if(manage == true && avg.m_settings.m_current_stage == 0)		
	{
		HealInjury(1);
	}








	if((avg.m_settings.m_computerTrades == TRUE && manage == true && (deadline == false || avg.m_settings.m_current_stage > 0))		
		&& avg.m_sched.m_playoff_started == false)
	{
	CComputer* comp = new CComputer;
	comp->avg = avg;

	comp->m_getoffersforteam = -1;
	comp->m_use_trading_block = false;
	for(int i=0; i<=(avg.m_settings.m_numberteams-1); i++)
	{
		comp->m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
		comp->m_control[i] = avg.m_settings.m_player_gm[i];
		comp->m_player_gm[i] = avg.m_settings.m_player_gm[i];
		comp->m_numberteams = avg.m_settings.m_numberteams;
		comp->m_own[i] = avg.m_own[i];
	}

	comp->m_path = avg.m_settings.m_path;
	comp->m_leagueName = avg.m_settings.m_league_name;
	comp->m_currentMonth = avg.m_sched.m_currentMonth;
	comp->m_currentDay = avg.m_sched.m_currentDay;
	comp->m_current_year = avg.m_settings.m_currentYear;
	comp->m_computerTrades = avg.m_settings.m_computerTrades;
	comp->m_checkCareer = TRUE;
	comp->avg = avg;
	comp->m_ast_gm = avg.m_settings.m_ast_gm;
	comp->m_finances_on = avg.m_settings.m_financial_on;	
	comp->m_free_agency_on = avg.m_settings.m_free_agency_on;


	int loops = avg.m_settings.m_salary_matching*10 + 2;

	bool invalid = comp->Trade(avg.m_settings.m_get_offers, loops, 1, avg.m_settings.m_current_stage);

	if(invalid == false ) 
	{	
		avg = comp->avg;
		//CallSetGamePlans();
		avg.m_own[0] = comp->m_own[0];
	}


	delete comp;	
	}

//	manage = true;//delete

	if(k == 1 && avg.m_sched.m_playoff_started == true) manage = true;


	if(manage == true) 
	{
		if(avg.m_settings.m_injury > 0) OffSeasonInjuries();


		//bool more_games = false;
		//for(int i=(avg.m_sched.m_currentGame+1); i<=16; i++)
		//{
		//	int game = avg.m_sched.m_schedule[avg.m_sched.m_currentMonth][avg.m_sched.m_currentDay][i];
		//	if(game > 0) more_games = true;
		//}
		//if(more_games == false) HealInjury(3);

		avg.ComputerSetsRotation();
		//if(avg.m_sched.m_playoff_started == true)
		//	HealInjury(3);
		if(avg.m_sched.m_playoff_started == false)
			avg.ComputerNegotiatesContracts();

		for(int t=0; t<avg.m_settings.m_numberteams; t++)
		{
			bool valid_rosters = true;
			bool dont_sign = true;
			bool release_player = false;
			avg.VerifyRosters(t, valid_rosters, dont_sign, release_player);
		
			//if(valid_rosters == false && avg.m_settings.m_player_gm[t] == "Player" && avg.m_actual[961].GetName() != "")
			//{
			//	stop = t;

			//}
			if((valid_rosters == false || dont_sign == false) && avg.m_actual[961].GetName() != "")
			{

				int result = IDYES;
				
				if(avg.m_settings.m_player_gm[t] == "Player")
				{
					CString str;
					str.Format("Your assistant requests permission to fill the %s roster before the next game because you may not have enough players", avg.m_settings.m_leagueTeamNames[t]);
					result = AfxMessageBox(str,  MB_YESNO);
					if(result != IDYES) stop = t;
				}
				
				if(result == IDYES)
				{
		
				CComputer* comp = new CComputer;
				comp->avg = avg;
				bool available_fa = comp->AvailableFA();
				if(available_fa == true)
				{

				comp->avg.m_settings.m_numberteams = avg.m_settings.m_numberteams;
				for(int i=0; i<=(avg.m_settings.m_numberteams-1); i++)
				{
					comp->avg.m_settings.m_leagueTeamNames[i] = avg.m_settings.m_leagueTeamNames[i];
					comp->avg.m_settings.m_control[i] = avg.m_settings.m_control[i];
					comp->avg.m_gm[i] = avg.m_gm[i];
				}

				comp->avg.m_settings.m_path = avg.m_settings.m_path;
				comp->m_leagueName = avg.m_settings.m_league_name;
				comp->avg.m_sched.m_currentMonth = avg.m_sched.m_currentMonth;
				comp->avg.m_sched.m_currentDay = avg.m_sched.m_currentDay;
				comp->m_current_year = avg.m_settings.m_currentYear;
				comp->avg.m_settings.m_computerTrades = avg.m_settings.m_computerTrades;
				comp->avg.m_settings.m_checkCareer = avg.m_settings.m_checkCareer;
				int team = t+1;
				bool never_mind = false;
				if(release_player == true)
				never_mind = comp->ReleasePlayer(team);
				if(never_mind == false) comp->SignFreeAgent(team);
				avg = comp->avg;

				}
				delete comp;	

				}

			}



		}



	}

	return stop;

}

void CBBallDoc::ResetSeason()
{



	//make budget file copy
		for(int i=0; i<=99; i++)
		{
			if(i<=31) avg.m_standings[i].ClearTeamStandings(i);
			avg.m_finance[i].ClearBudgetData();
		}	


		avg.SetHighs(false);
		avg.m_sched.ClearSchedule();
		CBBallFile* disk = new CBBallFile;
		disk->ResetSeasonFiles(avg.m_settings.m_path + avg.m_settings.m_league_name);
		delete disk;
		
		avg.m_settings.m_current_stage = 0;

	avg.m_sched.m_playoff_started = false;
	avg.m_sched.m_season_started = false;
	for(int i=0; i<=2000; i++)
	{
		avg.m_trans_str[i] = "";
	}
	avg.m_settings.m_number_transactions = 0;
	avg.m_sched.m_regular_season_ended = false;

	for(int i=1; i<=1600; i++)
	{


		
		avg.m_actual[i].SetActive(1);
		avg.m_actual[i].ClearSeasonStats();

		avg.m_actual[i].SetOldRatings();
		int team = avg.m_actual[i].m_current_team;
		if(team == -1) team = 99;
		avg.m_actual[i].SetAdjustedOldRatings(avg.m_coach[team], false);

		avg.m_actual[i].m_injury = 0;
		avg.m_actual[i].m_health = 100;
	}

	avg.ComputerSetsRotation();
	m_recordbook.ClearSeasonHighs(0,0);
}

void CBBallDoc::SetTitleBar()
{

	int month = avg.m_sched.m_currentMonth;
	int day = avg.m_sched.m_currentDay;
	CString heading;
	CString mon[] = {"October","November","December","January","February","March","April","May","June","July","August","September", "Post"};
	CString s1 = "Jump Shot Basketball - " + avg.m_settings.m_league_name + "-";
	CString s2;


	if(avg.m_settings.m_current_stage == 1) s2 = "End Season";
	else if(avg.m_settings.m_current_stage == 2) s2 = "Evaluate Staff";
	else if(avg.m_settings.m_current_stage == 3) s2 = "Begin Rookie Draft";
	else if(avg.m_settings.m_current_stage == 4) s2 = "Sign Free Agents";
	else if(avg.m_settings.m_current_stage == 5) s2 = "Set Ticket Prices";
	else if(avg.m_settings.m_current_stage == 6) s2 = "Evaluate Arena";
	else if(avg.m_settings.m_current_stage == 7) s2 = "Begin Training Camp";
	else s2.Format("(%d-%d)", avg.m_settings.m_currentYear, avg.m_settings.m_currentYear+1);

	//SetWindowText(heading);
	if(avg.m_settings.m_current_stage == 0)
		heading.Format("%s %s %d %s", s1, mon[month], day+1, s2);
	else
		heading.Format("%s (%d-%d) %s", s1, avg.m_settings.m_currentYear, avg.m_settings.m_currentYear+1, s2);

	((CWinApp *)AfxGetApp())->m_pMainWnd->SetWindowText(heading);

}

void CBBallDoc::OffSeasonInjuries()
{
	for(int i=0; i<=960; i++)
	{
		if(avg.m_actual[i].m_name == "" || avg.m_actual[i].m_injury > 0 || avg.m_actual[i].m_current_team < 0) continue;
		int days = 0;
		int inj = avg.m_actual[i].OffSeasonInjury(avg.m_settings.m_current_stage, days);
		if(inj > 99) inj = 99;
		if(inj > 0)
		{

			bool dis = avg.m_actual[i].Disabled(inj);
			CString str;
			if(m_injury_table[1].m_injury == "") str = "injury";

			do
			{
				int n=avg.IntRandom(306);
				int f=avg.IntRandom(10);
				int freq = m_injury_table[n].m_frequency;
				if(freq > 10) freq = freq - 10;//remember 11 to 13 is for offseason inj only!!!

				if( m_injury_table[n].m_min <= inj && m_injury_table[n].m_max >= inj &&
					freq >= f) 
						str = m_injury_table[n].m_injury;

			}
			while (str == "");

			avg.m_actual[i].m_injury_desc = str;


			int mo = avg.m_sched.m_currentMonth + 10;
			if(mo > 12) mo = mo - 12;
			CString string;
			int da = avg.m_sched.m_currentDay + 1;
			int yr = avg.m_settings.m_currentYear;
			int ty = 1;//injury
	
	
			string.Format("%2d%2d%4d%2d%6d%2d%4d%32s", mo, da, yr, ty, avg.m_actual[i].GetID(), avg.m_actual[i].m_current_team + 1, days, str);
			avg.m_settings.m_number_transactions = avg.m_settings.m_number_transactions + 1;
			avg.m_trans_str[avg.m_settings.m_number_transactions] = string;


			if(avg.m_settings.m_injury_prompt <= inj && avg.m_settings.m_injury_prompt > 0  &&
				avg.m_settings.m_player_gm[avg.m_actual[i].m_current_team] == "Player")
			{
				CString message;
				HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
				CString team = avg.m_settings.m_leagueTeamNames[avg.m_actual[i].m_current_team];
				AfxFormatString1( message, IDS_STRING_MESSAGE_INJURY, team); 
				MessageBox(hWnd, message, "Injury", MB_OK);			
				m_sim_ok = false;
			}



		}

	}

}

void CBBallDoc::CallAutoScheduler()
{
	CAutoSchDlg sch;
	sch.m_currentMonth = 1;
	sch.m_currentDay = 1;
	for(int i=0; i<=31; i++)
	{
		sch.m_leagueTeamNames[i+1] = avg.m_settings.m_leagueTeamNames[i];
		sch.m_conference[i+1] = avg.m_standings[i].m_conference;
		sch.m_division[i+1] = avg.m_standings[i].m_division;
		
	}
	sch.m_conferenceName1 = avg.m_settings.m_conferenceName1;
	sch.m_conferenceName2 = avg.m_settings.m_conferenceName2;
	sch.m_divisionName1 = avg.m_settings.m_divisionName1;
	sch.m_divisionName2 = avg.m_settings.m_divisionName2;
	sch.m_divisionName3 = avg.m_settings.m_divisionName3;
	sch.m_divisionName4 = avg.m_settings.m_divisionName4;
	sch.teams = avg.m_settings.m_numberteams;

	int result = sch.DoModal();
	if(result == IDOK)
	{

		int temp[33];
		for(int t=0; t<=32; t++)
		{
			temp[t] = 0;

		}

	for(int i=0; i<=12; i++)
	{
		for(int j=0; j<=30; j++)
		{
			for(int k=0; k<=15; k++)
			{

					avg.m_sched.m_schedule[i][j][k] = sch.m_sch[i][j][k];
					int g=avg.m_sched.m_schedule[i][j][k];
					int vis = g/100;
					int hom = g - vis*100;
					temp[vis] = temp[vis] + 1;
					temp[hom] = temp[hom] + 1;

			}
		}
	}
	}

}


void CBBallDoc::HealInjury(int days)
{

		//play unhealthy for one game ? May want to make more better :)
		for(int i=0; i<= 1600; i++)
		{
			int sl = i;
			int g =	avg.m_actual[sl].GetInjury() - days;
			if(g == 0 && avg.m_actual[sl].Random(1) >= (double)avg.m_actual[sl].m_games / (double)avg.m_hi_g[0]) 
				avg.m_actual[sl].m_health = 90 + avg.m_actual[sl].IntRandom(10);
			else
				avg.m_actual[sl].m_health = 100;
			if(avg.m_actual[sl].m_health >= 100) avg.m_actual[sl].m_injury_desc = "";
			if(g < 0) g = 0;
			avg.m_actual[sl].SetInjury(g);
		}
}


void CBBallDoc::EditPlayers()
{

		CEditDlg* edit = new CEditDlg;
		edit->avg = avg;
		edit->m_rookie_edit = false;

		edit->m_default_team = m_combo_team_index - 1;
		if(edit->m_default_team < 0) edit->m_default_team = 0;

		edit->m_actual = avg.m_actual[edit->m_default_team*30 + 1];


		int result = edit->DoModal();

		if(result == IDOK)
		{
			avg = edit->avg;
			bool started = avg.m_sched.m_season_started;
			avg.CalculateBetter(started);

		}

		delete edit;
}

void CBBallDoc::EditStaffs()
{


	CScoutEditDlg sc;
	sc.m_index = 0;
	for(int i=0; i<=99; i++)
	{
		sc.m_member[i] = avg.m_scout[i];
	}
	for(int i=100; i<=199; i++)
	{
		sc.m_member[i] = avg.m_coach[i-100];
	}
	for(int i=200; i<=299; i++)
	{
		sc.m_member[i] = avg.m_gm[i-200];
	}



	int r = sc.DoModal();
	if(r == IDOK)
	{
		for(int i=0; i<=99; i++)
		{
			avg.m_scout[i] = sc.m_member[i];
		}
		for(int i=100; i<=199; i++)
		{
			avg.m_coach[i-100] = sc.m_member[i]; 
		}
		for(int i=200; i<=299; i++)
		{
			 avg.m_gm[i-200] = sc.m_member[i];
		}

	}

}

void CBBallDoc::EditCities()
{

	CFranchiseEdit* edit = new CFranchiseEdit;

	edit->m_default_team = m_combo_team_index - 1;
	if(edit->m_default_team < 0) edit->m_default_team = 0;

	for(int i=0; i<=99; i++)
	{
		edit->m_finance[i] = avg.m_finance[i];
	}

	for(int i=0; i<=32; i++)
	{
		edit->m_league_team_names[i] = avg.m_settings.m_leagueTeamNames[i];
	}

	edit->m_path = avg.m_settings.m_path;
	edit->m_league_name = avg.m_settings.m_league_name;

	int result = edit->DoModal();
	if(result == IDOK)
	{
		for(int i=0; i<=99; i++)
		{
			avg.m_finance[i] = edit->m_finance[i];
		}
	}

	delete edit;		
	
}


void CBBallDoc::OnBnClickedMfMyButton2()
{
	// TODO: Add your control notification handler code here
}
