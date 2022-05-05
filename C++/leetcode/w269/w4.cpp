#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calAver(vector<int>& nums, int loc, int k)
    {
        int sum = 0;
        for (int i = loc - k; i <= loc + k; i++) {
            sum += nums[i];
        }
        return sum / (2 * k + 1);
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }
        int length = nums.size();
        if (length < 2 * k + 1) {
            vector<int> averages(length, -1);
            return averages;
        } 
        int begin = k;
        int end = length - k - 1;
        vector<int> averages;
        for (int i = 0; i < length; i++) {
            if (i < begin || i > length - k - 1) {
                averages.push_back(-1);
            } else {
                int aver = calAver(nums, i, k);
                averages.push_back(aver);
            }
        }
        return averages;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    s.getAverages(nums, 3);
}