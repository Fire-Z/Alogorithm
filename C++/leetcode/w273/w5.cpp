#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    typedef pair<int, vector<int>> loc;
    long long calAbs(int loc, vector<long long> locs)
    {
        long long a = 0;
        for (long long i : locs) {
            a += abs(i - loc);
        }
        return a;
    }
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> distances(arr.size(), 0);
        map<int, vector<long long>> locMap;
        for (int i = 0; i < arr.size(); i++) {
            map<int, vector<long long>>::iterator it = locMap.find(arr[i]);
            if (it == locMap.end()) {
                vector<long long> locs;
                locs.push_back(i);
                locMap.insert(pair<int, vector<long long>>(arr[i], locs));
            } else {
                it->second.push_back(i);
            }
        }
        map<int, vector<long long>>::iterator it1 = locMap.begin();
        while (it1 != locMap.end()) {
            int len = it1->second.size();
            map<vector<long long>, long long> absMap;
            for (int i = 0; i < it->second.size() - 1; i++) {
                for (int j = i + 1; j < it->second.size(); j++) {
                    
                }
            }
            for (int i = 0; i < len; i++) {
                distances[it1->second[i]] = calAbs(it1->second[i], it1->second); 
            }
            it1++;
        }
        return distances;
    }
};

int main()
{
    vector<int> arr = {2,1,3,1,2,3,3};
    Solution().getDistances(arr);
}