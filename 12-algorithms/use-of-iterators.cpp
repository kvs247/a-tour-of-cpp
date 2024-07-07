#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
using Iterator = typename T::iterator; // alias: T's iterator

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v) // find all occurences of v in c
{
  vector<Iterator<C>> res;
  for (auto p = c.begin(); p != c.end(); ++p)
    if (*p == v)
      res.push_back(p);
  return res;
}

void test()
{
  string m {"Mary had a little lamb"};

  for (auto p : find_all(m, 'a'))
    if (*p != 'a')
      cerr << "string bug!\n";

  list<int> ld {1, 2, 3, 1, -11, 2};
  for (auto p : find_all(ld, 1))
    if (*p != 1)
      cerr << "list bug!\n";

  vector<string> vs {"red", "blue", "green", "orange", "green"};
  for (auto p : find_all(vs, "red"))
    if (*p != "red")
      cerr << "vector bug!\n";
  for (auto p : find_all(vs, "green"))
    *p = "vert";  
}

int main()
{
  test();

  return 0;
}