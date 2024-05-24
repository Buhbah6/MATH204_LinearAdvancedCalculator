//
// Created by Hypericats on 5/16/2024.
//

#include "REF.h"

void REF::solve() {
    //-1 because last row is solution not coef
    for (int i = 0; i < matrix.getRowSize() - 1; i++) {
        doColumn(i);
    }
}
void REF::doColumn(int x) {
    for (int i = x; i < matrix.getColumnSize(); i++) {
        doPos(x, i);
    }
}

void REF::doPos(int x, int y) {
    std::cout << "Doing pos " << x << " " << y << std::endl;
    bool isLeading = y == x;
    double value = matrix.getAt(x, y);
    if (isLeading) make1(x, y, value);
    else make0(x, y, value);
    std::cout << matrix.toString();
}

void REF::make1(int x, int y, double& value) {
    //is value already ok?
    if (value == 1) return;
    //error probably impossible or infinite
    if (value == 0 && y == matrix.getColumnSize() - 1) return;
    matrix.mult(y, 1 / value);

}

void REF::make0(int x, int y, double& value) {
    //is value already ok?
    if (value == 0) return;
    std::cout << "Multiplying row " << x << " by " << value / matrix.getAt(x, x) * -1 << " and adding it to row " << y << std::endl;
    matrix.multAddRow(x, y, value / matrix.getAt(x, x) * -1);
}
