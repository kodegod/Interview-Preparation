//https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;    
        s.push(0);
        vector<int> ans(n);
        for(int i=1; i<n; i++)
        {
            while(s.size()>0 && nums[i] > nums[s.top()])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
