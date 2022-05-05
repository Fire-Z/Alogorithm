#include <iostream>
using namespace std;
class Solution {
public:

    bool isValidWord(string word)
    {
        int length = word.length();
        for (int i = 0; i < length; i++) {
            if ((word[i] == '!' || word[i] == '.' || word[i] == ',') && (i != length - 1)) {
                return false;
            } else {
                
            }
        }
    }
    int countValidWords(string sentence) {
        for ()
    }
};