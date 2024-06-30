#include <stdio.h>
#include <iostream>

#define sqr(x) (x) * (x)

using namespace std; // make names visible from std without std::

int main()
{
  printf("stdio.h\n");
  std::cout << "std::cout <<\n";
  cout << "cout <<\n";

  double x = 3.14;
  cout << "the square of " << x << " is " << sqr(x) << "\n"; 

  return 0;
}