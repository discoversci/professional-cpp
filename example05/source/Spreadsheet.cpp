//
// Created by jperme on 3/7/25.
//

#include "Spreadsheet.h"

#include <format>
#include <iostream>
#include <utility>


//star nacin definicije static memberjev - od C++17 se uporablja inline definicija v .h fajlu
// int Spreadsheet::ms_counter = 0;

Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, std::size_t width, std::size_t height) :
    m_width(std::min(width, Spreadsheet::MaxWidth)),    // Vec kot MaxWidth ne sme iti podano, sicer throw Exception
    m_height(std::min(height, Spreadsheet::MaxHeight)), // Vec kot MaxHeight ne sme iti podano, sicer throw Exception
    m_id(Spreadsheet::ms_counter++),
    m_theApp(theApp) {
    std::cout << "Spreadsheet::Spreadsheet constructor called" << std::endl;
    this->m_cells = new SpreadsheetCell*[this->m_width]; // stolpci
    for (size_t i{0}; i<this->m_width; ++i) {
        this->m_cells[i] = new SpreadsheetCell[this->m_height]; // m_cells[i] je pointer na dinamicno rezervirano tabelo SpreadsheetCell objektov
    }

}

// copy ctor
Spreadsheet::Spreadsheet(const Spreadsheet &src) : Spreadsheet{src.m_theApp, src.m_width, src.m_height} { // delegating ctor
    std::cout << "Spreadsheet::Spreadsheet copy constructor called" << std::endl;
    for (size_t i{0}; i<this->m_width; ++i) {
        for (size_t j{0}; j<this->m_height; ++j) {
            this->m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

// move ctor
Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept :
    m_theApp(src.m_theApp) {
    std::cout << "Spreadsheet::Spreadsheet move constructor called" << std::endl;
    this->swap(src);    // src bo neka rvalue vrednost, in ko se izgubi, se poklice njen destructor, ki bo sprostil memory
}


void Spreadsheet::verifyCoordinate(std::size_t x, std::size_t y) const {
    if (!inRange(x, this->m_width))
        throw std::out_of_range{std::format("x = ({}) must be less than ({}).", y, this->m_width)};
    if (!inRange(y, this->m_height))
        throw std::out_of_range{std::format("x = ({}) must be less than ({}).", y, this->m_height)};
}


void Spreadsheet::setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell &cell) {
    this->verifyCoordinate(x,y);
    this->m_cells[x][y] = cell;
}

const SpreadsheetCell& Spreadsheet::getCellAt(std::size_t x, std::size_t y) const {
    this->verifyCoordinate(x,y);
    return this->m_cells[x][y];
}

SpreadsheetCell& Spreadsheet::getCellAt(std::size_t x, std::size_t y){
    // pouporabimo tisto kar ZE obstaja. Kaj pa ZE obstaja ? const verzija te metode.
    return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x,y));
    //std::as_const(*this) - trenutni objekt Spreadsheet spremenimo v const objekt, da lahko klicemo overloadano metodo ki je const
    // s tem .getCellAt(x,y) poklicemo metodo nad const objektom (torej overloadano getCellAt(), ki je const). Nazaj dobimo SpreadsheetCell objekt, ki ne sme bit const
    // s tem const_cast<SpreadsheetCell&> pa odstranimo constness SpreadSheetCell-a
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet &rhs) {
    std::cout << "Spreadsheet copy assignment called" << std::endl;
    Spreadsheet temp{rhs};
    this->swap(temp);   // temp se po vrnitvi te motode izgubi... klice se njegov dtor v katerem se pocisti vse kar je imel temp rezerviranega
    return *this;

    // -----------------------------------------------------------------------------------------------------------
    // spodaj je star pristop, ki se ne priporoca, zaradi stanj ki se lahko dobijo, ko pride do exceptiona na celotni poti
    // -----------------------------------------------------------------------------------------------------------
    // if (this != &rhs) {
    //     return *this;
    // }
    // // bristi tisto kar ima lhs objekt, da mu lahko skopiras notri tisto kar ima rhs
    // // dejasnko moras izbrisat vse, ker so lahko dimenzije razlicne
    // for (size_t i{0}; i<this->m_width; ++i) {
    //     delete[] this->m_cells[i];
    // }
    // delete[] this->m_cells;
    // this->m_cells = nullptr;
    //
    // // kopiraj dimenzije
    // this->m_width = rhs.m_width;
    // this->m_height = rhs.m_height;
    //
    // // alokacija nove memorije v katero bos kopiral rhs podatke
    // this->m_cells = new SpreadsheetCell*[this->m_width];
    // for (size_t i{0}; i<this->m_width; ++i) {
    //     m_cells[i] = new SpreadsheetCell[this->m_height];
    // }
    //
    // // kopiranje iz rhs na lhs
    // for (size_t i{0}; i<this->m_width; ++i) {
    //     for (size_t j{0}; j<this->m_height; ++j) {
    //         this->m_cells[i][j] = rhs.m_cells[i][j];
    //     }
    // }
    // return *this;

}

