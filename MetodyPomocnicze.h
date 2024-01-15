#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class MetodyPomocnicze {

public:
    static string konwersjaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static int wczytajLiczbeCalkowita();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string nazwaPlikuTekstowego;
    bool czyPlikJestPusty(string);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static char wczytajZnak();
    char static wybierzOpcjeZMenuGlownego();
    char static wybierzOpcjeZMenuUzytkownika();

};

#endif
