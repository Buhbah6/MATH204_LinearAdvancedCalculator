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
    rawMatrix.at(y).at(x) = value;
}

void Matrixd::mult(int row, double coef) {
    std::vector<double> rowV = this->getRow(row);
    for (int i = 0; i < rowV.size(); i++) {
        this->set(i, row, rowV[i] * coef);
    }
}

void Matrixd::swapRows(int row1, int row2) {
    std::vector<double> rowV1 = this->getRow(row1);
    std::vector<double> rowV2 = this->getRow(row2);
    for (int i = 0; i < rowV1.size(); i++) {
        this->set(i, row2, rowV1[i]);
    }
    for (int i = 0; i < rowV2.size(); i++) {
        this->set(i, row1, rowV2[i]);
    }
}

void Matrixd::multAddRow(int rowToMultiply, int rowToAddTo, double coef) {
    std::vector<double> rowV1 = this->getRow(rowToMultiply);
    std::vector<double> rowV2 = this->getRow(rowToAddTo);
    for (int i = 0; i < rowV1.size(); i++) {
        std::cout << i << std::endl;
        std::cout << "adding " << rowV1[i] * coef << std::endl;
        this->set(i, rowToAddTo, rowV1[i] * coef + rowV2[i]);
    }
}
