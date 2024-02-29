#include "pch.h"
#include "AirTransport.h"
#include <iostream>
#include "consts.h"
#include "defineDLL.h"

AirTransport::AirTransport(std::string name, double speed, int iType) :Transport(name, sAirTransport, speed, iType)
{
    //nothing
}
AirTransport::AirTransport() :Transport()
{
    this->type = sAirTransport;
}
void AirTransport::calcRacingTime(int distance)
{
    racingTime = 0.0;
}