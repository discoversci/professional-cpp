//
// Created by jperme on 3/22/25.
//

#ifndef DERIVEDDERIVED_H
#define DERIVEDDERIVED_H
#include <Derived1.h>

class DerivedDerived : public Derived1 {
public:
    // ctor - delegating to Derived1 ctor
    DerivedDerived(int m_derived1_private_int1, int m_derived1_private_int2, int m_base1, int m_base2)
        : Derived1(m_derived1_private_int1, m_derived1_private_int2, m_base1, m_base2) { }

    void someOtherFunction() const override final;  // zaradi "final" se funkcije ne more nihce vec overridat - lahko jo deduje, ne more pa je spreminjat

    // v parentu Derived1 je definiran helper() pod scope-om "protected:", tu smo pa sprostili dostop v public - to lahko naredimo,
    // obratno ap NE, ne moremo bolj restriktirat, kot je v parentu. Ne moremo iti v bolj strogo smer, kot je pa strog parent
    void helper() override;
protected:

};

#endif //DERIVEDDERIVED_H
