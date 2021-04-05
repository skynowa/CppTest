/**
 * \file
 * \brief
 *
 * \todo
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


class A
{
public:
   A() { std::cout << "A::A" << std::endl;}
   ~A(){ std::cout << "A::~A" << std::endl;}

};

class B : public A
{
public:
   B() { std::cout << "B::B" << std::endl;}
   ~B(){ std::cout << "B::~B" << std::endl;}

};
//---------------------------------------------------------------------------
int main(int, char **)
{
	A *x = new A();
	B *y = new B();

	delete x;
	delete y;

	return 0;
}
//---------------------------------------------------------------------------
