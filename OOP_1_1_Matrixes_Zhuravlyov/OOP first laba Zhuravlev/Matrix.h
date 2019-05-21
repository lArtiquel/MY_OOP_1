#pragma once

struct Matrix
{
	Matrix(int n, int m, bool flag = 1);

	int n_,m_;								//size of matrix
	int **pMatrix;							//pointer to the matrix

	~Matrix();
};

//functions to work with matrix/vector(it's reasonable to do them in class, but prepod restricted to do that)

void askAboutSizeOfVector(int &m);

int** createMatrix(Matrix *matr);

int** fillMatrix(Matrix *matr);

int chooseMatrix();

Matrix* swapTranspose(Matrix *&matr);

Matrix* xorTranspose(Matrix *&matr);

Matrix* firstTransposeForNonSquareMatrix(Matrix *&matr);

Matrix * secondTransposeForNonSquareMatrix(Matrix *& matr);

Matrix * firstWayCreating(const Matrix *first, const Matrix *second);

void secondWayCreating(const Matrix *first, const Matrix * second, Matrix *& result);

void printMatrix(const Matrix *temp);

void deleteMatrix(Matrix * temp);


