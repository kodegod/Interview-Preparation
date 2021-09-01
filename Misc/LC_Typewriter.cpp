//https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

class Solution {
public:
    int minTimeToType(string word) {
        int sum = 0;
        char curr = 'a';
        for(int i=0; i<word.size(); i++)
        {
            int a = abs(word[i] - curr);
            int b = 26 - a;
            sum += min(a,b);
            curr = word[i];
        }
        return sum + word.size();
    }
};
