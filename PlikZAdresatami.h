#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <windows.h>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "PlikZUzytkownikami.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy {

    int idOstatniegoAdresata;
    string NAZWA_TYMCZASOWEGO_PLIKU;

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPliku);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    PlikZAdresatami(string NAZWA_PLIKU): PlikTekstowy(NAZWA_PLIKU) {
        idOstatniegoAdresata = 0;
        NAZWA_TYMCZASOWEGO_PLIKU = "Adresaci_temp.txt";

    };
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void edytujWybranaLinieWPliku(Adresat adresat, string liniaZDanymiAdresata);
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);

};

#endif
