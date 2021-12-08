// snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "Grid.h"
#include "Snake.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions


    Grid grid = Grid();
    Snake snake = Snake(3,3, true);

    grid.setGridArray(8, 3, 1);

    snake.grow();

    grid.printGrid(snake);


    std::cout << !grid.gameOver(snake) << endl;

    while (!grid.gameOver(snake)) {

        if (snake.keyboardInput) {
            if (GetAsyncKeyState(VK_UP)) {
                if (snake.direction != Direction::DOWN)
                    snake.direction = Direction::UP;
            }
            else if (GetAsyncKeyState(VK_RIGHT)) {
                if (snake.direction != Direction::LEFT)
                    snake.direction = Direction::RIGHT;
            }
            else if (GetAsyncKeyState(VK_LEFT)) {
                if (snake.direction != Direction::RIGHT)
                    snake.direction = Direction::LEFT;
            }
            else if (GetAsyncKeyState(VK_DOWN)) {
                if (snake.direction != Direction::UP)
                    snake.direction = Direction::DOWN;
            }
        }

        bool fruitConsumed = snake.move(snake.direction, grid.fruitPos);

        if (fruitConsumed) {
            grid.setGridArray(grid.fruitPos.xCoordinate, grid.fruitPos.yCoordinate, 0);

            int randXCoor = rand() % 19;
            int randYCoor = rand() % 19;

            grid.setGridArray(randXCoor, randYCoor, 1);

        }

        grid.printGrid(snake);

        MoveWindow(console, r.left, r.top, 380, 420, TRUE);
        this_thread::sleep_for(chrono::milliseconds(700));
    }

}