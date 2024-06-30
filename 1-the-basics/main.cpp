#include <iostream>

using namespace std;

int main()
{
  int x = 2;
  int y = 3;
  x = y;
  x++;

  cout << "x: " << x << " y: "<< y << '\n';

  int xx = 2;
  int yy = 3;
  int *xp = &xx;
  int *yp = &yy;
  xp = yp;
  (*xp)++; 

  cout << "x: " << *xp << " y: "<< *yp << '\n';

  return 0;
}