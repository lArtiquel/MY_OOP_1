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
	vector<Animals*> shark;
	vector<Animals*> sparrow;
	vector<Animals*> tiger;
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
			case 1: 
			{
				Animals *animal = new Shark(askForDouble("please, enter the age of shark: "),
											askForDouble("please, enter the weigth of shark: "),
											askForString("please, enter the color of shark: "),
											askForString("please, enter the voice of shark: "));
				shark.push_back(animal);
				break;
			}
			case 2: for_each(shark.begin(), shark.end(), [](Animals* animal) { animal->print(); });
				break;
			case 3:
			{
				for_each(shark.begin(), shark.end(), [](Animals* animal) { delete animal; });
				shark.clear();
				break;
			}

			case 4: 
			{
				Animals *animal = new Sparrow(askForDouble("please, enter the age of sparrow: "),
											  askForDouble("please, enter the weigth of sparrow: "),
											  askForInt("please, enter the number of kids of sparrow: "),
											  askForInt("please, enter the number of friends of sparrow: "));
				sparrow.push_back(animal);
				break;
			}
			case 5: for_each(sparrow.begin(), sparrow.end(), [](Animals* animal) { animal->print(); });
				break;
			case 6: 
			{
				for_each(sparrow.begin(), sparrow.end(), [](Animals* animal) { delete animal; });
				sparrow.clear();
				break;
			}
				
			case 7: 
			{
				Animals *animal = new Tiger(askForDouble("please, enter the age of tiger: "),
											askForDouble("please, enter the weigth of tiger: "),
											askForDouble("please, enter the speed of tiger: "),
											askForDouble("please, enter the max power of fangs of tiger: "));
				tiger.push_back(animal);
				break;
			}
			case 8: for_each(tiger.begin(), tiger.end(), [](Animals* animal) { animal->print(); });
				break;
			case 9: 
			{
				for_each(tiger.begin(), tiger.end(), [](Animals* animal) { delete animal; });
				tiger.clear();
				break;
			}
			case 10: 
				cout << "sharks:\n";
				for_each(shark.begin(), shark.end(), [](Animals* animal) { animal->print(); });
				cout << "sparrows:\n";
				for_each(sparrow.begin(), sparrow.end(), [](Animals* animal) { animal->print(); });
				cout << "tigers:\n";
				for_each(tiger.begin(), tiger.end(), [](Animals* animal) { animal->print(); });
				break;
			default: 
				for_each(shark.begin(), shark.end(), [](Animals* animal) { delete animal; });				//delete all objects before getting out
				for_each(sparrow.begin(), sparrow.end(), [](Animals* animal) { delete animal; });			//pointers in vect will delete d-ctor
				for_each(tiger.begin(), tiger.end(), [](Animals* animal) { delete animal; });
				return 0;
		}
	}
}