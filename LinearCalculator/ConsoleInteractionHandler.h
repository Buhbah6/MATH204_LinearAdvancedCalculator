//
// Created by Hypericats on 5/9/2024.
//

#ifndef CLION_CONSOLEINTERACTIONHANDLER_H
#define CLION_CONSOLEINTERACTIONHANDLER_H


#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <iterator>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Matrixd.h"
#include "Util.h"


class ConsoleInteractionHandler {
private:
    static void parseComponent(std::string& variable, double& coef, std::string component);
    static int getVarCount(std::string& str);
public:
    std::vector<std::string> getMath();
    std::vector<std::string> getMathFromFile(std::string filePath);
    Matrixd* parseMath(std::vector<std::string> math, std::vector<std::string>& variableOrder);
};


#endif //CLION_CONSOLEINTERACTIONHANDLER_H
