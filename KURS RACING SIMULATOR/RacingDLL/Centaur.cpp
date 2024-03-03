#include "pch.h"
#include "Centaur.h"
#include <iostream>
#include "consts.h"

void Centaur::calcRacingTime(int distance)
{
    //���������� ������� ��� ����������� �C
    double distanceBetweenStops = speed * timeBeforeRest;  //��������� ����� ��������� ������� ������, ��
    int stops = static_cast<int>(distance / distanceBetweenStops);        //���������� ����� ������ - ������� �� �������
    double delta = distance - (stops * distanceBetweenStops);//
    if (delta == 0)//��������� ���� - �� ������
    {
        if (stops > 0)
        {
            stops--; //��������� ���� �� �����
        }
    }

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

Centaur::Centaur(double speed, double timeBeforeRest, double timeRest) : GroundTransport(sCentaur, speed, timeBeforeRest, timeRest, timeRest, timeRest, static_cast<int>(TransportType::TTCentaur))
{
}
Centaur::Centaur() : GroundTransport()
{
    this->name = sCentaur;
}