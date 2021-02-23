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
    void solve(string s,int i,vector<string> temp,vector<vector<string>>&v)
    {
        if(i==s.size())
        {
            v.push_back(temp);
            return;
        }
        for(int j=i+1; j<=s.size(); j++)
        {
            string l=s.substr(i,j);
            if(ispal(l)==true)
            {
                temp.push_back(l);
                solve(s,i+j,temp,v);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> temp;
        solve(s,0,temp,v);
        return v;
    }
};
