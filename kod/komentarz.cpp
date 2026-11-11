#include "komentarz.h"
#include "pracownik_systemu.h"
#include <iostream>

Komentarz::Komentarz(string tresc, string dataDodania, PracownikSystemu* autor)
    : tresc(tresc), dataDodania(dataDodania), autor(autor) {}

void Komentarz::wypisz() const {
    cout << dataDodania << " " << autor->getImieNazwisko() << ": " << tresc << "\n";
}