#include "pch.h"
#include "AllTerrainBoots.h"
#include <iostream>
#include "consts.h"

void AllTerrainBoots::calcRacingTime(int distance)
{
    //реализация расчета для конкретного ТC
    double distanceBetweenStops = speed * timeBeforeRest;  //дистанция между соседними точками отдыха, км
    int stops = static_cast<int>(distance / distanceBetweenStops);        //количество точек отдыха - остаток от деления

    double timeRestStops = 0;  //время отдыха на всей дистанции, ч
    if (stops > 1)
    {
        //точек отдыха больше чем одна - используем t1 t
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

AllTerrainBoots::AllTerrainBoots(double speed, double timeBeforeRest, double timeRestPoint1, double timeRest) : GroundTransport(sAllTerrainBoots, speed, timeBeforeRest, timeRestPoint1, timeRest, timeRest, static_cast<int>(TransportType::TTAllTerrainBoots))
{
}
AllTerrainBoots::AllTerrainBoots() : GroundTransport()
{
    this->name = sAllTerrainBoots;
}