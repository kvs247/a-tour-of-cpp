#include <iostream>
#include <map>

using namespace std;

map<string, int> phone_book
{
  {"One", 111},
  {"Two", 222},
  {"Three", 333}
};

int main()
{
  int n1 = phone_book["One"];
  cout << n1 << '\n';

  return 0;
}