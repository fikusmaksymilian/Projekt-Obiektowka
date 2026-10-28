#pragma once
#include <string>

using namespace std;

class PracownikSystemu;

class Komentarz {
private:
    string tresc;
    string dataDodania;
    PracownikSystemu* autor;

public:
    Komentarz(string tresc, string dataDodania, PracownikSystemu* autor);
    void wypisz() const;
};
