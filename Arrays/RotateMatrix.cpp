https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int n=A.size();
    if(n==0)
        return;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
            swap(A[i][j],A[j][i]);
    }
    for(int i=0; i<n; i++)
        reverse(A[i].begin(),A[i].end());
}
