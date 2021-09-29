# Microsoft Developer Studio Project File - Name="BBall" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=BBall - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BBall.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BBall.mak" CFG="BBall - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BBall - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BBall - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "BBall - Win32 Release Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BBall - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W4 /GX /O2 /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 Htmlhelp.lib /nologo /subsystem:windows /machine:I386 /libpath:"C:\Program Files\HTML Help Workshop\lib"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "BBall - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Htmlhelp.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"C:\Program Files\HTML Help Workshop\lib"

!ELSEIF  "$(CFG)" == "BBall - Win32 Release Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BBall___Win32_Release_Debug"
# PROP BASE Intermediate_Dir "BBall___Win32_Release_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "BBall___Win32_Release_Debug"
# PROP Intermediate_Dir "BBall___Win32_Release_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W4 /GX /O2 /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W4 /GX /O2 /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Htmlhelp.lib /nologo /subsystem:windows /machine:I386 /libpath:"C:\Program Files\HTML Help Workshop\lib"
# SUBTRACT BASE LINK32 /debug
# ADD LINK32 Htmlhelp.lib /nologo /subsystem:windows /debug /machine:I386 /libpath:"C:\Program Files\HTML Help Workshop\lib"

!ENDIF 

# Begin Target

# Name "BBall - Win32 Release"
# Name "BBall - Win32 Debug"
# Name "BBall - Win32 Release Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AboutDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\AllStarDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AllStarWeekend.cpp
# End Source File
# Begin Source File

SOURCE=.\AllTimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoSchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Average.cpp
# End Source File
# Begin Source File

SOURCE=.\Awards.cpp
# End Source File
# Begin Source File

SOURCE=.\AwardsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BBall.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\BBall.hpj

!IF  "$(CFG)" == "BBall - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__BBALL="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=BBall
InputPath=.\hlp\BBall.hpj
InputName=BBall

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__BBALL="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=BBall
InputPath=.\hlp\BBall.hpj
InputName=BBall

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Release Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
USERDEP__BBALL="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\BBall___Win32_Release_Debug
TargetName=BBall
InputPath=.\hlp\BBall.hpj
InputName=BBall

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\BBall.rc
# End Source File
# Begin Source File

SOURCE=.\BBallCoachView.cpp
# End Source File
# Begin Source File

SOURCE=.\BBallDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\BBallFile.cpp
# End Source File
# Begin Source File

SOURCE=.\BBallSchedule.cpp
# End Source File
# Begin Source File

SOURCE=.\BBallSettings.cpp
# End Source File
# Begin Source File

SOURCE=.\BBallView.cpp
# End Source File
# Begin Source File

SOURCE=.\BitmapCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\BoxDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Boxscore.cpp
# End Source File
# Begin Source File

SOURCE=.\Boxscore.h
# End Source File
# Begin Source File

SOURCE=.\BudgetSheetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CampDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Career.cpp
# End Source File
# Begin Source File

SOURCE=.\CareerStatsCardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CityProfileDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CJFlatComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorStaticST.cpp
# End Source File
# Begin Source File

SOURCE=.\Computer.cpp
# End Source File
# Begin Source File

SOURCE=.\constants.cpp
# End Source File
# Begin Source File

SOURCE=.\Curvefit.cpp
# End Source File
# Begin Source File

SOURCE=.\DataSort.cpp
# End Source File
# Begin Source File

SOURCE=.\DefenseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Digistatic.cpp
# End Source File
# Begin Source File

SOURCE=.\Disk.cpp
# End Source File
# Begin Source File

SOURCE=.\DraftDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DropBtn.cpp
# End Source File
# Begin Source File

SOURCE=.\EditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\Financial.cpp
# End Source File
# Begin Source File

SOURCE=.\FranchiseChangeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FranchiseEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\FreeAgentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Future.cpp
# End Source File
# Begin Source File

SOURCE=.\GamePlan.cpp
# End Source File
# Begin Source File

SOURCE=.\GameView.cpp
# End Source File
# Begin Source File

SOURCE=.\High.cpp
# End Source File
# Begin Source File

SOURCE=.\HireStaff.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryAwards.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryAwardsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryDraftDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryStats.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryTeamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryView.cpp
# End Source File
# Begin Source File

SOURCE=.\HofDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Html.cpp
# End Source File
# Begin Source File

SOURCE=.\HtmlDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HtmlMsc.cpp
# End Source File
# Begin Source File

SOURCE=.\ImpExp.cpp
# End Source File
# Begin Source File

SOURCE=.\ImportDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ImportPlayersDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InjuryTable.cpp
# End Source File
# Begin Source File

