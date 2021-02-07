class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        vector<int> v;
        while(left<right)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                v.push_back(nums[left]*nums[left]);
                left++;
            }
            else if(abs(nums[left])<abs(nums[right]))
            {
                v.push_back(nums[right]*nums[right]);
                right--;
            }
            else
            {
                v.push_back(nums[left]*nums[left]);
                v.push_back(nums[left]*nums[left]);
                left++;
                right--;
            }
        }
        if(left==right)
            v.push_back(nums[left]*nums[left]);
        reverse(v.begin(),v.end());
        return v;
    }
};