Spreadsheet& Spreadsheet::operator=(Spreadsheet &&src) noexcept {
    std::cout << "Spreadsheet move assignment operator called" << std::endl;
    auto temp{std::move(src)}; // v temp spravimo src z move semantiko, da se ne klice copy ctor
    this->swap(temp);   // iz temp gre v nas trenutni objekt (ce pride do exceptiona se program konca)
    return *this;   //vracamo reference


    // if (this != &rhs) {
    //     return *this;   //vracamo isti objekt in se ne dela kopija, ko se tole izvede (vracamo referenco in ne objekta)
    // }
    // // nobena izmed spodnjih ne sme vreci exceptiona. Ce ga, se program konca.
    // this->cleanup();    // sprosti memory of lhs
    // moveFrom(rhs);   // prenesi memory is rhs v nas trenutni lhs, ki je klical ta move assignment operator
    // return *this;   // vracamo referenco in ce vrnemo *this, pomeni da vracamo isti objekt in se ne dela kopija
}

void Spreadsheet::swap(Spreadsheet &other) noexcept {

    // bolj optimalno bi bilo: this->m_width = other.m_width; Za primitive se ne izplaca uporabljat swap.
    // kaj pa ce v prihodnosti menjas primitiv za nekaj bolj kompleksnega, npr. class, potem bi moral pa uporabit swap, ki bi bil bolj optimalen
    std::swap(this->m_width, other.m_width);
    std::swap(this->m_height, other.m_height);
    std::swap(this->m_cells, other.m_cells);

}


Spreadsheet::~Spreadsheet() {

    std::cout << "Spreadsheet::~SpreadsheetCell called" << std::endl;

    //pocisti vse, kar je nastavljal ta objekt
    for (size_t i{0}; i<this->m_width; ++i) {
        delete[] this->m_cells[i];
    }
    delete[] this->m_cells;
    this->m_cells = nullptr;
    this->m_width = 0;  // lahko nastavis ali pa ne
    this->m_height = 0; // lahko nastavis ali pa ne

}



bool Spreadsheet::inRange(std::size_t value, std::size_t upper) const {
    return value < upper;
}

void swap(Spreadsheet &first, Spreadsheet &second) noexcept {
    first.swap(second); // first poklice svojo member funkcijo in
}

// void Spreadsheet::moveFrom(Spreadsheet &src) noexcept {
//
//     // podobno kot spodaj: iz src se kpira v memberje tega objekta, nato gre pa v src 0 oz. nullptr, vrne se pa stara vrednost, ki je bila v src
//     // [recej prirocno, ker naredis dvoje naenkrat: vzames src vrednost in jo ponucas, nato pa se resetiras src
//     this->m_width = std::exchange(src.m_width,0);
//     this->m_height = std::exchange(src.m_height,0);
//     this->m_cells = std::exchange(src.m_cells,0);
//
//     // !!! POMEMBNO !!!
//     // Kaj pa ce bi nas objekt Spreadsheet vseboval tudi memberje, ki niso primitivi ? Potem bi morali premakniti iz src taksne memberje s pomocjo
//     // std::move() in ne exchange.
//
//
//     // star nacin, ampak obstaja boljsi std::exchange
//     // // iz src premakni v trenutni objekt
//     // this->m_width = src.m_width;
//     // this->m_height = src.m_height;
//     // this->m_cells = src.m_cells;
//     //
//     // // postavi izvor od koder smo premaknili v neko znano stanje
//     // src.m_width = 0;
//     // src.m_height = 0;
//     // src.m_cells = nullptr;
// }

// void Spreadsheet::cleanup() noexcept {
//     //pocisti vse, kar je nastavljal ta objekt
//     for (size_t i{0}; i<this->m_width; ++i) {
//         delete[] this->m_cells[i];
//     }
//     delete[] this->m_cells;
//     this->m_cells = nullptr;
//     this->m_width = 0;  // lahko nastavis ali pa ne
//     this->m_height = 0; // lahko nastavis ali pa ne
// }
