//
// Created by Hypericats on 5/16/2024.
//

#ifndef CLION_GAUSSJORDANHANDLER_H
#define CLION_GAUSSJORDANHANDLER_H

#include "Matrixd.h"
#include <iostream>

class GaussJordanHandler {
public:
    explicit GaussJordanHandler(Matrixd& matrix) : matrix(matrix) {};
    void solve();
private:
    Matrixd& matrix;
    void doColumn(int x);
    void doPos(int x, int y);
    void make1(int x, int y, double& value);
    void make0(int x, int y, double& value);

};


#endif //CLION_GAUSSJORDANHANDLER_H
