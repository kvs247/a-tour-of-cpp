#include <iostream>
#include <list>

using namespace std;

struct Entry
{
  string name;
  int number;
};

ostream &operator<<(ostream &os, const Entry &e)
{
  return os << "{\"" << e.name << "\"," << e.number << "}";
}

list<Entry> phone_book{
    {"One", 111},
    {"Two", 222},
    {"Three", 333}};

int get_number(const string &s)
{
  for (auto p = phone_book.begin(); p != phone_book.end(); p++)
    if (p->name == s)
      return p->number;
  return -1; // -1 represents "number not found"
}

void f(const Entry &ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
  phone_book.insert(p, ee);
  phone_book.erase(q);
}

int main()
{
  cout << "Two: " << get_number("Two") << '\n';

  struct Entry ne
  {
    "Kyle", 5020701
  };
  f(ne, phone_book.begin(), next(phone_book.begin(), 2));

  for (auto p = phone_book.begin(); p != phone_book.end(); p++)
    cout << *p << '\n';

  return 0;
}