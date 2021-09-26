//https://cses.fi/problemset/task/1649/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int n;
int bsz;
vector<int> bval, bl, br, bno;
vector<int> v;

int query(int l, int r)
{
    int ans = INT_MAX;
    if (bno[l] == bno[r])
        for (int i = l; i <= r; i++)
            ans = min(ans, v[i]);
    else
    {
        for (int i = l; i <= br[bno[l]]; i++)
            ans = min(ans, v[i]);
        for (int i = bno[l] + 1; i < bno[r]; i++)
            ans = min(ans, bval[i]);
        for (int i = bl[bno[r]]; i <= r; i++)
            ans = min(ans, v[i]);
    }
    return ans;
}

void update(int idx, int x)
{
    v[idx] = x;
    bval[bno[idx]] = INT_MAX;
    for (int i = bl[bno[idx]]; i <= br[bno[idx]]; i++)
        bval[bno[i]] = min(bval[bno[i]], v[i]);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int n, q;
    cin >> n >> q;
    bsz = sqrt(n);
    int no_of_blocks = (n + bsz - 1) / bsz;
    v.resize(n, 0);
    bl.resize(no_of_blocks, -1);
    br.resize(no_of_blocks, 0);
    bval.resize(no_of_blocks, INT_MAX);
    bno.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        bno[i] = i / bsz;
        if (bl[bno[i]] == -1)
            bl[bno[i]] = i;
        br[bno[i]] = i;
        bval[bno[i]] = min(bval[bno[i]], v[i]);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, x;
            cin >> i >> x;
            update(i - 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1) << endl;
        }
    }

    return 0;
}
