#include <iostream>
#include <list>

using namespace std;

class Container
{
public:
  virtual double &operator[](int) = 0; // pure virtual function
  virtual int size() const = 0;        // const member function
  virtual ~Container() {}              // destructor
};

void use(Container &c)
{
  const int sz = c.size();

  for (int i = 0; i != sz; i++)
    cout << c[i] << '\n';
}

class List_container : public Container // List_container implements Container
{
public:
  List_container() {} // empty list
  List_container(initializer_list<double> il) : Id{il} {}
  ~List_container() {}

  double &operator[](int i) override;
  int size() const override { return Id.size(); }

private:
  std::list<double> Id;
};

double &List_container::operator[](int i)
{
  for (auto &x : Id)
  {
    if (i == 0)
      return x;
    i--;
  }
  throw out_of_range{"List container"};
};

void h()
{
  List_container lc = {1,2,3,4,5,6,7,8,9};
  use(lc);
}

int main()
{
  h();

  return 0;
}