/**
 * \file  Ranges.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <boost/range/irange.hpp>
//--------------------------------------------------------------------------------------------------
static inline double wtime(void)
{
    using t = std::chrono::high_resolution_clock;

    auto c = t::now().time_since_epoch().count();
    auto n = t::period::num;
    auto d = t::period::den;

    const auto r = static_cast<double>(c) / static_cast<double>(d) * static_cast<double>(n);

    return r;
}
//--------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    const int n = (argc>1) ? std::atoi(argv[1]) : 10;

    {
        std::cout << "standard\n";
        double k(0);
        auto t0 = wtime();
        for (int i=0; i<n; ++i) k+=1.0;
        auto t1 = wtime();
        std::cout << "dt = " << t1-t0 << "\n";
        std::cout << "k = " << k << "\n";
    }

    {
        auto rvi = boost::irange(0,n);

        //std::cout << "boost::irange(0,n)";
        //for (auto const & i : rvi) std::cout << i << ",";
        //std::cout << "\n";

        std::cout << "boost::irange\n";
        double k(0);
        auto t0 = wtime();
        for (auto const & i : rvi) {
            (void)i;

            k+=1.0;
        }
        auto t1 = wtime();
        std::cout << "dt = " << t1-t0 << "\n";
        std::cout << "k = " << k << "\n";
    }

    {
        auto rvi = std::ranges::views::iota(0,n);

        //std::cout << "ranges::views::iota(0,n) = ";
        //for (auto const & i : rvi) std::cout << i << ",";
        //std::cout << "\n";

        std::cout << "ranges::views::iota\n";
        double k(0);
        auto t0 = wtime();
        for (auto const & i : rvi) {
            (void)i;

            k+=1.0;
        }
        auto t1 = wtime();
        std::cout << "dt = " << t1-t0 << "\n";
        std::cout << "k = " << k << "\n";
    }

    {
        auto rvi = std::ranges::views::iota(0) | std::ranges::views::take(n - 0);

        //std::cout << "ranges::views::iota(0) | ranges::views::take(n - 0) = ";
        //for (auto const & i : rvi) std::cout << i << ",";
        //std::cout << "\n";

        std::cout << "ranges::views::iota | ranges::views::take\n";
        double k(0);
        auto t0 = wtime();
        for (auto const & i : rvi) {
            (void)i;

            k+=1.0;
        }
        auto t1 = wtime();
        std::cout << "dt = " << t1-t0 << "\n";
        std::cout << "k = " << k << "\n";
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------
