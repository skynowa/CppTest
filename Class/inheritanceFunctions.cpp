#include <StdTest.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
//---------------------------------------------------------------------------
class A {
	public:
		             A   () { STD_TRACE_FUNC; }
		            ~A   () { STD_TRACE_FUNC; }

		virtual void vFoo() { STD_TRACE_FUNC; }
};
//---------------------------------------------------------------------------
class B : public A {
	public:
					 B()    { STD_TRACE_FUNC; }
					~B()    { STD_TRACE_FUNC; }

		virtual void vFoo() { STD_TRACE_FUNC; }
};
//---------------------------------------------------------------------------
class C : public A {
	public:
		             C()   { STD_TRACE_FUNC; }
		            ~C()   { STD_TRACE_FUNC; }

		virtual void vFoo() { STD_TRACE_FUNC; }

};
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//-------------------------------------
	//
	{
		A *a = new A();
		a->vFoo();
		std:: cout << "----------" << std::endl;

		A *b = new B();
		b->vFoo();
		std:: cout << "----------" << std::endl;

		A *c = new C();
		c->vFoo();
		std:: cout << "----------" << std::endl;

		delete c;
		std:: cout << "----------" << std::endl;
		delete b;
		std:: cout << "----------" << std::endl;
		delete a;
		std:: cout << "----------" << std::endl;

		/*
		A::A
		A::vFoo
		----------
		A::A
		B::B
		B::vFoo
		----------
		A::A
		C::C
		C::vFoo
		----------
		A::~A
		----------
		A::~A
		----------
		A::~A
		----------
		*/
	}

	return 0;
}
//---------------------------------------------------------------------------
