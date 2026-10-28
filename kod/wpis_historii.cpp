#include "wpis_historii.h"
#include "pracownik_systemu.h"
#include <iostream>

using namespace std;

WpisHistorii::WpisHistorii(string dataZmiany, string staryStatus, string nowyStatus, PracownikSystemu* autor)
    : dataZmiany(dataZmiany), staryStatus(staryStatus), nowyStatus(nowyStatus), autor(autor) {}

void WpisHistorii::wypisz() const {
    cout << dataZmiany << ": " << staryStatus << " -> " << nowyStatus
         << " (autor id " << autor->getId() << ")\n";
}
