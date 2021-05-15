//https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    map<int,bool> visited;
    bool bfs(int src,vector<vector<int>>& graph,vector<int>&color)
    {
        color[src]=1;
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto child:graph[node])
            {
                if(!visited[child])
                {
                    visited[child]=true;
                    q.push(child);
                    color[child]=3-color[node];
                }
                else
                {
                    if(color[child]==color[node])
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color;
        color.resize(n,0);
        bool bar=true;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
                bar=bfs(i,graph,color);
            if(bar==false)
                return bar;
        }
        return true;
    }
};
