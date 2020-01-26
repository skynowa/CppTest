[[nodiscard]]

This attribute is used to indicate that the return value of the function should not be ignored:

// C++17
[[nodiscard]] int Sum(int a, int b)
{
  return a + b;
}

int main()
{
  Sum(5, 6); // Compiler/analyzer warning will be issued
  return 0;
}
[[nodiscard]] can be also applied to data types or enumerations to mark all functions that return this type as [[nodiscard]]:

// C++17
struct [[nodiscard]] NoDiscardType
{
  char a;
  int b;
};

NoDiscardType Func()
{
  return {'a', 42};
}

int main()
{
  Func(); // Compiler/analyzer warning will be issued

  return 0;
}
