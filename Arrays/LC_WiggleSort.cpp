//https://leetcode.com/problems/wiggle-sort/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return;
        for(int i=1; i<n; i+=2)
        {
            if(i==n-1)
            {
                if(nums[i]<nums[i-1])
                    swap(nums[i],nums[i-1]);
                continue;
            }
            if(nums[i]>=nums[i-1] && nums[i]>=nums[i+1])
                continue;
            else if(nums[i-1]>nums[i+1])
                swap(nums[i-1],nums[i]);
            else
                swap(nums[i+1],nums[i]);
        }
    }
};
