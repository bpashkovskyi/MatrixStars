#include <iostream>

#include "cmatrix.h"

void setTestValues(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = i * size + j;
		}
	}
}

void printMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void test()
{
	constexpr int size = 5;
	int** matrix = newMatrix(size);
	setTestValues(matrix, size);


	std::cout << "Init matrix:" << std::endl;
	printMatrix(matrix, size);

	rotate90(matrix, size);
	std::cout << "Rotated 90 matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	rotate180(matrix, size);
	std::cout << "Rotated 180 matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	rotate270(matrix, size);
	std::cout << "Rotated 270 matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	flipHorizontally(matrix, size);
	std::cout << "flipped horizontally matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	flipVertically(matrix, size);
	std::cout << "flipped vertically matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	shiftRight(matrix, size, 2);
	std::cout << "shifted right by 2 matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);

	shiftBottom(matrix, size, 2);
	std::cout << "shifted bottom by 2 matrix:" << std::endl;
	printMatrix(matrix, size);
	setTestValues(matrix, size);
}