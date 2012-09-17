#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


������ �������

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



������ �������

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



������

A* pA = new B;
delete pA;




��������� ������ ����
������ �������

A::A
B::B
A::~A



������ �������

A::A
B::B
B::~B
A::~A



������� ����?
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
