//https://leetcode.com/problems/satisfiability-of-equality-equations/

// DSU

class Solution {
public:
    map<int,int> par;
    int get_root(int u)
    {
        if(u==par[u])
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
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<equations.size(); i++)
        {
            par[equations[i][0]]=equations[i][0];
            par[equations[i][3]]=equations[i][3];
        }
        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1]=='=')
                merge(equations[i][0],equations[i][3]);
        }
        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1]=='!')
            {
                int a=get_root(equations[i][0]);
                int b=get_root(equations[i][3]);
                if(a==b)
                    return false;
            }
        }
        return true;
    }
};
