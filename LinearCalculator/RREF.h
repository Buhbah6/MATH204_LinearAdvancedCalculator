//
// Created by Hypericats on 5/23/2024.
//

#ifndef CLION_RREF_H
#define CLION_RREF_H

#include "Matrixd.h"
#include "SystemResult.h"
#include <iostream>

class RREF {
public:
    explicit RREF(Matrixd& matrix) : matrix(matrix) {};
    void solve();
private:
    Matrixd& matrix;
    void doColumn(int x);
    void doPos(int x, int y);

};


#endif //CLION_RREF_H
