//https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size();
        int start=1;
        int end=n-1;
        if(n==1)
            return 0;
        if(v[0]>v[1])
            return 0;
        if(v[n-1]>v[n-2])
            return n-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(v[mid]>v[mid-1]&&v[mid]>v[mid+1])
                return mid;
            else
            {
                if(v[mid+1]>v[mid])
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
    }
};
