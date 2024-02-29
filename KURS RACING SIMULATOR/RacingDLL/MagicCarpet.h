#pragma once
#include "AirTransport.h"
#include "defineDLL.h"

class MagicCarpet :
    public AirTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API MagicCarpet(double);
    RACINGDLL_API MagicCarpet();
};

