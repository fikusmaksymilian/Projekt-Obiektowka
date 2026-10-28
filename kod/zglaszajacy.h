#pragma once
#include "pracownik_systemu.h"

using namespace std;

class Zglaszajacy : public PracownikSystemu {
public:
    Zglaszajacy(int id, string imie, string nazwisko);
    void wyswietlPanel() const override;
};
