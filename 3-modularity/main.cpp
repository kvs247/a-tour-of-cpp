#include <iostream>

using namespace std;

struct Entry
{
  string name;
  int value;

  void print()
  {
    cout << "name: " << name << " value: " << value << endl;
  };
};

Entry readEntry(istream &is)
{
  string s;
  int i;
  is >> s >> i;
  return {s, i};
}

int main()
{
  // struct Entry e = readEntry(cin);
  // e.print();

  auto [name, value] = readEntry(cin);
  cout << "{" << name << " , " << value << "}\n";
};