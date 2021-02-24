class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    map<pair<int,int>,bool> visited;
    void solve(vector<vector<int>>&grid,int m,int n,int i,int j,int&count,int&cnt,int covered)
    {
        if(i<0||j<0||i>=m||j>=n)
            return;
        if(grid[i][j]==2)
        {
            if(covered==cnt+1)
                count++;
            return;
        }
        visited[{i,j}]=true;
        for(int k=0; k<4; k++)
        {
            if(i+dir[k][0]<m&&i+dir[k][0]>=0&&j+dir[k][1]<n&&j+dir[k][1]>=0&&grid[i+dir[k][0]][j+dir[k][1]]!=-1&&visited[{i+dir[k][0],j+dir[k][1]}]==false)
                solve(grid,m,n,i+dir[k][0],j+dir[k][1],count,cnt,covered+1);
        }
        visited[{i,j}]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        int i,j;
        int cnt=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                    cnt++;
            }
        }
        bool flag=1;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        solve(grid,m,n,i,j,count,cnt,0);
        return count;
    }
};
