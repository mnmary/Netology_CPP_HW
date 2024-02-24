#pragma once
#include "iostream"
#ifdef DYNAMICDLL_EXPORTS
#define DYNAMICDLL_API __declspec(dllexport)
#else
#define DYNAMICDLL_API __declspec(dllimport)
#endif
class Leaver
{
public:
	void DYNAMICDLL_API leave(std::string nm);
};

