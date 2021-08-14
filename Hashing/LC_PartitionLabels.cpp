//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        map<char,int> lastocc;
        for(int i=0; i<n; i++)
            lastocc[s[i]] = i;
        int count = 0;
        int lastmax = INT_MIN;
        for(int i=0; i<n; i++)
        {
            count++;
            lastmax = max(lastmax, lastocc[s[i]]);
            if(lastmax <= i)
            {
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};