SOURCE=.\Label.cpp
# End Source File
# Begin Source File

SOURCE=.\LeadersDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LeagueTeamSchedule.cpp
# End Source File
# Begin Source File

SOURCE=.\LeagueTeamsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MiscDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\NegotiateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OfferTrades1.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Own.cpp
# End Source File
# Begin Source File

SOURCE=.\PbpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Picture.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerCardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Playoff.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayoffDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressView.cpp
# End Source File
# Begin Source File

SOURCE=.\Record.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordbookDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReportDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Retirement.cpp
# End Source File
# Begin Source File

SOURCE=.\RookieCardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RookieDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ScheduleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ScheduleView.cpp
# End Source File
# Begin Source File

SOURCE=.\ScoutEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ScoutProfileDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SplashScreenEx.cpp
# End Source File
# Begin Source File

SOURCE=.\Staff.cpp
# End Source File
# Begin Source File

SOURCE=.\StaffDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StandingsView.cpp
# End Source File
# Begin Source File

SOURCE=.\StatsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SxGroupBox.cpp
# End Source File
# Begin Source File

SOURCE=.\TeamFinancial.cpp
# End Source File
# Begin Source File

SOURCE=.\TeamView.cpp
# End Source File
# Begin Source File

SOURCE=.\TimeoutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolsView.cpp
# End Source File
# Begin Source File

SOURCE=.\TradeBlockDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TradeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Transactions.cpp
# End Source File
# Begin Source File

SOURCE=.\TransactionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TypeGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\XComboList.cpp
# End Source File
# Begin Source File

SOURCE=.\XHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XListCtrl.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AboutDlg1.h
# End Source File
# Begin Source File

SOURCE=.\AllStarDlg.h
# End Source File
# Begin Source File

SOURCE=.\AllStarWeekend.h
# End Source File
# Begin Source File

SOURCE=.\AllTimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\AutoSchDlg.h
# End Source File
# Begin Source File

SOURCE=.\Average.h
# End Source File
# Begin Source File

SOURCE=.\Awards.h
# End Source File
# Begin Source File

SOURCE=.\AwardsDlg.h
# End Source File
# Begin Source File

SOURCE=.\BBall.h
# End Source File
# Begin Source File

SOURCE=.\BBallCoachView.h
# End Source File
# Begin Source File

SOURCE=.\BBallDoc.h
# End Source File
# Begin Source File

SOURCE=.\BBallFile.h
# End Source File
# Begin Source File

SOURCE=.\BBallSchedule.h
# End Source File
# Begin Source File

SOURCE=.\BBallSettings.h
# End Source File
# Begin Source File

SOURCE=.\BBallView.h
# End Source File
# Begin Source File

SOURCE=.\BitmapCtrl.h
# End Source File
# Begin Source File

SOURCE=.\BoxDlg.h
# End Source File
# Begin Source File

SOURCE=.\BudgetSheetDlg.h
# End Source File
# Begin Source File

SOURCE=.\CampDlg.h
# End Source File
# Begin Source File

SOURCE=.\Career.h
# End Source File
# Begin Source File

SOURCE=.\CareerStatsCardDlg.h
# End Source File
# Begin Source File

SOURCE=.\CInjuryTable.h
# End Source File
# Begin Source File

SOURCE=.\CityProfileDlg.h
# End Source File
# Begin Source File

SOURCE=.\CJFlatComboBox.h
# End Source File
# Begin Source File

SOURCE=.\ColorStaticST.h
# End Source File
# Begin Source File

SOURCE=.\Computer.h
# End Source File
# Begin Source File

SOURCE=.\Constants.h
# End Source File
# Begin Source File

SOURCE=.\CRetirement.h
# End Source File
# Begin Source File

SOURCE=.\Curvefit.h
# End Source File
# Begin Source File

SOURCE=.\DataSort.h
# End Source File
# Begin Source File

SOURCE=.\DefenseDlg.h
# End Source File
# Begin Source File

SOURCE=.\Digistatic.h
# End Source File
# Begin Source File

SOURCE=.\Disk.h
# End Source File
# Begin Source File

SOURCE=.\DraftDlg.h
# End Source File
# Begin Source File

SOURCE=.\DropBtn.h
# End Source File
# Begin Source File

SOURCE=.\EditDlg.h
# End Source File
# Begin Source File

SOURCE=.\Engine.h
# End Source File
# Begin Source File

SOURCE=.\Financial.h
# End Source File
# Begin Source File

SOURCE=.\FranchiseChangeDlg.h
# End Source File
# Begin Source File

SOURCE=.\FranchiseEdit.h
# End Source File
# Begin Source File

SOURCE=.\FreeAgentDlg.h
# End Source File
# Begin Source File

SOURCE=.\Future.h
# End Source File
# Begin Source File

SOURCE=.\GamePlan.h
# End Source File
# Begin Source File

SOURCE=.\GameView.h
# End Source File
# Begin Source File

SOURCE=.\High.h
# End Source File
# Begin Source File

SOURCE=.\HireStaff.h
# End Source File
# Begin Source File

SOURCE=.\HistoryAwards.h
# End Source File
# Begin Source File

SOURCE=.\HistoryAwardsDlg.h
# End Source File
# Begin Source File

SOURCE=.\HistoryDraftDlg.h
# End Source File
# Begin Source File

SOURCE=.\HistoryStats.h
# End Source File
# Begin Source File

SOURCE=.\HistoryTeamDlg.h
# End Source File
# Begin Source File

SOURCE=.\HistoryView.h
# End Source File
# Begin Source File

SOURCE=.\HofDlg.h
# End Source File
# Begin Source File

SOURCE=.\Html.h
# End Source File
# Begin Source File

SOURCE=.\HtmlDlg.h
# End Source File
# Begin Source File

SOURCE=.\HtmlMsc.h
# End Source File
# Begin Source File

SOURCE=.\ImpExp.h
# End Source File
# Begin Source File

SOURCE=.\ImportDlg.h
# End Source File
# Begin Source File

SOURCE=.\ImportPlayersDlg.h
# End Source File
# Begin Source File

SOURCE=.\InjuryTable.h
# End Source File
# Begin Source File

SOURCE=.\Label.h
# End Source File
# Begin Source File

SOURCE=.\LeadersDlg.h
# End Source File
# Begin Source File

SOURCE=.\LeagueTeamSchedule.h
# End Source File
# Begin Source File

SOURCE=.\LeagueTeamsDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\MemDCDraw.h
# End Source File
# Begin Source File

SOURCE=.\MiscDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyComboBox.h
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\NegotiateDlg.h
# End Source File
# Begin Source File

SOURCE=.\OfferTrades1.h
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\Own.h
# End Source File
# Begin Source File

SOURCE=.\PbpDlg.h
# End Source File
# Begin Source File

SOURCE=.\Picture.h
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\PlayerCardDlg.h
# End Source File
# Begin Source File

SOURCE=.\Playoff.h
# End Source File
# Begin Source File

SOURCE=.\PlayoffDlg.h
# End Source File
# Begin Source File

SOURCE=.\ProgressDlg1.h
# End Source File
# Begin Source File

SOURCE=.\ProgressView.h
# End Source File
# Begin Source File

SOURCE=.\Record.h
# End Source File
# Begin Source File

SOURCE=.\RecordbookDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.h
# End Source File
# Begin Source File

SOURCE=.\ReportDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "BBall - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=BBall
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=BBall
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Release Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=BBall
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Retirement.h
# End Source File
# Begin Source File

SOURCE=.\Rgbcolor.h
# End Source File
# Begin Source File

SOURCE=.\RookieCardDlg.h
# End Source File
# Begin Source File

SOURCE=.\RookieDlg.h
# End Source File
# Begin Source File

SOURCE=.\ScheduleDlg.h
# End Source File
# Begin Source File

SOURCE=.\ScheduleView.h
# End Source File
# Begin Source File

SOURCE=.\ScoutEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\ScoutProfileDlg.h
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\SplashScreenEx.h
# End Source File
# Begin Source File

SOURCE=.\Staff.h
# End Source File
# Begin Source File

SOURCE=.\StaffDlg.h
# End Source File
# Begin Source File

SOURCE=.\StandingsView.h
# End Source File
# Begin Source File

SOURCE=.\StatsDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SxGroupBox.h
# End Source File
# Begin Source File

SOURCE=.\TeamFinancial.h
# End Source File
# Begin Source File

SOURCE=.\TeamView.h
# End Source File
# Begin Source File

SOURCE=.\TimeoutDlg.h
# End Source File
# Begin Source File

SOURCE=.\ToolsView.h
# End Source File
# Begin Source File

SOURCE=.\TradeBlockDlg.h
# End Source File
# Begin Source File

SOURCE=.\TradeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Transactions.h
# End Source File
# Begin Source File

SOURCE=.\TransactionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\TypeGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\XComboList.h
# End Source File
# Begin Source File

SOURCE=.\XHeaderCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XListCtrl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\32x32x16_CancelBor.ico
# End Source File
# Begin Source File

SOURCE=.\res\About.ico
# End Source File
# Begin Source File

