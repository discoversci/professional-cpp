//
// Created by jperme on 3/7/25.
//

#ifndef FOO_H
#define FOO_H
#include <string>
#include "Bar.h"

class Bar;
class Foo {
private:
    std::string name;

public:
    Foo(std::string_view name) : name(name) {}

    friend void Bar::processFoosName(const Foo&);
    friend void Bar::processFoosNameStatic(const Foo&);  // staticna funkcija friend
    friend void processFoosNameStaticGlobal(const Foo& src);
};
#endif //FOO_H
