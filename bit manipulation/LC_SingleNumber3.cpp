//https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0; i<n; i++)
            k = k ^ nums[i];
        int rsb = 0;
        int i = 0;
        while(1)
        {
            if((k & (1<<i)) != 0)
                break;
            else 
                i++;
        }
        rsb = i;
        int a = 0;
        int b = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] & (1<<rsb))
                a = a ^ nums[i];
            else
                b = b ^ nums[i];
        }
        return {a,b};
    }
};
