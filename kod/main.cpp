#include "system_helpdesk.h"
#include <iostream>

using namespace std;

int main() {
    SystemHelpdesk system;
    Administrator* admin = system.dodajAdministratora("Robert", "Lewandowski");
    Zglaszajacy* piotr = system.dodajZglaszajacego("Piotr", "Zieliński");
    Technik* technicy[] = {
        system.dodajTechnika("Walerij", "Chodemczuk", "Sieci", 500),
        system.dodajTechnika("Bartosz", "Pińczuk", "Sprzet", 500),
        system.dodajTechnika("Kamil", "Kovalenko", "Oprogramowanie", 500)
    };
    string statusy[] = {"Nowe", "W trakcie", "Oczekuje", "Rozwiazane"};

    int wybor = -1;
    while (wybor != 0) {
        cout << "\n1. Utworz zgloszenie (Zglaszajacy)\n"
             << "2. Przydziel zgloszenie technikowi (Administrator)\n"
             << "3. Zmien status (Technik)\n"
             << "4. Pokaz historie i komentarze\n"
             << "5. Dodaj komentarz (Technik)\n"
             << "6. Filtruj zgloszenia technika (Technik)\n"
             << "7. Sprawdz deadline (Administrator)\n"
             << "8. Pokaz panele\n"
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
            Zgloszenie* z = system.utworzZgloszenie(opis, priorytet, static_cast<KategoriaProblemu>(kategoria), termin, piotr);
            cout << "Utworzono zgloszenie nr " << z->getId() << " ze statusem " << z->getStatus() << "\n";
            continue;
        }
        if (wybor == 8) {
            admin->wyswietlPanel();
            piotr->wyswietlPanel();
            for (Technik* t : technicy) {
                t->wyswietlPanel();
            }
            continue;
        }

        Technik* technik = nullptr;
        if (wybor == 2 || wybor == 6) {
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << " - " << technicy[i]->getImieNazwisko() << "\n";
            }
            int t;
            cout << "Technik: ";
            cin >> t;
            if (t < 1 || t > 3) {
                cout << "Nie ma takiego technika\n";
                continue;
            }
            technik = technicy[t - 1];
        }

        if (wybor == 6) {
            int s;
            cout << "Status (0-Nowe, 1-W trakcie, 2-Oczekuje, 3-Rozwiazane): ";
            cin >> s;
            if (s < 0 || s > 3) {
                continue;
            }
            for (Zgloszenie* z : system.filtrujZgloszenia(technik, statusy[s])) {
                cout << "Zgloszenie nr " << z->getId() << ", termin " << z->getTermin() << "\n";
            }
            continue;
        }
        if (wybor < 2 || wybor > 7) {
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
        if ((wybor == 3 || wybor == 5) && z->getTechnik() == nullptr) {
            cout << "Zgloszenie nie jest jeszcze przydzielone do technika\n";
            continue;
        }

        if (wybor == 2) {
            if (admin->przydzielZgloszenie(*z, *technik)) {
                cout << "Przydzielono do " << technik->getImieNazwisko() << "\n";
            } else {
                cout << "Mozna przydzielic tylko zgloszenie ze statusem Nowe\n";
            }
        } else if (wybor == 3) {
            int s;
            string data;
            cout << "Nowy status (1-W trakcie, 2-Oczekuje, 3-Rozwiazane): ";
            cin >> s;
            if (s < 1 || s > 3) {
                continue;
            }
            cout << "Data (RRRR-MM-DD): ";
            cin >> data;
            if (z->zmienStatus(statusy[s], z->getTechnik(), data)) {
                cout << "Status zmieniony na " << z->getStatus() << "\n";
            } else {
                cout << "Niedozwolona zmiana statusu\n";
            }
        } else if (wybor == 4) {
            cout << "Status: " << z->getStatus() << "\nHistoria:\n";
            for (const WpisHistorii& w : z->getHistoria()) {
                w.wypisz();
            }
            cout << "Komentarze:\n";
            for (const Komentarz& k : z->getKomentarze()) {
                k.wypisz();
            }
        } else if (wybor == 5) {
            string tresc, data;
            cout << "Tresc: ";
            getline(cin >> ws, tresc);
            cout << "Data (RRRR-MM-DD): ";
            cin >> data;
            z->dodajKomentarz(Komentarz(tresc, data, z->getTechnik()));
            cout << "Dodano komentarz\n";
        } else if (wybor == 7) {
            cout << "Deadline: " << admin->sprawdzDeadline(*z) << "\n";
        }
    }
    return 0;
}
