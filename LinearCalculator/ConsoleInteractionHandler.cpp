//
// Created by Hypericats on 5/9/2024.
//

#include "ConsoleInteractionHandler.h"

std::vector<std::string> ConsoleInteractionHandler::getMath() {
    std::vector<std::string> v;
    std::cout << "Enter equation line by line (type exit when done)" << std::endl;
    std::string str;
    while (str != "exit") {
        std::cin >> str;
        std::cout << std::endl;
        if (str == "exit") break;
        std::cout << str << std::endl;
        v.emplace_back(str);
    }
    std::cout << "test" << std::endl;
    return v;
}

Matrixd* ConsoleInteractionHandler::parseMath(std::vector<std::string> math, std::vector<std::string>& variableOrder) {
    int columnSize = math.size();
    int rowSize;
    Matrixd* matrixd = nullptr;
    bool vars = true;
    for (int j = 0; j < math.size(); j++) {
        std::cout << math.at(j) << std::endl;
        std::vector<std::string> results = Util::splitString(math.at(j), '=');
        std::string str = results.at(0);
        std::cout << results.at(0) << std::endl;
        std::cout << results.at(1) << std::endl;
        //remove empty space so we don't need to worry about that
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        //add + for every - so we can split at every +
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-') {
                str.insert(i, "+");
                i++;
            }
        }
        std::vector<std::string> components = Util::splitString(str, '+');
        variableOrder.clear();
        if (vars) {
            rowSize = getVarCount(str) + 1;
            matrixd = new Matrixd(rowSize, columnSize);
        }
        for (std::string c : components) {
            std::string variable;
            double coef = 0.0;
            parseComponent(variable, coef, c);
            if (vars) variableOrder.emplace_back(variable);
            matrixd->set(Util::indexOf(variable, variableOrder), j, coef);
        }
    }
    return matrixd;
}

void ConsoleInteractionHandler::parseComponent(std::string& variable, double& coef, std::string component) {
    for (int i = 0; i < component.size(); i++) {
        if (isalpha(component[i])) {
            variable = component[i];
            component.erase(i);
            break;
        }
    }
    std::cout << component << std::endl;
    coef = std::stod(component);
}

int ConsoleInteractionHandler::getVarCount(std::string& str) {
    int count = 0;
    for (char cha : str) {
        if (isalpha(cha)) count++;
    }
    return count;
}
