#include "pch.h"
#include "FastCamel.h"
#include <iostream>
#include"consts.h"

void FastCamel::calcRacingTime(int distance)
{
    //реализация расчета для конкретного ТC
    double distanceBetweenStops = speed * timeBeforeRest;  //дистанция между соседними точками отдыха, км
    int stops = static_cast<int>(distance / distanceBetweenStops);        //количество точек отдыха - остаток от деления

    double timeRestStops = 0;  //время отдыха на всей дистанции, ч
    if (stops > 2)
    {
        //точек отдыха больше 2 - используем t1 t2 t
        timeRestStops = timeRestPoint1 + timeRestPoint2 + (stops - 2) * timeRest;
    }
    else if (stops > 1)
    {
        //точек отдыха две - используем t1 t
        timeRestStops = timeRestPoint1 + (stops - 1) * timeRest;
    }
    else if (stops == 1)
    {
        //одна точка отдыха  - используем t
        timeRestStops = timeRest;
    }
    else
    {
        //нет точек отдыха - nothing
    }
    double timeDistance = distance / speed; //время перемещения на дистанции, ч

    racingTime = timeDistance + timeRestStops; //время на дистанции + время на стопах
}
FastCamel::FastCamel(double speed, double timeBeforeRest, double timeRestPoint1, double timeRestPoint2, double timeRest) : GroundTransport(sFastCamel, speed, timeBeforeRest, timeRestPoint1, timeRestPoint2, timeRest, static_cast<int>(TransportType::TTFastCamel))
{
}
FastCamel::FastCamel() : GroundTransport()
{
    this->name = sFastCamel;
}