#include "animals.h"

using namespace std;

double Animals::getAge() const
{
	return age;
}

void Animals::setAge(double age)
{
	this->age = age;
}

double Animals::getWeigth() const
{
	return weigth;
}

void Animals::setWeigth(double weigth)
{
	this->weigth = weigth;
}