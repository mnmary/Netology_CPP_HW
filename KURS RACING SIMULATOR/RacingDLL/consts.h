#pragma once
#include "defineDLL.h"

enum RACINGDLL_API RacingType
{
    Ground = 1,
    Air,
    GroundAndAir,
    None = 0
};

enum RACINGDLL_API TransportType
{
    TTCentaur = 1,
    TTCamel,
    TTFastCamel,
    TTAllTerrainBoots,
    TTMagicCarpet,
    TTBroomstick,
    TTEagle
};

const std::string sGroundTransport = "Наземный транспорт";
const std::string sAirTransport = "Воздушный транспорт";
const std::string sCentaur = "Кентавр";
const std::string sCamel = "Верблюд";
const std::string sFastCamel = "Верблюд-скороход";
const std::string sAllTerrainBoots = "Ботинки-вездеходы";
const std::string sMagicCarpet = "Ковер-самолет";
const std::string sBroomstick = "Метла";
const std::string sEagle = "Орел";
