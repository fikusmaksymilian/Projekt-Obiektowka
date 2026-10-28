#pragma once
#include <string>

using namespace std;

class PracownikSystemu {
protected:
    int id;
    string imie;
    string nazwisko;

public:
    PracownikSystemu(int id, string imie, string nazwisko);
    virtual ~PracownikSystemu() = default;
    int getId() const;
    string getImieNazwisko() const;
    virtual void wyswietlPanel() const = 0;
};
