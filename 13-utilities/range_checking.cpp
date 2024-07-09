// Range errors are a classic source of serious erros in C and C++ programs.

#include <iostream>

using namespace std;

void fpn(int *p, int n)
{
  for (int i = 0; i < n; ++i)
    p[i] = 0;
}
// Assumes p points to n integers, which is merely a convention.
// This does not allow range-for loops and the compiler cannot implement
// cheap and effective range checking. This assumption can also be wrong:
void use(int x)
{
  int a[100];
  fpn(a, 100);      // OK
  fpn(a, 1000);     // oops, my finger slipped! (range error in fpn)
  fpn(a + 10, 100); // range error in fpn
  fpn(a, x);        // suspect, but looks innocent
}

int main()
{
  return 0;
}