#pragma once
#include "Transport.h"
class GroundTransport : public Transport
{
    //наземный транспорт
protected:
    double timeBeforeRest = 0;	//наземное ТС время движения до отдыха, ч
    double timeRestPoint1 = 0;	//наземное ТС время отдыха в первой точке, ч
    double timeRestPoint2 = 0;	//наземное ТС время отдыха во второй точке, ч
    double timeRest = 0;		//наземное ТС время отдыха, ч

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

