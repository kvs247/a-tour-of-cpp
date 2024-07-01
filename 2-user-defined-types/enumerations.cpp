#include <iostream>

using namespace std;

enum class Color { red, green, blue };

int main()
{
  int x;
  cin >> x;
  Color y {x};

  switch (y)
  {
    case Color::red:
      cout << "red\n";
      break;
    case Color::green:
      cout << "green\n";
      break;
    case Color::blue:
      cout << "blue\n";
      break;
  }

  return 0;
}