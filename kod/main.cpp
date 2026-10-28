#include "system_helpdesk.h"
#include <iostream>

using namespace std;

int main() {
    SystemHelpdesk system;
    Administrator* admin = system.dodajAdministratora("Anna", "Nowak");
    Zglaszajacy* jan = system.dodajZglaszajacego("Jan", "Kowalski");
    Technik* piotr = system.dodajTechnika("Piotr", "Zielinski", "Sieci", 500);
    string statusy[] = {"Nowe", "W trakcie", "Oczekuje", "Rozwiazane"};

    int wybor = -1;
    while (wybor != 0) {
        cout << "\n1. Utworz zgloszenie (Zglaszajacy)\n"
             << "2. Przydziel zgloszenie technikowi (Administrator)\n"
             << "3. Zmien status (Technik)\n"
             << "4. Pokaz historie zgloszenia\n"
             << "0. Wyjscie\n"
             << "Wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            string opis, termin;
            int priorytet, kategoria;
            cout << "Opis: ";
            getline(cin >> ws, opis);
            cout << "Priorytet (1-3): ";
            cin >> priorytet;
            cout << "Kategoria (0-Sprzet, 1-Siec, 2-Oprogramowanie): ";
            cin >> kategoria;
            cout << "Termin (RRRR-MM-DD): ";
            cin >> termin;
            Zgloszenie* z = system.utworzZgloszenie(opis, priorytet, static_cast<KategoriaProblemu>(kategoria), termin, jan);
            cout << "Utworzono zgloszenie nr " << z->getId() << " ze statusem " << z->getStatus() << "\n";
            continue;
        }
        if (wybor < 2 || wybor > 4) {
            continue;
        }

        int id;
        cout << "Numer zgloszenia: ";
        cin >> id;
        Zgloszenie* z = system.znajdzZgloszenie(id);
        if (z == nullptr) {
            cout << "Nie ma takiego zgloszenia\n";
            continue;
        }

        if (wybor == 2) {
            if (admin->przydzielZgloszenie(*z, *piotr)) {
                cout << "Przydzielono do " << piotr->getImieNazwisko() << "\n";
            } else {
                cout << "Mozna przydzielic tylko zgloszenie ze statusem Nowe\n";
            }
        } else if (wybor == 3) {
            int s;
            string data;
            cout << "Nowy status (1-W trakcie, 2-Oczekuje, 3-Rozwiazane): ";
            cin >> s;
            cout << "Data (RRRR-MM-DD): ";
            cin >> data;
            if (z->zmienStatus(statusy[s], piotr, data)) {
                cout << "Status zmieniony na " << z->getStatus() << "\n";
            } else {
                cout << "Niedozwolona zmiana statusu\n";
            }
        } else if (wybor == 4) {
            cout << "Status: " << z->getStatus() << "\nHistoria:\n";
            for (const WpisHistorii& w : z->getHistoria()) {
                w.wypisz();
            }
        }
    }
    return 0;
}
