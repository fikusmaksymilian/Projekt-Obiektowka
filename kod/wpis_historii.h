#pragma once
#include <string>

using namespace std;

class PracownikSystemu;

class WpisHistorii {
private:
    string dataZmiany;
    string staryStatus;
    string nowyStatus;
    PracownikSystemu* autor;

public:
    WpisHistorii(string dataZmiany, string staryStatus, string nowyStatus, PracownikSystemu* autor);
    void wypisz() const;
};
