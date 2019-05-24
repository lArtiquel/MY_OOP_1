#include "inputModule.h"
#include <iostream>


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
					cout << "please, press one minus and he should be before the number!\nok, again: ";
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
							cout << "first zero!\nok, again: ";
							break;
						}
					}
					else
					{
						irInput = true;
						cout << "please, enter the numbers only!\nok, again: ";
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

double inputDecimalForMatr()
{
	while (1)
	{
		string s;
		bool irInput = false, isMinusAlreadyHere = false, isPointAlreadyHere = false, onlyPointAndOrMinus = true, firstZero = false, closedPoint = true;

		getline(cin, s);
		int size = s.size();					// remember this value for cycle par
		if (s.empty()) continue;				// empty string has 1 byte (null-term)
		for (int i = 0; i < size; i++)			// check if user pressed not number
		{
			char ch = s.at(i);
			if (ch == '.') 
			{
				if (isPointAlreadyHere) {		// if points more than 1
					cout << "too many points!\n";
					irInput = true;
					break;
				}

				closedPoint = false;

				isPointAlreadyHere = true;
			} else
			if(ch == '-')
			{
				if (isMinusAlreadyHere) {
					cout << "minus already here!\n";
					irInput = true;
					break;
				}

				if (i != 0) {
					cout << "minus is not at his place!\n";
					irInput = true;
					break;
				}

				isMinusAlreadyHere = true;
			} else
			if (ch == '0') {
				closedPoint = true;

				onlyPointAndOrMinus = false;

				if (firstZero && !isPointAlreadyHere) {
					irInput = true;
					break;
				}
				if (i == 0) firstZero = true;	

			} else
			if(ch >= '1' && ch <= '9')
			{
				closedPoint = true;

				onlyPointAndOrMinus = false;	

				if (firstZero && !isPointAlreadyHere) {
					irInput = true;
					break;
				}
			}
			else
			{
				irInput = true;
				break;
			}
		}

		if (!closedPoint || onlyPointAndOrMinus || irInput) {
			cout << "try again: ";
			continue;
		} else {
			cout << '\n';
			return stod(s);
		}
	}
}

string inputStringForMatr()
{
	string s;
	getline(cin, s);
	return s;
}

char inputCharForMatr()
{
	char c;
	cin >> c;
	return c;
}
