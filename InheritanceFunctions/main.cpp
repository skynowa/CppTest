#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tchar.h>

#include <XLib/xCommon.h>
//---------------------------------------------------------------------------
class A {
	public:
		             A   () { xSTD_COUT(__FUNCTION__) }
		            ~A   () { xSTD_COUT(__FUNCTION__) }

		virtual void vFoo() { xSTD_COUT(__FUNCTION__) }
};
//---------------------------------------------------------------------------
class B : public A {
	public:
					 B()    { xSTD_COUT(__FUNCTION__) }
					~B()    { xSTD_COUT(__FUNCTION__) }

		virtual void vFoo() { xSTD_COUT(__FUNCTION__) }
};
//---------------------------------------------------------------------------
class C : public A {
	public:
		             C()   { xSTD_COUT(__FUNCTION__) }
		            ~C()   { xSTD_COUT(__FUNCTION__) }

		virtual void vFoo() { xSTD_COUT(__FUNCTION__) }

};
//---------------------------------------------------------------------------
int _tmain(int argc, TCHAR *argv[]) {
	//-------------------------------------
	//
	{
		A *a = new A();
		a->vFoo();
		xSTD_COUT("----------");

		A *b = new B();
		b->vFoo();
		xSTD_COUT("----------");

		A *c = new C();
		c->vFoo();
		xSTD_COUT("----------");

		xDELETE_PTR(c);
		xSTD_COUT("----------");
		xDELETE_PTR(b);
		xSTD_COUT("----------");
		xDELETE_PTR(a);
		xSTD_COUT("----------");

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



	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
