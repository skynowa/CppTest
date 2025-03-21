/**
 * \file  LockUnlock_1.cpp
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
    int        mMoney {};
    std::mutex m1 {};

public:
    Wallet() : mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
      m1.lock();
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
       m1.unlock();
    }
};
//--------------------------------------------------------------------------------------------------
int
testMultithreadedWallet()
{
   Wallet walletObject;
   std::vector<std::thread> threads;
   for(std::size_t i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
   }

   for(std::size_t i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   return walletObject.getMoney();
}
//--------------------------------------------------------------------------------------------------
int main()
{

  int val = 0;
  bool flag = false;

  for(int k = 0; k < 1000; k++)
  {
     if((val = testMultithreadedWallet()) != 5000)
     {
        flag = true;
       std::cout << "Error at count = "<< k <<" Money in Wallet = "<<val << std::endl;
     }
  }

  if (flag == false)
    std::cout << "No Race Condition occurred" << std::endl;

  return 0;
}
//--------------------------------------------------------------------------------------------------
