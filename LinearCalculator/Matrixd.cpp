//
// Created by Hypericats on 5/9/2024.
//

#include "Matrixd.h"

double Matrixd::getAt(int x, int y) {
    return this->rawMatrix.at(x).at(y);
}

std::vector<double> Matrixd::getRow(int y) {
    return this->rawMatrix.at(y);
}

std::vector<double> Matrixd::getColumn(int x) {
    //iterate through columns and get 1 column
    std::vector<double> v;
    for (int i = 0; i < getColumnSize(); i++)
        v.emplace_back(getAt(x, i));
    return v;
}

std::string Matrixd::toString() {
    std::string str;
    for (int x = 0; x < getColumnSize(); x++) {
        for (int y = 0; y < getRowSize(); y++) {
            double d = getAt(x, y);
            //just get the integer if it has no decimals
            if (std::fmod(d, 1) == 0.0)
                str.append(std::to_string((int)d));
            else
                str.append(std::to_string(getAt(x, y)));
            str.append(" ");
        }
        str.append("\n");
    }
    return str;
}

int Matrixd::getRowSize() const {
    return rowSize;
}
int Matrixd::getColumnSize() const {
    return columnSize;
}

Matrixd::Matrixd(int sizeX, int sizeY) {
    this->rowSize = sizeX;
    this->columnSize = sizeY;
    //Initialize vector to 0
    rawMatrix = std::vector<std::vector<double>>(sizeY, std::vector<double>(sizeX, 0.0));
}

Matrixd::Matrixd(int sizeX, int sizeY, std::vector<std::vector<double>> data) {
    this->rowSize = sizeX;
    this->columnSize = sizeY;
    //Initialize vector to 0
    rawMatrix = data;
}

void Matrixd::setRow(int y, std::vector<double>& value) {
    if (value.size() > rowSize) throw std::out_of_range("Size " + std::to_string(value.size()) + " is out of bounds for size " + std::to_string(rowSize));
    if (y >= columnSize) throw std::out_of_range("Index " + std::to_string(y) + " is out of bounds for size " + std::to_string(columnSize));
    for (int i = 0; i < value.size(); i++) {
        rawMatrix.at(y).at(i) = value.at(i);
    }
}

void Matrixd::setColumn(int x, std::vector<double>& value) {
    if (value.size() > columnSize) throw std::out_of_range("Size " + std::to_string(value.size()) + " is out of bounds for size " + std::to_string(columnSize));
    if (x >= rowSize) throw std::out_of_range("Index " + std::to_string(x) + " is out of bounds for size " + std::to_string(rowSize));
    for (int i = 0; i < value.size(); i++) {
        rawMatrix.at(i).at(x) = value.at(i);
    }
}

void Matrixd::set(int x, int y, const double value) {
    rawMatrix.at(x).at(y) = value;
}
