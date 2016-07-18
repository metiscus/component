#pragma once
#ifndef src_port_h_
#define src_port_h_

/* Determine which platform this code is running on */
#if defined(__linux__)
    #define ENV_OS_LINUX
    #define ENV_OS_UNIX
    #define ENV_OS_POSIX
#elif defined(__APPLE__) && defined(__MACH__)
    #define ENV_OS_MACOS
    #define ENV_OS_UNIX
    #define ENV_OS_POSIX
#elif defined(_WIN32)
    #define ENV_OS_WINDOWS
    #if defined(__CYGWIN__)
        #define ENV_OS_CYGWIN
        #define ENV_OS_POSIX
    #endif
#elif defined(__unix__) || defined(__unix)
    #define ENV_OS_UNIX
    #define ENV_OS_POSIX
#else
    #error Unknown or unsupported platform
#endif

/* Unlikely macros <https://github.com/clibs/unlikely> */
#if defined(__GNUC__) && (__GNUC__ > 2) && defined(__OPTIMIZE__)
#define likely(expr) __builtin_expect(!!(expr), 1)
#define unlikely(expr) __builtin_expect(!!(expr), 0)
#else
#define likely(expr) (expr)
#define unlikely(expr) (expr)
#endif


#if defined(ENV_OS_WIN32) && !defined(ENV_OS_CYGWIN)
#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX 1
#include <windows.h>
#endif


#endif
