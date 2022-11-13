#include "../header/game.hpp"

Game::Game() {
	players = new Player();
}
Game::~Game() {
	delete players; 
}

void Game::PrintGameboard() {
	std::cout << "|" << gameboard[0][0] << "|" << gameboard[0][1] << "|" << gameboard[0][2] << "|" << std::endl;
	std::cout << "|" << gameboard[1][0] << "|" << gameboard[1][1] << "|" << gameboard[1][2] << "|" << std::endl;
	std::cout << "|" << gameboard[2][0] << "|" << gameboard[2][1] << "|" << gameboard[2][2] << "|" << std::endl;
	return;
}

void Game::CleanGameboard() {
	gameboard = empty_gameboard;
}

void Game::setCordX() {
	std::string wholeInput;
	std::cin >> wholeInput;
	cordX = wholeInput[0];
}

void Game::setCordY() {
	std::string wholeInput;
	std::cin >> wholeInput;
	cordY = wholeInput[0];
}

void Game::GameLoop() {
	while (!WinnerCheck()) {
		system("cls");
		// Errors Effect
		if (isOccupied) {
			std::cout << "Place is occupied!\n";
		}
		if (isOutofRange) {
			std::cout << "Cordinates out of range!" << std::endl;
		}
		if (isNotNumber) {
			std::cout << "Inserted value is not number!" << std::endl;
		}
		isOccupied = false;
		isOutofRange = false;
		isNotNumber = false;

		PrintGameboard();
		std::cout << "Enter coordinates:\n";
		std::cout << "X: "; setCordX();
		std::cout << "Y: ";	setCordY();

		if ((cordX > 47 && cordX < 58) && (cordY > 47 && cordY < 58)) {
			cordX -= 48;
			cordY -= 48;
		}
		else {
			isNotNumber = true;
			continue;
		}

		if (cordX < 0 || cordX > 2) {
			isOutofRange = true;
			continue;
		}

		if (gameboard[cordX][cordY] == ' ') {
			gameboard[cordX][cordY] = players->CurrentPlayer;

			if (players->CurrentPlayer == players->FirstPlayer)
				players->swapPlayers();
			else if (players->CurrentPlayer == players->SecondPlayer)
				players->swapPlayers();

			isOccupied = false;
		}
		else if (gameboard[cordX][cordY] == 'X' || gameboard[cordX][cordY] == 'O')
			isOccupied = true;
	}
	int winner = WinnerCheck();
	system("cls");
	PrintGameboard();

	if (winner == 1) {
		std::cout << "Player X won!\n";
		CleanGameboard();
		system("pause");
	}
	else if (winner == 2) {
		std::cout << "Player O won!\n";
		CleanGameboard();
		system("pause");
	}
		
	else {
		std::cout << "Draw!\n";
		CleanGameboard();
		system("pause");
	}
}

int Game::WinnerCheck() {
	// win in row
	for (int r = 0; r < 3; r++) {
		if (gameboard[r][0] == 'X' && gameboard[r][1] == 'X' && gameboard[r][2] == 'X')
			return 1;
		else if (gameboard[r][0] == 'O' && gameboard[r][1] == 'O' && gameboard[r][2] == 'O')
			return 2;
	}

	// win in column
	for (int c = 0; c < 3; c++) {
		if (gameboard[0][c] == 'X' && gameboard[1][c] == 'X' && gameboard[2][c] == 'X')
			return 1;
		else if (gameboard[0][c] == 'O' && gameboard[1][c] == 'O' && gameboard[2][c] == 'O')
			return 2;
	}

	// win diagonal \/
	if (gameboard[0][0] == 'X' && gameboard[1][1] == 'X' && gameboard[2][2] == 'X')
		return 1;
	else if (gameboard[0][0] == 'O' && gameboard[1][1] == 'O' && gameboard[2][2] == 'O')
		return 2;
	if (gameboard[0][2] == 'X' && gameboard[1][1] == 'X' && gameboard[2][0] == 'X')
		return 1;
	else if (gameboard[0][2] == 'O' && gameboard[1][1] == 'O' && gameboard[2][0] == 'O')
		return 2;

	// draw - by count occupied places in gameboard
	int result = 0;
	for (int i = 0; i < gameboard.size(); i++) {
		std::string::difference_type n = count(gameboard[i].begin(), gameboard[i].end(), ' ');
		if (n != 0) {
			result = 0;
			break;
		}
		else if (n == 0) {
			result = -1;
			continue;
		}
	}
	if (result == -1)
		return -1;

	return 0;
}