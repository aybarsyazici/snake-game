#pragma once
#include <vector>
#include "Snake.h"

using namespace std;

class Grid
{
	private:
		vector<vector<bool>> grid;

public:
	Coordinate fruitPos;
	Grid();
	void printGrid(Snake snake);
	bool gameOver(Snake snake);
	vector<vector<bool>> getGridArray();
	void setGridArray(int xCoor, int yCoor, bool value);
};
