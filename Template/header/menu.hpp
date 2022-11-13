#pragma once
#include <iostream>
#include "./game.hpp"

class Menu {
public:
    void mainMenu(char firstPlayer, char secondPlayer);
    void setMenuInput();
    char getMenuInput();
private:
    char menuInput;
    char firstPlayer;
    char secondPlayer;
};