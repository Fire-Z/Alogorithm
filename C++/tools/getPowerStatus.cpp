#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    string point = "null";
    cin >> point;
    while (point == "exit")
    {
        return 0;
    }
    SYSTEM_POWER_STATUS powerStatus;
    while (true) {
        GetSystemPowerStatus(&powerStatus);
        cout << (int)powerStatus.BatteryLifePercent << endl;
        if ((int)powerStatus.BatteryLifePercent <= 30) {
            cout << "请及时充电" << endl;
        }
        _sleep(5000);
    }
}