#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



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

std::ostream & operator << (std::ostream & strm, const Operator & Op);

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WyrZ);

std::istream & operator >>(std::istream & strm, WyrazenieZesp & WyrZ);

#endif
