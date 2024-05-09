//
// Created by Hypericats on 5/9/2024.
//

#include "ConsoleInteractionHandler.h"

std::vector<std::string> ConsoleInteractionHandler::getMath() {
    std::vector<std::string> v;
    std::cout << "Enter equation line by line (type exit when done)" << std::endl;
    std::string str;
    while (!str.compare("exit")) {
        std::cin >> str;
        v.emplace_back(str);
    }
    return v;
}

Matrixd ConsoleInteractionHandler::parseMath(std::vector<std::string> math) {
    int columnSize = math.size();
    for (std::string str : math) {
        str.erase(std::remove(str.begin(), str.end(), '+'), str.end());
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        for (int i = 0; i < str.size(); i++) {
            if ()
        }
    }

}
