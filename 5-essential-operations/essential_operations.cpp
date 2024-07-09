#include <iostream>

using namespace std;

class X
{
public:
  X(int);                  // "ordinary constructor": create object
  X();                     // default constructor
  X(const X &);            // copy constructor
  X(X &&);                 // move constructor
  X &operator=(const X &); // copy assignment: clean up target and copy
  X &operator=(X &&);      // move assignment: clen up target and move
  ~X();                    // destructor: clean up
  // ...
};

// If you want to be explicit about generating default implementations, you can
class Y
{
public:
  Y(int);
  Y(const Y &) = default; // I really do want the default copy constructor
  Y(Y &&) = default;      // and the default move constructor
};

class Shape
{
public:
  Shape(const Shape &) = delete; // no copy operations
  Shape &operator=(const Shape &) = delete;
  // ...
};

void copy(Shape &s1, const Shape &s2)
{
  s1 = s2; // error: Shape copy is deleted
}

// Conversion

// in the previous Vector definition, the defintion
//   Vector v = 7;
// would be OK and create a vector with 7 elements. This is not ideal

class Vector
{
public:
  explicit Vector(int s); // no implicit conversion from int to Vector
  // ...
};

// This gives
//   Vector v1(7);  // OK; v1 has 7 elements
//   Vector v2 = 7; // error:  no implicit conversions from int to Vector
// -> use `explicit` for constructors that take a single argument unless there is good reason not to

// Member Initializers

// can initialize class memebers with a default value 
class complex
{
  double re = 0;
  double im = 0;

public:
  complex(double r, double i) : re{r}, im{i} {}
  complex(double r) : re{r} {}
  complex() {}
  // ...
};

int main()
{
  return 0;
}