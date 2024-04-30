#include "application.h"
#include <iostream>

int main() {
    Application app;

    int choice;
    do {
        app.showMenu();
        std::cin >> choice;
        app.executeCommand(choice);
    } while (choice != 6);

    return 0;
}
