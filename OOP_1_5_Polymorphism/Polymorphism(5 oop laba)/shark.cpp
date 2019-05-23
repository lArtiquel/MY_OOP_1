#include "shark.h"
#include <iostream>

using namespace std;

void Shark::print() const
{
	cout << "age: " << getAge() << " weigth: " << getWeigth() << " color: " << getColor() << " voice: " << getVoice() << '\n';
}

std::string Shark::getColor() const
{
	return color;
}

void Shark::setColor(std::string color)
{
	this->color = color;
}

std::string Shark::getVoice() const
{
	return voice;
}

void Shark::setVoice(std::string voice)
{
	this->voice = voice;
}