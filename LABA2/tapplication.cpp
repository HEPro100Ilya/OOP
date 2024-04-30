#include "application.h"
#include "number.h"
#include "matrix.h"
#include <iostream>



void Application::showMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Creating a matrix(Real part and Imaginary part)" << std::endl;
    std::cout << "2. Determinant" << std::endl;
    std::cout << "3. Transposed matrix" << std::endl;
    std::cout << "4. Rank" << std::endl;
    std::cout << "5. Display on the screen" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Pick: ";
}

void Application::executeCommand(int choice) {
    switch (choice) {
        case 1:
            std::cout<< "Matrix " << std::endl;
            matrix.enterMatrix(matrix.GetSize(), matrix.Getdata());
            matrix.display(matrix.GetSize(), matrix.Getdata());
            break;
        case 2:
            std::cout << "Determinant: " <<matrix.determinant(matrix.Getdata()) << std::endl;
            break;
        case 3:
            matrix.transpose(matrix.GetSize(), matrix.Getdata());
            break;
        case 4:
            std::cout << "Rank: " << matrix.rank(matrix.GetSize(), matrix.Getdata()) << std::endl;
            break;
        case 5:
            matrix.display(matrix.GetSize(), matrix.Getdata());
            break;
        case 6:
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Invalid command number, please try again" << std::endl;
            break;
    }
}




