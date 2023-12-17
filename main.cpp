// Lets play with first 12 options of lab 8
// We're going to introduce a definition of 'arrow'
// 'Arrow' has it's direction (top/bottom/left/right)
// It also can be centered or not

// For example
// Option 2 - not centered arrow with right direction
// Option 3 - not centered arrow with bottom direction
// Option 4 - not centered arrow with top direction
// Option 5 - not centered arrow with left direction
// Option 6 - centered arrow with top direction
// Option 7 - centered arrow with bottom direction
// Option 8 - centered arrow with right direction
// Option 9 - centered arrow with left direction
// Option 10 - same as 6
// Option 12 - same as 7

// Option 1 - not centered arrow with bottom direction + not centered arrow with left direction
// Option 11 - centered arrow with top direction + centered arrow with bottom direction

#include <iostream>

#include "arrow.h"
#include "cmatrix.h"

using namespace std;

struct option
{
	int arrowsCount;
	arrow arrows[2];
};

option options[12] = {
	{2, {{direction::bottom, false}, {direction::left, false}}}, // 1
	{1, {{direction::right, false}}}, // 2
	{1, {{direction::bottom, false}}}, // 3
	{1, {{direction::top, false}}}, // 4
	{1, {{direction::left, false}}}, // 5
	{1, {{direction::top, true}}}, // 6
	{1, {{direction::bottom, true}}}, // 7
	{1, {{direction::right, true}}}, // 8
	{1, {{direction::left, true}}}, // 9
	{1, {{direction::top, true}}}, // 10
	{2, {{direction::top, true}, {direction::bottom, true}}}, // 11
	{1, {{direction::bottom, true}}}, // 12

};

int main()
{
	for (int optionNumber = 1; optionNumber <= 12; optionNumber++)
	{
		int size = 5;

		const option optionToDraw = options[optionNumber - 1];

		int** matrix = newMatrix(size);
		initWithZeroes(matrix, size);

		for (int i = 0; i < optionToDraw.arrowsCount; i++)
		{
			drawArrow(matrix, size, optionToDraw.arrows[i]);
		}

		cout << optionNumber << endl;
		printWithStars(matrix, size);
		cout << endl;

		deleteMatrix(matrix, size);
	}
}