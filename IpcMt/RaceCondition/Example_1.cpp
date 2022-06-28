/**
 * \file  Example_1.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Wallet
{
public:
    Wallet() = default;

    int money() const
    {
        return _money;
    }

    void addMoney(const int a_money)
    {
        for (int i = 0; i < a_money; ++ i) {
            ++ _money;
        }
    }

private:
    int _money {};
};
//--------------------------------------------------------------------------------------------------
int
testMultithreadedWallet()
{
    std::vector<std::thread> threads;
    Wallet                   wallet;

    for (std::size_t i = 0; i < 5; ++ i) {
        std::thread t(&Wallet::addMoney, &wallet, 1000);

        threads.push_back( std::move(t) );
    }

    for (std::size_t i = 0; i < threads.size(); ++ i) {
        threads.at(i).join();
    }

    return wallet.money();
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    for (int k = 0; k < 1000; ++ k) {
        const int val = ::testMultithreadedWallet();
        if (val != 5000) {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Error at count = 10 Money in Wallet = 3000
Error at count = 12 Money in Wallet = 4000
Error at count = 51 Money in Wallet = 4000
Error at count = 186 Money in Wallet = 4000
Error at count = 187 Money in Wallet = 4000
Error at count = 188 Money in Wallet = 4000
Error at count = 189 Money in Wallet = 4000
Error at count = 261 Money in Wallet = 4000
Error at count = 820 Money in Wallet = 4000
Error at count = 940 Money in Wallet = 4000

#endif
