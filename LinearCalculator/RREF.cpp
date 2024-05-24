//
// Created by Hypericats on 5/23/2024.
//

#include "RREF.h"

void RREF::solve() {
    //-2 because index starts at 0 and the last is the results
    for (int i = matrix.getRowSize() - 2; i > 0; i--) {
        doColumn(i);
    }
}
void RREF::doColumn(int x) {
    for (int i = x - 1; i >= 0; i--) {
        doPos(x, i);
    }
}

void RREF::doPos(int x, int y) {
    std::cout << "Doing pos " << x << " " << y << std::endl;
    //area is already covered by REF
    if (y >= x) std::cout << "error THIS SHOULD NOT OCCUR VERY BAD THINGS MIGHT HAPPEN" << std::endl;
    double value = matrix.getAt(x, y);
    //no changes needed
    if (value == 0) {
        std::cout << matrix.toString();
        return;
    }
    std::cout << "Multiplying row " << x << " by " << value / matrix.getAt(x, x) * -1 << " and adding it to row " << y << std::endl;
    matrix.multAddRow(x, y, value / matrix.getAt(x, x) * -1);
    std::cout << matrix.toString();
}
