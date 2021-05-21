//https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>,bool> visited;
    void dfs(vector<vector<char>>& board,int i,int j,int m,int n)
    {
        visited[{i,j}]=true;
        for(int k=0; k<4; k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x<0 || y<0 || x>=m || y>=n)
                continue;
            if(board[x][y]=='O' && !visited[{x,y}])
                dfs(board,x,y,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O')
                    if(!visited[{i,j}])
                        dfs(board,i,j,m,n);
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O')
                    continue;
                if(!visited[{i,j}] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
