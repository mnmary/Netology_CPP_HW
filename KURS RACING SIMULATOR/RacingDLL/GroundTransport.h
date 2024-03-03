#pragma once
#include "Transport.h"
class GroundTransport : public Transport
{
    //�������� ���������
protected:
    double timeBeforeRest = 0;	//�������� �� ����� �������� �� ������, �
    double timeRestPoint1 = 0;	//�������� �� ����� ������ � ������ �����, �
    double timeRestPoint2 = 0;	//�������� �� ����� ������ �� ������ �����, �
    double timeRest = 0;		//�������� �� ����� ������, �

public:
    RACINGDLL_API double getTimeRest();
    RACINGDLL_API void setTimeRest(double);
    RACINGDLL_API double getTimeBeforeRest();
    RACINGDLL_API void setTimeBeforeRest(double);
    RACINGDLL_API double getTimeRestPoint1();
    RACINGDLL_API void setTimeRestPoint1(double);
    RACINGDLL_API double getTimeRestPoint2();
    RACINGDLL_API void setTimeRestPoint2(double);
    RACINGDLL_API void calcRacingTime(int) override;

    RACINGDLL_API GroundTransport(std::string, double, double, double, double, double, int);
    RACINGDLL_API GroundTransport();
};

