#include "tiger.h"
#include <iostream>

using namespace std;

void Tiger::print() const
{
	cout << "age: " << getAge() << " weigth: " << getWeigth() << " speed: " << getSpeed() << " max power of fangs: " << getMaxPowerOfFangs() << '\n';
}

double Tiger::getSpeed() const
{
	return speed;
}

void Tiger::setSpeed(double speed)
{
	this->speed = speed;
}

double Tiger::getMaxPowerOfFangs() const
{
	return this->maxPowerOfFangs;
}

void Tiger::setMaxPowerOfFangs(double maxPowerOfFangs)
{
	this->maxPowerOfFangs = maxPowerOfFangs;
}