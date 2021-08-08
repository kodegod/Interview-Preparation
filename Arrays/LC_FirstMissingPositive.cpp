//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n)
        {
            if(nums[i]>=1 && nums[i]<=n)
            {
                if(i+1 == nums[i])
                    i++;
                else if(nums[nums[i]-1] == nums[i])
                {
                    i++;
                    continue;
                }
                else
                    swap(nums[i],nums[nums[i]-1]);
            }
            else 
                i++;
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i] == i+1)
                continue;
            else
                return (i+1);
        }
        return n+1;
    }
};
