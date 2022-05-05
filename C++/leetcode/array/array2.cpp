/*
No. level. Name.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (int num: nums) {
            if (smallest < num && num < largest) {
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {11,7,2,15};
    cout << Solution().countElements(nums) << endl;
}