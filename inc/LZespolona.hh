#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

/*!
 * Dodawanie zespolone
 */
LZespolona  operator + (LZespolona  L1,  LZespolona  L2);

/*!
 * Odejmowanie zespolone
 */
LZespolona  operator - (LZespolona  L1,  LZespolona  L2);

/*!
 * Mnozenie zespolone
 */
LZespolona  operator * (LZespolona  L1,  LZespolona  L2);

/*!
 * Dzielenie zespolone
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2);

/*!
 * Dzielenie liczby zespolonej przez rzeczywista
 */
LZespolona  operator / (LZespolona  L1,  int R);

/*!
 * Porownanie liczb zespolonych
 */
bool        operator == (LZespolona  L1,  LZespolona  L2);

/*!
 * Porownanie liczb zespolonych
 */
bool        operator != (LZespolona  L1,  LZespolona  L2);

/*!
 * Modul z liczby zespolonej
 */
double Modul(LZespolona L1);

/*!
 * Sprzezenie liczby zespolonej
 */
LZespolona Sprzezenie(LZespolona L1);

/*!
 * Wyswietla liczbe zespolona
 */
void Wyswietl(LZespolona Skl);

/*!
 * Tworzenie nowej liczby zespolonej z dwoch czesci rzeczywistych
 */
LZespolona Utworz(int re, int im);

/*!
 * Wczytuje i sprawdza poprawnosc wpisanego wyrazenia zespolonego
 */
bool Wczytaj(LZespolona &L);

#endif
