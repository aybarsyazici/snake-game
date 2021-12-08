#pragma once
#include <vector>

struct Coordinate {
	int xCoordinate;
	int yCoordinate;
	
	Coordinate(int x, int y) {
		xCoordinate = x;
		yCoordinate = y;
	}

	Coordinate() {
		xCoordinate = 0;
		yCoordinate = 0;
	}
};

enum class Direction { LEFT, RIGHT, UP, DOWN };

enum class SnakeType { HEAD, BODY, EMPTY };

class Snake
{
private:
	int size;

public:
	SnakeType snakePos(int xCoordinate, int yCoordinate);
	Snake(int startXCoor, int startYCoor, bool keyboardInput);
	void grow();
	bool move(Direction directionInput, Coordinate fruitPos);
	std::vector<Coordinate> positions;
	Direction direction;
	bool keyboardInput;
};
