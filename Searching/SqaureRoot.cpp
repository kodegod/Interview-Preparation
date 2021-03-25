//https://leetcode.com/problems/sqrtx/submissions/
class Solution {
public:
    bool good(long long x,long long mid)
    {
        long long k=mid*mid;
        if(k>x)
            return true;
        return false;
    }
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int start=1;
        int end=x;
        while(end>start+1)
        {
            int mid=start+(end-start)/2;
            if(good(x,mid))
                end=mid;
            else
                start=mid;
        }
        return start;
    }
};
