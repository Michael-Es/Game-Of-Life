#include "Game of Life Header.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>  
#include <utility>

GameOfLife::GameOfLife(int rows, int cols, int birth, int death, int maintain)
    : rows(rows), cols(cols), birthThreshold(birth), deathThreshold(death), maintainThreshold(maintain) {

    grid.resize(rows, std::vector<bool>(cols, false));
    nextGrid.resize(rows, std::vector<bool>(cols, false));
}

void GameOfLife::setCellState(int row, int col, bool state) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col] = state;
    }
}

void GameOfLife::displayGrid() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << (grid[i][j] ? "O" : ".") << " ";
        }
        std::cout << "\n";
    }
}

void GameOfLife::nextGeneration() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int n = countNeighbors(i, j);

            if (grid[i][j]) {
                
                if (n > deathThreshold) {
                    nextGrid[i][j] = false;
                }
                else {
                    nextGrid[i][j] = (n >= maintainThreshold && n <= deathThreshold);
                }
            }
            else {
                
                nextGrid[i][j] = (n == birthThreshold);
            }
        }
    }
    updateGrid();
}

int GameOfLife::countNeighbors(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  
            int r = row + i, c = col + j;
            int wrappedR = (row + i + rows) % rows;
            int wrappedC = (col + j + cols) % cols;
            if (grid[wrappedR][wrappedC]) {
                count++;
            }
        }
    }
    return count;
}

void GameOfLife::updateGrid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}


void GameOfLife::initializeRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Random starting point
    int startRow = rand() % rows;
    int startCol = rand() % cols;

    // Directions
    std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    
    std::vector<std::pair<int, int>> placed;
    placed.push_back(std::make_pair(startRow, startCol));
    setCellState(startRow, startCol, true);

    while (placed.size() < 25) { // usually its 5, but the grid is so small that if its 5 the sim usually ends around 3 gens which isnt that good
        // Pick a random existing cell from placed list
        std::pair<int, int> base = placed[rand() % placed.size()];
        int baseRow = base.first;
        int baseCol = base.second;

        
        std::random_shuffle(directions.begin(), directions.end());

      
        for (size_t i = 0; i < directions.size(); ++i) {
            int dr = directions[i].first;
            int dc = directions[i].second;

            int newRow = baseRow + dr;
            int newCol = baseCol + dc;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                !grid[newRow][newCol]) {
                setCellState(newRow, newCol, true);
                placed.push_back(std::make_pair(newRow, newCol));
                break;
            }
        }
    }
}

bool GameOfLife::isGridEmpty() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}

