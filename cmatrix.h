#pragma once
int** newMatrix(int size);
void deleteMatrix(int** matrix, int size);
int** copyMatrix(int** matrix, int size);

void rotate90(int** matrix, int size);
void rotate180(int** matrix, int size);
void rotate270(int** matrix, int size);

void shiftBottom(int** matrix, int size, int step);