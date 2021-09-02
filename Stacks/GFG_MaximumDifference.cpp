//https://practice.geeksforgeeks.org/problems/maximum-difference/1#

class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      vector<int> ls(n,0);
      vector<int> rs(n,0);
      stack<int> s;
      s.push(0);
      for(int i=1; i<n; i++)
      {
          while(s.size()>0 && A[i] < s.top())
          {
              ls[s.top()] = A[i];
              s.pop();
          }
          s.push(i);
      }
      while(!s.empty())
        s.pop();
      s.push(n-1);
      for(int i=n-2; i>=0; i--)
      {
          while(s.size()>0 && A[i] < s.top())
          {
              rs[s.top()] = A[i];
              s.pop();
          }
          s.push(i);
      }
      int ans = INT_MIN;
      for(int i=0; i<n; i++)
        ans = max(ans, abs(rs[i] - ls[i]));
      return ans;
    }
};
