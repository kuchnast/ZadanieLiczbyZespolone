#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Punkty{
    double LDobrychOdp;
    double LOdp;
};

void InicjalizujOdp(Punkty &Pkt);
void DobraOdp(Punkty &Pkt);
void ZlaOdp(Punkty &Pkt);
void WyswietlStatystyki(Punkty Pkt);

#endif