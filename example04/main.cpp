#include <iostream>
#include <string>
#include <format>
#include <numbers>
#include <iostream>
#include <string>
#include <format>
#include <memory>
#include <SpreadsheetCell.h>
#include <Spreadsheet.h>
#include <DataHolder.h>
#include <Operators.h>


using namespace std::literals; // tole rabimo, ce zelimo uporabljati famozni "s" na koncu stringa, da forsiramo da se iz literala res kreira std::string tip in ne char *
SpreadsheetApplication app;
Spreadsheet createObject() {
    return Spreadsheet{app,3,3};
}

int main() {

    // reference primeri
    // int &i{2};  // ne gre, ker referencane more kazat na rvalue
    const int& ref{3}; // const referenca ne more spremenit nicesar, zato lahko kaze na rvalue

    int a{3}, b{3};
    // int j&{a+b}; // ne gre, ker referenca ne more kazat na temp rvalue vrednost

    int &&r_ref{2};     // dovoljeno, rvalue referenca r_ref kaze na rvalue
    int &&r_a_sum{a+b}; // dovoljeno, ker rvalue referenca kaze na temp rvalue vrednost


    SpreadsheetCell myCell, anotherCell;
    myCell.set(6.0);
    anotherCell.set("3.2");
    std::cout << "myCell: " << myCell.getValue() << "\n";
    std::cout << "anotherCell: " << anotherCell.getValue() << "\n";
    std::cout << "anotherCell: " << anotherCell.getString() << "\n";

    // uporaba operatorja ->
    SpreadsheetCell *myCellp{new SpreadsheetCell{4.4}};
    myCell.set(3.7);
    std::cout << "myCell: " << myCell.getValue() << " " << myCell.getString() << "\n";
    delete myCellp;
    myCellp = nullptr;

    // uporaba zvezdice in pike
    SpreadsheetCell *myCellp_raw{new SpreadsheetCell{8.8}};
    (*myCellp_raw).set(3.7);
    std::cout << "myCell: " << (*myCellp_raw).getValue() << " " << (*myCellp_raw).getString() << "\n";
    delete myCellp_raw;
    myCellp_raw = nullptr;

    // se najbolje pa uporaba smart pointerjev
    std::unique_ptr<SpreadsheetCell> cell_smart{std::make_unique<SpreadsheetCell>(10.10)};
    cell_smart->set(3.7);
    std::cout << "cell_smart: " << cell_smart->getValue() << " " << cell_smart->getString() << "\n";

    // most vexing parse :)
    // SpreadsheetCell doNotUseVexingCell();   // tole se tretira kot funkcijo in ne kot ddefinicijo nove celice in klic constructorja

    SpreadsheetCell allowedNonVexingCell1{}; // tu pa SE klice default constructor
    SpreadsheetCell allowedNonVexingCell2{0.0}; // tu pa SE klice constructor ki prejme double

    auto smartCell1 {std::make_unique<SpreadsheetCell>()};  // klic default constructor
    SpreadsheetCell* smartCell2 {new SpreadsheetCell{}};  // klic default constructor

    // klic copy sctor
    SpreadsheetCell aCopy{myCell};
    std::cout << "myCell: " << aCopy.getValue() << "\n";

    // aCopy = 5.5; // tule bi se delala implicitna konverzija. Ker pa je ctor definiran kot explicit, se to ne naredi (lahko bi pravzaprav klicali tudi // aCopy = 5;, pa bi sel 5 najprej v double potem pa implicitno v SpreadsheetCell)
    // std::cout << "myCell: " << aCopy.getValue() << "\n";

    Spreadsheet ss1{app,2,2};
    ss1.setCellAt(0,0,myCell);
    Spreadsheet ss2{ss1};
    std::cout << ss2.getCellAt(0,0).getValue() << "\n";

    Spreadsheet original{app,2,2};  // constructor se klice
    Spreadsheet new_one1 = Spreadsheet{app,3,3}; // zaradi RVO (return value optimization) se klice navadni constructor in ne copy constructor
    Spreadsheet new_one2(app,3,3);
    new_one2 = new_one1;
    new_one2 = std::move(new_one1);

    Spreadsheet new_one4 = std::move(Spreadsheet{app,4,4}); // klice se move constructor
    std::cout << new_one4.getCellAt(3,3).getValue() << std::endl;

    Spreadsheet s33_1 = createObject(); // klice se le constructor, ker se uporabi RVO in ne copy constructor za temp objekt, ki se vraca, niti move ctor
    Spreadsheet s33_2{app,3,3};
    s33_2 = createObject();

    SpreadsheetCell cell1(2.75);
    SpreadsheetCell cell2(4.75);
    SpreadsheetCell cell3 = cell1 + cell2;
    std::cout << "sum = cell3 = " << cell3.getValue() << "\n";

    SpreadsheetCell cell4 = cell1 * cell2;
    std::cout << "mult = cell4 = " << cell4.getValue() << "\n";

    // SpreadsheetCell cell4 = 3 + cell2; // rabili bi bodisi globalni operator+ in converting ctor, da 3 spremeni v objekt SpreadsheetCell avtomatsko
                                          // ali pa globalni operator, ki prejme za prvi argument int, drugi pa SpreadsheetCell objekt. Tako operator deluje pac.

//    demo za data holder da pocekiramo kako in kdaj pride do uporabe klica ene ali druge metode
    std::cout << "DataHolder demo" << "\n";
    DataHolder wrapper;
    std::vector myData{11,22,33};
    wrapper.setData(myData);        // klic l-value reference
    wrapper.setData({1,2,3,4});     // klic r-value reference

    return 0;
}




