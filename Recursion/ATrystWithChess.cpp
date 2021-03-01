#include<bits/stdc++.h>
using namespace std;
 
void solve(int i,int j,int n,int& count,map<pair<int,int>,bool>&mp)
{
	if(i>9||j>9||i<0||j<0)
		return;
	if(n==0)
	{
		if(mp[{i,j}]==false)
		{
			count++;
			mp[{i,j}]=true;
		}
		return;
	}
	solve(i+1,j+2,n-1,count,mp);
	solve(i+1,j-2,n-1,count,mp);
	solve(i+2,j+1,n-1,count,mp);
	solve(i+2,j-1,n-1,count,mp);
	solve(i-1,j-2,n-1,count,mp);
	solve(i-1,j+2,n-1,count,mp);
	solve(i-2,j+1,n-1,count,mp);
	solve(i-2,j-1,n-1,count,mp);
}
 
int main()
{
	int i,j,n;
	cin>>i>>j>>n;
	map<pair<int,int>,bool> mp;
	int count=0;
	solve(i,j,n,count,mp);
	cout<<count;
}
