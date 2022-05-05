/*
No.2149 level.medium Name.按符号重排数组
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> nums1;  // 正数
        vector<int> nums2;  // 负数
        vector<int> res;
        size_t len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                nums1.push_back(nums[i]);
            } else {
                nums2.push_back(nums[i]);
            }
        }
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                res.push_back(nums1[f1]);
                f1++;
            } else {
                res.push_back(nums2[f2]);
                f2++;
            }
        }
        return res;
    }
};

int main()
{
    
}