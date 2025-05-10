
#include <vector>
#include "Game of Life Header.h""
#include <iostream>
using namespace std;

int main() {

    int rows = 10;
    int cols = 10;

    // Get custom thresholds from user, logistical limit for a 10x10 is 8 and it cant be below 0
    int birth = getValidatedThreshold("Enter the number of neighbors to birth a cell (0 to 8): ");
    int death = getValidatedThreshold("Enter the number of neighbors to kill a cell (0 to 8): ");
    int maintain = getValidatedThreshold("Enter the number of neighbors to maintain a cell (0 to 8): ");

    GameOfLife game(rows, cols, birth, death, maintain);



    game.initializeRandom(); //sets 5 random living blocks on the 10x10

    // Display the initial grid
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        game.nextGeneration();      // Compute the next generation
        game.displayGrid();         // Show the new grid

        if (game.isGridEmpty()) {   // Stop if no live cells
            std::cout << "All cells are dead. Game over.\n";
            break;
        }

        cont = getYesOrNoInput("Generate next generation? (y/n): ");
    }
}
