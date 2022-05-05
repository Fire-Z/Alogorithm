/*
No.5235 level.medium Name.找出输掉零场或一场的玩家
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> userLoseCount;
        vector<vector<int>> winners;
        vector<int> winners0;
        vector<int> winners1;
        for (int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];
            int winner = matches[i][0];
            auto user = userLoseCount.find(loser);
            auto win = userLoseCount.find(winner);
            if (user != userLoseCount.end()) {
                user->second = user->second + 1;
            } else {
                userLoseCount.insert(pair<int, int>(loser, 1));
            }
            if (win == userLoseCount.end()) {
                userLoseCount.insert(pair<int, int>(winner, 0));
            }
        }
        auto it = userLoseCount.begin();
        while (it != userLoseCount.end()) {
            if (it->second == 0) {
                winners0.push_back(it->first);
            } else if (it->second == 1) {
                winners1.push_back(it->first);
            }
            it++;
        }
        winners.push_back(winners0);
        winners.push_back(winners1);
        return winners;
    }
};

int main()
{
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> rtn = Solution().findWinners(matches);
}