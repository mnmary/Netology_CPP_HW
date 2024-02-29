#pragma once
#include "Transport.h"
class AirTransport :
    public Transport
{
public:
    RACINGDLL_API AirTransport(std::string, double, int);
    RACINGDLL_API AirTransport();
    RACINGDLL_API void calcRacingTime(int) override;
};

