//
// Created by jperme on 3/22/25.
//

#include "Derived2.h"
#include <iostream>

void Derived2::someOtherFunction() const {
    // lahko dostopamo do protected in public memberjev
    std::cout << "Accessing public and protected memebers in Derived2: " << this->m_protectedInt << "\n";
}

void Derived2::someFunction() {
    std::cout << "someFunction() called in Derived2" << "\n";

    // klici se Base verzijo te iste member funkcije - npr. da bi rabil narediti override, ampak ti Base verzija tudi lahko anredi nekaj uporabnega in jo zelis pouporabiti
    Base::someFunction();   // ne smes pa misliti, da klic someFunction() povzroci klic Base verzije - resolve se dela najprej lokalno v funkciji, potem gre na nivo class-a

    this->doCalculation();
}

void Derived2::doCalculation() const {
    std::cout << "doCalculation() called in Derived2" << "\n";
}
