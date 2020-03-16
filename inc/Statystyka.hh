#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Punkty{
    int LDobrychOdp;
    int LOdp;
};

void InicjalizujOdp(Punkty &Pkt);
void DobraOdp(Punkty &Pkt);
void ZlaOdp(Punkty &Pkt);
void WyswietlStatystyki(Punkty Pkt);

#endif