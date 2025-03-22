//
// Created by jperme on 3/22/25.
//

#include "Base.h"

#include <Base.h>
#include <iostream>
#include <ostream>

void Base::someFunction() {
    std::cout << "someFunction() called in Base" << std::endl;
}

int Base::getValue1() const {
    return this->m_basePrivateInt1;
}

int Base::getValue2() const {
    return this->m_basePrivateInt2;
}