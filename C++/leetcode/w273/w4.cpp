#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int exceOrder(int n, int row, int cel, string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'R':
                if (cel + 1 >= n)
                {
                    return count;
                }
                else
                {
                    cel++;
                }
                break;

            case 'L':
                if (cel - 1 < 0)
                {
                    return count;
                }
                else
                {
                    cel--;
                }
                break;

            case 'U':
                if (row - 1 < 0)
                {
                    return count;
                }
                else
                {
                    row--;
                }
                break;

            case 'D':
                if (row + 1 >= n)
                {
                    return count;
                }
                else
                {
                    row++;
                }
                break;
            }
            count++;
        }
        return count;
    }

    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> answers;
        // vector<int> pos = startPos;
        for (int i = 0; i < s.length(); i++)
        {
            int answer = exceOrder(n, startPos[0], startPos[1], s.substr(i));
            answers.push_back(answer);
        }
        return answers;
    }
};

int main()
{
    vector<int> pos = {0, 1};
    Solution().executeInstructions(3, pos, "RRDDLU");

}