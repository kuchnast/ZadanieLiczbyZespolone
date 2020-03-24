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
 * Dzielenie liczby zespolonej przez rzeczywista
 */
LZespolona  operator / (LZespolona  L1,  double R);

/*!
 * Dzielenie zespolone
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2);

/*!
 * Porownanie liczb zespolonych
 */
bool operator == (LZespolona  L1,  LZespolona  L2);

/*!
 * Porownanie liczb zespolonych
 */
bool operator != (LZespolona  L1,  LZespolona  L2);

/*!
 * Porownanie liczby zespolonej i rzeczywistej
 */
bool operator == (LZespolona  L,  double R);

/*!
 * Porownanie liczby zespolonej i rzeczywistej
 */
bool operator != (LZespolona  L,  double R);

/*!
 * Modul z liczby zespolonej
 */
double Modul(LZespolona L1);

/*!
 * Sprzezenie liczby zespolonej
 */
LZespolona Sprzezenie(LZespolona L1);

/*!
 * Tworzenie nowej liczby zespolonej z dwoch czesci rzeczywistych
 */
LZespolona Utworz(double re, double im);

/*!
 * Wczytuje i sprawdza poprawnosc liczby zespolonej
 */
std::istream & operator >> (std::istream & strm, LZespolona & L);

/*!
 * Wyswietla liczbe zespolona
 */
std::ostream & operator << (std::ostream & strm, const LZespolona & L);


#endif
