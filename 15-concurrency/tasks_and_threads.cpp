#include <iostream>
#include <thread>

using namespace std;

void f() // function
{
  cout << "Hello ";
}

struct F // function object
{
  void operator()() { cout << "Parallel World!\n"; } // F's call operator
};

void user()
{
  thread t1{f};   // f() executes in a separate thread
  thread t2{F()}; // F()() executes in a separate thread

  t1.join(); // wait for t1
  t2.join(); // wait for t2
}

int main()
{
  user();

  return 0;
}