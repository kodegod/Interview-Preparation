//https://leetcode.com/problems/paint-fence/

class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp_s(n,0);
        vector<int> dp_d(n,0);
        dp_s[0]=k;
        dp_d[0]=k;
        if(n==1)
            return k;
        dp_s[1]=k;
        dp_d[1]=k*(k-1);
        for(int i=2; i<n; i++)
        {
            dp_s[i]=dp_d[i-1];
            dp_d[i]=(dp_s[i-1]+dp_d[i-1])*(k-1);
        }
        return dp_s[n-1] + dp_d[n-1];
    }
};
