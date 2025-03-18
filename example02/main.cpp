#include <iostream>
#include <Class01.hpp>

consteval double inchToMm(double inch) {
    return inch * 2.54;
}

constexpr double const_inch1{6.0};
constexpr double mm1{inchToMm(const_inch1)};

constexpr double const_inch2{6.0};
double mm2{inchToMm(const_inch2)};  // tu javi compiler error

int main() {

    int x=321; int y=4;
    std::cout << x << std::endl;
    int &rx{x}; int &ry{y};
    std::cout << "Pred:" << rx << " " << ry << std::endl;
    rx=ry;
    std::cout << "Potem:" << rx << " " << ry << std::endl;
    std::cout << "Potem izvorne vrednosti:" << rx << " " << ry << std::endl;

    int z_var=5; int y_var{10};
    const int& general_reference{z_var};
    std::cout << "general_reference pred: " << general_reference << std::endl;
    z_var=6;
    std::cout << "general_reference po: " << general_reference << std::endl;
    // general_reference = y_var; // Enkrat ko je referenca bounded na variablo, ne more vec referencirat nobene druge variable. Drugace je pri parametrih metod/funkcij.
                                  // Tam se bounda ob klicu metode/funkcije in sprosti ob koncu metode/funkcije.

    std::cout << "Hello World!\n";

    int temp1 = 3;
    Class01 my_class{temp1};
    // Class01 my_class{temp}; // ce bi zeleli pa tak klic, bi morala biti definicija constructorja pa taka: explicit Class01(const int& ref):m_ref{ref} {}


    int variabla1 = 505;
    int *p1 = &variabla1;
    std::cout << *p1 << std::endl;  // 505
    variabla1 = 101;
    std::cout << *p1 << std::endl;  // 101
    *p1 = 505;
    std::cout << variabla1 << std::endl; //505

    int variabla2 = 101;
    const int* p2 = &variabla2;
    std::cout << *p2 << std::endl;
    // *p2 = 505;   // tega ne moreom narediti, ker je vrednost na katero kaze p2 za pointer konstantna in se je obvezal, da je ne bo spremenil
    p2 = &variabla1;    // p2 kaze na druo spremenljivko, ki jo tudi obravnava kot konstanto

    const int* const p3 = &variabla2;
    // p3 = &variabla1; // ne gre, ker je sam pointer konstanten in ga ne moremo spremenit tako, da kaze na drugo spremeljivko. Podobno delovanje kot referenca
                        // enkrat ko ji definiras kam kaze, je ne mores vec spremenit

    //pa se ena varianta: naslo reference je kaj ? Pointer na vrednost. Npr.
    int vrednost = 17;
    int &referenca_int = vrednost;
    int *pointer_to_reference = &referenca_int;
    std::cout << "Pointer na referenco: " << *pointer_to_reference << std::endl;


    std::cout << my_class.readA();


















    return 0;
}
