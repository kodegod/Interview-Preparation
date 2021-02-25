class Solution {
public:
    bool issafe(vector<string>&temp,int x,int y,int n)
    {
        for(int i=x; i>=0; i--)
        {
            if(temp[i][y]=='Q')
                return false;
        }
        int i=x;
        int j=y;
        while(i>=0&&j>=0)
        {
            if(temp[i][j]=='Q')
                return false;
            else
            {
                i--;
                j--;
            }
        }
        i=x;
        j=y;
        while(i>=0&&j<n)
        {
            if(temp[i][j]=='Q')
                return false;
            else
            {
                i--;
                j++;
            }
        }
        return true;
    }
    void queens(int i,int n,vector<string>&temp,vector<vector<string>>&v)
    {
        if(i==n)
        {
            v.push_back(temp);
            return;
        }
        for(int j=0; j<n; j++)
        {
            if(issafe(temp,i,j,n))
            {
                temp[i][j]='Q';
                queens(i+1,n,temp,v);
                temp[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> v;
        vector<string> temp;
        for(int i=0; i<n; i++)
        {
            string s;
            for(int j=0; j<n; j++)
                s.push_back('.');
            temp.push_back(s);
        }
        queens(0,n,temp,v);
        return v;
    }
};
