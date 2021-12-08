#pragma once
#include "Snake.h"
#include "Grid.h"


Snake::Snake(int startXCoor, int startYCoor, bool keyboardInput = true) {
	size = 1;
	Coordinate startingCoordinate = Coordinate(startXCoor, startYCoor);
	positions.push_back(startingCoordinate);
	direction = Direction::RIGHT;
	this->keyboardInput = keyboardInput;
}

SnakeType Snake::snakePos(int xCoordinate, int yCoordinate) {

	for (int i = 0; i < positions.size(); i++) {
		Coordinate currCoor = positions[i];

		if (currCoor.xCoordinate == xCoordinate && currCoor.yCoordinate == yCoordinate) {

			if (i == 0) {
				return SnakeType::HEAD;
			}

			return SnakeType::BODY;
		}
	}

	return SnakeType::EMPTY;

}

void Snake::grow() {

	if (size == 1) {
		Coordinate headCoor = positions[0];
		switch (direction)
		{
		case Direction::LEFT: {
			Coordinate coordinate = Coordinate(headCoor.xCoordinate + 1, headCoor.yCoordinate);
			positions.push_back(coordinate);
			break;
		}
		case Direction::RIGHT: {
			Coordinate coordinate = Coordinate(headCoor.xCoordinate - 1, headCoor.yCoordinate);
			positions.push_back(coordinate);
			break;
		}
		case Direction::UP: {
			Coordinate coordinate = Coordinate(headCoor.xCoordinate, headCoor.yCoordinate + 1);
			positions.push_back(coordinate);
			break;
		}
	
		case Direction::DOWN: {
			Coordinate coordinate = Coordinate(headCoor.xCoordinate, headCoor.yCoordinate - 1);
			positions.push_back(coordinate);
			break;
		}
		default: {
			break;
		}
		}
	}
	else {
		Coordinate tailCoord = positions[size - 1];
		Coordinate secondLast = positions[size - 2];
		Coordinate temp;
		// Grow in X 
		if (secondLast.xCoordinate != tailCoord.xCoordinate) { 
			
			if (tailCoord.xCoordinate < secondLast.xCoordinate) {
				temp = Coordinate(tailCoord.xCoordinate - 1, tailCoord.yCoordinate);
			}
			else {
				temp = Coordinate(tailCoord.xCoordinate + 1, tailCoord.yCoordinate);
			}

		}
		else if (secondLast.yCoordinate != tailCoord.yCoordinate) { 
			// Grow in Y
			if (tailCoord.yCoordinate < secondLast.yCoordinate) {
				temp = Coordinate(tailCoord.xCoordinate, tailCoord.yCoordinate - 1);
			}
			else {
				temp = Coordinate(tailCoord.xCoordinate, tailCoord.yCoordinate + 1);
			}
		}
		positions.push_back(temp);
	}
	size++;

}

bool Snake::move(Direction directionInput, Coordinate fruitPos) {
	switch (directionInput)
	{
	case Direction::LEFT: {

		if (direction == Direction::RIGHT) {
			return false;
		}

		direction = Direction::LEFT;
		
		Coordinate head = positions[0];
		positions.pop_back();

		Coordinate newHead = Coordinate(head.xCoordinate - 1, head.yCoordinate);

		positions.insert(positions.begin(), newHead);

		break;
	}
	case Direction::RIGHT: {

		if (direction == Direction::LEFT) {
			return false;
		}
		Coordinate head = positions[0];
		positions.pop_back();

		Coordinate newHead = Coordinate(head.xCoordinate + 1, head.yCoordinate);

		positions.insert(positions.begin(), newHead);

		break;
	}
	case Direction::UP: {

		if (direction == Direction::DOWN) {
			return false;
		}
		Coordinate head = positions[0];
		positions.pop_back();

		Coordinate newHead = Coordinate(head.xCoordinate, head.yCoordinate - 1);

		positions.insert(positions.begin(), newHead);

		break;
	}
	case Direction::DOWN: {

		if (direction == Direction::UP) {
			return false;
		}
		Coordinate head = positions[0];
		positions.pop_back();

		Coordinate newHead = Coordinate(head.xCoordinate, head.yCoordinate + 1);

		positions.insert(positions.begin(), newHead);

		break;
	}
	default:
		break;
	}

	//If the head is on top of a fruit
	Coordinate head = positions[0];

	if (fruitPos.xCoordinate == head.xCoordinate && fruitPos.yCoordinate == head.yCoordinate) {
		grow();

		return true;
	}

	return false;

}