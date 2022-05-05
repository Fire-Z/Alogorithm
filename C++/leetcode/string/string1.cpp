/*
No.3 level.medium Name.无重复长度的最长子串
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num, lon;
        string tem;
        for (int i = 0; i < s.size(); i++) {
            if (tem.find(s[i]) == string::npos) {
                tem = tem + s[i];
            } else {
                int pos = tem.find(s[i]) ;
                tem = tem.substr(pos + 1);                
                tem = tem + s[i];
                num = tem.size();                
                if(lon < num) {
                    lon = num;
                } 
            }
        }
        //后续没有重复字符
        num = tem.size();        
        if (lon < num) {
            lon = num;
        } 
        return lon;
    }
};

int main()
{
    
}