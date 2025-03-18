#include <iostream>
#include <string>
#include <format>
#include <numbers>
#include <iostream>
#include <string>
#include <format>
#include <memory>
#include <SpreadSheetCell.h>
#include <Bar.h>
#include <Foo.h>

using namespace std::literals; // tole rabimo, ce zelimo uporabljati famozni "s" na koncu stringa, da forsiramo da se iz literala res kreira std::string tip in ne char *


void processFoosNameStaticGlobal(const Foo& src) {
    std::cout << std::format("Foo's processed name from global function: {}_the_greatest.", src.name) << "\n";   // dostop do privat memberjev od Foo-ja, ker je Bar friend Foo-ju
}

int main() {
    std::cout << "Hello World!\n";


    std::string first_name = "Marko";
    std::string second_name = "Potocnik";
    auto cmpr_result = first_name <=> second_name;

    if (std::is_lt(cmpr_result)) {
        std::cout << first_name << " is less than " << second_name << '\n';
    } else if (std::is_gt(cmpr_result)) {
        std::cout << first_name << " is greater than " << second_name << '\n';
    } else if (std::is_eq(cmpr_result)) {
        std::cout << first_name << " is equal to " << second_name << '\n';
    }

    std::cout << "Classical way of char* output: " << first_name.c_str() << "\n";

    auto position_of_substring = second_name.find("toc");
    std::cout << "position_of_substring: " << position_of_substring << "\n";
    auto position_of_nonexistent_substring = second_name.find("kaka");
    std::cout << "position_of_nonexistent_substring: " << position_of_nonexistent_substring << "\n"; // ce kaj ne obstaja dobimo zelo veliko stevilko v obliki string::npos

    std::string str_variable = R"(Kekec \n Lekec)"s;
    std::cout << "str_variable: " << str_variable << "\n";

    std::cout << std::format("I read {} day for {} hours. \n", "every", 3);

    std::cout << std::format("My favorite numbers are {} and {}.\n", std::numbers::pi, std::numbers::e);
    std::cout << std::format("My favorite numbers are contra {1} and {0}.\n", std::numbers::pi, std::numbers::e);

    std::cout << (std::format("My favorite numbers are contra {1} and {0}.\n", std::numbers::pi, std::numbers::e));

    auto ptr1{std::make_shared<SpreadSheetCell>()}; // kreiramo objekt in pointer na njega
    // zdaj zelimo pa se do drugega shareane-ga pointerja priti, ampak preko metode ki jo ima objekt sam
    auto ptr2{ptr1->getSharedPointerOnYourSelf()};  // ko se klice se pravilno nastavi counter
    std::cout << "ptr1.use_count(): " << ptr1.use_count() << " ptr2.use_count(): " << ptr2.use_count() << "\n";

    auto ptr3{ptr1};  // ko se klice se pravilno nastavi counter
    std::cout << "ptr1.use_count(): " << ptr1.use_count() << " ptr2.use_count(): " << ptr2.use_count() << " ptr3.use_count(): " << ptr3.use_count() << "\n";

    ptr3.reset();
    std::cout << "ptr1.use_count(): " << ptr1.use_count() << " ptr2.use_count(): " << ptr2.use_count() << " ptr3.use_count(): " << ptr3.use_count() << "\n";


    SpreadSheetCell myCell, anotherCell;
    myCell.setValue(6);
    anotherCell.setString("3.2");
    std::cout << "myCell: " << myCell.getValue() << "\n";
    std::cout << "anotherCell: " << anotherCell.getValue() << "\n";
    std::cout << "anotherCell: " << anotherCell.getString() << "\n";

    // uporaba operatorja ->
    SpreadSheetCell *myCellp{new SpreadSheetCell{4.4}};
    myCell.setValue(3.7);
    std::cout << "myCell: " << myCell.getValue() << " " << myCell.getString() << "\n";
    delete myCellp;
    myCellp = nullptr;

    // uporaba zvezdice in pike
    SpreadSheetCell *myCellp_raw{new SpreadSheetCell{8.8}};
    (*myCellp_raw).setValue(3.7);
    std::cout << "myCell: " << (*myCellp_raw).getValue() << " " << (*myCellp_raw).getString() << "\n";
    delete myCellp_raw;
    myCellp_raw = nullptr;

    // se najbolje pa uporaba smart pointerjev
    std::unique_ptr<SpreadSheetCell> cell_smart{std::make_unique<SpreadSheetCell>(10.10)};
    cell_smart->setValue(3.7);
    std::cout << "cell_smart: " << cell_smart->getValue() << " " << cell_smart->getString() << "\n";

    // most vexing parse :)
    // SpreadSheetCell doNotUseVexingCell();   // tole se tretira kot funkcijo in ne kot ddefinicijo nove celice in klic constructorja

    SpreadSheetCell allowedNonVexingCell1{}; // tu pa SE klice default constructor
    SpreadSheetCell allowedNonVexingCell2{0.0}; // tu pa SE klice constructor ki prejme double

    auto smartCell1 {std::make_unique<SpreadSheetCell>()};  // klic default constructor
    SpreadSheetCell* smartCell2 {new SpreadSheetCell{}};  // klic default constructor

    // klic copy sctor
    SpreadSheetCell aCopy{myCell};
    std::cout << "myCell: " << aCopy.getValue() << "\n";

    // aCopy = 5.5; // tule bi se delala implicitna konverzija. Ker pa je ctor definiran kot explicit, se to ne naredi (lahko bi pravzaprav klicali tudi // aCopy = 5;, pa bi sel 5 najprej v double potem pa implicitno v SpreadsheetCell)
    // std::cout << "myCell: " << aCopy.getValue() << "\n";

    // demonstracija FRIEND funkcij, metod, classov
    Bar myBar;
    std::cout << "myCell via myBar: " << myBar.getCellValue(aCopy) << "\n"; // poklices myBar metodo, ki dostopa direktno do privat memberjev /spreadsheeCell objekta, ker mu je friend
    Foo ramzas{"Ramzas"};
    myBar.processFoosName(ramzas);      // ta metoda v Bar dostopa do private memberjev Foo-ja
    Bar::processFoosNameStatic(ramzas); // ta STATICNA metoda v Bar dostopa do private memberjev Foo-ja (podobno kot bi neka globalna funckcija, le da je definirana znotraj class-a kot staticna)
    processFoosNameStaticGlobal(ramzas);// ta GLOBALNA metoda, definirana v tem fajlu  dostopa do private memberjev Foo-ja


    return 0;
}
