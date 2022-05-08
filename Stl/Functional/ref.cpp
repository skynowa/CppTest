/**
 * \file  ref.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class Test
{
public:
	static std::mutex outMutex;

    Test() = default;

    void out(const int no, const double value) const;
    void test() const;
};
//-------------------------------------------------------------------------------------------------
std::mutex Test::outMutex;
//-------------------------------------------------------------------------------------------------
void
Test::out(
    const int    no,
    const double value
) const
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
    const double w[2] {10.0, 20.0};

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
    Test t;
    t.test();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

-> 0 -- 10
-> 1 -- 20
<- 0 -- 10
<- 1 -- 20

#endif
