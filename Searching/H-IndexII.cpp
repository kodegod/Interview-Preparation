//https://leetcode.com/problems/h-index-ii/
class Solution {
public:
    int hIndex(vector<int>& v) {
        int n=v.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(v[mid]>=(n-mid))
                end=mid;
            else
                start=mid+1;
        }
        return min(v[start],n-start);
    }
};
