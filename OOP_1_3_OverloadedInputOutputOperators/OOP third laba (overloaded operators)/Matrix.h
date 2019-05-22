#pragma once

class Matrix
{
public:
	Matrix(int n, int m, bool flag = 1);

	static void askAboutSizeOfMatrix(int &n, int &m);

	static int** createMatrix(Matrix *matr);

	static int** fillMatrix(Matrix *matr);

	static int chooseMatrix();

	static Matrix* swapTranspose(Matrix * matr);

	static Matrix* xorTranspose(Matrix * matr);

	static Matrix* swapTransposeForNonSquareMatrix(Matrix * matr);

	static Matrix* firstWayAdditing(const Matrix *first, const Matrix *second);

	static bool secondWayAdditing(Matrix * first, const Matrix * second);

	Matrix* operator+(const Matrix &second);

	friend bool operator+(const Matrix &first, const Matrix & second);

	friend ostream& operator<<(ostream& os, const Matrix& temp);

	static void printMatrix(const Matrix *temp);

	static void deleteMatrix(Matrix * temp);

	~Matrix();
private:
	int n_,m_;								//size of matrix
	int **pMatrix;							//private pointer to the matrix
};



