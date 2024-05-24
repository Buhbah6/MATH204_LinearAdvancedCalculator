//
// Created by Hypericats on 5/16/2024.
//

#ifndef CLION_REF_H
#define CLION_REF_H

#include "Matrixd.h"
#include <iostream>

class REF {
public:
    explicit REF(Matrixd& matrix) : matrix(matrix) {};
    void solve();
private:
    Matrixd& matrix;
    void doColumn(int x);
    void doPos(int x, int y);
    void make1(int x, int y, double& value);
    void make0(int x, int y, double& value);

};


#endif //CLION_REF_H
