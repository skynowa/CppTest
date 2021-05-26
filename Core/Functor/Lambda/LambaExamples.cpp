/**
 * \file  LambaExamples.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Function to print vector
void printVector(std::vector<int> v)
{
    // lambda expression to print vector
    std::for_each(v.begin(), v.end(),
        [](int i)
        {
            std::cout << i << " ";
        });

    std::cout << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};

    printVector(v);

    // below snippet find first number greater than 4
    // find_if searches for an element for which
    // function(third argument) returns true
    auto p = std::find_if(v.begin(), v.end(),
        [](int i)
        {
            return i > 4;
        });

    std::cout << "First number greater than 4 is : " << *p << std::endl;


    // function to sort vector, lambda expression is for sorting in
    // non-decreasing order Compiler can make out return type as
    // bool, but shown here just for explanation
    std::sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });

    printVector(v);

    // function to count numbers greater than or equal to 5
    int count_5 = count_if(v.begin(), v.end(), [](int a)
    {
        return (a >= 5);
    });

    std::cout << "The number of elements greater than or equal to 5 is : "
         << count_5 << std::endl;

    // function for removing duplicate element (after sorting all
    // duplicate comes together)
    p = std::unique(v.begin(), v.end(), [](int a, int b)
    {
        return a == b;
    });

    // resizing vector to make size equal to total different number
    v.resize(std::distance(v.begin(), p));
    printVector(v);

    // accumulate function accumulate the container on the basis of
    // function provided as third argument
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = std::accumulate(arr, arr + 10, 1,
        [](int i, int j)
        {
            return i * j;
        });

    std::cout << "Factorial of 10 is : " << f << std::endl;

    // We can also access function by storing this into variable
    auto square = [](int i)
    {
        return i * i;
    };

    std::cout << "Square of 5 is : " << square(5) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

4 1 3 5 2 3 1 7
First number greater than 4 is : 5
7 5 4 3 3 2 1 1
The number of elements greater than or equal to 5 is : 2
7 5 4 3 2 1
Factorial of 10 is : 3628800
Square of 5 is : 25


#endif
