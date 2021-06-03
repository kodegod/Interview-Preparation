//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int gaph=v1[0];
        int gapv=v2[0];
        for(int i=1; i<v1.size(); i++)
            gaph=max(gaph,v1[i]-v1[i-1])%1000000007;
        gaph=max(gaph,h-v1[v1.size()-1])%1000000007;
        for(int i=1; i<v2.size(); i++)
            gapv=max(gapv,v2[i]-v2[i-1])%1000000007;
        gapv=max(gapv,w-v2[v2.size()-1])%1000000007;
        const long MOD = pow(10, 9) + 7;
        return ((long long)gaph * (gapv)) % MOD;
    }
};
