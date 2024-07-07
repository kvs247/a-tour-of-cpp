#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Greater_than
{
  int val;
  Greater_than(int v) : val{v} {}
  bool operator()(const pair<string, int> &r) const { return r.second > val; }
};

void f(map<string, int> &m)
{
  auto p = find_if(m.begin(), m.end(), Greater_than{42});
  // ...
}

// or use a lambda...

void g(map<string, int> &m)
{
  auto p = find_if(m.begin(), m.end(), [](const auto &r)
                   { return r.second > 42; });
}

int main()
{
  return 0;
}