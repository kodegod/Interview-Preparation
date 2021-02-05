class NumMatrix {
public:
    vector<vector<int>> v2;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()!=0)
        {
            int m=matrix.size();
            int n=matrix[0].size();
            for(int i=0; i<m; i++)
                v2.push_back(matrix[i]);
            for(int i=0; i<m; i++)
            {
                for(int j=1; j<n; j++)
                    v2[i][j]+=v2[i][j-1];
            }
            for(int i=0; i<n; i++)
            {
                for(int j=1; j<m; j++)
                    v2[j][i]+=v2[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(v2.size()==0)
            return 0;
        int sum=0;
        sum+=v2[row2][col2];
        if(row1>0)
            sum-=v2[row1-1][col2];
        if(col1>0)
            sum-=v2[row2][col1-1];
        if(row1>0&&col1>0)
            sum+=v2[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
