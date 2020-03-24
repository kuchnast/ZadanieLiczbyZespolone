#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

/*!
 * Struktura statystyk odpowiedzi
 */
struct Punkty{
    double LDobrychOdp; //liczba dobrych odpowiedzi
    double LOdp; //liczba wszystkich udzielonych odpowiedzi
};

/*!
 * Inicjalizuje strukture statystyk odpowiedzi
 */
void InicjalizujOdp(Punkty &Pkt);

/*!
 * Aktualizuje statystyki w przypadku dobrej odpowiedzi
 */
void DobraOdp(Punkty &Pkt);

/*!
 * Aktualizuje statystyki w przypadku zlej odpowiedzi
 */
void ZlaOdp(Punkty &Pkt);

/*!
 * Wyswietla statystyki udzielonych odpowiedzi
 */
void WyswietlStatystyki(Punkty Pkt);

#endif