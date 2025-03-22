#ifndef SMARTTHISPOINTER_H
#define SMARTTHISPOINTER_H
#include <memory>
#include <string>
#include <string_view>


class SpreadsheetCell : public std::enable_shared_from_this<SpreadsheetCell> {

public:
    // enumerations
    enum class Color {Red=1, Green, Blue, Yellow};  //
    void setColor(Color color);
    [[nodiscard]] Color getColor() const;

    // navadni ctor
    // explicit zato, da preprecimo implicitne konverzije iz double direkt v SpreadsheetCell temp object, pa potem uporaba assignment operatorja, da se naredi myCell = "5"sv;
    explicit SpreadsheetCell(double initialValue);

    // explicit zato, da preprecimo implicitne konverzije iz string_view direkt v SpreadsheetCell temp object, pa potem uporaba assignment operatorja, da se naredi myCell = "5"sv;
    explicit SpreadsheetCell(std::string_view initialValue);
    // SpreadSheetCell(std::initializer_list<double> values);   // tu lahko sprejmemo initializer listo in jo uporabimo za inicializacijo, ampak nimamo kle take potrebe po temu
                                                             // values.size() je dolzina liste, drugas se palahko sprehodis po vrednostih s const referenco v loopu in jih uporabis


    // copy ctor - ce tega ne definiramo, nam compiler avtomatsko generira svojega. Pri tem se skopira vse memberje podanega parametra (src) v memberje novo kreiranega  objekta.
    // ce so memberji class-a objekti, potem se za vsakega od teh klice copy ctor in v njih podajo notri korespondencni parametri iz src member objektov
    // posebno tam kjer se uporabljajo pointerji, pa je potrebno definirati copy construcotr posebej rocno in premisljeno.
    SpreadsheetCell(const SpreadsheetCell& src);
    // v tem primeru, kjer lahko uporabimo kar default ctor in nam ga sploh ni treba definirat, bi lahko naredili tudi takole:
    // SpreadsheetCell(const SpreadsheetCell& src) = default;
    // ali ce ne rabimo copy ctor, ker ne zelimo da se objekt kopira (npr unique_ptr imajo to, ker dajejo izkljucno samo enemu objektu pravico dostopa in ne pustijo kopirat),
    // potem takole: SpreadsheetCell(const SpreadsheetCell& src) = delete;

    // default ctor; to pove da ga zelimo vseeno imeti; ker cim definiras drug ctor, ki ni default, se default ne generira vec avtomatsko
    SpreadsheetCell() = default;

    ~SpreadsheetCell();

    // tole pa uporabimo ko ne potrebujemo default ctor, npr. classi s staicnimi memberji. Tam ne poterbujemo default ctor.
    // mimogrede, ce bi imel ta class neke memberje, ki bi imeli ze sami po sebi deleted constructor, potem bi avtomatsko tudi ta class imel deleted constructor
    // SpreadSheetCell() = delete;


    // assignment operator
    SpreadsheetCell& operator=(const SpreadsheetCell& rhs); // rhs je lahko const referenca, ker se bo samo bralo iz njega, vrnit pa moramo referenco
    // lahko ga damo pa tudi v default ali pa delete, ce ga ne potrebujemo
    // SpreadSheetCell& operator=(const SpreadSheetCell& rhs) = default;
    // SpreadSheetCell& operator=(const SpreadSheetCell& rhs) = delete;
    void set(int value) = delete;   // ne pustimo klica z int

    void set(double value);
    [[nodiscard]] double getValue() const;  // ce to ni oznaceno kot const in podas ta objekt kot const SpeadsheetCell& nekam v metodo, ti ne bo pustil klica metode, ce ta ni oznaceno s const
                                            // dodatni je potrebno tu in se v definiciji

    void set(std::string_view value);
    [[nodiscard]] std::string getString() const; // ce to ni oznaceno kot const in podas ta objekt kot const SpeadsheetCell& nekam v metodo, ti ne bo pustil klica metode, ce ta ni oznaceno s const
                                                 // dodatni je potrebno tu in se v definiciji

    std::shared_ptr<SpreadsheetCell> getSharedPointerOnYourSelf();
    std::weak_ptr<SpreadsheetCell> getWeakPointerOnYourSelf();

    // imejmo en class, ki je friend temu classu
    friend class Bar;

    // tole se klice nad navadnim objektom SpreadsheetCell
    const std::string& getDescription() const &;

    // tole se klice nad temp  rvalue objektom SpreadsheetCell - v tem primeru ce rabimo string enostavno premaknemo ownership, in prisparamo na casu
    std::string&& getDescription() &&;

    // OPERATOR OVERLOADINGS

    //problem tega implicitnega operatorja je, da operacija ni komutativna - torej na desni je lahko karkoli, na levi mora biti pa vedno SpreadsheetCell instance
    //zato potem obstajajo globalni oepratorji
    // SpreadsheetCell operator+(const SpreadsheetCell& cell) const;

    // short hand operatorje vedno definiramo implicitno znotraj class-a
    SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);


    bool operator==(const SpreadsheetCell& rhs) const;
    std::partial_ordering operator<=>(const SpreadsheetCell& rhs) const;

    // definicije za operacije neposredno z double, da se ne uporabi converting ctor in s tem po nepotrebnem dodatna kopija
    bool operator==(double rhs) const;
    std::partial_ordering operator<=>(double rhs) const;


private:
    [[nodiscard]] static std::string doubleToString(double value);
    [[nodiscard]] static double stringToDouble(std::string_view value);
    double m_value{0.0}; // in-class member initializer - pomeni da na tem emstu definiramo in inicializiramo member
    mutable unsigned m_numOfAccesses{0};    // mutable pomeni, da tudi ce se bo ta member nekje v kaksni const metodi spremenjen, bo metoda se vedno veljala za const metodo
    // tole je kot neke vrste izjema za const objekte.
    std::string m_description{"cell description for internal use"};
    Color m_color{Color::Red};

};



#endif //SMARTTHISPOINTER_H
