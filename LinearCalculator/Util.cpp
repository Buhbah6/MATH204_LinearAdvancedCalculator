#include "Util.h"


//for a future string version, str.find(std::basic_string, size_t size) exists
std::vector<std::string> Util::splitString(const std::string& str, const char& regex) {
    std::vector<std::string> splits;
    std::string strCopy = str;
    int searchIndex;
    int index = 0;
    //Check that there is still another instance of the regex in the string
    while (true) {
        searchIndex = (int)strCopy.find(regex);
        if (searchIndex == -1) break;
        //Need to store in variable in order to call the constructor from Cstring to string
        std::string out = strCopy.substr(0, searchIndex);
        splits.push_back(out);
        strCopy = strCopy.substr(searchIndex + 1);
        index++;
    }
    splits.push_back(strCopy);
    return splits;
}

int Util::indexOf(std::string str, std::vector<std::string> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == str) return i;
    }
    return -1;
}