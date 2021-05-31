//https://leetcode.com/problems/swim-in-rising-water/

// Dijkstra on Matrix


class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        map<int,bool> visited;
        visited[grid[0][0]]=true;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> node=pq.top();
            pq.pop();
            if(node.second.first==n-1 && node.second.second == n-1)
                return node.first;
            for(int i=0; i<4; i++)
            {
                int x=node.second.first+dir[i][0];
                int y=node.second.second+dir[i][1];
                if(x<0||y<0||x>=n||y>=n||visited[grid[x][y]]==true)
                    continue;
                pq.push({max(node.first,grid[x][y]),{x,y}});
                visited[grid[x][y]]=true;
            }
        }
        return 0;
    }
};


// MST - Kruskal - DSU


