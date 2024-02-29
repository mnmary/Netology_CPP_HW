#include "pch.h"
#include "GroundTransport.h"
#include <iostream>
#include "consts.h"
#include "defineDLL.h"

double GroundTransport::getTimeRest()
{
    return timeRest;
}
void GroundTransport::setTimeRest(double timeRest)
{
    this->timeRest = timeRest;
}
double GroundTransport::getTimeBeforeRest()
{
    return timeBeforeRest;
}
void GroundTransport::setTimeBeforeRest(double timeBeforeRest)
{
    this->timeBeforeRest = timeBeforeRest;
}
double GroundTransport::getTimeRestPoint1()
{
    return timeRestPoint1;
}
void GroundTransport::setTimeRestPoint1(double timeRestPoint1)
{
    this->timeRestPoint1 = timeRestPoint1;
}
double GroundTransport::getTimeRestPoint2()
{
    return timeRestPoint2;
}
void GroundTransport::setTimeRestPoint2(double timeRestPoint2)
{
    this->timeRestPoint2 = timeRestPoint2;
}


GroundTransport::GroundTransport(std::string name, double speed, double timeBeforeRest, double timeRestPoint1, double timeRestPoint2, double timeRest, int iType) :Transport(name, sGroundTransport, speed, iType)
{
    this->timeBeforeRest = timeBeforeRest;
    this->timeRestPoint1 = timeRestPoint1;
    this->timeRestPoint2 = timeRestPoint2;
    this->timeRest = timeRest;

}
GroundTransport::GroundTransport() :Transport()
{
    this->type = sGroundTransport;
}
void GroundTransport::calcRacingTime(int distance)
{
    racingTime = 0.0;
}