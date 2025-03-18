//
// Created by jperme on 3/7/25.
//

#ifndef BAR_H
#define BAR_H
#include <SpreadSheetCell.h>
#include <iostream>
#include <format>

class Foo;
class SpreadsheetCell;

class Bar {

public:
    double getCellValue(const SpreadSheetCell& src);
    void processFoosName(const Foo& src);
    static void processFoosNameStatic(const Foo& src);
};




#endif //BAR_H
