#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"


class AdresatMenedzer {

    MetodyPomocnicze metodyPomocnicze;

    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);


public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void ustawIdZalogowanegoUzytkownika(int id);
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdOstatniegoAdresata(int id);
    int pobierzIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wylogowywanieUzytkownika();
};

#endif
