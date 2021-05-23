//https://leetcode.com/problems/sentence-similarity-ii/

//DSU


class Solution {
public:
    map<string,string> par;
    string get_root(string u)
    {
        if(par[u]==u)
            return u;
        return par[u]=get_root(par[u]);
    }
    void merge(string u,string v)
    {
        string a=get_root(u);
        string b=get_root(v);
        if(a==b)
            return;
        if(rand()%2)
            par[a]=b;
        else
            par[b]=a;
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size())
            return false;
        for(int i=0; i<pairs.size(); i++)
        {
            par[pairs[i][0]]=pairs[i][0];
            par[pairs[i][1]]=pairs[i][1];
        }
        for(int i=0; i<words1.size(); i++)
            par[words1[i]]=words1[i];
        for(int i=0; i<words1.size(); i++)
            par[words2[i]]=words2[i];
        for(int i=0; i<pairs.size(); i++)
            merge(pairs[i][0],pairs[i][1]);
        for(int i=0; i<words1.size(); i++)
        {
            if(words1[i]==words2[i])
                continue;
            string a=get_root(words1[i]);
            string b=get_root(words2[i]);
            if(a!=b)
                return false;
        }
        return true;
    }
};
