/*
No. level. Name.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> re_nums;
        map<int,int> c_data;
        for (int i=0; i<nums.size(); i++) {
            c_data[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++){
            if (c_data[nums[i]] == 1 && c_data[nums[i]+1] == 0 && c_data[nums[i]-1] == 0) {
                re_nums.push_back(nums[i]);            
        }          
        return re_nums;
    }
}
};

int main()
{
    vector<int> nums = {10,6,5,8};  
    vector<int> rtn = Solution().findLonely(nums);
    return 0;
}