//
// Created by Hypericats on 5/9/2024.
//

#ifndef CLION_MATRIXD_H
#define CLION_MATRIXD_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

class Matrixd {

private:
    //stores columns of rows
    //so outer vector is the columns (x)
    //inner is the rows (y)

    //first x = 0 same for y
    std::vector<std::vector<double>> rawMatrix;
    int rowSize = 0;
    int columnSize = 0;

public:
    double getAt(int x, int y);
    std::vector<double> getRow(int y);
    std::vector<double> getColumn(int x);
    std::string toString();
    int getRowSize() const;
    int getColumnSize() const;
    void setRow(int y, std::vector<double>& value);
    void setColumn(int x, std::vector<double>& value);
    void set(int x, int y, const double value);
    bool isNoSolution();

    Matrixd(int sizeX, int sizeY);
    Matrixd(int sizeX, int sizeY, std::vector<std::vector<double>> data);

    //gaus jordan thingies
    void swapRows(int row1, int row2);
    void multAddRow(int rowToMultiply, int rowToAddTo, double coef);
    void mult(int row, double coef);
};


#endif //CLION_MATRIXD_H
