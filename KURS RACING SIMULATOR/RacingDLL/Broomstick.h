#pragma once
#include "AirTransport.h"
#include "defineDLL.h"

class Broomstick : public AirTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API Broomstick(double);
    RACINGDLL_API Broomstick();
};

