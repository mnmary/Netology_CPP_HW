#pragma once
#ifdef RACINGDLL_EXPORTS
#define RACINGDLL_API __declspec(dllexport)
#else
#define RACINGDLL_API __declspec(dllimport)
#endif