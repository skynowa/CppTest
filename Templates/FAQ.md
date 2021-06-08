# Templates

## FAQ

* [todo] [www.geeksforgeeks.org](https://www.geeksforgeeks.org/templates-cpp/)
* [todo] https://www.youtube.com/watch?v=-PKyagrtIfs&feature=youtu.be
* [todo] https://www.youtube.com/watch?v=ULX_VTkMvf8

## Classes

* You can't have a virtual function template in a class — this would be meaningless —
but a virtual function in a class template is fine.

* Member function templates cannot be declared virtual. This constraint is imposed because the usual implementation of the virtual function call mechanism uses a fixed-size table with one entry per virtual function. However, the number of instantiations of a member function template is not fixed until the entire program has been translated. Hence, supporting virtual member function templates would require support for a whole new kind of mechanism in C++ compilers and linkers. In contrast, the ordinary members of class templates can be virtual because their number is fixed when a class is instantiated
