//https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        s.push(0);
        vector<string> ans;
        for(int i=0; i<target.size(); i++)
        {
            if(s.size()>0 && target[i] > 1 + s.top())
            {
                for(int j=0; j<target[i]-s.top()-1; j++)
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
            }
            s.push(target[i]);
            ans.push_back("Push");
        }
        return ans;
    }
};
