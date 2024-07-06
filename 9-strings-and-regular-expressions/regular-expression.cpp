#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

void use()
{
  ifstream in("file.txt");
  if (!in)
    cerr << "no file\n";

  regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};

  int lineno = 0;
  for (string line; getline(in, line);)
  {
    ++lineno;
    smatch matches; // matched string go here
    if (regex_search(line, matches, pat))
    {
      cout << lineno << ":" << matches[0] << '\n';  // the complete match
      if (1 < matches.size() && matches[1].matched) // if there is a sub-pattern
                                                    // and if it is matched
        cout << "\t:" << matches[1] << '\n';        // submatch
    }
  }
}

int main()
{
  use();

  return 0;
}