#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int length = nums.size();
        int maxLoc = (int)(max_element(nums.begin(), nums.end()) - nums.begin());
        int minLoc = (int)(min_element(nums.begin(), nums.end()) - nums.begin());
        if (minLoc < maxLoc) {
            return minLoc + length - maxLoc + 1;
        } else {
            return maxLoc + length - minLoc + 1;
        }
    }
};

int main()
{
    vector<int> nums = {2,10,7,5,4,1,8,6};
    Solution s;
    s.minimumDeletions(nums);
}