#pragma once
#include "administrator.h"
#include "technik.h"
#include "zglaszajacy.h"
#include "zgloszenie.h"
#include <memory>
#include <vector>

using namespace std;

class SystemHelpdesk {
private:
    vector<unique_ptr<Zgloszenie>> listaZgloszen;
    vector<unique_ptr<Administrator>> administratorzy;
    vector<unique_ptr<Zglaszajacy>> zglaszajacy;
    vector<unique_ptr<Technik>> technicy;
    int nastepneId = 1;

public:
    Administrator* dodajAdministratora(string imie, string nazwisko);
    Zglaszajacy* dodajZglaszajacego(string imie, string nazwisko);
    Technik* dodajTechnika(string imie, string nazwisko, string specjalizacja, double premia);
    Zgloszenie* utworzZgloszenie(string opis, int priorytet, KategoriaProblemu kategoria, string termin, Zglaszajacy* autor);
    Zgloszenie* znajdzZgloszenie(int id) const;
    vector<Zgloszenie*> filtrujZgloszenia(Technik* technik, string status) const;
};
