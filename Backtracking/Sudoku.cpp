class Solution {
public:
    void solve(vector<vector<char>>& board,int i,int j,vector<vector<char>>&rf,vector<vector<char>>&cf,vector<vector<char>>&mf,bool&ansfound,vector<vector<char>>&ans)
    {
        if(ansfound==true)
            return;
        if(i==9)
        {
            ans=board;
            ansfound=true;
            return;
        }
        if(board[i][j]!='.')
        {
            if(j==8)
                solve(board,i+1,0,rf,cf,mf,ansfound,ans);
            else
                solve(board,i,j+1,rf,cf,mf,ansfound,ans);
            return;
        }
        else
        {
            for(int k=0; k<9; k++)
            {
                if(rf[i][k]==0&&cf[j][k]==0&&mf[((i/3)*3)+j/3][k]==0)
                {
                    board[i][j]=k+48+1;
                    rf[i][k]=1;
                    cf[j][k]=1;
                    mf[((i/3)*3)+j/3][k]=1;
                    if(j==8)
                        solve(board,i+1,0,rf,cf,mf,ansfound,ans);
                    else
                        solve(board,i,j+1,rf,cf,mf,ansfound,ans);
                    rf[i][k]=0;
                    cf[j][k]=0;
                    mf[((i/3)*3)+j/3][k]=0;
                    board[i][j]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rf;
        vector<vector<char>> cf;
        vector<vector<char>> mf;
        for(int i=0; i<9; i++)
        {
            vector<char> temp(9,0);
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                    temp[board[i][j]-'1']++;
            }
            rf.push_back(temp);
        }
        for(int i=0; i<9; i++)
        {
            vector<char> temp(9,0);
            for(int j=0; j<9; j++)
            {
                if(board[j][i]!='.')
                    temp[board[j][i]-'1']++;
            }
            cf.push_back(temp);
        }
        for(int i=0; i<9; i+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                vector<char> temp(9,0);
                for(int i1=i; i1<i+3; i1++)
                {
                    for(int j1=j; j1<j+3; j1++)
                    {
                        if(board[i1][j1]!='.')
                            temp[board[i1][j1]-'1']++;
                    }
                }
                mf.push_back(temp);
            }
        }
        bool ansfound=false;
        vector<vector<char>> ans=board;
        solve(board,0,0,rf,cf,mf,ansfound,ans);
        board=ans;
    }
};
