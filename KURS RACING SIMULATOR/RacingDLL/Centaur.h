#pragma once
#include "GroundTransport.h"
#include "defineDLL.h"

class Centaur : public GroundTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API Centaur(double, double, double);
    RACINGDLL_API Centaur();
};

