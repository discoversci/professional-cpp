//
// Created by jperme on 2/27/25.
//

#ifndef DERIVED1_H
#define DERIVED1_H
#include "Base.h"

class Derived1 : public Base {
public:
    Derived1(int m_derived1_private_int1, int m_derived1_private_int2, int m_base1, int m_base2)
        : Base(m_base1, m_base2),
          m_derived1PrivateInt1(m_derived1_private_int1),
          m_derived1PrivateInt2(m_derived1_private_int2)
    {
    }

    void someFunction() override;
    virtual void someOtherFunction() const;  // dodamo virtual, ce bo kdaj se kdo od Derived1 dedoval, da s tem zagotovimo potem dynaimc binding oz. polimorfizem
    void getAllValues() const;

    virtual ~Derived1() override = default; // za clarity navedemo vse - pomembno je, da je overriden in pa da je v Base nastavljeno kot virtual
protected:
    void doCalculation() const override;

    // dobra praksa je, da vedno das tudi getters in setters med protected, tako da jih uporabljajo samo dedujoci classi in ne expterni, ki tega ne potrebujejo
    // externi morajo imeti le uporabne API za njih
    [[nodiscard]] int getDerivedValue1() const;
    [[nodiscard]] int getDerivedValue2() const;
private:
    int m_derived1PrivateInt1{0};
    int m_derived1PrivateInt2{0};
};


#endif
