class Solution {
public:
    void solve(string &s,int i,int count,vector<string>&v)
    {
        if(i==s.size()&&count==4)
        {
            string str(s.begin(),s.end()-1);
            v.push_back(str);
            return;
        }
        if(count==4)
            return;
        for(int j=1; j<=s.size()-i; j++)
        {
            string small=s.substr(i,j);
            int num=stoi(small);
            if(num>255)
                break;
            if(small[0]=='0'&&j>1)
                break;
            s.insert(s.begin()+i+j,'.');
            solve(s,i+j+1,count+1,v);
            s.erase(s.begin()+i+j);
            if(j==3)
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        solve(s,0,0,v);
        return v;
    }
};
