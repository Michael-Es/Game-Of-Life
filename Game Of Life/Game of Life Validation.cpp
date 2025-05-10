#include <iostream>
#include <limits>
#include <string>
#include "Game of Life Header.h"

char getYesOrNoInput(const std::string& prompt) {
    std::string input;
    char response;

    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (input.length() == 1) {
            response = std::tolower(input[0]);
            if (response == 'y' || response == 'n') {
                return response;
            }
        }

        std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int getValidatedThreshold(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < min || value > max) {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        else {
            return value;
        }
    }
}