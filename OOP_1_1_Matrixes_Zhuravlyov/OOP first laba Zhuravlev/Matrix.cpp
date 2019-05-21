#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include "inputModule.h"

using namespace std;

Matrix::Matrix(int n, int m, bool flag)
{
	n_ = n;
	m_ = m;
	createMatrix(this);
	if (flag) {
		fillMatrix(this);
	}
}

int ** createMatrix(Matrix * matr)
{
	matr->pMatrix = new int*[matr->n_];
	for (int i = 0; i < matr->n_; i++)
	{
		matr->pMatrix[i] = new int[matr->m_];
	}
	//TODO:: realize safety input matrix
	cout << "matrix successfully created!\n";
	return matr->pMatrix;
}

int ** fillMatrix(Matrix * matr)
{
	cout << "please, enter the matrix this size:\n";
	for (int i = 0; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
			matr->pMatrix[i][j] = inputNumberForMatr();
	return matr->pMatrix;
}

int chooseMatrix()
{
	int choise;
	while (true)
	{
		cout << "please, choose the matrix(0 - quit)\n";
		choise = inputNumber();
		if (choise == 0) break; else
			if (choise != 1 && choise != 2)
				cout << "wrong number of matrix\n"; else
				return choise;
	}
}

void askAboutSizeOfVector(int &m)
{
	while (true) {
		cout << "please, enter number of elements in your matrix\n";
		m = inputNumber();
		if (m <= 0) continue;
		break;
	}
}

Matrix * swapTranspose(Matrix *& matr)
{
	//it will save some cpu time if you will transpose square matrixes
	if (matr->n_ != matr->m_)	//then create matrix m_ n_(only for non square matrixes!)
	{
		return firstTransposeForNonSquareMatrix(matr);
	}
	else
	{
		for (int i = 0; i < matr->n_; i++)
			for (int j = 0; j < i; j++)
				if(i != j)
					swap(matr->pMatrix[i][j], matr->pMatrix[j][i]);
		return matr;
	}	
}

Matrix * xorTranspose(Matrix *& matr)
{
	if (matr->n_ != matr->m_)	//then create matrix m_ n_(only for non square matrixes!)
	{
		return secondTransposeForNonSquareMatrix(matr);
	}
	else
	{
		for (int i = 1; i < matr->n_; i++)
			for (int j = 0; j < matr->m_; j++)
				if (matr->pMatrix[i][j] != matr->pMatrix[j][i]) {
					matr->pMatrix[i][j] ^= matr->pMatrix[j][i];
					matr->pMatrix[j][i] ^= matr->pMatrix[i][j];
					matr->pMatrix[i][j] ^= matr->pMatrix[j][i];
				}
		return matr;
	}
}

Matrix * firstTransposeForNonSquareMatrix(Matrix *& matr)
{
	Matrix * newMatr = new Matrix(matr->m_, matr->n_, 0);	//creating without entering
	for (int i = 0; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
		{
			if (i < matr->m_ && j < matr->n_)
			{
				if (i == j)
				{
					newMatr->pMatrix[i][j] = matr->pMatrix[i][j];
				}
				else
				{
					newMatr->pMatrix[j][i] = matr->pMatrix[i][j];
				}
			}
			else
				if (i >= matr->m_)
				{
					newMatr->pMatrix[j][i] = matr->pMatrix[i][j];
				}
				else
					if (j >= matr->n_)
					{
						newMatr->pMatrix[j][i] = matr->pMatrix[i][j];
					}
		}
	delete matr;		//here call d-ctor of the first matrix(we don't need her anymore)
	return newMatr;
}

Matrix * secondTransposeForNonSquareMatrix(Matrix *& matr)
{
	Matrix * newMatr = new Matrix(matr->m_, matr->n_, 0);	//creating without entering
	for (int i = 0; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
		{
			newMatr->pMatrix[j][i] = matr->pMatrix[i][j];
		}
	delete matr;		
	return newMatr;
}

Matrix * firstWayCreating(const Matrix * first, const Matrix * second)
{
	//The first element will be from the first vector
	Matrix *temp = new Matrix(first->m_, second->m_+1, 0);	//create new empty matrix
	for (int i = 0; i < temp->n_; i++)
		for (int j = 0; j < temp->m_; j++)
		{
			if (j == 0) {
				temp->pMatrix[i][j] = first->pMatrix[j][i];
			} else
				if (i == 0)
				{
					temp->pMatrix[i][j] = second->pMatrix[i][j - 1];
				}
				else
				{
					temp->pMatrix[i][j] = first->pMatrix[0][i] * second->pMatrix[0][j-1];
				}
		}
	return temp;
}

void secondWayCreating(const Matrix * first, const Matrix * second, Matrix *& result)
{
	result = new Matrix(first->m_, second->m_ + 1, 0);	//create new empty matrix
	for (int i = 0; i < result->n_; i++)
		for (int j = 0; j < result->m_; j++)
		{
			if (j == 0) {
				result->pMatrix[i][j] = first->pMatrix[j][i];
			}
			else
				if (i == 0)
				{
					result->pMatrix[i][j] = second->pMatrix[i][j - 1];
				}
				else
				{
					result->pMatrix[i][j] = first->pMatrix[0][i] * second->pMatrix[0][j - 1];
				}
		}
}

void printMatrix(const Matrix * temp)
{
	if (temp != nullptr)
	{
		for (int i = 0; i < temp->n_; i++) {
			for (int j = 0; j < temp->m_; j++) {
				cout  << temp->pMatrix[i][j] << setw(3);
			}
			cout << '\n';
		}	
	}
	else
		cout << "matrix is empty\n";
}

void deleteMatrix(Matrix * temp)
{
	for (int i = 0; i < temp->n_; i++)
		delete[] temp->pMatrix[i];
	delete[] temp->pMatrix;
}

Matrix::~Matrix()
{
	deleteMatrix(this);
}
