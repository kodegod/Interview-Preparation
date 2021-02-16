class Solution {
public:
    void solve(string ip,string op,vector<string>&v)
    {
        if(op.size()==0)
        {
            v.push_back(ip);
            return;
        }
        string temp=op;
        op.erase(op.begin());
        if(isalpha(temp[0]))
        {
            char b=toupper(temp[0]);
            solve(ip+b,op,v);
            char d=tolower(temp[0]);
            solve(ip+d,op,v);
        }
        else
            solve(ip+temp[0],op,v);
    }
    vector<string> letterCasePermutation(string S) {
        string ip="";
        string op=S;
        vector<string> v;
        solve(ip,op,v);
        return v;
    }
};
