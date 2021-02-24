class Solution {
public:
    map<pair<int,int>,bool> visited;
    bool solve(vector<vector<char>>& board,int m,int n,int i,int j,int curr,string word)
    {
        if(curr==word.length())
            return true;
        if(i>=m||j>=n||i<0||j<0)
            return false;
        if(board[i][j]!=word[curr])
            return false;
        bool b1=false,b2=false,b3=false,b4=false;
        board[i][j]='*';
        bool ans=solve(board,m,n,i+1,j,curr+1,word)
        || solve(board,m,n,i-1,j,curr+1,word)
        || solve(board,m,n,i,j+1,curr+1,word)
        || solve(board,m,n,i,j-1,curr+1,word);
        board[i][j]=word[curr];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(solve(board,m,n,i,j,0,word)==true)
                    return true;
            }
        }
        return false;
    }
};
