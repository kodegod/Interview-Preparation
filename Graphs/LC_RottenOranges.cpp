//https://leetcode.com/problems/rotting-oranges/


//Multi-Source BFS
class Solution {
public:
    map<pair<int,int>,int> level;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& grid,int m,int n)
    {
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    level[{i,j}]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x=node.first+dir[i][0];
                int y=node.second+dir[i][1];
                if(x<0||y<0||x>=m||y>=n)
                    continue;
                if(grid[x][y]==1)
                {
                    grid[x][y]=2;
                    q.push({x,y});
                    level[{x,y}]=1+level[node];
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bfs(grid,m,n);
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        for(auto it:level)
            ans=max(ans,it.second);
        return ans;
    }
};
