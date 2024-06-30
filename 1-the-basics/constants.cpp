// const: "I promise not to change this value." The value of a const can be
// calculated at run time.
// constexpr: "To be evaluated at compile time." The value of a constexpr must
// be calculated by the compiler.
//    - constexpr function cannot be defined inside another function

constexpr double square(double x) { return x * x; }

int main()
{
  int var = 17;

  constexpr double max1 = 1.4 * square(17);   // OK: 1.4*square(17) is a constant expression
  // constexpr double max2 = 1.4 * square(var);  // error: var is not a constant expression
  const double max3 = 1.4 * square(var);      // OK: may be evaluated at run time

  constexpr int constexpr_var = 17;

  constexpr double max4 = 1.4 * square(constexpr_var);

  return 0;
}