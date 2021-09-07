//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.size();
        stack<char> s;
        s.push(str[0]);
        for(int i=1; i<n; i++)
        {
            if(s.size()>0 && str[i] == s.top())
                s.pop();
            else
                s.push(str[i]);
        }
        string ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
