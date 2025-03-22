//
// Created by jperme on 3/22/25.
//

#ifndef DERIVED2_H
#define DERIVED2_H
#include <Base.h>

class Derived2 : public Base {
public:
    void someFunction() override;
    void someOtherFunction() const; // dodamo virtual, ce bo kdaj se kdo od Derived2 dedoval, da s tem zagotovimo potem dynaimc binding oz. polimorfizem
    virtual ~Derived2() override = default; // za clarity navedemo vse - pomembno je, da je overriden in pa da je v Base nastavljeno kot virtual
protected:
    void doCalculation() const override;
private:
};

#endif //DERIVED2_H
