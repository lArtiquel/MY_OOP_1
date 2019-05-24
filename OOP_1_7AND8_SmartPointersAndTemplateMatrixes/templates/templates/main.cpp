#include <iostream>
#include "Matrix.h"
#include "inputModule.h"
#include <vector>
#include <memory>

using namespace std;

int main()
{
	cout << "Welcome to easy project, please, choose command:\n\007";
	unique_ptr<Matrix<int>> fInt;						// all possible pointers to the classes of matrix
	unique_ptr<Matrix<int>> sInt;
	unique_ptr<Matrix<double>> fDouble;
	unique_ptr<Matrix<double>> sDouble;
	unique_ptr<Matrix<char>> fChar;
	unique_ptr<Matrix<char>> sChar;
	//unique_ptr<Matrix<string>> fString;
	//unique_ptr<Matrix<string>> sString;
	int firstMatrixFlag = 0, secondMatrixFlag = 0;

	while (true)
	{
		cout << "Commands:\n"
			<< "0 - to quit\n"
			<< "1 - create first matrix\n"
			<< "2 - create second matrix\n"
			<< "3 - to transpose matrix\n"
			<< "4 - to try first way of matrix additing(returns new matrix)\n"
			<< "5 - to try second way of matrix additing(overrides result into first matrix)\n"
			<< "6 - delete first matrix\n"
			<< "7 - delete second matrix\n"
			<< "8 - print first matrix\n"
			<< "9 - print second matrix\n";

		cout << "your choise: ";
		//TODO: find my defend from fool

		switch (inputNumber())
		{
			case 0: return 0;
			case 1: 
				if (!firstMatrixFlag)
					{
						int n, m;																// template vars for acking for a size
						int type = chooseTypeOfMatr();											// here asking about type of matrix(int/double/char/string)
						if (type == 0) {														// if 0 then user want to quit from this peace of code
							break;
						}
						askAboutSizeOfMatrix(n, m);												// here we are asking about size of matrix
						firstMatrixFlag = type;													// turn flag to "matrix of this type created"

						switch (type)															// by previosly chosed type and size of matrix cheate her
						{
							case 1:	fInt.reset(new Matrix<int>(n, m, type)); break;	
							case 2: fDouble.reset(new Matrix<double>(n, m, type)); break;
							case 3: fChar.reset(new Matrix<char>(n, m, type)); break;
						}
					}	else
						cout << "problemo: matrix created, delete it first!\n";
					break;
			case 2:
				if (!secondMatrixFlag)
				{
					int n, m;																// template vars for acking for a size
					int type = chooseTypeOfMatr();											// here asking about type of matrix
					if (type == 0) {
						break;
					}
					askAboutSizeOfMatrix(n, m);
					secondMatrixFlag = type;

					switch (type)
					{
						case 1: sInt.reset(new Matrix<int>(n, m, type)); break;
						case 2: sDouble.reset(new Matrix<double>(n, m, type)); break;
						case 3: sChar.reset(new Matrix<char>(n, m, type)); break;
					}
				}
				else
						cout << "problemo: matrix created, delete it first!\n";
				break;
			case 3: 
			{
				int numberOfMatrix = chooseMatrix();									// choose matrix to transpose
				if (numberOfMatrix == 1) {
					if (firstMatrixFlag != 0) {
						switch (firstMatrixFlag)
						{
							case 1: 
							{
								Matrix<int> *temp = Matrix<int>::swapTranspose(fInt.get());
								if (temp != fInt.get()) {								// to avoid self-reset: p.reset(p.get());
									fInt.reset(temp);
								}
								cout << *fInt.get();
								break;
							}
							case 2:
							{
								Matrix<double> *temp = Matrix<double>::swapTranspose(fDouble.get());
								if (temp != fDouble.get()) {
									fDouble.reset(temp);
								}
								cout << *fDouble.get();
								break;
							}
							case 3: 
							{
								Matrix<char> *temp = Matrix<char>::swapTranspose(fChar.get());
								if (temp != fChar.get()) {
									fChar.reset(temp);
								}
								cout << *fChar.get();
								break;
							}
						}
						cout << "matrix transposed!\n";
					}
					else
						cout << "problemo: first matrix not created or deleted\n ";
				}
				else
					if (numberOfMatrix == 2) {
						if (secondMatrixFlag != 0) {
							switch (secondMatrixFlag)
							{
								case 1:
								{
									Matrix<int> *temp = Matrix<int>::swapTranspose(sInt.get());
									if (temp != sInt.get()) {
										fInt.reset(temp);
									}
									cout << *sInt.get();
									break;
								}
								case 2:
								{
									Matrix<double> *temp = Matrix<double>::swapTranspose(sDouble.get());
									if (temp != sDouble.get()) {
										sDouble.reset(temp);
									}
									cout << *sDouble.get();
									break;
								}
								case 3:
								{
									Matrix<char> *temp = Matrix<char>::swapTranspose(sChar.get());
									if (temp != sChar.get()) {
										sChar.reset(temp);
									}
									cout << *sChar.get();
									break;
								}
							}
							cout << "matrix transposed!\n";
						}
						else
							cout << "problemo: first matrix not created or deleted\n ";
					}
				break;
			}
			case 4: 
				if (firstMatrixFlag == 0 || secondMatrixFlag == 0)
					cout << "problemo: matrixes aren't created!";
				else
				{
					if (firstMatrixFlag == secondMatrixFlag)
					{
						switch (firstMatrixFlag)
						{
							case 1:
							{
								unique_ptr<Matrix<int>> temp(*fInt.get() + *sInt.get());
								if (temp.get() != nullptr)  Matrix<int>::printMatrix(temp.get()); break;
							}
							case 2:
							{
								unique_ptr<Matrix<double>> temp(*fDouble.get() + *sDouble.get());
								if (temp.get() != nullptr)  Matrix<double>::printMatrix(temp.get()); break;
							}
							case 3:
							{
								unique_ptr<Matrix<char>> temp(*fChar.get() + *sChar.get());
								if (temp.get() != nullptr)  Matrix<char>::printMatrix(temp.get()); break;
							}
						}
					}
					else
						cout << "addition of the different matrices are not supporting yet!\n";
				}
				break;
			case 5:
				if (firstMatrixFlag == 0 || secondMatrixFlag == 0)
					cout << "problemo: matrixes aren't created!";
				else
				{
					if (firstMatrixFlag == secondMatrixFlag)
					{
						switch (firstMatrixFlag)
						{
							case 1:
							{
								bool doPrint = Matrix<int>::secondWayAdditing(fInt.get(), sInt.get());
								if (doPrint) cout << *fInt; break;			// if matrixes successfully added - print changed matrix
							}
							case 2:
							{
								bool doPrint = Matrix<double>::secondWayAdditing(fDouble.get(), sDouble.get());
								if (doPrint) cout << *fDouble; break;			// if matrixes successfully added - print changed matrix
							}
							case 3:
							{
								bool doPrint = Matrix<char>::secondWayAdditing(fChar.get(), sChar.get());
								if (doPrint) cout << *fChar; break;			// if matrixes successfully added - print changed matrix
							}
						}
					} else
						cout << "addition of the different matrices are not supporting yet!\n";
				}
				break;
			case 6: 
				if (firstMatrixFlag != 0)
				{
					switch (firstMatrixFlag)
					{
						case 1: fInt.reset(nullptr); break;
						case 2: fDouble.reset(nullptr); break;
						case 3: fChar.reset(nullptr); break;
					}
					cout << "matrix deleted!\n";
					firstMatrixFlag = 0;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 7:
				if (secondMatrixFlag != 0)
				{
					switch (secondMatrixFlag)
					{
						case 1: sInt.reset(nullptr); break;
						case 2: sDouble.reset(nullptr); break;
						case 3: sChar.reset(nullptr); break;
					}
					cout << "matrix deleted!\n";
					secondMatrixFlag = 0;
				}
				else
					cout << "matrix cannot be deleted, cause it's not created!\n";
				break;
			case 8:
				if (firstMatrixFlag == 0) cout << "there is no matrix!\n";
					else
					{
						switch (firstMatrixFlag)
						{
							case 1:  cout << *fInt.get(); break;
							case 2:  cout << *fDouble.get(); break;
							case 3:  cout << *fChar.get(); break;
						}
					}
				break;
			case 9: 
				if (secondMatrixFlag == 0) cout << "there is no matrix!\n";
				else
				{
					switch (secondMatrixFlag)
					{
						case 1:  Matrix<int>::printMatrix(sInt.get()); break;
						case 2:  Matrix<double>::printMatrix(sDouble.get()); break;
						case 3:  Matrix<char>::printMatrix(sChar.get()); break;
					}
				}
				break;
		}
		cout << "\n";
	}
	return 0;
}