/*
No. level. Name.
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int c = (l + r)/2;
        while (c >= 0) {            
            if(nums[c] == target) {
                return c;
            }else if(nums[c] > target) {
                r = c - 1;
                c = (r + l)/2;
            }else {
                l = c + 1;
                c = (l + r)/2;
            }
            if (l> r) {
                return -1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    Solution().search(nums,2);
    return 0;
}