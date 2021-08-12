https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int left = 0;
        while(left<=j)
        {
            if(nums[left]==0)
                swap(nums[left++],nums[i++]);
            else if(nums[left]==2)
                swap(nums[left],nums[j--]);
            else
                left++;
        }
    }
};
