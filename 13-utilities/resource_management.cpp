#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
using namespace std;

// 13.2.1 unique_ptr and shared_ptr

struct X
{
};

struct Z
{
};

void f(int i, int j)
{
  X *p = new X;            // allocate a new X
  unique_ptr<X> sp{new X}; // allocate a new X and give its pointer to unique_ptr
  // ...

  if (i < 99)
    throw Z{}; // may throw an exception
  if (j < 77)
    return; // may return "early"
  // ... use p and sp ...
  delete p; // destroy *p
}
// We "forgot" to delete p if i < 99 or j < 77. Conversley, unique_ptr ensures
// that its object is properly destroyed whichever way we exit f(). We could
// also have avoided the problem by just using a local variable (X x;)

// the shared_ptr is similar to unique_ptr except that shared_ptr's are copied
// rather than moved. The shared_ptr's for an object share ownership of an
// object; that object is destroyed when the last of its shared_ptr's is
// destroyed. For example:

struct No_file
{
};

void f(shared_ptr<fstream>){};
void g(shared_ptr<fstream>){};

void user(const string &name, ios_base::openmode mode)
{
  shared_ptr<fstream> fp{new fstream(name, mode)};
  if (!*fp)
    throw No_file{};

  f(fp);
  g(fp);
  // ...
}

// Using smart pointers has some associated common mistakes, so there are
// functions for constructing such smart pointers:
struct S
{
  int i;
  string s;
  double d;
  // ...

  S(int i_, string s_, double d_) : i(i_), s(s_), d(d_) {}
};

auto p1 = make_shared<S>(1, "Ankh Morpork", 4.65); // p1 is a shared_ptr<S>
auto p2 = make_unique<S>(2, "Oz", 7.62);           // p2 is a unique_ptr<S>

// 13.2.2 move() and forward()
// The choice between moving and copying is mostly implicit, but sometimes we
// must be explicit. For example, a unique_ptr is the sole owner of an object.
// Consequently, it cannot be copied:
void f1()
{
  auto p = make_unique<int>(2);
  // auto q = p; // error: we can't copy a unique_ptr
  // ...
}

// You must move a unique_ptr to use it elsewhere:
void f2()
{
  auto p = make_unique<int>(2);
  auto q = move(p); // p now holds nullptr
  // ...

  cout << *q << '\n';
}

// use of move():
template <typename T>
void swap(T &a, T &b)
{
  T tmp{move(a)}; // the T constructor sees and rvalue and moves
  a = move(b);    // the T assignment sees an rvalue and moves
  b = move(tmp);  // the T assignment Sees and rvalue and moves
}

// Caution:
void careful()
{
  string s1 = "Hello";
  string s2 = "World";
  vector<string> v;
  v.push_back(s1);       // use "const string&" argument; push_back() will copy
  v.push_back(move(s2)); // use a move constructor
}
// s1 is copied whereas s2 is moved. Somethis this makes the s2 push_back
// cheaper, but the moved-from object s2 is left behind. If s2 is used again,
// there will be a problem. Don't use move() unless it provides considerable
// performance improvement.

int main()
{
  f2();

  return 0;
}