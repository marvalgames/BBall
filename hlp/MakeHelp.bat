@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by BBALL.HPJ. >"hlp\BBall.hm"
echo. >>"hlp\BBall.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\BBall.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\BBall.hm"
echo. >>"hlp\BBall.hm"
echo // Prompts (IDP_*) >>"hlp\BBall.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\BBall.hm"
echo. >>"hlp\BBall.hm"
echo // Resources (IDR_*) >>"hlp\BBall.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\BBall.hm"
echo. >>"hlp\BBall.hm"
echo // Dialogs (IDD_*) >>"hlp\BBall.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\BBall.hm"
echo. >>"hlp\BBall.hm"
echo // Frame Controls (IDW_*) >>"hlp\BBall.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\BBall.hm"
REM -- Make help for Project BBALL


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\BBall.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\BBall.hlp" goto :Error
if not exist "hlp\BBall.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\BBall.hlp" Debug
if exist Debug\nul copy "hlp\BBall.cnt" Debug
if exist Release\nul copy "hlp\BBall.hlp" Release
if exist Release\nul copy "hlp\BBall.cnt" Release
echo.
goto :done

:Error
echo hlp\BBall.hpj(1) : error: Problem encountered creating help file

:done
echo.
