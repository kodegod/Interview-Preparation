//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// BS on answer

class Solution {
public:
    bool good(vector<int>& nums, int threshold,int mid)
    {
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%mid==0)
                ans+=(nums[i]/mid);
            else
                ans+=(nums[i]/mid)+1;
        }
        if(mid==5)
            cout<<ans;
        if(ans<=threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1;
        int end=*max_element(nums.begin(),nums.end())+1;
        while(start+1<end)
        {
            int mid=start+(end-start)/2;
            if(good(nums,threshold,mid)==true)
                end=mid;
            else
                start=mid;
        }
        if(good(nums,threshold,start)==true)
            return start;
        return end;
    }
};
