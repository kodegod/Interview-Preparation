class Solution {
public:
    vector<string> key={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string ip,string op,vector<string>&v)
    {
        if(op.size()==0)
        {
            v.push_back(ip);
            return;
        }
        int k=op[0]-48;
        op.erase(op.begin());
        for(int i=0; i<key[k].size(); i++)
            helper(ip+key[k][i],op,v);
    }
    vector<string> letterCombinations(string digits) {
        string ip="";
        string op=digits;
        vector<string> v;
        if(op.size()==0)
            return v;
        helper(ip,op,v);
        return v;
    }
};
