#include <iostream>
#include "Statystyka.hh"

using std::cout;
using std::endl;

/*!
 * Inicjalizuje strukture statystyk odpowiedzi
 * Argumenty:
 *    
 * Zwraca:
 *    true jezeli sa rozne, false jesli liczby sa rowne.
 */
void InicjalizujOdp(Punkty &Pkt){
    Pkt.LDobrychOdp = 0;
    Pkt.LOdp = 0;
}

void DobraOdp(Punkty &Pkt){
    Pkt.LDobrychOdp++;
    Pkt.LOdp++;
}

void ZlaOdp(Punkty &Pkt){
    Pkt.LOdp++;
}

void WyswietlStatystyki(Punkty Pkt){
    double procent;

    cout<<"Ilosc dobrych odpowiedzi: "<<Pkt.LDobrychOdp<<endl;
    cout<<"Ilosc blednych odpowiedzi: "<<Pkt.LOdp - Pkt.LDobrychOdp<<endl;
    procent = Pkt.LDobrychOdp / Pkt.LOdp * 100;
    cout<<"Wynik procentowy poprawnych odpowiedzi: "<<procent<<" %"<<endl;
}