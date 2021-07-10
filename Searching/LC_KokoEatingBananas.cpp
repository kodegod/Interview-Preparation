//https://leetcode.com/problems/koko-eating-bananas/

// BS on answer

class Solution {
public:
    bool good(vector<int>&v,int h,int n,int mid)
    {
        int ans=0;
        for(int i=0; i<n; i++)
            ans+=(v[i]-1)/mid+1;
        if(ans<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int n=v.size();            
        int start=1;
        int end=*max_element(v.begin(),v.end());
        if(n==1)
            return (v[0]-1)/h+1;
        while(end>start+1)
        {
            int mid=(start+end)/2;
            if(good(v,h,n,mid))
                end=mid;
            else
                start=mid;
        }
        return end;
    }
};
