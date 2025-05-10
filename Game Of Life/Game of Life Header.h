#pragma once

#ifndef GAMEOFLIFE_H

#define GAMEOFLIFE_H

#include <vector>
#include <string>

class GameOfLife {
public:
    GameOfLife(int rows, int cols, int birth, int death, int maintain);

    void setCellState(int row, int col, bool state);
    void displayGrid() const;
    void nextGeneration();
    void initializeRandom();
    bool isGridEmpty() const;
    int countLiveCells() const;


private:
    int rows;
    int cols;
    int birthThreshold;
    int deathThreshold;
    int maintainThreshold;
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;

    int countNeighbors(int row, int col) const;
    void updateGrid();
};

//validations
char getYesOrNoInput(const std::string& prompt);
int getValidatedThreshold(const std::string& prompt, int min = 0, int max = 8);

#endif

