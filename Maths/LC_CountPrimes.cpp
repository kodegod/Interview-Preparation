//https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        n--;
        vector<bool> v(n+1,true);
        int count = 0;
        for(int i=2; i<=(sqrt(n)); i++)
        {
            if(v[i]==true)
            {
                for(int j=2*i; j<=n; j+=i)
                    v[j] = false;
            }
        }
        for(int i=2; i<=n; i++)
            if(v[i]==true)
                count++;
        return count;
    }
};
