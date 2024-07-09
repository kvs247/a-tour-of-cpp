#include <iostream>

using namespace std;

// 5.2.1 Copying Containers

// The default memberwise copy is sometimes appropriate (usually is for concrete types)
// For Vector, memberwise copy will produces two pointers to the same memory: a disaster
// Memberwise copy is almost never appropriate for abstract types

class Vector
{
private:
  double *elem;
  int sz;

public:
  Vector(int s);               // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; } // destructor: release resources

  Vector(const Vector &a);            // copy constructor
  Vector &operator=(const Vector &a); // copy assignment

  double &operator[](int i);
  const double &operator[](int i) const;

  int size() const;
};

Vector::Vector(const Vector &a) // copy constructor
    : elem{new double[a.sz]},   // allocate space for elements
      sz{a.sz}
{
  for (int i = 0; i < sz; i++)
    elem[i] = a.elem[i];
}

Vector &Vector::operator=(const Vector &a)
{
  double *p = new double[a.sz];
  for (int i = 0; i < a.sz; i++)
    p[i] = a.elem[i];
  delete[] elem; // delete old elements
  elem = p;
  sz = a.sz;
  return *this;
}

// 5.2.2 Moving Containers

// Defining a + operator on Vector and then doing something like
//   z = v1 + v2 + v3
// would create local Vector instances that are return after the + operation
// and copied to z. This can be costly and ineffect for large amouts of data.
// Instead, we would prefer to move the result vector instead of copy it

// class Vector
// {
//   // ..
//   Vector(const Vector &a);            // copy constructor
//   Vector &operator=(const Vector &a); // copy assignment

//   Vector(Vector &&a);            // move constructor
//   Vector &operator=(Vector &&a); // move assignment
// };

// Given this definition, the compiler will choose the move constructor to
// implement the transfer of the return value out of the function. This means
// that z = v1 + v2 + v3 will involve no copying of Vectors, just moving
// Vector's move constructor is trivial to define:

// Vector::Vector(Vector &&a)
//   : elem{a.elem}, // "grab the elements" from a
//   z{a, sz}
// {
//   a.elem = nullptr; // now a has no elements
//   a.sz = 0;
// }

// The && means "rvalue reference" and is a reference to which we can bind an 
// rvalue. The word "rvalue" is intended to complement "lvalue", which roughly
// means "something that can appear on the left-hand side of an assignment." So
// an rvalue is - to a first approximation - a value that you can't assign to,
// such as an integer returned by a function call. Thus, an rvalue reference 
// is a reference to something that nobody else can assign to, so we can safely
// "steal" its value.  

int main()
{
  return 0;
}
