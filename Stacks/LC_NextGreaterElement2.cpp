//https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;    
        s.push(0);
        vector<int> ans(n);
        for(int i=1; i<n; i++)
        {
            while(s.size()>0 && nums[i] > nums[s.top()])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i=0; i<n; i++)
        {
            while(s.size()>0 && nums[i] > nums[s.top()])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
        }
        while(!s.empty())
        {
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};
