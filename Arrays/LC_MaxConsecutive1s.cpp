//https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_max=0;
        int maxy=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
                curr_max++;
            else
            {
                maxy=max(maxy,curr_max);
                curr_max=0;
            }
        }
        maxy=max(maxy,curr_max);
        return maxy;
    }
};
