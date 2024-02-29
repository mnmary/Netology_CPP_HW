#include "pch.h"
#include "AllTerrainBoots.h"
#include <iostream>
#include "consts.h"

void AllTerrainBoots::calcRacingTime(int distance)
{
    //���������� ������� ��� ����������� �C
    double distanceBetweenStops = speed * timeBeforeRest;  //��������� ����� ��������� ������� ������, ��
    int stops = static_cast<int>(distance / distanceBetweenStops);        //���������� ����� ������ - ������� �� �������

    double timeRestStops = 0;  //����� ������ �� ���� ���������, �
    if (stops > 1)
    {
        //����� ������ ������ ��� ���� - ���������� t1 t
        timeRestStops = timeRestPoint1 + (stops - 1) * timeRest;
    }
    else if (stops == 1)
    {
        //���� ����� ������  - ���������� t
        timeRestStops = timeRest;
    }
    else
    {
        //��� ����� ������ - nothing
    }
    double timeDistance = distance / speed; //����� ����������� �� ���������, �

    racingTime = timeDistance + timeRestStops; //����� �� ��������� + ����� �� ������
}

AllTerrainBoots::AllTerrainBoots(double speed, double timeBeforeRest, double timeRestPoint1, double timeRest) : GroundTransport(sAllTerrainBoots, speed, timeBeforeRest, timeRestPoint1, timeRest, timeRest, static_cast<int>(TransportType::TTAllTerrainBoots))
{
}
AllTerrainBoots::AllTerrainBoots() : GroundTransport()
{
    this->name = sAllTerrainBoots;
}