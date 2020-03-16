#include <iostream>
#include <cmath>

#include "LZespolona.hh"

using std::cout;
using std::cin;
using std::endl;
using std::showpos;
using std::noshowpos;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dodawania,
 *    L2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - liczba od której odejmujemy,
 *    L2 - liczba którą odejmujemy.
 * Zwraca:
 *    Różnicę dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Roznica;

  Roznica.re = L1.re - L2.re;
  Roznica.im = L1.im - L2.im;
  return Roznica;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy mnożnik,
 *    L2 - drugi mnożnik.
 * Zwraca:
 *    Iloczyn dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Iloczyn;

  Iloczyn.re = L1.re * L2.re - L1.im * L2.im;
  Iloczyn.im = L1.re * L2.re + L1.im * L2.im;
  return Iloczyn;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba - dzielna,
 *    L2 - druga liczba - dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2){
  LZespolona Iloraz;

  Iloraz = (L1 * Sprzezenie(L2)) / pow(Modul(L2), 2);
  return Iloraz;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez całkowitą.
 * Argumenty:
 *    L1 - pierwsza liczba - zespolona dzielna,
 *    R - druga liczba - rzeczywisty dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry, czyli liczbę zespolona.
 */
LZespolona  operator / (LZespolona  L1,  double R){
  LZespolona Iloraz;
  
  Iloraz.re = L1.re / R;
  Iloraz.im = L1.im / R;

  return Iloraz;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba,
 *    L2 - druga liczba.
 * Zwraca:
 *    true jesli liczby sa rowne, false jezeli sa rozne.
 */
bool  operator == (LZespolona  L1,  LZespolona  L2){
  if(L1.re == L2.re && L1.im == L2.im){
    return true;
  }
  return false;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba,
 *    L2 - druga liczba.
 * Zwraca:
 *    true jezeli sa rozne, false jesli liczby sa rowne.
 */
bool  operator != (LZespolona  L1,  LZespolona  L2){
  if(L1.re != L2.re && L1.im != L2.im){
    return false;
  }
  return true;
}

/*!
 * Oblicza modul z liczby zespolonej.
 * Argumenty:
 *    L1 - liczba zespolona,
 * Zwraca:
 *    Liczbe rzeczywista bedaca modulem liczby zespolonej
 */
double Modul(LZespolona L1){
  double modul;
  
  modul = sqrt(pow(L1.re, 2) + pow(L1.im, 2));
  return modul;
}

/*!
 * Oblicza sprzezenie liczby zespolonej.
 * Argumenty:
 *    L1 - liczba zespolona,
 * Zwraca:
 *    Liczbe zespolona sprzezona do liczby przekazanej jako parametr
 */
LZespolona Sprzezenie(LZespolona L1){
  L1.im = -L1.im;
  return L1;
}

/*!
 * Wyswietla liczbe zespolona.
 * Argumenty:
 *    L1 - liczba zespolona,
 */
void Wyswietl(LZespolona Skl){
  cout << '(' << Skl.re << showpos << Skl.im << noshowpos << "i)" << endl; 
}

/*!
 * Tworzy nowa liczbe zespolona.
 * Argumenty:
 *    re - czesc rzeczywista liczby zespolonej
 *    im - czesc urojona liczby zespolonej
 * Zwraca:
 *    Liczbe zespolona utworzona z dwoch liczb rzeczywistych przeslanych jako parametry
 */
LZespolona Utworz(double re, int double){
  LZespolona Nowa;

  Nowa.re = re;
  Nowa.im = im;
  return Nowa;
}

/*!
 * Wykonuje operacje matematyczna zawarta w strukturze wyrazenia
 * Argumenty:
 *    L - referencja do ktorej zostanie wczytana liczba zespolona
 * Zwraca:
 *    true jezeli udalo sie wczytac liczbe, w przeciwnym razie false
 */
bool Wczytaj(LZespolona &L){
    char c;
    if (cin >> c)

    return true;
}