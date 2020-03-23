#include <iostream>
#include "Statystyka.hh"

using std::cout;
using std::endl;

/*!
 * Inicjalizuje strukture statystyk odpowiedzi
 * Argumenty:
 *    Pkt - referencja na strukture statystyk
 */
void InicjalizujOdp(Punkty &Pkt){
    Pkt.LDobrychOdp = 0;
    Pkt.LOdp = 0;
}

/*!
 * Zwieksza liczbe dobrych i udzielonych odpowiedzi
 * Argumenty:
 *    Pkt - referencja na strukture statystyk
 * 
 * Warunek początkowy:
 *    -struktura Pkt musi byc poczotkowo zainicjalizowana funkcja InicjalizujOdp
 */
void DobraOdp(Punkty &Pkt){
    Pkt.LDobrychOdp++;
    Pkt.LOdp++;
}

/*!
 * Zwieksz liczbe udzielonych odpowiedzi
 * Argumenty:
 *    Pkt - referencja na strukture statystyk
 * 
 * Warunek początkowy:
 *    -struktura Pkt musi byc poczatkowo zainicjalizowana funkcja InicjalizujOdp
 */
void ZlaOdp(Punkty &Pkt){
    Pkt.LOdp++;
}

/*!
 * Wyswietla statystyki udzielonych odpowiedzi
 * Argumenty:
 *    Pkt - zmienna struktury statystyk
 * 
 * Warunek początkowy:
 *    -struktura Pkt musi byc poczatkowo zainicjalizowana funkcja InicjalizujOdp
 */
void WyswietlStatystyki(Punkty Pkt){
    double procent;

    cout<<"Ilosc dobrych odpowiedzi: "<<Pkt.LDobrychOdp<<endl;
    cout<<"Ilosc blednych odpowiedzi: "<<Pkt.LOdp - Pkt.LDobrychOdp<<endl;
    procent = Pkt.LDobrychOdp / Pkt.LOdp * 100;
    cout<<"Wynik procentowy poprawnych odpowiedzi: "<<procent<<" %"<<endl;
}