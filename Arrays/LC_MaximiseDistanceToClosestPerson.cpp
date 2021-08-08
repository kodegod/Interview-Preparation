//https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> ps(n,0);
        vector<int> ss(n,0);
        ps[0] = 0;
        for(int i=1; i<n; i++)
        {
            if(seats[i] == 1)
                ps[i] = 0;
            else
                ps[i] = 1 + ps[i-1];
        }
        ss[n-1] = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(seats[i] == 1)
                ss[i] = 0;
            else
                ss[i] = 1 + ss[i+1];
        }
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, min(ps[i],ss[i]));
        ans = max(ans, max(ps[n-1],ss[0]));
        return ans;
    }
};
