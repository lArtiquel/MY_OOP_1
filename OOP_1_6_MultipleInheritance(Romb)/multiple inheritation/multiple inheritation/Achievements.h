#pragma once
#include "Period.h"
#include "Century.h"
#include <string>
#include <iostream>
using namespace std;

class Achievement : public Period, public Century {
	string field;
	string importance;

public:
	Achievement(string place, string people,
				string periodName, string mostFamousGenious, string mostFamousCommanders,
				string centuryName, string greatestWars, string greatestAlliance,
				string field, string importance)
				: History(place, people),
				  Period (place, people, periodName, mostFamousGenious, mostFamousCommanders),
				  Century (place, people, centuryName, greatestWars, greatestAlliance),
				  field(field), importance(importance) {};
	void print();
	~Achievement() {}
};