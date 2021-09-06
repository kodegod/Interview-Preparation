//https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string str) {
        stack<int> s;
        vector<int> temp;
        for(int i=0; i<str.size(); i++)
        {
            if(s.size() == 0)
            {
                s.push(i);
                temp.push_back(i);
            }
            else if(s.size() == 1 && str[i] == ')')
            {
                temp.push_back(i);
                s.pop();
            }
            else if(str[i] == '(')
                s.push(i);
            else
                s.pop();
        }
        map<int,bool> mp;
        for(auto it:temp)
            mp[it] = true;
        for(int i=0; i<str.size(); i++)
            if(mp[i] == true)
                str[i] = 'x';
        string ans;
        for(int i=0; i<str.size(); i++)
            if(str[i]!='x')
                ans.push_back(str[i]);
        return ans;
        }
};
