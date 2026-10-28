#include "administrator.h"
#include "technik.h"
#include "zgloszenie.h"
#include <iostream>

using namespace std;

Administrator::Administrator(int id, string imie, string nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

void Administrator::wyswietlPanel() const {
    cout << "Panel administratora: " << getImieNazwisko() << "\n";
}

bool Administrator::przydzielZgloszenie(Zgloszenie& zgloszenie, Technik& technik) {
    if (zgloszenie.getStatus() != "Nowe") {
        return false;
    }
    zgloszenie.przypiszTechnika(&technik);
    technik.dodajZgloszenie(&zgloszenie);
    return true;
}
