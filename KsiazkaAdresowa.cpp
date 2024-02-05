#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

void KsiazkaAdresowa::menu() {
    char wybor;

    while (true) {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

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
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyszukajAdresatowPoImieniu();
                break;
            case '3':
                wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
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
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true) {
        adresatMenedzer -> dodajAdresata();
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
        adresatMenedzer -> wyswietlWszystkichAdresatow();
    } else {
        cout << "Musisz byc zalogowany, by wyswietlic kontakty" << endl;
        system("pause");
    }
}
void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}
bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::usunAdresata() {
    adresatMenedzer -> usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {
    adresatMenedzer -> edytujAdresata();
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresatMenedzer -> wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
    adresatMenedzer -> wyszukajAdresatowPoNazwisku();
}


