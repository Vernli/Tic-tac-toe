#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "player.hpp"
#include "menu.hpp"

class Game {
public:
    Game();
    ~Game();
    Game(const Game& game) = delete;

    void GameLoop();
    void GameLoopAI();
    int WinnerCheck();
    void PrintGameboard();
    void CleanGameboard();

    const char getFirstPlayer() { return players->FirstPlayer; };
    const char getSecondPlayer() { return players->SecondPlayer; };
    const char getCurrentPlayer() { return players->CurrentPlayer; };
    const void makeSwapPlayer() { players->swapPlayers(); };
    const void makeChangePlayer() { players->changePlayers(); }

    void setCordX();
    void setCordY();

private:
    std::vector<std::string> gameboard = { "   ", "   ", "   " };
    const std::vector<std::string> empty_gameboard = { "   ", "   ", "   " };
    char cordX;
    char cordY;
    bool isOccupied, isOutofRange, isNotNumber, isComputerTurn = false;;
    Player* players;

};