/**
 * \file  OperatorFunctor.cpp
 * \brief operator() as functor
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Increment
    ///< Functor
{
public:
    Increment(int n) :
        num(n)
    {
    }

    // This operator overloading enables calling operator function () on objects of Increment
    int
    operator () (int arr_num) const
    {
        return num + arr_num;
    }

private:
    int num {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int arr[]  = {1, 2, 3, 4, 5};
    int n      = sizeof(arr) / sizeof(arr[0]);
    int to_add = 5;

    std::transform(arr, arr+n, arr, Increment(to_add));

    for (int i = 0; i < n; ++ i) {
        std::cout << arr[i] << " ";
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

6 7 8 9 10

#endif
