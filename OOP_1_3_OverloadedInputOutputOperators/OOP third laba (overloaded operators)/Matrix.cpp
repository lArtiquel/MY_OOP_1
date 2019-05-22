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

int ** Matrix::createMatrix(Matrix * matr)
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

int ** Matrix::fillMatrix(Matrix * matr)
{
	cout << "please, enter the matrix this size:\n";
	for (int i = 0; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
			matr->pMatrix[i][j] = inputNumberForMatr();
	return matr->pMatrix;
}

int Matrix::chooseMatrix()
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

void Matrix::askAboutSizeOfMatrix(int &n,int &m)
{
	while (true) {
		cout << "please, enter number of rows\n";
		n = inputNumber();
		if (n <= 0) continue;
		cout << "please, enter number of columns\n";
		m = inputNumber();
		if (m <= 0) continue;
		break;
	}
}

Matrix * Matrix::swapTranspose(Matrix * matr)
{
	if (matr->n_ != matr->m_)	//then create matrix m_ n_(only for non square matrixes!)
	{
		return swapTransposeForNonSquareMatrix(matr);
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

Matrix * Matrix::xorTranspose(Matrix * matr)
{
	if (matr->n_ != matr->m_)	//then create matrix m_ n_(only for non square matrixes!)
	{
		return swapTransposeForNonSquareMatrix(matr);
	}
	for (int i = 1; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
			if (matr->pMatrix[i][j] != matr->pMatrix[j][i]) {
				matr->pMatrix[i][j] ^= matr->pMatrix[j][i];
				matr->pMatrix[j][i] ^= matr->pMatrix[i][j];
				matr->pMatrix[i][j] ^= matr->pMatrix[j][i];
			}
	swap(matr->n_, matr->m_);								//swap'aem size
	return matr;
}

Matrix * Matrix::swapTransposeForNonSquareMatrix(Matrix * matr)
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

Matrix * Matrix::firstWayAdditing(const Matrix * first, const Matrix * second)
{
	if ((first->n_ == second->n_) && (first->m_ == second->m_))
	{
		Matrix *temp = new Matrix(first->n_, first->m_, 0);
		for (int i = 0; i < first->n_; i++)
			for (int j = 0; j < first->m_; j++)
				temp->pMatrix[i][j] = first->pMatrix[i][j] + second->pMatrix[i][j];
		return temp;
	}
	else
	{
		cout << "sizes of matrixes not equal!!!\n";
		return nullptr;
	}
}

bool Matrix::secondWayAdditing(Matrix * first, const Matrix * second)
{
	if ((first->n_ == second->n_) && (first->m_ == second->m_))
	{
		for (int i = 0; i < first->n_; i++)
			for (int j = 0; j < first->m_; j++)
				first->pMatrix[i][j] += second->pMatrix[i][j];
		return true;		//do we need to print
	} else
		cout << "sizes of matrixes not equal!!!\n";
	return false;
}

Matrix* Matrix::operator+(const Matrix &second)
{
	if ((this->n_ == second.n_) && (this->m_ == second.m_))
	{
		Matrix *temp = new Matrix(this->n_, this->m_, 0);
		for (int i = 0; i < this->n_; i++)
			for (int j = 0; j < this->m_; j++)
				temp->pMatrix[i][j] = this->pMatrix[i][j] + second.pMatrix[i][j];
		return temp;
	}
	else
	{
		cout << "sizes of matrixes not equal!!!\n";
		return nullptr;
	}
}

bool operator+(const Matrix & first, const Matrix & second)	//out of the class
{
	if ((first.n_ == second.n_) && (first.m_ == second.m_))
	{
		for (int i = 0; i < first.n_; i++)
			for (int j = 0; j < first.m_; j++)
				first.pMatrix[i][j] += second.pMatrix[i][j];
		return true;		//do we need to print
	}
	else
		cout << "sizes of matrixes not equal!!!\n";
	return false;
}

ostream& operator<<(ostream& os, const Matrix& temp)
{
	try
	{
		for (int i = 0; i < temp.n_; i++) {
			for (int j = 0; j < temp.m_; j++) {
				os << temp.pMatrix[i][j] << setw(3);
			}
			os << '\n';
		}
	}
	catch (...)
	{
		cout << "matrix is empty\n";
	}
	return os;
}

void Matrix::printMatrix(const Matrix * temp)
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

void Matrix::deleteMatrix(Matrix * temp)
{
	for (int i = 0; i < temp->n_; i++)
		delete[] temp->pMatrix[i];
	delete[] temp->pMatrix;
}

Matrix::~Matrix()
{
	deleteMatrix(this);
}
