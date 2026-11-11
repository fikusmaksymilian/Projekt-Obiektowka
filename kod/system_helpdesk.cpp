#include "system_helpdesk.h"

using namespace std;

Administrator* SystemHelpdesk::dodajAdministratora(string imie, string nazwisko) {
    administratorzy.push_back(make_unique<Administrator>(nastepneId++, imie, nazwisko));
    return administratorzy.back().get();
}

Zglaszajacy* SystemHelpdesk::dodajZglaszajacego(string imie, string nazwisko) {
    zglaszajacy.push_back(make_unique<Zglaszajacy>(nastepneId++, imie, nazwisko));
    return zglaszajacy.back().get();
}

Technik* SystemHelpdesk::dodajTechnika(string imie, string nazwisko, string specjalizacja, double premia) {
    technicy.push_back(make_unique<Technik>(nastepneId++, imie, nazwisko, specjalizacja, premia));
    return technicy.back().get();
}

Zgloszenie* SystemHelpdesk::utworzZgloszenie(string opis, int priorytet, KategoriaProblemu kategoria, string termin, Zglaszajacy* autor) {
    int id = listaZgloszen.size() + 1;
    listaZgloszen.push_back(make_unique<Zgloszenie>(id, opis, priorytet, kategoria, termin, autor));
    return listaZgloszen.back().get();
}

Zgloszenie* SystemHelpdesk::znajdzZgloszenie(int id) const {
    for (const auto& z : listaZgloszen) {
        if (z->getId() == id) {
            return z.get();
        }
    }
    return nullptr;
}

vector<Zgloszenie*> SystemHelpdesk::filtrujZgloszenia(Technik* technik, string status) const {
    vector<Zgloszenie*> wynik;
    for (const auto& z : listaZgloszen) {
        if (z->getTechnik() == technik && z->getStatus() == status) {
            wynik.push_back(z.get());
        }
    }
    return wynik;
}

bool SystemHelpdesk::zmienStatusZgloszenia(int idZgloszenia, string nowyStatus, string data) {
    Zgloszenie* z = znajdzZgloszenie(idZgloszenia);
    if (z == nullptr) {
        return false;
    }
    return z->zmienStatus(nowyStatus, z->getTechnik(), data);
}
