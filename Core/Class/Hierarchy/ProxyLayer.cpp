/**
 * \file  ProxyLayer.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
             A() = default;
    virtual ~A() = default;

    virtual void foo(int i)
    {
        std::cout << "A::" << __FUNCTION__ << ": " << i << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class Proxy :
	public A
{
public:
    Proxy() = default;

    void foo(int i) override
    {
        std::cout << "Proxy::" << __FUNCTION__ << ": " << i << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class ProxyNo :
	public A
{
public:
    void foo(int i) override
    {
        std::cout << "ProxyNo::" << __FUNCTION__ << ": " << i << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class ProxyYes :
	public Proxy
{
public:
    void foo(int i) override
    {
        std::cout << "ProxyYes::" << __FUNCTION__ << ": " << i << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::map<int, A *> objects;
    objects[0] = new ProxyNo();
    objects[1] = new ProxyYes();

    for (auto &[key, value] : objects) {
        value->foo(key);

		delete value; value = nullptr;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

ProxyNo::foo:  0
ProxyYes::foo: 1

#endif
