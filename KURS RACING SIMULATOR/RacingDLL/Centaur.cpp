#include "pch.h"
#include "Centaur.h"
#include <iostream>
#include "consts.h"

void Centaur::calcRacingTime(int distance)
{
    //реализация расчета для конкретного ТC
    double distanceBetweenStops = speed * timeBeforeRest;  //дистанция между соседними точками отдыха, км
    int stops = static_cast<int>(distance / distanceBetweenStops);        //количество точек отдыха - остаток от деления
    double delta = distance - (stops * distanceBetweenStops);//
    if (delta == 0)//последний стоп - на финише
    {
        if (stops > 0)
        {
            stops--; //последний стоп не нужен
        }
    }

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

Centaur::Centaur(double speed, double timeBeforeRest, double timeRest) : GroundTransport(sCentaur, speed, timeBeforeRest, timeRest, timeRest, timeRest, static_cast<int>(TransportType::TTCentaur))
{
}
Centaur::Centaur() : GroundTransport()
{
    this->name = sCentaur;
}