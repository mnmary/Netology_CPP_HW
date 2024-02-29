#include "pch.h"
#include "FastCamel.h"
#include <iostream>
#include"consts.h"

void FastCamel::calcRacingTime(int distance)
{
    //���������� ������� ��� ����������� �C
    double distanceBetweenStops = speed * timeBeforeRest;  //��������� ����� ��������� ������� ������, ��
    int stops = static_cast<int>(distance / distanceBetweenStops);        //���������� ����� ������ - ������� �� �������

    double timeRestStops = 0;  //����� ������ �� ���� ���������, �
    if (stops > 2)
    {
        //����� ������ ������ 2 - ���������� t1 t2 t
        timeRestStops = timeRestPoint1 + timeRestPoint2 + (stops - 2) * timeRest;
    }
    else if (stops > 1)
    {
        //����� ������ ��� - ���������� t1 t
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
FastCamel::FastCamel(double speed, double timeBeforeRest, double timeRestPoint1, double timeRestPoint2, double timeRest) : GroundTransport(sFastCamel, speed, timeBeforeRest, timeRestPoint1, timeRestPoint2, timeRest, static_cast<int>(TransportType::TTFastCamel))
{
}
FastCamel::FastCamel() : GroundTransport()
{
    this->name = sFastCamel;
}