 /*
 * \file  Main.cpp
 * \brief virtual inheritance
 */
 
 /*
    ��� ����� ���� � ��� 3 ����������� ����������� ������ � (B1..B3) 
    � ����� � �������� � ����:

        class C : 
            public virtual B1, public virtual B2, public virtual B3

    ������� ����� ����� �?
*/


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
class A {
    public:
        A () {
            std::cout << __FUNCTION__ << std::endl;
        }
        virtual ~A() {
            std::cout << __FUNCTION__ << std::endl;
        }
};
//---------------------------------------------------------------------------
class B1 :
    public virtual A
{
    public:
        B1 () {
            std::cout << __FUNCTION__ << std::endl;
        }  
};

class B2 :
    public virtual A
{
    public:
        B2 () {
            std::cout << __FUNCTION__ << std::endl;
        }  
};

class B3 :
    public virtual A
{
    public:
        B3 () {
            std::cout << __FUNCTION__ << std::endl;
        }  
};
//---------------------------------------------------------------------------
class C : 
    public virtual B1, 
    public virtual B2, 
    public virtual B3
{
    public:
        C () {
            std::cout << __FUNCTION__ << std::endl;
        } 
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    C objC;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

A::A
B1::B1
B2::B2
B3::B3
C::C

#endif