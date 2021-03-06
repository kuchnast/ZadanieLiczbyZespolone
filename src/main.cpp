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

  BazaTestu BazaT;

  if(!InicjalizujTest(BazaT,argv[1])) {  //inicjuj odpowiedni poziom trudności testu lub zwróć błąd
    cerr << "   Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona OdpUzyt, OdpWlasc;
  Punkty Pkt;
  int b_zapisu;
  
  cout << endl;
  cout << "   Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  InicjalizujOdp(Pkt);

  while (PobierzNastpnePytanie(BazaT, WyrZ_PytanieTestowe)) {
    b_zapisu = 0;
    
    try{
      OdpWlasc = Oblicz(WyrZ_PytanieTestowe);
    }
    catch(const char * k){  //obsluga wyjatku generowanego przez dzielenie przez 0
      cerr << k << " Przejście do kolejnego pytania" << endl;
      continue;
    }

    cout << ":? Podaj wynik operacji: " << WyrZ_PytanieTestowe << " = " << endl;
    cout << "   Twoja odpowiedz: ";
    cin >> OdpUzyt;

    while(!cin.good() && b_zapisu < 2){
      b_zapisu++;
      cin.clear();
      cin.ignore(1000,'\n');
      cout << ":/ Błąd zapisu liczby zespolonej. Spróbuj jeszcze raz." << endl;
      cout << "   Twoja odpowiedz: ";
      cin >> OdpUzyt;
    }

    if(b_zapisu == 3){  //po trzecim bledzie zapisu przejdz do kolejnego pytania
      cin.clear();
      cin.ignore(1000,'\n');
      cout << ":( Trzeci błąd zapisu liczby zespolonej. Przejście do kolejnego pytania." << endl;
      ZlaOdp(Pkt);
    }
    else if(OdpWlasc != OdpUzyt){
      cout << ":( Błąd. Prawidłowym wynikiem jest: "<< OdpWlasc << endl;
      ZlaOdp(Pkt);
    }
    else{
      cout << ":) Poprawna odpowiedź" << endl;
      DobraOdp(Pkt);
    }
  }
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  WyswietlStatystyki(Pkt);
  cout << endl;
}
