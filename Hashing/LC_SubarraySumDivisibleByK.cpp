//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        map<int,int> mp;
        int prev=0;
        int curr=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0; i<n; i++)
        {
            curr=(A[i]+prev)%K;
            curr=(curr+K)%K;
            cnt+=mp[curr];  
            mp[curr]++;
            prev=curr;
        }
        return cnt;
    }
};
