#include "Game of life Header.h"
#include <iostream>
#include <cassert>

void testRandomInitialization() {
    GameOfLife game(5, 5, 3, 3, 2);

    game.initializeRandom();
    std::cout << "After Random Initialization:\n";
    game.displayGrid();

    int liveCells = game.countLiveCells();
    std::cout << "Live cells count: " << liveCells << "\n";

    // Check that the grid is not empty
    assert(!game.isGridEmpty());

    // Check that live cells are at most 25
    assert(liveCells <= 25);

    // Check that at least 1 cell is alive
    assert(liveCells >= 1);

    std::cout << "testRandomInitialization passed!\n";
}

int main () {
    testRandomInitialization();
}