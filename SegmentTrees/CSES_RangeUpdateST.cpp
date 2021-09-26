//https://cses.fi/problemset/task/1651/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

vector<int> arr;
vector<int> tree;

vector<bool> lazy;
vector<int> upd;

void apply(int i, int l, int r, int val)
{
    tree[i] += (r - l + 1) * val;
    if (l != r)
    {
        lazy[i] = true;
        upd[i] += val;
    }
}

void pushdown(int i, int l, int r)
{
    if (lazy[i] == true)
    {
        int mid = (l + r) / 2;
        apply(2 * i, l, mid, upd[i]);
        apply(2 * i + 1, mid + 1, r, upd[i]);
        lazy[i] = false;
        upd[i] = 0;
    }
}

int query(int qs, int qe, int l, int r, int i)
{
    if (qe < l || r < qs)
        return 0;
    if (qs <= l && qe >= r)
        return tree[i];

    pushdown(i, l, r);
    int mid = (l + r) / 2;
    int left = query(qs, qe, l, mid, 2 * i);
    int right = query(qs, qe, mid + 1, r, 2 * i + 1);
    return left + right;
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
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void update(int i, int l, int r, int s, int e, int x)
{
    if (s > r || e < l)
        return;

    else if (s <= l && e >= r)
    {
        apply(i, l, r, x);
        return;
    }

    pushdown(i, l, r);
    int mid = (l + r) / 2;
    update(2 * i, l, mid, s, e , x);
    update(2 * i + 1, mid + 1, r, s, e, x);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
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
    lazy.resize(4 * n, false);
    upd.resize(4 * n, 0);
    tree.resize(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int k;
            cin >> k;
            k--;
            cout << query(k, k, 0, n - 1, 1) << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            update(1, 0, n - 1, l , r , x);
        }
    }
    return 0;
}
