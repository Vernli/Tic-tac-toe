#pragma once

struct Player
{
    char FirstPlayer = 'X';
    char SecondPlayer = 'O';
    char CurrentPlayer = FirstPlayer;

    void swapPlayers();
    void changePlayers();
};