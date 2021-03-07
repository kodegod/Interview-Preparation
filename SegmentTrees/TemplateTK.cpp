#include<bits/stdc++.h>
using namespace std;

int ST[4*N], A[N];
#define lc (x<<1)
#define rc (x<<1)|1
void build(int x=1,int l=1,int r=N+1)
{
	if(l==r-1)
		return void(ST[x]=A[l]);
	int mid=(l+r)/2;
	build(lc,l,mid);
	build(rc,mid,r);
	ST[x]=combine(ST[lc],ST[rc]);
}
int query(int L,int R,int x=1,int l=1, int r=N-1)
{
	if(l>=R || r<=L)
		return 0; //some default value
	if(l>=L && r<=R)
		return ST[x];
	int mid=(l+r)/2;
	return combine(query(L,R,lc,l,mid),query(L,R,rc,mid,r));
}
void point_update(int pos,int val,int x=1,int l=1,int r=N-1)
{
	if(pos<l || pos>=r)
		return;
	if(l==r-1)
	{
		ST[x]=val;
		A[pos]=val;
		return;
	}
	int mid=(l+r)/2;
	point_update(pos,val,lc,l,mid);
	point_update(pos,val,rc,mid,r);
	ST[x]=combine(ST[lc],ST[rc]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
