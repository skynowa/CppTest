/**
 * \file  main.cpp
 * \brief filecomment
 */


//---------------------------------------------------------------------------
#include <unistd.h>
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
        std::cout << "Functor: i = " << i << std::endl;
    }
} functor_t;
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    std::list<int> cont;

    cont.push_back(0);
    cont.push_back(1);
    cont.push_back(2);

    std::for_each(cont.begin(), cont.end(), Function);

    std::cout << "----------" << std::endl;

    std::for_each(cont.begin(), cont.end(), functor_t);

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

$ ./Functor

    Function: i = 0
    Function: i = 1
    Function: i = 2
    ----------
    Functor: i = 0
    Functor: i = 1
    Functor: i = 2

#endif
