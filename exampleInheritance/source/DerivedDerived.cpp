//
// Created by jperme on 3/22/25.
//

#include <DerivedDerived.h>
#include <iostream>


void DerivedDerived::someOtherFunction() const {
    // lahko dostopamo do protected in public memberjev
    std::cout << "Running FINAL DerivedDerived someOtherFunction()" << "\n";
}

void DerivedDerived::helper() {
    std::cout << "Calling helper in DerivedDerived AND... ";
    Derived1::helper();
    std::cout << "Done!\n";
}


