#include "technik.h"
#include <iostream>

using namespace std;

Technik::Technik(int id, string imie, string nazwisko, string specjalizacja, double premia)
    : PracownikSystemu(id, imie, nazwisko), specjalizacja(specjalizacja), premia(premia) {}

void Technik::wyswietlPanel() const {
    cout << "Panel technika: " << getImieNazwisko() << ", specjalizacja: " << specjalizacja
         << ", zgloszen: " << zgloszenia.size() << ", premia: " << premia << "\n";
}

void Technik::dodajZgloszenie(Zgloszenie* zgloszenie) {
    zgloszenia.push_back(zgloszenie);
}

void Technik::obetnijPremie() {
    premia = premia - 100;
    if (premia < 0) {
        premia = 0;
    }
}
