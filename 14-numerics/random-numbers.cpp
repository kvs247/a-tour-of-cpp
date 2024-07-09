#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

using my_engine = default_random_engine;
using my_distribution = uniform_int_distribution<>;

my_engine re{};                   // the default engine
my_distribution one_to_six{1, 6}; // distribution that maps to the ints 1..6
auto die = []()
{ return one_to_six(re); }; // make a generator

// put into a class
class Rand_int
{
public:
  Rand_int(double avg, double std) : dist{avg, std}, max_value(avg + 3 * std) {}
  int operator()()
  {
    int result = dist(re);
    return clamp(result, 0, static_cast<int>(max_value) - 1);
  }
  void seed(int s) { re.seed(s); } // choose new random engine seed
private:
  default_random_engine re;
  normal_distribution<double> dist;
  double max_value;
};

int main()
{
  int x = die();
  cout << "x: " << x << "\n\n";

  constexpr double avg = 24.2;
  constexpr double std = 2.1;
  Rand_int rnd{avg, std};

  time_t t = time(nullptr);
  auto now = chrono::system_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();
  rnd.seed(ms);

  constexpr int bucket_size = avg + 3 * std + 1;
  vector<int> histogram(bucket_size); // make a vector of appropriate size
  double rd;
  for (int i = 0; i != 200; i++)
    ++histogram[rnd()];

  for (int i = 0; i != histogram.size(); ++i)
  {
    printf("%d-%d:%4s", i, i + 1, "");
    for (int j = 0; j != histogram[i]; ++j)
      cout << '*';
    cout << '\n';
  }

  return 0;
}