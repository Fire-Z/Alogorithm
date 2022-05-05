#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int Max = 0;
        if (prices[len - 1] > prices[len - 2]) {
            Max = prices[len - 1] - prices[len - 2];
        }
        for (int i = len - 3)
    }
};