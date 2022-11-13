#include "../header/menu.hpp"

void Menu::setMenuInput() {
    std::string wholeInput;
    std::cin >> wholeInput;
    
    menuInput = wholeInput[0];
    if (wholeInput.length() > 1) {
        menuInput = '9';
        return;
    }
    if (menuInput > 48 && menuInput < 52) {
        menuInput -= 48;
        return;
    }
    else {
        menuInput = '9';
        return;
    }

    
}

char Menu::getMenuInput() {
    return menuInput;
}

void Menu::mainMenu(char firstPlayer, char secondPlayer) {
    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << "-----------\n";
    std::cout << "First player: " << firstPlayer << std::endl;
    std::cout << "Second player: " << secondPlayer << std::endl;
    std::cout << "-----------\n\n";
    std::cout << "1# Press me to play!" << std::endl;
    std::cout << "2# Press me to swap players!" << std::endl;
    std::cout << "3# Press me to leave!" << std::endl;
    std::cout << "#: "; setMenuInput();
}