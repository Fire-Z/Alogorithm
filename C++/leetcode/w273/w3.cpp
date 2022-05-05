#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int rever = atoi(s.c_str());
        string reverStr = to_string(rever);
        reverse(reverStr.begin(), reverStr.end());
        int rev = atoi(reverStr.c_str());
        return num == rev;
    }
};

int main()
{
    Solution().isSameAfterReversals(526);
}