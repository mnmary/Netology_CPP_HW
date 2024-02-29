#pragma once
#include <iostream>
#include "defineDLL.h"

class Tr
{
protected:
	double speed = 0.0;
	std::string name = "";
	std::string type = "";
	double racingTime = 0.0;
	int iType = 0;
public:
	RACINGDLL_API double getRacingTime();
	RACINGDLL_API std::string getName();
	RACINGDLL_API std::string getType();
	RACINGDLL_API double getSpeed();
	RACINGDLL_API void setName(std::string);
	RACINGDLL_API void setType(std::string);
	RACINGDLL_API void setSpeed(double);
	RACINGDLL_API Tr();
	RACINGDLL_API Tr(std::string, std::string, double, int);
	RACINGDLL_API virtual void calcRacingTime(int);
	RACINGDLL_API int getIType();
};

