#pragma once
#include <string>
#include <vector>

class Util {
public:
    static std::vector<std::string> splitString(const std::string& str, const char& regex);
    static int indexOf(std::string str, std::vector<std::string>);
};

