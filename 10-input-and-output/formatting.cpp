#include <iostream>

using namespace std;

int main()
{
  // We can output integers as decimal, octal, or hexadecimal numbers
  cout << 1234 << ',' << hex << 1234 << ',' << oct << 1234 << endl;

  constexpr double d = 123.456;

  cout << d << "; " // use the default format for d
    << scientific << d << "; " // use 1.123d2 style formatter for d
    << hexfloat << d << "; " // use hexadecimal notation for d
    << fixed << d << "; " // use 123.456 style for d
    << defaultfloat << d << endl; // use the default format for d

  cout.precision(8);
  cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << endl;

  cout.precision(4);
  cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << endl;
  cout << 1234.56789 << endl;

  return 0;
}