//
// Created by jperme on 3/7/25.
//

#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <cstddef>
#include <SpreadSheetCell.h>

#include "SpreadsheetApplication.h"


class Spreadsheet {

public:
    // stataic stuff
    [[nodiscard]] std::size_t getId() const;
    static constexpr std::size_t MaxHeight{100};
    static constexpr std::size_t MaxWidth{100};

    // ctors
    // ker imas spodnji constructor default parametre, compiler ne bozmozen razlikovati med tem in default construcotjrem, torej se ta obravnava kot default ctor
    explicit Spreadsheet(const SpreadsheetApplication& theApp, std::size_t width=Spreadsheet::MaxWidth, std::size_t height=Spreadsheet::MaxHeight); // default parameters se navede samo v .h fajlu (oz modulu). tu uporabimo satic constexpress definicije
    Spreadsheet(const Spreadsheet& src);
    // dctor
    ~Spreadsheet(); // nikoli ne sme metat Exceptiona

    // move constructor
    Spreadsheet(Spreadsheet&& src) noexcept;

    // mutators
    void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);

    // accessors - pazi spodaj PROBLEM. Ce ne bi bil definiran tudi overload, potem bi lahko tole metodo klical samo nad const objekti, ne pa tudi non const objekti
    // zato uporabimo Scott Meyers pattern in definiramo se non const verzijo metode
    const SpreadsheetCell& getCellAt(std::size_t x, std::size_t y) const;
    SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);

    // operators
    Spreadsheet& operator=(const Spreadsheet& src);

    // move assignment operator
    Spreadsheet& operator=(Spreadsheet&& src) noexcept;

    //namen swap je, da pride do izmenjave vseh memberjev ali pa nicesar - ne moremo polovico prevekslati, pol pa ne. Ce pride do exceptiona, potem se program prekine v celoti.
    // obvezemo se, da ne bomo vrgli exceptiona v tej metodi (ce pa pride do tega, pa program konca, oz. MORA program koncati, ker je prislo do stanja ki ga ne zelimo)
    void swap(Spreadsheet& other) noexcept; // lahko pride const na koncu funckije in potem noexcept, ne obratno.

    // v bistvu niti ne rabimo, ker smo realizirali move ctor in move assignemnt operator s pomocjo swap, prej smo pa ti dve funkciji upoarbljali
    // void moveFrom(Spreadsheet & src) noexcept;  // src bomo spreminajli, zato ne sme biti const
    // void cleanup() noexcept;


    // ce ne dovolis kopij, enostavno disableas copy consktructor in assignment operator takole:
    // Spreadsheet(const Spreadsheet& rhs) = delete;
    // Spreadsheet& operator=(Spreadsheet&& other) = delete;


private:
    //static stuff
    static inline int ms_counter{0};   // novi nacin: definiras in deklariras hkrati v .h fajlu, sicer bi moral tu deklarirat, v .cpp pa definirat in rezervirat prostor (stari nacin)
                                        // kaj pomeni ms_ ? "m" kot member, "s" pa kot static
    std::size_t m_width{0};
    std::size_t m_height{0};
    const std::size_t m_id{0};

    // relations with other objects/parents
    // tule sicer uporabljamo pristop ki ni najbolj posrecen - za taksne stvari raje uporabljajmo Model View Controller pattern, ampak za demonstrativne namene, je OK
    // zakaj referenca in ne pointer na tistega, ki owna ta Spreadsheet ? Ker, referenca zagotavlja da vedno "kaze" na Spreadsheet Application, pointer pa tega ne zagotavlja, saj lahko kaze tudi na kaj drugega
    // nastavit jo moras pa vedno, ker ne more obstajati, brez da nekam referencira oz. inicializirat jo moras, lahko v initializer listi, ce je ne, compiler ne bo spustil cez prevajanje
    // enkrat ko jo inicializiras, je ne mores vec srepmeniti da referencira nekam drugam
    // vedno pazi da to referenco nastavis tudi v delegating constructorju - ko delas copy consturctor (pri move ctor tega ne rabis)
    const SpreadsheetApplication& m_theApp;

    SpreadsheetCell** m_cells{nullptr};
    [[nodiscard]] bool inRange(std::size_t value, std::size_t upper) const;
    void verifyCoordinate(std::size_t x, std::size_t y) const;


};

// to pa navedemo, da lahko ta swap, za ta class, uporabijo tudi zunanji klienti, ki niti ne rabijo kreirat objektov Spreadsheet
// naloga tega je enostavna: posreduj klic swap na objekte ki imajo definiran ta swap
void swap (Spreadsheet& first, Spreadsheet& second) noexcept;

#endif //SPREADSHEET_H
