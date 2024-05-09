#include <iostream>
#include "ConsoleInteractionHandler.h"

#include "Matrixd.h"


int main() {
    ConsoleInteractionHandler console;
    std::vector<std::string> math = console.getMath();

    Matrixd matrix(10, 10);
    matrix.set(9, 9, 5);
    std::cout << matrix.toString();
}
