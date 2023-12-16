#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main()
{
    char wybor;

    MetodyPomocnicze metodyPomocnicze;

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() > 0)
        {
            wybor = metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                ksiazkaAdresowa.pobierzZPlikuIdOstatniegoAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '3':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                break;
            case '4':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '5':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            case '6':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
