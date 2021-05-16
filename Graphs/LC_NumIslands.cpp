//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    map<pair<int,int>,bool> visited;
    void dfs(int x,int y,vector<vector<char>>& grid,int m,int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return;
        if(grid[x][y]=='0')
            return;
        visited[{x,y}]=true;
        if(!visited[{x+1,y}])
            dfs(x+1,y,grid,m,n);
        if(!visited[{x-1,y}])
            dfs(x-1,y,grid,m,n);
        if(!visited[{x,y+1}])
            dfs(x,y+1,grid,m,n);
        if(!visited[{x,y-1}])
            dfs(x,y-1,grid,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1' && !visited[{i,j}])
                {
                    dfs(i,j,grid,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};
