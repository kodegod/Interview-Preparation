//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int two = 0;
        int three = 0;
        int five = 0;
        for(int i=1; i<n; i++)
        {
            int ug1 = 2 * dp[two];
            int ug2 = 3 * dp[three];
            int ug3 = 5 * dp[five];
            int mini = min(ug1,min(ug2,ug3));
            dp[i] = mini;
            if(ug1==mini)
                two++;
            if(ug2==mini)
                three++;
            if(ug3==mini)
                five++;
        }
        return dp[n-1];
    }
};
