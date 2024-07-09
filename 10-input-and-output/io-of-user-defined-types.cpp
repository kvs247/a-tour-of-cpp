#include <iostream>

using namespace std;

struct Entry
{
  string name;
  long int number;
};

ostream &operator<<(ostream &os, const Entry &e)
{
  return os << "{\"" << e.name << "\"," << e.number << "}";
}

istream &operator>>(istream &is, Entry &e)
// read {"name", number} pair. Note: formatted with {"", and}
{
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') // start with a { followed by a "
  {
    string name;
    while (is.get(c) && c != '"')
      name += c;

    if (is >> c && c == ',')
    {
      long int number = 0;
      if (is >> number >> c && c == '}') // read the number and a }
      {
        e = {name, number}; // assign to the entry
        return is;
      }
    }
  }
  is.setstate(ios_base::failbit);
  return is;
}

int main()
{
  struct Entry e
  {
    "Kyle", 7195020701
  };
  cout << e << endl;

  struct Entry e2;
  cin >> e2;
  cout << endl
       << e2 << endl;

  return 0;
}