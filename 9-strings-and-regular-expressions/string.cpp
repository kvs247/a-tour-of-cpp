#include <iostream>
#include <string>

using namespace std;

string name = "Claire Schneider";

void m3()
{
  string s = name.substr(7, 15);
  cout << "s: " << name.substr(7, 15) << endl;
  name.replace(0, 6, "bernie");
  name[0] = toupper(name[0]);
}

int main()
{
  cout << name << endl;
  m3();
  cout << name << endl;

  return 0;
}