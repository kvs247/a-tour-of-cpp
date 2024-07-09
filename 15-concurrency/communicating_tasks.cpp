#include <iostream>
#include <thread>
#include <future>
#include <numeric>
#include <vector>

using namespace std;

// 15.7.1 future and promise
// Transfer of a value between two tasks without explicit use of a lock.

struct X
{
};

void f(promise<X> &px) // a task: place the result in px
{
  // ...
  try
  {
    X res;
    // ... compute a value for res ...
    px.set_value(res);
  }
  catch (...) // oops: couldn't compute res
  {
    px.set_exception(current_exception()); // pass the execption to the future's thread
  }
}

// To deal with an exception transmitted through a future, the caller of get()
// must be prepared to catch it somewhere.
void g(future<X> &fx) // a task: get result from fx
{
  // ...
  try
  {
    X v = fx.get(); // if necessary, wait for the value to get computed
    // ... use v ...
  }
  catch (...) // oops: someone couldn't compute v
  {
    // ... handle error ...
  }
}

// 15.7.2 packaged_task
// A packaged_task simplifies setting up tasks connected with futures and
// promises to be run on threads.

double accum(double *beg, double *end, double init)
// compute the sum of [beg:end) starting with the initial value init
{
  return accumulate(beg, end, init);
}

double comp2(vector<double> &v)
{
  using Task_type = double(double *, double *, double); // type of task

  packaged_task<Task_type> pt0{accum}; // package the task (i.e., accum)
  packaged_task<Task_type> pt1{accum};

  future<double> f0{pt0.get_future()}; // get hold of pt0's future
  future<double> f1{pt1.get_future()}; // get hold of pt1's futures

  double *first = &v[0];
  thread t1{move(pt0), first, first + v.size() / 2, 0};            // start a thread for pt0
  thread t2{move(pt1), first + v.size() / 2, first + v.size(), 0}; // start a thread for pt1

  // ...

  t1.join();
  t2.join();

  return f0.get() + f1.get();
}

// 15.7.3
// To launch tasks to potentially run asynchronously, we can use async():
double comp4(vector<double> &v)
// spawn many tasks if v is large enough
{
  if (v.size() < 10000) // Is it worth using concurrency?
    return accum(&*v.begin(), &*v.end(), 0.0);

  auto v0 = &v[0];
  auto sz = v.size();

  auto f0 = async(accum, v0, v0 + sz / 4, 0.0);              // first quarter
  auto f1 = async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);     // second quarter
  auto f2 = async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0); // third quarter
  auto f3 = async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0);     // fourth quarter

  return f0.get() + f1.get() + f2.get() + f3.get();
}

int main()
{
  vector<double> v = {1.0, 2.0, 3.5, 4.1};

  double sum = comp2(v);
  cout << sum << '\n';

  return 0;
}