//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 1;
        int cnt2 = 0;
        int num1 = nums[0];
        int num2 = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] == num1)
                cnt1++;
            else if(nums[i] == num2)
                cnt2++;
            else
            {
                if(cnt1 == 0)
                {
                    cnt1 = 1;
                    num1 = nums[i];
                }
                else if(cnt2 == 0)
                {
                    cnt2 = 1;
                    num2 = nums[i];
                }
                else
                {
                    cnt1--;
                    cnt2--;
                }
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == num1)
                cnt1++;
            else if(nums[i] == num2)
                cnt2++;
        }
        int needed = (n/3);
        if(cnt1 > needed)
            ans.push_back(num1);
        if(cnt2 > needed)
            ans.push_back(num2);
        return ans;
    }
};
