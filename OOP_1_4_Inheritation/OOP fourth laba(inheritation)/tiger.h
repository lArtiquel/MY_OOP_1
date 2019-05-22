#pragma once
#include "animals.h"

class Tiger : protected Animals
{
public:
	Tiger(double age, double weigth, double speed, double maxPowerOfFangs) : Animals(age, weigth), speed(speed), maxPowerOfFangs(maxPowerOfFangs) {};

	double getSpeed() const;
	void setSpeed(double);

	double getMaxPowerOfFangs() const;
	void setMaxPowerOfFangs(double);

	void print() const;
private:
	double speed;
	double maxPowerOfFangs;			//fangs-kliki
};