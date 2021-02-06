#include<bits/stdc++.h>
using namespace std;

bool compr(string s1, string s2)
{
    int n=s1.length();
    int m=s2.length();
    if(n!=m)
        return false;
    for(int i=0; i<n; i++)
    {
        if(s2[i]=='1'&&s1[i]=='2')
            return false;
        else if(s2[i]>s1[i])
            return false;
    }
    return true;
}
string change(string s)
{
    string temp="";
    int c=1;
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i]==s[i+1])
            c++;
        else
        {
            temp=temp+to_string(c);
            c=1;
        }
    }
    temp=temp+to_string(c);
    return temp;
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    bool bar=false;
    for(int i=0; i<n; i++)
    {
        if(compr(change(s),change(v[i]))==true)
        {
            bar=true;
            break;
        }
    }
    cout<<bar;
}
