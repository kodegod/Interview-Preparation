//https://leetcode.com/problems/smallest-string-with-swaps/

// DSU

class Solution {
public:
    vector<int> par;
    map<int,vector<int>> index;
    int get_root(int u)
    {
        if(par[u]==u)
            return u;
        return par[u]=get_root(par[u]);
    }
    void merge(int u,int v)
    {
        int a=get_root(u);
        int b=get_root(v);
        if(a==b)
            return;
        if(rand()%2)
            par[a]=b;
        else
            par[b]=a;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        par.resize(s.size(),0);
        for(int i=0; i<s.size(); i++)
            par[i]=i;
        for(int i=0; i<pairs.size(); i++)
            merge(pairs[i][0],pairs[i][1]);
        for(int i=0; i<s.size(); i++)
            index[get_root(i)].push_back(i);
        for(auto it:index)
        {
            string temp;
            for(auto ip:it.second)
                temp.push_back(s[ip]);
            sort(temp.begin(),temp.end());
            int k=0;
            for(auto ip:it.second)
                s[ip]=temp[k++];
        }
        return s;
    }
};
