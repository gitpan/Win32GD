# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug" && "$(CFG)" !=\
 "Win32 Release (build 105)"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Win32_GD.MAK" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Release (build 105)" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : "\perl\lib\auto\gd\gd106.pll" $(OUTDIR)/"Win32_GD.bsc"

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# SUBTRACT CPP /X
CPP_PROJ=/nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"Win32_GD.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Win32_GD.bsc" 
BSC32_SBRS= \
	$(INTDIR)/"Win32_GD.sbr"

$(OUTDIR)/"Win32_GD.bsc" : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 gd_perl.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /OUT:"c:\perl\lib\auto\gd\gd106.pll"
LINK32_FLAGS=gd_perl.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"Win32_GD.pdb"\
 /MACHINE:I386 /DEF:".\Win32_GD.DEF" /OUT:"c:\perl\lib\auto\gd\gd106.pll"\
 /IMPLIB:$(OUTDIR)/"Win32_GD.lib" 
DEF_FILE=".\Win32_GD.DEF"
LINK32_OBJS= \
	$(INTDIR)/"Win32_GD.obj"

"\perl\lib\auto\gd\gd106.pll" : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : "\perl\lib\auto\gd\gd.pll" $(OUTDIR)/"Win32_GD.bsc"

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /GX /Zi /YX /Od /Gy /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# SUBTRACT CPP /u
CPP_PROJ=/nologo /W3 /GX /Zi /YX /Od /Gy /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"Win32_GD.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"Win32_GD.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Win32_GD.bsc" 
BSC32_SBRS= \
	$(INTDIR)/"Win32_GD.sbr"

$(OUTDIR)/"Win32_GD.bsc" : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
# ADD LINK32 gd_perl_debug.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"c:\perl\lib\auto\gd\gd.pll"
LINK32_FLAGS=gd_perl_debug.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"Win32_GD.pdb" /DEBUG\
 /MACHINE:I386 /DEF:".\Win32_GD.DEF" /OUT:"c:\perl\lib\auto\gd\gd.pll"\
 /IMPLIB:$(OUTDIR)/"Win32_GD.lib" 
DEF_FILE=".\Win32_GD.DEF"
LINK32_OBJS= \
	$(INTDIR)/"Win32_GD.obj"

"\perl\lib\auto\gd\gd.pll" : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Release (build 105)"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Win32_Re"
# PROP BASE Intermediate_Dir "Win32_Re"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Win32_Re"
# PROP Intermediate_Dir "Win32_Re"
OUTDIR=.\Win32_Re
INTDIR=.\Win32_Re

ALL : "\perl\lib\auto\gd\gd105.pll" $(OUTDIR)/"Win32_GD.bsc"

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /I "c:\source\include\perl105" /I "c:\source\include" /I "d:\msvc\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# SUBTRACT BASE CPP /X
# ADD CPP /nologo /W3 /GX /YX /O2 /X /I "c:\source\include\perl105" /I "c:\source\include" /I "d:\msvc\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
CPP_PROJ=/nologo /W3 /GX /YX /O2 /X /I "c:\source\include\perl105" /I\
 "c:\source\include" /I "d:\msvc\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"Win32_GD.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\Win32_Re/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Win32_GD.bsc" 
BSC32_SBRS= \
	$(INTDIR)/"Win32_GD.sbr"

$(OUTDIR)/"Win32_GD.bsc" : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 gd.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /OUT:"c:\perl\lib\auto\gd\gd106.pll"
# ADD LINK32 gd_perl.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /OUT:"c:\perl\lib\auto\gd\gd105.pll"
LINK32_FLAGS=gd_perl.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"Win32_GD.pdb"\
 /MACHINE:I386 /DEF:".\Win32_GD.DEF" /OUT:"c:\perl\lib\auto\gd\gd105.pll"\
 /IMPLIB:$(OUTDIR)/"Win32_GD.lib" 
DEF_FILE=".\Win32_GD.DEF"
LINK32_OBJS= \
	$(INTDIR)/"Win32_GD.obj"

"\perl\lib\auto\gd\gd105.pll" : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\Win32_GD.DEF
# End Source File
################################################################################
# Begin Source File

SOURCE=.\Win32_GD.CPP
DEP_WIN32=\
	"\source\include\perl\extern.h"\
	"\source\include\perl\perl.h"\
	"\source\include\perl\xsub.h"\
	"\source\include\gd.h"\
	"\source\include\perl\embed.h"\
	"\source\include\perl\config.h"\
	"D:\MSVC\INCLUDE\sys\TYPES.H"\
	"D:\MSVC\INCLUDE\sys\STAT.H"\
	"\source\include\perl\dirent.h"\
	"\source\include\perl\handy.h"\
	"\source\include\perl\dosish.h"\
	"\source\include\perl\unixish.h"\
	"\source\include\perl\regexp.h"\
	"\source\include\perl\sv.h"\
	"\source\include\perl\util.h"\
	"\source\include\perl\form.h"\
	"\source\include\perl\gv.h"\
	"\source\include\perl\cv.h"\
	"\source\include\perl\opcode.h"\
	"\source\include\perl\op.h"\
	"\source\include\perl\cop.h"\
	"\source\include\perl\av.h"\
	"\source\include\perl\hv.h"\
	"\source\include\perl\scope.h"\
	"\source\include\perl\perly.h"\
	"\source\include\perl\perllib.h"\
	"\source\include\perl\proto.h"\
	"\source\include\perl\pp.h"\
	"\source\include\perl\ntpp.h"\
	"\source\include\perl\mg.h"\
	"\source\include\perl\NTXSub.h"\
	"\source\include\gdfontg.h"\
	"\source\include\gdfontl.h"\
	"\source\include\gdfontmb.h"\
	"\source\include\gdfonts.h"\
	"\source\include\gdfontt.h"\
	"\source\include\perl\nt.h"\
	"\source\include\perl\iperlsup.h"

!IF  "$(CFG)" == "Win32 Release"

$(INTDIR)/"Win32_GD.obj" :  $(SOURCE)  $(DEP_WIN32) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/"Win32_GD.obj" :  $(SOURCE)  $(DEP_WIN32) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Release (build 105)"

$(INTDIR)/"Win32_GD.obj" :  $(SOURCE)  $(DEP_WIN32) $(INTDIR)

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
