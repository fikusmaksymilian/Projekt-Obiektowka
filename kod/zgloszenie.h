#pragma once
#include "kategoria_problemu.h"
#include "komentarz.h"
#include "wpis_historii.h"
#include <string>
#include <vector>

using namespace std;

class Zglaszajacy;
class Technik;

class Zgloszenie {
private:
    int idZgloszenia;
    string opis;
    int priorytet;
    string status;
    KategoriaProblemu kategoria;
    string termin;
    Zglaszajacy* zglaszajacy;
    Technik* technik;
    vector<WpisHistorii> historia;
    vector<Komentarz> komentarze;

public:
    Zgloszenie(int id, string opis, int priorytet, KategoriaProblemu kategoria, string termin, Zglaszajacy* zglaszajacy);
    bool zmienStatus(string nowyStatus, PracownikSystemu* autor, string data);
    void dodajKomentarz(Komentarz k);
    void przypiszTechnika(Technik* t);
    int getId() const;
    string getStatus() const;
    string getTermin() const;
    Technik* getTechnik() const;
    vector<WpisHistorii> getHistoria() const;
    vector<Komentarz> getKomentarze() const;
};
