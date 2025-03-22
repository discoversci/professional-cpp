//
// Created by jperme on 3/18/25.
//

#ifndef OPERATORS_H
#define OPERATORS_H

#include <SpreadsheetCell.h>

SpreadsheetCell operator+(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight);
SpreadsheetCell operator-(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight);
SpreadsheetCell operator/(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight);
SpreadsheetCell operator*(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight);

#endif //OPERATORS_H
