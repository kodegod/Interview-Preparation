//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int i=0,j=0;
        int ans = 0;
        int prev_valid = 0;
        while(i<n && j<n)
        {
            if(nums[j]>=left && nums[j]<=right)
            {
                ans += (j-i+1);
                prev_valid = (j-i+1);
                j++;
            }
            else if(nums[j]<left)
            {
                ans +=prev_valid;
                j++;
            }
            else
            {
                i = j+1;
                j = i;
                prev_valid = 0;
            }
        }
        return ans;
    }
};
