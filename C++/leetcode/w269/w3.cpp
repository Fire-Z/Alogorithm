#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> locs;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                locs.push_back(i);
            }
        }
        return locs;
    }
};

int main()
{
    for (int i = 0; i < 100; i++) {
        function();
    }
    return 0;
}