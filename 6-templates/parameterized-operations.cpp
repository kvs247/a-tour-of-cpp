#include <iostream>
#include <vector>

using namespace std;

// 6.3.1 Function Templates

// We can write a function that calculates the sum of the element values of any
// sequence that a range-for can traverse:
template <typename Sequence, typename Value>
Value sum(const Sequence &s, Value v)
{
  for (auto x : s)
    v += x;
  return v;
}

void use_sum()
{
  vector<int> v = {1, 2, 3, -1};

  int x = sum(v, 0);
  cout << x << endl;
}

// 6.3.2 Function Objects (Functor)

template <typename T>
class Less_than
{
  const T val; // value to compare against
public:
  Less_than(const T &v) : val{v} {}
  bool operator()(const T &x) const { return x < val; } // call operator
};

Less_than lti{42};              // lti(i) will compare i to 42 using < (i < 42)
Less_than lts("Backus"s);       // lts(s) will compare s to "Backus" using < (s < "Backus")
Less_than<string> lts2{"Naur"}; // "Naur" is a C-style string, so we need <string> to get the right <

// 6.3.3 Lambda Expressions

// find examples
// [&](int s){ return s * s; }

int main()
{
  use_sum();
}