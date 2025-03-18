//
// Created by jperme on 2/27/25.
//

#ifndef TESTINGCLASS_H
#define TESTINGCLASS_H
#include <iostream>
#include <ostream>

namespace LevelOneNamespace::LevelTwoNamespace {
    class TestingClass {
    private:
        int i;

    public:
        explicit TestingClass(int i)
            : i(i) {
            std::cout << "TestingClass::TestingClass(int i)" << std::endl;
        }
        [[nodiscard]] int get_i() const;
    };
}

#endif //TESTINGCLASS_H
