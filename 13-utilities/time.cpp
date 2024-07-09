#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

bool is_prime(long int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}

void do_work(int n)
{
  for (int i = 2; i < n; i++)
  {
    is_prime(i);
  }
}

int main()
{
  long int n = 1e7;

  auto t0 = high_resolution_clock::now();
  do_work(n);
  auto t1 = high_resolution_clock::now();

  cout << duration_cast<milliseconds>(t1 - t0).count() << "ms\n";

  // this_thread::sleep_for(10ms + 33us);

  return 0;
}