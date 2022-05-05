/*
1218 mediunm 最长定差子序列
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxCount = 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            int tempMax = 1;
            int leftNum = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] - leftNum == difference) {
                    tempMax++;
                    leftNum = arr[j];
                }
            }
            if (tempMax > maxCount) {
                maxCount = tempMax;
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    int res  = s.longestSubsequence(arr, -2);
}