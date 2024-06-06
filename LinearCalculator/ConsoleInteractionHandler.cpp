//
// Created by Hypericats on 5/9/2024.
//

#include "ConsoleInteractionHandler.h"

std::vector<std::string> ConsoleInteractionHandler::getMath() {
    std::vector<std::string> v;
    std::cout << "Enter equation line by line (type exit when done)" << std::endl;
    std::string str;
    while (str != "exit") {
        std::cout << "Enter next equation :" << std::endl;
        std::cin >> str;
        if (str == "exit") break;
        v.emplace_back(str);
    }
    return v;
}

//typing equations in got looong
std::vector<std::string> ConsoleInteractionHandler::getMathFromFile(std::string filePath) {
    std::ifstream f(filePath);
    std::istream_iterator<std::string> start(f), end;
    return std::vector<std::string>(start, end);
}

Matrixd* ConsoleInteractionHandler::parseMath(std::vector<std::string> math, std::vector<std::string>& variableOrder) {
    variableOrder.clear();
    int columnSize = math.size();
    int rowSize;
    Matrixd* matrixd = nullptr;
    for (int j = 0; j < math.size(); j++) {
        //std::cout << math.at(j) << std::endl;
        std::string  equation = math.at(j);

        //remove spaces so we don't need to worry about that
        equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());
        std::vector<std::string> results = Util::splitString(equation, '=');
        std::string str = results.at(0);
        //std::cout << results.at(0) << std::endl;
        //std::cout << results.at(1) << std::endl;

        //add + for every - so we can split at every +
        //start i=1 because if the first is a negative we dont want to add a +
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '-') {
                str.insert(i, "+");
                i++;
            }
        }
        std::vector<std::string> components = Util::splitString(str, '+');
        //initialization if not done already
        if (j == 0) {
            rowSize = getVarCount(str) + 1;
            matrixd = new Matrixd(rowSize, columnSize);
        }
        for (std::string c : components) {
            std::string variable;
            double coef = 1.0;
            parseComponent(variable, coef, c);
            if (j == 0) variableOrder.emplace_back(variable);
            //std::cout << "Variable order : " << std::endl;
            //Util::printVec(variableOrder);
            //std::cout << "Index : " << Util::indexOf(variable, variableOrder) << std::endl;
            //std::cout << "J : " << j << std::endl;
            //std::cout << "coef : " << coef << std::endl;
            matrixd->set(Util::indexOf(variable, variableOrder), j, coef);
            //std::cout << matrixd->toString();
        }
        matrixd->set(rowSize - 1, j, std::stod(results.at(1)));
    }
    return matrixd;
}

void ConsoleInteractionHandler::parseComponent(std::string& variable, double& coef, std::string component) {
    //std::cout << component << std::endl;
    for (int i = 0; i < component.size(); i++) {
        if (isalpha(component[i])) {
            variable = component[i];
            component.erase(i);
            break;
        }
    }
    try {
        coef = std::stod(component);
    }
    catch (std::exception& ignore) {
        for (char c : component) {
            if (c == '-') {
                coef = -1;
                return;
            }
        }
        //this means that there was no coef and it was positive therefore coef should be 1 which it already is as that is the initial value
    }
}

int ConsoleInteractionHandler::getVarCount(std::string& str) {
    int count = 0;
    for (char cha : str) {
        if (isalpha(cha)) count++;
    }
    return count;
}

