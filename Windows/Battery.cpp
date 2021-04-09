/**
 * \file  Battery.cpp
 * \brief
 */


#include <windows.h>
#include <iostream>
//-------------------------------------------------------------------------------------------------
#define UNKNOWN \
     0xFFFFFFFF
//-------------------------------------------------------------------------------------------------
using namespace std;

int main()
{
     SYSTEM_POWER_STATUS status;
     GetSystemPowerStatus(&status);

     int life = status.BatteryLifePercent;
     int secs = status.BatteryLifeTime;

     cout << life << "%   ->   ";

     switch (status.BatteryFlag) {
     case 1:
          cout << "High";
          break;
     case 2:
          cout << "Low";
          break;
     case 4:
          cout << "Critical";
          break;
     case 8:
          cout << "Charging";
          break;
     case 128:
          cout << "No system battery";
          break;
     case 256:
          cout << "Unknown status";
          break;
     }

     if (secs == UNKNOWN) {
          cout << endl << "Amount of time remaining is unkown";
     } else {
          cout << endl << secs << " seconds remaining";
     }
}
//-------------------------------------------------------------------------------------------------
