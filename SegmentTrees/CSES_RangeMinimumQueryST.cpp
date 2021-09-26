//https://cses.fi/problemset/task/1649/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

vector<int> arr;
vector<int> tree;

int query(int qs, int qe, int l, int r, int i)
{
    if (qe < l || r < qs)
        return INT_MAX;
    if (qs <= l && qe >= r)
        return tree[i];
    int mid = (l + r) / 2;
    int left = query(qs, qe, l, mid, 2 * i);
    int right = query(qs, qe, mid + 1, r, 2 * i + 1);
    return min(left, right);
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        tree[i] = arr[r];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void update(int i, int l, int r, int idx, int x)
{
    if (idx < l || idx > r)
        return;
    if (l == r && l == idx)
    {
        tree[i] = x;
        arr[l] = x;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * i, l, mid, idx, x);
    update(2 * i + 1, mid + 1, r, idx, x);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
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
    arr.resize(n);
    tree.resize(4 * n, INT_MAX);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(l, r, 0, n - 1, 1) << endl;
        }
        else
        {
            int idx, x;
            cin >> idx >> x;
            idx--;
            update(1, 0, n - 1, idx, x);
        }
    }
    return 0;
}
