//
// Created by jperme on 3/18/25.
//

#include "Operators.h"
#include <SpreadsheetCell.h>

SpreadsheetCell operator+(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight) {
    // implementacija operatorja z uporabo implicitnega shorthand operatorja za vsoto - podobno lahko naredis za ostale, a nisem tega delal.
    // da se vidi oba pristopa
    auto result{cellLeft};
    result += cellRight;
    return result;
}

SpreadsheetCell operator-(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight) {
    return SpreadsheetCell(cellLeft.getValue() - cellRight.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight) {
    if ((cellRight.getValue() <=> 0.0) == std::strong_ordering::equal)
        throw std::invalid_argument("Division by zero");
    return SpreadsheetCell(cellLeft.getValue() / cellRight.getValue());
}

SpreadsheetCell operator*(const SpreadsheetCell& cellLeft, const SpreadsheetCell& cellRight) {
    return SpreadsheetCell(cellLeft.getValue() * cellRight.getValue());
}

