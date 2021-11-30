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
    Snake snake = Snake(3,3);

    grid.setGridArray(8, 3, 1);

    grid.printGrid(snake);

    snake.grow();
    snake.grow();
    snake.grow();

    grid.printGrid(snake);


    std::cout << !grid.gameOver(snake) << endl;

    while (!grid.gameOver(snake)) {

        std::cout << "hey" << endl;
        bool fruitConsumed = snake.move(Direction::RIGHT, grid.fruitPos);

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
