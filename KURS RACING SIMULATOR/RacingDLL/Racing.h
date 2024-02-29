#pragma once
#include <iostream>
#include "consts.h"
#include "Transport.h"
#include "defineDLL.h"
//#include "Tr.h"

class Racing
{
protected:
	int distance = 0;
	int cntRegTransport = 0;
	RacingType racingType = RacingType::None;
	Transport* transports[7] = {};
public:
	void RACINGDLL_API registerTransport(Transport*);
	RACINGDLL_API Transport* getTransport(int);

	void RACINGDLL_API sortRegTransport();
	int RACINGDLL_API getCntRegTransport();
	void RACINGDLL_API initRacing();
	void RACINGDLL_API calcRacingTime();
	int RACINGDLL_API getDistance();
	void RACINGDLL_API setDistance(int);
	RACINGDLL_API RacingType getRacingType();
	void RACINGDLL_API setRacingType(RacingType);

	void RACINGDLL_API processRacing();
};

