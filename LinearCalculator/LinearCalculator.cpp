#include <iostream>
#include "ConsoleInteractionHandler.h"

#include "Matrixd.h"
#include "REF.h"
#include "RREF.h"
#include "SystemResult.h"

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

    //transform matrix to row echelon form
    REF ref(*matrix);
    ref.solve();

    std::cout << std::endl;
    std::cout << "DONE REF!" << std::endl;
    std::cout << std::endl;

    //transform matrix to reduced row echelon form
    RREF rref(*matrix);
    rref.solve();
    std::cout << "DONE RREF!" << std::endl;
    std::cout << std::endl;

    SystemResult result(variableOrder, *matrix);
    std::cout << result.toString();




}
//todo
//console input doesn't work with space because std::cin