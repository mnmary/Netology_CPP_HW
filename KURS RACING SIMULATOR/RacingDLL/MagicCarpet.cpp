#include "pch.h"
#include "MagicCarpet.h"
#include <iostream>
#include "consts.h"

void MagicCarpet::calcRacingTime(int distance)
{
    double newDistance = 0;    //расстояние, км

    if (distance >= 10000)
    {
        newDistance = distance * 0.95;
    }
    else if (distance >= 5000)
    {
        newDistance = distance * 0.9;
    }
    else if (distance >= 1000)
    {
        newDistance = distance * 0.97;
    }
    else
    {
        newDistance = distance * 1;
    }

    racingTime = newDistance / speed; //время, ч
}
MagicCarpet::MagicCarpet(double speed) : AirTransport(sMagicCarpet, speed, static_cast<int>(TransportType::TTMagicCarpet))
{
}
MagicCarpet::MagicCarpet() :AirTransport()
{
    this->name = sMagicCarpet;
}