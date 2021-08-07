//https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int curr = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == curr)
                cnt++;
            else
                cnt--;
            if(cnt==0)
            {
                curr = nums[i];
                cnt = 1;
            }
        }
        return curr;
    }
};
