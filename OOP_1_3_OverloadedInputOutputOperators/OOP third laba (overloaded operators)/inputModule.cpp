#include "inputModule.h"
#include <string>
#include <iostream>

using namespace std;

//TODO:: string parser
int inputNumber()
{
	while (1)
	{
		string s;
		bool irInput = false, isMinusHere = false, zeroIsNotFirst = false;
		
		getline(cin, s);
		int size = s.size();					//remember this value for cycle par
		if (s.empty()) continue;				//empty string has 1 byte (null-term)
		for (int i = 0; i < size; i++)     //check if user pressed not number
		{
			if (s[i] == '-')		//minus
			{
				if ((!isMinusHere) && (i == 0))
					isMinusHere = true;
				else
				{
					cout << "please, press one minus and he should be before the number!\nOk, again: ";
					irInput = true;
					break;
				}
			}
			else
				if (s[i] < '1' || s[i] > '9')		//numbers
				{
					if (s[i] == '0')
					{
						if (i == 0 && i == size - 1) continue;
						if (!zeroIsNotFirst)
						{
							irInput = true;
							cout << "first zero!\nOk, again: ";
							break;
						}
					}
					else
					{
						irInput = true;
						cout << "please, enter the numbers only!\nOk, again: ";
						break;
					}
				}
				else
				{
					if(!zeroIsNotFirst) zeroIsNotFirst = true;
				}
		}

		if (irInput) continue; else //if input is regular-convert string to double or int and return it
		{
			cout << '\n';
			return stoi(s);
		}
	}
}

int inputNumberForMatr()
{
	int temp;
	while (true)
	{
		if (cin >> temp)
			return temp;
		else
		{
			cout << "mistake found! characters after that mistake in current string won't be counting!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
	}
}
