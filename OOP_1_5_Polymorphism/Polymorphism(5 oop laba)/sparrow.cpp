#include "sparrow.h"
#include <iostream>
using namespace std;

void Sparrow::print() const
{
	cout << "age: " << getAge() << " weigth: " << getWeigth() << " number of kids: " << getKids() << " number of friends: " << getFriends() << '\n';
}

int Sparrow::getKids() const
{
	return kids;
}

void Sparrow::setKids(int color)
{
	this->kids = kids;
}

int Sparrow::getFriends() const
{
	return friends;
}

void Sparrow::setFriends(int voice)
{
	this->friends = friends;
}