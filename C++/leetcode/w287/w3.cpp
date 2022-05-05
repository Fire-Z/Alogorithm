/*
No.6055 level.easy Name.转化时间需要的最小操作数
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int currHour = atoi(current.substr(0, 2).c_str());
        int currMin = atoi(current.substr(3, 2).c_str());
        int correctHour = atoi(correct.substr(0, 2).c_str());
        int correctMin = atoi(correct.substr(3, 2).c_str());
        int hour = 0;
        int minute = 0;
        if (correctHour - currHour > 1) {
            hour = correctHour - currHour - 1;
            minute = 60 - currMin + correctMin;

        } else if (correctHour - currHour == 1) {
            minute = 60- currMin  + correctMin;
        } else {
            minute = correctMin - currMin;
        }
        int num = minute / 60;
        minute = minute % 60;
        num += minute / 15;
        minute = minute % 15;
        num += minute / 5;
        minute = minute % 5;
        num += minute;
        num += hour;
        return num;
    }
};

int main()
{
    string curr = "09:41";
    string correct = "10:34";
    cout << Solution().convertTime(curr, correct) << endl; 
}