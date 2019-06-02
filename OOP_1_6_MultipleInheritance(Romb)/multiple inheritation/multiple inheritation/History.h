#pragma once
#include <string>
#include <iostream>
using namespace std;

class History {
	string place;
	string people;

public:
	History(string place, string people) : place(place), people(people) {};
	virtual void print();
	virtual ~History() {}
};
