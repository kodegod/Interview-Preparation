//https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    map<int,vector<int>> g;
    vector<int> count;
    vector<int> par;
    vector<int> ans;
    vector<int> level;
    int glob = 0;
    void dfs(int root)
    {
        count[root] = 1;
        for(auto it: g[root])
        {
            if(par[root]!=it)
            {
                level[it] = 1 + level[root];
                glob += level[it];
                par[it] = root;
                dfs(it);
                count[root] += count[it];
            }
        }
    }
    void solve(int root,int n)
    {
        for(auto it: g[root])
        {
            if(par[root]!=it)
            {
                ans[it] = ans[root] - count[it] + (n - count[it]);
                solve(it,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto it:edges)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        count.resize(n,0);
        par.resize(n,0);
        ans.resize(n,0);
        level.resize(n,0);
        level[0] = 0;
        par[0] = 0;
        dfs(0);
        ans[0] = glob;
        solve(0,n);
        return ans;
    }
};
