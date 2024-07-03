#include <iostream>

using namespace std;

class Vector
{
public:
  Vector(int s) : elem{new double[s]}, sz{s} // constructor: acquire resources
  {
    for (int i = 0; i < s; i++) // initialize elements
      elem[i] = 0;
  }

  Vector(std::initializer_list<double>); // initialize with a list of doubles
  // ...

  ~Vector() { delete[] elem; } // destructor: release resources

  void push_back(double); // add element at end, increasing the size by one

  void print(void)
  {
    cout << "[";
    for (int i = 0; i < sz; i++)
    {
      cout << elem[i];
      if (i != sz - 1)
        cout << ' ';
    }
    cout << "]\n";
  }

  double &operator[](int i) { return elem[i]; }
  int size() const { return sz; };

private:
  double *elem; // array of sz doubles
  int sz;
};

void fct(int n)
{
  Vector v(n);
  // use v...
  {
    Vector v2(2 * n);
    // use v2...
  } // v2 is destroyed here
  // use v...
} // v is destroyed here

// Resource Acquisition Is Initialization (RAII)

int main()
{
  // Vector v(3);

  // for (int i = 0; i < v.size(); i++)
    // cin >> v[i];

  Vector v = {4, 6, 2};

  v.print();

  return 0;
}