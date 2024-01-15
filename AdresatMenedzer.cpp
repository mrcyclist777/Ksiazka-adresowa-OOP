#include "AdresatMenedzer.h"

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int id) {
    idZalogowanegoUzytkownika = id;
}
int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
void AdresatMenedzer::ustawIdOstatniegoAdresata(int id) {
    idOstatniegoAdresata = id;
}
int AdresatMenedzer::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId((pobierzIdOstatniegoAdresata() + 1));
    adresat.ustawIdUzytkownika(pobierzIdZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    ustawIdOstatniegoAdresata(pobierzIdOstatniegoAdresata()+1);
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    if (idZalogowanegoUzytkownika != 0) {
        ustawIdOstatniegoAdresata(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata());
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    }
}


void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wylogowywanieUzytkownika() {
    adresaci.clear();
    ustawIdZalogowanegoUzytkownika(0);
}

