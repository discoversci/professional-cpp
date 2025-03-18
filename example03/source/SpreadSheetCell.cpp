#include <charconv>
#include <iostream>
#include <SpreadSheetCell.h>

std::string SpreadSheetCell::doubleToString(double value) const {
    return std::to_string(value);
}

double SpreadSheetCell::stringToDouble(std::string_view value) const {
    double number{0};
    std::from_chars(value.data(), value.data() + value.size(), number); // od poinerja value.data() do kolikor je dolg string_view, spremeni to v double stevliko
    return number;  // vrni double
}

// stari nacin ctor
// SpreadSheetCell::SpreadSheetCell(double initialValue) {
//     this->setValue(initialValue);
// }

// novi nacin ctor
SpreadSheetCell::SpreadSheetCell(double initialValue) : m_value{initialValue} {
}

// tule uporabimo kar delegating ctor, ce dobimo string, ga spremenimo v double in klicemo ctor ki polni celico z double
SpreadSheetCell::SpreadSheetCell(std::string_view initialValue) : SpreadSheetCell{stringToDouble(initialValue)} {
    // this->setString(initialValue); // lahko bi takole inicializirali, ampak delegating ctor pride tule prav
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell &src) : m_value {src.m_value} {

}

//tega ne rabimo ce v h fajlu dolocimo = default za constructor
// SpreadSheetCell::SpreadSheetCell() {
//     // brez potrebe da tu kaj specificiramo, ker smo uporabili in-class member initializer
//     // ce pa ze, bi pa lahko takole inicializirali memberja z neko default vrednostjo
//     // this->m_value = 0.0;
// }

SpreadSheetCell::~SpreadSheetCell() {
    std::cout << "SpreadSheetCell::~SpreadSheetCell called" << std::endl;
}

// assignment operator, vrni referenco, da se ne dela po nepotrebnem kopija in klice copy constructor
SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell &rhs) {
    if (this == &rhs) { // ce sta naslova enaka: mora biti &rhs, da dobis naslov objekta, ker primerjas s pointerjem
        return *this;   // vrnes objekt, ampak kot reference - to lahko naredis, ker to ze obstaja in ni kreirano lokalno, da bi bil problem tak, da se po koncu metode objekt izgubi
    }
    m_value = rhs.m_value;
    return *this;
}

void SpreadSheetCell::setValue(double value) {
    this->m_value = value;
}

double SpreadSheetCell::getValue() const {
    return this->m_value; // ali return->this->getValue();
}

void SpreadSheetCell::setString(std::string_view value) {
    this->m_value = this->stringToDouble(value);
}

std::string SpreadSheetCell::getString() const {
    return this->doubleToString(this->m_value);
}

std::shared_ptr<SpreadSheetCell> SpreadSheetCell::getSharedPointerOnYourSelf() {
    return shared_from_this();
}

std::weak_ptr<SpreadSheetCell> SpreadSheetCell::getWeakPointerOnYourSelf() {
    return weak_from_this();
}
