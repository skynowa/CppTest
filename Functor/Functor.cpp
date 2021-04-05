/**
 * \file
 * \brief
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
void
Function (int i) {
    std::cout << "Function: i = " << i << std::endl;
}

struct SFunctor {
    void operator() (int i) {
        std::cout << "SFunctor: i = " << i << std::endl;
    }
} functor_t;

class CFunctor
{
public:
    void operator() (int i) {
        std::cout << "CFunctor: i = " << i << std::endl;
    }
};

class CFunctorParams
{
public:

    std::string m_sStr1;
    std::string m_sStr2;

         CFunctorParams(const std::string &csStr1, const std::string &csStr2) :
                            m_sStr1(csStr1),
                            m_sStr2(csStr2) { /**/ }
        ~CFunctorParams() { /**/ }

    void operator() (int i) {
        std::cout << "CFunctorParams: i = " << i;
        std::cout << "  params: " << m_sStr1 << ", " << m_sStr1 << std::endl;
    }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::list<int> cont;

    cont.push_back(0);
    cont.push_back(1);
    cont.push_back(2);

    std::for_each(cont.begin(), cont.end(), Function);
    std::cout << "----------" << std::endl;

    std::for_each(cont.begin(), cont.end(), functor_t);
    std::cout << "----------" << std::endl;

    std::for_each(cont.begin(), cont.end(), CFunctor());
    std::cout << "----------" << std::endl;

    std::for_each(cont.begin(), cont.end(), CFunctorParams("string_1", "string_2"));
    std::cout << "----------" << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

$ ./Functor

    Function: i = 0
    Function: i = 1
    Function: i = 2
    ----------
    SFunctor: i = 0
    SFunctor: i = 1
    SFunctor: i = 2
    ----------
    CFunctor: i = 0
    CFunctor: i = 1
    CFunctor: i = 2
    ----------
    CFunctorParams: i = 0  params: string_1, string_1
    CFunctorParams: i = 1  params: string_1, string_1
    CFunctorParams: i = 2  params: string_1, string_1


#endif
