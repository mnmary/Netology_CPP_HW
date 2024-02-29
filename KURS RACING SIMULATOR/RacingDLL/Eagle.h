#pragma once
#include "AirTransport.h"
#include "defineDLL.h"

class Eagle :
    public AirTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API Eagle(double);
    RACINGDLL_API Eagle();
};

