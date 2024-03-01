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

const std::string sGroundTransport = "�������� ���������";
const std::string sAirTransport = "��������� ���������";
const std::string sCentaur = "�������";
const std::string sCamel = "�������";
const std::string sFastCamel = "�������-��������";
const std::string sAllTerrainBoots = "�������-���������";
const std::string sMagicCarpet = "�����-�������";
const std::string sBroomstick = "�����";
const std::string sEagle = "����";
