//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int n=v.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(v[mid]>=target)
                end=mid;
            else
                start=mid+1;
        }
        if(start==end&&v[start]<target)
            return start+1;
        return start;
    }
};
