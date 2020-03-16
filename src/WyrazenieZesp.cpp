#include <iostream>
#include "WyrazenieZesp.hh"

using std::cout;

/*!
 * Wyswietla wyrazenie zespolone
 * Argumenty:
 *    WyrZ - wyrazenie zespolone do wyswietlenia
 */
void Wyswietl(WyrazenieZesp  WyrZ){
    Wyswietl(WyrZ.Arg1);
    switch(WyrZ.Op){
        case Op_Dodaj:
            cout << '+';
            break;
        case Op_Odejmij:
            cout << '-';
            break;
        case Op_Mnoz:
            cout << '*';
            break;
        case Op_Dziel:
            cout << '/';
            break;
    }
    Wyswietl(WyrZ.Arg2);
}

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
