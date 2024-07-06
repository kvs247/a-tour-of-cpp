#include <iostream>
#include <vector>
#include <string>
#include <concepts>

using namespace std;

// 7.2.1 Use of Concepts
// This function requires that its first template argument is some kind of
// sequence and its second template argument is some kind of number. We call
// such requirements 'concepts'.
// template<typename Seq, typename Num>
// Num sum(Seq s, Num v)
// {
//   for (const auto& x : s)
//     v += x;
//   return v;
// }

// The following notation contraints the arguments of sum() to be such that
// the first argument is a sequence and the second argument a number such that
// elements of the sequence can be added to the number (arithmetic applies)
// template <Sequence Seq, Number Num>
//   requires Arithmetic<Value_type<Seq>, Num>
// Num sum(Seq s, Num v)
// {
//   for (const auto &x : s)
//     v += x;
//   return v;
// }

// 7.2.3 Valid Code 
// The question of whether a set of template arguments offers what a template
// requires of its template parameters ultimately boils down to whether some
// expressions are valid. Using a 'requires'-expression, we can check if a set
// of expressions is valid.
// template <Forward_iterator Iter, int n>
//   requires requires(Iter p, int i) { p[i]; p + i; } // iter has subscripting and addition
// void advance(Iter p, int n)
// {
//   p += n; // a random-access iterator has +=
// }
// The first requires starts the requirements-clause and the second requires
// starts the requires-expression. A requires-expression is a predicate that
// is true if the statements in it are valid code and false if they are not.
// This implementation is deliberately inelegant and hackish.

// 7.2.4 Definition of Concepts (C++20)
// template<typename T>
// concept Equality_comparable = 
//   requires (T a, T b)
//   {
//     { a == b} -> bool; // compare Ts with ==
//     { a != b } -> bool; // compare Ts with !=
//   };

// The process of generalizing from a concrete piece of code (and preferably
// from several) while preserving performance is called 'lifting'. Conversely,
// the best way to develop a template is often to
//   - first, write a concrete version
//   - then, debug, test, and measure it
//   - finally, replace the concrete types with template arguments.

int main()
{
  return 0;
}