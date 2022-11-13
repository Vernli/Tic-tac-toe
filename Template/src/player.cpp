#include "../header/player.hpp"

// swap current player
void Player::swapPlayers() {
    if (CurrentPlayer == FirstPlayer) {
        CurrentPlayer = SecondPlayer;
    }
    else if (CurrentPlayer == SecondPlayer) {
        CurrentPlayer = FirstPlayer;
    }
}

// change 1st player and 2sd player
void Player::changePlayers() {
    if (FirstPlayer == 'X') {
        FirstPlayer = SecondPlayer;
        SecondPlayer = 'X';
        CurrentPlayer = FirstPlayer;
    }
    else if (FirstPlayer == 'O') {
        FirstPlayer = SecondPlayer;
        SecondPlayer = 'O';
        CurrentPlayer = FirstPlayer;
    }
}