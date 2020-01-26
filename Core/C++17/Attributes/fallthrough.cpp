[[fallthrough]]

This attribute indicates that the break operator inside a case block is missing intentionally (i.e., control is passed to the next case block), and therefore, a compiler or static code analyzer warning should not be issued.

Quick example:

// C++17
switch (i)
{
case 10:
  f1();
  break;
case 20:
  f2();
  break;
case 30:
  f3();
  break;
case 40:
  f4();
  [[fallthrough]]; // The warning will be suppressed
case 50:
  f5();
}
