/**
 * \file    IteratorPair.cpp
 * \brief   Specify a range of data values without worrying about the underlying data structure
 *
 * \warning Iterators should expose a fixed, minimal interface such as a **pre-increment operator**
 * \see     https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Iterator_Pair
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template <class T>
class Vector
    /// Iterator-pair class
{
public:
    template <class InputIterator>
    Vector(InputIterator begin, InputIterator end)
    {
        _mem = new T[ std::distance(begin, end) ];

        for (int i = 0; begin != end; ++ i) {
            _mem[i] = *begin;
            ++ begin;
        }
    }

    ~Vector()
    {
        delete [] _mem; _mem = {};
    }

private:
    T *_mem {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::list<int> l(4);
    std::cout << STD_TRACE_VAR(l) << std::endl;

    // fill up list using iterator pair technique
    std::fill(l.begin(), l.end(), 10);
    std::cout << STD_TRACE_VAR(l) << std::endl;

    // create vector using iterator pair technique
    std::vector<int> v(l.cbegin(), l.cend());
    std::cout << STD_TRACE_VAR(v) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

l: std::list (size=4): {0,0,0,0}
l: std::list (size=4): {10,10,10,10}
v: std::vector (size=4): {10,10,10,10}

#endif
