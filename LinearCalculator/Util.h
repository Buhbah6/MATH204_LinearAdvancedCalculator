//
// Created by Hypericats on 5/9/2024.
//

#ifndef CLION_UTIL_H
#define CLION_UTIL_H

#include <string>
#include <vector>
#include <iostream>

class Util {
public:
    static std::vector<std::string> splitString(const std::string& str, const char& regex);
    static int indexOf(std::string str, std::vector<std::string>);
    static void printVec(std::vector<std::string> vec);
};


#endif //CLION_UTIL_H
