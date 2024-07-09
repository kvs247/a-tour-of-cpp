#include <iostream>

using namespace std;

class complex
{
  double re, im;

public:
  complex(double r, double i) : re{r}, im{i} {}
  complex(double r) : re{r}, im{0} {}
  complex() : re{0}, im{0} {}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() { return im; }
  void imag(double d) { im = d; }

  void print()
  {
    cout << re << (im >= 0.0 ? " + " : " - ") << abs(im) << "i\n";
  }

  complex &operator+=(complex z)
  {
    re += z.re;
    im += z.im;
    return *this;
  }

  complex &operator-=(complex z)
  {
    re -= z.re;
    im -= z.im;
    return *this;
  }

  complex &operator*=(complex z)
  {
    double nre = re * z.re - im * z.im;
    double nim = im * z.re + re * z.im;
    re = nre;
    im = nim;
    return *this;
  }

  complex &operator/=(complex z)
  {
    double nre = re * z.re + im * z.im;
    double nim = im * z.re - re * z.im;
    double d = im * im + z.im * z.im;
    re = nre / d;
    im = nim / d;
    return *this;
  }
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b)
{
  return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b)
{
  return !(a == b);
}

int main()
{
  complex a{-2, 5};
  complex b{4, -3};

  a *= b;
  a.print();

  b = -b;
  complex z = a + b;
  z.print();

  return 0;
}
