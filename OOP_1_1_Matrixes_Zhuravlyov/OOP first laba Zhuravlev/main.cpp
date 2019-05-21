#include <iostream>
#include "Matrix.h"
#include "inputModule.h"

using namespace std;


int main()
{
	cout << "Welcome to easy project, please, choose command:\n\007";
	Matrix *firstVector = nullptr, *secondVector = nullptr;								//pointers to the classes of matrix
	while (true)
	{
		cout << "Commands:\n"
			<< "0 - to quit\n"
			<< "1 - create first vector\n"
			<< "2 - create second vector\n"
			<< "3 - to try the first vector transposition method(swap method)\n"
			<< "4 - to try the second vector transposition method(XOR method)\n"
			<< "5 - try to create matrix of two vectors(returns new matrix, args not changing)\n"
			<< "6 - try to create matrix of two vectors(new matrix passing with args)\n"
			<< "7 - delete first vector\n"
			<< "8 - delete second vector\n"
			<< "9 - print first vector\n"
			<< "10 - print second vector\n";

		cout << "your choise: ";
		//TODO: find my defend from fool

		switch (inputNumber())
		{
			case 0: delete firstVector; delete secondVector; return 0;
			case 1: 
				if (firstVector == nullptr)
					{
						int m;																//template vars for acking for a size
						askAboutSizeOfVector(m);
						firstVector = new Matrix(1,m);  
					}	else
						cout << "problemo: vector created, delete it first!\n";
					break;
			case 2:
				if (secondVector == nullptr)
					{
						int m;																//template vars for acking for a size
						askAboutSizeOfVector(m);
						secondVector = new Matrix(1, m);									//creating new v-tor								
					}	else
						cout << "problemo: vector created, delete it first!\n";
					break;
			case 3: 
			{
				int numberOfMatrix = chooseMatrix();
				if (numberOfMatrix == 1) {
					if (firstVector != nullptr) {
						firstVector = swapTranspose(firstVector);
						cout << "now vector is look:\n";
						printMatrix(firstVector);
					}
					else
						cout << "problemo: first vector not created or deleted\n ";
				}
				else
					if (numberOfMatrix == 2) {
						if (secondVector != nullptr) {
							secondVector = swapTranspose(secondVector);
							cout << "now vector is looks like:\n";
							printMatrix(secondVector);
						}
						else
							cout << "problemo: second vector not created or deleted\n ";
					}
				break;
			}
			case 4: 
			{
				int numberOfMatrix = chooseMatrix();
				if (numberOfMatrix == 1) {
					if (firstVector != nullptr) {
						firstVector = xorTranspose(firstVector);
						cout << "now vector is look:\n";
						printMatrix(firstVector);
					}
					else
						cout << "problemo: first matrix not created or deleted\n ";
				}
				else
					if (numberOfMatrix == 2) {
						if (secondVector != nullptr) {
							secondVector = xorTranspose(secondVector);
							cout << "now vector is look:\n";
							printMatrix(secondVector);
						}
						else
							cout << "problemo^ second vector not created or deleted\n ";
					}
				break;
			}
			case 5: 
				if (firstVector == nullptr || secondVector == nullptr)
				cout << "problemo: vectors aren't created!"; 
				else
				{
					Matrix *temp = firstWayCreating(firstVector, secondVector);
					printMatrix(temp);
					delete temp;												//we need to delete dynamicaly crested temp class of matrix
				}
				break;
			case 6: 
				if (firstVector == nullptr || secondVector == nullptr)
					cout << "problemo: vectors aren't created!";
				else
				{
					Matrix *result = nullptr;
					secondWayCreating(firstVector, secondVector, result);
					printMatrix(result);
					delete result;
				}
				break;
			case 7: 
				if (firstVector != nullptr)
				{
					delete firstVector;
					cout << "matrix deleted!\n";
					firstVector = nullptr;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 8:
				if (secondVector != nullptr)
				{
					delete secondVector;
					cout << "matrix deleted!\n";
					secondVector = nullptr;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 9: printMatrix(firstVector); break;
			case 10: printMatrix(secondVector); break;
		}
		cout << "\n";
	}
	return 0;
}