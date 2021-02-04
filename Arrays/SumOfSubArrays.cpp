long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long long ans=0;
        long long MOD=1e9+7;
        for(int i=0; i<n; i++)
        {
            ans+=a[i]*(n+(i*(n-i-1))%MOD);
            ans=ans%MOD;
        }
        return ans;
    }
