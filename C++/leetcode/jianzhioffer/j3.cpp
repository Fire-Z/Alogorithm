#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        set<int> hashSet;
        for (int i : nums) {
            if (hashSet.find(i) == hashSet.end()) {
                hashSet.insert(i);
            } else {
                return i;
            }
        }
        return 0;
    }

    // 交换
    int findRepeatNumber1(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int tem;
            while (nums[i]!=i)
            {
                tem = nums[i];
                if(nums[i] == nums[tem])
                {
                    return nums[i];
                }                
                nums[i] = i;
                nums[tem] = tem;
                
            }
            
        }
        return 0;
    }

    //----二分---
    int getSame(int left, int mid, int right, vector<int>& nums)
    {
        if (right - left == 1) {
            int flag = 0;
            for (int i : nums) {
                if (i == left) {
                    if (flag == 1) {
                        return left;
                    }
                    flag++;
                }
            }
            return right;
        }
        int count = 0;
        int size = mid - left + 1;
        for (int i : nums) {
            if (left <= i && i <= mid) {
                count++;
            }
        }
        if (count > size) {
            getSame(left, left + (mid - left) / 2 , mid, nums);
        } else {
            getSame(mid + 1,mid + 1 + (right - mid - 1) / 2, right, nums);
        }
        return 0;
    }

    int findRepeatNumber2(vector<int>& nums)
    {
        // map<int, int> numMap;  // <num, count>
        int size = nums.size();
        int sameNum = getSame(0, (size - 1) / 2,size - 1, nums);
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3}
    s.findRepeatNumber2(nums);
}