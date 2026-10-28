#pragma once
#include "pracownik_systemu.h"
#include <vector>

using namespace std;

class Zgloszenie;

class Technik : public PracownikSystemu {
private:
    string specjalizacja;
    double premia;
    vector<Zgloszenie*> zgloszenia;

public:
    Technik(int id, string imie, string nazwisko, string specjalizacja, double premia);
    void wyswietlPanel() const override;
    void dodajZgloszenie(Zgloszenie* zgloszenie);
    void obetnijPremie();
    double getPremia() const;
    vector<Zgloszenie*> getZgloszenia() const;
};
