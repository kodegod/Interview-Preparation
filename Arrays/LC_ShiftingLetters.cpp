//https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for(int i=n-2; i>=0; i--)
        {
            shifts[i] += shifts[i+1]%26;
            shifts[i] %= 26;
        }
        for(int i=0; i<n; i++)
        {
            int temp = s[i] - 97;
            temp += shifts[i];
            temp %= 26;
            s[i] = temp + 97;
        }
        return s;
    }
};
