//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n=v.size();
        int start=1;
        int end=n-1;
        if(n==1)
            return v[0];
        if(n>1)
        {
            if(v[0]!=v[1])
                return v[0];
            else if(v[n-1]!=v[n-2])
                return v[n-1];
        }
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(v[mid+1]!=v[mid]&&v[mid-1]!=v[mid])
                return v[mid];
            else if(v[mid+1]==v[mid])
            {
                if(mid%2==1)
                    end=mid-1;
                else
                    start=mid+1;
            }
            else
            {
                if(mid%2==1)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return 0;
    }
};
