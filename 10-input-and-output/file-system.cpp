#include <iostream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

void print_directory(path p)
{
  try
  {
    if (is_directory(p))
    {
      cout << p << ":\n";
      for (const directory_entry &x : directory_iterator{p})
        cout << "   " << x.path() << endl;
    }
  }
  catch (const filesystem_error &ex)
  {
    cerr << ex.what() << endl;
  }
}

int main()
{
  print_directory(".");
  print_directory("..");
  print_directory("/");
  print_directory("c:");

  for (string s; cin >> s;)
    print_directory(s);

  return 0;
}