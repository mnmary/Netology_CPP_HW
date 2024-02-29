#include "pch.h"
#include "Eagle.h"
#include <iostream>
#include "consts.h"

void Eagle::calcRacingTime(int distance)
{
    double newDistance = distance * (0.94);
    racingTime = newDistance / speed; //время, ч
}
Eagle::Eagle(double speed) : AirTransport(sEagle, speed, static_cast<int>(TransportType::TTEagle))
{
}
Eagle::Eagle() :AirTransport()
{
    this->name = sEagle;
}