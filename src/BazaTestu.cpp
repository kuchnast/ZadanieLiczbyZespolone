#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "BazaTestu.hh"

using std::cerr;
using std::endl;
using std::string;

/*!
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    bazaT - referencja do struktury obslugujacej baze testu.
 *    sNazwaPliku  - wskaznik na sciezke do pliku z wybrana baza pytan.
 *   
 * Zwraca:
 *    true - gdy operacja otwarcia pliku sie powiedzie
 *    false - w przeciwnym razie
 */
bool UstawTest( BazaTestu &bazaT, const char * sNazwaPliku){
  ssize_t dl;
  char buf[1024];
  string sciezka;

  dl = readlink("/proc/self/exe", buf, sizeof(buf) - 1);  //odczytanie sciezki wykonywanego programu
  if(dl == -1)                                            //w przypadku gdy nie odczytano sciezki, zwroc blad
    return false;
  buf[dl] = '\0';                                         //dodanie /0 zaraz po ostatnim wczytanym znaku
  sciezka = buf;                                          //konwersja na typ string
  sciezka = sciezka.substr(0, sciezka.find_last_of('/')); //znalezienie ostatniego wystapienia '/' po ktorym jest nazwa pliku, a nastepnie odciecie nazwy od sciezki
  sciezka += "/../../bazaPytan/";                         //dodanie wzglednej sciezki do katalogu bazy pytan
  sciezka += sNazwaPliku;                                 //dodanie nazwy pozadanego pliku z testem

  bazaT.nrLini = 0;
  bazaT.plik.open(sciezka, std::ifstream::in);
  if(!bazaT.plik.is_open()){
    cerr << "Błąd otwarcia pliku z bazą pytań. Błędna ścieżka: " << sciezka << endl;
    return false;
  }
  return true;
}

/*!
 * Inicjalizuje test kojarzac otrzymana nazwe z jedna ze znanych lokalizacji pliku
 * Parametry:
 *    bazaT - referencja do struktury obslugujacej baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *      
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest(BazaTestu  &bazaT, const char *sNazwaTestu){
  if(!strcmp(sNazwaTestu,"latwy")){
    return UstawTest(bazaT, "latwy.dat");
  }
  
  if(!strcmp(sNazwaTestu,"trudny")){
    return UstawTest(bazaT, "trudny.dat");
  }

  cerr << "Nieznana nazwa testu '" << sNazwaTestu << "'." << endl;
  return false;
}



/*!
 * Funkcja udostepnia nastepne pytania o ile nie osiagnieto konca pliku 
 * oraz pomija te o nieprawidlowym formacie.
 * Parametry:
 *    bazaT - referencja do struktury obslugujacej baze testu.
 *    wZesp  - referencja do struktury na wczytywane wyrazenie zespolone.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i zostanie pobraze poprawne wyrazenie.
 *       false - gdy nie mozna pobrac juz nastepnego pytania bo jest koniec pliku.
 */
bool PobierzNastpnePytanie(BazaTestu &bazaT, WyrazenieZesp &wZesp){
  bazaT.plik >> wZesp;
  bazaT.nrLini++;

  if(bazaT.plik.eof())  //gdy osiagnieto koniec pliku, zwroc false
    return false;

  if(!bazaT.plik.good()){ //gdy podczas wczytywania wyrazenia wystapil blad, pomin linie i wypisz komunikat
    bazaT.plik.clear();
    bazaT.plik.ignore(1000,'\n');
    cerr << "Napotkano błędne wyrażenie w lini " << bazaT.nrLini <<". Zostało ono pominięte." << endl;
    return PobierzNastpnePytanie(bazaT, wZesp); //sprobuj wczytac nastepne pytanie
  }

  return true;
}
