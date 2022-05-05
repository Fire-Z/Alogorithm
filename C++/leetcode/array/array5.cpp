/*
No.704 level.easy Name.二分查找
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int mid = (len - 1) / 2;
        int left = 0;
        int right = len - 1;
        while (right - left > 1) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        if (nums[right] == target) {
            return right;
        } else if (nums[left] == target) {
            return left;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << Solution().search(nums, 2) << endl;
}