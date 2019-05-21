#include <iostream>
#include "Matrix.h"
#include "inputModule.h"

using namespace std;


int main()
{
	cout << "Welcome to easy project, please, choose command:\n\007";
	Matrix *firstMatrix = nullptr, *secondMatrix = nullptr;								//pointers to the classes of matrix
	while (true)
	{
		cout << "Commands:\n"
			<< "0 - to quit\n"
			<< "1 - create first matrix\n"
			<< "2 - create second matrix\n"
			<< "3 - to try first way of transpose\n"
			<< "4 - to try second way of transpose(XOR)\n"
			<< "5 - to try first way of matrix additing with first matrix transpose(returns new matrix)\n"
			<< "6 - to try second way of matrix additing with first matrix transpose(returns first matrix as result)\n"
			<< "7 - delete first matrix\n"
			<< "8 - delete second matrix\n"
			<< "9 - print first matrix\n"
			<< "10 - print second matrix\n";

		cout << "your choise: ";
		//TODO: find my defend from fool

		switch (inputNumber())
		{
			case 0: delete firstMatrix; delete secondMatrix; return 0;
			case 1: 
				if (firstMatrix == nullptr)
					{
						int n, m;																//template vars for acking for a size
						Matrix::askAboutSizeOfMatrix(n, m);
						firstMatrix = new Matrix(n,m);  
					}	else
						cout << "problemo: matrix created, delete it first!\n";
					break;
			case 2:
				if (secondMatrix == nullptr)
					{
						int n, m;																//template vars for acking for a size
						Matrix::askAboutSizeOfMatrix(n, m);
						secondMatrix = new Matrix(n, m);										//create new matrix in the heap
					}	else
						cout << "problemo: matrix created, delete it first!\n";
					break;
			case 3: 
			{
				int numberOfMatrix = Matrix::chooseMatrix();
				if (numberOfMatrix == 1) {
					if (firstMatrix != nullptr) {
						firstMatrix = Matrix::swapTranspose(firstMatrix);
						cout << "now matrix is look:\n";
						Matrix::printMatrix(firstMatrix);
					}
					else
						cout << "problemo: first matrix not created or deleted\n ";
				}
				else
					if (numberOfMatrix == 2) {
						if (secondMatrix != nullptr) {
							secondMatrix = Matrix::swapTranspose(secondMatrix);
							cout << "now matrix is looks like:\n";
							Matrix::printMatrix(secondMatrix);
						}
						else
							cout << "problemo: second matrix not created or deleted\n ";
					}
				break;
			}
			case 4: 
			{
				int numberOfMatrix = Matrix::chooseMatrix();
				if (numberOfMatrix == 1) {
					if (firstMatrix != nullptr) {
						firstMatrix = Matrix::xorTranspose(firstMatrix);
						cout << "now matrix is look:\n";
						Matrix::printMatrix(firstMatrix);
					}
					else
						cout << "problemo: first matrix not created or deleted\n ";
				}
				else
					if (numberOfMatrix == 2) {
						if (secondMatrix != nullptr) {
							secondMatrix = Matrix::xorTranspose(secondMatrix);
							cout << "now matrix is look:\n";
							Matrix::printMatrix(secondMatrix);
						}
						else
							cout << "problemo^ second matrix not created or deleted\n ";
					}
				break;
			}
			case 5: 
				if (firstMatrix == nullptr || secondMatrix == nullptr)
				cout << "problemo: matrixes aren't created!"; 
				else
				{
					firstMatrix = Matrix::swapTranspose(firstMatrix);							//task it needs!!!
					Matrix *temp = Matrix::firstWayAdditing(firstMatrix, secondMatrix);
					if(temp != nullptr)											//we don't need to print empty matrix
						Matrix::printMatrix(temp);
					delete temp;												//we need to delete dynamicaly crested temp class of matrix
				}
				break;
			case 6: 
				if (firstMatrix == nullptr || secondMatrix == nullptr)
					cout << "problemo: matrixes aren't created!";
				else
				{
					Matrix::swapTranspose(firstMatrix);
					bool flag = Matrix::secondWayAdditing(firstMatrix, secondMatrix);
					if(flag) Matrix::printMatrix(firstMatrix);
				}
				break;
			case 7: 
				if (firstMatrix != nullptr)
				{
					delete firstMatrix;
					cout << "matrix deleted!\n";
					firstMatrix = nullptr;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 8:
				if (secondMatrix != nullptr)
				{
					delete secondMatrix;
					cout << "matrix deleted!\n";
					secondMatrix = nullptr;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 9: Matrix::printMatrix(firstMatrix); break;
			case 10: Matrix::printMatrix(secondMatrix); break;
		}
		cout << "\n";
	}
	return 0;
}