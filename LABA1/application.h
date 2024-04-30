#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include "matrix.h"

class Application {
private:
    Matrix matrix; // объект класса "Квадратная матрица"

public:
    void showMenu(); // метод для вывода меню команд приложения
    void executeCommand(int choice); // метод для выполнения выбранной команды
};

#endif // TAPPLICATION_H
