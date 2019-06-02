#include "Achievements.h"
#include "inputModule.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<Achievement> ach;
	while (1)
	{
		cout << "choose command:\n"
			<< "0 - to quit\n"
			<< "1 - add achievement\n"
			<< "2 - print achievements\n"
			<< "3 - delete all achievements\n";

		switch (askForInt("ok, your choise(0 - to quit): "))
		{
			case 1: 
			{
				string periodName = askForString("please, enter the time period of discovery: ");
				string centuryName = askForString("please, enter the century of discovery: ");
				string place = askForString("please, enter place where achievement been done: ");
				string nameOfPeople = askForString("please, enter the name of people, lived there: ");
				string namesOfGenPeople = askForString("please, enter the names of the most genious people, lived there: ");
				string namesOfGrCommanders = askForString("please, enter the names of the greatest commanders, lived there: ");
				string namesOfTheGrWars = askForString("please, enter the names of the greatest wars there: ");
				string namesOfTheGrAlliance = askForString("please, enter the greatest alliance there: ");
				string fieldOfAch = askForString("please, enter the field of achievement: ");
				string importance = askForString("please, enter the importaancce of achievement: ");
				ach.push_back(Achievement(place, nameOfPeople,
								periodName, namesOfGenPeople, namesOfGrCommanders,
								centuryName, namesOfTheGrWars, namesOfTheGrAlliance,
								fieldOfAch, importance));
				break;
			}
			case 2: 
			{
				for_each(ach.begin(), ach.end(), [](Achievement a) {
																	a.History::print(),
																	a.Period::print(),
																	a.Century::print(),
																	a.print(); });
				break;
			}
			case 3:
			{
				ach.clear();
				break;
			}

			default: 
				return 0;
		}
	}
}