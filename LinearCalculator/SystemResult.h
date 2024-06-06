//
// Created by Hypericats on 5/23/2024.
//

#ifndef CLION_SYSTEMRESULT_H
#define CLION_SYSTEMRESULT_H

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Matrixd.h"
#include "Util.h"

class SystemResult {
public:
    SystemResult(std::vector<std::string>& variableOrder, Matrixd& matrixd);
    std::string getVar(int index);
    double getVarVal(std::string var);
    double getVarIndexVal(int index);
    bool isInfinite();
    bool isNoSolution();
    std::string toString();
private:
    std::vector<std::string>& variables;
    Matrixd& matrix;
    std::vector<double> results;
};


#endif //CLION_SYSTEMRESULT_H
