#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
         vector<int> bitmap(nums.size() + 1, 0);
         for(int i : nums) {
            bitmap[i] = 1;
         }
         for (int i = 0; i < nums.size() + 1; i++)  {
             if (bitmap[i] == 0) {
                return i;
             }
         }
         return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 0, 1};
    int miss = s.missingNumber(nums);
    cout << miss << endl;
}