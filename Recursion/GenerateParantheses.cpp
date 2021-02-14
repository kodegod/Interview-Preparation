class Solution {
public:
    void solve(int n,int no,int nc,string s,vector<string>&v)
    {
        if(no==nc&&no==n)
        {
            v.push_back(s);
            return;
        }
        if(no==nc)
            solve(n,no+1,nc,s+"(",v);
        else if(no>nc)
        {
            if(no+1<=n)
                solve(n,no+1,nc,s+"(",v);
            solve(n,no,nc+1,s+")",v);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="(";
        vector<string> v;
        solve(n,1,0,s,v);
        return v;
    }
};
