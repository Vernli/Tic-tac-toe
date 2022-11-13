#include <iostream>
#include "../header/game.hpp"
#include "../header/menu.hpp"

using namespace std;

int main() {
	Game* game = new Game;
	Menu* menu = new Menu();
	bool errInvalidInput = false;
	while (menu->getMenuInput() != '3') {
		system("cls");
		if (errInvalidInput) {
			cout << "Not avalible option or invalid input" << std::endl;
		}
		menu->mainMenu(game->getFirstPlayer(), game->getSecondPlayer());

		switch (menu->getMenuInput()) {
		case 1:
			game->GameLoop();
			break;
		case 2:
			game->makeChangePlayer();
			break;
		case 3:
			cout << "Bye, bye... !";
			return 0;
		default:
			errInvalidInput = true;
			break;
		}
	}
}