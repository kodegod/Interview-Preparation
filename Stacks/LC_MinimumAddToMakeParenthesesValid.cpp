//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<int> s;
        s.push(str[0]);
        for(int i=1; i<str.size(); i++)
        {
            if(str[i] =='(')
                s.push(str[i]);
            else
            {
                if(s.empty())
                    s.push(str[i]);
                else if(s.top() == '(')
                    s.pop();
                else
                    s.push(str[i]);
            }
        }
        return s.size();
    }
};
