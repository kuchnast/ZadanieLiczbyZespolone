#include <iostream>
#include <cmath>

#include "LZespolona.hh"

using std::cout;
using std::cin;
using std::endl;
using std::showpos;
using std::noshowpos;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dodawania,
 *    L2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - liczba od której odejmujemy,
 *    L2 - liczba którą odejmujemy.
 * Zwraca:
 *    Różnicę dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Roznica;

  Roznica.re = L1.re - L2.re;
  Roznica.im = L1.im - L2.im;
  return Roznica;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy mnożnik,
 *    L2 - drugi mnożnik.
 * Zwraca:
 *    Iloczyn dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  Iloczyn;

  Iloczyn.re = L1.re * L2.re - L1.im * L2.im;
  Iloczyn.im = L1.re * L2.im + L1.im * L2.re;
  return Iloczyn;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez całkowitą.
 * Argumenty:
 *    L1 - pierwsza liczba - zespolona dzielna,
 *    R - druga liczba - rzeczywisty dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry, czyli liczbę zespolona.
 */
LZespolona  operator / (LZespolona  L1,  double R){
  LZespolona Iloraz;
  if(R == 0)
    throw "Próba dzielenia przez 0.";  //zwrocenie wyjatku
  
  Iloraz.re = L1.re / R;
  Iloraz.im = L1.im / R;

  return Iloraz;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba - dzielna,
 *    L2 - druga liczba - dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2){
  LZespolona Iloraz;

  if(L2 == 0)
    throw "Próba dzielenia przez 0.";  //zwrocenie wyjatku
    
  Iloraz = (L1 * Sprzezenie(L2)) / pow(Modul(L2), 2);
  return Iloraz;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba,
 *    L2 - druga liczba.
 * Zwraca:
 *    true jesli liczby sa rowne, false jezeli sa rozne.
 */
bool  operator == (LZespolona  L1,  LZespolona  L2){
  if(L1.re == L2.re && L1.im == L2.im){
    return true;
  }
  return false;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwsza liczba,
 *    L2 - druga liczba.
 * Zwraca:
 *    true jezeli sa rozne, false jesli liczby sa rowne.
 */
bool  operator != (LZespolona  L1,  LZespolona  L2){
  return !(L1==L2);
}

/*!
 * Realizuje porównanie liczby zespolonej i rzeczywistej
 * Argumenty:
 *    L1 - pierwsza liczba - zespolona,
 *    R - druga liczba - rzeczywista.
 * Zwraca:
 *    true jezeli sa rowne, false jesli liczby sa rozne.
 */
bool  operator == (LZespolona L, double R){
  if(L.re == R && L.im == 0){
    return true;
  }
  return false;
}

/*!
 * Realizuje porównanie liczby zespolonej i rzeczywistej
 * Argumenty:
 *    L1 - pierwsza liczba - zespolona,
 *    R - druga liczba - rzeczywista.
 * Zwraca:
 *    true jezeli sa rozne, false jesli liczby sa rowne.
 */
bool  operator != (LZespolona L, double R){
  return !(L==R);
}

/*!
 * Oblicza modul z liczby zespolonej.
 * Argumenty:
 *    L1 - liczba zespolona,
 * Zwraca:
 *    Liczbe rzeczywista bedaca modulem liczby zespolonej
 */
double Modul(LZespolona L1){
  double modul;
  
  modul = sqrt(pow(L1.re, 2) + pow(L1.im, 2));
  return modul;
}

/*!
 * Oblicza sprzezenie liczby zespolonej.
 * Argumenty:
 *    L1 - liczba zespolona,
 * Zwraca:
 *    Liczbe zespolona sprzezona do liczby przekazanej jako parametr
 */
LZespolona Sprzezenie(LZespolona L1){
  L1.im = -L1.im;
  return L1;
}

/*!
 * Tworzy nowa liczbe zespolona.
 * Argumenty:
 *    re - czesc rzeczywista liczby zespolonej
 *    im - czesc urojona liczby zespolonej
 * Zwraca:
 *    Liczbe zespolona utworzona z dwoch liczb rzeczywistych przeslanych jako parametry
 */
LZespolona Utworz(double re, double im){
  LZespolona Nowa;

  Nowa.re = re;
  Nowa.im = im;
  return Nowa;
}

/*!
 * Realizuje wczytywanie liczby zespolonej
 * Argumenty:
 *    strm - referencja do strumienia wejściowego.
 *    Skl - referencja do struktury na liczbę zespoloną.
 * Zwraca:
 *    referencja do strumienia wejściowego.
 */
std::istream & operator >>(std::istream & strm, LZespolona & L){
  char znak;
  double liczba;

  strm >> znak;
  if(znak != '(')                       //sprawdzenie czy pierwszy znak to nawias
    strm.setstate(std::ios::failbit);

  znak = strm.peek();                   //podejzyj nastepny znak
  if(znak == '-'){                      //(1)pierwszy znak to minus
    strm >> znak;
    znak = strm.peek();
    if(znak == 'i'){                    //(2)drugi znak to i czyli to liczba -i
      strm >> znak;
      L.re = 0;
      L.im = -1;
    }
    else if(isdigit(znak)){             //(2)drugi znak to cyfra, wiec wczytaj liczbe
      strm >> liczba >> znak;
      if(znak == ')'){                  //(3)znak po liczbie to nawias, wiec wczytano -re
        L.re = -liczba;
        L.im = 0;
        return strm;
      }
      else if(znak == 'i'){             //(3)znak po liczbie to i, wiec wczytano -im
        L.re = 0;
        L.im = -liczba;
      }
      else if(znak == '-'){             //(3)znak po liczbie to -, wiec czytaj dalej
        L.re = -liczba;
        znak = strm.peek();
        if(znak == 'i'){                //(4)dalej jest i, wiec wczytano -re-i
          strm >> znak;
          L.im = -1;
        }
        else if(isdigit(znak)){         //(4)dalej jest cyfra, wiec wczytano -re-im
          strm >> L.im >> znak;
          L.im = -L.im;
          if(znak != 'i')               //(5)jesli po liczbie nie ma i, zwroc blad
            strm.setstate(std::ios::failbit);
        }
        else{                           //(4)jesli cos innego, zwroc blad
          strm.setstate(std::ios::failbit);
        }
      }
      else if(znak == '+'){             //(3)znak po liczbie to +, wiec czytaj dalej
        L.re = -liczba;
        znak = strm.peek();
        if(znak == 'i'){                //(4)dalej jest i, wiec wczytano -re+i
          strm >> znak;
          L.im = 1;
        }
        else if(isdigit(znak)){         //(4)dalej jest cyfra, wiec wczytano -re+im
          strm >> L.im >> znak;
          if(znak != 'i')               //(5)jesli po liczbie nie ma i, zwroc blad
            strm.setstate(std::ios::failbit);
        }
        else{                           //(4)jesli cos innego, zwroc blad
          strm.setstate(std::ios::failbit);
        }
      }
      else{                             //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else{                               //(2)jesli cos innego, zwroc blad
      strm.setstate(std::ios::failbit);
    }
  }
  else if(znak == 'i'){                 //(1)pierwszy znak to i, wiec wczytano i
    strm >> znak;
    L.re = 0;
    L.im = 1;
  }
  else if(isdigit(znak)){               //(1)pierwszy znak to cyfra, wiec wczytaj liczbe
    strm >> liczba >> znak;
    if(znak == ')'){                    //(2)drugi znak to ), wiec wczytano re
      L.re = liczba;
      L.im = 0;
      return strm;
    }
    else if(znak == 'i'){               //(2)drugi znak to i, wiec wczytano im
      L.re = 0;
      L.im = liczba;
    }
    else if(znak == '-'){               //(2)drugi znak to -, wiec czytaj dalej
      L.re = liczba;
      znak = strm.peek();
      if(znak == 'i'){                  //(3)kolejny znak to i, wiec wczytano re-i
        strm >> znak;
        L.im = -1;
      }
      else if(isdigit(znak)){           //(3)kolejny znak to cyfra, wiec wczytano re-im
        strm >> L.im >> znak;
        L.im = -L.im;
        if(znak != 'i')                 //(4)jesli po liczbie nie ma i, zwroc blad
          strm.setstate(std::ios::failbit);
      }
      else{                             //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else if(znak == '+'){               //(2)drugi znak to -, wiec czytaj dalej
      L.re = liczba;
      znak = strm.peek();
      if(znak == 'i'){                  //(3)kolejny znak to i, wiec wczytano re+i
        strm >> znak;
        L.im = 1;
      }
      else if(isdigit(znak)){           //(3)kolejny znak to cyfra, wiec wczytano re+im
        strm >> L.im >> znak;
        if(znak != 'i')                 //(4)jesli po liczbie nie ma i, zwroc blad
          strm.setstate(std::ios::failbit);
      }
      else{                             //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else{                               //(2)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
    }
  }
  else{                                 //(1)jesli cos innego, zwroc blad
    strm.setstate(std::ios::failbit); 
  }

  strm >> znak;                   //wczytaj kolejny znak
  if(znak != ')')                 //jesli jest to ), znaczy ze koniec liczby
    strm.setstate(std::ios::failbit); 

  return strm;
}

/*!
 * Realizuje wypisanie liczby zespolonej
 * Argumenty:
 *    strm - referencja do strumienia wyjściowego.
 *    L - referencja do struktury na liczbę zespoloną.
 * Zwraca:
 *    referencja do strumienia wyjściowego.
 */
std::ostream & operator << (std::ostream & strm, const LZespolona & L){
  strm << '(';

  if(L.re != 0){                  //jesli czesc rzeczywista jest rozna od 0, wypisz ja
    strm << L.re;
  }

  if(L.im != 0){                  //jesli czesc urojona jest rozna od 0, wypisz jej odpowiednia wersje
    if(L.im == 1){                
      if(L.re == 0)               //jesli czesc urojona byla rowna 1, a rzeczywista rowna 0, wypisz i
        strm << "i";
      else                        //jesli czesc urojona byla rowna 1, a rzeczywista rozna od 0, wypisz +i
        strm << "+i";
    }
    else if(L.im == -1){          //jesli czesc urojona byla rowna -1, wypisz -i
      strm << "-i";
    }
    else{                         
      if(L.re != 0)               //jesli czesc urojona byla inna liczba rozna od 0, a rzeczywista rozna od 0, wypisz ja z ew. +
        strm << showpos << L.im << noshowpos << 'i';
      else                        //jesli czesc urojona byla inna liczba rozna od 0, a rzeczywista rowna 0, wypisz ja bez ew. +
        strm << L.im << 'i';
    }
  }
  else{
    if(L.re == 0)                 //jesli czesc rzeczywista i zespolona sa rowne 0, wypisz 0
      strm << 0;
  }

  strm << ')';
 
  return strm;
}