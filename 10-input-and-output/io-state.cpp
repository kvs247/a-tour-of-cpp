#include <iostream>
#include <vector>

using namespace std;

vector<int> read_ints(istream &is, const string &terminator)
{
  vector<int> res;
  for (int i; is >> i;)
    res.push_back(i);

  if (is.eof()) // fine: end of file
    return res;

  if (is.fail()) // we failed to read an int; was it the terminator?
  {
    is.clear(); // reset the state to good()
    is.unget(); // put the non-digit back into the stream
    string s;
    if (cin >> s && s == terminator)
      return res;
    cin.setstate(ios_base::failbit); // add fail() to cin's state
  }

  return res;
}

int main()
{
  auto v = read_ints(cin, "stop");

  cout << '\n[';
  for (auto x : v)
    cout << x << ' ';
  cout << "]\n";

  return 0;
}