#pragma once
#include "GroundTransport.h"
#include "defineDLL.h"

class AllTerrainBoots :
    public GroundTransport
{
public:
    RACINGDLL_API void calcRacingTime(int) override;
    RACINGDLL_API AllTerrainBoots(double, double, double, double);
    RACINGDLL_API AllTerrainBoots();
};

