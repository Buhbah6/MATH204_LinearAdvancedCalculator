#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <stdexcept>

class Matrixd {

private:
    //stores columns of rows
    //so outer vector is the columns (x)
    //inner is the rows (y)

    //first x = 0 same for y
    std::vector<std::vector<double>> rawMatrix;
    int rowSize;
    int columnSize;

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

    Matrixd(int sizeX, int sizeY);
    Matrixd(int sizeX, int sizeY, std::vector<std::vector<double>> data);
};

