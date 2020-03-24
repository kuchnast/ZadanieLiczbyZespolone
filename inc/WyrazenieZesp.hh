#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include <iostream>

#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*!
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

/*!
 * Oblicza przesłane wyrazenie zespolone
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ);

/*!
 * Wczytuje operator arytmetyczny ze strumienia wejsciowego
 */
std::istream & operator >> (std::istream & strm, Operator & Op);

/*!
 * Wypisuje operator arytmetyczny na strumien wyjsciowy
 */
std::ostream & operator << (std::ostream & strm, const Operator & Op);

/*!
 * Wypisuje wyrazenie arytmetyczny na strumien wyjsciowy
 */
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WyrZ);

/*!
 * Wczytuje wyrazenie arytmetyczny ze strumienia wejsciowego
 */
std::istream & operator >>(std::istream & strm, WyrazenieZesp & WyrZ);

#endif
