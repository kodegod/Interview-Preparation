//https://leetcode.com/problems/consecutive-numbers-sum/

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if(n==1)
            return 1;
        int cnt = 0;
        for(int k = 1; k < n; k++)
        {
            int a = (n - (k*(k-1))/2);
            if(a <= 0)
                break;
            if(a % k == 0)
                cnt++;
        }
        return cnt;
    }
};
