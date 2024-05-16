//
// Created by Hypericats on 5/16/2024.
//

#include "GaussJordanHandler.h"

void GaussJordanHandler::solve() {
    //-1 because last row is solution not coef
    for (int i = 0; i < matrix.getRowSize() - 1; i++) {
        doColumn(i);
    }
}
void GaussJordanHandler::doColumn(int x) {
    for (int i = x; i < matrix.getColumnSize(); i++) {
        doPos(x, i);
    }
}

void GaussJordanHandler::doPos(int x, int y) {
    bool isLeading = y == x;
    double value = matrix.getAt(x, y);
    if (isLeading) make1(x, y, value);
    else make0(x, y, value);
}

void GaussJordanHandler::make1(int x, int y, double& value) {
    //is value already ok?
    if (value == 1) return;

}

void GaussJordanHandler::make0(int x, int y, double& value) {
    //is value already ok?
    if (value == 0) return;
}
