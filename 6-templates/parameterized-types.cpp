#include <iostream>
#include <list>
#include <string>       // Include this for std::string
#include <stdexcept>    // Include this for invalid_argument and out_of_range

using namespace std;

template <typename T>
class Vector
{
private:
  T *elem; // elem points to an array of sz elements of type T
  int sz;

public:
  explicit Vector(int s);      // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; } // destructor: release resources

  // ... copy and move operations ...

  T &operator[](int i);             // for non-const Vectors
  const T &operator[](int i) const; // for const Vectors
  int size() const { return sz; }
};

template <typename T>
Vector<T>::Vector(int s)
{
  if (s < 0)
    throw invalid_argument("negative value");
  elem = new T[s];
  sz = s;
}

template <typename T>
T &Vector<T>::operator[](int i)
{
  if (i < 0 || size() <= i)
    throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

template <typename T>
const T &Vector<T>::operator[](int i) const
{
  if (i < 0 || size() <= i)
    throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

void write(const Vector<string> &vs)
{
  for (int i = 0; i != vs.size(); i++)
    cout << vs[i] << '\n';
}

template <typename T>
T *begin(Vector<T> &x)
{
  return x.size() ? &x[0] : nullptr;
}

template <typename T>
T *end(Vector<T> &x)
{
  return x.size() ? &x[0] + x.size() : nullptr;
}

void write2(Vector<string> &vs)
{
  for (auto &s : vs)
    cout << s << '\n';
}

int main()
{
  Vector<char> vc(200);
  Vector<string> vs(17);
  Vector<list<int>> vl(45);

  for (int i = 0; i < 17; i++)
  {
    string s = "yo";
    for (int j = i; j > 0; j--)
      s += "yo";
    vs[i] = s;
  }

  write(vs);
  write2(vs);

  return 0;
}