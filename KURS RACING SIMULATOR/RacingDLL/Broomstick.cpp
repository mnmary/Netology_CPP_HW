#include "pch.h"
#include "Broomstick.h"
#include <iostream>
#include "consts.h"

void Broomstick::calcRacingTime(int distance)
{
    double newDistance = 0;    //расстояние, км
    int cnt1000 = static_cast<int>(distance / 1000);//in %

    newDistance = distance * ((100.0-cnt1000) / 100);
    racingTime = newDistance / speed; //время, ч
}
Broomstick::Broomstick(double speed) : AirTransport(sBroomstick, speed, static_cast<int>(TransportType::TTBroomstick))
{
}
Broomstick::Broomstick() :AirTransport()
{
    this->name = sBroomstick;
}