#include <iostream>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

using std::cout;
using std::cin;
using std::endl;


/*!
 * Wykonuje operacje matematyczna zawarta w strukturze wyrazenia
 * Argumenty:
 *    WyrZ - wyrazenie zespolone, ktore zostanie obliczone
 * Zwraca:
 *    Wynik operacji matematycznej bedacy liczba zespolona
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona Obl;

    switch(WyrZ.Op){
        case Op_Dodaj:
            Obl = WyrZ.Arg1 + WyrZ.Arg2;
            break;
        case Op_Odejmij:
            Obl = WyrZ.Arg1 - WyrZ.Arg2;
            break;
        case Op_Mnoz:
            Obl = WyrZ.Arg1 * WyrZ.Arg2;
            break;
        case Op_Dziel:
            Obl = WyrZ.Arg1 / WyrZ.Arg2;
            break;
    }
    return Obl;
}

/*!
 * Wczytuje znak arytmetyczny wyrazenia zespolonego
 * Argumenty:
 *    strm - referencja do strumienia wejsciowego
 *    Op - referencja do struktury przechowujacej operator arytmetyczny
 * Zwraca:
 *    referencja do strumienia wejsciowego
 */
std::istream & operator >> (std::istream & strm, Operator & Op) {
  char znak;
  
  strm >> znak;
  switch(znak){
        case '+':
          Op = Op_Dodaj;
          break;
        case '-':
          Op = Op_Odejmij;
          break;
        case '*':
          Op = Op_Mnoz;
          break;
        case '/':
          Op = Op_Dziel;
          break;
    }
  return strm;
}

/*!
 * Wypisuje znak równania arytmetycznego
 * Argumenty:
 *    strm - referencja do strumienia wyjsciowego
 *    Op - referencja do struktury przechowujacej operator arytmetyczny
* Zwraca:
 *    referencja do strumienia wyjsciowego
 */
std::ostream & operator << (std::ostream & strm, const Operator & Op) {
  switch(Op){
        case Op_Dodaj:
            strm << " + ";
            break;
        case Op_Odejmij:
            strm << " - ";
            break;
        case Op_Mnoz:
            strm << " * ";
            break;
        case Op_Dziel:
            strm << " / ";
            break;
    }
  return strm;
}

/*!
 * Wypisuje wyrazenie zespolone
 * Argumenty:
 *    strm - referencja do strumienia wyjsciowego
 *    WyrZ - wyrazenie zespolone do wyswietlenia
 * Zwraca:
 *    referencja do strumienia wyjsciowego
 */
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WyrZ){
    strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
    return strm;
}

/*!
 * Wczytuje wyrazenie zespolone
 * Argumenty:
 *    strm - referencja do strumienia wejsciowego
 *    WyrZ - referencja wyrazenia zespolonego do ktorej wczytujemy
 * Zwraca:
 *    referencja do strumienia wejsciowego
 */
std::istream & operator >>(std::istream & strm, WyrazenieZesp & WyrZ){
    strm >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return strm;
}