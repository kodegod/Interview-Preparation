//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pprod(n,0);
        int sprod = 1;
        pprod[0] = nums[0];
        for(int i=1; i<n; i++)
            pprod[i] = pprod[i-1]*nums[i];
        for(int i=n-1; i>=1; i--)
        {
            pprod[i] = pprod[i-1] * sprod;
            sprod = sprod * nums[i];
        }
        pprod[0] = sprod;
        return pprod;
    }
};
