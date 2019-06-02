#pragma once
#include "History.h"
#include <string>
#include <iostream>
using namespace std;

class Period : virtual public History {
	string periodName;
	string mostFamousGenious;
	string mostFamousCommanders;

public:
	Period(string place, string people, string periodName, string mostFamousGenious, string mostFamousCommanders) 
		: History(place, people), periodName(periodName), mostFamousGenious(mostFamousGenious), mostFamousCommanders(mostFamousCommanders) {};
	virtual void print();
	virtual ~Period() {}
};