#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Matrixd.h"
#include "Util.h"


class ConsoleInteractionHandler {
private:
    static void parseComponent(std::string& variable, double& coef, std::string component);
    static int getVarCount(std::string& str);
public:
    std::vector<std::string> getMath();
    Matrixd* parseMath(std::vector<std::string> math, std::vector<std::string>& variableOrder);
};

