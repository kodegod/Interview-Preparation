//https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    vector<char> op = {'(', '{', '['};
    vector<char> cl = {')', '}', ']'};
    bool isValid(string str) {
        stack<int> s;
        if(str[0]==')' || str[0] ==']' || str[0] =='}')
            return false;
        s.push(str[0]);
        int opening = 1;
        int closing = 0;
        for(int i=1; i<str.size(); i++)
        {
            cout<<i << " ";
            auto it1 = find(op.begin(),op.end(),str[i]);
            auto it2 = find(cl.begin(),cl.end(),str[i]);
            if(it1!=op.end())
            {
                s.push(str[i]);
                opening++;
            }
            else
            {
                if(s.empty())
                    return false;
                int idx = it2 - cl.begin();
                char a = s.top();
                closing++;
                s.pop();
                if(op[idx] != a)
                    return false;
            }
        }
        return (opening==closing);
    }
};
