#pragma once
#include "GroundTransport.h"
#include "defineDLL.h"

class FastCamel :
    public GroundTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API FastCamel(double, double, double, double, double);
    RACINGDLL_API  FastCamel();
};

