#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


Первый вариант

class A 
{
public:
   A() { cout << "A::A" << endl;}
   ~A(){ cout << "A::~A" << endl;}

}

class B : public A 
{
public:
   B() { cout << "B::B" << endl;}
   ~B(){ cout << "B::~B" << endl;}

}



Второй вариант

class A 
{
public:
   A() { cout << "A::A" << endl;}
   virtual ~A(){ cout << "A::~A" << endl;}

}

class B : public A 
{
public:
   B() { cout << "B::B" << endl;}
   ~B(){ cout << "B::~B" << endl;}

}



КодКод

A* pA = new B;
delete pA;




Результат работы кода
Первый вариант

A::A
B::B
A::~A



Второй вариант

A::A
B::B
B::~B
A::~A



Вопросы есть?
//---------------------------------------------------------------------------
int main(int argc, CHAR* argv[]) {
	X *x = new X();
	X *y = new Y();
	
	std::cout << x->getType() << "    " << y->getType() << "\n";

	delete x;
	delete y;

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
