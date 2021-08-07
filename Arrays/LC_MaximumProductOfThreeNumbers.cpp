//https://leetcode.com/problems/maximum-product-of-three-numbers/

// can be done in o(n) using separate variables

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans1 = nums[0]*nums[1]*nums[n-1];
        int ans2 = nums[n-3]*nums[n-2]*nums[n-1];
        return max(ans1,ans2);
    }
};
