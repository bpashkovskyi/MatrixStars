#include "arrow.h"

#include <iostream>
#include <ostream>

#include "cmatrix.h"

void addMatrices(int** matrix, int** newMatrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = matrix[i][j] + newMatrix[i][j];
		}
	}
}

void drawBottomArrow(int** matrix, int size, bool isCentered)
{
	// we will do this - because this is simple
	// first row is full
	// each next has 1 more empty cell from start and end

	const int middle = size / 2;

	for (int i = 0; i <= middle; ++i)
	{
		for (int j = i; j < size - i; ++j)
		{
			matrix[i][j] = 1;
		}
	}

	if (isCentered)
	{
		shiftBottom(matrix, size, middle);
	}
}

void drawLeftArrow(int** matrix, int size, bool isCentered)
{
	drawBottomArrow(matrix, size, isCentered);
	rotate90(matrix, size);
}

void drawTopArrow(int** matrix, int size, bool isCentered)
{
	drawBottomArrow(matrix, size, isCentered);
	rotate180(matrix, size);
}

void drawRightArrow(int** matrix, int size, bool isCentered)
{
	drawBottomArrow(matrix, size, isCentered);
	rotate270(matrix, size);
}

void drawArrow(int** matrix, int size, arrow arrow)
{
	int** tempMatrix = newMatrix(size);
	initWithZeroes(tempMatrix, size);

		switch (arrow.direction)
	{
	case direction::top: drawTopArrow(tempMatrix, size, arrow.isCentered);
		break;
	case direction::bottom: drawBottomArrow(tempMatrix, size, arrow.isCentered);
		break;
	case direction::left: drawLeftArrow(tempMatrix, size, arrow.isCentered);
		break;
	case direction::right: drawRightArrow(tempMatrix, size, arrow.isCentered);
		break;
	}

	addMatrices(matrix, tempMatrix, size);

	deleteMatrix(tempMatrix, size);
}

void initWithZeroes(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

void printWithStars(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (matrix[i][j] == 0)
			{
				std::cout << "- ";
			}
			else
			{
				std::cout << "* ";
			}
		}
		std::cout << std::endl;
	}
}