//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/


// DSU


class Solution {
public:
    map<int,bool> col,row;
    vector<int> par;
    map<int,bool> visited;
    int comp;
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
        comp--;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=0;
        for(int i=0; i<stones.size(); i++)
            n=max(n,max(stones[i][0],stones[i][1]));
        par.resize(2*n+2,0);
        for(int i=0; i<par.size(); i++)
            par[i]=i;
        comp=2*n+2;
        for(int i=0; i<stones.size(); i++)
        {
            merge(stones[i][0],stones[i][1]+n+1);
            visited[stones[i][0]]=true;
            visited[stones[i][1]+n+1]=true;
        }
        for(int i=0; i<par.size(); i++)
            if(!visited[i])
                comp--;
        return stones.size()-comp;
    }
};
