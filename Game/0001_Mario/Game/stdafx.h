﻿#pragma once

//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS     // https://msdn.microsoft.com/ru-ru/library/8ef0s5kh.aspx
#define _SCL_SECURE_NO_WARNINGS     // https://msdn.microsoft.com/ru-ru/library/aa985974.aspx	
#define _CRT_SECURE_NO_DEPRECATE
//#define _HAS_EXCEPTIONS 0
//#define _HAS_ITERATOR_DEBUGGING 0
#define _SCL_SECURE 0
#define _SECURE_SCL 0
//-----------------------------------------------------------------------------
#ifdef _WIN32
#	define STRICT
#	define WIN32_LEAN_AND_MEAN      // 
#	define WIN32_EXTRA_LEAN         // 
#	define VC_EXTRALEAN             // 
#	define NOIME                    // 
#	define NOWINRES                 // 
#	define NOGDICAPMASKS            // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#	define NOVIRTUALKEYCODES        // VK_*
#	define NOWINMESSAGES            // WM_*, EM_*, LB_*, CB_*
#	define NOWINSTYLES              // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#	define NOSYSMETRICS             // SM_*
#	define NOMENUS                  // MF_*
#	define NOICONS                  // IDI_*
#	define NOKEYSTATES              // MK_*
#	define NOSYSCOMMANDS            // SC_*
#	define NORASTEROPS              // Binary and Tertiary raster ops
#	define NOSHOWWINDOW             // SW_*
#	define OEMRESOURCE              // OEM Resource values
#	define NOATOM                   // Atom Manager routines
#	define NOCLIPBOARD              // Clipboard routines
#	define NOCOLOR                  // Screen colors
#	define NOCTLMGR                 // Control and Dialog routines
#	define NODRAWTEXT               // DrawText() and DT_*
#	define NOGDI                    // All GDI defines and routines
#	define NOUSER                   // All USER defines and routines
#	define NOMB                     // MB_* and MessageBox()
#	define NOMEMMGR                 // GMEM_*, LMEM_*, GHND, LHND, associated routines
#	define NOMETAFILE               // typedef METAFILEPICT
#	define NOMINMAX                 // Macros min(a, b) and max(a, b)
#	define NOMSG                    // typedef MSG and associated routines
#	define NOOPENFILE               // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#	define NOSCROLL                 // SB_* and scrolling routines
#	define NOSERVICE                // All Service Controller routines, SERVICE_ equates, etc.
#	define NOSOUND                  // Sound driver routines
#	define NOTEXTMETRIC             // typedef TEXTMETRIC and associated routines
#	define NOWH                     // SetWindowsHook and WH_*
#	define NOWINOFFSETS             // GWL_*, GCL_*, associated routines
#	define NOCOMM                   // COMM driver routines
#	define NOKANJI                  // Kanji support stuff.
#	define NOHELP                   // Help engine interface.
#	define NOPROFILER               // Profiler interface.
#	define NODEFERWINDOWPOS         // DeferWindowPos routines
#	define NOMCX                    // Modem Configuration Extensions
#	define NOPROXYSTUB              // 
#	define NOIMAGE                  // 
#	define NO                       // 
#	define NOTAPE                   // 
#	define ANSI_ONLY                // 
#	define NOCRYPT                  // 
#	define NOKERNEL                 // All KERNEL defines and routines
#	define NONLS                    // All NLS defines and routines
#endif
//-----------------------------------------------------------------------------
// DOC: https://azrael.digipen.edu/~mmead/www/docs/CompilingWarningLevel4.html
#ifdef _MSC_VER
#	pragma warning(disable: 4290)   // Suppress 'C++ Exception Specification ignored'
#	pragma warning(disable: 4710)   // Suppress 'function ... not inlined' for Release builds
#	pragma warning(disable: 4514)   // Suppress '... unreferenced inline function has been removed'
#	pragma warning(disable: 4786)   // Suppress '... truncated to 255 chars in debug'
#	pragma warning(push, 3)         // Set warning levels to a quieter level for the STL
#endif

// STANDART C++ HEADER
#include <string>

// PLATFORM HEADER

// 3RD PARTY HEADER
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_mixer.h"

#ifdef _MSC_VER
#	pragma warning(pop)             // Restore warning levels for our code
#endif
//-----------------------------------------------------------------------------