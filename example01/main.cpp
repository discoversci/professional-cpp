#include <iostream>
#include <optional>
#include <TestingClass.h>
#include "Enumclass.h"
#include <array>


int getValue() {
    return 5;
}

int main() {
    std::pair<int, double> my_pair{112, 12.12};
    std::cout << my_pair.first << " " << my_pair.second << "\n";

    std::optional<std::string> my_optional;
    my_optional = "hello world value to Optional variable";
    std::cout << "Optionals out: \n";
    if (my_optional.has_value()) {
        std::cout << "Optional with no star: " << my_optional.value() << "\n";

        // my_optional ima njabrz definiran dereference operator in vrne objekt ki je hranjen v optional objektu
        std::cout << "Optional with star: " << *my_optional << "\n";
    }

    // Operacija nima veze z optional objektom, ampak tistemu objektu ki ga optional hrani. V tem primeru hrani string objekt in do njega dostopas preko pointerja
    // zato dereference -> operator in prides do vsebine, ki je v tem primeru string vsebina
    my_optional->append("dodatek");

    my_optional.reset();    // postavi optional value na empty
    try {
        std::cout << my_optional.value() << "\n";
    } catch (std::bad_optional_access &e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }

    [[maybe_unused]] int cc;

    std::cout << "Hello, World!" << std::endl;
    LevelOneNamespace::LevelTwoNamespace::TestingClass a{1};
    std::cout << a.get_i() << std::endl;

    // ali tudi takole
    // auto state{LevelOneNamespace::LevelTwoNamespace::EnumClass::High};
    LevelOneNamespace::LevelTwoNamespace::EnumClass state{LevelOneNamespace::LevelTwoNamespace::EnumClass::Unknown};
    switch(state) {
        case LevelOneNamespace::LevelTwoNamespace::EnumClass::High: {
            std::cout << "High!" << std::endl;
            break;
        }
        case LevelOneNamespace::LevelTwoNamespace::EnumClass::Medium:
            std::cout << "Medium!" << std::endl;
        case LevelOneNamespace::LevelTwoNamespace::EnumClass::Low:
        case LevelOneNamespace::LevelTwoNamespace::EnumClass::Unknown:
        default:
            std::cout << "Unknown!" << std::endl;
    }

    std::cout << static_cast<int>(state) << std::endl;

    std::array<int, 5> values{1,2,3,4,5};

    // structured bindings iz arraya
    auto [a1,a2,a3,a4,a5]{values};  // kle so posamezne variable pac navadne variable
    std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << "\n";

    // structured bindings iz arraya
    auto& [b1,b2,b3,b4,b5]{values}; // kle so posamezne variable pa reference

    // structured bindings iz arraya
    const auto& [c1,c2,c3,c4,c5]{values}; // kle so posamezne variable pa const reference


    struct Point2d{
        int x;
        int y;
    } constexpr point1{101,102,}, point2{201,202,};
    std::cout << point1.x << " " << point1.y << "\n";
    std::cout << point2.x << " " << point2.y << "\n";
    struct Point2d point3{401,402,};
    std::cout << point3.x << " " << point3.y << "\n";

    typedef struct Point3d_t_def {
        int x;
        int y;
        int z;
    } Point3d_t;
    Point3d_t point3d{505,506,507,};
    std::cout << point3d.x << " " << point3d.y << " " << point3d.z << "\n";

    // structured bindings iz strukture
    auto [x1,y1,z1] = point3d;
    std::cout << x1 << " " << y1 << " " << z1 << "\n";

    std::cout << ::getValue() << "/n";  // demonstiramo jemanje iz globalnega namespace-a




















    return 0;
}
