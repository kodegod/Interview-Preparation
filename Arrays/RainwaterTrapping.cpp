class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2)
            return 0;
        vector<int> pmax(n);
        vector<int> smax(n);
        pmax[0]=height[0];
        smax[n-1]=height[n-1];
        for(int i=1; i<n; i++)
            pmax[i]=max(pmax[i-1],height[i]);
        for(int i=n-2; i>=0; i--)
            smax[i]=max(smax[i+1],height[i]);
        int ans=0;
        for(int i=1; i<n-1; i++)
        {
            if(pmax[i-1]>height[i]&&smax[i+1]>height[i])
            {
                ans+=min(pmax[i-1],smax[i+1]);
                ans-=height[i];
            }
        }
        return ans;
    }
};
