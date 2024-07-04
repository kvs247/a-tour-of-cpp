#include <iostream>
#include "container.cpp"

using namespace std;

class Container
{
public:
  virtual double &operator[](int) = 0; // pure virtual function
  virtual int size() const = 0;        // const member function
  virtual ~Container() {}              // destructor
};

// The word `virtual` means "may be redefined later in a class defined from this one"

// Use case:
void use(Container &c)
{
  const int sz = c.size();

  for (int i = 0; i < sz; i++)
    cout << c[i] << '\n';
}

// A class that provides the interface to a variety of other classes is often called a polymorphic type.

// Implementation of Container:
class Vector_container : public Container
{
public:
  Vector_container(int s) : v(s) {}
  ~Vector_container() {}

  double &operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }

private:
  Vector v;
};
// the use of `override` is optional, but being explicit allows the compiler to catch mistakes
// the defintion in the Vector_container implementation is overriding the Container interface

int main()
{
  // Container c; // error: there can be no objects of an abstract class
  Container *p = new Vector_container(10); // OK: Container is an interface

  return 0;
}