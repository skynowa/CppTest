/**
 * \file  MultiArray3d.cpp
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
print(const boost::multi_array<double, 3> &array)
{
    for (std::size_t i = 0; i < array.shape()[0]; i++) {
        for (std::size_t j = 0; j < array.shape()[1]; j++) {
            for (std::size_t k = 0; k < array.shape()[2]; k++) {
                std::cout << array[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
//--------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    const std::size_t m = (argc > 1) ? atoi(argv[1]) : 4;
    const std::size_t n = (argc > 2) ? atoi(argv[2]) : 5;
    const std::size_t o = (argc > 3) ? atoi(argv[3]) : 2;

    boost::multi_array<double, 3> A(boost::extents[o][n][m]);

    for (std::size_t i = 0; i < o; i++)
        for (std::size_t j = 0; j < n; j++)
            for (std::size_t k = 0; k < m; k++) A[i][j][k] = i * m * n + j * m + k;

    boost::multi_array<double, 3> B(boost::extents[o][n][m]);

    for (std::size_t i = 0; i < o; i++)
        for (std::size_t j = 0; j < n; j++)
            for (std::size_t k = 0; k < m; k++) B[i][j][k] = i * m * n + j * m + k + 0.5;

    print(A);
    print(B);

    // safe copies, would even work with differing dimensions:
    B = A;
    print(B);

    // RAII: no manual free, no memory leaks
    return 0;
}
//--------------------------------------------------------------------------------------------------
