//https://cses.fi/problemset/task/1620

// BS on answer

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

bool good(vector<int>&v, int n, int t, int mid)
{
    int curr = 0;
    for (auto it : v)
        curr += (mid / it);
    if (curr >= t)
        return true;
    return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int end = *min_element(v.begin(), v.end());
    end = end * t;
    int start = 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (good(v, n, t, mid) == true)
            end = mid;
        else
            start = mid;
    }
    cout << end;
    return 0;
}
