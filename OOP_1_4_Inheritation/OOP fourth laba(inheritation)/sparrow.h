#pragma once
#include "animals.h"

class Sparrow : protected Animals
{
public:
	Sparrow(double age, double weigth, int kids, int friends) : Animals(age, weigth), kids(kids), friends(friends) {};

	int getKids() const;
	void setKids(int);

	int getFriends() const;
	void setFriends(int);

	void print() const;
private:
	int kids;
	int friends;
};