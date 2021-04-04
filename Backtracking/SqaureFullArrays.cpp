//https://leetcode.com/problems/number-of-squareful-arrays/
class Solution {
public:
    bool issquare(int n)
    {
        int a=sqrt(n);
        return (a*a==n);
    }
    bool isspecial(vector<int>&v,int n)
    {
        for(int i=0; i<n-1; i++)
        {
            int k=v[i]+v[i+1];
            if(issquare(k)==false)
                return false;
        }
        return true;
    }
    void permute(vector<int>&A,int n,vector<vector<int>>&v,int i)
    {
        if(i==n)
        {
            v.push_back(A);
            return;
        }
        set<int> s;
        for(int j=i; j<n; j++)
        {
            if(s.find(A[j])==s.end())
            {
                s.insert(A[j]);
                swap(A[i],A[j]);
                if(i==0||issquare(A[i]+A[i-1]))
                    permute(A,n,v,i+1);
                swap(A[i],A[j]);
            }
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        vector<vector<int>> v;
        int n=A.size();
        permute(A,n,v,0);
        int cnt=0;
        for(auto it:v)
            if(isspecial(it,n))
                cnt++;
        return cnt;
    }
};
