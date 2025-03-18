#ifndef SMARTTHISPOINTER_H
#define SMARTTHISPOINTER_H
#include <memory>
#include <string>
#include <string_view>

class SpreadSheetCell : public std::enable_shared_from_this<SpreadSheetCell> {
private:
    [[nodiscard]] std::string doubleToString(double value) const;
    [[nodiscard]] double stringToDouble(std::string_view value) const;
    double m_value{0.0}; // in-class member initializer - pomeni da na tem emstu definiramo in inicializiramo member

public:

    // navadni ctor
    // explicit zato, da preprecimo implicitne konverzije iz double direkt v SpreadsheetCell temp object, pa potem uporaba assignment operatorja, da se naredi myCell = "5"sv;
    explicit SpreadSheetCell(double initialValue);

    // explicit zato, da preprecimo implicitne konverzije iz string_view direkt v SpreadsheetCell temp object, pa potem uporaba assignment operatorja, da se naredi myCell = "5"sv;
    explicit SpreadSheetCell(std::string_view initialValue);
    // SpreadSheetCell(std::initializer_list<double> values);   // tu lahko sprejmemo initializer listo in jo uporabimo za inicializacijo, ampak nimamo kle take potrebe po temu
                                                             // values.size() je dolzina liste, drugas se palahko sprehodis po vrednostih s const referenco v loopu in jih uporabis


    // copy ctor - ce tega ne definiramo, nam compiler avtomatsko generira svojega. Pri tem se skopira vse memberje podanega parametra (src) v memberje novo kreiranega  objekta.
    // ce so memberji class-a objekti, potem se za vsakega od teh klice copy ctor in v njih podajo notri korespondencni parametri iz src member objektov
    // posebno tam kjer se uporabljajo pointerji, pa je potrebno definirati copy construcotr posebej rocno in premisljeno.
    SpreadSheetCell(const SpreadSheetCell& src);
    // v tem primeru, kjer lahko uporabimo kar default ctor in nam ga sploh ni treba definirat, bi lahko naredili tudi takole:
    // SpreadsheetCell(const SpreadsheetCell& src) = default;
    // ali ce ne rabimo copy ctor, ker ne zelimo da se objekt kopira (npr unique_ptr imajo to, ker dajejo izkljucno samo enemu objektu pravico dostopa in ne pustijo kopirat),
    // potem takole: SpreadsheetCell(const SpreadsheetCell& src) = delete;

    // default ctor; to pove da ga zelimo vseeno imeti; ker cim definiras drug ctor, ki ni default, se default ne generira vec avtomatsko
    SpreadSheetCell() = default;

    ~SpreadSheetCell();

    // tole pa uporabimo ko ne potrebujemo default ctor, npr. classi s staicnimi memberji. Tam ne poterbujemo default ctor.
    // mimogrede, ce bi imel ta class neke memberje, ki bi imeli ze sami po sebi deleted constructor, potem bi avtomatsko tudi ta class imel deleted constructor
    // SpreadSheetCell() = delete;


    // assignment operator
    SpreadSheetCell& operator=(const SpreadSheetCell& rhs); // rhs je lahko const referenca, ker se bo samo bralo iz njega, vrnit pa moramo referenco
    // lahko ga damo pa tudi v default ali pa delete, ce ga ne potrebujemo
    // SpreadSheetCell& operator=(const SpreadSheetCell& rhs) = default;
    // SpreadSheetCell& operator=(const SpreadSheetCell& rhs) = delete;

    void setValue(double value);
    [[nodiscard]] double getValue() const;

    void setString(std::string_view value);
    [[nodiscard]] std::string getString() const;

    std::shared_ptr<SpreadSheetCell> getSharedPointerOnYourSelf();
    std::weak_ptr<SpreadSheetCell> getWeakPointerOnYourSelf();

    // imejmo en class, ki je friend temu classu
    friend class Bar;


};



#endif //SMARTTHISPOINTER_H
