#include "cmatrix.h"

#include <iostream>

int** newMatrix(int size)
{
	int** matrix = new int* [size];

	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}

	return matrix;
}

void deleteMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** copyMatrix(int** matrix, int size)
{
	int** tempMatrix = newMatrix(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			tempMatrix[i][j] = matrix[i][j];
		}
	}

	return tempMatrix;
}

void rotate90(int** matrix, int size)
{
	int** tempMatrix = copyMatrix(matrix, size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = tempMatrix[size - j - 1][i];
		}
	}

	deleteMatrix(tempMatrix, size);
}

void rotate180(int** matrix, int size)
{
	rotate90(matrix, size);
	rotate90(matrix, size);
}

void rotate270(int** matrix, int size)
{
	rotate90(matrix, size);
	rotate90(matrix, size);
	rotate90(matrix, size);
}

void shiftBottom(int** matrix, int size, int step)
{
	int** tempMatrix = copyMatrix(matrix, size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i < step)
			{
				matrix[i][j] = 0;
			}
			else
			{
				matrix[i][j] = tempMatrix[i - step][j];
			}
		}
	}

	deleteMatrix(tempMatrix, size);
}