SOURCE=.\arrow.cur
# End Source File
# Begin Source File

SOURCE=.\arrowcop.cur
# End Source File
# Begin Source File

SOURCE=.\res\Baloon.ico
# End Source File
# Begin Source File

SOURCE=".\res\bball help.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\BBall.ico
# End Source File
# Begin Source File

SOURCE=.\res\BBall.rc2
# End Source File
# Begin Source File

SOURCE=.\res\BBallDoc.ico
# End Source File
# Begin Source File

SOURCE=".\res\big man.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\big man3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\big-man3.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_b.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bk256.bmp
# End Source File
# Begin Source File

SOURCE=.\res\blue.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BmpBack.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Butterfly.ico
# End Source File
# Begin Source File

SOURCE=.\res\Button.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonsmall.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Cancel1_32x32x16.ico
# End Source File
# Begin Source File

SOURCE=.\res\Cancel3_32x32x256.ico
# End Source File
# Begin Source File

SOURCE=.\res\Cancel4_32x32x2.ico
# End Source File
# Begin Source File

SOURCE=.\res\Cannibal.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CButtonST_Demo.ico
# End Source File
# Begin Source File

SOURCE=".\res\cc-background.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\CDRom.ico
# End Source File
# Begin Source File

SOURCE=.\res\Classes1_32x32x16.ico
# End Source File
# Begin Source File

SOURCE=.\res\coach.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor.cur
# End Source File
# Begin Source File

SOURCE=.\res\cximage.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ddraw_in_mfcwind.ico
# End Source File
# Begin Source File

SOURCE=.\res\EOapp.ico
# End Source File
# Begin Source File

SOURCE=.\res\Explorer.ico
# End Source File
# Begin Source File

SOURCE=.\res\floor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FRANKIE.ico
# End Source File
# Begin Source File

SOURCE=.\res\gamescore.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Halloween1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Hardwoodfloor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=".\res\ICON 51.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 52.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 53.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 54.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 55.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 56.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 57.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 58.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 59.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 60.ico"
# End Source File
# Begin Source File

SOURCE=".\res\icon 61.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 74.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 75.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 76.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICON 77.ico"
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon10.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon18.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon20.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon21.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon22.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon23.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon24.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon25.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon26.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon27.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon28.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon29.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon30.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon31.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon39.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon41.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon49.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon50.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon51.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon52.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon53.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon54.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon55.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon56.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon57.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon58.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon59.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon62.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon68.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon69.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon7.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon70.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon72.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon73.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon74.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon75.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon76.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon77.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon8.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_form.ico
# End Source File
# Begin Source File

SOURCE=.\res\jpg1.bin
# End Source File
# Begin Source File

SOURCE=".\res\JSB PIC3 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\JSB-MAIN-SCREEN.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\JSB-SCREEN.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\JSB1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\JSB2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\JSBPIC2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Key manager.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Lamp1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lamp2.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOff.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOn.ico
# End Source File
# Begin Source File

SOURCE=.\res\Left2_32x32x16.ico
# End Source File
# Begin Source File

SOURCE=.\res\Litening.ico
# End Source File
# Begin Source File

SOURCE=.\res\logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\michael_jordan.jpg
# End Source File
# Begin Source File

SOURCE=.\res\new.bmp
# End Source File
# Begin Source File

SOURCE=.\nodrop.cur
# End Source File
# Begin Source File

SOURCE=.\res\pic.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Picture3 bcopy.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\Picture3 copy.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Right2_32x32x16.ico
# End Source File
# Begin Source File

SOURCE=.\res\roster.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Run.ico
# End Source File
# Begin Source File

SOURCE=.\res\SAMPE3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SAMPE4.bmp
# End Source File
# Begin Source File

SOURCE=".\res\SAMPLE-4-JSB.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\sample.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sample2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\sample3-jsb.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\sample5jsb.bmp
# End Source File
# Begin Source File

SOURCE=.\res\schedule.bmp
# End Source File
# Begin Source File

SOURCE=.\sdi.ico
# End Source File
# Begin Source File

SOURCE=.\res\Search1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Shot.ico
# End Source File
# Begin Source File

SOURCE=.\res\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\standings.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SWScan00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Untitled-1.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\untitled.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Workgroup.ico
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\BBall.cnt

!IF  "$(CFG)" == "BBall - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\BBall.cnt
InputName=BBall

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\BBall.cnt
InputName=BBall

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "BBall - Win32 Release Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\BBall___Win32_Release_Debug
InputPath=.\hlp\BBall.cnt
InputName=BBall

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section BBall : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:102
# 	2:21:SplashScreenInsertKey:4.0
# End Section
