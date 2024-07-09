#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main_old()
{
  string from, to;
  cin >> from >> to; // get source and target file names

  ifstream is{from};
  istream_iterator<string> ii{is}; // input iterator from stream
  istream_iterator<string> eos{};  // input sentinel

  ofstream os{to};                       // output stream for file "to"
  ostream_iterator<string> oo{os, "\n"}; // output iterator for stream

  vector<string> b{ii, eos}; // b is a vector initialized from input
  sort(b.begin(), b.end());  // sort the buffer

  unique_copy(b.begin(), b.end(), oo); // copy buffer to output, discard replicated values

  return !is.eof() || !os; // return error state
}

// We can use set() instead of vector with sort and unique_copy since a set
// does not keep duplicates and keeps elements in order.
// We can also be more efficient with ii, eos, and oo.
int main()
{
  string from, to;
  cin >> from >> to; // get source and target file names

  ifstream is{from}; // input stream for file "from"
  ofstream os{to};   // output stream for file "to"

  set<string> b // read input
      {
          istream_iterator<string>{is}, istream_iterator<string>{}};
  copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"}); // copy to output

  return !is.eof() || !os; // return error state
}