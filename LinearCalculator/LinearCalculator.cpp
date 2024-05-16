#include <iostream>
#include "ConsoleInteractionHandler.h"

#include "Matrixd.h"
#include "GaussJordanHandler.h"

int main() {
    ConsoleInteractionHandler console;
    std::vector<std::string> math = console.getMath();
    std::cout << "loading equation : " << std::endl;
    for (std::string str : math) {
        std::cout << str << '\n';
    }

    std::cout << "Creating matrix : " << std::endl;
    std::vector<std::string> variableOrder;
    //don't forget to delete matrix
    Matrixd* matrix = console.parseMath(math, variableOrder);
    std::cout << matrix->toString();

    GaussJordanHandler gauss(*matrix);
    gauss.solve();


}
//todo
//console input doesn't work with space because std::cin