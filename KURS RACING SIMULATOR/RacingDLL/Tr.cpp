#include "pch.h"
#include "Tr.h"
std::string Tr::getName()
{
	return name;
}
std::string Tr::getType()
{
	return type;
}
double Tr::getSpeed()
{
	return speed;
}
void Tr::setName(std::string name)
{
	this->name = name;
}
void Tr::setType(std::string type)
{
	this->type = type;
}
void Tr::setSpeed(double speed)
{
	this->speed = speed;
}
double  Tr::getRacingTime()
{
	return racingTime;
}
void Tr::calcRacingTime(int distance)
{
	racingTime = 0.0;
}
Tr::Tr()
{
	//nothing
}
Tr::Tr(std::string name, std::string type, double speed, int iType)
{
	this->name = name;
	this->type = type;
	this->speed = speed;
	this->iType = iType;
}
int Tr::getIType()
{
	return iType;
}

