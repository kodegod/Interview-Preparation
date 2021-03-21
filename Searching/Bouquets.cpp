//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:
    bool good(vector<int>& v, int m, int k,int&mid)
    {
        int n=v.size();
        vector<int> cnt;
        int temp=0;
        for(int i=0; i<n; i++)
        {
            if(v[i]<=mid)
                temp++;
            else
            {
                cnt.push_back(temp);
                temp=0;
            }    
        }
        if(temp>0)
            cnt.push_back(temp);
        int ans=0;
        for(auto it:cnt)
            ans+=it/k;
        if(ans>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        int start=0;
        int end=*max_element(v.begin(),v.end());
        while(end-1>start)
        {
            int mid=(start+end)/2;
            if(good(v,m,k,mid))
                end=mid;
            else
                start=mid;
        }
        if(end==start+1&&good(v,m,k,end)==false)
            return -1;
        return end;
    }
};
