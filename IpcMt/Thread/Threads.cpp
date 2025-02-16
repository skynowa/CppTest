/**
 * \file  Threads.cpp
 * \brief Create std::vector of threads
 */


 #include <StdStream/StdStream.h>
 #include <StdTest/StdTest.h>
 #include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
worker(
	const int value
)
{
    std::this_thread::sleep_for( std::chrono::seconds(value) );
    std::cout << "[worker] running on thread " << std::this_thread::get_id() << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int threadsNum = std::thread::hardware_concurrency();
    std::cout << STD_TRACE_VAR(threadsNum) << std::endl;

    std::vector<std::thread> pool;

    for (int i = 0; i < threadsNum; ++ i) {
        pool.emplace_back( std::thread(worker, i) );
    }

    for (auto &it_t : pool){
        it_t.join();
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

---------------------------------------------
threadsNum: 20
[worker] running on thread 133090835957312
[worker] running on thread 133090825471552
[worker] running on thread 133090814985792
[worker] running on thread 133090670282304
[worker] running on thread 133090804500032
[worker] running on thread 133090794014272
[worker] running on thread 133090783528512
[worker] running on thread 133090699642432
[worker] running on thread 133090689156672
[worker] running on thread 133090659796544
[worker] running on thread 133090649310784
[worker] running on thread 133090638825024
[worker] running on thread 133090628339264
[worker] running on thread 133090617853504
[worker] running on thread 133090607367744
[worker] running on thread 133090596881984
[worker] running on thread 133090586396224
[worker] running on thread 133090575910464
[worker] running on thread 133090565424704
[worker] running on thread 133090554938944
---------------------------------------------

#endif
