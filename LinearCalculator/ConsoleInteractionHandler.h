#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Matrixd.h"


class ConsoleInteractionHandler {
public:
    std::vector<std::string> getMath();
    Matrixd parseMath(std::vector<std::string> math);
};

