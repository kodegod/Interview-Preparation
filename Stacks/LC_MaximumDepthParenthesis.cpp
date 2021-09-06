//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string str) {
        stack<int> s;
        int ans = 0;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '(')
                s.push(i);
            else if(str[i] == ')')
                s.pop();
            ans = max(ans,(int)s.size());
        }
        return ans;
    }
};
