#pragma once
#include "Grid.h"

#include <iostream>

Grid::Grid() {
	for (int j = 0; j < 20; j++) {
		vector<bool> temp;
		for (int i = 0; i < 20; i++) {
			temp.push_back(0);
		}
		grid.push_back(temp);
	}
}

void Grid::printGrid(Snake snake) {
	for (int i = 0; i < grid.size(); i++) {

		if (i == 0) {
			std::cout << " ";
			for (int a = 0; a < 40; a++) {
				std::cout << "_";
			}
			std::cout << endl;
		}
		std::cout << "|";

		for (int j = 0; j < grid[i].size(); j++) {

			SnakeType result = snake.snakePos(j, i);

			if (result == SnakeType::HEAD) {
				std::cout << "O ";
			}
			else if (result == SnakeType::BODY) {
				std::cout << "a ";
			}
			else {
				std::cout << (grid[i][j] ? "1" : " ") << " ";
			}
		}
		std::cout << "|";
		std::cout << endl;

		if (i == 19) {
			std::cout << " ";
			for (int a = 0; a < 40; a++) {
				std::cout << "_";
			}
			std::cout << endl;
		}
	}
}

bool Grid::gameOver(Snake snake) {

	Coordinate headCoor = snake.positions[0];

	if (headCoor.xCoordinate < 0 || headCoor.xCoordinate > 19 || headCoor.yCoordinate < 0 || headCoor.yCoordinate > 19) {
		return true;
	}

	else {
		for (int i = 1; i < snake.positions.size(); i++) {
			if (headCoor.xCoordinate == snake.positions[i].xCoordinate && headCoor.yCoordinate == snake.positions[i].yCoordinate) {
				return true;
			}
		}
	}

	return false;
}

vector<vector<bool>> Grid::getGridArray() {
	return this->grid;
}

void Grid::setGridArray(int xCoor, int yCoor, bool value) {
	this->grid[yCoor][xCoor] = value;

	if (value) {
		this->fruitPos.xCoordinate = xCoor;
		this->fruitPos.yCoordinate = yCoor;
	}
}
