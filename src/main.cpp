#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

int main(int argc, char **argv)
{

  if (argc < 2) { //zwroc blad jesli nie wybrano poziomu trudnosci
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};

  if(InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  Punkty Pkt;
  int l_bledow;
  char znak;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    l_bledow = 0;

    cout<<":? Podaj wynik operacji: ";
    Wyswietl(WyrZ_PytanieTestowe);
    cout<<" = "<<endl;
    cout<<"Twoja odpowiedz: ";
    cin>>znak;
    if(znak=='(')

  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
