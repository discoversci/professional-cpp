#include <iostream>
#include <Derived1.h>
#include <Derived2.h>
#include <DerivedDerived.h>
#include <memory>

int main() {

    std::cout << "---------- 1 ------------------------" << "\n";
    Derived1 myDerived(1,2,3,4);
    myDerived.someFunction();   // podedovana memeber funkcija od Base
    myDerived.someOtherFunction();  //native memeber funkcija o Derived
    Base* base{ new Derived1{1,2,3,4}};
    base->someFunction();
    // base->someOtherFunction();   // tole ne gre, ker Base nima pojma, kaj ima Derived se definirano

    // uporaba z smart pointerji
    std::unique_ptr<Base> base_smart{std::make_unique<Derived1>(myDerived)};

    std::cout << "---------- 2 ------------------------" << "\n";

    // Base myBase; //tega ne moremo narediti, ker ima Base vsaj eno pure virtual function
    // myBase.someFunction();

    Derived1 myDerived1(1,2,3,4);
    myDerived1.someFunction();
    myDerived1.getAllValues();

    Derived2 myDerived2;
    myDerived2.someFunction();

    Base& base_reference1{myDerived1};  // base reference na derived class - polimorfizem se lahko uporabi, ker je member funkcija virtual
    base_reference1.someFunction();
    // base_reference1.someOtherFunction(); // ne mores klicat, ker base referenca nima pojma o member funkcijah v Derived1

    Base& base_reference2{myDerived2};  // base reference na derived class - polimorfizem se lahko uporabi, ker je member funkcija virtual
    base_reference2.someFunction();

    DerivedDerived derivedDerived{1,2,3,4};
    derivedDerived.helper();



    std::cout << "--------- End! --------------- \n";
    return 0;
}
