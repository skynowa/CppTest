 /*
 * \file  main.cpp
 * \brief
 */


#include <string>
#include <iostream>
#include <assert.h>

#include <iostream>
#include <future>
#include <chrono>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
class Test
{
public:
	static std::mutex outMutex;

    Test(){}

    void out(const int no, const double &value) const;
    void test() const;
};
//-------------------------------------------------------------------------------------------------
std::mutex Test::outMutex;
//-------------------------------------------------------------------------------------------------
void
Test::out(const int no, const double &value) const
{
    {
        std::lock_guard<std::mutex> locker(outMutex);

        std::cout << "<- " << no << " -- " << value << std::endl;
    }

    // std::this_thread::sleep_for( std::chrono::seconds(1) );
}
//-------------------------------------------------------------------------------------------------
void
Test::test() const
{
    double w[2] {10.0, 20.0};

    std::cout << "-> " << 0 << " -- " << w[0] << std::endl;
	std::cout << "-> " << 1 << " -- " << w[1] << std::endl;

    std::future<void> f1 = std::async(&Test::out, this, 0, std::ref(w[0]));
    std::future<void> f2 = std::async(&Test::out, this, 1, std::ref(w[1]));

    f1.get();
    f2.get();
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    try {
        Test t;
        t.test();
    }
    catch (const std::exception &e) {
        std::cout << "\nstd::exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "\nUnknown exception" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif





