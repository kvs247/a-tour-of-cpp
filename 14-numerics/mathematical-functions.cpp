#include <iostream>
#include <cmath>

using namespace std;

void f()
{
  errno = 0; // clear old error state
  sqrt(-1);
  if (errno == EDOM) // EDOM -> domain error
    cerr << "sqrt() not defined for negative argument\n";
  
  errno = 0; // clear old error state
  pow(numeric_limits<double>::max(), 2);
  if (errno == ERANGE) // ERANGE -> range error
    cerr << "result of pow() too large to represent as double\n";
}

int main()
{
  f();

  return 0;
}