#include <iostream>
#include "ConsoleInteractionHandler.h"

#include "Matrixd.h"

int main() {
    ConsoleInteractionHandler console;
    std::vector<std::string> math = console.getMath();
    std::vector<std::string> variableOrder;
    Matrixd* matrix = console.parseMath(math, variableOrder);
    std::cout << matrix->toString();
}
