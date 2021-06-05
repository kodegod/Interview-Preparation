//https://leetcode.com/problems/find-eventual-safe-states/

// Cycle detection in Directed Graphs

class Solution {
public:
    vector<int> color;
    bool dfs(int node,vector<vector<int>>& graph)
    {
        if(color[node]==0)
            return true;
        if(color[node]==1)
            return false;
        color[node]=1;
        for(auto it:graph[node])
        {
            bool temp=dfs(it,graph);
            if(temp==false)
                return false;
        }
        color[node]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        color.resize(n,-1);
        vector<int> ans;
        for(int i=0; i<n; i++)
            dfs(i,graph); 
        for(int i=0; i<n; i++)
        {
            if(color[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};
