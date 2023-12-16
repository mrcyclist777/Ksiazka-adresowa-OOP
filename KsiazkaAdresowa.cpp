#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true)
    {
        adresatMenedzer -> dodajAdresata();
    }
    else
    {
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
    uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

int KsiazkaAdresowa::pobierzZPlikuIdOstatniegoAdresata() {
    adresatMenedzer -> pobierzZPlikuIdOstatniegoAdresata();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
