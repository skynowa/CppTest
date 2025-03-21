/**
 * \file  MultiArray2d.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <boost/multi_array.hpp>
//--------------------------------------------------------------------------------------------------
// safety: array dimensions and data tied into one, can't mix them up!
// also: type safety.
void
print(const boost::multi_array<double, 2> &array)
{
    for (std::size_t i = 0; i < array.shape()[0]; i++) {
        for (std::size_t j = 0; j < array.shape()[1]; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}
//--------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    const std::size_t m = (argc > 1) ? atoi(argv[1]) : 4;
    const std::size_t n = (argc > 2) ? atoi(argv[2]) : 5;

    boost::multi_array<double, 2> A(boost::extents[n][m]);

    for (std::size_t i = 0; i < n; i++)
        for (std::size_t j = 0; j < m; j++)
            A[i][j] = i * m + j;

    boost::multi_array<double, 2> B(boost::extents[n][m]);

    for (std::size_t i = 0; i < n; i++)
        for (std::size_t j = 0; j < m; j++)
            B[i][j] = i * m + j + 0.5;

    print(A);
    print(B);

    // safe copies, would even work with differing dimensions:
    B = A;
    print(B);

    // RAII: no manual free, no memory leaks
    return 0;
}
//--------------------------------------------------------------------------------------------------
