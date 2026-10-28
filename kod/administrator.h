#pragma once
#include "pracownik_systemu.h"

using namespace std;

class Zgloszenie;
class Technik;

class Administrator : public PracownikSystemu {
public:
    Administrator(int id, string imie, string nazwisko);
    void wyswietlPanel() const override;
    bool przydzielZgloszenie(Zgloszenie& zgloszenie, Technik& technik);
    string sprawdzDeadline(const Zgloszenie& zgloszenie) const;
};
