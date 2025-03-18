#include <charconv>
#include <iostream>
#include <SpreadSheetCell.h>

std::string SpreadsheetCell::doubleToString(double value) {
    return std::to_string(value);
}

double SpreadsheetCell::stringToDouble(std::string_view value) {
    double number{0};
    std::from_chars(value.data(), value.data() + value.size(), number); // od poinerja value.data() do kolikor je dolg string_view, spremeni to v double stevliko
    return number;  // vrni double
}

// stari nacin ctor
// SpreadsheetCell::SpreadsheetCell(double initialValue) {
//     this->set(initialValue);
// }

// novi nacin ctor
SpreadsheetCell::SpreadsheetCell(double initialValue) : m_value{initialValue} {
}

// tule uporabimo kar delegating ctor, ce dobimo string, ga spremenimo v double in klicemo ctor ki polni celico z double
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue) : SpreadsheetCell{stringToDouble(initialValue)} {
    // this->set(initialValue); // lahko bi takole inicializirali, ampak delegating ctor pride tule prav
}

// copy ctor
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src) : m_value {src.m_value} {

}

//tega ne rabimo ce v h fajlu dolocimo = default za constructor
// SpreadsheetCell::SpreadsheetCell() {
//     // brez potrebe da tu kaj specificiramo, ker smo uporabili in-class member initializer
//     // ce pa ze, bi pa lahko takole inicializirali memberja z neko default vrednostjo
//     // this->m_value = 0.0;
// }

SpreadsheetCell::~SpreadsheetCell() {
    //std::cout << "SpreadsheetCell::~SpreadsheetCell called" << std::endl;
}

// assignment operator, vrni referenco, da se ne dela po nepotrebnem kopija in klice copy constructor
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if (this == &rhs) { // ce sta naslova enaka: mora biti &rhs, da dobis naslov objekta, ker primerjas s pointerjem
        return *this;   // vrnes objekt, ampak kot reference - to lahko naredis, ker to ze obstaja in ni kreirano lokalno, da bi bil problem tak, da se po koncu metode objekt izgubi
    }
    m_value = rhs.m_value;
    return *this;
}

void SpreadsheetCell::set(double value) {
    this->m_value = value;
}

double SpreadsheetCell::getValue() const {
    ++this->m_numOfAccesses;    //povecamo stevec dostopov
    return this->m_value; // ali return->this->getValue();
}

void SpreadsheetCell::set(std::string_view value) {
    this->m_value = this->stringToDouble(value);
}

std::string SpreadsheetCell::getString() const {
    ++this->m_numOfAccesses;    // povecamo stevec dostopov
    return this->doubleToString(this->m_value);
}

std::shared_ptr<SpreadsheetCell> SpreadsheetCell::getSharedPointerOnYourSelf() {
    return shared_from_this();
}

std::weak_ptr<SpreadsheetCell> SpreadsheetCell::getWeakPointerOnYourSelf() {
    return weak_from_this();
}

const std::string & SpreadsheetCell::getDescription() const & {
    return this->m_description;
}

std::string&& SpreadsheetCell::getDescription() && {
    return std::move(m_description);    // tu lahko moveamo ker se bo zacasni objekt itak unicil in lahko naredimo move
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
    return SpreadsheetCell{this->m_value + cell.m_value};
}


