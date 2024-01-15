#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

void KsiazkaAdresowa::menu() {
    char wybor;

    while (true) {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0) {
            wybor = metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyswietlWszystkichAdresatow();
                break;
            case '3':
                wypiszWszystkichUzytkownikow();
                break;
            case '4':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '5':
                wylogowanieUzytkownika();
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
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true) {
        adresatMenedzer.dodajAdresata();
    } else {
        cout << "Konieczne jest zalogowanie w celu dodania adresata" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true) {
        adresatMenedzer.wyswietlWszystkichAdresatow();
    } else {
        cout << "Musisz byc zalogowany, by wyswietlic kontakty" << endl;
        system("pause");
    }
}
void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
}
bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}
