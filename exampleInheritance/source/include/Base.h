//
// Created by jperme on 3/22/25.
//

#ifndef BASE_H
#define BASE_H
#include <iostream>


class Base {
public:
    //Base() = default;
    // non trivial ctor
    explicit Base(int a=0, int b=0) : m_basePrivateInt1(a), m_basePrivateInt2(b) {} // toje hrakti tudi default ctor, zato sem zgoraj zakomentiral Base() = default;
    virtual void someFunction(); // virtual zato da dosezemo dynamic binding v run time, ce tega ne bi bilo, se dela binding v rcompile time in je odsvisno od tipa ponterja
    //int m_publicInt{0}   -  TEGA NE DELAMO NIKOLI
    virtual ~Base() = default;  // destructor je lahko prakticno vedno virtual, tudi ce nima nobenih dedovalcev (jih bo pacl alhko imel kdaj)
protected:
    // dobra praksa je, da se tu navede getterje in setterje za derived classe. Ne da imajo derived classi direkt dostop do protected memberjev
    // ti getterji in setterji potem omogocajo dostop do privat variabel base-a. torej vse v private, potem pa dolocis sam, kdo naj ima dostop do teh spremenljivk
    // ce zelis da imajo dostop do funkcij le derived classi, das to v prostected, sicer das v public
    // v protected spadajo predvsem kaksne pomozne funkcije ?
    int m_protectedInt{0};
    virtual void doCalculation() const = 0; // pure virtual function, ki MORA biti overridana

    // protected getters and setters
    [[nodiscard]] int getValue1() const; // pure virtual function, ki MORA biti overridana
    [[nodiscard]] int getValue2() const; // pure virtual function, ki MORA biti overridana

    virtual void helper() {
        std::cout << "Calling helper" << "\n";
    }


private:
    int m_basePrivateInt1{0};
    int m_basePrivateInt2{0};
};




#endif //BASE_H
