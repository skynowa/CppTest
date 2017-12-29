#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


//---------------------------------------------------------------------------
class X {
	public:
		virtual char getType(){return 'X';}
};
//---------------------------------------------------------------------------
class Y: public X {
	public:
		char getType(){return 'Y';}
};
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	X *x = new X();
	X *y = new Y();

	std::cout << x->getType() << "    " << y->getType() << "\n";

	delete x;
	delete y;

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
