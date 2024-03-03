#pragma once
#pragma warning (disable : 4251)
#ifdef RACINGDLL_EXPORTS
#define RACINGDLL_API __declspec(dllexport)
#else
#define RACINGDLL_API __declspec(dllimport)
#endif