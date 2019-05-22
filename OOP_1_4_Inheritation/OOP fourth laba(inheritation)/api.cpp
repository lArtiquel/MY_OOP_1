#include "animals.h"
#include "inputModule.h"
#include "tiger.h"
#include "shark.h"
#include "sparrow.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<Shark> shark;
	vector<Sparrow> sparrow;
	vector<Tiger> tiger;
	while (1)
	{
		cout << "choose command:\n"
			<< "1 - to create shark object\n"
			<< "2 - to print shark objects\n"
			<< "3 - to delete shark objects\n"
			<< "4 - to create sparrow object\n"
			<< "5 - to print sparrow objects\n"
			<< "6 - to delete sparrow objects\n"
			<< "7 - to create tiger object\n"
			<< "8 - to print tiger odbjects\n"
			<< "9 - to delete tiger objects\n"
			<< "10 - to print all animals\n";

		switch (askForInt("ok, your choise(0 - to quit): "))
		{
			case 1: shark.push_back(Shark(askForDouble("please, enter the age of shark: "),
										  askForDouble("please, enter the weigth of shark: "),
										  askForString("please, enter the color of shark: "),
										  askForString("please, enter the voice of shark: ")));
				break;
			case 2: for_each(shark.begin(), shark.end(), [](const Shark &s) { s.print(); });
				break;
			case 3: shark.clear();
				break;
			case 4: sparrow.push_back(Sparrow(askForDouble("please, enter the age of sparrow: "),
										  askForDouble("please, enter the weigth of sparrow: "),
										  askForInt("please, enter the number of kids of sparrow: "),
										  askForInt("please, enter the number of friends of sparrow: ")));
				break;
			case 5: for_each(sparrow.begin(), sparrow.end(), [](const Sparrow &s) { s.print(); });
				break;
			case 6: sparrow.clear();
				break;
			case 7: tiger.push_back(Tiger(askForDouble("please, enter the age of tiger: "),
										  askForDouble("please, enter the weigth of tiger: "),
										  askForDouble("please, enter the speed of tiger: "),
										  askForDouble("please, enter the max power of fangs of tiger: ")));
				break;
			case 8: for_each(tiger.begin(), tiger.end(), [](const Tiger &t) { t.print(); });
				break;
			case 9: tiger.clear();
				break;
			case 10: 
				cout << "sharks:\n";
				for_each(shark.begin(), shark.end(), [](const Shark &s) { s.print(); });
				cout << "sparrows:\n";
				for_each(sparrow.begin(), sparrow.end(), [](const Sparrow &s) { s.print(); });
				cout << "tigers:\n";
				for_each(tiger.begin(), tiger.end(), [](const Tiger &t) { t.print(); });
				break;
			case 0: return 0;
			default: return 0;
		}
	}
}