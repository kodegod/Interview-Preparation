class Solution {
public:
    bool ispal(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string&op,int i,vector<string>&temp,vector<vector<string>>&v)
    {
        if(i==op.size())
        {
            v.push_back(temp);
            return;
        }
        for(int j=1; j<=op.size()-i; j++)
        {
            string s=op.substr(i,j);
            if(ispal(s))
            {
                temp.push_back(s);
                solve(op,i+j,temp,v);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> v;
        vector<string> temp;
        solve(s,0,temp,v);
        return v;
    }
};
