// https://leetcode.com/problems/max-area-of-island/

// BFS

class Solution {
public:
    map<pair<int,int>,bool> visited;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int bfs(int i,int j,vector<vector<int>>& grid,int&m,int&n)
    {
        visited[{i,j}]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        int cnt=1;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x=node.first+dir[k][0];
                int y=node.second+dir[k][1];
                if(x<0||y<0||x>=m||y>=n)
                    continue;
                if(grid[x][y]==0 || visited[{x,y}]==true)
                    continue;
                visited[{x,y}]=true;
                q.push({x,y});
                cnt++;
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && visited[{i,j}]==false)
                    ans=max(ans,bfs(i,j,grid,m,n));
            }
        }
        return ans;
    }
};
