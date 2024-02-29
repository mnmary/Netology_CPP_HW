#include "pch.h"
#include "Racing.h"

#include "Transport.h"
#include "Camel.h"
#include "FastCamel.h"
#include "MagicCarpet.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "Broomstick.h"
#include "Eagle.h"

int Racing::getDistance()
{
	return distance;
}
void Racing::setDistance(int distance)
{
	this->distance = distance;
}
RacingType Racing::getRacingType()
{
	return racingType;
}
void Racing::setRacingType(RacingType racingType)
{
	this->racingType = racingType;
}
void Racing::registerTransport(Transport* transport)
{
	transports[cntRegTransport] = transport;
	cntRegTransport++;
}
Transport* Racing::getTransport(int index)
{
	return transports[index];
}
void Racing::initRacing()
{
	cntRegTransport = 0;
}

void Racing::calcRacingTime()
{
	for (int i = 0; i < cntRegTransport; i++)
	{
		transports[i]->calcRacingTime(distance);
	}
}

void Racing::sortRegTransport()
{
	Transport* tempTransport;

	int listLength = cntRegTransport;

	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (transports[i]->getRacingTime() > transports[i + 1]->getRacingTime())
			{
				tempTransport = transports[i];
				transports[i] = transports[i + 1];
				transports[i + 1] = tempTransport;

				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}

}

int Racing::getCntRegTransport()
{
	return cntRegTransport;
}


void Racing::processRacing()
{
	//посчитаем время в пути всех ТС
	for (int i = 0; i < cntRegTransport;i++)
	{
		transports[i]->calcRacingTime(distance);
	}
	sortRegTransport();
}



