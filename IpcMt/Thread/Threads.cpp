/**
 * \file  Threads.cpp
 * \brief
 */


 #include <StdStream/StdStream.h>
 #include <StdTest/StdTest.h>
 #include <Stl.h>
//--------------------------------------------------------------------------------------------------
void fnoarg(int t)
{
    std::this_thread::sleep_for( std::chrono::seconds(t) );
    std::cout << "fnoarg running on thread " << std::this_thread::get_id() << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int nthreads = std::thread::hardware_concurrency();
    std::cout << "nthreads = " << nthreads << std::endl;

    std::vector<std::thread> pool;

    for (int i=0; i<nthreads; ++i) {
        pool.push_back( std::thread(fnoarg,i) );
    }

    for (auto& t : pool){
        t.join();
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------
