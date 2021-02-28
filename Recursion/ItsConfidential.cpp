//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/its-confidential-f006e2c4/
#include<bits/stdc++.h>
using namespace std;

void solve(string str,string&ip,string&s)
{
	int mid=(str.length()-1)/2;
	ip.push_back(str[mid]);
	if(ip.size()==s.size())
	{
		cout<<ip<<endl;
		return;
	}
	if(mid!=0)
	{
		string temp1=str.substr(0,mid);
		solve(temp1,ip,s);
	}
	if(mid!=str.size()-1)
	{
		string temp2=str.substr(mid+1,str.length()-mid-1);
		solve(temp2,ip,s);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ip="";
		string str=s;
		solve(str,ip,s);
	}
}
