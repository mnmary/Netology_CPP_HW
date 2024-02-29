#include "pch.h"
#include "Transport.h"

std::string Transport::getName()
{
	return name;
}
std::string Transport::getType()
{
	return type;
}
double Transport::getSpeed()
{
	return speed;
}
void Transport::setName(std::string name)
{
	this->name = name;
}
void Transport::setType(std::string type)
{
	this->type = type;
}
void Transport::setSpeed(double speed)
{
	this->speed = speed;
}
double  Transport::getRacingTime()
{
	return racingTime;
}
void Transport::calcRacingTime(int distance)
{
	racingTime = 0.0;
}
Transport::Transport()
{
//nothing
}
Transport::Transport(std::string name, std::string type, double speed, int iType)
{
	this->name = name;
	this->type = type;
	this->speed = speed;
	this->iType = iType;
}
int Transport::getIType()
{
	return iType;
}
