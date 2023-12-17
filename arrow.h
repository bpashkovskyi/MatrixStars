#pragma once

enum direction { top, bottom, left, right };

struct arrow
{
	direction direction;
	bool isCentered;
};

void drawArrow(int** matrix, int size, arrow arrow);

void initWithZeroes(int** matrix, int size);
void printWithStars(int** matrix, int size);