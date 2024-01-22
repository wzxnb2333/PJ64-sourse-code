/*
 * Project 64 - A Nintendo 64 emulator.
 *
 * (c) Copyright 2001 zilmar (zilmar@emulation64.com) and 
 * Jabo (jabo@emulation64.com).
 *
 * pj64 homepage: www.pj64.net
 *
 * Permission to use, copy, modify and distribute Project64 in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Project64 is freeware for PERSONAL USE only. Commercial users should
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for Project64 or software derived from Project64.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so if they want them.
 *
 */
#ifndef __main_h 
#define __main_h 

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' ""version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "MemTest.h"

#include <stdio.h>
#include <objbase.h>
#include "Types.h"
#include "win32Timer.h"
#include "Profiling.h"
#include "SettingsAPI.h"
#include "rombrowser.h"
#include "Language.h"
#include "FileUtil.h"
#ifdef _MSC_VER
	typedef __int8 s8;
	typedef unsigned __int8 u8;
	typedef __int16 s16;
	typedef unsigned __int16 u16;
	typedef __int32 s32;
	typedef unsigned __int32 u32;
	typedef __int64 s64;
	typedef unsigned __int64 u64;
	typedef float f32;
	typedef double f64;
	typedef unsigned __int32 uptr;
#endif

/********* General Defaults **********/
#ifndef EXTERNAL_RELEASE
#define AppVer   "Project64 - Build 57"
#define AppName  "Project64 (Build 57)"
#else
//#define BETA_VERSION
#define AppVer   "Project64 - Version 1.6"
#ifdef BETA_VERSION
#define AppName  "Project64 Version 1.6"
#else
#define AppName  "Project64 Version 1.6"
#endif
#endif

#define IniName						"Project64.rdb"
#define NotesIniName				"Project64.rdn"
#define ExtIniName					"Project64.rdx"
#define CheatIniName				"Project64.cht"
#define LangFileName				"Project64.lng"
#define CacheFileName				"Project64.cache"
#define Default_AdvancedBlockLink	TRUE
#define Default_AutoStart			TRUE
#define Default_AutoSleep			TRUE
#define Default_DisableRegCaching	FALSE
#define Default_RdramSize			0x400000
#define Default_UseIni				TRUE
#define Default_AutoZip				TRUE
#define Default_LimitFPS			TRUE
#define Default_AlwaysOnTop			FALSE
#define Default_BasicMode			TRUE
#define Default_RememberCheats		FALSE
#define Default_RomsToRemember		4
#define Default_RomsDirsToRemember	4
#define LinkBlocks
#define TLB_HACK

/*********** Menu Stuff **************/
#define ID_FILE_RECENT_FILE		1000
#define ID_FILE_RECENT_DIR		1100
#define ID_LANG_SELECT			2000

/************** Core *****************/
#define CPU_Default					-1
#define CPU_Interpreter				0
#define CPU_Recompiler				1
#define Default_CPU					CPU_Recompiler

/*********** GFX Defaults ************/
#define NoOfFrames	7
//#define CFB_READ

/******* Self modifying code *********/
#define ModCode_Default				-1
#define ModCode_None				0
#define ModCode_Cache				1
#define ModCode_ProtectedMemory		2
#define ModCode_ChangeMemory		4
#define ModCode_CheckMemoryCache	6
#define ModCode_CheckMemory2		7 // *** Add in Build 53

/********** Counter Factor ***********/
#define Default_CountPerOp			2

/************ Debugging **************/
#define Default_HaveDebugger		FALSE
#define Default_AutoMap				TRUE
#define Default_ShowUnhandledMemory	FALSE
#define Default_ShowTLBMisses		FALSE
#define Default_ShowDlistCount		FALSE
#define Default_ShowCompileMemory	TRUE
#define Default_ShowPifRamErrors	FALSE
#define Default_SelfModCheck		ModCode_CheckMemory2
//#define Interpreter_StackTest		

/************ Profiling **************/
#define Default_ShowCPUPer			FALSE
#define Default_ProfilingOn			FALSE
#define Default_IndvidualBlock		FALSE

/********** Rom Browser **************/
#define Default_UseRB				TRUE
#define Default_Rercursion			FALSE
#define Default_RomStatus			"Unknown"

/************* Logging ***************/
//#define Log_x86Code

/********* Global Variables **********/
extern LARGE_INTEGER Frequency, Frames[NoOfFrames], LastFrame;
extern BOOL HaveDebugger, AutoLoadMapFile, ShowUnhandledMemory, ShowTLBMisses, 
	ShowDListAListCount, ShowCompMem, Profiling, IndvidualBlock, AutoStart, 
	AutoSleep, DisableRegCaching, UseIni, UseTlb, UseLinking, RomBrowser,
	IgnoreMove, Rercursion, ShowPifRamErrors, LimitFPS, ShowCPUPer, AutoZip, 
	AutoFullScreen, SystemABL, AlwaysOnTop, BasicMode, DelaySI, RememberCheats,AudioSignal;
extern DWORD CurrentFrame, CPU_Type, SystemCPU_Type, SelfModCheck, SystemSelfModCheck, 
	RomsToRemember, RomDirsToRemember;
extern HWND hMainWindow, hHiddenWin, hStatusWnd;
extern char CurrentSave[256], main_directory[_MAX_PATH];
extern HMENU hMainMenu;
extern HINSTANCE hInst;

/******** Function Prototype *********/
DWORD AsciiToHex          ( char * HexValue );
void AlwaysOnTopWindow    ( HWND hWnd );
void  __cdecl DisplayError       ( char * Message, ... );
void DebugError       ( char * Message, ... );
void ChangeWinSize        ( HWND hWnd, long width, long height, HWND hStatusBar );
void  DisplayFPS          ( void );
char* GetExtIniFileName   ( void );
char* GetIniFileName      ( void );
char* GetLangFileName     ( void );
char* GetNotesIniFileName ( void );
int   GetStoredWinPos     ( char * WinName, DWORD * X, DWORD * Y );
int   GetStoredWinSize    ( char * WinName, DWORD * Width, DWORD * Height );
void  LoadSettings        ( void );
void  MenuSetText         ( HMENU hMenu, int MenuPos, char * Title, char * ShotCut );
void  RegisterExtension   ( char * Extension, BOOL RegisterWithPj64 );
void  SetCurrentSaveState ( HWND hWnd, int State);
void  SetupMenu           ( HWND hWnd );
//void  SetupMenuTitle      ( HMENU hMenu, int MenuPos, char * ShotCut, char * Title, char * Language, char *  LangFile );
void  StoreCurrentWinPos  ( char * WinName, HWND hWnd );
void  StoreCurrentWinSize ( char * WinName, HWND hWnd );
BOOL  TestExtensionRegistered ( char * Extension );

void AboutBox (void);


#endif
