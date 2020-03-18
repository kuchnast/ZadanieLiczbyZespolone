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
    return true;
  }
  return false;
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
 * Tworzy nowa liczbe zespolona.
 * Argumenty:
 *    re - czesc rzeczywista liczby zespolonej
 *    im - czesc urojona liczby zespolonej
 * Zwraca:
 *    Liczbe zespolona utworzona z dwoch liczb rzeczywistych przeslanych jako parametry
 */
LZespolona Utworz(double re, double im){
  LZespolona Nowa;

  Nowa.re = re;
  Nowa.im = im;
  return Nowa;
}

/*!
 * Realizuje wczytywanie liczby zespolonej
 * Argumenty:
 *    strm - referencja do strumienia wejściowego.
 *    Skl - referencja do struktury na liczbę zespoloną.
 * Zwraca:
 *    referencja do strumienia wejściowego.
 */
std::istream & operator >>(std::istream & strm, LZespolona & L){
  char znak;

  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit); 
  strm>>L.re>>L.im>>znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit); 
  strm>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit); 

  return strm;
}

/*!
 * Realizuje wypisanie liczby zespolonej
 * Argumenty:
 *    strm - referencja do strumienia wyjściowego.
 *    L - referencja do struktury na liczbę zespoloną.
 * Zwraca:
 *    referencja do strumienia wyjściowego.
 */
std::ostream & operator << (std::ostream & strm, const LZespolona & L){
  strm << '(' << L.re << showpos << L.im << noshowpos << "i)"; 
  return strm;
}