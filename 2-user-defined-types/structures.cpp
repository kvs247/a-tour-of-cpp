#include <iostream>

using namespace std;

struct Vector
{
  int size;
  double *elem;
};

void vectorInit(Vector &v, int s)
{
  v.elem = new double[s];
  v.size = s;
}

// void vectorPrint(Vector &v, int s)
// {
//   cout << "[";
//   for (int i = 0; i < s; i++)
//   {
//     cout << v.ele[i];
//     if (i < s - 1)
//       cout << ' ';
//   }
//   cout << "]\n";
// }

void vectorPrint(Vector v, int s)
{
  cout << "[";
  for (int i = 0; i < s; i++, v.elem++)
  {
    cout << *v.elem;
    if (i < s - 1)
      cout << ' ';
  }
  cout << "]\n";
}

int main()
{
  Vector v;
  vectorInit(v, 5);

  for (int i = 0; i != 5; ++i)
    cin >> v.elem[i];

  vectorPrint(v, 5);

  return 0;
}