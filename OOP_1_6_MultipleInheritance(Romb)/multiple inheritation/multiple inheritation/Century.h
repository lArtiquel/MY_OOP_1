#pragma once
#include "History.h"
#include <string>
#include <iostream>
using namespace std;

class Century : virtual public History {
	string centuryName;
	string greatestWars;
	string greatestAlliance;

public:
	Century(string place, string people, string centuryName, string greatestWars, string greatestAlliance) 
		: History(place, people), centuryName(centuryName), greatestWars(greatestWars), greatestAlliance(greatestAlliance) {};
	virtual void print();
	virtual ~Century() {}
};