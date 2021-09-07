//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int> mp;
        stack<int> s;
        s.push(0);
        for(int i=1; i<n; i++)
        {
            while(s.size()>0 && nums2[i] > nums2[s.top()])
            {
                mp[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans(nums1.size(),-1);
        for(int i=0; i<nums1.size(); i++)
            if(mp.find(nums1[i])!=mp.end())
                ans[i] = mp[nums1[i]];
        return ans;
    }
};
