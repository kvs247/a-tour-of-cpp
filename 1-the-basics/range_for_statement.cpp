#include <iostream>

using namespace std;

int main()
{
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto x : v)
    cout << x << '\n';

  cout << '\n';

  for (auto x : {2, 3, 5, 7, 11, 13})
    cout << x << '\n';

  cout << '\n';

  for (auto &x : v)
    cout << x++ << '\n';

  return 0;
}