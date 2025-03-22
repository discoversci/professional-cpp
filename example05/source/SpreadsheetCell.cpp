    #include <charconv>
    #include <iostream>
    #include <SpreadsheetCell.h>
    #include <cmath>

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

    // implementacija implicitnega operatorja - trenutno implementiran globalni operator, ki prejme dva objekta SpreadsheetCell ampak lahko bi bil pa tudi takole implementiran.
    // SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
    //     return SpreadsheetCell{this->m_value + cell.m_value};
    // }

    // SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
    SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell &rhs) {
        this->set(this->getValue() + rhs.getValue());
        return *this;
    }

    // overloading za splosno primerjavo med objekti
    bool SpreadsheetCell::operator==(const SpreadsheetCell& rhs) const {
         return (std::fabs(this->getValue() - rhs.getValue())) < 0.000000001;
    }

    std::partial_ordering SpreadsheetCell::operator<=>(const SpreadsheetCell& rhs) const {
         return this->getValue() <=> rhs.getValue();
    }

    // overloading za primerjao specificno med objektom in double vrednostjo
    // lahko ne navedemo teh operatorjev, vendar se bo potem uporabil converting constructor in double spremenil v objekt SpreadsheetCell, ampak s tem nastane pa kopija
    // pri teh fukncijah se pa ne uporabi convetring ctor in se s tem ne kreira kopija, ampak se primerjava naredi direktno z double vrednostjo - prihranimo na kreiranju objekta
    bool SpreadsheetCell::operator==(double rhs) const {
        return (std::fabs(getValue() - rhs)) < 0.000000001;
    }

    std::partial_ordering SpreadsheetCell::operator<=>(double rhs) const {
        return this->getValue() <=> rhs;
    }