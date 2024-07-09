#include <iostream>
#include <string>

using namespace std;

// The standard library offers 'string_view', a (pointer, length) pair denoting
// a sequence of characters. This is, for example, useful for substrings.

string cat(string_view sv1, string_view sv2)
{
  string res{sv1};
  return res += sv2;
}

void user()
{
  string king = "Harold";
  auto s1 = cat(king, "William");       // string and const char*
  auto s2 = cat(king, king);            // string and string
  auto s3 = cat("Edward", "Stephen"sv); // const char* and string_view
  auto s4 = cat("Canute"sv, king);
  auto s5 = cat({&king[0], 2}, "Henry"sv);     // HaHenry
  auto s6 = cat({&king[0], 2}, {&king[2], 4}); // Harold

  cout << s1 << endl
       << s2 << endl
       << s3 << endl
       << s4 << endl
       << s5 << endl
       << s6 << endl;
}

// the 'sv' (string view) suffix requires 'using namespace std::literals::string_view_literals;'

string_view bad()
{
  string s = "Once upon a time";
  return {&s[5], 4}; // bad: returning a pointer to a local
}
// the returned string is destroyed after returning to the caller

int main()
{
  user();

  string_view bsv = bad();
  cout << bsv << endl;

  return 0;
}