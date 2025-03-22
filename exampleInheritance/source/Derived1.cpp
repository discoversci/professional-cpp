//
// Created by jperme on 2/27/25.
//

#include "Derived1.h"

#include <format>
#include <iostream>
#include <ostream>

void Derived1::someOtherFunction() const {
    // lahko dostopamo do protected in public memberjev
    std::cout << "Accessing public and protected memebers in Derived1: " << this->m_protectedInt << "\n";
}

void Derived1::getAllValues() const {
    std::cout << std::format("Values are: {}-{}-{}-{}\n", this->getDerivedValue1(), this->getDerivedValue2(), this->getValue1(), this->getValue2());
}

void Derived1::someFunction() {
    std::cout << "someFunction() called in Derived1" << "\n";
    this->doCalculation();
}

void Derived1::doCalculation() const {
    std::cout << "doCalculation() called in Derived1" << "\n";
}

int Derived1::getDerivedValue1() const {
    return this->m_derived1PrivateInt1;
}
int Derived1::getDerivedValue2() const {
    return this->m_derived1PrivateInt2;
}
