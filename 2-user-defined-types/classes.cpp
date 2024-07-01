#include <iostream>

using namespace std;

class Vector
{
public:
  Vector(int s) : elem{new double[s]}, sz(s) {} // construct a vector
  double &operator[](int i) { return elem[i]; } // element access: subscripting
  int size() { return sz; }
  void print(void) {
    cout << "[";
    for (int i = 0; i < size(); i++)
    {
      cout << elem[i];
      if (i != size() - 1)
        cout << ' ';
    }
    cout << "]\n";
  }

private:
  double *elem;
  int sz;
};

int main()
{
  Vector v(6);
  for (int i = 0; i < v.size(); i++)
    v[i] = i * i;

  v.print();
}