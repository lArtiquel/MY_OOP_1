#pragma once
#include <iostream>
using namespace std;


template <class T>
class Matrix
{
public:
	Matrix(int n, int m, int type = 0);

	int getType() const;

	static T** createMatrix(Matrix *matr);

	static T** fillMatrix(Matrix *matr, int type);

	static Matrix* swapTranspose(Matrix * matr);

	static Matrix* swapTransposeForNonSquareMatrix(Matrix * matr);

	static Matrix* firstWayAdditing(const Matrix *first, const Matrix *second);

	static bool secondWayAdditing(Matrix * first, const Matrix * second);

	Matrix* operator+(const Matrix & second);

	friend ostream& operator<< <>(ostream&, const Matrix&);   // Mark the friend function as template function !!!syntax!!!

	static void printMatrix(const Matrix *temp);

	static void deleteMatrix(Matrix * temp);

	~Matrix();
private:
	int n_,m_;								//size of matrix
	int type_;
	T **pMatrix;							//private pointer to the matrix
};

int chooseMatrix();
void askAboutSizeOfMatrix(int &, int &);
int chooseTypeOfMatr();

//CAUSE TEMP SHOULD BE INTO COMMON FILE
#include <string>
#include <iomanip>
#include "inputModule.h"

using namespace std;

template <class T>
Matrix<T>::Matrix(int n, int m, int type)
{
	n_ = n;
	m_ = m;
	type_ = type;
	createMatrix(this);			// this fucnc creating matrix
	if (type) {
		fillMatrix(this, type); // and this matrix only filling created matrix with type values
	}
}

template <class T>
int Matrix<T>::getType() const
{
	return type;
}

template <class T>
T ** Matrix<T>::createMatrix(Matrix * matr)
{
	matr->pMatrix = new T*[matr->n_];
	for (int i = 0; i < matr->n_; i++)
	{
		matr->pMatrix[i] = new T[matr->m_];
	}

	cout << "matrix successfully created!\n";
	return matr->pMatrix;
}

template <class T>
T ** Matrix<T>::fillMatrix(Matrix<T> * matr, int type)
{
	cout << "please, enter the matrix this size:\n";
	for (int i = 0; i < matr->n_; i++)
		for (int j = 0; j < matr->m_; j++)
		{
			switch (type)
			{
				case 1: matr->pMatrix[i][j] = inputNumberForMatr(); break;
				case 2: cout << "matr[" << i + 1 << "][" << j + 1 << "]: "; matr->pMatrix[i][j] = inputDecimalForMatr(); break;
				case 3: matr->pMatrix[i][j] = inputCharForMatr(); break;
			}
		}
	return matr->pMatrix;
}

template <class T>
Matrix<T> * Matrix<T>::swapTranspose(Matrix<T> * matr)
{
	if (matr->n_ != matr->m_)	//then create matrix m_ n_(only for non square matrixes!)
	{
		return swapTransposeForNonSquareMatrix(matr);
	}
	else
	{
		for (int i = 0; i < matr->n_; i++)
			for (int j = 0; j < i; j++)
				if (i != j)
					swap(matr->pMatrix[i][j], matr->pMatrix[j][i]);
		return matr;
	}
}

template <class T>
Matrix<T> * Matrix<T>::swapTransposeForNonSquareMatrix(Matrix<T> * matr)
{
	Matrix<T> * newMatr = new Matrix<T>(matr->m_, matr->n_, 0);	//creating without entering
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
	//delete matr;		//here call d-ctor of the first matrix(we don't need her anymore)  
	//if we are using smartpointers we don't need it anymore(u can't delete object before it released by unique_ptr
	return newMatr;
}

template <class T>
Matrix<T> * Matrix<T>::firstWayAdditing(const Matrix * first, const Matrix * second)
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

template <class T>
bool Matrix<T>::secondWayAdditing(Matrix * first, const Matrix * second)
{
	if ((first->n_ == second->n_) && (first->m_ == second->m_))
	{
		for (int i = 0; i < first->n_; i++)
			for (int j = 0; j < first->m_; j++)
				first->pMatrix[i][j] += second->pMatrix[i][j];
		return true;		//do we need to print
	}
	else
		cout << "sizes of matrixes not equal!!!\n";
	return false;
}

//template <class T>
//Matrix<T>* operator+(const Matrix<T> & first, const Matrix<T> & second)	// friend function out of the class
//{
//	if ((first.n_ == second.n_) && (first.m_ == second.m_))
//	{
//		Matrix<T> *temp = new Matrix<T>(first.n_, first.m_, 0);
//		for (int i = 0; i < first.n_; i++)
//			for (int j = 0; j < first.m_; j++)
//				temp->pMatrix[i][j] = first.pMatrix[i][j] + second.pMatrix[i][j];
//		return temp;		//do we need to print
//	}
//	else
//		cout << "sizes of matrixes not equal!!!\n";
//	return nullptr;
//}

template <class T>
Matrix<T>* Matrix<T>::operator+(const Matrix<T> & second)	// friend function out of the class
{
	if ((this->n_ == second.n_) && (this->m_ == second.m_))
	{
		Matrix<T> *temp = new Matrix<T>(second.n_, second.m_, 0);
		for (int i = 0; i < second.n_; i++)
			for (int j = 0; j < second.m_; j++)
				temp->pMatrix[i][j] = this->pMatrix[i][j] + second.pMatrix[i][j];
		return temp;		//do we need to print
	}
	else
		cout << "sizes of matrixes not equal!!!\n";
	return nullptr;
}

template <class T>
ostream& operator<< <>(ostream& os, const Matrix<T>& temp)
{
	try
	{
		for (int i = 0; i < temp.n_; i++) {
			for (int j = 0; j < temp.m_; j++) {
				os << temp.pMatrix[i][j] << "   ";
			}
			os << '\n';
		}
	}
	catch (...)
	{
		os.clear();
		os << "matrix is empty\n";
	}
	return os;
}

template <class T>
void Matrix<T>::printMatrix(const Matrix * temp)
{
	if (temp != nullptr)
	{
		for (int i = 0; i < temp->n_; i++) {
			for (int j = 0; j < temp->m_; j++) {
				cout << temp->pMatrix[i][j] << setw(3);
			}
			cout << '\n';
		}
	}
	else
		cout << "matrix is empty\n";
}

template <class T>
void Matrix<T>::deleteMatrix(Matrix * temp)
{
	for (int i = 0; i < temp->n_; i++)
		delete[] temp->pMatrix[i];
	delete[] temp->pMatrix;
}

int chooseTypeOfMatr()
{
	while (1)
	{
		cout << "please, enter the type of matrix:\n"
			<< " 0 - quit\n"
			<< " 1 - integer matrix\n"
			<< " 2 - decimal matrix\n"
			<< " 3 - char matrix\n";
		int num = inputNumber();
		if (num < 0 || num > 4) {
			cout << "wrong command!\n";
		}
		else
			return num;
	}
}

void askAboutSizeOfMatrix(int &n, int &m)
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

template <class T>
Matrix<T>::~Matrix()
{
	cout << "d-ctor\n";
	deleteMatrix(this);
}



