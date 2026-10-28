#include "zgloszenie.h"
#include "technik.h"

using namespace std;

Zgloszenie::Zgloszenie(int id, string opis, int priorytet, KategoriaProblemu kategoria, string termin, Zglaszajacy* zglaszajacy)
    : idZgloszenia(id), opis(opis), priorytet(priorytet), status("Nowe"), kategoria(kategoria),
      termin(termin), zglaszajacy(zglaszajacy), technik(nullptr) {}

bool Zgloszenie::zmienStatus(string nowyStatus, PracownikSystemu* autor, string data) {
    vector<string> kolejnosc = {"Nowe", "W trakcie", "Oczekuje", "Rozwiazane"};
    int stary = -1;
    int nowy = -1;
    for (int i = 0; i < 4; i++) {
        if (kolejnosc[i] == status) {
            stary = i;
        }
        if (kolejnosc[i] == nowyStatus) {
            nowy = i;
        }
    }
    if (nowy != stary + 1) {
        return false;
    }
    historia.push_back(WpisHistorii(data, status, nowyStatus, autor));
    status = nowyStatus;
    if (status == "Rozwiazane" && technik != nullptr && data > termin) {
        technik->obetnijPremie();
    }
    return true;
}

void Zgloszenie::przypiszTechnika(Technik* t) {
    technik = t;
}

int Zgloszenie::getId() const {
    return idZgloszenia;
}

string Zgloszenie::getStatus() const {
    return status;
}

vector<WpisHistorii> Zgloszenie::getHistoria() const {
    return historia;
}
