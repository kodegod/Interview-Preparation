//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int findPivot(vector<int>&v,int n)
    {
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(v[mid]>v[mid+1])
                return mid;
            else if(v[mid]>v[n-1])
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    int search(vector<int>& v, int target) {
        int n=v.size();
        if(n==1)
        {
            if(target==v[0])
                return 0;
            return -1;
        }
        int k=findPivot(v,n);
        auto it=lower_bound(v.begin(),v.begin()+k,target);
        if(it!=v.begin()+k+1&&v[it-v.begin()]==target)
            return it-v.begin();
        auto it2=lower_bound(v.begin()+k+1,v.end(),target);
        if(it2!=v.end()&&v[it2-v.begin()]==target)
            return it2-v.begin();
        return -1;
    }
};
