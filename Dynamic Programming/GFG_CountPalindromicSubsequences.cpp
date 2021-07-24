//https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/

class Solution{
    public:
    /*You are required to complete below method */
    int dp[1002][1002];
    
    long long solve(string&str,int i,int j)
    {
        if(i==j)
            return 1;
        else if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j]%1000000007;
            
        if(str[i]==str[j])
            return dp[i][j] =  (solve(str,i+1,j) + solve(str,i,j-1) +1)%1000000007;
        else
            return dp[i][j] = (solve(str,i+1,j) + solve(str,i,j-1) - solve(str,i+1,j-1) + 1000000007)%1000000007;
    }
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp, -1, sizeof dp);
       return solve(str,0,str.size()-1)%1000000007;
    }
     
};
