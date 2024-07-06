#include <iostream>

using namespace std;

template <typename T, typename... Tail>
void print(T head, Tail... tail)
{
  cout << head << ' ';
  if constexpr(sizeof...(tail) > 0)
    print(tail...);
}

void user()
{
  print("first:" , 1, 2.2, "hello\n"s);

  print("\nsecond: ", 0.2, 'c', "yuck!"s, 0, 1, 2, '\n');
}

int main()
{
  user();

  return 0;
}