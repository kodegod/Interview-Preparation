//https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int left_max = nums[0];
        int curr_max = nums[0];
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] >= curr_max)
                left_max = max(left_max,nums[i]);
            else
            {
                ans = i;
                curr_max = left_max;
            }
        }
        return ans+1;
    }
};
