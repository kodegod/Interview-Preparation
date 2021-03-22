//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int n=v.size();
        int start = 0;
        int end = n - 1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(v[mid]>=target)
                end=mid;
            else
                start=mid+1;
        }
        cout<<start;
        if(start>end)
            return {-1,-1};
        else if(start==end&&(start==n-1||start==0)&&v[start]!=target)
            return {-1,-1};
        
        if(v[start]!=target)
            return {-1,-1};
        int ans1=start;
        start=0,end=n-1;
        while(start<end)
        {
            int mid=(start+end+1)/2;
            if(v[mid]<=target)
                start=mid;
            else if(v[mid]>target)
                end=mid-1;
        }
        return {ans1,end};
    }
};
