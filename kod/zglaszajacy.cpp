#include "zglaszajacy.h"
#include <iostream>

using namespace std;

Zglaszajacy::Zglaszajacy(int id, string imie, string nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

void Zglaszajacy::wyswietlPanel() const {
    cout << "Panel zglaszajacego: " << getImieNazwisko() << "\n";
}
