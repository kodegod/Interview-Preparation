// Don't know

// N is the number of passengers. Calculate the total no of possible passages of picking and dropping the N passengers
// Eg- for N=2 
//       P1 P2 D1 D2
//       P1 P2 D2 D1 
//       P1 D1 P2 D2
//       P2 P1 D1 D2 
//       P2 P1 D2 D1
//       P2 D2 P1 D1 

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int x = 2 * i - 1;
        int k = ((x) * (x + 1)) / 2;
        dp[i] = dp[i - 1] * k;
    }
    cout << dp[n];

    return 0;
}
