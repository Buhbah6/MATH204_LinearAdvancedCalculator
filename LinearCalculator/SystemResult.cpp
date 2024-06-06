//
// Created by Hypericats on 5/23/2024.
//

#include "SystemResult.h"

std::string SystemResult::getVar(int index) {
    return variables.at(index);
}

double SystemResult::getVarVal(std::string var) {
    return results.at(std::find(variables.begin(), variables.end(), var) - variables.begin());
}

double SystemResult::getVarIndexVal(int index) {
    return results.at(index);
}

SystemResult::SystemResult(std::vector<std::string>& variableOrder, Matrixd& matrixd) : variables(variableOrder), matrix(matrixd) {
    for (int i = 0; i < this->matrix.getColumnSize(); i++) {
        results.emplace_back(matrixd.getAt(matrixd.getRowSize() - 1, i));
    }
}

std::string SystemResult::toString() {
    std::string str;

    if (isInfinite())
        return "There are infinitely many solutions!";
    if (isNoSolution())
        return "There are no possible solutions!";

    for (int i = 0; i < variables.size(); i++) {
        str.append(variables.at(i));
        str.append(" = ");
        std::ostringstream res;
        res << results.at(i);
        str.append(res.str());
        str.append("\n");
    }
    return str;
}

bool SystemResult::isInfinite() {
    for (double d : results) {
        if (_isnan(d)) return true;
    }
    return false;
}

bool SystemResult::isNoSolution() {
    return matrix.isNoSolution();
}

