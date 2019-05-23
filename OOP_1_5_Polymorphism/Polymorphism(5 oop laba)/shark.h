#pragma once
#include "animals.h"
#include <string>

class Shark : public Animals
{
public:
	Shark(double age, double weigth, std::string color, std::string voice) : Animals(age, weigth), color(color), voice(voice) {};

	std::string getColor() const;
	void setColor(std::string);

	std::string getVoice() const;
	void setVoice(std::string);

	void print() const override;
private:
	std::string color;
	std::string voice;	
};

