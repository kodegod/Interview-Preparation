#include<bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if(n<10)
        return n;
    else
        return n%10+sum(n/10);
}
int solve(int n)
{
    if(n<10)
        return n;
    else
        return solve(sum(n));
}
int main()
{
    string n;
    cin>>n;
    int k;
    cin>>k;
    int s=0;
    for(int i=0; i<n.size(); i++)
        s+=n[i]-48;
    int temp=solve(s);
    temp*=k;
    cout<<solve(temp);
}
