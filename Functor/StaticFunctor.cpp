/**
 * \file  main.cpp
 * \brief filecomment
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <assert.h>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
//---------------------------------------------------------------------------
class CFunctor
{
public:
    CFunctor() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~CFunctor() {
        std::cout << __FUNCTION__ << std::endl;
    }

    void operator() (int i) {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//---------------------------------------------------------------------------
class CStaticFunctor
{
public:
    CStaticFunctor() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~CStaticFunctor() {
        std::cout << __FUNCTION__ << std::endl;
    }

    static void
    exec(int i) {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::list<int> cont;

    cont.push_back(0);
    cont.push_back(1);
    cont.push_back(2);

    {
        std::for_each(cont.begin(), cont.end(), CFunctor());
        std::cout << "----------" << std::endl;
    }

    {
        std::for_each(cont.begin(), cont.end(), CStaticFunctor::exec);
        std::cout << "----------" << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

// VC2012
#if OUTPUT

    CFunctor::CFunctor
    CFunctor::operator ()
    CFunctor::operator ()
    CFunctor::operator ()
    CFunctor::~CFunctor
    CFunctor::~CFunctor
    CFunctor::~CFunctor
    CFunctor::~CFunctor
    ----------
    CStaticFunctor::exec
    CStaticFunctor::exec
    CStaticFunctor::exec
    ----------

#endif

// GCC
#if OUTPUT

    CFunctor
    operator()
    operator()
    operator()
    ~CFunctor
    ~CFunctor
    ----------
    exec
    exec
    exec
    ----------

#endif
