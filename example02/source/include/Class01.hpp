//
// Created by jperme on 2/27/25.
//

#ifndef CLASS01_H
#define CLASS01_H

// class Class01 {
//     int& m_ref;
// public:
//     explicit Class01(int& ref) {
//        m_ref = ref; // tole ne inicializira pravilno
//     }
// };
class Class01 {
    int a = 1234;
    int& m_ref;
public:
    explicit Class01(int& ref):m_ref{ref} { // sedaj je pa pravilno
    }
    [[nodiscard]] int readA() const {   // metoda se obveze, da ne bo spreminjala svojih privat memberjev
        return this->a;
    }
};

#endif //CLASS01_H
