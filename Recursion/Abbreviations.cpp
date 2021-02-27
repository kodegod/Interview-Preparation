#include<bits/stdc++.h>
using namespace std;

void abbrev(string ip,string op,int count,int pos)
{
    if(pos==op.length())
    {
        if(count>0)
            cout<<ip<<count<<endl;
        else
            cout<<ip<<endl;
        return;
    }
    if(count>0)
        abbrev(ip+to_string(count)+op[pos],op,0,pos+1);
    else
        abbrev(ip+op[pos],op,0,pos+1);
    abbrev(ip,op,count+1,pos+1);
}

int main()
{
    string s;
    cin>>s;
    string ip="";
    string op=s;
    abbrev(ip,op,0,0);
}
