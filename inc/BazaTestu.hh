#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include <fstream>

#include "WyrazenieZesp.hh"

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  std::ifstream plik;     /* uchwyt do pliku zawierajacego pytania testu */
  unsigned int nrLini;    /* Numer aktualnie wczytywanej lini */
};

/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest(BazaTestu  &bazaT, const char *sNazwaTestu);
/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastpnePytanie(BazaTestu &bazaT, WyrazenieZesp &wZesp);

#endif
