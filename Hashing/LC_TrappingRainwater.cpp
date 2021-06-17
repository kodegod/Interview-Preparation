//https://leetcode.com/problems/trapping-rain-water/

// Space -> O(N).   (prefix sums)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0]=height[0];
        for(int i=1; i<n; i++)
            lmax[i]=max(lmax[i-1],height[i]);
        rmax[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--)
            rmax[i]=max(rmax[i+1],height[i]);
        int ans=0;
        for(int i=1; i<n-1; i++)
        {
            int k=min(lmax[i],rmax[i]);
            ans+=max(0,k-height[i]);
        }
        return ans;
    }
};


// Space -> O(1).       (2 pointers)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        int lmax=height[0];
        int rmax=height[n-1];
        int i=0,j=n-1;
        int ans=0;
        while(i<=j)
        {
            if(lmax<=rmax)
            {
                lmax=max(lmax,height[i]);
                ans+=lmax-height[i];
                i++;
            }
            else
            {
                rmax=max(rmax,height[j]);
                ans+=rmax-height[j];
                j--;
            }
        }
        return ans;
    }
};
