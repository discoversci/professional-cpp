//
// Created by jperme on 3/7/25.
//

#include "Bar.h"
#include "Foo.h"

double Bar::getCellValue(const SpreadSheetCell& src) {
    return src.m_value; // Access private member
}

void Bar::processFoosName(const Foo& src) {
    std::cout << std::format("Foo's processed name from normal method: {}_the_greatest.", src.name) << "\n";   // dostop do privat memberjev od Foo-ja, ker je Bar friend Foo-ju
}

void Bar::processFoosNameStatic(const Foo &src) {
    std::cout << std::format("Foo's processed name from static function: {}_the_greatest.", src.name) << "\n";   // dostop do privat memberjev od Foo-ja, ker je Bar friend Foo-ju
}
