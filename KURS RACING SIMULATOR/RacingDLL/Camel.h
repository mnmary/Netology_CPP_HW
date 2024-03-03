#pragma once
#include "GroundTransport.h"
#include "defineDLL.h"

class Camel : public GroundTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API Camel(double, double, double, double);
    RACINGDLL_API Camel();
};

