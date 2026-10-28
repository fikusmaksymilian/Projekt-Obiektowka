#include "pracownik_systemu.h"

using namespace std;

PracownikSystemu::PracownikSystemu(int id, string imie, string nazwisko)
    : id(id), imie(imie), nazwisko(nazwisko) {}

int PracownikSystemu::getId() const {
    return id;
}

string PracownikSystemu::getImieNazwisko() const {
    return imie + " " + nazwisko;
}
