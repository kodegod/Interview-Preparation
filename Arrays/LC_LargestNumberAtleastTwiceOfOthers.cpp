//https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int large = nums[0];
        int slarge = 0;
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i]>large)
            {
                slarge = large;
                large = nums[i];
                ans = i;
            }
            else if(nums[i]>slarge)
                slarge = nums[i];
        }
        return (large>=(2*slarge))?ans:-1;
    }
};
